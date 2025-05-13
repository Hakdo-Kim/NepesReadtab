#pragma once

#include "CustomScrollView.h"
#include "CustomStep.h"

#include "CommonCapture.h"
#include "UserInterfaceDef.h"

#include "Proc/ProcessDef.h"



// CTapView dialog

class CTapView : public CDialogEx
{
	DECLARE_DYNAMIC(CTapView)
public:
	CTapView(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTapView();

	CCustomScrollView* GetScrollView();
	
	void SetCameraPos(TYPE_CAMERAPOS ePos);
	const TYPE_CAMERAPOS GetCameraPos();

	void SetStepState(TYPE_STEP eStep, BOOL bResult);
	void UpdateEnableStep();

	

// Dialog Data
	enum { IDD = IDD_TAP_VIEW };
protected:
	const int MARGIN = 5;
	const int BARHEIGHT = 80;
	const int STEPWIDTH = 60;

	TYPE_CAMERAPOS m_eCameraPos;
	TYPE_STEP m_eStep;

	RECT m_rtBar;

	CCustomScrollView* m_pCustomView;
	CCustomStep m_pCustomStepList[TYPE_STEP_MAX];
	BOOL m_pStepResultList[TYPE_STEP_MAX];

	// ui function
	void AdjustLayout();
	void DrawBarLayout(CDC* pDC, CRect rect, COLORREF rgbBk, DWORD dwLT, DWORD dwLB, DWORD dwRT, DWORD dwRB);
	int GetStringLength(CString* pString);
	CString GetString(CString* pString, const int nStart, const int nEnd);
	

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	DECLARE_MESSAGE_MAP()
	afx_msg LRESULT OnMsgEdit(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMsgGrab(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMsgStrobe(WPARAM wParam, LPARAM lParam);

	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();

};
