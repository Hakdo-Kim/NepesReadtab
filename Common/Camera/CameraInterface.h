#pragma once

#include "CameraInterfaceDef.h"
#include "CameraDev.h"

#ifdef _USRDLL
	#define CAMERAINTERFACE extern "C"  __declspec(dllexport)
#else
	#define CAMERAINTERFACE extern "C"  __declspec(dllimport)
#endif

typedef void*  HCAMERA;

CAMERAINTERFACE  HCAMERA InitCamera(TYPE_NETWORK eNetwork);
CAMERAINTERFACE  void DeinitCamera( HCAMERA hCamera);
 
CAMERAINTERFACE  const TYPE_NETWORK GetNetworkType( HCAMERA hCamera );
CAMERAINTERFACE  BOOL IsConnected( HCAMERA hCamera );

CAMERAINTERFACE  int GetDeviceCount( HCAMERA hCamera );
CAMERAINTERFACE  int GetDeviceIndex( HCAMERA hCamera, const INFO_CONNECT_DEV* pDev);
CAMERAINTERFACE  int GetDeviceID(HCAMERA hCamera, const TCHAR* pName);
CAMERAINTERFACE  BOOL GetDeviceInfo( HCAMERA hCamera,  int nIdx, INFO_CONNECT_DEV* pstDevice);

CAMERAINTERFACE  BOOL ResearchDeviceInfo( HCAMERA hCamera );

// Device Information
CAMERAINTERFACE  BOOL GetFrameInfo( HCAMERA hCamera, const int nIdx ,INFO_FRAME* pstFrame);
CAMERAINTERFACE  BOOL SetEventFunc( HCAMERA hCamera, const int nIdx, FuncAcquisitionEvent pFunc, void* pUserData);

CAMERAINTERFACE  BOOL StartCamera( HCAMERA hCamera, const int nIdx, BOOL bSingle);
CAMERAINTERFACE  void StopCamera(HCAMERA hCamera, const int nIdx);

CAMERAINTERFACE  BOOL IsOpenCamera(HCAMERA hCamera, const int nIdx);
CAMERAINTERFACE  BOOL OpenCamera(HCAMERA hCamera, const int nIdx);
CAMERAINTERFACE  void CloseCamera(HCAMERA hCamera, const int nIdx);


	
// Command Function
CAMERAINTERFACE  BOOL SetRegister(HCAMERA hCamera, const int nIdx, const DWORD dwAddress, const DWORD dwValue, DWORD dwReserved);
CAMERAINTERFACE  BOOL GetRegister(HCAMERA hCamera, const int nIdx, const DWORD dwAddress, DWORD* pdwValue, DWORD dwReserved);

//
CAMERAINTERFACE BOOL SetGain(HCAMERA hCamera, const int nIdx, const int nGainType, const int nGainValue);
CAMERAINTERFACE BOOL GetGain(HCAMERA hCamera, const int nIdx, const int nGainType, int* pnGainValue);
	
CAMERAINTERFACE BOOL SetEnableFrameRate(HCAMERA hCamera, const int nIdx, const unsigned int nEnable);
CAMERAINTERFACE BOOL GetEnableFrameRate(HCAMERA hCamera, const int nIdx, unsigned int* pnEnable);

CAMERAINTERFACE BOOL SetFrameRate(HCAMERA hCamera, const int nIdx, const unsigned int nFrameRate);
CAMERAINTERFACE BOOL GetFrameRate(HCAMERA hCamera, const int nIdx, unsigned int* pnFrameRate);
CAMERAINTERFACE BOOL GetMaxFrameRate(HCAMERA hCamera, const int nIdx, unsigned int* pnFrameRate);
	
CAMERAINTERFACE BOOL SetExposureTime(HCAMERA hCamera, const int nIdx, const unsigned int nSetExposureTime);
CAMERAINTERFACE BOOL GetExposureTime(HCAMERA hCamera, const int nIdx, unsigned int* pnSetExposureTime);
CAMERAINTERFACE BOOL GetExposureMaxTime(HCAMERA hCamera, const int nIdx, unsigned int nFrameRate, unsigned int* pnExposureTime);
CAMERAINTERFACE BOOL ConvertExposureTime(HCAMERA hCamera, const int nIdx, unsigned int nStep, double* pfUSec);
	
CAMERAINTERFACE BOOL SetTriggerMode(HCAMERA hCamera, const int nIdx, INFO_TRIGGER_PARA stTrigger);
CAMERAINTERFACE BOOL GetTriggerMode(HCAMERA hCamera, const int nIdx, INFO_TRIGGER_PARA* pstTrigger);

CAMERAINTERFACE BOOL SetTriggerDelay(HCAMERA hCamera, const int nIdx, int nDelay);
	
CAMERAINTERFACE BOOL SaveUserset(HCAMERA hCamera, const int nIdx, unsigned int nNumber);
CAMERAINTERFACE BOOL LoadUserset(HCAMERA hCamera, const int nIdx, unsigned int nNumber);
	
CAMERAINTERFACE BOOL SetStrobeMode(HCAMERA hCamera, const int nIdx, INFO_STROBE_PARA stStrobe);
CAMERAINTERFACE BOOL GetStrobeMode(HCAMERA hCamera, const int nIdx, INFO_STROBE_PARA* pstStrobe);
	
CAMERAINTERFACE BOOL SetFlipMode(HCAMERA hCamera, const int nIdx, unsigned short nMode);
CAMERAINTERFACE BOOL GetFlipMode(HCAMERA hCamera, const int nIdx, unsigned short* pnMode);
	
