#pragma once
#include "RoiTracker.h"

#define DEF_CIRCLE
//#define DEF_ROTATE

#define ROICIRCLE_POINT_COUNT		9
#define CIRCLE_POINT_COUNT			5

class CCircleRoiTracker : public CRoiTracker
{
public:
	CCircleRoiTracker(CWnd* pWnd);
	virtual ~CCircleRoiTracker();

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

	INFO_POINT m_PointSrc[ROICIRCLE_POINT_COUNT];
	INFO_POINT m_PointDest[CIRCLE_POINT_COUNT];

	HCURSOR m_hCur[ROICIRCLE_POINT_COUNT];

	COLORREF m_rgbTrack;
	COLORREF m_rgbRoiRect;
	COLORREF m_rgbRoiCircle;

#ifdef DEF_ROTATE
	/// Rotate
	Matrix m_Transform;
	REAL  m_StartPhi;

	INFO_POINT m_FixedPoint;
	INFO_POINT m_MovingPoint;
#endif

	LPINFO_POINT m_pTrackCircle;

protected:
	virtual TYPE_RESULTROI OnBeginTrack(UINT nFlags, INFO_POINT point, float fZoom);
	virtual TYPE_RESULTROI OnEndTrack(TYPE_RESULTROI eResult, float fZoom, BOOL bErase = TRUE);
	virtual TYPE_RESULTROI OnMouseMessage(UINT msg, UINT nFlags, INFO_POINT point, float fZoom);
	virtual TYPE_RESULTROI OnMessage(MSG& msg);
	virtual void OnUpdate(CDC* pDC, UINT nMode, float fZoom);


	INFO_RECT GetHitRect(TYPE_HITROI eHit, float fZoom);
	INFO_POINT GetHitPoint(LPINFO_POINT pPoint, TYPE_HITROI eHit);

	void SetInitState(BOOL bInit);
	void SwapDestPoint(BOOL bW, BOOL bH);
	void ReverseDestPoint();
	void MirrorDestPointH();
	void MirrorDestPointV();

	void DrawRoiCircle(CDC* pDC, float fZoom);
	void DrawTrackCircle(CDC* pDC, LPINFO_POINT pPtList, int nPtLen);


	BOOL SetCursor(TYPE_HITROI eHit);

	void ResizeCircle(TYPE_HITROI eHitRoi, INFO_POINT point);
#ifdef DEF_ROTATE
	void ResizeRotatedCircle(TYPE_HITROI eHitRoi, INFO_POINT point, float fZoom);
#endif


};