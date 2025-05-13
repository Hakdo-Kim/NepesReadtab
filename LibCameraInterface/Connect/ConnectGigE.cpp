#include "StdAfx.h"
#include "ConnectGigE.h"
#include "Util/Util.h"

#include "inc/PixelFormat.h"


CConnectGigE::CConnectGigE()
{
	memset(m_ArgList, 0x00, sizeof(INFO_ARG)*MAX_INTERFACE_MODULE);
}

CConnectGigE::~CConnectGigE()
{
	;
}

void CConnectGigE::AcquisitionEventHandler(unsigned char* pBuffer, unsigned int nSize, void* lpArg)
{
	INFO_ARG* pArg = (INFO_ARG*)lpArg;

	if (pArg && pArg->m_FuncAcq)
	{
		FuncAcquisitionEvent FuncAcq = pArg->m_FuncAcq;
		(*FuncAcq)(pBuffer, nSize, NULL, pArg->m_pUserData);
	}
}


BOOL CConnectGigE::IsConnected()
{
	BOOL bConnect = FALSE;

	const TYPE_NETWORK eNetwork = GetNetworkType();
	if ( TYPE_NETWORK_GIGE==eNetwork && m_GigE.IsOpen() )
		bConnect = TRUE;

	return bConnect;
}

BOOL CConnectGigE::Open(TYPE_NETWORK eNetwork)
{
	BOOL bResult = Open(eNetwork, NULL);
	return bResult;
}

BOOL CConnectGigE::Open(TYPE_NETWORK eNetwork, void* pReserved)
{
	if(TYPE_NETWORK_GIGE != eNetwork)
		return FALSE;

	BOOL bResult = m_GigE.Open();
	if(FALSE == bResult)
	{
		Close();
		return FALSE;
	}

	m_eNetwork = TYPE_NETWORK_GIGE;

	return TRUE;

}


void CConnectGigE::Close()
{
	m_GigE.Close();
	m_eNetwork = TYPE_NETWORK_NONE;
}

int CConnectGigE::GetDeviceCount()
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	return nCount;
}

int CConnectGigE::GetDeviceIndex(const INFO_CONNECT_DEV* pDev)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	int nIdx = -1;

	if(1>nCount || nCount <= nIdx || NULL==pDev )
		return nIdx;

	for(int i=0; i<nCount; i++)
	{
		const DEVMODULEINFO* pModule = m_GigE.GetDeviceModuleInfo(i);
		if (pModule->currentIPAddress == pDev->m_dwArg)
		{
			nIdx = i;
			break;
		}
	}

	return nIdx;
}

int CConnectGigE::GetDeviceID(const TCHAR* pName)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	int nIdx = -1;

	if (1>nCount || nCount <= nIdx || NULL == pName)
		return nIdx;

	INFO_CONNECT_GIGE stGigE;
	memset(&stGigE, 0x00, sizeof(INFO_CONNECT_GIGE));
	stGigE.m_stArg.m_eNetwork = TYPE_NETWORK_GIGE;

	BOOL bResult = FALSE;

	for (int i = 0; i < nCount; i++)
	{
		bResult = GetDeviceInfo(i, (INFO_CONNECT_DEV*)&stGigE);
		if (bResult  && CUtil::StringCompare((TCHAR*)pName, stGigE.m_stArg.m_szArg))
		{
			nIdx = i;
			break;
		}
	}
	return nIdx;
}


