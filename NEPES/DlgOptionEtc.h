#pragma once
#include "CommonCapture.h"
#include "afxwin.h"

// CDlgOptionEtc dialog

class CDlgOptionEtc : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgOptionEtc)
public:
	CDlgOptionEtc(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgOptionEtc();


	INFO_OPTIONETC	m_stEtcOption;

// Dialog Data
	enum { IDD = IDD_DLG_OPTION_ETC };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedOk();
	void CheckSaveErrorImage();
	void CheckSaveProbImage();
	void CheckSaveOKImage();
	void CheckSaveOKImagePeriod();
	
public:
	afx_msg void OnBnClickedBtnSelectlotid();
	afx_msg void OnBnClickedBtnSelect();
	afx_msg void OnBnClickedCheckErrorimage();
	afx_msg void OnBnClickedCheckProbimage();
	afx_msg void OnBnClickedEditSaveokperiod();
	afx_msg void OnBnClickedEditSaveokimage();
};
