#include "StdAfx.h"
#include "ConnectUSB.h"
#include "Util/Util.h"

#include "inc/PixelFormat.h"


CConnectUSB::CConnectUSB()
{
	memset(m_ArgList, 0x00, sizeof(INFO_ARG)*MAX_CAMERA_INTERFACE);
	m_nTempCount = 0;
}

CConnectUSB::~CConnectUSB()
{
}

void CConnectUSB::AcquisitionEventHandler(unsigned char* pBuffer, unsigned int nSize, void* lpArg)
{
	INFO_ARG* pArg = (INFO_ARG*)lpArg;
	if (pArg && pArg->m_FuncAcq)
	{
		FuncAcquisitionEvent FuncAcq = pArg->m_FuncAcq;
		(*FuncAcq)(pBuffer, nSize, NULL, pArg->m_pUserData);
	}
}


BOOL CConnectUSB::IsConnected()
{
	BOOL bConnect = FALSE;

	const TYPE_NETWORK eNetwork = GetNetworkType();
	if (TYPE_NETWORK_USB == eNetwork && m_USB.IsOpen())
		bConnect = TRUE;

	return bConnect;
}

BOOL CConnectUSB::Open(TYPE_NETWORK eNetwork)
{
	BOOL bResult = FALSE;

	bResult = Open(eNetwork, NULL);

	return bResult;
}

BOOL CConnectUSB::Open(TYPE_NETWORK eNetwork, void* pReserved)
{
	if (TYPE_NETWORK_USB != eNetwork)
		return FALSE;

	BOOL bResult = m_USB.Open();
	if (FALSE == bResult)
	{
		Close();
		return FALSE;
	}

	m_eNetwork = TYPE_NETWORK_USB;

	return TRUE;

}


void CConnectUSB::Close()
{
	m_USB.Close();
	m_eNetwork = TYPE_NETWORK_NONE;
}

int CConnectUSB::GetDeviceCount()
{
	const int nCount = m_USB.GetEnableDeviceCount();
	return nCount;
}

int CConnectUSB::GetDeviceIndex(const INFO_CONNECT_DEV* pDev)
{
	const int nCount = m_USB.GetEnableDeviceCount();
	int nIdx = -1;

	if (1>nCount || nCount <= nIdx || NULL == pDev)
		return nIdx;

	for (int i = 0; i<nCount; i++)
	{
		const INFO_USBDEV* pModule = m_USB.GetDeviceModuleInfo(i);

		if (pModule->m_stUsbDevInfo.Index == pDev->m_dwArg)
		{
			nIdx = i;
			break;
		}
	}

	return nIdx;
}

int CConnectUSB::GetDeviceID(const TCHAR* pName)
{
	const int nCount = m_USB.GetEnableDeviceCount();
	int nIdx = -1;

	if (1>nCount || nCount <= nIdx || NULL == pName)
		return nIdx;

	INFO_CONNECT_USB stUsb;
	memset(&stUsb, 0x00, sizeof(INFO_CONNECT_USB));
	stUsb.m_stArg.m_eNetwork = TYPE_NETWORK_USB;

	BOOL bResult = FALSE;

	for (int i = 0; i < nCount; i++)
	{
		bResult = GetDeviceInfo(i, (INFO_CONNECT_DEV*)&stUsb);
		if (bResult && CUtil::StringCompare((TCHAR*)pName, stUsb.m_stArg.m_szArg))
		{
			nIdx = i;
			break;
		}
	}

	return nIdx;
}

BOOL CConnectUSB::GetDeviceInfo(int nIdx, INFO_CONNECT_DEV* pstDevice)
{
	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx ||
		NULL == pstDevice || TYPE_NETWORK_USB != pstDevice->m_eNetwork)
	{
		return FALSE;
	}

	INFO_CONNECT_USB* pstUSB = (INFO_CONNECT_USB*)pstDevice;

	const INFO_USBDEV* pstDevModule = m_USB.GetDeviceModuleInfo(nIdx);
	if (NULL == pstDevModule)
		return FALSE;

	// Get Sensor Type...
	pstUSB->m_dwSensorType = pstDevModule->SensorType;
	pstUSB->m_stArg.m_eNetwork = TYPE_NETWORK_USB;
	pstUSB->m_stArg.m_dwArg = pstDevModule->m_stUsbDevInfo.Index;
	CUtil::StringFormat(pstUSB->m_stArg.m_szArg, MAX_NAME_LEN, _T("%s (%d)"), pstDevModule->m_stUsbDevInfo.szModelName, pstDevModule->m_stUsbDevInfo.Index);

	CUtil::StringCopy(pstUSB->m_szName, pstDevModule->m_stUsbDevInfo.szModelName);
	pstUSB->m_szIndex = pstDevModule->m_stUsbDevInfo.Index;
	CUtil::StringCopy(pstUSB->m_szSerialNumber, pstDevModule->m_stUsbDevInfo.szSerialNumber);

	

	return TRUE;
}

