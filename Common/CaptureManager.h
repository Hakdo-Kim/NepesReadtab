#pragma once

#include "Camera/CameraInterface.h"
#include "Camera/CameraDevice.h"
#include "Proc/ProcCaptureCamera.h"
#include "Video/VideoDef.h"
#include "Xml/Xml.h"
#include "Log/Log.h"
#include "Log/LogHeater.h"
#include "Serial/SerialCtrl.h"
#include "Ethernet/EthernetClient.h"
#include "Ethernet/EthernetServer.h"

#include "Inspection/Inspection.h"

#include "Common.h"
#include "CommonCapture.h"

#include <queue>

typedef enum TYPE_PLCPROTOCOL
{
	TYPE_PLCPROTOCOL_NONE,
	TYPE_PLCPROTOCOL_SIMULATION,
	TYPE_PLCPROTOCOL_TCPIP,
} _TYPE_PLCPROTOCOL;

typedef enum TYPE_PLCCONTROL
{
	TYPE_PLCCONTROL_NONE,
	TYPE_PLCCONTROL_Utility,
	TYPE_PLCCONTROL_Program,
} _TYPE_PLCCONTROL;

typedef enum 
{
	TYPE_STROBETYPE_A,
	TYPE_STROBETYPE_B,
} TYPE_STROBETYPE;

typedef struct
{
	// Capture Process
	DWORD m_dwProcID;
	
	// Camera
	TYPE_NETWORK m_eNetwork;
	int m_nCamID;
	INFO_CONNECT_DEV* m_pstDevice;

} INFO_CAPTUREPROC;

typedef struct
{
	INFO_VIDEODEV_ARG m_VideoDev;
	void* m_pArqument;
	
	HWND m_hWnd;

} INFO_CAPTUREVIDEO;

typedef struct
{
	void* m_pArgument;
	DWORD m_dwProcID;

} INFO_VIDEOARG;


class CCaptureManager
{
protected:
	static CCaptureManager* pInstance;
	CCaptureManager();

	CRITICAL_SECTION	m_CriticalSection;

	CProcCaptureCamera*	m_pCameraProcess[MAX_CAMERA_INTERFACE];
	INFO_CAPTUREPROC	m_pCaptureProc[MAX_CAMERA_INTERFACE];
	
	INFO_CAPTUREPROC*	m_pCapturePosition[TYPE_CAMERAPOS_MAX];
	INFO_CAPTUREVIDEO	m_stCaptureVideo;


	HCAMERA				m_pCamera[TYPE_NETWORK_MAX];

	CSerialCtrl			m_pStrobeCtrl[TYPE_CAMERAPOS_MAX];
	CEthernet*			m_pCommunicatePort;

	FuncNotifySerialListener m_pFuncSerialListener;
	void* m_pArgument;

	CString				m_szOptionFilePath;
	INFO_OPTION			m_stOption;
	INFO_OPTIONETC		m_stOptionEtc;
	INFO_SUMMARY		m_stResultSummary;
	INFO_SCENARIO		m_stScenario;
	INFO_STROBE			m_stStrobe;

	CInspection			m_Inspection;
	HANDLE				m_hFile_Total;

	

#ifdef DEF_FREERUN_CAPTURE
	BOOL				m_bReadySnapCapture;
	BOOL				m_bReadySnapCaptureFirst;
	BOOL				m_bReadySnapCaptureSecond;

	BOOL				m_bSingeSnapCapture;
#endif
public:
	CCameraDevice		m_CameraDevice;		// Default Information
	CXml				m_Xml;
	CLog				m_Log;
	CLogHeater			m_LogHeater;

	BOOL				m_bAlarmFlag;

	queue<INFO_SUMMARY_TOTAL_FLAG>	m_SummaryFirstQueue;
	queue<INFO_SUMMARY_TOTAL_FLAG>	m_SummarySecondQueue;

	int					m_eStrobeControllerType;

#ifdef USE_PLC_MXCOMPONENT
	BOOL				m_bMXComponentOpenCom;
	HWND				m_hTargetMXComModuleWnd;
	HWND				m_hNetPassMainDlgWnd;

