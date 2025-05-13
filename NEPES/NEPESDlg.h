
// NEPESDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "CustomMessage.h"
#include "TapView.h"

#include "TapMainSummary.h"
#include "TapMainSize.h"
#include "TapMainScenario.h"

#include "DlgSequence.h"
#include "DlgConfig.h"
#include "CaptureManager.h"

#include "MMTimer.h"
//Version 1.3.7.8
#include <memory> 

#define USE_COUNT_TAB

#ifdef USE_COUNT_TAB
#include "TapMainCount.h"
#endif

void CALLBACK CB_VisionKeepAlive(HWND hWnd, UINT nID, UINT_PTR nEl, DWORD time);
void CALLBACK CB_TemperatureCheck(HWND hWnd, UINT nID, UINT_PTR nEl, DWORD time);
void CALLBACK CB_SynchronizationCheck(HWND hWnd, UINT nID, UINT_PTR nEl, DWORD time);

// CNEPESDlg dialog
class CNEPESDlg : public CDialogEx, public CMMTimerListener
{
// Construction
public:
	CNEPESDlg(CWnd* pParent = NULL);	// standard constructor
	static BOOL CALLBACK FuncDisplayVideoDevice(const INFO_IMAGE* pstImage, void* pArg, int nRemainedFrame);
	static BOOL CALLBACK FuncNotifyEthernetListener(DWORD dwListener, void* pArg);
	static BOOL CALLBACK FuncNotifyInspectionResult(TYPE_CAMERAPOS eCameraPos, TYPE_STEP eStep, BOOL bResult, void* pArg, BOOL bCaptureFlag);
// Dialog Data
	enum { IDD = IDD_NEPES_DIALOG };
// Implementation

	// Version 1.3.7.6 Save OK Image Period
	BOOL CheckPeriod(TYPE_CAMERAPOS eCameraPos, int periodTime);
	// Version 1.3.7.8
	std::unique_ptr<CSampleSide> m_Sample1;
	std::unique_ptr<CSampleSide> m_Sample2;
/// MultiMedia Timer
private:
	UINT m_MaxResolution;
	CMMTimer m_Timer;
	BOOL MMTimer_Start(int nTimeInterval);
	BOOL MMTimer_Stop();
	void Update(CMMTimer &Timer);

	int m_nFirstResultPLCSettingDelayCount;
	int m_nSecondResultPLCSettingDelayCount;

	// Version 1.3.7.6 Save OK Image Period
	SYSTEMTIME m_stFirstCurTime;
	SYSTEMTIME m_stSecondCurTime;
	SYSTEMTIME m_stFirstPreTime;
	SYSTEMTIME m_stSecondPreTime;
	SYSTEMTIME GetPreviousPeriodTime(TYPE_CAMERAPOS eCameraPos);
	SYSTEMTIME GetCurrentPeriodTime(TYPE_CAMERAPOS eCameraPos);
	BOOL SetPreviousPeriodTime(TYPE_CAMERAPOS eCameraPos);
	BOOL SetCurrentPeriodTime(TYPE_CAMERAPOS eCameraPos);


protected:
	CRITICAL_SECTION m_CriticalSection;
	HANDLE m_hMutex;
	HICON m_hIcon;

	const int TIMERID_ETHERNET = 10;
#ifdef USE_PLC_MXCOMPONENT
	const int TIMERID_CHECK_MXCOMPONENTMODULE = 20;
	const int TIMERID_CHECK_PLCMAP_VISIONKEEPALIVE = 21;
	const int TIMERID_CHECK_PLC_TEMPERATURE = 31;
	// Version 1.3.7.7
	const int TIMERID_CHECK_PLC_SYNCHRONIZATION = 41;

	BOOL m_bTRUE_Data;
	int m_nPLCMAP_VISIONKEEPALIVE_Timer;
	int m_nPLC_CHECKTEMPERATURE_Timer;
	int m_nPLC_SYNCHRONIZATION_Timer;

	COPYDATASTRUCT m_LPMxComponentDS;

	int m_nCurrentPLCCommunicationStep;

	CString m_strSetDeviceName[3];
	CString m_strGetDeviceName[3];
	long m_lGetValue[3];

	BOOL m_bTempLogState;
	int m_nHeaterValue[PLC_HEATER_MAX];

