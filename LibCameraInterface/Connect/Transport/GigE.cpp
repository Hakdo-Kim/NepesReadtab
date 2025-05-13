#include "StdAfx.h"
#include "GigE.h"

#include "Util/Util.h"
#include "inc/LpGigEVID.h"


#if defined(_WIN64)
	#pragma comment (lib, "LpGenTLGigEx64.lib")
#else
	#pragma comment(lib, "LpGenTLGigE.lib")
#endif

CGigE::CGigE()
{
	m_hTLHandle	= NULL;
	m_bInit		= FALSE;

	memset(m_pstIfModuleInfo, 0x00, sizeof(IFMODULEINFO)*MAX_INTERFACE_MODULE);
	m_nIfModuleInfo = 0;

	memset(m_pstDevInfo, 0x00, sizeof(DEVLISTINFO)*MAX_INTERFACE_MODULE);

	memset(m_pstDevModuleInfo, 0x00, sizeof(DEVMODULEINFO)*MAX_INTERFACE_MODULE);
	m_nDevModuleInfo = 0;

	memset(m_pLastSWTrigger, 0x00, sizeof(LONGLONG)*MAX_INTERFACE_MODULE);

	m_bFilterDriverOnOff = FALSE;

	memset(m_pbWorkingModule, 0x00, sizeof(BOOL)*MAX_INTERFACE_MODULE);
}

CGigE::~CGigE()
{
	;
}

BOOL CGigE::Open()
{
	int nErrCode = GCInitLib();
	if(GC_ERR_SUCCESS != nErrCode)
		return FALSE;

	nErrCode = TLOpen(&m_hTLHandle);
	if(GC_ERR_SUCCESS != nErrCode)
		return FALSE;

	if(FALSE == FindAllDevice() )
		return FALSE;

	SetFilterDriverOnOff(FALSE);

	{
		const int nCount = GetEnableDeviceCount();
		for(int i=0; i<nCount; i++)
		{
			SetControlChannel(i, TRUE);
		}
	}

	m_bInit = TRUE;
	memset(m_pbWorkingModule, 0x00, sizeof(BOOL)*MAX_INTERFACE_MODULE);

	return TRUE;
}

void CGigE::Close()
{
	if(FALSE==IsOpen())
		return;

	for(int i=0; i<m_nDevModuleInfo; i++)
	{
		DevClose( (DEV_HANDLE) m_pstDevInfo[i].IPAddress);
	}

	SetFilterDriverOnOff(FALSE);

	if(m_hTLHandle)
		TLClose ( m_hTLHandle );
	m_hTLHandle = NULL;

	GCCloseLib();

	m_bInit = FALSE;
}

BOOL CGigE::IsOpen()
{
	BOOL bOpen = FALSE;
	if( m_bInit && m_hTLHandle )
		bOpen = TRUE;

	return bOpen;
}

BOOL CGigE::SetControlChannel(const int nIdx, BOOL bEnable)
{
	const int nCount = GetEnableDeviceCount() ;
	if( nIdx >= nCount)
		return FALSE;

	DWORD dwIP = 0;
	BOOL bResult = GetDevicePortHandle(nIdx, &dwIP);
	if(FALSE==bResult)
		return FALSE;

	if (bResult)
	{
		int nErrCode = EEOpenControlChannel((PORT_HANDLE)dwIP, bEnable);
		if (GC_ERR_SUCCESS != nErrCode)
			bResult = FALSE;
	}

	return bResult;
}

BOOL CGigE::FindAllDevice()
{
	int nErrCode = EEDiscoveryAllDevice();
	if(GC_ERR_SUCCESS != nErrCode)
		return FALSE;

	memset(m_pstIfModuleInfo, 0x00, sizeof(IFMODULEINFO)*MAX_INTERFACE_MODULE);
	m_nIfModuleInfo = MAX_INTERFACE_MODULE;

	memset(m_pstDevInfo, 0x00, sizeof(DEVLISTINFO)*MAX_INTERFACE_MODULE);

	DEVMODULEINFO pstDevModule[MAX_INTERFACE_MODULE];
	memset(pstDevModule, 0x00, sizeof(DEVMODULEINFO)*MAX_INTERFACE_MODULE);
	BYTE nDevModule = MAX_INTERFACE_MODULE;

	nErrCode = EEGetIFDevInformation(m_pstIfModuleInfo, &m_nIfModuleInfo, m_pstDevInfo, pstDevModule, &nDevModule);
	if (GC_ERR_SUCCESS != nErrCode)
	{
		memset(m_pstDevModuleInfo, 0x00, sizeof(DEVMODULEINFO)*MAX_INTERFACE_MODULE);
		m_nDevModuleInfo = 0;
		return FALSE;
	}

#if 0
	memcpy(m_pstDevModuleInfo, pstDevModuleInfo, sizeof(DEVMODULEINFO) * MAX_INTERFACE_MODULE);
	m_nDevModuleInfo = nDevModuleInfo;

#else

	int nWorkingDevice = 0;
	for (int i = 0; i < MAX_INTERFACE_MODULE; i++)
	{
		if (m_pbWorkingModule[i])
			nWorkingDevice++;
	}

	if (1 > nWorkingDevice)
	{
		memcpy(m_pstDevModuleInfo, pstDevModule, sizeof(DEVMODULEINFO) * MAX_INTERFACE_MODULE);
		m_nDevModuleInfo = nDevModule;
	}
	else
	{
		for (int i = m_nDevModuleInfo - 1; i >= 0; i--)
		{
			for (int j = 0; j < nDevModule; j++)
			{
				if (m_pstDevModuleInfo[i].nIFIPAddress == pstDevModule[j].nIFIPAddress)
				{
					pstDevModule[j].iIFIndex = 0xFF;
					break;
				}
			}
		}

		for (int i = 0; i < nDevModule; i++)
		{
			if (0xFF == pstDevModule[i].iIFIndex)
				continue;
			memcpy(&(m_pstDevModuleInfo[m_nDevModuleInfo]), &(pstDevModule[i]), sizeof(DEVMODULEINFO));
			m_nDevModuleInfo++;
		}
	}

	CUtil::PrintDebugString(_T("Search Device: GigE \r\n"));
	for (int i = 0; i < m_nDevModuleInfo; i++)
	{
		CUtil::PrintDebugString(_T("  [%d]  %s  %s \r\n"), i, m_pstDevModuleInfo[i].szIP, m_pstDevModuleInfo[i].szModelName);
	}
	CUtil::PrintDebugString(_T("Done \r\n"));

#endif


	{
		const int nCount = GetEnableDeviceCount();
		for (int i = 0; i<nCount; i++)
		{
			SetControlChannel(i, TRUE);
		}
	}

	return TRUE;
}

