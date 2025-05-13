#pragma once

#include "CameraInterfaceDef.h"
#include "inc/CameraLibrary.h"

#include "include/multicam.h"

typedef struct
{
	MCHANDLE m_Channel;
	PVOID m_pCurrent;

	int m_nSizeX;
	int m_nSizeY;
	int m_nPitch;

} INFO_EURESYS;


class CCLFile
{
public:
	CCLFile();
	virtual ~CCLFile();

	int	SearchSerial(INFO_SERIAL* pstInfo, const int nLen);

	BOOL IsOpen();
	BOOL Open(const INFO_CONNECT_CAMERALINK* pInfo=NULL);
	void Close();

	BOOL IsOpenSerial();
	BOOL OpenSerial();
	void CloseSerial();

	BOOL Update(const INFO_CONNECT_CAMERALINK* pInfo);
	BOOL GetFrameInfo(INFO_FRAME* pstFrame);

	BOOL IsStarted();
	BOOL Start(BOOL bSingleFrame = FALSE);
	void Stop();

	const INFO_CONNECT_CAMERALINK* GetDeviceInfo();
	const TYPE_CLIMGTAPS GetClImageTap(TYPE_IMAGE_TAPS eTap);
	const TYPE_IMAGE_TAPS GetImageTap(TYPE_CLIMGTAPS eTap);

	BOOL SetEventFunc(FuncAcquisitionEvent pFunc, void* pUserData);

	// EURESYS CALLBACK FUNC
	static void WINAPI EuresysCallback(PMCSIGNALINFO pSigInfo);

	BOOL LoadCameraUserSetting();

	const INFO_CAM_DEVICE* GetCameraDevice();
	const INFO_USER_SETTING* GetUserSetting();

	// 
	BOOL SetRoi(const int nX, const int nY, const int nW, const int nH);

	BOOL GetRoi(INFO_ROI_PARA* pstROI);
	BOOL SetRoi(INFO_ROI_PARA stROI);

	BOOL GetMaxWidth(DWORD* pdwValue);
	BOOL GetMaxHeight(DWORD* pdwValue);

	BOOL GetX(DWORD* pdwValue);
	BOOL GetY(DWORD* pdwValue);
	BOOL GetWidth(DWORD* pdwValue);
	BOOL GetHeight(DWORD* pdwValue);

	BOOL GetPixelFormat(DWORD* pdwValue);
	BOOL SetPixelFormat(DWORD dwValue);


	// 
	BOOL SetTrigger();

	BOOL GetTriggerMode(INFO_TRIGGER_PARA* pstTrigger);
	BOOL SetTriggerMode(INFO_TRIGGER_PARA stTrigger);

	BOOL GetTriggerDelay(DWORD* pDelay);
	BOOL SetTriggerDelay(DWORD dwDelay);


	//
	BOOL GetStrobeMode(INFO_STROBE_PARA* pstStrobe);
	BOOL SetStrobeMode(INFO_STROBE_PARA stStrobe);

	BOOL GetStrobeDelay(DWORD* pDelay);
	BOOL SetStrobeDelay(DWORD dwDelay);

	BOOL GetStrobeWidth(DWORD* pWidth);
	BOOL SetStrobeWidth(DWORD dwWidth);

	//
	BOOL GetGainDigital(DWORD* pGain);
	BOOL SetGainDigital(DWORD dwGain);

	BOOL GetGainAnalog(DWORD* pGain);
	BOOL SetGainAnalog(DWORD dwGain);

	//
	BOOL GetExposureTime(DWORD* pExTime);
	BOOL SetExposureTime(DWORD dwExTime);

	BOOL GetFps(DWORD* pFps);
	BOOL SetFps(DWORD dwFps);

	BOOL SetDataBit(unsigned short nDataBit);
	BOOL GetDataBit(unsigned short* nDataBit);


	// Userset
	BOOL LoadUserset(DWORD dwUserset);
	BOOL SaveUserset(DWORD dwUserset);

	BOOL GetStartupUserset(DWORD* pUserset);
	BOOL SetStartupUserset(DWORD dwUserset);

	// LUT
	BOOL SetLutMode(unsigned short nMode);
	BOOL GetLutMode(unsigned short* pnMode);

	BOOL WriteLut(const INFO_LUT_PARA* pLutList, const int nLen, BOOL bEeprom);
	
	//
	BOOL ReadFpgaRegAddress(const DWORD dwAddress, DWORD* pdwValue);
	BOOL WriteFpgaRegAddress(const DWORD dwAddress, DWORD dwValue);

	BOOL ReadSensorRegAddress(const DWORD dwAddress, DWORD* pdwValue);
	BOOL WriteSensorRegAddress(const DWORD dwAddress, DWORD dwValue);


protected:
	BOOL m_bInit;
	BOOL m_bStart;

