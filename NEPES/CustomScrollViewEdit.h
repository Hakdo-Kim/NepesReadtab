#pragma once

#include "Proc/ProcessDef.h"
#include "Tracker/LPTracker.h"

#include "UserInterfaceDef.h"
#include "CommonCapture.h"

#include "Inspection/Sample.h"

// CCustomScrollViewEdit view

class CCustomScrollViewEdit : public CScrollView
{
	DECLARE_DYNCREATE(CCustomScrollViewEdit)

protected:
	CCustomScrollViewEdit();           // protected constructor used by dynamic creation
	virtual ~CCustomScrollViewEdit();

	CRITICAL_SECTION m_CriticalSection;

	BOOL m_bFitZoom;
	double m_fZoom;

	INFO_IMAGE* m_pstDisplayImage;


	// Inspection
	TYPE_CAMERAPOS m_eCameraType;
	TYPE_STEP m_eStep;
	CLPTracker m_pTrackerFindLine[TYPE_FINDLINE_MAX];
	int m_nTrackerIdxForEdit;

	INFO_DISPLAYOUTPUT m_stDisplayOutput;

	CLPTracker m_TrackerStain;
	CLPTracker m_TrackerDiffer;
	CLPTracker m_TrackerBubble;
	CLPTracker m_TrackerScratch;
	CLPTracker m_TrackerStamp;

#ifdef USE_BASLER_CAMERA
	unsigned char*				m_pColorBuffer;
	int							m_nColorBufLen;
#endif

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif


	void DisplayImage(const INFO_IMAGE* pstImage);
#ifdef USE_BASLER_CAMERA
	void DisplayEditImage(const INFO_IMAGE* pstImage);
#endif
	void ClearImage();
	INFO_IMAGE* GetImage();

	const double GetZoom();
	void SetZoom(double fZoom);

	void SetFitZoom(BOOL bFit);
	const double GetFitZoom();

	void SetDisplayStep(TYPE_CAMERAPOS eCameraType, TYPE_STEP eStep);
	void GetDisplayStep(TYPE_CAMERAPOS& eCameraType, TYPE_STEP& eStep);

	void SelectSteSizeRoi(int nCur);

	void DisplayStepOutput(TYPE_STEP eStep, void* pstOutput);
	void GetDisplayStepOutput(TYPE_STEP& eStep);
	void ClearStepOutput();
	

protected:
#ifdef USE_BASLER_CAMERA
	BOOL CreateColorBuffer(const INFO_IMAGE* pImage);
#endif
	void DrawImage8bit(CDC* pDC);
	void DrawImage24bit(CDC* pDC);

#ifdef USE_BASLER_CAMERA
	void DrawBaslerImage(CDC* pDC);
	void DrawBaslerImage24bit(CDC* pDC);
#endif

	void DrawTrackerForSize(CDC* pDC, const int w, const int h, const double fZoom);
	void DrawTrackerForOther(CDC* pDC, const int w, const int h, const double fZoom);

	void UpdateScrollSize();

	void SetDisplayStepSize();
	void SetDisplayStepOther(TYPE_STEP eStep);

	void CopyPixelBuffer8Bit(TYPE_STEP eStep, const int w, const int h, const int pitch, void* pvBits);
	void CopyPixelBuffer24Bit(TYPE_STEP eStep, const int w, const int h, const int pitch, void* pvBits);

protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct

	DECLARE_MESSAGE_MAP()
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);

	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	

	// Command Function - Zoom
	afx_msg void OnCommandZoomIn();
	afx_msg void OnCommandZoomOut();
	afx_msg void OnCommandZoomFit();
	afx_msg void OnCommandZoom100();
	// Command Function - Grab
	afx_msg void OnCommandGrabEdit();
	// Command Function - Strobe
	afx_msg void OnCommandStrobeOff();
	afx_msg void OnCommandStrobeCoaxial();
	afx_msg void OnCommandStrobeRing();
	afx_msg void OnCommandStrobeBar();

public:
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
};


