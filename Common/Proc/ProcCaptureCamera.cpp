#include "StdAfx.h"
#include "ProcCaptureCamera.h"
#include "Util/Util.h"

#pragma warning(disable:4996)
#if defined(_WIN64)
	#pragma comment (lib, "LibCameraInterface_x64.lib")
#else
	#pragma comment (lib, "LibCameraInterface.lib")
#endif

CProcCaptureCamera::CProcCaptureCamera()
{
	m_bStop	= FALSE;
	m_bSkipFrame = FALSE;

	memset(&m_stFrame, 0x00, sizeof(INFO_FRAME));

	// Thread - Display
	m_hThread		= NULL;
	m_hEvent		= NULL;
	m_hStopEvent	= NULL;

	m_hCamera		= NULL;
	m_eNetwork		= TYPE_NETWORK_NONE;
	m_nCameraId		= -1;

	m_hWnd			= NULL;

	m_eProcessState	= TYPE_STATE_PROCESS_NONE;

#ifdef TRIGGER_TIMEOUT
	// Thread - TimeOut
	m_hThreadTimeOut= NULL;
	m_hEventTimeOut	= NULL;

	m_bCheckTimeOut	= TRUE;
	m_bWaitAcq		= FALSE;
	m_dwTimeOut		= TIMEOUT_WAIT_TIME;
	m_bSearchDevice = FALSE;

	m_pstTimeOutDevice = NULL;

	m_stTimeoutRange.m_dwFrom = 100;
	m_stTimeoutRange.m_dwTo = 10000;
#endif
}

CProcCaptureCamera::~CProcCaptureCamera()
{
	;
}

BOOL CProcCaptureCamera::CreateCameraProcess(HCAMERA hCamera, int nCamId, HWND hWnd, INFO_VIDEODEV_ARG* pVideoArg)
{
	if (NULL == hCamera || NULL == hWnd || NULL == pVideoArg)
		return FALSE;

	m_hCamera	= hCamera;
	m_nCameraId	= nCamId;
	m_hWnd		= hWnd;

	m_bStop		= FALSE;
	m_bSkipFrame = FALSE;

	const TYPE_NETWORK eNetwork = ::GetNetworkType(m_hCamera);
	m_eNetwork = eNetwork;

	BOOL bResult = ::GetFrameInfo(m_hCamera, m_nCameraId, &m_stFrame);
	if (FALSE == bResult)
	{
		DestoryCameraProcess();
		return FALSE;
	}
	m_stFrame.m_eNetwork = eNetwork;


	// Set callback function...
	bResult = ::SetEventFunc(m_hCamera, m_nCameraId, AcquisitionEventHandler, this);
	if (FALSE == bResult)
	{
		DestoryCameraProcess();
		return FALSE;
	}
	// Create memory list...
	bResult = m_ProcessBuffer.CreateBuffer(&m_stFrame, MAX_PROCBUFFER_COUNT);
	if (FALSE == bResult)
	{
		DestoryCameraProcess();
		return FALSE;
	}

	// Display...
	if (pVideoArg)
	{
		m_VideoCallback.m_FuncDisplayDev = pVideoArg->m_FuncDisplayDev;
		m_VideoCallback.m_pArgument = pVideoArg->m_pArgument;
	}

	

	m_hEvent = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_hEvent)
	{
		DestoryCameraProcess();
		return FALSE;
	}
	m_hStopEvent = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_hStopEvent)
	{
		DestoryCameraProcess();
		return FALSE;
	}

	DWORD dwThreadId = 0;
	m_hThread = ::CreateThread(0, 0, ThreadProc, LPVOID(this), 0, &dwThreadId);
	if (NULL == m_hThread)
	{
		DestoryCameraProcess();
		return FALSE;
	}
	//::SetThreadPriority(m_hThread, PROC_THREAD_PRIORITY_FLAG);

	SetProcessState(TYPE_STATE_PROCESS_STOP);

#ifdef TRIGGER_TIMEOUT
	m_hEventTimeOut = ::CreateEvent(0, TRUE, FALSE, 0);
	// Thread - TimeOut
	dwThreadId = 1;
	m_hThreadTimeOut = ::CreateThread(0, 0, ThreadTimeOutProc, LPVOID(this), 0, &dwThreadId);
	//if (m_hThreadTimeOut)
	//	::SetThreadPriority(m_hThreadTimeOut, PROC_THREAD_PRIORITY_FLAG);
#endif
	return TRUE;
}