BOOL CConnectGigE::GetDeviceInfo(int nIdx, INFO_CONNECT_DEV* pstDevice)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if( 1>nCount || nCount <= nIdx || 
		NULL==pstDevice || TYPE_NETWORK_GIGE!=pstDevice->m_eNetwork )
	{
		return FALSE;
	}

	INFO_CONNECT_GIGE* pstGigE = (INFO_CONNECT_GIGE*)pstDevice;

	const DEVMODULEINFO* pstDevModule = m_GigE.GetDeviceModuleInfo(nIdx);
	if(NULL==pstDevModule)
		return FALSE;

	pstGigE->m_stArg.m_eNetwork = TYPE_NETWORK_GIGE;
	pstGigE->m_stArg.m_dwArg = pstDevModule->currentIPAddress;
	
	CUtil::StringFormat(pstGigE->m_szIpAddress, MAX_NAME_LEN, _T("%d.%d.%d.%d"),
		pstDevModule->currentIPAddress & 0xFF,
		(pstDevModule->currentIPAddress & 0xFF00) >> 8,
		(pstDevModule->currentIPAddress & 0xFF0000) >> 16,
		(pstDevModule->currentIPAddress & 0xFF000000) >> 24);
	CUtil::StringFormat(pstGigE->m_stArg.m_szArg, MAX_NAME_LEN, _T("%s (%s)"), pstDevModule->szModelName, pstGigE->m_szIpAddress);

	CUtil::StringCopy(pstGigE->m_szName, pstDevModule->szModelName);
	CUtil::StringCopy(pstGigE->m_szSerialNumber, pstDevModule->szSerialNumber);


	return TRUE;
}

BOOL CConnectGigE::UpdateDeviceInfo(int nIdx, INFO_CONNECT_DEV* pstDevice)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx ||
		NULL == pstDevice || TYPE_NETWORK_GIGE != pstDevice->m_eNetwork)
	{
		return FALSE;
	}

	INFO_CONNECT_GIGE* pstGigE = (INFO_CONNECT_GIGE*)pstDevice;

	const DEVMODULEINFO* pstDevModule = m_GigE.GetDeviceModuleInfo(nIdx);
	if (NULL == pstDevModule)
		return FALSE;

	// Update Ip address, subnetmask, gate way
	BOOL bResult = m_GigE.UpdateIpAddress(nIdx, pstGigE->m_dwIpAddress, pstGigE->m_dwSubnetMask, pstGigE->m_dwGateWay);
	
	return bResult;
}


BOOL CConnectGigE::ResearchDeviceInfo()
{
	EnterCriticalSection();

	BOOL bResult = m_GigE.FindAllDevice();
	CUtil::Sleep(10);

	LeaveCriticalSection();

	return bResult;
}


BOOL CConnectGigE::GetFrameInfo(const int nIdx ,INFO_FRAME* pstFrame)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if(1>nCount || nCount <= nIdx || NULL==pstFrame )
		return FALSE;

	m_GigE.GetMaxWidth( nIdx, &pstFrame->m_dwMaxWidth);
	m_GigE.GetMaxHeight( nIdx, &pstFrame->m_dwMaxHeight);

	DWORD dwPixelFormat	= 0;
	m_GigE.GetX( nIdx, &pstFrame->m_dwX);
	m_GigE.GetY( nIdx, &pstFrame->m_dwY);
	m_GigE.GetWidth( nIdx, &pstFrame->m_dwWidth);
	m_GigE.GetHeight( nIdx, &pstFrame->m_dwHeight);
	m_GigE.GetPixelFormat( nIdx, &dwPixelFormat);


	if (GVSP_PIX_MONO & dwPixelFormat)					pstFrame->m_eColor = TYPE_CAMCOLOR_MONO;
	else if (GVSP_PIX_COLOR & dwPixelFormat)			pstFrame->m_eColor = TYPE_CAMCOLOR_COLOR;
	else return FALSE;

	DWORD dwBit = ((dwPixelFormat>>16) & 0xFF) << 16;
	if( GVSP_PIX_OCCUPY8BIT == dwBit )				pstFrame->m_eDataBit = TYPE_DATABIT_08;
	else if( GVSP_PIX_OCCUPY12BIT  == dwBit )		pstFrame->m_eDataBit = TYPE_DATABIT_12;
	else if( GVSP_PIX_OCCUPY16BIT  == dwBit )		pstFrame->m_eDataBit = TYPE_DATABIT_16;
	else if( GVSP_PIX_OCCUPY24BIT  == dwBit )		pstFrame->m_eDataBit = TYPE_DATABIT_24;
	else if( GVSP_PIX_OCCUPY32BIT  == dwBit )		pstFrame->m_eDataBit = TYPE_DATABIT_32;
	else if( GVSP_PIX_OCCUPY36BIT  == dwBit )		pstFrame->m_eDataBit = TYPE_DATABIT_36;
	else if( GVSP_PIX_OCCUPY48BIT  == dwBit )		pstFrame->m_eDataBit = TYPE_DATABIT_48;
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

