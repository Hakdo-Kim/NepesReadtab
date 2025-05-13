#pragma once

#include "Connect.h"

#include "Transport/EmulFile.h"
#include "xml/XmlEmulDevice.h"

#include <vector>

#define MAX_EMULCAMERA_COUNT		MAX_CAMERA_INTERFACE


class CConnectEmulFile : public CConnect
{
public:
	CConnectEmulFile();
	virtual ~CConnectEmulFile();

	virtual BOOL IsConnected();

	virtual BOOL Open(TYPE_NETWORK eNetwork);
	virtual BOOL Open(TYPE_NETWORK eNetwork, void* pReserved);
	virtual void Close();

	virtual int GetDeviceCount();
	virtual BOOL GetDeviceInfo(int nIdx, INFO_CONNECT_DEV* pstDevice);

	virtual int GetDeviceIndex(const INFO_CONNECT_DEV* pDev);
	virtual int GetDeviceID(const TCHAR* pName);
	virtual BOOL UpdateDeviceInfo(int nCamID, INFO_CONNECT_DEV* pstDevice);

	virtual BOOL ResearchDeviceInfo();


	// Device Information
	virtual BOOL GetFrameInfo(const int nCamID, INFO_FRAME* pstFrame);
	virtual BOOL SetEventFunc(const int nCamID, FuncAcquisitionEvent pFunc, void* pUserData);

	virtual BOOL Start(const int nCamID, BOOL bSingle = FALSE);
	virtual void Stop(const int nCamID);

	virtual BOOL IsOpen(const int nCamID);
	virtual BOOL Open(const int nCamID);
	virtual void Close(const int nCamID);


	// Command Function
	virtual BOOL SetRegister(const int nCamID, const DWORD dwAddress, const DWORD dwValue, DWORD dwReserved);
	virtual BOOL GetRegister(const int nCamID, const DWORD dwAddress, DWORD* pdwValue, DWORD dwReserved);
	
	//
	virtual BOOL SetGain(const int nCamID, const int nGainType, const int nGainValue);
	virtual BOOL GetGain(const int nCamID, const int nGainType, int* pnGainValue);
	
	virtual BOOL SetEnableFrameRate(const int nCamID, const unsigned int nEnale);
	virtual BOOL GetEnableFrameRate(const int nCamID, unsigned int* pnEnale);

	virtual BOOL SetFrameRate(const int nCamID, const unsigned int nFrameRate);
	virtual BOOL GetFrameRate(const int nCamID, unsigned int* pnFrameRate);
	virtual BOOL GetMaxFrameRate(const int nIdx, unsigned int* pnFrameRate);
	
	virtual BOOL SetExposureTime(const int nCamID, const unsigned int nSetExposureTime);
	virtual BOOL GetExposureTime(const int nCamID, unsigned int* pnSetExposureTime);
	virtual BOOL GetExposureMaxTime(const int nCamID, unsigned int FrameRate, unsigned int* pnSetExposureTime);
	virtual BOOL ConvertExposureTime(const int nCamID, unsigned int nStep, double* pfUSec);
	
	virtual BOOL SetTriggerMode(const int nCamID, INFO_TRIGGER_PARA stTrigger);
	virtual BOOL GetTriggerMode(const int nCamID, INFO_TRIGGER_PARA* pstTrigger);
	
	virtual BOOL SetTriggerDelay(const int nCamID, int nDelay);

	virtual BOOL SaveUserset(const int nCamID, unsigned int nNumber);
	virtual BOOL LoadUserset(const int nCamID, unsigned int nNumber);
	
	virtual BOOL SetStrobeMode(const int nCamID, INFO_STROBE_PARA stStrobe);
	virtual BOOL GetStrobeMode(const int nCamID, INFO_STROBE_PARA* pstStrobe);
	
	virtual BOOL SetFlipMode(const int nCamID, unsigned short nMode);
	virtual BOOL GetFlipMode(const int nCamID, unsigned short* pnMode);
	
	virtual BOOL SetROI(const int nCamID, INFO_ROI_PARA stROI);
	virtual BOOL GetROI(const int nCamID, INFO_ROI_PARA* pstROI);
	
