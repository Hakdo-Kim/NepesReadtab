#include "StdAfx.h"
#include "ConnectCL.h"
#include "Util/Util.h"

CConnectCL::CConnectCL()
{
	for (int i = 0; i < MAX_CLCAMERA_COUNT; i++)
	{
		m_IdList[i] = FALSE;
	}
}

CConnectCL::~CConnectCL()
{
}

int	CConnectCL::SearchSerial(INFO_SERIAL* pstInfo, const int nLen)
{
	const int idx = GetEnableCamID();
	if (0 > idx)
		return -1;
	ReleaseCamID(idx);

	int nCount = m_CLFileList[idx].SearchSerial(pstInfo, nLen);
	return nCount;
}

int CConnectCL::GetEnableCamID()
{
	int idx = -1;
	for (int i = 0; i < MAX_CLCAMERA_COUNT; i++)
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

void CConnectCL::ReleaseCamID(int nCamID)
{
	if (0 > nCamID || MAX_CLCAMERA_COUNT <= nCamID)
		return;
	m_IdList[nCamID] = FALSE;
}

const int CConnectCL::FindCameraLink(const TCHAR* pszName)
{
	if (NULL == pszName)
		return -1;

	const int nCount = m_CLDeviceList.size();

	for (int i = 0; i<nCount; i++)
	{
		const INFO_CONNECT_CAMERALINK* pstCL = m_CLDeviceList[i]->GetDeviceInfo();
		if (pstCL)
		{
			if (TRUE == CUtil::StringCompare((LPTSTR)pszName, (LPTSTR)pstCL->m_szName))
				return i;
		}
	}
	return -1;
}

const int CConnectCL::FindCameraLinkFromID(const int nCamID)
{
	if (0 > nCamID || MAX_CLCAMERA_COUNT <= nCamID)
		return -1;

	const int nCount = m_CLDeviceList.size();
	for (int i = 0; i<nCount; i++)
	{
		const INFO_CONNECT_CAMERALINK* pstCL = m_CLDeviceList[i]->GetDeviceInfo();
		if (pstCL)
		{
			if (nCamID == pstCL->m_CamID)
				return i;
		}
	}
	return -1;
}

BOOL CConnectCL::IsConnected()
{
	BOOL bResult = TRUE;
	return bResult;
}

BOOL CConnectCL::Open(TYPE_NETWORK eNetwork)
{
	BOOL bResult = Open(eNetwork, NULL);
	return bResult;
}

BOOL CConnectCL::Open(TYPE_NETWORK eNetwork, void* pReserved)
{
	if (TYPE_NETWORK_CAMERALINK != eNetwork)
		return FALSE;
	m_eNetwork = eNetwork;
	
#ifdef DEF_LPAPP
	// Not Use
#else
	ResearchDeviceInfo();
#endif
	return TRUE;
}

void CConnectCL::Close()
{
	const int nCount = GetDeviceCount();
	for (int i = 0; i<nCount; i++)
	{
		CCLFile* pCL = m_CLDeviceList[i];
		if (pCL)
		{
			const INFO_CONNECT_CAMERALINK* pstCL = pCL->GetDeviceInfo();
			ReleaseCamID(pstCL->m_CamID);

			pCL->Close();
			delete pCL;
		}
	}

	std::vector<CCLFile*> eclear;		// vector memory leak ¹æÁö.
	m_CLDeviceList.swap(eclear);
	eclear.clear();
	m_CLDeviceList.clear();

}

int CConnectCL::GetDeviceCount()
{
	int nCount = m_CLDeviceList.size();
	return nCount;
}

int CConnectCL::GetDeviceIndex(const INFO_CONNECT_DEV* pDev)
{
	const int nCount = GetDeviceCount();
	const INFO_CONNECT_CAMERALINK* pCL = (INFO_CONNECT_CAMERALINK*)pDev;

	int nCamId = -1;
	for (int i = 0; i<nCount; i++)
	{
		const INFO_CONNECT_CAMERALINK* pstCLDev = m_CLDeviceList[i]->GetDeviceInfo();
		if (TRUE == CUtil::StringCompare((LPTSTR)pCL->m_szName, (LPTSTR)pstCLDev->m_szName))
		{
			nCamId = pCL->m_CamID;
			break;
		}
	}

	return nCamId;
}

int CConnectCL::GetDeviceID(const TCHAR* pName)
{
	if (NULL == pName)
		return -1;

	int nCamId = -1;

	const int nCount = GetDeviceCount();
	for (int i = 0; i<nCount; i++)
	{
		const INFO_CONNECT_CAMERALINK* pstCLDev = m_CLDeviceList[i]->GetDeviceInfo();
		if (TRUE == CUtil::StringCompare((LPTSTR)pstCLDev->m_szName, (LPTSTR)pName))
		{
			nCamId = pstCLDev->m_CamID;
			break;
		}
	}

	return nCamId;
}

BOOL CConnectCL::GetDeviceInfo(int nIdx, INFO_CONNECT_DEV* pstDevice)
{
	if (MAX_CLCAMERA_COUNT <= nIdx || NULL == pstDevice || 
		TYPE_NETWORK_CAMERALINK != pstDevice->m_eNetwork ||	FALSE == m_CLDeviceList[nIdx]->IsOpen())
	{
		return FALSE;
	}

	INFO_CONNECT_CAMERALINK* pCL = (INFO_CONNECT_CAMERALINK*)pstDevice;

	const INFO_CONNECT_CAMERALINK* pstCLDev = m_CLDeviceList[nIdx]->GetDeviceInfo();
	memcpy(pCL, pstCLDev, sizeof(INFO_CONNECT_CAMERALINK));

	return TRUE;
}

BOOL CConnectCL::UpdateDeviceInfo(int nCamID, INFO_CONNECT_DEV* pstDevice)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx || NULL == pstDevice || 
		TYPE_NETWORK_CAMERALINK != pstDevice->m_eNetwork)
	{
		return FALSE;
	}

	INFO_CONNECT_CAMERALINK* pCL = (INFO_CONNECT_CAMERALINK*)pstDevice;
	return TRUE;
}