BOOL CConnectUSB::UpdateDeviceInfo(int nIdx, INFO_CONNECT_DEV* pstDevice)
{
	BOOL bResult = TRUE;
	return bResult;
}

BOOL CConnectUSB::ResearchDeviceInfo()
{
	BOOL bResult = FALSE;

	bResult = m_USB.FindAllDevice();
	if (bResult)
	{
		// For updating "Unknown Device"
		const int nCount = m_USB.GetEnableDeviceCount();
		if (0 < nCount)
		{
			for (int i = 0; i < min(nCount, 2); i++)
			{
				CUtil::WaitnSleep(100);
				m_USB.FindAllDevice();
			}
		}
		m_nTempCount = nCount;
	}
	return bResult;
}


BOOL CConnectUSB::GetFrameInfo(const int nIdx, INFO_FRAME* pstFrame)
{
	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx || NULL == pstFrame)
		return FALSE;

	m_USB.GetMaxWidth(nIdx, &pstFrame->m_dwMaxWidth);
	m_USB.GetMaxHeight(nIdx, &pstFrame->m_dwMaxHeight);

	DWORD dwPixelFormat = 0;
	m_USB.GetX(nIdx, &pstFrame->m_dwX);
	m_USB.GetY(nIdx, &pstFrame->m_dwY);
	m_USB.GetWidth(nIdx, &pstFrame->m_dwWidth);
	m_USB.GetHeight(nIdx, &pstFrame->m_dwHeight);

	m_USB.GetPixelFormat(nIdx, &dwPixelFormat);
	m_USB.GetColorFormat(nIdx, (DWORD*)&pstFrame->m_eColorFormat);


	if (GVSP_PIX_MONO & dwPixelFormat)
		pstFrame->m_eColor = TYPE_CAMCOLOR_MONO;
	else if (GVSP_PIX_COLOR & dwPixelFormat)			
		pstFrame->m_eColor = TYPE_CAMCOLOR_COLOR;
	else 
		return FALSE;

	unsigned short nDataBit = 0;
	m_USB.GetDataBit(nIdx, &nDataBit);

	if (8 == nDataBit)
		pstFrame->m_eDataBit = TYPE_DATABIT_08;
	else if (10 == nDataBit)
		pstFrame->m_eDataBit = TYPE_DATABIT_10;
	else if (12 == nDataBit)
		pstFrame->m_eDataBit = TYPE_DATABIT_12;
	else 
		return FALSE;

	pstFrame->m_dwMaxPitch = (DWORD)(pstFrame->m_dwMaxWidth * nDataBit / 8.0f);
	pstFrame->m_dwPitch = (DWORD)(pstFrame->m_dwWidth * nDataBit / 8.0f);

	return TRUE;
}

BOOL CConnectUSB::SetEventFunc(const int nIdx, FuncAcquisitionEvent pFunc, void* pUserData)
{
	BOOL bResult = FALSE;
	
	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx || NULL == pFunc)
		return FALSE;

	m_ArgList[nIdx].m_FuncAcq = pFunc;
	m_ArgList[nIdx].m_pUserData = pUserData;

	bResult = m_USB.SetEventCallbackImageAcquisition(nIdx, AcquisitionEventHandler, &(m_ArgList[nIdx]));
	return bResult;
}

BOOL CConnectUSB::Start(const int nIdx, BOOL bSingle)
{
	BOOL bResult = FALSE;

	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	bResult = m_USB.Start(nIdx, bSingle);
	return bResult;
}