BOOL CProcCaptureCamera::CheckConnectInfo(const INFO_CONNECT_DEV* pstDevice)
{
	if (NULL == pstDevice || NULL == m_hCamera)
		return FALSE;

	INFO_CONNECT_DEV* pstDev = NULL;

	BOOL bResult = FALSE;

	if(TYPE_NETWORK_GIGE == pstDevice->m_eNetwork)
	{
		INFO_CONNECT_GIGE stGigE;
		memset(&stGigE, 0x00, sizeof(INFO_CONNECT_GIGE));
		stGigE.m_stArg.m_eNetwork = TYPE_NETWORK_GIGE;

		bResult = ::GetDeviceInfo(m_hCamera, m_nCameraId, (INFO_CONNECT_DEV*)&stGigE);
		if(bResult)
			pstDev = &stGigE.m_stArg;
	}
	else if(TYPE_NETWORK_ETHERNET == pstDevice->m_eNetwork)
	{
		INFO_CONNECT_ETHERNET stEth;
		memset(&stEth, 0x00, sizeof(INFO_CONNECT_ETHERNET));
		stEth.m_stArg.m_eNetwork = TYPE_NETWORK_ETHERNET;

		bResult = ::GetDeviceInfo(m_hCamera, m_nCameraId, (INFO_CONNECT_DEV*)&stEth);
		if(bResult)
			pstDev = &stEth.m_stArg;
	}
	else if(TYPE_NETWORK_USB == pstDevice->m_eNetwork)
	{
		INFO_CONNECT_USB stUsb;
		memset(&stUsb, 0x00, sizeof(INFO_CONNECT_USB));
		stUsb.m_stArg.m_eNetwork = TYPE_NETWORK_USB;

		bResult = ::GetDeviceInfo(m_hCamera, m_nCameraId, (INFO_CONNECT_DEV*)&stUsb);
		if(bResult)
			pstDev = &stUsb.m_stArg;
	}
	else if (TYPE_NETWORK_CAMERALINK == pstDevice->m_eNetwork)
	{
		INFO_CONNECT_CAMERALINK stCL;
		memset(&stCL, 0x00, sizeof(INFO_CONNECT_CAMERALINK));
		stCL.m_stArg.m_eNetwork = TYPE_NETWORK_CAMERALINK;

		bResult = ::GetDeviceInfo(m_hCamera, m_nCameraId, (INFO_CONNECT_DEV*)&stCL);
		if (bResult && 0 == _tcscmp(stCL.m_szName, (LPTSTR)((INFO_CONNECT_CAMERALINK*)pstDevice)->m_szName))
			pstDev = &stCL.m_stArg;
	}
	else if(TYPE_NETWORK_EMULFILE == pstDevice->m_eNetwork)
	{
		INFO_CONNECT_EMUL stEmul;
		memset(&stEmul, 0x00, sizeof(INFO_CONNECT_EMUL));
		stEmul.m_stArg.m_eNetwork = TYPE_NETWORK_EMULFILE;

		bResult = ::GetDeviceInfo(m_hCamera, m_nCameraId, (INFO_CONNECT_DEV*)&stEmul);
		if(bResult)
			pstDev = &stEmul.m_stArg;
	}
	else if (TYPE_NETWORK_BASLER == pstDevice->m_eNetwork)
	{
		INFO_CONNECT_OTHER_MANUFACTURER stBasler;
		memset(&stBasler, 0x00, sizeof(INFO_CONNECT_ETHERNET));
		stBasler.m_stArg.m_eNetwork = TYPE_NETWORK_BASLER;

		bResult = ::GetDeviceInfo(m_hCamera, m_nCameraId, (INFO_CONNECT_DEV*)&stBasler);
		if (bResult)
			pstDev = &stBasler.m_stArg;
	}
	else
	{
		return FALSE;
	}

	if(bResult && pstDev)
	{
		if( pstDevice->m_eNetwork==pstDev->m_eNetwork &&
			pstDevice->m_dwArg == pstDev->m_dwArg &&
			0 == _tcscmp((LPTSTR)pstDevice->m_szArg, (LPTSTR)pstDev->m_szArg))
		{
			bResult = TRUE;
		}
		else
		{
			bResult = FALSE;
		}
	}
	else
	{
		return FALSE;
	}
	 
	return bResult;
}



void CProcCaptureCamera::DestoryCameraProcess()
{
	Stop();
	SetEventFunc(m_hCamera, m_nCameraId, NULL, NULL);
	m_hCamera = NULL;

	m_bStop = TRUE;
	if (m_hEvent)
	{
		::SetEvent(m_hEvent);
		
		if(m_hStopEvent)
		{
			::ResetEvent(m_hStopEvent);
			::WaitForSingleObject(m_hStopEvent, 5000);
			::CloseHandle(m_hStopEvent);
		}
		::CloseHandle(m_hEvent);
	}

	if (m_hThread)
		::CloseHandle(m_hThread);

	// Clear queue.
	while(!m_BufferQueue.empty())
		m_BufferQueue.pop();


	m_hStopEvent	= NULL;
	m_hEvent		= NULL;
	m_hThread		= NULL;
	
	m_ProcessBuffer.DestoryBuffer();
	SetProcessState(TYPE_STATE_PROCESS_NONE);


#ifdef TRIGGER_TIMEOUT
	SetEnableTriggerTimeOut(FALSE);

	if (m_hEventTimeOut && m_hThreadTimeOut)
		m_bSearchDevice = TRUE;
	else
		m_bSearchDevice = FALSE;

	if (m_hEventTimeOut)
		::SetEvent(m_hEventTimeOut);
	if (m_hThreadTimeOut)
		::CloseHandle(m_hThreadTimeOut);

	while (m_bSearchDevice || m_pstTimeOutDevice)
	{
		CUtil::Sleep(10);
	}
	CUtil::PrintDebugString(_T("		Destroyed... \r\n"));

#endif


}

BOOL CProcCaptureCamera::Start(BOOL bSingleFrame)
{
	BOOL bResult= FALSE;

	if (m_hCamera)
	{
		bResult = ::StartCamera(m_hCamera, m_nCameraId, bSingleFrame);
	}
	
	if(bResult)
	{
		SetProcessState(TYPE_STATE_PROCESS_START);
		m_dwCurrentTick = ::GetTickCount();
	}

	return bResult;
}

void CProcCaptureCamera::Stop()
{
#ifdef TRIGGER_TIMEOUT
	if (m_bCheckTimeOut)
	{
		m_bWaitAcq = FALSE;
	}
#endif

	if (m_hCamera)
	{
		::StopCamera(m_hCamera, m_nCameraId);
	}
	SetProcessState(TYPE_STATE_PROCESS_STOP);

}

void CProcCaptureCamera::Close()
{
#ifdef TRIGGER_TIMEOUT
	if (m_bCheckTimeOut)
	{
		m_bWaitAcq = FALSE;
	}
#endif

	if (m_hCamera)
	{
		::CloseCamera(m_hCamera, m_nCameraId);
	}

	Sleep(100);
	SetProcessState(TYPE_STATE_PROCESS_STOP);
}

