#pragma once
#include "afxcmn.h"
#include "afxwin.h"

#include "CommonCapture.h"
#include "CustomScrollViewSize.h"
#include "CustomMessage.h"

#include "Inspection/Sample.h"

#include "TapSizeList.h"

// CTapMainSize dialog

class CTapMainSize : public CDialogEx
{
	DECLARE_DYNAMIC(CTapMainSize)

public:
	CTapMainSize(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTapMainSize();
	
	void UpdateResultSize(TYPE_CAMERAPOS eCameraPos, CSampleSide* pSample);;
	void UpdateRangeValue(TYPE_CAMERAPOS eCameraPos);
	void UpdateSizeName();

	void SetStateStartInspection();

// Dialog Data
	enum { IDD = IDD_TAP_MAINSIZE };
protected:
	const int MARGIN = 5;

	// Size Log Handle
	HANDLE m_hFileSample_First;
	HANDLE m_hFileSample_Second;
	HANDLE m_hFileSample_Total;

	RECT m_rtView;
	RECT m_rtFirstView;
	RECT m_rtSecondView;

	CCustomMessage m_ctlTitleSampleFirst;
	CCustomMessage m_ctlTitleSampleSecond;

	CCustomScrollViewSize* m_pScrollViewList[MAX_VIEW];
	CTapSizeList m_TapSizeList;


	void AdjustLayout();
	void DrawLayout(CDC* pDC, CRect rect, COLORREF rgbBk, DWORD dwLT, DWORD dwLB, DWORD dwRT, DWORD dwRB);


	void FormatSizeLog(TCHAR* pStr, const int nStrLen, const TCHAR* pszSizeTitle, const double fSizeValue, const BOOL bSizeResult);
	void WriteSizeLog(TYPE_CAMERAPOS eCameraPos, TCHAR* pString, int nLen);

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
};
