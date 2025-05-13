#include "StdAfx.h"
#include "CLFile.h"

#include "Util/Util.h"

#include "inc/CameraLibrary.h"

#pragma comment (lib, "multicam.lib")

CCLFile::CCLFile()
{
	m_bInit = FALSE;
	m_bStart = FALSE;

	::InitializeCriticalSection(&m_CriticalSection);

	memset(&m_stCL, 0x00, sizeof(INFO_CONNECT_CAMERALINK));
	memset(&m_stFrame, 0x00, sizeof(INFO_FRAME));

	// EURESYS
	memset(&m_stEuresys, 0x00, sizeof(INFO_EURESYS));
	memset(&m_stCamDevice, 0x00, sizeof(INFO_CAM_DEVICE));
	memset(&m_stUserSetting, 0x00, sizeof(INFO_USER_SETTING));
	m_LastSWTrigger = 0;


	//
	m_hThreadCl = NULL;
	m_bStopCl = FALSE;

	m_hEventClAcq = NULL;
	m_hEventClStop = NULL;
	

	m_pFunc = NULL;
	m_pFuncArg = NULL;

	// Dll Library
	m_hDllInstance = NULL;
	m_hCameraLib = NULL;

	InitCLLibrary();

}

CCLFile::~CCLFile()
{
	::DeleteCriticalSection(&m_CriticalSection);

	Close();
	DeinitCLLibrary();
}

int	CCLFile::SearchSerial(INFO_SERIAL* pstInfo, const int nLen)
{
	if (NULL == m_hCameraLib || NULL == pfSearchSerial)
		return -1;

	INFO_SERIALPORT* pstSerialPort = NULL;
	if (0 < nLen)
		pstSerialPort = new INFO_SERIALPORT[nLen];

	int nCount = (*pfSearchSerial)(m_hCameraLib, pstSerialPort, nLen);
	if (0 < nLen && 0 < nCount)
	{
		int val = nLen > nCount ? nCount : nLen;
		for (int i = 0; i < val; i++)
		{
			CUtil::StringCopy(pstInfo[i].m_szPortName, pstSerialPort[i].m_szPortName );
			CUtil::StringCopy(pstInfo[i].m_szFriendlyName, pstSerialPort[i].m_szFriendlyName);
			CUtil::StringCopy(pstInfo[i].m_szTechnology, pstSerialPort[i].m_szTechnology);
		}
	}

	if (pstSerialPort)
		delete[] pstSerialPort;
	pstSerialPort = NULL;

	return nCount;
}

BOOL CCLFile::IsOpen()
{
	return m_bInit;
}

BOOL CCLFile::Open(const INFO_CONNECT_CAMERALINK* pInfo)
{
	if (NULL == pInfo)
		return FALSE;
	memcpy(&m_stCL, pInfo, sizeof(INFO_CONNECT_CAMERALINK));
	m_bInit = TRUE;

	return TRUE;
}

void CCLFile::Close()
{
	m_bStart = FALSE;
	m_bStopCl = TRUE;

	/// Camera Link
	BOOL bResult = FALSE;
	{
		if (pfStop)
			bResult = (*pfStop)(m_hCameraLib);
		if (pfSetTrigger)
			bResult = (*pfSetTrigger)(m_hCameraLib, TYPE_TRIGGER_OFF, TYPE_TRIGGER_POLARITY_HIGH);
		if (pfStart)
			bResult = (*pfStart)(m_hCameraLib);

		CUtil::Sleep(300);
	}
	//*/

	if (m_hEventClAcq)
	{
		::SetEvent(m_hEventClAcq);
	}	

	if (m_hEventClStop)
	{
		if (m_hEventClStop)
			::SetEvent(m_hEventClStop);

		::ResetEvent(m_hEventClStop);
		::WaitForSingleObject(m_hEventClStop, 5000);
		::CloseHandle(m_hEventClStop);

		m_hEventClStop = NULL;
	}

	if (m_hEventClAcq)
	{
		::ResetEvent(m_hEventClAcq);
		::CloseHandle(m_hEventClAcq);

		m_hEventClAcq = NULL;
	}


	if (m_hThreadCl)
	{
		::CloseHandle(m_hThreadCl);

		m_hThreadCl = NULL;
	}


	// Euresys Library
	CloseEuresys();

	// CameraLink
	CloseSerial();
}

BOOL CCLFile::IsOpenSerial()
{
	BOOL bResult = FALSE;

	if (pfIsConnectedSerial)
		bResult = (*pfIsConnectedSerial)(m_hCameraLib);
	return bResult;
}

BOOL CCLFile::OpenSerial()
{
	const INFO_CONNECT_CAMERALINK* pstCameraLink = GetDeviceInfo();
	if (NULL == pstCameraLink)
		return FALSE;

	BOOL bResult = FALSE;
	if (pfConnectSerial)
		bResult = (*pfConnectSerial)(m_hCameraLib, (LPTSTR)(LPCTSTR)pstCameraLink->m_szSerial, pstCameraLink->m_dwSpeed);
	return bResult;
}

void CCLFile::CloseSerial()
{
	if (pfDisconnectSerial)
		(*pfDisconnectSerial)(m_hCameraLib);
}


BOOL CCLFile::Update(const INFO_CONNECT_CAMERALINK* pInfo)
{
	if (NULL == pInfo)
		return FALSE;
	this->Stop();

	m_stCL = *pInfo;
	return TRUE;
}

BOOL CCLFile::GetFrameInfo(INFO_FRAME* pstFrame)
{
	if (NULL == pstFrame)
		return FALSE;

	BOOL bResult = TRUE;

#ifndef AGING_ONLY_FRAMEGRABBER
	if (1>m_stFrame.m_dwWidth || 1>m_stFrame.m_dwHeight)
#endif
	{
		const BOOL bOpened = IsOpenSerial();
		if (FALSE == bOpened)
		{
			if (FALSE == OpenSerial())
				return FALSE;
		}

		bResult = (*pfLoadDefaultInformation)(m_hCameraLib, &m_stCamDevice);
		if (bResult)
		{
			bResult = (*pfLoadDeviceUserSet)(m_hCameraLib, &m_stUserSetting, FALSE);
#ifdef DEF_LPAPP
			if (bResult)
			{
				const INFO_CONNECT_CAMERALINK* pCameraLink =  GetDeviceInfo();

				if (pCameraLink->m_eClDevice != (TYPE_CLDEVICE)m_stCamDevice.m_stDevice.m_eDevice)
					return FALSE;
				
				if (pCameraLink->m_eClImageTaps != m_stUserSetting.m_stMain.m_eImageTap || 
					pCameraLink->m_eClDataBit != m_stUserSetting.m_stMain.m_eDataBit)
				{
					// Set ImageTap & DataBit
					if (pCameraLink->m_eClImageTaps != m_stUserSetting.m_stMain.m_eImageTap)
						(*pfSetImageTaps)(m_hCameraLib, (TYPE_IMAGE_TAPS)pCameraLink->m_eClImageTaps);
					if (pCameraLink->m_eClDataBit != m_stUserSetting.m_stMain.m_eDataBit)
						(*pfSetDataBit)(m_hCameraLib, (TYPE_DATA_BIT)pCameraLink->m_eClDataBit);
					
					bResult = (*pfLoadDefaultInformation)(m_hCameraLib, &m_stCamDevice);
					if (bResult)
						bResult = (*pfLoadDeviceUserSet)(m_hCameraLib, &m_stUserSetting, FALSE);
				}
			}
#endif
		}

		if (bResult)
		{
			int nBit = 0;
			//
			m_stFrame.m_bVariable = TRUE;

			if (TYPE_COLOR_COLOR == m_stCamDevice.m_stDevice.m_eColor)
			{
				m_stFrame.m_eColor = TYPE_CAMCOLOR_COLOR;
				m_stFrame.m_eColorFormat = TYPE_CAMCOLORFORMAT_NONE;	// ??
			}
			else
			{
				m_stFrame.m_eColor = TYPE_CAMCOLOR_MONO;
				m_stFrame.m_eColorFormat = TYPE_CAMCOLORFORMAT_NONE;
			}
			m_stFrame.m_eColor = TYPE_CAMCOLOR_MONO;	//

			if (TYPE_DATA_BIT_10 == m_stUserSetting.m_stMain.m_eDataBit)
			{
				m_stFrame.m_eDataBit = TYPE_DATABIT_10;
				nBit = 10;
			}
			else
			{
				m_stFrame.m_eDataBit = TYPE_DATABIT_08;
				nBit = 8;
			}

			m_stFrame.m_dwMaxWidth = m_stUserSetting.m_stMain.m_stRoi.m_dwWidth;
			m_stFrame.m_dwMaxHeight = m_stUserSetting.m_stMain.m_stRoi.m_dwHeight;
			m_stFrame.m_dwMaxPitch = (DWORD)(m_stUserSetting.m_stMain.m_stRoi.m_dwWidth * nBit / 8.0f);

			m_stFrame.m_dwX = m_stUserSetting.m_stMain.m_stRoi.m_nX;
			m_stFrame.m_dwY = m_stUserSetting.m_stMain.m_stRoi.m_nY;
			m_stFrame.m_dwWidth = m_stUserSetting.m_stMain.m_stRoi.m_dwWidth;
			m_stFrame.m_dwHeight = m_stUserSetting.m_stMain.m_stRoi.m_dwHeight;
			m_stFrame.m_dwPitch = (DWORD)(m_stUserSetting.m_stMain.m_stRoi.m_dwWidth * nBit / 8.0f);
		}

		if (!bOpened)
			CloseSerial();
	}

	if (bResult)
	{
		memcpy(pstFrame, &m_stFrame, sizeof(INFO_FRAME));
	}
	
	
	return bResult;
}