BOOL CConnectGigE::SetEventFunc(const int nIdx, FuncAcquisitionEvent pFunc, void* pUserData)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if(1>nCount || nCount <= nIdx )
		return FALSE;

	m_ArgList[nIdx].m_FuncAcq = pFunc;
	m_ArgList[nIdx].m_pUserData = pUserData;

	BOOL bResult = FALSE;

	if (NULL == pFunc && NULL == pUserData)
		bResult = m_GigE.SetEventCallbackImageAcquisition(nIdx, NULL, NULL);
	else
		bResult = m_GigE.SetEventCallbackImageAcquisition(nIdx, AcquisitionEventHandler, &(m_ArgList[nIdx]));

	return bResult;
}

BOOL CConnectGigE::Start(const int nIdx, BOOL bSingle)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if(1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = m_GigE.Start(nIdx, bSingle);
		
	return bResult;	
}

void CConnectGigE::Stop(const int nIdx)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if(1>nCount || nCount <= nIdx)
		return;

	m_GigE.Stop(nIdx);
}

BOOL CConnectGigE::IsOpen(const int nIdx)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;
	return TRUE;
}

BOOL CConnectGigE::Open(const int nIdx)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;
	return TRUE;
}

void CConnectGigE::Close(const int nIdx)
{
	Stop(nIdx);
}


BOOL CConnectGigE::SetRegister(const int nIdx, const DWORD dwAddress, const DWORD dwValue, DWORD dwReserved)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if(1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = m_GigE.WriteRegAddress(nIdx, dwAddress, dwValue);
	return bResult;
}

BOOL CConnectGigE::GetRegister(const int nIdx, const DWORD dwAddress, DWORD* pdwValue, DWORD dwReserved)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if(1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = m_GigE.ReadRegAddress(nIdx, dwAddress, pdwValue);
	return bResult;
}

/*//
BOOL CConnectGigE::SetRoi(const int nIdx, const int nX, const int nY, const int nW, const int nH)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if(1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = m_GigE.SetRoi(nIdx, nX, nY, nW, nH);
	return bResult;
}
//*/


//
BOOL CConnectGigE::SetGain(const int nIdx, const int nGainType, const int nGainValue)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = m_GigE.SetGain(nIdx, nGainValue);
	return bResult;
}
BOOL CConnectGigE::GetGain(const int nIdx, const int nGainType, int* pnGainValue)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx || NULL == pnGainValue)
		return FALSE;

	DWORD dwData = 0;
	BOOL bResult = m_GigE.GetGain(nIdx, &dwData);
	if (bResult)
	{
		*pnGainValue = dwData;
	}

	return bResult;
}

BOOL CConnectGigE::SetEnableFrameRate(const int nIdx, const unsigned int nEnale)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = m_GigE.SetEnableFps(nIdx, nEnale);
	return bResult;
}
BOOL CConnectGigE::GetEnableFrameRate(const int nIdx, unsigned int* pnEnale)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	DWORD dwValue = 0;

	BOOL bResult = m_GigE.GetEnableFps(nIdx, &dwValue);
	if (bResult)
	{
		*pnEnale = dwValue;
	}
	return bResult;
}

BOOL CConnectGigE::SetFrameRate(const int nIdx, const unsigned int nFrameRate)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = m_GigE.SetFps(nIdx, nFrameRate);
	return bResult;
}
BOOL CConnectGigE::GetFrameRate(const int nIdx, unsigned int* pnFrameRate)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx || NULL == pnFrameRate)
		return FALSE;

	DWORD dwFps = 0;

	BOOL bResult = m_GigE.GetFps(nIdx, &dwFps);
	if (bResult)
	{
		*pnFrameRate = dwFps;
	}
	return bResult;
}
BOOL CConnectGigE::GetMaxFrameRate(const int nIdx, unsigned int* pnFrameRate)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx || NULL == pnFrameRate)
		return FALSE;

	DWORD dwMaxFps = 0;

	BOOL bResult = m_GigE.GetMaxFps(nIdx, &dwMaxFps);
	if (bResult)
	{
		*pnFrameRate = dwMaxFps;
	}
	return bResult;
}

