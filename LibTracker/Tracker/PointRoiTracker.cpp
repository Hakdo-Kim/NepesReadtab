#include "stdafx.h"
#include "PointRoiTracker.h"

#include "RoiTrackerDC.h"

CPointRoiTracker::CPointRoiTracker(CWnd* pWnd)
	: CRoiTracker(pWnd)
{
	m_bInit = FALSE;

	m_rgbTrack = RGB(0, 0, 0);
	m_rgbRoiPoint = RGB(0, 0, 0);

	m_pTrackPoint = NULL;
}

CPointRoiTracker::~CPointRoiTracker()
{
	if (m_pTrackPoint)
		delete m_pTrackPoint;
	m_pTrackPoint = NULL;
}

BOOL CPointRoiTracker::IsInit()
{
	return m_bInit;
}

void CPointRoiTracker::Clear()
{
	SetInitState(FALSE);

	if (m_pTrackPoint)
		delete m_pTrackPoint;
	m_pTrackPoint = NULL;

	Invalidate();
}

TYPE_HITROI CPointRoiTracker::HitTest(INFO_POINT point, float fZoom)
{
	TYPE_HITROI eHitRoi = TYPE_HITROI_NONE;
	if (FALSE == IsInit())
		return eHitRoi;

	INFO_RECT rect;
	memset(&rect, 0x00, sizeof(INFO_RECT));

	const int x = GetHScrollPos();
	const int y = GetVScrollPos();

	INFO_POINT ptPos;
	ptPos.m_fx = (m_stPoint.m_fx * fZoom - x);
	ptPos.m_fy = (m_stPoint.m_fy * fZoom - y);

	rect.m_fleft = ptPos.m_fx - VALUE_INFLATE;
	rect.m_fright = ptPos.m_fx + VALUE_INFLATE;
	rect.m_ftop = ptPos.m_fy - VALUE_INFLATE;
	rect.m_fbottom = ptPos.m_fy + VALUE_INFLATE;

	if (IsPointInRectangle(rect, point))
	{
		return TYPE_HITROI_CENTER;
	}

	return TYPE_HITROI_NONE;
}

void CPointRoiTracker::Draw(CDC* pDC, float fZoom)
{
	if (NULL == pDC)
		return;

	int nOldRop = pDC->SetROP2(R2_NOTXORPEN);

	DrawRoiPoint(pDC, fZoom);

	pDC->SetROP2(nOldRop);
}

void CPointRoiTracker::DrawRoi(CDC* pDC, INFO_SIZE stSize, float fZoom, void* pReserved)
{
	if (NULL == pDC || FALSE == IsInit())
		return;

	BOOL bDrawForFile = FALSE;
	if (pReserved)
	{
		INFO_RESERVED* pstReserved = (INFO_RESERVED*)pReserved;
		bDrawForFile = pstReserved->m_bDrawForFile;
	}

	INFO_POINT PointZoom;
	ConvertPointPixelToDrawForRoi(&m_stPoint, &PointZoom, 1, stSize, fZoom, bDrawForFile);

	pDC->MoveTo((int)(PointZoom.m_fx), (int)(PointZoom.m_fy - VALUE_INFLATE_POINT + 1));
	pDC->LineTo((int)(PointZoom.m_fx), (int)(PointZoom.m_fy + VALUE_INFLATE_POINT));

	pDC->MoveTo((int)(PointZoom.m_fx - VALUE_INFLATE_POINT + 1), (int)(PointZoom.m_fy));
	pDC->LineTo((int)(PointZoom.m_fx + VALUE_INFLATE_POINT), (int)(PointZoom.m_fy));

}

