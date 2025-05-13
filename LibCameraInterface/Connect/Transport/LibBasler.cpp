#include "StdAfx.h"
#include "LibBasler.h"

#include "Util/Util.h"


CLibBasler::CLibBasler()
{
	// Function Pointer
	pFuncOpenBasler = NULL;
	pFuncCloseBasler = NULL;

	pFuncStartBasler = NULL;
	pFuncStopBasler = NULL;

	pFuncSearchBasler = NULL;
	pFuncGetCountBasler = NULL;

	pFuncIsGigEBasler = NULL;
	pFuncIsUsbBasler = NULL;

	pFuncGetIpAddressBasler = NULL;

	pFuncSetEventFuncBasler = NULL;

	pFuncGetCameraInformationBasler = NULL;
	pFuncGetCameraInfoFromNameBasler = NULL;

	pFuncGetCameraValueBasler = NULL;
	pFuncSetCameraValueBasler = NULL;


	// Handle
	m_hInstance = NULL;
	m_hBasler = NULL;

}

CLibBasler::~CLibBasler()
{
}

BOOL CLibBasler::Open()
{
	BOOL bResult = FALSE;

	TCHAR szLocation[MAX_PATH] = { 0, };
	CUtil::GetCurrentDirectory(szLocation, MAX_PATH);

	TCHAR szDllPath[MAX_PATH] = { 0, };
#ifdef _WIN64
	CUtil::StringFormat(szDllPath, MAX_PATH, _T("%s\\%s"), szLocation, DLL_MODULE64);
#else
	CUtil::StringFormat(szDllPath, MAX_PATH, _T("%s\\%s"), szLocation, DLL_MODULE);
#endif

	m_hInstance = ::LoadLibrary(szDllPath);

	if (m_hInstance)
	{
		pFuncOpenBasler = (HBASLER(*)())::GetProcAddress(m_hInstance, _T("OpenBasler"));
		pFuncCloseBasler = (void(*)(HBASLER))::GetProcAddress(m_hInstance, _T("CloseBasler"));

		pFuncStartBasler = (BOOL(*)(HBASLER, int))::GetProcAddress(m_hInstance, _T("StartBasler"));
		pFuncStopBasler = (void(*)(HBASLER, int))::GetProcAddress(m_hInstance, _T("StopBasler"));

		pFuncSearchBasler = (BOOL(*)(HBASLER))::GetProcAddress(m_hInstance, _T("SearchBasler"));
		pFuncGetCountBasler = (const int(*)(HBASLER))::GetProcAddress(m_hInstance, _T("GetCountBasler"));

		pFuncIsGigEBasler = (BOOL(*)(HBASLER, int))::GetProcAddress(m_hInstance, _T("IsGigEBasler"));
		pFuncIsUsbBasler = (BOOL(*)(HBASLER, int))::GetProcAddress(m_hInstance, _T("IsUsbBasler"));

		pFuncGetIpAddressBasler = (DWORD(*)(HBASLER, int))::GetProcAddress(m_hInstance, _T("GetIpAddressBasler"));

		pFuncSetEventFuncBasler = (BOOL(*)(HBASLER, const int, FuncAcquisitionEvent, void*))::GetProcAddress(m_hInstance, _T("SetEventFuncBasler"));

		pFuncGetCameraInformationBasler = (BOOL(*)(HBASLER, const int, INFO_OTHER_CATEGORY*))::GetProcAddress(m_hInstance, _T("GetCameraInformationBasler"));
		pFuncGetCameraInfoFromNameBasler = (const INFO_OTHER_IF* (*)(HBASLER, const int, const TCHAR*))::GetProcAddress(m_hInstance, _T("GetCameraInfoFromNameBasler"));

		pFuncGetCameraValueBasler = (BOOL(*)(HBASLER, const int, const INFO_OTHER_IF*, VALUE_OTHER*))::GetProcAddress(m_hInstance, _T("GetCameraValueBasler"));
		pFuncSetCameraValueBasler = (BOOL(*)(HBASLER, const int, const INFO_OTHER_IF*, VALUE_OTHER*))::GetProcAddress(m_hInstance, _T("SetCameraValueBasler"));

		if (NULL == pFuncOpenBasler || NULL == pFuncCloseBasler ||
			NULL == pFuncStartBasler || NULL == pFuncStopBasler ||
			NULL == pFuncSearchBasler || NULL == pFuncGetCountBasler ||
			NULL == pFuncIsGigEBasler || NULL == pFuncIsUsbBasler || NULL == pFuncSetEventFuncBasler ||

			NULL == pFuncGetCameraInformationBasler || NULL == pFuncGetCameraInfoFromNameBasler ||
			NULL == pFuncGetCameraValueBasler || NULL == pFuncSetCameraValueBasler)
		{
			bResult = FALSE;
		}
		else
		{
			m_hBasler = (*pFuncOpenBasler)();
			if (m_hBasler)
				bResult = TRUE;
			else
				bResult = FALSE;
		}
	}

	if (FALSE == bResult)
		this->Close();

	return bResult;
}

void CLibBasler::Close()
{
	if (pFuncCloseBasler && m_hBasler)
		(*pFuncCloseBasler)(m_hBasler);
	m_hBasler = NULL;

	::FreeLibrary(m_hInstance);
	m_hInstance = NULL;


	// Function Pointer
	pFuncOpenBasler = NULL;
	pFuncCloseBasler = NULL;

	pFuncStartBasler = NULL;
	pFuncStopBasler = NULL;

	pFuncSearchBasler = NULL;
	pFuncGetCountBasler = NULL;

	pFuncIsGigEBasler = NULL;
	pFuncIsUsbBasler = NULL;

	pFuncSetEventFuncBasler = NULL;

	pFuncGetCameraInformationBasler = NULL;
	pFuncGetCameraInfoFromNameBasler = NULL;

	pFuncGetCameraValueBasler = NULL;
	pFuncSetCameraValueBasler = NULL;
}

BOOL CLibBasler::IsOpen()
{
	BOOL bResult = FALSE;

	if (m_hInstance && m_hBasler)
		bResult = TRUE;
	return bResult;
}

BOOL CLibBasler::Start(int nIdx)
{
	BOOL bResult = FALSE;
	if (pFuncStartBasler)
		bResult = (*pFuncStartBasler)(m_hBasler, nIdx);
	return bResult;
}

void CLibBasler::Stop(int nIdx)
{
	if (pFuncStopBasler)
		(*pFuncStopBasler)(m_hBasler, nIdx);
}

BOOL CLibBasler::FindAllDevice()
{
	BOOL bResult = FALSE;
	if (pFuncSearchBasler)
		bResult = (*pFuncSearchBasler)(m_hBasler);
	return bResult;
}

const int CLibBasler::GetEnableDeviceCount()
{
	int nCount = -1;
	if (pFuncGetCountBasler)
		nCount = (*pFuncGetCountBasler)(m_hBasler);
	return nCount;
}

BOOL CLibBasler::IsGigE(int nIdx)
{
	BOOL bResult = FALSE;
	if (pFuncIsGigEBasler)
		bResult = (*pFuncIsGigEBasler)(m_hBasler, nIdx);
	return bResult;
}

BOOL CLibBasler::IsUsb(int nIdx)
{
	BOOL bResult = FALSE;
	if (pFuncIsUsbBasler)
		bResult = (*pFuncIsUsbBasler)(m_hBasler, nIdx);
	return bResult;
}

BOOL CLibBasler::GetModel(int nIdx, TCHAR* pValue)
{
	BOOL bResult = FALSE;
	if (pFuncGetCameraValueBasler)
	{
		INFO_OTHER_STRING stInfo;
		memset(&stInfo, 0x00, sizeof(INFO_OTHER_STRING));
		stInfo.m_stInterface.m_eInterface = TYPE_OTHER_INTERFACE_STRING;
		stInfo.m_stInterface.m_dwAccess = OTHER_OPCODE_READ;
		stInfo.m_stInterface.m_pszName = _T("DeviceModelName");

		VALUE_OTHER_STRING stValue;
		memset(&stValue, 0x00, sizeof(VALUE_OTHER_STRING));
		stValue.m_stInterfae.m_eInterface = TYPE_OTHER_INTERFACE_STRING;

		bResult = (*pFuncGetCameraValueBasler)(m_hBasler, nIdx, (INFO_OTHER_IF*)&stInfo, (VALUE_OTHER*)&stValue);
		if (bResult && stValue.m_pValue)
		{
			CUtil::StringCopy(pValue, stValue.m_pValue);
			delete[] stValue.m_pValue;
		}

	}
	return bResult;
}