BOOL CConnectGigE::SetExposureTime(const int nIdx, const unsigned int nSetExposureTime)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = m_GigE.SetExposureTime(nIdx, (DWORD)nSetExposureTime);
	return bResult;
}
BOOL CConnectGigE::GetExposureTime(const int nIdx, unsigned int* pnSetExposureTime)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx || NULL == pnSetExposureTime)
		return FALSE;

	DWORD dwData = 0;
	BOOL bResult = m_GigE.GetExposureTime(nIdx, &dwData);
	if (bResult)
	{
		*pnSetExposureTime = dwData;
	}

	return bResult;
}

BOOL CConnectGigE::GetExposureMaxTime(const int nIdx, unsigned int FrameRate, unsigned int* pnSetExposureTime)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx || NULL == pnSetExposureTime)
		return FALSE;

	DWORD dwData = 0;
	
	BOOL bResult = m_GigE.GetExposureMaxTime(nIdx, &dwData);
	if (bResult)
	{
		*pnSetExposureTime = dwData;
	}
	return bResult;
}

BOOL CConnectGigE::ConvertExposureTime(const int nIdx, unsigned int nStep, double* pfUSec)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx || NULL == pfUSec)
		return FALSE;

	BOOL bResult = m_GigE.ConvertExposureTime(nIdx, nStep, pfUSec);
	return bResult;
}


BOOL CConnectGigE::SetTriggerMode(const int nIdx, INFO_TRIGGER_PARA stTrigger)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	m_GigE.Stop(nIdx);
	CUtil::Sleep(100);

	bResult = m_GigE.SetTriggerSource(nIdx, (DWORD)stTrigger.nTriggerSource);	// Trigger Source ( sw, line )

	if (bResult)
		bResult = m_GigE.SetTriggerDelay(nIdx, (DWORD)stTrigger.nTriggerDelay);		// 호출하면 trigger 설정이 되지 않음 일담 막음

	if (bResult)
		bResult = m_GigE.SetTriggerMode(nIdx, (BYTE)stTrigger.nTriggerMode, (BYTE)stTrigger.nTriggerTypePolarity);	// Trigger OnOFF ,  polarity

	if (stTrigger.nTriggerMode == 1)
	{
		if (stTrigger.nTriggerSource == 1)
		{
			BOOL bSingle = TRUE;
			m_GigE.Start(nIdx, bSingle); // sw trigger on 은 정상동작 하지 않는다.
		}
	}
	else
	{
		CUtil::Sleep(100);

		BOOL bSingle = FALSE;
		m_GigE.Start(nIdx, bSingle); // trigger off 는 정상동작 하지만
	}


	return bResult;
}
BOOL CConnectGigE::GetTriggerMode(const int nIdx, INFO_TRIGGER_PARA* pstTrigger)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx || NULL == pstTrigger )
		return FALSE;

	BOOL bResult = FALSE;

	DWORD dwData = 0;

	BYTE nMode = 0;
	BYTE nPolarity = 0;

	bResult = m_GigE.GetTriggerSource(nIdx, &dwData);
	if (FALSE == bResult)
		return FALSE;
	pstTrigger->nTriggerSource = (UINT)dwData;

	bResult = m_GigE.GetTriggerDelay(nIdx, &dwData);
	if (FALSE == bResult)
		return FALSE;
	pstTrigger->nTriggerDelay = (UINT)dwData;

	bResult = m_GigE.GetTriggerMode(nIdx, &nMode, &nPolarity);
	if (FALSE == bResult)
		return FALSE;

	pstTrigger->nTriggerMode = nMode;
	pstTrigger->nTriggerTypePolarity = nPolarity;


	return TRUE;
}

