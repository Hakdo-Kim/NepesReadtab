#include "stdafx.h"
#include "PolygonRoiTracker.h"

#include "RoiTrackerDC.h"

CPolygonRoiTracker::CPolygonRoiTracker(CWnd* pWnd)
	: CRoiTracker(pWnd)
{
	m_bInit = FALSE;

	m_eHitRoi = TYPE_HITROI_NONE;
	m_eTransformRoi = TYPE_TRANSFORMROI_NONE;

	m_PointSrc.clear();
	m_PointDest.clear();
	m_nIdxDest = -1;

	memset(m_hCur, 0x00, sizeof(HCURSOR)*POLYGON_CURSOR_COUNT);

	m_rgbTrack = RGB(0, 0, 0);
	m_rgbRoiRect = RGB(0, 0, 0);
	m_rgbRoiPolygon = RGB(0, 0, 0);

	UINT CursorIDs[] =
	{
		AFX_IDC_TRACKNWSE,
		AFX_IDC_TRACKNS,
		AFX_IDC_TRACKNESW,
		AFX_IDC_TRACKWE,
		AFX_IDC_MOVE4WAY,
	};

	for (int i = 0; i < POLYGON_CURSOR_COUNT; i++)
	{
		m_hCur[i] = ::AfxGetApp()->LoadCursor(CursorIDs[i]);
	}

	m_pTrackPolygon = NULL;
	m_nPolygonLen = 0;
}

CPolygonRoiTracker::~CPolygonRoiTracker()
{
	for (int i = 0; i < POLYGON_CURSOR_COUNT; i++)
	{
		if (m_hCur[i])
		{
			::DestroyCursor(m_hCur[i]);
		}
	}


	if (m_pTrackPolygon)
		delete[] m_pTrackPolygon;
	m_pTrackPolygon = NULL;
	m_nPolygonLen = 0;
}

void CPolygonRoiTracker::Clear()
{
	m_bInit = FALSE;

	m_eHitRoi = TYPE_HITROI_NONE;
	m_eTransformRoi = TYPE_TRANSFORMROI_NONE;

	m_PointSrc.clear();
	m_PointDest.clear();
	

	if (m_pTrackPolygon)
		delete[] m_pTrackPolygon;
	m_pTrackPolygon = NULL;
	m_nPolygonLen = 0;

	Invalidate();
}

//
BOOL CPolygonRoiTracker::IsInit()
{
	return m_bInit;
}

TYPE_HITROI CPolygonRoiTracker::HitTest(INFO_POINT point, float fZoom)
{
	TYPE_HITROI eType = HitTest(point, NULL, 0, fZoom);
	return eType;
}

TYPE_HITROI CPolygonRoiTracker::HitTest(INFO_POINT point, int* pIdxList, int nLen, float fZoom)
{
	if (FALSE == IsInit())
		return TYPE_HITROI_NONE;

	const int nCount = m_PointSrc.size();
	INFO_RECT rect;
	// Selected point...
	for (int i = 0; i < nCount; i++)
	{
		rect = GetHitRect(i, fZoom);
		if (TRUE == CheckPointInRect(rect, point, fZoom))
		{
			if (pIdxList && 0 < nLen)
			{
				pIdxList[0] = i;
			}
			return TYPE_HITROI_BODY;
		}
	}

	// Center...
	TYPE_HITROI eHit = TYPE_HITROI_NONE;

	const int x = GetHScrollPos();
	const int y = GetVScrollPos();

	point.m_fx = ((point.m_fx + x) / fZoom);
	point.m_fy = ((point.m_fy + y) / fZoom);

	INFO_POINT stStart;
	INFO_POINT stEnd;
	for (int i = 1; i < nCount; i++)
	{
		stStart = m_PointSrc[i - 1];
		stEnd = m_PointSrc[i];

		const double x1 = min(stStart.m_fx, stEnd.m_fx);
		const double x2 = max(stStart.m_fx, stEnd.m_fx);
		
		if ( x1 > point.m_fx || x2 < point.m_fx)
		{
			continue;
		}

		eHit = HitTest(point, stStart, stEnd, fZoom);
		if (TYPE_HITROI_NONE != eHit)
			return eHit;
	}

	eHit = HitTest(point, m_PointSrc[nCount - 1], m_PointSrc[0], fZoom);
	return eHit;
}