BOOL CConnectCL::ResearchDeviceInfo()
{
	const int nCount = GetDeviceCount();

#ifndef DEF_LPAPP
	for (int i = 0; i < MAX_CLCAMERA_COUNT; i++)
		ReleaseCamID(i);
		
	BOOL bResult = m_XmlCLDevice.Load();
	if (FALSE == bResult && 1 > nCount)
		return FALSE;
#endif

	RefreshDeviceList();

	return TRUE;
}

void CConnectCL::RefreshDeviceList()
{
	INFO_CONNECT_CAMERALINK stCLDev;

	const int nCount = m_XmlCLDevice.GetDeviceCount();
	for (int i = 0; i<nCount; i++)
	{
		const INFO_CL_DEVICE* pCL = m_XmlCLDevice.GetDeviceInfo(i);
		memset(&stCLDev, 0x00, sizeof(INFO_CONNECT_CAMERALINK));

		stCLDev.m_stArg.m_eNetwork = TYPE_NETWORK_CAMERALINK;
		stCLDev.m_CamID = pCL->m_CamID;
		
		m_IdList[pCL->m_CamID] = TRUE;

		CUtil::StringCopy(stCLDev.m_stArg.m_szArg, (LPTSTR)(LPCTSTR)m_XmlCLDevice.GetModelName(pCL->m_stCameraLink.m_eClDevice));
		CUtil::StringCopy(stCLDev.m_szName, pCL->m_stCameraLink.m_szName);

		stCLDev.m_eClFrameGrabber = pCL->m_stCameraLink.m_eClFrameGrabber;
		stCLDev.m_eClDevice = pCL->m_stCameraLink.m_eClDevice;
		stCLDev.m_eClImageTaps = pCL->m_stCameraLink.m_eClImageTaps;
		stCLDev.m_eClDataBit = pCL->m_stCameraLink.m_eClDataBit;
		stCLDev.m_eClColor = pCL->m_stCameraLink.m_eClColor;
		CUtil::StringCopy(stCLDev.m_szCamFile[CLCAMFILE_NORMAL], pCL->m_szCamFile[CLCAMFILE_NORMAL]);
		CUtil::StringCopy(stCLDev.m_szCamFile[CLCAMFILE_TRIGGER], pCL->m_szCamFile[CLCAMFILE_TRIGGER]);

		//
		CUtil::StringCopy(stCLDev.m_szSerial, pCL->m_stCameraLink.m_szSerial);
		stCLDev.m_dwSpeed = pCL->m_stCameraLink.m_dwSpeed;

		// Check Duplicate device...
		if (-1< FindCameraLink(stCLDev.m_szName))
			continue;

		CCLFile* pCLFile = new CCLFile();
		if (TRUE == pCLFile->Open(&stCLDev))
		{
			m_CLDeviceList.push_back(pCLFile);
		}
	}
}



