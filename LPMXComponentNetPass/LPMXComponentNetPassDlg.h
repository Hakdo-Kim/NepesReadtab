
// LPMXComponentNetPassDlg.h : header file
//

#pragma once

#include "LPMxComponentPLCCtrl.h"

/////////////////////////////////////////////////////////////////////////////////////////////
///
#define TIMERID_CLOSEPROGRAM 1
#define TIMERID_OPENCOM 2
#define TIMERID_CLOSECOM 3
#define TIMERID_GetCPUTYPE 4
#define TIMERID_GetDEVICEDATA 5
#define TIMERID_SetDEVICEDATA 6

//#define USE_MESSAGE_TRACE

///
//////////////////////////////////////////////////////////////////////////////////////////////

// CLPMXComponentNetPassDlg dialog
class CLPMXComponentNetPassDlg : public CDialogEx
{
// Construction
public:
	CLPMXComponentNetPassDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_LPMXCOMPONENTNETPASS_DIALOG };

///
protected:
	CRITICAL_SECTION			m_CriticalSection;
	HWND						m_hTargetWnd;
	
	long						m_lCpuCode;
	int							m_nProtocolType;
	int							m_nControlType;
	CString						m_strHostAddress;
	int							m_nPortNum;
	int							m_nPLCStationNumber;

	CString						m_strGetDeviceName;
	CString						m_strSetDeviceName;
	long						m_lSetValue;

	CLPMxComponentPLCCtrl*		m_pLPMXComponectPLCCtrl;

	COPYDATASTRUCT				m_LPMxComponentDS;

	BOOL						m_bFirstOpenCommunication;

public:
	BOOL						OpenCommunication();
	BOOL						CloseCommunication();
	BOOL						GetCPUType(CString* pstrCpuName, long*plCpuCode, long* plRet);
	BOOL						GetDevice(CString strDeviceName, long*plValue, long* plRet);
	BOOL						SetDevice(CString strDeviceName, long lValue, long* plRet);
	void						CloseProgram();
	void						WindowShowHide(BOOL bShow);

public:

	protected:
	virtual void				DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL				OnCommand(WPARAM wParam, LPARAM lParam);
	virtual BOOL				PreTranslateMessage(MSG* pMsg);

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	DECLARE_MESSAGE_MAP()
	virtual BOOL				OnInitDialog();
	afx_msg void				OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void				OnPaint();
	afx_msg HCURSOR				OnQueryDragIcon();
	afx_msg void				OnDestroy();
	afx_msg void				OnClose();
public:
	afx_msg BOOL				OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
	afx_msg void				OnTimer(UINT_PTR nIDEvent);
};