	HANDLE m_hPLCGetDataProcessThread;
	HANDLE m_hPLCGetDataProcessThreadSecond;
	// Version 1.3.7.7
	HANDLE m_hPLCGetDataProcessThreadTimeSync;
	BOOL m_bRequestedInspection;
	BOOL m_bRealStartingInspectionPLC;

	BOOL m_bRequestedInspectionSecond;
	BOOL m_bRealStartingInspectionPLCSecond;
#endif

protected:
	int	m_bChaningInspectionState;
	const int TIMERID = 1;
	const int MSEC_INIT = 500;
	const int TEMPERATURE_TICK = 30000;

	const int MINWIDTH = 1150;
	const int MINHEIGHT = 870;
	const int MARGIN = 5;

	RECT m_rtTitle;
	RECT m_rtView;

	CCustomMessage m_ctlTitleMessage;

	CTapMainSummary m_TapMainSummary;
	CTapMainSize m_TapMainSize;
	CCustomMessage m_ctlStaticSize;

	CTapMainScenario m_TapMainScenario;
#ifdef USE_COUNT_TAB
	CTapMainCount m_TapMainCount;
#endif

	CDlgSequence* m_pDlgSequence;// Just Check for Popup dialog
	CDlgConfig* m_pDlgConfig;
	// Version 1.3.7.8
	struct ImageSet
	{
		const INFO_IMAGE* cam1_img1 = nullptr;
		const INFO_IMAGE* cam1_img2 = nullptr;
		const INFO_IMAGE* cam2_img1 = nullptr;
		const INFO_IMAGE* cam2_img2 = nullptr;

		void Set(TYPE_CAMERAPOS ePos, TYPE_STEP eStep, const INFO_IMAGE* img)
		{
			if (eStep != TYPE_STEP_001 && eStep != TYPE_STEP_007) return;

			if (ePos == TYPE_CAMERAPOS_FIRST)
			{
				if		(eStep == TYPE_STEP_001) cam1_img1 = img;
				else if (eStep == TYPE_STEP_007) cam1_img2 = img;
			}
			else if (ePos == TYPE_CAMERAPOS_SECOND)
			{
				if		(eStep == TYPE_STEP_001) cam2_img1 = img;
				else if (eStep == TYPE_STEP_007) cam2_img2 = img;
			}
		}

		const INFO_IMAGE* Get(TYPE_CAMERAPOS ePos, TYPE_STEP eStep)
		{
			if (ePos == TYPE_CAMERAPOS_FIRST)
			{
				if		(eStep == TYPE_STEP_001) return cam1_img1;
				else if (eStep == TYPE_STEP_007) return cam1_img2;
			}
			else if (ePos == TYPE_CAMERAPOS_SECOND)
			{
				if		(eStep == TYPE_STEP_001) return cam2_img1;
				else if (eStep == TYPE_STEP_007) return cam2_img2;
			}
		}

		bool IsValid() const 
		{
			auto valid = [](const INFO_IMAGE* img) {
				return img && img->m_pBuffer && img->m_nLen > 0;
			};

			return (valid(cam1_img1) && valid(cam1_img2)) ||
				(valid(cam2_img1) && valid(cam2_img2));
		}

		void Clear() 
		{
			cam1_img1 = nullptr;
			cam1_img2 = nullptr;
			cam2_img1 = nullptr;
			cam2_img2 = nullptr;
		}
	};
	ImageSet m_stCachedImages;
	//


	void Inspection();
	void AcquireForInspection(TYPE_CAMERAPOS eCameraPos, TYPE_STEP eStep);

	void AdjustLayout();
	void DrawLayout(CDC* pDC, CRect rect, COLORREF rgbBk, DWORD dwLT, DWORD dwLB, DWORD dwRT, DWORD dwRB);
	void CloseApplication();

	void ConfigDevices();
	void ConfigScenario(const TYPE_CAMERAPOS ePos);
	// Version 1.3.7.8
	void ConfigScenario(const TYPE_CAMERAPOS ePos, CSampleSide* sample, const INFO_IMAGE* pImageFirst, const INFO_IMAGE* pImageSecond);

	void ConfigOptionInsepction();
	void ConfigOption();