void CALLBACK CProcCaptureCamera::AcquisitionEventHandler(unsigned char* pBuffer, unsigned int nSize, void* pReserved, void* lpArg)
{
	if (NULL == lpArg || NULL == pBuffer)
		return;

	CProcCaptureCamera* pProcess = (CProcCaptureCamera*) lpArg;
	if (pProcess->m_bStop)
		return;

#ifdef TEST_DUMP
	/*//
	{
		if (TYPE_NETWORK_USB == pProcess->m_eNetwork)
		{
			INFO_TRIGGER_PARA stTrigger;
			pProcess->GetTriggerMode(&stTrigger);

			if (TRIGGER_ON == stTrigger.nTriggerMode)
			{
				SYSTEMTIME stTime;
				::GetLocalTime(&stTime);

				TCHAR szDir[MAX_FILE_PATH_LEN] = { 0, };
				TCHAR szPath[MAX_FILE_PATH_LEN] = { 0, };

				CUtil::GetCurrentDirectory(szDir, MAX_FILE_PATH_LEN);
				CUtil::StringFormat(szPath, MAX_FILE_PATH_LEN, _T("%s\\dump\\%02d%02d%02d.%03d_%d_USB.raw"),
					szDir,
					stTime.wHour, stTime.wMinute, stTime.wSecond, stTime.wMilliseconds,
					pProcess->m_nCameraId);

				CUtil::DumpFile(szPath, pBuffer, nSize);
			}
		}
	}
	//*/
#endif

#ifndef DEF_LPAPP
	//CUtil::PrintDebugString(_T("[%d] acq (%08x - %d) \r\n"), ::GetTickCount(), pProcess, pProcess->m_nCameraId);
#endif

	// Display FPS
	const DWORD dwCurTick = ::GetTickCount();
	//::PostMessage(pProcess->m_hWnd, WM_NOTIFY_FRAMERATE, dwCurTick - pProcess->m_dwCurrentTick, 0);
	pProcess->m_dwCurrentTick = dwCurTick;

	const int size = pProcess->m_BufferQueue.size();
	if (MAX_PROCBUFFER_COUNT <= size)
		return;

	{
		// Check Buffer size (Wrong buffer size)
		const INFO_FRAME* pstFrame = pProcess->GetFrameInfo();
		if (TYPE_NETWORK_CAMERALINK == pstFrame->m_eNetwork ||
			TYPE_NETWORK_USB == pstFrame->m_eNetwork)
		{
			const int nFrameSize = pstFrame->m_dwPitch * pstFrame->m_dwHeight;
			if (nFrameSize > (int)nSize)
				nSize = nFrameSize;
		}
	}

	INFO_IMAGE* pImage = pProcess->AllocImageBuffer(nSize);
	if (NULL == pImage || TYPE_STATE_PROCESS_START != pProcess->GetProcessState())
	{
		const int size = pProcess->m_BufferQueue.size();
		if (TYPE_STATE_PROCESS_START == pProcess->GetProcessState() && 1 > size)
		{
			pProcess->ResetImageBuffer();
			pImage = pProcess->AllocImageBuffer(nSize);
			if (NULL == pImage)
				return;
		}
		else
		{
			return;
		}
	}

	pImage->m_dwTick = dwCurTick;	// For Image display control...
	
	if (pImage->m_pReserved)
	{
		delete pImage->m_pReserved;
		pImage->m_pReserved = NULL;
	}
	pImage->m_pReserved = pReserved;

	BOOL bResult = ::GetFrameInfo(pProcess->m_hCamera, pProcess->m_nCameraId, &pProcess->m_stFrame);

	if (pReserved)
	{
		const INFO_FILE* pstFile = (INFO_FILE*)pReserved;
		memset(&pImage->m_stFrame, 0x00, sizeof(INFO_FRAME));
	
		pImage->m_stFrame.m_dwMaxWidth = pstFile->m_stImgBuf.m_dwWidth;
		pImage->m_stFrame.m_dwMaxHeight = pstFile->m_stImgBuf.m_dwHeight;
		pImage->m_stFrame.m_dwMaxPitch = pstFile->m_stImgBuf.m_dwPitch;

		pImage->m_stFrame.m_dwX = 0;
		pImage->m_stFrame.m_dwY = 0;
		pImage->m_stFrame.m_dwWidth = pImage->m_stFrame.m_dwMaxWidth;
		pImage->m_stFrame.m_dwHeight = pImage->m_stFrame.m_dwMaxHeight;
		pImage->m_stFrame.m_dwPitch = pImage->m_stFrame.m_dwMaxPitch;

		if (8 == pstFile->m_stImgBuf.m_nBit)
		{
			pImage->m_stFrame.m_eDataBit= TYPE_DATABIT_08;
			pImage->m_stFrame.m_eColor = TYPE_CAMCOLOR_MONO;
		}
		else if (12 == pstFile->m_stImgBuf.m_nBit)
		{
			pImage->m_stFrame.m_eDataBit = TYPE_DATABIT_12;
			pImage->m_stFrame.m_eColor = TYPE_CAMCOLOR_MONO;
		}
		else if (16 == pstFile->m_stImgBuf.m_nBit)
		{
			pImage->m_stFrame.m_eDataBit = TYPE_DATABIT_16;
			pImage->m_stFrame.m_eColor = TYPE_CAMCOLOR_COLOR;
		}
		else if (24 == pstFile->m_stImgBuf.m_nBit)
		{
			pImage->m_stFrame.m_eDataBit = TYPE_DATABIT_24;
			pImage->m_stFrame.m_eColor = TYPE_CAMCOLOR_COLOR;
		}
		else if (32 == pstFile->m_stImgBuf.m_nBit)
		{
			pImage->m_stFrame.m_eDataBit = TYPE_DATABIT_32;
			pImage->m_stFrame.m_eColor = TYPE_CAMCOLOR_COLOR;
		}
		else if (36 == pstFile->m_stImgBuf.m_nBit)
		{
			pImage->m_stFrame.m_eDataBit = TYPE_DATABIT_36;
			pImage->m_stFrame.m_eColor = TYPE_CAMCOLOR_COLOR;
		}
		else if (48 == pstFile->m_stImgBuf.m_nBit)
		{
			pImage->m_stFrame.m_eDataBit = TYPE_DATABIT_48;
			pImage->m_stFrame.m_eColor = TYPE_CAMCOLOR_COLOR;
		}
	}
	else
	{
		// Image data...
		memcpy(&pImage->m_stFrame, pProcess->GetFrameInfo(), sizeof(INFO_FRAME));
	}


	memcpy(pImage->m_pBuffer, pBuffer, nSize);
	pImage->m_nLen = nSize;

	pProcess->m_BufferMutex.lock();
	pProcess->m_BufferQueue.push(pImage);
	pProcess->m_BufferMutex.unlock();

	pProcess->SetAcquisitionEvent();
}