void CPointRoiTracker::DrawTracker(CDC* pDC, INFO_POINT pt1, INFO_POINT pt2, float fZoom, BOOL bDone)
{
	if (NULL == pDC || FALSE == IsInit())
		return;

	const int x = GetHScrollPos();
	const int y = GetVScrollPos();

	if (bDone && m_pTrackPoint)
	{
		m_stPoint = GetSrcPointFromTracker(*m_pTrackPoint, fZoom);

		delete m_pTrackPoint;
		m_pTrackPoint = NULL;
		
		return;
	}

	CRoiTrackerDC* pRDC = new CRoiTrackerDC(pDC, NOTSRCINVERT);
	pRDC->SetROP2(R2_NOTXORPEN);

	INFO_POINT point;
	point.m_fx = (m_stPoint.m_fx * fZoom - x);
	point.m_fy = (m_stPoint.m_fy * fZoom - y);

	if (NULL == m_pTrackPoint)
	{
		m_pTrackPoint = new INFO_POINT;
		*m_pTrackPoint = point;
	}
	else
	{
		DrawTrackPoint(pRDC, *m_pTrackPoint);
	}

	if (pDC)
	{
		POINT ptDraw;
		ptDraw.x = (long)point.m_fx;
		ptDraw.y = (long)point.m_fy;

		pDC->DPtoLP(&ptDraw);
	}

	point.m_fx = ((m_stPoint.m_fx + pt2.m_fx - pt1.m_fx) * fZoom - x);
	point.m_fy = ((m_stPoint.m_fy + pt2.m_fy - pt1.m_fy) * fZoom - y);

	DrawTrackPoint(pRDC, point);
	if (m_pTrackPoint)
	{
		*m_pTrackPoint = point;
	}
	
	delete pRDC;

}

void CPointRoiTracker::DrawTrackPoint(CDC* pDC, INFO_POINT point)
{
	if (NULL == pDC)
		return;

	LOGBRUSH stLb;
	memset(&stLb, 0x00, sizeof(LOGBRUSH));
	stLb.lbColor = m_rgbTrack;
	stLb.lbHatch = 0;
	stLb.lbStyle = BS_SOLID;

	CPen* pTrackPen = new CPen(PS_COSMETIC | PS_ALTERNATE, 1, &stLb);
	CGdiObject * pOldPen = pDC->SelectObject(pTrackPen);

	POINT ptDraw;
	ptDraw.x = (int)point.m_fx;
	ptDraw.y = (int)point.m_fy;

	CRect rect;
	rect.SetRectEmpty();
	rect.OffsetRect(ptDraw);
	rect.InflateRect(VALUE_INFLATE, VALUE_INFLATE);

	pDC->MoveTo(rect.left, rect.top - 1);
	pDC->LineTo(rect.right, rect.bottom);

	pDC->MoveTo(rect.right, rect.top - 1);
	pDC->LineTo(rect.left, rect.bottom);

	pDC->SelectObject(pOldPen);


	delete pTrackPen;	
}


void CPointRoiTracker::SetInitState(BOOL bInit)
{
	m_bInit = bInit;
}

TYPE_RESULTROI CPointRoiTracker::OnBeginTrack(UINT nFlags, INFO_POINT point, float fZoom)
{
	ConvertPointPixelToDraw(&m_stPoint, &m_stPoint, 1, fZoom);

	return TYPE_RESULTROI_CONTINUE;
}

TYPE_RESULTROI CPointRoiTracker::OnEndTrack(TYPE_RESULTROI eResult, float fZoom, BOOL bErase)
{
	SetInitState(TRUE);

	ConvertPointDrawToPixel(&m_stPoint, &m_stPoint, 1, fZoom);

	if (bErase)
		Invalidate();
	return TYPE_RESULTROI_SUCCEEDED;
}

TYPE_RESULTROI CPointRoiTracker::OnMouseMessage(UINT msg, UINT nFlags, INFO_POINT point, float fZoom)
{
	return CRoiTracker::OnMouseMessage(msg, nFlags, point, fZoom);
}

TYPE_RESULTROI CPointRoiTracker::OnMessage(MSG& msg)
{
	TYPE_RESULTROI eResult = TYPE_RESULTROI_FAILED;
	return eResult;
}

