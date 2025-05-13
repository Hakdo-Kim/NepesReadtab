#include "StdAfx.h"
#include "ConnectEthernet.h"

#include "Util/Util.h"

CConnectEthernet::CConnectEthernet()
{
	;
}

CConnectEthernet::~CConnectEthernet()
{
	;
}

BOOL CConnectEthernet::IsConnected()
{
	BOOL bResult = m_EthernetCtrl.IsOpen();
	return bResult;
}

BOOL CConnectEthernet::Open(TYPE_NETWORK eNetwork)
{
	BOOL bResult = Open(eNetwork, NULL);
	return bResult;
}

BOOL CConnectEthernet::Open(TYPE_NETWORK eNetwork, void* pReserved)
{
	if(TYPE_NETWORK_ETHERNET != eNetwork)
		return FALSE;

	BOOL bResult = m_EthernetCtrl.Open();
	return bResult;
}


void CConnectEthernet::Close()
{
	m_EthernetCtrl.Close();
}

int CConnectEthernet::GetDeviceCount()
{
	int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	return nCount;
}

int CConnectEthernet::GetDeviceIndex(const INFO_CONNECT_DEV* pDev)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	int nIdx = -1;

	if(1>nCount || nCount <= nIdx || NULL==pDev )
		return nIdx;

	for(int i=0; i<nCount; i++)
	{
		const INFO_CLIENT* pClient = m_EthernetCtrl.GetDeviceModuleInfo(i);

		if(pClient->m_dwIpAddress == pDev->m_dwArg)
		{
			nIdx = i;
			break;
		}
	}

	return nIdx;
}

int CConnectEthernet::GetDeviceID(const TCHAR* pName)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	int nIdx = -1;

	if (1>nCount || nCount <= nIdx || NULL == pName)
		return nIdx;

	return nIdx;
}


BOOL CConnectEthernet::GetDeviceInfo(int nIdx, INFO_CONNECT_DEV* pstDevice)
{
	if(NULL==pstDevice || TYPE_NETWORK_ETHERNET!=pstDevice->m_eNetwork) 
		return FALSE;

	BOOL bResult = m_EthernetCtrl.GetEnableDeviceInfo(nIdx, (INFO_CONNECT_ETHERNET*) pstDevice);
	return bResult;
}


BOOL CConnectEthernet::UpdateDeviceInfo(int nIdx, INFO_CONNECT_DEV* pstDevice)
{
	if (NULL == pstDevice || TYPE_NETWORK_ETHERNET != pstDevice->m_eNetwork)
		return FALSE;



	return FALSE;
}


BOOL CConnectEthernet::ResearchDeviceInfo()
{
	BOOL bResult = m_EthernetCtrl.FindAllDevice();
	return bResult;
}


// Device Information
BOOL CConnectEthernet::GetFrameInfo(const int nIdx, INFO_FRAME* pstFrame)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if(1>nCount || nCount <= nIdx || NULL==pstFrame )
		return FALSE;

	m_EthernetCtrl.GetMaxWidth( nIdx, &pstFrame->m_dwMaxWidth);
	m_EthernetCtrl.GetMaxHeight( nIdx, &pstFrame->m_dwMaxHeight);


	DWORD dwPixelFormat	= 0;
	m_EthernetCtrl.GetWidth( nIdx, &pstFrame->m_dwWidth);
	m_EthernetCtrl.GetHeight( nIdx, &pstFrame->m_dwHeight);
	m_EthernetCtrl.GetPixelFormat( nIdx, &dwPixelFormat);

	if( TYPE_DATABIT_08 == (TYPE_DATABIT)dwPixelFormat ||
		TYPE_DATABIT_12 == (TYPE_DATABIT)dwPixelFormat ||
		TYPE_DATABIT_16 == (TYPE_DATABIT)dwPixelFormat ||
		TYPE_DATABIT_24 == (TYPE_DATABIT)dwPixelFormat ||
		TYPE_DATABIT_32 == (TYPE_DATABIT)dwPixelFormat ||
		TYPE_DATABIT_36 == (TYPE_DATABIT)dwPixelFormat ||
		TYPE_DATABIT_48 == (TYPE_DATABIT)dwPixelFormat  )
	{
		pstFrame->m_eDataBit = (TYPE_DATABIT)dwPixelFormat;
	}
	else
	{
		return FALSE;
	}

	BYTE  nBit = 8;
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

BOOL CConnectEthernet::SetEventFunc(const int nIdx, FuncAcquisitionEvent pFunc, void* pUserData)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::Start(const int nIdx, BOOL bSingle)
{
	BOOL bResult = FALSE;
	return bResult;
}

void CConnectEthernet::Stop(const int nIdx)
{
}

BOOL CConnectEthernet::IsOpen(const int nIdx)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::Open(const int nIdx)
{
	BOOL bResult = FALSE;
	return bResult;
}

void CConnectEthernet::Close(const int nIdx)
{
}