BOOL CLibBasler::GetSerialNumber(int nIdx, TCHAR* pValue)
{
	BOOL bResult = FALSE;
	if (pFuncGetCameraValueBasler)
	{
		INFO_OTHER_STRING stInfo;
		memset(&stInfo, 0x00, sizeof(INFO_OTHER_STRING));
		stInfo.m_stInterface.m_eInterface = TYPE_OTHER_INTERFACE_STRING;
		stInfo.m_stInterface.m_dwAccess = OTHER_OPCODE_READ;
		stInfo.m_stInterface.m_pszName = _T("DeviceID");

		VALUE_OTHER_STRING stValue;
		memset(&stValue, 0x00, sizeof(VALUE_OTHER_STRING));
		stValue.m_stInterfae.m_eInterface = TYPE_OTHER_INTERFACE_STRING;

		bResult = (*pFuncGetCameraValueBasler)(m_hBasler, nIdx, (INFO_OTHER_IF*)&stInfo, (VALUE_OTHER*)&stValue);
		if (bResult && stValue.m_pValue)
		{
			CUtil::StringCopy(pValue, stValue.m_pValue);
			delete[] stValue.m_pValue;
		}

	}
	return bResult;
}

BOOL CLibBasler::GetVendor(int nIdx, TCHAR* pValue)
{
	BOOL bResult = FALSE;
	if (pFuncGetCameraValueBasler)
	{
		INFO_OTHER_STRING stInfo;
		memset(&stInfo, 0x00, sizeof(INFO_OTHER_STRING));
		stInfo.m_stInterface.m_eInterface = TYPE_OTHER_INTERFACE_STRING;
		stInfo.m_stInterface.m_dwAccess = OTHER_OPCODE_READ;
		stInfo.m_stInterface.m_pszName = _T("DeviceVendorName");

		VALUE_OTHER_STRING stValue;
		memset(&stValue, 0x00, sizeof(VALUE_OTHER_STRING));
		stValue.m_stInterfae.m_eInterface = TYPE_OTHER_INTERFACE_STRING;

		bResult = (*pFuncGetCameraValueBasler)(m_hBasler, nIdx, (INFO_OTHER_IF*)&stInfo, (VALUE_OTHER*)&stValue);
		if (bResult && stValue.m_pValue)
		{
			CUtil::StringCopy(pValue, stValue.m_pValue);
			delete[] stValue.m_pValue;
		}

	}
	return bResult;
}

const DWORD CLibBasler::GetIpAddress(int nIdx)
{
	DWORD dwIpAddr = 0;

	if(pFuncGetIpAddressBasler)
		dwIpAddr = (*pFuncGetIpAddressBasler)(m_hBasler, nIdx);
	return dwIpAddr;
}

//
BOOL CLibBasler::GetMaxWidth(const int nIdx, DWORD* pdwValue)
{
	BOOL bResult = FALSE;
	if (pFuncGetCameraValueBasler)
	{
		INFO_OTHER_INTEGER stInfo;
		memset(&stInfo, 0x00, sizeof(INFO_OTHER_INTEGER));
		stInfo.m_stInterface.m_eInterface = TYPE_OTHER_INTERFACE_INTEGER;
		stInfo.m_stInterface.m_dwAccess = OTHER_OPCODE_READ;
		stInfo.m_stInterface.m_pszName = _T("WidthMax");

		VALUE_OTHER_INTEGER stValue;
		memset(&stValue, 0x00, sizeof(VALUE_OTHER_INTEGER));
		stValue.m_stInterfae.m_eInterface = TYPE_OTHER_INTERFACE_INTEGER;

		bResult = (*pFuncGetCameraValueBasler)(m_hBasler, nIdx, (INFO_OTHER_IF*)&stInfo, (VALUE_OTHER*)&stValue);
		if (bResult && pdwValue)
		{
			*pdwValue = stValue.m_nValue;
		}
	}
	return bResult;
}
BOOL CLibBasler::GetMaxHeight(const int nIdx, DWORD* pdwValue)
{
	BOOL bResult = FALSE;
	if (pFuncGetCameraValueBasler)
	{
		INFO_OTHER_INTEGER stInfo;
		memset(&stInfo, 0x00, sizeof(INFO_OTHER_INTEGER));
		stInfo.m_stInterface.m_eInterface = TYPE_OTHER_INTERFACE_INTEGER;
		stInfo.m_stInterface.m_dwAccess = OTHER_OPCODE_READ;
		stInfo.m_stInterface.m_pszName = _T("HeightMax");

		VALUE_OTHER_INTEGER stValue;
		memset(&stValue, 0x00, sizeof(VALUE_OTHER_INTEGER));
		stValue.m_stInterfae.m_eInterface = TYPE_OTHER_INTERFACE_INTEGER;

		bResult = (*pFuncGetCameraValueBasler)(m_hBasler, nIdx, (INFO_OTHER_IF*)&stInfo, (VALUE_OTHER*)&stValue);
		if (bResult && pdwValue)
		{
			*pdwValue = stValue.m_nValue;
		}
	}
	return bResult;
}

