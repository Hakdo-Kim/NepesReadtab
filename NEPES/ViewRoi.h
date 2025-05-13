#pragma once

#include "Camera/CameraInterfaceDef.h"
#include "Camera/CameraDev.h"

#include "RoiRectTracker.h"



#define ROI_HFACTOR			4
#define ROI_VFACTOR			2

// CViewRoi

class CViewRoi : public CStatic
{
	DECLARE_DYNAMIC(CViewRoi)

public:
	CViewRoi();
	virtual ~CViewRoi();

	void UpdateInformation(const INFO_DEFROI* pDefROI);


	void SetRoi(const INFO_ROI_PARA* pstRoi);
	void SetRoiPosition(int x, int y, int w, int h);

	void GetRoi(INFO_ROI_PARA* pstRoi);

	void CorrectRoi(INFO_ROI_PARA* pstRoi);


protected:
	INFO_DEFROI m_stDefRoi;		// Default Information
	BOOL m_bDefInit;

	CRoiRectTracker* m_pTracker;
	INFO_ROI_PARA	m_stRoi;


	COLORREF m_BkColor;
	COLORREF m_GuideColor;
	COLORREF m_LineColor;
	COLORREF m_RoiColor;

	void DrawBackground(CDC* pDC);
	void DrawLine(CDC* pMemDC);

	const POINT GetStartPoint();
	const POINT GetEndPoint();

	void GetRect(const INFO_ROI_PARA* pstRoi, RECT* pRect);
	void GetRoi(INFO_ROI_PARA* pstRoi, RECT* pRect, const INFO_ROI_PARA* pstCur = NULL);


	DECLARE_MESSAGE_MAP()
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	afx_msg void OnPaint();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
};


