#pragma once

#include "CommonCapture.h"
#include "StaticDisplay.h"
#include "StaticText.h"

// CCustomCaptureDisplay

class CCustomCaptureDisplay : public CStatic
{
	DECLARE_DYNAMIC(CCustomCaptureDisplay)

public:
	CCustomCaptureDisplay();
	virtual ~CCustomCaptureDisplay();

	void SetTitle(TCHAR* pszTitle);
	void SetPostionType(TYPE_CAMERAPOS eType);

	BOOL DisplayImage(const INFO_IMAGE* pstImage, const DWORD dwCurFlag, const INFO_CAPTURE_PROCESS* pstCapture);
	void ClearImage();

	BOOL IsClearImage();

	void AddCount();
	void ClearCount();

protected:
	const int MARGIN = 5;
	COLORREF m_rgbBk;
	COLORREF m_rgbTxt;

	int m_nFontHeight;
	int m_nFontWeight;
	CString m_szFontName;


	CString m_szTitle;
	TYPE_CAMERAPOS m_ePosType;
	CStaticDisplay* m_pctlDisplay;
	
	CStaticText* m_pctlCount;
	DWORD m_dwFrameCount;
	

	void DrawBackground(CDC* pMemDC);
	void DrawTitle(CDC* pMemDC);
	void AdjustLayout();

	virtual void PreSubclassWindow();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
};