BOOL CGigE::SetFilterDriverOnOff(BOOL bOnOff)
{
	int nErrCode = EnableFilterDriver( bOnOff );
	if(GC_ERR_SUCCESS != nErrCode)
		return FALSE;

	m_bFilterDriverOnOff = bOnOff;

	return TRUE;
}

BOOL CGigE::GetFilterDriverOnOff(BOOL* pbOnOff)
{
	if(NULL==pbOnOff)
		return FALSE;

	BYTE nOnOff = FALSE;
	int nErrCode = GetFilterDriverStatus( &nOnOff );
	if(GC_ERR_SUCCESS != nErrCode)
		return FALSE;

	*pbOnOff = nOnOff;
	m_bFilterDriverOnOff = *pbOnOff;

	return TRUE;
}

const int CGigE::GetEnableDeviceCount()
{
	return m_nDevModuleInfo;
}

const DEVMODULEINFO* CGigE::GetDeviceModuleInfo(const int nIdx)
{
	const int nCount = GetEnableDeviceCount() ;
	if( nIdx >=  nCount )
		return NULL;

	return &m_pstDevModuleInfo[nIdx];
}

BOOL CGigE::GetFirmwareVersion(const int nIdx, DWORD* pVersion)
{
	if (NULL == pVersion)
		return FALSE;

	DWORD dwVer = 0;
	//
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_SS_MIRROR_COL, &dwVer);
	if (bResult)
		*pVersion = dwVer;

	return bResult;
}

BOOL CGigE::GetSensorType(const int nIdx, DWORD* pSensorType)
{
	if (NULL == pSensorType)
		return FALSE;

	DWORD dwType = 0;
	const DWORD dwAddr = (2 << 28) | (0);
	BOOL bResult = ReadRegAddress(nIdx, dwAddr, &dwType);
	if (bResult)
		*pSensorType = dwType;

	return bResult;
}


BOOL CGigE::GetDevicePortHandle(int nIdx, DWORD* pdwIp)
{
	const DEVMODULEINFO* pstModule = GetDeviceModuleInfo(nIdx);

	if(NULL==pstModule || NULL==pdwIp)
		return FALSE;

	*pdwIp = pstModule->currentIPAddress;
	return TRUE;
}

BOOL CGigE::UpdateIpAddress(const int nIdx, DWORD dwIpAddr, DWORD dwSubnet, DWORD dwGateWay)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount)
		return FALSE;

	DWORD dwIP = 0;
	BOOL bResult = GetDevicePortHandle(nIdx, &dwIP);
	if (FALSE == bResult)
		return FALSE;

	int nErrCode = DeviceIPChange((PORT_HANDLE)dwIP, dwIpAddr, dwSubnet, dwGateWay);
	if (GC_ERR_SUCCESS == nErrCode)
	{
		m_pstDevModuleInfo[nIdx].currentIPAddress = dwIpAddr;
		m_pstDevModuleInfo[nIdx].subnetAddress = dwSubnet;
		m_pstDevModuleInfo[nIdx].GateWay = dwGateWay;

		bResult = TRUE;
	}
	else
	{
		bResult = FALSE;
	}

	return bResult;
}

BOOL CGigE::ReadDword(DWORD dwIP, DWORD dwAddress, DWORD* pValue)
{
	size_t nSize = sizeof(DWORD);
	int nErrCode = GCReadPort( (PORT_HANDLE)dwIP, dwAddress, pValue, &nSize );
	if(GC_ERR_SUCCESS != nErrCode)
		return FALSE;

	return TRUE;
}

BOOL CGigE::WriteDword(DWORD dwIP, DWORD dwAddress, DWORD* pValue)
{
	size_t nSize = sizeof(DWORD);
	int nErrCode = GCWritePort( (PORT_HANDLE)dwIP, dwAddress, pValue, &nSize );
	if(GC_ERR_SUCCESS != nErrCode)
		return FALSE;

	return TRUE;
}


BOOL CGigE::ReadRegAddress(const int nIdx, const DWORD dwAddress, DWORD* pdwValue)
{
	const int nCount = GetEnableDeviceCount() ;
	if( nIdx >= nCount || NULL==pdwValue )
		return FALSE;

	DWORD dwIP = 0;
	BOOL bResult = GetDevicePortHandle(nIdx, &dwIP);
	if(bResult)
		bResult = ReadDword(dwIP, dwAddress, pdwValue);

	return bResult;
}

BOOL CGigE::WriteRegAddress(const int nIdx, const DWORD dwAddress, DWORD dwValue)
{
	const int nCount = GetEnableDeviceCount() ;
	if( nIdx >= nCount )
		return FALSE;

	DWORD dwIP = 0;
	BOOL bResult = GetDevicePortHandle(nIdx, &dwIP);
	if(bResult)
		bResult = WriteDword(dwIP, dwAddress, &dwValue);

	return bResult;
}

BOOL CGigE::GetX(const int nIdx, DWORD* pdwValue)
{
	if( NULL==pdwValue )
		return FALSE;

	DWORD dwValue = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_IMG_XOFFSET, &dwValue);
	if (bResult)
		*pdwValue = dwValue;

	return bResult;
}

BOOL CGigE::GetY(const int nIdx, DWORD* pdwValue)
{
	if (NULL == pdwValue)
		return FALSE;

	DWORD dwValue = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_IMG_YOFFSET, &dwValue);
	if (bResult)
		*pdwValue = dwValue;

	return bResult;

}


BOOL CGigE::GetWidth(const int nIdx, DWORD* pdwValue)
{
	if (NULL == pdwValue)
		return FALSE;

	DWORD dwValue = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_IMG_WIDTH, &dwValue);
	if (bResult)
		*pdwValue = dwValue;

	return bResult;

}

BOOL CGigE::GetHeight(const int nIdx, DWORD* pdwValue)
{
	if (NULL == pdwValue)
		return FALSE;

	DWORD dwValue = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_IMG_HEIGHT, &dwValue);
	if (bResult)
		*pdwValue = dwValue;

	return bResult;
}

