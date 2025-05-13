#pragma once
#include "CommonCapture.h"

// CDlgStrobeBrightness dialog

class CDlgStrobeBrightness : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgStrobeBrightness)

public:
	CDlgStrobeBrightness(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgStrobeBrightness();

	TYPE_CAMERAPOS m_eCameraPos;
	TYPE_STROBE m_eStrobe;
	int m_nBrightness;

// Dialog Data
	enum { IDD = IDD_DLG_BRIGHTNESS };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedOk();
};
