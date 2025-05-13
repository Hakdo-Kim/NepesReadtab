#include "StdAfx.h"
#include "ConnectBasler.h"

#include "Util/Util.h"
#include "inc/PixelFormat.h"

#ifdef ENABLE_CAMERA_LIBRARY_BASLER
CConnectBasler::CConnectBasler()
{
	;
}

CConnectBasler::~CConnectBasler()
{
	Close();
}

void CConnectBasler::AcquisitionEventHandler(unsigned char* pBuffer, unsigned int nSize, void* lpArg)
{
	;
}

BOOL CConnectBasler::IsConnected()
{
	BOOL bConnect = FALSE;

	const TYPE_NETWORK eNetwork = GetNetworkType();
	if (TYPE_NETWORK_BASLER == eNetwork && m_LibBasler.IsOpen())
		bConnect = TRUE;

	return bConnect;
}

BOOL CConnectBasler::Open(TYPE_NETWORK eNetwork)
{
	BOOL bResult = Open(eNetwork, NULL);
	return bResult;
}
BOOL CConnectBasler::Open(TYPE_NETWORK eNetwork, void* pReserved)
{
	if (TYPE_NETWORK_BASLER != eNetwork)
		return FALSE;
	BOOL bResult = m_LibBasler.Open();
	if (FALSE == bResult)
	{
		Close();
		return FALSE;
	}

	m_eNetwork = TYPE_NETWORK_BASLER;

	return TRUE;
}
void CConnectBasler::Close()
{
	m_LibBasler.Close();
	m_eNetwork = TYPE_NETWORK_NONE;

}

int CConnectBasler::GetDeviceCount()
{
	return m_LibBasler.GetEnableDeviceCount();
}
int CConnectBasler::GetDeviceIndex(const INFO_CONNECT_DEV* pDev)
{
	const int nCount = m_LibBasler.GetEnableDeviceCount();
	int nIdx = -1;

	if (1>nCount || nCount <= nIdx || NULL == pDev)
		return nIdx;

	const INFO_CONNECT_OTHER_MANUFACTURER* pManufacture = (INFO_CONNECT_OTHER_MANUFACTURER*)pDev;

//	if (TYPE_NETWORK_GIGE == pManufacture->m_eCameraType)
	if (TYPE_NETWORK_BASLER == pManufacture->m_eCameraType)
	{
		for (int i = 0; i < nCount; i++)
		{
			const DWORD dwIpAddr = m_LibBasler.GetIpAddress(i);
			if (dwIpAddr == pDev->m_dwArg)
			{
				nIdx = i;
				break;
			}
		}
	}
	else if (TYPE_NETWORK_USB == pManufacture->m_eCameraType)
	{
		nIdx = pDev->m_dwArg;
	}

	return nIdx;
}
int CConnectBasler::GetDeviceID(const TCHAR* pName)
{
	const int nCount = m_LibBasler.GetEnableDeviceCount();
	int nIdx = -1;
	if (1>nCount || nCount <= nIdx || NULL == pName)
		return nIdx;

	INFO_CONNECT_OTHER_MANUFACTURER stBasler;
	memset(&stBasler, 0x00, sizeof(INFO_CONNECT_OTHER_MANUFACTURER));
	stBasler.m_stArg.m_eNetwork = TYPE_NETWORK_BASLER;

	BOOL bResult = FALSE;

	for (int i = 0; i < nCount; i++)
	{
		bResult = GetDeviceInfo(i, (INFO_CONNECT_DEV*)&stBasler);
		if (bResult  && CUtil::StringCompare((TCHAR*)pName, stBasler.m_stArg.m_szArg))
		{
			nIdx = i;
			break;
		}
	}
	return nIdx;
}
BOOL CConnectBasler::GetDeviceInfo(int nIdx, INFO_CONNECT_DEV* pstDevice)
{
	const int nCount = m_LibBasler.GetEnableDeviceCount();
	if (1 > nCount || nCount <= nIdx ||
		NULL == pstDevice || TYPE_NETWORK_BASLER != pstDevice->m_eNetwork)
	{
		return FALSE;
	}

	INFO_CONNECT_OTHER_MANUFACTURER* pstBasler = (INFO_CONNECT_OTHER_MANUFACTURER*)pstDevice;

	TCHAR pszManufacturer[MAX_NAME_LEN] = { 0, };
	TCHAR pszModel[MAX_NAME_LEN] = { 0, };

	m_LibBasler.GetVendor(nIdx, pszManufacturer);
	m_LibBasler.GetModel(nIdx, pszModel);

	if (m_LibBasler.IsGigE(nIdx))
	{
		DWORD dwIpAddr = m_LibBasler.GetIpAddress(nIdx);
		pstBasler->m_stArg.m_dwArg = dwIpAddr;
		CUtil::StringFormat(pstBasler->m_stArg.m_szArg, MAX_NAME_LEN, _T("%s (%d.%d.%d.%d)"),
			pszModel,
			(dwIpAddr & 0xFF000000) >> 24,
			(dwIpAddr & 0x00FF0000) >> 16,
			(dwIpAddr & 0x0000FF00) >> 8,
			(dwIpAddr & 0x000000FF));

		//pstBasler->m_eCameraType = TYPE_NETWORK_GIGE;
		pstBasler->m_eCameraType = TYPE_NETWORK_BASLER;
	}
	else if (m_LibBasler.IsUsb(nIdx))
	{
		pstBasler->m_stArg.m_dwArg = nIdx;
		CUtil::StringFormat(pstBasler->m_stArg.m_szArg, MAX_NAME_LEN, _T("%s (%d)"), pszModel, nIdx);

		pstBasler->m_eCameraType = TYPE_NETWORK_USB;
	}
	else
	{
		return FALSE;
	}
	

	CUtil::StringCopy(pstBasler->m_szManufacturer, (LPTSTR)pszManufacturer);
	CUtil::StringCopy(pstBasler->m_szName, (LPTSTR)pszModel);


	return TRUE;
}
BOOL CConnectBasler::UpdateDeviceInfo(int nIdx, INFO_CONNECT_DEV* pstDevice)
{
	return FALSE;
}

