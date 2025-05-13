#include "StdAfx.h"
#include "TrackerLibrary.h"

#include "./CircleRoiTracker.h"
#include "./LineRoiTracker.h"
#include "./PointRoiTracker.h"
#include "./PolygonRoiTracker.h"
#include "./RectRoiTracker.h"
#include "./RotateRectRoiTracker.h"
#include "./RingRoiTracker.h"


HTRACKER InitTracker(TYPE_TRACKER eTracker, CWnd* pWnd)
{
	if (NULL == pWnd)
		return NULL;

	HTRACKER hTracker = NULL;

	if (TYPE_TRACKER_CIRCLE == eTracker)
		hTracker = new CCircleRoiTracker(pWnd);

	else if (TYPE_TRACKER_LINE == eTracker)
		hTracker = new CLineRoiTracker(pWnd);

	else if (TYPE_TRACKER_POINT == eTracker)
		hTracker = new CPointRoiTracker(pWnd);

	else if (TYPE_TRACKER_POLYGON == eTracker)
		hTracker = new CPolygonRoiTracker(pWnd);

	else if (TYPE_TRACKER_RECT == eTracker)
		hTracker = new CRectRoiTracker(pWnd);

	else if (TYPE_TRACKER_RECT_ROTATE == eTracker)
		hTracker = new CRotateRectRoiTracker(pWnd);

	else if (TYPE_TRACKER_RING == eTracker)
		hTracker = new CRingRoiTracker(pWnd);

	return hTracker;
}

void DeinitTracker(HTRACKER hTracker)
{
	TYPE_TRACKER eTracker = GetTrackerType(hTracker);

	if (TYPE_TRACKER_CIRCLE == eTracker)
	{
		CCircleRoiTracker* pTracker = dynamic_cast<CCircleRoiTracker*> ((CRoiTracker*)hTracker);
		delete pTracker;
	}
	else if (TYPE_TRACKER_LINE == eTracker)
	{
		CLineRoiTracker* pTracker = dynamic_cast<CLineRoiTracker*> ((CRoiTracker*)hTracker);
		delete pTracker;
	}
	else if (TYPE_TRACKER_POINT == eTracker)
	{
		CPointRoiTracker* pTracker = dynamic_cast<CPointRoiTracker*> ((CRoiTracker*)hTracker);
		delete pTracker;
	}
	else if (TYPE_TRACKER_POLYGON == eTracker)
	{
		CPolygonRoiTracker* pTracker = dynamic_cast<CPolygonRoiTracker*> ((CRoiTracker*)hTracker);
		delete pTracker;
	}
	else if (TYPE_TRACKER_RECT == eTracker)
	{
		CRectRoiTracker* pTracker = dynamic_cast<CRectRoiTracker*> ((CRoiTracker*)hTracker);
		delete pTracker;
	}
	else if (TYPE_TRACKER_RECT_ROTATE == eTracker)
	{
		CRotateRectRoiTracker* pTracker = dynamic_cast<CRotateRectRoiTracker*> ((CRoiTracker*)hTracker);
		delete pTracker;
	}
	else if (TYPE_TRACKER_RING == eTracker)
	{
		CRingRoiTracker* pTracker = dynamic_cast<CRingRoiTracker*> ((CRoiTracker*)hTracker);
		delete pTracker;
	}
}


BOOL IsInitTracker(HTRACKER hTracker)
{
	BOOL bResult = FALSE;

	CRoiTracker* pTracker = dynamic_cast<CRoiTracker*> ((CRoiTracker*)hTracker);
	if (pTracker)
	{
		bResult = pTracker->IsInit();
	}
	return bResult;
}