const INFO_CONNECT_CAMERALINK* CCLFile::GetDeviceInfo()
{
	return &m_stCL;
}

const TYPE_CLIMGTAPS CCLFile::GetClImageTap(TYPE_IMAGE_TAPS eTap)
{
	TYPE_CLIMGTAPS eClTap = TYPE_CLIMGTAPS_NONE;

	if(TYPE_IMAGE_TAPS_02 == eTap)
		eClTap = TYPE_CLIMGTAPS_02;
	else if (TYPE_IMAGE_TAPS_04 == eTap)
		eClTap = TYPE_CLIMGTAPS_04;
	else if (TYPE_IMAGE_TAPS_08 == eTap)
		eClTap = TYPE_CLIMGTAPS_08;
	else if (TYPE_IMAGE_TAPS_10 == eTap)
		eClTap = TYPE_CLIMGTAPS_10;


	return eClTap;
}
const TYPE_IMAGE_TAPS CCLFile::GetImageTap(TYPE_CLIMGTAPS eTap)
{
	TYPE_IMAGE_TAPS eImgTap = TYPE_IMAGE_TAPS_NONE;

	if (TYPE_CLIMGTAPS_02 == eTap)
		eImgTap = TYPE_IMAGE_TAPS_02;
	else if (TYPE_CLIMGTAPS_04 == eTap)
		eImgTap = TYPE_IMAGE_TAPS_04;
	else if (TYPE_CLIMGTAPS_08 == eTap)
		eImgTap = TYPE_IMAGE_TAPS_08;
	else if (TYPE_CLIMGTAPS_10 == eTap)
		eImgTap = TYPE_IMAGE_TAPS_10;

	return eImgTap;
}

BOOL CCLFile::LoadCameraUserSetting()
{
	BOOL bResult = IsOpenSerial();

	if (bResult)
		bResult = (*pfLoadDefaultInformation)(m_hCameraLib, &m_stCamDevice);
	if (bResult)
		bResult = (*pfLoadDeviceUserSet)(m_hCameraLib, &m_stUserSetting, FALSE);

	return bResult;
}


const INFO_CAM_DEVICE* CCLFile::GetCameraDevice()
{
	return &m_stCamDevice;
}

const INFO_USER_SETTING* CCLFile::GetUserSetting()
{
	if (FALSE == IsOpenSerial())
		return NULL;

	const INFO_USER_SETTING* pstSetting = (*pfGetUserSettingInformation)(m_hCameraLib);
	return pstSetting;
}


BOOL CCLFile::SetEventFunc(FuncAcquisitionEvent pFunc, void* pUserData)
{
	m_pFunc = pFunc;
	m_pFuncArg = pUserData;

	return TRUE;
}

BOOL CCLFile::IsStarted()
{
	const INFO_CONNECT_CAMERALINK* pstInfo = GetDeviceInfo();
	if (NULL == pstInfo)
		return FALSE;

	BOOL bStarted = FALSE;
	if (TYPE_CLGRABBER_EURESYS == pstInfo->m_eClFrameGrabber && m_stEuresys.m_Channel)
	{
		bStarted = TRUE;
	}
	else if (TYPE_CLGRABBER_SILICONSOFTWARE == pstInfo->m_eClFrameGrabber)
	{
	}
	else if (TYPE_CLGRABBER_MATROX == pstInfo->m_eClFrameGrabber)
	{
	}

	return m_bStart;

}

BOOL CCLFile::Start(BOOL bSingleFrame)
{
	const INFO_CONNECT_CAMERALINK* pstInfo = GetDeviceInfo();
	if (NULL == pstInfo)
		return FALSE;

	if (NULL == m_hEventClAcq || NULL == m_hEventClStop || NULL == m_hThreadCl)
	{
		// Thread
		m_hEventClAcq = ::CreateEvent(0, TRUE, FALSE, 0);
		if (NULL == m_hEventClAcq)
		{
			Close();
			return FALSE;
		}

		m_hEventClStop = ::CreateEvent(0, TRUE, FALSE, 0);
		if (NULL == m_hEventClStop)
		{
			Close();
			return FALSE;
		}

		DWORD dwThreadId = 0;
		m_hThreadCl = ::CreateThread(0, 0, ThreadClProc, LPVOID(this), 0, &dwThreadId);
	}


	BOOL bResult = FALSE;
	if (TYPE_CLGRABBER_EURESYS == pstInfo->m_eClFrameGrabber)
	{
		bResult = StartEuresys();
	}
	else if (TYPE_CLGRABBER_SILICONSOFTWARE == pstInfo->m_eClFrameGrabber)
	{
	}
	else if (TYPE_CLGRABBER_MATROX == pstInfo->m_eClFrameGrabber)
	{
	}

	return bResult;
}

void CCLFile::Stop()
{
	const INFO_CONNECT_CAMERALINK* pstInfo = GetDeviceInfo();
	if (NULL == pstInfo)
		return;

	if (TYPE_CLGRABBER_EURESYS == pstInfo->m_eClFrameGrabber)
	{
		StopEuresys();
	}
	else if (TYPE_CLGRABBER_SILICONSOFTWARE == pstInfo->m_eClFrameGrabber)
	{
	}
	else if (TYPE_CLGRABBER_MATROX == pstInfo->m_eClFrameGrabber)
	{
	}
}



// EURESYS CALLBACK FUNC
void WINAPI CCLFile::EuresysCallback(PMCSIGNALINFO pSigInfo)
{
	if (NULL == pSigInfo || NULL == pSigInfo->Context)
		return;
	
	CCLFile* pCLFile = (CCLFile*)pSigInfo->Context;
	switch (pSigInfo->Signal)
	{
	case MC_SIG_SURFACE_PROCESSING:
		{
			if (pCLFile && pCLFile->m_pFunc && pCLFile->m_bStart)
			{
				McGetParamInt(pSigInfo->SignalInfo, MC_SurfaceAddr, (PINT32)&(pCLFile->m_stEuresys.m_pCurrent));
				if (pCLFile->m_hEventClAcq)
				{
					::SetEvent(pCLFile->m_hEventClAcq);
				}
			}
		}
		break;

	case MC_SIG_ACQUISITION_FAILURE:
		{
			/*//
			CUtil::PrintDebugString(_T("[%d] MC_SIG_ACQUISITION_FAILURE \r\n"), ::GetTickCount() );
			if (TYPE_TRIGGER_BOARDCONTROL == pCLFile->m_stUserSetting.m_stTrigger.m_eTrigger)
			{
				pCLFile->SetTrigger();
			}
			//*/
		}
		break;

	default:
		break;
	}
	
}

BOOL CCLFile::StartEuresys()
{
	const INFO_CONNECT_CAMERALINK* pstInfo = GetDeviceInfo();
	if (NULL == pstInfo || TYPE_CLGRABBER_EURESYS != pstInfo->m_eClFrameGrabber)
		return FALSE;

	BOOL bResult = TRUE;
	if (NULL == m_stEuresys.m_Channel)
	{
		// EURESYS: Initialize driver and error handling
		McOpenDriver(NULL);

		// Read device information
		const int EURESYS_SURFACE_COUNT = 3;

		// Set the board topology to support 10 taps mode (only with a Grablink Full)
		if (TYPE_CLIMGTAPS_10 == pstInfo->m_eClImageTaps)
			McSetParamInt(MC_BOARD + 0, MC_BoardTopology, MC_BoardTopology_MONO_DECA);
		else
			McSetParamInt(MC_BOARD + 0, MC_BoardTopology, MC_BoardTopology_MONO);

		McCreate(MC_CHANNEL, &m_stEuresys.m_Channel);
		McSetParamInt(m_stEuresys.m_Channel, MC_DriverIndex, 0);

		// In order to use single camera on connector A
		// MC_Connector need to be set to A for Grablink Expert 2 and Grablink DualBase
		// For all the other Grablink boards the parameter has to be set to M  

		// For all GrabLink boards but Grablink Expert 2 and Dualbase
		McSetParamStr(m_stEuresys.m_Channel, MC_Connector, "M");


		TCHAR* pszCamFile = NULL;
		if (TYPE_TRIGGER_OFF == m_stUserSetting.m_stTrigger.m_eTrigger)
		{
			pszCamFile = (LPTSTR)(LPCTSTR)pstInfo->m_szCamFile[CLCAMFILE_NORMAL];
		}
		else if (TYPE_TRIGGER_EXTERNAL == m_stUserSetting.m_stTrigger.m_eTrigger ||
				 TYPE_TRIGGER_BOARDCONTROL == m_stUserSetting.m_stTrigger.m_eTrigger)
		{
			pszCamFile = (LPTSTR)(LPCTSTR)pstInfo->m_szCamFile[CLCAMFILE_TRIGGER];
		}

		// Choose the video standard
		if (CUtil::IsExistFile(pszCamFile))
		{
			McSetParamStr(m_stEuresys.m_Channel, MC_CamFile, pszCamFile);
		}
		else
		{
			StopEuresys();

			McSetParamInt(m_stEuresys.m_Channel, MC_ChannelState, MC_ChannelState_IDLE);
			CUtil::Sleep(100);
			McDelete(m_stEuresys.m_Channel);
			m_stEuresys.m_Channel = NULL;

			return FALSE;
		}

		// Choose the camera expose duration
		McSetParamInt(m_stEuresys.m_Channel, MC_Expose_us, 10000);
		// Choose the pixel color format
		McSetParamInt(m_stEuresys.m_Channel, MC_ColorFormat, MC_ColorFormat_Y8);

		// FreeRun
		if (TYPE_TRIGGER_OFF == m_stUserSetting.m_stTrigger.m_eTrigger)
		{
			// Set the acquisition mode to snapShot
			McSetParamInt(m_stEuresys.m_Channel, MC_AcquisitionMode, MC_AcquisitionMode_SNAPSHOT);
			// Choose the way the first acquisition is triggered
			McSetParamInt(m_stEuresys.m_Channel, MC_TrigMode, MC_TrigMode_IMMEDIATE);
			// Choose the triggering mode for subsequent acquisitions
			McSetParamInt(m_stEuresys.m_Channel, MC_NextTrigMode, MC_NextTrigMode_REPEAT);
		}
		// Trigger...
		else if (TYPE_TRIGGER_EXTERNAL == m_stUserSetting.m_stTrigger.m_eTrigger ||
				 TYPE_TRIGGER_BOARDCONTROL == m_stUserSetting.m_stTrigger.m_eTrigger )
		{
			// Configure triggering mode
			McSetParamInt(m_stEuresys.m_Channel, MC_TrigMode, MC_TrigMode_COMBINED);
			McSetParamInt(m_stEuresys.m_Channel, MC_NextTrigMode, MC_NextTrigMode_COMBINED);

			// Configure triggering line
			// A rising edge on the triggering line generates a trigger.
			// See the TrigLine Parameter and the board documentation for more details.
			McSetParamInt(m_stEuresys.m_Channel, MC_TrigLine, MC_TrigLine_NOM);
			McSetParamInt(m_stEuresys.m_Channel, MC_TrigEdge, MC_TrigEdge_GOHIGH);
			McSetParamInt(m_stEuresys.m_Channel, MC_TrigFilter, MC_TrigFilter_ON);

			// Parameter valid for all Grablink but Full, DualBase, Base
			// McSetParamInt(m_Channel, MC_TrigCtl, MC_TrigCtl_ITTL);
			// Parameter valid only for Grablink Full, DualBase, Base
			McSetParamInt(m_stEuresys.m_Channel, MC_TrigCtl, MC_TrigCtl_ISO);


			const int nTimeOut = (int)(1000.f * 5 / m_stUserSetting.m_stAnalog.m_stFPS.m_nCur);
			McSetParamInt(m_stEuresys.m_Channel, MC_AcqTimeout_ms, nTimeOut);

		}

		// Choose the number of images to acquire
		McSetParamInt(m_stEuresys.m_Channel, MC_SeqLength_Fr, MC_INDETERMINATE);


		// Retrieve image dimensions
		{
			//
			{
				int nStartX = this->m_stFrame.m_dwX;
				int nStartY = this->m_stFrame.m_dwY;
				int nWidth = this->m_stFrame.m_dwWidth;
				int nHeight = this->m_stFrame.m_dwHeight;
				int nPitch = nHeight;

				int nResult = 0;

				nResult = McSetParamInt(m_stEuresys.m_Channel, MC_Hactive_Px, nWidth);
				nResult = McSetParamInt(m_stEuresys.m_Channel, MC_Vactive_Ln, nHeight);

				nResult = McSetParamInt(m_stEuresys.m_Channel, MC_OffsetX_Px, nStartX);
				nResult = McSetParamInt(m_stEuresys.m_Channel, MC_OffsetY_Ln, nStartY);
				nResult = McSetParamInt(m_stEuresys.m_Channel, MC_WindowX_Px, nWidth);
				nResult = McSetParamInt(m_stEuresys.m_Channel, MC_WindowY_Ln, nHeight);
			}

			// Check Current
			McGetParamInt(m_stEuresys.m_Channel, MC_ImageSizeX, &m_stEuresys.m_nSizeX);
			McGetParamInt(m_stEuresys.m_Channel, MC_ImageSizeY, &m_stEuresys.m_nSizeY);
			McGetParamInt(m_stEuresys.m_Channel, MC_BufferPitch, &m_stEuresys.m_nPitch);
		}

		// The memory allocation for the images is automatically done by Multicam when activating the channel.
		// We only set the number of surfaces to be created by MultiCam.
		McSetParamInt(m_stEuresys.m_Channel, MC_SurfaceCount, EURESYS_SURFACE_COUNT);

		// Enable MultiCam signals
		McSetParamInt(m_stEuresys.m_Channel, MC_SignalEnable + MC_SIG_SURFACE_PROCESSING, MC_SignalEnable_ON);
		McSetParamInt(m_stEuresys.m_Channel, MC_SignalEnable + MC_SIG_ACQUISITION_FAILURE, MC_SignalEnable_ON);

		// Register the callback function
		McRegisterCallback(m_stEuresys.m_Channel, EuresysCallback, this);


		//
#ifndef AGING_ONLY_FRAMEGRABBER
		bResult = this->IsOpenSerial();
		if (FALSE == bResult)
			bResult = OpenSerial();
		if(bResult)
			bResult = LoadCameraUserSetting();
		if (bResult)
		{
			const INFO_USER_SETTING* pstSetting = GetUserSetting();
			if (NULL == pstSetting || pstInfo->m_eClImageTaps != GetClImageTap(pstSetting->m_stMain.m_eImageTap))
				bResult = FALSE;
		}

		if (FALSE == bResult)
#endif
		{
			McSetParamInt(m_stEuresys.m_Channel, MC_ChannelState, MC_ChannelState_IDLE);
		}

		McSetParamInt(m_stEuresys.m_Channel, MC_ChannelState, MC_ChannelState_ACTIVE);
		m_bStart = TRUE;
	}
	else
	{
		McSetParamInt(m_stEuresys.m_Channel, MC_ChannelState, MC_ChannelState_ACTIVE);
		m_bStart = TRUE;
	}
	return bResult;
}

void CCLFile::StopEuresys()
{
	McSetParamInt(m_stEuresys.m_Channel, MC_ChannelState, MC_ChannelState_IDLE);
	m_bStart = FALSE;
}

void CCLFile::CloseEuresys()
{
	if (m_stEuresys.m_Channel)
	{
		m_bStart = FALSE;

		McSetParamInt(m_stEuresys.m_Channel, MC_ChannelState, MC_ChannelState_IDLE);
		CUtil::Sleep(100);
		McDelete(m_stEuresys.m_Channel);

		m_stEuresys.m_Channel = NULL;

		// EURESYS: Terminate driver
		McCloseDriver();
	}
}

void CCLFile::UpdateUserSetting()
{
	if (m_hCameraLib)
	{
		const INFO_USER_SETTING* pUserSetting = (*pfGetUserSettingInformation)(m_hCameraLib);
		memcpy(&m_stUserSetting, pUserSetting, sizeof(INFO_USER_SETTING));
	}
}