void CConnectUSB::Stop(const int nIdx)
{
	BOOL bResult = FALSE;

	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return;

	m_USB.Stop(nIdx);

}

BOOL CConnectUSB::IsOpen(const int nIdx)
{
	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	return TRUE;
}

BOOL CConnectUSB::Open(const int nIdx)
{
	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	return TRUE;
}

void CConnectUSB::Close(const int nIdx)
{
	Stop(nIdx);
}


BOOL CConnectUSB::SetRegister(const int nIdx, const DWORD dwAddress, const DWORD dwValue, DWORD dwReserved)
{
	BOOL bResult = FALSE;
	if (0x300C == dwAddress)
	{
		bResult = m_USB.WriteRegAddress(nIdx, REG_UCAM_SPI, dwAddress, dwValue);
	}
	return bResult;
}

BOOL CConnectUSB::GetRegister(const int nIdx, const DWORD dwAddress, DWORD* pdwValue, DWORD dwReserved)
{
	BOOL bResult = FALSE;
	if (0x300C == dwAddress)
	{
		bResult = m_USB.ReadRegAddress(nIdx, REG_UCAM_SPI, dwAddress, pdwValue);
	}
	return bResult;
}

BOOL CConnectUSB::SetGain(const int nIdx, const int nGainType, const int nGainValue)
{
	BOOL bResult = FALSE;

	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	bResult = m_USB.SetGain(nIdx, nGainType, nGainValue);
	return bResult;
}

BOOL CConnectUSB::GetGain(const int nIdx, const int nGainType, int* nGainValue)
{
	BOOL bResult = FALSE;

	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	bResult = m_USB.GetGain(nIdx, nGainType, (int*)nGainValue);
	return bResult;
}


BOOL CConnectUSB::SetEnableFrameRate(const int nIdx, const unsigned int nEnale)
{
	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = TRUE;
	return bResult;
}
BOOL CConnectUSB::GetEnableFrameRate(const int nIdx, unsigned int* pnEnale)
{
	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = TRUE;
	return bResult;
}

BOOL CConnectUSB::SetFrameRate(const int nIdx, const unsigned int nFrameRate)
{
	BOOL bResult = FALSE;

	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	bResult = m_USB.SetFrameRate(nIdx, (unsigned int)nFrameRate);
	return bResult;
}

BOOL CConnectUSB::GetFrameRate(const int nIdx, unsigned int* nFrameRate)
{
	BOOL bResult = FALSE;

	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	bResult = m_USB.GetFrameRate(nIdx, (unsigned int*)nFrameRate);
	return bResult;
}

BOOL CConnectUSB::GetMaxFrameRate(const int nIdx, unsigned int* pnFrameRate)
{
	BOOL bResult = FALSE;

	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	return bResult;
}

BOOL CConnectUSB::SetExposureTime(const int nIdx, const unsigned int nExposureTime)
{
	BOOL bResult = FALSE;

	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	bResult = m_USB.SetExposureTime(nIdx, (unsigned int)nExposureTime);
	return bResult;
}

BOOL CConnectUSB::GetExposureTime(const int nIdx, unsigned int* nExposureTime)
{
	BOOL bResult = FALSE;

	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	bResult = m_USB.GetExposureTime(nIdx, (unsigned int*)nExposureTime);
	return bResult;
}

BOOL CConnectUSB::GetExposureMaxTime(const int nIdx, unsigned int FrameRate, unsigned int* nExposureTime)
{
	BOOL bResult = FALSE;

	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	bResult = m_USB.GetExposureMaxTime(nIdx,  FrameRate,  (unsigned int*)nExposureTime);
	return bResult;

}

BOOL CConnectUSB::ConvertExposureTime(const int nIdx, unsigned int nStep, double* pfUSec)
{
	BOOL bResult = FALSE;

	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;
	
	bResult = m_USB.ConvertExposureTime(nIdx, nStep, pfUSec);
	return bResult;
}


BOOL CConnectUSB::SetDataBit(const int nIdx, unsigned short nDataBit)
{
	BOOL bResult = FALSE;

	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	bResult = m_USB.SetDataBit(nIdx, nDataBit);
	return bResult;
}

