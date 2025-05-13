#pragma once

#include <vector>
#include "inc/tinyxml2.h"

#define MAX_EMUL_PATH		1024

typedef struct
{
	DWORD	m_CamID;

	TCHAR	m_szName[MAX_PATH];
	TCHAR	m_szPath[MAX_EMUL_PATH];

	DWORD	m_dwFPS;
	BOOL	m_bCycleDir;


	BOOL	m_bCameraEmulator;
	SIZE	m_stResolution;
	RECT	m_stRoi;

} INFO_EMUL_DEVICE;


class CXmlEmulDevice
{
public:
	CXmlEmulDevice();
	virtual ~CXmlEmulDevice();

	BOOL Load();
	BOOL Save();

	//Information.
	const int GetDeviceCount();
	const INFO_EMUL_DEVICE* GetDeviceInfo(const int nIdx);

	// Add
	BOOL AddDevice(INFO_EMUL_DEVICE& stEmul);
	BOOL UpdateDevice(const int nIdx, INFO_EMUL_DEVICE& stEmul);
	
	// Find
	BOOL FindDevice(const TCHAR* pszName, int* pIdx=NULL);
	
	// Delete
	void DeleteDevice(int nIdx);
	void DeleteDevice(const TCHAR* pszName);

	void ClearDevice();


protected:
	BOOL LoadInfomation(const TCHAR* pszPath);
	BOOL LoadEmulator(tinyxml2::XMLHandle hEmul, INFO_EMUL_DEVICE& stEmul);

	BOOL SaveInformation(const TCHAR* pszPath);
	BOOL SaveEmulator(tinyxml2::XMLDocument* pXmlDoc,  tinyxml2::XMLElement* pEmul, INFO_EMUL_DEVICE* pstEmul);

	void ClearInformation();


protected:
	std::vector<INFO_EMUL_DEVICE*> m_EmulDeviceList;


};