////////////////////
void CCLFile::InitCLLibrary()
{
	TCHAR szLocation[MAX_PATH] = { 0, };
	CUtil::GetCurrentDirectory(szLocation, MAX_PATH);

	TCHAR szDllPath[MAX_PATH] = { 0, };

#ifdef _WIN64
	CUtil::StringFormat(szDllPath, MAX_PATH, _T("%s\\%s"), szLocation, _T("LibControl_x64.dll"));
#else
	CUtil::StringFormat(szDllPath, MAX_PATH, _T("%s\\%s"), szLocation, _T("LibControl.dll"));
#endif

	m_hDllInstance = ::LoadLibrary(szDllPath);
	if (NULL == m_hDllInstance)
		return;

	pfInitCameraLib = (HCAMERALIB(CALLBACK *)())::GetProcAddress(m_hDllInstance, "InitCameraLib");
	pfDeinitCameraLib = (void(CALLBACK *)(HCAMERALIB ))::GetProcAddress(m_hDllInstance, "DeinitCameraLib");

	// Device
	pfLoadDefaultInformation = (BOOL(CALLBACK *)(HCAMERALIB, INFO_CAM_DEVICE*))::GetProcAddress(m_hDllInstance, "LoadDefaultInformation");
	pfGetDeviceInformation = (const INFO_CAM_DEVICE* (CALLBACK *)(HCAMERALIB))::GetProcAddress(m_hDllInstance, "GetDeviceInformation");
	pfSetDeviceFactoryDefault = (BOOL(CALLBACK *)(HCAMERALIB))::GetProcAddress(m_hDllInstance, "SetDeviceFactoryDefault");
	pfLoadDeviceUserSet = (BOOL(CALLBACK *)(HCAMERALIB, INFO_USER_SETTING*, BOOL))::GetProcAddress(m_hDllInstance, "LoadDeviceUserSet");

	// User Setting.
	pfGetUserSettingInformation = (const INFO_USER_SETTING* (CALLBACK *)(HCAMERALIB))::GetProcAddress(m_hDllInstance, "GetUserSettingInformation");
	pfSetUserSettingMain = (void (CALLBACK *)(HCAMERALIB, const INFO_STATUS_MAIN*))::GetProcAddress(m_hDllInstance, "SetUserSettingMain");
	pfSetUserSettingAnalog = (void (CALLBACK *)(HCAMERALIB, const INFO_STATUS_ANALOG*))::GetProcAddress(m_hDllInstance, "SetUserSettingAnalog");
	pfSetUserSettingTrigger = (void (CALLBACK *)(HCAMERALIB, const INFO_STATUS_TRIGGER*))::GetProcAddress(m_hDllInstance, "SetUserSettingTrigger");
	pfSetUserSettingLut = (void (CALLBACK *)(HCAMERALIB, const INFO_STATUS_LUT*))::GetProcAddress(m_hDllInstance, "SetUserSettingLut");

#ifndef AGING_ONLY_FRAMEGRABBER
	// Command Device
	pfStart = (BOOL(CALLBACK *)(HCAMERALIB))::GetProcAddress(m_hDllInstance, "Start");
	pfStop = (BOOL(CALLBACK *)(HCAMERALIB))::GetProcAddress(m_hDllInstance, "Stop");

	//
	pfSetDataBit = (BOOL(CALLBACK *)(HCAMERALIB, const TYPE_DATA_BIT))::GetProcAddress(m_hDllInstance, "SetDataBit");
	pfSetViewMode = (BOOL(CALLBACK *)(HCAMERALIB, const TYPE_VIEW_MODE, INFO_ROI*))::GetProcAddress(m_hDllInstance, "SetViewMode");
	pfSetTestPattern = (BOOL(CALLBACK *)(HCAMERALIB, const TYPE_TEST_PATTERN))::GetProcAddress(m_hDllInstance, "SetTestPattern");
	pfSetRoi = (BOOL(CALLBACK *)(HCAMERALIB, const INFO_ROI*))::GetProcAddress(m_hDllInstance, "SetRoi");
	pfSetImageTaps = (BOOL(CALLBACK *)(HCAMERALIB, TYPE_IMAGE_TAPS))::GetProcAddress(m_hDllInstance, "SetImageTaps");

	// 
	pfSetAnalogGain = (BOOL(CALLBACK *)(HCAMERALIB, DWORD))::GetProcAddress(m_hDllInstance, "SetAnalogGain");
	pfSetDigitalGain = (BOOL(CALLBACK *)(HCAMERALIB, DWORD))::GetProcAddress(m_hDllInstance, "SetDigitalGain");

	pfSetExposure = (BOOL(CALLBACK *)(HCAMERALIB, DWORD))::GetProcAddress(m_hDllInstance, "SetExposure");
	pfSetFramerate = (BOOL(CALLBACK *)(HCAMERALIB, DWORD))::GetProcAddress(m_hDllInstance, "SetFramerate");

	pfSetEnablePrnu = (BOOL(CALLBACK *)(HCAMERALIB, BOOL))::GetProcAddress(m_hDllInstance, "SetEnablePrnu");

	pfSetEnableFfc = (BOOL(CALLBACK *)(HCAMERALIB, BOOL))::GetProcAddress(m_hDllInstance, "SetEnableFfc");
	pfGetFfcResolution = (BOOL(CALLBACK *)(HCAMERALIB, DWORD*, DWORD*))::GetProcAddress(m_hDllInstance, "GetFfcResolution");

	pfAllocGainTable = (BOOL(CALLBACK *)(HCAMERALIB, const int, const int, INFO_GAIN_TABLE*))::GetProcAddress(m_hDllInstance, "AllocGainTable");
	pfReleaseGainTable = (BOOL(CALLBACK *)(HCAMERALIB, INFO_GAIN_TABLE*))::GetProcAddress(m_hDllInstance, "ReleaseGainTable");

	pfMakeFfcAvgBuffer = (BOOL(CALLBACK *)(HCAMERALIB, const INFO_BITMAP*, const int, INFO_GAIN_TABLE*))::GetProcAddress(m_hDllInstance, "MakeFfcAvgBuffer");
	pfMakeFfcGainBuffer = (BOOL(CALLBACK *)(HCAMERALIB, INFO_GAIN_TABLE*))::GetProcAddress(m_hDllInstance, "MakeFfcGainBuffer");
	pfMakeFfcGainTable = (BOOL(CALLBACK *)(HCAMERALIB, INFO_GAIN_TABLE*))::GetProcAddress(m_hDllInstance, "MakeFfcGainTable");
	pfMakeFfcWriteBuffer = (BOOL(CALLBACK *)(HCAMERALIB, INFO_GAIN_TABLE*))::GetProcAddress(m_hDllInstance, "MakeFfcWriteBuffer");

	pfWriteFfcEvenBuffer = (BOOL(CALLBACK *)(HCAMERALIB, const INFO_GAIN_TABLE*, BOOL))::GetProcAddress(m_hDllInstance, "WriteFfcEvenBuffer");
	pfWriteFfcOddBuffer = (BOOL(CALLBACK *)(HCAMERALIB, const INFO_GAIN_TABLE*, BOOL))::GetProcAddress(m_hDllInstance, "WriteFfcOddBuffer");

	pfSetEnableBlackLevel = (BOOL(CALLBACK *)(HCAMERALIB, BOOL))::GetProcAddress(m_hDllInstance, "SetEnableBlackLevel");
	pfSetBlackLevel = (BOOL(CALLBACK *)(HCAMERALIB, DWORD))::GetProcAddress(m_hDllInstance, "SetBlackLevel");

	pfSetEnableDefectFilter = (BOOL(CALLBACK *)(HCAMERALIB, BOOL))::GetProcAddress(m_hDllInstance, "SetEnableDefectFilter");
	pfSetEnableUsertableDefectFilter = (BOOL(CALLBACK *)(HCAMERALIB, BOOL))::GetProcAddress(m_hDllInstance, "SetEnableUsertableDefectFilter");

	pfSetThresholdDefectFilter = (BOOL(CALLBACK *)(HCAMERALIB, DWORD))::GetProcAddress(m_hDllInstance, "SetThresholdDefectFilter");
	pfSetUsertableDefectFilter = (BOOL(CALLBACK *)(HCAMERALIB, const DWORD*, const DWORD))::GetProcAddress(m_hDllInstance, "SetUsertableDefectFilter");

	pfGetInternalTemperature = (BOOL(CALLBACK *)(HCAMERALIB, DWORD*))::GetProcAddress(m_hDllInstance, "GetInternalTemperature");
	pfGetExternalTemperature = (BOOL(CALLBACK *)(HCAMERALIB, DWORD*))::GetProcAddress(m_hDllInstance, "GetExternalTemperature");

	//
	pfSetTrigger = (BOOL(CALLBACK *)(HCAMERALIB, TYPE_TRIGGER, TYPE_TRIGGER_POLARITY))::GetProcAddress(m_hDllInstance, "SetTrigger");
	pfSetSensorExposureTime = (BOOL(CALLBACK *)(HCAMERALIB, TYPE_SENSOR_EXPOSURE))::GetProcAddress(m_hDllInstance, "SetSensorExposureTime");
	pfSetTriggerDelayTime = (BOOL(CALLBACK *)(HCAMERALIB, DWORD))::GetProcAddress(m_hDllInstance, "SetTriggerDelayTime");

	pfSetStrobePolarity = (BOOL(CALLBACK *)(HCAMERALIB, BOOL, TYPE_STROBE_POLARITY))::GetProcAddress(m_hDllInstance, "SetStrobePolarity");
	pfSetStrobeSync = (BOOL(CALLBACK *)(HCAMERALIB, TYPE_STROBE_SYNC))::GetProcAddress(m_hDllInstance, "SetStrobeSync");
	pfSetStrobeDelayTime = (BOOL(CALLBACK *)(HCAMERALIB, DWORD))::GetProcAddress(m_hDllInstance, "SetStrobeDelayTime");
	pfSetStrobeDurationTime = (BOOL(CALLBACK *)(HCAMERALIB, DWORD))::GetProcAddress(m_hDllInstance, "SetStrobeDurationTime");

	//
	pfSetEnableLut = (BOOL(CALLBACK *)(HCAMERALIB, BOOL))::GetProcAddress(m_hDllInstance, "SetEnableLut");
	pfSetLutIndex = (BOOL(CALLBACK *)(HCAMERALIB, int))::GetProcAddress(m_hDllInstance, "SetLutIndex");

	pfWriteLutTable = (BOOL(CALLBACK *)(HCAMERALIB, const INFO_LUT_TABLE*, const int, BOOL))::GetProcAddress(m_hDllInstance, "WriteLutTable");

	// Command Register
	pfReadRegister = (BOOL(CALLBACK *)(HCAMERALIB, const TYPE_REGISTER, WORD, WORD*))::GetProcAddress(m_hDllInstance, "ReadRegister");
	pfWriteRegister = (BOOL(CALLBACK *)(HCAMERALIB, const TYPE_REGISTER, WORD, WORD))::GetProcAddress(m_hDllInstance, "WriteRegister");;
	pfWritePrnu = (BOOL(CALLBACK *)(HCAMERALIB, const DWORD*, const DWORD))::GetProcAddress(m_hDllInstance, "WritePrnu");

	// Command SPI
	pfReadFlash = (BOOL(CALLBACK *)(HCAMERALIB, DWORD, DWORD, BYTE*, DWORD))::GetProcAddress(m_hDllInstance, "ReadFlash");
	pfWriteFlash = (BOOL(CALLBACK *)(HCAMERALIB, DWORD, DWORD, const BYTE*, DWORD))::GetProcAddress(m_hDllInstance, "WriteFlash");

	pfGetSerialNumber = (BOOL(CALLBACK *)(HCAMERALIB, TCHAR*, int))::GetProcAddress(m_hDllInstance, "GetSerialNumber");
	pfSetSerialNumber = (BOOL(CALLBACK *)(HCAMERALIB, WORD))::GetProcAddress(m_hDllInstance, "SetSerialNumber");

	// INI
	pfSaveFileUserSet = (BOOL(CALLBACK *)(HCAMERALIB, const TCHAR*, const TYPE_MENU_USERSET))::GetProcAddress(m_hDllInstance, "SaveFileUserSet");
	pfLoadFileUserSet = (BOOL(CALLBACK *)(HCAMERALIB, const TCHAR*, INFO_USER_SETTING*))::GetProcAddress(m_hDllInstance, "LoadFileUserSet");

	pfSaveEepromUserSet = (BOOL(CALLBACK *)(HCAMERALIB, const TYPE_MENU_USERSET))::GetProcAddress(m_hDllInstance, "SaveEepromUserSet");
	pfLoadEepromUserSet = (BOOL(CALLBACK *)(HCAMERALIB, const TYPE_MENU_USERSET, INFO_USER_SETTING*))::GetProcAddress(m_hDllInstance, "LoadEepromUserSet");

	pfSetStartUpUserSet = (BOOL(CALLBACK *)(HCAMERALIB, TYPE_MENU_USERSET))::GetProcAddress(m_hDllInstance, "SetStartUpUserSet");
	pfGetStartUpUserSet = (BOOL(CALLBACK *)(HCAMERALIB, TYPE_MENU_USERSET*))::GetProcAddress(m_hDllInstance, "GetStartUpUserSet");
#endif	


	pfSearchSerial = (int(CALLBACK *)(HCAMERALIB , INFO_SERIALPORT* , const int ))::GetProcAddress(m_hDllInstance, "SearchSerial");

	pfIsConnectedSerial = (BOOL(CALLBACK *)(HCAMERALIB ))::GetProcAddress(m_hDllInstance, "IsConnectedSerial");
	pfConnectSerial = (BOOL(CALLBACK *)(HCAMERALIB , TCHAR* , DWORD ))::GetProcAddress(m_hDllInstance, "ConnectSerial");
	pfDisconnectSerial = (void(CALLBACK *)(HCAMERALIB ))::GetProcAddress(m_hDllInstance, "DisconnectSerial");

	if (m_hDllInstance && pfInitCameraLib)
		m_hCameraLib = (*pfInitCameraLib)();

}