	CRITICAL_SECTION m_CriticalSection;

	INFO_CONNECT_CAMERALINK m_stCL;
	INFO_FRAME m_stFrame;
	LONGLONG m_LastSWTrigger;


	HANDLE	m_hThreadCl;
	BOOL	m_bStopCl;

	HANDLE	m_hEventClAcq;
	HANDLE	m_hEventClStop;
	

	FuncAcquisitionEvent m_pFunc;
	void* m_pFuncArg;

	static DWORD WINAPI ThreadClProc(LPVOID lpArg);
	DWORD ThreadClProc(void);


	// EURESYS
	INFO_EURESYS m_stEuresys;
	BOOL StartEuresys();
	void StopEuresys();
	void CloseEuresys();

	void UpdateUserSetting();


	// DLL Library
	HINSTANCE	m_hDllInstance;
	HCAMERALIB	m_hCameraLib;			// Device Handle

	INFO_CAM_DEVICE m_stCamDevice;
	INFO_USER_SETTING m_stUserSetting;

	HCAMERALIB (CALLBACK *pfInitCameraLib)();
	void (CALLBACK *pfDeinitCameraLib)(HCAMERALIB);

	// Device
	BOOL(CALLBACK *pfLoadDefaultInformation)(HCAMERALIB, INFO_CAM_DEVICE*);
	const INFO_CAM_DEVICE* (CALLBACK *pfGetDeviceInformation)(HCAMERALIB);
	BOOL(CALLBACK *pfSetDeviceFactoryDefault)(HCAMERALIB);
	BOOL(CALLBACK *pfLoadDeviceUserSet)(HCAMERALIB, INFO_USER_SETTING*, BOOL);


	// User Setting.
	const INFO_USER_SETTING* (CALLBACK *pfGetUserSettingInformation)(HCAMERALIB);

	void (CALLBACK *pfSetUserSettingMain)(HCAMERALIB, const INFO_STATUS_MAIN*);
	void (CALLBACK *pfSetUserSettingAnalog)(HCAMERALIB, const INFO_STATUS_ANALOG*);
	void (CALLBACK *pfSetUserSettingTrigger)(HCAMERALIB, const INFO_STATUS_TRIGGER*);
	void (CALLBACK *pfSetUserSettingLut)(HCAMERALIB, const INFO_STATUS_LUT*);

	// Command Device
	BOOL (CALLBACK *pfStart)(HCAMERALIB);
	BOOL (CALLBACK *pfStop)(HCAMERALIB);

	//
	BOOL (CALLBACK *pfSetDataBit)(HCAMERALIB, const TYPE_DATA_BIT);
	BOOL (CALLBACK *pfSetViewMode)(HCAMERALIB, const TYPE_VIEW_MODE, INFO_ROI*);
	BOOL (CALLBACK *pfSetTestPattern)(HCAMERALIB, const TYPE_TEST_PATTERN);
	BOOL (CALLBACK *pfSetRoi)(HCAMERALIB, const INFO_ROI*);
	BOOL (CALLBACK *pfSetImageTaps)(HCAMERALIB, TYPE_IMAGE_TAPS);

	// 
	BOOL (CALLBACK *pfSetAnalogGain)(HCAMERALIB, DWORD);
	BOOL (CALLBACK *pfSetDigitalGain)(HCAMERALIB, DWORD);

	BOOL (CALLBACK *pfSetExposure)(HCAMERALIB, DWORD);
	BOOL (CALLBACK *pfSetFramerate)(HCAMERALIB, DWORD);

	BOOL (CALLBACK *pfSetEnablePrnu)(HCAMERALIB, BOOL);

	BOOL (CALLBACK *pfSetEnableFfc)(HCAMERALIB, BOOL);
	BOOL (CALLBACK *pfGetFfcResolution)(HCAMERALIB, DWORD*, DWORD*);

	BOOL (CALLBACK *pfAllocGainTable)(HCAMERALIB, const int, const int, INFO_GAIN_TABLE*);
	BOOL (CALLBACK *pfReleaseGainTable)(HCAMERALIB, INFO_GAIN_TABLE*);

	BOOL (CALLBACK *pfMakeFfcAvgBuffer)(HCAMERALIB, const INFO_BITMAP*, const int, INFO_GAIN_TABLE*);
	BOOL (CALLBACK *pfMakeFfcGainBuffer)(HCAMERALIB, INFO_GAIN_TABLE*);
	BOOL (CALLBACK *pfMakeFfcGainTable)(HCAMERALIB, INFO_GAIN_TABLE*);
	BOOL (CALLBACK *pfMakeFfcWriteBuffer)(HCAMERALIB, INFO_GAIN_TABLE*);

