#pragma once


// CDlgLotIDOnce dialog

class CDlgLotIDOnce : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgLotIDOnce)

public:
	CDlgLotIDOnce(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgLotIDOnce();

	CString m_szLotID_A;
	CString m_szLotID_B;


// Dialog Data
	enum { IDD = IDD_DLG_LOTID_ONE };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEditLotid();
};