void CCLFile::DeinitCLLibrary()
{
	if (m_hDllInstance && pfDeinitCameraLib && m_hCameraLib)
		(*pfDeinitCameraLib)(m_hCameraLib);
	m_hCameraLib = NULL;

	if (m_hDllInstance)
		::FreeLibrary(m_hDllInstance);	
	m_hDllInstance = NULL;

}

// 
BOOL CCLFile::SetRoi(const int nX, const int nY, const int nW, const int nH)
{
	BOOL bResult = FALSE;

	m_bStart = FALSE;
	CloseEuresys();
	Sleep(100);

	if (pfStop)
		bResult = (*pfStop)(m_hCameraLib);
	if (pfSetViewMode)
	{
		INFO_ROI stRoi;
		memset(&stRoi, 0x00, sizeof(INFO_ROI));

		stRoi.m_nX = nX;
		stRoi.m_nY = nY;
		stRoi.m_dwWidth = nW;
		stRoi.m_dwHeight = nH;

		bResult = (*pfSetViewMode)(m_hCameraLib, TYPE_VIEW_MODE_ROI, &stRoi);
		if (bResult)
		{
			memset(&m_stFrame, 0x00, sizeof(INFO_FRAME));
			GetFrameInfo(&m_stFrame);
		}
	}
	if (pfStart)
		bResult = (*pfStart)(m_hCameraLib);
	
	if (pfLoadDeviceUserSet)
		(*pfLoadDeviceUserSet)(m_hCameraLib, &m_stUserSetting, FALSE);

	StartEuresys();

	return bResult;
}

BOOL CCLFile::GetRoi(INFO_ROI_PARA* pstROI)
{
	if (NULL == pstROI)
		return FALSE;

	DWORD dwValue = 0;

	if (GetMaxWidth(&dwValue))
		pstROI->nMaxWidth = dwValue;
	if (GetMaxHeight(&dwValue))
		pstROI->nMaxHeight = dwValue;

	if(GetX(&dwValue))
		pstROI->nXstart = dwValue;
	if (GetY(&dwValue))
		pstROI->nYstart = dwValue;
	if (GetWidth(&dwValue))
		pstROI->nWidth = dwValue;
	if (GetHeight(&dwValue))
		pstROI->nHeight = dwValue;

	return TRUE;
}

BOOL CCLFile::SetRoi(INFO_ROI_PARA stROI)
{
	BOOL bResult = SetRoi(stROI.nXstart, stROI.nYstart, stROI.nWidth, stROI.nHeight);
	return bResult;
}


BOOL CCLFile::GetMaxWidth(DWORD* pdwValue)
{
	const INFO_CAM_DEVICE* pstCamDev = GetCameraDevice();
	if (NULL == pstCamDev || NULL == pdwValue)
		return FALSE;

	*pdwValue = pstCamDev->m_dwMaxWidth;
	return TRUE;
}

BOOL CCLFile::GetMaxHeight(DWORD* pdwValue)
{
	const INFO_CAM_DEVICE* pstCamDev = GetCameraDevice();
	if (NULL == pstCamDev || NULL == pdwValue)
		return FALSE;

	*pdwValue = pstCamDev->m_dwMaxHeight;
	return TRUE;
}

BOOL CCLFile::GetX(DWORD* pdwValue)
{
	const INFO_USER_SETTING* pstSetting = GetUserSetting();
	if (NULL == pstSetting || NULL == pdwValue)
		return FALSE;

	*pdwValue = pstSetting->m_stMain.m_stRoi.m_nX;
	return TRUE;
}

BOOL CCLFile::GetY(DWORD* pdwValue)
{
	const INFO_USER_SETTING* pstSetting = GetUserSetting();
	if (NULL == pstSetting || NULL == pdwValue)
		return FALSE;

	*pdwValue = pstSetting->m_stMain.m_stRoi.m_nY;
	return TRUE;
}

BOOL CCLFile::GetWidth(DWORD* pdwValue)
{
	const INFO_USER_SETTING* pstSetting = GetUserSetting();
	if (NULL == pstSetting || NULL == pdwValue)
		return FALSE;

	*pdwValue = pstSetting->m_stMain.m_stRoi.m_dwWidth;
	return TRUE;
}

