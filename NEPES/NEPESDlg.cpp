
// NEPESDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "NEPESDlg.h"
#include "afxdialogex.h"

#include "DlgOption.h"
#include "DlgOptionEtc.h"
#include "DlgStrobeBrightness.h"
#include "DlgMessage.h"
#include "DlgExtractSample.h"

#ifdef USE_BASLER_CAMERA
#include "Video/ConvertColor.h"
#include "inc/PixelFormat.h"
#endif

#include "Util/Util.h"
#include "stringres.h"

#include "Ethernet/EthernetClient.h"
#include "Ethernet/EthernetServer.h"

#include <set>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
	
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


void RotateImage(INFO_IMAGE* pstImage, const DWORD dwDegree);

BOOL WriteImageFromBuffer(const TCHAR* pszPath, BYTE* pBuffer, DWORD dwLen, DWORD dwWidth, DWORD dwHeight, BYTE nBit, int nPitch);

// CNEPESDlg dialog

BOOL CNEPESDlg::FuncDisplayVideoDevice(const INFO_IMAGE* pstImage, void* pArg, int nRemainedFrame)
{
	if (NULL == pArg)
		return FALSE;

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();

	INFO_VIDEOARG* pInfoArg = (INFO_VIDEOARG*)pArg;
	if (pInfoArg && pInfoArg->m_pArgument)
	{
		///
		CNEPESDlg* pDlg = (CNEPESDlg*)pInfoArg->m_pArgument;
		const TYPE_CAMERAPOS eType = pCaptureManager->GetCapturePosByProc(pInfoArg->m_dwProcID);

		if (TYPE_CAMERAPOS_FIRST != eType && TYPE_CAMERAPOS_SECOND != eType)
			return FALSE;

		if (FALSE == pCaptureManager->IsReadySnapCapture(eType))
		{
			if (pCaptureManager->IsSingleSnapCapture())
				pCaptureManager->SetReadySnapCapture(eType, TRUE);

			CUtil::PrintDebugString(_T("FuncDisplayVideoDevice - TYPE_CAMERAPOS[%d] \r\n"), eType);

			if (TYPE_CAMERAPOS_SECOND == eType)
			{
				DWORD dwValue = 0;
				CUtil::GetRegDword(REG_ROOT_PATH, REG_VALUE_SECOND_ROTATE, dwValue);

				if (90 == dwValue || 270 == dwValue)
				{
					RotateImage((INFO_IMAGE*)pstImage, dwValue);
				}
			}

			// Print Log
			{
				if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
				{
					if (TYPE_CAMERAPOS_FIRST == eType)
						stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Grab - First camera");
					else if (TYPE_CAMERAPOS_SECOND == eType)
						stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Grab - Second camera");
				}
			}

			if (pDlg->m_pDlgSequence)
			{
				// Sequence Edit Dialog
				pDlg->m_pDlgSequence->DisplayImage(pstImage);
			}
			else
			{
				CUtil::PrintDebugString(_T("DISPLAY - TYPE_CAMERAPOS[%d] \r\n"), eType);

				// Main Dialog - ScrollView
				CCustomScrollView* pScrollView = pDlg->m_TapMainScenario.GetScrollView(eType);
				pScrollView->DisplayImage(pstImage);

				CInspection* pInspection = pCaptureManager->GetInspection();
				if (pInspection && pInspection->IsInit() && pInspection->IsStart())
				{
					if (FALSE == pInspection->IsWorkingInspection(eType) || pInspection->IsWaitingAcquire(eType))
					{
						CUtil::PrintDebugString(_T("START WORK - TYPE_CAMERAPOS[%d] \r\n"), eType);

						const INFO_IMAGE* pstImage = pScrollView->GetDisplayImage();
						
						if (FALSE == pInspection->IsWorkingInspection(eType))
						{
							CUtil::PrintDebugString(_T("   NEW INSPECTION \r\n"));

							shared_ptr<CSampleSide> pSample(new CSampleSide());
							const INFO_OPTION* pstOption = pCaptureManager->GetOption();
							memcpy(pSample->m_pstRefOptRangeSpecList, pstOption->m_pstRangeSpec, sizeof(INFO_OPT_RANGE)*MAX_SIZE_MEASURECOUNT);
							if (TYPE_CAMERAPOS_FIRST == eType)
							{
								const int nNextIndex = pCaptureManager->GetResultSummary()->m_stSummaryFirst.m_nSampleCount;
								memcpy(pSample->m_pstRefOptRangeList, pstOption->m_pstRange[0], sizeof(INFO_OPT_RANGE)*MAX_SIZE_MEASURECOUNT);
								
								pSample->m_pRefImage = (INFO_IMAGE*)pstImage;
								//pDlg->m_TapMainScenario.SetStepState(eType, TYPE_STEP_001);

								// Print Log
								{
									if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
										stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Start Inspection: First %d", nNextIndex);
								}
							}
							else if (TYPE_CAMERAPOS_SECOND == eType)
							{
								if (!pCaptureManager->m_SummaryFirstQueue.empty()){
									const int nNextIndex = pCaptureManager->GetResultSummary()->m_stSummarySecond.m_nSampleCount;


									memcpy(pSample->m_pstRefOptRangeList, pstOption->m_pstRange[1], sizeof(INFO_OPT_RANGE)*MAX_SIZE_MEASURECOUNT);

									pSample->m_pRefImage = (INFO_IMAGE*)pstImage;
									//pDlg->m_TapMainScenario.SetStepState(eType, TYPE_STEP_001);

									// Print Log
									{
										if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
											stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Start Inspection: Second %d", nNextIndex);
									}
								}
								else
								{
									if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
										stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Queue is empty");

									//CString strDeviceName = pDlg->MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), TYPE_CAMERAPOS_SECOND - 1/*pCaptureManager->GetCurCameraPos()*/, TYPE_STATE_VISION_SENDINSPECTION);
									//pCaptureManager->LPMxComSetDevice(strDeviceName, 2);
									
									return TRUE;
								}
							}

							pInspection->InspectCamera(eType, pSample);
						}
						else if (pInspection->IsWaitingAcquire(eType))
						{
							CUtil::PrintDebugString(_T("   ACQ for INSPECTION \r\n"));

							pInspection->UpdateInspectCameraSample(eType, pstImage);
						}
						else
						{
							CUtil::PrintDebugString(_T("    Now Busy Skipped... \r\n"));
						}
					}
					else
					{
						CUtil::PrintDebugString(_T("SKIP WORK - TYPE_CAMERAPOS[%d] \r\n"), eType);
					}
				}
			}
		}
		else
		{
			//CUtil::PrintDebugString(_T("Skip - TYPE_CAMERAPOS_FIRST \r\n"));
		}
		//*/
		
	}
	return TRUE;
}

BOOL CNEPESDlg::FuncNotifyEthernetListener(DWORD dwListener, void* pArg)
{
	if (NULL == pArg)
		return FALSE;
	CUtil::PrintDebugString(_T("[%d] FuncNotifyEthernetListener \r\n"), ::GetTickCount());
	TCHAR szMessage[MAX_TEXT_LEN] = { 0, };


	CNEPESDlg* pDlg = (CNEPESDlg*)pArg;

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CEthernet* pEthernetPort = pCaptureManager->GetCommunicatePort();
	INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();

	BOOL bServer = FALSE;

	CEthernetClient* pEthernetClient = dynamic_cast<CEthernetClient*>(pEthernetPort);
	if (NULL == pEthernetClient)
	{
		CEthernetServer* pEthernetServer = dynamic_cast<CEthernetServer*>(pEthernetPort);
		if (pEthernetServer)
		{
			pEthernetClient = pEthernetServer->GetConnectedClinet(0);
			bServer = TRUE;
		}
	}
	if (NULL == pEthernetClient)
		return FALSE;

	// Check disconnected..
	if (pEthernetClient && FALSE == pEthernetClient->IsOpen())
	{
		if (bServer)
		{
			CEthernetServer* pEthernetServer = dynamic_cast<CEthernetServer*>(pEthernetPort);
			pEthernetServer->DeleteClient(pEthernetClient);
		}
		//else	// Disconnect message from Device. All Disconnect communication port.
		{
			CInspection* pInspection = pCaptureManager->GetInspection();
			const BOOL bStart = pInspection->IsStart();
			if (bStart)
				pDlg->OnBnClickedBtnStart();
			pCaptureManager->DeleteCommunicatePort();

			if (pDlg->m_pDlgConfig && pDlg->m_pDlgConfig->IsWindowVisible())
				pDlg->m_pDlgConfig->UpdateEthernetPort();
			else
				pDlg->PostMessage(WM_COMMAND, ID_CONFIG_CONFIG, 0);
		}
		return FALSE;
	}

	const TCHAR* pInputString = pEthernetClient->GetInputString();
	if (pInputString)
	{
		CInspection* pInspection = pCaptureManager->GetInspection();
		BOOL bMatchCommand = FALSE;
		
		if (pInspection->IsInit() && pInspection->IsStart())
		{
			CUtil::StringFormat(szMessage, MAX_TEXT_LEN, _T("INPUT %s \r\n"), pInputString);
			CUtil::PrintDebugString(szMessage);

			// Print Log
			{
				if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
				{
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "INPUT [%s]", pInputString);
				}
			}
		}

	}
	else
	{
		CUtil::StringFormat(szMessage, MAX_TEXT_LEN, _T("INPUT NULL \r\n"));
		CUtil::PrintDebugString(szMessage);
	}

	return TRUE;
}

BOOL CNEPESDlg::FuncNotifyInspectionResult(TYPE_CAMERAPOS eCameraPos, TYPE_STEP eStep, BOOL bResult, void* pArg, BOOL bCeptureFlag)
{
	
	if (NULL == pArg)
		return FALSE;

	CNEPESDlg* pDlg = (CNEPESDlg*)pArg;
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();


	if (bCeptureFlag == FALSE){
		CUtil::PrintDebugString(_T("[%d] FuncNotifyInspectionResult [CAMERAPOS:%d] [STEP:%d] [RESULT:%d]\r\n"), ::GetTickCount(), eCameraPos, eStep, bResult);

		int nRes = 0;
		//CNEPESDlg* pDlg = (CNEPESDlg*)pArg;

		//CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
		const INFO_OPTION* pstOption = pCaptureManager->GetOption();
		INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();
		// Version 1.3.6.7
		const INFO_OPTIONETC* pstEtcOption = pCaptureManager->GetOptionEtc();
		
		// Print Log
		if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
			stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "FuncNotifyInspectionResult [CAMERAPOS:%d] [STEP:%d] [RESULT:%d]", eCameraPos, eStep, bResult);

		//CInspection* pInspection = pCaptureManager->GetInspection();
		if (pInspection->IsInit() && pInspection->IsStart())
		{
			/*if (TYPE_STEP_001 == eStep ||
				TYPE_STEP_002 == eStep ||
				TYPE_STEP_003 == eStep ||
				TYPE_STEP_004 == eStep ||
				TYPE_STEP_005 == eStep ||
				TYPE_STEP_006 == eStep)*/
			if (TYPE_STEP_001 == eStep ||
				TYPE_STEP_002 == eStep ||
				TYPE_STEP_003 == eStep ||
				TYPE_STEP_004 == eStep)
				// Version 1.3.6.8
				//TYPE_STEP_005 == eStep
				
			{
				CSampleSide* pSample = pInspection->GetInspectionSample(eCameraPos).get();
				
				if (TYPE_STEP_001 == eStep)
				{
					if (TYPE_CAMERAPOS_FIRST == eCameraPos)
					{
						//
						if (pstOption->m_stFirstCameraStep.m_bStep001)
						{
							//pDlg->m_TapMainSize.UpdateResultSize(eCameraPos, pSample);
#ifdef USE_COUNT_TAB
							//pDlg->m_TapMainCount.UpdateResultSize(eCameraPos, pSample);
#endif
						}
						pDlg->m_TapMainScenario.UpdateResult(eCameraPos, eStep, pSample);	// Update Display
#ifdef USE_COUNT_TAB
						pDlg->m_TapMainCount.UpdateResult(eCameraPos, eStep, pSample);	// Update Display
#endif
						// Check & Write Image
						//pDlg->DumpImageErrorResult(eCameraPos, eStep, pSample);
					}
					else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
					{
						if (pstOption->m_stSecondCameraStep.m_bStep001)
						{
							//pDlg->m_TapMainSize.UpdateResultSize(eCameraPos, pSample);
#ifdef USE_COUNT_TAB
							//pDlg->m_TapMainCount.UpdateResultSize(eCameraPos, pSample);
#endif
						}
						pDlg->m_TapMainScenario.UpdateResult(eCameraPos, eStep, pSample);	// Update Display
#ifdef USE_COUNT_TAB
						pDlg->m_TapMainCount.UpdateResult(eCameraPos, eStep, pSample);	// Update Display
#endif
						// Check & Write Image
						//pDlg->DumpImageErrorResult(eCameraPos, eStep, pSample);
					}
				}
				else
				{
					pDlg->m_TapMainScenario.UpdateResult(eCameraPos, eStep, pSample);		// Update Display
#ifdef USE_COUNT_TAB
					pDlg->m_TapMainCount.UpdateResult(eCameraPos, eStep, pSample);	// Update Display
#endif
					// Check & Write Image
					pDlg->DumpImageErrorResult(eCameraPos, eStep, pSample);
				}

				pDlg->UpdateCtrlScenraioState(eCameraPos, eStep, pSample);

				//pDlg->m_TapMainScenario.SetStepState(eCameraPos, (TYPE_STEP)(eStep + 1));
			}
			else if (TYPE_STEP_007 == eStep)
			{
				// Inspection End: Send message 
				CSampleSide* pSample = pInspection->GetInspectionSample(eCameraPos).get();

				// Version 1.3.7.8
				if (TYPE_CAMERAPOS_FIRST == eCameraPos)
				{
					if (!pDlg->m_Sample1) pDlg->m_Sample1.reset(new CSampleSide());
					if (pDlg->m_Sample1 && pSample) pDlg->m_Sample1->CopyFrom(*pSample);
				}
				else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
				{
					if (!pDlg->m_Sample2) pDlg->m_Sample2.reset(new CSampleSide());
					if (pDlg->m_Sample2 && pSample) pDlg->m_Sample2->CopyFrom(*pSample);
				}
				//
				
				// Inspection End: Send message 
				int iDValue = 0;
				int iSValue = 0;
				// Version 1.3.6.5 (치수 영역 추가 없이 PLC 통신 데이터 추가 (X1-X2, L))
				int iLValue = 0;
				int iX1X2Value = 0;
				// Version 1.3.7.2 (M1, M2 데이터 통신 추가)
				int iM1Value = 0;
				int iM2Value = 0;
				// Version 1.3.7.4 (S1S3 데이터 통신 추가)
				int iS1S3Value = 0;

				// Version 1.3.7.9 Name 미설정인 경우 결과 상시 OK
				//for (int i = 0; i < MAX_GEOMETRY_DISTANCELINE_COUNT; i++)
				//{
				//	if (pstOption->m_stSizeName.m_szName[i][0] == '\0')
				//	{
				//		pSample->m_SizeCalculationResult.m_stDistance[i].m_bOK = TRUE;
				//	}
				//}

				// Version 1.3.6.5 (치수 영역 추가 없이 PLC 통신 데이터 추가 (X1-X2, L))
				pCaptureManager->SendInspectionResultCommand(eCameraPos, pSample, iDValue, iSValue, iLValue, iX1X2Value, iM1Value, iM2Value, iS1S3Value);

				//StepSizeCalc 측정치 업데이트
				pDlg->m_TapMainSize.UpdateResultSize(eCameraPos, pSample);
#ifdef USE_COUNT_TAB
				pDlg->m_TapMainCount.UpdateResultSize(eCameraPos, pSample);
#endif
				pDlg->UpdateCtrlScenraioState(eCameraPos, eStep, pSample);  //시퀀스 네모박스
				
				pDlg->m_TapMainScenario.UpdateResult(eCameraPos, eStep, pSample);		// Update Display
#ifdef USE_COUNT_TAB
				pDlg->m_TapMainCount.UpdateResult(eCameraPos, eStep, pSample);	// Update Display
#endif
				// Check & Write Image
				pDlg->DumpImageErrorResult(eCameraPos, eStep, pSample);


				////////////////////PLC
				if (TYPE_CAMERAPOS_FIRST == eCameraPos)
				{
					pCaptureManager->UpdateSummary(eCameraPos, pSample);
					pDlg->m_TapMainSummary.UpdateSummary();
				}
				else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
				{
					pCaptureManager->UpdateSummary(eCameraPos, pSample);
					pDlg->m_TapMainSummary.UpdateSummary();
					pDlg->m_TapMainSummary.UpdateTotalSummary();
				}

				int nResultSize = DEF_CMD_RESULT_OK;
				int nResultShape = DEF_CMD_RESULT_OK;
				int nResultAlarm = DEF_CMD_ALARM_OFF;

				if (TYPE_CAMERAPOS_FIRST == eCameraPos)
				{
					// Result - First Camera
					BOOL bSizeFirstRes = TRUE;
					BOOL bShapeFirstRes = TRUE;
					pDlg->CheckInspectionResult(eCameraPos, pSample, bSizeFirstRes, bShapeFirstRes);

					{
						if (FALSE == bSizeFirstRes) nResultSize = DEF_CMD_RESULT_NG;
						if (FALSE == bShapeFirstRes) nResultShape = DEF_CMD_RESULT_NG;

						// Version 1.3.7.2
						if (pstEtcOption->m_stLogInfo.m_bSaveOKImage == TRUE)
						{
							pDlg->DumpImageOKResult(eCameraPos, eStep, pSample);
						}
						// Version 1.3.7.6 
						if (pstEtcOption->m_stLogInfo.m_bSaveOKImage_Period)
						{
							pDlg->SetCurrentPeriodTime(eCameraPos);

							if (pDlg->CheckPeriod(eCameraPos, pstEtcOption->m_stLogInfo.m_nSavePeriodTime) == TRUE)
							{
								pDlg->SetPreviousPeriodTime(eCameraPos);
								pDlg->PeriodImageOKResult(eCameraPos, eStep, pSample);
							}
						}
					}
				}
				else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
				{
					// Result - Second Camera
					BOOL bSizeSecondRes = TRUE;
					BOOL bShapeSecondRes = TRUE;
					pDlg->CheckInspectionResult(eCameraPos, pSample, bSizeSecondRes, bShapeSecondRes);

					{
						if (FALSE == bSizeSecondRes)	nResultSize = DEF_CMD_RESULT_NG;
						if (FALSE == bShapeSecondRes)	nResultShape = DEF_CMD_RESULT_NG;

						// Version 1.3.7.2
						if (pstEtcOption->m_stLogInfo.m_bSaveOKImage == TRUE)
						{
							pDlg->DumpImageOKResult(eCameraPos, eStep, pSample);
							*(BOOL*)&pstEtcOption->m_stLogInfo.m_bSaveOKImage = FALSE;
						}
						// Version 1.3.7.6 
						if (pstEtcOption->m_stLogInfo.m_bSaveOKImage_Period)
						{
							pDlg->SetCurrentPeriodTime(eCameraPos);

							if (pDlg->CheckPeriod(eCameraPos, pstEtcOption->m_stLogInfo.m_nSavePeriodTime) == TRUE)
							{
								pDlg->SetPreviousPeriodTime(eCameraPos);
								pDlg->PeriodImageOKResult(eCameraPos, eStep, pSample);
							}
						}

						// Version 1.3.6.7
						if (CUtil::StringCompare((TCHAR*)&pstEtcOption->m_stLogInfo.m_szSaveImageFormat, ".png"))
						{
							if (pstEtcOption->m_stLogInfo.m_nFormatCount < pstEtcOption->m_stLogInfo.m_nUserSetCount - 1)
								*(int*)&pstEtcOption->m_stLogInfo.m_nFormatCount = pstEtcOption->m_stLogInfo.m_nFormatCount + 1;
							else if (pstEtcOption->m_stLogInfo.m_nFormatCount == pstEtcOption->m_stLogInfo.m_nUserSetCount - 1)
							{
								CUtil::StringCopy((TCHAR*)&pstEtcOption->m_stLogInfo.m_szSaveImageFormat, ".jpg");
								pCaptureManager->UpdateOptionEtc(pstEtcOption);
								*(int*)&pstEtcOption->m_stLogInfo.m_nFormatCount = pstEtcOption->m_stLogInfo.m_nFormatCount + 1;
							}
						}
					}
				}

				// Result Send
#ifdef USE_PLC_MXCOMPONENT			

				// Size result
				CString strDeviceName = pDlg->MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), eCameraPos - 1, TYPE_STATE_ALL_RESULTSIZE);
				pCaptureManager->LPMxComSetDevice(strDeviceName, nResultSize);

				// Shape result
				strDeviceName = pDlg->MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), eCameraPos - 1, TYPE_STATE_ALL_RESULTSHAPE, 0, pstOption, pSample);
				
				pCaptureManager->LPMxComSetDevice(strDeviceName, nResultShape);

				//2021-02-16 수정, S, D 퍼스트 세컨드 둘다 PLC에 전송
				//if (TYPE_CAMERAPOS_FIRST == eCameraPos)
				//{
					// Average S value
				strDeviceName = pDlg->MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), eCameraPos - 1, TYPE_STATE_ALL_AVERAGESIZE);
				pCaptureManager->LPMxComSetDevice(strDeviceName, iSValue);

				// D value
				strDeviceName = pDlg->MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), eCameraPos - 1, TYPE_STATE_ALL_VALUESIZE);
				pCaptureManager->LPMxComSetDevice(strDeviceName, iDValue);

				// Version 1.3.6.5 (치수 영역 추가 없이 PLC 통신 데이터 추가 (X1-X2, L))
				// L value
				strDeviceName = pDlg->MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), eCameraPos - 1, TYPE_STATE_ALL_LVALUESIZE);
				pCaptureManager->LPMxComSetDevice(strDeviceName, iLValue);

				// Version 1.3.6.5 (치수 영역 추가 없이 PLC 통신 데이터 추가 (X1-X2, L))
				// X1X2 value
				strDeviceName = pDlg->MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), eCameraPos - 1, TYPE_STATE_ALL_X1X2VALUESIZE);
				pCaptureManager->LPMxComSetDevice(strDeviceName, iX1X2Value);

				// Version 1.3.7.2 (M1, M2)
				strDeviceName = pDlg->MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), eCameraPos - 1, TYPE_STATE_ALL_M1VALUESIZE);
				pCaptureManager->LPMxComSetDevice(strDeviceName, iM1Value);

				// Version 1.3.7.2 (M1, M2)
				strDeviceName = pDlg->MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), eCameraPos - 1, TYPE_STATE_ALL_M2VALUESIZE);
				pCaptureManager->LPMxComSetDevice(strDeviceName, iM2Value);

				// Version 1.3.7.4 (S1S3)
				strDeviceName = pDlg->MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), eCameraPos - 1, TYPE_STATE_ALL_S1S3VALUESIZE);
				pCaptureManager->LPMxComSetDevice(strDeviceName, iS1S3Value);

				// Inspection end
				strDeviceName = pDlg->MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), eCameraPos - 1/*pCaptureManager->GetCurCameraPos()*/, TYPE_STATE_VISION_SENDINSPECTION);
				pCaptureManager->LPMxComSetDevice(strDeviceName, 2);

				if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
				{
					if (TYPE_CAMERAPOS_FIRST == eCameraPos)
						// Version 1.3.6.5 (치수 영역 추가 없이 PLC 통신 데이터 추가 (X1-X2, L))
						// Version 1.3.7.2 (M1, M2)
						// Version 1.3.7.4 (S1S3)
						stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, eCameraPos, "RESULT", "Inspection result: [Size: %d] [Shape: %d] [S: %d] [D: %d] [L: %d] [X1X2: %d] [M1: %d] [M2: %d] [S1S3: %d]", nResultSize, nResultShape, iSValue, iDValue, iLValue, iX1X2Value, iM1Value, iM2Value, iS1S3Value);
					else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
						// Version 1.3.7.4 (S1S3)
						//stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, eCameraPos, "RESULT", "Inspection result: [Size: %d] [Shape: %d]", nResultSize, nResultShape);
						stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, eCameraPos, "RESULT", "Inspection result: [Size: %d] [Shape: %d] [S: %d] [D: %d] [L: %d] [X1X2: %d] [M1: %d] [M2: %d] [S1S3: %d]", nResultSize, nResultShape, iSValue, iDValue, iLValue, iX1X2Value, iM1Value, iM2Value, iS1S3Value);
				}
				/////////////////////
