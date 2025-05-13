#pragma once
#include "RectRoiTracker.h"

class CRotateRectRoiTracker : public CRectRoiTracker
{
public:
	CRotateRectRoiTracker(CWnd* pWnd);
	virtual ~CRotateRectRoiTracker();

	virtual TYPE_HITROI HitTest(INFO_POINT point, float fZoom);
	virtual void Draw(CDC* pDC, float fZoom);
	virtual void DrawRoi(CDC* pDC, INFO_SIZE stSize, float fZoom, void* pReserved = NULL);
	virtual void DrawTracker(CDC* pDC, INFO_POINT pt1, INFO_POINT pt2, float fZoom, BOOL bDone = FALSE);

	virtual BOOL IsEnableRotate();

	virtual BOOL SetCursor(CDC* pDC, float fZoom);

	virtual BOOL SetWidth(DWORD dwWidth);
	virtual BOOL SetHeight(DWORD dwHeight);


protected:
	/// Rotate
	Matrix m_Transform;
	REAL  m_StartPhi;

	INFO_POINT m_FixedPoint;
	INFO_POINT m_MovingPoint;


protected:
	virtual TYPE_RESULTROI OnBeginTrack(UINT nFlags, INFO_POINT point, float fZoom);
	virtual TYPE_RESULTROI OnEndTrack(TYPE_RESULTROI eResult, float fZoom, BOOL bErase = TRUE);
	virtual TYPE_RESULTROI OnMouseMessage(UINT msg, UINT nFlags, INFO_POINT point, float fZoom);
	virtual TYPE_RESULTROI OnMessage(MSG& msg);
	virtual void OnUpdate(CDC* pDC, UINT nMode, float fZoom);

	virtual void DrawRoiEdgeLine(CDC* pDC, INFO_SIZE stSize, LPINFO_POINT pPointList, float fZoom, void* pReserved);
	virtual void DrawRoiHStepLine(CDC* pDC, LPINFO_POINT pPointList, DWORD dwStep, float fZoom, BOOL bLtoR);
	virtual void DrawRoiVStepLine(CDC* pDC, LPINFO_POINT pPointList, DWORD dwStep, float fZoom, BOOL bTtoB);

	void DrawRoiRectangle(CDC* pDC, float fZoom);
	void ResizeRotatedRectangle(TYPE_HITROI eHitRoi, INFO_POINT point, float fZoom);
	
	TYPE_HITROI HitLineTest(INFO_POINT point, TYPE_HITROI eStart, TYPE_HITROI eEnd, float fZoom);
	TYPE_HITROI HitTest(INFO_POINT point, INFO_POINT stStart, INFO_POINT stEnd, float fZoom);

	virtual BOOL SetCursor(TYPE_HITROI eHit);
	


};