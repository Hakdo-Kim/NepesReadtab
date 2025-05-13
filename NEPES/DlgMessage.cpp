// DlgMessage.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "DlgMessage.h"
#include "afxdialogex.h"

#include "Common.h"
#include "CaptureManager.h"
#include "Util/Util.h"

#include "stringres.h"

// CDlgMessage dialog

IMPLEMENT_DYNAMIC(CDlgMessage, CDialogEx)

CDlgMessage::CDlgMessage(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgMessage::IDD, pParent)
{
	m_eLoadingType = TYPE_LOAD_NONE;
	m_dwPosFlag = 0;
	m_dwOptFlag = 0;
}

CDlgMessage::~CDlgMessage()
{
}

void CDlgMessage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL CDlgMessage::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (IDOK == wParam)
	{
		return TRUE;
	}
	return CDialogEx::OnCommand(wParam, lParam);
}

BOOL CDlgMessage::PreTranslateMessage(MSG* pMsg)
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

BOOL CDlgMessage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	this->SetTimer(TIMERID, MSEC_TIMER, NULL);
	return TRUE;
}

BEGIN_MESSAGE_MAP(CDlgMessage, CDialogEx)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CDlgMessage message handlers

void CDlgMessage::OnTimer(UINT_PTR nIDEvent)
{
	if (TIMERID == nIDEvent)
	{
		this->KillTimer(TIMERID);

		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
		if (TYPE_LOAD_CONNECTCAMERA == m_eLoadingType)
		{
			GetDlgItem(IDC_STATIC_MESSAGE)->SetWindowText(STR_CAMERA_CONNECTED);
			pCaptureManager->CreateCaptureConnection();
			this->UpdateCameraListFromReg();
			CUtil::PumpMessage();

			CUtil::WaitnSleep(100);
			
			pCaptureManager->StartCaptureConnection();
			CUtil::PumpMessage();

			// Check Trigger Mode...
			{
				DWORD dwPosFlag = 0;
				DWORD dwOptFlag = 0;

				BOOL bChangeTriggerMode = GetLoadFlagTriggerMode(dwPosFlag, dwOptFlag);
				if (bChangeTriggerMode)
				{
					SetLoadType(TYPE_LOAD_TRIGGERMODE, dwPosFlag, dwOptFlag);

					GetDlgItem(IDC_STATIC_MESSAGE)->SetWindowText(STR_MSG_TRIGGERMODE);
					UpdateTriggerMode();
					CUtil::WaitnSleep(100);
				}
			}

		}
		else if (TYPE_LOAD_DISCONNECTCAMERA == m_eLoadingType)
		{
			GetDlgItem(IDC_STATIC_MESSAGE)->SetWindowText(STR_CAMERA_DISCONNECTED);
			pCaptureManager->CloseCaptureConnection();

			CUtil::Sleep(500);
		}
		else if (TYPE_LOAD_RESEARCHCAMERA == m_eLoadingType)
		{
			// Disconnect
			GetDlgItem(IDC_STATIC_MESSAGE)->SetWindowText(STR_CAMERA_DISCONNECTED);
			pCaptureManager->CloseCaptureConnection();

			CUtil::Sleep(500);


			// Connect
			GetDlgItem(IDC_STATIC_MESSAGE)->SetWindowText(STR_CAMERA_CONNECTED);
			pCaptureManager->CreateCaptureConnection();
			this->UpdateCameraListFromReg();

			CUtil::Sleep(100);
			pCaptureManager->StartCaptureConnection();

			// Check Trigger Mode...
			{
				DWORD dwPosFlag = 0;
				DWORD dwOptFlag = 0;

				BOOL bChangeTriggerMode = GetLoadFlagTriggerMode(dwPosFlag, dwOptFlag);
				if (bChangeTriggerMode)
				{
					SetLoadType(TYPE_LOAD_TRIGGERMODE, dwPosFlag, dwOptFlag);

					GetDlgItem(IDC_STATIC_MESSAGE)->SetWindowText(STR_MSG_TRIGGERMODE);
					UpdateTriggerMode();
					CUtil::Sleep(100);
				}
			}

		}
		else if (TYPE_LOAD_TRIGGERMODE == m_eLoadingType)
		{
			GetDlgItem(IDC_STATIC_MESSAGE)->SetWindowText(STR_CAMERA_FREERUN);
			UpdateTriggerMode();
		}

		else if (TYPE_LOAD_INSPECTIONENV_READY == m_eLoadingType)
		{
			GetDlgItem(IDC_STATIC_MESSAGE)->SetWindowText(STR_INSPECTION_READYSTATE);
			if (m_hTargetWnd)
				::SendMessage(m_hTargetWnd, WM_NOTIFY_CHECK_INSPECTIONENV_READY, NULL, NULL);
		}

		this->SendMessage(WM_CLOSE);
	}
}