#else
				// TODO: ��� ��� ���� �� ����
#endif
			}

			/*if (pInspection->IsWaitingAcquire(eCameraPos))
				pDlg->AcquireForInspection(eCameraPos, (TYPE_STEP)(eStep + 1));*/
		}
	}
	if (bCeptureFlag == TRUE){
		if (pInspection->IsWaitingAcquire(eCameraPos))
			pDlg->AcquireForInspection(eCameraPos, (TYPE_STEP)(eStep + 1));
	}
	return TRUE;
}

CNEPESDlg::CNEPESDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNEPESDlg::IDD, pParent)
{
	::InitializeCriticalSection(&m_CriticalSection);

	m_hMutex = NULL;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	memset(&m_rtTitle, 0x00, sizeof(RECT));
	memset(&m_rtView, 0x00, sizeof(RECT));

	m_pDlgSequence = NULL;
	m_pDlgConfig = NULL;

	m_MaxResolution = 0;

#ifdef USE_PLC_MXCOMPONENT
	m_nCurrentPLCCommunicationStep = 0;
	m_strSetDeviceName[0] = _T("");
	m_strSetDeviceName[1] = _T("");
	m_strSetDeviceName[2] = _T("");
	m_strGetDeviceName[0] = _T("");
	m_strGetDeviceName[1] = _T("");
	m_strGetDeviceName[2] = _T("");
	m_lGetValue[0] = 0;
	m_lGetValue[1] = 0;
	m_lGetValue[2] = 0;

	m_bTempLogState = FALSE;
	memset(m_nHeaterValue, sizeof(int) * PLC_HEATER_MAX, 0x00);

	m_bTRUE_Data = FALSE;
	m_nPLCMAP_VISIONKEEPALIVE_Timer = 0;
	m_nPLC_CHECKTEMPERATURE_Timer = 0;
	m_hPLCGetDataProcessThread = NULL;
	// Version 1.3.7.7
	m_hPLCGetDataProcessThreadTimeSync = NULL;

	m_bRequestedInspection = FALSE;
	m_bRealStartingInspectionPLC = FALSE;

	m_bRequestedInspectionSecond = FALSE;
	m_bRealStartingInspectionPLCSecond = FALSE;
#endif

	m_bChaningInspectionState = FALSE;

	m_nFirstResultPLCSettingDelayCount = FALSE;
	m_nSecondResultPLCSettingDelayCount = FALSE;

}

void CNEPESDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_MAINMESSAGE, m_ctlTitleMessage);
#ifdef DEF_SECONDCAMERA_CHECKSIZE
	//DDX_Control(pDX, IDC_STATIC_SIZETITLE, m_ctlStaticSize);
	//DDX_Control(pDX, IDC_BTN_RECYCLE, m_ctlBtnRecycle);
	//DDX_Control(pDX, IDC_STATIC_LINE_TYPE, m_ctlStaticLineType);

#endif
}

BOOL CNEPESDlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (IDOK == wParam)
	{
		return TRUE;
	}
	return CDialogEx::OnCommand(wParam, lParam);
}

BOOL CNEPESDlg::PreTranslateMessage(MSG* pMsg)
{
	if (WM_KEYDOWN == pMsg->message)
	{
		if (VK_ESCAPE == pMsg->wParam)
		{
			return TRUE;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

BOOL CNEPESDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	m_ctlTitleMessage.SetTextFont(_T("MS Shell Dlg"), 20, FW_BOLD);
	m_ctlTitleMessage.SetMessage(_T("NOT READY..."));

	//
	GetDlgItem(IDC_BTN_START)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_CLEAR_QUEUE)->EnableWindow(FALSE);
	//
	GetDlgItem(IDC_RADIO_MAINSUMMARY)->SetWindowText(STR_MAINVIEW_SUMMARY);
	GetDlgItem(IDC_RADIO_MAINSIZE)->SetWindowText(STR_MAINVIEW_SIZE);
	GetDlgItem(IDC_RADIO_MAINSCENARIO)->SetWindowText(STR_MAINVIEW_SCENARIO);
	GetDlgItem(IDC_RADIO_MAINCOUNT)->SetWindowText(STR_MAINVIEW_COUNT);
	GetDlgItem(IDC_BTN_CLEAR_QUEUE)->SetWindowText(STR_SUMMARY_BTN_CLEAR_QUEUE);

	((CButton*)GetDlgItem(IDC_RADIO_MAINSUMMARY))->SetCheck(BST_CHECKED);
	((CButton*)GetDlgItem(IDC_RADIO_MAINSIZE))->SetCheck(BST_UNCHECKED);
	((CButton*)GetDlgItem(IDC_RADIO_MAINSCENARIO))->SetCheck(BST_UNCHECKED);
	((CButton*)GetDlgItem(IDC_RADIO_MAINCOUNT))->SetCheck(BST_UNCHECKED);
	
	m_TapMainSummary.Create(CTapMainSummary::IDD, this);
	m_TapMainSize.Create(CTapMainSize::IDD, this);
	m_TapMainScenario.Create(CTapMainScenario::IDD, this);
#ifdef USE_COUNT_TAB
	m_TapMainCount.Create(CTapMainCount::IDD, this);
#endif

	//m_TapMainSummary.EnableWindow(FALSE);
	//m_TapMainSize.EnableWindow(FALSE);
	m_TapMainScenario.EnableWindow(FALSE);

	SetCurrentTapView(TYPE_TAPVIEW_SUMMARY);



	// Init Instance
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();
	// Print Log
	if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
		stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Initializing...");
	
	// Notify Event Handler
	pCaptureManager->SetCommunicateNotifyHandler(FuncNotifyEthernetListener, this);

	INFO_CAPTUREVIDEO stVideo;
	memset(&stVideo, 0x00, sizeof(INFO_CAPTUREVIDEO));
	stVideo.m_hWnd = this->m_hWnd;
	stVideo.m_pArqument = this;
	stVideo.m_VideoDev.m_eVideoDev = TYPE_VIDEODEV_CALLBACK;
	stVideo.m_VideoDev.m_FuncDisplayDev = CNEPESDlg::FuncDisplayVideoDevice;

	pCaptureManager->UpdateCaptureVideo(stVideo);


	AdjustLayout();

	UpdateMenuStatus();

	// Check Ethernet Adaptor Enable
#ifdef DEF_ETHERNET_SERVER
#	ifdef DEF_TIMER_CHECK_ADAPTOR
	SetTimer(TIMERID_ETHERNET, MSEC_CHECK_ADAPTOR, NULL);
#	endif
#endif

	// Size Test
	GetDlgItem(IDC_BTN_TESTSIZE)->SetWindowText(STR_MAINVIEW_BTN_SIZE_FIRST);
	GetDlgItem(IDC_BTN_TESTSIZE2)->SetWindowText(STR_MAINVIEW_BTN_SIZE_SECOND);

#ifdef USE_PLC_MXCOMPONENT
	pCaptureManager->SetNetPassMainDlgWnd(m_hWnd);

	HWND hWnd = ::FindWindow(NULL, TARGETWINDOWTITLE);
	if (hWnd)
	{
		pCaptureManager->SetTargetMXComModuleWnd(hWnd);
		pCaptureManager->LPMxComCloseProgram();

		Sleep(1500);
	}

	pCaptureManager->PLC_MXCOMPONENT_Module_Execution();

	SetTimer(TIMERID_CHECK_MXCOMPONENTMODULE, 5000, NULL);
#endif

	// MMTimer
	m_Timer.AttachListener(*(CMMTimerListener*)this);

	TIMECAPS TimeCaps;
	m_Timer.GetDevCaps(&TimeCaps);
	m_MaxResolution = TimeCaps.wPeriodMax;

	SetWindowText(NETPASSWINDOWTITLE);

	this->SetTimer(TIMERID, MSEC_INIT, NULL);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

BEGIN_MESSAGE_MAP(CNEPESDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_WM_GETMINMAXINFO()
	ON_WM_TIMER()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BTN_START, &CNEPESDlg::OnBnClickedBtnStart)

	// Command
	ON_MESSAGE(WM_NOTIFY_EDIT, &CNEPESDlg::OnMsgEdit)
	ON_MESSAGE(WM_NOTIFY_GRAB, &CNEPESDlg::OnMsgGrab)
	ON_MESSAGE(WM_NOTIFY_GRABEDIT, &CNEPESDlg::OnMsgGrabEdit)
	ON_MESSAGE(WM_NOTIFY_STROBE, &CNEPESDlg::OnMsgStrobe)
	ON_COMMAND(ID_FILE_START, &CNEPESDlg::OnCommandStart)
	ON_COMMAND(ID_FILE_STOP, &CNEPESDlg::OnCommandStop)
	ON_COMMAND(ID_FILE_EXIT, &CNEPESDlg::OnCommandExit)
	ON_COMMAND(ID_CONFIG_CONFIG, &CNEPESDlg::OnCommandConfig)
	ON_COMMAND(ID_CONFIG_CONFIGINSPECTION, &CNEPESDlg::OnCommandConfigInspection)
	ON_COMMAND(ID_CONFIG_OPTION, &CNEPESDlg::OnCommandOption)
	ON_COMMAND(ID_ABOUT_ABOUT, &CNEPESDlg::OnCommandAbout)

	ON_BN_CLICKED(IDC_RADIO_MAINSUMMARY, &CNEPESDlg::OnBnClickedRadioMainsummary)
	ON_BN_CLICKED(IDC_RADIO_MAINSIZE, &CNEPESDlg::OnBnClickedRadioMainsize)
	ON_BN_CLICKED(IDC_RADIO_MAINSCENARIO, &CNEPESDlg::OnBnClickedRadioMainscenario)
	ON_BN_CLICKED(IDC_RADIO_MAINCOUNT, &CNEPESDlg::OnBnClickedRadioMaincount)
	ON_BN_CLICKED(IDC_BTN_TESTSIZE, &CNEPESDlg::OnBnClickedBtnTestsize)
	ON_BN_CLICKED(IDC_BTN_TESTSIZE2, &CNEPESDlg::OnBnClickedBtnTestsize2)

	ON_WM_COPYDATA()
	ON_MESSAGE(WM_NOTIFY_CHECK_INSPECTIONENV_READY, &CNEPESDlg::OnMsgInspectionEnvReady)
	ON_BN_CLICKED(IDC_BTN_CLEAR_QUEUE, &CNEPESDlg::OnBnClickedBtnClearQueue)
	ON_BN_CLICKED(IDC_BTN_TEST_STEP2, &CNEPESDlg::OnBnClickedBtnTestStep2)
	ON_BN_CLICKED(IDC_BTN_TEST_STEP3, &CNEPESDlg::OnBnClickedBtnTestStep3)
	ON_BN_CLICKED(IDC_BTN_TEST_STEP4, &CNEPESDlg::OnBnClickedBtnTestStep4)
	ON_BN_CLICKED(IDC_BTN_TEST_STEP2_2, &CNEPESDlg::OnBnClickedBtnTestStep22)
	ON_BN_CLICKED(IDC_BTN_TEST_STEP3_2, &CNEPESDlg::OnBnClickedBtnTestStep32)
	ON_BN_CLICKED(IDC_BTN_TEST_STEP4_2, &CNEPESDlg::OnBnClickedBtnTestStep42)
END_MESSAGE_MAP()

// CNEPESDlg message handlers
HCURSOR CNEPESDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CNEPESDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CNEPESDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this); // device context for painting

		CRect rect;
		GetClientRect(&rect);

		const int nClientWidth = rect.Width();
		const int nClientHeight = rect.Height();

		CDC bmpDC;
		bmpDC.CreateCompatibleDC(&dc);

		HBITMAP hBitmap = ::LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BMP_LAONPEOPLE));
		if (hBitmap)
		{
			HBITMAP hOldBitmap = (HBITMAP)bmpDC.SelectObject(hBitmap);

			BITMAP bm;
			::GetObject(hBitmap, sizeof(BITMAP), &bm);

			dc.TransparentBlt(nClientWidth - bm.bmWidth - MARGIN * 2, MARGIN, bm.bmWidth, bm.bmHeight, &bmpDC, 0, 0, bm.bmWidth, bm.bmHeight, RGB(255, 255, 255));
			bmpDC.SelectObject(hOldBitmap);

			::DeleteObject(hBitmap);
			hBitmap = NULL;
		}

		//
		DrawLayout(&dc, m_rtTitle, RGB(200, 200, 200), IDB_STATIC_GUARD_LEFTTOP, IDB_STATIC_GUARD_LEFTBOTTOM, IDB_STATIC_GUARD_RIGHTTOP, IDB_STATIC_GUARD_RIGHTBOTTOM);

		CDialogEx::OnPaint();
	}
}

void CNEPESDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	AdjustLayout();
	this->Invalidate();
}

void CNEPESDlg::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	lpMMI->ptMinTrackSize.x = MINWIDTH;
	lpMMI->ptMinTrackSize.y = MINHEIGHT;

	CDialogEx::OnGetMinMaxInfo(lpMMI);
}

void CNEPESDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (TIMERID == nIDEvent)
	{
		this->KillTimer(TIMERID);

		// Check Camera Information...
		BOOL bFailToConfig = FALSE;
		if (FALSE == bFailToConfig)
		{
			ConfigDevices();
		}
	}

#ifdef DEF_TIMER_CHECK_ADAPTOR
	if (TIMERID_ETHERNET == nIDEvent && NULL == m_pDlgConfig)
	{
		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
		CEthernet* pEthernet = pCaptureManager->GetCommunicatePort();
		CEthernetServer* pEthernetServer = dynamic_cast<CEthernetServer*>(pEthernet);
		if (pEthernetServer && pEthernetServer->IsOpen())
		{
			BOOL bFound = FALSE;
			const TCHAR* pszIpAddr = pEthernetServer->GetIpAddress();
			{
				ULONG buflen = sizeof(IP_ADAPTER_INFO);
				IP_ADAPTER_INFO *pAdapterInfo = (IP_ADAPTER_INFO *)new BYTE[buflen];
				if (ERROR_BUFFER_OVERFLOW == ::GetAdaptersInfo(pAdapterInfo, &buflen))
				{
					delete[] pAdapterInfo;
					pAdapterInfo = (IP_ADAPTER_INFO *)new BYTE[buflen];
				}

				if (NO_ERROR == ::GetAdaptersInfo(pAdapterInfo, &buflen))
				{
					for (IP_ADAPTER_INFO *pAdapter = pAdapterInfo; pAdapter; pAdapter = pAdapter->Next)
					{
						if (CUtil::StringCompare((TCHAR*)pszIpAddr, PLC_DEFAULT_HOSTADDRESS) ||
							CUtil::StringCompare(pAdapter->IpAddressList.IpAddress.String, (TCHAR*)pszIpAddr))
						{
							bFound = TRUE;
							break;
						}
					}
				}
				if (pAdapterInfo)
				{
					delete[] pAdapterInfo;
				}
			}

			if (FALSE == bFound)
			{
				CInspection* pInspection = pCaptureManager->GetInspection();
				const BOOL bStart = pInspection->IsStart();
				if (bStart)
					OnBnClickedBtnStart();
				pCaptureManager->DeleteCommunicatePort();

				PostMessage(WM_COMMAND, ID_CONFIG_CONFIG, 0);
			}
		}
	}
#endif

#ifdef USE_PLC_MXCOMPONENT
	if (TIMERID_CHECK_MXCOMPONENTMODULE == nIDEvent)
	{
		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
		HWND hTargetMXComModuleWnd = ::FindWindow(NULL, TARGETWINDOWTITLE);
		if (!hTargetMXComModuleWnd)
			pCaptureManager->PLC_MXCOMPONENT_Module_Execution();
		pCaptureManager->SetTargetMXComModuleWnd(hTargetMXComModuleWnd);
	}
#endif

}

void CNEPESDlg::OnClose()
{
	CloseApplication();
}

void CNEPESDlg::OnBnClickedBtnStart()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_SUMMARY* pstSummary = pCaptureManager->GetResultSummary();
	INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();

	if(m_bChaningInspectionState)
	{
		if (pCaptureManager->GetInspection()->IsStart())
			AfxMessageBox(STR_MSG_CONTINUE_STOPACTION);
		else
			AfxMessageBox(STR_MSG_CONTINUE_STARTACTION);

		return;
	}

	m_bChaningInspectionState = TRUE;

	CString szLotId = pstSummary->m_szLotId;
	szLotId.Trim();

	if (1 > szLotId.GetLength())
	{
		AfxMessageBox(STR_MSG_FAIL_LOTID);

		((CButton*)GetDlgItem(IDC_RADIO_MAINSUMMARY))->SetCheck(BST_CHECKED);
		((CButton*)GetDlgItem(IDC_RADIO_MAINSIZE))->SetCheck(BST_UNCHECKED);
		((CButton*)GetDlgItem(IDC_RADIO_MAINSCENARIO))->SetCheck(BST_UNCHECKED);
		((CButton*)GetDlgItem(IDC_RADIO_MAINCOUNT))->SetCheck(BST_UNCHECKED);
		SetCurrentTapView(TYPE_TAPVIEW_SUMMARY);

		m_bChaningInspectionState = FALSE;

		return;
	}

	Inspection();

	UpdateCtrlStatus();
	UpdateMenuStatus();

	m_TapMainSummary.SetStateStartInspection();
	m_TapMainSize.SetStateStartInspection();

	// Version 1.3.6.6
	// Start Button Click -> Path Update
	// Stop Button -> No Acction
	if (pCaptureManager->GetInspection()->IsStart())
	{
		const INFO_OPTIONETC* pstOptEtc = pCaptureManager->GetOptionEtc();
		const INFO_SCENARIO* pstScenario = pCaptureManager->GetScenario();
		{
			CString FirstMonitoring = pstScenario->m_szFirstFilePath;
			CString SecondMonitoring = pstScenario->m_szSecondFilePath;
			CString OptionMonitoring = pCaptureManager->GetOptionFilePath();
			CString ImageFormatMonitoring = pstOptEtc->m_stLogInfo.m_szSaveImageFormat;
			m_TapMainCount.UpdateMonitoring(FirstMonitoring, SecondMonitoring, OptionMonitoring, ImageFormatMonitoring);

			// Version 1.3.7.6 Save OK Image Period
			SetPreviousPeriodTime(TYPE_CAMERAPOS_MAX);
			SetCurrentPeriodTime(TYPE_CAMERAPOS_MAX);
		}
	}
	m_bChaningInspectionState = FALSE;
	
}



