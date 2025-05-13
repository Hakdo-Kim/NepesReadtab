#pragma once
#include "CameraInterfaceDef.h"

typedef struct
{
	FuncAcquisitionEvent m_FuncAcq;
	void* m_pUserData;

}INFO_ARG;

class CConnect
{
public:
	CConnect();
	virtual ~CConnect();

	virtual const TYPE_NETWORK GetNetworkType();
	virtual BOOL IsConnected()	= 0;

	virtual BOOL Open(TYPE_NETWORK eNetwork) = 0;
	virtual BOOL Open(TYPE_NETWORK eNetwork, void* pReserved) = 0;
	virtual void Close() = 0;

	virtual int GetDeviceCount() = 0;
	virtual int GetDeviceIndex(const INFO_CONNECT_DEV* pDev) = 0;
	virtual int GetDeviceID(const TCHAR* pName) = 0;
	virtual BOOL GetDeviceInfo(int nIdx, INFO_CONNECT_DEV* pstDevice) = 0;
	virtual BOOL UpdateDeviceInfo(int nIdx, INFO_CONNECT_DEV* pstDevice) = 0;


	virtual BOOL ResearchDeviceInfo() = 0;


	// Device Information
	virtual BOOL GetFrameInfo(const int nIdx ,INFO_FRAME* pstFrame) = 0;
	virtual BOOL SetEventFunc(const int nIdx, FuncAcquisitionEvent pFunc, void* pUserData) = 0;


	virtual BOOL Start(const int nIdx, BOOL bSingle = FALSE) = 0;
	virtual void Stop(const int nIdx) = 0;
	
	virtual BOOL IsOpen(const int nIdx) = 0;
	virtual BOOL Open(const int nIdx) = 0;
	virtual void Close(const int nIdx) = 0;


	// Command Function
	virtual BOOL SetRegister(const int nIdx, const DWORD dwAddress, const DWORD dwValue, DWORD dwReserved) = 0;
	virtual BOOL GetRegister(const int nIdx, const DWORD dwAddress, DWORD* pdwValue, DWORD dwReserved) = 0;
	
	//
	virtual BOOL SetGain(const int nIdx, const int nGainType, const int nGainValue) = 0;
	virtual BOOL GetGain(const int nIdx, const int nGainType, int* pnGainValue) = 0;
	
	virtual BOOL SetEnableFrameRate(const int nIdx, const unsigned int nEnale) = 0;
	virtual BOOL GetEnableFrameRate(const int nIdx, unsigned int* pnEnale) = 0;

	virtual BOOL SetFrameRate(const int nIdx, const unsigned int nFrameRate) = 0;
	virtual BOOL GetFrameRate(const int nIdx, unsigned int* pnFrameRate) = 0;
	virtual BOOL GetMaxFrameRate(const int nIdx, unsigned int* pnFrameRate) = 0;


	virtual BOOL SetExposureTime(const int nIdx, const unsigned int nSetExposureTime) = 0;
	virtual BOOL GetExposureTime(const int nIdx, unsigned int* pnSetExposureTime) = 0;
	virtual BOOL GetExposureMaxTime(const int nIdx, unsigned int FrameRate, unsigned int* pnSetExposureTime) = 0;
	virtual BOOL ConvertExposureTime(const int nIdx, unsigned int nStep, double* pfUSec) = 0;

	virtual BOOL SetTriggerMode(const int nIdx, INFO_TRIGGER_PARA stTrigger) = 0;
	virtual BOOL GetTriggerMode(const int nIdx, INFO_TRIGGER_PARA* pstTrigger) = 0;

	virtual BOOL SetTriggerDelay(const int nIdx, int nDelay) = 0;


	virtual BOOL SaveUserset(const int nIdx, unsigned int nNumber) = 0;
	virtual BOOL LoadUserset(const int nIdx, unsigned int nNumber) = 0;
	
	virtual BOOL SetStrobeMode(const int nIdx, INFO_STROBE_PARA stStrobe) = 0;
	virtual BOOL GetStrobeMode(const int nIdx, INFO_STROBE_PARA* pstStrobe) = 0;
	