BOOL CGigE::GetMaxWidth(const int nIdx, DWORD* pdwValue)
{
	if (NULL == pdwValue)
		return FALSE;

	DWORD dwValue = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RO_IMG_MAXWIDTH, &dwValue);
	if (bResult)
		*pdwValue = dwValue;

	return bResult;
}

BOOL CGigE::GetMaxHeight(const int nIdx, DWORD* pdwValue)
{
	DWORD dwValue = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RO_IMG_MAXHEIGHT, &dwValue);
	if (bResult)
		*pdwValue = dwValue;

	return bResult;
}

BOOL CGigE::GetPixelFormat(const int nIdx, DWORD* pdwValue)
{
	DWORD dwValue = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_PIXELFORMAT, &dwValue);
	if (bResult)
		*pdwValue = dwValue;

	return bResult;
}

BOOL CGigE::SetPixelFormat(const int nIdx, DWORD dwValue)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_PIXELFORMAT, dwValue);
	return bResult;
}

BOOL CGigE::SetEventCallbackImageAcquisition(const int nIdx, CallBackAcquisitionEvent pFunc, void* pUserData)
{
	const int nCount = GetEnableDeviceCount() ;
	if( nIdx >= nCount)
		return FALSE;

	DWORD dwIP = 0;
	BOOL bResult = GetDevicePortHandle(nIdx, &dwIP);
	if (FALSE == bResult)
		return FALSE;

	if (pFunc || pUserData)
	{
		SetControlChannel(nIdx, TRUE);
		m_pbWorkingModule[nIdx] = TRUE;
	}
	else
	{
		SetControlChannel(nIdx, FALSE);
		m_pbWorkingModule[nIdx] = FALSE;
	}

	int nErrCode = EventCallbackImageAcquisition( (PORT_HANDLE)dwIP, pFunc, pUserData);
	if(GC_ERR_SUCCESS != nErrCode)
		return FALSE;

	return TRUE;
}


BOOL CGigE::Start(const int nIdx, BOOL bSingle)
{
	const int nCount = GetEnableDeviceCount() ;
	if( nIdx >= nCount )
		return FALSE;

	DWORD dwIP = 0;
	BOOL bResult = GetDevicePortHandle(nIdx, &dwIP);
	if (FALSE == bResult)
		return FALSE;

	DWORD dwNumAcquire = 1;
	if(bSingle)
	{
		dwNumAcquire = 1;
		m_pstDevModuleInfo[nIdx].bReceiveMode = 2;		// Single and SW Trigger
	}
	else
	{
		dwNumAcquire = 0xFFFFFFFF;
		m_pstDevModuleInfo[nIdx].bReceiveMode = 1;		// Continuous
	}

	if (bResult)
	{
		DWORD dwData = 1;
		WriteRegAddress(nIdx, LP_GIGE_RW_DDR_RESET, dwData);
		Sleep(100);

		int nErrCode = DSStartAcquisition((PORT_HANDLE)dwIP, ACQ_START_FLAGS_DEFAULT, dwNumAcquire);
		if (GC_ERR_SUCCESS != nErrCode)
			bResult =  FALSE;

		m_bStart = bResult;
	}

	return bResult;
}

void CGigE::Stop(const int nIdx)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount)
		return;

	DWORD dwIP = 0;
	BOOL bResult = GetDevicePortHandle(nIdx, &dwIP);
	if(FALSE==bResult)
		return;

	if (bResult)
	{
		int nErrCode = DSStopAcquisition((PORT_HANDLE)dwIP, ACQ_STOP_FLAGS_DEFAULT);
		if (GC_ERR_SUCCESS == nErrCode)
		{
			m_pstDevModuleInfo[nIdx].bReceiveMode = 0;
			bResult = TRUE;
		}
		else
		{
			bResult = FALSE;
		}

		if (m_bStart)
		{
			CUtil::Sleep(1000);
			m_bStart = FALSE;
		}
	}
}

BOOL CGigE::SetTrigger(const int nIdx)
{
#if 1
	DWORD dwData = 0x02;
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_OPMODE, dwData);
#else
	DWORD dwData = 0x00;
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_OPMODE, dwData);
	if (bResult)
	{
		dwData = 0x02;
		bResult = WriteRegAddress(nIdx, LP_GIGE_RW_OPMODE, dwData);
	}
#endif
	return bResult;
}

BOOL CGigE::SetRoi(const int nIdx, const int nX, const int nY, const int nW, const int nH)
{
	const int nCount = GetEnableDeviceCount() ;
	if( nIdx >= nCount )
		return FALSE;

	DWORD dwIP = 0;
	BOOL bResult = GetDevicePortHandle(nIdx, &dwIP);

	if (bResult)
	{
		int nErrCode = EESetImageSizeROI((PORT_HANDLE)dwIP, nX, nY, nW, nH);
		if (GC_ERR_SUCCESS != nErrCode)
			bResult = FALSE;
	}

	return bResult;

}

void CGigE::ConvertColor(BYTE* pSrc, BYTE* pDest, BYTE* pColor, int nW, int nH, DWORD dwPixelFormat)
{
	EEConvertColor(pSrc, pDest, pColor, nW, nH, dwPixelFormat);
}

BOOL CGigE::GetBinning(const int nIdx, DWORD* pdwMode)
{
	if (NULL == pdwMode)
		return FALSE;

	DWORD dwBinning = 0;

	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_SS_BIN_MODE, &dwBinning);
	if (bResult)
	{
		*pdwMode = dwBinning;
	}

	return bResult;
}

BOOL CGigE::SetBinning(const int nIdx, int nW, int nH, BYTE nMode)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount )
		return FALSE;

	DWORD dwIP = 0;
	BOOL bResult = GetDevicePortHandle(nIdx, &dwIP);
	if (FALSE == bResult)
		return FALSE;

	if (0 == nMode)
	{
		if (nW % 4)
			return FALSE;
	}
	else if (1 == nMode)
	{
		if (nW % 8)
			return FALSE;
	}
	else if (2 == nMode)
	{
		if (nW % 12)
			return FALSE;
	}

	int nErrCode = EESetImageSizeBinning((PORT_HANDLE)dwIP, nW, nH, nMode);
	if (GC_ERR_SUCCESS != nErrCode)
		bResult = FALSE;

	return bResult;
}