	int					m_ePLCProtocolType;
	int					m_ePLCControlType;
	int					m_nPLCStationNumber;
	CString				m_strPLCHostAddress;

	int					m_eSelectLine;
	int					m_eActionState;

	BOOL				m_bFirstCameraReverseX;
	BOOL				m_bFirstCameraReverseY;
	BOOL				m_bSecondCameraReverseX;
	BOOL				m_bSecondCameraReverseY;

public:
	BOOL				GetMXComponentOpenCom() { return m_bMXComponentOpenCom; }
	void				SetMXComponentOpenCom(BOOL bMXComponentOpenCom) { m_bMXComponentOpenCom = bMXComponentOpenCom; }
	HWND				GetNetPassMainDlgWnd() { return m_hNetPassMainDlgWnd; }
	void				SetNetPassMainDlgWnd(HWND hWnd) { m_hNetPassMainDlgWnd = hWnd; }
	HWND				GetTargetMXComModuleWnd() { return m_hTargetMXComModuleWnd; }
	void				SetTargetMXComModuleWnd(HWND hWnd) { m_hTargetMXComModuleWnd = hWnd; }

	int					GetPLCProtocolType() { return m_ePLCProtocolType; }
	void				SetPLCProtocolType(int ePLCProtocolType) { m_ePLCProtocolType = ePLCProtocolType; }
	int					GetPLCControlType() { return m_ePLCControlType; }
	void				SetPLCControlType(int ePLCControlType) { m_ePLCControlType = ePLCControlType; }
	int					GetPLCStationNumber() { return m_nPLCStationNumber; }
	void				SetPLCStationNumber(int nStationNumber) { m_nPLCStationNumber = nStationNumber; }
	CString				GetPLCHostAddress() { return m_strPLCHostAddress; }
	void				SetPLCHostAddress(CString strPLCHostAddress) { m_strPLCHostAddress = strPLCHostAddress; }

	int					GetSelectLineInfo() { return m_eSelectLine; }
	void				SetSelectLineInfo(int eSelectLine) { m_eSelectLine = eSelectLine; }
	int					GetActionState() { return m_eActionState; }
	void				SetActionState(int eActionState) { m_eActionState = eActionState; }

	BOOL				GetFirstCameraReverseX() { return m_bFirstCameraReverseX; }
	void				SetFirstCemaraReverseX(BOOL bReverseX) { m_bFirstCameraReverseX = bReverseX; }
	BOOL				GetFirstCameraReverseY() { return m_bFirstCameraReverseY; }
	void				SetFirstCemaraReverseY(BOOL bReverseY) { m_bFirstCameraReverseY = bReverseY; }
	BOOL				GetSecondCameraReverseX() { return m_bSecondCameraReverseX; }
	void				SetSecondCemaraReverseX(BOOL bReverseX) { m_bSecondCameraReverseX = bReverseX; }
	BOOL				GetSecondCameraReverseY() { return m_bSecondCameraReverseY; }
	void				SetSecondCemaraReverseY(BOOL bReverseY) { m_bSecondCameraReverseY = bReverseY; }
#endif

public:
	virtual ~CCaptureManager();

	static CCaptureManager* GetInstance();
	void				ReleaseInstance();

	BOOL				InitLibrary();
	void				DeinitLibrary();

	/// Capture Camera Connection
	BOOL				CreateCaptureConnection();
	void				CloseCaptureConnection();
	int					ResearchCaptureConnection(TYPE_NETWORK eNetwork);

	BOOL				StartCaptureConnection();
	void				StopCaptureConnection();
	void				StopAllCamera();


	const INFO_CAPTUREPROC* GetCapturePosition(TYPE_CAMERAPOS eType);
	BOOL				SetCapturePosition(TYPE_CAMERAPOS eType, TYPE_NETWORK eNetwork, int nCamId);

	TYPE_CAMERAPOS		GetCapturePosByProc(const DWORD dwProcID);

	void				UpdateCaptureVideo(INFO_CAPTUREVIDEO stVideo);
	//*/
	// Connect
	BOOL				IsEnableConnection(TYPE_NETWORK eNetwork);

