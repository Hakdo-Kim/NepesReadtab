#include "stdafx.h"
#include "LineRoiTracker.h"

#include "RoiTrackerDC.h"

#include <cmath>

CLineRoiTracker::CLineRoiTracker(CWnd* pWnd)
	: CRoiTracker(pWnd)
{
	m_bInit = FALSE;

	m_eHitRoi = TYPE_HITROI_NONE;
	m_eTransformRoi = TYPE_TRANSFORMROI_NONE;

	memset(m_PointSrc, 0x00, sizeof(INFO_POINT)*ROILINE_POINT_COUNT);
	memset(m_PointDest, 0x00, sizeof(INFO_POINT)*LINE_POINT_COUNT);
	memset(m_hCur, 0x00, sizeof(HCURSOR)*ROILINE_POINT_COUNT);

	m_rgbTrack = RGB(0, 0, 0);
	m_rgbRoiRect = RGB(0, 0, 0);
	m_rgbRoiLine = RGB(0, 0, 0);

	UINT CursorIDs[] =
	{
		AFX_IDC_TRACKNWSE,
		AFX_IDC_TRACKNS,
		AFX_IDC_TRACKNESW,
		AFX_IDC_TRACKWE,
		AFX_IDC_MOVE4WAY,
	};

	for (int i = 0; i < ROILINE_POINT_COUNT; i++)
	{
		m_hCur[i] = ::AfxGetApp()->LoadCursor(CursorIDs[i]);
	}

	m_pTrackLine = NULL;
}

CLineRoiTracker::~CLineRoiTracker()
{
	for (int i = 0; i < ROILINE_POINT_COUNT; i++)
	{
		if (m_hCur[i])
		{
			::DestroyCursor(m_hCur[i]);
		}
	}

	if (m_pTrackLine)
		delete[] m_pTrackLine;
	m_pTrackLine = NULL;
}

void CLineRoiTracker::Clear()
{
	m_bInit = FALSE;

	m_eHitRoi = TYPE_HITROI_NONE;
	m_eTransformRoi = TYPE_TRANSFORMROI_NONE;

	memset(m_PointSrc, 0x00, sizeof(INFO_POINT)*ROILINE_POINT_COUNT);
	memset(m_PointDest, 0x00, sizeof(INFO_POINT)*LINE_POINT_COUNT);

	if (m_pTrackLine)
		delete[] m_pTrackLine;
	m_pTrackLine = NULL;

	Invalidate();
}

//
BOOL CLineRoiTracker::IsInit()
{
	return m_bInit;
}

TYPE_HITROI CLineRoiTracker::HitTest(INFO_POINT point, float fZoom)
{
	TYPE_HITROI eHitRoi = TYPE_HITROI_NONE;
	if (FALSE == IsInit())
		return eHitRoi;

	int i = 0;
	for (i = 0; i < TYPE_HITROI_BODY; i++)
	{
		INFO_RECT rect = GetHitRect((TYPE_HITROI)i, fZoom);
		if (TRUE == CheckPointInRect(rect, point, fZoom))
			break;
	}

	eHitRoi = (TYPE_HITROI)i;

	if (TYPE_HITROI_BODY <= i)
		eHitRoi = TYPE_HITROI_NONE;

	if (TYPE_HITROI_NONE == eHitRoi)
		eHitRoi = HitTest(point, m_PointSrc[0], m_PointSrc[1], fZoom);

	return eHitRoi;
}