BOOL CGigE::GetControlChannelPrivilege(const int nIdx, DWORD* pdwValue)
{
	if (NULL == pdwValue)
		return FALSE;

	const DWORD dwAddress = 0x00000A00;
	DWORD dwData = 0;

	BOOL bResult = ReadRegAddress(nIdx, dwAddress, &dwData);
	if (bResult)
	{
		*pdwValue = dwData;
	}

	return bResult;
}

BOOL CGigE::GetMTU(const int nIdx, DWORD* pdwMtu)
{
	if (NULL == pdwMtu)
		return FALSE;

	DWORD dwIP = 0;
	BOOL bResult = GetDevicePortHandle(nIdx, &dwIP);
	if (FALSE == bResult)
		return FALSE;

	unsigned int nMtuSize = 0;
	int nErrCode = ::GetMTU((PORT_HANDLE)dwIP, &nMtuSize);
	if (GC_ERR_SUCCESS != nErrCode)
		bResult = FALSE;
	
	*pdwMtu = nMtuSize;

	return bResult;
}

BOOL CGigE::SetMTU(const int nIdx, DWORD dwMtu)
{
	DWORD dwIP = 0;
	BOOL bResult = GetDevicePortHandle(nIdx, &dwIP);
	if (FALSE == bResult)
		return FALSE;

	int nErrCode = ::SetMTU((PORT_HANDLE)dwIP, dwMtu);
	if (GC_ERR_SUCCESS != nErrCode)
		bResult = FALSE;

	return bResult;
}

BOOL CGigE::SetHeartbeat(const int nIdx, DWORD dwValue)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_GEN_HEARTBEAT_TO, dwValue);
	return bResult;
}

BOOL CGigE::GetTriggerMode(const int nIdx, BYTE* pMode, BYTE* pType)
{
	if (NULL == pMode || pType == pMode)
		return FALSE;

	BYTE nEnable = 0;
	BYTE nPol = 0;

	BOOL bResult = GetTriggerEnable(nIdx, &nEnable);
	if (FALSE == bResult)
		return FALSE;

	bResult = GetTriggerPolarity(nIdx, &nPol);
	if (bResult)
	{
		*pMode = nEnable;
		*pType = nPol;
	}

	return bResult;
}

BOOL CGigE::SetTriggerMode(const int nIdx, BYTE nMode, BYTE nType)
{
	BYTE nEnable = nMode;
	BYTE nPol = nType;

	BOOL bResult = SetTriggerEnable(nIdx, nEnable);
	if (FALSE == bResult)
		return FALSE;

	bResult = SetTriggerPolarity(nIdx, nPol);

	return bResult;
}

BOOL CGigE::GetTriggerEnable(const int nIdx, BYTE* pEnable)
{
	if (NULL == pEnable)
		return FALSE;

	DWORD dwEnable = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_TRIG_EN, &dwEnable);
	if (bResult)
		*pEnable = (BYTE)dwEnable;
	
	return bResult;
}

BOOL CGigE::SetTriggerEnable(const int nIdx, BYTE nEnable)
{
	DWORD dwEnable = nEnable;
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_TRIG_EN, dwEnable);

	return bResult;
}

BOOL CGigE::GetTriggerPolarity(const int nIdx, BYTE* pPolarity)
{
	if (NULL == pPolarity)
		return FALSE;

	DWORD dwPol = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_TRIG_POL, &dwPol);
	if (bResult)
		*pPolarity = (BYTE)dwPol;

	return bResult;
}

BOOL CGigE::SetTriggerPolarity(const int nIdx, BYTE nPolarity)
{
	DWORD dwPol = nPolarity;
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_TRIG_POL, dwPol);

	return bResult;
}

BOOL CGigE::GetTriggerDelay(const int nIdx, DWORD* pDelay)
{
	if (NULL == pDelay)
		return FALSE;

	DWORD dwDelay = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_TRIG_DELAY, &dwDelay);
	if (bResult)
		*pDelay = dwDelay;

	return bResult;
}

BOOL CGigE::SetTriggerDelay(const int nIdx, DWORD dwDelay)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_TRIG_DELAY, dwDelay);
	return bResult;
}

BOOL CGigE::GetTriggerWidth(const int nIdx, DWORD* pWidth)
{
	if (NULL == pWidth)
		return FALSE;

	DWORD dwWidth = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_TRIG_WIDTH, &dwWidth);
	if (bResult)
		*pWidth = dwWidth;

	return bResult;
}

BOOL CGigE::SetTriggerWidth(const int nIdx, DWORD dwWidth)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_TRIG_WIDTH, dwWidth);
	return bResult;
}

BOOL CGigE::GetTriggerSource(const int nIdx, DWORD* pSrc)
{
	if (NULL == pSrc)
		return FALSE;

	DWORD dwSrc = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_TRIG_SRC, &dwSrc);
	if (bResult)
		*pSrc = dwSrc;

	return bResult;
}

BOOL CGigE::SetTriggerSource(const int nIdx, DWORD dwSrc)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_TRIG_SRC, dwSrc);
	return bResult;
}


BOOL CGigE::GetStrobeMode(const int nIdx, BYTE* pMode, BYTE* pType, BYTE* pPolarity)
{
	if (NULL == pMode || NULL == pType || NULL == pPolarity)
		return FALSE;

	BYTE nEnable = 0;
	BYTE nType = 0;
	BYTE nPol = 0;

	BOOL bResult = GetStrobeEnable(nIdx, &nEnable);
	if (FALSE == bResult)
		return FALSE;

	bResult = GetStrobeType(nIdx, &nType);
	//if (FALSE == bResult)		// false return...
	//	return FALSE;

	bResult = GetStrobePolarity(nIdx, &nPol);
	if (FALSE == bResult)
		return FALSE;

	*pMode = nEnable;
	*pType = nType;
	*pPolarity = nPol;

	return bResult;
}

BOOL CGigE::SetStrobeMode(const int nIdx, BYTE nMode, BYTE nType, BYTE nPolarity)
{
	BOOL bResult = SetStrobeEnable(nIdx, nMode);
	if (FALSE == bResult)
		return FALSE;

	bResult = SetStrobeType(nIdx, nType);
	//if (FALSE == bResult)		// false return...
	//	return FALSE;

	bResult = SetStrobePolarity(nIdx, nPolarity);

	return bResult;
}