	BOOL				CreateConnection(TYPE_NETWORK eNetwork);
	void				DestoryConnection(TYPE_NETWORK eNetwork);


	int					GetConnectedDeviceCount(const TYPE_NETWORK eNetwork);
	int					GetConnectedDeviceID(const TYPE_NETWORK eNetwork, const TCHAR* pszName);
	BOOL				GetConnectedDeviceInfo(const TYPE_NETWORK eNetwork, int nCameraId, INFO_CONNECT_DEV* pstDevice);
	
	BOOL				FindConnectedDevice(const TYPE_NETWORK eNetwork, INFO_CONNECT_DEV* pstDevice);
	BOOL				ResearchConnectedDevice(const TYPE_NETWORK eNetwork);

	//Device Default Information
	BOOL				GetCurrentDeviceInfo(TYPE_NETWORK eNetwork, const TCHAR* pszName, INFO_DEFDEV* pstDefDev, BOOL bReload);
	


	// Device Information
	BOOL				GetImageFrameInfo(const int nProcessId, INFO_FRAME* pstFrame);
	void				UpdateImageFrameInfo(const int nProcessId);

	BOOL				CreateCameraProcess(const TYPE_NETWORK eNetwork, const int nProcessId, const int nCamId, HWND hWnd, INFO_VIDEODEV_ARG* pVideoArg);
	void				DestoryCameraProcess(const TYPE_NETWORK eNetwork, const int nProcessId, const int nCamId);

	BOOL				Start(const TYPE_NETWORK eNetwork, const int nProcessId, BOOL bSingleFrame = FALSE);
	void				Stop(const TYPE_NETWORK eNetwork, const int nProcessId);

	const int			GetEnableProcessId();
	const int			GetWorkingProcessCount();
	const int			GetProcessId(const INFO_CONNECT_DEV* pstDevice);
	const int			GetCameraId(const INFO_CONNECT_DEV* pstDevice);
	const int			GetCameraId(const int nProcessId);

	BOOL				IsWorkingCamera(const int nProcessId);
	BOOL				IsStartCamera(const int nProcessId);


	//
	BOOL				SetGain(const TYPE_NETWORK eNetwork, const int nProcessId, const int nGainType, const int nGainVal);
	BOOL 				GetGain(const TYPE_NETWORK eNetwork, const int nProcessId, const int nGainType, int* pnGainVal);

	BOOL 				SetEnableFrameRate(const TYPE_NETWORK eNetwork, const int nProcessId, const BOOL bEnable);
	BOOL 				GetEnableFrameRate(const TYPE_NETWORK eNetwork, const int nProcessId, BOOL* pbEnable);

	BOOL 				SetFrameRate(const TYPE_NETWORK eNetwork, const int nProcessId, const unsigned int nFrameRate);
	BOOL 				GetFrameRate(const TYPE_NETWORK eNetwork, const int nProcessId, unsigned int* pnFrameRate);

	BOOL 				SetExposureTime(const TYPE_NETWORK eNetwork, const int nProcessId, const unsigned int nExposureTime);
	BOOL 				GetExposureTime(const TYPE_NETWORK eNetwork, const int nProcessId, unsigned int* pnExposureTime);
	BOOL 				GetExposureMaxTime(const TYPE_NETWORK eNetwork, const int nProcessId, unsigned int nFrameRate, unsigned int* pnExposureTime);
	BOOL 				ConvertExposureTime(const TYPE_NETWORK eNetwork, const int nProcessId, unsigned int nStep, double* pfUSec); // Step to Time

	BOOL 				SetTriggerMode(const TYPE_NETWORK eNetwork, const int nProcessId, INFO_TRIGGER_PARA stTrigger);
	BOOL 				GetTriggerMode(const TYPE_NETWORK eNetwork, const int nProcessId, INFO_TRIGGER_PARA* pstTrigger);

	BOOL 				SetTriggerDelay(const TYPE_NETWORK eNetwork, const int nProcessId, int nDelay);

	
	BOOL				SaveUserset(const TYPE_NETWORK eNetwork, const int nProcessId, const int nNumber);
	BOOL 				LoadUserset(const TYPE_NETWORK eNetwork, const int nProcessId, const int nNumber);