// Message
LRESULT CNEPESDlg::OnMsgEdit(WPARAM wParam, LPARAM lParam) // WPARAM: Windows Handle
{
	LRESULT hRes = S_OK;

	CWnd* pWnd = (CWnd*)wParam;
	if (pWnd)
	{
		const TYPE_CAMERAPOS ePos = m_TapMainScenario.GetViewFromMessage(pWnd);
		//if (TYPE_CAMERAPOS_FIRST == ePos || TYPE_CAMERAPOS_SECOND == ePos)
		//{
			//ConfigScenario(ePos);
		//}

		// Version 1.3.7.8
		if		(TYPE_CAMERAPOS_FIRST == ePos)
		{
			CSampleSide* temp = m_Sample1.get();
			const INFO_IMAGE* pImage1 = m_stCachedImages.cam1_img1;
			const INFO_IMAGE* pImage2 = m_stCachedImages.cam1_img2;
			ConfigScenario(ePos, temp, pImage1, pImage2);
		}
		else if (TYPE_CAMERAPOS_SECOND == ePos)
		{
			CSampleSide* temp = m_Sample2.get();
			const INFO_IMAGE* pImage1 = m_stCachedImages.cam2_img1;
			const INFO_IMAGE* pImage2 = m_stCachedImages.cam2_img2;
			ConfigScenario(ePos, temp, pImage1, pImage2);
		}

	}
	return hRes;
}

LRESULT CNEPESDlg::OnMsgGrab(WPARAM wParam, LPARAM lParam)
{
	LRESULT hRes = S_OK;

	CWnd* pWnd = (CWnd*)wParam;
	if (pWnd)
	{
		const TYPE_CAMERAPOS ePos = m_TapMainScenario.GetViewFromMessage(pWnd);
		if (TYPE_CAMERAPOS_FIRST == ePos || TYPE_CAMERAPOS_SECOND == ePos)
		{
			CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

			pCaptureManager->SetSingleSnapCapture(TRUE);
			pCaptureManager->SetReadySnapCapture(ePos, FALSE);
		}
	}
	return hRes;
}

LRESULT CNEPESDlg::OnMsgGrabEdit(WPARAM wParam, LPARAM lParam)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	pCaptureManager->SetSingleSnapCapture(TRUE);
	pCaptureManager->SetReadySnapCapture((TYPE_CAMERAPOS)wParam, FALSE);

	return S_OK;
}

LRESULT CNEPESDlg::OnMsgStrobe(WPARAM wParam, LPARAM lParam)
{
	LRESULT hRes = S_OK;
	CWnd* pWnd = (CWnd*)wParam;
	if (pWnd)
	{
		const TYPE_CAMERAPOS ePos = m_TapMainScenario.GetViewFromMessage(pWnd);
		if (TYPE_CAMERAPOS_FIRST == ePos || TYPE_CAMERAPOS_SECOND == ePos)
		{
			CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
			CSerialCtrl* pSerialCtrl = pCaptureManager->GetStrobeControlPort(ePos);

			TYPE_STROBE eStrobe = (TYPE_STROBE)lParam;
			if (TYPE_STROBE_COXIAL == eStrobe || TYPE_STROBE_RING == eStrobe || TYPE_STROBE_BAR == eStrobe)
			{
				CDlgStrobeBrightness dlgStrobe;
				dlgStrobe.m_eCameraPos = ePos;
				dlgStrobe.m_eStrobe = eStrobe;
				if (IDOK == dlgStrobe.DoModal())
				{
					pCaptureManager->ControlStrobeBrightness(pSerialCtrl, ePos, eStrobe, dlgStrobe.m_nBrightness);
				}
			}
			else if (TYPE_STROBE_OFF == eStrobe)
			{
				pCaptureManager->ControlStrobeBrightness(pSerialCtrl, ePos, TYPE_STROBE_OFF, 0);
			}
			//pCaptureManager->ControlStrobeOnOff(pSerialCtrl, ePos, eStrobe);
		}
	}
	return hRes;
}


// Command Function - File
void CNEPESDlg::OnCommandStart()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	if (m_bChaningInspectionState)
	{
		if (pCaptureManager->GetInspection()->IsStart())
			AfxMessageBox(STR_MSG_CONTINUE_STOPACTION);
		else
			AfxMessageBox(STR_MSG_CONTINUE_STARTACTION);

		return;
	}

	m_bChaningInspectionState = TRUE;

	Inspection();

	UpdateCtrlStatus();
	UpdateMenuStatus();

	m_bChaningInspectionState = FALSE;
}

void CNEPESDlg::OnCommandStop()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	if (m_bChaningInspectionState)
	{
		if (pCaptureManager->GetInspection()->IsStart())
			AfxMessageBox(STR_MSG_CONTINUE_STOPACTION);
		else
			AfxMessageBox(STR_MSG_CONTINUE_STARTACTION);

		return;
	}
	m_bChaningInspectionState = TRUE;

	Inspection();

	UpdateCtrlStatus();
	UpdateMenuStatus();

	m_bChaningInspectionState = FALSE;
}

void CNEPESDlg::OnCommandExit()
{
	CloseApplication();
}

// Command Function - Config
void CNEPESDlg::OnCommandConfig()
{
	ConfigDevices();
}

void CNEPESDlg::OnCommandConfigInspection()
{
	ConfigOptionInsepction();
}

void CNEPESDlg::OnCommandOption()
{
	ConfigOption();
}


// Command Function - About
void CNEPESDlg::OnCommandAbout()
{
	CAboutDlg dlg;
	dlg.DoModal();
}

void CNEPESDlg::OnBnClickedRadioMainsummary()
{
	SetCurrentTapView(TYPE_TAPVIEW_SUMMARY);
}

void CNEPESDlg::OnBnClickedRadioMainsize()
{
	SetCurrentTapView(TYPE_TAPVIEW_SIZE);
}

void CNEPESDlg::OnBnClickedRadioMainscenario()
{
	SetCurrentTapView(TYPE_TAPVIEW_SCENARIO);
}

void CNEPESDlg::OnBnClickedRadioMaincount()
{
	SetCurrentTapView(TYPE_TAPVIEW_COUNT);
}

void CNEPESDlg::OnBnClickedBtnClearQueue()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	INFO_SUMMARY* pstSummary = pCaptureManager->GetResultSummary();

	pCaptureManager->ClearSummaryQueue();
	
	INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();
	// Print Log
	if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
		stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Sample extraction [SIZE:%d], [SHAPE:%d]", pstSummary->m_stSummaryTotal.m_nSampleCountErrorSize, pstSummary->m_stSummaryTotal.m_nSampleCountErrorShape);


	//CDlgExtractSample dlg;
	//dlg.DoModal();
}

void CNEPESDlg::ClickedBtnTestStep(TYPE_CAMERAPOS eCameraPos, TYPE_STEP eStep)
{
	CCustomScrollView* pScrollView = m_TapMainScenario.GetScrollView(eCameraPos);

	// Version 1.3.7.8 단일 검사 시 STEP_001 검사 후에 001, 007 이미지 취득 및 업로드 가능
	if (eStep == TYPE_STEP_001)
		pScrollView->SendMessage(WM_COMMAND, ID_VIEW_TEST_SIZE, 0);
	else if (eStep == TYPE_STEP_002)
		pScrollView->SendMessage(WM_COMMAND, ID_VIEW_TEST_STEP2, 0);
	else if (eStep == TYPE_STEP_003)
		pScrollView->SendMessage(WM_COMMAND, ID_VIEW_TEST_STEP3, 0);
	else if (eStep == TYPE_STEP_004)
		pScrollView->SendMessage(WM_COMMAND, ID_VIEW_TEST_STEP4, 0);

	{
		((CButton*)GetDlgItem(IDC_RADIO_MAINSUMMARY))->SetCheck(BST_UNCHECKED);
		((CButton*)GetDlgItem(IDC_RADIO_MAINSIZE))->SetCheck(BST_UNCHECKED);
		((CButton*)GetDlgItem(IDC_RADIO_MAINSCENARIO))->SetCheck(BST_CHECKED);
		((CButton*)GetDlgItem(IDC_RADIO_MAINCOUNT))->SetCheck(BST_UNCHECKED);
		SetCurrentTapView(TYPE_TAPVIEW_SCENARIO);
	}

	// Version 1.3.7.8
	if (TYPE_CAMERAPOS_FIRST == eCameraPos)
	{
		m_Sample1.reset(new CSampleSide());
		m_Sample1 = std::move(pScrollView->m_Sample);// ((CSampleSide*)pScrollView->m_Sample);
	}
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
	{
		m_Sample2.reset(new CSampleSide());
		m_Sample2 = std::move(pScrollView->m_Sample);
	}
}

void CNEPESDlg::OnBnClickedBtnTestsize()
{
	/*CCustomScrollView* pScrollView = m_TapMainScenario.GetScrollView(TYPE_CAMERAPOS_FIRST);

	pScrollView->SendMessage(WM_COMMAND, ID_VIEW_TEST_SIZE, 0);

	{
		((CButton*)GetDlgItem(IDC_RADIO_MAINSUMMARY))->SetCheck(BST_UNCHECKED);
		((CButton*)GetDlgItem(IDC_RADIO_MAINSIZE))->SetCheck(BST_UNCHECKED);
		((CButton*)GetDlgItem(IDC_RADIO_MAINSCENARIO))->SetCheck(BST_CHECKED);
		((CButton*)GetDlgItem(IDC_RADIO_MAINCOUNT))->SetCheck(BST_UNCHECKED);
		SetCurrentTapView(TYPE_TAPVIEW_SCENARIO);
	}*/
	ClickedBtnTestStep(TYPE_CAMERAPOS_FIRST, TYPE_STEP_001);
}

void CNEPESDlg::OnBnClickedBtnTestsize2()
{
	/*CCustomScrollView* pScrollView = m_TapMainScenario.GetScrollView(TYPE_CAMERAPOS_SECOND);

	pScrollView->SendMessage(WM_COMMAND, ID_VIEW_TEST_SIZE, 0);

	{
		((CButton*)GetDlgItem(IDC_RADIO_MAINSUMMARY))->SetCheck(BST_UNCHECKED);
		((CButton*)GetDlgItem(IDC_RADIO_MAINSIZE))->SetCheck(BST_UNCHECKED);
		((CButton*)GetDlgItem(IDC_RADIO_MAINSCENARIO))->SetCheck(BST_CHECKED);
		((CButton*)GetDlgItem(IDC_RADIO_MAINCOUNT))->SetCheck(BST_UNCHECKED);
		SetCurrentTapView(TYPE_TAPVIEW_SCENARIO);
	}*/
	ClickedBtnTestStep(TYPE_CAMERAPOS_SECOND, TYPE_STEP_001);
}

void CNEPESDlg::OnBnClickedBtnTestStep2()
{
	ClickedBtnTestStep(TYPE_CAMERAPOS_FIRST, TYPE_STEP_002);
}

void CNEPESDlg::OnBnClickedBtnTestStep3()
{
	ClickedBtnTestStep(TYPE_CAMERAPOS_FIRST, TYPE_STEP_003);
}

void CNEPESDlg::OnBnClickedBtnTestStep4()
{
	ClickedBtnTestStep(TYPE_CAMERAPOS_FIRST, TYPE_STEP_004);
}

void CNEPESDlg::OnBnClickedBtnTestStep22()
{
	ClickedBtnTestStep(TYPE_CAMERAPOS_SECOND, TYPE_STEP_002);
}

void CNEPESDlg::OnBnClickedBtnTestStep32()
{
	ClickedBtnTestStep(TYPE_CAMERAPOS_SECOND, TYPE_STEP_003);
}

void CNEPESDlg::OnBnClickedBtnTestStep42()
{
	ClickedBtnTestStep(TYPE_CAMERAPOS_SECOND, TYPE_STEP_004);
}

void CNEPESDlg::Inspection()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();
	INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();

	const BOOL bStart = pInspection->IsStart();
	if (bStart)
	{
		pInspection->Stop();

		//
		m_TapMainScenario.SetStepState(TYPE_CAMERAPOS_FIRST, TYPE_STEP_NONE);
		m_TapMainScenario.UpdateResult(TYPE_CAMERAPOS_FIRST, TYPE_STEP_NONE, NULL);

		m_TapMainScenario.SetStepState(TYPE_CAMERAPOS_SECOND, TYPE_STEP_NONE);
		m_TapMainScenario.UpdateResult(TYPE_CAMERAPOS_SECOND, TYPE_STEP_NONE, NULL);
#ifdef USE_COUNT_TAB
		m_TapMainCount.SetStepState(TYPE_CAMERAPOS_FIRST, TYPE_STEP_NONE);
		m_TapMainCount.UpdateResult(TYPE_CAMERAPOS_FIRST, TYPE_STEP_NONE, NULL);

		m_TapMainCount.SetStepState(TYPE_CAMERAPOS_SECOND, TYPE_STEP_NONE);
		m_TapMainCount.UpdateResult(TYPE_CAMERAPOS_SECOND, TYPE_STEP_NONE, NULL);
#endif

		// Off Strobe
		{
			CSerialCtrl* pSerialCtrl = NULL;
			pSerialCtrl = pCaptureManager->GetStrobeControlPort(TYPE_CAMERAPOS_FIRST);
			pCaptureManager->ControlStrobeOnOff(pSerialCtrl, TYPE_CAMERAPOS_FIRST, TYPE_STROBE_OFF);

			pSerialCtrl = pCaptureManager->GetStrobeControlPort(TYPE_CAMERAPOS_SECOND);
			pCaptureManager->ControlStrobeOnOff(pSerialCtrl, TYPE_CAMERAPOS_SECOND, TYPE_STROBE_OFF);
		}


		// Print Log
		{
			if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
			{
				const INFO_SUMMARY* pstSummary = pCaptureManager->GetResultSummary();
				CString szLotId = pstSummary->m_szLotId;
				szLotId.Trim();
				stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Stop Inspection (Lot:%s,)...", (LPCTSTR)szLotId);
			}
		}

#ifdef USE_PLC_MXCOMPONENT
		if (pCaptureManager->GetSelectLineInfo() == TYPE_LINE_1)
			AllClearPLCMemoryMap(TYPE_LINE_1);
		else if (pCaptureManager->GetSelectLineInfo() == TYPE_LINE_2)
			AllClearPLCMemoryMap(TYPE_LINE_2);
#endif
	}
	else
	{
#ifdef USE_PLC_MXCOMPONENT
		if (pCaptureManager->GetSelectLineInfo() == TYPE_LINE_1)
			AllClearPLCMemoryMap(TYPE_LINE_1);
		else if (pCaptureManager->GetSelectLineInfo() == TYPE_LINE_2)
			AllClearPLCMemoryMap(TYPE_LINE_2);

		/// First Camera Ready
		CString strDeviceName = MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), TYPE_POS_FIRST, TYPE_STATE_VISION_SENDINSPECTION);
		pCaptureManager->LPMxComSetDevice(strDeviceName, 0);

		// Print Log
		if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
			stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MX_PLC", "OUTPUT [%s, 0]", strDeviceName);

		/// Second Camera Ready
		strDeviceName = MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), TYPE_POS_SECOND, TYPE_STATE_VISION_SENDINSPECTION);
		pCaptureManager->LPMxComSetDevice(strDeviceName, 0);

		// Print Log
		if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
			stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MX_PLC", "OUTPUT [%s, 0]", strDeviceName);

#endif

		const INFO_OPTION* pstOption = pCaptureManager->GetOption();
		pInspection->UpdateEnableInspectionStep(&pstOption->m_stFirstCameraStep, &pstOption->m_stSecondCameraStep);

		BOOL bResult = pInspection->Start();
		if (bResult)
		{
			// Print Log
			{
				if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Start Inspection...");
			}
		}
		else
		{
			AfxMessageBox(STR_MSG_ESTART_INSPECTION);
			// Print Log
			{
				if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Fail to start Inspection...");
			}
		}
	}
}

