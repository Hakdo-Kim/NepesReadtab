#pragma once

#include "CameraInterfaceDef.h"
#include "CameraDev.h"

#include <vector>

class CCameraDevice
{
public:
	CCameraDevice();
	~CCameraDevice();

	// Clear
	void ClearAll();

	// Camera Default Information
	const int GetDefaultListCount(TYPE_NETWORK eNetwork);
	const INFO_DEFDEV* GetDefaultDevice(TYPE_NETWORK eNetwork, const TCHAR* pszName);
	const INFO_DEFDEV* GetDefaultDevice(const INFO_CONNECT_DEV* pDev);
	
	int AddDefaultDevice(INFO_DEFDEV* pstDefDev);
	void ClearDefaultDevice(TYPE_NETWORK eNetwork);


	// Camera (CameraLink) Default Information
	const INFO_DEFDEV_CL* GetCameraLinkDevice(const TYPE_CLDEVICE eDevice);

	BOOL IsEnableFramegrabber(TYPE_CLGRABBER eGrabber);
	int GetEnableModelList(TYPE_CLGRABBER eGrabber, BOOL* pbModelList, int nLen);
	int GetEnableImageTapList(TYPE_CLGRABBER eGrabber, TYPE_CLDEVICE eModel, BOOL* pbTapList, int nLen);
	int GetEnableDataBitList(TYPE_CLGRABBER eGrabber, TYPE_CLDEVICE eModel, BOOL* pbDataBitList, int nLen);
	int GetEnableColorList(TYPE_CLGRABBER eGrabber, TYPE_CLDEVICE eModel, BOOL* pbColorList, int nLen);

	// Camera (CameraLink) - CAM File...
	const INFO_FRAMEGRABBER_CAMFILE* GetCamFile(const INFO_CAMERALINK* pstCL);
	int AddCamfile(INFO_FRAMEGRABBER_CAMFILE* pstCamfile);
	void ClearCamfile();

	// UserConfig
	const INFO_DEFDEV_USERCONFIG* GetUserConfig();
	void UpdateUserConfig(const INFO_DEFDEV_USERCONFIG* pstUserConfig);

	
protected:
	std::vector<INFO_DEFDEV> m_DefGigEList;
	std::vector<INFO_DEFDEV> m_DefUSBList;
	std::vector<INFO_DEFDEV_CL> m_DefCLList;
	std::vector<INFO_FRAMEGRABBER_CAMFILE> m_CLCamFileList;

	//basler
	std::vector<INFO_DEFDEV> m_DefBaslerList;

	// UserConfig
	INFO_DEFDEV_USERCONFIG m_stDefUserConfig;


};