#include "StdAfx.h"
#include "CameraInterfaceBasler.h"

#include "Connect/Transport/SdkBasler.h"

HBASLER OpenBasler()
{
	HBASLER hBasler = NULL;

	CSdkBasler* pSdkBasler = new CSdkBasler();
	if (pSdkBasler && pSdkBasler->Open())
	{
		hBasler = pSdkBasler;
	}
	else
	{
		delete pSdkBasler;
	}
	return hBasler;
}
 void CloseBasler(HBASLER hBalser)
 {
	 if (NULL == hBalser)
		 return;

	 CSdkBasler* pSdkBasler = (CSdkBasler*)hBalser;

	 pSdkBasler->Close();
	 delete pSdkBasler;
 }

BOOL StartBasler(HBASLER hBalser, int nIdx)
{
	if (NULL == hBalser)
		return FALSE;

	CSdkBasler* pSdkBasler = (CSdkBasler*)hBalser;

	BOOL bResult = pSdkBasler->Start(nIdx);
	return bResult;
}
void StopBasler(HBASLER hBalser, int nIdx)
{
	if (NULL == hBalser)
		return ;

	CSdkBasler* pSdkBasler = (CSdkBasler*)hBalser;
	pSdkBasler->Stop(nIdx);
}

BOOL SearchBasler(HBASLER hBalser)
{
	if (NULL == hBalser)
		return FALSE;

	CSdkBasler* pSdkBasler = (CSdkBasler*)hBalser;

	BOOL bResult = pSdkBasler->FindAllDevice();;
	return bResult;
}
const int GetCountBasler(HBASLER hBalser)
{
	if (NULL == hBalser)
		return -1;

	CSdkBasler* pSdkBasler = (CSdkBasler*)hBalser;

	int nCount = pSdkBasler->GetEnableDeviceCount();
	return nCount;
}

BOOL IsGigEBasler(HBASLER hBalser, int nIdx)
{
	if (NULL == hBalser)
		return FALSE;

	CSdkBasler* pSdkBasler = (CSdkBasler*)hBalser;

	BOOL bResult = pSdkBasler->IsGigE(nIdx);
	return bResult;
}
BOOL IsUsbBasler(HBASLER hBalser, int nIdx)
{
	if (NULL == hBalser)
		return FALSE;

	CSdkBasler* pSdkBasler = (CSdkBasler*)hBalser;

	BOOL bResult = pSdkBasler->IsUsb(nIdx);
	return bResult;
}

DWORD GetIpAddressBasler(HBASLER hBalser, int nIdx)
{
	if (NULL == hBalser)
		return FALSE;

	CSdkBasler* pSdkBasler = (CSdkBasler*)hBalser;
	DWORD dwIpAddr = pSdkBasler->GetIpAddress(nIdx);
	return dwIpAddr;
}

BOOL SetEventFuncBasler(HBASLER hBalser, const int nIdx, FuncAcquisitionEvent pFunc, void* pUserData)
{
	if (NULL == hBalser)
		return FALSE;

	CSdkBasler* pSdkBasler = (CSdkBasler*)hBalser;

	BOOL bResult = pSdkBasler->SetEventFunc(nIdx, pFunc, pUserData);
	return bResult;
}

BOOL GetCameraInformationBasler(HBASLER hBalser, const int nIdx, INFO_OTHER_CATEGORY* pstRootCategory)
{
	if (NULL == hBalser)
		return FALSE;

	CSdkBasler* pSdkBasler = (CSdkBasler*)hBalser;

	BOOL bResult = pSdkBasler->GetCameraInformation(nIdx, pstRootCategory);
	return bResult;
}

const INFO_OTHER_IF* GetCameraInfoFromNameBasler(HBASLER hBalser, const int nIdx, const TCHAR* pszName)
{
	if (NULL == hBalser)
		return NULL;

	CSdkBasler* pSdkBasler = (CSdkBasler*)hBalser;

	const INFO_OTHER_IF* pOther = pSdkBasler->GetCameraInformation(nIdx, pszName);
	return pOther;
}

BOOL GetCameraValueBasler(HBASLER hBalser, const int nIdx, const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue)
{
	if (NULL == hBalser)
		return FALSE;

	CSdkBasler* pSdkBasler = (CSdkBasler*)hBalser;

	BOOL bResult = pSdkBasler->GetCameraValue(nIdx, pstInfo, pstValue);
	return bResult;
}

BOOL SetCameraValueBasler(HBASLER hBalser, const int nIdx, const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue)
{
	if (NULL == hBalser)
		return FALSE;

	CSdkBasler* pSdkBasler = (CSdkBasler*)hBalser;

	BOOL bResult = pSdkBasler->SetCameraValue(nIdx, pstInfo, pstValue);
	return bResult;
}