BOOL CLibBasler::GetX(const int nIdx, DWORD* pdwValue)
{
	BOOL bResult = FALSE;
	if (pFuncGetCameraValueBasler)
	{
		INFO_OTHER_INTEGER stInfo;
		memset(&stInfo, 0x00, sizeof(INFO_OTHER_INTEGER));
		stInfo.m_stInterface.m_eInterface = TYPE_OTHER_INTERFACE_INTEGER;
		stInfo.m_stInterface.m_dwAccess = OTHER_OPCODE_READ;
		stInfo.m_stInterface.m_pszName = _T("OffsetX");

		VALUE_OTHER_INTEGER stValue;
		memset(&stValue, 0x00, sizeof(VALUE_OTHER_INTEGER));
		stValue.m_stInterfae.m_eInterface = TYPE_OTHER_INTERFACE_INTEGER;

		bResult = (*pFuncGetCameraValueBasler)(m_hBasler, nIdx, (INFO_OTHER_IF*)&stInfo, (VALUE_OTHER*)&stValue);
		if (bResult && pdwValue)
		{
			*pdwValue = stValue.m_nValue;
		}
	}
	return bResult;
}
BOOL CLibBasler::GetY(const int nIdx, DWORD* pdwValue)
{
	BOOL bResult = FALSE;
	if (pFuncGetCameraValueBasler)
	{
		INFO_OTHER_INTEGER stInfo;
		memset(&stInfo, 0x00, sizeof(INFO_OTHER_INTEGER));
		stInfo.m_stInterface.m_eInterface = TYPE_OTHER_INTERFACE_INTEGER;
		stInfo.m_stInterface.m_dwAccess = OTHER_OPCODE_READ;
		stInfo.m_stInterface.m_pszName = _T("OffsetY");

		VALUE_OTHER_INTEGER stValue;
		memset(&stValue, 0x00, sizeof(VALUE_OTHER_INTEGER));
		stValue.m_stInterfae.m_eInterface = TYPE_OTHER_INTERFACE_INTEGER;

		bResult = (*pFuncGetCameraValueBasler)(m_hBasler, nIdx, (INFO_OTHER_IF*)&stInfo, (VALUE_OTHER*)&stValue);
		if (bResult && pdwValue)
		{
			*pdwValue = stValue.m_nValue;
		}
	}
	return bResult;
}
BOOL CLibBasler::GetWidth(const int nIdx, DWORD* pdwValue)
{
	BOOL bResult = FALSE;
	if (pFuncGetCameraValueBasler)
	{
		INFO_OTHER_INTEGER stInfo;
		memset(&stInfo, 0x00, sizeof(INFO_OTHER_INTEGER));
		stInfo.m_stInterface.m_eInterface = TYPE_OTHER_INTERFACE_INTEGER;
		stInfo.m_stInterface.m_dwAccess = OTHER_OPCODE_READ;
		stInfo.m_stInterface.m_pszName = _T("Width");

		VALUE_OTHER_INTEGER stValue;
		memset(&stValue, 0x00, sizeof(VALUE_OTHER_INTEGER));
		stValue.m_stInterfae.m_eInterface = TYPE_OTHER_INTERFACE_INTEGER;

		bResult = (*pFuncGetCameraValueBasler)(m_hBasler, nIdx, (INFO_OTHER_IF*)&stInfo, (VALUE_OTHER*)&stValue);
		if (bResult && pdwValue)
		{
			*pdwValue = stValue.m_nValue;
		}
	}
	return bResult;
}
BOOL CLibBasler::GetHeight(const int nIdx, DWORD* pdwValue)
{
	BOOL bResult = FALSE;
	if (pFuncGetCameraValueBasler)
	{
		INFO_OTHER_INTEGER stInfo;
		memset(&stInfo, 0x00, sizeof(INFO_OTHER_INTEGER));
		stInfo.m_stInterface.m_eInterface = TYPE_OTHER_INTERFACE_INTEGER;
		stInfo.m_stInterface.m_dwAccess = OTHER_OPCODE_READ;
		stInfo.m_stInterface.m_pszName = _T("Height");

		VALUE_OTHER_INTEGER stValue;
		memset(&stValue, 0x00, sizeof(VALUE_OTHER_INTEGER));
		stValue.m_stInterfae.m_eInterface = TYPE_OTHER_INTERFACE_INTEGER;

		bResult = (*pFuncGetCameraValueBasler)(m_hBasler, nIdx, (INFO_OTHER_IF*)&stInfo, (VALUE_OTHER*)&stValue);
		if (bResult && pdwValue)
		{
			*pdwValue = stValue.m_nValue;
		}
	}
	return bResult;
}