	void UpdateMenuStatus();
	void UpdateCtrlStatus();
	void UpdateCtrlScenraioState(TYPE_CAMERAPOS eCameraPos, TYPE_STEP eStep, CSampleSide* pSample);
	void UpdateOptionFilePath();

	TYPE_TAPVIEW GetCurrentTapView();
	void SetCurrentTapView(TYPE_TAPVIEW eType);

	void CheckInspectionResult(TYPE_CAMERAPOS eCameraPos, CSampleSide* pSample, BOOL& bResSize, BOOL& bResShape);
	void DumpImageOKResult(TYPE_CAMERAPOS eCameraPos, TYPE_STEP eStep, CSampleSide* pSample);
	void DumpImageErrorResult(TYPE_CAMERAPOS eCameraPos, TYPE_STEP eStep, CSampleSide* pSample);
	// Version 1.3.7.6 Save OK Image Period
	void PeriodImageOKResult(TYPE_CAMERAPOS eCameraPos, TYPE_STEP eStep, CSampleSide* pSample);

	void ClickedBtnTestStep(TYPE_CAMERAPOS eCameraPos, TYPE_STEP eStep);

public:
#ifdef USE_PLC_MXCOMPONENT
	BOOL GetTRUE_AliveData() { return m_bTRUE_Data; }
	void SetTRUE_AliveData(BOOL bTRUE_Data) { m_bTRUE_Data = bTRUE_Data; }
	BOOL GetTempLogState() { return m_bTempLogState; }
	void SetTempLogState(BOOL bState) { m_bTempLogState = bState; }

	// Version 1.3.6.9 Update
	CString MakeDeviceInfo(int eSelectLine, int eCurPos, int eActionState, int eHeaterNumber = 0, const INFO_OPTION* pstOption = NULL, CSampleSide* pSample = NULL);
	BOOL AllClearPLCMemoryMap(int eSelectLine);
	BOOL AllStartPLCMemoryMap(int eSelectLine);
	//
	
	static DWORD WINAPI PLCGetDataProcessThreadProc(LPVOID lpArg);
	DWORD PLCGetDataProcessThreadProc();

	static DWORD WINAPI PLCGetDataProcessThreadProcSecond(LPVOID lpArg);
	DWORD PLCGetDataProcessThreadProcSecond();
	bool PLCGetDataProcessThreadAllClose();

	static DWORD WINAPI PLCGetDataProcessThreadTemperature(LPVOID lpArg);
	DWORD PLCGetDataProcessThreadTemperature();

	static DWORD WINAPI PLCGetDataProcessThreadTimeSync(LPVOID lpArg);
	DWORD PLCGetDataProcessThreadTimeSync();
#endif

protected:
	// Generated message map functions
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClose();
	afx_msg void OnBnClickedBtnStart();

	// Command Function
	afx_msg LRESULT OnMsgEdit(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMsgGrab(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMsgGrabEdit(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMsgStrobe(WPARAM wParam, LPARAM lParam);
	// Command Function - File
	afx_msg void OnCommandStart();
	afx_msg void OnCommandStop();
	afx_msg void OnCommandExit();
	// Command Function - Config
	afx_msg void OnCommandConfig();
	afx_msg void OnCommandConfigInspection();
	afx_msg void OnCommandOption();
	// Command Function - About
	afx_msg void OnCommandAbout();
	
	afx_msg void OnBnClickedRadioMainsummary();
	afx_msg void OnBnClickedRadioMainsize();
	afx_msg void OnBnClickedRadioMainscenario();
	afx_msg void OnBnClickedRadioMaincount();
	afx_msg void OnBnClickedBtnTestsize();
	afx_msg void OnBnClickedBtnTestsize2();

public:
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
	afx_msg LRESULT OnMsgInspectionEnvReady(WPARAM wParam, LPARAM lParam);
	afx_msg void OnBnClickedBtnClearQueue();
	afx_msg void OnBnClickedBtnTestStep2();
	afx_msg void OnBnClickedBtnTestStep3();
	afx_msg void OnBnClickedBtnTestStep4();
	afx_msg void OnBnClickedBtnTestStep22();
	afx_msg void OnBnClickedBtnTestStep32();
	afx_msg void OnBnClickedBtnTestStep42();
};
