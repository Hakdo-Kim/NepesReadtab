#include "StdAfx.h"
#include "CaptureManager.h"

#include "../nepes/stringres.h"
#include "Util/Util.h"

#pragma warning(disable:4996)

CCaptureManager* CCaptureManager::pInstance;

CCaptureManager* CCaptureManager::GetInstance()
{
	if (NULL == pInstance)
	{
		pInstance = new CCaptureManager;
		pInstance->InitLibrary();
	}
	return pInstance;
}

void CCaptureManager::ReleaseInstance()
{
	if (NULL == pInstance)
		return;

	DeinitLibrary();

	if (NULL != pInstance)
	{
		delete pInstance;
		pInstance = NULL;
	}
}

CCaptureManager::CCaptureManager()
{
	for (int i = 0; i < MAX_CAMERA_INTERFACE; i++)
	{
		m_pCameraProcess[i] = NULL;
		memset(&m_pCaptureProc[i], 0x00, sizeof(INFO_CAPTUREPROC));
	}
	for (int i = 0; i < TYPE_CAMERAPOS_MAX; i++)
	{
		m_pCapturePosition[i] = NULL;
	}
	memset(&m_stCaptureVideo, 0x00, sizeof(INFO_CAPTUREVIDEO));


	for (int i = 0; i < TYPE_NETWORK_MAX; i++)
	{
		m_pCamera[i] = NULL;
	}

	//
	m_pFuncSerialListener = NULL;
	m_pArgument = NULL;

	m_pCommunicatePort = NULL;

	memset(&m_stOption, 0x00, sizeof(INFO_OPTION));
	memset(&m_stOptionEtc, 0x00, sizeof(INFO_OPTIONETC));
	memset(&m_stResultSummary, 0x00, sizeof(INFO_SUMMARY));
	memset(&m_stScenario, 0x00, sizeof(INFO_SCENARIO));
	memset(&m_stStrobe, 0x00, sizeof(INFO_STROBE));

#ifdef USE_PLC_MXCOMPONENT
	m_bMXComponentOpenCom = FALSE;
	m_hTargetMXComModuleWnd = NULL;
	m_hNetPassMainDlgWnd = NULL;
	m_ePLCProtocolType = PLC_DEFAULT_PROTOCOLTYPE;
	m_ePLCControlType = PLC_DEFAULT_CONTROLTYPE;
	m_nPLCStationNumber = PLC_DEFAULT_STATIONNUMBER;
	m_strPLCHostAddress = PLC_DEFAULT_HOSTADDRESS;
#endif

	m_bFirstCameraReverseX = FALSE;
	m_bFirstCameraReverseY = FALSE;
	m_bSecondCameraReverseX = FALSE;
	m_bSecondCameraReverseY = FALSE;
}

CCaptureManager::~CCaptureManager()
{
}

BOOL CCaptureManager::InitLibrary()
{
	::InitializeCriticalSection(&m_CriticalSection);

	TCHAR pszCurDir[MAX_FILE_PATH_LEN] = { 0, };
	CUtil::GetCurrentDirectory(pszCurDir, MAX_FILE_PATH_LEN);

	/// Load Camera Default Information
	m_CameraDevice.ClearAll();

	TCHAR pszConfigDir[MAX_FILE_PATH_LEN] = { 0, };
	CUtil::StringCopy(pszConfigDir, pszCurDir);
	CUtil::StringCat(pszConfigDir, _T("\\Config\\navi_lpcamera.xml"));
	m_Xml.LoadDefCamera(pszConfigDir, m_CameraDevice);

	CUtil::StringCopy(pszConfigDir, pszCurDir);
	CUtil::StringCat(pszConfigDir, _T("\\Config\\navi_lpcamera_userconfig.xml"));
	m_Xml.LoadCameraUserConfig(pszConfigDir, m_CameraDevice);
	//*/


	CUtil::StringCopy(pszConfigDir, pszCurDir);
	CUtil::StringCat(pszConfigDir, _T("\\Option\\DefaultOption.xml"));
	{
		m_stOption.m_stFirstCameraStep.m_bStep001 = TRUE;
		m_stOption.m_stFirstCameraStep.m_bStep002 = TRUE;
		m_stOption.m_stFirstCameraStep.m_bStep003 = TRUE;
		m_stOption.m_stFirstCameraStep.m_bStep004 = TRUE;
		m_stOption.m_stFirstCameraStep.m_bStep005 = TRUE;
		m_stOption.m_stFirstCameraStep.m_bStep006 = TRUE;

		m_stOption.m_stSecondCameraStep.m_bStep001 = FALSE;
		m_stOption.m_stSecondCameraStep.m_bStep002 = TRUE;
		m_stOption.m_stSecondCameraStep.m_bStep003 = TRUE;
		m_stOption.m_stSecondCameraStep.m_bStep004 = TRUE;
		m_stOption.m_stSecondCameraStep.m_bStep005 = TRUE;
		m_stOption.m_stSecondCameraStep.m_bStep006 = TRUE;

		// Version 1.3.6.9 Update
		m_stOption.m_stShapeToSize.m_bStep001 = FALSE;
		m_stOption.m_stShapeToSize.m_bStep002 = FALSE;
		m_stOption.m_stShapeToSize.m_bStep003 = FALSE;
		m_stOption.m_stShapeToSize.m_bStep004 = FALSE;
		m_stOption.m_stShapeToSize.m_bStep005 = FALSE;
		m_stOption.m_stShapeToSize.m_bStep006 = FALSE;
	}
	m_Xml.LoadOption(pszConfigDir, m_stOption);
	{
		// Default Setting - Step Title
		if (1 > CUtil::StringLength(m_stOption.m_stFirstCameraStep.m_szTitleStep01))
			CUtil::StringCopy(m_stOption.m_stFirstCameraStep.m_szTitleStep01, STR_MSG_SEQUENCE_STEP01);
		if (1 > CUtil::StringLength(m_stOption.m_stFirstCameraStep.m_szTitleStep02))
			CUtil::StringCopy(m_stOption.m_stFirstCameraStep.m_szTitleStep02, STR_MSG_SEQUENCE_STEP02);
		if (1 > CUtil::StringLength(m_stOption.m_stFirstCameraStep.m_szTitleStep03))
			CUtil::StringCopy(m_stOption.m_stFirstCameraStep.m_szTitleStep03, STR_MSG_SEQUENCE_STEP03);
		if (1 > CUtil::StringLength(m_stOption.m_stFirstCameraStep.m_szTitleStep04))
			CUtil::StringCopy(m_stOption.m_stFirstCameraStep.m_szTitleStep04, STR_MSG_SEQUENCE_STEP04);
		if (1 > CUtil::StringLength(m_stOption.m_stFirstCameraStep.m_szTitleStep05))
			CUtil::StringCopy(m_stOption.m_stFirstCameraStep.m_szTitleStep05, STR_MSG_SEQUENCE_STEP05);
		if (1 > CUtil::StringLength(m_stOption.m_stFirstCameraStep.m_szTitleStep06))
			CUtil::StringCopy(m_stOption.m_stFirstCameraStep.m_szTitleStep06, STR_MSG_SEQUENCE_STEP06);

		if (1 > CUtil::StringLength(m_stOption.m_stSecondCameraStep.m_szTitleStep01))
			CUtil::StringCopy(m_stOption.m_stSecondCameraStep.m_szTitleStep01, STR_MSG_SEQUENCE_STEP01);
		if (1 > CUtil::StringLength(m_stOption.m_stSecondCameraStep.m_szTitleStep02))
			CUtil::StringCopy(m_stOption.m_stSecondCameraStep.m_szTitleStep02, STR_MSG_SEQUENCE_STEP02);
		if (1 > CUtil::StringLength(m_stOption.m_stSecondCameraStep.m_szTitleStep03))
			CUtil::StringCopy(m_stOption.m_stSecondCameraStep.m_szTitleStep03, STR_MSG_SEQUENCE_STEP03);
		if (1 > CUtil::StringLength(m_stOption.m_stSecondCameraStep.m_szTitleStep04))
			CUtil::StringCopy(m_stOption.m_stSecondCameraStep.m_szTitleStep04, STR_MSG_SEQUENCE_STEP04);
		if (1 > CUtil::StringLength(m_stOption.m_stSecondCameraStep.m_szTitleStep05))
			CUtil::StringCopy(m_stOption.m_stSecondCameraStep.m_szTitleStep05, STR_MSG_SEQUENCE_STEP05);
		if (1 > CUtil::StringLength(m_stOption.m_stSecondCameraStep.m_szTitleStep06))
			CUtil::StringCopy(m_stOption.m_stSecondCameraStep.m_szTitleStep06, STR_MSG_SEQUENCE_STEP06);

		// Version 1.3.6.9 Update
		if (1 > CUtil::StringLength(m_stOption.m_stShapeToSize.m_szTitleStep01))
			CUtil::StringCopy(m_stOption.m_stShapeToSize.m_szTitleStep01, STR_MSG_SEQUENCE_STEP01);
		if (1 > CUtil::StringLength(m_stOption.m_stShapeToSize.m_szTitleStep02))
			CUtil::StringCopy(m_stOption.m_stShapeToSize.m_szTitleStep02, STR_MSG_SEQUENCE_STEP02);
		if (1 > CUtil::StringLength(m_stOption.m_stShapeToSize.m_szTitleStep03))
			CUtil::StringCopy(m_stOption.m_stShapeToSize.m_szTitleStep03, STR_MSG_SEQUENCE_STEP03);
		if (1 > CUtil::StringLength(m_stOption.m_stShapeToSize.m_szTitleStep04))
			CUtil::StringCopy(m_stOption.m_stShapeToSize.m_szTitleStep04, STR_MSG_SEQUENCE_STEP04);
		if (1 > CUtil::StringLength(m_stOption.m_stShapeToSize.m_szTitleStep05))
			CUtil::StringCopy(m_stOption.m_stShapeToSize.m_szTitleStep05, STR_MSG_SEQUENCE_STEP05);
		if (1 > CUtil::StringLength(m_stOption.m_stShapeToSize.m_szTitleStep06))
			CUtil::StringCopy(m_stOption.m_stShapeToSize.m_szTitleStep06, STR_MSG_SEQUENCE_STEP06);
	}



	// Option Etc
	TCHAR szString[MAX_FILE_PATH_LEN] = { 0, };
	DWORD dwValue = 0;

	BOOL bResult = CUtil::GetRegString(REG_ROOT_PATH, REG_VALUE_OPTION_LOTIDPATH, szString, MAX_FILE_PATH_LEN);
	//if (FALSE == bResult || FALSE == CUtil::IsExistFile(szString))
	if (FALSE == bResult || FALSE == CUtil::IsDirectory(szString))
	{
		CUtil::GetCurrentDirectory(m_stOptionEtc.m_szLotIdPath, MAX_FILE_PATH_LEN);
		CUtil::StringFormat(szString, MAX_FILE_PATH_LEN, _T("%s\\%s"), m_stOptionEtc.m_szLotIdPath, _T("LotID"));
		if (CUtil::IsDirectory(szString))
			CUtil::StringCopy(m_stOptionEtc.m_szLotIdPath, szString);
	}
	else
	{
		CUtil::StringCopy(m_stOptionEtc.m_szLotIdPath, szString);
	}

	bResult = CUtil::GetRegString(REG_ROOT_PATH, REG_VALUE_OPTION_LOGPATH, szString, MAX_FILE_PATH_LEN);
	//if (FALSE == bResult || FALSE == CUtil::IsExistFile(szString))
	if (FALSE == bResult || FALSE == CUtil::IsDirectory(szString))
	{
		CUtil::GetCurrentDirectory(m_stOptionEtc.m_stLogInfo.m_szLogPath, MAX_FILE_PATH_LEN);
		CUtil::StringFormat(szString, MAX_FILE_PATH_LEN, _T("%s\\%s"), m_stOptionEtc.m_stLogInfo.m_szLogPath, _T("Log"));
		if (CUtil::IsDirectory(szString))
			CUtil::StringCopy(m_stOptionEtc.m_stLogInfo.m_szLogPath, szString);
	}
	else
	{
		CUtil::StringCopy(m_stOptionEtc.m_stLogInfo.m_szLogPath, szString);
	}

	bResult = CUtil::GetRegDword(REG_ROOT_PATH, REG_VALUE_OPTION_SAVETEXT, dwValue);
	if (FALSE == bResult)
		m_stOptionEtc.m_stLogInfo.m_bSaveTextLog = FALSE;
	else
		m_stOptionEtc.m_stLogInfo.m_bSaveTextLog = (BOOL)dwValue;
	
	bResult = CUtil::GetRegDword(REG_ROOT_PATH, REG_VALUE_OPTION_SAVEERRORIMAGE, dwValue);
	if (FALSE == bResult)
		m_stOptionEtc.m_stLogInfo.m_bSaveErrorImage = FALSE;
	else
		m_stOptionEtc.m_stLogInfo.m_bSaveErrorImage = (BOOL)dwValue;

	bResult = CUtil::GetRegDword(REG_ROOT_PATH, REG_VALUE_OPTION_SAVEPROBIMAGE, dwValue);
	if (FALSE == bResult)
		m_stOptionEtc.m_stLogInfo.m_bSaveProbImage = FALSE;
	else
		m_stOptionEtc.m_stLogInfo.m_bSaveProbImage = (BOOL)dwValue;

	this->m_Log.UpdateLogInformation(&m_stOptionEtc.m_stLogInfo);
	this->m_LogHeater.UpdateLogInformation(&m_stOptionEtc.m_stLogInfo);

	// Ver 1.362
	// 2022-04-08 추가
	// Save Image Format 초기값 설정
	// 양품 이미지 저장 초기값 설정
	bResult = CUtil::GetRegString(REG_ROOT_PATH, REG_VALUE_OPTION_SAVEIMAGEFORMAT, (TCHAR*)szString, MAX_FILE_PATH_LEN);
	if (FALSE == bResult)
		CUtil::StringCopy(m_stOptionEtc.m_stLogInfo.m_szSaveImageFormat, ".png");
	else
		CUtil::StringCopy(m_stOptionEtc.m_stLogInfo.m_szSaveImageFormat, (TCHAR*)szString);
	
	bResult = CUtil::GetRegDword(REG_ROOT_PATH, REG_VALUE_OPTION_SAVEOKIMAGE, dwValue);
	if (FALSE == bResult)
		m_stOptionEtc.m_stLogInfo.m_bSaveOKImage = FALSE;
	else
		m_stOptionEtc.m_stLogInfo.m_bSaveOKImage = (BOOL)dwValue;

	// Ver 1.367
	if (CUtil::StringCompare(m_stOptionEtc.m_stLogInfo.m_szSaveImageFormat, ".png")) m_stOptionEtc.m_stLogInfo.m_nFormatCount = 0;

	bResult = CUtil::GetRegDword(REG_ROOT_PATH, REG_VALUE_OPTION_IMAGECOUNT, dwValue);
	if (FALSE == bResult)
		m_stOptionEtc.m_stLogInfo.m_nUserSetCount = 0;
	else
		m_stOptionEtc.m_stLogInfo.m_nUserSetCount = dwValue;

	// Version 1.3.7.6 Save OK Image Period
	bResult = CUtil::GetRegDword(REG_ROOT_PATH, REG_VALUE_OPTION_PERIOD_CHECK, dwValue);
	if (FALSE == bResult)
		m_stOptionEtc.m_stLogInfo.m_bSaveOKImage_Period = FALSE;
	else
		m_stOptionEtc.m_stLogInfo.m_bSaveOKImage_Period = (BOOL)dwValue;

	bResult = CUtil::GetRegDword(REG_ROOT_PATH, REG_VALUE_OPTION_PERIOD_TIME, dwValue);
	if (FALSE == bResult)
		m_stOptionEtc.m_stLogInfo.m_nSavePeriodTime = 0;
	else
		m_stOptionEtc.m_stLogInfo.m_nSavePeriodTime = dwValue;


#ifdef DEF_FREERUN_CAPTURE
	SetReadySnapCapture(FALSE);
	SetReadySnapCapture(TYPE_CAMERAPOS_FIRST, TRUE);
	SetReadySnapCapture(TYPE_CAMERAPOS_SECOND, TRUE);

	SetSingleSnapCapture(FALSE);
#endif
	m_bAlarmFlag = TRUE;

	return TRUE;
}

void CCaptureManager::DeinitLibrary()
{
	::DeleteCriticalSection(&m_CriticalSection);

	for (int i = 0; i<TYPE_NETWORK_MAX; i++)
	{
		::DeinitCamera(m_pCamera[i]);
		m_pCamera[i] = NULL;
	}

	for (int i = 0; i < MAX_CAMERA_INTERFACE; i++)
	{
		if (m_pCameraProcess[i])
		{
			delete m_pCameraProcess[i];
			m_pCameraProcess[i] = NULL;
		}

		if (m_pCaptureProc[i].m_pstDevice)
			delete m_pCaptureProc[i].m_pstDevice;
		memset(&m_pCaptureProc[i], 0x00, sizeof(INFO_CAPTUREPROC));
	}

	for (int i = 0; i < TYPE_CAMERAPOS_MAX; i++)
	{
		m_pCapturePosition[i] = NULL;
	}
	
	memset(&m_stCaptureVideo, 0x00, sizeof(INFO_CAPTUREVIDEO));

	DeleteCommunicatePort();
}


#ifdef USE_BASLER_CAMERA
int CCaptureManager::CreateCaptureConnection()
{

	// Research Camera
	const int nBasler = ResearchCaptureConnection(TYPE_NETWORK_BASLER);
	CUtil::PumpMessage();

	int nTotal = 0;
	if (0 <= nBasler)		nTotal += nBasler;

	// Update Capture Position....
	for (int i = 0; i < MAX_CAMERA_INTERFACE; i++)
	{
		if (m_pCaptureProc[i].m_pstDevice)
			delete m_pCaptureProc[i].m_pstDevice;
		memset(&m_pCaptureProc[i], 0x00, sizeof(INFO_CAPTUREPROC));
		CUtil::PumpMessage();
	}

	for (int i = 0; i < TYPE_CAMERAPOS_MAX; i++)
	{
		m_pCapturePosition[i] = NULL;
	}


	// GigE: Left, Right
	{
		INFO_CONNECT_OTHER_MANUFACTURER stBasler;
		memset(&stBasler, 0x00, sizeof(INFO_CONNECT_OTHER_MANUFACTURER));
		stBasler.m_stArg.m_eNetwork = TYPE_NETWORK_BASLER;

		for (int i = 0; i < nBasler; i++)
		{
			if (GetConnectedDeviceInfo(TYPE_NETWORK_BASLER, i, (INFO_CONNECT_DEV*)&stBasler))
			{
				DWORD dwProcID = GetEnableProcessId();

				INFO_VIDEOARG* pInfoArg = new INFO_VIDEOARG;
				pInfoArg->m_dwProcID = dwProcID;
				pInfoArg->m_pArgument = m_stCaptureVideo.m_pArqument;

				m_stCaptureVideo.m_VideoDev.m_pArgument = pInfoArg;

				TYPE_CAMERAPOS ePos = TYPE_CAMERAPOS_NONE;
				if (NULL == m_pCapturePosition[TYPE_CAMERAPOS_FIRST])	ePos = TYPE_CAMERAPOS_FIRST;
				else if (NULL == m_pCapturePosition[TYPE_CAMERAPOS_SECOND])	ePos = TYPE_CAMERAPOS_SECOND;
				else
					continue;

				BOOL bResult = CreateCameraProcess(TYPE_NETWORK_BASLER, dwProcID, i, m_stCaptureVideo.m_hWnd, &m_stCaptureVideo.m_VideoDev);
				if (bResult)
				{
					INFO_CAPTUREPROC* pstInfo = &m_pCaptureProc[dwProcID];

					INFO_CONNECT_OTHER_MANUFACTURER* pBasler = new INFO_CONNECT_OTHER_MANUFACTURER;
					memcpy(pBasler, &stBasler, sizeof(INFO_CONNECT_OTHER_MANUFACTURER));

					pstInfo->m_dwProcID = dwProcID;
					pstInfo->m_eNetwork = pBasler->m_stArg.m_eNetwork;
					pstInfo->m_nCamID = i;
					pstInfo->m_pstDevice = (INFO_CONNECT_DEV*)pBasler;

					m_pCapturePosition[ePos] = pstInfo;
				}
				else
				{
					delete m_stCaptureVideo.m_VideoDev.m_pArgument;
				}
			}
			CUtil::PumpMessage();
		}
		m_stCaptureVideo.m_VideoDev.m_pArgument = NULL;
		CUtil::PumpMessage();
	}

	return nTotal;
}

#endif

#ifdef USE_GIGE_CAMERA
// Capture Connection
int CCaptureManager::CreateCaptureConnection()
{
	// Research Camera
	const int nGigE = ResearchCaptureConnection(TYPE_NETWORK_GIGE);
	CUtil::PumpMessage();

	int nTotal = 0;
	if (0 <= nGigE)		nTotal += nGigE;

	// Update Capture Position....
	for (int i = 0; i < MAX_CAMERA_INTERFACE; i++)
	{
		if (m_pCaptureProc[i].m_pstDevice)
			delete m_pCaptureProc[i].m_pstDevice;
		memset(&m_pCaptureProc[i], 0x00, sizeof(INFO_CAPTUREPROC));
		CUtil::PumpMessage();
	}

	for (int i = 0; i < TYPE_CAMERAPOS_MAX; i++)
	{
		m_pCapturePosition[i] = NULL;
	}


	// GigE: Left, Right
	{
		INFO_CONNECT_GIGE stGigE;
		memset(&stGigE, 0x00, sizeof(INFO_CONNECT_GIGE));
		stGigE.m_stArg.m_eNetwork = TYPE_NETWORK_GIGE;

		for (int i = 0; i < nGigE; i++)
		{
			if (GetConnectedDeviceInfo(TYPE_NETWORK_GIGE, i, (INFO_CONNECT_DEV*)&stGigE))
			{
				DWORD dwProcID = GetEnableProcessId();

				INFO_VIDEOARG* pInfoArg = new INFO_VIDEOARG;
				pInfoArg->m_dwProcID = dwProcID;
				pInfoArg->m_pArgument = m_stCaptureVideo.m_pArqument;

				m_stCaptureVideo.m_VideoDev.m_pArgument = pInfoArg;

				TYPE_CAMERAPOS ePos = TYPE_CAMERAPOS_NONE;
				if (NULL == m_pCapturePosition[TYPE_CAMERAPOS_FIRST])	ePos = TYPE_CAMERAPOS_FIRST;
				else if (NULL == m_pCapturePosition[TYPE_CAMERAPOS_SECOND])	ePos = TYPE_CAMERAPOS_SECOND;
				else
					continue;

				BOOL bResult = CreateCameraProcess(TYPE_NETWORK_GIGE, dwProcID, i, m_stCaptureVideo.m_hWnd, &m_stCaptureVideo.m_VideoDev);
				if (bResult)
				{
					INFO_CAPTUREPROC* pstInfo = &m_pCaptureProc[dwProcID];

					INFO_CONNECT_GIGE* pGigE = new INFO_CONNECT_GIGE;
					memcpy(pGigE, &stGigE, sizeof(INFO_CONNECT_GIGE));

					pstInfo->m_dwProcID = dwProcID;
					pstInfo->m_eNetwork = pGigE->m_stArg.m_eNetwork;
					pstInfo->m_nCamID = i;
					pstInfo->m_pstDevice = (INFO_CONNECT_DEV*)pGigE;

					m_pCapturePosition[ePos] = pstInfo;
				}
				else
				{
					delete m_stCaptureVideo.m_VideoDev.m_pArgument;
				}
			}
			CUtil::PumpMessage();
		}
		m_stCaptureVideo.m_VideoDev.m_pArgument = NULL;
		CUtil::PumpMessage();
	}

	return nTotal;
}
#endif

void CCaptureManager::CloseCaptureConnection()
{
	INFO_CAPTUREPROC* pInfo = NULL;

	for (int i = 0; i < MAX_CAMERA_INTERFACE; i++)
	{
		pInfo = &m_pCaptureProc[i];

#ifdef USE_BASLER_CAMERA
		if (TYPE_NETWORK_BASLER == pInfo->m_eNetwork)
#endif

#ifdef USE_GIGE_CAMERA
		if (TYPE_NETWORK_GIGE == pInfo->m_eNetwork)
#endif

		{
			DestoryCameraProcess(pInfo->m_eNetwork, pInfo->m_dwProcID, pInfo->m_nCamID);
		}
		else
		{
			DestoryCameraProcess(pInfo->m_eNetwork, pInfo->m_dwProcID, pInfo->m_nCamID);
		}
	}
	

	// Close Camera Interface
#ifdef USE_BASLER_CAMERA
	BOOL bEnable = IsEnableConnection(TYPE_NETWORK_BASLER);
	if (bEnable)
		DestoryConnection(TYPE_NETWORK_BASLER);
#endif

#ifdef USE_GIGE_CAMERA
	BOOL bEnable = IsEnableConnection(TYPE_NETWORK_GIGE);
	if (bEnable)
		DestoryConnection(TYPE_NETWORK_GIGE);
#endif

}

int CCaptureManager::ResearchCaptureConnection(TYPE_NETWORK eNetwork)
{
	int nCount = -1;

	BOOL bEnable = IsEnableConnection(eNetwork);
	if (bEnable)
		DestoryConnection(eNetwork);

	BOOL bResult = CreateConnection(eNetwork);
	if (bResult)
	{
		ResearchConnectedDevice(eNetwork);
		nCount = GetConnectedDeviceCount(eNetwork);
	}
	return nCount;
}

BOOL CCaptureManager::StartCaptureConnection()
{
	// GigE
	const INFO_CAPTUREPROC* pstLeft = GetCapturePosition(TYPE_CAMERAPOS_FIRST);
	if (pstLeft)
	{
#ifdef USE_BASLER_CAMERA

		this->Start(TYPE_NETWORK_BASLER, pstLeft->m_dwProcID);
#endif

#ifdef USE_GIGE_CAMERA
		this->Start(TYPE_NETWORK_GIGE, pstLeft->m_dwProcID);
#endif
		CUtil::PumpMessage();
	}
	const INFO_CAPTUREPROC* pstRight = GetCapturePosition(TYPE_CAMERAPOS_SECOND);
	if (pstRight)
	{
#ifdef USE_BASLER_CAMERA

		this->Start(TYPE_NETWORK_BASLER, pstRight->m_dwProcID);
#endif

#ifdef USE_GIGE_CAMERA
		this->Start(TYPE_NETWORK_GIGE, pstRight->m_dwProcID);
#endif

		CUtil::PumpMessage();
	}

	return TRUE;
}

void CCaptureManager::StopCaptureConnection()
{
	// GigE
	const INFO_CAPTUREPROC* pstLeft = GetCapturePosition(TYPE_CAMERAPOS_FIRST);
	if (pstLeft)
	{
#ifdef USE_BASLER_CAMERA
		this->Stop(TYPE_NETWORK_BASLER, pstLeft->m_dwProcID);
#endif

#ifdef USE_GIGE_CAMERA
		this->Stop(TYPE_NETWORK_GIGE, pstLeft->m_dwProcID);
#endif
		CUtil::WaitnSleep(100);
	}
	const INFO_CAPTUREPROC* pstRight = GetCapturePosition(TYPE_CAMERAPOS_SECOND);
	if (pstRight)
	{
#ifdef USE_BASLER_CAMERA
		this->Stop(TYPE_NETWORK_BASLER, pstRight->m_dwProcID);
#endif

#ifdef USE_GIGE_CAMERA
		this->Stop(TYPE_NETWORK_GIGE, pstRight->m_dwProcID);
#endif
		CUtil::WaitnSleep(100);
	}
}

void CCaptureManager::StopAllCamera()
{
	for (int i = 0; i < MAX_CAMERA_INTERFACE; i++)
	{
		CProcCaptureCamera* pCameraProc = m_pCameraProcess[i];
		if (pCameraProc)
		{
			pCameraProc->Stop();

			const TYPE_NETWORK eNetwork = pCameraProc->GetCameraNetwork();
#ifdef USE_BASLER_CAMERA
			if (TYPE_NETWORK_BASLER == eNetwork)
#endif

#ifdef USE_GIGE_CAMERA
			if (TYPE_NETWORK_GIGE == eNetwork)
#endif
				CUtil::WaitnSleep(500);
			else
				CUtil::WaitnSleep(100);
		}
	}
}



const INFO_CAPTUREPROC* CCaptureManager::GetCapturePosition(TYPE_CAMERAPOS eType)
{
	if (TYPE_CAMERAPOS_NONE == eType || TYPE_CAMERAPOS_MAX == eType)
		return NULL;

	return m_pCapturePosition[eType];
}

BOOL CCaptureManager::SetCapturePosition(TYPE_CAMERAPOS eType, TYPE_NETWORK eNetwork, int nCamId)
{
	if (TYPE_CAMERAPOS_NONE == eType || TYPE_CAMERAPOS_MAX == eType)
		return FALSE;

	if (TYPE_NETWORK_NONE == eNetwork)
	{
		m_pCapturePosition[eType] = NULL;
	}
	else
	{
		int nIdx = -1;

		for (int i = 0; i < TYPE_CAMERAPOS_MAX; i++)
		{
			if (eNetwork == m_pCaptureProc[i].m_eNetwork && nCamId == m_pCaptureProc[i].m_nCamID)
			{
				nIdx = i;
				break;
			}
		}
		if (0 > nIdx)
			return FALSE;

		//if (nIdx != eType)
		{
			INFO_CAPTUREPROC* pstInfo = &m_pCaptureProc[nIdx];

			if (pstInfo)
			{
				Stop(pstInfo->m_eNetwork, pstInfo->m_dwProcID);
				CUtil::WaitnSleep(500);
			}

			for (int i = 0; i < TYPE_CAMERAPOS_MAX; i++)
			{
				if (m_pCapturePosition[i] && pstInfo == m_pCapturePosition[i])
				{
					m_pCapturePosition[i] = NULL;
					break;
				}
			}
			m_pCapturePosition[eType] = pstInfo;

			if (pstInfo && FALSE == IsStartCamera(pstInfo->m_dwProcID))
			{
				Start(pstInfo->m_eNetwork, pstInfo->m_dwProcID);
			}
		}
	}
	return TRUE;
}

TYPE_CAMERAPOS CCaptureManager::GetCapturePosByProc(const DWORD dwProcID)
{
	// GigE
	const INFO_CAPTUREPROC* pstLeft = GetCapturePosition(TYPE_CAMERAPOS_FIRST);
	if (pstLeft && dwProcID == pstLeft->m_dwProcID)
	{
		return TYPE_CAMERAPOS_FIRST;
	}
	const INFO_CAPTUREPROC* pstRight = GetCapturePosition(TYPE_CAMERAPOS_SECOND);
	if (pstRight && dwProcID == pstRight->m_dwProcID)
	{
		return TYPE_CAMERAPOS_SECOND;
	}

	return TYPE_CAMERAPOS_NONE;
}


void CCaptureManager::UpdateCaptureVideo(INFO_CAPTUREVIDEO stVideo)
{
	m_stCaptureVideo = stVideo;
}


// Connect
BOOL CCaptureManager::IsEnableConnection(TYPE_NETWORK eNetwork)
{
	BOOL bConnect = FALSE;

	if (m_pCamera[eNetwork])
		bConnect = TRUE;

	return bConnect;
}

BOOL CCaptureManager::CreateConnection(TYPE_NETWORK eNetwork)
{
	DestoryConnection(eNetwork);

	m_pCamera[eNetwork] = ::InitCamera(eNetwork);
	if (NULL == m_pCamera[eNetwork])
	{
		DestoryConnection(eNetwork);
		return FALSE;
	}

	return TRUE;
}

void CCaptureManager::DestoryConnection(TYPE_NETWORK eNetwork)
{
	if (m_pCamera[eNetwork])
	{
		::DeinitCamera(m_pCamera[eNetwork]);
		m_pCamera[eNetwork] = NULL;
	}
}

int	CCaptureManager::GetConnectedDeviceCount(const TYPE_NETWORK eNetwork)
{
	if (FALSE == ::IsConnected(m_pCamera[eNetwork]))
		return 0;

	const int nCount = ::GetDeviceCount(m_pCamera[eNetwork]);
	return nCount;
}

int	CCaptureManager::GetConnectedDeviceID(const TYPE_NETWORK eNetwork, const TCHAR* pszName)
{
	if (FALSE == ::IsConnected(m_pCamera[eNetwork]))
		return -1;

	const int nCamID = ::GetDeviceID(m_pCamera[eNetwork], pszName);
	return nCamID;
}

BOOL CCaptureManager::GetConnectedDeviceInfo(const TYPE_NETWORK eNetwork, int nCameraId, INFO_CONNECT_DEV* pstDevice)
{
	BOOL bResult = ::GetDeviceInfo(m_pCamera[eNetwork], nCameraId, pstDevice);
	return bResult;
}

BOOL CCaptureManager::FindConnectedDevice(const TYPE_NETWORK eNetwork, INFO_CONNECT_DEV* pstDevice)
{
	const int nIdx = ::GetDeviceIndex(m_pCamera[eNetwork], pstDevice);
	if (-1 == nIdx)
		return FALSE;

	return TRUE;
}

BOOL CCaptureManager::ResearchConnectedDevice(const TYPE_NETWORK eNetwork)
{
	BOOL bResult = ::ResearchDeviceInfo(m_pCamera[eNetwork] );
	return bResult;
}

//Device Default Information
BOOL CCaptureManager::GetCurrentDeviceInfo(TYPE_NETWORK eNetwork, const TCHAR* pszName, INFO_DEFDEV* pstDefDev, BOOL bReload)
{
	const INFO_DEFDEV* pDev = m_CameraDevice.GetDefaultDevice(eNetwork, pszName);
	if (NULL == pstDefDev || NULL == pDev)
		return FALSE;

	BOOL bResult = TRUE;
	/*//
	if (TYPE_NETWORK_CAMERALINK == eNetwork)
	{
		const int nCamID = GetConnectedDeviceID(eNetwork, pstDefDev->m_szName);
		memcpy(pstDefDev, pDev, sizeof(INFO_DEFDEV));

		bResult = ::GetConnectedDeviceInfo(m_pCamera[eNetwork], nCamID, pstDefDev, bReload);
	}
	else
	//*/
	{
		memcpy(pstDefDev, pDev, sizeof(INFO_DEFDEV));
	}

	return bResult;
}


// Device Information
BOOL CCaptureManager::GetImageFrameInfo(const int nProcessId, INFO_FRAME* pstFrame)
{
	BOOL bResult = FALSE;
	if (m_pCameraProcess[nProcessId])
	{
		const INFO_FRAME* pFrame = m_pCameraProcess[nProcessId]->GetFrameInfo();
		if (pstFrame && pFrame)
		{
			memcpy(pstFrame, pFrame, sizeof(INFO_FRAME));
			bResult = TRUE;
		}

	}
	return bResult;
}

void CCaptureManager::UpdateImageFrameInfo(const int nProcessId)
{
	if (m_pCameraProcess[nProcessId])
	{
		m_pCameraProcess[nProcessId]->UpdateFrameInfo();
	}
}


BOOL CCaptureManager::CreateCameraProcess(const TYPE_NETWORK eNetwork, const int nProcessId, const int nCamId, HWND hWnd, INFO_VIDEODEV_ARG* pVideoArg)
{
	if (0 > nProcessId)
		return FALSE;

	if (m_pCameraProcess[nProcessId])
	{
		delete m_pCameraProcess[nProcessId];
		m_pCameraProcess[nProcessId] = NULL;
	}

	m_pCameraProcess[nProcessId] = new CProcCaptureCamera;

	BOOL bResult = m_pCameraProcess[nProcessId]->CreateCameraProcess(m_pCamera[eNetwork], nCamId, hWnd, pVideoArg);
	if (bResult)
	{ 
		const INFO_DEFDEV_USERCONFIG* pstUser = m_CameraDevice.GetUserConfig();

#ifdef TRIGGER_TIMEOUT
		m_pCameraProcess[nProcessId]->SetEnableTriggerTimeOut(pstUser->m_stTimeOut.m_bEnable);
		m_pCameraProcess[nProcessId]->SetTimeTriggerTimeOut(pstUser->m_stTimeOut.m_nCurTimeOut);
#endif

#ifdef USE_BASLER_CAMERA
		if (TYPE_NETWORK_BASLER == eNetwork)
#endif
#ifdef USE_GIGE_CAMERA
		if (TYPE_NETWORK_GIGE == eNetwork)
#endif
		{
			if (pstUser->m_stUserGigE.m_stMtu.m_bSupport && pstUser->m_stUserGigE.m_stMtu.m_bEnable)
			{
				m_pCameraProcess[nProcessId]->Stop();
				CUtil::WaitnSleep(500);
				m_pCameraProcess[nProcessId]->SetMTU(pstUser->m_stUserGigE.m_stMtu.m_dwMtu);
				m_pCameraProcess[nProcessId]->Start();
			}
		}
	}
	else
	{
		DestoryCameraProcess(eNetwork, nProcessId, nCamId);
	}

	return bResult;
}

void CCaptureManager::DestoryCameraProcess(const TYPE_NETWORK eNetwork, const int nProcessId, const int nCamId)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return;
	}

	m_pCameraProcess[nProcessId]->Stop();

#ifdef USE_BASLER_CAMERA
	if (TYPE_NETWORK_BASLER == eNetwork)
#endif
#ifdef USE_GIGE_CAMERA
	if (TYPE_NETWORK_GIGE == eNetwork)
#endif
		CUtil::WaitnSleep(500);
	else
		CUtil::WaitnSleep(100);

	if(TYPE_NETWORK_CAMERALINK == eNetwork)
		m_pCameraProcess[nProcessId]->Close();
	m_pCameraProcess[nProcessId]->DestoryCameraProcess();
	
	delete m_pCameraProcess[nProcessId];
	m_pCameraProcess[nProcessId] = NULL;

}

BOOL CCaptureManager::Start(const TYPE_NETWORK eNetwork, const int nProcessId, BOOL bSingleFrame)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bStart = IsStartCamera(nProcessId);		// Camera Stop...
	if (bStart)
		return TRUE;

	BOOL bResult = m_pCameraProcess[nProcessId]->Start(bSingleFrame);
	return bResult;
}


void CCaptureManager::Stop(const TYPE_NETWORK eNetwork, const int nProcessId)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return;
	}

	m_pCameraProcess[nProcessId]->Stop();
}

const int CCaptureManager::GetEnableProcessId()
{
	int nProcessId = -1;

	for (int i = 0; i<MAX_CAMERA_INTERFACE; i++)
	{
		if (NULL == m_pCameraProcess[i] ||
			TYPE_STATE_PROCESS_NONE == m_pCameraProcess[i]->GetProcessState())
		{
			nProcessId = i;
			break;
		}
	}

	return nProcessId;
}

const int CCaptureManager::GetWorkingProcessCount()
{
	int nCount = 0;
	for (int i = 0; i<MAX_CAMERA_INTERFACE; i++)
	{
		CProcCaptureCamera* pCameraProc = m_pCameraProcess[i];
		if (pCameraProc && TYPE_STATE_PROCESS_NONE != pCameraProc->GetProcessState())
		{
			nCount++;
		}
	}
	return nCount;
}

const int CCaptureManager::GetProcessId(const INFO_CONNECT_DEV* pstDevice)
{
	int nProcessId = -1;
	if (NULL == pstDevice)
		return nProcessId;

	for (int i = 0; i<MAX_CAMERA_INTERFACE; i++)
	{
		CProcCaptureCamera* pCameraProc = m_pCameraProcess[i];

		if (pCameraProc && pCameraProc->CheckConnectInfo(pstDevice))
		{
			nProcessId = i;
			break;
		}
	}

	return nProcessId;
}

const int CCaptureManager::GetCameraId(const INFO_CONNECT_DEV* pstDevice)
{
	int nCamId = -1;
	if (NULL == pstDevice || NULL == m_pCamera[pstDevice->m_eNetwork])
		return nCamId;

	nCamId = ::GetDeviceIndex(m_pCamera[pstDevice->m_eNetwork], pstDevice);
	return nCamId;

}

const int CCaptureManager::GetCameraId(const int nProcessId)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return -1;
	}

	return m_pCameraProcess[nProcessId]->GetCameraId();

}

BOOL CCaptureManager::IsWorkingCamera(const int nProcessId)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	const TYPE_STATE_PROCESS eState = m_pCameraProcess[nProcessId]->GetProcessState();
	if (TYPE_STATE_PROCESS_START == eState || TYPE_STATE_PROCESS_STOP == eState)
		return TRUE;

	return FALSE;
}

BOOL CCaptureManager::IsStartCamera(const int nProcessId)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	const TYPE_STATE_PROCESS eState = m_pCameraProcess[nProcessId]->GetProcessState();
	if (TYPE_STATE_PROCESS_START == eState )
		return TRUE;

	return FALSE;
}


//
BOOL CCaptureManager::SetGain(const TYPE_NETWORK eNetwork, const int nProcessId, const int nGainType, const int nGainVal)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->SetGain(nGainType, nGainVal);
	return bResult;
}
BOOL CCaptureManager::GetGain(const TYPE_NETWORK eNetwork, const int nProcessId, const int nGainType, int* pnGainVal)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->GetGain(nGainType, pnGainVal);
	return bResult;
}

BOOL CCaptureManager::SetEnableFrameRate(const TYPE_NETWORK eNetwork, const int nProcessId, const BOOL bEnable)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}
	BOOL bResult = m_pCameraProcess[nProcessId]->SetEnableFrameRate(bEnable);
	return bResult;
}

BOOL CCaptureManager::GetEnableFrameRate(const TYPE_NETWORK eNetwork, const int nProcessId, BOOL* pbEnable)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}
	BOOL bResult = m_pCameraProcess[nProcessId]->GetEnableFrameRate(pbEnable);
	return bResult;

}

BOOL CCaptureManager::SetFrameRate(const TYPE_NETWORK eNetwork, const int nProcessId, const unsigned int nFrameRate)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->SetFrameRate(nFrameRate);
	return bResult;
}
BOOL CCaptureManager::GetFrameRate(const TYPE_NETWORK eNetwork, const int nProcessId, unsigned int* pnFrameRate)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->GetFrameRate(pnFrameRate);
	return bResult;
}

BOOL CCaptureManager::SetExposureTime(const TYPE_NETWORK eNetwork, const int nProcessId, const unsigned int nExposureTime)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->SetExposureTime(nExposureTime);
	return bResult;
}
BOOL CCaptureManager::GetExposureTime(const TYPE_NETWORK eNetwork, const int nProcessId, unsigned int* pnExposureTime)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->GetExposureTime(pnExposureTime);
	return bResult;
}

BOOL CCaptureManager::GetExposureMaxTime(const TYPE_NETWORK eNetwork, const int nProcessId, unsigned int nFrameRate, unsigned int* pnExposureTime)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->GetExposureMaxTime(nFrameRate, pnExposureTime);
	return bResult;
}

BOOL CCaptureManager::ConvertExposureTime(const TYPE_NETWORK eNetwork, const int nProcessId, unsigned int nStep, double* pfUSec)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->ConvertExposureTime(nStep, pfUSec);
	return bResult;
}

BOOL CCaptureManager::SetTriggerMode(const TYPE_NETWORK eNetwork, const int nProcessId, INFO_TRIGGER_PARA stTrigger)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->SetTriggerMode(stTrigger);
	return bResult;
}
BOOL CCaptureManager::GetTriggerMode(const TYPE_NETWORK eNetwork, const int nProcessId, INFO_TRIGGER_PARA* pstTrigger)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->GetTriggerMode(pstTrigger);
	return bResult;
}

BOOL CCaptureManager::SetTriggerDelay(const TYPE_NETWORK eNetwork, const int nProcessId, int nDelay)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}
	
	BOOL bResult = m_pCameraProcess[nProcessId]->SetTriggerDelay(nDelay);
	return bResult;
}

BOOL CCaptureManager::SaveUserset(const TYPE_NETWORK eNetwork, const int nProcessId, const int nNumber)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->SaveUserset(nNumber);
	return bResult;
}
BOOL CCaptureManager::LoadUserset(const TYPE_NETWORK eNetwork, const int nProcessId, const int nNumber)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->LoadUserset(nNumber);
	return bResult;
}

BOOL CCaptureManager::SetStrobeMode(const TYPE_NETWORK eNetwork, const int nProcessId, INFO_STROBE_PARA stStrobe)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->SetStrobeMode(stStrobe);
	return bResult;
}
BOOL CCaptureManager::GetStrobeMode(const TYPE_NETWORK eNetwork, const int nProcessId, INFO_STROBE_PARA* pstStrobe)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->GetStrobeMode(pstStrobe);
	return bResult;
}

BOOL CCaptureManager::SetFlipMode(const TYPE_NETWORK eNetwork, const int nProcessId, unsigned short nMode)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->SetFlipMode(nMode);
	return bResult;
}
BOOL CCaptureManager::GetFlipMode(const TYPE_NETWORK eNetwork, const int nProcessId, unsigned short* pnMode)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->GetFlipMode(pnMode);
	return bResult;
}

BOOL CCaptureManager::SetROI(const TYPE_NETWORK eNetwork, const int nProcessId, INFO_ROI_PARA stROI)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->SetROI(stROI);
	return bResult;
}
BOOL CCaptureManager::GetROI(const TYPE_NETWORK eNetwork, const int nProcessId, INFO_ROI_PARA* pstROI)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->GetROI(pstROI);
	return bResult;
}

BOOL CCaptureManager::SetUsersetStartNo(const TYPE_NETWORK eNetwork, const int nProcessId, unsigned char nUsersetStartNo)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->SetUsersetStartNo(nUsersetStartNo);
	return bResult;
}
BOOL CCaptureManager::GetUsersetStartNo(const TYPE_NETWORK eNetwork, const int nProcessId, unsigned char* pnUsersetStartNo)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->GetUsersetStartNo(pnUsersetStartNo);
	return bResult;
}

BOOL CCaptureManager::SetDataBit(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short nDataBit)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->SetDataBit(nDataBit);
	return bResult;
}

BOOL CCaptureManager::GetDataBit(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short* pnDataBit)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->GetDataBit(pnDataBit);
	return bResult;
}

BOOL CCaptureManager::SetColorMode(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short nColorMode)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->SetColorMode(nColorMode);
	return bResult;
}
BOOL CCaptureManager::GetColorMode(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short* pnColorMode)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->GetColorMode(pnColorMode);
	return bResult;
}

BOOL CCaptureManager::SetMTU(TYPE_NETWORK eNetwork, const int nProcessId, unsigned int nMTU)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->SetMTU(nMTU);
	return bResult;
}

BOOL CCaptureManager::GetMTU(TYPE_NETWORK eNetwork, const int nProcessId, unsigned int* pnMTU)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->GetMTU(pnMTU);
	return bResult;
}


BOOL CCaptureManager::GetDiag(const TYPE_NETWORK eNetwork, const int nProcessId, void* pstDiag, int nLen)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->GetDiag(pstDiag, nLen);
	return bResult;
}

BOOL CCaptureManager::SetSWTrigger(const TYPE_NETWORK eNetwork, const int nProcessId)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->SetSWTrigger();
	return bResult;
}



// Effect
BOOL CCaptureManager::SetEffectNR(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short nEffect)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->SetEffectNR(nEffect);
	return bResult;
}
BOOL CCaptureManager::GetEffectNR(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short* pnEffect)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->GetEffectNR(pnEffect);
	return bResult;
}

BOOL CCaptureManager::SetEffectGC(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short nEffect)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->SetEffectGC(nEffect);
	return bResult;
}
BOOL CCaptureManager::GetEffectGC(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short* pnEffect)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->GetEffectGC(pnEffect);
	return bResult;
}

BOOL CCaptureManager::SetEffectCM(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short nEffect)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->SetEffectCM(nEffect);
	return bResult;
}
BOOL CCaptureManager::GetEffectCM(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short* pnEffect)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->GetEffectCM(pnEffect);
	return bResult;
}

BOOL CCaptureManager::SetEffectAWB(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short nEffect)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->SetEffectAWB(nEffect);
	return bResult;
}
BOOL CCaptureManager::GetEffectAWB(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short* pnEffect)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->GetEffectAWB(pnEffect);
	return bResult;
}

BOOL CCaptureManager::SetEffectSmooth(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short nEffect)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->SetEffectSmooth(nEffect);
	return bResult;
}
BOOL CCaptureManager::GetEffectSmooth(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short* pnEffect)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->GetEffectSmooth(pnEffect);
	return bResult;
}

BOOL CCaptureManager::SetEffectSharpen(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short nEffect)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->SetEffectSharpen(nEffect);
	return bResult;
}
BOOL CCaptureManager::GetEffectSharpen(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short* pnEffect)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->GetEffectSharpen(pnEffect);
	return bResult;
}

BOOL CCaptureManager::SetEffectFPN(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short nEffect)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->SetEffectFPN(nEffect);
	return bResult;
}
BOOL CCaptureManager::GetEffectFPN(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short* pnEffect)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->GetEffectFPN(pnEffect);
	return bResult;
}

BOOL CCaptureManager::SetEffectPRNU(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short nEffect)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->SetEffectPRNU(nEffect);
	return bResult;
}
BOOL CCaptureManager::GetEffectPRNU(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short* pnEffect)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->GetEffectPRNU(pnEffect);
	return bResult;
}

BOOL CCaptureManager::SetEffectDPC(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short nEffect)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->SetEffectDPC(nEffect);
	return bResult;
}
BOOL CCaptureManager::GetEffectDPC(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short* pnEffect)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->GetEffectDPC(pnEffect);
	return bResult;
}

BOOL CCaptureManager::SetColorGain(const TYPE_NETWORK eNetwork, const int nProcessId, const int nGainType, const int nGainVal)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->SetColorGain(nGainType, nGainVal);
	return bResult;
}
BOOL CCaptureManager::GetColorGain(const TYPE_NETWORK eNetwork, const int nProcessId, const int nGainType, int* pnGainVal)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->GetColorGain(nGainType, pnGainVal);
	return bResult;
}


// Command
BOOL CCaptureManager::ReadRegDword(const int nProcessId, const DWORD dwAddress, DWORD* pdwValue, DWORD dwReserved)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->ReadRegDword(dwAddress, pdwValue, dwReserved);
	return bResult;
}

BOOL CCaptureManager::WriteRegDword(const int nProcessId, const DWORD dwAddress, const DWORD dwValue, DWORD dwReserved)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = m_pCameraProcess[nProcessId]->WriteRegDword(dwAddress, dwValue, dwReserved);
	return bResult;
}

BOOL CCaptureManager::CalculateMaxFrameRate(const INFO_DEFDEV* pstDefDev, const int nProcessId, const int nWidth, const int nHeight, DWORD* pdwMaxFps)
{
	if (NULL == pdwMaxFps)
		return FALSE;
	
	BOOL bResult = FALSE;
	
	if (TYPE_NETWORK_USB == pstDefDev->m_eNetwork)
	{
		bResult = ::CalculateMaxFrameRate(pstDefDev, nWidth, nHeight, pdwMaxFps);
	}
	else if (TYPE_NETWORK_GIGE == pstDefDev->m_eNetwork || TYPE_NETWORK_CAMERALINK == pstDefDev->m_eNetwork || TYPE_NETWORK_BASLER == pstDefDev->m_eNetwork)
	{
		unsigned int nMaxFps = 0;
		if(m_pCameraProcess[nProcessId])
			bResult = m_pCameraProcess[nProcessId]->GetMaxFrameRate(&nMaxFps);

		if (bResult)
			*pdwMaxFps = nMaxFps;
	}
	
	return bResult;
}


#ifdef TRIGGER_TIMEOUT
BOOL CCaptureManager::IsSupportTriggerTimeOut()
{
	BOOL bSupport = FALSE;

	const INFO_DEFDEV_USERCONFIG* pstConfig = m_CameraDevice.GetUserConfig();
	if (pstConfig)
		bSupport = pstConfig->m_stTimeOut.m_bSupport;
	return bSupport;
}

void CCaptureManager::SetEnableTriggerTimeOut(BOOL bEnable)
{
	INFO_DEFDEV_USERCONFIG stUserConfig;
	memset(&stUserConfig, 0x00, sizeof(INFO_DEFDEV_USERCONFIG));

	const INFO_DEFDEV_USERCONFIG* pstConfig = m_CameraDevice.GetUserConfig();
	if (pstConfig)
	{
		memcpy(&stUserConfig, pstConfig, sizeof(INFO_DEFDEV_USERCONFIG));
		stUserConfig.m_stTimeOut.m_bEnable = bEnable;

		m_CameraDevice.UpdateUserConfig(&stUserConfig);

		//
		for (int i = 0; i < MAX_CAMERA_INTERFACE; i++)
		{
			SetEnableTriggerTimeOut(i, bEnable);
		}
	}
}

BOOL CCaptureManager::GetEnableTriggerTimeOut()
{
	BOOL bEnable = FALSE;
	const INFO_DEFDEV_USERCONFIG* pstConfig = m_CameraDevice.GetUserConfig();
	if (pstConfig)
		bEnable = pstConfig->m_stTimeOut.m_bEnable;

	return bEnable;
}

void CCaptureManager::SetTimeTriggerTimeOut(DWORD dwMsec)
{
	INFO_DEFDEV_USERCONFIG stUserConfig;
	memset(&stUserConfig, 0x00, sizeof(INFO_DEFDEV_USERCONFIG));

	const INFO_DEFDEV_USERCONFIG* pstConfig = m_CameraDevice.GetUserConfig();
	if (pstConfig)
	{
		memcpy(&stUserConfig, pstConfig, sizeof(INFO_DEFDEV_USERCONFIG));
		stUserConfig.m_stTimeOut.m_nCurTimeOut = dwMsec;

		m_CameraDevice.UpdateUserConfig(&stUserConfig);


		//
		for (int i = 0; i < MAX_CAMERA_INTERFACE; i++)
		{
			SetTimeTriggerTimeOut(i, dwMsec);
		}

	}
}

DWORD CCaptureManager::GetTimeTriggerTimeOut()
{
	DWORD dwTime = 1000;

	const INFO_DEFDEV_USERCONFIG* pstConfig = m_CameraDevice.GetUserConfig();
	if (pstConfig && pstConfig->m_stTimeOut.m_bSupport)
	{
		dwTime = pstConfig->m_stTimeOut.m_nCurTimeOut;
	}

	return dwTime;
}

BOOL CCaptureManager::GetRangeTriggerTimeOut(DWORD& dwFrom, DWORD& dwTo)
{
	const INFO_DEFDEV_USERCONFIG* pstConfig =  m_CameraDevice.GetUserConfig();
	if (pstConfig && pstConfig->m_stTimeOut.m_bSupport)
	{
		dwFrom = pstConfig->m_stTimeOut.m_stTimeOutRange.m_nFrom;
		dwTo = pstConfig->m_stTimeOut.m_stTimeOutRange.m_nTo;
	}
	else
	{
		return FALSE;
	}
	return TRUE;	
}

void CCaptureManager::SetEnableTriggerTimeOut(const int nProcessId, BOOL bEnable)
{
	if (m_pCameraProcess[nProcessId])
		m_pCameraProcess[nProcessId]->SetEnableTriggerTimeOut(bEnable);
}


BOOL CCaptureManager::GetEnableTriggerTimeOut(const int nProcessId)
{
	BOOL bEnable = FALSE;
	if (m_pCameraProcess[nProcessId])
		bEnable = m_pCameraProcess[nProcessId]->GetEnableTriggerTimeOut();

	return bEnable;
}

void CCaptureManager::SetTimeTriggerTimeOut(const int nProcessId, DWORD dwMsec)
{
	if (m_pCameraProcess[nProcessId])
		m_pCameraProcess[nProcessId]->SetTimeTriggerTimeOut(dwMsec);
}
DWORD CCaptureManager::GetTimeTriggerTimeOut(const int nProcessId)
{
	DWORD dwTime = 0;
	if (m_pCameraProcess[nProcessId])
		dwTime = m_pCameraProcess[nProcessId]->GetTimeTriggerTimeOut();

	return dwTime;
}

#endif


#if defined(ENABLE_CAMERA_LIBRARY_BASLER)
BOOL CCaptureManager::GetCameraInformation(const int nProcessId, INFO_OTHER_CATEGORY* pstRootCategory)
{
	if (0 > nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = FALSE;
	if (m_pCameraProcess[nProcessId])
		bResult = m_pCameraProcess[nProcessId]->GetCameraInformation(pstRootCategory);

	return bResult;
}

const INFO_OTHER_IF* CCaptureManager::GetCameraInformation(const int nProcessId, const TCHAR* szName)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return NULL;
	}

	INFO_OTHER_IF* pOther = NULL;
	if (m_pCameraProcess[nProcessId])
		pOther = (INFO_OTHER_IF*)m_pCameraProcess[nProcessId]->GetCameraInformation(szName);
	return pOther;
}

BOOL CCaptureManager::GetCameraValue(const int nProcessId, const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = FALSE;
	if (m_pCameraProcess[nProcessId])
		bResult = m_pCameraProcess[nProcessId]->GetCameraValue(pstInfo, pstValue);
	return bResult;
}

BOOL CCaptureManager::SetCameraValue(const int nProcessId, const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue)
{
	if (0>nProcessId || MAX_CAMERA_INTERFACE <= nProcessId || NULL == m_pCameraProcess[nProcessId])
	{
		return FALSE;
	}

	BOOL bResult = FALSE;
	if (m_pCameraProcess[nProcessId])
		bResult = m_pCameraProcess[nProcessId]->SetCameraValue(pstInfo, pstValue);
	return bResult;
}

BOOL CCaptureManager::IsActiveSoftwareTrigger(const int nProcessId, BOOL* pbTriggerOn, BOOL* pbTriggerSoftware)
{
	BOOL bActive = FALSE;

	const TCHAR* szMode = _T("TriggerMode");
	const INFO_OTHER_IF* pstMode = GetCameraInformation(nProcessId, szMode);
	if (pstMode)
	{
		BOOL bTriggerOn = FALSE;
		DWORD dwOn = 0;
		DWORD dwOff = 0;

		VALUE_OTHER_ENUM stValueEnum;
		memset(&stValueEnum, 0x00, sizeof(VALUE_OTHER_ENUM));
		stValueEnum.m_stInterfae.m_eInterface = TYPE_OTHER_INTERFACE_ENUM;

		// Get Trigger mode..
		BOOL bResult = GetCameraValue(nProcessId, pstMode, (VALUE_OTHER*)&stValueEnum);
		if (bResult && TYPE_OTHER_INTERFACE_ENUM == pstMode->m_eInterface)
		{
			const INFO_OTHER_ENUM* pEnumMode = (INFO_OTHER_ENUM*)pstMode;
			for (int i = 0; i < pEnumMode->m_nItemList; i++)
			{
				if (CUtil::StringICompare(_T("Off"), pEnumMode->m_pItemList[i].m_pszName))
				{
					dwOff = pEnumMode->m_pItemList[i].m_dwValue;
				}
				else if (CUtil::StringICompare(_T("On"), pEnumMode->m_pItemList[i].m_pszName))
				{
					dwOn = pEnumMode->m_pItemList[i].m_dwValue;
				}
			}

			if (dwOn == stValueEnum.m_dwValue)
				bTriggerOn = TRUE;
		}

		if (pbTriggerOn)
			*pbTriggerOn = bTriggerOn;

		if (bTriggerOn)
		{
			// Mode On
			memset(&stValueEnum, 0x00, sizeof(VALUE_OTHER_ENUM));
			stValueEnum.m_stInterfae.m_eInterface = TYPE_OTHER_INTERFACE_ENUM;
			stValueEnum.m_dwValue = dwOn;
			SetCameraValue(nProcessId, pstMode, (VALUE_OTHER*)&stValueEnum);

			// Select software trigger
			const TCHAR* szSource = _T("TriggerSource");
			const INFO_OTHER_IF* pstSource = GetCameraInformation(nProcessId, szSource);
			if (pstSource && TYPE_OTHER_INTERFACE_ENUM == pstSource->m_eInterface)
			{
				DWORD dwSource = 0;
				const INFO_OTHER_ENUM* pEnumSource = (INFO_OTHER_ENUM*)pstSource;
				for (int i = 0; i < pEnumSource->m_nItemList; i++)
				{
					if (CUtil::StringICompare(_T("Software"), pEnumSource->m_pItemList[i].m_pszName))
					{
						dwSource = pEnumSource->m_pItemList[i].m_dwValue;
					}
				}

				memset(&stValueEnum, 0x00, sizeof(VALUE_OTHER_ENUM));
				stValueEnum.m_stInterfae.m_eInterface = TYPE_OTHER_INTERFACE_ENUM;
				bResult = GetCameraValue(nProcessId, pstSource, (VALUE_OTHER*)&stValueEnum);
				if (bResult && dwSource == stValueEnum.m_dwValue)
				{
					bActive = TRUE;
					if (pbTriggerSoftware)
						*pbTriggerSoftware = bActive;
				}
			}
		}
	}
	return bActive;
}

BOOL CCaptureManager::SetSoftwareTriggerMode(const int nProcessId)
{
	BOOL bResult = FALSE;

	const TCHAR* szMode = _T("TriggerMode");
	const INFO_OTHER_IF* pstMode = GetCameraInformation(nProcessId, szMode);
	if (pstMode)
	{
		BOOL bTriggerOn = FALSE;
		DWORD dwOn = 0;
		DWORD dwOff = 0;

		VALUE_OTHER_ENUM stValueEnum;
		memset(&stValueEnum, 0x00, sizeof(VALUE_OTHER_ENUM));
		stValueEnum.m_stInterfae.m_eInterface = TYPE_OTHER_INTERFACE_ENUM;

		// Get Trigger mode..
		bResult = GetCameraValue(nProcessId, pstMode, (VALUE_OTHER*)&stValueEnum);
		if (bResult && TYPE_OTHER_INTERFACE_ENUM == pstMode->m_eInterface)
		{
			const INFO_OTHER_ENUM* pEnumMode = (INFO_OTHER_ENUM*)pstMode;
			for (int i = 0; i < pEnumMode->m_nItemList; i++)
			{
				if (CUtil::StringICompare(_T("Off"), pEnumMode->m_pItemList[i].m_pszName))
				{
					dwOff = pEnumMode->m_pItemList[i].m_dwValue;
				}
				else if (CUtil::StringICompare(_T("On"), pEnumMode->m_pItemList[i].m_pszName))
				{
					dwOn = pEnumMode->m_pItemList[i].m_dwValue;
				}
			}

			if (dwOn == stValueEnum.m_dwValue)
				bTriggerOn = TRUE;
		}

		if (FALSE == bTriggerOn)
		{
			// Mode On
			memset(&stValueEnum, 0x00, sizeof(VALUE_OTHER_ENUM));
			stValueEnum.m_stInterfae.m_eInterface = TYPE_OTHER_INTERFACE_ENUM;
			stValueEnum.m_dwValue = dwOn;
			SetCameraValue(nProcessId, pstMode, (VALUE_OTHER*)&stValueEnum);

			// Select software trigger
			const TCHAR* szSource = _T("TriggerSource");
			const INFO_OTHER_IF* pstSource = GetCameraInformation(nProcessId, szSource);
			if (pstSource && pstSource->m_eInterface)
			{
				DWORD dwSource = 0;
				const INFO_OTHER_ENUM* pEnumSource = (INFO_OTHER_ENUM*)pstSource;
				for (int i = 0; i < pEnumSource->m_nItemList; i++)
				{
					if (CUtil::StringICompare(_T("Software"), pEnumSource->m_pItemList[i].m_pszName))
					{
						dwSource = pEnumSource->m_pItemList[i].m_dwValue;
					}
				}

				memset(&stValueEnum, 0x00, sizeof(VALUE_OTHER_ENUM));
				stValueEnum.m_stInterfae.m_eInterface = TYPE_OTHER_INTERFACE_ENUM;
				stValueEnum.m_dwValue = dwSource;
				bResult = SetCameraValue(nProcessId, pstSource, (VALUE_OTHER*)&stValueEnum);
			}
		}

	}
	return bResult;
}

BOOL CCaptureManager::SetSoftwareTrigger(const int nProcessId)
{
	BOOL bResult = FALSE;

	// Set Software trigger
	const TCHAR* szSwTrigger = _T("TriggerSoftware");
	const INFO_OTHER_IF* pstSwTrigger = GetCameraInformation(nProcessId, szSwTrigger);
	if (pstSwTrigger)
	{
		VALUE_OTHER* pstTrigger = GetCameraOtherValue(pstSwTrigger, NULL);
		bResult = SetCameraValue(nProcessId, pstSwTrigger, pstTrigger);
		if (pstTrigger)
			delete pstTrigger;
		pstTrigger = NULL;
	}

	return bResult;
}


BOOL CCaptureManager::SetCameraPropertyReverseX(const int nProcessId, const BOOL bReverseX)
{
	BOOL bResult = FALSE;

	// Set ReverseX
	const TCHAR* szReverseX = _T("ReverseX");
	const INFO_OTHER_IF* pstReverseX = GetCameraInformation(nProcessId, szReverseX);
	if (pstReverseX && TYPE_OTHER_INTERFACE_BOOLEAN == pstReverseX->m_eInterface)
	{
		VALUE_OTHER_BOOLEAN stValueBoolean;
		memset(&stValueBoolean, 0x00, sizeof(VALUE_OTHER_BOOLEAN));
		stValueBoolean.m_stInterfae.m_eInterface = TYPE_OTHER_INTERFACE_BOOLEAN;
		stValueBoolean.m_bValue = bReverseX;

		bResult = SetCameraValue(nProcessId, pstReverseX, (VALUE_OTHER*)&stValueBoolean);

		/////UpdateImageFrameInfo(nProcessID);
	}

	return bResult;
}

BOOL CCaptureManager::SetCameraPropertyReverseY(const int nProcessId, const BOOL bReverseY)
{
	BOOL bResult = FALSE;

	// Set ReverseX
	const TCHAR* szReverseX = _T("ReverseY");
	const INFO_OTHER_IF* pstReverseX = GetCameraInformation(nProcessId, szReverseX);
	if (pstReverseX && TYPE_OTHER_INTERFACE_BOOLEAN == pstReverseX->m_eInterface)
	{
		VALUE_OTHER_BOOLEAN stValueBoolean;
		memset(&stValueBoolean, 0x00, sizeof(VALUE_OTHER_BOOLEAN));
		stValueBoolean.m_stInterfae.m_eInterface = TYPE_OTHER_INTERFACE_BOOLEAN;
		stValueBoolean.m_bValue = bReverseY;

		bResult = SetCameraValue(nProcessId, pstReverseX, (VALUE_OTHER*)&stValueBoolean);

		/////UpdateImageFrameInfo(nProcessID);
	}

	return bResult;
}

VALUE_OTHER* CCaptureManager::GetCameraOtherValue(const INFO_OTHER_IF* pstInfo, void* pValue)
{
	if (NULL == pstInfo)
		return NULL;

	VALUE_OTHER* pstValue = NULL;
	if (TYPE_OTHER_INTERFACE_INTEGER == pstInfo->m_eInterface && pValue)
	{
		VALUE_OTHER_INTEGER* pstInteger = new VALUE_OTHER_INTEGER;
		memset(pstInteger, 0x00, sizeof(VALUE_OTHER_INTEGER));

		pstInteger->m_stInterfae.m_eInterface = pstInfo->m_eInterface;
		pstInteger->m_nValue = *(int*)pValue;

		pstValue = (VALUE_OTHER*)pstInteger;

	}
	else if (TYPE_OTHER_INTERFACE_FLOAT == pstInfo->m_eInterface && pValue)
	{
		VALUE_OTHER_FLOAT* pstFloat = new VALUE_OTHER_FLOAT;
		memset(pstFloat, 0x00, sizeof(VALUE_OTHER_FLOAT));

		pstFloat->m_stInterfae.m_eInterface = pstInfo->m_eInterface;
		pstFloat->m_fValue = *(double*)pValue;

		pstValue = (VALUE_OTHER*)pstFloat;
	}
	else if (TYPE_OTHER_INTERFACE_STRING == pstInfo->m_eInterface)
	{
	}
	else if (TYPE_OTHER_INTERFACE_ENUM == pstInfo->m_eInterface && pValue)
	{
		const INFO_OTHER_ENUM* pstEnumInfo = (INFO_OTHER_ENUM*)pstInfo;

		TCHAR szValue[128] = { 0, };
		CUtil::StringCopy(szValue, (LPCTSTR)pValue);

		BOOL bFound = FALSE;
		DWORD dwValue = 0;
		for (int i = 0; i < pstEnumInfo->m_nItemList; i++)
		{
			if (!CUtil::StringCompare(pstEnumInfo->m_pItemList[i].m_pszName, (LPTSTR)(LPCTSTR)szValue))
				continue;

			bFound = TRUE;
			dwValue = pstEnumInfo->m_pItemList[i].m_dwValue;
			break;
		}
		if (!bFound)
			return NULL;

		VALUE_OTHER_ENUM* pstEnum = new VALUE_OTHER_ENUM;
		memset(pstEnum, 0x00, sizeof(VALUE_OTHER_ENUM));

		pstEnum->m_stInterfae.m_eInterface = pstInfo->m_eInterface;
		pstEnum->m_dwValue = dwValue;

		pstValue = (VALUE_OTHER*)pstEnum;
	}
	else if (TYPE_OTHER_INTERFACE_COMMAND == pstInfo->m_eInterface)
	{
		VALUE_OTHER* pstCmd = new VALUE_OTHER;
		memset(pstCmd, 0x00, sizeof(VALUE_OTHER));

		pstCmd->m_eInterface = pstInfo->m_eInterface;

		pstValue = (VALUE_OTHER*)pstCmd;
	}
	else if (TYPE_OTHER_INTERFACE_BOOLEAN == pstInfo->m_eInterface && pValue)
	{
		VALUE_OTHER_BOOLEAN* pstBool = new VALUE_OTHER_BOOLEAN;
		memset(pstBool, 0x00, sizeof(VALUE_OTHER_BOOLEAN));

		pstBool->m_stInterfae.m_eInterface = pstInfo->m_eInterface;
		pstBool->m_bValue = *(BOOL*)pValue;;

		pstValue = (VALUE_OTHER*)pstBool;
	}
	else if (TYPE_OTHER_INTERFACE_REGISTER == pstInfo->m_eInterface)
	{
	}
	else if (TYPE_OTHER_INTERFACE_CATEGORY == pstInfo->m_eInterface)
	{
	}

	return pstValue;
}


void CCaptureManager::ConvertColorBit10to8(const TYPE_NETWORK eNetwork, const INFO_IMAGE* pFrom, BYTE* pTo, int nToPitch)
{
	if (NULL == pFrom || NULL == pTo)
		return;

	const INFO_FRAME* pFrame = &pFrom->m_stFrame;
	ConvertColorBit10to8(eNetwork, pFrame->m_dwWidth, pFrame->m_dwHeight, (BYTE*)pFrom->m_pBuffer, pFrame->m_dwPitch, pTo, nToPitch);
}

void CCaptureManager::ConvertColorBit12to8(const TYPE_NETWORK eNetwork, const INFO_IMAGE* pFrom, BYTE* pTo, int nToPitch)
{
	if (NULL == pFrom || NULL == pTo)
		return;

	const INFO_FRAME* pFrame = &pFrom->m_stFrame;
	ConvertColorBit12to8(eNetwork, pFrame->m_dwWidth, pFrame->m_dwHeight, (BYTE*)pFrom->m_pBuffer, pFrame->m_dwPitch, pTo, nToPitch);
}


void CCaptureManager::ConvertColorBit10to8(const TYPE_NETWORK eNetwork, const int nW, const int nH, BYTE* pFrom, int nFromPitch, BYTE* pTo, int nToPitch)
{
	if (NULL == pFrom || NULL == pTo)
		return;

	BYTE* pDestBuf = pTo;
	BYTE* pSrcBUf = pFrom;

	int nSkip = 0;

	for (int y = 0; y < nH; y++)
	{
		nSkip = 0;
		for (int x = 0; x < nW; x++)
		{
			if (0 != x && 0 == x % 4)
				nSkip++;
			*(pDestBuf + x) = *(pSrcBUf + x + nSkip);
		}
		pDestBuf += nToPitch;
		pSrcBUf += nFromPitch;
	}
}

void CCaptureManager::ConvertColorBit12to8(const TYPE_NETWORK eNetwork, const int nW, const int nH, BYTE* pFrom, int nFromPitch, BYTE* pTo, int nToPitch)
{
	if (NULL == pFrom || NULL == pTo)
		return;

	BYTE* pDest = pTo;
	BYTE* pSrc = pFrom;

	int nSkip = 0;

	if (TYPE_NETWORK_USB == eNetwork)
	{
		for (int y = 0; y < nH; y++)
		{
			nSkip = 0;
			for (int x = 0; x < nW; x++)
			{
				if (0 != x && 0 == x % 2)
					nSkip++;
				*(pDest + x) = *(pSrc + x + nSkip);
			}
			pDest += nToPitch;
			pSrc += nFromPitch;
		}

	}
	else if (TYPE_NETWORK_GIGE == eNetwork)
	{
		for (int y = 0; y < nH; y++)
		{
			nSkip = 0;
			for (int x = 0; x < nW; x++)
			{
				*(pDest + x) = *(pSrc + x + nSkip);
				if (0 == x || 0 == x % 2)
					nSkip++;
			}
			pDest += nToPitch;
			pSrc += nFromPitch;
		}
	}
}

#endif

int CCaptureManager::GetBitCount(TYPE_DATABIT eBit)
{
	int  nBit = 8;

	if (TYPE_DATABIT_08 == eBit)		nBit = 8;
	else if (TYPE_DATABIT_12 == eBit)	nBit = 12;
	else if (TYPE_DATABIT_16 == eBit)	nBit = 16;
	else if (TYPE_DATABIT_24 == eBit)	nBit = 24;
	else if (TYPE_DATABIT_32 == eBit)	nBit = 32;
	else
		return -1;

	return nBit;
}

int CCaptureManager::GetBitCount(TYPE_VIDEOFORMAT eFormat)
{
	int  nBit = 8;

	if (TYPE_VIDEOFORMAT_RGB08 == eFormat)		nBit = 8;
	else if (TYPE_VIDEOFORMAT_RGB12 == eFormat)	nBit = 12;
	else if (TYPE_VIDEOFORMAT_RGB16 == eFormat)	nBit = 16;
	else if (TYPE_VIDEOFORMAT_RGB24 == eFormat)	nBit = 24;
	else if (TYPE_VIDEOFORMAT_RGB32 == eFormat)	nBit = 32;
	else
		return -1;

	return nBit;
}


#ifdef DEF_FREERUN_CAPTURE
BOOL CCaptureManager::IsReadySnapCapture()
{
	return m_bReadySnapCapture;
}

void CCaptureManager::SetReadySnapCapture(BOOL bReady)
{
	m_bReadySnapCapture = bReady;
}

BOOL CCaptureManager::IsReadySnapCapture(TYPE_CAMERAPOS eType)
{
	BOOL bReadySnap = FALSE;

	if (TYPE_CAMERAPOS_FIRST == eType)
		bReadySnap = m_bReadySnapCaptureFirst;
	else if (TYPE_CAMERAPOS_SECOND == eType)
		bReadySnap = m_bReadySnapCaptureSecond;

	return bReadySnap;
}

void CCaptureManager::SetReadySnapCapture(TYPE_CAMERAPOS eType, BOOL bReady)
{
	if (TYPE_CAMERAPOS_FIRST == eType)
		m_bReadySnapCaptureFirst = bReady;
	else if (TYPE_CAMERAPOS_SECOND == eType)
		m_bReadySnapCaptureSecond = bReady;

	{
		INFO_LOGFUNC stLogFunc = this->m_Log.GetLogInterface();
		// Print Log
		{
			if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg && FALSE == bReady)
			{
				if (TYPE_CAMERAPOS_FIRST == eType)
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Grab Command - First camera");					
				else if (TYPE_CAMERAPOS_SECOND == eType)
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Grab Command - Second camera");					
			}
		}
	}

}

BOOL CCaptureManager::IsSingleSnapCapture()
{
	return m_bSingeSnapCapture;
}

void CCaptureManager::SetSingleSnapCapture(BOOL bSingle)
{
	m_bSingeSnapCapture = bSingle;
}

#endif

CSerialCtrl* CCaptureManager::GetStrobeControlPort(TYPE_CAMERAPOS eType)
{
	if (TYPE_CAMERAPOS_FIRST == eType || TYPE_CAMERAPOS_SECOND == eType)
	{
		return &(m_pStrobeCtrl[TYPE_CAMERAPOS_FIRST]);
		//return &(m_pStrobeCtrl[eType]);
	}
	return NULL;
}

CEthernet* CCaptureManager::GetCommunicatePort()
{
	return m_pCommunicatePort;
}

CEthernet* CCaptureManager::CreateCommunicatePort(const TCHAR* pszType)
{
	if (NULL == pszType)
		return NULL;

	if (m_pCommunicatePort && m_pCommunicatePort->IsOpen())
		DeleteCommunicatePort();

	if (CUtil::StringICompare(_T("CLIENT"), (TCHAR*)pszType))
	{
		m_pCommunicatePort = new CEthernetClient;
	}
	else if (CUtil::StringICompare(_T("SERVER"), (TCHAR*)pszType))
	{
		m_pCommunicatePort = new CEthernetServer;
	}

	return m_pCommunicatePort;
}

void CCaptureManager::DeleteCommunicatePort()
{
	if (m_pCommunicatePort)
	{
		m_pCommunicatePort->Close();
		delete m_pCommunicatePort;
	}
	m_pCommunicatePort = NULL;
}

void CCaptureManager::SetCommunicateNotifyHandler(FuncNotifyEthernetListener pFunc, void* pArg)
{
	m_pFuncSerialListener = pFunc;
	m_pArgument = pArg;
}

// Version 1.3.6.5 (치수 영역 추가 없이 PLC 통신 데이터 추가 (X1-X2, L))
// Version 1.3.7.2 (M1, M2 add)
// Version1.3.7.4 (치수 영역 추가 없이 PLC 통신 데이터 추가 (S1-S3)) 
void CCaptureManager::CheckInspectionResult(TYPE_CAMERAPOS eCameraPos, CSampleSide* pSampleSide, BOOL& bResSize, BOOL& bResShape, float &fResDValue, float &fResSValue, float &fResLValue, float &fResX1X2Value, float& fResM1Value, float& fResM2Value, float& fResS1S3Value)
{
	if (NULL == pSampleSide)
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
			if (FALSE == pSampleSide->m_SizeCalculationResult.m_stDistance[i].m_bOK)
			{
				bResSize = FALSE;
				break;
			}
		}

		fResDValue = pSampleSide->m_SizeCalculationResult.m_stDistance[TYPE_GEOMETRY_DISTANCE_D].m_dValue;
		float fS1Value = pSampleSide->m_SizeCalculationResult.m_stDistance[TYPE_GEOMETRY_DISTANCE_S1].m_dValue;
		float fS2Value = pSampleSide->m_SizeCalculationResult.m_stDistance[TYPE_GEOMETRY_DISTANCE_S2].m_dValue;
		float fS3Value = pSampleSide->m_SizeCalculationResult.m_stDistance[TYPE_GEOMETRY_DISTANCE_S3].m_dValue;
		// Version 1.3.6.5 (치수 영역 추가 없이 PLC 통신 데이터 추가 (X1-X2, L))
		fResLValue = pSampleSide->m_SizeCalculationResult.m_stDistance[TYPE_GEOMETRY_DISTANCE_L].m_dValue;
		fResX1X2Value = pSampleSide->m_SizeCalculationResult.m_stDistance[TYPE_GEOMETRY_DISTANCE_X1X2].m_dValue;
		// Version 1.3.7.2 
		fResM1Value = pSampleSide->m_SizeCalculationResult.m_stDistance[TYPE_GEOMETRY_DISTANCE_M1].m_dValue;
		fResM2Value = pSampleSide->m_SizeCalculationResult.m_stDistance[TYPE_GEOMETRY_DISTANCE_M2].m_dValue;
		// Version 1.3.7.4
		fResS1S3Value = pSampleSide->m_SizeCalculationResult.m_stDistance[TYPE_GEOMETRY_DISTANCE_S1S3].m_dValue;

		/*if (fS1Value > 0.f &&
			fS2Value > 0.f &&
			fS3Value > 0.f)
			fResSValue = (fS1Value + fS3Value) / 2;
		else
			fResSValue = 0.f;*/

		//신장비용 s2 테스트버전
		if (fS2Value > 0.f)
			fResSValue = fS2Value;
		else
			fResSValue = 0.f;

		if (fResSValue < m_stOption.m_pstValidRange[TYPE_SIZE_VALID_S].m_fMin ||
			fResSValue > m_stOption.m_pstValidRange[TYPE_SIZE_VALID_S].m_fMax)
			fResSValue = 0.f;

		if (fResDValue < m_stOption.m_pstValidRange[TYPE_SIZE_VALID_D].m_fMin ||
			fResDValue > m_stOption.m_pstValidRange[TYPE_SIZE_VALID_D].m_fMax)
			fResDValue = 0.f;

		// Version 1.3.6.5 (치수 영역 추가 없이 PLC 통신 데이터 추가 (X1-X2, L))
		if (fResLValue < m_stOption.m_pstValidRange[TYPE_SIZE_VALID_L].m_fMin ||
			fResLValue > m_stOption.m_pstValidRange[TYPE_SIZE_VALID_L].m_fMax)
			fResLValue = 0.f;

		/*if (fResX1X2Value < m_stOption.m_pstValidRange[TYPE_SIZE_VALID_X1X2].m_fMin ||
			fResX1X2Value > m_stOption.m_pstValidRange[TYPE_SIZE_VALID_X1X2].m_fMax)
			fResX1X2Value = 0.f;*/

		// Version 1.3.7.2 (M1, M2)
		if (fResM1Value < m_stOption.m_pstValidRange[TYPE_SIZE_VALID_M1].m_fMin ||
			fResM1Value > m_stOption.m_pstValidRange[TYPE_SIZE_VALID_M1].m_fMax)
			fResM1Value = 0.f;

		if (fResM2Value < m_stOption.m_pstValidRange[TYPE_SIZE_VALID_M2].m_fMin ||
			fResM2Value > m_stOption.m_pstValidRange[TYPE_SIZE_VALID_M2].m_fMax)
			fResM2Value = 0.f;

		// Version 1.3.7.4
		/*if (fResS1S3Value < m_stOption.m_pstValidRange[TYPE_SIZE_VALID_S1S3].m_fMin ||
			fResS1S3Value > m_stOption.m_pstValidRange[TYPE_SIZE_VALID_S1S3].m_fMax)
			fResS1S3Value = 0.f;*/
	}
	else
	{
		fResDValue = 0.f;
		fResSValue = 0.f;
		// Version 1.3.6.5 (치수 영역 추가 없이 PLC 통신 데이터 추가 (X1-X2, L))
		fResLValue = 0.f;
		fResX1X2Value = 0.f;
		// Version 1.3.7.2 (M1, M2)
		fResM1Value = 0.f;
		fResM2Value = 0.f;
		// Version 1.3.7.4 (S1S3)
		fResS1S3Value = 0.f;
	}
}

// Version 1.3.6.5 (치수 영역 추가 없이 PLC 통신 데이터 추가 (X1-X2, L))
// Ver1.3.7.2 (치수 영역 추가 없이 PLC 통신 데이터 추가 (M1, M2))
// Ver1.3.7.4 (치수 영역 추가 없이 PLC 통신 데이터 추가 (S1S3))
BOOL CCaptureManager::SendInspectionResultCommand(TYPE_CAMERAPOS eCameraPos, CSampleSide* pSampleSide, int &iD, int &iS, int &iL, int &iX1X2, int &iM1, int &iM2, int &iS1S2)
{
	if (NULL == pSampleSide)
		return FALSE;

	BOOL bSize = TRUE;
	BOOL bShape = TRUE;
	float fDValue = 0.f;
	float fSValue = 0.f;
	// Version 1.3.6.5 (치수 영역 추가 없이 PLC 통신 데이터 추가 (X1-X2, L))
	float fLValue = 0.f;
	float fX1X2Value = 0.f;
	// Version 1.3.7.2 (M1, M2)
	float fM1Value = 0.f;
	float fM2Value = 0.f;
	// Version 1.3.7.4 (S1S3)
	float fS1S3Value = 0.f;
	iD, iS, iL, iX1X2, iM1, iM2, iS1S2 = 0;

	// Version 1.3.7.2 (M1, M2)
	// Version 1.3.7.4 (S1S3)
	CheckInspectionResult(eCameraPos, pSampleSide, bSize, bShape, fDValue, fSValue, fLValue, fX1X2Value, fM1Value, fM2Value, fS1S3Value);
	if (eCameraPos == TYPE_CAMERAPOS_FIRST)
	{
		const float fRatio = 100.f; // convert from 0.01 unit

		iD = static_cast<int>(fDValue * fRatio);
		iS = static_cast<int>(fSValue * fRatio);
		// Version 1.3.6.5 (치수 영역 추가 없이 PLC 통신 데이터 추가 (X1-X2, L))
		iL = static_cast<int>(fLValue * fRatio);
		iX1X2 = static_cast<int>(fX1X2Value * fRatio);
		// Version 1.3.7.2 (M1, M2)
		iM1 = static_cast<int>(fM1Value * fRatio);
		iM2 = static_cast<int>(fM2Value * fRatio);
		// Version 1.3.7.4 (S1S3)
		iS1S2 = static_cast<int>(fS1S3Value * fRatio);
	}

	else
	{
		const float fRatio = 100.f; // convert from 0.01 unit

		iD = static_cast<int>(fDValue * fRatio);
		iS = static_cast<int>(fSValue * fRatio);
		// Version 1.3.6.5 (치수 영역 추가 없이 PLC 통신 데이터 추가 (X1-X2, L))
		iL = static_cast<int>(fLValue * fRatio);
		iX1X2 = static_cast<int>(fX1X2Value * fRatio);
		// Version 1.3.7.2 (M1, M2)
		iM1 = static_cast<int>(fM1Value * fRatio);
		iM2 = static_cast<int>(fM2Value * fRatio);
		// Version 1.3.7.4 (S1S3)
		iS1S2 = static_cast<int>(fS1S3Value * fRatio);
	}
	return TRUE;
}


BOOL CCaptureManager::IntTo4HexString(int nData, TCHAR *szString, const int nLen)
{
	if (szString == NULL)
		return FALSE;

	TCHAR szTemp[MAX_TEXT_LEN] = { 0, };
	CUtil::StringFormat(szTemp, MAX_TEXT_LEN, "%04x", nData);

	TCHAR *szTemp_4char = szTemp + (CUtil::StringLength(szTemp) - 4);
	CUtil::StringCopy(szString, szTemp_4char);

	return TRUE;
}

void CCaptureManager::SendCommand(CSerialCtrl* pSerialCtrl, BYTE* pCommand, int nCmdLen, BYTE* pResponse, int& nResLen)
{
	SendStrobeCommand(pSerialCtrl, pCommand, nCmdLen, pResponse, nResLen);
}


BOOL CCaptureManager::GetCommunicateNotifyHandler(FuncNotifyEthernetListener* pFunc, void** pArg)
{
	if (NULL == m_pFuncSerialListener || NULL == m_pArgument)
		return FALSE;

	*pFunc = m_pFuncSerialListener;
	*pArg = m_pArgument;
	
	return TRUE;
}

BOOL CCaptureManager::ControlStrobeOnOff(CSerialCtrl* pSerialCtrl, TYPE_CAMERAPOS eType, TYPE_STROBE eStrobe)
{
	if (NULL == pSerialCtrl)
		return FALSE;
	::EnterCriticalSection(&m_CriticalSection);

#ifdef DEF_EMUL_STROBE
	ControlStrobeOnOffEmulator(pSerialCtrl, eType, eStrobe);
#else
	ControlStrobeOnOffDevice(pSerialCtrl, eType, eStrobe);
#endif

	if (TYPE_CAMERAPOS_FIRST == eType)
	{
		if (TYPE_STROBE_COXIAL == eStrobe)
			m_stStrobe.m_stFirstStrobe.m_bStrobeOnCoxial = TRUE;
		else if (TYPE_STROBE_RING == eStrobe)
			m_stStrobe.m_stFirstStrobe.m_bStrobeOnRing = TRUE;
		else if (TYPE_STROBE_BAR == eStrobe)
			m_stStrobe.m_stFirstStrobe.m_bStrobeOnBar = TRUE;
		else if (TYPE_STROBE_OFF == eStrobe)
		{
			m_stStrobe.m_stFirstStrobe.m_bStrobeOnCoxial = FALSE;
			m_stStrobe.m_stFirstStrobe.m_bStrobeOnRing = FALSE;
			m_stStrobe.m_stFirstStrobe.m_bStrobeOnBar = FALSE;
		}
	}
	else if (TYPE_CAMERAPOS_SECOND == eType)
	{
		if (TYPE_STROBE_COXIAL == eStrobe)
			m_stStrobe.m_stSecondStrobe.m_bStrobeOnCoxial = TRUE;
		else if (TYPE_STROBE_RING == eStrobe)
			m_stStrobe.m_stSecondStrobe.m_bStrobeOnRing = TRUE;
		else if (TYPE_STROBE_BAR == eStrobe)
			m_stStrobe.m_stSecondStrobe.m_bStrobeOnBar = TRUE;
		else if (TYPE_STROBE_OFF == eStrobe)
		{
			m_stStrobe.m_stSecondStrobe.m_bStrobeOnCoxial = FALSE;
			m_stStrobe.m_stSecondStrobe.m_bStrobeOnRing = FALSE;
			m_stStrobe.m_stSecondStrobe.m_bStrobeOnBar = FALSE;
		}
	}

	{
		INFO_LOGFUNC stLogFunc = this->m_Log.GetLogInterface();
		// Print Log
		{
			if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
			{
				if (TYPE_CAMERAPOS_FIRST == eType)
				{
					if(TYPE_STROBE_OFF == eStrobe)
						stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "First strobe - Off");
					else if (TYPE_STROBE_COXIAL == eStrobe)
						stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "First strobe - Coxial");
					else if (TYPE_STROBE_RING == eStrobe)
						stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "First strobe - Ring");
					else if (TYPE_STROBE_BAR == eStrobe)
						stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "First strobe - Bar");
				}
				else if (TYPE_CAMERAPOS_SECOND == eType)
				{
					if (TYPE_STROBE_OFF == eStrobe)
						stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Second strobe - Off");
					else if (TYPE_STROBE_COXIAL == eStrobe)
						stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Second strobe - Coxial");
					else if (TYPE_STROBE_RING == eStrobe)
						stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Second strobe - Ring");
					else if (TYPE_STROBE_BAR == eStrobe)
						stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Second strobe - Bar");
				}
			}
		}
	}

	::LeaveCriticalSection(&m_CriticalSection);
	return TRUE;
}

BOOL CCaptureManager::ControlStrobeBrightness(CSerialCtrl* pSerialCtrl, TYPE_CAMERAPOS eType, TYPE_STROBE eStrobe, int nBrightness)
{
	if (NULL == pSerialCtrl)
		return FALSE;
	::EnterCriticalSection(&m_CriticalSection);

#ifdef DEF_EMUL_STROBE
	ControlStrobeBrightnessEmulator(pSerialCtrl, eType, eStrobe, nBrightness);
#else
	ControlStrobeBrightnessDevice(pSerialCtrl, eType, eStrobe, nBrightness);
#endif
	if (TYPE_CAMERAPOS_FIRST == eType)
	{
		if (TYPE_STROBE_COXIAL == eStrobe)
		{
			m_stStrobe.m_stFirstStrobe.m_bStrobeOnCoxial = TRUE;
			m_stStrobe.m_stFirstStrobe.m_nBrightnessCoxial = nBrightness;
		}
		else if (TYPE_STROBE_RING == eStrobe)
		{
			m_stStrobe.m_stFirstStrobe.m_bStrobeOnRing = TRUE;
			m_stStrobe.m_stFirstStrobe.m_nBrightnessRing = nBrightness;
		}
		else if (TYPE_STROBE_BAR == eStrobe)
		{
			m_stStrobe.m_stFirstStrobe.m_bStrobeOnBar = TRUE;
			m_stStrobe.m_stFirstStrobe.m_nBrightnessBar = nBrightness;
		}
		else if (TYPE_STROBE_OFF == eStrobe)
		{
			m_stStrobe.m_stFirstStrobe.m_bStrobeOnCoxial = FALSE;
			m_stStrobe.m_stFirstStrobe.m_bStrobeOnRing = FALSE;
			m_stStrobe.m_stFirstStrobe.m_bStrobeOnBar = FALSE;
		}
	}
	else if (TYPE_CAMERAPOS_SECOND == eType)
	{
		if (TYPE_STROBE_COXIAL == eStrobe)
		{
			m_stStrobe.m_stSecondStrobe.m_bStrobeOnCoxial = TRUE;
			m_stStrobe.m_stSecondStrobe.m_nBrightnessCoxial = nBrightness;
		}
		else if (TYPE_STROBE_RING == eStrobe)
		{
			m_stStrobe.m_stSecondStrobe.m_bStrobeOnRing = TRUE;
			m_stStrobe.m_stSecondStrobe.m_nBrightnessRing = nBrightness;
		}
		else if (TYPE_STROBE_BAR == eStrobe)
		{
			m_stStrobe.m_stSecondStrobe.m_bStrobeOnBar = TRUE;
			m_stStrobe.m_stSecondStrobe.m_nBrightnessBar = nBrightness;
		}
		else if (TYPE_STROBE_OFF == eStrobe)
		{
			m_stStrobe.m_stSecondStrobe.m_bStrobeOnCoxial = FALSE;
			m_stStrobe.m_stSecondStrobe.m_bStrobeOnRing = FALSE;
			m_stStrobe.m_stSecondStrobe.m_bStrobeOnBar = FALSE;
		}
	}

	{
		INFO_LOGFUNC stLogFunc = this->m_Log.GetLogInterface();
		// Print Log
		{
			if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
			{
				if (TYPE_CAMERAPOS_FIRST == eType)
				{
					if (TYPE_STROBE_COXIAL == eStrobe)
						stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "First strobe - Write Coxial(%d)", nBrightness);
					else if (TYPE_STROBE_RING == eStrobe)
						stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "First strobe - Write Ring(%d)", nBrightness);
					else if (TYPE_STROBE_BAR == eStrobe)
						stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "First strobe - Write Bar(%d)", nBrightness);
				}
				else if (TYPE_CAMERAPOS_SECOND == eType)
				{
					if (TYPE_STROBE_COXIAL == eStrobe)
						stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Second strobe - Write Coxial(%d)", nBrightness);
					else if (TYPE_STROBE_RING == eStrobe)
						stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Second strobe - Write Ring(%d)", nBrightness);
					else if (TYPE_STROBE_BAR == eStrobe)
						stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Second strobe - Write Bar(%d)", nBrightness);
				}
			}
		}
	}
	::LeaveCriticalSection(&m_CriticalSection);
	return TRUE;
}