BOOL CConnectEthernet::SetRegister(const int nIdx, const DWORD dwAddress, const DWORD dwValue, DWORD dwReserved)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if(1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::GetRegister(const int nIdx, const DWORD dwAddress, DWORD* pdwValue, DWORD dwReserved)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if(1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

/*//
BOOL CConnectEthernet::SetRoi(const int nIdx, const int nX, const int nY, const int nW, const int nH)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if(1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}
//*/


//
BOOL CConnectEthernet::SetGain(const int nIdx, const int nGainType, const int nGainValue)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEthernet::GetGain(const int nIdx, const int nGainType, int* pnGainValue)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::SetEnableFrameRate(const int nIdx, const unsigned int nEnale)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEthernet::GetEnableFrameRate(const int nIdx, unsigned int* pnEnale)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::SetFrameRate(const int nIdx, const unsigned int nFrameRate)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEthernet::GetFrameRate(const int nIdx, unsigned int* pnFrameRate)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEthernet::GetMaxFrameRate(const int nIdx, unsigned int* pnFrameRate)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::SetExposureTime(const int nIdx, const unsigned int nSetExposureTime)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEthernet::GetExposureTime(const int nIdx, unsigned int* pnSetExposureTime)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::GetExposureMaxTime(const int nIdx, unsigned int FrameRate, unsigned int* pnSetExposureTime)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::ConvertExposureTime(const int nIdx, unsigned int nStep, double* pfUSec)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::SetTriggerMode(const int nIdx, INFO_TRIGGER_PARA stTrigger)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEthernet::GetTriggerMode(const int nIdx, INFO_TRIGGER_PARA* pstTrigger)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::SetTriggerDelay(const int nIdx, int nDelay)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::SaveUserset(const int nIdx, unsigned int nNumber)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEthernet::LoadUserset(const int nIdx, unsigned int nNumber)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::SetStrobeMode(const int nIdx, INFO_STROBE_PARA stStrobe)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEthernet::GetStrobeMode(const int nIdx, INFO_STROBE_PARA* pstStrobe)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::SetFlipMode(const int nIdx, unsigned short nMode)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEthernet::GetFlipMode(const int nIdx, unsigned short* pnMode)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::SetROI(const int nIdx, INFO_ROI_PARA stROI)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEthernet::GetROI(const int nIdx, INFO_ROI_PARA* pstROI)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::SetUsersetStartNo(const int nIdx, unsigned char nUsersetStartNo)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEthernet::GetUsersetStartNo(const int nIdx, unsigned char* pnUsersetStartNo)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::SetDataBit(const int nIdx, unsigned short nDataBit)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::GetDataBit(const int nIdx, unsigned short* pnDataBit)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}


BOOL CConnectEthernet::SetColorMode(const int nIdx, unsigned short nColorMode)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::GetColorMode(const int nIdx, unsigned short* pnColorMode)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}


BOOL CConnectEthernet::SetMTU(const int nIdx, unsigned int nMTU)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::GetMTU(const int nIdx, unsigned int* pnMTU)
{
	BOOL bResult = FALSE;
	return bResult;
}


BOOL CConnectEthernet::GetDiag(const int nIdx, void* pstDiag, const int nLen)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::SetSWTrigger(const int nIdx)
{
	const int nCount = m_EthernetCtrl.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}



// LUT
BOOL CConnectEthernet::SetLutMode(const int nIdx, unsigned short nMode)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEthernet::GetLutMode(const int nIdx, unsigned short* pnMode)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::WriteLut(const int nIdx, const INFO_LUT_PARA* pLutList, const int nLen, BOOL bEeprom)
{
	BOOL bResult = FALSE;
	return bResult;
}

// Effect
BOOL CConnectEthernet::SetEffectNR(const int nIdx, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEthernet::GetEffectNR(const int nIdx, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::SetEffectGC(const int nIdx, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEthernet::GetEffectGC(const int nIdx, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::SetEffectCM(const int nIdx, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEthernet::GetEffectCM(const int nIdx, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::SetEffectAWB(const int nIdx, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEthernet::GetEffectAWB(const int nIdx, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::SetEffectSmooth(const int nIdx, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEthernet::GetEffectSmooth(const int nIdx, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::SetEffectSharpen(const int nIdx, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEthernet::GetEffectSharpen(const int nIdx, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::SetEffectFPN(const int nIdx, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEthernet::GetEffectFPN(const int nIdx, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::SetEffectPRNU(const int nIdx, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEthernet::GetEffectPRNU(const int nIdx, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::SetEffectDPC(const int nIdx, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEthernet::GetEffectDPC(const int nIdx, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectEthernet::SetColorGain(const int nIdx, const int nGainType, int nGainVal)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectEthernet::GetColorGain(const int nIdx, const int nGainType, int* pnGainVal)
{
	BOOL bResult = FALSE;
	return bResult;
}