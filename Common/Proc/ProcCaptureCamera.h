#pragma once

#include "ProcessDef.h"
#include "ProcBuffer.h"

#include "Camera/CameraInterface.h"
#include "Video/VideoDef.h"
#include "Video/VideoCaptureCallback.h"

#include <list>
#include <queue>
#include <mutex>


typedef enum
{
	TYPE_STATE_PROCESS_NONE,

	TYPE_STATE_PROCESS_START,
	TYPE_STATE_PROCESS_STOP,


} TYPE_STATE_PROCESS;

typedef struct
{
	DWORD m_dwFrom;
	DWORD m_dwTo;

} INFO_TIMEOUT_RANGE;


class CProcCaptureCamera
{
public:
	CProcCaptureCamera();
	~CProcCaptureCamera();

	static void CALLBACK AcquisitionEventHandler(unsigned char* pBuffer, unsigned int nSize, void* pReserved, void* lpArg);
	void SetAcquisitionEvent();

	BOOL SetAcquisitionData(unsigned char* pBuffer, unsigned int nSize);

	BOOL CreateCameraProcess(HCAMERA hCamera, int nCamId, HWND hWnd, INFO_VIDEODEV_ARG* pVideoArg);
	void DestoryCameraProcess();

	BOOL CheckConnectInfo(const INFO_CONNECT_DEV* pstDevice);

	BOOL Start(BOOL bSingleFrame=FALSE);
	void Stop();
	void Close();

	HWND GetDisplayWindowHandle();

	
	const TYPE_STATE_PROCESS GetProcessState();
	const INFO_FRAME* GetFrameInfo();
	void UpdateFrameInfo();
	const TYPE_NETWORK GetCameraNetwork();
	const int GetCameraId();

	void SkipCameraFrame(BOOL bSkip);

	// Command
	BOOL ReadRegDword(const DWORD dwAddress, DWORD* pdwValue, DWORD dwReserved);
	BOOL WriteRegDword(const DWORD dwAddress, const DWORD dwValue, DWORD dwReserved);

	//
	BOOL SetGain(const int nGainType, const int nGainVal);
	BOOL GetGain(int nGainType, int* pnGainVal);

	BOOL SetEnableFrameRate(const BOOL bEnable);
	BOOL GetEnableFrameRate(BOOL* pbEnable);

	BOOL SetFrameRate(const unsigned int nFrameRate);
	BOOL GetFrameRate(unsigned int* pnFrameRate);
	BOOL GetMaxFrameRate(unsigned int* pnFrameRate);

	BOOL SetExposureTime(const unsigned int nExposureTime);
	BOOL GetExposureTime(unsigned int* pnExposureTime);
	BOOL GetExposureMaxTime(unsigned int nFrameRate, unsigned int* pnExposureTime);
	BOOL ConvertExposureTime(unsigned int nStep, double* pfUSec); // Step to Time

	BOOL SetTriggerMode(INFO_TRIGGER_PARA stTrigger);
	BOOL GetTriggerMode(INFO_TRIGGER_PARA* pstTrigger);

	BOOL SetTriggerDelay(int nDelay);


	BOOL SaveUserset(const int nNumber);
	BOOL LoadUserset(const int nNumber);

	BOOL SetStrobeMode(INFO_STROBE_PARA stStrobe);
	BOOL GetStrobeMode(INFO_STROBE_PARA* pstStrobe);

	BOOL SetFlipMode(unsigned short nMode);
	BOOL GetFlipMode(unsigned short* pnMode);

	BOOL SetROI(INFO_ROI_PARA stROI);
	BOOL GetROI(INFO_ROI_PARA* pstROI);

	BOOL SetUsersetStartNo(unsigned char nUsersetStartNo);
	BOOL GetUsersetStartNo(unsigned char* pnUsersetStartNo);

	BOOL SetDataBit(unsigned short nDataBit);
	BOOL GetDataBit(unsigned short* pnDataBit);

	BOOL SetColorMode(unsigned short nColorMode);
	BOOL GetColorMode(unsigned short* pnColorMode);

	BOOL SetMTU(unsigned int nMTU);
	BOOL GetMTU(unsigned int* pnMTU);