// Device Information
BOOL CConnectCL::GetFrameInfo(const int nCamID, INFO_FRAME* pstFrame)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	const INFO_CONNECT_CAMERALINK* pstCLDev = m_CLDeviceList[nIdx]->GetDeviceInfo();

	BOOL bResult = FALSE;
	CCLFile* pClFile = m_CLDeviceList[nIdx];
	if(pClFile)
	{
		bResult = pClFile->GetFrameInfo(pstFrame);
	}
	return bResult;
}

BOOL CConnectCL::SetEventFunc(const int nCamID, FuncAcquisitionEvent pFunc, void* pUserData)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = m_CLDeviceList[nIdx]->SetEventFunc(pFunc, pUserData);
	return bResult;
}

BOOL CConnectCL::Start(const int nCamID, BOOL bSingle)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL)
	{
		bResult = pCL->Start(bSingle);
	}

	return bResult;
}

void CConnectCL::Stop(const int nCamID)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL)
	{
		pCL->Stop();
	}

}

BOOL CConnectCL::IsOpen(const int nCamID)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL)
	{
		bResult = pCL->IsOpenSerial();
	}
	return bResult;
}

BOOL CConnectCL::Open(const int nCamID)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL)
	{
		bResult = pCL->OpenSerial();
	}
	return bResult;
}

void CConnectCL::Close(const int nCamID)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL)
	{
		pCL->Close();
	}

}


// Command Function
BOOL CConnectCL::SetRegister(const int nCamID, const DWORD dwAddress, const DWORD dwValue, DWORD dwReserved)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL)
	{
	}
	return bResult;
}
BOOL CConnectCL::GetRegister(const int nCamID, const DWORD dwAddress, DWORD* pdwValue, DWORD dwReserved)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL)
	{
	}
	return bResult;
}

//
BOOL CConnectCL::SetGain(const int nCamID, const int nGainType, const int nGainValue)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL)
	{
		if (GAIN_DIGITAL_ADC == nGainType)
			bResult = pCL->SetGainDigital(nGainValue);
		else if (GAIN_ANALOG_PGA == nGainType)
			bResult = pCL->SetGainAnalog(nGainValue);
	}
	return bResult;
}
BOOL CConnectCL::GetGain(const int nCamID, const int nGainType, int* pnGainValue)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL && pnGainValue)
	{
		DWORD dwValue = 0;

		if (GAIN_DIGITAL_ADC == nGainType)
			bResult = pCL->GetGainDigital(&dwValue);
		else if (GAIN_ANALOG_PGA == nGainType)
			bResult = pCL->GetGainAnalog(&dwValue);

		*pnGainValue = dwValue;
	}
	return bResult;
}

BOOL CConnectCL::SetEnableFrameRate(const int nCamID, const unsigned int nEnale)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	return TRUE;
}
BOOL CConnectCL::GetEnableFrameRate(const int nCamID, unsigned int* pnEnale)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;
	*pnEnale = 1;
	return TRUE;
}

BOOL CConnectCL::SetFrameRate(const int nCamID, const unsigned int nFrameRate)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL)
	{
		bResult = pCL->SetFps(nFrameRate);
	}
	return bResult;
}
BOOL CConnectCL::GetFrameRate(const int nCamID, unsigned int* pnFrameRate)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL && pnFrameRate)
	{
		DWORD dwValue = 0;
		bResult = pCL->GetFps(&dwValue);

		*pnFrameRate = dwValue;
	}
	return bResult;
}
BOOL CConnectCL::GetMaxFrameRate(const int nCamID, unsigned int* pnFrameRate)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = TRUE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL && pnFrameRate)
	{
		const INFO_USER_SETTING* pSetting = pCL->GetUserSetting();
		*pnFrameRate = pSetting->m_stAnalog.m_stFPS.m_nMax;
	}
	return bResult;
}

