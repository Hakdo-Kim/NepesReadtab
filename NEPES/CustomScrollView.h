#pragma once

#include "Proc/ProcessDef.h"
#include "Tracker/LPTracker.h"

#include "CommonCapture.h"
#include "UserInterfaceDef.h"

#include "Inspection/Sample.h"
// Version 1.3.7.8
#include <memory> 
// CCustomScrollView view

class CCustomScrollView : public CScrollView
{
	DECLARE_DYNCREATE(CCustomScrollView)

protected:
	CCustomScrollView();           // protected constructor used by dynamic creation
	virtual ~CCustomScrollView();

	CRITICAL_SECTION m_CriticalSection;
	CRITICAL_SECTION m_CriticalSection_ImageBuffer;
	ULONG_PTR m_GdiPlusToken;

	BOOL m_bFitZoom;
	double m_fZoom;

	INFO_IMAGE* m_pstDisplayImage;
	INFO_DISPLAYOUTPUT m_stDisplayOutput;

	TYPE_CAMERAPOS m_eCameraPos;

#ifdef USE_BASLER_CAMERA
	unsigned char*				m_pColorBuffer;
	int							m_nColorBufLen;

	unsigned char*				m_pBuffer;
	int							m_nBufLen;
#endif


public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif
	void DisplayImage(const INFO_IMAGE* pstImage);
	const INFO_IMAGE* GetDisplayImage();
	void ClearImage();

	const double GetZoom();
	void SetZoom(double fZoom);

	void SetFitZoom(BOOL bFit);
	const double GetFitZoom();

	void DisplayStepOutput(TYPE_STEP eStep, void* pstOutput);
	void ClearStepOutput();

	TYPE_CAMERAPOS GetCameraPos() { return m_eCameraPos; }
	void SetCameraPos(TYPE_CAMERAPOS ePos);

	// Version 1.3.7.8
	std::unique_ptr<CSampleSide> m_Sample;

protected:
#ifdef USE_BASLER_CAMERA
	BOOL		CreateColorBuffer(const INFO_IMAGE* pImage);
#endif

	void DrawImage(CDC* pDC);
	void DrawImage8bit(CDC* pDC);
	void DrawImage24bit(CDC* pDC);

#ifdef USE_BASLER_CAMERA
	void DrawBaslerImage(CDC* pDC);
	void DrawBaslerImage24bit(CDC* pDC);
#endif


	void UpdateScrollSize();
	void CopyPixelBuffer8Bit(TYPE_STEP eStep, const int w, const int h, const int pitch, void* pvBits);
	void CopyPixelBuffer24Bit(TYPE_STEP eStep, const int w, const int h, const int pitch, void* pvBits);


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
	
	void FormatSizeLog(TCHAR* pStr, const int nStrLen, const TCHAR* pszSizeTitle, const double fSizeValue, const BOOL bSizeResult);
protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct

	DECLARE_MESSAGE_MAP()
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

	// Command Function - Edit
	afx_msg void OnCommandEdit();
	// Command Function - Grab
	afx_msg void OnCommandGrab();
	afx_msg void OnCommandStrobeOff();
	afx_msg void OnCommandStrobeCoaxial();
	afx_msg void OnCommandStrobeRing();
	afx_msg void OnCommandStrobeBar();
	// Command Function - Test
	afx_msg void OnCommandTestSize();
	afx_msg void OnCommandTestStep2();
	afx_msg void OnCommandTestStep3();
	afx_msg void OnCommandTestStep4();

};


