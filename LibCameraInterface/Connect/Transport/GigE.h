#ifndef __LP_GIGE_H__
#define __LP_GIGE_H__

#include "inc/LpGenTLGigE.h"

class CGigE
{
public:
	CGigE();
	~CGigE();

	BOOL Open();
	void Close();

	BOOL IsOpen();

	// Device Information
	BOOL FindAllDevice();	
	const int GetEnableDeviceCount();
	const DEVMODULEINFO* GetDeviceModuleInfo(const int nIdx);
	
	BOOL GetFirmwareVersion(const int nIdx, DWORD* pVersion);
	
	BOOL GetSensorType(const int nIdx, DWORD* pSensorType);
	BOOL UpdateIpAddress(const int nIdx, DWORD dwIpAddr, DWORD dwSubnet, DWORD dwGateWay);

	// 
	BOOL SetRoi(const int nIdx, const int nX, const int nY, const int nW, const int nH);

	BOOL GetMaxWidth(const int nIdx, DWORD* pdwValue);
	BOOL GetMaxHeight(const int nIdx, DWORD* pdwValue);
	
	BOOL GetX(const int nIdx, DWORD* pdwValue);
	BOOL GetY(const int nIdx, DWORD* pdwValue);
	BOOL GetWidth(const int nIdx, DWORD* pdwValue);
	BOOL GetHeight(const int nIdx, DWORD* pdwValue);

	BOOL GetPixelFormat(const int nIdx, DWORD* pdwValue);
	BOOL SetPixelFormat(const int nIdx, DWORD dwValue);

	//
	BOOL SetControlChannel(const int nIdx, BOOL bEnable);
	BOOL SetEventCallbackImageAcquisition(const int nIdx, CallBackAcquisitionEvent pFunc, void* pUserData);

	BOOL Start(const int nIdx, BOOL bSingle = FALSE);
	void Stop(const int nIdx);

	// 
	BOOL SetTrigger(const int nIdx);

	BOOL GetTriggerMode(const int nIdx, BYTE* pMode, BYTE* pType);
	BOOL SetTriggerMode(const int nIdx, BYTE nMode, BYTE nType);

	BOOL GetTriggerEnable(const int nIdx, BYTE* pEnable);
	BOOL SetTriggerEnable(const int nIdx, BYTE nEnable);

	BOOL GetTriggerPolarity(const int nIdx, BYTE* pPolarity);
	BOOL SetTriggerPolarity(const int nIdx, BYTE nPolarity);

	BOOL GetTriggerDelay(const int nIdx, DWORD* pDelay);
	BOOL SetTriggerDelay(const int nIdx, DWORD dwDelay);

	BOOL GetTriggerWidth(const int nIdx, DWORD* pWidth);
	BOOL SetTriggerWidth(const int nIdx, DWORD dwWidth);

	BOOL GetTriggerSource(const int nIdx, DWORD* pSrc);
	BOOL SetTriggerSource(const int nIdx, DWORD dwSrc);

	//
	BOOL GetStrobeMode(const int nIdx, BYTE* pMode, BYTE* pType, BYTE* pPolarity);
	BOOL SetStrobeMode(const int nIdx, BYTE nMode, BYTE nType, BYTE nPolarity);

	BOOL GetStrobeEnable(const int nIdx, BYTE* pEnable);
	BOOL SetStrobeEnable(const int nIdx, BYTE nEnable);

	BOOL GetStrobeType(const int nIdx, BYTE* pType);
	BOOL SetStrobeType(const int nIdx, BYTE nType);

	BOOL GetStrobePolarity(const int nIdx, BYTE* pPolarity);
	BOOL SetStrobePolarity(const int nIdx, BYTE nPolarity);

	BOOL GetStrobeDelay(const int nIdx, DWORD* pDelay);
	BOOL SetStrobeDelay(const int nIdx, DWORD dwDelay);

	BOOL GetStrobeWidth(const int nIdx, DWORD* pWidth);
	BOOL SetStrobeWidth(const int nIdx, DWORD dwWidth);

	//
	BOOL GetGain(const int nIdx, DWORD* pGain);
	BOOL SetGain(const int nIdx, DWORD dwGain);

	BOOL GetGainRed(const int nIdx, DWORD* pGain);
	BOOL SetGainRed(const int nIdx, DWORD dwGain);

	BOOL GetGainGreen(const int nIdx, DWORD* pGain);
	BOOL SetGainGreen(const int nIdx, DWORD dwGain);

	BOOL GetGainGreen2(const int nIdx, DWORD* pGain);
	BOOL SetGainGreen2(const int nIdx, DWORD dwGain);

	BOOL GetGainBlue(const int nIdx, DWORD* pGain);
	BOOL SetGainBlue(const int nIdx, DWORD dwGain);

	BOOL GetGainAnalog(const int nIdx, DWORD* pGain);
	BOOL SetGainAnalog(const int nIdx, DWORD dwGain);
	
	BOOL GetAGC(const int nIdx, DWORD* pAgc);
	BOOL SetAGC(const int nIdx, DWORD dwAgc);

	BOOL GetAEC(const int nIdx, DWORD* pAec);
	BOOL SetAEC(const int nIdx, DWORD dwAec);

	BOOL GetHBlank(const int nIdx, DWORD* pBlank);
	BOOL SetHBlank(const int nIdx, DWORD dwBlank);

	BOOL GetVBlank(const int nIdx, DWORD* pBlank);
	BOOL SetVBlank(const int nIdx, DWORD dwBlank);