	BOOL 				SetStrobeMode(const TYPE_NETWORK eNetwork, const int nProcessId, INFO_STROBE_PARA stStrobe);
	BOOL 				GetStrobeMode(const TYPE_NETWORK eNetwork, const int nProcessId, INFO_STROBE_PARA* pstStrobe);

	BOOL 				SetFlipMode(const TYPE_NETWORK eNetwork, const int nProcessId, unsigned short nMode);
	BOOL 				GetFlipMode(const TYPE_NETWORK eNetwork, const int nProcessId, unsigned short* pnMode);

	BOOL 				SetROI(const TYPE_NETWORK eNetwork, const int nProcessId, INFO_ROI_PARA stROI);
	BOOL 				GetROI(const TYPE_NETWORK eNetwork, const int nProcessId, INFO_ROI_PARA* pstROI);

	BOOL 				SetUsersetStartNo(const TYPE_NETWORK eNetwork, const int nProcessId, unsigned char nUsersetStartNo);
	BOOL 				GetUsersetStartNo(const TYPE_NETWORK eNetwork, const int nProcessId, unsigned char* pnUsersetStartNo);

	BOOL 				SetDataBit(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short nDataBit);
	BOOL 				GetDataBit(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short* pnDataBit);

	BOOL 				SetColorMode(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short nColorMode);
	BOOL 				GetColorMode(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short* pnColorMode);

	BOOL 				SetMTU(TYPE_NETWORK eNetwork, const int nProcessId, unsigned int nMTU);
	BOOL 				GetMTU(TYPE_NETWORK eNetwork, const int nProcessId, unsigned int* pnMTU);

	BOOL 				GetDiag(const TYPE_NETWORK eNetwork, const int nProcessId, void* pstDiag, int nLen);
	BOOL 				SetSWTrigger(const TYPE_NETWORK eNetwork, const int nProcessId);

	// Effect
	BOOL 				SetEffectNR(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short nEffect);
	BOOL 				GetEffectNR(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short* pnEffect);

	BOOL 				SetEffectGC(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short nEffect);
	BOOL 				GetEffectGC(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short* pnEffect);

	BOOL 				SetEffectCM(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short nEffect);
	BOOL 				GetEffectCM(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short* pnEffect);

	BOOL 				SetEffectAWB(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short nEffect);
	BOOL 				GetEffectAWB(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short* pnEffect);

	BOOL 				SetEffectSmooth(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short nEffect);
	BOOL 				GetEffectSmooth(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short* pnEffect);

	BOOL				SetEffectSharpen(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short nEffect);
	BOOL 				GetEffectSharpen(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short* pnEffect);

	BOOL 				SetEffectFPN(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short nEffect);
	BOOL 				GetEffectFPN(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short* pnEffect);

	BOOL				SetEffectPRNU(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short nEffect);
	BOOL 				GetEffectPRNU(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short* pnEffect);

	BOOL 				SetEffectDPC(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short nEffect);
	BOOL 				GetEffectDPC(TYPE_NETWORK eNetwork, const int nProcessId, unsigned short* pnEffect);

	BOOL 				SetColorGain(const TYPE_NETWORK eNetwork, const int nProcessId, const int nGainType, const int nGainVal);
	BOOL 				GetColorGain(const TYPE_NETWORK eNetwork, const int nProcessId, const int nGainType, int* pnGainVal);
	
	void				SkipCameraFrame(const int nProcessId, BOOL bSkip);

	void				SetTotalLogHandle(HANDLE hFile) { m_hFile_Total = hFile; }
	HANDLE				GetTotalLogHandle() { return m_hFile_Total; }

	// Command
	BOOL 				ReadRegDword(const int nProcessId, const DWORD dwAddress, DWORD* pdwValue, DWORD dwReserved = 0);
	BOOL 				WriteRegDword(const int nProcessId, const DWORD dwAddress, const DWORD dwValue, DWORD dwReserved = 0);
	