BOOL CCLFile::GetHeight(DWORD* pdwValue)
{
	const INFO_USER_SETTING* pstSetting = GetUserSetting();
	if (NULL == pstSetting || NULL == pdwValue)
		return FALSE;

	*pdwValue = pstSetting->m_stMain.m_stRoi.m_dwHeight;
	return TRUE;
}

BOOL CCLFile::GetPixelFormat(DWORD* pdwValue)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CCLFile::SetPixelFormat(DWORD dwValue)
{
	BOOL bResult = FALSE;
	return bResult;
}


// 
BOOL CCLFile::SetTrigger()
{
	::EnterCriticalSection(&m_CriticalSection);

	/*//
	const int nMaxWait = 0;
	int nSleep = 0;
	
	const LONGLONG CURTICK = ::GetTickCount64();
	const LONGLONG LASTTRIGGER = m_LastSWTrigger;
	
	m_LastSWTrigger = CURTICK;
	if (0 == LASTTRIGGER || 0 != LASTTRIGGER && LASTTRIGGER > CURTICK)
	{
		m_LastSWTrigger = CURTICK;
	}
	else
	{
		LONGLONG delta = CURTICK - LASTTRIGGER;
		if (nMaxWait > delta)
		{
			nSleep = nMaxWait - delta;
			CUtil::Sleep(nMaxWait - delta);
		}
	}
	//*/

	McSetParamInt(m_stEuresys.m_Channel, MC_ChannelState, MC_ChannelState_ACTIVE);
	McSetParamInt(m_stEuresys.m_Channel, MC_ForceTrig, MC_ForceTrig_TRIG);

	::LeaveCriticalSection(&m_CriticalSection);

	return TRUE;
}

BOOL CCLFile::GetTriggerMode(INFO_TRIGGER_PARA* pstTrigger)
{
#ifndef AGING_ONLY_FRAMEGRABBER
	const INFO_USER_SETTING* pstSetting = GetUserSetting();
	if (NULL == pstSetting)
		return FALSE;

	if (TYPE_TRIGGER_OFF == pstSetting->m_stTrigger.m_eTrigger)
	{
		pstTrigger->nTriggerMode = TRIGGER_OFF;
		pstTrigger->nTriggerSource = TRIGGER_SRC_SW;
	}
	else if (TYPE_TRIGGER_EXTERNAL == pstSetting->m_stTrigger.m_eTrigger)
	{
		pstTrigger->nTriggerMode = TRIGGER_ON;
		pstTrigger->nTriggerSource = TRIGGER_SRC_LINE;
	}
	else if (TYPE_TRIGGER_BOARDCONTROL == pstSetting->m_stTrigger.m_eTrigger)
	{
		pstTrigger->nTriggerMode = TRIGGER_ON;
		pstTrigger->nTriggerSource = TRIGGER_SRC_SW;
	}
	else
		return FALSE;
	
	if (TYPE_SENSOR_EXPOSURE_EDGE == pstSetting->m_stTrigger.m_eSensorExposure)
	{
		if (TYPE_TRIGGER_POLARITY_LOW == pstSetting->m_stTrigger.m_eTriggerPolarity)
			pstTrigger->nTriggerTypePolarity = TRIGGER_EDGE_NEGATIVE;
		else if (TYPE_TRIGGER_POLARITY_HIGH == pstSetting->m_stTrigger.m_eTriggerPolarity)
			pstTrigger->nTriggerTypePolarity = TRIGGER_EDGE_POSITIVE;
	}
	else if (TYPE_SENSOR_EXPOSURE_PULSE == pstSetting->m_stTrigger.m_eSensorExposure)
	{
		if (TYPE_TRIGGER_POLARITY_LOW == pstSetting->m_stTrigger.m_eTriggerPolarity)
			pstTrigger->nTriggerTypePolarity = TRIGGER_LEVEL_NEGATIVE;
		else if (TYPE_TRIGGER_POLARITY_HIGH == pstSetting->m_stTrigger.m_eTriggerPolarity)
			pstTrigger->nTriggerTypePolarity = TRIGGER_LEVEL_POSITIVE;
	}	
	else
	{
		return FALSE;
	}
	pstTrigger->nTriggerDelay = pstSetting->m_stTrigger.m_stTriggerDelay.m_nCur;
#else
	if (TYPE_TRIGGER_OFF == m_stUserSetting.m_stTrigger.m_eTrigger)
	{
		pstTrigger->nTriggerMode = TRIGGER_OFF;
		pstTrigger->nTriggerSource = TRIGGER_SRC_SW;
	}
	else if (TYPE_TRIGGER_EXTERNAL == m_stUserSetting.m_stTrigger.m_eTrigger)
	{
		pstTrigger->nTriggerMode = TRIGGER_ON;
		pstTrigger->nTriggerSource = TRIGGER_SRC_LINE;
	}
	else if (TYPE_TRIGGER_BOARDCONTROL == m_stUserSetting.m_stTrigger.m_eTrigger)
	{
		pstTrigger->nTriggerMode = TRIGGER_ON;
		pstTrigger->nTriggerSource = TRIGGER_SRC_SW;
	}
#endif

	return TRUE;
}

BOOL CCLFile::SetTriggerMode(INFO_TRIGGER_PARA stTrigger)
{
	TYPE_TRIGGER eTrigger = TYPE_TRIGGER_NONE;
	TYPE_TRIGGER_POLARITY ePolarity = TYPE_TRIGGER_POLARITY_NONE;
	TYPE_SENSOR_EXPOSURE eExposure = TYPE_SENSOR_EXPOSURE_NONE;

	if (stTrigger.nTriggerMode) // Trigger On
	{
		if (TRIGGER_SRC_LINE == stTrigger.nTriggerSource)	// Line
			eTrigger = TYPE_TRIGGER_EXTERNAL;
		else //if (TRIGGER_SRC_SW == stTrigger.nTriggerSource)	// SW
			eTrigger = TYPE_TRIGGER_BOARDCONTROL;
	}
	else  // Trigger Off
	{
		eTrigger = TYPE_TRIGGER_OFF;
	}

	if (TRIGGER_EDGE_NEGATIVE == stTrigger.nTriggerTypePolarity || TRIGGER_EDGE_POSITIVE == stTrigger.nTriggerTypePolarity)
	{
		eExposure = TYPE_SENSOR_EXPOSURE_EDGE;

		if (TRIGGER_EDGE_NEGATIVE == stTrigger.nTriggerTypePolarity)
			ePolarity = TYPE_TRIGGER_POLARITY_LOW;
		else if (TRIGGER_EDGE_POSITIVE == stTrigger.nTriggerTypePolarity)
			ePolarity = TYPE_TRIGGER_POLARITY_HIGH;
	}
	else if (TRIGGER_LEVEL_NEGATIVE == stTrigger.nTriggerTypePolarity || TRIGGER_LEVEL_POSITIVE == stTrigger.nTriggerTypePolarity)
	{
		eExposure = TYPE_SENSOR_EXPOSURE_PULSE;

		if (TRIGGER_LEVEL_NEGATIVE == stTrigger.nTriggerTypePolarity)
			ePolarity = TYPE_TRIGGER_POLARITY_LOW;
		else if (TRIGGER_LEVEL_POSITIVE == stTrigger.nTriggerTypePolarity)
			ePolarity = TYPE_TRIGGER_POLARITY_HIGH;
	}
	else
	{
		return FALSE;
	}

	////////////////////
	m_bStart = FALSE;
	CloseEuresys();
	Sleep(100);

	BOOL bResult = FALSE;

	if (pfStop)
		(*pfStop)(m_hCameraLib);

	if (TYPE_TRIGGER_OFF != eTrigger)
	{
		if (pfSetTriggerDelayTime)
			bResult = (*pfSetTriggerDelayTime)(m_hCameraLib, stTrigger.nTriggerDelay);
		if (bResult && pfSetSensorExposureTime)
			bResult = (*pfSetSensorExposureTime)(m_hCameraLib, eExposure);

		if (bResult && pfSetTrigger)
			bResult = (*pfSetTrigger)(m_hCameraLib, eTrigger, ePolarity);
	}
	else
	{
		if (pfSetTrigger)
			bResult = (*pfSetTrigger)(m_hCameraLib, TYPE_TRIGGER_OFF, TYPE_TRIGGER_POLARITY_HIGH);
	}

	if (pfStart)
		(*pfStart)(m_hCameraLib);


	UpdateUserSetting();
	return bResult;
}