	BOOL GetMirror(const int nIdx, DWORD* pValue);
	BOOL SetMirror(const int nIdx, DWORD dwValue);

	BOOL ProcessWB(BYTE* pImg, DWORD dwWidth, DWORD dwHeight, BYTE nRed, BYTE nGreen, BYTE nBlue);
	BOOL ProcessAWB(BYTE* pImg, DWORD dwWidth, DWORD dwHeight);

	BOOL GetAWB(const int nIdx, BOOL* pOn);
	BOOL SetAWB(const int nIdx, BOOL bOn);

	BOOL GetMinVID(const int nIdx, DWORD VID, DWORD* pMin);
	BOOL GetMaxVID(const int nIdx, DWORD VID, DWORD* pMax);
		
	BOOL GetDPC(const int nIdx, DWORD* pDpc);
	BOOL SetDPC(const int nIdx, DWORD dwDpc);

	BOOL GetPRNU(const int nIdx, DWORD* pPrnu);
	BOOL SetPRNU(const int nIdx, DWORD dwPrnu);

	BOOL GetLPF(const int nIdx, DWORD* pLpf);
	BOOL SetLPF(const int nIdx, DWORD dwLpf);

	BOOL GetColorMatrix(const int nIdx, DWORD* pColorMatrix);
	BOOL SetColorMatrix(const int nIdx, DWORD dwColorMatrix);

	BOOL GetGamma(const int nIdx, DWORD* pGamma);
	BOOL SetGamma(const int nIdx, DWORD dwGamma);

	BOOL GetGammaTable(const int nIdx, DWORD* pTable);
	BOOL SetGammaTable(const int nIdx, DWORD dwTable);

	BOOL GetLUT(const int nIdx, DWORD* pLut);
	BOOL SetLUT(const int nIdx, DWORD dwLut);

	BOOL GetLUTTable(const int nIdx, DWORD* pTable);
	BOOL SetLUTTable(const int nIdx, DWORD dwTable);

	BOOL GetLUTData(const int nIdx, int nLutIdx, BYTE* pData, int nLen);
	BOOL SetLUTData(const int nIdx, BYTE* pData, int nLen);
	

	//
	BOOL GetExposureTime(const int nIdx, DWORD* pExTime);
	BOOL GetExposureMaxTime(const int nIdx, DWORD* pMaxExTime);
	BOOL SetExposureTime(const int nIdx, DWORD dwExTime);
	
	BOOL ConvertExposureTime(const int nIdx, DWORD dwStep, double* pfUsec);

	BOOL GetDiag(const int nIdx, DiagnosticData* pstDiag);

	BOOL GetEnableFps(const int nIdx, DWORD* pFps);
	BOOL SetEnableFps(const int nIdx, DWORD dwFps);

	BOOL GetFps(const int nIdx, DWORD* pFps);
	BOOL SetFps(const int nIdx, DWORD dwFps);

	BOOL GetMaxFps(const int nIdx, DWORD* pFps);
	
	// Userset
	BOOL LoadDefaultUserset(const int nIdx);
	
	BOOL GetBoostUserset(const int nIdx, DWORD* pdwBoost);
	BOOL SetBoostUserset(const int nIdx, DWORD dwBoost);

	BOOL LoadUserset(const int nIdx, DWORD dwUserset);
	BOOL SaveUserset(const int nIdx, DWORD dwUserset);

	BOOL GetUserset(const int nIdx, DWORD* pUserset);
	BOOL SetUserset(const int nIdx, DWORD dwUserset);

	//
	void ConvertColor(BYTE* pSrc, BYTE* pDest, BYTE* pColor, int nW, int nH, DWORD dwPixelFormat);
	
	BOOL GetBinning(const int nIdx, DWORD* pdwMode);
	BOOL SetBinning(const int nIdx, int nW, int nH, BYTE nMode);

	BOOL GetControlChannelPrivilege(const int nIdx, DWORD* pdwValue);

	BOOL GetMTU(const int nIdx, DWORD* pdwMtu);
	BOOL SetMTU(const int nIdx, DWORD dwMtu);

	BOOL SetHeartbeat(const int nIdx, DWORD dwValue);

	BOOL SetFilterDriverOnOff(BOOL bOnOff);
	BOOL GetFilterDriverOnOff(BOOL* pbOnOff);

	//
	BOOL ReadRegAddress(const int nIdx, const DWORD dwAddress, DWORD* pdwValue);
	BOOL WriteRegAddress(const int nIdx, const DWORD dwAddress, DWORD dwValue);

protected:
	BOOL GetDevicePortHandle(int nIdx, DWORD* pdwIp);

	BOOL ReadDword(DWORD dwIP, DWORD dwAddress, DWORD* pValue);
	BOOL WriteDword(DWORD dwIP, DWORD dwAddress, DWORD* pValue);

	void*			m_hTLHandle;
	BOOL			m_bInit;
	IFMODULEINFO	m_pstIfModuleInfo[MAX_INTERFACE_MODULE];
	BYTE			m_nIfModuleInfo;
	DEVLISTINFO		m_pstDevInfo[MAX_INTERFACE_MODULE];
	DEVMODULEINFO	m_pstDevModuleInfo[MAX_INTERFACE_MODULE];
	BYTE			m_nDevModuleInfo;
	BOOL			m_bFilterDriverOnOff;

	LONGLONG		m_pLastSWTrigger[MAX_INTERFACE_MODULE];

	BOOL			m_pbWorkingModule[MAX_INTERFACE_MODULE];


	BOOL m_bStart;

};


#endif