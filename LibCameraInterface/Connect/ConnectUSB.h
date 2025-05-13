#pragma once

#include "Connect.h"

#include "Transport/USB.h"

class CConnectUSB : public CConnect
{
public:
	CConnectUSB();
	virtual ~CConnectUSB();

	static void CALLBACK AcquisitionEventHandler(unsigned char* pBuffer, unsigned int nSize, void* lpArg);

	virtual BOOL IsConnected();

	virtual BOOL Open(TYPE_NETWORK eNetwork);
	virtual BOOL Open(TYPE_NETWORK eNetwork, void* pReserved);
	virtual void Close();

	virtual int GetDeviceCount();
	virtual int GetDeviceIndex(const INFO_CONNECT_DEV* pDev);
	virtual int GetDeviceID(const TCHAR* pName);
	virtual BOOL GetDeviceInfo(int nIdx, INFO_CONNECT_DEV* pstDevice);
	virtual BOOL UpdateDeviceInfo(int nIdx, INFO_CONNECT_DEV* pstDevice);
	
	virtual BOOL ResearchDeviceInfo();


	// Device Information
	virtual BOOL GetFrameInfo(const int nIdx, INFO_FRAME* pstFrame);
	virtual BOOL SetEventFunc(const int nIdx, FuncAcquisitionEvent pFunc, void* pUserData);

	virtual BOOL Start(const int nIdx, BOOL bSingle = FALSE);
	virtual void Stop(const int nIdx);

	virtual BOOL IsOpen(const int nIdx);
	virtual BOOL Open(const int nIdx);
	virtual void Close(const int nIdx);


	// Command Function
	virtual BOOL SetGain(const int nIdx, const int nGainType, const int nGainValue);
	virtual BOOL GetGain(const int nIdx, const int nGainType, int* nGainValue);

	virtual BOOL SetEnableFrameRate(const int nIdx, const unsigned int nEnale);
	virtual BOOL GetEnableFrameRate(const int nIdx, unsigned int* pnEnale);

	virtual BOOL SetFrameRate(const int nIdx, const unsigned int nFrameRate);
	virtual BOOL GetFrameRate(const int nIdx, unsigned int* nFrameRate);
	virtual BOOL GetMaxFrameRate(const int nIdx, unsigned int* pnFrameRate);

	virtual BOOL SetExposureTime(const int nIdx, const unsigned int nSetExposureTime);
	virtual BOOL GetExposureTime(const int nIdx, unsigned int* nSetExposureTime);
	virtual BOOL GetExposureMaxTime(const int nIdx, unsigned int FrameRate, unsigned int* pnSetExposureTime);
	virtual BOOL ConvertExposureTime(const int nIdx, unsigned int nStep, double* pfUSec);
	
	virtual BOOL SetTriggerMode(const int nIdx, INFO_TRIGGER_PARA stTrigger);
	virtual BOOL GetTriggerMode(const int nIdx, INFO_TRIGGER_PARA* stTrigger);

	virtual BOOL SetTriggerDelay(const int nIdx, int nDelay);

	virtual BOOL SaveUserset(const int nIdx, unsigned int nNumber);
	virtual BOOL LoadUserset(const int nIdx, unsigned int nNumber);

	virtual BOOL SetStrobeMode(const int nIdx, INFO_STROBE_PARA stStrobe);
	virtual BOOL GetStrobeMode(const int nIdx, INFO_STROBE_PARA* stStrobe);

	virtual BOOL SetFlipMode(const int nIdx, unsigned short nMode);
	virtual BOOL GetFlipMode(const int nIdx, unsigned short* nMode);

	virtual BOOL SetROI(const int nIdx, INFO_ROI_PARA stROI);
	virtual BOOL GetROI(const int nIdx, INFO_ROI_PARA* stROI);

	virtual BOOL SetUsersetStartNo(const int nIdx, unsigned char nUsersetStartNo);
	virtual BOOL GetUsersetStartNo(const int nIdx, unsigned char* nUsersetStartNo);

	virtual BOOL SetRegister(const int nIdx, const DWORD dwAddress, const DWORD dwValue, DWORD dwReserved);
	virtual BOOL GetRegister(const int nIdx, const DWORD dwAddress, DWORD* pdwValue, DWORD dwReserved);

	virtual BOOL SetDataBit(const int nIdx, unsigned short nDataBit);
	virtual BOOL GetDataBit(const int nIdx, unsigned short* pnDataBit);

	virtual BOOL SetColorMode(const int nIdx, unsigned short nColorMode);
	virtual BOOL GetColorMode(const int nIdx, unsigned short* pnColorMode);

	virtual BOOL SetMTU(const int nIdx, unsigned int nMTU);
	virtual BOOL GetMTU(const int nIdx, unsigned int* pnMTU);

	virtual BOOL GetDiag(const int nIdx, void* pstDiag, const int nLen);
	virtual BOOL SetSWTrigger(const int nIdx);


	// LUT
	virtual BOOL SetLutMode(const int nIdx, unsigned short nMode);
	virtual BOOL GetLutMode(const int nIdx, unsigned short* pnMode);

	virtual BOOL WriteLut(const int nIdx, const INFO_LUT_PARA* pLutList, const int nLen, BOOL bEeprom);

	// Effect
	virtual BOOL SetEffectNR(const int nIdx, unsigned short nEffect);
	virtual BOOL GetEffectNR(const int nIdx, unsigned short* pnEffect);

	virtual BOOL SetEffectGC(const int nIdx, unsigned short nEffect);
	virtual BOOL GetEffectGC(const int nIdx, unsigned short* pnEffect);

	virtual BOOL SetEffectCM(const int nIdx, unsigned short nEffect);
	virtual BOOL GetEffectCM(const int nIdx, unsigned short* pnEffect);

	virtual BOOL SetEffectAWB(const int nIdx, unsigned short nEffect);
	virtual BOOL GetEffectAWB(const int nIdx, unsigned short* pnEffect);

	virtual BOOL SetEffectSmooth(const int nIdx, unsigned short nEffect);
	virtual BOOL GetEffectSmooth(const int nIdx, unsigned short* pnEffect);

	virtual BOOL SetEffectSharpen(const int nIdx, unsigned short nEffect);
	virtual BOOL GetEffectSharpen(const int nIdx, unsigned short* pnEffect);

	virtual BOOL SetEffectFPN(const int nIdx, unsigned short nEffect);
	virtual BOOL GetEffectFPN(const int nIdx, unsigned short* pnEffect);

	virtual BOOL SetEffectPRNU(const int nIdx, unsigned short nEffect);
	virtual BOOL GetEffectPRNU(const int nIdx, unsigned short* pnEffect);

	virtual BOOL SetEffectDPC(const int nIdx, unsigned short nEffect);
	virtual BOOL GetEffectDPC(const int nIdx, unsigned short* pnEffect);

	virtual BOOL SetColorGain(const int nIdx, const int nGainType, int nGainVal);
	virtual BOOL GetColorGain(const int nIdx, const int nGainType, int* pnGainVal);

protected:
	 CUSB	   m_USB;

	 INFO_ARG m_ArgList[MAX_CAMERA_INTERFACE];
	 int m_nTempCount;	// Temparary Device Count

};