void CNEPESDlg::AcquireForInspection(TYPE_CAMERAPOS eCameraPos, TYPE_STEP eStep)
{
	CUtil::PrintDebugString(_T("[%d] AcquireForInspection [%d] [%d] \r\n"), ::GetTickCount(), eCameraPos, eStep);

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_OPTION* pstOption = pCaptureManager->GetOption();

	CSerialCtrl* pStrobeControl = pCaptureManager->GetStrobeControlPort(eCameraPos);
	INFO_STEPSTROBE pstStepStrobe[MAX_STEPSTROBE_LIST];	
	memset(pstStepStrobe, 0x00, sizeof(INFO_STEPSTROBE) * MAX_STEPSTROBE_LIST);

	INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();
	CInspection* pInspection = pCaptureManager->GetInspection();
	CStep* pStep = pInspection->GetInsectionStep(eCameraPos, eStep);

	if (TYPE_STEP_001 == eStep)
	{
		CStepSize* pStepSize = dynamic_cast<CStepSize*>(pStep);

		const INFO_INSPECTION_SIZE* pInfoSize = pStepSize->GetInformation();
		for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
		{
			pstStepStrobe[i].m_eStrobeType = pInfoSize->m_pstStepStrobe[i].m_eStrobeType;
			pstStepStrobe[i].m_nStrobeBrightness = pInfoSize->m_pstStepStrobe[i].m_nStrobeBrightness;
		}
	}
	else if (TYPE_STEP_002 == eStep)
	{
		CStepStain* pStepStain = dynamic_cast<CStepStain*>(pStep);

		const INFO_INSPECTION_STAIN* pInfoStain = pStepStain->GetInformation();
		for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
		{
			pstStepStrobe[i].m_eStrobeType = pInfoStain->m_pstStepStrobe[i].m_eStrobeType;
			pstStepStrobe[i].m_nStrobeBrightness = pInfoStain->m_pstStepStrobe[i].m_nStrobeBrightness;
		}
	}
	else if (TYPE_STEP_003 == eStep)
	{
		CStepDiffer* pStepDiffer = dynamic_cast<CStepDiffer*>(pStep);

		const INFO_INSPECTION_DIFFER* pInfoDiffer = pStepDiffer->GetInformation();
		for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
		{
			pstStepStrobe[i].m_eStrobeType = pInfoDiffer->m_pstStepStrobe[i].m_eStrobeType;
			pstStepStrobe[i].m_nStrobeBrightness = pInfoDiffer->m_pstStepStrobe[i].m_nStrobeBrightness;
		}
	}
	else if (TYPE_STEP_004 == eStep)
	{
		CStepBubble* pStepBubble = dynamic_cast<CStepBubble*>(pStep);

		const INFO_INSPECTION_BUBBLE* pInfoBubble = pStepBubble->GetInformation();
		for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
		{
			pstStepStrobe[i].m_eStrobeType = pInfoBubble->m_pstStepStrobe[i].m_eStrobeType;
			pstStepStrobe[i].m_nStrobeBrightness = pInfoBubble->m_pstStepStrobe[i].m_nStrobeBrightness;
		}
	}
	else if (TYPE_STEP_005 == eStep)
	{
		CStepScratch* pStepScratch = dynamic_cast<CStepScratch*>(pStep);

		const INFO_INSPECTION_SCRATCH* pInfoScratch = pStepScratch->GetInformation();
		for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
		{
			pstStepStrobe[i].m_eStrobeType = pInfoScratch->m_pstStepStrobe[i].m_eStrobeType;
			pstStepStrobe[i].m_nStrobeBrightness = pInfoScratch->m_pstStepStrobe[i].m_nStrobeBrightness;
		}
	}
	else if (TYPE_STEP_006 == eStep)
	{
		CStepStamp* pStepStamp = dynamic_cast<CStepStamp*>(pStep);

		const INFO_INSPECTION_STAMP* pInfoStamp = pStepStamp->GetInformation();
		for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
		{
			pstStepStrobe[i].m_eStrobeType = pInfoStamp->m_pstStepStrobe[i].m_eStrobeType;
			pstStepStrobe[i].m_nStrobeBrightness = pInfoStamp->m_pstStepStrobe[i].m_nStrobeBrightness;
		}
	}

	else if (TYPE_STEP_007 == eStep)
	{
		//pStep = pInspection->GetInsectionStep(eCameraPos, TYPE_STEP_001);

		CStepSizeSecond* pStepSizeSecond = dynamic_cast<CStepSizeSecond*>(pStep);

		//CStepSize* pStepSize = dynamic_cast<CStepSize*>(pStep);

		const INFO_INSPECTION_SIZE* pInfoSizeSecond = pStepSizeSecond->GetInformation();
		for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
		{
			pstStepStrobe[i].m_eStrobeType = pInfoSizeSecond->m_pstStepStrobe[i].m_eStrobeType;
			pstStepStrobe[i].m_nStrobeBrightness = pInfoSizeSecond->m_pstStepStrobe[i].m_nStrobeBrightness;
		}
	}

	BOOL bCapture = FALSE;
	if (TYPE_CAMERAPOS_FIRST == eCameraPos)
	{
		if (TYPE_STEP_001 == eStep ||
			TYPE_STEP_002 == eStep && pstOption->m_stFirstCameraStep.m_bStep002 ||
			TYPE_STEP_003 == eStep && pstOption->m_stFirstCameraStep.m_bStep003 ||
			TYPE_STEP_004 == eStep && pstOption->m_stFirstCameraStep.m_bStep004 ||
			TYPE_STEP_005 == eStep && pstOption->m_stFirstCameraStep.m_bStep005 ||
			TYPE_STEP_006 == eStep && pstOption->m_stFirstCameraStep.m_bStep006 ||
			TYPE_STEP_007 == eStep && pstOption->m_stFirstCameraStep.m_bStep001)
		{
			bCapture = TRUE;
		}
	}
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
	{
#ifdef DEF_SECONDCAMERA_CHECKSIZE
		if (TYPE_STEP_001 == eStep ||
			TYPE_STEP_002 == eStep && pstOption->m_stSecondCameraStep.m_bStep002 ||
#else
		if (TYPE_STEP_002 == eStep && pstOption->m_stSecondCameraStep.m_bStep002 ||
#endif
			TYPE_STEP_003 == eStep && pstOption->m_stSecondCameraStep.m_bStep003 ||
			TYPE_STEP_004 == eStep && pstOption->m_stSecondCameraStep.m_bStep004 ||
			TYPE_STEP_005 == eStep && pstOption->m_stSecondCameraStep.m_bStep005 ||
			TYPE_STEP_006 == eStep && pstOption->m_stSecondCameraStep.m_bStep006 ||
			TYPE_STEP_007 == eStep && pstOption->m_stSecondCameraStep.m_bStep001)
		{
			bCapture = TRUE;
		}
	}

	if (bCapture)
	{
		// Off Strobe
		//pCaptureManager->ControlStrobeOnOff(pStrobeControl, eCameraPos, TYPE_STROBE_OFF);
		// Strobe Control
		std::set<TYPE_STROBE> StepStrobeOff;
		StepStrobeOff.insert(TYPE_STROBE_COXIAL);
		StepStrobeOff.insert(TYPE_STROBE_RING);
		StepStrobeOff.insert(TYPE_STROBE_BAR);
		//for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
		//{
		//	TYPE_STROBE eStrobeType = pstStepStrobe[i].m_eStrobeType;
		//	int nBrightness = pstStepStrobe[i].m_nStrobeBrightness;
		//	if (TYPE_STROBE_COXIAL == eStrobeType || TYPE_STROBE_RING == eStrobeType || TYPE_STROBE_BAR == eStrobeType)
		//	{
		//		if (TYPE_STEP_001 == eStep && FALSE == pstOption->m_stFirstCameraStep.m_bStep001)
		//		{
		//			// strobe: do nothing.
		//		}
		//		else
		//		{
		//			//pCaptureManager->ControlStrobeOnOff(pStrobeControl, eCameraPos, eStrobeType);
		//			pCaptureManager->ControlStrobeBrightness(pStrobeControl, eCameraPos, eStrobeType, nBrightness);
		//		}
		//	}
		//}
		int nBrightness_COXIAL = 0;
		int nBrightness_RING = 0;
		int	nBrightness_BAR = 0;

		for (int i = 0; i < MAX_STEPSTROBE_LIST; i++){
			if (pstStepStrobe[i].m_eStrobeType == TYPE_STROBE_COXIAL)
				nBrightness_COXIAL = pstStepStrobe[i].m_nStrobeBrightness;
			else if (pstStepStrobe[i].m_eStrobeType == TYPE_STROBE_RING)
				nBrightness_RING = pstStepStrobe[i].m_nStrobeBrightness;
			else if (pstStepStrobe[i].m_eStrobeType == TYPE_STROBE_BAR)
				nBrightness_BAR = pstStepStrobe[i].m_nStrobeBrightness;
			StepStrobeOff.erase(pstStepStrobe[i].m_eStrobeType);
		}

		for (auto element : StepStrobeOff){
			if (element == TYPE_STROBE_COXIAL)
				nBrightness_COXIAL = 0;
			else if (element == TYPE_STROBE_RING)
				nBrightness_RING = 0;
			else if (element == TYPE_STROBE_BAR)
				nBrightness_BAR = 0;
		}

		pCaptureManager->ControlStrobeBrightness(pStrobeControl, eCameraPos, nBrightness_COXIAL, nBrightness_RING, nBrightness_BAR);

#ifdef DEF_DELAY_CAPTURE
		int delay = pstOption->m_stCapture.m_nDelay;
		if (delay > 0)
			CUtil::WaitnSleep(delay);
#endif
	}
	// Acquisition
	pCaptureManager->SetSingleSnapCapture(TRUE);
	pCaptureManager->SetReadySnapCapture(eCameraPos, FALSE);
}

void CNEPESDlg::AdjustLayout()
{
	if (NULL == m_ctlTitleMessage.GetSafeHwnd())
		return;

	CRect rtClient;
	this->GetClientRect(rtClient);

	const int nClientWidth = rtClient.Width();
	const int nClientHeight = rtClient.Height();

	//
	m_rtTitle.left = MARGIN;
	m_rtTitle.top = MARGIN;
	m_rtTitle.right = nClientWidth - 150 - MARGIN * 3;
	m_rtTitle.bottom = 50 + MARGIN * 3;

	//
	m_rtView.left = 0;
	m_rtView.top = m_rtTitle.bottom + MARGIN * 2;
	m_rtView.right = rtClient.right;
	m_rtView.bottom = rtClient.bottom - MARGIN;


	m_TapMainSummary.MoveWindow(&m_rtView);

	m_TapMainSize.MoveWindow(&m_rtView);
	m_TapMainScenario.MoveWindow(&m_rtView);
#ifdef USE_COUNT_TAB
	m_TapMainCount.MoveWindow(&m_rtView);
#endif

	{
		CRect rtStart;
		GetDlgItem(IDC_BTN_START)->GetWindowRect(rtStart);
		ScreenToClient(rtStart);


	

		CRect rtStep04_2;
		rtStep04_2.top = rtStart.top;
		rtStep04_2.bottom = rtStart.bottom;
		rtStep04_2.right = nClientWidth - 180;
		rtStep04_2.left = rtStep04_2.right - rtStart.Width() + 30;
		GetDlgItem(IDC_BTN_TEST_STEP4_2)->MoveWindow(rtStep04_2);

		CRect rtStep03_2;
		rtStep03_2.top = rtStart.top;
		rtStep03_2.bottom = rtStart.bottom;
		rtStep03_2.right = rtStep04_2.left - MARGIN;
		rtStep03_2.left = rtStep03_2.right - rtStep04_2.Width();
		GetDlgItem(IDC_BTN_TEST_STEP3_2)->MoveWindow(rtStep03_2);

		CRect rtStep02_2;
		rtStep02_2.top = rtStart.top;
		rtStep02_2.bottom = rtStart.bottom;
		rtStep02_2.right = rtStep03_2.left - MARGIN;
		rtStep02_2.left = rtStep02_2.right - rtStep04_2.Width();
		GetDlgItem(IDC_BTN_TEST_STEP2_2)->MoveWindow(rtStep02_2);

		CRect rtSize02;
		rtSize02.top = rtStart.top;
		rtSize02.bottom = rtStart.bottom;
		rtSize02.right = rtStep02_2.left - MARGIN;
		rtSize02.left = rtSize02.right - rtStart.Width();
		GetDlgItem(IDC_BTN_TESTSIZE2)->MoveWindow(rtSize02);
		
		CRect rtSize01;
		rtSize01.top = rtStart.top;
		rtSize01.bottom = rtStart.bottom;
		rtSize01.left = rtStart.right + 300;
		rtSize01.right = rtSize01.left + rtStart.Width();
		GetDlgItem(IDC_BTN_TESTSIZE)->MoveWindow(rtSize01);

		CRect rtStep02;
		rtStep02.top = rtStart.top;
		rtStep02.bottom = rtStart.bottom;
		rtStep02.left = rtSize01.right + MARGIN;
		rtStep02.right = rtStep02.left + rtStep04_2.Width();
		GetDlgItem(IDC_BTN_TEST_STEP2)->MoveWindow(rtStep02);
		
		CRect rtStep03;
		rtStep03.top = rtStart.top;
		rtStep03.bottom = rtStart.bottom;
		rtStep03.left = rtStep02.right + MARGIN;
		rtStep03.right = rtStep03.left + rtStep04_2.Width();
		GetDlgItem(IDC_BTN_TEST_STEP3)->MoveWindow(rtStep03);

		CRect rtStep04;
		rtStep04.top = rtStart.top;
		rtStep04.bottom = rtStart.bottom;
		rtStep04.left = rtStep03.right + MARGIN;
		rtStep04.right = rtStep04.left + rtStep04_2.Width();
		GetDlgItem(IDC_BTN_TEST_STEP4)->MoveWindow(rtStep04);
		
		CRect rtQueue;
		rtQueue.top = rtStart.top;
		rtQueue.bottom = rtStart.bottom;
		rtQueue.left = ((rtStep04.right + rtSize02.left) / 2) - (rtStart.Width() / 2);
		rtQueue.right = rtQueue.left + rtStart.Width();
		GetDlgItem(IDC_BTN_CLEAR_QUEUE)->MoveWindow(rtQueue);

#ifdef DEF_SECONDCAMERA_CHECKSIZE
		CRect rtTitleSize;
		ScreenToClient(rtTitleSize);

		rtTitleSize.left = rtStart.left - MARGIN * 0.5;
		rtTitleSize.right = rtStart.right + MARGIN * 6;
#endif

	}


	RECT rtMsg;
	m_ctlTitleMessage.GetWindowRect(&rtMsg);
	this->ScreenToClient(&rtMsg);
	rtMsg.right = rtClient.right - 180;
	m_ctlTitleMessage.MoveWindow(&rtMsg);

	this->Invalidate(FALSE);
}

void CNEPESDlg::DrawLayout(CDC* pDC, CRect rect, COLORREF rgbBk, DWORD dwLT, DWORD dwLB, DWORD dwRT, DWORD dwRB)
{
	if (NULL == pDC)
		return;

	CRect rtClient = rect;
	{
		CPen pen;
		pen.CreatePen(PS_SOLID, 3, rgbBk);
		CPen* pOldPen = pDC->SelectObject(&pen);

		const int gap = 2;

		pDC->MoveTo(rtClient.left + gap, rtClient.top + gap);
		pDC->LineTo(rtClient.right - gap, rtClient.top + gap);
		pDC->LineTo(rtClient.right - gap, rtClient.bottom - gap);
		pDC->LineTo(rtClient.left + gap, rtClient.bottom - gap);
		pDC->LineTo(rtClient.left + gap, rtClient.top + gap);
	}

	const int w = rtClient.Width();
	const int h = rtClient.Height();

	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);

	BITMAP bm;
	HBITMAP hBmpLeftTop = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(dwLT));
	if (hBmpLeftTop)
	{
		::GetObject(hBmpLeftTop, sizeof(BITMAP), &bm);

		HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpLeftTop);
		pDC->BitBlt(rtClient.left, rtClient.top, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

		MemDC.SelectObject(hOld);
		::DeleteObject(hBmpLeftTop);
	}

	HBITMAP hBmpLeftBottom = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(dwLB));
	if (hBmpLeftBottom)
	{
		::GetObject(hBmpLeftBottom, sizeof(BITMAP), &bm);

		HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpLeftBottom);
		pDC->BitBlt(rtClient.left, rtClient.bottom - bm.bmHeight, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

		MemDC.SelectObject(hOld);
		::DeleteObject(hBmpLeftBottom);
	}

	HBITMAP hBmpRightTop = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(dwRT));
	if (hBmpRightTop)
	{
		::GetObject(hBmpRightTop, sizeof(BITMAP), &bm);

		HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpRightTop);
		pDC->BitBlt(rtClient.right - bm.bmWidth, rtClient.top, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

		MemDC.SelectObject(hOld);
		::DeleteObject(hBmpRightTop);
	}

	HBITMAP hBmpRightBottom = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(dwRB));
	if (hBmpRightBottom)
	{
		::GetObject(hBmpRightBottom, sizeof(BITMAP), &bm);

		HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpRightBottom);
		pDC->BitBlt(rtClient.right - bm.bmWidth, rtClient.bottom - bm.bmHeight, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

		MemDC.SelectObject(hOld);
		::DeleteObject(hBmpRightBottom);
	}
}

void CNEPESDlg::CloseApplication()
{
	// 
	static BOOL bStaticClose = FALSE;
	if (bStaticClose)
		return;

	if (IDCANCEL == AfxMessageBox(STR_MSG_CLOSE, MB_OKCANCEL))
		return;

	bStaticClose = TRUE;

	// Release Instance
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

#ifdef USE_PLC_MXCOMPONENT
	KillTimer(TIMERID_CHECK_MXCOMPONENTMODULE);
	pCaptureManager->LPMxComCloseProgram();

	PLCGetDataProcessThreadAllClose();

	if (m_nPLCMAP_VISIONKEEPALIVE_Timer)
		KillTimer(m_nPLCMAP_VISIONKEEPALIVE_Timer);
	if (m_nPLC_CHECKTEMPERATURE_Timer)
		KillTimer(m_nPLC_CHECKTEMPERATURE_Timer);
	if (m_Timer.IsRunning())
		m_Timer.Stop();

#endif

	CInspection* pInspection = pCaptureManager->GetInspection();
	if (pInspection)
	{
		pInspection->Stop();
	}

	pCaptureManager->ReleaseInstance();

	::DeleteCriticalSection(&m_CriticalSection);
	CDialogEx::OnOK();
}

void CNEPESDlg::ConfigDevices()
{
#ifdef DEF_FREERUN_CAPTURE
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	pCaptureManager->SetReadySnapCapture(FALSE);
#endif

	CDlgConfig dlg;
	m_pDlgConfig = &dlg;
	dlg.DoModal();
	m_pDlgConfig = NULL;

	CDlgMessage dlgMessage;
	dlgMessage.SetLoadType(TYPE_LOAD_INSPECTIONENV_READY);
	dlgMessage.SetTargetWnd(m_hWnd);
	dlgMessage.DoModal();
}

LRESULT CNEPESDlg::OnMsgInspectionEnvReady(WPARAM wParam, LPARAM lParam)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	BOOL bReady = FALSE;
	if (pCaptureManager->IsReadyInspectionDevice())
	{
		CInspection* pInspction = pCaptureManager->GetInspection();
		if (FALSE == pInspction->IsInit())
		{
			INFO_NOTIFY_INSPECTION stNotify;
			stNotify.m_pFuncNotifyInspectionResult = FuncNotifyInspectionResult;
			stNotify.m_pArgument = this;

			// Log Function & Argument
			INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();

			const INFO_INSPECTION* pstFirstInspect = pCaptureManager->GetInspectionInfo(TYPE_CAMERAPOS_FIRST);
			const INFO_INSPECTION* pstSecondInspect = pCaptureManager->GetInspectionInfo(TYPE_CAMERAPOS_SECOND);

			// Init Library
			bReady = pInspction->Init(this->m_hWnd, pstFirstInspect, pstSecondInspect, &stNotify, stLogFunc);
			if (FALSE == bReady)
			{
				AfxMessageBox(STR_MSG_EINIT_LIBRARY);
			}
		}
		else
		{
			const INFO_INSPECTION* pstFirstInspect = pCaptureManager->GetInspectionInfo(TYPE_CAMERAPOS_FIRST);
			const INFO_INSPECTION* pstSecondInspect = pCaptureManager->GetInspectionInfo(TYPE_CAMERAPOS_SECOND);

			bReady = pInspction->Update(pstFirstInspect, pstSecondInspect);
			if (FALSE == bReady)
			{
				AfxMessageBox(STR_MSG_EINIT_LIBRARY);
			}
		}
	}
	else
	{
		CInspection* pInspction = pCaptureManager->GetInspection();
		pInspction->Deinit();
	}
	bReady = TRUE;
	m_TapMainScenario.EnableWindow(bReady);

#ifdef DEF_FREERUN_CAPTURE
	pCaptureManager->SetReadySnapCapture(TRUE);
#endif

	m_TapMainSize.UpdateRangeValue(TYPE_CAMERAPOS_FIRST);
	m_TapMainSize.UpdateSizeName();
	m_TapMainSummary.UpdateTitleStep();
	m_TapMainSummary.UpdateSizeName();
#ifdef USE_COUNT_TAB
	m_TapMainCount.UpdateRangeValue(TYPE_CAMERAPOS_FIRST);
	m_TapMainCount.UpdateSizeName();
#endif

	UpdateOptionFilePath();
	UpdateMenuStatus();

	return S_OK;
}

void CNEPESDlg::ConfigScenario(const TYPE_CAMERAPOS ePos)
{
	TYPE_CAMERAPOS eCameraType = ePos;
	if (TYPE_CAMERAPOS_FIRST != eCameraType && TYPE_CAMERAPOS_SECOND != eCameraType)
		return;

	CCustomScrollView* pScrollView = m_TapMainScenario.GetScrollView(eCameraType);
	const INFO_IMAGE* pImage = pScrollView->GetDisplayImage();
	if (NULL == pImage)
	{
		{
			const TYPE_CAMERAPOS ePos = pScrollView->GetCameraPos();
			if (TYPE_CAMERAPOS_FIRST == ePos || TYPE_CAMERAPOS_SECOND == ePos)
			{
				CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

				pCaptureManager->SetSingleSnapCapture(TRUE);
				pCaptureManager->SetReadySnapCapture(ePos, FALSE);
			}
			CUtil::WaitnSleep(100);
		}

		///
		CUtil::WaitnSleep(300);
		pImage = pScrollView->GetDisplayImage();
		if (NULL == pImage)
		{
			AfxMessageBox(STR_MSG_ELOAD_IMAGE);
			return;
		}
	}

	CDlgSequence dlg;
	dlg.UpdateInformation(eCameraType, pImage);

	m_pDlgSequence = &dlg;			// Just Check for Popup...
	if (IDOK == dlg.DoModal())
	{

	}
	m_pDlgSequence = NULL;

}

// Version 1.3.7.8
void CNEPESDlg::ConfigScenario(const TYPE_CAMERAPOS ePos, CSampleSide* sample, const INFO_IMAGE* pImageFirst, const INFO_IMAGE* pImageSecond)
{
	TYPE_CAMERAPOS eCameraType = ePos;
	if (TYPE_CAMERAPOS_FIRST != eCameraType && TYPE_CAMERAPOS_SECOND != eCameraType)
		return;

	CCustomScrollView* pScrollView = m_TapMainScenario.GetScrollView(eCameraType);
	const INFO_IMAGE* pImage = pScrollView->GetDisplayImage();
	if (NULL == pImage)
	{
		{
			const TYPE_CAMERAPOS ePos = pScrollView->GetCameraPos();
			if (TYPE_CAMERAPOS_FIRST == ePos || TYPE_CAMERAPOS_SECOND == ePos)
			{
				CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

				pCaptureManager->SetSingleSnapCapture(TRUE);
				pCaptureManager->SetReadySnapCapture(ePos, FALSE);
			}
			CUtil::WaitnSleep(100);
		}

		///
		CUtil::WaitnSleep(300);
		pImage = pScrollView->GetDisplayImage();
		if (NULL == pImage)
		{
			AfxMessageBox(STR_MSG_ELOAD_IMAGE);
			return;
		}
	}

	const INFO_IMAGE* pImage1 = pImageFirst;
	const INFO_IMAGE* pImage2 = pImageSecond;
	if (NULL == pImage && NULL == pImage1 && NULL == pImage2)
	{
		AfxMessageBox(STR_MSG_ELOAD_IMAGE);
		return;	
	}

	CDlgSequence dlg;
	dlg.UpdateInformation(eCameraType, sample, pImage, pImage1, pImage2);

	m_pDlgSequence = &dlg;
	if (IDOK == dlg.DoModal())
	{

	}
	m_pDlgSequence = NULL;

}


