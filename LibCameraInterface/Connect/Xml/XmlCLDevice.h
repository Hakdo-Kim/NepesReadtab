#pragma once

#include <vector>
#include "inc/tinyxml2.h"

#include "CameraInterfaceDef.h"

#define MAX_CL_PATH		1024

typedef struct
{
	DWORD	m_CamID;
	TCHAR	m_szCamFile[CLCAMFILE_MAX][MAX_CL_PATH];

	INFO_CAMERALINK m_stCameraLink;

} INFO_CL_DEVICE;


class CXmlCLDevice
{
public:
	CXmlCLDevice();
	virtual ~CXmlCLDevice();

	BOOL Load();
	BOOL Save();

	//Information.
	const int GetDeviceCount();
	const INFO_CL_DEVICE* GetDeviceInfo(const int nIdx);
	const TCHAR* GetModelName(TYPE_CLDEVICE	eDevice);

	// Add
	BOOL AddDevice(INFO_CL_DEVICE& stEmul);
	BOOL UpdateDevice(const int nIdx, INFO_CL_DEVICE& stEmul);

	// Find
	BOOL FindDevice(const TCHAR* pszName, int* pIdx = NULL);

	// Delete
	void DeleteDevice(int nIdx);
	void DeleteDevice(const TCHAR* pszName);

	void ClearDevice();


protected:
	BOOL LoadInfomation(const TCHAR* pszPath);
	BOOL LoadCameraLink(tinyxml2::XMLHandle hCL, INFO_CL_DEVICE& pstCL);
	BOOL LoadCameraLinkCamFile(tinyxml2::XMLHandle hCL, INFO_CL_DEVICE& stCL);
	

	BOOL SaveInformation(const TCHAR* pszPath);
	BOOL SaveCameraLink(tinyxml2::XMLDocument* pXmlDoc, tinyxml2::XMLElement* pCL, INFO_CL_DEVICE* pstCL);

	void ClearInformation();


protected:
	std::vector<INFO_CL_DEVICE*> m_CLDeviceList;


};