BOOL CConnectCL::SetExposureTime(const int nCamID, const unsigned int nSetExposureTime)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL)
	{
		bResult = pCL->SetExposureTime(nSetExposureTime);
	}
	return bResult;
}
BOOL CConnectCL::GetExposureTime(const int nCamID, unsigned int* pnSetExposureTime)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL && pnSetExposureTime)
	{
		DWORD dwValue = 0;
		bResult = pCL->GetExposureTime(&dwValue);

		*pnSetExposureTime = dwValue;
	}
	return bResult;
}
BOOL CConnectCL::GetExposureMaxTime(const int nCamID, unsigned int FrameRate, unsigned int* pnSetExposureTime)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL)
	{
		const INFO_USER_SETTING* pstSetting = pCL->GetUserSetting();

		if (pstSetting && pnSetExposureTime)
		{
			//*pnSetExposureTime = pstSetting->m_stAnalog.m_stExposure.m_nMax;
			bResult = TRUE;
		}
	}
	return bResult;
}

BOOL CConnectCL::ConvertExposureTime(const int nCamID, unsigned int nStep, double* pfUSec)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL && pfUSec)
	{
		*pfUSec = nStep;
		bResult = TRUE;
	}
	return bResult;
}

BOOL CConnectCL::SetTriggerMode(const int nCamID, INFO_TRIGGER_PARA stTrigger)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL)
	{
		bResult = pCL->SetTriggerMode(stTrigger);
	}
	return bResult;
}
BOOL CConnectCL::GetTriggerMode(const int nCamID, INFO_TRIGGER_PARA* pstTrigger)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL && pstTrigger)
	{
		bResult = pCL->GetTriggerMode(pstTrigger);
	}
	return bResult;
}

BOOL CConnectCL::SetTriggerDelay(const int nCamID, int nDelay)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL)
	{
		bResult = pCL->SetTriggerDelay((DWORD) nDelay);
	}
	return bResult;
}


BOOL CConnectCL::SaveUserset(const int nCamID, unsigned int nNumber)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL)
	{
	}
	return bResult;
}
BOOL CConnectCL::LoadUserset(const int nCamID, unsigned int nNumber)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL)
	{
	}
	return bResult;
}

BOOL CConnectCL::SetStrobeMode(const int nCamID, INFO_STROBE_PARA stStrobe)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL)
	{
		bResult = pCL->SetStrobeMode(stStrobe);
	}
	return bResult;
}
BOOL CConnectCL::GetStrobeMode(const int nCamID, INFO_STROBE_PARA* pstStrobe)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL && pstStrobe)
	{
		bResult = pCL->GetStrobeMode(pstStrobe);
	}

	return bResult;
}

BOOL CConnectCL::SetFlipMode(const int nCamID, unsigned short nMode)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL)
	{
	}
	return bResult;
}
BOOL CConnectCL::GetFlipMode(const int nCamID, unsigned short* pnMode)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL)
	{
	}
	return bResult;
}

BOOL CConnectCL::SetROI(const int nCamID, INFO_ROI_PARA stROI)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL)
	{
		bResult = pCL->SetRoi(stROI);
	}
	return bResult;
}
BOOL CConnectCL::GetROI(const int nCamID, INFO_ROI_PARA* pstROI)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL)
	{
		bResult = pCL->GetRoi(pstROI);
	}
	return bResult;
}

BOOL CConnectCL::SetUsersetStartNo(const int nCamID, unsigned char nUsersetStartNo)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL)
	{
		bResult = pCL->SetStartupUserset(nUsersetStartNo);
	}
	return bResult;
}
BOOL CConnectCL::GetUsersetStartNo(const int nCamID, unsigned char* pnUsersetStartNo)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL)
	{
		DWORD dwNumber = 0;
		bResult = pCL->GetStartupUserset(&dwNumber);
		if (bResult)
			*pnUsersetStartNo = (unsigned char)dwNumber;

	}
	return bResult;
}