BOOL CGigE::GetStrobeEnable(const int nIdx, BYTE* pEnable)
{
	if (NULL == pEnable)
		return FALSE;

	DWORD dwEnable = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_STROBE_EN, &dwEnable);
	if (bResult)
		*pEnable = (BYTE)dwEnable;

	return bResult;
}

BOOL CGigE::SetStrobeEnable(const int nIdx, BYTE nEnable)
{
	DWORD dwEnable = nEnable;
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_STROBE_EN, dwEnable);

	return bResult;
}

BOOL CGigE::GetStrobeType(const int nIdx, BYTE* pType)
{
	if (NULL == pType)
		return FALSE;

	DWORD dwType = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_STROBE_TYPE, &dwType);
	if (bResult)
		*pType = (BYTE)dwType;

	return bResult;
}

BOOL CGigE::SetStrobeType(const int nIdx, BYTE nType)
{
	DWORD dwType = nType;
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_STROBE_TYPE, dwType);

	return bResult;
}

BOOL CGigE::GetStrobePolarity(const int nIdx, BYTE* pPolarity)
{
	if (NULL == pPolarity)
		return FALSE;

	DWORD dwPol = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_STROBE_POL, &dwPol);
	if (bResult)
		*pPolarity = (BYTE)dwPol;

	return bResult;
}

BOOL CGigE::SetStrobePolarity(const int nIdx, BYTE nPolarity)
{
	DWORD dwPol = nPolarity;
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_STROBE_POL, dwPol);

	return bResult;
}

BOOL CGigE::GetStrobeDelay(const int nIdx, DWORD* pDelay)
{
	if (NULL == pDelay)
		return FALSE;

	DWORD dwDelay = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_STROBE_DELAY, &dwDelay);
	if (bResult)
		*pDelay = dwDelay;

	return bResult;
}


BOOL CGigE::SetStrobeDelay(const int nIdx, DWORD dwDelay)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_STROBE_DELAY, dwDelay);
	return bResult;
}

BOOL CGigE::GetStrobeWidth(const int nIdx, DWORD* pWidth)
{
	if (NULL == pWidth)
		return FALSE;

	DWORD dwWidth = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_STROBE_WIDTH, &dwWidth);
	if (bResult)
		*pWidth = dwWidth;

	return bResult;
}

BOOL CGigE::SetStrobeWidth(const int nIdx, DWORD dwWidth)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_STROBE_WIDTH, dwWidth);
	return bResult;
}

BOOL CGigE::GetGain(const int nIdx, DWORD* pGain)
{
	if (NULL == pGain)
		return FALSE;

	DWORD dwGain = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_SS_GAIN_GLOBAL, &dwGain);
	if (bResult)
		*pGain = dwGain;

	return bResult;
}

BOOL CGigE::SetGain(const int nIdx, DWORD dwGain)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_SS_GAIN_GLOBAL, dwGain);
	return bResult;
}

BOOL CGigE::GetGainRed(const int nIdx, DWORD* pGain)
{
	if (NULL == pGain)
		return FALSE;

	DWORD dwGain = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_SS_GAIN_RED, &dwGain);
	if (bResult)
		*pGain = dwGain;

	return bResult;
}

BOOL CGigE::SetGainRed(const int nIdx, DWORD dwGain)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_SS_GAIN_RED, dwGain);
	return bResult;
}

BOOL CGigE::GetGainGreen(const int nIdx, DWORD* pGain)
{
	if (NULL == pGain)
		return FALSE;

	DWORD dwGain = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_SS_GAIN_GREEN1, &dwGain);
	if (bResult)
		*pGain = dwGain;

	return bResult;
}

BOOL CGigE::SetGainGreen(const int nIdx, DWORD dwGain)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_SS_GAIN_GREEN1, dwGain);
	return bResult;
}

BOOL CGigE::GetGainGreen2(const int nIdx, DWORD* pGain)
{
	if (NULL == pGain)
		return FALSE;

	DWORD dwGain = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_SS_GAIN_GREEN2, &dwGain);
	if (bResult)
		*pGain = dwGain;

	return bResult;
}

BOOL CGigE::SetGainGreen2(const int nIdx, DWORD dwGain)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_SS_GAIN_GREEN2, dwGain);
	return bResult;
}

BOOL CGigE::GetGainBlue(const int nIdx, DWORD* pGain)
{
	if (NULL == pGain)
		return FALSE;

	DWORD dwGain = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_SS_GAIN_BLUE, &dwGain);
	if (bResult)
		*pGain = dwGain;

	return bResult;
}

BOOL CGigE::SetGainBlue(const int nIdx, DWORD dwGain)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_SS_GAIN_BLUE, dwGain);
	return bResult;
}

BOOL CGigE::GetGainAnalog(const int nIdx, DWORD* pGain)
{
	if (NULL == pGain)
		return FALSE;

	DWORD dwGain = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_SS_GAIN_ANALOG, &dwGain);
	if (bResult)
		*pGain = dwGain;

	return bResult;
}

BOOL CGigE::SetGainAnalog(const int nIdx, DWORD dwGain)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_SS_GAIN_ANALOG, dwGain);
	return bResult;
}


BOOL CGigE::GetAGC(const int nIdx, DWORD* pAgc)
{
	if (NULL == pAgc)
		return FALSE;

	DWORD dwAgc = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_SS_AGC, &dwAgc);
	if (bResult)
		*pAgc = dwAgc;

	return bResult;
}

BOOL CGigE::SetAGC(const int nIdx, DWORD dwAgc)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_SS_AGC, dwAgc);
	return bResult;
}

BOOL CGigE::GetAEC(const int nIdx, DWORD* pAec)
{
	if (NULL == pAec)
		return FALSE;

	DWORD dwAec = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_SS_AEC, &dwAec);
	if (bResult)
		*pAec = dwAec;

	return bResult;
}

BOOL CGigE::SetAEC(const int nIdx, DWORD dwAec)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_SS_AEC, dwAec);
	return bResult;
}

BOOL CGigE::GetExposureTime(const int nIdx, DWORD* pExTime)
{
	if (NULL == pExTime)
		return FALSE;

	DWORD dwTime = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_SS_EXPOSURE_TI, &dwTime);
	if (bResult)
		*pExTime = dwTime;

	return bResult;
}