void CNEPESDlg::ConfigOptionInsepction()
{
	CDlgOption dlg;
	if (IDOK == dlg.DoModal())
	{
		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
		pCaptureManager->UpdateOption(&dlg.m_stOption);
		pCaptureManager->SetOptionFilePath((LPCTSTR)dlg.m_szFilePath);

		{
			INFO_OPTION stOption = dlg.m_stOption;

			INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();
			// Print Log
			{
				if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
				{
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Change option value...");

#ifdef DEF_DELAY_CAPTURE
					CString szDelay;
					szDelay.Format(_T("%d"), stOption.m_stCapture.m_nDelay);
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Capture Delay (%s)", (LPCTSTR)szDelay);
#endif
					CString szCount;
					CString szRatio;
					szCount.Format(_T("%d"), stOption.m_stSampleA.m_nMinCount);
					szRatio.Format(_T("%f"), stOption.m_stSampleA.m_fAlarmRatio);
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Sample A - Alarm (%s, %s)", (LPCTSTR)szCount, (LPCTSTR)szRatio);

					szCount.Format(_T("%d"), stOption.m_stSampleB.m_nMinCount);
					szRatio.Format(_T("%f"), stOption.m_stSampleB.m_fAlarmRatio);
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Sample B - Alarm (%s, %s)", (LPCTSTR)szCount, (LPCTSTR)szRatio);


					// 아래 치수 명은 개발자 확인용 로그이므로 변경된 이름이 아닌 기본 이름을 사용함
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Range (First)");
					CString szMinMax;
					int idx = 0;

					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_01, stOption.m_pstRange[0][idx].m_fMin, stOption.m_pstRange[0][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_02, stOption.m_pstRange[0][idx].m_fMin, stOption.m_pstRange[0][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_03, stOption.m_pstRange[0][idx].m_fMin, stOption.m_pstRange[0][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_04, stOption.m_pstRange[0][idx].m_fMin, stOption.m_pstRange[0][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_05, stOption.m_pstRange[0][idx].m_fMin, stOption.m_pstRange[0][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_06, stOption.m_pstRange[0][idx].m_fMin, stOption.m_pstRange[0][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_07, stOption.m_pstRange[0][idx].m_fMin, stOption.m_pstRange[0][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_08, stOption.m_pstRange[0][idx].m_fMin, stOption.m_pstRange[0][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_09, stOption.m_pstRange[0][idx].m_fMin, stOption.m_pstRange[0][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_10, stOption.m_pstRange[0][idx].m_fMin, stOption.m_pstRange[0][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_11, stOption.m_pstRange[0][idx].m_fMin, stOption.m_pstRange[0][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_12, stOption.m_pstRange[0][idx].m_fMin, stOption.m_pstRange[0][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_13, stOption.m_pstRange[0][idx].m_fMin, stOption.m_pstRange[0][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_14, stOption.m_pstRange[0][idx].m_fMin, stOption.m_pstRange[0][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_15, stOption.m_pstRange[0][idx].m_fMin, stOption.m_pstRange[0][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_16, stOption.m_pstRange[0][idx].m_fMin, stOption.m_pstRange[0][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_17, stOption.m_pstRange[0][idx].m_fMin, stOption.m_pstRange[0][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_18, stOption.m_pstRange[0][idx].m_fMin, stOption.m_pstRange[0][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);

					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Range (Second)");
					idx = 0;

					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_01, stOption.m_pstRange[1][idx].m_fMin, stOption.m_pstRange[1][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_02, stOption.m_pstRange[1][idx].m_fMin, stOption.m_pstRange[1][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_03, stOption.m_pstRange[1][idx].m_fMin, stOption.m_pstRange[1][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_04, stOption.m_pstRange[1][idx].m_fMin, stOption.m_pstRange[1][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_05, stOption.m_pstRange[1][idx].m_fMin, stOption.m_pstRange[1][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_06, stOption.m_pstRange[1][idx].m_fMin, stOption.m_pstRange[1][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_07, stOption.m_pstRange[1][idx].m_fMin, stOption.m_pstRange[1][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_08, stOption.m_pstRange[1][idx].m_fMin, stOption.m_pstRange[1][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_09, stOption.m_pstRange[1][idx].m_fMin, stOption.m_pstRange[1][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_10, stOption.m_pstRange[1][idx].m_fMin, stOption.m_pstRange[1][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_11, stOption.m_pstRange[1][idx].m_fMin, stOption.m_pstRange[1][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_12, stOption.m_pstRange[1][idx].m_fMin, stOption.m_pstRange[1][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_13, stOption.m_pstRange[1][idx].m_fMin, stOption.m_pstRange[1][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_14, stOption.m_pstRange[1][idx].m_fMin, stOption.m_pstRange[1][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_15, stOption.m_pstRange[1][idx].m_fMin, stOption.m_pstRange[1][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_16, stOption.m_pstRange[1][idx].m_fMin, stOption.m_pstRange[1][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_17, stOption.m_pstRange[1][idx].m_fMin, stOption.m_pstRange[1][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_18, stOption.m_pstRange[1][idx].m_fMin, stOption.m_pstRange[1][idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);

					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Spec Range");
					idx = 0;

					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_01, stOption.m_pstRangeSpec[idx].m_fMin, stOption.m_pstRangeSpec[idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_02, stOption.m_pstRangeSpec[idx].m_fMin, stOption.m_pstRangeSpec[idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_03, stOption.m_pstRangeSpec[idx].m_fMin, stOption.m_pstRangeSpec[idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_04, stOption.m_pstRangeSpec[idx].m_fMin, stOption.m_pstRangeSpec[idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_05, stOption.m_pstRangeSpec[idx].m_fMin, stOption.m_pstRangeSpec[idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_06, stOption.m_pstRangeSpec[idx].m_fMin, stOption.m_pstRangeSpec[idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_07, stOption.m_pstRangeSpec[idx].m_fMin, stOption.m_pstRangeSpec[idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_08, stOption.m_pstRangeSpec[idx].m_fMin, stOption.m_pstRangeSpec[idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_09, stOption.m_pstRangeSpec[idx].m_fMin, stOption.m_pstRangeSpec[idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_10, stOption.m_pstRangeSpec[idx].m_fMin, stOption.m_pstRangeSpec[idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_11, stOption.m_pstRangeSpec[idx].m_fMin, stOption.m_pstRangeSpec[idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_12, stOption.m_pstRangeSpec[idx].m_fMin, stOption.m_pstRangeSpec[idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_13, stOption.m_pstRangeSpec[idx].m_fMin, stOption.m_pstRangeSpec[idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_14, stOption.m_pstRangeSpec[idx].m_fMin, stOption.m_pstRangeSpec[idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_15, stOption.m_pstRangeSpec[idx].m_fMin, stOption.m_pstRangeSpec[idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_16, stOption.m_pstRangeSpec[idx].m_fMin, stOption.m_pstRangeSpec[idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_17, stOption.m_pstRangeSpec[idx].m_fMin, stOption.m_pstRangeSpec[idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);
					szMinMax.Format(_T("    %s (%f, %f)  "), STR_SIZEMEASURE_18, stOption.m_pstRangeSpec[idx].m_fMin, stOption.m_pstRangeSpec[idx].m_fMax); idx++;
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szMinMax);

					CString szEnableStep;

					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", _T("Enable Step"));
					szEnableStep.Format(_T("    First Camera - Enable Sttep01(%d)"), stOption.m_stFirstCameraStep.m_bStep001);
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szEnableStep);
					szEnableStep.Format(_T("    First Camera - Enable Sttep02(%d)"), stOption.m_stFirstCameraStep.m_bStep002);
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szEnableStep);
					szEnableStep.Format(_T("    First Camera - Enable Sttep03(%d)"), stOption.m_stFirstCameraStep.m_bStep003);
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szEnableStep);
					szEnableStep.Format(_T("    First Camera - Enable Sttep04(%d)"), stOption.m_stFirstCameraStep.m_bStep004);
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szEnableStep);
					szEnableStep.Format(_T("    First Camera - Enable Sttep05(%d)"), stOption.m_stFirstCameraStep.m_bStep005);
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szEnableStep);
					szEnableStep.Format(_T("    First Camera - Enable Sttep06(%d)"), stOption.m_stFirstCameraStep.m_bStep006);
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szEnableStep);

					szEnableStep.Format(_T("    Second Camera - Enable Sttep02(%d)"), stOption.m_stSecondCameraStep.m_bStep002);
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szEnableStep);
					szEnableStep.Format(_T("    Second Camera - Enable Sttep03(%d)"), stOption.m_stSecondCameraStep.m_bStep003);
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szEnableStep);
					szEnableStep.Format(_T("    Second Camera - Enable Sttep04(%d)"), stOption.m_stSecondCameraStep.m_bStep004);
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szEnableStep);
					szEnableStep.Format(_T("    Second Camera - Enable Sttep05(%d)"), stOption.m_stSecondCameraStep.m_bStep005);
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szEnableStep);
					szEnableStep.Format(_T("    Second Camera - Enable Sttep06(%d)"), stOption.m_stSecondCameraStep.m_bStep006);
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "%s", (LPCTSTR)szEnableStep);
				}
			}
		}

		m_TapMainSize.UpdateRangeValue(TYPE_CAMERAPOS_FIRST);
		m_TapMainSize.UpdateSizeName();
		GetDlgItem(IDC_BTN_TESTSIZE)->EnableWindow(dlg.m_stOption.m_stFirstCameraStep.m_bStep001);
		GetDlgItem(IDC_BTN_TEST_STEP2)->EnableWindow(dlg.m_stOption.m_stFirstCameraStep.m_bStep002);
		GetDlgItem(IDC_BTN_TEST_STEP3)->EnableWindow(dlg.m_stOption.m_stFirstCameraStep.m_bStep003);
		GetDlgItem(IDC_BTN_TEST_STEP4)->EnableWindow(dlg.m_stOption.m_stFirstCameraStep.m_bStep004);
		GetDlgItem(IDC_BTN_TEST_STEP2_2)->EnableWindow(dlg.m_stOption.m_stSecondCameraStep.m_bStep002);
		GetDlgItem(IDC_BTN_TEST_STEP3_2)->EnableWindow(dlg.m_stOption.m_stSecondCameraStep.m_bStep003);
		GetDlgItem(IDC_BTN_TEST_STEP4_2)->EnableWindow(dlg.m_stOption.m_stSecondCameraStep.m_bStep004);

		GetDlgItem(IDC_BTN_TEST_STEP2)->SetWindowTextA(dlg.m_stOption.m_stFirstCameraStep.m_szTitleStep02);
		GetDlgItem(IDC_BTN_TEST_STEP3)->SetWindowTextA(dlg.m_stOption.m_stFirstCameraStep.m_szTitleStep03);
		GetDlgItem(IDC_BTN_TEST_STEP4)->SetWindowTextA(dlg.m_stOption.m_stFirstCameraStep.m_szTitleStep04);
		GetDlgItem(IDC_BTN_TEST_STEP2_2)->SetWindowTextA(dlg.m_stOption.m_stSecondCameraStep.m_szTitleStep02);
		GetDlgItem(IDC_BTN_TEST_STEP3_2)->SetWindowTextA(dlg.m_stOption.m_stSecondCameraStep.m_szTitleStep03);
		GetDlgItem(IDC_BTN_TEST_STEP4_2)->SetWindowTextA(dlg.m_stOption.m_stSecondCameraStep.m_szTitleStep04);
#ifdef DEF_SECONDCAMERA_CHECKSIZE
		GetDlgItem(IDC_BTN_TESTSIZE2)->EnableWindow(dlg.m_stOption.m_stSecondCameraStep.m_bStep001);
#endif
#ifdef USE_COUNT_TAB
		m_TapMainCount.UpdateRangeValue(TYPE_CAMERAPOS_FIRST);
		m_TapMainCount.UpdateSizeName();
#endif
	}
	m_TapMainScenario.UpdateEnableStep();
	m_TapMainSummary.UpdateTitleStep();
	m_TapMainSummary.UpdateSizeName();

	UpdateOptionFilePath();
}

void CNEPESDlg::ConfigOption()
{
	CDlgOptionEtc dlg;
	if (IDOK == dlg.DoModal())
	{
		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
		pCaptureManager->UpdateOptionEtc(&dlg.m_stEtcOption);
	}
}

void CNEPESDlg::UpdateMenuStatus()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	const INFO_OPTION* pstOption = pCaptureManager->GetOption();

	BOOL bInit = pInspection->IsInit();
	BOOL bStart = pInspection->IsStart();

	// Inspection
	CMenu* pSubMenuInspection = GetMenu()->GetSubMenu(0);
	if (pSubMenuInspection)
	{
		if (bInit)
		{
			GetDlgItem(IDC_BTN_TEST_STEP2)->SetWindowTextA(pstOption->m_stFirstCameraStep.m_szTitleStep02);
			GetDlgItem(IDC_BTN_TEST_STEP3)->SetWindowTextA(pstOption->m_stFirstCameraStep.m_szTitleStep03);
			GetDlgItem(IDC_BTN_TEST_STEP4)->SetWindowTextA(pstOption->m_stFirstCameraStep.m_szTitleStep04);
			GetDlgItem(IDC_BTN_TEST_STEP2_2)->SetWindowTextA(pstOption->m_stSecondCameraStep.m_szTitleStep02);
			GetDlgItem(IDC_BTN_TEST_STEP3_2)->SetWindowTextA(pstOption->m_stSecondCameraStep.m_szTitleStep03);
			GetDlgItem(IDC_BTN_TEST_STEP4_2)->SetWindowTextA(pstOption->m_stSecondCameraStep.m_szTitleStep04);

			if (bStart)
			{
				pSubMenuInspection->EnableMenuItem(ID_FILE_START, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
				pSubMenuInspection->EnableMenuItem(ID_FILE_STOP, MF_BYCOMMAND | MF_ENABLED);

				GetDlgItem(IDC_BTN_START)->SetWindowText(STR_BTN_STOP);
				GetDlgItem(IDC_BTN_TESTSIZE)->EnableWindow(FALSE);
				GetDlgItem(IDC_BTN_TESTSIZE2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BTN_TEST_STEP2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BTN_TEST_STEP3)->EnableWindow(FALSE);
				GetDlgItem(IDC_BTN_TEST_STEP4)->EnableWindow(FALSE);
				GetDlgItem(IDC_BTN_TEST_STEP2_2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BTN_TEST_STEP3_2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BTN_TEST_STEP4_2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BTN_CLEAR_QUEUE)->EnableWindow(FALSE);

				m_ctlTitleMessage.SetMessage(_T("START"));
			}
			else
			{
				pSubMenuInspection->EnableMenuItem(ID_FILE_START, MF_BYCOMMAND | MF_ENABLED);
				pSubMenuInspection->EnableMenuItem(ID_FILE_STOP, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);

				GetDlgItem(IDC_BTN_START)->SetWindowText(STR_BTN_START);
				GetDlgItem(IDC_BTN_TESTSIZE)->EnableWindow(pstOption->m_stFirstCameraStep.m_bStep001);
				GetDlgItem(IDC_BTN_TESTSIZE2)->EnableWindow(pstOption->m_stSecondCameraStep.m_bStep001);
				GetDlgItem(IDC_BTN_TEST_STEP2)->EnableWindow(pstOption->m_stFirstCameraStep.m_bStep002);
				GetDlgItem(IDC_BTN_TEST_STEP3)->EnableWindow(pstOption->m_stFirstCameraStep.m_bStep003);
				GetDlgItem(IDC_BTN_TEST_STEP4)->EnableWindow(pstOption->m_stFirstCameraStep.m_bStep004);
				GetDlgItem(IDC_BTN_TEST_STEP2_2)->EnableWindow(pstOption->m_stSecondCameraStep.m_bStep002);
				GetDlgItem(IDC_BTN_TEST_STEP3_2)->EnableWindow(pstOption->m_stSecondCameraStep.m_bStep003);
				GetDlgItem(IDC_BTN_TEST_STEP4_2)->EnableWindow(pstOption->m_stSecondCameraStep.m_bStep004);
				GetDlgItem(IDC_BTN_CLEAR_QUEUE)->EnableWindow(TRUE);

				m_ctlTitleMessage.SetMessage(_T("READY"));
			}
			GetDlgItem(IDC_BTN_START)->EnableWindow(TRUE);
		}
		else
		{
			pSubMenuInspection->EnableMenuItem(ID_FILE_START, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
			pSubMenuInspection->EnableMenuItem(ID_FILE_STOP, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);

			GetDlgItem(IDC_BTN_START)->SetWindowText(STR_BTN_START);
			GetDlgItem(IDC_BTN_START)->EnableWindow(FALSE);
			GetDlgItem(IDC_BTN_TESTSIZE)->EnableWindow(FALSE);
			GetDlgItem(IDC_BTN_TESTSIZE2)->EnableWindow(FALSE);
			GetDlgItem(IDC_BTN_TEST_STEP2)->EnableWindow(FALSE);
			GetDlgItem(IDC_BTN_TEST_STEP3)->EnableWindow(FALSE);
			GetDlgItem(IDC_BTN_TEST_STEP4)->EnableWindow(FALSE);
			GetDlgItem(IDC_BTN_TEST_STEP2_2)->EnableWindow(FALSE);
			GetDlgItem(IDC_BTN_TEST_STEP3_2)->EnableWindow(FALSE);
			GetDlgItem(IDC_BTN_TEST_STEP4_2)->EnableWindow(FALSE);
			GetDlgItem(IDC_BTN_CLEAR_QUEUE)->EnableWindow(FALSE);

			m_ctlTitleMessage.SetMessage(_T("NOT READY..."));
		}
	}

	// Config
	CMenu* pSubMenuConfig = GetMenu()->GetSubMenu(1);
	if (pSubMenuConfig)
	{
		if (bStart)
		{
			pSubMenuConfig->EnableMenuItem(ID_CONFIG_CONFIG, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
			pSubMenuConfig->EnableMenuItem(ID_CONFIG_CONFIGINSPECTION, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
			//pSubMenuConfig->EnableMenuItem(ID_CONFIG_OPTION, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
		}
		else
		{
			pSubMenuConfig->EnableMenuItem(ID_CONFIG_CONFIG, MF_BYCOMMAND | MF_ENABLED);
			pSubMenuConfig->EnableMenuItem(ID_CONFIG_CONFIGINSPECTION, MF_BYCOMMAND | MF_ENABLED);
			pSubMenuConfig->EnableMenuItem(ID_CONFIG_OPTION, MF_BYCOMMAND | MF_ENABLED);
		}
	}
}

void CNEPESDlg::UpdateCtrlStatus()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	const BOOL bStat = pInspection->IsStart();
	if (bStat)
	{
		GetDlgItem(IDC_BTN_START)->SetWindowText(STR_BTN_STOP);

		//m_TapMainSummary.EnableWindow(FALSE);
		//m_TapMainSize.EnableWindow(FALSE);
		m_TapMainScenario.EnableWindow(FALSE);
#ifdef USE_COUNT_TAB
		m_TapMainCount.EnableWindow(FALSE);
#endif
	}
	else
	{
		GetDlgItem(IDC_BTN_START)->SetWindowText(STR_BTN_START);

		m_TapMainSummary.EnableWindow(TRUE);
		m_TapMainSize.EnableWindow(TRUE);
		m_TapMainScenario.EnableWindow(TRUE);
#ifdef USE_COUNT_TAB
		m_TapMainCount.EnableWindow(TRUE);
#endif
	}
}

void CNEPESDlg::UpdateCtrlScenraioState(TYPE_CAMERAPOS eCameraPos, TYPE_STEP eStep, CSampleSide* pSample)
{
	if (NULL == pSample)
		return;
	if (TYPE_CAMERAPOS_FIRST != eCameraPos && TYPE_CAMERAPOS_SECOND != eCameraPos)
		return;
	BOOL bResult = FALSE;

	if (TYPE_STEP_001 == eStep)
	{
		bResult = TRUE;
		for (int i = 0; i < TYPE_GEOMETRY_DISTANCE_MAX; i++)
		{
			if (FALSE == pSample->m_SizeResult.m_stDistance[i].m_bOK)
			{
				bResult = FALSE;
				break;
			}
		}
	}
	else if (TYPE_STEP_002 == eStep)
	{
		bResult = pSample->m_StainResult.m_bResult;
	}
	else if (TYPE_STEP_003 == eStep)
	{
		bResult = pSample->m_DifferResult.m_bResult;
	}
	else if (TYPE_STEP_004 == eStep)
	{
		bResult = pSample->m_BubbleResult.m_bResult;
	}
	else if (TYPE_STEP_005 == eStep)
	{
		bResult = pSample->m_ScratchResult.m_bResult;
	}
	else if (TYPE_STEP_006 == eStep)
	{
		bResult = pSample->m_StampResult.m_bResult;
	}
	else if (TYPE_STEP_007 == eStep)
	{
		bResult = TRUE;
		for (int i = 0; i < TYPE_GEOMETRY_DISTANCE_MAX; i++)
		{
			if (FALSE == pSample->m_SizeCalculationResult.m_stDistance[i].m_bOK)
			{
				bResult = FALSE;
				break;
			}
		}
	}
	else
	{
		return;
	}
	m_TapMainScenario.SetStepState(eCameraPos, eStep, bResult);
#ifdef USE_COUNT_TAB
	m_TapMainCount.SetStepState(eCameraPos, eStep, bResult);
#endif
}

void CNEPESDlg::UpdateOptionFilePath()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CString szOptionFilePath = pCaptureManager->GetOptionFilePath();
	int idx = szOptionFilePath.Find("\\", 0);
	int idxLeft = 0;
	int idxRight = 0;
	while (idx >= 0)
	{
		idxLeft = idx + 1;
		idx = szOptionFilePath.Find("\\", idxLeft);
	}
	idxRight = szOptionFilePath.Find(".xml", idxLeft);
	szOptionFilePath = szOptionFilePath.Mid(idxLeft, idxRight - idxLeft);
	GetDlgItem(IDC_STATIC_OPTION)->SetWindowText(szOptionFilePath);
}

TYPE_TAPVIEW CNEPESDlg::GetCurrentTapView()
{
	TYPE_TAPVIEW eType = TYPE_TAPVIEW_NONE;

	if (m_TapMainSummary.m_hWnd && m_TapMainSummary.IsWindowVisible())
		eType = TYPE_TAPVIEW_SUMMARY;
	else if (m_TapMainSummary.m_hWnd && (m_TapMainSize.IsWindowVisible()))
		eType = TYPE_TAPVIEW_SIZE;
	else if (m_TapMainScenario.m_hWnd && m_TapMainScenario.IsWindowVisible())
		eType = TYPE_TAPVIEW_SCENARIO;
#ifdef USE_COUNT_TAB
	else if (m_TapMainCount.m_hWnd && (m_TapMainCount.IsWindowVisible()))
		eType = TYPE_TAPVIEW_COUNT;
#endif

	return eType;
}

void CNEPESDlg::SetCurrentTapView(TYPE_TAPVIEW eType)
{
	if (TYPE_TAPVIEW_SUMMARY == eType)
	{
		m_TapMainSummary.ShowWindow(SW_SHOW);
		m_TapMainScenario.ShowWindow(SW_HIDE);
		m_TapMainSize.ShowWindow(SW_HIDE);
#ifdef USE_COUNT_TAB
		m_TapMainCount.ShowWindow(SW_HIDE);
#endif
	}
	else if (TYPE_TAPVIEW_SIZE == eType)
	{
		m_TapMainSummary.ShowWindow(SW_HIDE);
		m_TapMainScenario.ShowWindow(SW_HIDE);
		m_TapMainSize.ShowWindow(SW_SHOW);
#ifdef USE_COUNT_TAB
		m_TapMainCount.ShowWindow(SW_HIDE);
#endif
	}
	else if (TYPE_TAPVIEW_SCENARIO == eType)
	{
		m_TapMainSummary.ShowWindow(SW_HIDE);
		m_TapMainScenario.ShowWindow(SW_SHOW);
		m_TapMainSize.ShowWindow(SW_HIDE);
#ifdef USE_COUNT_TAB
		m_TapMainCount.ShowWindow(SW_HIDE);
#endif
	}
	else if (TYPE_TAPVIEW_COUNT == eType)
	{
		m_TapMainSummary.ShowWindow(SW_HIDE);
		m_TapMainScenario.ShowWindow(SW_HIDE);
		m_TapMainSize.ShowWindow(SW_HIDE);
#ifdef USE_COUNT_TAB
		m_TapMainCount.ShowWindow(SW_SHOW);
#endif
	}
}

void CNEPESDlg::CheckInspectionResult(TYPE_CAMERAPOS eCameraPos, CSampleSide* pSample, BOOL& bResSize, BOOL& bResShape)
{
	if (NULL == pSample)
		return;

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_OPTION* pstOption = pCaptureManager->GetOption();

	INFO_OPT_INSPECTSTEP* pstOptStep = NULL;
	if (TYPE_CAMERAPOS_FIRST == eCameraPos)
	{
		pstOptStep = (INFO_OPT_INSPECTSTEP*)&pstOption->m_stFirstCameraStep;
	}
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
	{
		pstOptStep = (INFO_OPT_INSPECTSTEP*)&pstOption->m_stSecondCameraStep;
	}


	bResSize = TRUE;
	bResShape = TRUE;

	if (pstOptStep->m_bStep001)
	{
		for (int i = 0; i < TYPE_GEOMETRY_DISTANCE_MAX; i++)
		{
			if (FALSE == pSample->m_SizeCalculationResult.m_stDistance[i].m_bOK)
			{
				bResSize = FALSE;
				break;
			}
		}
	}

	if (TRUE == pstOptStep->m_bStep002 && FALSE == pSample->m_StainResult.m_bResult)
		bResShape = FALSE;
	if (TRUE == pstOptStep->m_bStep003 && FALSE == pSample->m_DifferResult.m_bResult)
		bResShape = FALSE;
	if (TRUE == pstOptStep->m_bStep004 && FALSE == pSample->m_BubbleResult.m_bResult)
		bResShape = FALSE;
	if (TRUE == pstOptStep->m_bStep005 && FALSE == pSample->m_ScratchResult.m_bResult)
		bResShape = FALSE;
	if (TRUE == pstOptStep->m_bStep006 && FALSE == pSample->m_StampResult.m_bResult)
		bResShape = FALSE;

}

void CNEPESDlg::DumpImageOKResult(TYPE_CAMERAPOS eCameraPos, TYPE_STEP eStep, CSampleSide* pSample)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_OPTION* pstOption = pCaptureManager->GetOption();
	const INFO_OPTIONETC* pstOptEtc = pCaptureManager->GetOptionEtc();

	if (NULL == pSample || FALSE == pstOptEtc->m_stLogInfo.m_bSaveOKImage || TYPE_STEP_007 != eStep)
		return;

	TCHAR szCamPos[MAX_NAME_LEN] = { 0, };

	INFO_OPT_INSPECTSTEP* pstOptStep = NULL;
	if (TYPE_CAMERAPOS_FIRST == eCameraPos)
	{
		CUtil::StringCopy(szCamPos, _T("First"));
		pstOptStep = (INFO_OPT_INSPECTSTEP*)&pstOption->m_stFirstCameraStep;
	}
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
	{
		CUtil::StringCopy(szCamPos, _T("Second"));
		pstOptStep = (INFO_OPT_INSPECTSTEP*)&pstOption->m_stSecondCameraStep;
	}
	else
	{
		return;
	}


	INFO_IMAGE* pRefImage = pSample->m_pRefImage;

	if (FALSE == pRefImage)
		return;

	SYSTEMTIME stTime;
	::GetLocalTime(&stTime);

	TCHAR szDumpPath[MAX_FILE_PATH_LEN] = { 0, };

#ifdef IDC_EDIT_SAVEIMAGEFORMAT
	/*
	CUtil::StringFormat(szDumpPath, MAX_FILE_PATH_LEN, _T("%s\\%04d%02d%02d_%02d%02d%02d_%s_OKImage%s"),
		pstOptEtc->m_stLogInfo.m_szLogPath,
		stTime.wYear, stTime.wMonth, stTime.wDay,
		stTime.wHour, stTime.wMinute, stTime.wSecond,
		szCamPos,
		pstOptEtc->m_stLogInfo.m_szSaveImageFormat);
	*/
	// Version 1.3.7.2 OK image Save Size & Step
	CUtil::StringFormat(szDumpPath, MAX_FILE_PATH_LEN, _T("%s\\%04d%02d%02d_%02d%02d%02d_%s_Saveimage_Step1%s"),
		pstOptEtc->m_stLogInfo.m_szLogPath,
		stTime.wYear, stTime.wMonth, stTime.wDay,
		stTime.wHour, stTime.wMinute, stTime.wSecond,
		szCamPos,
		pstOptEtc->m_stLogInfo.m_szSaveImageFormat);
#else
	CUtil::StringFormat(szDumpPath, MAX_FILE_PATH_LEN, _T("%s\\%04d%02d%02d_%02d%02d%02d_%s_%s.png"),
		pstOptEtc->m_stLogInfo.m_szLogPath,
		stTime.wYear, stTime.wMonth, stTime.wDay,
		stTime.wHour, stTime.wMinute, stTime.wSecond,
		szCamPos,
		szStep);
#endif

	DWORD dwWidth = pRefImage->m_stFrame.m_dwWidth;
	DWORD dwHeight = pRefImage->m_stFrame.m_dwHeight;


#ifdef USE_BASLER_CAMERA
	int nPitch = pRefImage->m_stFrame.m_dwPitch;
	BYTE nBit = 24;

	WriteImageFromBuffer(szDumpPath, pRefImage->m_pBuffer, pRefImage->m_nLen, dwWidth, dwHeight, nBit, nPitch);

	// Version 1.3.7.2 OK image Save Size & Step
	CUtil::StringFormat(szDumpPath, MAX_FILE_PATH_LEN, _T("%s\\%04d%02d%02d_%02d%02d%02d_%s_Saveimage_Step2_Stain%s"),
		pstOptEtc->m_stLogInfo.m_szLogPath,
		stTime.wYear, stTime.wMonth, stTime.wDay,
		stTime.wHour, stTime.wMinute, stTime.wSecond,
		szCamPos,
		pstOptEtc->m_stLogInfo.m_szSaveImageFormat);
	cv::imwrite(szDumpPath, pSample->m_StainResult.m_pInputImage);

	CUtil::StringFormat(szDumpPath, MAX_FILE_PATH_LEN, _T("%s\\%04d%02d%02d_%02d%02d%02d_%s_Saveimage_Step3_Differ%s"),
		pstOptEtc->m_stLogInfo.m_szLogPath,
		stTime.wYear, stTime.wMonth, stTime.wDay,
		stTime.wHour, stTime.wMinute, stTime.wSecond,
		szCamPos, 
		pstOptEtc->m_stLogInfo.m_szSaveImageFormat);
	cv::imwrite(szDumpPath, pSample->m_DifferResult.m_pInputImage);

	CUtil::StringFormat(szDumpPath, MAX_FILE_PATH_LEN, _T("%s\\%04d%02d%02d_%02d%02d%02d_%s_Saveimage_Step4_Bubble%s"),
		pstOptEtc->m_stLogInfo.m_szLogPath,
		stTime.wYear, stTime.wMonth, stTime.wDay,
		stTime.wHour, stTime.wMinute, stTime.wSecond,
		szCamPos, 
		pstOptEtc->m_stLogInfo.m_szSaveImageFormat);
	cv::imwrite(szDumpPath, pSample->m_BubbleResult.m_pInputImage);
#else
	int nPitch = dwWidth;
	BYTE nBit = 8;
	WriteImageFromBuffer(szDumpPath, pRefImage->m_pBuffer, pRefImage->m_nLen, dwWidth, dwHeight, nBit, nPitch);
#endif

	INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();
	// Print Log
	{
		if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
		{
			stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Save image (%s)", szDumpPath);
		}
	}
}


void CNEPESDlg::DumpImageErrorResult(TYPE_CAMERAPOS eCameraPos, TYPE_STEP eStep, CSampleSide* pSample)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_OPTION* pstOption = pCaptureManager->GetOption();
	const INFO_OPTIONETC* pstOptEtc = pCaptureManager->GetOptionEtc();

	if (NULL == pSample || FALSE == pstOptEtc->m_stLogInfo.m_bSaveErrorImage)
		return;

	TCHAR szCamPos[MAX_NAME_LEN] = { 0, };
	TCHAR szStep[MAX_NAME_LEN] = { 0, };

	INFO_OPT_INSPECTSTEP* pstOptStep = NULL;
	if (TYPE_CAMERAPOS_FIRST == eCameraPos)
	{
		CUtil::StringCopy(szCamPos, _T("First"));
		pstOptStep = (INFO_OPT_INSPECTSTEP*)&pstOption->m_stFirstCameraStep;
	}
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
	{
		CUtil::StringCopy(szCamPos, _T("Second"));
		pstOptStep = (INFO_OPT_INSPECTSTEP*)&pstOption->m_stSecondCameraStep;
	}
	else
	{
		return;
	}

	BOOL bErrorResult = FALSE;
	cv::Mat TempProbImage;
	cv::Mat TempInputImage;
	if (TYPE_STEP_001 == eStep)
	{
		const TCHAR* pTitleStep = pCaptureManager->GetTitleStep(eCameraPos, eStep);
		CUtil::StringFormat(szStep, MAX_NAME_LEN, _T("%s_%s"), _T("step01"), pTitleStep);
		for (int i = 0; i < TYPE_GEOMETRY_DISTANCE_MAX; i++)
		{
			if (!pSample->m_SizeResult.m_stDistance[i].m_bOK)
			{
				bErrorResult = TRUE;
				break;
			}
		}

		if (FALSE == pstOptStep->m_bStep001)
			return;
	}
	else if (TYPE_STEP_002 == eStep)
	{
		const TCHAR* pTitleStep = pCaptureManager->GetTitleStep(eCameraPos, eStep);
		CUtil::StringFormat(szStep, MAX_NAME_LEN, _T("%s_%s"), _T("step02"), pTitleStep);
		TempInputImage = pSample->m_StainResult.m_pInputImage;
		TempProbImage = pSample->m_StainResult.m_pProbImage;
		bErrorResult = !pSample->m_StainResult.m_bResult;

		if (FALSE == pstOptStep->m_bStep002)
			return;
	}
	else if (TYPE_STEP_003 == eStep)
	{
		const TCHAR* pTitleStep = pCaptureManager->GetTitleStep(eCameraPos, eStep);
		CUtil::StringFormat(szStep, MAX_NAME_LEN, _T("%s_%s"), _T("step03"), pTitleStep);
		TempInputImage = pSample->m_DifferResult.m_pInputImage;
		TempProbImage = pSample->m_DifferResult.m_pProbImage;
		bErrorResult = !pSample->m_DifferResult.m_bResult;

		if (FALSE == pstOptStep->m_bStep003)
			return;
	}
	else if (TYPE_STEP_004 == eStep)
	{
		const TCHAR* pTitleStep = pCaptureManager->GetTitleStep(eCameraPos, eStep);
		CUtil::StringFormat(szStep, MAX_NAME_LEN, _T("%s_%s"), _T("step04"), pTitleStep);
		TempInputImage = pSample->m_BubbleResult.m_pInputImage;
		TempProbImage = pSample->m_BubbleResult.m_pProbImage;
		bErrorResult = !pSample->m_BubbleResult.m_bResult;

		if (FALSE == pstOptStep->m_bStep004)
			return;
	}
	else if (TYPE_STEP_005 == eStep)
	{
		const TCHAR* pTitleStep = pCaptureManager->GetTitleStep(eCameraPos, eStep);
		CUtil::StringFormat(szStep, MAX_NAME_LEN, _T("%s_%s"), _T("step05"), pTitleStep);
		TempInputImage = pSample->m_ScratchResult.m_pInputImage;
		TempProbImage = pSample->m_ScratchResult.m_pProbImage;
		bErrorResult = !pSample->m_ScratchResult.m_bResult;

		if (FALSE == pstOptStep->m_bStep005)
			return;
	}
	else if (TYPE_STEP_006 == eStep)
	{
		const TCHAR* pTitleStep = pCaptureManager->GetTitleStep(eCameraPos, eStep);
		CUtil::StringFormat(szStep, MAX_NAME_LEN, _T("%s_%s"), _T("step06"), pTitleStep);
		TempInputImage = pSample->m_StampResult.m_pInputImage;
		TempProbImage = pSample->m_StampResult.m_pProbImage;
		bErrorResult = !pSample->m_StampResult.m_bResult;

		if (FALSE == pstOptStep->m_bStep006)
			return;
	}
	else if (TYPE_STEP_007 == eStep)
	{
		const TCHAR* pTitleStep = pCaptureManager->GetTitleStep(eCameraPos, eStep);
		CUtil::StringFormat(szStep, MAX_NAME_LEN, _T("%s_%s"), _T("step07"), pTitleStep);
		for (int i = 0; i < TYPE_GEOMETRY_DISTANCE_MAX; i++)
		{
			if (!pSample->m_SizeCalculationResult.m_stDistance[i].m_bOK)
			{
				bErrorResult = TRUE;
				break;
			}
		}
		if (FALSE == pstOptStep->m_bStep001)
			bErrorResult = FALSE;

	}
	else
	{
		return;
	}

	INFO_IMAGE* pRefImage = pSample->m_pRefImage;

	if (FALSE == bErrorResult || FALSE == pRefImage)
		return;

	SYSTEMTIME stTime;
	::GetLocalTime(&stTime);

	TCHAR szDumpPath[MAX_FILE_PATH_LEN] = { 0, };

#ifdef IDC_EDIT_SAVEIMAGEFORMAT
	CUtil::StringFormat(szDumpPath, MAX_FILE_PATH_LEN, _T("%s\\%04d%02d%02d_%02d%02d%02d_%s_%s%s"),
		pstOptEtc->m_stLogInfo.m_szLogPath,
		stTime.wYear, stTime.wMonth, stTime.wDay,
		stTime.wHour, stTime.wMinute, stTime.wSecond,
		szCamPos,
		szStep,
		pstOptEtc->m_stLogInfo.m_szSaveImageFormat);
#else
	CUtil::StringFormat(szDumpPath, MAX_FILE_PATH_LEN, _T("%s\\%04d%02d%02d_%02d%02d%02d_%s_%s.png"),
		pstOptEtc->m_stLogInfo.m_szLogPath,
		stTime.wYear, stTime.wMonth, stTime.wDay,
		stTime.wHour, stTime.wMinute, stTime.wSecond,
		szCamPos,
		szStep);
#endif

	DWORD dwWidth = pRefImage->m_stFrame.m_dwWidth;
	DWORD dwHeight = pRefImage->m_stFrame.m_dwHeight;


#ifdef USE_BASLER_CAMERA
	int nPitch = pRefImage->m_stFrame.m_dwPitch;
	BYTE nBit = 24;
	if (TRUE == bErrorResult)
	{
		if (TYPE_STEP_007 == eStep)
			WriteImageFromBuffer(szDumpPath, pRefImage->m_pBuffer, pRefImage->m_nLen, dwWidth, dwHeight, nBit, nPitch);
		else
			cv::imwrite(szDumpPath, TempInputImage);
	}

#else
	int nPitch = dwWidth;
	BYTE nBit = 8;
	WriteImageFromBuffer(szDumpPath, pRefImage->m_pBuffer, pRefImage->m_nLen, dwWidth, dwHeight, nBit, nPitch);
#endif

	//검사 결과 이미지 저장
	if ((TRUE == pstOptEtc->m_stLogInfo.m_bSaveProbImage) && (TYPE_STEP_001 != eStep) && (TYPE_STEP_007 != eStep)){
		if (pCaptureManager->m_nCountSaveProbImage < pstOptEtc->m_stLogInfo.m_nSaveProbImageCount && TRUE == bErrorResult){
			++pCaptureManager->m_nCountSaveProbImage;
			TCHAR szProbDumpPath[MAX_FILE_PATH_LEN] = { 0, };

#ifdef IDC_EDIT_SAVEIMAGEFORMAT
			CUtil::StringFormat(szProbDumpPath, MAX_FILE_PATH_LEN, _T("%s_Error%s"), szDumpPath,pstOptEtc->m_stLogInfo.m_szSaveImageFormat);
#else
			CUtil::StringFormat(szProbDumpPath, MAX_FILE_PATH_LEN, _T("%s_Error.png"), szDumpPath);
#endif
			cv::imwrite(szProbDumpPath, TempProbImage);
		}
	}
	INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();
	// Print Log
	{
		if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
		{
			stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Save image (%s)", szDumpPath);
		}
	}
}

void CNEPESDlg::PeriodImageOKResult(TYPE_CAMERAPOS eCameraPos, TYPE_STEP eStep, CSampleSide* pSample)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_OPTION* pstOption = pCaptureManager->GetOption();
	const INFO_OPTIONETC* pstOptEtc = pCaptureManager->GetOptionEtc();

	if (NULL == pSample || FALSE == pstOptEtc->m_stLogInfo.m_bSaveOKImage_Period || TYPE_STEP_007 != eStep)
		return;

	TCHAR szCamPos[MAX_NAME_LEN] = { 0, };

	INFO_OPT_INSPECTSTEP* pstOptStep = NULL;
	if (TYPE_CAMERAPOS_FIRST == eCameraPos)
	{
		CUtil::StringCopy(szCamPos, _T("First"));
		pstOptStep = (INFO_OPT_INSPECTSTEP*)&pstOption->m_stFirstCameraStep;
	}
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
	{
		CUtil::StringCopy(szCamPos, _T("Second"));
		pstOptStep = (INFO_OPT_INSPECTSTEP*)&pstOption->m_stSecondCameraStep;
	}
	else
	{
		return;
	}

	SYSTEMTIME stTime;
	::GetLocalTime(&stTime);

	TCHAR szDumpPath[MAX_FILE_PATH_LEN] = { 0, };

#ifdef USE_BASLER_CAMERA
	// Version 1.3.7.2 OK image Save Size & Step
	CUtil::StringFormat(szDumpPath, MAX_FILE_PATH_LEN, _T("%s\\%04d%02d%02d_%02d%02d_%s_SavePeriodimage_Step2%s"),
		pstOptEtc->m_stLogInfo.m_szLogPath,
		stTime.wYear, stTime.wMonth, stTime.wDay,
		stTime.wHour, stTime.wMinute, //stTime.wSecond,
		szCamPos,
		pstOptEtc->m_stLogInfo.m_szSaveImageFormat);
	cv::imwrite(szDumpPath, pSample->m_StainResult.m_pInputImage);
#else
	int nPitch = dwWidth;
	BYTE nBit = 8;
	WriteImageFromBuffer(szDumpPath, pRefImage->m_pBuffer, pRefImage->m_nLen, dwWidth, dwHeight, nBit, nPitch);
#endif

	INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();
	// Print Log
	{
		if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
		{
			stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Save Period image (%s)", szDumpPath);
		}
	}
}

#include "opencv\cv.h"
#include "opencv\highgui.h"

BOOL WriteImageFromBuffer(const TCHAR* pszPath, BYTE* pBuffer, DWORD dwLen, DWORD dwWidth, DWORD dwHeight, BYTE nBit, int nPitch)
{
	if (NULL == pszPath || NULL == pBuffer)
		return FALSE;

	IplImage* pcvImage = cvCreateImage(cvSize(dwWidth, dwHeight), IPL_DEPTH_8U, nBit / 8);
	if (pcvImage)
	{
		BYTE* pSrc = pBuffer;
		BYTE* pDest = (BYTE*)pcvImage->imageData;

		const int nDestPitch = pcvImage->widthStep;
		const int nMinPitch = nDestPitch > nPitch ? nPitch : nDestPitch;

		for (int y = 0; y < (int)dwHeight; y++)
		{
			memcpy(pDest, pSrc, nMinPitch);
			pDest += nDestPitch;
			pSrc += nPitch;
		}

		TCHAR* pExt = ::PathFindExtension(pszPath);
		if (CUtil::StringICompare(_T("jpg"), pExt))
		{
			int params[3];
			params[0] = CV_IMWRITE_JPEG_QUALITY;
			params[1] = 50;	// %,  100: no compress, 1: full compress
			params[2] = 0;

			cvSaveImage(pszPath, pcvImage, params);
		}
		else
		{
			cvSaveImage(pszPath, pcvImage);
		}
		if (pcvImage)
			cvReleaseImage(&pcvImage);
	}
	else
	{
		return FALSE;
	}

	return TRUE;
}


void RotateImage(INFO_IMAGE* pstImage, const DWORD dwDegree)
{
	if (NULL == pstImage)
		return;

	const int w = pstImage->m_stFrame.m_dwWidth;
	const int h = pstImage->m_stFrame.m_dwHeight;

	double fAngle = 90;
	if (90 == dwDegree)			fAngle = 270;
	else if (270 == dwDegree)	fAngle = 90;

	IplImage* pcvImage = cvCreateImage(cvSize(w, h), IPL_DEPTH_8U, 1);
	IplImage* pcvResult = cvCreateImage(cvSize(w, h), IPL_DEPTH_8U, 1);

	memcpy(pcvImage->imageData, pstImage->m_pBuffer, pstImage->m_nLen);

	// Rotate
	CvMat* pMatrix = cvCreateMat(2, 3, CV_32FC1);
	cv2DRotationMatrix(CvPoint2D32f(w / 2.0, h / 2.0), fAngle, 1, pMatrix);
	cvWarpAffine(pcvImage, pcvResult, pMatrix);


	memcpy(pstImage->m_pBuffer, pcvResult->imageData, pstImage->m_nLen);



	cvReleaseMat(&pMatrix);

	cvReleaseImage(&pcvImage);
	cvReleaseImage(&pcvResult);
}


BOOL CNEPESDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct)
{
#ifdef USE_PLC_MXCOMPONENT
	m_LPMxComponentDS = *(PCOPYDATASTRUCT)pCopyDataStruct;
	stLPMXComponentCommnd* pstMXCommand = (stLPMXComponentCommnd*)(m_LPMxComponentDS.lpData);
	
	m_nCurrentPLCCommunicationStep = pstMXCommand->nCommandType;

	//m_strSetDeviceName = _T("");
	//m_strGetDeviceName = _T("");
	//m_lGetValue = 0;

	switch (pstMXCommand->nCommandType)
	{
		case TYPE_COMMAND_SETTING:
		{
			CUtil::PrintDebugString("TYPE_COMMAND_OPENCOM Success\r\n");
		}
		break;
		case TYPE_COMMAND_OPENCOM:
		{
			CString strLogData = _T("");
			strLogData.Format(_T("Open Communication : %d, Result : 0x%08x \r\n"), pstMXCommand->bControlOpened, pstMXCommand->lRet);
			CUtil::PrintDebugString(strLogData);

			CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
			pCaptureManager->SetMXComponentOpenCom(pstMXCommand->bControlOpened);

			if (m_pDlgConfig->IsWindowVisible())
			{
				m_pDlgConfig->UpdateSerialPort();

				if (!pCaptureManager->GetMXComponentOpenCom())
				{
					INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();

					AfxMessageBox(STR_MSG_ERROR_PLCMXCOMPONENT);
					// Print Log
					{
						if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
						{
							stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Fail to open PLC Com");
						}
					}
				}
			}

			if (pstMXCommand->bControlOpened && !m_Timer.IsRunning())
			{
				MMTimer_Start(PLC_CHECKTIME_MS);

				Sleep(100);
				m_nPLCMAP_VISIONKEEPALIVE_Timer = SetTimer(TIMERID_CHECK_PLCMAP_VISIONKEEPALIVE, 1000, CB_VisionKeepAlive);
				m_nPLC_CHECKTEMPERATURE_Timer = SetTimer(TIMERID_CHECK_PLC_TEMPERATURE, TEMPERATURE_TICK, CB_TemperatureCheck);
				CString strDeviceInfo = MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), TYPE_POS_FIRST, TPYE_STATE_TEMPERATURE);
				pCaptureManager->LPMxComSetDevice(strDeviceInfo, 0);

				// Version 1.3.7.7
				m_nPLC_SYNCHRONIZATION_Timer = SetTimer(TIMERID_CHECK_PLC_SYNCHRONIZATION, 5000,	CB_SynchronizationCheck);
			}
			SetTempLogState(FALSE);

			if (pCaptureManager->GetMXComponentOpenCom())
				pCaptureManager->LPMxComGetCpuType();

			m_bRequestedInspection = FALSE;
			m_bRealStartingInspectionPLC = FALSE;

			m_bRequestedInspectionSecond = FALSE;
			m_bRealStartingInspectionPLCSecond = FALSE;

		}
		break;
		case TYPE_COMMAND_GETCPUTYPE:
		{
			CString strLogData = _T("");
			strLogData.Format(_T("CPU Name : %s, CpuCode: 0x%x, Result : 0x%08x \r\n"), pstMXCommand->szCpuName, pstMXCommand->lCpuCode, pstMXCommand->lRet);
			CUtil::PrintDebugString(strLogData);
		}
		break;
		case TYPE_COMMAND_GETDEVICE:
		{
			CString strLogData = _T("");
			strLogData.Format(_T("Get Device : %s, Value : 0x%04x, Result : 0x%08x\r\n"), pstMXCommand->szDeviceName, pstMXCommand->lGetValue, pstMXCommand->lRet);
			CUtil::PrintDebugString(strLogData);

			{
				CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
				INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();

				// Print Log
				if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MX_PLC", "Get Device : %s, Value : 0x%04x, Result : 0x%08x", pstMXCommand->szDeviceName, pstMXCommand->lGetValue, pstMXCommand->lRet);
			}

			int nCameraPos = pstMXCommand->nCameraPos;
			if (nCameraPos == TYPE_POS_FIRST)
			{
				m_strGetDeviceName[0].Format(_T("%s"), pstMXCommand->szDeviceName);
				m_lGetValue[0] = pstMXCommand->lGetValue;

				DWORD dwCreateThreadId = 0;
				m_hPLCGetDataProcessThread = ::CreateThread(0, 0, PLCGetDataProcessThreadProc, LPVOID(this), 0, &dwCreateThreadId);
				// Version 1.3.7.7
				dwCreateThreadId = 0;
				m_hPLCGetDataProcessThreadTimeSync = ::CreateThread(0, 0, PLCGetDataProcessThreadTimeSync, LPVOID(this), 0, &dwCreateThreadId);
			}
			else if (nCameraPos == TYPE_POS_SECOND)
			{
				m_strGetDeviceName[1].Format(_T("%s"), pstMXCommand->szDeviceName);
				m_lGetValue[1] = pstMXCommand->lGetValue;

				DWORD dwCreateThreadId = 0;
				m_hPLCGetDataProcessThreadSecond = ::CreateThread(0, 0, PLCGetDataProcessThreadProcSecond, LPVOID(this), 0, &dwCreateThreadId);
			}
			else if (nCameraPos == TYPE_POS_MAX)
			{
				m_strGetDeviceName[2].Format(_T("%s"), pstMXCommand->szDeviceName);
				m_lGetValue[2] = pstMXCommand->lGetValue;

				DWORD dwCreateThreadId = 0;
				m_hPLCGetDataProcessThreadSecond = ::CreateThread(0, 0, PLCGetDataProcessThreadTemperature, LPVOID(this), 0, &dwCreateThreadId);
			}
		}
		break;
		case TYPE_COMMAND_SETDEVICE:
		{
			CString strLogData = _T("");
			strLogData.Format(_T("Set Device : %s, Value : 0x%04x, Result : 0x%08x\r\n"), pstMXCommand->szDeviceName, pstMXCommand->lSetValue, pstMXCommand->lRet);
			CUtil::PrintDebugString(strLogData);

			{
				CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
				INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();

				// Print Log
				if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MX_PLC", "Set Device : %s, Value : 0x%04x, Result : 0x%08x", pstMXCommand->szDeviceName, pstMXCommand->lSetValue, pstMXCommand->lRet);
			}

			//int nCameraPos = pstMXCommand->nCameraPos;
			//if (nCameraPos == TYPE_POS_FIRST)
			//{
			//	//m_strSetDeviceName[0].Format(_T("%s"), pstMXCommand->szDeviceName);
			//}
			//else
			//{
			//	//m_strSetDeviceName[1].Format(_T("%s"), pstMXCommand->szDeviceName);
			//}
		}
		break;
		case TYPE_COMMAND_CLOSECOM:
		{
			CString strLogData = _T("");
			strLogData.Format(_T("Close Communication : %d, Result : 0x%08x\r\n"), pstMXCommand->bControlOpened, pstMXCommand->lRet);
			CUtil::PrintDebugString(strLogData);

			CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
			pCaptureManager->SetMXComponentOpenCom(pstMXCommand->bControlOpened);

			if (m_pDlgConfig->IsWindowVisible())
				m_pDlgConfig->UpdateSerialPort();

			m_bTRUE_Data = FALSE;
			m_bTempLogState = FALSE;
			if (m_nPLCMAP_VISIONKEEPALIVE_Timer)
				KillTimer(m_nPLCMAP_VISIONKEEPALIVE_Timer);

			if (m_nPLC_CHECKTEMPERATURE_Timer)
				KillTimer(m_nPLC_CHECKTEMPERATURE_Timer);

			if (!pstMXCommand->bControlOpened && m_Timer.IsRunning())
				MMTimer_Stop();

			m_bRequestedInspection = FALSE;
			m_bRealStartingInspectionPLC = FALSE;
			m_bRequestedInspectionSecond = FALSE;
			m_bRealStartingInspectionPLCSecond = FALSE;
		}
		break;
		case TYPE_COMMAND_CLOSEPROGRAM:
		{
			CUtil::PrintDebugString("TYPE_COMMAND_CLOSEPROGRAM Success\r\n");
		}
		break;
		case TYPE_COMMAND_WINDOWSHOWHIDE:
		{
			CUtil::PrintDebugString("TYPE_COMMAND_WINDOWSHOWHIDE Success\r\n");
		}
		break;
	}
#endif

	return CDialogEx::OnCopyData(pWnd, pCopyDataStruct);
}

#ifdef USE_PLC_MXCOMPONENT
BOOL CNEPESDlg::MMTimer_Start(int nTimeInterval)
{
	// nTimeInterval : timer call interval, unit : msec
	bool bResult = m_Timer.Start(nTimeInterval, m_MaxResolution);

	return (BOOL)bResult;
}


BOOL CNEPESDlg::MMTimer_Stop()
{
	m_Timer.Stop();

	return TRUE;
}

// Version 1.3.7.6 Save OK Image Period
BOOL CNEPESDlg::CheckPeriod(TYPE_CAMERAPOS eCameraPos, int periodTime)
{
	SYSTEMTIME curTime = GetCurrentPeriodTime(eCameraPos);
	SYSTEMTIME preTime = GetPreviousPeriodTime(eCameraPos);

	int gabDay		= curTime.wDay		- preTime.wDay;
	int gabHour		= curTime.wHour		- preTime.wHour;
	int gabminite	= curTime.wMinute	- preTime.wMinute;
	int gabTime		= (gabDay * 3600) + (gabHour * 60) + gabminite;

	if (gabTime		>= periodTime)	return TRUE;
	else							return FALSE;
}

// Version 1.3.7.6 Save OK Image Period
SYSTEMTIME CNEPESDlg::GetPreviousPeriodTime(TYPE_CAMERAPOS eCameraPos)
{
	SYSTEMTIME tempTime;
	if		(TYPE_CAMERAPOS_FIRST == eCameraPos) 	tempTime = m_stFirstPreTime;
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)   tempTime = m_stSecondPreTime;

	return tempTime;
}

// Version 1.3.7.6 Save OK Image Period
SYSTEMTIME CNEPESDlg::GetCurrentPeriodTime(TYPE_CAMERAPOS eCameraPos)
{
	SYSTEMTIME tempTime;
	if		(TYPE_CAMERAPOS_FIRST == eCameraPos) 	tempTime = m_stFirstCurTime;
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)   tempTime = m_stSecondCurTime;

	return tempTime;
}

// Version 1.3.7.6 Save OK Image Period
BOOL CNEPESDlg::SetPreviousPeriodTime(TYPE_CAMERAPOS eCameraPos)
{
	if		(TYPE_CAMERAPOS_FIRST == eCameraPos)	m_stFirstPreTime = m_stFirstCurTime;
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)	m_stSecondPreTime = m_stSecondCurTime;
	else if (TYPE_CAMERAPOS_MAX == eCameraPos)
	{
		m_stFirstPreTime = m_stFirstCurTime;
		m_stSecondPreTime = m_stSecondCurTime;
	}

	return TRUE;
}
// Version 1.3.7.6 Save OK Image Period
BOOL CNEPESDlg::SetCurrentPeriodTime(TYPE_CAMERAPOS eCameraPos)
{
	if		(TYPE_CAMERAPOS_FIRST == eCameraPos)	::GetLocalTime(&m_stFirstCurTime);
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)	::GetLocalTime(&m_stSecondCurTime);
	else if (TYPE_CAMERAPOS_MAX == eCameraPos)
	{
		::GetLocalTime(&m_stFirstCurTime);
		::GetLocalTime(&m_stSecondCurTime);
	}

	return TRUE;
}

// Version 1.3.6.9 Update
CString CNEPESDlg::MakeDeviceInfo(int eSelectLine, int eCurPos, int eActionState, int eHeaterNumber, const INFO_OPTION* pstOption, CSampleSide* pSample)
{
	CString strDeviceMemoryMap = _T("");

	switch (eActionState)
	{
		case TYPE_STATE_VISION_SENDINSPECTION:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + eCurPos * 0x10 + MEMORY0;
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
			return strDeviceMemoryMap;
		}
		break;
		case TYPE_STATE_PLC_SENDINSPECTION:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + eCurPos * 0x10 + MEMORY1;
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
			return strDeviceMemoryMap;
		}
		break;
		case TYPE_STATE_ALL_RESULTSIZE:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + eCurPos * 0x10 + MEMORY2;
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
			return strDeviceMemoryMap;
		}
		break;
		case TYPE_STATE_ALL_RESULTSHAPE:
		{
			// Version 1.3.6.9 Update
			int nMemoryMapIndex;
			if (pstOption != NULL)
			{
				if ((pstOption->m_stShapeToSize.m_bStep002 && (!pSample->m_StainResult.m_bResult	))		||
					(pstOption->m_stShapeToSize.m_bStep003 && (!pSample->m_DifferResult.m_bResult	))		||
					(pstOption->m_stShapeToSize.m_bStep004 && (!pSample->m_BubbleResult.m_bResult	))		||
					(pstOption->m_stShapeToSize.m_bStep005 && (!pSample->m_ScratchResult.m_bResult	))		||
					(pstOption->m_stShapeToSize.m_bStep006 && (!pSample->m_StampResult.m_bResult	)))
					nMemoryMapIndex = eSelectLine * 0x0100 + eCurPos * 0x10 + MEMORY2;
				else nMemoryMapIndex = eSelectLine * 0x0100 + eCurPos * 0x10 + MEMORY3;
			}
			else nMemoryMapIndex = eSelectLine * 0x0100 + eCurPos * 0x10 + MEMORY3;

			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
			return strDeviceMemoryMap;
		}
		break;
		case TYPE_STATE_ALL_AVERAGESIZE:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + eCurPos * 0x10 + MEMORY4;
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
			return strDeviceMemoryMap;
		}
		break;
		case TYPE_STATE_ALL_VALUESIZE:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + eCurPos * 0x10 + MEMORY5;
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
			return strDeviceMemoryMap;
		}
		break;
		case TPYE_STATE_VISION_LIVEBIT:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + MEMORY6; // 상하면 구분 없음
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
			return strDeviceMemoryMap;
		}
		break;
		// 온도 기록 준비
		case TPYE_STATE_TEMPERATURE:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + MEMORY7;
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
			return strDeviceMemoryMap;
		}
		break;
		// 온도 기록 요청
		case TPYE_STATE_TEMPERATURE_REQUEST:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + MEMORY8;
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
			return strDeviceMemoryMap;
		}
		// 현재 온도
		case TPYE_STATE_TEMPERATURE_SUB:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + MEMORY9 + eHeaterNumber;
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
		}
		break;
		// Version 1.3.6.5 (치수 영역 추가 없이 PLC 통신 데이터 추가 (X1-X2, L))
		// L Value
		case TYPE_STATE_ALL_LVALUESIZE:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + eCurPos * 0x10 + MEMORY10;
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
			return strDeviceMemoryMap;
		}
		break;
		// X1X2 Value
		case TYPE_STATE_ALL_X1X2VALUESIZE:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + eCurPos * 0x10 + MEMORY11;
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
			return strDeviceMemoryMap;
		}
		break;
		// Version 1.3.7.2
		// M1 Value
		case TYPE_STATE_ALL_M1VALUESIZE:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + eCurPos * 0x10 + MEMORY12;
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
			return strDeviceMemoryMap;
		}
		break;
		// M2 Value
		case TYPE_STATE_ALL_M2VALUESIZE:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + eCurPos * 0x10 + MEMORY13;
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
			return strDeviceMemoryMap;
		}
		break;
		// S1S3 Value
		case TYPE_STATE_ALL_S1S3VALUESIZE:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + eCurPos * 0x10 + MEMORY14;
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
			return strDeviceMemoryMap;
		}
		break;
		// Version 1.3.7.7
		case TYPE_STATE_PLCSYNC_YEAR:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + eCurPos * 0x10 + MEMORY15;
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
			return strDeviceMemoryMap;
		}
		break;
		case TYPE_STATE_PLCSYNC_MONTH:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + eCurPos * 0x10 + MEMORY16;
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
			return strDeviceMemoryMap;
		}
		break;
		case TYPE_STATE_PLCSYNC_DATE:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + eCurPos * 0x10 + MEMORY17;
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
			return strDeviceMemoryMap;
		}
		break;
		case TYPE_STATE_PLCSYNC_HOUR:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + eCurPos * 0x10 + MEMORY18;
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
			return strDeviceMemoryMap;
		}
		break;
		case TYPE_STATE_PLCSYNC_MINUTE:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + eCurPos * 0x10 + MEMORY19;
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
			return strDeviceMemoryMap;
		}
		break;
		case TYPE_STATE_PLCSYNC_SECOND:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + eCurPos * 0x10 + MEMORY20;
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
			return strDeviceMemoryMap;
		}
		break;
	}

	return strDeviceMemoryMap;
}

BOOL CNEPESDlg::AllClearPLCMemoryMap(int eSelectLine)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	for (int nPosInfo = 0; nPosInfo < 2; nPosInfo++)
	{
		CString strDeviceMemoryMap = MakeDeviceInfo(eSelectLine, nPosInfo, TYPE_STATE_VISION_SENDINSPECTION);

		long lRet = 0;
		long lValue = 3;

		pCaptureManager->LPMxComSetDevice(strDeviceMemoryMap, lValue);
	}

	m_bRequestedInspection = FALSE;
	m_bRealStartingInspectionPLC = FALSE;

	m_bRequestedInspectionSecond = FALSE;
	m_bRealStartingInspectionPLCSecond = FALSE;

	return TRUE;
}


// PLC Memory Map Checking
void CNEPESDlg::Update(CMMTimer &Timer)
{
	CUtil::PrintDebugString(_T(" ==== Update \r\n"));

	///          First  Second Camera
	/// Line 1     W20,    W30       W31 , W32, W33
	/// Line 2    W120,   W130 

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();

	CInspection* pInspection = pCaptureManager->GetInspection();
	if (pInspection->IsInit() && pInspection->IsStart())
	{
		CString strDeviceInfo = MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), TYPE_POS_FIRST, TYPE_STATE_PLC_SENDINSPECTION);
		pCaptureManager->LPMxComGetDevice(strDeviceInfo);

		strDeviceInfo = MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), TYPE_POS_SECOND, TYPE_STATE_PLC_SENDINSPECTION);
		pCaptureManager->LPMxComGetDevice(strDeviceInfo);

		//TODO : 온도 저장 요청 상태 확인
	}
}

void CALLBACK CB_VisionKeepAlive(HWND hWnd, UINT nID, UINT_PTR nEl, DWORD time)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();

	CWnd* m_pWnd = AfxGetMainWnd();
	CNEPESDlg* m_pParent = (CNEPESDlg*)m_pWnd;

	CString strDeviceInfo = m_pParent->MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), TYPE_POS_FIRST, TPYE_STATE_VISION_LIVEBIT);

	if (m_pParent->GetTRUE_AliveData())
	{
		//m_pParent->SetTRUE_AliveData(FALSE);
		if (pCaptureManager->LPMxComSetDevice(strDeviceInfo, 0))
		{
			m_pParent->SetTRUE_AliveData(FALSE);
		}
		else
		{
			m_pParent->SetTRUE_AliveData(TRUE);
		}
	}
	else
	{
		//m_pParent->SetTRUE_AliveData(TRUE);
		if (pCaptureManager->LPMxComSetDevice(strDeviceInfo, 1))
		{
			m_pParent->SetTRUE_AliveData(TRUE);
		}
		else
		{
			m_pParent->SetTRUE_AliveData(FALSE);
		}
	}
	strDeviceInfo = m_pParent->MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), TYPE_POS_FIRST, TPYE_STATE_VISION_LIVEBIT);

	CString strLogMessage = _T("");
	strLogMessage.Format(_T("CB_VisionKeepAlive ; Checking Vison Keep Alive Lit : %s \r\n"), strDeviceInfo);
	CUtil::PrintDebugString(strLogMessage);

	// TODO: 아래 온도 관련 동작은 별도 타이머로 분리
	//strDeviceInfo = m_pParent->MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), TYPE_POS_FIRST, TPYE_STATE_TEMPERATURE_REQUEST);
	//pCaptureManager->LPMxComGetDevice(strDeviceInfo);
}

