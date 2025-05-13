#pragma once

#include "Tracker/LPTracker.h"

#include "CommonCapture.h"
#include "UserInterfaceDef.h"

#include "Inspection/Sample.h"


// CCustomScrollViewSize view

class CCustomScrollViewSize : public CScrollView
{
	DECLARE_DYNCREATE(CCustomScrollViewSize)

protected:
	CCustomScrollViewSize();           // protected constructor used by dynamic creation
	virtual ~CCustomScrollViewSize();

	CRITICAL_SECTION m_CriticalSection;
	ULONG_PTR m_GdiPlusToken;

	BOOL m_bFitZoom;
	double m_fZoom;

	INFO_IMAGE* m_pstDisplayImage;
	OUTPUT_SIZE* m_pstOutputSize;


public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

	void DisplayResult(CSampleSide* pSampleSide);
	void ClearResult();

	const double GetZoom();
	void SetZoom(double fZoom);

	void SetFitZoom(BOOL bFit);
	const double GetFitZoom();


protected:
	void DrawImage(CDC* pDC);
	void DrawImage24bit(CDC* pDC);

	void UpdateScrollSize();

	void GetLineDistance_d(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText);
	void GetLineDistance_L(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText);
	void GetLineDistance_W(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText);

	void GetLineDistance_I1(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText);
	void GetLineDistance_I2(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText);
	void GetLineDistance_I3(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText);

	void GetLineDistance_M1(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText);
	void GetLineDistance_M2(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText);

	void GetLineDistance_S1(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText);
	void GetLineDistance_S2(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText);
	void GetLineDistance_S3(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText);
	void GetLineDistance_S4(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText);
	void GetLineDistance_S5(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText);

	void GetLineDistance_X1(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText);
	void GetLineDistance_X2(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText);

	void GetLineDistance_R(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText);

	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	void GetLineDistance_SS1(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText);
	void GetLineDistance_SS2(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText);
	void GetLineDistance_SS3(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText);

protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct
	DECLARE_MESSAGE_MAP()
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
};


