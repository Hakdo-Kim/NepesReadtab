#pragma once

#include "CommonCapture.h"
#include "CustomCaptureDisplay.h"

// CCustomCapture

#define MAX_CAPTUREDISPLAY			2


class CCustomCapture : public CStatic
{
	DECLARE_DYNAMIC(CCustomCapture)

public:
	CCustomCapture();
	virtual ~CCustomCapture();

	BOOL DisplayImage(const TYPE_CAMERAPOS eType, const INFO_IMAGE* pstImage, const DWORD dwCurFlag, const INFO_CAPTURE_PROCESS* pstCapture);
	void ClearImage(const TYPE_CAMERAPOS eType);

	BOOL IsClearImage(const TYPE_CAMERAPOS eType);

	void AddCount(const TYPE_CAMERAPOS eType);
	void ClearCount(const TYPE_CAMERAPOS eType);

protected:
	const int MARGIN = 5;
	COLORREF m_rgbBk;
	COLORREF m_rgbTxt;

	int m_nFontHeight;
	int m_nFontWeight;
	CString m_szFontName;


	CString m_szTitle;
	CCustomCaptureDisplay* m_pctlCaptureDisplay[MAX_CAPTUREDISPLAY];

	void DrawBackground(CDC* pMemDC);
	void DrawTitle(CDC* pMemDC);
	void AdjustLayout();

	virtual void PreSubclassWindow();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	
};


