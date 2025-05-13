#pragma once


// CDlgLotID dialog

class CDlgLotID : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgLotID)

public:
	CDlgLotID(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgLotID();

	CString m_szLotID;

// Dialog Data
	enum { IDD = IDD_DLG_LOTID };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedOk();

};