BOOL CProcCaptureCamera::SetAcquisitionData(unsigned char* pBuffer, unsigned int nSize)
{
	if (NULL == pBuffer)
		return FALSE;

	INFO_IMAGE* pImage = AllocImageBuffer();
	if (NULL == pImage || TYPE_STATE_PROCESS_START != GetProcessState())
	{
		if (NULL == pImage)
		{
			CUtil::PrintDebugString(_T("		[PROC] droped image  \r\n"));
		}
		return FALSE;
	}

	// Display FPS
	const DWORD dwCurTick = ::GetTickCount();
	//::SendMessage(m_hWnd, WM_NOTIFY_FRAMERATE, dwCurTick - m_dwCurrentTick, 0);
	m_dwCurrentTick = dwCurTick;

	int nBufLen = pImage->m_nBufLen;
	pImage->m_nLen = nBufLen;
	if (nBufLen > (int)nSize)
	{
		nBufLen = nSize;
		pImage->m_nLen = nSize;
	}

	// Tick 
	pImage->m_dwTick = dwCurTick;	// For Image display control...

	// Image data...
	memcpy(&pImage->m_stFrame, GetFrameInfo(), sizeof(INFO_FRAME));
	memcpy(pImage->m_pBuffer, pBuffer, nBufLen);
	
	m_BufferMutex.lock();
	m_BufferQueue.push(pImage);
	m_BufferMutex.unlock();

	SetAcquisitionEvent();

	return TRUE;
}

void CProcCaptureCamera::SetAcquisitionEvent()
{
#ifdef TRIGGER_TIMEOUT
	if (m_bCheckTimeOut)
	{
		m_bWaitAcq = FALSE;
	}
#endif

	if(m_hEvent)
	{
		SetEvent(m_hEvent);
	}
}


DWORD WINAPI CProcCaptureCamera::ThreadProc(LPVOID lpArg)
{
	CProcCaptureCamera* pCameraProc = (CProcCaptureCamera*)lpArg;

	return pCameraProc->ThreadProc();
}

DWORD CProcCaptureCamera::ThreadProc(void)
{
	if (m_hEvent)
		::ResetEvent(m_hEvent);

#ifdef AGING_ONLY_FRAMEGRABBER
	DWORD dwDisplay = 0;
#endif

	do
	{
		if (::WaitForSingleObject(m_hEvent, INFINITE) != WAIT_OBJECT_0)
		{
			break;
		}
		else
		{
			if (m_hEvent)
				::ResetEvent(m_hEvent);
			else
				break;

			if(m_bStop)
			{
				break;
			}

			while (!m_BufferQueue.empty())
			{
				m_BufferMutex.lock();
				INFO_IMAGE* pstBuf = (INFO_IMAGE*)m_BufferQueue.front();
				if (NULL == pstBuf)
					continue;				
				m_BufferQueue.pop();
				m_BufferMutex.unlock();

				// display...
				if (!m_bStop && FALSE == m_bSkipFrame)
				{
					if (m_VideoCallback.m_FuncDisplayDev)
					{
						int nRemainedFrame = m_BufferQueue.size();
						m_VideoCallback.m_FuncDisplayDev(pstBuf, m_VideoCallback.m_pArgument, nRemainedFrame);
					}
				}

				if (pstBuf)
				{
					ReleaseImageBuffer(pstBuf);
				}

			}
		}

	} while(FALSE==m_bStop);

	if (m_hStopEvent)
		::SetEvent(m_hStopEvent);

	CUtil::PrintDebugString(_T("		[PROC] stop [%d] [%d] \r\n"), m_eNetwork, m_nCameraId);

	return 0;
}

INFO_IMAGE* CProcCaptureCamera::AllocImageBuffer(int nMinimum)
{
	INFO_IMAGE* pstBuf = m_ProcessBuffer.AllocBuffer(nMinimum);
	return pstBuf;
}

void CProcCaptureCamera::ReleaseImageBuffer(INFO_IMAGE* pstBuf)
{
	m_ProcessBuffer.ReleaseBuffer(pstBuf);
}

void CProcCaptureCamera::ResetImageBuffer()
{
	m_ProcessBuffer.ResetBuffer();
}

const TYPE_STATE_PROCESS CProcCaptureCamera::GetProcessState()
{
	return m_eProcessState;
}

void CProcCaptureCamera::SetProcessState(TYPE_STATE_PROCESS eState)
{
	m_eProcessState = eState;
}

const INFO_FRAME* CProcCaptureCamera::GetFrameInfo()
{
	return &m_stFrame;
}

void CProcCaptureCamera::UpdateFrameInfo()
{
	::GetFrameInfo(m_hCamera, m_nCameraId, &m_stFrame);
}

const TYPE_NETWORK CProcCaptureCamera::GetCameraNetwork()
{
	return m_eNetwork;
}

const int CProcCaptureCamera::GetCameraId()
{
	return m_nCameraId;
}
HWND CProcCaptureCamera::GetDisplayWindowHandle()
{
	return m_hWnd;
}

// Command
BOOL CProcCaptureCamera::ReadRegDword(const DWORD dwAddress, DWORD* pdwValue, DWORD dwReserved)
{
	BOOL bResult = ::GetRegister(m_hCamera, m_nCameraId, dwAddress, pdwValue, dwReserved);
	return bResult;
}
BOOL CProcCaptureCamera::WriteRegDword(const DWORD dwAddress, const DWORD dwValue, DWORD dwReserved)
{
	BOOL bResult = ::SetRegister(m_hCamera, m_nCameraId, dwAddress, dwValue, dwReserved);
	return bResult;
}

//
BOOL CProcCaptureCamera::SetGain(const int nGainType, const int nGainVal)
{
	BOOL bResult = ::SetGain(m_hCamera, m_nCameraId, nGainType, nGainVal);
	return bResult;
}
BOOL CProcCaptureCamera::GetGain(const int nGainType, int* pnGainVal)
{
	BOOL bResult = ::GetGain(m_hCamera, m_nCameraId, nGainType, pnGainVal);
	return bResult;
}

BOOL CProcCaptureCamera::SetEnableFrameRate(const BOOL bEnable)
{
	unsigned int nValue = bEnable;

	BOOL bResult = ::SetEnableFrameRate(m_hCamera, m_nCameraId, nValue);
	return bResult;
}