BOOL CGigE::GetExposureMaxTime(const int nIdx, DWORD* pMaxExTime)
{
	if (NULL == pMaxExTime)
		return FALSE;

	DWORD dwIP = 0;
	BOOL bResult = GetDevicePortHandle(nIdx, &dwIP);
	if (bResult)
	{
		DWORD dwMaxTime = 0;
		int errorcode = EEGetMAXofVID((DEV_HANDLE)dwIP, LP_GIGE_RW_SS_EXPOSURE_TI, (void*)&dwMaxTime);
		if (GC_ERR_SUCCESS == errorcode)
		{
			*pMaxExTime = dwMaxTime;
			bResult = TRUE;
		}
		else
		{
			bResult = FALSE;
		}
	}
	return bResult;
}

BOOL CGigE::GetDiag(const int nIdx, DiagnosticData* pstDiag)
{
	DWORD dwIP = 0;
	
	if (NULL == pstDiag)
		return FALSE;

	BOOL bResult = GetDevicePortHandle(nIdx, &dwIP);
	bResult = GetDiagnosticData((PORT_HANDLE)dwIP, (DiagnosticData*)pstDiag);

	return bResult;
}

BOOL CGigE::SetExposureTime(const int nIdx, DWORD dwExTime)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_SS_EXPOSURE_TI, dwExTime);
	if (bResult)
	{
		BYTE bEnableTrigger = FALSE;
		GetTriggerEnable(nIdx, &bEnableTrigger);

		if (bEnableTrigger)
		{
			const DWORD dwAddr = 0x10000000;
			const DWORD dwData = 0x03;

			bResult = WriteRegAddress(nIdx, dwAddr, dwData);
		}
	}
	return bResult;
}

BOOL CGigE::ConvertExposureTime(const int nIdx, DWORD dwStep, double* pfUsec)
{
	const DEVMODULEINFO* pstModule = GetDeviceModuleInfo(nIdx);

	if (NULL == pstModule || NULL == pfUsec)
		return FALSE;

	TCHAR* pModel = (LPTSTR)(LPCTSTR)pstModule->szModelName;

	TCHAR LPMVC_EE010[] = _T("LPMVC-EE010");
	TCHAR LPMVC_EE120[] = _T("LPMVC-EE120");
	TCHAR LPMVC_EE120C[] = _T("LPMVC-EE120C");
	TCHAR LPMVC_EE030[] = _T("LPMVC-EE030");
	TCHAR LPMVC_EE030C[] = _T("LPMVC-EE030C");
	TCHAR LPMVC_EE400[] = _T("LPMVC-EE400");
	TCHAR LPMVC_EE500[] = _T("LPMVC-EE500");
	TCHAR LPMVC_EE500C[] = _T("LPMVC-EE500C");
	TCHAR LPMVC_EE500X45[] = _T("LPMVC-EE500X45");
	TCHAR LPMVC_EE1R2M54C29[] = _T("LPMVC-EE1R2M54C29");
	TCHAR LPMVC_EE1R2C54C29[] = _T("LPMVC-EE1R2C54C29");
	TCHAR LPMVC_EE0R3M60C29[] = _T("LPMVC-EE0R3M60C29");
	TCHAR LPMVC_EE0R3C60C29[] = _T("LPMVC-EE0R3C60C29");
	TCHAR LPMVC_EE0R3M4FC29[] = _T("LPMVC-EE0R3M4FC29");
	TCHAR LPMVC_EE005M14C29[] = _T("LPMVC-EE005M14C29");
	TCHAR LPMVC_EE005C14C29[] = _T("LPMVC-EE005C14C29");

	
	if (CUtil::StringICompare(pModel, LPMVC_EE500) || 
		CUtil::StringICompare(pModel, LPMVC_EE500C) || 
		CUtil::StringICompare(pModel, LPMVC_EE500X45) || 
		CUtil::StringICompare(pModel, LPMVC_EE005M14C29) ||
		CUtil::StringICompare(pModel, LPMVC_EE005C14C29))
	{
		const double fRow = 36.38f;
		const double fPixClk = 0.01042f;

		DWORD dwSw = dwStep;
		if (1 >= dwSw)
			dwSw = 1;

		DWORD dwBinning = 0;
		GetBinning(nIdx, &dwBinning);
		dwBinning &= 0x03;

		DWORD dwSo = (364 * (dwBinning + 1) + 98 + 166);
		*pfUsec = dwSw * fRow - dwSo * fPixClk * 2;

	}
	else if (CUtil::StringICompare(pModel, LPMVC_EE010))
	{
		*pfUsec = (46.5f * dwStep) + 6.1325f;
	}	
	else if (CUtil::StringICompare(pModel, LPMVC_EE0R3M60C29) || CUtil::StringICompare(pModel, LPMVC_EE0R3C60C29))
	{
		*pfUsec = dwStep * 0.031725f * 1000.f;
	}
	else if (CUtil::StringICompare(pModel, LPMVC_EE0R3M4FC29))
	{
		*pfUsec = dwStep;
	}
	else if (CUtil::StringICompare(pModel, LPMVC_EE1R2M54C29) || CUtil::StringICompare(pModel, LPMVC_EE1R2C54C29))
	{
		*pfUsec = dwStep * 18.69f;
	}
	else if (CUtil::StringICompare(pModel, LPMVC_EE400))
	{
		*pfUsec = dwStep;
	}
	else
	{
		*pfUsec = dwStep * 0.022275f * 1000.f;
	}


	return TRUE;
}



BOOL CGigE::GetEnableFps(const int nIdx, DWORD* pFps)
{
	if (NULL == pFps)
		return FALSE;

	DWORD dwFps = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_FRAME_RATE_EN, &dwFps);
	if (bResult)
		*pFps = dwFps;

	return bResult;
}

BOOL CGigE::SetEnableFps(const int nIdx, DWORD dwFps)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_FRAME_RATE_EN, dwFps);
	return bResult;
}

BOOL CGigE::GetFps(const int nIdx, DWORD* pFps)
{
	if (NULL == pFps)
		return FALSE;

	DWORD dwFps = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_FRAME_RATE, &dwFps);
	if (bResult)
		*pFps = dwFps;

	return bResult;
}

BOOL CGigE::SetFps(const int nIdx, DWORD dwFps)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_FRAME_RATE, dwFps);
	return bResult;
}

BOOL CGigE::GetMaxFps(const int nIdx, DWORD* pFps)
{
	if (NULL == pFps)
		return FALSE;

	DWORD dwFps = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_MAX_FRAME_RATE, &dwFps);
	if (bResult)
		*pFps = dwFps;

	return bResult;
}