CAMERAINTERFACE BOOL SetROI(HCAMERA hCamera, const int nIdx, INFO_ROI_PARA stROI);
CAMERAINTERFACE BOOL GetROI(HCAMERA hCamera, const int nIdx, INFO_ROI_PARA* pstROI);
	
CAMERAINTERFACE BOOL SetUsersetStartNo(HCAMERA hCamera, const int nIdx, unsigned char nUsersetStartNo);
CAMERAINTERFACE BOOL GetUsersetStartNo(HCAMERA hCamera, const int nIdx, unsigned char* pnUsersetStartNo);

CAMERAINTERFACE BOOL SetDataBits(HCAMERA hCamera, const int nIdx, unsigned short nDataBit);
CAMERAINTERFACE BOOL GetDataBits(HCAMERA hCamera, const int nIdx, unsigned short* pnDataBit);

CAMERAINTERFACE BOOL SetColorMode(HCAMERA hCamera, const int nIdx, unsigned short nColorMode);	// 0:Bayer,1:YUV
CAMERAINTERFACE BOOL GetColorMode(HCAMERA hCamera, const int nIdx, unsigned short* pnColorMode);

CAMERAINTERFACE BOOL SetMtu(HCAMERA hCamera, const int nIdx, unsigned int nMTU);
CAMERAINTERFACE BOOL GetMtu(HCAMERA hCamera, const int nIdx, unsigned int* pnMTU);
	
CAMERAINTERFACE BOOL GetDiag(HCAMERA hCamera, const int nIdx, void* pstDiag, const int nLen);
CAMERAINTERFACE BOOL SetSWTrigger(HCAMERA hCamera, const int nIdx);


// LUT
CAMERAINTERFACE BOOL SetLutMode(HCAMERA hCamera, const int nIdx, unsigned short nMode);
CAMERAINTERFACE BOOL GetLutMode(HCAMERA hCamera, const int nIdx, unsigned short* pnMode);

CAMERAINTERFACE BOOL WriteLut(HCAMERA hCamera, const int nIdx, const INFO_LUT_PARA* pLutList, const int nLen, BOOL bEeprom);


// Effect
CAMERAINTERFACE BOOL SetEffectNR(HCAMERA hCamera, const int nIdx, unsigned short nEffect);
CAMERAINTERFACE BOOL GetEffectNR(HCAMERA hCamera, const int nIdx, unsigned short* pnEffect);

CAMERAINTERFACE BOOL SetEffectGC(HCAMERA hCamera, const int nIdx, unsigned short nEffect);
CAMERAINTERFACE BOOL GetEffectGC(HCAMERA hCamera, const int nIdx, unsigned short* pnEffect);

CAMERAINTERFACE BOOL SetEffectCM(HCAMERA hCamera, const int nIdx, unsigned short nEffect);
CAMERAINTERFACE BOOL GetEffectCM(HCAMERA hCamera, const int nIdx, unsigned short* pnEffect);

CAMERAINTERFACE BOOL SetEffectAWB(HCAMERA hCamera, const int nIdx, unsigned short nEffect);
CAMERAINTERFACE BOOL GetEffectAWB(HCAMERA hCamera, const int nIdx, unsigned short* pnEffect);

CAMERAINTERFACE BOOL SetEffectSmooth(HCAMERA hCamera, const int nIdx, unsigned short nEffect);
CAMERAINTERFACE BOOL GetEffectSmooth(HCAMERA hCamera, const int nIdx, unsigned short* pnEffect);

CAMERAINTERFACE BOOL SetEffectSharpen(HCAMERA hCamera, const int nIdx, unsigned short nEffect);
CAMERAINTERFACE BOOL GetEffectSharpen(HCAMERA hCamera, const int nIdx, unsigned short* pnEffect);

CAMERAINTERFACE BOOL SetEffectFPN(HCAMERA hCamera, const int nIdx, unsigned short nEffect);
CAMERAINTERFACE BOOL GetEffectFPN(HCAMERA hCamera, const int nIdx, unsigned short* pnEffect);

CAMERAINTERFACE BOOL SetEffectPRNU(HCAMERA hCamera, const int nIdx, unsigned short nEffect);
CAMERAINTERFACE BOOL GetEffectPRNU(HCAMERA hCamera, const int nIdx, unsigned short* pnEffect);

CAMERAINTERFACE BOOL SetEffectDPC(HCAMERA hCamera, const int nIdx, unsigned short nEffect);
CAMERAINTERFACE BOOL GetEffectDPC(HCAMERA hCamera, const int nIdx, unsigned short* pnEffect);

CAMERAINTERFACE BOOL SetColorGain(HCAMERA hCamera, const int nIdx, const int nGainType, int nGainVal);
CAMERAINTERFACE BOOL GetColorGain(HCAMERA hCamera, const int nIdx, const int nGainType, int* pnGainVal);


// Some Camera Model...
CAMERAINTERFACE  BOOL CalculateMaxFrameRate(const INFO_DEFDEV* pstDefDev, const int nWidth, const int nHeight, DWORD* pdwMaxFps);

#if defined(ENABLE_CAMERA_LIBRARY_BASLER)
CAMERAINTERFACE  BOOL GetCameraInformation(HCAMERA hCamera, const int nIdx, INFO_OTHER_CATEGORY* pstRootCategory);
CAMERAINTERFACE  const INFO_OTHER_IF* GetCameraInfoFromName(HCAMERA hCamera, const int nIdx, const TCHAR* pszName);

CAMERAINTERFACE  BOOL GetCameraValue(HCAMERA hCamera, const int nIdx, const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue);
CAMERAINTERFACE  BOOL SetCameraValue(HCAMERA hCamera, const int nIdx, const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue);
#endif