TYPE_HITROI CLineRoiTracker::HitTest(INFO_POINT point, INFO_POINT stStart, INFO_POINT stEnd, float fZoom)
{
	const double fPhi = GetAngle(stStart, stEnd, TRUE);

	// Transform
	m_Transform.Reset();
	m_Transform.Translate((REAL)-stStart.m_fx, (REAL)-stStart.m_fy);
	m_Transform.Rotate((REAL)(fPhi*-1), MatrixOrderAppend);

	PointF ptf = PointF((REAL)point.m_fx, (REAL)point.m_fy);
	PointF ptfStart = PointF((REAL)stStart.m_fx, (REAL)stStart.m_fy);
	PointF ptfEnd = PointF((REAL)stEnd.m_fx, (REAL)stEnd.m_fy);

	m_Transform.TransformPoints(&ptf, 1);
	m_Transform.TransformPoints(&ptfStart, 1);
	m_Transform.TransformPoints(&ptfEnd, 1);

	point = this->GetPointFromPointF(ptf);
	stStart = this->GetPointFromPointF(ptfStart);
	stEnd = this->GetPointFromPointF(ptfEnd);


	//
	INFO_RECT rect;
	memset(&rect, 0x00, sizeof(INFO_RECT));

	rect.m_fleft = stEnd.m_fx + VALUE_INFLATE;
	rect.m_fright = -VALUE_INFLATE;
	rect.m_ftop -= VALUE_INFLATE;
	rect.m_fbottom += VALUE_INFLATE;

	if (IsPointInRectangle(rect, point))
		return TYPE_HITROI_CENTER;

	return TYPE_HITROI_NONE;
}


INFO_RECT CLineRoiTracker::GetHitRect(TYPE_HITROI eHit, float fZoom)
{
	INFO_RECT rect;
	memset(&rect, 0x00, sizeof(INFO_RECT));

	if (NULL == m_pWnd)
		return rect;

	if (TYPE_HITROI_LEFT == eHit || TYPE_HITROI_RIGHT == eHit || TYPE_HITROI_CENTER == eHit)
	{
		const int x = GetHScrollPos();
		const int y = GetVScrollPos();

		INFO_POINT point = GetHitPoint(m_PointSrc, eHit);
		point.m_fx = (point.m_fx * fZoom - x);
		point.m_fy = (point.m_fy * fZoom - y);

		rect = GetPointRect(point);
	}

	return rect;	
}

INFO_POINT CLineRoiTracker::GetHitPoint(LPINFO_POINT pPoint, TYPE_HITROI eHit)
{
	//
	//		0		   2		  1
	//		*----------*----------*
	//
	//      0: Left
	//      1: Right
	//      2: Center
	//

	INFO_POINT pnt;
	pnt.m_fx = 0;
	pnt.m_fy = 0;

	if (TYPE_HITROI_LEFT == eHit)
		pnt = pPoint[0];
	else if (TYPE_HITROI_RIGHT == eHit)
		pnt = pPoint[1];
	else if (TYPE_HITROI_CENTER == eHit)
		pnt = pPoint[2];
	
	return pnt;
}

void CLineRoiTracker::Draw(CDC* pDC, float fZoom)
{
	if (NULL == pDC)
		return;

	int nOldRop = 0;

	nOldRop = pDC->SetROP2(R2_NOTXORPEN);
	DrawRoiLine(pDC, fZoom);
	pDC->SetROP2(nOldRop);
}

void CLineRoiTracker::DrawRoi(CDC* pDC, INFO_SIZE stSize, float fZoom, void* pReserved)
{
	if (NULL == pDC || FALSE == IsInit())
		return;

	BOOL bDrawForFile = FALSE;
	if (pReserved)
	{
		INFO_RESERVED* pstReserved = (INFO_RESERVED*)pReserved;
		bDrawForFile = pstReserved->m_bDrawForFile;
	}

	INFO_POINT PointZoom[ROILINE_POINT_COUNT];
	memset(PointZoom, 0x00, sizeof(INFO_POINT)*ROILINE_POINT_COUNT);
	ConvertPointPixelToDrawForRoi(m_PointSrc, PointZoom, ROILINE_POINT_COUNT, stSize, fZoom, bDrawForFile);

	INFO_RESERVED* pstReserved = (INFO_RESERVED*)pReserved;
	if (pstReserved && pstReserved->m_hOutLine)
	{
		pDC->SelectObject(pstReserved->m_hOutLine);
	}
	this->DrawLine(pDC, PointZoom[0], PointZoom[1]);
}

