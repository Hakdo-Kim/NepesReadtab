#pragma once
#include "afxwin.h"
#include "CustomMessage.h"
#include "TapView.h"


// CTapMainScenario dialog

class CTapMainScenario : public CDialogEx
{
	DECLARE_DYNAMIC(CTapMainScenario)

public:
	CTapMainScenario(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTapMainScenario();

	CCustomScrollView* GetScrollView(TYPE_CAMERAPOS eCameraPos);
	const TYPE_CAMERAPOS GetViewFromMessage(CWnd* pWnd);

	void SetStepState(TYPE_CAMERAPOS eCameraPos, TYPE_STEP eStep, BOOL bResult = TRUE);
	void UpdateResult(TYPE_CAMERAPOS eCameraPos, TYPE_STEP eStep, CSampleSide* pSample);

	void UpdateEnableStep();

// Dialog Data
	enum { IDD = IDD_TAP_MAINSCENARIO };
protected:
	const int MARGIN = 5;

	RECT m_rtView;
	RECT m_rtFirstView;
	RECT m_rtSecondView;

	CCustomMessage m_ctlFirstTitle;
	CCustomMessage m_ctlSecondTitle;

	CTapView m_pViewList[MAX_VIEW];

	void AdjustLayout();
	void DrawLayout(CDC* pDC, CRect rect, COLORREF rgbBk, DWORD dwLT, DWORD dwLB, DWORD dwRT, DWORD dwRB);

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();

	// Command Function
	afx_msg LRESULT OnMsgEdit(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMsgGrab(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMsgGrabEdit(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMsgStrobe(WPARAM wParam, LPARAM lParam);
};