TYPE_TRACKER GetTrackerType(HTRACKER hTracker)
{
	TYPE_TRACKER eTracker = TYPE_TRACKER_NONE;

	if (dynamic_cast<CCircleRoiTracker*> ((CRoiTracker*)hTracker))
	{
		eTracker = TYPE_TRACKER_CIRCLE;
	}
	else if (dynamic_cast<CLineRoiTracker*> ((CRoiTracker*)hTracker))
	{
		eTracker = TYPE_TRACKER_LINE;
	}
	else if (dynamic_cast<CPointRoiTracker*> ((CRoiTracker*)hTracker))
	{
		eTracker = TYPE_TRACKER_POINT;
	}
	else if (dynamic_cast<CPolygonRoiTracker*> ((CRoiTracker*)hTracker))
	{
		eTracker = TYPE_TRACKER_POLYGON;
	}
	else if (dynamic_cast<CRotateRectRoiTracker*> ((CRoiTracker*)hTracker))
	{
		eTracker = TYPE_TRACKER_RECT_ROTATE;
	}
	else if (dynamic_cast<CRectRoiTracker*> ((CRoiTracker*)hTracker))
	{
		eTracker = TYPE_TRACKER_RECT;
	}	
	else if (dynamic_cast<CRingRoiTracker*> ((CRoiTracker*)hTracker))
	{
		eTracker = TYPE_TRACKER_RING;
	}

	return eTracker;
}

BOOL SetTrackerCursor(HTRACKER hTracker, CDC* pDC, float fZoom)
{
	BOOL bResult = FALSE;

	CRoiTracker* pTracker = dynamic_cast<CRoiTracker*> ((CRoiTracker*)hTracker);
	if (pTracker)
	{
		bResult = pTracker->SetCursor(pDC, fZoom);
	}
	return bResult;
}

void ClearTracker(HTRACKER hTracker)
{
	CRoiTracker* pTracker = dynamic_cast<CRoiTracker*> ((CRoiTracker*)hTracker);
	if (pTracker)
	{
		pTracker->Clear();
	}
}

BOOL RunTracker(HTRACKER hTracker, CDC* pDC, UINT nFlags, TRACKPOINT point, float fZoom, BOOL bErase)
{
	BOOL bResult = FALSE;

	CRoiTracker* pTracker = dynamic_cast<CRoiTracker*> ((CRoiTracker*)hTracker);
	if (pTracker)
	{
		INFO_POINT stPoint;
		stPoint.m_fx = point.m_fx;
		stPoint.m_fy = point.m_fy;

		bResult = pTracker->Track(pDC, nFlags, stPoint, fZoom, bErase);
	}
	return bResult;	
}

void DrawTracker(HTRACKER hTracker, CDC* pDC, float fZoom)
{
	CRoiTracker* pTracker = dynamic_cast<CRoiTracker*> ((CRoiTracker*)hTracker);
	if (pTracker)
	{
		pTracker->Draw(pDC, fZoom);
	}
}

void DrawRoi(HTRACKER hTracker, CDC* pDC, TRACKSIZE size, float fZoom, void* pReserved)
{
	CRoiTracker* pTracker = dynamic_cast<CRoiTracker*> ((CRoiTracker*)hTracker);
	if (pTracker)
	{
		INFO_SIZE stSize;
		stSize.m_fcx = size.m_fcx;
		stSize.m_fcy = size.m_fcy;

		pTracker->DrawRoi(pDC, stSize, fZoom, pReserved);
	}
}

void DrawMoveTracker(HTRACKER hTracker, CDC* pDC, TRACKPOINT pt1, TRACKPOINT pt2, float fZoom, BOOL bDone)
{
	CRoiTracker* pTracker = dynamic_cast<CRoiTracker*> ((CRoiTracker*)hTracker);
	if (pTracker)
	{
		INFO_POINT stPt1;
		INFO_POINT stPt2;

		stPt1.m_fx = pt1.m_fx;
		stPt1.m_fy = pt1.m_fy;

		stPt2.m_fx = pt2.m_fx;
		stPt2.m_fy = pt2.m_fy;

		pTracker->DrawTracker(pDC, stPt1, stPt2, fZoom, bDone);
	}
}