void CLineRoiTracker::DrawTracker(CDC* pDC, INFO_POINT pt1, INFO_POINT pt2, float fZoom, BOOL bDone)
{
	if (NULL == pDC || FALSE == IsInit())
		return;

	const int x = GetHScrollPos();
	const int y = GetVScrollPos();

	if (bDone && m_pTrackLine)
	{
		m_PointSrc[0] = GetSrcPointFromTracker(m_pTrackLine[0], fZoom);
		m_PointSrc[1] = GetSrcPointFromTracker(m_pTrackLine[1], fZoom);

		m_PointSrc[2].m_fx = m_PointSrc[0].m_fx + (m_PointSrc[1].m_fx - m_PointSrc[0].m_fx) / 2;
		m_PointSrc[2].m_fy = m_PointSrc[0].m_fy + (m_PointSrc[1].m_fy - m_PointSrc[0].m_fy) / 2;

		delete[] m_pTrackLine;
		m_pTrackLine = NULL;

		return;
	}

	CRoiTrackerDC* pRDC = new CRoiTrackerDC(pDC, NOTSRCINVERT);
	pRDC->SetROP2(R2_NOTXORPEN);

	INFO_POINT pPt[LINE_POINT_COUNT];
	pPt[0] = GetTrackerPointFromSrc(m_PointSrc[0], fZoom);
	pPt[1] = GetTrackerPointFromSrc(m_PointSrc[1], fZoom);

	if (NULL == m_pTrackLine)
	{
		m_pTrackLine = new INFO_POINT[LINE_POINT_COUNT];
		m_pTrackLine[0] = pPt[0];
		m_pTrackLine[1] = pPt[1];
	}
	else
	{
		DrawTrackLine(pRDC, m_pTrackLine, LINE_POINT_COUNT);
	}

	pPt[0] = GetTrackerPointFromSrc(m_PointSrc[0], pt1, pt2, fZoom);
	pPt[1] = GetTrackerPointFromSrc(m_PointSrc[1], pt1, pt2, fZoom);

	DrawTrackLine(pRDC, pPt, LINE_POINT_COUNT);
	if (m_pTrackLine)
	{
		m_pTrackLine[0] = pPt[0];
		m_pTrackLine[1] = pPt[1];
	}

	delete pRDC;
}


void CLineRoiTracker::DrawTrackLine(CDC* pDC, LPINFO_POINT pPtList, int nPtLen)
{
	if (NULL == pDC || NULL == pPtList || LINE_POINT_COUNT > nPtLen)
		return;

	CPen* pTrackPen = NULL;

	LOGBRUSH stLb;
	memset(&stLb, 0x00, sizeof(LOGBRUSH));
	stLb.lbColor = m_rgbTrack;
	stLb.lbHatch = 0;
	stLb.lbStyle = BS_SOLID;

	pTrackPen = new CPen(PS_COSMETIC | PS_ALTERNATE, 1, &stLb);
	CGdiObject * pOldPen = pDC->SelectObject(pTrackPen);

	this->DrawLine(pDC, pPtList[0], pPtList[1]);

	pDC->SelectObject(pOldPen);
	delete pTrackPen;


}



BOOL CLineRoiTracker::SetCursor(CDC* pDC, float fZoom)
{
	if (NULL == pDC || FALSE == this->IsInit())
		return FALSE;

	CPoint point;
	::GetCursorPos(&point);
	this->m_pWnd->ScreenToClient(&point);

	INFO_POINT pt;
	pt.m_fx = point.x;
	pt.m_fy = point.y;

	TYPE_HITROI eHitRoi = HitTest(pt, fZoom);
	if (TYPE_HITROI_NONE == eHitRoi)
		return FALSE;

	BOOL bResult = SetCursor(eHitRoi);
	return bResult;
}

//
TYPE_RESULTROI CLineRoiTracker::OnBeginTrack(UINT nFlags, INFO_POINT point, float fZoom)
{
	m_eHitRoi = HitTest(point, fZoom);

	if (TYPE_HITROI_NONE == m_eHitRoi)
	{
		m_eTransformRoi = TYPE_TRANSFORMROI_CREATE;

		for (int i = 0; i < LINE_POINT_COUNT; i++)
		{
			m_PointDest[i] = point;
		}
	}
	else if (TYPE_HITROI_CENTER == m_eHitRoi)
	{
		m_eTransformRoi = TYPE_TRANSFORMROI_MOVE;
	}
	else
	{
		m_eTransformRoi = TYPE_TRANSFORMROI_SCALE;
	}

	if (TYPE_TRANSFORMROI_CREATE != m_eTransformRoi)
	{
		INFO_POINT PointZoom[ROILINE_POINT_COUNT];
		memset(PointZoom, 0x00, sizeof(POINT)*ROILINE_POINT_COUNT);
		ConvertPointPixelToDraw(m_PointSrc, PointZoom, ROILINE_POINT_COUNT, fZoom);

		m_PointDest[0] = PointZoom[0];
		m_PointDest[1] = PointZoom[1];
	}

	return TYPE_RESULTROI_CONTINUE;
}

