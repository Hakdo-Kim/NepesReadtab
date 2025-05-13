#pragma once
#include "afxwin.h"
#include "CommonCapture.h"
#include "CustomMessage.h"
#include "TapSizeList.h"
#include "Inspection/Sample.h"

#include "TapView.h"
// Version 1.366
#include "Util/Util.h"

// CTapMainCount dialog

class CTapMainCount : public CDialogEx
{
	DECLARE_DYNAMIC(CTapMainCount)

public:
	CTapMainCount(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTapMainCount();

	void UpdateResultSize(TYPE_CAMERAPOS eCameraPos, CSampleSide* pSample);
	void UpdateRangeValue(TYPE_CAMERAPOS eCameraPos);
	void UpdateSizeName();


	////////////
	//CCustomScrollView* GetScrollView(TYPE_CAMERAPOS eCameraPos);
	//const TYPE_CAMERAPOS GetViewFromMessage(CWnd* pWnd);
	void SetStepState(TYPE_CAMERAPOS eCameraPos, TYPE_STEP eStep, BOOL bResult = TRUE);
	void UpdateResult(TYPE_CAMERAPOS eCameraPos, TYPE_STEP eStep, CSampleSide* pSample);
	void DrawLayout(CDC* pDC, CRect rect, COLORREF rgbBk, DWORD dwLT, DWORD dwLB, DWORD dwRT, DWORD dwRB);
	
	// Version 1.366
	void CTapMainCount::UpdateMonitoring(CString FirstMonitoring, CString SecondMonitoring, CString OptionMonitoring, CString ImageFormatMonitoring);

	void UpdateEnableStep();
	////////////

// Dialog Data
	enum { IDD = IDD_TAP_MAINCOUNT };

protected:
	const int MARGIN = 5;

	RECT m_rtView;

	CTapSizeList m_TapSizeList;

	CTapView m_pViewList[MAX_VIEW];

	// Version 1.366
	CStatic *m_label[MAX_TYPE_MONITORINGOPTION];


	void AdjustLayout();

	void UpdateList();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnSize(UINT nType, int cx, int cy);
public:
	afx_msg void OnPaint();
};
