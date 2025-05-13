#pragma once

#include "CameraInterfaceDef.h"

#include "CameraBasler.h"

class CSdkBasler
{
public:
	CSdkBasler();
	~CSdkBasler();

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

	const DWORD GetIpAddress(int nIdx);

	BOOL SetEventFunc(const int nIdx, FuncAcquisitionEvent pFunc, void* pUserData);

	BOOL GetCameraInformation(const int nIdx, INFO_OTHER_CATEGORY* pstRootCategory);
	const INFO_OTHER_IF* GetCameraInformation(const int nIdx, const TCHAR* szName);

	BOOL GetCameraValue(const int nIdx, const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue);
	BOOL SetCameraValue(const int nIdx, const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue);

protected:
	void ClearDeviceList();

	BOOL m_bOpen;
	std::vector<CCameraBasler*> m_PylonDeviceList;

};