void CALLBACK CB_TemperatureCheck(HWND hWnd, UINT nID, UINT_PTR nEl, DWORD time)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CWnd* m_pWnd = AfxGetMainWnd();
	CNEPESDlg* m_pParent = (CNEPESDlg*)m_pWnd;

	CString strDeviceInfo = m_pParent->MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), TYPE_POS_FIRST, TPYE_STATE_TEMPERATURE_REQUEST);
	pCaptureManager->LPMxComGetDevice(strDeviceInfo);
}

void CALLBACK CB_SynchronizationCheck(HWND hWnd, UINT nID, UINT_PTR nEl, DWORD time)
{
	CUtil::PrintDebugString(_T("PLCGetDataProcessThreadTimeSync [%d]\r\n"), ::GetTickCount());

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CWnd* m_pWnd = AfxGetMainWnd();
	CNEPESDlg* m_pParent = (CNEPESDlg*)m_pWnd;

	INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();
	if (pCaptureManager->GetMXComponentOpenCom())
	{
		CString strDeviceInfo;
		SYSTEMTIME stTime;
		::GetLocalTime(&stTime);

		strDeviceInfo = m_pParent->MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), TYPE_POS_FIRST, TYPE_STATE_PLCSYNC_YEAR);
		pCaptureManager->LPMxComSetDevice(strDeviceInfo, stTime.wYear);

		strDeviceInfo = m_pParent->MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), TYPE_POS_FIRST, TYPE_STATE_PLCSYNC_MONTH);
		pCaptureManager->LPMxComSetDevice(strDeviceInfo, stTime.wMonth);

		strDeviceInfo = m_pParent->MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), TYPE_POS_FIRST, TYPE_STATE_PLCSYNC_DATE);
		pCaptureManager->LPMxComSetDevice(strDeviceInfo, stTime.wDay);

		strDeviceInfo = m_pParent->MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), TYPE_POS_FIRST, TYPE_STATE_PLCSYNC_HOUR);
		pCaptureManager->LPMxComSetDevice(strDeviceInfo, stTime.wHour);

		strDeviceInfo = m_pParent->MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), TYPE_POS_FIRST, TYPE_STATE_PLCSYNC_MINUTE);
		pCaptureManager->LPMxComSetDevice(strDeviceInfo, stTime.wMinute);

		strDeviceInfo = m_pParent->MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), TYPE_POS_FIRST, TYPE_STATE_PLCSYNC_SECOND);
		pCaptureManager->LPMxComSetDevice(strDeviceInfo, stTime.wSecond);
	}
}