	BOOL (CALLBACK *pfWriteFfcEvenBuffer)(HCAMERALIB, const INFO_GAIN_TABLE*, BOOL);
	BOOL (CALLBACK *pfWriteFfcOddBuffer)(HCAMERALIB, const INFO_GAIN_TABLE*, BOOL);

	BOOL (CALLBACK *pfSetEnableBlackLevel)(HCAMERALIB, BOOL);
	BOOL (CALLBACK *pfSetBlackLevel)(HCAMERALIB, DWORD);

	BOOL (CALLBACK *pfSetEnableDefectFilter)(HCAMERALIB, BOOL);
	BOOL (CALLBACK *pfSetEnableUsertableDefectFilter)(HCAMERALIB, BOOL);

	BOOL (CALLBACK *pfSetThresholdDefectFilter)(HCAMERALIB, DWORD);
	BOOL (CALLBACK *pfSetUsertableDefectFilter)(HCAMERALIB, const DWORD*, const DWORD);

	BOOL (CALLBACK *pfGetInternalTemperature)(HCAMERALIB, DWORD*);
	BOOL (CALLBACK *pfGetExternalTemperature)(HCAMERALIB, DWORD*);

	//
	BOOL (CALLBACK *pfSetTrigger)(HCAMERALIB, TYPE_TRIGGER, TYPE_TRIGGER_POLARITY);
	BOOL (CALLBACK *pfSetSensorExposureTime)(HCAMERALIB, TYPE_SENSOR_EXPOSURE);
	BOOL (CALLBACK *pfSetTriggerDelayTime)(HCAMERALIB, DWORD);

	BOOL (CALLBACK *pfSetStrobePolarity)(HCAMERALIB, BOOL, TYPE_STROBE_POLARITY);
	BOOL (CALLBACK *pfSetStrobeSync)(HCAMERALIB, TYPE_STROBE_SYNC);
	BOOL (CALLBACK *pfSetStrobeDelayTime)(HCAMERALIB, DWORD);
	BOOL (CALLBACK *pfSetStrobeDurationTime)(HCAMERALIB, DWORD);

	//
	BOOL (CALLBACK *pfSetEnableLut)(HCAMERALIB, BOOL);
	BOOL (CALLBACK *pfSetLutIndex)(HCAMERALIB, int);
	BOOL (CALLBACK *pfWriteLutTable)(HCAMERALIB, const INFO_LUT_TABLE*, const int, BOOL);

	// Command Register
	BOOL (CALLBACK *pfReadRegister)(HCAMERALIB, const TYPE_REGISTER, WORD, WORD*);
	BOOL (CALLBACK *pfWriteRegister)(HCAMERALIB, const TYPE_REGISTER, WORD, WORD);
	BOOL (CALLBACK *pfWritePrnu)(HCAMERALIB, const DWORD*, const DWORD);

	// Command SPI
	BOOL (CALLBACK *pfReadFlash)(HCAMERALIB, DWORD, DWORD, BYTE*, DWORD);
	BOOL (CALLBACK *pfWriteFlash)(HCAMERALIB, DWORD, DWORD, const BYTE*, DWORD);

	BOOL (CALLBACK *pfGetSerialNumber)(HCAMERALIB, TCHAR*, int);
	BOOL (CALLBACK *pfSetSerialNumber)(HCAMERALIB, WORD);

	// INI
	BOOL (CALLBACK *pfSaveFileUserSet)(HCAMERALIB, const TCHAR*, const TYPE_MENU_USERSET);
	BOOL (CALLBACK *pfLoadFileUserSet)(HCAMERALIB, const TCHAR*, INFO_USER_SETTING*);

	BOOL (CALLBACK *pfSaveEepromUserSet)(HCAMERALIB, const TYPE_MENU_USERSET);
	BOOL (CALLBACK *pfLoadEepromUserSet)(HCAMERALIB, const TYPE_MENU_USERSET, INFO_USER_SETTING*);

	BOOL (CALLBACK *pfSetStartUpUserSet)(HCAMERALIB, TYPE_MENU_USERSET);
	BOOL (CALLBACK *pfGetStartUpUserSet)(HCAMERALIB, TYPE_MENU_USERSET*);

	

	// Serial
	int  (CALLBACK *pfSearchSerial)(HCAMERALIB, INFO_SERIALPORT*, const int );

	BOOL (CALLBACK *pfIsConnectedSerial)(HCAMERALIB );
	BOOL (CALLBACK *pfConnectSerial)(HCAMERALIB, TCHAR*, DWORD );
	void (CALLBACK *pfDisconnectSerial)(HCAMERALIB );


	void InitCLLibrary();
	void DeinitCLLibrary();




};