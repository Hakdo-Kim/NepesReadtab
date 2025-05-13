#pragma once


// CDlgInspection dialog

class CDlgInspection : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgInspection)

public:
	CDlgInspection(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgInspection();

// Dialog Data
	enum { IDD = IDD_DLG_STEPINSPECTION };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