BOOL CConnectBasler::ResearchDeviceInfo()
{
	EnterCriticalSection();

	BOOL bResult = m_LibBasler.FindAllDevice();
	CUtil::Sleep(10);

	LeaveCriticalSection();

	return TRUE;
}


// Device Information
BOOL CConnectBasler::GetFrameInfo(const int nIdx, INFO_FRAME* pstFrame)
{
	const int nCount = m_LibBasler.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx || NULL == pstFrame)
	{
		return FALSE;
	}

	DWORD dwPixelFormat = 0;
	m_LibBasler.GetMaxWidth(nIdx, &pstFrame->m_dwMaxWidth);
	m_LibBasler.GetMaxHeight(nIdx, &pstFrame->m_dwMaxHeight);

	m_LibBasler.GetX(nIdx, &pstFrame->m_dwX);
	m_LibBasler.GetY(nIdx, &pstFrame->m_dwY);
	m_LibBasler.GetWidth(nIdx, &pstFrame->m_dwWidth);
	m_LibBasler.GetHeight(nIdx, &pstFrame->m_dwHeight);
	m_LibBasler.GetPixelFormat(nIdx, &dwPixelFormat);
	
	if (GVSP_PIX_MONO & dwPixelFormat)					pstFrame->m_eColor = TYPE_CAMCOLOR_MONO;
	else if (GVSP_PIX_COLOR & dwPixelFormat)			pstFrame->m_eColor = TYPE_CAMCOLOR_COLOR;
	else return FALSE;

	DWORD dwBit = ((dwPixelFormat >> 16) & 0xFF) << 16;
	if (GVSP_PIX_OCCUPY8BIT == dwBit)				pstFrame->m_eDataBit = TYPE_DATABIT_08;
	else if (GVSP_PIX_OCCUPY12BIT == dwBit)		pstFrame->m_eDataBit = TYPE_DATABIT_12;
	else if (GVSP_PIX_OCCUPY16BIT == dwBit)		pstFrame->m_eDataBit = TYPE_DATABIT_16;
	else if (GVSP_PIX_OCCUPY24BIT == dwBit)		pstFrame->m_eDataBit = TYPE_DATABIT_24;
	else if (GVSP_PIX_OCCUPY32BIT == dwBit)		pstFrame->m_eDataBit = TYPE_DATABIT_32;
	else if (GVSP_PIX_OCCUPY36BIT == dwBit)		pstFrame->m_eDataBit = TYPE_DATABIT_36;
	else if (GVSP_PIX_OCCUPY48BIT == dwBit)		pstFrame->m_eDataBit = TYPE_DATABIT_48;
	else return FALSE;

	pstFrame->m_eColorBit = pstFrame->m_eDataBit;

	if (TYPE_DATABIT_08 == pstFrame->m_eDataBit)
	{
		if (GVSP_PIX_BAYERGR8 == dwPixelFormat)
		{
			pstFrame->m_eColorFormat = TYPE_CAMCOLORFORMAT_BAYER_GR;
			pstFrame->m_eColor = TYPE_CAMCOLOR_COLOR;
		}
		else if (GVSP_PIX_BAYERRG8 == dwPixelFormat)
		{
			pstFrame->m_eColorFormat = TYPE_CAMCOLORFORMAT_BAYER_RG;
			pstFrame->m_eColor = TYPE_CAMCOLOR_COLOR;
		}
		else if (GVSP_PIX_BAYERGB8 == dwPixelFormat)
		{
			pstFrame->m_eColorFormat = TYPE_CAMCOLORFORMAT_BAYER_GB;
			pstFrame->m_eColor = TYPE_CAMCOLOR_COLOR;
		}
		else if (GVSP_PIX_BAYERBG8 == dwPixelFormat)
		{
			pstFrame->m_eColorFormat = TYPE_CAMCOLORFORMAT_BAYER_BG;
			pstFrame->m_eColor = TYPE_CAMCOLOR_COLOR;
		}
		else
		{
			pstFrame->m_eColorFormat = TYPE_CAMCOLORFORMAT_MONO;
			pstFrame->m_eColor = TYPE_CAMCOLOR_MONO;
		}
	}
	else if (TYPE_DATABIT_12 == pstFrame->m_eDataBit)
	{
		// 10
		if (GVSP_PIX_BAYERGR10_PACKED == dwPixelFormat)
		{
			pstFrame->m_eColorFormat = TYPE_CAMCOLORFORMAT_BAYER_GR;
			pstFrame->m_eColor = TYPE_CAMCOLOR_COLOR;
			pstFrame->m_eColorBit = TYPE_DATABIT_10;
		}
		else if (GVSP_PIX_BAYERRG10_PACKED == dwPixelFormat)
		{
			pstFrame->m_eColorFormat = TYPE_CAMCOLORFORMAT_BAYER_RG;
			pstFrame->m_eColor = TYPE_CAMCOLOR_COLOR;
			pstFrame->m_eColorBit = TYPE_DATABIT_10;
		}
		else if (GVSP_PIX_BAYERGB10_PACKED == dwPixelFormat)
		{
			pstFrame->m_eColorFormat = TYPE_CAMCOLORFORMAT_BAYER_GB;
			pstFrame->m_eColor = TYPE_CAMCOLOR_COLOR;
			pstFrame->m_eColorBit = TYPE_DATABIT_10;
		}
		else if (GVSP_PIX_BAYERBG10_PACKED == dwPixelFormat)
		{
			pstFrame->m_eColorFormat = TYPE_CAMCOLORFORMAT_BAYER_BG;
			pstFrame->m_eColor = TYPE_CAMCOLOR_COLOR;
			pstFrame->m_eColorBit = TYPE_DATABIT_10;
		}
		else if (GVSP_PIX_MONO10_PACKED == dwPixelFormat)
		{
			pstFrame->m_eColorFormat = TYPE_CAMCOLORFORMAT_MONO;
			pstFrame->m_eColor = TYPE_CAMCOLOR_MONO;
			pstFrame->m_eColorBit = TYPE_DATABIT_10;
		}
		// 12
		else if (GVSP_PIX_BAYERGR12_PACKED == dwPixelFormat)
		{
			pstFrame->m_eColorFormat = TYPE_CAMCOLORFORMAT_BAYER_GR;
			pstFrame->m_eColor = TYPE_CAMCOLOR_COLOR;
		}
		else if (GVSP_PIX_BAYERRG12_PACKED == dwPixelFormat)
		{
			pstFrame->m_eColorFormat = TYPE_CAMCOLORFORMAT_BAYER_RG;
			pstFrame->m_eColor = TYPE_CAMCOLOR_COLOR;
		}
		else if (GVSP_PIX_BAYERGB12_PACKED == dwPixelFormat)
		{
			pstFrame->m_eColorFormat = TYPE_CAMCOLORFORMAT_BAYER_GB;
			pstFrame->m_eColor = TYPE_CAMCOLOR_COLOR;
		}
		else if (GVSP_PIX_BAYERBG12_PACKED == dwPixelFormat)
		{
			pstFrame->m_eColorFormat = TYPE_CAMCOLORFORMAT_BAYER_BG;
			pstFrame->m_eColor = TYPE_CAMCOLOR_COLOR;
		}
		else if (GVSP_PIX_MONO12_PACKED == dwPixelFormat)
		{
			pstFrame->m_eColorFormat = TYPE_CAMCOLORFORMAT_MONO;
			pstFrame->m_eColor = TYPE_CAMCOLOR_MONO;
		}
		else
		{
			pstFrame->m_eColorFormat = TYPE_CAMCOLORFORMAT_MONO;
			pstFrame->m_eColor = TYPE_CAMCOLOR_MONO;
		}
	}

	BYTE nBit = 8;
	if (TYPE_DATABIT_08 == pstFrame->m_eDataBit)	nBit = 8;
	else if (TYPE_DATABIT_12 == pstFrame->m_eDataBit)	nBit = 12;
	else if (TYPE_DATABIT_16 == pstFrame->m_eDataBit)	nBit = 16;
	else if (TYPE_DATABIT_24 == pstFrame->m_eDataBit)	nBit = 24;
	else if (TYPE_DATABIT_32 == pstFrame->m_eDataBit)	nBit = 32;
	else if (TYPE_DATABIT_36 == pstFrame->m_eDataBit)	nBit = 36;
	else if (TYPE_DATABIT_48 == pstFrame->m_eDataBit)	nBit = 48;
	else return FALSE;

	DWORD dwW = max(pstFrame->m_dwMaxWidth, pstFrame->m_dwWidth);
	pstFrame->m_dwMaxPitch = (DWORD)(dwW* nBit / 8.0f);
	pstFrame->m_dwPitch = (DWORD)(pstFrame->m_dwWidth * nBit / 8.0f);

	return TRUE;
}
BOOL CConnectBasler::SetEventFunc(const int nIdx, FuncAcquisitionEvent pFunc, void* pUserData)
{
	const int nCount = m_LibBasler.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx || NULL == pFunc)
	{
		return FALSE;
	}

	BOOL bResult = m_LibBasler.SetEventFunc(nIdx, pFunc, pUserData);
	return bResult;
}