	virtual BOOL SetUsersetStartNo(const int nCamID, unsigned char nUsersetStartNo);
	virtual BOOL GetUsersetStartNo(const int nCamID, unsigned char* pnUsersetStartNo);

	virtual BOOL SetDataBit(const int nCamID, unsigned short nDataBit);
	virtual BOOL GetDataBit(const int nCamID, unsigned short* pnDataBit);

	virtual BOOL SetColorMode(const int nCamID, unsigned short nColorMode);
	virtual BOOL GetColorMode(const int nCamID, unsigned short* pnColorMode);

	virtual BOOL SetMTU(const int nCamID, unsigned int nMTU);
	virtual BOOL GetMTU(const int nCamID, unsigned int* pnMTU);
	
	virtual BOOL GetDiag(const int nCamID, void* pstDiag, const int nLen);
	virtual BOOL SetSWTrigger(const int nCamID);


	// LUT
	virtual BOOL SetLutMode(const int nCamID, unsigned short nMode);
	virtual BOOL GetLutMode(const int nCamID, unsigned short* pnMode);

	virtual BOOL WriteLut(const int nCamID, const INFO_LUT_PARA* pLutList, const int nLen, BOOL bEeprom);

	// Effect
	virtual BOOL SetEffectNR(const int nCamID, unsigned short nEffect);
	virtual BOOL GetEffectNR(const int nCamID, unsigned short* pnEffect);

	virtual BOOL SetEffectGC(const int nCamID, unsigned short nEffect);
	virtual BOOL GetEffectGC(const int nCamID, unsigned short* pnEffect);

	virtual BOOL SetEffectCM(const int nCamID, unsigned short nEffect);
	virtual BOOL GetEffectCM(const int nCamID, unsigned short* pnEffect);

	virtual BOOL SetEffectAWB(const int nCamID, unsigned short nEffect);
	virtual BOOL GetEffectAWB(const int nCamID, unsigned short* pnEffect);

	virtual BOOL SetEffectSmooth(const int nCamID, unsigned short nEffect);
	virtual BOOL GetEffectSmooth(const int nCamID, unsigned short* pnEffect);

	virtual BOOL SetEffectSharpen(const int nCamID, unsigned short nEffect);
	virtual BOOL GetEffectSharpen(const int nCamID, unsigned short* pnEffect);

	virtual BOOL SetEffectFPN(const int nCamID, unsigned short nEffect);
	virtual BOOL GetEffectFPN(const int nCamID, unsigned short* pnEffect);

	virtual BOOL SetEffectPRNU(const int nCamID, unsigned short nEffect);
	virtual BOOL GetEffectPRNU(const int nCamID, unsigned short* pnEffect);

	virtual BOOL SetEffectDPC(const int nCamID, unsigned short nEffect);
	virtual BOOL GetEffectDPC(const int nCamID, unsigned short* pnEffect);

	virtual BOOL SetColorGain(const int nCamID, const int nGainType, int nGainVal);
	virtual BOOL GetColorGain(const int nCamID, const int nGainType, int* pnGainVal);


	// Emulator Control
	BOOL AddEmulator(const INFO_EMUL* pstEmul);
	BOOL UpdateEmulator(const int nCamID, const INFO_EMUL* pstEmul);

	void DeleteEmulator(const TCHAR* pszName);
	void DeleteEmulator(const int nIdx);
	void ClearEmulator();

	BOOL SaveEmulator();
	BOOL GetEmulator(const int nCamID, INFO_EMUL* pstEmul);


protected:
	int GetEnableCamID();
	void ReleaseCamID(int nCamID);

	const int FindEmulator(const TCHAR* pszName);	// Name to index
	const int FindEmulatorFromID(const int nCamID);


protected:
	BOOL m_IdList[MAX_EMULCAMERA_COUNT];

	// Emulator
	std::vector<CEmulFile*> m_EmulDeviceList;
	CXmlEmulDevice m_XmlEmulDevice;


	void RefreshDeviceList();


};
