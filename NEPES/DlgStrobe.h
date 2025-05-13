#pragma once

#include "CommonCapture.h"
#include "afxwin.h"

// CDlgStrobe dialog

class CDlgStrobe : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgStrobe)

public:
	CDlgStrobe(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgStrobe();

	INFO_STEPSTROBE m_pstStepStrobe[MAX_STEPSTROBE_LIST];



// Dialog Data
	enum { IDD = IDD_DLG_STEPSTROBE };
protected:
	CComboBox m_ctlStrobe01;
	CComboBox m_ctlStrobe02;

	void UpdateCtrlStrobe(CComboBox* pCtlCombo, const DWORD dwCtrlID);

	TYPE_STROBE GetStrobeTypeFromControl(CComboBox* pCtlCombo);
	BOOL IsEnableBrightnessValue(TYPE_STROBE eStrobe, int nValue);
	
	int GetEditValue(const DWORD dwCtrlID);
	void SetEditValue(const DWORD dwCtrlID, int nValue);

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnCbnSelchangeComboStrobe1();
	afx_msg void OnCbnSelchangeComboStrobe2();
	afx_msg void OnEnKillfocusEditBrightness1();
	afx_msg void OnEnKillfocusEditBrightness2();
	afx_msg void OnBnClickedOk();

};
