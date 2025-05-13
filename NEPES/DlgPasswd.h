#pragma once


// CDlgPasswd dialog

class CDlgPasswd : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgPasswd)

public:
	CDlgPasswd(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgPasswd();

	CString m_szPasswd;

// Dialog Data
	enum { IDD = IDD_DLG_PASSWD };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedOk();
};