BOOL CProcCaptureCamera::GetEnableFrameRate(BOOL* pbEnable)
{
	unsigned int nValue = 0;

	BOOL bResult = ::GetEnableFrameRate(m_hCamera, m_nCameraId, &nValue);
	if (bResult && pbEnable)
	{
		*pbEnable = nValue;
	}
	return bResult;
}

BOOL CProcCaptureCamera::SetFrameRate(const unsigned int nFrameRate)
{
	BOOL bResult = ::SetFrameRate(m_hCamera, m_nCameraId, nFrameRate);
	return bResult;
}
BOOL CProcCaptureCamera::GetFrameRate(unsigned int* pnFrameRate)
{
	BOOL bResult = ::GetFrameRate(m_hCamera, m_nCameraId, pnFrameRate);
	return bResult;
}

BOOL CProcCaptureCamera::GetMaxFrameRate(unsigned int* pnFrameRate)
{
	BOOL bResult = ::GetMaxFrameRate(m_hCamera, m_nCameraId, pnFrameRate);
	return bResult;
}

BOOL CProcCaptureCamera::SetExposureTime(const unsigned int nExposureTime)
{
	BOOL bResult = ::SetExposureTime(m_hCamera, m_nCameraId, nExposureTime);
	return bResult;
}
BOOL CProcCaptureCamera::GetExposureTime(unsigned int* pnExposureTime)
{
	BOOL bResult = ::GetExposureTime(m_hCamera, m_nCameraId, pnExposureTime);
	return bResult;
}

BOOL CProcCaptureCamera::GetExposureMaxTime(unsigned int nFrameRate, unsigned int* pnExposureTime)
{
	BOOL bResult = FALSE;
	if (m_hCamera)
	{
		bResult = ::GetExposureMaxTime(m_hCamera, m_nCameraId, nFrameRate, pnExposureTime);
	}
	return bResult;
}

BOOL CProcCaptureCamera::ConvertExposureTime(unsigned int nStep, double* pfUSec)
{
	BOOL bResult = FALSE;
	if (m_hCamera)
	{
		bResult = ::ConvertExposureTime(m_hCamera, m_nCameraId, nStep, pfUSec);
	}
	return bResult;
}

BOOL CProcCaptureCamera::SetTriggerMode(INFO_TRIGGER_PARA stTrigger)
{
	BOOL bResult = ::SetTriggerMode(m_hCamera, m_nCameraId, stTrigger);
	return bResult;
}
BOOL CProcCaptureCamera::GetTriggerMode(INFO_TRIGGER_PARA* pstTrigger)
{
	BOOL bResult = ::GetTriggerMode(m_hCamera, m_nCameraId, pstTrigger);
	return bResult;
}

BOOL CProcCaptureCamera::SetTriggerDelay(int nDelay)
{
	BOOL bResult = ::SetTriggerDelay(m_hCamera, m_nCameraId, nDelay);
	return bResult;
}

BOOL CProcCaptureCamera::SaveUserset(const int nNumber)
{
	BOOL bResult = ::SaveUserset(m_hCamera, m_nCameraId, nNumber);
	return bResult;
}
BOOL CProcCaptureCamera::LoadUserset(const int nNumber)
{
	BOOL bResult = ::LoadUserset(m_hCamera, m_nCameraId, nNumber);
	return bResult;
}

BOOL CProcCaptureCamera::SetStrobeMode(INFO_STROBE_PARA stStrobe)
{
	BOOL bResult = ::SetStrobeMode(m_hCamera, m_nCameraId, stStrobe);
	return bResult;
}
BOOL CProcCaptureCamera::GetStrobeMode(INFO_STROBE_PARA* pstStrobe)
{
	BOOL bResult = ::GetStrobeMode(m_hCamera, m_nCameraId, pstStrobe);
	return bResult;
}

BOOL CProcCaptureCamera::SetFlipMode(unsigned short nMode)
{
	BOOL bResult = ::SetFlipMode(m_hCamera, m_nCameraId, nMode);
	if (bResult && TYPE_CAMCOLOR_COLOR == m_stFrame.m_eColor)
	{
		::GetFrameInfo(m_hCamera, m_nCameraId, &m_stFrame);
	}
	return bResult;
}
BOOL CProcCaptureCamera::GetFlipMode(unsigned short* pnMode)
{
	BOOL bResult = ::GetFlipMode(m_hCamera, m_nCameraId, pnMode);
	return bResult;
}

BOOL CProcCaptureCamera::SetROI(INFO_ROI_PARA stROI)
{
	BOOL bResult = ::SetROI(m_hCamera, m_nCameraId, stROI);
	if (bResult)
	{
		int nBit = 8;

		if (TYPE_DATABIT_08 == m_stFrame.m_eDataBit)		nBit = 8;
		else if (TYPE_DATABIT_10 == m_stFrame.m_eDataBit)	nBit = 10;
		else if (TYPE_DATABIT_12 == m_stFrame.m_eDataBit)	nBit = 12;
		else if (TYPE_DATABIT_16 == m_stFrame.m_eDataBit)	nBit = 16;
		else if (TYPE_DATABIT_24 == m_stFrame.m_eDataBit)	nBit = 24;
		else if (TYPE_DATABIT_32 == m_stFrame.m_eDataBit)	nBit = 32;
		else if (TYPE_DATABIT_36 == m_stFrame.m_eDataBit)	nBit = 36;
		else if (TYPE_DATABIT_48 == m_stFrame.m_eDataBit)	nBit = 48;

		m_stFrame.m_dwWidth = stROI.nWidth;
		m_stFrame.m_dwHeight = stROI.nHeight;
		m_stFrame.m_dwPitch = m_stFrame.m_dwWidth * nBit / 8;
		m_stFrame.m_dwMaxPitch = m_stFrame.m_dwMaxWidth * nBit / 8;
	}

	return bResult;
}
BOOL CProcCaptureCamera::GetROI(INFO_ROI_PARA* pstROI)
{
	BOOL bResult = ::GetROI(m_hCamera, m_nCameraId, pstROI);
	return bResult;
}

BOOL CProcCaptureCamera::SetUsersetStartNo(unsigned char nUsersetStartNo)
{
	BOOL bResult = ::SetUsersetStartNo(m_hCamera, m_nCameraId, nUsersetStartNo);
	return bResult;
}
BOOL CProcCaptureCamera::GetUsersetStartNo(unsigned char* pnUsersetStartNo)
{
	BOOL bResult = ::GetUsersetStartNo(m_hCamera, m_nCameraId, pnUsersetStartNo);
	return bResult;
}