TYPE_RESULTROI CLineRoiTracker::OnEndTrack(TYPE_RESULTROI eResult, float fZoom, BOOL bErase)
{
	if (TYPE_RESULTROI_SUCCEEDED == eResult)
	{
		SetInitState(TRUE);

		INFO_POINT PointZoom[ROILINE_POINT_COUNT];
		memset(PointZoom, 0x00, sizeof(INFO_POINT)*ROILINE_POINT_COUNT);
		ConvertPointDrawToPixel(m_PointDest, PointZoom, ROILINE_POINT_COUNT, fZoom);


		const double w = PointZoom[1].m_fx - PointZoom[0].m_fx;
		const double h = PointZoom[1].m_fy - PointZoom[0].m_fy;

		// 0: Left
		// 1: Right
		// 2: Centor
		m_PointSrc[0] = PointZoom[0];
		m_PointSrc[1] = PointZoom[1];

		m_PointSrc[2] = PointZoom[0];
		m_PointSrc[2].m_fx += w / 2;
		m_PointSrc[2].m_fy += h / 2;
	}

	if (bErase)
		Invalidate();

	m_eTransformRoi = TYPE_TRANSFORMROI_NONE;

	return eResult;
}

TYPE_RESULTROI CLineRoiTracker::OnMouseMessage(UINT msg, UINT nFlags, INFO_POINT point, float fZoom)
{
	// 0: Left
	// 1: Right
	// 2: Center
	const BOOL bShift = (::GetKeyState(VK_LSHIFT) & FLAG_LBUTTONDOWN || ::GetKeyState(VK_RSHIFT) & FLAG_LBUTTONDOWN);

	if (TYPE_TRANSFORMROI_CREATE == m_eTransformRoi)
	{
		m_PointDest[1] = point;
		if (bShift)
		{
			SetPoint(point, m_PointDest[0], m_PointDest[1]);
		}
	}
	else if (TYPE_TRANSFORMROI_SCALE == m_eTransformRoi)
	{
		if (TYPE_HITROI_LEFT == m_eHitRoi)
		{
			m_PointDest[0].m_fx = point.m_fx;
			m_PointDest[0].m_fy = point.m_fy;
			if (bShift)
			{
				SetPoint(point, m_PointDest[1], m_PointDest[0]);
			}
		}
		else if (TYPE_HITROI_RIGHT == m_eHitRoi)
		{
			m_PointDest[1].m_fx = point.m_fx;
			m_PointDest[1].m_fy = point.m_fy;
			if (bShift)
			{
				SetPoint(point, m_PointDest[0], m_PointDest[1]);
			}

		}
	}
	else if (TYPE_TRANSFORMROI_MOVE == m_eTransformRoi)
	{
		const double w = m_stPoint.m_fx - m_stPreviousPoint.m_fx;
		const double h = m_stPoint.m_fy - m_stPreviousPoint.m_fy;

		for (int i = 0; i < 2; i++)
		{
			m_PointDest[i].m_fx += w;
			m_PointDest[i].m_fy += h;
		}
	}

	return CRoiTracker::OnMouseMessage(msg, nFlags, point, fZoom);
}

TYPE_RESULTROI CLineRoiTracker::OnMessage(MSG& msg)
{
	return TYPE_RESULTROI_FAILED;
}

void CLineRoiTracker::OnUpdate(CDC* pDC, UINT nMode, float fZoom)
{
	if (NULL == pDC)
		return;

	// Draw Tracking Rectangle.
	if (TYPE_TRANSFORMROI_NONE != m_eTransformRoi)
	{
		CPen* pTrackPen = NULL;

		LOGBRUSH stLb;
		memset(&stLb, 0x00, sizeof(LOGBRUSH));
		stLb.lbColor = m_rgbTrack;
		stLb.lbHatch = 0;
		stLb.lbStyle = BS_SOLID;

		pTrackPen = new CPen(PS_COSMETIC | PS_ALTERNATE, 1, &stLb);
		CGdiObject * pOldPen = pDC->SelectObject(pTrackPen);
		this->DrawLine(pDC, m_PointDest[0], m_PointDest[1]);
		pDC->SelectObject(pOldPen);
		delete pTrackPen;
	}
}