BOOL CConnectGigE::SetTriggerDelay(const int nIdx, int nDelay)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx )
		return FALSE;

	BOOL bResult = m_GigE.SetTriggerDelay(nIdx, (DWORD)nDelay);
	return bResult;
}

BOOL CConnectGigE::SaveUserset(const int nIdx, unsigned int nNumber)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = m_GigE.SaveUserset(nIdx, nNumber);
	return bResult;
}
BOOL CConnectGigE::LoadUserset(const int nIdx, unsigned int nNumber)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	if (0 == nNumber)
		bResult = m_GigE.LoadDefaultUserset(nIdx);
	else
		bResult = m_GigE.LoadUserset(nIdx, nNumber);

	return bResult;
}

BOOL CConnectGigE::SetStrobeMode(const int nIdx, INFO_STROBE_PARA stStrobe)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = FALSE;

	bResult = m_GigE.SetStrobeWidth(nIdx, (DWORD)stStrobe.nStrobeWidth);
	if (FALSE == bResult)
		return FALSE;
	
	bResult = m_GigE.SetStrobeDelay(nIdx, (DWORD)stStrobe.nStrobeDelay);
	if (FALSE == bResult)
		return FALSE;

	bResult = m_GigE.SetStrobeMode(nIdx, (BYTE)stStrobe.nStrobeMode, 1, (BYTE)stStrobe.nStrobePolarity); // strobe type fix "1"

	return bResult;
}
BOOL CConnectGigE::GetStrobeMode(const int nIdx, INFO_STROBE_PARA* pstStrobe)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx || NULL == pstStrobe)
		return FALSE;

	DWORD dwData = 0;

	BYTE  nMode = 0;
	BYTE  nType = 0;
	BYTE  nPolarity = 0;

	BOOL bResult = FALSE;

	bResult = m_GigE.GetStrobeWidth(nIdx, &dwData);
	if (FALSE == bResult)
		return FALSE;
	pstStrobe->nStrobeWidth = (UINT)dwData;

	bResult = m_GigE.GetStrobeDelay(nIdx, &dwData);
	if (FALSE == bResult)
		return FALSE;
	pstStrobe->nStrobeDelay = (UINT)dwData;

	bResult = m_GigE.GetStrobeMode(nIdx, &nMode, &nType, &nPolarity);
	if (FALSE == bResult)
		return FALSE;
	pstStrobe->nStrobeMode = nMode;
	pstStrobe->nStrobePolarity = nPolarity;
	
	return TRUE;
}

BOOL CConnectGigE::SetFlipMode(const int nIdx, unsigned short nMode)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = m_GigE.SetMirror(nIdx, nMode);
	return bResult;
}
BOOL CConnectGigE::GetFlipMode(const int nIdx, unsigned short* pnMode)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx || NULL == pnMode )
		return FALSE;

	DWORD dwData = 0;
	BOOL bResult = m_GigE.GetMirror(nIdx, &dwData);
	*pnMode = (unsigned short)dwData;


	return bResult;
}

BOOL CConnectGigE::SetROI(const int nIdx, INFO_ROI_PARA stROI)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	m_GigE.Stop(nIdx);
	CUtil::Sleep(500);

	BOOL bResult = m_GigE.SetRoi(nIdx, stROI.nXstart, stROI.nYstart, stROI.nWidth, stROI.nHeight);
	CUtil::Sleep(200);

	BOOL bSingle = FALSE;
	m_GigE.Start(nIdx, bSingle);

	return bResult;
}
BOOL CConnectGigE::GetROI(const int nIdx, INFO_ROI_PARA* pstROI)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx || NULL == pstROI )
		return FALSE;

	DWORD dwData = 0;

	m_GigE.GetX(nIdx, &dwData);
	pstROI->nXstart = dwData;

	m_GigE.GetY(nIdx, &dwData);
	pstROI->nYstart = dwData;

	m_GigE.GetWidth(nIdx, &dwData);
	pstROI->nWidth = dwData;

	m_GigE.GetHeight(nIdx, &dwData);
	pstROI->nHeight = dwData;

	m_GigE.GetMaxWidth(nIdx, &dwData);
	pstROI->nMaxWidth = dwData;

	m_GigE.GetMaxHeight(nIdx, &dwData);
	pstROI->nMaxHeight = dwData;


	return TRUE;
}

