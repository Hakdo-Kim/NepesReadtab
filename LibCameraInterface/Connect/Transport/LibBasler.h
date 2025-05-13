#pragma once

#include "CameraInterfaceDef.h"
#include "Basler/CameraInterfaceBasler.h"

class CLibBasler
{
public:
	CLibBasler();
	~CLibBasler();

	BOOL Open();
	void Close();
	BOOL IsOpen();

	BOOL Start(int nIdx);
	void Stop(int nIdx);

	// Device Information
	BOOL FindAllDevice();
	const int GetEnableDeviceCount();

	BOOL IsGigE(int nIdx);
	BOOL IsUsb(int nIdx);

	BOOL GetModel(int nIdx, TCHAR* pValue);
	BOOL GetSerialNumber(int nIdx, TCHAR* pValue);
	BOOL GetVendor(int nIdx, TCHAR* pValue);
	const DWORD GetIpAddress(int nIdx);

	//
	BOOL GetMaxWidth(const int nIdx, DWORD* pdwValue);
	BOOL GetMaxHeight(const int nIdx, DWORD* pdwValue);

	BOOL GetX(const int nIdx, DWORD* pdwValue);
	BOOL GetY(const int nIdx, DWORD* pdwValue);
	BOOL GetWidth(const int nIdx, DWORD* pdwValue);
	BOOL GetHeight(const int nIdx, DWORD* pdwValue);
	BOOL GetPixelFormat(const int nIdx, DWORD* pdwValue);

	BOOL SetEventFunc(const int nIdx, FuncAcquisitionEvent pFunc, void* pUserData);



	BOOL GetCameraInformation(const int nIdx, INFO_OTHER_CATEGORY* pstRootCategory);
	const INFO_OTHER_IF* GetCameraInformation(const int nIdx, const TCHAR* szName);

	BOOL GetCameraValue(const int nIdx, const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue);
	BOOL SetCameraValue(const int nIdx, const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue);

protected:

	// Function Pointer
	HBASLER (*pFuncOpenBasler)();
	void (*pFuncCloseBasler)(HBASLER hBalser);

	BOOL (*pFuncStartBasler)(HBASLER hBalser, int nIdx);
	void (*pFuncStopBasler)(HBASLER hBalser, int nIdx);

	BOOL (*pFuncSearchBasler)(HBASLER hBalser);
	const int (*pFuncGetCountBasler)(HBASLER hBalser);

	BOOL (*pFuncIsGigEBasler)(HBASLER hBalser, int nIdx);
	BOOL (*pFuncIsUsbBasler)(HBASLER hBalser, int nIdx);

	DWORD(*pFuncGetIpAddressBasler)(HBASLER hBalser, int nIdx);

	BOOL (*pFuncSetEventFuncBasler)(HBASLER hBalser, const int nIdx, FuncAcquisitionEvent pFunc, void* pUserData);

	BOOL (*pFuncGetCameraInformationBasler)(HBASLER hBalser, const int nIdx, INFO_OTHER_CATEGORY* pstRootCategory);
	const INFO_OTHER_IF* (*pFuncGetCameraInfoFromNameBasler)(HBASLER hBalser, const int nIdx, const TCHAR* pName);
	
	BOOL (*pFuncGetCameraValueBasler)(HBASLER hBalser, const int nIdx, const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue);
	BOOL (*pFuncSetCameraValueBasler)(HBASLER hBalser, const int nIdx, const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue);

	const TCHAR* DLL_MODULE = _T("LibBasler.dll");
	const TCHAR* DLL_MODULE64 = _T("LibBasler_x64.dll");

	// Dll
	HINSTANCE m_hInstance;
	HBASLER m_hBasler;

};