BOOL CGigE::GetHBlank(const int nIdx, DWORD* pBlank)
{
	if (NULL == pBlank)
		return FALSE;

	DWORD dwBlank = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_SS_HBLANK, &dwBlank);
	if (bResult)
		*pBlank = dwBlank;

	return bResult;
}

BOOL CGigE::SetHBlank(const int nIdx, DWORD dwBlank)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_SS_HBLANK, dwBlank);
	return bResult;
}

BOOL CGigE::GetVBlank(const int nIdx, DWORD* pBlank)
{
	if (NULL == pBlank)
		return FALSE;

	DWORD dwBlank = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_SS_VBLANK, &dwBlank);
	if (bResult)
		*pBlank = dwBlank;

	return bResult;
}

BOOL CGigE::SetVBlank(const int nIdx, DWORD dwBlank)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_SS_VBLANK, dwBlank);
	return bResult;
}

BOOL CGigE::GetMirror(const int nIdx, DWORD* pValue)
{
	if (NULL == pValue)
		return FALSE;

	DWORD dwMirror = 0;
	
	//
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_SS_MIRROR_COL, &dwMirror);
	if (FALSE == bResult)
		return FALSE;

	if (dwMirror & 0x01)
		*pValue = 0x01;
	
	//
	bResult = ReadRegAddress(nIdx, LP_GIGE_RW_SS_MIRROR_ROW, &dwMirror);
	if (FALSE == bResult)
		return FALSE;

	if (dwMirror & 0x01)
		*pValue |= 0x02;

	return bResult;
}

BOOL CGigE::SetMirror(const int nIdx, DWORD dwValue)
{
	DWORD dwMirror = 0;
	if (dwValue & 0x01)
		dwMirror = 1;
	
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_SS_MIRROR_COL, dwMirror);
	if (FALSE == bResult)
		return FALSE;

	dwMirror = 0;
	if (dwValue & 0x02)
		dwMirror = 1;

	bResult = WriteRegAddress(nIdx, LP_GIGE_RW_SS_MIRROR_ROW, dwMirror);
	if (FALSE == bResult)
		return FALSE;

	return bResult;

}

BOOL CGigE::ProcessWB(BYTE* pImg, DWORD dwWidth, DWORD dwHeight, BYTE nRed, BYTE nGreen, BYTE nBlue)
{
	TL_WB_GAIN stGAin;
	stGAin.RGain = nRed;
	stGAin.GGain = nGreen;
	stGAin.BGain = nBlue;

	int nErrCode = EEProcessWB(pImg, dwWidth, dwHeight, &stGAin);
	if (GC_ERR_SUCCESS != nErrCode)
		return FALSE;

	return TRUE;
}

BOOL CGigE::ProcessAWB(BYTE* pImg, DWORD dwWidth, DWORD dwHeight)
{
	int nErrCode = EEProcessAWB(pImg, dwWidth, dwHeight);
	if (GC_ERR_SUCCESS != nErrCode)
		return FALSE;

	return TRUE;
}

BOOL CGigE::GetAWB(const int nIdx, BOOL* pOn)
{
	if (NULL == pOn)
		return FALSE;

	DWORD dwOn = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_HW_AWB_EN, &dwOn);
	if (bResult)
		*pOn = dwOn;

	return bResult;
}

BOOL CGigE::SetAWB(const int nIdx, BOOL bOn)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_HW_AWB_EN, bOn);
	return bResult;
}

BOOL CGigE::GetMinVID(const int nIdx, DWORD VID, DWORD* pMin)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || NULL == pMin)
		return FALSE;

	DWORD dwValue = 0;

	DWORD dwIP = 0;
	BOOL bResult = GetDevicePortHandle(nIdx, &dwIP);
	if (FALSE == bResult)
		return FALSE;

	int nErrCode = EEGetMINofVID((DEV_HANDLE)dwIP, VID, (void*)&dwValue);
	if (GC_ERR_SUCCESS == nErrCode)
	{
		bResult = TRUE;
		*pMin = dwValue;
	}
	else
	{
		bResult = FALSE;
	}

	return bResult;
}

BOOL CGigE::GetMaxVID(const int nIdx, DWORD VID, DWORD* pMax)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || NULL == pMax)
		return FALSE;

	DWORD dwValue = 0;

	DWORD dwIP = 0;
	BOOL bResult = GetDevicePortHandle(nIdx, &dwIP);
	if (FALSE == bResult)
		return FALSE;

	int nErrCode = EEGetMAXofVID((DEV_HANDLE)dwIP, VID, (void*)&dwValue);
	if (GC_ERR_SUCCESS == nErrCode)
	{
		bResult = TRUE;
		*pMax = dwValue;
	}
	else
	{
		bResult = FALSE;
	}

	return bResult;
}

// Userset
BOOL CGigE::LoadDefaultUserset(const int nIdx)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount )
		return FALSE;

	DWORD dwValue = 0;

	DWORD dwIP = 0;
	BOOL bResult = GetDevicePortHandle(nIdx, &dwIP);
	if (FALSE == bResult)
		return FALSE;

	int nErrCode = EEDefaultDeviceSetting((DEV_HANDLE)dwIP);
	if (GC_ERR_SUCCESS == nErrCode)
		bResult = TRUE;
	else
		bResult = FALSE;

	return bResult;
}


BOOL CGigE::GetBoostUserset(const int nIdx, DWORD* pdwBoost)
{
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_NUM_USERSET, pdwBoost);
	return bResult;
}

BOOL CGigE::SetBoostUserset(const int nIdx, DWORD dwBoost)
{
	BOOL bResult = FALSE;

	bResult = WriteRegAddress(nIdx, LP_GIGE_RW_NUM_USERSET, dwBoost);
	if (bResult)
		bResult = WriteRegAddress(nIdx, LP_GIGE_WO_START_USERSET, dwBoost);
	return bResult;
}


BOOL CGigE::LoadUserset(const int nIdx, DWORD dwUserset)
{
	BOOL bResult = FALSE;

	bResult = WriteRegAddress(nIdx, LP_GIGE_RW_NUM_USERSET, dwUserset);
	if (bResult)
	{
		DWORD dwFlag = 1;
		bResult = WriteRegAddress(nIdx, LP_GIGE_WO_LOAD_USERSET, dwFlag);
	}
	return bResult;
}