	BOOL 				CalculateMaxFrameRate(const INFO_DEFDEV* pstDefDev, const int nProcessId, const int nWidth, const int nHeight, DWORD* pdwMaxFps);

#ifdef TRIGGER_TIMEOUT
	void 				SetEnableTriggerTimeOut(const int nProcessId, BOOL bEnable);
	BOOL 				GetEnableTriggerTimeOut(const int nProcessId);

	void 				SetTimeTriggerTimeOut(const int nProcessId, DWORD dwMsec);
	DWORD 				GetTimeTriggerTimeOut(const int nProcessId);
public:
	BOOL 				IsSupportTriggerTimeOut();

	void 				SetEnableTriggerTimeOut(BOOL bEnable);
	BOOL 				GetEnableTriggerTimeOut();

	void 				SetTimeTriggerTimeOut(DWORD dwMsec);
	DWORD 				GetTimeTriggerTimeOut( );
	BOOL 				GetRangeTriggerTimeOut(DWORD& dwFrom, DWORD& dwTo);
#endif

#if defined(ENABLE_CAMERA_LIBRARY_BASLER)
	BOOL				GetCameraInformation(const int nProcessId, INFO_OTHER_CATEGORY* pstRootCategory);
	const INFO_OTHER_IF* GetCameraInformation(const int nProcessId, const TCHAR* szName);

	VALUE_OTHER*		GetCameraOtherValue(const INFO_OTHER_IF* pstInfo, void* pValue);

	BOOL				GetCameraValue(const int nProcessId, const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue);
	BOOL				SetCameraValue(const int nProcessId, const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue);

	// Trigger Function
	BOOL				IsActiveSoftwareTrigger(const int nProcessId, BOOL* pbTriggerOn = NULL, BOOL* pbTriggerSoftware = NULL);

	BOOL				SetSoftwareTriggerMode(const int nProcessId);
	BOOL				SetSoftwareTrigger(const int nProcessId);

	BOOL				SetCameraPropertyReverseX(const int nProcessId, const BOOL bReverseX);
	BOOL				SetCameraPropertyReverseY(const int nProcessId, const BOOL bReverseY);

	void				ConvertColorBit10to8(const TYPE_NETWORK eNetwork, const INFO_IMAGE* pFrom, BYTE* pTo, int nToPitch);
	void				ConvertColorBit12to8(const TYPE_NETWORK eNetwork, const INFO_IMAGE* pFrom, BYTE* pTo, int nToPitch);

	void				ConvertColorBit10to8(const TYPE_NETWORK eNetwork, const int nW, const int nH, BYTE* pFrom, int nFromPitch, BYTE* pTo, int nToPitch);
	void				ConvertColorBit12to8(const TYPE_NETWORK eNetwork, const int nW, const int nH, BYTE* pFrom, int nFromPitch, BYTE* pTo, int nToPitch);
#endif

	int					GetBitCount(TYPE_DATABIT eBit);
	int					GetBitCount(TYPE_VIDEOFORMAT eFormat);

#ifdef DEF_FREERUN_CAPTURE
public:
	BOOL 				IsReadySnapCapture();
	void 				SetReadySnapCapture(BOOL bReady);

	BOOL 				IsReadySnapCapture(TYPE_CAMERAPOS eType);
	void 				SetReadySnapCapture(TYPE_CAMERAPOS eType, BOOL bReady);

	BOOL 				IsSingleSnapCapture();
	void 				SetSingleSnapCapture(BOOL bSingle);
#endif

public:
	CSerialCtrl* 		GetStrobeControlPort(TYPE_CAMERAPOS eType);
	CEthernet* 			GetCommunicatePort();
	CEthernet*			CreateCommunicatePort(const TCHAR* pszType);
	void 				DeleteCommunicatePort();

	void 				SetCommunicateNotifyHandler(FuncNotifyEthernetListener pFunc, void* pArg);
	BOOL 				GetCommunicateNotifyHandler(FuncNotifyEthernetListener* pFunc, void** pArg);

