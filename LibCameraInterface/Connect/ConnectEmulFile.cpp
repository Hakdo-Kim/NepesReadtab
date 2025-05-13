#include "StdAfx.h"
#include "ConnectEmulFile.h"
#include "Util/Util.h"

CConnectEmulFile::CConnectEmulFile()
{
	for (int i = 0; i < MAX_EMULCAMERA_COUNT; i++)
	{
		m_IdList[i] = FALSE;
	}
}

CConnectEmulFile::~CConnectEmulFile()
{
}

int CConnectEmulFile::GetEnableCamID()
{
	int idx = -1;
	for (int i = 0; i < MAX_EMULCAMERA_COUNT; i++)
	{
		if (FALSE == m_IdList[i])
		{
			m_IdList[i] = TRUE;
			idx = i;
			break;
		}
	}
	return idx;
}

void CConnectEmulFile::ReleaseCamID(int nCamID)
{
	if (0 > nCamID || MAX_EMULCAMERA_COUNT <= nCamID)
		return;
	m_IdList[nCamID] = FALSE;
}

BOOL CConnectEmulFile::IsConnected()
{
	return TRUE;
}

BOOL CConnectEmulFile::Open(TYPE_NETWORK eNetwork)
{
	BOOL bResult = Open(eNetwork, NULL);
	return bResult;
}

BOOL CConnectEmulFile::Open(TYPE_NETWORK eNetwork, void* pReserved)
{
	if( TYPE_NETWORK_EMULFILE!=eNetwork )
		return FALSE;

#ifdef DEF_LPAPP
	// Not Use
#else
	ResearchDeviceInfo();
#endif
	return TRUE;
}

void CConnectEmulFile::Close()
{
	const int nCount = GetDeviceCount();
	for(int i=0; i<nCount; i++)
	{
		CEmulFile* pEmul = m_EmulDeviceList[i];
		if(pEmul)
		{
			const INFO_CONNECT_EMUL* pstEmul = pEmul->GetDeviceInfo();
			ReleaseCamID(pstEmul->m_CamID);

			pEmul->Close();
			delete pEmul;
		}
	}

	std::vector<CEmulFile*> eclear;		// vector memory leak ¹æÁö.
	m_EmulDeviceList.swap(eclear);
	eclear.clear();
	m_EmulDeviceList.clear();

}

int CConnectEmulFile::GetDeviceCount()
{
	int nCount = m_EmulDeviceList.size();
	return nCount;
}

int CConnectEmulFile::GetDeviceIndex(const INFO_CONNECT_DEV* pDev)
{
	const int nCount = GetDeviceCount();
	const INFO_CONNECT_EMUL* pEmul = (INFO_CONNECT_EMUL*) pDev;

	int nCamId = -1;
	for(int i=0; i<nCount; i++)
	{
		const INFO_CONNECT_EMUL* pstEmulDev = m_EmulDeviceList[i]->GetDeviceInfo();
		if(TRUE==CUtil::StringCompare((LPTSTR)pEmul->m_szName, (LPTSTR)pstEmulDev->m_szName))
		{
			nCamId = pEmul->m_CamID;
			break;
		}
	}

	return nCamId;
}

int CConnectEmulFile::GetDeviceID(const TCHAR* pName)
{
	if (NULL == pName)
		return -1;

	int nCamId = -1;

	const int nCount = GetDeviceCount();
	for (int i = 0; i<nCount; i++)
	{
		const INFO_CONNECT_EMUL* pstEmulDev = m_EmulDeviceList[i]->GetDeviceInfo();
		if (TRUE == CUtil::StringCompare((LPTSTR)pstEmulDev->m_szName, (LPTSTR)pName))
		{
			nCamId = pstEmulDev->m_CamID;
			break;
		}
	}

	return nCamId;
}


BOOL CConnectEmulFile::GetDeviceInfo(int nIdx, INFO_CONNECT_DEV* pstDevice)
{
	if (MAX_EMULCAMERA_COUNT <= nIdx ||
		NULL == pstDevice || TYPE_NETWORK_EMULFILE != pstDevice->m_eNetwork)
	{
		return FALSE;
	}

	INFO_CONNECT_EMUL* pEmul = (INFO_CONNECT_EMUL*) pstDevice;

	const INFO_CONNECT_EMUL* pstEmulDev = m_EmulDeviceList[nIdx]->GetDeviceInfo();
	memcpy(pEmul, pstEmulDev, sizeof(INFO_CONNECT_EMUL));

	
	return TRUE;
}

BOOL CConnectEmulFile::UpdateDeviceInfo(int nCamID, INFO_CONNECT_DEV* pstDevice)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx ||
		NULL == pstDevice || TYPE_NETWORK_EMULFILE != pstDevice->m_eNetwork)
	{
		return FALSE;
	}

	INFO_CONNECT_EMUL* pEmul = (INFO_CONNECT_EMUL*)pstDevice;
	return TRUE;
}

BOOL CConnectEmulFile::ResearchDeviceInfo()
{
	const int nCount = GetDeviceCount();

#ifndef DEF_LPAPP
	for (int i = 0; i < MAX_EMULCAMERA_COUNT; i++)
		ReleaseCamID(i);

	BOOL bResult = m_XmlEmulDevice.Load();
	if (FALSE == bResult && 1 > nCount)
		return FALSE;
#endif

	RefreshDeviceList();

	return TRUE;
}

void CConnectEmulFile::RefreshDeviceList()
{
	INFO_CONNECT_EMUL stEmulDev;

	const int nCount = m_XmlEmulDevice.GetDeviceCount();
	for (int i = 0; i<nCount; i++)
	{
		const INFO_EMUL_DEVICE* pEmul = m_XmlEmulDevice.GetDeviceInfo(i);
		memset(&stEmulDev, 0x00, sizeof(INFO_CONNECT_EMUL));

		stEmulDev.m_stArg.m_eNetwork = TYPE_NETWORK_EMULFILE;
		stEmulDev.m_CamID = pEmul->m_CamID;

		m_IdList[pEmul->m_CamID] = TRUE;

		CUtil::StringCopy(stEmulDev.m_stArg.m_szArg, pEmul->m_szName);
		CUtil::StringCopy(stEmulDev.m_szName, pEmul->m_szName);
		CUtil::StringCopy(stEmulDev.m_szFilePath, pEmul->m_szPath);

		CUtil::StringCopy(stEmulDev.m_szDirPath, pEmul->m_szPath);
		TCHAR* pCh = _tcsrchr(stEmulDev.m_szDirPath, _T('\\'));
		if (pCh) *pCh = 0;

		stEmulDev.m_bCameraEmulator = pEmul->m_bCameraEmulator;
		stEmulDev.m_dwFps = pEmul->m_dwFPS;
		stEmulDev.m_bCycleDir = pEmul->m_bCycleDir;

		/// Use Camera Emulator...
		{
			stEmulDev.m_stFrame.m_dwMaxWidth = pEmul->m_stResolution.cx;
			stEmulDev.m_stFrame.m_dwMaxHeight = pEmul->m_stResolution.cy;

			stEmulDev.m_stFrame.m_dwX = pEmul->m_stRoi.left;
			stEmulDev.m_stFrame.m_dwY = pEmul->m_stRoi.top;
			stEmulDev.m_stFrame.m_dwWidth = pEmul->m_stRoi.right - pEmul->m_stRoi.left;
			stEmulDev.m_stFrame.m_dwHeight = pEmul->m_stRoi.bottom - pEmul->m_stRoi.top;
			
			stEmulDev.m_stFrame.m_eColor = TYPE_CAMCOLOR_COLOR;
			stEmulDev.m_stFrame.m_eDataBit = TYPE_DATABIT_24;
		}
		//*/

		// Check Duplicate device...
		if (-1< FindEmulator(stEmulDev.m_szName))
			continue;

		CEmulFile* pEmulFile = new CEmulFile();
		if (TRUE == pEmulFile->Open(&stEmulDev))
		{
			m_EmulDeviceList.push_back(pEmulFile);
		}
	}
}

// Device Information
BOOL CConnectEmulFile::GetFrameInfo(const int nCamID, INFO_FRAME* pstFrame)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	const INFO_CONNECT_EMUL* pstEmulDev = m_EmulDeviceList[nIdx]->GetDeviceInfo();

	// Original Image or Camera Emulator...
	pstFrame->m_bVariable	= !pstEmulDev->m_bCameraEmulator;
	pstFrame->m_dwMaxWidth	= pstEmulDev->m_stFrame.m_dwMaxWidth;
	pstFrame->m_dwMaxHeight	= pstEmulDev->m_stFrame.m_dwMaxHeight;
	pstFrame->m_dwX			= pstEmulDev->m_stFrame.m_dwX;
	pstFrame->m_dwY			= pstEmulDev->m_stFrame.m_dwY;
	pstFrame->m_dwWidth		= pstEmulDev->m_stFrame.m_dwWidth;
	pstFrame->m_dwHeight	= pstEmulDev->m_stFrame.m_dwHeight;
	pstFrame->m_eColor		= pstEmulDev->m_stFrame.m_eColor;
	pstFrame->m_eDataBit	= pstEmulDev->m_stFrame.m_eDataBit;

	BYTE  nBit = 8;
	if (pstFrame->m_bVariable)
		nBit = 24;

	if(TYPE_DATABIT_08		== pstFrame->m_eDataBit)	nBit = 8;
	else if(TYPE_DATABIT_12 == pstFrame->m_eDataBit)	nBit = 12;
	else if(TYPE_DATABIT_16 == pstFrame->m_eDataBit)	nBit = 16;
	else if(TYPE_DATABIT_24 == pstFrame->m_eDataBit)	nBit = 24;
	else if(TYPE_DATABIT_32 == pstFrame->m_eDataBit)	nBit = 32;
	else if(TYPE_DATABIT_36 == pstFrame->m_eDataBit)	nBit = 36;
	else if(TYPE_DATABIT_48 == pstFrame->m_eDataBit)	nBit = 48;
	else return FALSE;

	DWORD dwW = max(pstFrame->m_dwMaxWidth, pstFrame->m_dwWidth);
	pstFrame->m_dwMaxPitch = (DWORD)(dwW* nBit / 8.0f);
	pstFrame->m_dwPitch = (DWORD)(pstFrame->m_dwWidth * nBit / 8.0f);

	return TRUE;
}
	
BOOL CConnectEmulFile::SetEventFunc(const int nCamID, FuncAcquisitionEvent pFunc, void* pUserData)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = m_EmulDeviceList[nIdx]->SetEventFunc(pFunc, pUserData);
	return bResult;
}

BOOL CConnectEmulFile::Start(const int nCamID, BOOL bSingle)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CEmulFile* pEmul = m_EmulDeviceList[nIdx];
	if (pEmul)
	{
		bResult = pEmul->Start(bSingle);
	}

	return bResult;
}

void CConnectEmulFile::Stop(const int nCamID)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return;

	CEmulFile* pEmul = m_EmulDeviceList[nIdx];
	if(pEmul)
	{
		pEmul->Stop();
	}

}

BOOL CConnectEmulFile::IsOpen(const int nCamID)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CEmulFile* pEmul = m_EmulDeviceList[nIdx];
	if (pEmul)
	{
		bResult = pEmul->IsOpen();
	}

	return bResult;
}

BOOL CConnectEmulFile::Open(const int nCamID)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CEmulFile* pEmul = m_EmulDeviceList[nIdx];
	if (pEmul)
	{
		bResult = TRUE;
	}

	return bResult;
}

void CConnectEmulFile::Close(const int nCamID)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return;

	CEmulFile* pEmul = m_EmulDeviceList[nIdx];
	if(pEmul)
	{
		pEmul->Close();
	}

}

