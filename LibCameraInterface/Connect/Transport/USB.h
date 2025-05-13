#ifndef __LP_USB_H__
#define __LP_USB_H__

#include "inc/UCamLibEx.h"
#include "CameraInterfaceDef.h"

typedef struct
{
	USBDEVINFO m_stUsbDevInfo;

	DWORD	SensorType;
	BOOL	bStart;

}INFO_USBDEV;

class CUSB
{
public:
	CUSB();
	~CUSB();

	BOOL Open();
	void Close();

	BOOL IsOpen();

	BOOL FindAllDevice();
	
	BOOL GetSensorType(const int nIdx, DWORD* pdwType);

	const int GetEnableDeviceCount();
	const INFO_USBDEV* GetDeviceModuleInfo(const int nIdx);

	BOOL SetRoi(const int nIdx, const int nX, const int nY, const int nW, const int nH);

	BOOL GetMaxWidth(const int nIdx, DWORD* pdwValue);
	BOOL GetMaxHeight(const int nIdx, DWORD* pdwValue);

	BOOL GetX(const int nIdx, DWORD* pdwValue);
	BOOL GetY(const int nIdx, DWORD* pdwValue);
	BOOL GetWidth(const int nIdx, DWORD* pdwValue);
	BOOL GetHeight(const int nIdx, DWORD* pdwValue);

	BOOL GetPixelFormat(const int nIdx, DWORD* pdwValue);
	BOOL GetColorFormat(const int nIdx, DWORD* pdwValue);

	BOOL SetEventCallbackImageAcquisition(const int nIdx, ReceiveCallback  pFunc, void* pUserData);

	BOOL IsStart(const int nIdx);
	BOOL Start(const int nIdx, BOOL bSingle = FALSE);
	void Stop(const int nIdx);
	
	BOOL ReadRegAddress(const int nIdx, const UCAM_REG_TYPE eType, const DWORD dwAddress, DWORD* pdwValue);
	BOOL WriteRegAddress(const int nIdx, const UCAM_REG_TYPE eType, const DWORD dwAddress, DWORD dwValue);

	

	BOOL SetGain(const int nIdx, int GainType, int GainValue);
	BOOL GetGain(const int nIdx, int GainType, int* GainValue);

	BOOL SetFrameRate(const int nIdx, unsigned int FrameRate);
	BOOL GetFrameRate(const int nIdx, unsigned int* FrameRate);

	BOOL SetExposureTime(const int nIdx, unsigned int ExposureTime);
	BOOL GetExposureTime(const int nIdx, unsigned int* ExposureTime);
	BOOL GetExposureMaxTime(const int nIdx, unsigned int FrameRate, unsigned int* ExposureTime);
	BOOL ConvertExposureTime(const int nIdx, DWORD dwStep, double* pfUsec);

	BOOL SetSWTrigger(const int nIdx);

	BOOL SetTriggerMode(const int nIdx, INFO_TRIGGER_PARA stTrigger);
	BOOL GetTriggerMode(const int nIdx, INFO_TRIGGER_PARA* stTrigger);

	BOOL SetTriggerDelay(const int nIdx, int nDelay);

	BOOL GetDiag(const int nIdx, INFO_DIAGONOSTICS_USB* pstDiag);

	BOOL SetStrobeMode(const int nIdx, INFO_STROBE_PARA stStrobe);
	BOOL GetStrobeMode(const int nIdx, INFO_STROBE_PARA* stStrobe);
	
	BOOL SetFlipMode(const int nIdx, unsigned short nMode);
	BOOL GetFlipMode(const int nIdx, unsigned short* nMode);

	BOOL SetDataBit(const int nIdx, unsigned short nDataBit);
	BOOL GetDataBit(const int nIdx, unsigned short* nDataBit);

	BOOL SetColorMode(const int nIdx, unsigned short nColorMode);
	BOOL GetColorMode(const int nIdx, unsigned short* pnColorMode);

	// Userset
	BOOL SaveUserset(const int nIdx, unsigned char nNumber);
	BOOL LoadUserset(const int nIdx, unsigned char nNumber);

	BOOL GetUsersetStartNo(const int nIdx, unsigned char* pValue);
	BOOL SetUsersetStartNo(const int nIdx, unsigned char Value);

	// LUT
	BOOL SetLutMode(const int nIdx, unsigned short nMode);
	BOOL GetLutMode(const int nIdx, unsigned short* pnMode);

	BOOL WriteLut(const int nIdx, const INFO_LUT_PARA* pLutList, const int nLen, BOOL bEeprom);

	// Effect
	BOOL SetEffectDPC(const int nIdx, unsigned short nEffect);
	BOOL GetEffectDPC(const int nIdx, unsigned short* pnEffect);

	BOOL SetEffectSharpen(const int nIdx, unsigned short nEffect);
	BOOL GetEffectSharpen(const int nIdx, unsigned short* pnEffect);

	BOOL SetEffectFPN(const int nIdx, unsigned short nEffect);
	BOOL GetEffectFPN(const int nIdx, unsigned short* pnEffect);

	BOOL SetEffectPRNU(const int nIdx, unsigned short nEffect);
	BOOL GetEffectPRNU(const int nIdx, unsigned short* pnEffect);



protected:
	BOOL GetDevicePortHandle(int nIdx, DWORD* pdwIp);

	BOOL ReadDword(DWORD dwIP, DWORD dwAddress, DWORD* pValue);
	BOOL WriteDword(DWORD dwIP, DWORD dwAddress, DWORD* pValue);

	BOOL		m_bInit;
	INFO_USBDEV	m_pstUSBDevInfo[MAX_CAMERA];
	LONGLONG	m_pLastSWTrigger[MAX_CAMERA];
	
	char		m_DeviceCount;
	char		m_IndexArray[MAX_CAMERA];
	char		m_SerialArray[MAX_CAMERA][SERIAL_CHAR_LENGTH + 1];
};


#endif