DWORD WINAPI CNEPESDlg::PLCGetDataProcessThreadProc(LPVOID lpArg)
{
	CNEPESDlg* pPLCGetDataProcess = (CNEPESDlg*)lpArg;

	return pPLCGetDataProcess->PLCGetDataProcessThreadProc();
}

DWORD CNEPESDlg::PLCGetDataProcessThreadProc()
{
	CUtil::PrintDebugString(_T("PLCGetDataProcessThreadProc [%d], First DeviceName  : %s, %d\r\n"), ::GetTickCount(), m_strGetDeviceName[0], m_lGetValue[0]);

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CNEPESDlg* pDlg = this;

	TCHAR szMessage[MAX_TEXT_LEN] = { 0, };
	INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();

	CInspection* pInspection = pCaptureManager->GetInspection();
	if (!pInspection->IsInit() || !pInspection->IsStart())
		return 0;

	BOOL bMatchCommand = FALSE;
	if (pInspection->IsInit() && pInspection->IsStart())
	{
		CString strGetDeviceName0 = m_strGetDeviceName[0];
		long lGetValue0 = m_lGetValue[0];

		CUtil::StringFormat(szMessage, MAX_TEXT_LEN, _T("INPUT Fisrt %s, %d\r\n"), strGetDeviceName0, lGetValue0);
		CUtil::PrintDebugString(szMessage);

		if (!strGetDeviceName0.CompareNoCase(_T("W20")) || !strGetDeviceName0.CompareNoCase(_T("W120")))
		{
			switch (lGetValue0)
			{
			case 0: // Confirm inspection result
			{
				CUtil::StringFormat(szMessage, MAX_TEXT_LEN, _T("Confirm inspection result : INPUT %s, %d \r\n"), strGetDeviceName0, lGetValue0);
				CUtil::PrintDebugString(szMessage);

				m_bRequestedInspection = FALSE;

				CString  strSetDeviceName = MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), TYPE_POS_FIRST, TYPE_STATE_VISION_SENDINSPECTION);
				pCaptureManager->LPMxComSetDevice(strSetDeviceName, 0);

				m_nFirstResultPLCSettingDelayCount = 0;
			}
			break;
			case 1: // Inspection start
			{
				if (!m_bRequestedInspection)
				{
					CUtil::StringFormat(szMessage, MAX_TEXT_LEN, _T("Inspection start : INPUT %s, %d \r\n"), strGetDeviceName0, lGetValue0);
					CUtil::PrintDebugString(szMessage);

					m_bRequestedInspection = TRUE;
					m_bRealStartingInspectionPLC = TRUE;

					CString  strSetDeviceName = MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), TYPE_POS_FIRST, TYPE_STATE_VISION_SENDINSPECTION);
					pCaptureManager->LPMxComSetDevice(strSetDeviceName, 1);

					{
						if (!strGetDeviceName0.CompareNoCase(_T("W20")) || !strGetDeviceName0.CompareNoCase(_T("W120")))
						{
							// Print Log
							{
								if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
									stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Command - Start First Camera");
							}
							bMatchCommand = TRUE;
							pDlg->AcquireForInspection(TYPE_CAMERAPOS_FIRST, TYPE_STEP_001);
						}
					}

					m_nFirstResultPLCSettingDelayCount++;

					/// Second Inspection Result End Setting  2
					if (m_nFirstResultPLCSettingDelayCount > PLC_CHECKCOUNT_RESULTDELAY)
					{
						if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
							stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "First Result Set Delay Count : %d", m_nFirstResultPLCSettingDelayCount);

						m_nFirstResultPLCSettingDelayCount = 0;

						// Inspection end
						CString strDeviceName = pDlg->MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), TYPE_CAMERAPOS_FIRST, TYPE_STATE_VISION_SENDINSPECTION);
						pCaptureManager->LPMxComSetDevice(strDeviceName, 2);
					}
				}
			}
			break;
			}
		}
	}

	return 0;
}