BOOL CConnectCL::SetDataBit(const int nCamID, unsigned short nDataBit)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL)
	{
		bResult = pCL->SetDataBit(nDataBit);
	}
	return bResult;
}

BOOL CConnectCL::GetDataBit(const int nCamID, unsigned short* pnDataBit)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL)
	{
		bResult = pCL->GetDataBit(pnDataBit);
	}
	return bResult;
}

BOOL CConnectCL::SetColorMode(const int nCamID, unsigned short nColorMode)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectCL::GetColorMode(const int nCamID, unsigned short* pnColorMode)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}




BOOL CConnectCL::SetMTU(const int nCamID, unsigned int nMTU)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectCL::GetMTU(const int nCamID, unsigned int* pnMTU)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectCL::GetDiag(const int nCamID, void* pstDiag, const int nLen)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL)
	{
	}
	return bResult;
}
BOOL CConnectCL::SetSWTrigger(const int nCamID)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL)
	{
		bResult = pCL->SetTrigger();
	}
	return bResult;
}



// CameraLink Control
BOOL CConnectCL::AddCameraLink(const INFO_CAMERALINK* pstCL, const INFO_FRAMEGRABBER_CAMFILE* pstCamFile)
{
	const int nCount = m_CLDeviceList.size();
	if (NULL == pstCL || NULL == pstCamFile || MAX_CLCAMERA_COUNT <= nCount)
		return FALSE;

	const int nCamID = GetEnableCamID();
	if (0 > nCamID || MAX_CLCAMERA_COUNT <= nCamID)
	{
		ReleaseCamID(nCamID);
		return FALSE;
	}

	TCHAR szLocation[MAX_TEXT_LEN] = _T("");
	CUtil::GetCurrentDirectory(szLocation, MAX_TEXT_LEN);

	INFO_CL_DEVICE stCL;
	memset(&stCL, 0x00, sizeof(INFO_CL_DEVICE));

	//
	stCL.m_CamID = nCamID;
	CUtil::StringFormat(stCL.m_szCamFile[CLCAMFILE_NORMAL], MAX_CL_PATH, _T("%s\\%s"), szLocation, pstCamFile->m_szCamFile[CLCAMFILE_NORMAL]);
	CUtil::StringFormat(stCL.m_szCamFile[CLCAMFILE_TRIGGER], MAX_CL_PATH, _T("%s\\%s"), szLocation, pstCamFile->m_szCamFile[CLCAMFILE_TRIGGER]);
	

	CUtil::StringCopy(stCL.m_stCameraLink.m_szName, pstCL->m_szName);
	// Grabber & Camera Information
	stCL.m_stCameraLink.m_eClFrameGrabber = pstCL->m_eClFrameGrabber;
	stCL.m_stCameraLink.m_eClDevice = pstCL->m_eClDevice;
	stCL.m_stCameraLink.m_eClImageTaps = pstCL->m_eClImageTaps;
	stCL.m_stCameraLink.m_eClDataBit = pstCL->m_eClDataBit;
	stCL.m_stCameraLink.m_eClColor = pstCL->m_eClColor;

	// Serial Information
	CUtil::StringCopy(stCL.m_stCameraLink.m_szSerial, pstCL->m_szSerial);
	stCL.m_stCameraLink.m_dwSpeed = pstCL->m_dwSpeed;


	BOOL bResult = m_XmlCLDevice.AddDevice(stCL);
#ifdef DEF_LPAPP
	// Not Use...
#else
	if (bResult)
	{
		RefreshDeviceList();
		m_XmlCLDevice.Save();
	}
#endif

	return bResult;
}