BOOL CConnectEmulFile::AddEmulator(const INFO_EMUL* pstEmul)
{
	const int nCount = m_EmulDeviceList.size();
	if ( NULL == pstEmul || MAX_EMULCAMERA_COUNT <= nCount )
		return FALSE;

	const int nCamID = GetEnableCamID();
	if (0 > nCamID || MAX_EMULCAMERA_COUNT <= nCamID)
	{
		ReleaseCamID(nCamID);
		return FALSE;
	}


	INFO_EMUL_DEVICE stEmul;
	memset(&stEmul, 0x00, sizeof(INFO_EMUL_DEVICE));

	CUtil::StringCopy(stEmul.m_szName, pstEmul->m_szName);
	CUtil::StringCopy(stEmul.m_szPath, pstEmul->m_szPath);

	stEmul.m_CamID = nCamID;
	stEmul.m_dwFPS = pstEmul->m_dwFps;
	stEmul.m_bCycleDir = pstEmul->m_bCycleDir;
	stEmul.m_bCameraEmulator = pstEmul->m_bCameraEmul;

	BOOL bResult = FALSE;

	if (FALSE == stEmul.m_bCameraEmulator || 0 == pstEmul->m_stResolution.cx || 0 == pstEmul->m_stResolution.cy)
	{
		// Check Max Image size...
		int width = 0;
		int height = 0;

		//bResult = CUtil::GetMaxImageSizeDir(stEmul.m_szPath, width, height);

		if (1 > width)			width = 1;
		if (1 > height)			height = 1;

		stEmul.m_stResolution.cx = width;
		stEmul.m_stResolution.cy = height;

		stEmul.m_stRoi.left = 0;
		stEmul.m_stRoi.top = 0;
		stEmul.m_stRoi.right = width;
		stEmul.m_stRoi.bottom = height;
	}
	else
	{
		stEmul.m_stResolution = pstEmul->m_stResolution;
		stEmul.m_stRoi = pstEmul->m_stRoi;
	}

	bResult = m_XmlEmulDevice.AddDevice(stEmul);

#ifdef DEF_LPAPP
	// Not Use...
#else
	if (bResult)
	{
		RefreshDeviceList();
		m_XmlEmulDevice.Save();
	}
#endif

	return bResult;

}

BOOL CConnectEmulFile::UpdateEmulator(const int nCamID, const INFO_EMUL* pstEmul)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (NULL == pstEmul || 0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	INFO_EMUL_DEVICE stEmul;
	memset(&stEmul, 0x00, sizeof(INFO_EMUL_DEVICE));

	CUtil::StringCopy(stEmul.m_szName, pstEmul->m_szName);
	CUtil::StringCopy(stEmul.m_szPath, pstEmul->m_szPath);

	stEmul.m_dwFPS = pstEmul->m_dwFps;
	stEmul.m_bCycleDir = pstEmul->m_bCycleDir;
	stEmul.m_bCameraEmulator = pstEmul->m_bCameraEmul;

	BOOL bResult = FALSE;

	if (FALSE == stEmul.m_bCameraEmulator )
	{
		// Check Max Image size...
		int width = 0;
		int height = 0;

		bResult = CUtil::GetMaxImageSizeDir(stEmul.m_szPath, width, height);

		stEmul.m_stResolution.cx = width;
		stEmul.m_stResolution.cy = height;

		stEmul.m_stRoi.left = 0;
		stEmul.m_stRoi.top = 0;
		stEmul.m_stRoi.right = width;
		stEmul.m_stRoi.bottom = height;
	}
	else
	{
		stEmul.m_stResolution = pstEmul->m_stResolution;
		stEmul.m_stRoi = pstEmul->m_stRoi;
	}	


	bResult = m_XmlEmulDevice.UpdateDevice(nIdx, stEmul);
	if (bResult)
	{
		const INFO_CONNECT_EMUL* pInfo = m_EmulDeviceList[nIdx]->GetDeviceInfo();

		INFO_CONNECT_EMUL stInfo;
		memcpy(&stInfo, pInfo, sizeof(INFO_CONNECT_EMUL));

		CUtil::StringCopy(stInfo.m_szName, pstEmul->m_szName);
		CUtil::StringCopy(stInfo.m_szFilePath, pstEmul->m_szPath);
		CUtil::StringCopy(stInfo.m_szDirPath, pstEmul->m_szPath);
		TCHAR* pCh = _tcsrchr(stInfo.m_szDirPath, _T('\\'));
		if (pCh) *pCh = 0;
		
		stInfo.m_bCameraEmulator = pstEmul->m_bCameraEmul;
		stInfo.m_bCycleDir = pstEmul->m_bCycleDir;
		stInfo.m_dwFps = pstEmul->m_dwFps;

		bResult = m_EmulDeviceList[nIdx]->Update(&stInfo);
	}

	return bResult;
}