void CDlgMessage::SetLoadType(TYPE_LOAD eType, DWORD dwPosFlag, DWORD dwOptFlag)
{
	m_eLoadingType = eType;
	m_dwPosFlag = dwPosFlag;
	m_dwOptFlag = dwOptFlag;
}

void CDlgMessage::UpdateCameraListFromReg()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	BOOL bResult = FALSE;

	TCHAR szFirst[MAX_NAME_LEN] = { 0, };
	bResult = CUtil::GetRegString(REG_ROOT_PATH, REG_VALUE_CAMERA_FIRST, szFirst, MAX_NAME_LEN);

#ifdef USE_BASLER_CAMERA
	if (bResult)
	{
		const int nIdx = pCaptureManager->GetConnectedDeviceID(TYPE_NETWORK_BASLER, szFirst);
		if (0 > nIdx)
			pCaptureManager->SetCapturePosition(TYPE_CAMERAPOS_FIRST, TYPE_NETWORK_NONE, -1);
		else
			pCaptureManager->SetCapturePosition(TYPE_CAMERAPOS_FIRST, TYPE_NETWORK_BASLER, nIdx);
	}

	TCHAR szSecond[MAX_NAME_LEN] = { 0, };
	bResult = CUtil::GetRegString(REG_ROOT_PATH, REG_VALUE_CAMERA_SECOND, szSecond, MAX_NAME_LEN);
	if (bResult)
	{
		const int nIdx = pCaptureManager->GetConnectedDeviceID(TYPE_NETWORK_BASLER, szSecond);
		if (0 > nIdx)
			pCaptureManager->SetCapturePosition(TYPE_CAMERAPOS_SECOND, TYPE_NETWORK_NONE, -1);
		else
			pCaptureManager->SetCapturePosition(TYPE_CAMERAPOS_SECOND, TYPE_NETWORK_BASLER, nIdx);
	}
#endif

#ifdef USE_GIGE_CAMERA
	if (bResult)
	{
		const int nIdx = pCaptureManager->GetConnectedDeviceID(TYPE_NETWORK_GIGE, szFirst);
		if (0 > nIdx)
			pCaptureManager->SetCapturePosition(TYPE_CAMERAPOS_FIRST, TYPE_NETWORK_NONE, -1);
		else
			pCaptureManager->SetCapturePosition(TYPE_CAMERAPOS_FIRST, TYPE_NETWORK_GIGE, nIdx);
	}

	TCHAR szSecond[MAX_NAME_LEN] = { 0, };
	bResult = CUtil::GetRegString(REG_ROOT_PATH, REG_VALUE_CAMERA_SECOND, szSecond, MAX_NAME_LEN);
	if (bResult)
	{
		const int nIdx = pCaptureManager->GetConnectedDeviceID(TYPE_NETWORK_GIGE, szSecond);
		if (0 > nIdx)
			pCaptureManager->SetCapturePosition(TYPE_CAMERAPOS_SECOND, TYPE_NETWORK_NONE, -1);
		else
			pCaptureManager->SetCapturePosition(TYPE_CAMERAPOS_SECOND, TYPE_NETWORK_GIGE, nIdx);
	}
#endif

}



void CDlgMessage::UpdateTriggerMode()
{
	// GigE
	UpdateTriggerMode(TYPE_CAMERAPOS_FIRST);
	UpdateTriggerMode(TYPE_CAMERAPOS_SECOND);

}