//
void CLineRoiTracker::SetInitState(BOOL bInit)
{
	m_bInit = bInit;
}

void CLineRoiTracker::DrawRoiLine(CDC* pDC, float fZoom)
{
	// 0 Left
	// 1 Right
	// 2 Center

	if (pDC && IsInit())
	{
		CGdiObject * pOldPen = NULL;

		INFO_POINT PointZoom[ROILINE_POINT_COUNT];
		memset(PointZoom, 0x00, sizeof(INFO_POINT)*ROILINE_POINT_COUNT);
		ConvertPointPixelToDraw(m_PointSrc, PointZoom, ROILINE_POINT_COUNT, fZoom);


		/// Draw Line
		{
			CPen* pLinePen = new CPen(PS_SOLID, 1, m_rgbRoiLine);
			pOldPen = pDC->SelectObject(pLinePen);

			this->DrawLine(pDC, PointZoom[0], PointZoom[1]);

			pDC->SelectObject(pOldPen);

			delete pLinePen;
		}
		//*/

		/// Draw Edge Rectangle;
		{
			CPen* pRectPen = new CPen(PS_SOLID, 1, m_rgbRoiRect);
			CGdiObject * pOldBrush = NULL;
			if (IsBaseSelection())
				pOldBrush = pDC->SelectStockObject(BLACK_BRUSH);
			else
				pOldBrush = pDC->SelectStockObject(NULL_BRUSH);

			pOldPen = pDC->SelectObject(pRectPen);

			INFO_RECT rect;
			memset(&rect, 0x00, sizeof(INFO_RECT));

			RECT rtDraw;
			
			rect = GetHitRect(TYPE_HITROI_RIGHT, fZoom);
			rtDraw = GetRectangle(rect);
			pDC->Rectangle(&rtDraw);

			rect = GetHitRect(TYPE_HITROI_LEFT, fZoom);
			rtDraw = GetRectangle(rect);
			pDC->Rectangle(&rtDraw);

			rect = GetHitRect(TYPE_HITROI_CENTER, fZoom);
			rtDraw = GetRectangle(rect);
			pDC->Rectangle(&rtDraw);


			pDC->SelectObject(pOldPen);
			pDC->SelectObject(pOldBrush);

			delete pRectPen;
		}
		//*/
	}
}

void CLineRoiTracker::SetPoint(const INFO_POINT point, INFO_POINT& pt1, INFO_POINT& pt2)
{
	const double w = std::abs(pt2.m_fx - pt1.m_fx);
	const double h = std::abs(pt2.m_fy - pt1.m_fy);
	if (w > h)
	{
		pt2.m_fy = pt1.m_fy;
		pt2.m_fx = point.m_fx;
	}
	else if (w < h)
	{
		pt2.m_fx = pt1.m_fx;
		pt2.m_fy = point.m_fy;
	}
}

BOOL CLineRoiTracker::SetCursor(TYPE_HITROI eHit)
{
	BOOL bResult = FALSE;

	int nIdx = -1;

	/*//
	UINT CursorIDs[] =
	{
	AFX_IDC_TRACKNWSE,
	AFX_IDC_TRACKNS,
	AFX_IDC_TRACKNESW,
	AFX_IDC_TRACKWE,
	AFX_IDC_MOVE4WAY,
	};
	//*/

	if (TYPE_HITROI_RIGHT == eHit || TYPE_HITROI_LEFT == eHit)
	{
		int nDegree = (int)(GetAngle(m_PointSrc[1], m_PointSrc[0], TRUE) + 360);
		nDegree %= 360;

		if ((45 - 23) < nDegree && (45 + 23) > nDegree || (225 - 23) < nDegree && (225 + 23) > nDegree)
			nIdx = 0;
		else if ((90 - 23) < nDegree && (90 + 23) > nDegree || (270 - 23) < nDegree && (270 + 23) > nDegree)
			nIdx = 1;
		else if ((135 - 23) < nDegree && (135 + 23) > nDegree || (315 - 23) < nDegree && (315 + 23) > nDegree)
			nIdx = 2;
		else
			nIdx = 3;

	}
	else if (TYPE_HITROI_CENTER == eHit)
	{
		nIdx = 4;
	}
	else
	{
		return FALSE;
	}

	if (m_hCur[nIdx])
	{
		::SetCursor(m_hCur[nIdx]);
		bResult = TRUE;
	}

	return bResult;
}