BOOL CConnectCL::UpdateCameraLink(const int nCamID, const INFO_CAMERALINK* pstCL, const INFO_FRAMEGRABBER_CAMFILE* pstCamFile)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (NULL == pstCL || 0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	TCHAR szLocation[MAX_TEXT_LEN] = _T("");
	CUtil::GetCurrentDirectory(szLocation, MAX_TEXT_LEN);

	INFO_CL_DEVICE stCL;
	memset(&stCL, 0x00, sizeof(INFO_CL_DEVICE));

	//
	stCL.m_CamID = nCamID;
	CUtil::StringFormat(stCL.m_szCamFile[CLCAMFILE_NORMAL], MAX_CL_PATH, _T("%s\\%s"), szLocation, pstCamFile->m_szCamFile[CLCAMFILE_NORMAL]);
	CUtil::StringFormat(stCL.m_szCamFile[CLCAMFILE_TRIGGER], MAX_CL_PATH, _T("%s\\%s"), szLocation, pstCamFile->m_szCamFile[CLCAMFILE_TRIGGER]);

	CUtil::StringCopy(stCL.m_stCameraLink.m_szName, pstCL->m_szName);
	// Grabber & Camera Information
	stCL.m_stCameraLink.m_eClFrameGrabber = pstCL->m_eClFrameGrabber;
	stCL.m_stCameraLink.m_eClDevice = pstCL->m_eClDevice;
	stCL.m_stCameraLink.m_eClImageTaps = pstCL->m_eClImageTaps;
	stCL.m_stCameraLink.m_eClDataBit = pstCL->m_eClDataBit;
	stCL.m_stCameraLink.m_eClColor = pstCL->m_eClColor;

	// Serial Information
	CUtil::StringCopy(stCL.m_stCameraLink.m_szSerial, pstCL->m_szSerial);
	stCL.m_stCameraLink.m_dwSpeed = pstCL->m_dwSpeed;


	BOOL bResult = m_XmlCLDevice.UpdateDevice(nIdx, stCL);
	if (bResult)
	{
		const INFO_CONNECT_CAMERALINK* pInfo = m_CLDeviceList[nIdx]->GetDeviceInfo();

		INFO_CONNECT_CAMERALINK stInfo;
		memcpy(&stInfo, pInfo, sizeof(INFO_CONNECT_CAMERALINK));

		//
		stInfo.m_stArg.m_eNetwork = TYPE_NETWORK_CAMERALINK;
		stInfo.m_CamID = stCL.m_CamID;

		CUtil::StringCopy(stInfo.m_stArg.m_szArg, stCL.m_stCameraLink.m_szName);
		CUtil::StringCopy(stInfo.m_szName, stCL.m_stCameraLink.m_szName);

		stInfo.m_eClFrameGrabber = stCL.m_stCameraLink.m_eClFrameGrabber;
		stInfo.m_eClDevice = stCL.m_stCameraLink.m_eClDevice;
		stInfo.m_eClImageTaps = stCL.m_stCameraLink.m_eClImageTaps;
		stInfo.m_eClDataBit = stCL.m_stCameraLink.m_eClDataBit;
		stInfo.m_eClColor = stCL.m_stCameraLink.m_eClColor;
		CUtil::StringCopy(stInfo.m_szCamFile[CLCAMFILE_NORMAL], stCL.m_szCamFile[CLCAMFILE_NORMAL]);
		CUtil::StringCopy(stInfo.m_szCamFile[CLCAMFILE_TRIGGER], stCL.m_szCamFile[CLCAMFILE_TRIGGER]);

		//
		CUtil::StringCopy(stInfo.m_szSerial, stCL.m_stCameraLink.m_szSerial);
		stInfo.m_dwSpeed = stCL.m_stCameraLink.m_dwSpeed;

		bResult = m_CLDeviceList[nIdx]->Update(&stInfo);
	}

	return bResult;
}

void CConnectCL::DeleteCameraLink(const TCHAR* pszName)
{
	if (NULL == pszName)
		return;

	m_XmlCLDevice.DeleteDevice(pszName);

	const int nIdx = FindCameraLink(pszName);
	DeleteCameraLink(nIdx);

}

void CConnectCL::DeleteCameraLink(const int nIdx)
{
	const int nCount = m_CLDeviceList.size();
	if (0 > nIdx || nCount <= nIdx)
		return;

	CCLFile* pCL = m_CLDeviceList[nIdx];

	std::vector<CCLFile*>::iterator iterBegin = m_CLDeviceList.begin();
	iterBegin += nIdx;
	m_CLDeviceList.erase(iterBegin);

	if (pCL)
	{
		const INFO_CONNECT_CAMERALINK* pstCL = pCL->GetDeviceInfo();
		ReleaseCamID(pstCL->m_CamID);
		delete pCL;
	}
	pCL = NULL;
}