BOOL CConnectGigE::SetUsersetStartNo(const int nIdx, unsigned char nUsersetStartNo)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = m_GigE.SetBoostUserset(nIdx, nUsersetStartNo);
	return bResult;
}

BOOL CConnectGigE::GetUsersetStartNo(const int nIdx, unsigned char* pnUsersetStartNo)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx || NULL== pnUsersetStartNo)
		return FALSE;

	DWORD dwBoost = 0;

	BOOL bResult = m_GigE.GetBoostUserset(nIdx, &dwBoost);
	if (bResult)
		*pnUsersetStartNo = (BYTE)dwBoost;
	return bResult;
}

BOOL CConnectGigE::SetDataBit(const int nIdx, unsigned short nDataBit)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	DWORD dwPixelFormat = 0;

	INFO_FRAME stFrame;
	memset(&stFrame, 0x00, sizeof(INFO_FRAME));
	GetFrameInfo(nIdx, &stFrame);

	if (8 == nDataBit)
	{
		if (TYPE_CAMCOLORFORMAT_BAYER_GR == stFrame.m_eColorFormat)
			dwPixelFormat = GVSP_PIX_BAYERGR8;
		else if (TYPE_CAMCOLORFORMAT_BAYER_RG == stFrame.m_eColorFormat)
			dwPixelFormat = GVSP_PIX_BAYERRG8;
		else if (TYPE_CAMCOLORFORMAT_BAYER_GB == stFrame.m_eColorFormat)
			dwPixelFormat = GVSP_PIX_BAYERGB8;
		else if (TYPE_CAMCOLORFORMAT_BAYER_BG == stFrame.m_eColorFormat)
			dwPixelFormat = GVSP_PIX_BAYERBG8;
		else //if (TYPE_CAMCOLORFORMAT_MONO == stFrame.m_eColorFormat)
			dwPixelFormat = GVSP_PIX_MONO8;
	}
	else if (10 == nDataBit)
	{
		if (TYPE_CAMCOLORFORMAT_BAYER_GR == stFrame.m_eColorFormat)
			dwPixelFormat = GVSP_PIX_BAYERGR10_PACKED;
		else if (TYPE_CAMCOLORFORMAT_BAYER_RG == stFrame.m_eColorFormat)
			dwPixelFormat = GVSP_PIX_BAYERRG10_PACKED;
		else if (TYPE_CAMCOLORFORMAT_BAYER_GB == stFrame.m_eColorFormat)
			dwPixelFormat = GVSP_PIX_BAYERGB10_PACKED;
		else if (TYPE_CAMCOLORFORMAT_BAYER_BG == stFrame.m_eColorFormat)
			dwPixelFormat = GVSP_PIX_BAYERBG10_PACKED;
		else //if (TYPE_CAMCOLORFORMAT_MONO == stFrame.m_eColorFormat)
			dwPixelFormat = GVSP_PIX_MONO10_PACKED;

	}
	else if (12 == nDataBit)
	{
		if (TYPE_CAMCOLORFORMAT_BAYER_GR == stFrame.m_eColorFormat)
			dwPixelFormat = GVSP_PIX_BAYERGR12_PACKED;
		else if (TYPE_CAMCOLORFORMAT_BAYER_RG == stFrame.m_eColorFormat)
			dwPixelFormat = GVSP_PIX_BAYERRG12_PACKED;
		else if (TYPE_CAMCOLORFORMAT_BAYER_GB == stFrame.m_eColorFormat)
			dwPixelFormat = GVSP_PIX_BAYERGB12_PACKED;
		else if (TYPE_CAMCOLORFORMAT_BAYER_BG == stFrame.m_eColorFormat)
			dwPixelFormat = GVSP_PIX_BAYERBG12_PACKED;
		else //if (TYPE_CAMCOLORFORMAT_MONO == stFrame.m_eColorFormat)
			dwPixelFormat = GVSP_PIX_MONO12_PACKED;
	}
	else
	{
		return FALSE;
	}

	this->Stop(nIdx);
	CUtil::Sleep(500);

	BOOL bResult = m_GigE.SetPixelFormat(nIdx, dwPixelFormat);
	CUtil::Sleep(500);

	this->Start(nIdx);

	return bResult;
}