BOOL CConnectUSB::GetDataBit(const int nIdx, unsigned short* pnDataBit)
{
	BOOL bResult = FALSE;

	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	bResult = m_USB.GetDataBit(nIdx, pnDataBit);
	return bResult;
}

BOOL CConnectUSB::SetColorMode(const int nIdx, unsigned short nColorMode)
{
	BOOL bResult = FALSE;

	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	bResult = m_USB.SetColorMode(nIdx, nColorMode);
	return bResult;
}

BOOL CConnectUSB::GetColorMode(const int nIdx, unsigned short* pnColorMode)
{
	BOOL bResult = FALSE;

	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	bResult = m_USB.GetColorMode(nIdx, pnColorMode);
	return bResult;
}

BOOL CConnectUSB::SetMTU(const int nIdx, unsigned int nMTU)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectUSB::GetMTU(const int nIdx, unsigned int* pnMTU)
{
	BOOL bResult = FALSE;
	return bResult;
}


BOOL CConnectUSB::GetDiag(const int nIdx, void* pstDiag, const int nLen)
{
	BOOL bResult = FALSE;

	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	bResult = m_USB.GetDiag(nIdx, (INFO_DIAGONOSTICS_USB*)pstDiag);

	return bResult;
}

BOOL CConnectUSB::SetTriggerMode(const int nIdx, INFO_TRIGGER_PARA stTrigger)
{
	BOOL bResult = FALSE;

	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	bResult = m_USB.SetTriggerMode(nIdx, stTrigger);	
	return bResult;
}


BOOL CConnectUSB::GetTriggerMode(const int nIdx, INFO_TRIGGER_PARA* stTrigger)
{
	BOOL bResult = FALSE;

	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	bResult = m_USB.GetTriggerMode(nIdx, stTrigger);
	return bResult;
}

BOOL CConnectUSB::SetTriggerDelay(const int nIdx, int nDelay)
{
	BOOL bResult = FALSE;

	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	bResult = m_USB.SetTriggerDelay(nIdx, nDelay);
	return bResult;
}

BOOL CConnectUSB::SetSWTrigger(const int nIdx)
{
	BOOL bResult = FALSE;

	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	bResult = m_USB.SetSWTrigger(nIdx);
	return bResult;
}

BOOL CConnectUSB::SaveUserset(const int nIdx, unsigned int nNumber)
{
	BOOL bResult = FALSE;

	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	bResult = m_USB.SaveUserset(nIdx, nNumber);
	return bResult;
}

BOOL CConnectUSB::LoadUserset(const int nIdx, unsigned int nNumber)
{
	BOOL bResult = FALSE;

	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	bResult = m_USB.LoadUserset(nIdx, nNumber);
	return bResult;
}


BOOL CConnectUSB::SetStrobeMode(const int nIdx, INFO_STROBE_PARA stStrobe)
{
	BOOL bResult = FALSE;

	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	bResult = m_USB.SetStrobeMode(nIdx, stStrobe);
	return bResult;
}

BOOL CConnectUSB::GetStrobeMode(const int nIdx, INFO_STROBE_PARA* stStrobe)
{
	BOOL bResult = FALSE;

	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	bResult = m_USB.GetStrobeMode(nIdx, stStrobe);
	return bResult;
}

BOOL CConnectUSB::SetFlipMode(const int nIdx, unsigned short nMode)
{
	BOOL bResult = FALSE;

	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	bResult = m_USB.SetFlipMode(nIdx, nMode);
	return bResult;
}

BOOL CConnectUSB::GetFlipMode(const int nIdx, unsigned short* nMode)
{
	BOOL bResult = FALSE;

	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	bResult = m_USB.GetFlipMode(nIdx, nMode);
	return bResult;
}

BOOL CConnectUSB::SetROI(const int nIdx, INFO_ROI_PARA stROI)
{
	BOOL bResult = FALSE;

	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	bResult = m_USB.SetRoi(nIdx, stROI.nXstart, stROI.nYstart, stROI.nWidth, stROI.nHeight);
	return bResult;
}

