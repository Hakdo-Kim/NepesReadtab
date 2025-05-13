#pragma once

#include "CameraInterfaceDef.h"
#include "CameraDev.h"

#ifdef _USRDLL
#define BASLERINTERFACE extern "C"  __declspec(dllexport)
#else
#define BASLERINTERFACE extern "C"  __declspec(dllimport)
#endif

typedef void*  HBASLER;

BASLERINTERFACE  HBASLER OpenBasler();
BASLERINTERFACE  void CloseBasler(HBASLER hBalser);

BASLERINTERFACE BOOL StartBasler(HBASLER hBalser, int nIdx);
BASLERINTERFACE void StopBasler(HBASLER hBalser, int nIdx);

BASLERINTERFACE BOOL SearchBasler(HBASLER hBalser);
BASLERINTERFACE const int GetCountBasler(HBASLER hBalser);

BASLERINTERFACE BOOL IsGigEBasler(HBASLER hBalser, int nIdx);
BASLERINTERFACE BOOL IsUsbBasler(HBASLER hBalser, int nIdx);

BASLERINTERFACE DWORD GetIpAddressBasler(HBASLER hBalser, int nIdx);

BASLERINTERFACE BOOL SetEventFuncBasler(HBASLER hBalser, const int nIdx, FuncAcquisitionEvent pFunc, void* pUserData);

BASLERINTERFACE BOOL GetCameraInformationBasler(HBASLER hBalser, const int nIdx, INFO_OTHER_CATEGORY* pstRootCategory);
BASLERINTERFACE const INFO_OTHER_IF* GetCameraInfoFromNameBasler(HBASLER hBalser, const int nIdx, const TCHAR* pszName);

BASLERINTERFACE BOOL GetCameraValueBasler(HBASLER hBalser, const int nIdx, const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue);
BASLERINTERFACE BOOL SetCameraValueBasler(HBASLER hBalser, const int nIdx, const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue);