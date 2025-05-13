#pragma once
#include "RoiTracker.h"

#define ROIRECT_POINT_COUNT		9
#define RECT_POINT_COUNT		4

class CRectRoiTracker : public CRoiTracker
{
public:
	CRectRoiTracker(CWnd* pWnd);
	virtual ~CRectRoiTracker();

	virtual BOOL IsInit();

	virtual TYPE_HITROI HitTest(INFO_POINT point, float fZoom);
	virtual void Draw(CDC* pDC, float fZoom);
	virtual void DrawRoi(CDC* pDC, INFO_SIZE stSize, float fZoom, void* pReserved = NULL);
	virtual void DrawTracker(CDC* pDC, INFO_POINT pt1, INFO_POINT pt2, float fZoom, BOOL bDone = FALSE);

	virtual BOOL IsEnableRotate();

	virtual BOOL SetCursor(CDC* pDC, float fZoom);

	virtual void Clear();


	virtual int GetPoint(LPINFO_POINT pPoint, int nLen);
	virtual int SetPoint(const LPINFO_POINT pPoint, const int nLen, float fZoom, BOOL bErase = TRUE);

	virtual BOOL SetWidth(DWORD dwWidth);
	virtual BOOL SetHeight(DWORD dwHeight);

	virtual BOOL MovePoint(int cx, int cy);

protected:
	BOOL m_bInit;

	TYPE_HITROI m_eHitRoi;
	TYPE_TRANSFORMROI m_eTransformRoi;

	INFO_POINT m_PointSrc[ROIRECT_POINT_COUNT];
	INFO_POINT m_PointDest[RECT_POINT_COUNT];
	
	HCURSOR m_hCur[ROIRECT_POINT_COUNT];

	COLORREF m_rgbTrack;
	COLORREF m_rgbRoiRect;
	COLORREF m_rgbRoiLine;

	LPINFO_POINT m_pTrackRect;
	
protected:
	virtual TYPE_RESULTROI OnBeginTrack(UINT nFlags, INFO_POINT point, float fZoom);
	virtual TYPE_RESULTROI OnEndTrack(TYPE_RESULTROI eResult, float fZoom, BOOL bErase = TRUE);
	virtual TYPE_RESULTROI OnMouseMessage(UINT msg, UINT nFlags, INFO_POINT point, float fZoom);
	virtual TYPE_RESULTROI OnMessage(MSG& msg);
	virtual void OnUpdate(CDC* pDC, UINT nMode, float fZoom);

	virtual void DrawRoiEdgeLine(CDC* pDC, INFO_SIZE stSize, LPINFO_POINT pPointList, float fZoom, void* pReserved);
	virtual void DrawRoiHStepLine(CDC* pDC, LPINFO_POINT pPointList, DWORD dwStep, float fZoom, BOOL bLtoR);
	virtual void DrawRoiVStepLine(CDC* pDC, LPINFO_POINT pPointList, DWORD dwStep, float fZoom, BOOL bTtoB);

	

	
	INFO_RECT GetHitRect(TYPE_HITROI eHit, float fZoom);
	INFO_POINT GetHitPoint(LPINFO_POINT pPoint, TYPE_HITROI eHit);

	void SetInitState(BOOL bInit);
	void SwapDestPoint(BOOL bW, BOOL bH);
	void ReverseDestPoint();
	void MirrorDestPointH();
	void MirrorDestPointV();
	
	void DrawRoiRectangle(CDC* pDC, float fZoom);
	void DrawTrackRectangle(CDC* pDC, LPINFO_POINT pPtList, int nPtLen);


	void ResizeRectangle(TYPE_HITROI eHitRoi, INFO_POINT point);
	void SetRectanglePoint(const INFO_POINT point, const INFO_POINT ptFix, INFO_POINT& ptMove, INFO_POINT& ptX, INFO_POINT& ptY);
	

	TYPE_HITROI HitLineTest(INFO_POINT point, TYPE_HITROI eStart, TYPE_HITROI eEnd, float fZoom);
	TYPE_HITROI HitTest(INFO_POINT point, INFO_POINT stStart, INFO_POINT stEnd, float fZoom);


	virtual BOOL SetCursor(TYPE_HITROI eHit);



};