BOOL CCaptureManager::ControlStrobeBrightness(CSerialCtrl* pSerialCtrl, TYPE_CAMERAPOS eType, int nBrightness_COXIAL, int nBrightness_RING, int nBrightness_BAR)
{
	if (NULL == pSerialCtrl)
		return FALSE;
	::EnterCriticalSection(&m_CriticalSection);
#ifdef DEF_EMUL_STROBE
	if (TYPE_CAMERAPOS_FIRST == eType)
	{
		ControlStrobeBrightnessEmulator(pSerialCtrl, eType, nBrightness_COXIAL, nBrightness_RING, nBrightness_BAR,
			m_stStrobe.m_stSecondStrobe.m_nBrightnessCoxial, m_stStrobe.m_stSecondStrobe.m_nBrightnessRing, m_stStrobe.m_stSecondStrobe.m_nBrightnessBar);
	}
	else if (TYPE_CAMERAPOS_SECOND == eType)
	{

		ControlStrobeBrightnessEmulator(pSerialCtrl, eType, m_stStrobe.m_stFirstStrobe.m_nBrightnessCoxial, m_stStrobe.m_stFirstStrobe.m_nBrightnessRing,
			m_stStrobe.m_stFirstStrobe.m_nBrightnessBar, nBrightness_COXIAL, nBrightness_RING, nBrightness_BAR);
	}
#else
	if (TYPE_CAMERAPOS_FIRST == eType)
	{
		ControlStrobeBrightnessDevice(pSerialCtrl, eType, nBrightness_COXIAL, nBrightness_RING, nBrightness_BAR,
			m_stStrobe.m_stSecondStrobe.m_nBrightnessCoxial, m_stStrobe.m_stSecondStrobe.m_nBrightnessRing, m_stStrobe.m_stSecondStrobe.m_nBrightnessBar);
	}
	else if (TYPE_CAMERAPOS_SECOND == eType)
	{
		
		ControlStrobeBrightnessDevice(pSerialCtrl, eType, m_stStrobe.m_stFirstStrobe.m_nBrightnessCoxial, m_stStrobe.m_stFirstStrobe.m_nBrightnessRing, 
			m_stStrobe.m_stFirstStrobe.m_nBrightnessBar, nBrightness_COXIAL, nBrightness_RING, nBrightness_BAR);
	}
#endif
	if (TYPE_CAMERAPOS_FIRST == eType)
	{
		m_stStrobe.m_stFirstStrobe.m_bStrobeOnCoxial = TRUE;
		m_stStrobe.m_stFirstStrobe.m_nBrightnessCoxial = nBrightness_COXIAL;
		m_stStrobe.m_stFirstStrobe.m_bStrobeOnRing = TRUE;
		m_stStrobe.m_stFirstStrobe.m_nBrightnessRing = nBrightness_RING;
		m_stStrobe.m_stFirstStrobe.m_bStrobeOnBar = TRUE;
		m_stStrobe.m_stFirstStrobe.m_nBrightnessBar = nBrightness_BAR;
	}
	else if (TYPE_CAMERAPOS_SECOND == eType)
	{
		m_stStrobe.m_stSecondStrobe.m_bStrobeOnCoxial = TRUE;
		m_stStrobe.m_stSecondStrobe.m_nBrightnessCoxial = nBrightness_COXIAL;
		m_stStrobe.m_stSecondStrobe.m_bStrobeOnRing = TRUE;
		m_stStrobe.m_stSecondStrobe.m_nBrightnessRing = nBrightness_RING;
		m_stStrobe.m_stSecondStrobe.m_bStrobeOnBar = TRUE;
		m_stStrobe.m_stSecondStrobe.m_nBrightnessBar = nBrightness_BAR;
	}

	{
		INFO_LOGFUNC stLogFunc = this->m_Log.GetLogInterface();
		// Print Log
		{
			if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
			{
				if (TYPE_CAMERAPOS_FIRST == eType)
				{
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "First strobe - Write Coxial(%d)", nBrightness_COXIAL);
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "First strobe - Write Ring(%d)", nBrightness_RING);
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "First strobe - Write Bar(%d)", nBrightness_BAR);
				}
				else if (TYPE_CAMERAPOS_SECOND == eType)
				{
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Second strobe - Write Coxial(%d)", nBrightness_COXIAL);
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Second strobe - Write Ring(%d)", nBrightness_RING);
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Second strobe - Write Bar(%d)", nBrightness_BAR);
				}
			}
		}
	}
	::LeaveCriticalSection(&m_CriticalSection);
	return TRUE;
}

BOOL CCaptureManager::ReadStrobeBrightness(CSerialCtrl* pSerialCtrl)
{
	if (NULL == pSerialCtrl)
		return FALSE;
	BOOL bResult = FALSE;

	::EnterCriticalSection(&m_CriticalSection);

	m_stStrobe.m_stFirstStrobe.m_bStrobeOnCoxial = TRUE;
	m_stStrobe.m_stFirstStrobe.m_bStrobeOnRing = TRUE;
	m_stStrobe.m_stFirstStrobe.m_bStrobeOnBar = TRUE;

	m_stStrobe.m_stSecondStrobe.m_bStrobeOnCoxial = TRUE;
	m_stStrobe.m_stSecondStrobe.m_bStrobeOnRing = TRUE;
	m_stStrobe.m_stSecondStrobe.m_bStrobeOnBar = TRUE;

#ifdef DEF_EMUL_STROBE
	// do nothing;
	bResult = TRUE;

	ReadStrobeBrightnessEmulator(pSerialCtrl, TYPE_CAMERAPOS_FIRST, TYPE_STROBE_COXIAL);
	ReadStrobeBrightnessEmulator(pSerialCtrl, TYPE_CAMERAPOS_FIRST, TYPE_STROBE_RING);
	ReadStrobeBrightnessEmulator(pSerialCtrl, TYPE_CAMERAPOS_FIRST, TYPE_STROBE_BAR);

	ReadStrobeBrightnessEmulator(pSerialCtrl, TYPE_CAMERAPOS_SECOND, TYPE_STROBE_COXIAL);
	ReadStrobeBrightnessEmulator(pSerialCtrl, TYPE_CAMERAPOS_SECOND, TYPE_STROBE_RING);
	ReadStrobeBrightnessEmulator(pSerialCtrl, TYPE_CAMERAPOS_SECOND, TYPE_STROBE_BAR);

#else
	bResult = ReadStrobeBrightnessDevice(pSerialCtrl, TYPE_CAMERAPOS_FIRST, TYPE_STROBE_COXIAL);
	if (bResult)
		bResult = ReadStrobeBrightnessDevice(pSerialCtrl, TYPE_CAMERAPOS_FIRST, TYPE_STROBE_RING);
	if (bResult)
		bResult = ReadStrobeBrightnessDevice(pSerialCtrl, TYPE_CAMERAPOS_FIRST, TYPE_STROBE_BAR);

	if (bResult)
		bResult = ReadStrobeBrightnessDevice(pSerialCtrl, TYPE_CAMERAPOS_SECOND, TYPE_STROBE_COXIAL);
	if (bResult)
		bResult = ReadStrobeBrightnessDevice(pSerialCtrl, TYPE_CAMERAPOS_SECOND, TYPE_STROBE_RING);
	if (bResult)
		bResult = ReadStrobeBrightnessDevice(pSerialCtrl, TYPE_CAMERAPOS_SECOND, TYPE_STROBE_BAR);
#endif

	{
		ControlStrobeOnOff(pSerialCtrl, TYPE_CAMERAPOS_FIRST, TYPE_STROBE_OFF);
		ControlStrobeOnOff(pSerialCtrl, TYPE_CAMERAPOS_SECOND, TYPE_STROBE_OFF);
		
		// Strobe On
		BYTE pCommand[MAX_NAME_LEN] = { 0, };
		int nCmdLen = MAX_NAME_LEN;
		BYTE pResponse[MAX_NAME_LEN] = { 0, };
		int nResLen = MAX_NAME_LEN;
#ifdef DEF_EMUL_STROBE
#else
		BOOL bOn = TRUE;

		//TYPE_CAMERAPOS_FIRST
		{
			int ID_BAR = FIRST_STROBE_CH_BAR;
			int ID_COAX = FIRST_STROBE_CH_COAX;
			int ID_RING_4CHto1CH = FIRST_STROBE_CH_RING_1CH;

			// Strobe - COXIAL
			nCmdLen = MAX_NAME_LEN;
			nResLen = MAX_NAME_LEN;		memset(pResponse, 0x00, MAX_NAME_LEN);
			//#ifdef DEF_OLD_STROBE
			if (m_eStrobeControllerType == TYPE_STROBETYPE_A)
			{
				ComposeCommandSetStrobeOn(pCommand, nCmdLen, ID_COAX, bOn);
				SendStrobeCommand(pSerialCtrl, pCommand, nCmdLen, pResponse, nResLen);
			}
			//#endif		

			// Strobe - RING
#ifdef DEF_STROBE_RING_4CHto1CH
			nCmdLen = MAX_NAME_LEN;
			nResLen = MAX_NAME_LEN;		memset(pResponse, 0x00, MAX_NAME_LEN);
			//#ifdef DEF_OLD_STROBE
			if (m_eStrobeControllerType == TYPE_STROBETYPE_A)
			{
				ComposeCommandSetStrobeOn(pCommand, nCmdLen, ID_RING_4CHto1CH, bOn);
				SendStrobeCommand(pSerialCtrl, pCommand, nCmdLen, pResponse, nResLen);
			}
			//#endif
#else
			nCmdLen = MAX_NAME_LEN;
			nResLen = MAX_NAME_LEN;		memset(pResponse, 0x00, MAX_NAME_LEN);
			if (m_eStrobeControllerType == TYPE_STROBETYPE_A)
			{
				ComposeCommandSetStrobeOn(pCommand, nCmdLen, ID_RING01, bOn);
				SendStrobeCommand(pSerialCtrl, pCommand, nCmdLen, pResponse, nResLen);
			}

			nCmdLen = MAX_NAME_LEN;
			nResLen = MAX_NAME_LEN;		memset(pResponse, 0x00, MAX_NAME_LEN);
			if (m_eStrobeControllerType == TYPE_STROBETYPE_A)
			{
				ComposeCommandSetStrobeOn(pCommand, nCmdLen, ID_RING02, bOn);
				SendStrobeCommand(pSerialCtrl, pCommand, nCmdLen, pResponse, nResLen);
			}

			nCmdLen = MAX_NAME_LEN;
			nResLen = MAX_NAME_LEN;		memset(pResponse, 0x00, MAX_NAME_LEN);
			if (m_eStrobeControllerType == TYPE_STROBETYPE_A)
			{
				ComposeCommandSetStrobeOn(pCommand, nCmdLen, ID_RING03, bOn);
				SendStrobeCommand(pSerialCtrl, pCommand, nCmdLen, pResponse, nResLen);
			}

			nCmdLen = MAX_NAME_LEN;
			nResLen = MAX_NAME_LEN;		memset(pResponse, 0x00, MAX_NAME_LEN);
			if (m_eStrobeControllerType == TYPE_STROBETYPE_A)
			{
				ComposeCommandSetStrobeOn(pCommand, nCmdLen, ID_RING04, bOn);
				SendStrobeCommand(pSerialCtrl, pCommand, nCmdLen, pResponse, nResLen);
			}
#endif

			// Strobe - BAR
			nCmdLen = MAX_NAME_LEN;
			nResLen = MAX_NAME_LEN;		memset(pResponse, 0x00, MAX_NAME_LEN);
//#ifdef DEF_OLD_STROBE
			if (m_eStrobeControllerType == TYPE_STROBETYPE_A)
			{
				ComposeCommandSetStrobeOn(pCommand, nCmdLen, ID_BAR, bOn);
				SendStrobeCommand(pSerialCtrl, pCommand, nCmdLen, pResponse, nResLen);
			}
//#endif		

		}

		//TYPE_CAMERAPOS_SECOND
		{
			int ID_BAR = SECOND_STROBE_CH_BAR;
			int ID_COAX = SECOND_STROBE_CH_COAX;
			int ID_RING_4CHto1CH = SECOND_STROBE_CH_RING_1CH;

			/// Strobe - COXIAL
			nCmdLen = MAX_NAME_LEN;
			nResLen = MAX_NAME_LEN;		memset(pResponse, 0x00, MAX_NAME_LEN);
//#ifdef DEF_OLD_STROBE
			if (m_eStrobeControllerType == TYPE_STROBETYPE_A)
			{
				ComposeCommandSetStrobeOn(pCommand, nCmdLen, ID_COAX, bOn);
				SendStrobeCommand(pSerialCtrl, pCommand, nCmdLen, pResponse, nResLen);
			}
//#endif

			/// Strobe - RING
#ifdef DEF_STROBE_RING_4CHto1CH
			nCmdLen = MAX_NAME_LEN;
			nResLen = MAX_NAME_LEN;		memset(pResponse, 0x00, MAX_NAME_LEN);
//#ifdef DEF_OLD_STROBE
			if (m_eStrobeControllerType == TYPE_STROBETYPE_A)
			{
				ComposeCommandSetStrobeOn(pCommand, nCmdLen, ID_RING_4CHto1CH, bOn);
				SendStrobeCommand(pSerialCtrl, pCommand, nCmdLen, pResponse, nResLen);
			}
//#endif
#else
			nCmdLen = MAX_NAME_LEN;
			nResLen = MAX_NAME_LEN;		memset(pResponse, 0x00, MAX_NAME_LEN);
			if (m_eStrobeControllerType == TYPE_STROBETYPE_A)
			{
				ComposeCommandSetStrobeOn(pCommand, nCmdLen, ID_RING01, bOn);
				SendStrobeCommand(pSerialCtrl, pCommand, nCmdLen, pResponse, nResLen);
			}

			nCmdLen = MAX_NAME_LEN;
			nResLen = MAX_NAME_LEN;		memset(pResponse, 0x00, MAX_NAME_LEN);
			if (m_eStrobeControllerType == TYPE_STROBETYPE_A)
			{
				ComposeCommandSetStrobeOn(pCommand, nCmdLen, ID_RING02, bOn);
				SendStrobeCommand(pSerialCtrl, pCommand, nCmdLen, pResponse, nResLen);
			}

			nCmdLen = MAX_NAME_LEN;
			nResLen = MAX_NAME_LEN;		memset(pResponse, 0x00, MAX_NAME_LEN);
			if (m_eStrobeControllerType == TYPE_STROBETYPE_A)
			{
				ComposeCommandSetStrobeOn(pCommand, nCmdLen, ID_RING03, bOn);
				SendStrobeCommand(pSerialCtrl, pCommand, nCmdLen, pResponse, nResLen);
			}

			nCmdLen = MAX_NAME_LEN;
			nResLen = MAX_NAME_LEN;		memset(pResponse, 0x00, MAX_NAME_LEN);
			if (m_eStrobeControllerType == TYPE_STROBETYPE_A)
			{
				ComposeCommandSetStrobeOn(pCommand, nCmdLen, ID_RING04, bOn);
				SendStrobeCommand(pSerialCtrl, pCommand, nCmdLen, pResponse, nResLen);
			}
#endif

			// Strobe - BAR
			nCmdLen = MAX_NAME_LEN;
			nResLen = MAX_NAME_LEN;		memset(pResponse, 0x00, MAX_NAME_LEN);
//#ifdef DEF_OLD_STROBE
			if (m_eStrobeControllerType == TYPE_STROBETYPE_A)
			{
				ComposeCommandSetStrobeOn(pCommand, nCmdLen, ID_BAR, bOn);
				SendStrobeCommand(pSerialCtrl, pCommand, nCmdLen, pResponse, nResLen);
			}
//#endif
		}
#endif		
	}

	{
		INFO_LOGFUNC stLogFunc = this->m_Log.GetLogInterface();
		// Print Log
		{
			if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
			{
				stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "First strobe - Read Coxial(%d)", m_stStrobe.m_stFirstStrobe.m_nBrightnessCoxial);
				stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "First strobe - Read Ring(%d)", m_stStrobe.m_stFirstStrobe.m_nBrightnessRing);
				stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "First strobe - Read Bar(%d)", m_stStrobe.m_stFirstStrobe.m_nBrightnessBar);

				stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Second strobe - Read Coxial(%d)", m_stStrobe.m_stSecondStrobe.m_nBrightnessCoxial);
				stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Second strobe - Read Ring(%d)", m_stStrobe.m_stSecondStrobe.m_nBrightnessRing);
				stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Second strobe - Read Bar(%d)", m_stStrobe.m_stSecondStrobe.m_nBrightnessBar);
			}
		}
	}
	::LeaveCriticalSection(&m_CriticalSection);
	return bResult;
}



void CCaptureManager::ControlStrobeOnOffEmulator(CSerialCtrl* pSerialCtrl, TYPE_CAMERAPOS eType, TYPE_STROBE eStrobe)
{
	if (NULL == pSerialCtrl)
		return;

	TCHAR pszCommand[MAX_NAME_LEN] = { 0, };
	if (TYPE_CAMERAPOS_FIRST == eType)
	{
		if (TYPE_STROBE_OFF == eStrobe)
			CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("FIRST %s\r\n"), _T("TYPE_STROBE_OFF"));
		else if (TYPE_STROBE_COXIAL == eStrobe)
			CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("FIRST %s\r\n"), _T("TYPE_STROBE_COXIAL"));
		else if (TYPE_STROBE_RING == eStrobe)
			CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("FIRST %s\r\n"), _T("TYPE_STROBE_RING"));
		else if (TYPE_STROBE_BAR == eStrobe)
			CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("FIRST %s\r\n"), _T("TYPE_STROBE_BAR"));
		else
			CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("FIRST %s\r\n"), _T("WRONG STROBE"));
	}
	else if (TYPE_CAMERAPOS_SECOND == eType)
	{
		if (TYPE_STROBE_OFF == eStrobe)
			CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("SECOND %s\r\n"), _T("TYPE_STROBE_OFF"));
		else if (TYPE_STROBE_COXIAL == eStrobe)
			CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("SECOND %s\r\n"), _T("TYPE_STROBE_COXIAL"));
		else if (TYPE_STROBE_RING == eStrobe)
			CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("SECOND %s\r\n"), _T("TYPE_STROBE_RING"));
		else if (TYPE_STROBE_BAR == eStrobe)
			CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("SECOND %s\r\n"), _T("TYPE_STROBE_BAR"));
		else
			CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("SECOND %s\r\n"), _T("WRONG STROBE"));
	}
	else
	{
		CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("%s\r\n"), _T("WRONG STROBE"));
	}

	DWORD dwRes = 0;

	int nLen = CUtil::StringLength(pszCommand);
	CUtil::PrintDebugString(pszCommand);
	BOOL bResult = pSerialCtrl->Write(pszCommand, nLen, &dwRes);
	if (!bResult)
	{
		CUtil::PrintDebugString(_T("Fail to write strobe. \r\n"));
	}
}

void CCaptureManager::ControlStrobeOnOffDevice(CSerialCtrl* pSerialCtrl, TYPE_CAMERAPOS eType, TYPE_STROBE eStrobe)
{
	if (NULL == pSerialCtrl || TYPE_CAMERAPOS_FIRST != eType && TYPE_CAMERAPOS_SECOND != eType)
		return;

	int nBrightness = 0;
	if (TYPE_CAMERAPOS_FIRST == eType)
	{
		if (TYPE_STROBE_COXIAL == eStrobe)		nBrightness = m_stStrobe.m_stFirstStrobe.m_nBrightnessCoxial;
		else if (TYPE_STROBE_RING == eStrobe)	nBrightness = m_stStrobe.m_stFirstStrobe.m_nBrightnessRing;
		else if (TYPE_STROBE_BAR == eStrobe)	nBrightness = m_stStrobe.m_stFirstStrobe.m_nBrightnessBar;
	}
	else if (TYPE_CAMERAPOS_SECOND == eType)
	{
		if (TYPE_STROBE_COXIAL == eStrobe)		nBrightness = m_stStrobe.m_stSecondStrobe.m_nBrightnessCoxial;
		else if (TYPE_STROBE_RING == eStrobe)	nBrightness = m_stStrobe.m_stSecondStrobe.m_nBrightnessRing;
		else if (TYPE_STROBE_BAR == eStrobe)	nBrightness = m_stStrobe.m_stSecondStrobe.m_nBrightnessBar;
	}

	if (TYPE_STROBE_OFF == eStrobe)
	{
		// All Off
		ControlStrobeBrightnessDevice(pSerialCtrl, eType, TYPE_STROBE_OFF, nBrightness);
	}
	else if (TYPE_STROBE_COXIAL == eStrobe)
	{
		// Coxial On
		ControlStrobeBrightnessDevice(pSerialCtrl, eType, eStrobe, nBrightness);
	}
	else if (TYPE_STROBE_RING == eStrobe)
	{
		// Ring On
		ControlStrobeBrightnessDevice(pSerialCtrl, eType, eStrobe, nBrightness);
	}
	else if (TYPE_STROBE_BAR == eStrobe)
	{
		// Bar On
		ControlStrobeBrightnessDevice(pSerialCtrl, eType, eStrobe, nBrightness);
	}
}


void CCaptureManager::ControlStrobeBrightnessEmulator(CSerialCtrl* pSerialCtrl, TYPE_CAMERAPOS eType, TYPE_STROBE eStrobe, int nBrightness)
{
	if (NULL == pSerialCtrl)
		return;

	TCHAR pszCommand[MAX_NAME_LEN] = { 0, };
	if (TYPE_CAMERAPOS_FIRST == eType)
	{
		if (TYPE_STROBE_COXIAL == eStrobe)
			CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("FIRST %s Write(%d)\r\n"), _T("TYPE_STROBE_COXIAL"), nBrightness);
		else if (TYPE_STROBE_RING == eStrobe)
			CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("FIRST %s Write(%d)\r\n"), _T("TYPE_STROBE_RING"), nBrightness);
		else if (TYPE_STROBE_BAR == eStrobe)
			CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("FIRST %s Write(%d)\r\n"), _T("TYPE_STROBE_BAR"), nBrightness);
		else if (TYPE_STROBE_OFF == eStrobe)
			CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("FIRST %s Write\r\n"), _T("TYPE_STROBE_OFF"));
		else
			CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("FIRST %s\r\n"), _T("WRONG STROBE"));
	}
	else if (TYPE_CAMERAPOS_SECOND == eType)
	{
		if (TYPE_STROBE_COXIAL == eStrobe)
			CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("SECOND %s Write(%d)\r\n"), _T("TYPE_STROBE_COXIAL"), nBrightness);
		else if (TYPE_STROBE_RING == eStrobe)
			CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("SECOND %s Write(%d)\r\n"), _T("TYPE_STROBE_RING"), nBrightness);
		else if (TYPE_STROBE_BAR == eStrobe)
			CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("SECOND %s Write(%d)\r\n"), _T("TYPE_STROBE_BAR"), nBrightness);
		else if (TYPE_STROBE_OFF == eStrobe)
			CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("SECOND %s Write\r\n"), _T("TYPE_STROBE_OFF"));
		else
			CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("SECOND %s\r\n"), _T("WRONG STROBE"));
	}
	else
	{
		CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("%s\r\n"), _T("WRONG STROBE"));
	}

	DWORD dwRes = 0;

	int nLen = CUtil::StringLength(pszCommand);
	CUtil::PrintDebugString(pszCommand);
	BOOL bResult = pSerialCtrl->Write(pszCommand, nLen, &dwRes);
	if (!bResult)
	{
		CUtil::PrintDebugString(_T("Fail to write strobe. \r\n"));
	}
}

