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


	// Dynamic Dll Link
	HINSTANCE m_hDllInstance;
	BOOL OpenLibrary();
	void CloseLibrary();

	GC_ERROR (*pfGCGetInfo)(TL_INFO_CMD iInfoCmd, INFO_DATATYPE *piType, void *pBuffer, size_t *piSize);
	GC_ERROR (*pfGCGetLastError)(GC_ERROR *piErrorCode, char *sErrText, size_t *piSize);

	GC_ERROR (*pfGCInitLib)(void);
	GC_ERROR (*pfGCCloseLib)(void);

	GC_ERROR (*pfGCReadPort)(PORT_HANDLE hPort, uint64_t iAddress, void *pBuffer, size_t *piSize);
	GC_ERROR (*pfGCWritePort)(PORT_HANDLE hPort, uint64_t iAddress, const void *pBuffer, size_t *piSize);
	GC_ERROR (*pfGCGetPortURL)(PORT_HANDLE hPort, char *sURL, size_t *piSize);
	GC_ERROR (*pfGCGetPortInfo)(PORT_HANDLE hPort, PORT_INFO_CMD iInfoCmd, INFO_DATATYPE *piType, void *pBuffer, size_t *piSize);
	GC_ERROR (*pfGCRegisterEvent)(EVENTSRC_HANDLE hEventSrc, EVENT_TYPE iEventID, EVENT_HANDLE *phEvent);
	GC_ERROR (*pfGCUnregisterEvent)(EVENTSRC_HANDLE hEventSrc, EVENT_TYPE iEventID);
	GC_ERROR (*pfEventGetData)(EVENT_HANDLE hEvent, void *pBuffer, size_t *piSize, uint64_t iTimeout);
	GC_ERROR (*pfEventGetDataInfo)(EVENT_HANDLE hEvent, const void *pInBuffer, size_t iInSize, EVENT_DATA_INFO_CMD iInfoCmd, INFO_DATATYPE *piType, void *pOutBuffer, size_t *piOutSize);
	GC_ERROR (*pfEventGetInfo)(EVENT_HANDLE hEvent, EVENT_INFO_CMD iInfoCmd, INFO_DATATYPE *piType, void *pBuffer, size_t *piSize);
	GC_ERROR (*pfEventFlush)(EVENT_HANDLE hEvent);
	GC_ERROR (*pfEventKill)(EVENT_HANDLE hEvent);

	GC_ERROR (*pfTLOpen)(TL_HANDLE *phTL);
	GC_ERROR (*pfTLClose)(TL_HANDLE hTL);
	GC_ERROR (*pfTLGetInfo)(TL_HANDLE hTL, TL_INFO_CMD iInfoCmd, INFO_DATATYPE *piType, void *pBuffer, size_t *piSize);
	GC_ERROR (*pfTLGetNumInterfaces)(TL_HANDLE hTL, uint32_t *piNumIfaces);
	GC_ERROR (*pfTLGetInterfaceID)(TL_HANDLE hTL, uint32_t iIndex, char *sID, size_t *piSize);
	GC_ERROR (*pfTLGetInterfaceInfo)(TL_HANDLE hTL, const char *sIfaceID, INTERFACE_INFO_CMD iInfoCmd, INFO_DATATYPE *piType, void *pBuffer, size_t *piSize);
	GC_ERROR (*pfTLOpenInterface)(TL_HANDLE hTL, const char *sIfaceID, IF_HANDLE *phIface);
	GC_ERROR (*pfTLUpdateInterfaceList)(TL_HANDLE hTL, bool8_t *pbChanged, uint64_t iTimeout);

	GC_ERROR (*pfIFClose)(IF_HANDLE hIface);
	GC_ERROR (*pfIFGetInfo)(IF_HANDLE hIface, INTERFACE_INFO_CMD iInfoCmd, INFO_DATATYPE *piType, void *pBuffer, size_t *piSize);
	GC_ERROR (*pfIFGetNumDevices)(IF_HANDLE hIface, uint32_t *piNumDevices);
	GC_ERROR (*pfIFGetDeviceID)(IF_HANDLE hIface, uint32_t iIndex, char *sIDeviceID, size_t *piSize);
	GC_ERROR (*pfIFUpdateDeviceList)(IF_HANDLE hIface, bool8_t *pbChanged, uint64_t iTimeout);
	GC_ERROR (*pfIFGetDeviceInfo)(IF_HANDLE hIface, const char *sDeviceID, DEVICE_INFO_CMD iInfoCmd, INFO_DATATYPE *piType, void *pBuffer, size_t *piSize);
	GC_ERROR (*pfIFOpenDevice)(IF_HANDLE hIface, const char *sDeviceID, DEVICE_ACCESS_FLAGS iOpenFlags, DEV_HANDLE *phDevice);

	GC_ERROR (*pfDevGetPort)(DEV_HANDLE hDevice, PORT_HANDLE *phRemoteDevice);
	GC_ERROR (*pfDevGetNumDataStreams)(DEV_HANDLE hDevice, uint32_t *piNumDataStreams);
	GC_ERROR (*pfDevGetDataStreamID)(DEV_HANDLE hDevice, uint32_t iIndex, char *sDataStreamID, size_t *piSize);
	GC_ERROR (*pfDevOpenDataStream)(DEV_HANDLE hDevice, const char *sDataStreamID, DS_HANDLE *phDataStream);
	GC_ERROR (*pfDevGetInfo)(DEV_HANDLE hDevice, DEVICE_INFO_CMD iInfoCmd, INFO_DATATYPE *piType, void *pBuffer, size_t *piSize);
	GC_ERROR (*pfDevClose)(DEV_HANDLE hDevice);

	GC_ERROR (*pfDSAnnounceBuffer)(DS_HANDLE hDataStream, void *pBuffer, size_t iSize, void *pPrivate, BUFFER_HANDLE *phBuffer);
	GC_ERROR (*pfDSAllocAndAnnounceBuffer)(DS_HANDLE hDataStream, size_t iSize, void *pPrivate, BUFFER_HANDLE *phBuffer);
	GC_ERROR (*pfDSFlushQueue)(DS_HANDLE hDataStream, ACQ_QUEUE_TYPE iOperation);
	GC_ERROR (*pfDSStartAcquisition)(DS_HANDLE hDataStream, ACQ_START_FLAGS iStartFlags, uint64_t iNumToAcquire);
	GC_ERROR (*pfDSStopAcquisition)(DS_HANDLE hDataStream, ACQ_STOP_FLAGS iStopFlags);
	GC_ERROR (*pfDSGetInfo)(DS_HANDLE hDataStream, STREAM_INFO_CMD iInfoCmd, INFO_DATATYPE *piType, void *pBuffer, size_t *piSize);
	GC_ERROR (*pfDSGetBufferID)(DS_HANDLE hDataStream, uint32_t iIndex, BUFFER_HANDLE *phBuffer);
	GC_ERROR (*pfDSClose)(DS_HANDLE hDataStream);

	GC_ERROR (*pfDSRevokeBuffer)(DS_HANDLE hDataStream, BUFFER_HANDLE hBuffer, void **pBuffer, void **pPrivate);
	GC_ERROR (*pfDSQueueBuffer)(DS_HANDLE hDataStream, BUFFER_HANDLE hBuffer);
	GC_ERROR (*pfDSGetBufferInfo)(DS_HANDLE hDataStream, BUFFER_HANDLE hBuffer, BUFFER_INFO_CMD iInfoCmd, INFO_DATATYPE *piType, void *pBuffer, size_t *piSize);

	/* GenTL v1.1 */
	GC_ERROR (*pfGCGetNumPortURLs)(PORT_HANDLE hPort, uint32_t *piNumURLs);
	GC_ERROR (*pfGCGetPortURLInfo)(PORT_HANDLE hPort, uint32_t iURLIndex, URL_INFO_CMD iInfoCmd, INFO_DATATYPE *piType, void *pBuffer, size_t *piSize);
	GC_ERROR (*pfGCReadPortStacked)(PORT_HANDLE hPort, PORT_REGISTER_STACK_ENTRY *pEntries, size_t *piNumEntries);
	GC_ERROR (*pfGCWritePortStacked)(PORT_HANDLE hPort, PORT_REGISTER_STACK_ENTRY *pEntries, size_t *piNumEntries);
	/* GenTL v1.3 */
	GC_ERROR (*pfDSGetBufferChunkData)(DS_HANDLE hDataStream, BUFFER_HANDLE hBuffer, SINGLE_CHUNK_DATA *pChunkData, size_t *piNumChunks);



	GC_ERROR (*pfEnableFilterDriver)(unsigned char Enable);
	GC_ERROR (*pfGetFilterDriverStatus)(unsigned char* pStatus);
	GC_ERROR (*pfDeviceIPChange)(DEV_HANDLE hDevice, unsigned int nChangeIPAddress, unsigned int nSubnetMask, unsigned int nGateway);
	GC_ERROR (*pfSetMTU)(DEV_HANDLE hDevice, unsigned int nMTUSize);
	GC_ERROR (*pfGetMTU)(DEV_HANDLE hDevice, unsigned int* pMTUSize);

	GC_ERROR (*pfEEDiscoveryAllDevice)();
	GC_ERROR (*pfEEDiscoveryAllDeviceForIPSetting)();
	GC_ERROR (*pfEEOpenControlChannel)(DEV_HANDLE hDevice, unsigned char OnOff);
	GC_ERROR (*pfEEGetIFDevInformation)(IFMODULEINFO* pIFInformation, unsigned char* pnIFCount, DEVLISTINFO* pDevListInformation, DEVMODULEINFO* pDevInformation, unsigned char* pnDevCount); // ok
	GC_ERROR (*pfEEMemoryWrite)(DEV_HANDLE hDevice, unsigned int nAddress, unsigned char* pData, unsigned int Size);
	GC_ERROR (*pfGetDiagnosticData)(DEV_HANDLE hDevice, DiagnosticData* pDiagnosticData);
	
	void(*pfEEConvertColor)(unsigned char* pSrc, unsigned char* pDest, unsigned char* pColor, int width, int height, unsigned int PixelFormat);

	GC_ERROR (*pfEESetImageSizeROI)(DEV_HANDLE hDevice, unsigned int XStart, unsigned int YStart, unsigned int nWidth, unsigned int nHeight);
	GC_ERROR (*pfEESetImageSizeBinning)(DEV_HANDLE hDevice, unsigned int nWidth, unsigned int nHeight, unsigned char nMode);
	GC_ERROR (*pfEEProcessWB)(unsigned char* pImage, unsigned int nWidth, unsigned int nHeight, TL_WB_GAIN* pWBGain);
	GC_ERROR (*pfEEProcessAWB)(unsigned char* pImage, unsigned int nWidth, unsigned int nHeight);
	
	unsigned int(*pfEEBufferingEnable)(DEV_HANDLE hDevice, unsigned int nBufferedFrames);
	unsigned int(*pfEEGetNextBufferedImage)(DEV_HANDLE hDevice, char* ptrBuffer, unsigned int scBufSize);

	GC_ERROR (*pfEEReleaseBuffering)(DEV_HANDLE hDevice);
	GC_ERROR (*pfEEDefaultDeviceSetting)(DEV_HANDLE hDevice);
	GC_ERROR (*pfEEGetMINofVID)(DEV_HANDLE hDevice, uint64_t VID, void * ptrData);
	GC_ERROR (*pfEEGetMAXofVID)(DEV_HANDLE hDevice, uint64_t VID, void * ptrData);
	GC_ERROR (*pfEEGetDefaultofVID)(DEV_HANDLE hDevice, uint64_t VID, void * ptrData);
	GC_ERROR (*pfEEIsAvailableVID)(DEV_HANDLE hDevice, uint64_t VID, void * ptrData);
	GC_ERROR (*pfEEGetSupportedDevList)(char* ptrListBuf, unsigned int unScListBuf);
	GC_ERROR (*pfEESetUserLUTData)(DEV_HANDLE hDevice, unsigned char * ptrUserLUTdata);
	GC_ERROR (*pfEEGetLUTData)(DEV_HANDLE hDevice, unsigned int nLUTNum, unsigned char * ptrLUTdata);
	GC_ERROR (*pfEEWriteDPCTable)(DEV_HANDLE hDevice, unsigned char* ptrBinaryData, unsigned int nLength, unsigned int nBitPerPixel, unsigned char* ptrProgress, unsigned int nThresHold);
	GC_ERROR (*pfEECheckSupportedPixelformat)(DEV_HANDLE hDevice, unsigned int unPixelformat);

	int (*pfEventCallbackImageAcquisition)(DEV_HANDLE hDevice, CallBackAcquisitionEvent func, void * ptrUserData);



};


#endif