BOOL CCLFile::GetTriggerDelay(DWORD* pDelay)
{
	const INFO_USER_SETTING* pstSetting = GetUserSetting();
	if (NULL == pstSetting)
		return FALSE;
	*pDelay = pstSetting->m_stTrigger.m_stTriggerDelay.m_nCur;

	return TRUE;
}
BOOL CCLFile::SetTriggerDelay(DWORD dwDelay)
{
	BOOL bResult = FALSE;
	if(pfSetTriggerDelayTime)
		bResult = (*pfSetTriggerDelayTime)(m_hCameraLib, dwDelay);

	UpdateUserSetting();
	return bResult;
}


//
BOOL CCLFile::GetStrobeMode(INFO_STROBE_PARA* pstStrobe)
{
	const INFO_USER_SETTING* pstSetting = GetUserSetting();
	if (NULL == pstSetting || NULL == pstStrobe)
		return FALSE;
	DWORD dwValue = 0;

	pstStrobe->nStrobeMode = pstSetting->m_stTrigger.m_bStrobe;

	if (TYPE_STROBE_SYNC_BYPASS == pstSetting->m_stTrigger.m_eStrobeSync)
		pstStrobe->nStrobeSync = STROBE_SYNC_BYPASS;
	else //if (TYPE_STROBE_SYNC_EXPOSURE == pstSetting->m_stTrigger.m_eStrobeSync)
		pstStrobe->nStrobeSync = STROBE_SYNC_EXPOSURE;

	if (TYPE_STROBE_POLARITY_LOW == pstSetting->m_stTrigger.m_eStrobePolarity)
		pstStrobe->nStrobePolarity = STROBE_POLA_NEGATIVE;
	else //if (TYPE_STROBE_POLARITY_HIGH == pstSetting->m_stTrigger.m_eStrobePolarity)
		pstStrobe->nStrobePolarity = STROBE_POLA_POSITIVE;

	if (GetStrobeWidth(&dwValue))
		pstStrobe->nStrobeWidth = dwValue;
	else
		pstStrobe->nStrobeWidth = 0;

	if(GetStrobeDelay(&dwValue))
		pstStrobe->nStrobeDelay = dwValue;
	else
		pstStrobe->nStrobeDelay = 0;
	
	return TRUE;
}

BOOL CCLFile::SetStrobeMode(INFO_STROBE_PARA stStrobe)
{

	BOOL bEnable = stStrobe.nStrobeMode;
	TYPE_STROBE_POLARITY ePolarity = TYPE_STROBE_POLARITY_NONE;
	TYPE_STROBE_SYNC eSync = TYPE_STROBE_SYNC_NONE;

	if (STROBE_SYNC_EXPOSURE == stStrobe.nStrobeSync)
		eSync = TYPE_STROBE_SYNC_EXPOSURE;
	else //if (STROBE_SYNC_BYPASS == stStrobe.nStrobeSync)
		eSync = TYPE_STROBE_SYNC_BYPASS;

	if (STROBE_POLA_NEGATIVE == stStrobe.nStrobePolarity)
		ePolarity = TYPE_STROBE_POLARITY_LOW;
	else
		ePolarity = TYPE_STROBE_POLARITY_HIGH;

	BOOL bResult = FALSE;

	bResult = SetStrobeDelay(stStrobe.nStrobeDelay);
	if (bResult)
		bResult = SetStrobeWidth(stStrobe.nStrobeWidth);

	if (pfSetStrobeSync && bResult)
		bResult = (*pfSetStrobeSync)(m_hCameraLib, eSync);

	if (pfSetStrobePolarity && bResult)
		bResult = (*pfSetStrobePolarity)(m_hCameraLib, bEnable, ePolarity);


	UpdateUserSetting();
	return bResult;
}

BOOL CCLFile::GetStrobeDelay(DWORD* pDelay)
{
	const INFO_USER_SETTING* pstSetting = GetUserSetting();
	if (NULL == pstSetting)
		return FALSE;
	*pDelay = pstSetting->m_stTrigger.m_stStrobeDelay.m_nCur;

	return TRUE;
}

BOOL CCLFile::SetStrobeDelay(DWORD dwDelay)
{
	BOOL bResult = FALSE;
	if (pfSetStrobeDelayTime)
		bResult = (*pfSetStrobeDelayTime)(m_hCameraLib, dwDelay);

	UpdateUserSetting();
	return bResult;
}

BOOL CCLFile::GetStrobeWidth(DWORD* pWidth)
{
	const INFO_USER_SETTING* pstSetting = GetUserSetting();
	if (NULL == pstSetting || NULL == pWidth)
		return FALSE;
	*pWidth = pstSetting->m_stTrigger.m_stStrobeDuration.m_nCur;

	return TRUE;
}

BOOL CCLFile::SetStrobeWidth(DWORD dwWidth)
{
	BOOL bResult = FALSE;
	if (pfSetStrobeDurationTime)
		bResult = (*pfSetStrobeDurationTime)(m_hCameraLib, dwWidth);

	return bResult;
}


//
BOOL CCLFile::GetGainDigital(DWORD* pGain)
{
	const INFO_USER_SETTING* pstSetting = GetUserSetting();
	if (NULL == pstSetting || NULL == pGain)
		return FALSE;
	*pGain = pstSetting->m_stAnalog.m_stDigital.m_nCur;

	return TRUE;
}

BOOL CCLFile::SetGainDigital(DWORD dwGain)
{
	BOOL bResult = FALSE;
	if (pfSetDigitalGain)
		bResult = (*pfSetDigitalGain)(m_hCameraLib, dwGain);

	return bResult;
}

BOOL CCLFile::GetGainAnalog(DWORD* pGain)
{
	const INFO_USER_SETTING* pstSetting = GetUserSetting();
	if (NULL == pstSetting || NULL == pGain)
		return FALSE;
	*pGain = pstSetting->m_stAnalog.m_stAnalog.m_nCur;

	return TRUE;
}

BOOL CCLFile::SetGainAnalog(DWORD dwGain)
{
	BOOL bResult = FALSE;
	if (pfSetAnalogGain)
		bResult = (*pfSetAnalogGain)(m_hCameraLib, dwGain);

	return bResult;
}

//
BOOL CCLFile::GetExposureTime(DWORD* pExTime)
{
	const INFO_USER_SETTING* pstSetting = GetUserSetting();
	if (NULL == pstSetting || NULL == pExTime)
		return FALSE;
	*pExTime = pstSetting->m_stAnalog.m_stExposure.m_nCur;

	return TRUE;
}

BOOL CCLFile::SetExposureTime(DWORD dwExTime)
{
	BOOL bResult = FALSE;
	if (pfSetExposure)
		bResult = (*pfSetExposure)(m_hCameraLib, dwExTime);

	return bResult;
}

BOOL CCLFile::GetFps(DWORD* pFps)
{
	const INFO_USER_SETTING* pstSetting = GetUserSetting();
	if (NULL == pstSetting || NULL == pFps)
		return FALSE;
	*pFps = pstSetting->m_stAnalog.m_stFPS.m_nCur;

	return TRUE;
}

BOOL CCLFile::SetFps(DWORD dwFps)
{
	BOOL bResult = FALSE;
	if (pfSetFramerate)
		bResult = (*pfSetFramerate)(m_hCameraLib, dwFps);

	return bResult;
}

BOOL CCLFile::SetDataBit(unsigned short nDataBit)
{
	TYPE_DATA_BIT eDataBit = TYPE_DATA_BIT_NONE;
	if (8 == nDataBit)			eDataBit = TYPE_DATA_BIT_08;
	else if (10 == nDataBit)	eDataBit = TYPE_DATA_BIT_10;
	else
		return FALSE;

	BOOL bResult = FALSE;

	if (pfSetDataBit)
		bResult = (*pfSetDataBit)(m_hCameraLib, eDataBit);

	return bResult;
}

BOOL CCLFile::GetDataBit(unsigned short* nDataBit)
{
	const INFO_USER_SETTING* pstSetting = GetUserSetting();
	if (NULL == pstSetting || NULL == nDataBit)
		return FALSE;

	if (TYPE_DATA_BIT_08 == pstSetting->m_stMain.m_eDataBit)
		*nDataBit = 8;
	else if (TYPE_DATA_BIT_08 == pstSetting->m_stMain.m_eDataBit)
		*nDataBit = 10;
	else
		return FALSE;

	return TRUE;
}


// Userset
BOOL CCLFile::LoadUserset(DWORD dwUserset)
{
	TYPE_MENU_USERSET eUserSet = TYPE_MENU_USERSET_FACTORY;

	if (1 == dwUserset)			eUserSet = TYPE_MENU_USERSET_01;
	else if (2 == dwUserset)	eUserSet = TYPE_MENU_USERSET_02;
	else if (3 == dwUserset)	eUserSet = TYPE_MENU_USERSET_03;
	else if (4 == dwUserset)	eUserSet = TYPE_MENU_USERSET_04;
	else if (5 == dwUserset)	eUserSet = TYPE_MENU_USERSET_05;
	else if (6 == dwUserset)	eUserSet = TYPE_MENU_USERSET_06;
	else if (7 == dwUserset)	eUserSet = TYPE_MENU_USERSET_07;
	else if (8 == dwUserset)	eUserSet = TYPE_MENU_USERSET_08;

	BOOL bResult = FALSE;
	if (pfLoadEepromUserSet)
	{
		INFO_USER_SETTING stSetting;
		memset(&stSetting, 0x00, sizeof(INFO_USER_SETTING));

		bResult = (*pfLoadEepromUserSet)(m_hCameraLib, eUserSet, &stSetting);
	}

	return bResult;
}