BOOL CConnectEmulFile::GetEmulator(const int nCamID, INFO_EMUL* pstEmul)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (NULL == pstEmul || 0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	CEmulFile* pEmul = m_EmulDeviceList[nIdx];
	const INFO_CONNECT_EMUL* pInfo = pEmul->GetDeviceInfo();


	CUtil::StringCopy(pstEmul->m_szName, pInfo->m_szName);
	CUtil::StringCopy(pstEmul->m_szPath, pInfo->m_szFilePath);


	pstEmul->m_bCameraEmul = pInfo->m_bCameraEmulator;
	pstEmul->m_dwFps = pInfo->m_dwFps;
	pstEmul->m_bCycleDir = pInfo->m_bCycleDir;

	pstEmul->m_stResolution.cx = pInfo->m_stFrame.m_dwWidth;
	pstEmul->m_stResolution.cy = pInfo->m_stFrame.m_dwHeight;

	pstEmul->m_stRoi.left = pInfo->m_stFrame.m_dwX;
	pstEmul->m_stRoi.top = pInfo->m_stFrame.m_dwY;
	pstEmul->m_stRoi.right = pstEmul->m_stRoi.left + pInfo->m_stFrame.m_dwWidth;
	pstEmul->m_stRoi.bottom = pstEmul->m_stRoi.top + pInfo->m_stFrame.m_dwHeight;

	return TRUE;
}


void CConnectEmulFile::DeleteEmulator(const TCHAR* pszName)
{
	if(NULL==pszName )
		return;

	m_XmlEmulDevice.DeleteDevice(pszName);

	const int nIdx = FindEmulator(pszName);
	DeleteEmulator(nIdx);

}

void CConnectEmulFile::DeleteEmulator(const int nIdx)
{
	const int nCount = m_EmulDeviceList.size();
	if (0 > nIdx || nCount <= nIdx)
		return;

	CEmulFile* pEmul = m_EmulDeviceList[nIdx];

	std::vector<CEmulFile*>::iterator iterBegin = m_EmulDeviceList.begin();
	iterBegin += nIdx;
	m_EmulDeviceList.erase(iterBegin);

	if (pEmul)
	{
		const INFO_CONNECT_EMUL* pstEmul = pEmul->GetDeviceInfo();
		ReleaseCamID(pstEmul->m_CamID);
		delete pEmul;
	}
	pEmul = NULL;
}


void CConnectEmulFile::ClearEmulator()
{
	m_XmlEmulDevice.ClearDevice();

	std::vector<CEmulFile*>::iterator iter;
	while (m_EmulDeviceList.empty() == false)
	{
		iter = m_EmulDeviceList.begin();
		CEmulFile* pEmulFile = (*iter);
		if (pEmulFile)
		{
			const INFO_CONNECT_EMUL* pstEmul = pEmulFile->GetDeviceInfo();
			ReleaseCamID(pstEmul->m_CamID);
			delete pEmulFile;
		}
		pEmulFile = NULL;

		m_EmulDeviceList.erase(iter);
	}
	m_EmulDeviceList.clear();
}

const int CConnectEmulFile::FindEmulator(const TCHAR* pszName)
{
	if(NULL==pszName)
		return -1;

	const int nCount = m_EmulDeviceList.size();

	for(int i=0; i<nCount; i++)
	{
		const INFO_CONNECT_EMUL* pstEmul = m_EmulDeviceList[i]->GetDeviceInfo();
		if(pstEmul)
		{
			if(TRUE==CUtil::StringCompare((LPTSTR)pszName, (LPTSTR)pstEmul->m_szName))
				return i;
		}
	}
	return -1;
}

const int CConnectEmulFile::FindEmulatorFromID(const int nCamID)
{
	if (0 > nCamID || MAX_EMULCAMERA_COUNT <= nCamID)
		return -1;

	const int nCount = m_EmulDeviceList.size();
	for (int i = 0; i<nCount; i++)
	{
		const INFO_CONNECT_EMUL* pstEmul = m_EmulDeviceList[i]->GetDeviceInfo();
		if (pstEmul)
		{
			if (nCamID == pstEmul->m_CamID)
				return i;
		}
	}
	return -1;
}

BOOL CConnectEmulFile::SaveEmulator()
{
	BOOL bResult = m_XmlEmulDevice.Save();
	return bResult;
}

BOOL CConnectEmulFile::SetRegister(const int nIdx, const DWORD dwAddress, const DWORD dwValue, DWORD dwReserved)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::GetRegister(const int nIdx, const DWORD dwAddress, DWORD* pdwValue, DWORD dwReserved)
{
	BOOL bResult = FALSE;
	return bResult;
}