BOOL CProcCaptureCamera::SetDataBit(unsigned short nDataBit)
{
	BOOL bResult = ::SetDataBits(m_hCamera, m_nCameraId, nDataBit);
	if (bResult)
	{
		::GetFrameInfo(m_hCamera, m_nCameraId, &m_stFrame);

		/*//
		if (8 == nDataBit)			m_stFrame.m_eDataBit = TYPE_DATABIT_08;
		else if (10 == nDataBit)	m_stFrame.m_eDataBit = TYPE_DATABIT_10;
		else if (12 == nDataBit)	m_stFrame.m_eDataBit = TYPE_DATABIT_12;
		else if (16 == nDataBit)	m_stFrame.m_eDataBit = TYPE_DATABIT_16;
		else if (24 == nDataBit)	m_stFrame.m_eDataBit = TYPE_DATABIT_24;
		else if (32 == nDataBit)	m_stFrame.m_eDataBit = TYPE_DATABIT_32;
		else if (36 == nDataBit)	m_stFrame.m_eDataBit = TYPE_DATABIT_36;
		else if (48 == nDataBit)	m_stFrame.m_eDataBit = TYPE_DATABIT_48;

		m_stFrame.m_dwPitch = m_stFrame.m_dwWidth * nDataBit / 8;
		m_stFrame.m_dwMaxPitch = m_stFrame.m_dwMaxWidth * nDataBit / 8;
		//*/
	}

	return bResult;
}

BOOL CProcCaptureCamera::GetDataBit(unsigned short* pnDataBit)
{
	BOOL bResult = ::GetDataBits(m_hCamera, m_nCameraId, pnDataBit);
	return bResult;
}

BOOL CProcCaptureCamera::SetColorMode(unsigned short nColorMode)
{
	BOOL bResult = ::SetColorMode(m_hCamera, m_nCameraId, nColorMode);
	if (bResult)
	{
		::GetFrameInfo(m_hCamera, m_nCameraId, &m_stFrame);
	}
	return bResult;
}
BOOL CProcCaptureCamera::GetColorMode(unsigned short* pnColorMode)
{
	BOOL bResult = ::GetColorMode(m_hCamera, m_nCameraId, pnColorMode);
	return bResult;
}


BOOL CProcCaptureCamera::SetMTU(unsigned int nMTU)
{
	BOOL bResult = ::SetMtu(m_hCamera, m_nCameraId, nMTU);
	return bResult;
}

BOOL CProcCaptureCamera::GetMTU(unsigned int* pnMTU)
{
	BOOL bResult = ::GetMtu(m_hCamera, m_nCameraId, pnMTU);
	return bResult;
}


BOOL CProcCaptureCamera::GetDiag(void* pstDiag, int nLen)
{
	BOOL bResult = ::GetDiag(m_hCamera, m_nCameraId, pstDiag, nLen);
	return bResult;
}

BOOL CProcCaptureCamera::SetSWTrigger()
{
	BOOL bResult = FALSE;
	if (m_hCamera)
	{
#ifdef TRIGGER_TIMEOUT
		const TYPE_NETWORK eNetwork = ::GetNetworkType(m_hCamera);
		if (m_bCheckTimeOut)
		{
			m_bWaitAcq = TRUE;
			if (m_hEventTimeOut)
				::SetEvent(m_hEventTimeOut);
		}
#endif

#ifndef DEF_LPAPP
//		CUtil::PrintDebugString(_T("[%d] trigger (%08x - %d) \r\n"), ::GetTickCount(), this, m_nCameraId);
#endif
		bResult = ::SetSWTrigger(m_hCamera, m_nCameraId);
	}

	if (bResult)
	{
		SetProcessState(TYPE_STATE_PROCESS_START);
		m_dwCurrentTick = ::GetTickCount();
	}

	return bResult;
}


// Effect
BOOL CProcCaptureCamera::SetEffectNR(unsigned short nEffect)
{
	BOOL bResult = ::SetEffectNR(m_hCamera, m_nCameraId, nEffect);
	return bResult;
}
BOOL CProcCaptureCamera::GetEffectNR(unsigned short* pnEffect)
{
	BOOL bResult = ::GetEffectNR(m_hCamera, m_nCameraId, pnEffect);
	return bResult;
}

BOOL CProcCaptureCamera::SetEffectGC(unsigned short nEffect)
{
	BOOL bResult = ::SetEffectGC(m_hCamera, m_nCameraId, nEffect);
	return bResult;
}
BOOL CProcCaptureCamera::GetEffectGC(unsigned short* pnEffect)
{
	BOOL bResult = ::GetEffectGC(m_hCamera, m_nCameraId, pnEffect);
	return bResult;
}

BOOL CProcCaptureCamera::SetEffectCM(unsigned short nEffect)
{
	BOOL bResult = ::SetEffectCM(m_hCamera, m_nCameraId, nEffect);
	return bResult;
}
BOOL CProcCaptureCamera::GetEffectCM(unsigned short* pnEffect)
{
	BOOL bResult = ::GetEffectCM(m_hCamera, m_nCameraId, pnEffect);
	return bResult;
}

BOOL CProcCaptureCamera::SetEffectAWB(unsigned short nEffect)
{
	BOOL bResult = ::SetEffectAWB(m_hCamera, m_nCameraId, nEffect);
	return bResult;
}
BOOL CProcCaptureCamera::GetEffectAWB(unsigned short* pnEffect)
{
	BOOL bResult = ::GetEffectAWB(m_hCamera, m_nCameraId, pnEffect);
	return bResult;
}

BOOL CProcCaptureCamera::SetEffectSmooth(unsigned short nEffect)
{
	BOOL bResult = ::SetEffectSmooth(m_hCamera, m_nCameraId, nEffect);
	return bResult;
}
BOOL CProcCaptureCamera::GetEffectSmooth(unsigned short* pnEffect)
{
	BOOL bResult = ::GetEffectSmooth(m_hCamera, m_nCameraId, pnEffect);
	return bResult;
}

