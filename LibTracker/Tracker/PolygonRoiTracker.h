#pragma once
#include "RoiTracker.h"

#include <vector>

#define POLYGON_CURSOR_COUNT	5

#define POLYGON_POINT_COUNT		2
#define POLYGON_POINT_MINCOUNT	2

#define POLYGON_VALUE_INFLATE	(VALUE_INFLATE*2)

class CPolygonRoiTracker : public CRoiTracker
{
public:
	CPolygonRoiTracker(CWnd* pWnd);
	virtual ~CPolygonRoiTracker();

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

	std::vector<INFO_POINT> m_PointSrc;
	std::vector<INFO_POINT> m_PointDest;
	int m_nIdxDest;

	HCURSOR m_hCur[POLYGON_CURSOR_COUNT];

	COLORREF m_rgbTrack;
	COLORREF m_rgbRoiRect;
	COLORREF m_rgbRoiPolygon;

	LPINFO_POINT m_pTrackPolygon;
	int m_nPolygonLen;


protected:
	virtual TYPE_RESULTROI OnBeginTrack(UINT nFlags, INFO_POINT point, float fZoom);
	virtual TYPE_RESULTROI OnEndTrack(TYPE_RESULTROI eResult, float fZoom, BOOL bErase = TRUE);
	virtual TYPE_RESULTROI OnMouseMessage(UINT msg, UINT nFlags, INFO_POINT point, float fZoom);
	virtual TYPE_RESULTROI OnMessage(MSG& msg);
	virtual void OnUpdate(CDC* pDC, UINT nMode, float fZoom);

	INFO_RECT GetHitRect(int nIdx, float fZoom);
	INFO_POINT GetHitPoint(LPINFO_POINT pPoint, TYPE_HITROI eHit);

	void SetInitState(BOOL bInit);

	void DrawRoiPolygon(CDC* pDC, float fZoom);
	void DrawTrackPolygon(CDC* pDC, LPINFO_POINT pPtList, int nPtLen);


	TYPE_HITROI HitTest(INFO_POINT point, int* pIdxList, int nLen, float fZoom);
	TYPE_HITROI HitTest(INFO_POINT point, INFO_POINT stStart, INFO_POINT stEnd, float fZoom);

	BOOL SetCursor(int nIdx);



};