BOOL CCLFile::SaveUserset(DWORD dwUserset)
{
	TYPE_MENU_USERSET eUserSet = TYPE_MENU_USERSET_FACTORY;

	if (1 == dwUserset)			eUserSet = TYPE_MENU_USERSET_01;
	else if (2 == dwUserset)	eUserSet = TYPE_MENU_USERSET_02;
	else if (3 == dwUserset)	eUserSet = TYPE_MENU_USERSET_03;
	else if (4 == dwUserset)	eUserSet = TYPE_MENU_USERSET_04;
	else if (5 == dwUserset)	eUserSet = TYPE_MENU_USERSET_05;
	else if (6 == dwUserset)	eUserSet = TYPE_MENU_USERSET_06;
	else if (7 == dwUserset)	eUserSet = TYPE_MENU_USERSET_07;
	else if (8 == dwUserset)	eUserSet = TYPE_MENU_USERSET_08;
	else
		return FALSE;

	BOOL bResult = FALSE;
	if (pfSaveEepromUserSet)
	{
		bResult = (*pfSaveEepromUserSet)(m_hCameraLib, eUserSet);
	}
	return bResult;
}

BOOL CCLFile::GetStartupUserset(DWORD* pUserset)
{
	if (NULL == pUserset)
		return FALSE;

	BOOL bResult = FALSE;
	if (pfGetStartUpUserSet)
	{
		TYPE_MENU_USERSET eUserSet = TYPE_MENU_USERSET_FACTORY;

		bResult = (*pfGetStartUpUserSet)(m_hCameraLib, &eUserSet);
		if (bResult)
		{
			if (TYPE_MENU_USERSET_01 == eUserSet)		*pUserset = 1;
			else if (TYPE_MENU_USERSET_02 == eUserSet)	*pUserset = 2;
			else if (TYPE_MENU_USERSET_03 == eUserSet)	*pUserset = 3;
			else if (TYPE_MENU_USERSET_04 == eUserSet)	*pUserset = 4;
			else if (TYPE_MENU_USERSET_05 == eUserSet)	*pUserset = 5;
			else if (TYPE_MENU_USERSET_06 == eUserSet)	*pUserset = 6;
			else if (TYPE_MENU_USERSET_07 == eUserSet)	*pUserset = 7;
			else if (TYPE_MENU_USERSET_08 == eUserSet)	*pUserset = 8;
			else *pUserset = 0;
		}
	}
	return bResult;
}

BOOL CCLFile::SetStartupUserset(DWORD dwUserset)
{
	BOOL bResult = FALSE;
	if (pfSetStartUpUserSet)
	{
		TYPE_MENU_USERSET eUserSet = TYPE_MENU_USERSET_FACTORY;

		if (1 == dwUserset)			eUserSet = TYPE_MENU_USERSET_01;
		else if (2 == dwUserset)	eUserSet = TYPE_MENU_USERSET_02;
		else if (3 == dwUserset)	eUserSet = TYPE_MENU_USERSET_03;
		else if (4 == dwUserset)	eUserSet = TYPE_MENU_USERSET_04;
		else if (5 == dwUserset)	eUserSet = TYPE_MENU_USERSET_05;
		else if (6 == dwUserset)	eUserSet = TYPE_MENU_USERSET_06;
		else if (7 == dwUserset)	eUserSet = TYPE_MENU_USERSET_07;
		else if (8 == dwUserset)	eUserSet = TYPE_MENU_USERSET_08;

		bResult = (*pfSetStartUpUserSet)(m_hCameraLib, eUserSet);
	}
	return bResult;
}


// LUT
BOOL CCLFile::SetLutMode(unsigned short nMode)
{
	BOOL bResult = FALSE;

	BOOL bEnable = nMode & 0x0F;
	if (bEnable)
	{		
		int nIdx = (nMode & 0xF0) >> 4;
		if (pfSetLutIndex)
			(*pfSetLutIndex)(m_hCameraLib, nIdx);
	}

	if (pfSetEnableLut)
		bResult = (*pfSetEnableLut)(m_hCameraLib, bEnable);

	UpdateUserSetting();
	return bResult;	
}

BOOL CCLFile::GetLutMode(unsigned short* pnMode)
{
	const INFO_USER_SETTING* pstSetting = GetUserSetting();
	if (NULL == pstSetting || NULL == pnMode)
		return FALSE;

	const BOOL bEnable = pstSetting->m_stLut.m_bEnable;
	int nIdx = 0;

	if (TYPE_LUT_USERSET_01 == pstSetting->m_stLut.m_eUserset)			nIdx = 0;
	else if (TYPE_LUT_USERSET_02 == pstSetting->m_stLut.m_eUserset)		nIdx = 1;
	else if (TYPE_LUT_USERSET_03 == pstSetting->m_stLut.m_eUserset)		nIdx = 2;
	else if (TYPE_LUT_USERSET_04 == pstSetting->m_stLut.m_eUserset)		nIdx = 3;
	else if (TYPE_LUT_USERSET_05 == pstSetting->m_stLut.m_eUserset)		nIdx = 4;
	else if (TYPE_LUT_USERSET_06 == pstSetting->m_stLut.m_eUserset)		nIdx = 5;
	else if (TYPE_LUT_USERSET_07 == pstSetting->m_stLut.m_eUserset)		nIdx = 6;
	else if (TYPE_LUT_USERSET_08 == pstSetting->m_stLut.m_eUserset)		nIdx = 7;

	*pnMode = (nIdx<<4) | bEnable;

	return TRUE;
}

BOOL CCLFile::WriteLut(const INFO_LUT_PARA* pLutList, const int nLen, BOOL bEeprom)
{
	const INFO_CAM_DEVICE* pstCam = GetCameraDevice();
	if (NULL == pstCam || NULL == pLutList)
		return FALSE;

	if (bEeprom && pstCam->m_stLutFeature.m_dwMaxCount != nLen)
		return FALSE;

	BOOL bResult = FALSE;

	const int nMaxPoint = pstCam->m_stLutFeature.m_dwMaxValue;
	if (pstCam->m_stLutFeature.m_dwMaxCount == nLen)
	{
		INFO_LUT_TABLE* pTableList = new INFO_LUT_TABLE[nLen];
		memset(pTableList, 0x00, sizeof(INFO_LUT_TABLE)*nLen);

		for (int i = 0; i < nLen; i++)
		{
			for (int p = 0; p < nMaxPoint; p++)
			{
				pTableList[i].m_stPos[p].m_nX = pLutList[i].m_PointList[p].x;
				pTableList[i].m_stPos[p].m_nY = pLutList[i].m_PointList[p].y;
			}
		}

		if (pfWriteLutTable)
			bResult = (*pfWriteLutTable)(m_hCameraLib, pTableList, nLen, bEeprom);

		delete[] pTableList;
	}
	return bResult;
}




//
BOOL CCLFile::ReadFpgaRegAddress(const DWORD dwAddress, DWORD* pdwValue)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CCLFile::WriteFpgaRegAddress(const DWORD dwAddress, DWORD dwValue)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CCLFile::ReadSensorRegAddress(const DWORD dwAddress, DWORD* pdwValue)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CCLFile::WriteSensorRegAddress(const DWORD dwAddress, DWORD dwValue)
{
	BOOL bResult = FALSE;
	return bResult;
}



DWORD WINAPI CCLFile::ThreadClProc(LPVOID lpArg)
{
	CCLFile* pClFile = (CCLFile*)lpArg;
	return pClFile->ThreadClProc();
}

DWORD CCLFile::ThreadClProc(void)
{
	m_bStopCl = FALSE;

	if (m_hEventClAcq)
		::ResetEvent(m_hEventClAcq);

	do
	{
		if (::WaitForSingleObject(m_hEventClAcq, INFINITE) != WAIT_OBJECT_0)
		{
			break;
		}
		else
		{
			if (m_hEventClAcq)
				::ResetEvent(m_hEventClAcq);
			else
				break;

			if (m_bStopCl)
				break;

			if (m_pFunc && m_bStart)
			{
				(*m_pFunc)((BYTE*)(m_stEuresys.m_pCurrent), m_stEuresys.m_nPitch * m_stEuresys.m_nSizeY, NULL, m_pFuncArg);
			}
		}

	} while (FALSE == m_bStopCl);

	if (m_hEventClStop)
		SetEvent(m_hEventClStop);

	return 0;
}