BOOL CConnectGigE::GetDataBit(const int nIdx, unsigned short* pnDataBit)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx || NULL == pnDataBit)
		return FALSE;

	DWORD dwPixelFormat = 0;
	BOOL bResult = m_GigE.GetPixelFormat(nIdx, &dwPixelFormat);
	if (bResult)
	{
		const DWORD dwBit = ((dwPixelFormat >> 16) & 0xFF) << 16;

		BYTE nBit = 8;
		if (GVSP_PIX_OCCUPY8BIT == dwBit)			nBit = 8;
		else if (GVSP_PIX_OCCUPY12BIT == dwBit)		nBit = 12;
		else if (GVSP_PIX_OCCUPY16BIT == dwBit)		nBit = 16;
		else if (GVSP_PIX_OCCUPY24BIT == dwBit)		nBit = 24;
		else if (GVSP_PIX_OCCUPY32BIT == dwBit)		nBit = 32;
		else if (GVSP_PIX_OCCUPY36BIT == dwBit)		nBit = 36;
		else if (GVSP_PIX_OCCUPY48BIT == dwBit)		nBit = 48;
		else return FALSE;

		*pnDataBit = nBit;
	}

	return bResult;
}

BOOL CConnectGigE::SetColorMode(const int nIdx, unsigned short nColorMode)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1 > nCount || nCount <= nIdx )
		return FALSE;
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectGigE::GetColorMode(const int nIdx, unsigned short* pnColorMode)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1 > nCount || nCount <= nIdx)
		return FALSE;
	BOOL bResult = FALSE;
	return bResult;
}



BOOL CConnectGigE::SetMTU(const int nIdx, unsigned int nMTU)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = m_GigE.SetMTU(nIdx, nMTU);
	return bResult;
}

BOOL CConnectGigE::GetMTU(const int nIdx, unsigned int* pnMTU)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx || NULL == pnMTU)
		return FALSE;

	DWORD dwMtu = 0;

	BOOL bResult = m_GigE.GetMTU(nIdx, &dwMtu);
	if (bResult && pnMTU)
		*pnMTU = dwMtu;
	return bResult;
}

BOOL CConnectGigE::GetDiag(const int nIdx, void* pstDiag, const int nLen)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx || sizeof(INFO_DIAGONOSTICS_GIGE) >nLen )
		return FALSE;

	DiagnosticData stDiag;
	memset(&stDiag, 0x00, sizeof(DiagnosticData));

	BOOL bResult = bResult = m_GigE.GetDiag(nIdx, &stDiag);
	if (bResult)
	{
		INFO_DIAGONOSTICS_GIGE* pstDiagGigE = (INFO_DIAGONOSTICS_GIGE*)pstDiag;

		pstDiagGigE->nDisplaySkipCount = stDiag.nDisplaySkipCount;
		pstDiagGigE->nFrameSkipCount = stDiag.nFrameSkipCount;
		pstDiagGigE->nImageFrameCount = stDiag.nImageFrameCount;
		pstDiagGigE->nRecvResend = stDiag.nRecvResend;

		pstDiagGigE->nRequestResend = stDiag.nRequestResend;
		pstDiagGigE->fFrameRate = stDiag.fFrameRate;
		pstDiagGigE->Mbps = stDiag.Mbps;

	}

	return bResult;
}

BOOL CConnectGigE::SetSWTrigger(const int nIdx)
{
	const int nCount = m_GigE.GetEnableDeviceCount();
	if (1>nCount || nCount <= nIdx)
		return FALSE;

	BOOL bResult = m_GigE.SetTrigger(nIdx);
	return bResult;
}



