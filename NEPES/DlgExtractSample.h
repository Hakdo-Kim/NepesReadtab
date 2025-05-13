#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "CustomMessage.h"

// CDlgExtractSample dialog

class CDlgExtractSample : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgExtractSample)

public:
	CDlgExtractSample(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgExtractSample();

// Dialog Data
	enum { IDD = IDD_DLG_STEPEXTRACT };

protected:
	CCustomMessage m_ctlFirstTitle;
	CCustomMessage m_ctlSecondTitle;

	CListCtrl m_ctlFirstQueue;
	CListCtrl m_ctlSecondQueue;


	void UpdateListSampleQueue();


	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnLvnItemchangedListFirstqueue(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedListSecondqueue(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBtnFirstDelete();
	afx_msg void OnBnClickedBtnSecondDelete();
};
