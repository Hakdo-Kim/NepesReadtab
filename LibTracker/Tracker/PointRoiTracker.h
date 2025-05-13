#pragma once
#include "RoiTracker.h"

class CPointRoiTracker : public CRoiTracker
{
public:
	CPointRoiTracker(CWnd* pWnd);
	virtual ~CPointRoiTracker();

	virtual BOOL IsInit();
	virtual void Clear();

	virtual TYPE_HITROI HitTest(INFO_POINT point, float fZoom);
	virtual void Draw(CDC* pDC, float fZoom);
	virtual void DrawRoi(CDC* pDC, INFO_SIZE stSize, float fZoom, void* pReserved = NULL);
	virtual void DrawTracker(CDC* pDC, INFO_POINT pt1, INFO_POINT pt2, float fZoom, BOOL bDone = FALSE);

	virtual int GetPoint(LPINFO_POINT pPoint, int nLen);
	virtual int SetPoint(const LPINFO_POINT pPoint, const int nLen, float fZoom, BOOL bErase = TRUE);

	virtual void SetAlign(TYPE_ALIGN eAlign, INFO_RECT rtPos);

	virtual BOOL MovePoint(int cx, int cy);

protected:
	BOOL m_bInit;

	COLORREF m_rgbTrack;
	COLORREF m_rgbRoiPoint;

	LPINFO_POINT m_pTrackPoint;

	virtual TYPE_RESULTROI OnBeginTrack(UINT nFlags, INFO_POINT point, float fZoom);
	virtual TYPE_RESULTROI OnEndTrack(TYPE_RESULTROI eResult, float fZoom, BOOL bErase = TRUE);
	virtual TYPE_RESULTROI OnMouseMessage(UINT msg, UINT nFlags, INFO_POINT point, float fZoom);
	virtual TYPE_RESULTROI OnMessage(MSG& msg);
	virtual void OnUpdate(CDC* pDC, UINT nMode, float fZoom);


	INFO_RECT GetHitRect(TYPE_HITROI eHit, float fZoom);
	INFO_POINT GetHitPoint(LPINFO_POINT pPoint, TYPE_HITROI eHit);

	void SetInitState(BOOL bInit);
	void DrawRoiPoint(CDC* pDC, float fZoom);

	void DrawTrackPoint(CDC* pDC, INFO_POINT point);




};