TYPE_HITROI CPolygonRoiTracker::HitTest(INFO_POINT point, INFO_POINT stStart, INFO_POINT stEnd, float fZoom)
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

void CPolygonRoiTracker::Draw(CDC* pDC, float fZoom)
{
	if (NULL == pDC)
		return;

	int nOldRop = pDC->SetROP2(R2_NOTXORPEN);

	DrawRoiPolygon(pDC, fZoom);

	pDC->SetROP2(nOldRop);
}

void CPolygonRoiTracker::DrawRoi(CDC* pDC, INFO_SIZE stSize, float fZoom, void* pReserved)
{
	if (NULL == pDC || FALSE == IsInit())
		return;

	BOOL bDrawForFile = FALSE;
	if (pReserved)
	{
		INFO_RESERVED* pstReserved = (INFO_RESERVED*)pReserved;
		bDrawForFile = pstReserved->m_bDrawForFile;
	}

	const int nCount = m_PointSrc.size();

	INFO_POINT* pPointSrc = new INFO_POINT[nCount];
	INFO_POINT* pPointZoom = new INFO_POINT[nCount];
	for (int i = 0; i < nCount; i++)
		pPointSrc[i] = m_PointSrc[i];

	ConvertPointPixelToDrawForRoi(pPointSrc, pPointZoom, nCount, stSize, fZoom, bDrawForFile);

	for (int i = 1; i < nCount; i++)
	{
		this->DrawLine(pDC, pPointZoom[i - 1], pPointZoom[i]);
	}

	if (POLYGON_POINT_MINCOUNT < nCount)
	{
		this->DrawLine(pDC, pPointZoom[0], pPointZoom[nCount - 1]);
	}

	delete[] pPointSrc;
	delete[] pPointZoom;
}

void CPolygonRoiTracker::DrawTracker(CDC* pDC, INFO_POINT pt1, INFO_POINT pt2, float fZoom, BOOL bDone)
{
	if (NULL == pDC || FALSE == IsInit())
		return;

	const int x = GetHScrollPos();
	const int y = GetVScrollPos();

	if (bDone && m_pTrackPolygon)
	{
		const int nSize = m_PointSrc.size();
		for (int i = 0; i < nSize; i++)
		{
			m_PointSrc[i] = GetSrcPointFromTracker(m_pTrackPolygon[i], fZoom);
		}

		delete[] m_pTrackPolygon;
		m_pTrackPolygon = NULL;

		return;
	}

	CRoiTrackerDC* pRDC = new CRoiTrackerDC(pDC, NOTSRCINVERT);
	pRDC->SetROP2(R2_NOTXORPEN);

	m_nPolygonLen = m_PointSrc.size();
	LPINFO_POINT pPt = new INFO_POINT[m_nPolygonLen];

	for (int i = 0; i < m_nPolygonLen; i++)
		pPt[i] = GetTrackerPointFromSrc(m_PointSrc[i], fZoom);

	if (NULL == m_pTrackPolygon)
	{
		m_pTrackPolygon = new INFO_POINT[m_nPolygonLen];
		for (int i = 0; i < m_nPolygonLen; i++)
		{
			m_pTrackPolygon[i] = pPt[i];
		}
	}
	else
	{
		DrawTrackPolygon(pRDC, m_pTrackPolygon, m_nPolygonLen);
	}

	
	for (int i = 0; i < m_nPolygonLen; i++)
		pPt[i] = GetTrackerPointFromSrc(m_PointSrc[i], pt1, pt2, fZoom);
	
	DrawTrackPolygon(pRDC, pPt, m_nPolygonLen);
	if (m_pTrackPolygon)
	{
		for (int i = 0; i < m_nPolygonLen; i++)
		{
			m_pTrackPolygon[i] = pPt[i];
		}
	}

	delete[] pPt;
	delete pRDC;
}