int	GetTrackerPoint(HTRACKER hTracker, LPTRACKPOINT pPoint, int nLen)
{
	CRoiTracker* pTracker = dynamic_cast<CRoiTracker*> ((CRoiTracker*)hTracker);
	
	int nCount = 0;
	if (pTracker)
	{
		INFO_POINT* pPointList = new INFO_POINT[nLen];

		nCount = pTracker->GetPoint(pPointList, nLen);

		for (int i = 0; i < nLen; i++)
		{
			pPoint[i].m_fx = pPointList[i].m_fx;
			pPoint[i].m_fy = pPointList[i].m_fy;
		}
		delete[] pPointList;
	}
	return nCount;
}

int	SetTrackerPoint(HTRACKER hTracker, const LPTRACKPOINT pPoint, const int nLen, float fZoom, BOOL bErase)
{
	CRoiTracker* pTracker = dynamic_cast<CRoiTracker*> ((CRoiTracker*)hTracker);

	int nCount = 0;
	if (pTracker)
	{
		INFO_POINT* pPointList = new INFO_POINT[nLen];
		for (int i = 0; i < nLen; i++)
		{
			pPointList[i].m_fx = pPoint[i].m_fx;
			pPointList[i].m_fy = pPoint[i].m_fy;
		}
		nCount = pTracker->SetPoint(pPointList, nLen, fZoom, bErase);

		delete[] pPointList;
	}
	return nCount;
}

void SetTrackerAlign(HTRACKER hTracker, TYPE_ALIGNTRACKER eAlign, TRACKRECT rtPos)
{
	CRoiTracker* pTracker = dynamic_cast<CRoiTracker*> ((CRoiTracker*)hTracker);

	if (pTracker)
	{
		TYPE_ALIGN eType = TYPE_ALIGN_NONE;

		if(TYPE_ALIGNTRACKER_LEFT == eAlign)			eType = TYPE_ALIGN_LEFT;
		else if (TYPE_ALIGNTRACKER_CENTER == eAlign)	eType = TYPE_ALIGN_CENTER;
		else if (TYPE_ALIGNTRACKER_RIGHT == eAlign)		eType = TYPE_ALIGN_RIGHT;
		else if (TYPE_ALIGNTRACKER_TOP == eAlign)		eType = TYPE_ALIGN_TOP;
		else if (TYPE_ALIGNTRACKER_MIDDLE == eAlign)	eType = TYPE_ALIGN_MIDDLE;
		else if (TYPE_ALIGNTRACKER_BOTTOM == eAlign)	eType = TYPE_ALIGN_BOTTOM;

		INFO_RECT rect;
		rect.m_fleft = rtPos.m_fleft;
		rect.m_ftop = rtPos.m_ftop;
		rect.m_fright = rtPos.m_fright;
		rect.m_fbottom = rtPos.m_fbottom;

		pTracker->SetAlign(eType, rect);
	}
}

void SetOuterScroll(HTRACKER hTracker, BOOL bOuter)
{
	CRoiTracker* pTracker = dynamic_cast<CRoiTracker*> ((CRoiTracker*)hTracker);
	if (pTracker)
	{
		pTracker->SetOuterScroll(bOuter);
	}
}

void SetBaseSelection(HTRACKER hTracker, BOOL bBase)
{
	CRoiTracker* pTracker = dynamic_cast<CRoiTracker*> ((CRoiTracker*)hTracker);
	if (pTracker)
	{
		pTracker->SetBaseSelection(bBase);
	}
}

BOOL SetWidth(HTRACKER hTracker, DWORD dwWidth)
{
	BOOL bResult = FALSE;
	CRoiTracker* pTracker = dynamic_cast<CRoiTracker*> ((CRoiTracker*)hTracker);
	if (pTracker)
	{
		bResult = pTracker->SetWidth(dwWidth);
	}

	return bResult;
}

BOOL SetHeight(HTRACKER hTracker, DWORD dwHeight)
{
	BOOL bResult = FALSE;
	CRoiTracker* pTracker = dynamic_cast<CRoiTracker*> ((CRoiTracker*)hTracker);
	if (pTracker)
	{
		bResult = pTracker->SetHeight(dwHeight);
	}

	return bResult;
}