// LUT
BOOL CConnectGigE::SetLutMode(const int nIdx, unsigned short nMode)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectGigE::GetLutMode(const int nIdx, unsigned short* pnMode)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectGigE::WriteLut(const int nIdx, const INFO_LUT_PARA* pLutList, const int nLen, BOOL bEeprom)
{
	BOOL bResult = FALSE;
	return bResult;
}


// Effect
BOOL CConnectGigE::SetEffectNR(const int nIdx, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectGigE::GetEffectNR(const int nIdx, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectGigE::SetEffectGC(const int nIdx, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectGigE::GetEffectGC(const int nIdx, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectGigE::SetEffectCM(const int nIdx, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectGigE::GetEffectCM(const int nIdx, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectGigE::SetEffectAWB(const int nIdx, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectGigE::GetEffectAWB(const int nIdx, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectGigE::SetEffectSmooth(const int nIdx, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectGigE::GetEffectSmooth(const int nIdx, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}


BOOL CConnectGigE::SetEffectSharpen(const int nIdx, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectGigE::GetEffectSharpen(const int nIdx, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectGigE::SetEffectFPN(const int nIdx, unsigned short nEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}
BOOL CConnectGigE::GetEffectFPN(const int nIdx, unsigned short* pnEffect)
{
	BOOL bResult = FALSE;
	return bResult;
}

BOOL CConnectGigE::SetEffectPRNU(const int nIdx, unsigned short nEffect)
{
	BOOL bResult = m_GigE.SetPRNU(nIdx, nEffect);
	return bResult;
}
BOOL CConnectGigE::GetEffectPRNU(const int nIdx, unsigned short* pnEffect)
{
	DWORD dwPrnu = 0;
	BOOL bResult = m_GigE.GetPRNU(nIdx, &dwPrnu);
	if (bResult && pnEffect)
	{
		*pnEffect = (unsigned short)dwPrnu;
	}
	return bResult;
}

BOOL CConnectGigE::SetEffectDPC(const int nIdx, unsigned short nEffect)
{
	BOOL bResult = m_GigE.SetDPC(nIdx, nEffect);
	return bResult;
}
BOOL CConnectGigE::GetEffectDPC(const int nIdx, unsigned short* pnEffect)
{
	if (NULL == pnEffect)
		return FALSE;

	DWORD dwDPC = 0;
	BOOL bResult = m_GigE.GetDPC(nIdx, &dwDPC);
	if (bResult && pnEffect)
	{
		*pnEffect = (unsigned short)dwDPC;
	}

	return bResult;
}

BOOL CConnectGigE::SetColorGain(const int nIdx, const int nGainType, int nGainVal)
{
	BOOL bResult = FALSE;

	if (RED == nGainType)
		bResult = m_GigE.SetGainRed(nIdx, nGainVal);
	else if (GREEN == nGainType)
		bResult = m_GigE.SetGainGreen(nIdx, nGainVal);
	else if (BLUE == nGainType)
		bResult = m_GigE.SetGainBlue(nIdx, nGainVal);
	else if (GREEN2 == nGainType)
		bResult = m_GigE.SetGainGreen2(nIdx, nGainVal);
	
	return bResult;
}
BOOL CConnectGigE::GetColorGain(const int nIdx, const int nGainType, int* pnGainVal)
{
	BOOL bResult = FALSE;

	DWORD dwGain = 0;

	if (RED == nGainType)
		bResult = m_GigE.GetGainRed(nIdx, &dwGain);
	else if (GREEN == nGainType)
		bResult = m_GigE.GetGainGreen(nIdx, &dwGain);
	else if (BLUE == nGainType)
		bResult = m_GigE.GetGainBlue(nIdx, &dwGain);
	else if (GREEN2 == nGainType)
		bResult = m_GigE.GetGainGreen2(nIdx, &dwGain);

	if (bResult)
		*pnGainVal = dwGain;

	return bResult;
}