BOOL CLibBasler::GetPixelFormat(const int nIdx, DWORD* pdwValue)
{
	BOOL bResult = FALSE;
	if (pFuncGetCameraValueBasler)
	{
		INFO_OTHER_ENUM stInfo;
		memset(&stInfo, 0x00, sizeof(INFO_OTHER_ENUM));
		stInfo.m_stInterface.m_eInterface = TYPE_OTHER_INTERFACE_ENUM;
		stInfo.m_stInterface.m_dwAccess = OTHER_OPCODE_READ;
		stInfo.m_stInterface.m_pszName = _T("PixelFormat");

		VALUE_OTHER_ENUM stValue;
		memset(&stValue, 0x00, sizeof(VALUE_OTHER_ENUM));
		stValue.m_stInterfae.m_eInterface = TYPE_OTHER_INTERFACE_ENUM;

		bResult = (*pFuncGetCameraValueBasler)(m_hBasler, nIdx, (INFO_OTHER_IF*)&stInfo, (VALUE_OTHER*)&stValue);
		if (bResult && pdwValue)
		{
			*pdwValue = stValue.m_dwValue;
		}
	}
	return bResult;
}

BOOL CLibBasler::SetEventFunc(const int nIdx, FuncAcquisitionEvent pFunc, void* pUserData)
{
	BOOL bResult = FALSE;
	if (pFuncSetEventFuncBasler)
		bResult = (*pFuncSetEventFuncBasler)(m_hBasler, nIdx, pFunc, pUserData);
	return bResult;
}



BOOL CLibBasler::GetCameraInformation(const int nIdx, INFO_OTHER_CATEGORY* pstRootCategory)
{
	BOOL bResult = FALSE;
	if (pFuncGetCameraInformationBasler)
		bResult = (*pFuncGetCameraInformationBasler)(m_hBasler, nIdx, pstRootCategory);
	return bResult;
}

const INFO_OTHER_IF* CLibBasler::GetCameraInformation(const int nIdx, const TCHAR* szName)
{
	INFO_OTHER_IF* pOther = NULL;
	if (pFuncGetCameraInfoFromNameBasler)
		pOther = (INFO_OTHER_IF*)(*pFuncGetCameraInfoFromNameBasler)(m_hBasler, nIdx, szName);
	return pOther;
}


BOOL CLibBasler::GetCameraValue(const int nIdx, const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue)
{
	BOOL bResult = FALSE;
	if (pFuncGetCameraValueBasler)
		bResult = (*pFuncGetCameraValueBasler)(m_hBasler, nIdx, pstInfo, pstValue);
	return bResult;
}

BOOL CLibBasler::SetCameraValue(const int nIdx, const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue)
{
	BOOL bResult = FALSE;
	if (pFuncSetCameraValueBasler)
		bResult = (*pFuncSetCameraValueBasler)(m_hBasler, nIdx, pstInfo, pstValue);
	return bResult;
}