BOOL CProcCaptureCamera::SetEffectSharpen(unsigned short nEffect)
{
	BOOL bResult = ::SetEffectSharpen(m_hCamera, m_nCameraId, nEffect);
	return bResult;
}
BOOL CProcCaptureCamera::GetEffectSharpen(unsigned short* pnEffect)
{
	BOOL bResult = ::GetEffectSharpen(m_hCamera, m_nCameraId, pnEffect);
	return bResult;
}

BOOL CProcCaptureCamera::SetEffectFPN(unsigned short nEffect)
{
	BOOL bResult = ::SetEffectFPN(m_hCamera, m_nCameraId, nEffect);
	return bResult;
}
BOOL CProcCaptureCamera::GetEffectFPN(unsigned short* pnEffect)
{
	BOOL bResult = ::GetEffectFPN(m_hCamera, m_nCameraId, pnEffect);
	return bResult;
}

BOOL CProcCaptureCamera::SetEffectPRNU(unsigned short nEffect)
{
	BOOL bResult = ::SetEffectPRNU(m_hCamera, m_nCameraId, nEffect);
	return bResult;
}
BOOL CProcCaptureCamera::GetEffectPRNU(unsigned short* pnEffect)
{
	BOOL bResult = ::GetEffectPRNU(m_hCamera, m_nCameraId, pnEffect);
	return bResult;
}

BOOL CProcCaptureCamera::SetEffectDPC(unsigned short nEffect)
{
	BOOL bResult = ::SetEffectDPC(m_hCamera, m_nCameraId, nEffect);
	return bResult;
}
BOOL CProcCaptureCamera::GetEffectDPC(unsigned short* pnEffect)
{
	BOOL bResult = ::GetEffectDPC(m_hCamera, m_nCameraId, pnEffect);
	return bResult;
}

BOOL CProcCaptureCamera::SetColorGain(const int nGainType, int nGainVal)
{
	BOOL bResult = ::SetColorGain(m_hCamera, m_nCameraId, nGainType, nGainVal);
	return bResult;
}
BOOL CProcCaptureCamera::GetColorGain(const int nGainType, int* pnGainVal)
{
	BOOL bResult = ::GetColorGain(m_hCamera, m_nCameraId, nGainType, pnGainVal);
	return bResult;
}


#ifdef TRIGGER_TIMEOUT
DWORD CProcCaptureCamera::ThreadTimeOutProc(LPVOID lpArg)
{
	CProcCaptureCamera* pCameraProc = (CProcCaptureCamera*)lpArg;
	return pCameraProc->ThreadTimeOutProc();
}

DWORD CProcCaptureCamera::ThreadTimeOutProc(void)
{
	//CUtil::PrintDebugString(_T("		[TIMEOUT] start [%d] \r\n"), m_nCameraId);

	if (m_hEventTimeOut)
		::ResetEvent(m_hEventTimeOut);

	const TYPE_NETWORK eNetwork = ::GetNetworkType(m_hCamera);
	InitTimeOutDeviceInfo();

	INFO_TRIGGER_PARA stTrigger;
	memset(&stTrigger, 0x00, sizeof(INFO_TRIGGER_PARA));
	GetTriggerMode(&stTrigger);
	stTrigger.nTriggerMode = TRIGGER_ON;
	stTrigger.nTriggerSource = TRIGGER_SRC_SW;

	unsigned int nMtu = 9000;	// 9K
	this->GetMTU(&nMtu);

	DWORD dwRetryCount = 0;
	do
	{
		//CUtil::PrintDebugString(_T("		[TIMEOUT] wait [%d] \r\n"), m_nCameraId);
		m_bSearchDevice = FALSE;

		if (::WaitForSingleObject(m_hEventTimeOut, INFINITE) == WAIT_OBJECT_0)
		{
			//CUtil::PrintDebugString(_T("		[TIMEOUT] event [%d] \r\n"), m_nCameraId);
			if (m_hEventTimeOut)
				::ResetEvent(m_hEventTimeOut);
			else
				break;

			if (m_bCheckTimeOut)
			{
				for (int i = 0; i < (int)m_dwTimeOut; i++)
				{
					if (m_bStop || FALSE == m_bWaitAcq)
						break;
					CUtil::Sleep(1);
				}

				if (FALSE == m_bStop && m_bWaitAcq)
				{
					m_bSearchDevice = TRUE;

#ifdef TRIGGER_REFRESH_CONNECTION
					if (RETRY_TRIGGERCOUNT > dwRetryCount)
					{
						dwRetryCount++;
						CUtil::PrintDebugString(_T("		[TIMEOUT] retry (%d) [%d] \r\n"), dwRetryCount, m_nCameraId);

						SetSWTrigger();
					}
					else
					{
						CUtil::PrintDebugString(_T("		[TIMEOUT] Try reconnect... [%d] \r\n"), m_nCameraId);
						::SetEventFunc(m_hCamera, m_nCameraId, NULL, NULL);
						::Stop(m_hCamera, m_nCameraId);

						BOOL bFind = FALSE;

						while (FALSE == m_bStop && m_bWaitAcq && FALSE == bFind)
						{
							bFind = RefreshTimeOutDevice((INFO_CONNECT_DEV*)m_pstTimeOutDevice, stTrigger, nMtu);
							if (bFind)
							{
								SetSWTrigger();

								dwRetryCount = 0;
								m_bSearchDevice = FALSE;
								break;
							}

							CUtil::Sleep(100);
						}

					}
#else
					{
						dwRetryCount++;
						CUtil::PrintDebugString(_T("		[TIMEOUT] retry (%d) [%d] \r\n"), dwRetryCount, m_nCameraId);

						#ifdef TEST_DUMP
						if (TYPE_NETWORK_USB == this->m_eNetwork)
						{
							SYSTEMTIME stTime;
							::GetLocalTime(&stTime);

							TCHAR szDir[MAX_FILE_PATH_LEN] = { 0, };
							TCHAR szPath[MAX_FILE_PATH_LEN] = { 0, };

							CUtil::GetCurrentDirectory(szDir, MAX_FILE_PATH_LEN);
							CUtil::StringFormat(szPath, MAX_FILE_PATH_LEN, _T("%s\\dump\\%02d%02d%02d.%03d_%d_USB_retry_%d.txt"),
								szDir,
								stTime.wHour, stTime.wMinute, stTime.wSecond, stTime.wMilliseconds,
								this->m_nCameraId, dwRetryCount);
							CUtil::DumpFile(szPath, (BYTE*)szPath, CUtil::StringLength(szPath));
						}
						#endif

						SetSWTrigger();
					}
#endif
				}
				else
				{
					dwRetryCount = 0;
				}
			}
		}
	} while (FALSE == m_bStop);

	CUtil::PrintDebugString(_T("		[TIMEOUT] stop [%d] [%d] \r\n"), m_eNetwork, m_nCameraId);
	if (m_pstTimeOutDevice)
		delete m_pstTimeOutDevice;
	m_pstTimeOutDevice = NULL;

	m_bSearchDevice = FALSE;

	return 0;
}