DWORD WINAPI CNEPESDlg::PLCGetDataProcessThreadProcSecond(LPVOID lpArg)
{
	CNEPESDlg* pPLCGetDataProcess = (CNEPESDlg*)lpArg;

	return pPLCGetDataProcess->PLCGetDataProcessThreadProcSecond();
}

DWORD CNEPESDlg::PLCGetDataProcessThreadProcSecond()
{
	CUtil::PrintDebugString(_T("PLCGetDataProcessThreadProcSecond [%d], Second DeviceName : %s, %d \r\n"), ::GetTickCount(), m_strGetDeviceName[1], m_lGetValue[1]);

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CNEPESDlg* pDlg = this;

	TCHAR szMessage[MAX_TEXT_LEN] = { 0, };
	INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();

	CInspection* pInspection = pCaptureManager->GetInspection();
	if (!pInspection->IsInit() || !pInspection->IsStart())
		return 0;

	BOOL bMatchCommand = FALSE;
	if (pInspection->IsInit() && pInspection->IsStart())
	{
		CString strGetDeviceName1 = m_strGetDeviceName[1];
		long lGetValue1 = m_lGetValue[1];

		CUtil::StringFormat(szMessage, MAX_TEXT_LEN, _T("INPUT Second : %s, %d \r\n"), strGetDeviceName1, lGetValue1);
		CUtil::PrintDebugString(szMessage);

		if (!strGetDeviceName1.CompareNoCase(_T("W30")) || !strGetDeviceName1.CompareNoCase(_T("W130")))
		{
			switch (lGetValue1)
			{
			case 0: // Confirm inspection result
			{
				CUtil::StringFormat(szMessage, MAX_TEXT_LEN, _T("Confirm inspection result : INPUT %s, %d \r\n"), strGetDeviceName1, lGetValue1);
				CUtil::PrintDebugString(szMessage);

				m_bRequestedInspectionSecond = FALSE;

				CString  strSetDeviceName = MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), TYPE_POS_SECOND, TYPE_STATE_VISION_SENDINSPECTION);
				pCaptureManager->LPMxComSetDevice(strSetDeviceName, 0);

				m_nSecondResultPLCSettingDelayCount = 0;
			}
			break;
			case 1: // Inspection start
			{
				if (!m_bRequestedInspectionSecond)
				{
					CUtil::StringFormat(szMessage, MAX_TEXT_LEN, _T("Inspection start : INPUT %s, %d \r\n"), strGetDeviceName1, lGetValue1);
					CUtil::PrintDebugString(szMessage);

					m_bRequestedInspectionSecond = TRUE;
					m_bRealStartingInspectionPLCSecond = TRUE;

					CString  strSetDeviceName = MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), TYPE_POS_SECOND, TYPE_STATE_VISION_SENDINSPECTION);
					pCaptureManager->LPMxComSetDevice(strSetDeviceName, 1);

					{
						if (!strGetDeviceName1.CompareNoCase(_T("W30")) || !strGetDeviceName1.CompareNoCase(_T("W130")))
						{
							// Print Log
							{
								if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
									stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Command - Start Second Camera");
							}
							bMatchCommand = TRUE;
							pDlg->AcquireForInspection(TYPE_CAMERAPOS_SECOND, TYPE_STEP_001);
						}
					}

					m_nSecondResultPLCSettingDelayCount++;

					/// Second Inspection Result End Setting  2
					if (m_nSecondResultPLCSettingDelayCount > PLC_CHECKCOUNT_RESULTDELAY)
					{
						if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
							stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Second Result Set Delay Count : %d", m_nSecondResultPLCSettingDelayCount);

						m_nSecondResultPLCSettingDelayCount = 0;

						// Inspection end
						CString strDeviceName = pDlg->MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), TYPE_CAMERAPOS_SECOND, TYPE_STATE_VISION_SENDINSPECTION);
						pCaptureManager->LPMxComSetDevice(strDeviceName, 2);
					}
				}
			}
			break;
			}
		}
	}

	return 0;
}


DWORD WINAPI CNEPESDlg::PLCGetDataProcessThreadTemperature(LPVOID lpArg)
{
	CNEPESDlg* pPLCGetDataProcess = (CNEPESDlg*)lpArg;

	return pPLCGetDataProcess->PLCGetDataProcessThreadTemperature();
}

DWORD CNEPESDlg::PLCGetDataProcessThreadTemperature()
{
	CUtil::PrintDebugString(_T("PLCGetDataProcessThreadTemperature [%d], DeviceName : %s, %d \r\n"), ::GetTickCount(), m_strGetDeviceName[2], m_lGetValue[2]);

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CNEPESDlg* pDlg = this;

	TCHAR szMessage[MAX_TEXT_LEN] = { 0, };
	INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();
	if (pCaptureManager->GetMXComponentOpenCom())
	{
		CString strGetDeviceName2 = m_strGetDeviceName[2];
		long lGetValue2 = m_lGetValue[2];

		if (strGetDeviceName2.CompareNoCase(_T("W2A")) == 0 || strGetDeviceName2.CompareNoCase(_T("W12A")) == 0)
		{
			CString strDeviceInfo;
			switch (lGetValue2)
			{
			case 0: // Confirm log end
				if (GetTempLogState() == TRUE)
				{
					strDeviceInfo = MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), TYPE_POS_FIRST, TPYE_STATE_TEMPERATURE);
					pCaptureManager->LPMxComSetDevice(strDeviceInfo, 0);
					SetTempLogState(FALSE);
				}
				else
				{
					// do nothing
				}
				break;
			case 1: // Log start
				if (GetTempLogState() == TRUE)
				{
					// do nothing
				}
				else
				{
					strDeviceInfo = MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), TYPE_POS_FIRST, TPYE_STATE_TEMPERATURE_SUB, 0);
					pCaptureManager->LPMxComGetDevice(strDeviceInfo);
					//SetTempLogState(TRUE);
					KillTimer(TIMERID_CHECK_PLC_TEMPERATURE);
				}
			}
		}
		else // W40~W59
		{
			int i = 0;
			for (; i < PLC_HEATER_MAX; i++)
			{
				CString strDeviceInfo = MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), TYPE_POS_FIRST, TPYE_STATE_TEMPERATURE_SUB, i);
				if (strGetDeviceName2.CompareNoCase(strDeviceInfo) == 0)
				{
					m_nHeaterValue[i] = lGetValue2;
					break;
				}
			}

			if (i >= PLC_HEATER_MAX - 1)
			{
				INFO_LOGFUNCHEATER stLogFunc = pCaptureManager->m_LogHeater.GetLogInterface();
				if (stLogFunc.m_pFuncHeaterLog && stLogFunc.m_pArg)
					stLogFunc.m_pFuncHeaterLog(stLogFunc.m_pArg, m_nHeaterValue);

				CString strDeviceInfo = MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), TYPE_POS_FIRST, TPYE_STATE_TEMPERATURE);
				pCaptureManager->LPMxComSetDevice(strDeviceInfo, 1);
				SetTempLogState(TRUE);
				m_nPLC_CHECKTEMPERATURE_Timer = SetTimer(TIMERID_CHECK_PLC_TEMPERATURE, TEMPERATURE_TICK, CB_TemperatureCheck);
			}
			else
			{
				// Get next value
				CString strDeviceInfo = MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(), TYPE_POS_FIRST, TPYE_STATE_TEMPERATURE_SUB, i + 1);
				pCaptureManager->LPMxComGetDevice(strDeviceInfo);
			}
		}
	}
	return 0;
}

// Version 1.3.7.7 (PC - PLC Sync)
DWORD WINAPI CNEPESDlg::PLCGetDataProcessThreadTimeSync(LPVOID lpArg)
{
	CNEPESDlg* pPLCGetDataProcess = (CNEPESDlg*)lpArg;

	return pPLCGetDataProcess->PLCGetDataProcessThreadTimeSync();
}

// Version 1.3.7.7 (PC - PLC Sync)
DWORD CNEPESDlg::PLCGetDataProcessThreadTimeSync()
{
	CUtil::PrintDebugString(_T("PLCGetDataProcessThreadTimeSync [%d]\r\n"), ::GetTickCount());

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CNEPESDlg* pDlg = this;

	INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();
	if (pCaptureManager->GetMXComponentOpenCom())
	{
		CString strDeviceInfo;
		SYSTEMTIME stTime;
		::GetLocalTime(&stTime);
		
		strDeviceInfo = MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(),		TYPE_POS_FIRST, TYPE_STATE_PLCSYNC_YEAR);
		pCaptureManager->LPMxComSetDevice(strDeviceInfo, stTime.wYear);

		strDeviceInfo = MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(),		TYPE_POS_FIRST, TYPE_STATE_PLCSYNC_MONTH);
		pCaptureManager->LPMxComSetDevice(strDeviceInfo, stTime.wMonth);

		strDeviceInfo = pDlg->MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(),	TYPE_POS_FIRST, TYPE_STATE_PLCSYNC_DATE);
		pCaptureManager->LPMxComSetDevice(strDeviceInfo, stTime.wDay);

		strDeviceInfo = pDlg->MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(),	TYPE_POS_FIRST, TYPE_STATE_PLCSYNC_HOUR);
		pCaptureManager->LPMxComSetDevice(strDeviceInfo, stTime.wHour);

		strDeviceInfo = pDlg->MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(),	TYPE_POS_FIRST, TYPE_STATE_PLCSYNC_MINUTE);
		pCaptureManager->LPMxComSetDevice(strDeviceInfo, stTime.wMinute);

		strDeviceInfo = pDlg->MakeDeviceInfo(pCaptureManager->GetSelectLineInfo(),	TYPE_POS_FIRST, TYPE_STATE_PLCSYNC_SECOND);
		pCaptureManager->LPMxComSetDevice(strDeviceInfo, stTime.wSecond);
		
	}
	return 0;
}




bool CNEPESDlg::PLCGetDataProcessThreadAllClose()
{
	if (m_hPLCGetDataProcessThread)
		::CloseHandle(m_hPLCGetDataProcessThread);
	m_hPLCGetDataProcessThread = NULL;

	if (m_hPLCGetDataProcessThreadSecond)
		::CloseHandle(m_hPLCGetDataProcessThreadSecond);
	m_hPLCGetDataProcessThreadSecond = NULL;
	// Version 1.3.7.7
	if (m_hPLCGetDataProcessThreadTimeSync)
		::CloseHandle(m_hPLCGetDataProcessThreadTimeSync);
	m_hPLCGetDataProcessThreadTimeSync = NULL;
	return true;
}


#endif