void CPointRoiTracker::OnUpdate(CDC* pDC, UINT nMode, float fZoom)
{
	if (NULL == pDC)
		return;

	CPen* pTrackPen = NULL;

	LOGBRUSH stLb;
	memset(&stLb, 0x00, sizeof(LOGBRUSH));
	stLb.lbColor = m_rgbTrack;
	stLb.lbHatch = 0;
	stLb.lbStyle = BS_SOLID;

	pTrackPen = new CPen(PS_COSMETIC | PS_ALTERNATE, 1, &stLb);
	CGdiObject * pOldPen = pDC->SelectObject(pTrackPen);


	INFO_RECT rect = GetInflateRect(m_stPoint, VALUE_INFLATE, VALUE_INFLATE);
	
	pDC->MoveTo((int)(rect.m_fleft), (int)(rect.m_ftop - 1));
	pDC->LineTo((int)(rect.m_fright), (int)(rect.m_fbottom));

	pDC->MoveTo((int)(rect.m_fright), (int)(rect.m_ftop - 1));
	pDC->LineTo((int)(rect.m_fleft), (int)(rect.m_fbottom));

	pDC->SelectObject(pOldPen);

	delete pTrackPen;

}

void CPointRoiTracker::DrawRoiPoint(CDC* pDC, float fZoom)
{
	if (NULL == pDC || FALSE==IsInit())
		return;

	INFO_POINT PointZoom;
	ConvertPointPixelToDraw(&m_stPoint, &PointZoom, 1, fZoom);

	/// Draw Line
	{
		CPen* pLinePen = new CPen(PS_SOLID, 1, m_rgbRoiPoint);
		CGdiObject * pOldPen = pDC->SelectObject(pLinePen);

		pDC->MoveTo((int)(PointZoom.m_fx), (int)(PointZoom.m_fy - VALUE_INFLATE_POINT + 1));
		pDC->LineTo((int)(PointZoom.m_fx), (int)(PointZoom.m_fy + VALUE_INFLATE_POINT));

		pDC->MoveTo((int)(PointZoom.m_fx - VALUE_INFLATE_POINT + 1), (int)(PointZoom.m_fy));
		pDC->LineTo((int)(PointZoom.m_fx + VALUE_INFLATE_POINT), (int)(PointZoom.m_fy));

		pDC->SelectObject(pOldPen);

		delete pLinePen;
	}
	//*/
}

int CPointRoiTracker::GetPoint(LPINFO_POINT pPoint, int nLen)
{
	if (FALSE == IsInit())
	{
		return -1;
	}
	else
	{
		if (NULL == pPoint || 1 > nLen)
			return 1;
	}

	pPoint[0] = m_stPoint;

	return 1;
}

int CPointRoiTracker::SetPoint(const LPINFO_POINT pPoint, const int nLen, float fZoom, BOOL bErase)
{
	if (NULL == pPoint || 1 > nLen)
		return 1;

	INFO_POINT PointZoom;
	ConvertPointPixelToDraw(pPoint, &PointZoom, 1, fZoom);

	m_stPoint = PointZoom;

	OnEndTrack(TYPE_RESULTROI_SUCCEEDED, fZoom, bErase);

	return 1;
}

void CPointRoiTracker::SetAlign(TYPE_ALIGN eAlign, INFO_RECT rtPos)
{
	const double w = rtPos.m_fright - rtPos.m_fleft;
	const double h = rtPos.m_fbottom - rtPos.m_ftop;

	if (TYPE_ALIGN_LEFT == eAlign)
		m_stPoint.m_fx = rtPos.m_fleft;
	else if (TYPE_ALIGN_RIGHT == eAlign)
		m_stPoint.m_fx = rtPos.m_fright;
	else if (TYPE_ALIGN_CENTER == eAlign)
		m_stPoint.m_fx = rtPos.m_fleft + w / 2;

	else if (TYPE_ALIGN_TOP == eAlign)
		m_stPoint.m_fy = rtPos.m_ftop;
	else if (TYPE_ALIGN_BOTTOM == eAlign)
		m_stPoint.m_fy = rtPos.m_fbottom;
	else if (TYPE_ALIGN_MIDDLE == eAlign)
		m_stPoint.m_fy = rtPos.m_ftop + h / 2;

}

BOOL CPointRoiTracker::MovePoint(int cx, int cy)
{
	if (FALSE == IsInit())
		return FALSE;

	m_stPoint.m_fx += cx;
	m_stPoint.m_fy += cy;

	return TRUE;
}