BOOL CProcCaptureCamera::RefreshTimeOutDevice(const INFO_CONNECT_DEV* pstDevice, INFO_TRIGGER_PARA& stTrigger, DWORD dwMtu)
{
	if (NULL == pstDevice)
		return FALSE;

	const TYPE_NETWORK eNetwork = ::GetNetworkType(m_hCamera);
	BOOL bFound = FALSE;

	BOOL bResult = ResearchDeviceInfo(m_hCamera);
	if (TYPE_NETWORK_GIGE == eNetwork)
	{
		INFO_CONNECT_GIGE stGigE;
		memset(&stGigE, 0x00, sizeof(INFO_CONNECT_GIGE));
		stGigE.m_stArg.m_eNetwork = TYPE_NETWORK_GIGE;

		const int nCount = ::GetDeviceCount(m_hCamera);
		for (int i = 0; i < nCount; i++)
		{
			if (m_bStop || FALSE == m_bWaitAcq)
				break;

			bResult = ::GetDeviceInfo(m_hCamera, i, (INFO_CONNECT_DEV*)&stGigE);
			if (FALSE == bResult)
				continue;

			if (pstDevice->m_dwArg == stGigE.m_stArg.m_dwArg)
			{
				CUtil::PrintDebugString(_T("		[TIMEOUT] Find device... [%d] \r\n"), m_nCameraId);
				bFound = TRUE;

				m_nCameraId = ::GetDeviceIndex(m_hCamera, (INFO_CONNECT_DEV*)&stGigE);

				::SetEventFunc(m_hCamera, m_nCameraId, AcquisitionEventHandler, this);

				SetTriggerMode(stTrigger);
				SetMTU(dwMtu);
				CUtil::Sleep(100);

				::StartCamera(m_hCamera, m_nCameraId, FALSE);
				CUtil::Sleep(100);
				
				break;
			}
		}
	}

	
	return bFound;
}

void CProcCaptureCamera::InitTimeOutDeviceInfo()
{
	const TYPE_NETWORK eNetwork = ::GetNetworkType(m_hCamera);

	if (TYPE_NETWORK_GIGE == eNetwork)
	{
		m_pstTimeOutDevice = (INFO_CONNECT_DEV*)(new INFO_CONNECT_GIGE);
		memset(m_pstTimeOutDevice, 0x00, sizeof(INFO_CONNECT_GIGE));
		m_pstTimeOutDevice->m_eNetwork = TYPE_NETWORK_GIGE;
	}
	else if (TYPE_NETWORK_ETHERNET == eNetwork)
	{
		m_pstTimeOutDevice = (INFO_CONNECT_DEV*)(new INFO_CONNECT_ETHERNET);
		memset(m_pstTimeOutDevice, 0x00, sizeof(INFO_CONNECT_ETHERNET));
		m_pstTimeOutDevice->m_eNetwork = TYPE_NETWORK_ETHERNET;
	}
	else if (TYPE_NETWORK_USB == eNetwork)
	{
		m_pstTimeOutDevice = (INFO_CONNECT_DEV*)(new INFO_CONNECT_USB);
		memset(m_pstTimeOutDevice, 0x00, sizeof(INFO_CONNECT_USB));
		m_pstTimeOutDevice->m_eNetwork = TYPE_NETWORK_USB;
	}
	else if (TYPE_NETWORK_CAMERALINK == eNetwork)
	{
		m_pstTimeOutDevice = (INFO_CONNECT_DEV*)(new INFO_CONNECT_CAMERALINK);
		memset(m_pstTimeOutDevice, 0x00, sizeof(INFO_CONNECT_CAMERALINK));
		m_pstTimeOutDevice->m_eNetwork = TYPE_NETWORK_CAMERALINK;
	}
	::GetDeviceInfo(m_hCamera, m_nCameraId, m_pstTimeOutDevice);
}

void CProcCaptureCamera::SetEnableTriggerTimeOut(BOOL bEnable)
{
	m_bCheckTimeOut = bEnable;
}
BOOL CProcCaptureCamera::GetEnableTriggerTimeOut()
{
	return m_bCheckTimeOut;
}

void CProcCaptureCamera::SetTimeTriggerTimeOut(DWORD dwMsec)
{
	m_dwTimeOut = dwMsec;
}
DWORD CProcCaptureCamera::GetTimeTriggerTimeOut()
{
	return m_dwTimeOut;
}
#endif

#if defined(ENABLE_CAMERA_LIBRARY_BASLER)
BOOL CProcCaptureCamera::GetCameraInformation(INFO_OTHER_CATEGORY* pstRootCategory)
{
	BOOL bResult = ::GetCameraInformation(m_hCamera, m_nCameraId, pstRootCategory);

	return bResult;
}

const INFO_OTHER_IF* CProcCaptureCamera::GetCameraInformation(const TCHAR* szName)
{
	const INFO_OTHER_IF* pOther = ::GetCameraInfoFromName(m_hCamera, m_nCameraId, szName);

	return pOther;
}

BOOL CProcCaptureCamera::GetCameraValue(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue)
{
	BOOL bResult = ::GetCameraValue(m_hCamera, m_nCameraId, pstInfo, pstValue);

	return bResult;
}

BOOL CProcCaptureCamera::SetCameraValue(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue)
{
	BOOL bResult = ::SetCameraValue(m_hCamera, m_nCameraId, pstInfo, pstValue);

	return bResult;
}
#endif