void CPolygonRoiTracker::DrawTrackPolygon(CDC* pDC, LPINFO_POINT pPtList, int nPtLen)
{
	if (NULL == pDC || NULL == pPtList)
		return;

	LOGBRUSH stLb;
	memset(&stLb, 0x00, sizeof(LOGBRUSH));
	stLb.lbColor = m_rgbTrack;
	stLb.lbHatch = 0;
	stLb.lbStyle = BS_SOLID;

	CPen* pTrackPen = new CPen(PS_COSMETIC | PS_ALTERNATE, 1, &stLb);

	CGdiObject * pOldPen = pDC->SelectObject(pTrackPen);
	if (POLYGON_POINT_MINCOUNT <= nPtLen)
	{
		for (int i = 1; i < nPtLen; i++)
		{
			this->DrawLine(pDC, pPtList[i - 1], pPtList[i]);
		}
		this->DrawLine(pDC, pPtList[nPtLen - 1], pPtList[0]);
	}

	pDC->SelectObject(pOldPen);

	delete pTrackPen;
}


BOOL CPolygonRoiTracker::SetCursor(CDC* pDC, float fZoom)
{
	if (NULL == pDC || FALSE == this->IsInit())
		return FALSE;

	CPoint ptPos;
	::GetCursorPos(&ptPos);
	this->m_pWnd->ScreenToClient(&ptPos);

	INFO_POINT point;
	point.m_fx = ptPos.x;
	point.m_fy = ptPos.y;

	TYPE_HITROI eHitRoi = HitTest(point, fZoom);

	int nIdx = 0;
	if (TYPE_HITROI_BODY == eHitRoi)
	{
		const int x = GetHScrollPos();
		const int y = GetVScrollPos();

		INFO_POINT ptCur;
		ptCur.m_fx = ((point.m_fx + x) / fZoom);
		ptCur.m_fy = ((point.m_fy + y) / fZoom);

		double x1 = m_PointSrc[0].m_fx;
		double x2 = m_PointSrc[0].m_fx;
		double y1 = m_PointSrc[0].m_fy;
		double y2 = m_PointSrc[0].m_fy;

		int nSize = m_PointSrc.size();
		for (int i = 0; i < nSize; i++)
		{
			x1 = min(m_PointSrc[i].m_fx, x1);
			x2 = max(m_PointSrc[i].m_fx, x2);

			y1 = min(m_PointSrc[i].m_fy, y1);
			y2 = max(m_PointSrc[i].m_fy, y2);
		}


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

		INFO_POINT ptCenter;
		ptCenter.m_fx = x1 + (x2 - x1) / 2;
		ptCenter.m_fy = y1 + (y2 - y1) / 2;

		int nDegree = (int)(GetAngle(ptCur, ptCenter, TRUE) + 360);
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
	else if (TYPE_HITROI_CENTER == eHitRoi)
	{
		nIdx = 4;
	}
	else
	{
		return FALSE;
	}

	BOOL bResult = SetCursor(nIdx);
	return bResult;
}

TYPE_RESULTROI CPolygonRoiTracker::OnBeginTrack(UINT nFlags, INFO_POINT point, float fZoom)
{
	m_eHitRoi = HitTest(point, &m_nIdxDest, 1, fZoom);

	if (TYPE_HITROI_NONE == m_eHitRoi)
	{
		m_eTransformRoi = TYPE_TRANSFORMROI_CREATE;
		
		m_PointDest.clear();
		m_PointDest.push_back(point);
		m_PointDest.push_back(point);
	}
	else if (TYPE_HITROI_CENTER == m_eHitRoi)
	{
		m_eTransformRoi = TYPE_TRANSFORMROI_MOVE;
	}
	else if (TYPE_HITROI_BODY == m_eHitRoi)
	{
		m_eTransformRoi = TYPE_TRANSFORMROI_SCALE;
	}

	if (TYPE_TRANSFORMROI_CREATE != m_eTransformRoi)
	{
		m_PointDest.clear();

		// Convert point
		const int nCount = m_PointSrc.size();

		INFO_POINT* pPointSrc = new INFO_POINT[nCount];
		INFO_POINT* pPointZoom = new INFO_POINT[nCount];

		for (int i = 0; i < nCount; i++)
			pPointSrc[i] = m_PointSrc[i];

		ConvertPointPixelToDraw(pPointSrc, pPointZoom, nCount, fZoom);


		for (int i = 0; i < nCount; i++)
		{
			m_PointDest.push_back(pPointZoom[i]);
		}

		delete[] pPointSrc;
		delete[] pPointZoom;
	}

	return TYPE_RESULTROI_CONTINUE;
}

TYPE_RESULTROI CPolygonRoiTracker::OnEndTrack(TYPE_RESULTROI eResult, float fZoom, BOOL bErase)
{
	if (TYPE_RESULTROI_SUCCEEDED == eResult)
	{
		SetInitState(TRUE);

		const int nCount = m_PointDest.size();
		m_PointSrc.clear();

		// Convert point

		INFO_POINT* pPointSrc = new INFO_POINT[nCount];
		INFO_POINT* pPointZoom = new INFO_POINT[nCount];

		for (int i = 0; i < nCount; i++)
			pPointSrc[i] = m_PointDest[i];

		ConvertPointDrawToPixel(pPointSrc, pPointZoom, nCount, fZoom);

		for (int i = 0; i < nCount; i++)
		{
			m_PointSrc.push_back(pPointZoom[i]);
		}

		delete[] pPointSrc;
		delete[] pPointZoom;
	}

	if (bErase)
		Invalidate();

	m_eTransformRoi = TYPE_TRANSFORMROI_NONE;

	return eResult;
}

TYPE_RESULTROI CPolygonRoiTracker::OnMouseMessage(UINT msg, UINT nFlags, INFO_POINT point, float fZoom)
{
	const int nCount = m_PointDest.size();

	if (TYPE_TRANSFORMROI_CREATE == m_eTransformRoi)
	{
		m_PointDest[nCount - 1].m_fx = point.m_fx;
		m_PointDest[nCount - 1].m_fy = point.m_fy;

		if (WM_LBUTTONDOWN == msg)
		{
			m_PointDest.push_back(point);
		}
		else if (WM_RBUTTONUP == msg || WM_LBUTTONDBLCLK == msg)
		{
			const int w = (int)abs(m_PointDest[nCount - 1].m_fx - m_PointDest[nCount - 2].m_fx);
			const int h = (int)abs(m_PointDest[nCount - 1].m_fy - m_PointDest[nCount - 2].m_fy);

			if (VALUE_INFLATE >= w || VALUE_INFLATE >= h)
			{
				m_PointDest.pop_back();
			}

			return TYPE_RESULTROI_SUCCEEDED;
		}

		return TYPE_RESULTROI_CONTINUE;
	}
	else if (TYPE_TRANSFORMROI_MOVE == m_eTransformRoi)
	{
		const double w = (m_stPoint.m_fx - m_stPreviousPoint.m_fx);
		const double h = (m_stPoint.m_fy - m_stPreviousPoint.m_fy);

		for (int i = 0; i < nCount; i++)
		{
			m_PointDest[i].m_fx += w;
			m_PointDest[i].m_fy += h;
		}

	}
	else if (TYPE_TRANSFORMROI_SCALE == m_eTransformRoi)
	{
		m_PointDest[m_nIdxDest].m_fx = point.m_fx;
		m_PointDest[m_nIdxDest].m_fy = point.m_fy;

	}

	return CRoiTracker::OnMouseMessage(msg, nFlags, point, fZoom);

}

TYPE_RESULTROI CPolygonRoiTracker::OnMessage(MSG& msg)
{
	TYPE_RESULTROI eResult = TYPE_RESULTROI_FAILED;
	return eResult;
}

void CPolygonRoiTracker::OnUpdate(CDC* pDC, UINT nMode, float fZoom)
{
	if (NULL == pDC)
		return;

	// Draw Tracking Rectangle.
	if (TYPE_TRANSFORMROI_NONE != m_eTransformRoi)
	{
		LOGBRUSH stLb;
		memset(&stLb, 0x00, sizeof(LOGBRUSH));
		stLb.lbColor = m_rgbTrack;
		stLb.lbHatch = 0;
		stLb.lbStyle = BS_SOLID;

		CPen* pTrackPen = new CPen(PS_COSMETIC | PS_ALTERNATE, 1, &stLb);

		CGdiObject * pOldPen = pDC->SelectObject(pTrackPen);
		const int nCount = m_PointDest.size();
		if (POLYGON_POINT_MINCOUNT<=nCount)
		{
			for (int i = 1; i < nCount; i++)
			{
				this->DrawLine(pDC, m_PointDest[i - 1], m_PointDest[i]);
			}

			if (TYPE_TRANSFORMROI_CREATE != m_eTransformRoi)
			{
				if (POLYGON_POINT_MINCOUNT < nCount)
				{
					this->DrawLine(pDC, m_PointDest[nCount - 1], m_PointDest[0]);
				}
			}

		}
		pDC->SelectObject(pOldPen);

		delete pTrackPen;
	}

}

INFO_RECT CPolygonRoiTracker::GetHitRect(int nIdx, float fZoom)
{
	const int nCount = m_PointSrc.size();

	INFO_RECT rect;
	memset(&rect, 0x00, sizeof(INFO_RECT));

	if (NULL == m_pWnd || 0 > nIdx || nCount <= nIdx)
		return rect;

	const int x = GetHScrollPos();
	const int y = GetVScrollPos();

	INFO_POINT point = m_PointSrc[nIdx];
	point.m_fx = (point.m_fx * fZoom - x);
	point.m_fy = (point.m_fy * fZoom - y);

	rect = GetPointRect(point);

	return rect;
}

void CPolygonRoiTracker::SetInitState(BOOL bInit)
{
	m_bInit = bInit;
}

void CPolygonRoiTracker::DrawRoiPolygon(CDC* pDC, float fZoom)
{
	if (pDC && IsInit())
	{
		CGdiObject * pOldPen = NULL;

		const int nCount = m_PointSrc.size();
		if (POLYGON_POINT_MINCOUNT > nCount)
		{
			this->Clear();
			return;
		}

		/// Draw Line
		{
			CPen* pLinePen = new CPen(PS_SOLID, 1, m_rgbRoiPolygon);
			pOldPen = pDC->SelectObject(pLinePen);

			INFO_POINT* pPointSrc = new INFO_POINT[nCount];
			INFO_POINT* pPointZoom = new INFO_POINT[nCount];
			for (int i = 0; i < nCount; i++)
				pPointSrc[i] = m_PointSrc[i];

			ConvertPointPixelToDraw(pPointSrc, pPointZoom, nCount, fZoom);

			for (int i = 1; i < nCount; i++)
			{
				this->DrawLine(pDC, pPointZoom[i - 1], pPointZoom[i]);
			}

			if (POLYGON_POINT_MINCOUNT < nCount)
			{
				this->DrawLine(pDC, pPointZoom[0], pPointZoom[nCount - 1]);
			}

			pDC->SelectObject(pOldPen);

			delete pLinePen;
			delete[] pPointSrc;
			delete[] pPointZoom;
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

			for (int i = 0; i < nCount; i++)
			{
				INFO_RECT rect = GetHitRect(i, fZoom);
				RECT rtDraw = GetRectangle(rect);
				pDC->Rectangle(&rtDraw);
			}

			pDC->SelectObject(pOldPen);
			pDC->SelectObject(pOldBrush);

			delete pRectPen;
		}
		//*/

	}
}

BOOL CPolygonRoiTracker::SetCursor(int nIdx)
{
	BOOL bResult = FALSE;

	if (m_hCur[nIdx])
	{
		::SetCursor(m_hCur[nIdx]);
		bResult = TRUE;
	}

	return bResult;
}

int CPolygonRoiTracker::GetPoint(LPINFO_POINT pPoint, int nLen)
{
	const int nSize = m_PointSrc.size();

	if (FALSE == IsInit())
	{
		return -1;
	}
	else
	{
		if (NULL == pPoint || nSize > nLen)
			return nSize;
	}

	for (int i = 0; nSize > i; i++)
	{
		pPoint[i] = m_PointSrc[i];
	}
	return nSize;
}

int CPolygonRoiTracker::SetPoint(const LPINFO_POINT pPoint, const int nLen, float fZoom, BOOL bErase)
{
	if (NULL == pPoint || POLYGON_POINT_MINCOUNT > nLen)
		return POLYGON_POINT_MINCOUNT;

	m_PointDest.clear();

	LPINFO_POINT PointZoom = new INFO_POINT[nLen];
	ConvertPointPixelToDraw(pPoint, PointZoom, nLen, fZoom);

	for (int i = 0; nLen > i; i++)
	{
		m_PointDest.push_back(PointZoom[i]);
	}
	delete[] PointZoom;
	PointZoom = NULL;

	OnEndTrack(TYPE_RESULTROI_SUCCEEDED, fZoom, bErase);

	return nLen;
}


BOOL CPolygonRoiTracker::SetWidth(DWORD dwWidth)
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
	if (dwCurWidth != dwWidth)
	{
		const float fRatio = (float)dwWidth / (float)dwCurWidth;

		double nLeft = 0;
		int idx = 0;
		for (int i = 0; i < nLen; i++)
		{
			if (0 == i)
			{
				nLeft = pPointList[i].m_fx;
				idx = i;
			}
			else if (pPointList[i].m_fx < nLeft)
			{
				nLeft = pPointList[i].m_fx;
				idx = i;
			}
		}

		for (int i = 0; i < nLen; i++)
		{
			if (idx == i)
				continue;
			pPointList[i].m_fx = nLeft + (pPointList[i].m_fx - nLeft) * fRatio;
		}
		
		SetPoint(pPointList, nLen, 1.0f);
	}

	delete[] pPointList;
	return TRUE;
}

BOOL CPolygonRoiTracker::SetHeight(DWORD dwHeight)
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
	if (dwCurHeight != dwHeight)
	{
		const float fRatio = (float)dwHeight / (float)dwCurHeight;

		double nTop = 0;
		int idx = 0;
		for (int i = 0; i < nLen; i++)
		{
			if (0 == i)
			{
				nTop = pPointList[i].m_fy;
				idx = i;
			}
			else if (pPointList[i].m_fx < nTop)
			{
				nTop = pPointList[i].m_fy;
				idx = i;
			}
		}

		for (int i = 0; i < nLen; i++)
		{
			if (idx == i)
				continue;
			pPointList[i].m_fy = nTop + (pPointList[i].m_fy - nTop) * fRatio;
		}
		SetPoint(pPointList, nLen, 1.0f);
	}

	delete[] pPointList;
	return TRUE;
}

BOOL CPolygonRoiTracker::MovePoint(int cx, int cy)
{
	if (FALSE == IsInit())
		return FALSE;

	const int size = m_PointSrc.size();
	for (int i = 0; i < size; i++)
	{
		m_PointSrc[i].m_fx += cx;
		m_PointSrc[i].m_fy += cy;
	}
	return TRUE;
}

