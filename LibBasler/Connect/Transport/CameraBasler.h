#pragma once

#include "CameraInterfaceDef.h"

#include <pylon/PylonIncludes.h>
#include <pylon/gige/BaslerGigEInstantCamera.h>

class CCameraBasler
{
public:
	CCameraBasler();
	~CCameraBasler();

	BOOL Open(Pylon::IPylonDevice* pDevice);
	void Close();

	BOOL IsStart();
	BOOL Start();
	void Stop();

	BOOL IsGigE();
	BOOL IsUsb();

	const DWORD GetIpAddress();

	//
	BOOL SetEventFunc(FuncAcquisitionEvent pFunc, void* pUserData);

	BOOL GetCameraInformation(INFO_OTHER_CATEGORY* pstRootCategory);
	const INFO_OTHER_IF* GetCameraInformation(const TCHAR* szName);

	BOOL GetCameraValue(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue);
	BOOL SetCameraValue(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue);

protected:
	// Callback
	FuncAcquisitionEvent m_pFuncAcq;
	void* m_pstUserData;

	BOOL m_bStarted;

protected:
	// Thread...
	HANDLE	m_hThreadBasler;
	HANDLE	m_hEventBaslerStop;
	BOOL	m_bStopBasler;
	BOOL	m_bSuspend;

	CRITICAL_SECTION m_CriticalSection;

	static DWORD WINAPI ThreadBaslerProc(LPVOID lpArg);
	DWORD ThreadBaslerProc(void);



	// Basler SDK
protected:
	Pylon::IPylonDevice*   m_pPylonDevice;
	Pylon::CInstantCamera* m_pInstanceCamera;
	
	INFO_OTHER_CATEGORY* m_pRootCategory;


	const int MAX_TIMEOUT_MSEC = 5000;

	void PrintInterface(GenApi::EInterfaceType eIfType);

	// Load
	void LoadIValue(GenApi::INode* piChild);
	void LoadIBase(GenApi::INode* piChild);
	void LoadIInteger(GenApi::INode* piChild, INFO_OTHER_INTEGER* pstInfo);
	void LoadIBoolean(GenApi::INode* piChild, INFO_OTHER_BOOLEAN* pstInfo);
	void LoadICommand(GenApi::INode* piChild, INFO_OTHER_COMMAND* pstInfo);
	void LoadIFloat(GenApi::INode* piChild, INFO_OTHER_FLOAT* pstInfo);
	void LoadIString(GenApi::INode* piChild, INFO_OTHER_STRING* pstInfo);
	void LoadIRegister(GenApi::INode* piChild);
	void LoadICategory(GenApi::INode* piChild, INFO_OTHER_CATEGORY* pstCategoty);
	void LoadIEnumeration(GenApi::INode* piChild, INFO_OTHER_ENUM* pstInfo);
	void LoadIEnumEntry(GenApi::INode* piChild);
	void LoadIPort(GenApi::INode* piChild);
	void LoadInterface(GenApi::INode* piChild, TYPE_OTHER_INTERFACE eInterface, INFO_OTHER_IF* pstInfo);

	void LoadCategory(INFO_OTHER_CATEGORY* pstInfo);

	// Update
	void UpdateIValue(GenApi::INode* piChild);
	void UpdateIBase(GenApi::INode* piChild);
	void UpdateIInteger(GenApi::INode* piChild, INFO_OTHER_INTEGER* pstInfo);
	void UpdateIBoolean(GenApi::INode* piChild, INFO_OTHER_BOOLEAN* pstInfo);
	void UpdateICommand(GenApi::INode* piChild, INFO_OTHER_COMMAND* pstInfo);
	void UpdateIFloat(GenApi::INode* piChild, INFO_OTHER_FLOAT* pstInfo);
	void UpdateIString(GenApi::INode* piChild, INFO_OTHER_STRING* pstInfo);
	//void UpdateIRegister(GenApi::INode* piChild);
	//void UpdateICategory(GenApi::INode* piChild, INFO_OTHER_CATEGORY* pstCategoty);
	void UpdateIEnumeration(GenApi::INode* piChild, INFO_OTHER_ENUM* pstInfo);
	//void UpdateIEnumEntry(GenApi::INode* piChild);
	//void UpdateIPort(GenApi::INode* piChild);

	void UpdateCategory(INFO_OTHER_CATEGORY* pstInfo);


	// Clear
	void ClearCategory(INFO_OTHER_CATEGORY* pstInfo);
	void ClearInterface(INFO_OTHER_IF* pstInfo);

	void CopyInformation(const INFO_OTHER_IF* pstSrc, INFO_OTHER_IF** ppstDest);
	void CopyInterface(const INFO_OTHER_IF* pstSrc, INFO_OTHER_IF* pstDest);

	INFO_OTHER_IF* SearchInterface(const TCHAR* szName);
	INFO_OTHER_IF* SearchInterfaceFromCategory(INFO_OTHER_CATEGORY* pstCategory, const TCHAR* szName);


	BOOL SetIInteger(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue);
	BOOL SetIBoolean(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue);
	BOOL SetICommand(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue);
	BOOL SetIFloat(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue);
	BOOL SetIString(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue);
	BOOL SetIEnumeration(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue);

	BOOL GetIInteger(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue);
	BOOL GetIBoolean(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue);
	BOOL GetICommand(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue);
	BOOL GetIFloat(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue);
	BOOL GetIString(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue);
	BOOL GetIEnumeration(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue);

};