						// Version 1.3.6.5 (치수 영역 추가 없이 PLC 통신 데이터 추가 (X1-X2, L))
						// Ver1.3.7.2 (치수 영역 추가 없이 PLC 통신 데이터 추가 (M1, M2))
						// Ver1.3.7.4 (치수 영역 추가 없이 PLC 통신 데이터 추가 (S1S3))
	BOOL				SendInspectionResultCommand(TYPE_CAMERAPOS eCameraPos, CSampleSide* pSampleSide, int &iD, int &iS, int &iL, int &iX1X2, int &iM1, int &iM2, int &iS1S3);
						// Version 1.3.6.5 (치수 영역 추가 없이 PLC 통신 데이터 추가 (X1-X2, L))
						// Ver1.3.7.2 (치수 영역 추가 없이 PLC 통신 데이터 추가 (M1, M2))
						// Ver1.3.7.4 (치수 영역 추가 없이 PLC 통신 데이터 추가 (S1S3))
	void				CheckInspectionResult(TYPE_CAMERAPOS eCameraPos, CSampleSide* pSampleSide, BOOL& bResSize, BOOL& bResShape, float &fResDValue, float &fResSValue, float &fResLValue, float & fResX1X2Value, float &fResM1Value, float& fResM2Value, float& fResS1S3Value);
	BOOL				IntTo4HexString(int nData, TCHAR *szString, const int nLen);
	void				SendCommand(CSerialCtrl* pSerialCtrl, BYTE* pCommand, int nCmdLen, BYTE* pResponse, int& nResLen);


	BOOL 				ControlStrobeOnOff(CSerialCtrl* pSerialCtrl, TYPE_CAMERAPOS eType, TYPE_STROBE eStrobe);
	BOOL 				ControlStrobeBrightness(CSerialCtrl* pSerialCtrl, TYPE_CAMERAPOS eType, TYPE_STROBE eStrobe, int nBrightness);
	BOOL 				ControlStrobeBrightness(CSerialCtrl* pSerialCtrl, TYPE_CAMERAPOS eType, int nBrightness_COXIAL, int nBrightness_RING, int nBrightness_BAR);
	BOOL 				ReadStrobeBrightness(CSerialCtrl* pSerialCtrl);

	BOOL 				IsReadyInspectionDevice();
	
	
	// Inspection
	CInspection*		GetInspection();

	void 				SetOptionFilePath(const TCHAR* pszFilePath);
	const TCHAR*		GetOptionFilePath();

	const INFO_OPTION*	GetOption();
	void 				UpdateOption(const INFO_OPTION* pstOpt);

	const INFO_OPTIONETC* GetOptionEtc();
	void 				UpdateOptionEtc(const INFO_OPTIONETC* pstOptEtc);

	const INFO_SCENARIO* GetScenario();

	const INFO_STROBE*	GetCurrentStrobeInfo();

	INFO_SUMMARY*	GetResultSummary();

	void			UpdateSummary(TYPE_CAMERAPOS eCameraPos, CSampleSide* pSample);
	void			ClearSummaryQueue();

	const int		GetResultSummaryCount();
	const int		AddSampleCount();

	BOOL			UpdateInspection(TYPE_CAMERAPOS ePos, const TCHAR* pszFilePath, const INFO_INSPECTION* pstInsection);
	const TCHAR*	GetInspectionFilePath(TYPE_CAMERAPOS ePos);
	const INFO_INSPECTION* GetInspectionInfo(TYPE_CAMERAPOS ePos);

	// String...
	const TCHAR*	GetTitleStep(TYPE_CAMERAPOS ePos, TYPE_STEP eStep);
	
	int				m_nCountSaveProbImage = 0;

#ifdef USE_PLC_MXCOMPONENT
	CString			GetProgramExecutePath();
	BOOL			PLC_MXCOMPONENT_Module_Execution();
	void			LPMxComponentConfigSetting(int nPLCProtocolType, int nPLCControlType, int nStationNum, CString strHostAddress, int nPortNum);
	BOOL			LPMxComOpenCommunication();
	BOOL			LPMxComGetCpuType();
	BOOL			LPMxComGetDevice(CString strDeviceName);
	BOOL			LPMxComSetDevice(CString strDeviceName, long lValue);
	BOOL			LPMXComCloseCommunication();
	void			LPMxComCloseProgram();
	void			LPMxComWindowShowHide(BOOL bWindowShow);
#endif

protected:
	void			UpdateSummarySampleSide(TYPE_CAMERAPOS eCameraPos, CSampleSide* pSample, INFO_SUMMARY_SAMPLE& stSampleSummary);
	void			UpdateTotalSummary(INFO_SUMMARY_TOTAL_FLAG stFirstSummayResult, INFO_SUMMARY_TOTAL_FLAG stsecondSummayResult, INFO_SUMMARY_TOTAL& stSummatyTotal);