	virtual BOOL SetFlipMode(const int nIdx, unsigned short nMode) = 0;
	virtual BOOL GetFlipMode(const int nIdx, unsigned short* pnMode) = 0;
	
	virtual BOOL SetROI(const int nIdx, INFO_ROI_PARA stROI) = 0;
	virtual BOOL GetROI(const int nIdx, INFO_ROI_PARA* pstROI) = 0;
	
	virtual BOOL SetUsersetStartNo(const int nIdx, unsigned char nUsersetStartNo) = 0;
	virtual BOOL GetUsersetStartNo(const int nIdx, unsigned char* pnUsersetStartNo) = 0;

	virtual BOOL SetDataBit(const int nIdx, unsigned short nDataBit) = 0;
	virtual BOOL GetDataBit(const int nIdx, unsigned short* pnDataBit) = 0;

	virtual BOOL SetColorMode(const int nIdx, unsigned short nColorMode) = 0;
	virtual BOOL GetColorMode(const int nIdx, unsigned short* pnColorMode) = 0;

	virtual BOOL SetMTU(const int nIdx, unsigned int nMTU) = 0;
	virtual BOOL GetMTU(const int nIdx, unsigned int* pnMTU) = 0;

	virtual BOOL GetDiag(const int nIdx, void* pstDiag, const int nLen) = 0;
	virtual BOOL SetSWTrigger(const int nIdx) = 0;


	// LUT
	virtual BOOL SetLutMode(const int nIdx, unsigned short nMode) = 0;
	virtual BOOL GetLutMode(const int nIdx, unsigned short* pnMode) = 0;

	virtual BOOL WriteLut(const int nIdx, const INFO_LUT_PARA* pLutList, const int nLen, BOOL bEeprom) = 0;

	// Effect
	virtual BOOL SetEffectNR(const int nIdx, unsigned short nEffect) = 0;
	virtual BOOL GetEffectNR(const int nIdx, unsigned short* pnEffect) = 0;

	virtual BOOL SetEffectGC(const int nIdx, unsigned short nEffect) = 0;
	virtual BOOL GetEffectGC(const int nIdx, unsigned short* pnEffect) = 0;

	virtual BOOL SetEffectCM(const int nIdx, unsigned short nEffect) = 0;
	virtual BOOL GetEffectCM(const int nIdx, unsigned short* pnEffect) = 0;

	virtual BOOL SetEffectAWB(const int nIdx, unsigned short nEffect) = 0;
	virtual BOOL GetEffectAWB(const int nIdx, unsigned short* pnEffect) = 0;

	virtual BOOL SetEffectSmooth(const int nIdx, unsigned short nEffect) = 0;
	virtual BOOL GetEffectSmooth(const int nIdx, unsigned short* pnEffect) = 0;

	virtual BOOL SetEffectSharpen(const int nIdx, unsigned short nEffect) = 0;
	virtual BOOL GetEffectSharpen(const int nIdx, unsigned short* pnEffect) = 0;

	virtual BOOL SetEffectFPN(const int nIdx, unsigned short nEffect) = 0;
	virtual BOOL GetEffectFPN(const int nIdx, unsigned short* pnEffect) = 0;

	virtual BOOL SetEffectPRNU(const int nIdx, unsigned short nEffect) = 0;
	virtual BOOL GetEffectPRNU(const int nIdx, unsigned short* pnEffect) = 0;

	virtual BOOL SetEffectDPC(const int nIdx, unsigned short nEffect) = 0;
	virtual BOOL GetEffectDPC(const int nIdx, unsigned short* pnEffect) = 0;

	virtual BOOL SetColorGain(const int nIdx, const int nGainType, int nGainVal) = 0;
	virtual BOOL GetColorGain(const int nIdx, const int nGainType, int* pnGainVal) = 0;


protected:
	TYPE_NETWORK m_eNetwork;
	CRITICAL_SECTION m_CriticalSection;

	void EnterCriticalSection();
	void LeaveCriticalSection();


};