BOOL MoveRoi(HTRACKER hTracker, int cx, int cy)
{
	BOOL bResult = FALSE;
	CRoiTracker* pTracker = dynamic_cast<CRoiTracker*> ((CRoiTracker*)hTracker);
	if (pTracker)
	{
		bResult = pTracker->MovePoint(cx, cy);
	}

	return bResult;
}



TRACKRECT GetPositionRect(HTRACKER hTracker, LPTRACKPOINT pPointList, int nLen)
{
	TRACKRECT rect;
	memset(&rect, 0x00, sizeof(TRACKRECT));

	CRoiTracker* pTracker = dynamic_cast<CRoiTracker*> ((CRoiTracker*)hTracker);
	if (pTracker)
	{
		INFO_POINT* pstPointList = new INFO_POINT[nLen];
		for (int i = 0; i < nLen; i++)
		{
			pstPointList[i].m_fx = pPointList[i].m_fx;
			pstPointList[i].m_fy = pPointList[i].m_fy;
		}

		INFO_RECT rtInfo = pTracker->GetPositionRect(pstPointList, nLen);
		
		rect.m_fleft = rtInfo.m_fleft;
		rect.m_ftop = rtInfo.m_ftop;
		rect.m_fright = rtInfo.m_fright;
		rect.m_fbottom = rtInfo.m_fbottom;

		
		delete[] pstPointList;
		pstPointList = NULL;
	}
	return rect;
}

TYPE_HITTRACKER GetTrackerHitPosition(HTRACKER hTracker, TRACKPOINT point, float fZoom)
{
	TYPE_HITTRACKER eHit = TYPE_HITTRACKER_NONE;

	CRoiTracker* pTracker = dynamic_cast<CRoiTracker*> ((CRoiTracker*)hTracker);
	if (pTracker)
	{
		INFO_POINT stPoint;
		stPoint.m_fx = point.m_fx;
		stPoint.m_fy = point.m_fy;
		
		const TYPE_HITROI eType = pTracker->HitTest(stPoint, fZoom);

		// For Point
		if (TYPE_HITROI_TOPLEFT == eType)
		{
			eHit = TYPE_HITTRACKER_TOPLEFT;
		}
		else if (TYPE_HITROI_TOP == eType)
		{
			eHit = TYPE_HITTRACKER_TOP;
		}
		else if (TYPE_HITROI_TOPRIGHT == eType)
		{
			eHit = TYPE_HITTRACKER_TOPRIGHT;
		}
		else if (TYPE_HITROI_RIGHT == eType)
		{
			eHit = TYPE_HITTRACKER_RIGHT;
		}
		else if (TYPE_HITROI_BOTTOMRIGHT == eType)
		{
			eHit = TYPE_HITTRACKER_BOTTOMRIGHT;
		}
		else if (TYPE_HITROI_BOTTOM == eType)
		{
			eHit = TYPE_HITTRACKER_BOTTOM;
		}
		else if (TYPE_HITROI_BOTTOMLEFT == eType)
		{
			eHit = TYPE_HITTRACKER_BOTTOMLEFT;
		}
		else if (TYPE_HITROI_LEFT == eType)
		{
			eHit = TYPE_HITTRACKER_LEFT;
		}
		else if (TYPE_HITROI_CENTER == eType)
		{
			eHit = TYPE_HITTRACKER_BODY;
		}
		else if (TYPE_HITROI_BODY == eType)
		{
			eHit = TYPE_HITTRACKER_BODY;
		}

		// For Line (Rectangle
		else if (TYPE_HITROI_LINE_LEFT == eType || 
			TYPE_HITROI_LINE_RIGHT == eType || 
			TYPE_HITROI_LINE_TOP == eType || 
			TYPE_HITROI_LINE_BOTTOM == eType)
		{
			eHit = TYPE_HITTRACKER_BODY;
		}

		// For Ring
		else if (TYPE_HITROI_LINE_INNER == eType || 
			TYPE_HITROI_LINE_OUTER == eType || 
			TYPE_HITROI_LINE_TOPANGLE == eType || 
			TYPE_HITROI_LINE_BOTTOMANGLE == eType)
		{
			eHit = TYPE_HITTRACKER_BODY;
		}
		

	}
	return eHit;
}
