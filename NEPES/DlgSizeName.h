#pragma once
#include "afxwin.h"
#include "CommonCapture.h"


// CDlgSizeName dialog

class CDlgSizeName : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgSizeName)

public:
	CDlgSizeName(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgSizeName();

// Dialog Data
	enum { IDD = IDD_DLG_SIZENAME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_szName[MAX_GEOMETRY_DISTANCELINE_COUNT];

	INFO_OPT_SIZENAME m_stInfoSizeName;

	afx_msg void OnBnClickedOk();

	void SetInfoSizeName(const INFO_OPT_SIZENAME *stInfoSizeName);

	void Log(char* pszLog, ...);
	virtual BOOL OnInitDialog();
};
