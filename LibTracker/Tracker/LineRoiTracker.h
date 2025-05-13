#pragma once
#include "RoiTracker.h"

#define ROILINE_POINT_COUNT		3
#define LINE_POINT_COUNT		2


class CLineRoiTracker : public CRoiTracker
{
public:
	CLineRoiTracker(CWnd* pWnd);
	virtual ~CLineRoiTracker();

	virtual BOOL IsInit();

	virtual TYPE_HITROI HitTest(INFO_POINT point, float fZoom);
	virtual void Draw(CDC* pDC, float fZoom);
	virtual void DrawRoi(CDC* pDC, INFO_SIZE stSize, float fZoom, void* pReserved = NULL);
	virtual void DrawTracker(CDC* pDC, INFO_POINT pt1, INFO_POINT pt2, float fZoom, BOOL bDone = FALSE);

	virtual BOOL SetCursor(CDC* pDC, float fZoom);

	virtual void Clear();

	virtual int GetPoint(LPINFO_POINT pPoint, int nLen);
	virtual int SetPoint(const LPINFO_POINT pPoint, const int nLen, float fZoom, BOOL bErase = TRUE);

	virtual BOOL SetWidth(DWORD dwWidth);
	virtual BOOL SetHeight(DWORD dwHeight);

	virtual BOOL MovePoint(int cx, int cy);

protected:
	BOOL m_bInit;
	Matrix m_Transform;
	
	TYPE_HITROI m_eHitRoi;
	TYPE_TRANSFORMROI m_eTransformRoi;

	INFO_POINT m_PointSrc[ROILINE_POINT_COUNT];
	INFO_POINT m_PointDest[LINE_POINT_COUNT];

	HCURSOR m_hCur[ROILINE_POINT_COUNT];

	COLORREF m_rgbTrack;
	COLORREF m_rgbRoiRect;
	COLORREF m_rgbRoiLine;

	LPINFO_POINT m_pTrackLine;

protected:
	virtual TYPE_RESULTROI OnBeginTrack(UINT nFlags, INFO_POINT point, float fZoom);
	virtual TYPE_RESULTROI OnEndTrack(TYPE_RESULTROI eResult, float fZoom, BOOL bErase = TRUE);
	virtual TYPE_RESULTROI OnMouseMessage(UINT msg, UINT nFlags, INFO_POINT point, float fZoom);
	virtual TYPE_RESULTROI OnMessage(MSG& msg);
	virtual void OnUpdate(CDC* pDC, UINT nMode, float fZoom);


	INFO_RECT GetHitRect(TYPE_HITROI eHit, float fZoom);
	INFO_POINT GetHitPoint(LPINFO_POINT pPoint, TYPE_HITROI eHit);

	void SetInitState(BOOL bInit);
	void DrawRoiLine(CDC* pDC, float fZoom);
	void DrawTrackLine(CDC* pDC, LPINFO_POINT pPtList, int nPtLen);

	void SetPoint(const INFO_POINT point, INFO_POINT& pt1, INFO_POINT& pt2);

	TYPE_HITROI HitTest(INFO_POINT point, INFO_POINT stStart, INFO_POINT stEnd, float fZoom);

	BOOL SetCursor(TYPE_HITROI eHit);

};