void CCaptureManager::ControlStrobeBrightnessEmulator(CSerialCtrl* pSerialCtrl, TYPE_CAMERAPOS eType, int nBrightness_FC, int nBrightness_FR, int nBrightness_FB, int nBrightness_SC, int nBrightness_SR, int nBrightness_SB)
{
	if (NULL == pSerialCtrl)
		return;

	TCHAR pszCommand[MAX_NAME_LEN] = { 0, };
	TCHAR pszCommand_C[MAX_NAME_LEN] = { 0, };
	TCHAR pszCommand_R[MAX_NAME_LEN] = { 0, };
	TCHAR pszCommand_B[MAX_NAME_LEN] = { 0, };
	if (TYPE_CAMERAPOS_FIRST == eType)
	{
		CUtil::StringFormat(pszCommand_C, MAX_NAME_LEN, _T("FIRST %s Write(%d)\r\n"), _T("TYPE_STROBE_COXIAL"), nBrightness_FC);
		CUtil::StringFormat(pszCommand_R, MAX_NAME_LEN, _T("FIRST %s Write(%d)\r\n"), _T("TYPE_STROBE_RING"), nBrightness_FR);
		CUtil::StringFormat(pszCommand_B, MAX_NAME_LEN, _T("FIRST %s Write(%d)\r\n"), _T("TYPE_STROBE_BAR"), nBrightness_FB);

		DWORD dwRes = 0;

		int nLen = CUtil::StringLength(pszCommand_C);
		CUtil::PrintDebugString(pszCommand_C);
		BOOL bResult = pSerialCtrl->Write(pszCommand_C, nLen, &dwRes);
		if (!bResult)
		{
			CUtil::PrintDebugString(_T("Fail to write strobe. \r\n"));
		}

		nLen = CUtil::StringLength(pszCommand_R);
		CUtil::PrintDebugString(pszCommand_R);
		bResult = pSerialCtrl->Write(pszCommand_R, nLen, &dwRes);
		if (!bResult)
		{
			CUtil::PrintDebugString(_T("Fail to write strobe. \r\n"));
		}

		nLen = CUtil::StringLength(pszCommand_B);
		CUtil::PrintDebugString(pszCommand_B);
		bResult = pSerialCtrl->Write(pszCommand_B, nLen, &dwRes);
		if (!bResult)
		{
			CUtil::PrintDebugString(_T("Fail to write strobe. \r\n"));
		}
	}
	else if (TYPE_CAMERAPOS_SECOND == eType)
	{
		CUtil::StringFormat(pszCommand_C, MAX_NAME_LEN, _T("SECOND %s Write(%d)\r\n"), _T("TYPE_STROBE_COXIAL"), nBrightness_SC);
		CUtil::StringFormat(pszCommand_R, MAX_NAME_LEN, _T("SECOND %s Write(%d)\r\n"), _T("TYPE_STROBE_RING"), nBrightness_SR);
		CUtil::StringFormat(pszCommand_B, MAX_NAME_LEN, _T("SECOND %s Write(%d)\r\n"), _T("TYPE_STROBE_BAR"), nBrightness_SB);

		DWORD dwRes = 0;

		int nLen = CUtil::StringLength(pszCommand_C);
		CUtil::PrintDebugString(pszCommand_C);
		BOOL bResult = pSerialCtrl->Write(pszCommand_C, nLen, &dwRes);
		if (!bResult)
		{
			CUtil::PrintDebugString(_T("Fail to write strobe. \r\n"));
		}

		nLen = CUtil::StringLength(pszCommand_R);
		CUtil::PrintDebugString(pszCommand_R);
		bResult = pSerialCtrl->Write(pszCommand_R, nLen, &dwRes);
		if (!bResult)
		{
			CUtil::PrintDebugString(_T("Fail to write strobe. \r\n"));
		}

		nLen = CUtil::StringLength(pszCommand_B);
		CUtil::PrintDebugString(pszCommand_B);
		bResult = pSerialCtrl->Write(pszCommand_B, nLen, &dwRes);
		if (!bResult)
		{
			CUtil::PrintDebugString(_T("Fail to write strobe. \r\n"));
		}
	}
	else
	{
		CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("%s\r\n"), _T("WRONG STROBE"));

		DWORD dwRes = 0;

		int nLen = CUtil::StringLength(pszCommand);
		CUtil::PrintDebugString(pszCommand);
		BOOL bResult = pSerialCtrl->Write(pszCommand, nLen, &dwRes);
		if (!bResult)
		{
			CUtil::PrintDebugString(_T("Fail to write strobe. \r\n"));
		}
	}

	/*DWORD dwRes = 0;

	int nLen = CUtil::StringLength(pszCommand);
	CUtil::PrintDebugString(pszCommand);
	BOOL bResult = pSerialCtrl->Write(pszCommand, nLen, &dwRes);
	if (!bResult)
	{
	CUtil::PrintDebugString(_T("Fail to write strobe. \r\n"));
	}*/
}

void CCaptureManager::ControlStrobeBrightnessDevice(CSerialCtrl* pSerialCtrl, TYPE_CAMERAPOS eType, TYPE_STROBE eStrobe, int nBrightness)
{
	if (NULL == pSerialCtrl || TYPE_CAMERAPOS_FIRST != eType && TYPE_CAMERAPOS_SECOND != eType)
		return;

	int ID_RING01 = 0;
	int ID_RING02 = 0;
	int ID_RING03 = 0;
	int ID_RING04 = 0;
	int ID_BAR = 0;
	int ID_COAX = 0;
	int ID_RING_4CHto1CH = 0;

	if (TYPE_CAMERAPOS_FIRST == eType)
	{
		ID_BAR = FIRST_STROBE_CH_BAR;
		ID_COAX = FIRST_STROBE_CH_COAX;
		ID_RING_4CHto1CH = FIRST_STROBE_CH_RING_1CH;
	}
	else if (TYPE_CAMERAPOS_SECOND == eType)
	{
		ID_BAR = SECOND_STROBE_CH_BAR;
		ID_COAX = SECOND_STROBE_CH_COAX;
		ID_RING_4CHto1CH = SECOND_STROBE_CH_RING_1CH;
	}

	BYTE pCommand[MAX_NAME_LEN] = { 0, };
	int nCmdLen = MAX_NAME_LEN;
	BYTE pResponse[MAX_NAME_LEN] = { 0, };
	int nResLen = MAX_NAME_LEN;

	BOOL bResult = FALSE;

	if (TYPE_STROBE_COXIAL == eStrobe)
	{
		nCmdLen = MAX_NAME_LEN;
		nResLen = MAX_NAME_LEN;		memset(pResponse, 0x00, MAX_NAME_LEN);
		ComposeCommandSetStrobeBrightness(pCommand, nCmdLen, ID_COAX, nBrightness);
		SendStrobeCommand(pSerialCtrl, pCommand, nCmdLen, pResponse, nResLen);
//#ifdef DEF_OLD_STROBE
		if (m_eStrobeControllerType == TYPE_STROBETYPE_A)
		{
			bResult = CUtil::StringSearch((TCHAR*)pResponse, _T("OK"));
		}
//#else
		else if (m_eStrobeControllerType == TYPE_STROBETYPE_B)
		{
			if ((pResponse[3] == 79) && (pResponse[4]) == 75) //79=="O", 75=="K"
				bResult = TRUE;
		}
//#endif
	}
	else if (TYPE_STROBE_RING == eStrobe)
	{
#ifdef DEF_STROBE_RING_4CHto1CH
		nCmdLen = MAX_NAME_LEN;
		nResLen = MAX_NAME_LEN;		memset(pResponse, 0x00, MAX_NAME_LEN);
		ComposeCommandSetStrobeBrightness(pCommand, nCmdLen, ID_RING_4CHto1CH, nBrightness);
		SendStrobeCommand(pSerialCtrl, pCommand, nCmdLen, pResponse, nResLen);
//#ifdef DEF_OLD_STROBE
		if (m_eStrobeControllerType == TYPE_STROBETYPE_A)
		{
			bResult = CUtil::StringSearch((TCHAR*)pResponse, _T("OK"));
		}
//#else
		else if (m_eStrobeControllerType == TYPE_STROBETYPE_B)
		{
			if ((pResponse[3] == 79) && (pResponse[4]) == 75) //79=="O", 75=="K"
				bResult = TRUE;
		}
//#endif
#else
		nCmdLen = MAX_NAME_LEN;
		nResLen = MAX_NAME_LEN;		memset(pResponse, 0x00, MAX_NAME_LEN);
		ComposeCommandSetStrobeBrightness(pCommand, nCmdLen, ID_RING01, nBrightness);
		SendStrobeCommand(pSerialCtrl, pCommand, nCmdLen, pResponse, nResLen);
		if (m_eStrobeControllerType == TYPE_STROBETYPE_A)
		{
			bResult = CUtil::StringSearch((TCHAR*)pResponse, _T("OK"));
		}
		else if (m_eStrobeControllerType == TYPE_STROBETYPE_B)
		{
			if ((pResponse[3] == 79) && (pResponse[4]) == 75) //79=="O", 75=="K"
				bResult = TRUE;
		}

		nCmdLen = MAX_NAME_LEN;
		nResLen = MAX_NAME_LEN;		memset(pResponse, 0x00, MAX_NAME_LEN);
		ComposeCommandSetStrobeBrightness(pCommand, nCmdLen, ID_RING02, nBrightness);
		SendStrobeCommand(pSerialCtrl, pCommand, nCmdLen, pResponse, nResLen);
		if (m_eStrobeControllerType == TYPE_STROBETYPE_A)
		{
			bResult = CUtil::StringSearch((TCHAR*)pResponse, _T("OK"));
		}
		else if (m_eStrobeControllerType == TYPE_STROBETYPE_B)
		{
			if ((pResponse[3] == 79) && (pResponse[4]) == 75) //79=="O", 75=="K"
				bResult = TRUE;
		}

		nCmdLen = MAX_NAME_LEN;
		nResLen = MAX_NAME_LEN;		memset(pResponse, 0x00, MAX_NAME_LEN);
		ComposeCommandSetStrobeBrightness(pCommand, nCmdLen, ID_RING03, nBrightness);
		SendStrobeCommand(pSerialCtrl, pCommand, nCmdLen, pResponse, nResLen);
		if (m_eStrobeControllerType == TYPE_STROBETYPE_A)
		{
			bResult = CUtil::StringSearch((TCHAR*)pResponse, _T("OK"));
		}
		else if (m_eStrobeControllerType == TYPE_STROBETYPE_B)
		{
			if ((pResponse[3] == 79) && (pResponse[4]) == 75) //79=="O", 75=="K"
				bResult = TRUE;
		}

		nCmdLen = MAX_NAME_LEN;
		nResLen = MAX_NAME_LEN;		memset(pResponse, 0x00, MAX_NAME_LEN);
		ComposeCommandSetStrobeBrightness(pCommand, nCmdLen, ID_RING04, nBrightness);
		SendStrobeCommand(pSerialCtrl, pCommand, nCmdLen, pResponse, nResLen);
		if (m_eStrobeControllerType == TYPE_STROBETYPE_A)
		{
			bResult = CUtil::StringSearch((TCHAR*)pResponse, _T("OK"));
		}
		else if (m_eStrobeControllerType == TYPE_STROBETYPE_B)
		{
			if ((pResponse[3] == 79) && (pResponse[4]) == 75) //79=="O", 75=="K"
				bResult = TRUE;
		}
#endif
	}
	else if (TYPE_STROBE_BAR == eStrobe)
	{
		nCmdLen = MAX_NAME_LEN;
		nResLen = MAX_NAME_LEN;		memset(pResponse, 0x00, MAX_NAME_LEN);
		ComposeCommandSetStrobeBrightness(pCommand, nCmdLen, ID_BAR, nBrightness);
		SendStrobeCommand(pSerialCtrl, pCommand, nCmdLen, pResponse, nResLen);
//#ifdef DEF_OLD_STROBE
		if (m_eStrobeControllerType == TYPE_STROBETYPE_A)
		{
			bResult = CUtil::StringSearch((TCHAR*)pResponse, _T("OK"));
		}
//#else
		else if (m_eStrobeControllerType == TYPE_STROBETYPE_B)
		{
			if ((pResponse[3] == 79) && (pResponse[4]) == 75) //79=="O", 75=="K"
				bResult = TRUE;
		}
//#endif
	}
	else if (TYPE_STROBE_OFF == eStrobe)
	{
		//ControlStrobeOnOff(pSerialCtrl, eType, TYPE_STROBE_OFF);
		if (TYPE_CAMERAPOS_FIRST == eType)
		{
			if (m_stStrobe.m_stFirstStrobe.m_bStrobeOnCoxial)
				ControlStrobeBrightnessDevice(pSerialCtrl, eType, TYPE_STROBE_COXIAL, 0);
			if (m_stStrobe.m_stFirstStrobe.m_bStrobeOnRing)
				ControlStrobeBrightnessDevice(pSerialCtrl, eType, TYPE_STROBE_RING, 0);
			if (m_stStrobe.m_stFirstStrobe.m_bStrobeOnBar)
				ControlStrobeBrightnessDevice(pSerialCtrl, eType, TYPE_STROBE_BAR, 0);
		}
		else if (TYPE_CAMERAPOS_SECOND == eType)
		{
			if (m_stStrobe.m_stSecondStrobe.m_bStrobeOnCoxial)
				ControlStrobeBrightnessDevice(pSerialCtrl, eType, TYPE_STROBE_COXIAL, 0);
			if (m_stStrobe.m_stSecondStrobe.m_bStrobeOnRing)
				ControlStrobeBrightnessDevice(pSerialCtrl, eType, TYPE_STROBE_RING, 0);
			if (m_stStrobe.m_stSecondStrobe.m_bStrobeOnBar)
				ControlStrobeBrightnessDevice(pSerialCtrl, eType, TYPE_STROBE_BAR, 0);
		}
	}
}

void CCaptureManager::ControlStrobeBrightnessDevice(CSerialCtrl* pSerialCtrl, TYPE_CAMERAPOS eType, int nBrightness_FC, int nBrightness_FR, int nBrightness_FB, int nBrightness_SC, int nBrightness_SR, int nBrightness_SB)
{
	if (NULL == pSerialCtrl || TYPE_CAMERAPOS_FIRST != eType && TYPE_CAMERAPOS_SECOND != eType)
		return;

	BYTE pCommand[MAX_NAME_LEN] = { 0, };
	int nCmdLen = 0;
	BYTE pResponse[MAX_NAME_LEN] = { 0, };
	int nResLen = MAX_NAME_LEN;

	BOOL bResult = FALSE;

	nCmdLen = MAX_NAME_LEN;
	nResLen = MAX_NAME_LEN;		memset(pResponse, 0x00, MAX_NAME_LEN);
	ComposeCommandSetStrobeBrightness(pCommand, nCmdLen, nBrightness_FC, nBrightness_FR, nBrightness_FB, nBrightness_SC, nBrightness_SR, nBrightness_SB);
	SendStrobeCommand(pSerialCtrl, pCommand, nCmdLen, pResponse, nResLen);

//#ifdef DEF_OLD_STROBE
	if (m_eStrobeControllerType == TYPE_STROBETYPE_A)
	{
		bResult = CUtil::StringSearch((TCHAR*)pResponse, _T("OK"));
	}
//#else
	else if (m_eStrobeControllerType == TYPE_STROBETYPE_B)
	{
		if ((pResponse[3] == 79) && (pResponse[4]) == 75)
			bResult = TRUE;
	}
//#endif
}

BOOL CCaptureManager::ReadStrobeBrightnessEmulator(CSerialCtrl* pSerialCtrl, TYPE_CAMERAPOS eType, TYPE_STROBE eStrobe)
{
	if (NULL == pSerialCtrl || TYPE_CAMERAPOS_FIRST != eType && TYPE_CAMERAPOS_SECOND != eType)
		return FALSE;

	INFO_STROBE_BRIGHTNESS* pstBrightness = NULL;
	if (TYPE_CAMERAPOS_FIRST == eType)
		pstBrightness = &m_stStrobe.m_stFirstStrobe;
	else if (TYPE_CAMERAPOS_SECOND == eType)
		pstBrightness = &m_stStrobe.m_stSecondStrobe;

	{
		TCHAR pszCommand[MAX_NAME_LEN] = { 0, };
		if (TYPE_CAMERAPOS_FIRST == eType)
		{
			if (TYPE_STROBE_COXIAL == eStrobe)
			{
				CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("FIRST %s - READ 1\r\n"), _T("TYPE_STROBE_COXIAL"));
				pstBrightness->m_nBrightnessCoxial = 1;
			}
			else if (TYPE_STROBE_RING == eStrobe)
			{
				CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("FIRST %s - READ 1\r\n"), _T("TYPE_STROBE_RING"));
				pstBrightness->m_nBrightnessRing = 1;
			}
			else if (TYPE_STROBE_BAR == eStrobe)
			{
				CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("FIRST %s - READ 1\r\n"), _T("TYPE_STROBE_BAR"));
				pstBrightness->m_nBrightnessBar = 1;
			}
			else if (TYPE_STROBE_OFF == eStrobe)
			{
				CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("FIRST %s\r\n"), _T("TYPE_STROBE_OFF"));
				pstBrightness->m_nBrightnessBar = 0;
			}
			else
			{
				CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("FIRST %s - READ\r\n"), _T("WRONG STROBE"));
			}
		}
		else if (TYPE_CAMERAPOS_SECOND == eType)
		{
			if (TYPE_STROBE_COXIAL == eStrobe)
			{
				CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("SECOND %s - READ 1\r\n"), _T("TYPE_STROBE_COXIAL"));
				pstBrightness->m_nBrightnessCoxial = 1;
			}
			else if (TYPE_STROBE_RING == eStrobe)
			{
				CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("SECOND %s - READ 1\r\n"), _T("TYPE_STROBE_RING"));
				pstBrightness->m_nBrightnessRing = 1;
			}
			else if (TYPE_STROBE_BAR == eStrobe)
			{
				CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("SECOND %s - READ 1\r\n"), _T("TYPE_STROBE_BAR"));
				pstBrightness->m_nBrightnessBar = 1;
			}
			else if (TYPE_STROBE_OFF == eStrobe)
			{
				CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("SECOND %s\r\n"), _T("TYPE_STROBE_OFF"));
				pstBrightness->m_nBrightnessBar = 0;
			}
			else
			{
				CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("SECOND %s - READ\r\n"), _T("WRONG STROBE"));
			}
		}
		else
		{
			CUtil::StringFormat(pszCommand, MAX_NAME_LEN, _T("%s\r\n"), _T("WRONG STROBE - READ"));
		}

		DWORD dwRes = 0;

		int nLen = CUtil::StringLength(pszCommand);
		CUtil::PrintDebugString(pszCommand);
		BOOL bResult = pSerialCtrl->Write(pszCommand, nLen, &dwRes);
		if (!bResult)
		{
			CUtil::PrintDebugString(_T("Fail to read brightness. \r\n"));
		}
	}


	return TRUE;
}

BOOL CCaptureManager::ReadStrobeBrightnessDevice(CSerialCtrl* pSerialCtrl, TYPE_CAMERAPOS eType, TYPE_STROBE eStrobe)
{
	if (NULL == pSerialCtrl || TYPE_CAMERAPOS_FIRST != eType && TYPE_CAMERAPOS_SECOND != eType)
		return FALSE;

	INFO_STROBE_BRIGHTNESS* pstBrightness = NULL;

	int ID_RING01 = 0;
	int ID_RING02 = 0;
	int ID_RING03 = 0;
	int ID_RING04 = 0;
	int ID_BAR = 0;
	int ID_COAX = 0;
	int ID_RING_4CHto1CH = 0;

	if (TYPE_CAMERAPOS_FIRST == eType)
	{
		ID_BAR = FIRST_STROBE_CH_BAR;
		ID_COAX = FIRST_STROBE_CH_COAX;
		ID_RING_4CHto1CH = FIRST_STROBE_CH_RING_1CH;

		pstBrightness = &m_stStrobe.m_stFirstStrobe;
	}
	else if (TYPE_CAMERAPOS_SECOND == eType)
	{
		ID_BAR = SECOND_STROBE_CH_BAR;
		ID_COAX = SECOND_STROBE_CH_COAX;
		ID_RING_4CHto1CH = SECOND_STROBE_CH_RING_1CH;

		pstBrightness = &m_stStrobe.m_stSecondStrobe;
	}

#ifdef DEF_STROBE_RING_4CHto1CH
	int ID_RING = ID_RING_4CHto1CH;
#endif


	BYTE pCommand[MAX_NAME_LEN] = { 0, };
	int nCmdLen = MAX_NAME_LEN;
	BYTE pResponse[MAX_NAME_LEN] = { 0, };
	int nResLen = MAX_NAME_LEN;

	BOOL bResult = FALSE;
	if (TYPE_STROBE_COXIAL == eStrobe)
	{
		nCmdLen = MAX_NAME_LEN;
		nResLen = MAX_NAME_LEN;		memset(pResponse, 0x00, MAX_NAME_LEN);
		ComposeCommandGetStrobeBrightness(pCommand, nCmdLen, ID_COAX);
		SendStrobeCommand(pSerialCtrl, pCommand, nCmdLen, pResponse, nResLen);

		pstBrightness->m_nBrightnessCoxial = ParseCommandGetStrobeBrightness(pResponse, nResLen, ID_COAX);
		if (-1 < pstBrightness->m_nBrightnessCoxial)
		{
			bResult = TRUE;
		}

	}
	else if (TYPE_STROBE_RING == eStrobe)
	{
		nCmdLen = MAX_NAME_LEN;
		nResLen = MAX_NAME_LEN;		memset(pResponse, 0x00, MAX_NAME_LEN);
		ComposeCommandGetStrobeBrightness(pCommand, nCmdLen, ID_RING);
		SendStrobeCommand(pSerialCtrl, pCommand, nCmdLen, pResponse, nResLen);

		pstBrightness->m_nBrightnessRing = ParseCommandGetStrobeBrightness(pResponse, nResLen, ID_RING);
		if (-1 < pstBrightness->m_nBrightnessRing)
		{
			bResult = TRUE;
		}

	}
	else if (TYPE_STROBE_BAR == eStrobe)
	{
		nCmdLen = MAX_NAME_LEN;
		nResLen = MAX_NAME_LEN;		memset(pResponse, 0x00, MAX_NAME_LEN);
		ComposeCommandGetStrobeBrightness(pCommand, nCmdLen, ID_BAR);
		SendStrobeCommand(pSerialCtrl, pCommand, nCmdLen, pResponse, nResLen);

		pstBrightness->m_nBrightnessBar = ParseCommandGetStrobeBrightness(pResponse, nResLen, ID_BAR);
		if (-1 < pstBrightness->m_nBrightnessBar)
		{
			bResult = TRUE;
		}
	}

	return bResult;
}



BOOL CCaptureManager::IsReadyInspectionDevice()
{
#ifdef USE_BASLER_CAMERA
	BOOL bConnect = this->IsEnableConnection(TYPE_NETWORK_BASLER);
#endif

#ifdef USE_GIGE_CAMERA
	BOOL bConnect = this->IsEnableConnection(TYPE_NETWORK_GIGE);
#endif

	if (FALSE == bConnect)
		return FALSE;
	
	const INFO_CAPTUREPROC* pstProcFirst = this->GetCapturePosition(TYPE_CAMERAPOS_FIRST);
	const INFO_CAPTUREPROC* pstProcSecond = this->GetCapturePosition(TYPE_CAMERAPOS_SECOND);
	if (NULL == pstProcFirst || NULL == pstProcSecond)
	{
		return FALSE;
	}

	CSerialCtrl* pSerialFirst = this->GetStrobeControlPort(TYPE_CAMERAPOS_FIRST);
	CSerialCtrl* pSerialSecond = this->GetStrobeControlPort(TYPE_CAMERAPOS_SECOND);
	if (NULL == pSerialFirst || NULL == pSerialSecond ||
		FALSE == pSerialFirst->IsOpen() || FALSE == pSerialSecond->IsOpen())
	{
		return FALSE;
	}


#ifdef USE_PLC_MXCOMPONENT
	if (!m_bMXComponentOpenCom)
		return FALSE;
#else
	CEthernet* pEthernetPort = this->GetCommunicatePort();
	if (NULL == pEthernetPort || FALSE == pEthernetPort->IsOpen())
		return FALSE;
#endif

	return TRUE;
}

CInspection* CCaptureManager::GetInspection()
{
	return &m_Inspection;
}

void CCaptureManager::SetOptionFilePath(const TCHAR* pszFilePath)
{
	if (NULL == pszFilePath)
		return;
	m_szOptionFilePath = pszFilePath;
}

const TCHAR* CCaptureManager::GetOptionFilePath()
{
	return (LPCTSTR)m_szOptionFilePath;
}

const INFO_OPTION* CCaptureManager::GetOption()
{
	return &m_stOption;
}

void CCaptureManager::UpdateOption(const INFO_OPTION* pstOpt)
{
	if (NULL == pstOpt)
		return;
	memcpy(&m_stOption, pstOpt, sizeof(INFO_OPTION));
}

const INFO_OPTIONETC* CCaptureManager::GetOptionEtc()
{
	return &m_stOptionEtc;
}