int CLineRoiTracker::GetPoint(LPINFO_POINT pPoint, int nLen)
{
	if (FALSE == IsInit())
	{
		return -1;
	}
	else
	{
		if (NULL == pPoint || LINE_POINT_COUNT > nLen)
			return LINE_POINT_COUNT;
	}

	int idx = 0;

	pPoint[idx] = m_PointSrc[idx];		idx++;
	pPoint[idx] = m_PointSrc[idx];		idx++;

	return LINE_POINT_COUNT;
}

int CLineRoiTracker::SetPoint(const LPINFO_POINT pPoint, const int nLen, float fZoom, BOOL bErase)
{
	if (NULL == pPoint || LINE_POINT_COUNT > nLen)
		return LINE_POINT_COUNT;

	INFO_POINT PointZoom[LINE_POINT_COUNT];
	ConvertPointPixelToDraw(pPoint, PointZoom, LINE_POINT_COUNT, fZoom);
	
	int idx = 0;
	m_PointDest[idx] = PointZoom[idx];	idx++;
	m_PointDest[idx] = PointZoom[idx];	idx++;
	
	OnEndTrack(TYPE_RESULTROI_SUCCEEDED, fZoom, bErase);

	return LINE_POINT_COUNT;
}


BOOL CLineRoiTracker::SetWidth(DWORD dwWidth)
{
	const int nLen = GetPoint(NULL, 0);
	if (1 > nLen)
		return FALSE;
	LPINFO_POINT pPointList = new INFO_POINT[nLen];
	if (NULL == pPointList)
		return FALSE;
	GetPoint(pPointList, nLen);

	const INFO_RECT rect = this->GetPositionRect(pPointList, nLen);
	const DWORD dwCurWidth = (DWORD)(rect.m_fright - rect.m_fleft);
	if (0 < dwCurWidth && dwCurWidth != dwWidth)
	{
		if(pPointList[0].m_fx < pPointList[1].m_fx)
			pPointList[1].m_fx = pPointList[0].m_fx + dwWidth;
		else
			pPointList[0].m_fx = pPointList[1].m_fx + dwWidth;
		SetPoint(pPointList, nLen, 1.0f);
	}

	delete[] pPointList;
	return TRUE;
}

BOOL CLineRoiTracker::SetHeight(DWORD dwHeight)
{
	const int nLen = GetPoint(NULL, 0);
	if (1 > nLen)
		return FALSE;
	LPINFO_POINT pPointList = new INFO_POINT[nLen];
	if (NULL == pPointList)
		return FALSE;
	GetPoint(pPointList, nLen);

	const INFO_RECT rect = this->GetPositionRect(pPointList, nLen);
	const DWORD dwCurHeight = (DWORD)(rect.m_fbottom - rect.m_ftop);
	if (0 < dwCurHeight && dwCurHeight != dwHeight)
	{
		if(pPointList[0].m_fy < pPointList[1].m_fy)
			pPointList[1].m_fy = pPointList[0].m_fy + dwHeight;
		else
			pPointList[0].m_fy = pPointList[1].m_fy + dwHeight;
		SetPoint(pPointList, nLen, 1.0f);
	}

	delete[] pPointList;
	return TRUE;
}

BOOL CLineRoiTracker::MovePoint(int cx, int cy)
{
	if (FALSE == IsInit())
		return FALSE;

	for (int i = 0; i < ROILINE_POINT_COUNT; i++)
	{
		m_PointSrc[i].m_fx += cx;
		m_PointSrc[i].m_fy += cy;
	}
	return TRUE;
}