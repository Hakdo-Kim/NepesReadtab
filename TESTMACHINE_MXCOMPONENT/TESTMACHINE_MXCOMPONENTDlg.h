
// TESTMACHINE_MXCOMPONENTDlg.h : header file
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include <queue>

#include "Common.h"
#include "MMTimer.h"
#include "LPMxComponentPLCCtrl.h"

//#define USE_PLC_COPYDATA

#define DEF_RUN2STEP

typedef enum
{
	TYPE_STATE_PLC_NONE,
	TYPE_STATE_PLC_MOVING,
	TYPE_STATE_PLC_WAITING_INSPECTION,
	TYPE_STATE_PLC_WAITING_READY,
} TYPE_STATE_PLC;

// CTESTMACHINE_MXCOMPONENTDlg dialog
class CTESTMACHINE_MXCOMPONENTDlg : public CDialogEx
{
// Construction
public:
	CTESTMACHINE_MXCOMPONENTDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_TESTMACHINE_MXCOMPONENT_DIALOG };

	TYPE_STATE_PLC				m_eStatePLC;
	DWORD						m_dwThreadIdCommPLC;
	HANDLE						m_hThreadCommPLC;
	static DWORD WINAPI			ThreadCommPLC(LPVOID pArg);

	const int					TIMERID_CLOSECOMMUNICATION = 1;
	const int					TIMERID_INSPECTIONSTOP = 2;

	const int					ONESEC_TIMER = 1000;
	const int					MSEC_TIMER = 2000;

	int							m_nSampleFirstCount;
	int							m_nSampleSecondCount;

	/// Inspection Argument 
	BOOL						m_bStart;
	BOOL						m_bRealTestStarted;

	TYPE_STATE					m_eActionState;
	int							m_eSelectLine;
	int							m_nPLCStationNumber;
	CLPMxComponentPLCCtrl*		m_pLPMXComponectPLCCtrl;

	CString						MakeDeviceInfo(int eSelectLine, int eCurPos, int eActionState, int eHeaterNumber = 0);
	BOOL						AllClearPLCMemoryMap(int eSelectLine);

	BOOL						ReadInspectionState(int& nStateFirst, int& nStateSecond);
	BOOL						ReadyInspection();
	BOOL						StartInspection();

	const BOOL					IsStarted();
	void						UpdateConnectState(BOOL bConnect);
	void						UpdateStartState(BOOL bStart);

	BOOL						InspectFirstCamera();
	BOOL						InspectSecondCamera();
	BOOL						RunInspect(TYPE_POS eCameraPos);

	void						UpdateMessage(TCHAR* pszMessage);

	virtual void				DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL				OnCommand(WPARAM wParam, LPARAM lParam);
	virtual BOOL				PreTranslateMessage(MSG* pMsg);

	void						CheckTemperatureState(int nTimerCounter, long lTemperature);

	BOOL						m_bStartFlag;

// Implementation
	HICON m_hIcon;

	DECLARE_MESSAGE_MAP()
	// Generated message map functions
	virtual BOOL				OnInitDialog();
	afx_msg void				OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void				OnPaint();
	afx_msg HCURSOR				OnQueryDragIcon();
	afx_msg void				OnTimer(UINT_PTR nIDEvent);
	afx_msg void				OnDestroy();
	afx_msg void				OnClose();

	afx_msg void				OnBnClickedBtnOpencom();
	afx_msg void				OnBnClickedBtnClosecom();
	afx_msg void				OnBnClickedBtnStart();
	afx_msg void				OnBnClickedBtnStop();
	afx_msg void				OnBnClickedRdoLine1();
	afx_msg void				OnBnClickedRdoLine2();

	afx_msg BOOL				OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
};