void CCaptureManager::UpdateOptionEtc(const INFO_OPTIONETC* pstOptEtc)
{
	if (NULL == pstOptEtc)
		return;

	memcpy(&m_stOptionEtc, pstOptEtc, sizeof(INFO_OPTIONETC));
	m_Log.UpdateLogInformation(&m_stOptionEtc.m_stLogInfo);
	m_LogHeater.UpdateLogInformation(&m_stOptionEtc.m_stLogInfo);

	//
	CUtil::SetRegString(REG_ROOT_PATH, REG_VALUE_OPTION_LOTIDPATH,			(TCHAR*)pstOptEtc->m_szLotIdPath);
	CUtil::SetRegString(REG_ROOT_PATH, REG_VALUE_OPTION_LOGPATH,			(TCHAR*)pstOptEtc->m_stLogInfo.m_szLogPath);
	CUtil::SetRegDword(REG_ROOT_PATH, REG_VALUE_OPTION_SAVETEXT,			pstOptEtc->m_stLogInfo.m_bSaveTextLog);
	CUtil::SetRegDword(REG_ROOT_PATH, REG_VALUE_OPTION_SAVEERRORIMAGE,		pstOptEtc->m_stLogInfo.m_bSaveErrorImage);
	CUtil::SetRegDword(REG_ROOT_PATH, REG_VALUE_OPTION_SAVEPROBIMAGE,		pstOptEtc->m_stLogInfo.m_bSaveProbImage);
	CUtil::SetRegDword(REG_ROOT_PATH, REG_VALUE_OPTION_SAVEOKIMAGE,			pstOptEtc->m_stLogInfo.m_bSaveOKImage);
	CUtil::SetRegString(REG_ROOT_PATH, REG_VALUE_OPTION_SAVEIMAGEFORMAT,	(TCHAR*)pstOptEtc->m_stLogInfo.m_szSaveImageFormat);
	CUtil::SetRegDword(REG_ROOT_PATH, REG_VALUE_OPTION_IMAGECOUNT,			pstOptEtc->m_stLogInfo.m_nUserSetCount);
	// Version 1.3.7.6 Save OK Image Period
	CUtil::SetRegDword(REG_ROOT_PATH, REG_VALUE_OPTION_PERIOD_CHECK,		pstOptEtc->m_stLogInfo.m_bSaveOKImage_Period);
	CUtil::SetRegDword(REG_ROOT_PATH, REG_VALUE_OPTION_PERIOD_TIME,			pstOptEtc->m_stLogInfo.m_nSavePeriodTime);

}

const INFO_SCENARIO* CCaptureManager::GetScenario()
{
	return &m_stScenario;
}

const INFO_STROBE* CCaptureManager::GetCurrentStrobeInfo()
{
	return &m_stStrobe;
}



INFO_SUMMARY* CCaptureManager::GetResultSummary()
{
	return &m_stResultSummary;
}

void CCaptureManager::UpdateSummary(TYPE_CAMERAPOS eCameraPos, CSampleSide* pSample)
{
	if (NULL == pSample)
		return;

	if (TYPE_CAMERAPOS_FIRST == eCameraPos){
		UpdateSummarySampleSide(eCameraPos, pSample, m_stResultSummary.m_stSummaryFirst);
		m_SummaryFirstQueue.push(m_stResultSummary.m_stSummaryFirst.m_stTotalFlag);
	}
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos){
		UpdateSummarySampleSide(eCameraPos, pSample, m_stResultSummary.m_stSummarySecond);
		if (!m_SummaryFirstQueue.empty()) {
				INFO_SUMMARY_TOTAL_FLAG stFirstSummayResult = m_SummaryFirstQueue.front(); m_SummaryFirstQueue.pop();
				UpdateTotalSummary(stFirstSummayResult, m_stResultSummary.m_stSummarySecond.m_stTotalFlag, m_stResultSummary.m_stSummaryTotal);
				m_stResultSummary.m_stSummaryTotal.first_queue_size = m_SummaryFirstQueue.size();	//디버그용
		}
	}
}

void CCaptureManager::ClearSummaryQueue()
{
	while (!m_SummaryFirstQueue.empty())
	{
		m_SummaryFirstQueue.pop();
	}

	// Print Log, nepesdlg에서 로그 생성
	//INFO_LOGFUNC stLogFunc = this->m_Log.GetLogInterface();
	//if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
	//	stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Sample extraction");
}

void CCaptureManager::UpdateTotalSummary(INFO_SUMMARY_TOTAL_FLAG stFirstSummayResult, INFO_SUMMARY_TOTAL_FLAG stsecondSummayResult, INFO_SUMMARY_TOTAL& stSummatyTotal)
{
	stSummatyTotal.m_nSampleCount++;

	stSummatyTotal.ErrorSize = false;
	stSummatyTotal.ShapeSize = false;

	if (stFirstSummayResult.m_bSizeResult == FALSE || stsecondSummayResult.m_bSizeResult == FALSE){
		stSummatyTotal.m_nSampleCountErrorSize++;
		stSummatyTotal.ErrorSize = true;
	}
	else if (stFirstSummayResult.m_bShapeResult == FALSE || stsecondSummayResult.m_bShapeResult == FALSE){
		stSummatyTotal.m_nSampleCountErrorShape++;
		stSummatyTotal.ShapeSize = true;
	}
	stSummatyTotal.m_fSampleRatioErrorSize = ((double)stSummatyTotal.m_nSampleCountErrorSize / (double)stSummatyTotal.m_nSampleCount) * 100.0f;
	stSummatyTotal.m_fSampleRatioErrorShape = ((double)stSummatyTotal.m_nSampleCountErrorShape / (double)stSummatyTotal.m_nSampleCount) * 100.0f;
}

const int CCaptureManager::GetResultSummaryCount()
{
	const INFO_SUMMARY* pstSummary = CCaptureManager::GetResultSummary();
	return pstSummary->m_nTotalCount;
}

const int CCaptureManager::AddSampleCount()
{
	INFO_SUMMARY* pstSummary = CCaptureManager::GetResultSummary();
	pstSummary->m_nTotalCount++;
	return pstSummary->m_nTotalCount;
}

// Version 1.3.8.0 Resin Count Add (First)
void CCaptureManager::UpdateSummarySampleSide(TYPE_CAMERAPOS eCameraPos, CSampleSide* pSample, INFO_SUMMARY_SAMPLE& stSampleSummary)
{
	if (NULL == pSample)
		return;

	const INFO_OPTION* pstOption = this->GetOption();
	const INFO_OPT_INSPECTSTEP *pstOptInspect = NULL;
	if (TYPE_CAMERAPOS_FIRST == eCameraPos)
		pstOptInspect = &pstOption->m_stFirstCameraStep;
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
		pstOptInspect = &pstOption->m_stSecondCameraStep;
	
	if (NULL == pstOptInspect)
		return;

	// Total Error Count - Sample
	stSampleSummary.m_nSampleCount++;
	
	// Result - Size
	BOOL bSizeResult = TRUE;
	stSampleSummary.m_stTotalFlag.m_bSizeResult = TRUE;

	// First Capture & Second Capture
	if (pstOptInspect->m_bStep001)
	{
		BOOL bFirstSize = FALSE;

		for (int i = 0; i < TYPE_GEOMETRY_DISTANCE_MAX; i++)
		{
			bFirstSize = pSample->m_SizeCalculationResult.m_stDistance[i].m_bOK;
			//pSample->m_SizeCalculationResult.m_stDistance[i].m_dValue;

			if (FALSE == bFirstSize)
			{
				stSampleSummary.m_pListErrorSize[i]++;
				bSizeResult = FALSE;
			}
		}
		if (FALSE == bSizeResult)
		{
			stSampleSummary.m_nSampleCountErrorSize++;
			stSampleSummary.m_stTotalFlag.m_bSizeResult = FALSE;
		}

		//stSampleSummary.m_fSampleRatioErrorSize = ((double)stSampleSummary.m_nSampleCountErrorSize / (double)stSampleSummary.m_nSampleCount) * 100.0f;
	}

	stSampleSummary.m_fSampleRatioErrorSize = ((double)stSampleSummary.m_nSampleCountErrorSize / (double)stSampleSummary.m_nSampleCount) * 100.0f;

	BOOL bStain = TRUE;
	BOOL bDiffer = TRUE;
	BOOL bBubble = TRUE;
	BOOL bScratch = TRUE;
	BOOL bStamp = TRUE;
	stSampleSummary.m_stTotalFlag.m_bShapeResult = TRUE;

	if (pstOptInspect->m_bStep002 && FALSE == pSample->m_StainResult.m_bResult)
		bStain = FALSE;
	if (pstOptInspect->m_bStep003 && FALSE == pSample->m_DifferResult.m_bResult)
		bDiffer = FALSE;
	if (pstOptInspect->m_bStep004 && FALSE == pSample->m_BubbleResult.m_bResult)
		bBubble = FALSE;
	if (pstOptInspect->m_bStep005 && FALSE == pSample->m_ScratchResult.m_bResult)
		bScratch = FALSE;
	if (pstOptInspect->m_bStep006 && FALSE == pSample->m_StampResult.m_bResult)
		bStamp = FALSE;

	// Result - Summary
	if (FALSE == bStain)
		stSampleSummary.m_pListErrorShape[TYPE_STEP_002]++;
	if (FALSE == bDiffer)
		stSampleSummary.m_pListErrorShape[TYPE_STEP_003]++;
	if (FALSE == bBubble)
		stSampleSummary.m_pListErrorShape[TYPE_STEP_004]++;
	if (FALSE == bScratch)
		stSampleSummary.m_pListErrorShape[TYPE_STEP_005]++;
	if (FALSE == bStamp)
		stSampleSummary.m_pListErrorShape[TYPE_STEP_006]++;

	if (FALSE == bStain || FALSE == bDiffer || FALSE == bBubble || FALSE == bScratch || FALSE == bStamp)
	{
		stSampleSummary.m_nSampleCountErrorShape++;
		stSampleSummary.m_stTotalFlag.m_bShapeResult = FALSE;
	}

	stSampleSummary.m_fSampleRatioErrorShape = ((double)stSampleSummary.m_nSampleCountErrorShape / (double)stSampleSummary.m_nSampleCount) * 100.0f;


	// Total
	{
		// Total Error Count & Radio
		if (FALSE == bSizeResult || (FALSE == bStain || FALSE == bDiffer || FALSE == bBubble || FALSE == bScratch || FALSE == bStamp))
		{
			stSampleSummary.m_nSampleCountError++;
		}
		stSampleSummary.m_fSampleRatioError = ((double)stSampleSummary.m_nSampleCountError / (double)stSampleSummary.m_nSampleCount) * 100.0f;
	}
}


void CCaptureManager::SendStrobeCommand(CSerialCtrl* pSerialCtrl, BYTE* pCommand, int nCmdLen, BYTE* pResponse, int& nResLen)
{
	DWORD dwRes = 0;
	
	BOOL bResult = pSerialCtrl->Write(pCommand, nCmdLen, &dwRes);
	if (bResult)
	{
		bResult = pSerialCtrl->Read(pResponse, MAX_NAME_LEN, &dwRes);
		if (bResult)
			nResLen = dwRes;
		else
			nResLen = -1;
	}
	else
	{
		nResLen = -1;
	}
}


void CCaptureManager::ComposeCommandSetStrobeOnAllChannel(BYTE* pCmd, int& nCmdLen, BOOL bOn)
{
	if (NULL == pCmd)
		return;

	int idx = 0;

	// Head
	pCmd[idx] = 0x02;			idx++;

	// Body - Command
	pCmd[idx] = '9';			idx++;
	pCmd[idx] = '9';			idx++;
	pCmd[idx] = 'O';			idx++;
	pCmd[idx] = 'N';			idx++;

	// Body - Value
	{
		if (bOn)	pCmd[idx] = '1';
		else		pCmd[idx] = '0';
	}
	idx++;


	// Tail
	pCmd[idx] = 0x03;			idx++;

	nCmdLen = idx;
}

void CCaptureManager::ComposeCommandSetStrobeOn(BYTE* pCmd, int& nCmdLen, int nCh, BOOL bOn)
{
	if (NULL == pCmd)
		return;
	int idx = 0;
		
//#ifdef DEF_OLD_STROBE
	if (m_eStrobeControllerType == TYPE_STROBETYPE_A)
	{
		char szChannel[16] = { 0, };
		sprintf(szChannel, "%02d", nCh);

		// Head
		pCmd[idx] = 0x02;			idx++;

		// Body - Command
		pCmd[idx] = 'C';			idx++;
		pCmd[idx] = 'H';			idx++;
		pCmd[idx] = szChannel[0];	idx++;
		pCmd[idx] = szChannel[1];	idx++;
		pCmd[idx] = 'O';			idx++;

		// Body - Value
		{
			if (bOn)	pCmd[idx] = '1';
			else		pCmd[idx] = '0';
		}
		idx++;

		// Tail
		pCmd[idx] = 0x03;			idx++;
	}
//#else
	else if (m_eStrobeControllerType == TYPE_STROBETYPE_B)
	{
		// Head
		pCmd[idx] = 0x01;			idx++;

		// Body - Command
		pCmd[idx] = 0x00;			idx++;
		pCmd[idx] = 0x02;			idx++;
		pCmd[idx] = 0x34;			idx++;

		// Body - Value
		switch (nCh)
		{
		case FIRST_STROBE_CH_BAR:
			pCmd[idx] = 0x00;			idx++;	//ch16~9
			pCmd[idx] = 0x01;			idx++;	//ch8~1
			break;
		case FIRST_STROBE_CH_COAX:
			pCmd[idx] = 0x00;			idx++;	//ch16~9
			pCmd[idx] = 0x02;			idx++;	//ch8~1
			break;
		case FIRST_STROBE_CH_RING_1CH:
			pCmd[idx] = 0x00;			idx++;	//ch16~9
			pCmd[idx] = 0x08;			idx++;	//ch8~1
			break;
		case SECOND_STROBE_CH_BAR:
			pCmd[idx] = 0x01;			idx++;	//ch16~9
			pCmd[idx] = 0x00;			idx++;	//ch8~1
			break;
		case SECOND_STROBE_CH_COAX:
			pCmd[idx] = 0x02;			idx++;	//ch16~9
			pCmd[idx] = 0x00;			idx++;	//ch8~1
			break;
		case SECOND_STROBE_CH_RING_1CH:
			pCmd[idx] = 0x08;			idx++;	//ch16~9
			pCmd[idx] = 0x00;			idx++;	//ch8~1
			break;
		default:
			//pCmd[idx] = 0x00;			idx++;	//ch16~9
			//pCmd[idx] = 0x00;			idx++;	//ch8~1
			break;
		}

		// Tail
		pCmd[idx] = 0x04;			idx++;
	}
//#endif 

	nCmdLen = idx;
}

void CCaptureManager::ComposeCommandSetStrobeOn_new(BYTE* pCmd, int& nCmdLen, int nCh, BOOL bOn)
{
	if (NULL == pCmd)
		return;

	int idx = 0;

	// Head
	pCmd[idx] = 0x01;			idx++;

	// Body - Command
	pCmd[idx] = 0x00;			idx++;
	pCmd[idx] = 0x02;			idx++;
	pCmd[idx] = 0x34;			idx++;

	// Body - Value
	switch (nCh)
	{
		case FIRST_STROBE_CH_BAR:
			pCmd[idx] = 0x00;			idx++;	//ch16~9
			pCmd[idx] = 0x01;			idx++;	//ch8~1
			break;
		case FIRST_STROBE_CH_COAX:
			pCmd[idx] = 0x00;			idx++;	//ch16~9
			pCmd[idx] = 0x02;			idx++;	//ch8~1
			break;
		case FIRST_STROBE_CH_RING_1CH:
			pCmd[idx] = 0x00;			idx++;	//ch16~9
			pCmd[idx] = 0x08;			idx++;	//ch8~1
			break;
		case SECOND_STROBE_CH_BAR:
			pCmd[idx] = 0x01;			idx++;	//ch16~9
			pCmd[idx] = 0x00;			idx++;	//ch8~1
			break;
		case SECOND_STROBE_CH_COAX:
			pCmd[idx] = 0x02;			idx++;	//ch16~9
			pCmd[idx] = 0x00;			idx++;	//ch8~1
			break;
		case SECOND_STROBE_CH_RING_1CH:
			pCmd[idx] = 0x08;			idx++;	//ch16~9
			pCmd[idx] = 0x00;			idx++;	//ch8~1
			break;
		default:
			//pCmd[idx] = 0x00;			idx++;	//ch16~9
			//pCmd[idx] = 0x00;			idx++;	//ch8~1
			break;
	}

	// Tail
	pCmd[idx] = 0x04;			idx++;

	nCmdLen = idx;
}

void CCaptureManager::ComposeCommandSetStrobeBrightness(BYTE* pCmd, int& nCmdLen, int nCh, int nValue)
{
	if (NULL == pCmd)
		return;
	int idx = 0;

//#ifdef DEF_OLD_STROBE
	if (m_eStrobeControllerType == TYPE_STROBETYPE_A)
	{
		char szChannel[16] = { 0, };
		sprintf(szChannel, "%02d", nCh);

		char szValue[16] = { 0, };
		sprintf(szValue, "%03d", nValue);

		// Head
		pCmd[idx] = 0x02;			idx++;

		// Body - Command
		pCmd[idx] = 'C';			idx++;
		pCmd[idx] = 'H';			idx++;
		pCmd[idx] = szChannel[0];	idx++;
		pCmd[idx] = szChannel[1];	idx++;
		pCmd[idx] = 'S';			idx++;

		// Body - Value
		pCmd[idx] = szValue[0];		idx++;
		pCmd[idx] = szValue[1];		idx++;
		pCmd[idx] = szValue[2];		idx++;

		// Tail
		pCmd[idx] = 0x03;			idx++;
	}
//#else
	else if (m_eStrobeControllerType == TYPE_STROBETYPE_B)
	{
		// Head
		pCmd[idx] = 0x01;			idx++;

		// Body - Command
		pCmd[idx] = 0x00;			idx++;
		pCmd[idx] = 0x03;			idx++;
		pCmd[idx] = 0x21;			idx++;
		switch (nCh)
		{
		case FIRST_STROBE_CH_BAR:
			pCmd[idx] = 0x00;			idx++;	//ch16~9
			pCmd[idx] = 0x01;			idx++;	//ch8~1
			break;
		case FIRST_STROBE_CH_COAX:
			pCmd[idx] = 0x00;			idx++;	//ch16~9
			pCmd[idx] = 0x02;			idx++;	//ch8~1
			break;
		case FIRST_STROBE_CH_RING_1CH:
			pCmd[idx] = 0x00;			idx++;	//ch16~9
			pCmd[idx] = 0x08;			idx++;	//ch8~1
			break;
		case SECOND_STROBE_CH_BAR:
			pCmd[idx] = 0x01;			idx++;	//ch16~9
			pCmd[idx] = 0x00;			idx++;	//ch8~1
			break;
		case SECOND_STROBE_CH_COAX:
			pCmd[idx] = 0x02;			idx++;	//ch16~9
			pCmd[idx] = 0x00;			idx++;	//ch8~1
			break;
		case SECOND_STROBE_CH_RING_1CH:
			pCmd[idx] = 0x08;			idx++;	//ch16~9
			pCmd[idx] = 0x00;			idx++;	//ch8~1
			break;
		default:
			pCmd[idx] = 0x00;			idx++;	//ch16~9
			pCmd[idx] = 0x00;			idx++;	//ch8~1
			break;
		}

		// Body - Value
		pCmd[idx] = nValue;			idx++;

		// Tail
		pCmd[idx] = 0x04;			idx++;
	}
//#endif

	nCmdLen = idx;
}

//안씀
void CCaptureManager::ComposeCommandSetStrobeBrightness_new(BYTE* pCmd, int& nCmdLen, int nCh, int nValue)
{
	if (NULL == pCmd)
		return;
	int idx = 0;

	// Head
	pCmd[idx] = 0x01;			idx++;

	// Body - Command
	pCmd[idx] = 0x00;			idx++;
	pCmd[idx] = 0x03;			idx++;
	pCmd[idx] = 0x21;			idx++;
	switch (nCh)
	{
		case FIRST_STROBE_CH_BAR:
			pCmd[idx] = 0x00;			idx++;	//ch16~9
			pCmd[idx] = 0x01;			idx++;	//ch8~1
			break;
		case FIRST_STROBE_CH_COAX:
			pCmd[idx] = 0x00;			idx++;	//ch16~9
			pCmd[idx] = 0x02;			idx++;	//ch8~1
			break;
		case FIRST_STROBE_CH_RING_1CH:
			pCmd[idx] = 0x00;			idx++;	//ch16~9
			pCmd[idx] = 0x08;			idx++;	//ch8~1
			break;
		case SECOND_STROBE_CH_BAR:
			pCmd[idx] = 0x01;			idx++;	//ch16~9
			pCmd[idx] = 0x00;			idx++;	//ch8~1
			break;
		case SECOND_STROBE_CH_COAX:
			pCmd[idx] = 0x02;			idx++;	//ch16~9
			pCmd[idx] = 0x00;			idx++;	//ch8~1
			break;
		case SECOND_STROBE_CH_RING_1CH:
			pCmd[idx] = 0x08;			idx++;	//ch16~9
			pCmd[idx] = 0x00;			idx++;	//ch8~1
			break;
		default:
			pCmd[idx] = 0x00;			idx++;	//ch16~9
			pCmd[idx] = 0x00;			idx++;	//ch8~1
			break;
	}

	// Body - Value
	pCmd[idx] = nValue;			idx++;

	// Tail
	pCmd[idx] = 0x04;			idx++;

	nCmdLen = idx;
}

void CCaptureManager::ComposeCommandGetStrobeBrightness(BYTE* pCmd, int& nCmdLen, int nCh)
{
	if (NULL == pCmd)
		return;
	int idx = 0;

//#ifdef DEF_OLD_STROBE
	if (m_eStrobeControllerType == TYPE_STROBETYPE_A)
	{
		char szChannel[16] = { 0, };
		sprintf(szChannel, "%02d", nCh);

		// Head
		pCmd[idx] = 0x02;			idx++;

		// Body - Command
		pCmd[idx] = 'C';			idx++;
		pCmd[idx] = 'H';			idx++;
		pCmd[idx] = szChannel[0];	idx++;
		pCmd[idx] = szChannel[1];	idx++;
		pCmd[idx] = 'R';			idx++;

		// Body - Value (not)

		// Tail
		pCmd[idx] = 0x03;			idx++;
}
//#else
	else if (m_eStrobeControllerType == TYPE_STROBETYPE_B)
	{
		// Head
		pCmd[idx] = 0x01;			idx++;

		// Body - Command
		pCmd[idx] = 0x01;			idx++; //Read OP Code 0x01
		pCmd[idx] = 0x00;			idx++; //Data Length
		pCmd[idx] = 0x21;			idx++; //Register Address
		// Body - Value (not)

		// Tail
		pCmd[idx] = 0x04;			idx++;
	}
//#endif

	nCmdLen = idx;
}

//안씀
void CCaptureManager::ComposeCommandGetStrobeBrightness_new(BYTE* pCmd, int& nCmdLen, int nCh)
{
	if (NULL == pCmd)
		return;
	int idx = 0;

	// Head
	pCmd[idx] = 0x01;			idx++;

	// Body - Command
	pCmd[idx] = 0x01;			idx++; //Read OP Code 0x01
	pCmd[idx] = 0x00;			idx++; //Data Length
	pCmd[idx] = 0x21;			idx++; //Register Address
	// Body - Value (not)

	// Tail
	pCmd[idx] = 0x04;			idx++;

	nCmdLen = idx;
}