	BOOL GetDiag(void* pstDiag, int nLen);
	BOOL SetSWTrigger();
	// Effect
	BOOL SetEffectNR(unsigned short nEffect);
	BOOL GetEffectNR(unsigned short* pnEffect);

	BOOL SetEffectGC(unsigned short nEffect);
	BOOL GetEffectGC(unsigned short* pnEffect);

	BOOL SetEffectCM(unsigned short nEffect);
	BOOL GetEffectCM(unsigned short* pnEffect);

	BOOL SetEffectAWB(unsigned short nEffect);
	BOOL GetEffectAWB(unsigned short* pnEffect);

	BOOL SetEffectSmooth(unsigned short nEffect);
	BOOL GetEffectSmooth(unsigned short* pnEffect);

	BOOL SetEffectSharpen(unsigned short nEffect);
	BOOL GetEffectSharpen(unsigned short* pnEffect);

	BOOL SetEffectFPN(unsigned short nEffect);
	BOOL GetEffectFPN(unsigned short* pnEffect);

	BOOL SetEffectPRNU(unsigned short nEffect);
	BOOL GetEffectPRNU(unsigned short* pnEffect);

	BOOL SetEffectDPC(unsigned short nEffect);
	BOOL GetEffectDPC(unsigned short* pnEffect);

	BOOL SetColorGain(const int nGainType, int nGainVal);
	BOOL GetColorGain(const int nGainType, int* pnGainVal);


protected:
	static DWORD WINAPI ThreadProc(LPVOID lpArg);
	DWORD ThreadProc(void);

	INFO_IMAGE* AllocImageBuffer(int nMinimum = -1);
	void ReleaseImageBuffer(INFO_IMAGE* pstBuf);
	void ResetImageBuffer();

	void SetProcessState(TYPE_STATE_PROCESS eState);


protected:
	BOOL	m_bStop;
	BOOL	m_bSkipFrame;

	HCAMERA		 m_hCamera;
	TYPE_NETWORK m_eNetwork;
	int			 m_nCameraId;

	INFO_FRAME	m_stFrame;
	HWND		m_hWnd;

	DWORD		m_dwCurrentTick;

	CProcBuffer	m_ProcessBuffer;

	std::queue<INFO_IMAGE*> m_BufferQueue;
	std::mutex m_BufferMutex;

	CVideoCaptureCallback m_VideoCallback;
	
	
	// Thread - Display
	HANDLE	m_hThread;
	HANDLE	m_hEvent;
	HANDLE	m_hStopEvent;

	// State
	TYPE_STATE_PROCESS m_eProcessState;


#ifdef TRIGGER_TIMEOUT
protected:
	static DWORD WINAPI ThreadTimeOutProc(LPVOID lpArg);
	DWORD ThreadTimeOutProc(void);

	void InitTimeOutDeviceInfo();
	BOOL RefreshTimeOutDevice(const INFO_CONNECT_DEV* pstDevice, INFO_TRIGGER_PARA& stTrigger, DWORD dwMtu );

	// Thread - TimeOut
	HANDLE	m_hThreadTimeOut;
	HANDLE	m_hEventTimeOut;

	BOOL	m_bCheckTimeOut;
	BOOL	m_bWaitAcq;
	DWORD	m_dwTimeOut;

	BOOL	m_bSearchDevice;

	INFO_CONNECT_DEV* m_pstTimeOutDevice;
	INFO_TIMEOUT_RANGE m_stTimeoutRange;
public:
	void SetEnableTriggerTimeOut(BOOL bEnable);
	BOOL GetEnableTriggerTimeOut();

	void SetTimeTriggerTimeOut(DWORD dwMsec);
	DWORD GetTimeTriggerTimeOut();
#endif

public:
#if defined(ENABLE_CAMERA_LIBRARY_BASLER)
	BOOL GetCameraInformation(INFO_OTHER_CATEGORY* pstRootCategory);
	const INFO_OTHER_IF* GetCameraInformation(const TCHAR* szName);

	BOOL GetCameraValue(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue);
	BOOL SetCameraValue(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue);
#endif

};