BOOL CConnectBasler::Start(const int nIdx, BOOL bSingle)
{
	BOOL bResult = m_LibBasler.Start(nIdx);
	return bResult;
}
void CConnectBasler::Stop(const int nIdx)
{
	m_LibBasler.Stop(nIdx);
}

BOOL CConnectBasler::IsOpen(const int nIdx)
{
	return FALSE;
}
BOOL CConnectBasler::Open(const int nIdx)
{
	return FALSE;
}
void CConnectBasler::Close(const int nIdx)
{
}


// Command Function
BOOL CConnectBasler::SetRegister(const int nIdx, const DWORD dwAddress, const DWORD dwValue, DWORD dwReserved)
{
	return FALSE;
}
BOOL CConnectBasler::GetRegister(const int nIdx, const DWORD dwAddress, DWORD* pdwValue, DWORD dwReserved)
{
	return FALSE;
}

//
BOOL CConnectBasler::SetGain(const int nIdx, const int nGainType, const int nGainValue)
{
	return FALSE;
}
BOOL CConnectBasler::GetGain(const int nIdx, const int nGainType, int* pnGainValue)
{
	return FALSE;
}

BOOL CConnectBasler::SetEnableFrameRate(const int nIdx, const unsigned int nEnale)
{
	return FALSE;
}
BOOL CConnectBasler::GetEnableFrameRate(const int nIdx, unsigned int* pnEnale)
{
	return FALSE;
}

