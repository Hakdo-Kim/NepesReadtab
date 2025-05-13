#pragma once
#include "RoiTracker.h"

#define ROIRING_POINT_COUNT		5
#define RING_POINT_COUNT		5

#define MIN_RING_DISTANCE		1

class CRingRoiTracker : public CRoiTracker
{
public:
	CRingRoiTracker(CWnd* pWnd);
	virtual ~CRingRoiTracker();

	virtual BOOL IsInit();

	virtual TYPE_HITROI HitTest(INFO_POINT point, float fZoom);
	virtual void Draw(CDC* pDC, float fZoom);
	virtual void DrawRoi(CDC* pDC, INFO_SIZE stSize, float fZoom, void* pReserved = NULL);
	virtual void DrawTracker(CDC* pDC, INFO_POINT pt1, INFO_POINT pt2, float fZoom, BOOL bDone = FALSE);

	virtual BOOL SetCursor(CDC* pDC, float fZoom);

	virtual void Clear();

	virtual int GetPoint(LPINFO_POINT pPoint, int nLen);
	virtual int SetPoint(const LPINFO_POINT pPoint, const int nLen, float fZoom, BOOL bErase = TRUE);

	virtual INFO_RECT GetPositionRect(LPINFO_POINT pPointList, int nLen);

	virtual void SetAlign(TYPE_ALIGN eAlign, INFO_RECT rtPos);

	virtual BOOL SetWidth(DWORD dwWidth);
	virtual BOOL SetHeight(DWORD dwHeight);

	virtual BOOL MovePoint(int cx, int cy);

protected:
	BOOL m_bInit;
	Matrix m_Transform;

	TYPE_HITROI m_eHitRoi;
	TYPE_TRANSFORMROI m_eTransformRoi;

	INFO_POINT m_PointSrc[ROIRING_POINT_COUNT];
	INFO_POINT m_PointDest[RING_POINT_COUNT];

	HCURSOR m_hCur[ROIRING_POINT_COUNT+3];

	COLORREF m_rgbTrack;
	COLORREF m_rgbRoiRect;
	COLORREF m_rgbRoiRing;

	const int MATCH_MARGIN = 1;
	const int MINGAP = 3;

	LPINFO_POINT m_pTrackRing;

protected:
	virtual TYPE_RESULTROI OnBeginTrack(UINT nFlags, INFO_POINT point, float fZoom);
	virtual TYPE_RESULTROI OnEndTrack(TYPE_RESULTROI eResult, float fZoom, BOOL bErase = TRUE);
	virtual TYPE_RESULTROI OnMouseMessage(UINT msg, UINT nFlags, INFO_POINT point, float fZoom);
	virtual TYPE_RESULTROI OnMessage(MSG& msg);
	virtual void OnUpdate(CDC* pDC, UINT nMode, float fZoom);

	void DrawRoiEdgeLine(CDC* pDC, INFO_SIZE stSize, LPINFO_POINT pPointList, float fZoom, void* pReserved);

	INFO_RECT GetHitRect(TYPE_HITROI eHit, float fZoom);
	INFO_POINT GetHitPoint(LPINFO_POINT pPoint, TYPE_HITROI eHit);

	void SetInitState(BOOL bInit);
	void DrawRoiRing(CDC* pDC, float fZoom);
	void DrawTrackRing(CDC* pDC, LPINFO_POINT pPtList, int nPtLen);

	TYPE_HITROI HitLineTest(INFO_POINT point, TYPE_HITROI eStart, TYPE_HITROI eEnd, float fZoom);
	TYPE_HITROI HitTest(INFO_POINT point, INFO_POINT stStart, INFO_POINT stEnd, float fZoom);

	BOOL SetCursor(TYPE_HITROI eHit, float fZoom);



};