void CDlgMessage::UpdateTriggerMode(TYPE_CAMERAPOS ePos)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	DWORD POS = 0x00;
	BOOL bTrigger = FALSE;

	if (TYPE_CAMERAPOS_FIRST == ePos)
	{
		//CUtil::PrintDebugString(_T("\t [UpdateTriggerMode] TYPE_CAMERAPOS_FIRST \r\n"));
		POS = FLAG_FIRST;
		if (FLAG_OPT_FIRST & m_dwOptFlag)
		{
#ifdef DEF_FREERUN_CAPTURE
			bTrigger = FALSE;
#else
			bTrigger = TRUE;
#endif
		}
	}
	else if (TYPE_CAMERAPOS_SECOND == ePos)
	{
		//CUtil::PrintDebugString(_T("\t [UpdateTriggerMode] TYPE_CAMERAPOS_SECOND \r\n"));
		POS = FLAG_SECOND;
		if (FLAG_OPT_SECOND & m_dwOptFlag)
		{
#ifdef DEF_FREERUN_CAPTURE
			bTrigger = FALSE;
#else
			bTrigger = TRUE;
#endif
		}
	}
	else
	{
		//CUtil::PrintDebugString(_T("\t [UpdateTriggerMode] TYPE_CAMERAPOS_NONE \r\n"));
		return;
	}

	const INFO_CAPTUREPROC* pstCaptureProc = pCaptureManager->GetCapturePosition(ePos);
	if ((POS & m_dwPosFlag) && pstCaptureProc)
	{
		INFO_TRIGGER_PARA stParam;
		memset(&stParam, 0x00, sizeof(INFO_TRIGGER_PARA));

		BOOL bResult = pCaptureManager->GetTriggerMode(pstCaptureProc->m_eNetwork, pstCaptureProc->m_dwProcID, &stParam);
		if (FALSE == bResult)
			return;

		BOOL bChangeTrigger = FALSE;
		if (bTrigger)
		{
			if (TRIGGER_ON != stParam.nTriggerMode)
				bChangeTrigger = TRUE;
			stParam.nTriggerMode = TRIGGER_ON;
		}
		else
		{
			if (TRIGGER_OFF != stParam.nTriggerMode)
				bChangeTrigger = TRUE;
			stParam.nTriggerMode = TRIGGER_OFF;
		}


		// FLAG_OPT_LEFT && FLAG_OPT_RIGHT
		{

#ifdef DEF_FREERUN_CAPTURE
			stParam.nTriggerMode = TRIGGER_OFF;
			stParam.nTriggerSource = TRIGGER_SRC_SW;
#else
			stParam.nTriggerSource = TRIGGER_SRC_SW;
#endif
		}

		if (bChangeTrigger)
		{
			pCaptureManager->Stop(pstCaptureProc->m_eNetwork, pstCaptureProc->m_dwProcID);
#ifdef USE_BASLER_CAMERA
			if (TYPE_NETWORK_BASLER == pstCaptureProc->m_eNetwork)
#endif
#ifdef USE_GIGE_CAMERA
			if (TYPE_NETWORK_GIGE == pstCaptureProc->m_eNetwork)
#endif
				CUtil::WaitnSleep(500);
			else
				CUtil::WaitnSleep(100);

			bResult = pCaptureManager->SetTriggerMode(pstCaptureProc->m_eNetwork, pstCaptureProc->m_dwProcID, stParam);
			
			bResult = pCaptureManager->Start(pstCaptureProc->m_eNetwork, pstCaptureProc->m_dwProcID);

		}
	}
	CUtil::WaitnSleep(100);
}

BOOL CDlgMessage::GetLoadFlagTriggerMode(DWORD& dwPosFlag, DWORD& dwOptFlag)
{
	BOOL bChangeTrigger = FALSE;

	DWORD dwTriggerMode = 0;
	DWORD dwTriggerSrc = 0;

	// First
	BOOL bResult = GetTriggerModeFromCamera(TYPE_CAMERAPOS_FIRST, dwTriggerMode, dwTriggerSrc);
	if (bResult)
	{
#ifdef DEF_FREERUN_CAPTURE
		if (TRIGGER_OFF != dwTriggerMode)
#else
		if (TRIGGER_ON == dwTriggerMode && TRIGGER_SRC_SW != dwTriggerSrc)
#endif
		{
			bChangeTrigger = TRUE;

			dwPosFlag |= FLAG_FIRST;
			dwOptFlag |= FLAG_OPT_FIRST;
		}
	}

	// Second
	bResult = GetTriggerModeFromCamera(TYPE_CAMERAPOS_SECOND, dwTriggerMode, dwTriggerSrc);
	if (bResult)
	{
#ifdef DEF_FREERUN_CAPTURE
		if (TRIGGER_OFF != dwTriggerMode)
#else
		if (TRIGGER_ON == dwTriggerMode && TRIGGER_SRC_SW != dwTriggerSrc)
#endif
		{
			bChangeTrigger = TRUE;

			dwPosFlag |= FLAG_SECOND;
			dwOptFlag |= FLAG_OPT_SECOND;
		}
	}

	return bChangeTrigger;
}

BOOL CDlgMessage::GetTriggerModeFromCamera(TYPE_CAMERAPOS ePos, DWORD& dwTriggerMode, DWORD& dwTriggerSrc)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	INFO_TRIGGER_PARA stParam;
	memset(&stParam, 0x00, sizeof(INFO_TRIGGER_PARA));

	BOOL bResult = FALSE;

	const INFO_CAPTUREPROC* pstProc = pCaptureManager->GetCapturePosition(ePos);
	if (pstProc)
	{
		bResult = pCaptureManager->GetTriggerMode(pstProc->m_eNetwork, pstProc->m_dwProcID, &stParam);
		if (bResult)
		{
			dwTriggerMode = stParam.nTriggerMode;
			dwTriggerSrc = stParam.nTriggerSource;
		}
	}

	return bResult;
}