BOOL CConnectBasler::SetFrameRate(const int nIdx, const unsigned int nFrameRate)
{
	return FALSE;
}
BOOL CConnectBasler::GetFrameRate(const int nIdx, unsigned int* pnFrameRate)
{
	return FALSE;
}
BOOL CConnectBasler::GetMaxFrameRate(const int nIdx, unsigned int* pnFrameRate)
{
	return FALSE;
}

BOOL CConnectBasler::SetExposureTime(const int nIdx, const unsigned int nSetExposureTime)
{
	return FALSE;
}
BOOL CConnectBasler::GetExposureTime(const int nIdx, unsigned int* pnSetExposureTime)
{
	return FALSE;
}
BOOL CConnectBasler::GetExposureMaxTime(const int nIdx, unsigned int FrameRate, unsigned int* pnSetExposureTime)
{
	return FALSE;
}
BOOL CConnectBasler::ConvertExposureTime(const int nIdx, unsigned int nStep, double* pfUSec)
{
	return FALSE;
}

BOOL CConnectBasler::SetTriggerMode(const int nIdx, INFO_TRIGGER_PARA stTrigger)
{
	return FALSE;
}
BOOL CConnectBasler::GetTriggerMode(const int nIdx, INFO_TRIGGER_PARA* pstTrigger)
{
	return FALSE;
}