void CCaptureManager::ComposeCommandSetStrobeBrightness(BYTE* pCmd, int& nCmdLen, int nBrightness_FC, int nBrightness_FR, int nBrightness_FB,
	int nBrightness_SC, int nBrightness_SR, int nBrightness_SB)
{
	if (NULL == pCmd)
		return;
	int idx = 0;

	if (m_eStrobeControllerType == TYPE_STROBETYPE_A){
//#ifdef DEF_OLD_STROBE

		char szValue_FC[16] = { 0, };
		sprintf(szValue_FC, "%03d", nBrightness_FC);
		char szValue_FR[16] = { 0, };
		sprintf(szValue_FR, "%03d", nBrightness_FR);
		char szValue_FB[16] = { 0, };
		sprintf(szValue_FB, "%03d", nBrightness_FB);
		char szValue_SC[16] = { 0, };
		sprintf(szValue_SC, "%03d", nBrightness_SC);
		char szValue_SR[16] = { 0, };
		sprintf(szValue_SR, "%03d", nBrightness_SR);
		char szValue_SB[16] = { 0, };
		sprintf(szValue_SB, "%03d", nBrightness_SB);

		// Head
		pCmd[idx] = 0x02;			idx++;

		// Body - Command
		pCmd[idx] = 'C';			idx++;
		pCmd[idx] = 'A';			idx++;
		pCmd[idx] = 'L';			idx++;
		pCmd[idx] = 'L';			idx++;
		pCmd[idx] = 'S';			idx++;

		// Body - Value
		for (int i = 1; i <= MAX_STROBE_CH; i++){
			switch (i){
			case FIRST_STROBE_CH_BAR:
				pCmd[idx] = szValue_FB[0];		idx++;
				pCmd[idx] = szValue_FB[1];		idx++;
				pCmd[idx] = szValue_FB[2];		idx++;
				break;
			case FIRST_STROBE_CH_COAX:
				pCmd[idx] = szValue_FC[0];		idx++;
				pCmd[idx] = szValue_FC[1];		idx++;
				pCmd[idx] = szValue_FC[2];		idx++;
				break;
			case FIRST_STROBE_CH_RING_1CH:
				pCmd[idx] = szValue_FR[0];		idx++;
				pCmd[idx] = szValue_FR[1];		idx++;
				pCmd[idx] = szValue_FR[2];		idx++;
				break;
			case SECOND_STROBE_CH_BAR:
				pCmd[idx] = szValue_SB[0];		idx++;
				pCmd[idx] = szValue_SB[1];		idx++;
				pCmd[idx] = szValue_SB[2];		idx++;
				break;
			case SECOND_STROBE_CH_COAX:
				pCmd[idx] = szValue_SC[0];		idx++;
				pCmd[idx] = szValue_SC[1];		idx++;
				pCmd[idx] = szValue_SC[2];		idx++;
				break;
			case SECOND_STROBE_CH_RING_1CH:
				pCmd[idx] = szValue_SR[0];		idx++;
				pCmd[idx] = szValue_SR[1];		idx++;
				pCmd[idx] = szValue_SR[2];		idx++;
				break;
			default:
				pCmd[idx] = '0';				idx++;
				pCmd[idx] = '0';				idx++;
				pCmd[idx] = '0';				idx++;
				break;
			}
		}

		// Tail
		pCmd[idx] = 0x03;			idx++;

//#else
	}
	else if (m_eStrobeControllerType == TYPE_STROBETYPE_B){
		// Head
		pCmd[idx] = 0x01;			idx++;
		// Body - Command
		pCmd[idx] = 0x00;			idx++;
		pCmd[idx] = 0x10;			idx++;
		pCmd[idx] = 0x29;			idx++;
		// Body - Value

		for (int i = 1; i <= MAX_STROBE_CH; i++){
			switch (i){
			case FIRST_STROBE_CH_BAR:
				pCmd[idx] = nBrightness_FB;		idx++;
				break;
			case FIRST_STROBE_CH_COAX:
				pCmd[idx] = nBrightness_FC;		idx++;
				break;
			case FIRST_STROBE_CH_RING_1CH:
				pCmd[idx] = nBrightness_FR;		idx++;
				break;
			case SECOND_STROBE_CH_BAR:
				pCmd[idx] = nBrightness_SB;		idx++;
				break;
			case SECOND_STROBE_CH_COAX:
				pCmd[idx] = nBrightness_SC;		idx++;
				break;
			case SECOND_STROBE_CH_RING_1CH:
				pCmd[idx] = nBrightness_SR;		idx++;
				break;
			default:
				pCmd[idx] = 0x00;				idx++;
				break;
			}
		}
		// Tail
		pCmd[idx] = 0x04;			idx++;
	}
//#endif

	nCmdLen = idx;
}

//안씀
void CCaptureManager::ComposeCommandSetStrobeBrightness_new(BYTE* pCmd, int& nCmdLen, int nBrightness_FC, int nBrightness_FR, int nBrightness_FB,
	int nBrightness_SC, int nBrightness_SR, int nBrightness_SB)
{
	if (NULL == pCmd)
		return;
	int idx = 0;

	// Head
	pCmd[idx] = 0x01;			idx++;
	// Body - Command
	pCmd[idx] = 0x00;			idx++;
	pCmd[idx] = 0x10;			idx++;
	pCmd[idx] = 0x29;			idx++;
	// Body - Value

	for (int i = 1; i <= MAX_STROBE_CH; i++){
		switch (i){
		case FIRST_STROBE_CH_BAR:
			pCmd[idx] = nBrightness_FB;		idx++;
			break;
		case FIRST_STROBE_CH_COAX:
			pCmd[idx] = nBrightness_FC;		idx++;
			break;
		case FIRST_STROBE_CH_RING_1CH:
			pCmd[idx] = nBrightness_FR;		idx++;
			break;
		case SECOND_STROBE_CH_BAR:
			pCmd[idx] = nBrightness_SB;		idx++;
			break;
		case SECOND_STROBE_CH_COAX:
			pCmd[idx] = nBrightness_SC;		idx++;
			break;
		case SECOND_STROBE_CH_RING_1CH:
			pCmd[idx] = nBrightness_SR;		idx++;
			break;
		default:
			pCmd[idx] = 0x00;				idx++;
			break;
		}
	}
	// Tail
	pCmd[idx] = 0x04;			idx++;

	nCmdLen = idx;
}

int CCaptureManager::ParseCommandGetStrobeBrightness(const BYTE* pRes, const int nResLen, const int nCh)
{
	if (NULL == pRes || 10 > nResLen)
		return -1;
	int idx = 0;
	int nValue = 0;

//#ifdef DEF_OLD_STROBE
	if (m_eStrobeControllerType == TYPE_STROBETYPE_A)
	{
		TCHAR szValue[5] = { 0, };

		// Head
		pRes[idx];	idx++;		// 0x02

		// Body - Command
		pRes[idx];	idx++;		//'C'
		pRes[idx];	idx++;		//'H'
		pRes[idx];	idx++;		// Channel string
		pRes[idx];	idx++;		// Channel String
		pRes[idx];	idx++;		//'R'

		// Body - Value
		szValue[0] = pRes[idx];		idx++;
		szValue[1] = pRes[idx];		idx++;
		szValue[2] = pRes[idx];		idx++;

		// Tail
		pRes[idx];	idx++;		// 0x03

		nValue = CUtil::StringToInt(szValue, CUtil::StringLength(szValue));
	}
//#else 
	else if (m_eStrobeControllerType == TYPE_STROBETYPE_B)
	{
		int nCHValue[17] = { 0, };

		// Head
		pRes[idx];	idx++;		// 0x01

		// Body - Command
		pRes[idx];	idx++;		// 0x01
		pRes[idx];	idx++;		// 0x10
		pRes[idx];	idx++;		// 0x21

		// Body - Value
		nCHValue[1] = pRes[idx];		idx++;	//ch1 first bar
		nCHValue[2] = pRes[idx];		idx++;	//ch2 first coax
		nCHValue[3] = pRes[idx];		idx++;
		nCHValue[4] = pRes[idx];		idx++;	//ch4 first ring
		nCHValue[5] = pRes[idx];		idx++;
		nCHValue[6] = pRes[idx];		idx++;
		nCHValue[7] = pRes[idx];		idx++;
		nCHValue[8] = pRes[idx];		idx++;
		nCHValue[9] = pRes[idx];		idx++;	//ch9 second bar
		nCHValue[10] = pRes[idx];		idx++;  //ch10 second coax
		nCHValue[11] = pRes[idx];		idx++;
		nCHValue[12] = pRes[idx];		idx++;  //ch12 second ring
		nCHValue[13] = pRes[idx];		idx++;
		nCHValue[14] = pRes[idx];		idx++;
		nCHValue[15] = pRes[idx];		idx++;
		nCHValue[16] = pRes[idx];		idx++;

		// Tail
		nCHValue[0] = pRes[idx];	idx++;		// 0x04

		switch (nCh)
		{
		case FIRST_STROBE_CH_BAR:
			nValue = nCHValue[1];
			break;
		case FIRST_STROBE_CH_COAX:
			nValue = nCHValue[2];
			break;
		case FIRST_STROBE_CH_RING_1CH:
			nValue = nCHValue[4];
			break;
		case SECOND_STROBE_CH_BAR:
			nValue = nCHValue[9];
			break;
		case SECOND_STROBE_CH_COAX:
			nValue = nCHValue[10];
			break;
		case SECOND_STROBE_CH_RING_1CH:
			nValue = nCHValue[12];
			break;
		default:
			break;
		}
	}
//#endif 

	return nValue;
}

//안씀
int CCaptureManager::ParseCommandGetStrobeBrightness_new(const BYTE* pRes, const int nResLen, const int nCh)
{
	if (NULL == pRes || 10 > nResLen)
		return -1;

	int nCHValue[17] = { 0, };

	int idx = 0;
	// Head
	pRes[idx];	idx++;		// 0x01

	// Body - Command
	pRes[idx];	idx++;		// 0x01
	pRes[idx];	idx++;		// 0x10
	pRes[idx];	idx++;		// 0x21

	// Body - Value
	nCHValue[1] = pRes[idx];		idx++;	//ch1 first bar
	nCHValue[2] = pRes[idx];		idx++;	//ch2 first coax
	nCHValue[3] = pRes[idx];		idx++;
	nCHValue[4] = pRes[idx];		idx++;	//ch4 first ring
	nCHValue[5] = pRes[idx];		idx++;
	nCHValue[6] = pRes[idx];		idx++;
	nCHValue[7] = pRes[idx];		idx++;
	nCHValue[8] = pRes[idx];		idx++;
	nCHValue[9] = pRes[idx];		idx++;	//ch9 second bar
	nCHValue[10] = pRes[idx];		idx++;  //ch10 second coax
	nCHValue[11] = pRes[idx];		idx++;
	nCHValue[12] = pRes[idx];		idx++;  //ch12 second ring
	nCHValue[13] = pRes[idx];		idx++;
	nCHValue[14] = pRes[idx];		idx++;
	nCHValue[15] = pRes[idx];		idx++;
	nCHValue[16] = pRes[idx];		idx++;

	// Tail
	nCHValue[0] = pRes[idx];	idx++;		// 0x04

	int nValue = 0;

	switch (nCh)
	{
	case FIRST_STROBE_CH_BAR:
		nValue = nCHValue[1];
		break;
	case FIRST_STROBE_CH_COAX:
		nValue = nCHValue[2];
		break;
	case FIRST_STROBE_CH_RING_1CH:
		nValue = nCHValue[4];
		break;
	case SECOND_STROBE_CH_BAR:
		nValue = nCHValue[9];
		break;
	case SECOND_STROBE_CH_COAX:
		nValue = nCHValue[10];
		break;
	case SECOND_STROBE_CH_RING_1CH:
		nValue = nCHValue[12];
		break;
	default:
		break;
	}

	return nValue;
}

BOOL CCaptureManager::UpdateInspection(TYPE_CAMERAPOS ePos, const TCHAR* pszFilePath, const INFO_INSPECTION* pstInsection)
{
	if (TYPE_CAMERAPOS_FIRST == ePos)
	{
		if (pszFilePath)
		{
			CUtil::StringCopy(m_stScenario.m_szFirstFilePath, pszFilePath);
		}
		if (pstInsection)
		{
			m_stScenario.m_stFirstInspection = *pstInsection;
			m_stScenario.m_stFirstInspection.m_stSizeCalc.m_stCalibration = m_stScenario.m_stFirstInspection.m_stSize.m_stCalibration;
		}
	}
	else if (TYPE_CAMERAPOS_SECOND == ePos)
	{
		if (pszFilePath)
		{
			CUtil::StringCopy(m_stScenario.m_szSecondFilePath, pszFilePath);
		}
		if (pstInsection)
		{
			m_stScenario.m_stSecondInspection = *pstInsection;
			m_stScenario.m_stFirstInspection.m_stSizeCalc.m_stCalibration = m_stScenario.m_stFirstInspection.m_stSize.m_stCalibration;
		}
	}
	else
	{
		return FALSE;
	}
	return TRUE;
}

const TCHAR* CCaptureManager::GetInspectionFilePath(TYPE_CAMERAPOS ePos)
{
	TCHAR* pszFilePath = NULL;

	if (TYPE_CAMERAPOS_FIRST == ePos)
		pszFilePath = m_stScenario.m_szFirstFilePath;
	else if (TYPE_CAMERAPOS_SECOND == ePos)
		pszFilePath = m_stScenario.m_szSecondFilePath;

	return pszFilePath;
}

const INFO_INSPECTION* CCaptureManager::GetInspectionInfo(TYPE_CAMERAPOS ePos)
{
	INFO_INSPECTION* pstInsection = NULL;

	if (TYPE_CAMERAPOS_FIRST == ePos)
		pstInsection = &m_stScenario.m_stFirstInspection;
	else if (TYPE_CAMERAPOS_SECOND == ePos)
		pstInsection = &m_stScenario.m_stSecondInspection;

	return pstInsection;
}


const TCHAR* CCaptureManager::GetTitleStep(TYPE_CAMERAPOS ePos, TYPE_STEP eStep)
{
	TCHAR* pszTitle = NULL;
	if (TYPE_CAMERAPOS_FIRST == ePos)
	{
		if(TYPE_STEP_001 == eStep)			pszTitle = m_stOption.m_stFirstCameraStep.m_szTitleStep01;
		else if (TYPE_STEP_002 == eStep)	pszTitle = m_stOption.m_stFirstCameraStep.m_szTitleStep02;
		else if (TYPE_STEP_003 == eStep)	pszTitle = m_stOption.m_stFirstCameraStep.m_szTitleStep03;
		else if (TYPE_STEP_004 == eStep)	pszTitle = m_stOption.m_stFirstCameraStep.m_szTitleStep04;
		else if (TYPE_STEP_005 == eStep)	pszTitle = m_stOption.m_stFirstCameraStep.m_szTitleStep05;
		else if (TYPE_STEP_006 == eStep)	pszTitle = m_stOption.m_stFirstCameraStep.m_szTitleStep06;
		else if (TYPE_STEP_007 == eStep)	pszTitle = m_stOption.m_stFirstCameraStep.m_szTitleStep01;
	}
	else if (TYPE_CAMERAPOS_SECOND == ePos)
	{
		if (TYPE_STEP_002 == eStep)			pszTitle = m_stOption.m_stSecondCameraStep.m_szTitleStep02;
		else if (TYPE_STEP_003 == eStep)	pszTitle = m_stOption.m_stSecondCameraStep.m_szTitleStep03;
		else if (TYPE_STEP_004 == eStep)	pszTitle = m_stOption.m_stSecondCameraStep.m_szTitleStep04;
		else if (TYPE_STEP_005 == eStep)	pszTitle = m_stOption.m_stSecondCameraStep.m_szTitleStep05;
		else if (TYPE_STEP_006 == eStep)	pszTitle = m_stOption.m_stSecondCameraStep.m_szTitleStep06;
#ifdef DEF_SECONDCAMERA_CHECKSIZE
		else if (TYPE_STEP_001 == eStep)	pszTitle = m_stOption.m_stFirstCameraStep.m_szTitleStep01;
		else if (TYPE_STEP_007 == eStep)	pszTitle = m_stOption.m_stFirstCameraStep.m_szTitleStep01;
#else
		else if (TYPE_STEP_001 == eStep)	pszTitle = m_stOption.m_stFirstCameraStep.m_szTitleStep01;
		else if (TYPE_STEP_007 == eStep)	pszTitle = m_stOption.m_stFirstCameraStep.m_szTitleStep01;
#endif

	}
	return pszTitle;
}

#ifdef USE_PLC_MXCOMPONENT
CString CCaptureManager::GetProgramExecutePath()
{
	TCHAR szTemp[300];
	::GetModuleFileName(NULL, szTemp, 300);
	CString path = szTemp;
	if (0 < path.ReverseFind('\\')) {
		path = path.Left(path.ReverseFind('\\'));
	}
	return path;
}

BOOL CCaptureManager::PLC_MXCOMPONENT_Module_Execution()
{
	CString strMxComponentExeFilePath = _T("");
	strMxComponentExeFilePath.Format(_T("%s\\%s"), GetProgramExecutePath(), LPMXCOMPONENT_EXE);
	::ShellExecute(NULL, "open", strMxComponentExeFilePath, NULL, NULL, SW_HIDE);

	return TRUE;
}

void CCaptureManager::LPMxComponentConfigSetting(int nPLCProtocolType, int nPLCControlType, int nStationNum, CString strHostAddress, int nPortNum)
{
	PDWORD_PTR pDw = NULL;

	stLPMXComponentCommnd stComponenetCommand;
	stComponenetCommand.nCommandType = TYPE_COMMAND_SETTING;
	stComponenetCommand.nPLCProtocolType = nPLCProtocolType;
	stComponenetCommand.nPLCControlType = nPLCControlType;
	memcpy(stComponenetCommand.szHostAddress, strHostAddress, strHostAddress.GetLength());
	stComponenetCommand.nPortNum = nPortNum;
	stComponenetCommand.nPLCStationNumber = nStationNum;

	COPYDATASTRUCT LPMxComponentDS;
	LPMxComponentDS.dwData = NULL;
	LPMxComponentDS.cbData = sizeof(stComponenetCommand);
	LPMxComponentDS.lpData = &stComponenetCommand;

	::SendMessage(m_hTargetMXComModuleWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)(LPVOID)&LPMxComponentDS);
	//::SendMessageTimeout(m_hTargetMXComModuleWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)(LPVOID)&m_LPMxComponentDS, SMTO_NORMAL, TIMEOUT_MS, pDw);
}

BOOL CCaptureManager::LPMxComOpenCommunication()
{
	PDWORD_PTR pDw = NULL;

	stLPMXComponentCommnd stComponenetCommand;
	stComponenetCommand.nCommandType = TYPE_COMMAND_OPENCOM;

	COPYDATASTRUCT LPMxComponentDS;
	LPMxComponentDS.dwData = NULL;
	LPMxComponentDS.cbData = sizeof(stComponenetCommand);
	LPMxComponentDS.lpData = &stComponenetCommand;

	::SendMessage(m_hTargetMXComModuleWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)(LPVOID)&LPMxComponentDS);
	//::SendMessageTimeout(m_hTargetMXComModuleWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)(LPVOID)&m_LPMxComponentDS, SMTO_NORMAL, TIMEOUT_MS, pDw);

	return TRUE;
}

BOOL CCaptureManager::LPMxComGetCpuType()
{
	PDWORD_PTR pDw = NULL;

	stLPMXComponentCommnd stComponenetCommand;
	stComponenetCommand.nCommandType = TYPE_COMMAND_GETCPUTYPE;

	COPYDATASTRUCT LPMxComponentDS;
	LPMxComponentDS.dwData = NULL;
	LPMxComponentDS.cbData = sizeof(stComponenetCommand);
	LPMxComponentDS.lpData = &stComponenetCommand;

	::SendMessage(m_hTargetMXComModuleWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)(LPVOID)&LPMxComponentDS);
	//::SendMessageTimeout(m_hTargetMXComModuleWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)(LPVOID)&m_LPMxComponentDS, SMTO_NORMAL, TIMEOUT_MS, pDw);

	return TRUE;
}

BOOL CCaptureManager::LPMxComGetDevice(CString strDeviceName)
{
	PDWORD_PTR pDw = NULL;

	stLPMXComponentCommnd stComponenetCommand;
	stComponenetCommand.nCommandType = TYPE_COMMAND_GETDEVICE;
	memcpy(stComponenetCommand.szDeviceName, strDeviceName, strDeviceName.GetLength());

	if (!strDeviceName.CompareNoCase(_T("W20")) || !strDeviceName.CompareNoCase(_T("W120")))
		stComponenetCommand.nCameraPos = TYPE_POS_FIRST;
	else if (!strDeviceName.CompareNoCase(_T("W30")) || !strDeviceName.CompareNoCase(_T("W130")))
		stComponenetCommand.nCameraPos = TYPE_POS_SECOND;
	else
		stComponenetCommand.nCameraPos = TYPE_POS_MAX; // 온도 기록은 TYPE_POS_MAX로 동작하도록 함

	COPYDATASTRUCT LPMxComponentDS;
	LPMxComponentDS.dwData = NULL;
	LPMxComponentDS.cbData = sizeof(stComponenetCommand);
	LPMxComponentDS.lpData = &stComponenetCommand;

	//::SendMessage(m_hTargetMXComModuleWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)(LPVOID)&m_LPMxComponentDS);
	::SendMessageTimeout(m_hTargetMXComModuleWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)(LPVOID)&LPMxComponentDS, SMTO_NORMAL, TIMEOUT_MS, pDw);

	return TRUE;
}

BOOL CCaptureManager::LPMxComSetDevice(CString strDeviceName, long lValue)
{
	PDWORD_PTR pDw = NULL;

	CString strLogData = _T("");
	strLogData.Format(_T("LPMxComSetDevice Name : %s, Value : %d \r\n"), strDeviceName, lValue);
	CUtil::PrintDebugString(strLogData);

	stLPMXComponentCommnd stComponenetCommand;
	stComponenetCommand.nCommandType = TYPE_COMMAND_SETDEVICE;
	memcpy(stComponenetCommand.szDeviceName, strDeviceName, strDeviceName.GetLength());
	stComponenetCommand.lSetValue = lValue;

	if (!strDeviceName.CompareNoCase(_T("W20")) || !strDeviceName.CompareNoCase(_T("W120")))
		stComponenetCommand.nCameraPos = TYPE_POS_FIRST;

	if (!strDeviceName.CompareNoCase(_T("W30")) || !strDeviceName.CompareNoCase(_T("W130")))
		stComponenetCommand.nCameraPos = TYPE_POS_SECOND;

	COPYDATASTRUCT LPMxComponentDS;
	LPMxComponentDS.dwData = NULL;
	LPMxComponentDS.cbData = sizeof(stComponenetCommand);
	LPMxComponentDS.lpData = &stComponenetCommand;


	//::SendMessage(m_hTargetMXComModuleWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)(LPVOID)&m_LPMxComponentDS);
	int nReturn = 0;
	nReturn = ::SendMessageTimeout(m_hTargetMXComModuleWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)(LPVOID)&LPMxComponentDS, SMTO_NORMAL, TIMEOUT_MS, pDw);
	if (nReturn == 0)
		return FALSE;

	return TRUE;
}

BOOL CCaptureManager::LPMXComCloseCommunication()
{
	PDWORD_PTR pDw = NULL;

	stLPMXComponentCommnd stComponenetCommand;
	stComponenetCommand.nCommandType = TYPE_COMMAND_CLOSECOM;

	COPYDATASTRUCT LPMxComponentDS;
	LPMxComponentDS.dwData = NULL;
	LPMxComponentDS.cbData = sizeof(stComponenetCommand);
	LPMxComponentDS.lpData = &stComponenetCommand;

	::SendMessage(m_hTargetMXComModuleWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)(LPVOID)&LPMxComponentDS);
	//::SendMessageTimeout(m_hTargetMXComModuleWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)(LPVOID)&m_LPMxComponentDS, SMTO_NORMAL, TIMEOUT_MS, pDw);

	return TRUE;
}

void CCaptureManager::LPMxComCloseProgram()
{
	PDWORD_PTR pDw = NULL;

	stLPMXComponentCommnd stComponenetCommand;
	stComponenetCommand.nCommandType = TYPE_COMMAND_CLOSEPROGRAM;

	COPYDATASTRUCT LPMxComponentDS;
	LPMxComponentDS.dwData = NULL;
	LPMxComponentDS.cbData = sizeof(stComponenetCommand);
	LPMxComponentDS.lpData = &stComponenetCommand;

	::SendMessage(m_hTargetMXComModuleWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)(LPVOID)&LPMxComponentDS);
	//::SendMessageTimeout(m_hTargetMXComModuleWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)(LPVOID)&m_LPMxComponentDS, SMTO_NORMAL, TIMEOUT_MS, pDw);

	SetMXComponentOpenCom(FALSE);
}

void CCaptureManager::LPMxComWindowShowHide(BOOL bWindowShow)
{
	PDWORD_PTR pDw = NULL;

	stLPMXComponentCommnd stComponenetCommand;
	stComponenetCommand.nCommandType = TYPE_COMMAND_WINDOWSHOWHIDE;
	stComponenetCommand.bWindowShow = bWindowShow;

	COPYDATASTRUCT LPMxComponentDS;
	LPMxComponentDS.dwData = NULL;
	LPMxComponentDS.cbData = sizeof(stComponenetCommand);
	LPMxComponentDS.lpData = &stComponenetCommand;

	::SendMessage(m_hTargetMXComModuleWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)(LPVOID)&LPMxComponentDS);
	//::SendMessageTimeout(m_hTargetMXComModuleWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)(LPVOID)&m_LPMxComponentDS, SMTO_NORMAL, TIMEOUT_MS, pDw);
}

#endif