BOOL CConnectEmulFile::SetGain(const int nCamID, const int nGainType, const int nGainValue)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEmulFile::GetGain(const int nCamID, const int nGainType, int* pnGainValue)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::SetEnableFrameRate(const int nCamID, const unsigned int nEnale)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEmulFile::GetEnableFrameRate(const int nCamID, unsigned int* pnEnale)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::SetFrameRate(const int nCamID, const unsigned int nFrameRate)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::GetFrameRate(const int nCamID, unsigned int* pnFrameRate)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::GetMaxFrameRate(const int nCamID, unsigned int* pnFrameRate)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::SetExposureTime(const int nCamID, const unsigned int nSetExposureTime)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::GetExposureTime(const int nCamID, unsigned int* pnSetExposureTime)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::GetExposureMaxTime(const int nCamID, unsigned int FrameRate, unsigned int* pnSetExposureTime)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::ConvertExposureTime(const int nCamID, unsigned int nStep, double* pfUSec)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::SetTriggerMode(const int nCamID, INFO_TRIGGER_PARA stTrigger)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEmulFile::GetTriggerMode(const int nCamID, INFO_TRIGGER_PARA* pstTrigger)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::SetTriggerDelay(const int nCamID, int nDelay)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::SaveUserset(const int nCamID, unsigned int nNumber)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEmulFile::LoadUserset(const int nCamID, unsigned int nNumber)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::SetStrobeMode(const int nCamID, INFO_STROBE_PARA stStrobe)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEmulFile::GetStrobeMode(const int nCamID, INFO_STROBE_PARA* pstStrobe)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::SetFlipMode(const int nCamID, unsigned short nMode)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEmulFile::GetFlipMode(const int nCamID, unsigned short* pnMode)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::SetROI(const int nCamID, INFO_ROI_PARA stROI)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEmulFile::GetROI(const int nCamID, INFO_ROI_PARA* pstROI)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::SetUsersetStartNo(const int nCamID, unsigned char nUsersetStartNo)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEmulFile::GetUsersetStartNo(const int nCamID, unsigned char* pnUsersetStartNo)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::SetDataBit(const int nCamID, unsigned short nDataBit)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::GetDataBit(const int nCamID, unsigned short* pnDataBit)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::SetColorMode(const int nCamID, unsigned short nColorMode)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::GetColorMode(const int nCamID, unsigned short* pnColorMode)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::SetMTU(const int nCamID, unsigned int nMTU)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::GetMTU(const int nCamID, unsigned int* pnMTU)
{
	BOOL bResult = FALSE;
	return bResult;
}



BOOL CConnectEmulFile::GetDiag(const int nCamID, void* pstDiag, const int nLen)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}


BOOL CConnectEmulFile::SetSWTrigger(const int nCamID)
{
	const int nIdx = FindEmulatorFromID(nCamID);
	if (0 > nIdx || MAX_EMULCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}


// LUT
BOOL CConnectEmulFile::SetLutMode(const int nCamID, unsigned short nMode)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEmulFile::GetLutMode(const int nCamID, unsigned short* pnMode)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::WriteLut(const int nCamID, const INFO_LUT_PARA* pLutList, const int nLen, BOOL bEeprom)
{
	BOOL bResult = FALSE;
	return bResult;
}


// Effect
BOOL CConnectEmulFile::SetEffectNR(const int nCamID, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEmulFile::GetEffectNR(const int nCamID, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::SetEffectGC(const int nCamID, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEmulFile::GetEffectGC(const int nCamID, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::SetEffectCM(const int nCamID, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEmulFile::GetEffectCM(const int nCamID, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::SetEffectAWB(const int nCamID, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEmulFile::GetEffectAWB(const int nCamID, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::SetEffectSmooth(const int nCamID, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEmulFile::GetEffectSmooth(const int nCamID, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}


BOOL CConnectEmulFile::SetEffectSharpen(const int nCamID, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEmulFile::GetEffectSharpen(const int nCamID, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::SetEffectFPN(const int nCamID, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEmulFile::GetEffectFPN(const int nCamID, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::SetEffectPRNU(const int nCamID, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEmulFile::GetEffectPRNU(const int nCamID, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::SetEffectDPC(const int nCamID, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEmulFile::GetEffectDPC(const int nCamID, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEmulFile::SetColorGain(const int nCamID, const int nGainType, int nGainVal)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEmulFile::GetColorGain(const int nCamID, const int nGainType, int* pnGainVal)
{
	BOOL bResult = FALSE;
	return bResult;
}