BOOL CConnectBasler::SetTriggerDelay(const int nIdx, int nDelay)
{
	return FALSE;
}

BOOL CConnectBasler::SaveUserset(const int nIdx, unsigned int nNumber)
{
	return FALSE;
}
BOOL CConnectBasler::LoadUserset(const int nIdx, unsigned int nNumber)
{
	return FALSE;
}

BOOL CConnectBasler::SetStrobeMode(const int nIdx, INFO_STROBE_PARA stStrobe)
{
	return FALSE;
}
BOOL CConnectBasler::GetStrobeMode(const int nIdx, INFO_STROBE_PARA* pstStrobe)
{
	return FALSE;
}

BOOL CConnectBasler::SetFlipMode(const int nIdx, unsigned short nMode)
{
	return FALSE;
}
BOOL CConnectBasler::GetFlipMode(const int nIdx, unsigned short* pnMode)
{
	return FALSE;
}

BOOL CConnectBasler::SetROI(const int nIdx, INFO_ROI_PARA stROI)
{
	return FALSE;
}
BOOL CConnectBasler::GetROI(const int nIdx, INFO_ROI_PARA* pstROI)
{
	return FALSE;
}

BOOL CConnectBasler::SetUsersetStartNo(const int nIdx, unsigned char nUsersetStartNo)
{
	return FALSE;
}
BOOL CConnectBasler::GetUsersetStartNo(const int nIdx, unsigned char* pnUsersetStartNo)
{
	return FALSE;
}

BOOL CConnectBasler::SetDataBit(const int nIdx, unsigned short nDataBit)
{
	return FALSE;
}
BOOL CConnectBasler::GetDataBit(const int nIdx, unsigned short* pnDataBit)
{
	return FALSE;
}

BOOL CConnectBasler::SetColorMode(const int nIdx, unsigned short nColorMode)
{
	return FALSE;
}
BOOL CConnectBasler::GetColorMode(const int nIdx, unsigned short* pnColorMode)
{
	return FALSE;
}

BOOL CConnectBasler::SetColorFormat(const int nIdx, TYPE_CAMCOLORFORMAT eFormat)
{
	return FALSE;
}

BOOL CConnectBasler::GetColorFormat(const int nIdx, TYPE_CAMCOLORFORMAT* peFormat)
{
	return FALSE;
}

BOOL CConnectBasler::SetMTU(const int nIdx, unsigned int nMTU)
{
	return FALSE;
}
BOOL CConnectBasler::GetMTU(const int nIdx, unsigned int* pnMTU)
{
	return FALSE;
}

BOOL CConnectBasler::GetDiag(const int nIdx, void* pstDiag, const int nLen)
{
	return FALSE;
}
BOOL CConnectBasler::SetSWTrigger(const int nIdx)
{
	return FALSE;
}


// LUT
BOOL CConnectBasler::SetLutMode(const int nIdx, unsigned short nMode)
{
	return FALSE;
}
BOOL CConnectBasler::GetLutMode(const int nIdx, unsigned short* pnMode)
{
	return FALSE;
}

