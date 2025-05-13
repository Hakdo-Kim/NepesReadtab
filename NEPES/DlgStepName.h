#pragma once

#include "CommonCapture.h"

// CDlgStepName dialog

class CDlgStepName : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgStepName)

public:
	CDlgStepName(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgStepName();

	BOOL SetStepNames(INFO_OPTION* pstOption);

	CString m_szFirstStep01;
	CString m_szFirstStep02;
	CString m_szFirstStep03;
	CString m_szFirstStep04;
	CString m_szFirstStep05;
	CString m_szFirstStep06;

	CString m_szSecondStep02;
	CString m_szSecondStep03;
	CString m_szSecondStep04;
	CString m_szSecondStep05;
	CString m_szSecondStep06;


// Dialog Data
	enum { IDD = IDD_DLG_STEPNAME };
protected:
	int GetStringLength(CString* pString);

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedCheckSamename();
	afx_msg void OnBnClickedOk();
	//
	afx_msg void OnEnKillfocusEditFirststep2();
	afx_msg void OnEnKillfocusEditFirststep3();
	afx_msg void OnEnKillfocusEditFirststep4();
	afx_msg void OnEnKillfocusEditFirststep5();
	afx_msg void OnEnKillfocusEditFirststep6();
};