BOOL CConnectUSB::GetROI(const int nIdx, INFO_ROI_PARA* stROI)
{
	DWORD dwData;

	const int nCount = m_USB.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	m_USB.GetX(nIdx, &dwData);
	stROI->nXstart = dwData;

	m_USB.GetY(nIdx, &dwData);
	stROI->nYstart = dwData;

	m_USB.GetWidth(nIdx, &dwData);
	stROI->nWidth = dwData;

	m_USB.GetHeight(nIdx, &dwData);
	stROI->nHeight = dwData;

	m_USB.GetMaxWidth(nIdx, &dwData);
	stROI->nMaxWidth = dwData;

	m_USB.GetMaxHeight(nIdx, &dwData);
	stROI->nMaxHeight = dwData;

	return TRUE;
}

BOOL CConnectUSB::SetUsersetStartNo(const int nIdx, unsigned char nUsersetStartNo)
{
	BOOL bResult = m_USB.SetUsersetStartNo(nIdx, nUsersetStartNo);
	return bResult;
}

BOOL CConnectUSB::GetUsersetStartNo(const int nIdx, unsigned char* nUsersetStartNo)
{
	BOOL bResult = m_USB.GetUsersetStartNo(nIdx, nUsersetStartNo);
	return bResult;
}

// LUT
BOOL CConnectUSB::SetLutMode(const int nIdx, unsigned short nMode)
{
	BOOL bResult = m_USB.SetLutMode(nIdx, nMode);
	return bResult;
}
BOOL CConnectUSB::GetLutMode(const int nIdx, unsigned short* pnMode)
{
	BOOL bResult = m_USB.GetLutMode(nIdx, pnMode);
	return bResult;
}

BOOL CConnectUSB::WriteLut(const int nIdx, const INFO_LUT_PARA* pLutList, const int nLen, BOOL bEeprom)
{
	BOOL bResult = m_USB.WriteLut(nIdx, pLutList, nLen, bEeprom);
	return bResult;
}


// Effect
BOOL CConnectUSB::SetEffectNR(const int nIdx, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectUSB::GetEffectNR(const int nIdx, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectUSB::SetEffectGC(const int nIdx, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectUSB::GetEffectGC(const int nIdx, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectUSB::SetEffectCM(const int nIdx, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectUSB::GetEffectCM(const int nIdx, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectUSB::SetEffectAWB(const int nIdx, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectUSB::GetEffectAWB(const int nIdx, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectUSB::SetEffectSmooth(const int nIdx, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectUSB::GetEffectSmooth(const int nIdx, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectUSB::SetEffectSharpen(const int nIdx, unsigned short nEffect)
{
	BOOL bResult = m_USB.SetEffectSharpen(nIdx, nEffect);
	return bResult;
}
BOOL CConnectUSB::GetEffectSharpen(const int nIdx, unsigned short* pnEffect)
{
	BOOL bResult = m_USB.GetEffectSharpen(nIdx, pnEffect);
	return bResult;
}

BOOL CConnectUSB::SetEffectFPN(const int nIdx, unsigned short nEffect)
{
	BOOL bResult = m_USB.SetEffectFPN(nIdx, nEffect);
	return bResult;
}
BOOL CConnectUSB::GetEffectFPN(const int nIdx, unsigned short* pnEffect)
{
	BOOL bResult = m_USB.GetEffectFPN(nIdx, pnEffect);
	return bResult;
}

BOOL CConnectUSB::SetEffectPRNU(const int nIdx, unsigned short nEffect)
{
	BOOL bResult = m_USB.SetEffectPRNU(nIdx, nEffect);
	return bResult;
}
BOOL CConnectUSB::GetEffectPRNU(const int nIdx, unsigned short* pnEffect)
{
	BOOL bResult = m_USB.GetEffectPRNU(nIdx, pnEffect);
	return bResult;
}

BOOL CConnectUSB::SetEffectDPC(const int nIdx, unsigned short nEffect)
{
	BOOL bResult = m_USB.SetEffectDPC(nIdx, nEffect);
	return bResult;
}
BOOL CConnectUSB::GetEffectDPC(const int nIdx, unsigned short* pnEffect)
{
	BOOL bResult = m_USB.GetEffectDPC(nIdx, pnEffect);
	return bResult;
}

BOOL CConnectUSB::SetColorGain(const int nIdx, const int nGainType, int nGainVal)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectUSB::GetColorGain(const int nIdx, const int nGainType, int* pnGainVal)
{
	BOOL bResult = FALSE;
	return bResult;
}