BOOL CConnectBasler::WriteLut(const int nIdx, const INFO_LUT_PARA* pLutList, const int nLen, BOOL bEeprom)
{
	return FALSE;
}

// Effect
BOOL CConnectBasler::SetEffectNR(const int nIdx, unsigned short nEffect)
{
	return FALSE;
}
BOOL CConnectBasler::GetEffectNR(const int nIdx, unsigned short* pnEffect)
{
	return FALSE;
}

BOOL CConnectBasler::SetEffectGC(const int nIdx, unsigned short nEffect)
{
	return FALSE;
}
BOOL CConnectBasler::GetEffectGC(const int nIdx, unsigned short* pnEffect)
{
	return FALSE;
}

BOOL CConnectBasler::SetEffectCM(const int nIdx, unsigned short nEffect)
{
	return FALSE;
}
BOOL CConnectBasler::GetEffectCM(const int nIdx, unsigned short* pnEffect)
{
	return FALSE;
}

BOOL CConnectBasler::SetEffectAWB(const int nIdx, unsigned short nEffect)
{
	return FALSE;
}
BOOL CConnectBasler::GetEffectAWB(const int nIdx, unsigned short* pnEffect)
{
	return FALSE;
}

BOOL CConnectBasler::SetEffectSmooth(const int nIdx, unsigned short nEffect)
{
	return FALSE;
}
BOOL CConnectBasler::GetEffectSmooth(const int nIdx, unsigned short* pnEffect)
{
	return FALSE;
}

BOOL CConnectBasler::SetEffectSharpen(const int nIdx, unsigned short nEffect)
{
	return FALSE;
}
BOOL CConnectBasler::GetEffectSharpen(const int nIdx, unsigned short* pnEffect)
{
	return FALSE;
}

BOOL CConnectBasler::SetEffectFPN(const int nIdx, unsigned short nEffect)
{
	return FALSE;
}
BOOL CConnectBasler::GetEffectFPN(const int nIdx, unsigned short* pnEffect)
{
	return FALSE;
}

BOOL CConnectBasler::SetEffectPRNU(const int nIdx, unsigned short nEffect)
{
	return FALSE;
}
BOOL CConnectBasler::GetEffectPRNU(const int nIdx, unsigned short* pnEffect)
{
	return FALSE;
}

BOOL CConnectBasler::SetEffectDPC(const int nIdx, unsigned short nEffect)
{
	return FALSE;
}
BOOL CConnectBasler::GetEffectDPC(const int nIdx, unsigned short* pnEffect)
{
	return FALSE;
}

BOOL CConnectBasler::SetColorGain(const int nIdx, const int nGainType, int nGainVal)
{
	return FALSE;
}
BOOL CConnectBasler::GetColorGain(const int nIdx, const int nGainType, int* pnGainVal)
{
	return FALSE;
}




BOOL CConnectBasler::GetCameraInformation(const int nIdx, INFO_OTHER_CATEGORY* pstRootCategory)
{
	const int nCount = m_LibBasler.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx || NULL == pstRootCategory)
	{
		return FALSE;
	}

	BOOL bResult = m_LibBasler.GetCameraInformation(nIdx, pstRootCategory);
	return bResult;
}

const INFO_OTHER_IF* CConnectBasler::GetCameraInformation(const int nIdx, const TCHAR* szName)
{
	const int nCount = m_LibBasler.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx || NULL == szName)
	{
		return NULL;
	}

	const INFO_OTHER_IF* pOther = m_LibBasler.GetCameraInformation(nIdx, szName);
	return pOther;
}


BOOL CConnectBasler::GetCameraValue(const int nIdx, const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue)
{
	const int nCount = m_LibBasler.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx || NULL == pstValue)
	{
		return FALSE;
	}

	BOOL bResult = m_LibBasler.GetCameraValue(nIdx, pstInfo, pstValue);
	return bResult;
}

BOOL CConnectBasler::SetCameraValue(const int nIdx, const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue)
{
	const int nCount = m_LibBasler.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx || NULL == pstValue)
	{
		return FALSE;
	}

	BOOL bResult = m_LibBasler.SetCameraValue(nIdx, pstInfo, pstValue);
	return bResult;
}

#endif