void CConnectCL::ClearCameraLink()
{
	m_XmlCLDevice.ClearDevice();

	std::vector<CCLFile*>::iterator iter;
	while (m_CLDeviceList.empty() == false)
	{
		iter = m_CLDeviceList.begin();
		CCLFile* pCLFile = (*iter);
		if (pCLFile)
		{
			const INFO_CONNECT_CAMERALINK* pstCL = pCLFile->GetDeviceInfo();
			ReleaseCamID(pstCL->m_CamID);
			delete pCLFile;
		}
		pCLFile = NULL;

		m_CLDeviceList.erase(iter);
	}
	m_CLDeviceList.clear();
}

BOOL CConnectCL::SaveCameraLink()
{
	BOOL bResult = m_XmlCLDevice.Save();
	return bResult;
}

BOOL CConnectCL::GetCameraLink(const int nCamID, INFO_CAMERALINK* pstCL)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (NULL == pstCL || 0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	const INFO_CONNECT_CAMERALINK* pInfo = pCL->GetDeviceInfo();

	//
	CUtil::StringCopy(pstCL->m_szName, pInfo->m_szName);

	// Grabber & Camera Information
	pstCL->m_eClFrameGrabber = pInfo->m_eClFrameGrabber;
	pstCL->m_eClDevice = pInfo->m_eClDevice;
	pstCL->m_eClImageTaps = pInfo->m_eClImageTaps;
	pstCL->m_eClDataBit = pInfo->m_eClDataBit;
	pstCL->m_eClColor = pInfo->m_eClColor;

	// Serial Information
	CUtil::StringCopy(pstCL->m_szSerial, pInfo->m_szSerial);
	pstCL->m_dwSpeed = pInfo->m_dwSpeed;

	return TRUE;
}

BOOL CConnectCL::GetConnectedDeviceInfo(const int nCamID, INFO_DEFDEV* pstDev, BOOL bReload)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (NULL == pstDev || 0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;
	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL->IsStarted())
	{
		bResult = TRUE;
		if (bReload)
		{
			bResult = pCL->LoadCameraUserSetting();
			if (FALSE == bResult)
				return bResult;
		}

		const INFO_CAM_DEVICE* pstCamDev = pCL->GetCameraDevice();
		const INFO_USER_SETTING* pstSetting = pCL->GetUserSetting();

		/*// ROI: Use XML Information...
		if (pstDev->m_stDefROI.m_bSupport)
		{
			pstDev->m_stDefROI.m_nUnitX;
			pstDev->m_stDefROI.m_nUnitY;
			pstDev->m_stDefROI.m_nUnitW;
			pstDev->m_stDefROI.m_nUnitH;

			pstDev->m_stDefROI.m_nMinWidth;
			pstDev->m_stDefROI.m_nMinHeight;
		}
		//*/

		// Digital Gain
		if (pstDev->m_stDefGain01.m_bSupport)
		{
			const INFO_STATUS_ANALOG* pstAnalog = &pstSetting->m_stAnalog;

			pstDev->m_stDefGain01.m_stRange.m_nFrom = pstAnalog->m_stDigital.m_nMin;
			pstDev->m_stDefGain01.m_stRange.m_nTo = pstAnalog->m_stDigital.m_nMax;
		}

		// Analog Gain
		if (pstDev->m_stDefGain02.m_bSupport)
		{
			const INFO_STATUS_ANALOG* pstAnalog = &pstSetting->m_stAnalog;

			pstDev->m_stDefGain02.m_stRange.m_nFrom = pstAnalog->m_stAnalog.m_nMin;
			pstDev->m_stDefGain02.m_stRange.m_nTo = pstAnalog->m_stAnalog.m_nMax;
		}

		// Exposure
		if (pstDev->m_stDefExposure.m_bSupport)
		{
			const INFO_STATUS_ANALOG* pstAnalog = &pstSetting->m_stAnalog;

			pstDev->m_stDefExposure.m_stRange.m_nFrom = pstAnalog->m_stExposure.m_nMin;
			pstDev->m_stDefExposure.m_stRange.m_nTo = pstAnalog->m_stExposure.m_nMax;
		}

		// Framerate
		if (pstDev->m_stDefFrameRate.m_bSupport)
		{
			const INFO_STATUS_ANALOG* pstAnalog = &pstSetting->m_stAnalog;

			pstDev->m_stDefFrameRate.m_stRange.m_nFrom = pstAnalog->m_stFPS.m_nMin;
			pstDev->m_stDefFrameRate.m_stRange.m_nTo = pstAnalog->m_stFPS.m_nMax;
		}

		// Trigger
		if (pstDev->m_stDefTrigger.m_bSupport)
		{
			const INFO_STATUS_TRIGGER* pstTrigger = &pstSetting->m_stTrigger;

			pstDev->m_stDefTrigger.m_stDelayRange.m_nFrom = pstTrigger->m_stTriggerDelay.m_nMin;
			pstDev->m_stDefTrigger.m_stDelayRange.m_nTo = pstTrigger->m_stTriggerDelay.m_nMax;
		}

		// Strobe
		if (pstDev->m_stDefStrobe.m_bSupport)
		{
			const INFO_STATUS_TRIGGER* pstTrigger = &pstSetting->m_stTrigger;

			pstDev->m_stDefStrobe.m_stDelayRange.m_nFrom = pstTrigger->m_stStrobeDelay.m_nMin;
			pstDev->m_stDefStrobe.m_stDelayRange.m_nTo = pstTrigger->m_stStrobeDelay.m_nMax;

			pstDev->m_stDefStrobe.m_stWidthRange.m_nFrom = pstTrigger->m_stStrobeDuration.m_nMin;
			pstDev->m_stDefStrobe.m_stWidthRange.m_nTo = pstTrigger->m_stStrobeDuration.m_nMax;
		}

	}

	return bResult;
}