	void			SendStrobeCommand(CSerialCtrl* pSerialCtrl, BYTE* pCommand, int nCmdLen, BYTE* pResponse, int& nResLen);

	void 			ComposeCommandSetStrobeOnAllChannel(BYTE* pCmd, int& nCmdLen, BOOL bOn);
	void			ComposeCommandSetStrobeOn(BYTE* pCmd, int& nCmdLen, int nCh, BOOL bOn);
	void			ComposeCommandSetStrobeOn_new(BYTE* pCmd, int& nCmdLen, int nCh, BOOL bOn);
	
	void			ComposeCommandSetStrobeBrightness(BYTE* pCmd, int& nCmdLen, int nCh, int nValue);
	void			ComposeCommandSetStrobeBrightness_new(BYTE* pCmd, int& nCmdLen, int nCh, int nValue);
	void			ComposeCommandSetStrobeBrightness(BYTE* pCmd, int& nCmdLen, int nBrightness_FC, int nBrightness_FR, int nBrightness_FB, int nBrightness_SC, int nBrightness_SR, int nBrightness_SB);
	void			ComposeCommandSetStrobeBrightness_new(BYTE* pCmd, int& nCmdLen, int nBrightness_FC, int nBrightness_FR, int nBrightness_FB, int nBrightness_SC, int nBrightness_SR, int nBrightness_SB);

	void			ComposeCommandGetStrobeBrightness(BYTE* pCmd, int& nCmdLen, int nCh);
	void			ComposeCommandGetStrobeBrightness_new(BYTE* pCmd, int& nCmdLen, int nCh);
	int				ParseCommandGetStrobeBrightness(const BYTE* pRes, const int nResLen, const int nCh);
	int				ParseCommandGetStrobeBrightness_new(const BYTE* pRes, const int nResLen, const int nCh);



	void			ControlStrobeOnOffEmulator(CSerialCtrl* pSerialCtrl, TYPE_CAMERAPOS eType, TYPE_STROBE eStrobe);
	void			ControlStrobeOnOffDevice(CSerialCtrl* pSerialCtrl, TYPE_CAMERAPOS eType, TYPE_STROBE eStrobe);

	void			ControlStrobeBrightnessEmulator(CSerialCtrl* pSerialCtrl, TYPE_CAMERAPOS eType, TYPE_STROBE eStrobe, int nBrightness);
	void			ControlStrobeBrightnessEmulator(CSerialCtrl* pSerialCtrl, TYPE_CAMERAPOS eType, int nBrightness_FC, int nBrightness_FR, int nBrightness_FB, int nBrightness_SC, int nBrightness_SR, int nBrightness_SB);
	void			ControlStrobeBrightnessDevice(CSerialCtrl* pSerialCtrl, TYPE_CAMERAPOS eType, TYPE_STROBE eStrobe, int nBrightness);
	void			ControlStrobeBrightnessDevice(CSerialCtrl* pSerialCtrl, TYPE_CAMERAPOS eType, int nBrightness_FC, int nBrightness_FR, int nBrightness_FB, int nBrightness_SC, int nBrightness_SR, int nBrightness_SB);

	BOOL			ReadStrobeBrightnessEmulator(CSerialCtrl* pSerialCtrl, TYPE_CAMERAPOS eType, TYPE_STROBE eStrobe);
	BOOL			ReadStrobeBrightnessDevice(CSerialCtrl* pSerialCtrl, TYPE_CAMERAPOS eType, TYPE_STROBE eStrobe);
	
};