BOOL CGigE::SaveUserset(const int nIdx, DWORD dwUserset)
{
	BOOL bResult =TRUE;

	int nIdxUserset = (int)dwUserset;

	if (0 <= nIdxUserset)
		bResult = WriteRegAddress(nIdx, LP_GIGE_RW_NUM_USERSET, nIdxUserset);
	if (bResult)
		bResult = WriteRegAddress(nIdx, LP_GIGE_WO_SAVE_USERSET, 1);
	return bResult;
}

BOOL CGigE::GetUserset(const int nIdx, DWORD* pUserset)
{
	if (NULL == pUserset)
		return FALSE;

	DWORD dwUserset = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_NUM_USERSET, &dwUserset);
	if (bResult)
		*pUserset = dwUserset;

	return bResult;
}

BOOL CGigE::SetUserset(const int nIdx, DWORD dwUserset)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_NUM_USERSET, dwUserset);
	return bResult;
}

BOOL CGigE::GetDPC(const int nIdx, DWORD* pDpc)
{
	if (NULL == pDpc)
		return FALSE;

	DWORD dwDpc = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_COLOR_ENHANCEMENT_DPC_EN, &dwDpc);
	if (bResult)
		*pDpc = dwDpc;

	return bResult;
}

BOOL CGigE::SetDPC(const int nIdx, DWORD dwDpc)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_COLOR_ENHANCEMENT_DPC_EN, dwDpc);
	return bResult;
}

BOOL CGigE::GetPRNU(const int nIdx, DWORD* pPrnu)
{
	if (NULL == pPrnu)
		return FALSE;

	DWORD dwPrnu = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_COLOR_ENHANCEMENT_PRNU_EN, &dwPrnu);
	if (bResult)
		*pPrnu = dwPrnu;

	return bResult;
}

BOOL CGigE::SetPRNU(const int nIdx, DWORD dwPrnu)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_COLOR_ENHANCEMENT_PRNU_EN, dwPrnu);
	return bResult;
}

BOOL CGigE::GetLPF(const int nIdx, DWORD* pLpf)
{
	if (NULL == pLpf)
		return FALSE;

	DWORD dwLpf = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_COLOR_ENHANCEMENT_LPF_EN, &dwLpf);
	if (bResult)
		*pLpf = dwLpf;

	return bResult;
}

BOOL CGigE::SetLPF(const int nIdx, DWORD dwLpf)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_COLOR_ENHANCEMENT_LPF_EN, dwLpf);
	return bResult;
}

BOOL CGigE::GetColorMatrix(const int nIdx, DWORD* pColorMatrix)
{
	if (NULL == pColorMatrix)
		return FALSE;

	DWORD dwColorMatrix = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_COLOR_ENHANCEMENT_CM_EN, &dwColorMatrix);
	if (bResult)
		*pColorMatrix = dwColorMatrix;

	return bResult;
}

BOOL CGigE::SetColorMatrix(const int nIdx, DWORD dwColorMatrix)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_COLOR_ENHANCEMENT_CM_EN, dwColorMatrix);
	return bResult;
}

BOOL CGigE::GetGamma(const int nIdx, DWORD* pGamma)
{
	if (NULL == pGamma)
		return FALSE;

	DWORD dwGamma = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_COLOR_ENHANCEMENT_GM_EN, &dwGamma);
	if (bResult)
		*pGamma = dwGamma;

	return bResult;
}

BOOL CGigE::SetGamma(const int nIdx, DWORD dwGamma)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_COLOR_ENHANCEMENT_GM_EN, dwGamma);
	return bResult;
}

BOOL CGigE::GetGammaTable(const int nIdx, DWORD* pTable)
{
	if (NULL == pTable)
		return FALSE;

	DWORD dwTable = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_GAMMA_TABLE_NUM, &dwTable);
	if (bResult)
		*pTable = dwTable;

	return bResult;
}

BOOL CGigE::SetGammaTable(const int nIdx, DWORD dwTable)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_GAMMA_TABLE_NUM, dwTable);
	return bResult;
}

BOOL CGigE::GetLUT(const int nIdx, DWORD* pLut)
{
	if (NULL == pLut)
		return FALSE;

	DWORD dwTable = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_COLOR_ENHANCEMENT_LUT_EN, &dwTable);
	if (bResult)
		*pLut = dwTable;

	return bResult;
}

BOOL CGigE::SetLUT(const int nIdx, DWORD dwLut)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_COLOR_ENHANCEMENT_LUT_EN, dwLut);
	return bResult;
}

BOOL CGigE::GetLUTTable(const int nIdx, DWORD* pTable)
{
	if (NULL == pTable)
		return FALSE;

	DWORD dwTable = 0;
	BOOL bResult = ReadRegAddress(nIdx, LP_GIGE_RW_COLOR_LUT_TABLE_NUM, &dwTable);
	if (bResult)
		*pTable = dwTable;

	return bResult;
}

BOOL CGigE::SetLUTTable(const int nIdx, DWORD dwTable)
{
	BOOL bResult = WriteRegAddress(nIdx, LP_GIGE_RW_COLOR_LUT_TABLE_NUM, dwTable);
	return bResult;
}

BOOL CGigE::GetLUTData(const int nIdx, int nLutIdx, BYTE* pData, int nLen)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || NULL == pData )
		return FALSE;

	DWORD dwIP = 0;
	BOOL bResult = GetDevicePortHandle(nIdx, &dwIP);
	if (FALSE == bResult)
		return FALSE;

	int nErrCode = EEGetLUTData((DEV_HANDLE)dwIP, nLutIdx, pData);
	if (GC_ERR_SUCCESS == nErrCode)
		bResult = TRUE;
	else
		bResult = FALSE;

	return bResult;
}

BOOL CGigE::SetLUTData(const int nIdx, BYTE* pData, int nLen)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || NULL == pData)
		return FALSE;

	DWORD dwIP = 0;
	BOOL bResult = GetDevicePortHandle(nIdx, &dwIP);
	if (FALSE == bResult)
		return FALSE;

	int nErrCode = EESetUserLUTData((DEV_HANDLE)dwIP, pData);
	if (GC_ERR_SUCCESS == nErrCode)
		bResult = TRUE;
	else
		bResult = FALSE;

	return bResult;
}