// LUT
BOOL CConnectCL::SetLutMode(const int nCamID, unsigned short nMode)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL)
	{
		bResult = pCL->SetLutMode(nMode);
	}
	return bResult;
}
BOOL CConnectCL::GetLutMode(const int nCamID, unsigned short* pnMode)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL)
	{
		bResult = pCL->GetLutMode(pnMode);
	}
	return bResult;
}

BOOL CConnectCL::WriteLut(const int nCamID, const INFO_LUT_PARA* pLutList, const int nLen, BOOL bEeprom)
{
	const int nIdx = FindCameraLinkFromID(nCamID);
	if (0 > nIdx || MAX_CLCAMERA_COUNT <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	CCLFile* pCL = m_CLDeviceList[nIdx];
	if (pCL)
	{
		bResult = pCL->WriteLut(pLutList, nLen, bEeprom);
	}
	return bResult;
}

// Effect
BOOL CConnectCL::SetEffectNR(const int nCamID, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectCL::GetEffectNR(const int nCamID, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectCL::SetEffectGC(const int nCamID, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectCL::GetEffectGC(const int nCamID, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectCL::SetEffectCM(const int nCamID, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectCL::GetEffectCM(const int nCamID, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectCL::SetEffectAWB(const int nCamID, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectCL::GetEffectAWB(const int nCamID, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectCL::SetEffectSmooth(const int nCamID, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectCL::GetEffectSmooth(const int nCamID, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectCL::SetEffectSharpen(const int nCamID, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectCL::GetEffectSharpen(const int nCamID, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectCL::SetEffectFPN(const int nCamID, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectCL::GetEffectFPN(const int nCamID, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectCL::SetEffectPRNU(const int nCamID, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectCL::GetEffectPRNU(const int nCamID, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectCL::SetEffectDPC(const int nCamID, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectCL::GetEffectDPC(const int nCamID, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectCL::SetColorGain(const int nCamID, const int nGainType, int nGainVal)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectCL::GetColorGain(const int nCamID, const int nGainType, int* pnGainVal)
{
	BOOL bResult = FALSE;
	return bResult;
}