#include "stdafx.h"
#include "RectRoiTracker.h"

#include "RoiTrackerDC.h"

#include "../Common/Tracker/VideoOutArrow.h"
#include <cmath>


CRectRoiTracker::CRectRoiTracker(CWnd* pWnd)
	: CRoiTracker(pWnd)
{
	m_bInit = FALSE;

	m_eHitRoi = TYPE_HITROI_NONE;
	m_eTransformRoi = TYPE_TRANSFORMROI_NONE;

	memset(m_PointSrc, 0x00, sizeof(INFO_POINT)*ROIRECT_POINT_COUNT);
	memset(m_PointDest, 0x00, sizeof(INFO_POINT)*RECT_POINT_COUNT);

	memset(m_hCur, 0x00, sizeof(HCURSOR)*ROIRECT_POINT_COUNT);

	m_rgbTrack = RGB(0, 0, 0);
	m_rgbRoiRect = RGB(0, 0, 0);
	m_rgbRoiLine = RGB(0, 0, 0);

	UINT CursorIDs[] =
	{
		AFX_IDC_TRACKNWSE, 
		AFX_IDC_TRACKNS,
		AFX_IDC_TRACKNESW,
		AFX_IDC_TRACKWE,
		AFX_IDC_TRACKNWSE,
		AFX_IDC_TRACKNS,
		AFX_IDC_TRACKNESW,
		AFX_IDC_TRACKWE,
		AFX_IDC_MOVE4WAY,
	};

	for (int i = 0; i < ROIRECT_POINT_COUNT; i++)
	{
		m_hCur[i] = ::AfxGetApp()->LoadCursor(CursorIDs[i]);
	}

	m_pTrackRect = NULL;

}

CRectRoiTracker::~CRectRoiTracker()
{
	for (int i = 0; i < ROIRECT_POINT_COUNT; i++)
	{
		if (m_hCur[i])
		{
			::DestroyCursor(m_hCur[i]);
		}
	}


	if (m_pTrackRect)
		delete[] m_pTrackRect;
	m_pTrackRect = NULL;

}

BOOL CRectRoiTracker::IsEnableRotate()
{
	return FALSE;
}

void CRectRoiTracker::Clear()
{
	m_bInit = FALSE;

	m_eHitRoi = TYPE_HITROI_NONE;
	m_eTransformRoi = TYPE_TRANSFORMROI_NONE;

	memset(m_PointSrc, 0x00, sizeof(INFO_POINT)*ROIRECT_POINT_COUNT);
	memset(m_PointDest, 0x00, sizeof(INFO_POINT)*RECT_POINT_COUNT);

	if (m_pTrackRect)
		delete[] m_pTrackRect;
	m_pTrackRect = NULL;

	Invalidate();
}


//
BOOL CRectRoiTracker::IsInit()
{
	return m_bInit;
}

void CRectRoiTracker::Draw(CDC* pDC, float fZoom)
{
	if (NULL == pDC)
		return;

	int nOldRop = pDC->SetROP2(R2_NOTXORPEN);

	DrawRoiRectangle(pDC, fZoom);

	pDC->SetROP2(nOldRop);
}

void CRectRoiTracker::DrawRoi(CDC* pDC, INFO_SIZE stSize, float fZoom, void* pReserved)
{
	if (NULL == pDC || FALSE == IsInit())
		return;

	BOOL bDrawForFile = FALSE;
	if (pReserved)
	{
		INFO_RESERVED* pstReserved = (INFO_RESERVED*)pReserved;
		bDrawForFile = pstReserved->m_bDrawForFile;
	}

	INFO_POINT PointZoom[ROIRECT_POINT_COUNT];
	memset(PointZoom, 0x00, sizeof(INFO_POINT)*ROIRECT_POINT_COUNT);
	ConvertPointPixelToDrawForRoi(m_PointSrc, PointZoom, ROIRECT_POINT_COUNT, stSize, fZoom, bDrawForFile);

	// ROI Inner Line - Edge
	DrawRoiEdgeLine(pDC, stSize, PointZoom, fZoom, pReserved);

	// ROI Outer Line
	this->DrawLine(pDC, PointZoom[TYPE_HITROI_TOPLEFT], PointZoom[TYPE_HITROI_TOPRIGHT]);
	this->DrawLine(pDC, PointZoom[TYPE_HITROI_TOPRIGHT], PointZoom[TYPE_HITROI_BOTTOMRIGHT]);
	this->DrawLine(pDC, PointZoom[TYPE_HITROI_BOTTOMRIGHT], PointZoom[TYPE_HITROI_BOTTOMLEFT]);
	this->DrawLine(pDC, PointZoom[TYPE_HITROI_BOTTOMLEFT], PointZoom[TYPE_HITROI_TOPLEFT]);

}

void CRectRoiTracker::DrawRoiEdgeLine(CDC* pDC, INFO_SIZE stSize, LPINFO_POINT pPointList, float fZoom, void* pReserved)
{
	if (NULL == pDC || NULL == pPointList || NULL == pReserved)
		return;

	INFO_RESERVED* pstReserved = (INFO_RESERVED*)pReserved;
	if (pstReserved->m_hInLine)
	{
		/*// DIRECTION
		typedef enum
		{
		TYPE_DIRECT_NONE,

		TYPE_DIRECT_L2R,		// Left to Right
		TYPE_DIRECT_R2L,		// Right to Left
		TYPE_DIRECT_T2B,		// Top to Bottom
		TYPE_DIRECT_B2T,		// Bottom to Top

		TYPE_DIRECT_IN2OUT,		// In to Out
		TYPE_DIRECT_OUT2IN,		// Out to In

		} TYPE_DIRECT;
		//*/

		if (!(1 == pstReserved->m_dwDirection || 2 == pstReserved->m_dwDirection || 3 == pstReserved->m_dwDirection || 4 == pstReserved->m_dwDirection))
			return;

		const int w = (int)stSize.m_fcx;
		const int h = (int)stSize.m_fcy;

		CDC maskDC;
		maskDC.CreateCompatibleDC(pDC);
		maskDC.SelectObject(pstReserved->m_hInLine);
		if (pstReserved->m_hInBrush)
			maskDC.SelectObject(pstReserved->m_hInBrush);

		VOID *pvBits = NULL;;          // pointer to DIB section
		HBITMAP hBitmap = CreateEdgeBitmap(maskDC.m_hDC, w, h, &pvBits);
		HBITMAP hOldBitmap = (HBITMAP)::SelectObject(maskDC.m_hDC, hBitmap);
		
		if (1 == pstReserved->m_dwDirection || 2 == pstReserved->m_dwDirection)
		{
			BOOL bLtoR = TRUE;
			if (2 == pstReserved->m_dwDirection)
				bLtoR = FALSE;

			DrawRoiHStepLine(&maskDC, pPointList, pstReserved->m_dwStep, fZoom, bLtoR);
		}
		else if (3 == pstReserved->m_dwDirection || 4 == pstReserved->m_dwDirection)
		{
			BOOL bTtoB = TRUE;
			if (4 == pstReserved->m_dwDirection)
				bTtoB = FALSE;

			DrawRoiVStepLine(&maskDC, pPointList, pstReserved->m_dwStep, fZoom, bTtoB);
		}

		// Set Alpha Value...
		UCHAR ubAlpha = 0xFF;
		float fAlphaFactor = (pstReserved->m_dwOpacity / 255.0f);

		BYTE red = 0;
		BYTE green = 0;
		BYTE blue = 0;

		for (int y = 0; y < (int)h; y++)
		{
			for (int x = 0; x < (int)w; x++)
			{
				UINT32& dwColor = ((UINT32 *)pvBits)[x + y * (int)w];

				red = GetRValue(dwColor);
				green = GetGValue(dwColor);
				blue = GetBValue(dwColor);

				if (0xBF != red && 0xBF != green && 0xBF != blue)
				{
					ubAlpha = (UCHAR)(0xFF * fAlphaFactor);
					
					dwColor = (ubAlpha << 24) |					//0xaa000000 
						((UCHAR)(blue* fAlphaFactor) << 16) |	//0x00rr0000 
						((UCHAR)(green* fAlphaFactor) << 8) |	//0x0000gg00 
						((UCHAR)(red* fAlphaFactor));			//0x000000bb
				}
				else
				{
					dwColor = 0;
				}
			}
		}

		BLENDFUNCTION bf;
		bf.BlendOp = AC_SRC_OVER;
		bf.BlendFlags = 0;
		bf.AlphaFormat = AC_SRC_ALPHA;   // use source alpha  
		bf.SourceConstantAlpha = 0xFF;   // use constant alpha, with
		::AlphaBlend(pDC->m_hDC, 0, 0, w, h, maskDC.m_hDC, 0, 0, w, h, bf);

		::SelectObject(maskDC.m_hDC, hOldBitmap);
		if (hBitmap)
			::DeleteObject(hBitmap);
		maskDC.DeleteDC();
	}
	pDC->SelectObject(pstReserved->m_hOutLine);

}

void CRectRoiTracker::DrawRoiHStepLine(CDC* pDC, LPINFO_POINT pPointList, DWORD dwStep, float fZoom, BOOL bLtoR)
{
	if (NULL == pDC || NULL == pPointList)
		return;

	const double w = pPointList[TYPE_HITROI_TOPRIGHT].m_fx - pPointList[TYPE_HITROI_TOPLEFT].m_fx;
	const double h = pPointList[TYPE_HITROI_BOTTOMLEFT].m_fy - pPointList[TYPE_HITROI_TOPLEFT].m_fy;

	const INFO_POINT ptStart = pPointList[TYPE_HITROI_TOPLEFT];
	const INFO_POINT ptEnd = pPointList[TYPE_HITROI_TOPRIGHT];

	INFO_POINT pt1 = ptStart;
	INFO_POINT pt2 = ptEnd;

	ARROWSTRUCT stArrow;
	stArrow.nWidth = (int)(ARROWWIDTH * fZoom);
	stArrow.fTheta = 0.3f;
	stArrow.bFill = TRUE;

	int nIdx = 0;

	const float fStep = dwStep * fZoom;
	for (float y = fStep; y < h; y += fStep)
	{
		pt1.m_fy = (ptStart.m_fy + y);
		pt2.m_fy = (ptEnd.m_fy + y);

		if (0==nIdx % 2)
		{
			int x1 = (int)pt1.m_fx;
			int y1 = (int)pt1.m_fy;
			int x2 = (int)pt2.m_fx;
			int y2 = (int)pt2.m_fy;

			if (FALSE==bLtoR)
			{
				x1 = (int)pt2.m_fx;
				y1 = (int)pt2.m_fy;
				x2 = (int)pt1.m_fx;
				y2 = (int)pt1.m_fy;
			}

			::MoveToEx(pDC->m_hDC, x1, y1, NULL);
			ArrowTo(pDC->m_hDC, x2, y2, &stArrow);

		}
		else
		{
			this->DrawLine(pDC, pt1, pt2);
		}

		nIdx++;
	}
}

void CRectRoiTracker::DrawRoiVStepLine(CDC* pDC, LPINFO_POINT pPointList, DWORD dwStep, float fZoom, BOOL bTtoB)
{
	if (NULL == pDC || NULL == pPointList)
		return;

	const double w = pPointList[TYPE_HITROI_TOPRIGHT].m_fx - pPointList[TYPE_HITROI_TOPLEFT].m_fx;
	const double h = pPointList[TYPE_HITROI_BOTTOMLEFT].m_fy - pPointList[TYPE_HITROI_TOPLEFT].m_fy;

	const INFO_POINT ptStart = pPointList[TYPE_HITROI_TOPLEFT];
	const INFO_POINT ptEnd = pPointList[TYPE_HITROI_BOTTOMLEFT];

	INFO_POINT pt1 = ptStart;
	INFO_POINT pt2 = ptEnd;

	ARROWSTRUCT stArrow;
	stArrow.nWidth = (int)(ARROWWIDTH * fZoom);
	stArrow.fTheta = 0.3f;
	stArrow.bFill = TRUE;

	int nIdx = 0;

	const double fStep = dwStep * fZoom;
	for (double x = fStep; x < w; x += fStep)
	{
		pt1.m_fx = (ptStart.m_fx + x);
		pt2.m_fx = (ptEnd.m_fx + x);

		if (0 == nIdx % 2)
		{
			int x1 = (int)pt1.m_fx;
			int y1 = (int)pt1.m_fy;
			int x2 = (int)pt2.m_fx;
			int y2 = (int)pt2.m_fy;

			if (FALSE == bTtoB)
			{
				x1 = (int)pt2.m_fx;
				y1 = (int)pt2.m_fy;
				x2 = (int)pt1.m_fx;
				y2 = (int)pt1.m_fy;
			}

			::MoveToEx(pDC->m_hDC, x1, y1, NULL);
			ArrowTo(pDC->m_hDC, x2, y2, &stArrow);
		}
		else
		{
			this->DrawLine(pDC, pt1, pt2);
		}

		nIdx++;
	}

}


void CRectRoiTracker::DrawRoiRectangle(CDC* pDC, float fZoom)
{
	if (pDC && IsInit())
	{
		CGdiObject * pOldPen = NULL;

		INFO_POINT PointZoom[ROIRECT_POINT_COUNT];
		memset(PointZoom, 0x00, sizeof(INFO_POINT)*ROIRECT_POINT_COUNT);
		ConvertPointPixelToDraw(m_PointSrc, PointZoom, ROIRECT_POINT_COUNT, fZoom);

		/// Draw Line
		{
			CPen* pLinePen = new CPen(PS_SOLID, 1, m_rgbRoiLine);
			pOldPen = pDC->SelectObject(pLinePen);

			this->DrawLine(pDC, PointZoom[TYPE_HITROI_TOPLEFT], PointZoom[TYPE_HITROI_TOPRIGHT]);
			this->DrawLine(pDC, PointZoom[TYPE_HITROI_TOPRIGHT], PointZoom[TYPE_HITROI_BOTTOMRIGHT]);
			this->DrawLine(pDC, PointZoom[TYPE_HITROI_BOTTOMRIGHT], PointZoom[TYPE_HITROI_BOTTOMLEFT]);
			this->DrawLine(pDC, PointZoom[TYPE_HITROI_BOTTOMLEFT], PointZoom[TYPE_HITROI_TOPLEFT]);

			pDC->SelectObject(pOldPen);
			delete pLinePen;

			if (IsEnableRotate())
			{
				CPen* pLinePen = new CPen(PS_SOLID, 1, m_rgbTrack);
				pOldPen = pDC->SelectObject(pLinePen);

				this->DrawLine(pDC, PointZoom[TYPE_HITROI_TOP], PointZoom[TYPE_HITROI_BOTTOM]);
				this->DrawLine(pDC, PointZoom[TYPE_HITROI_LEFT], PointZoom[TYPE_HITROI_RIGHT]);

				pDC->SelectObject(pOldPen);
				delete pLinePen;
			}
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

			for (int i = 0; i < TYPE_HITROI_BODY; i++)
			{
				INFO_RECT rect = GetPointRect(PointZoom[i]);
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

void CRectRoiTracker::DrawTracker(CDC* pDC, INFO_POINT pt1, INFO_POINT pt2, float fZoom, BOOL bDone)
{
	if (NULL == pDC || FALSE == IsInit())
		return;

	const int x = GetHScrollPos();
	const int y = GetVScrollPos();

	if (bDone && m_pTrackRect)
	{
		INFO_POINT PointZoom[ROIRECT_POINT_COUNT];
		memset(PointZoom, 0x00, sizeof(INFO_POINT)*ROIRECT_POINT_COUNT);
		ConvertPointDrawToPixel(m_pTrackRect, PointZoom, ROIRECT_POINT_COUNT, fZoom);

		double w = PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx - PointZoom[TYPE_HITROI_TOPLEFT / 2].m_fx;
		double h = PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy - PointZoom[TYPE_HITROI_TOPLEFT / 2].m_fy;


		m_PointSrc[TYPE_HITROI_TOPLEFT] = PointZoom[TYPE_HITROI_TOPLEFT / 2];
		m_PointSrc[TYPE_HITROI_TOP] = PointZoom[TYPE_HITROI_TOPLEFT / 2];
		m_PointSrc[TYPE_HITROI_TOP].m_fx += w / 2;

		m_PointSrc[TYPE_HITROI_TOPRIGHT] = PointZoom[TYPE_HITROI_TOPRIGHT / 2];
		m_PointSrc[TYPE_HITROI_RIGHT] = PointZoom[TYPE_HITROI_TOPRIGHT / 2];
		m_PointSrc[TYPE_HITROI_RIGHT].m_fy += h / 2;

		m_PointSrc[TYPE_HITROI_BOTTOMRIGHT] = PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2];
		m_PointSrc[TYPE_HITROI_BOTTOM] = PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2];
		m_PointSrc[TYPE_HITROI_BOTTOM].m_fx = m_PointSrc[TYPE_HITROI_TOP].m_fx;

		m_PointSrc[TYPE_HITROI_BOTTOMLEFT] = PointZoom[TYPE_HITROI_BOTTOMLEFT / 2];
		m_PointSrc[TYPE_HITROI_LEFT] = PointZoom[TYPE_HITROI_BOTTOMLEFT / 2];
		m_PointSrc[TYPE_HITROI_LEFT].m_fy = m_PointSrc[TYPE_HITROI_RIGHT].m_fy;

		m_PointSrc[TYPE_HITROI_CENTER].m_fx = m_PointSrc[TYPE_HITROI_TOP].m_fx;
		m_PointSrc[TYPE_HITROI_CENTER].m_fy = m_PointSrc[TYPE_HITROI_RIGHT].m_fy;
		

		delete[] m_pTrackRect;
		m_pTrackRect = NULL;

		return;
	}

	CRoiTrackerDC* pRDC = new CRoiTrackerDC(pDC, NOTSRCINVERT);
	pRDC->SetROP2(R2_NOTXORPEN);

	INFO_POINT pPt[RECT_POINT_COUNT];
	pPt[TYPE_HITROI_TOPLEFT / 2] = GetTrackerPointFromSrc(m_PointSrc[TYPE_HITROI_TOPLEFT], fZoom);
	pPt[TYPE_HITROI_TOPRIGHT / 2] = GetTrackerPointFromSrc(m_PointSrc[TYPE_HITROI_TOPRIGHT], fZoom);
	pPt[TYPE_HITROI_BOTTOMRIGHT / 2] = GetTrackerPointFromSrc(m_PointSrc[TYPE_HITROI_BOTTOMRIGHT], fZoom);
	pPt[TYPE_HITROI_BOTTOMLEFT / 2] = GetTrackerPointFromSrc(m_PointSrc[TYPE_HITROI_BOTTOMLEFT], fZoom);

	if (NULL == m_pTrackRect)
	{
		m_pTrackRect = new INFO_POINT[RECT_POINT_COUNT];

		for (int i = 0; i < RECT_POINT_COUNT; i++)
			m_pTrackRect[i] = pPt[i];
	}
	else
	{
		DrawTrackRectangle(pRDC, m_pTrackRect, RECT_POINT_COUNT);
	}

	pPt[TYPE_HITROI_TOPLEFT / 2] = GetTrackerPointFromSrc(m_PointSrc[TYPE_HITROI_TOPLEFT], pt1, pt2, fZoom);
	pPt[TYPE_HITROI_TOPRIGHT / 2] = GetTrackerPointFromSrc(m_PointSrc[TYPE_HITROI_TOPRIGHT], pt1, pt2, fZoom);
	pPt[TYPE_HITROI_BOTTOMRIGHT / 2] = GetTrackerPointFromSrc(m_PointSrc[TYPE_HITROI_BOTTOMRIGHT], pt1, pt2, fZoom);
	pPt[TYPE_HITROI_BOTTOMLEFT / 2] = GetTrackerPointFromSrc(m_PointSrc[TYPE_HITROI_BOTTOMLEFT], pt1, pt2, fZoom);

	DrawTrackRectangle(pRDC, pPt, RECT_POINT_COUNT);
	if (m_pTrackRect)
	{
		for (int i = 0; i < RECT_POINT_COUNT; i++)
			m_pTrackRect[i] = pPt[i];
	}

	delete pRDC;
}


void CRectRoiTracker::DrawTrackRectangle(CDC* pDC, LPINFO_POINT pPtList, int nPtLen)
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
	this->DrawPolygon(pDC, pPtList, nPtLen);
	pDC->SelectObject(pOldPen);

	delete pTrackPen;
}


TYPE_HITROI CRectRoiTracker::HitTest(INFO_POINT point, float fZoom)
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
	{
		eHitRoi = TYPE_HITROI_NONE;

		eHitRoi = HitLineTest(point, TYPE_HITROI_TOPLEFT, TYPE_HITROI_TOPRIGHT, fZoom);
		if (TYPE_HITROI_NONE != eHitRoi)
		{
			return TYPE_HITROI_CENTER;
			//return TYPE_HITROI_LINE_TOP;
		}

		eHitRoi = HitLineTest(point, TYPE_HITROI_TOPRIGHT, TYPE_HITROI_BOTTOMRIGHT, fZoom);
		if (TYPE_HITROI_NONE != eHitRoi)
		{
			return TYPE_HITROI_CENTER;
			//return TYPE_HITROI_LINE_RIGHT;
		}

		eHitRoi = HitLineTest(point, TYPE_HITROI_BOTTOMLEFT, TYPE_HITROI_BOTTOMRIGHT, fZoom);
		if (TYPE_HITROI_NONE != eHitRoi)
		{
			return TYPE_HITROI_CENTER;
			//return TYPE_HITROI_LINE_BOTTOM;
		}

		eHitRoi = HitLineTest(point, TYPE_HITROI_TOPLEFT, TYPE_HITROI_BOTTOMLEFT, fZoom);
		if (TYPE_HITROI_NONE != eHitRoi)
		{
			return TYPE_HITROI_CENTER;
			//return TYPE_HITROI_LINE_LEFT;
		}
	}

	return eHitRoi;
}

TYPE_HITROI CRectRoiTracker::HitLineTest(INFO_POINT point, TYPE_HITROI eStart, TYPE_HITROI eEnd, float fZoom)
{
	const int x = GetHScrollPos();
	const int y = GetVScrollPos();

	point.m_fx = ((point.m_fx + x) / fZoom);
	point.m_fy = ((point.m_fy + y) / fZoom);

	INFO_POINT stStart = GetHitPoint(m_PointSrc, eStart);
	INFO_POINT stEnd = GetHitPoint(m_PointSrc, eEnd);

	return HitTest(point, stStart, stEnd, fZoom);
}


TYPE_HITROI CRectRoiTracker::HitTest(INFO_POINT point, INFO_POINT stStart, INFO_POINT stEnd, float fZoom)
{
	//
	INFO_RECT rect;
	memset(&rect, 0x00, sizeof(INFO_RECT));

	rect.m_fleft = stStart.m_fx - VALUE_INFLATE;
	rect.m_ftop = stStart.m_fy - VALUE_INFLATE;
	rect.m_fright = stEnd.m_fx + VALUE_INFLATE;
	rect.m_fbottom = stEnd.m_fy + VALUE_INFLATE;

	if (IsPointInRectangle(rect, point))
		return TYPE_HITROI_CENTER;

	return TYPE_HITROI_NONE;
}


INFO_RECT CRectRoiTracker::GetHitRect(TYPE_HITROI eHit, float fZoom)
{
	if (NULL==m_pWnd)
	{
		INFO_RECT rect;
		memset(&rect, 0x00, sizeof(INFO_RECT));
		return rect;
	}

	const int x = GetHScrollPos();
	const int y = GetVScrollPos();

	INFO_POINT point = GetHitPoint(m_PointSrc, eHit);
	point.m_fx = (point.m_fx * fZoom - x);
	point.m_fy = (point.m_fy * fZoom - y);

	INFO_RECT rect = GetPointRect(point);
	return rect;
}


INFO_POINT CRectRoiTracker::GetHitPoint(LPINFO_POINT pPoint, TYPE_HITROI eHit)
{
	// Handles are numbered clockwise, like this:
	//
	//		0		   1		  2
	//		*----------*----------*
	//		|					  |
	//		|					  |
	//	  7 *		   * 8		  * 3
	//		|					  |
	//		|					  |
	//		*----------*----------*
	//		6		   5		  4
	//
	// The center point is handle 8, the body is handle 9.

	int idx = (int)eHit;

	INFO_POINT pnt = pPoint[idx];
	return pnt;
}

//
TYPE_RESULTROI CRectRoiTracker::OnBeginTrack(UINT nFlags, INFO_POINT point, float fZoom)
{
	m_eHitRoi = HitTest(point, fZoom);

	if (TYPE_HITROI_NONE == m_eHitRoi)
	{
		m_eTransformRoi = TYPE_TRANSFORMROI_CREATE;

		for (int i = 0; i < RECT_POINT_COUNT; i++)
		{
			m_PointDest[i] = point;
		}
	}
	else if (TYPE_HITROI_CENTER == m_eHitRoi || TYPE_HITROI_BODY == m_eHitRoi)
	{
		m_eTransformRoi = TYPE_TRANSFORMROI_MOVE;
	}
	else
	{
		m_eTransformRoi = TYPE_TRANSFORMROI_SCALE;
	}

	if (TYPE_TRANSFORMROI_CREATE != m_eTransformRoi)
	{
		INFO_POINT PointZoom[ROIRECT_POINT_COUNT];
		memset(PointZoom, 0x00, sizeof(INFO_POINT)*ROIRECT_POINT_COUNT);
		ConvertPointPixelToDraw(m_PointSrc, PointZoom, ROIRECT_POINT_COUNT, fZoom);

		m_PointDest[TYPE_HITROI_TOPLEFT / 2] = PointZoom[TYPE_HITROI_TOPLEFT];
		m_PointDest[TYPE_HITROI_TOPRIGHT / 2] = PointZoom[TYPE_HITROI_TOPRIGHT];
		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2] = PointZoom[TYPE_HITROI_BOTTOMRIGHT];
		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2] = PointZoom[TYPE_HITROI_BOTTOMLEFT];

	}


	return TYPE_RESULTROI_CONTINUE;
}

TYPE_RESULTROI CRectRoiTracker::OnEndTrack(TYPE_RESULTROI eResult, float fZoom, BOOL bErase)
{

	if (TYPE_RESULTROI_SUCCEEDED == eResult)
	{
		SetInitState(TRUE);

		// 0: TopLeft
		// 1: TopRight
		// 2: BottomRight
		// 3: BottomLeft

		double w = m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx - m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx;
		double h = m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy - m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy;

		BOOL bW = FALSE;
		BOOL bH = FALSE;
		if (0>w)	bW = TRUE;
		if (0>h)	bH = TRUE;

		if (bW || bH)
		{
			SwapDestPoint(bW, bH);

			w = m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx - m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx;
			h = m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy - m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy;
		}


		{
			INFO_POINT PointZoom[ROIRECT_POINT_COUNT];
			memset(PointZoom, 0x00, sizeof(INFO_POINT)*ROIRECT_POINT_COUNT);
			ConvertPointDrawToPixel(m_PointDest, PointZoom, ROIRECT_POINT_COUNT, fZoom);

			w = PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx - PointZoom[TYPE_HITROI_TOPLEFT / 2].m_fx;
			h = PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy - PointZoom[TYPE_HITROI_TOPLEFT / 2].m_fy;


			m_PointSrc[TYPE_HITROI_TOPLEFT]		= PointZoom[TYPE_HITROI_TOPLEFT / 2];
			m_PointSrc[TYPE_HITROI_TOP]			= PointZoom[TYPE_HITROI_TOPLEFT / 2];
			m_PointSrc[TYPE_HITROI_TOP].m_fx += w / 2;

			m_PointSrc[TYPE_HITROI_TOPRIGHT]	= PointZoom[TYPE_HITROI_TOPRIGHT / 2];
			m_PointSrc[TYPE_HITROI_RIGHT]		= PointZoom[TYPE_HITROI_TOPRIGHT / 2];
			m_PointSrc[TYPE_HITROI_RIGHT].m_fy += h / 2;

			m_PointSrc[TYPE_HITROI_BOTTOMRIGHT] = PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2];
			m_PointSrc[TYPE_HITROI_BOTTOM]		= PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2];
			m_PointSrc[TYPE_HITROI_BOTTOM].m_fx = m_PointSrc[TYPE_HITROI_TOP].m_fx;

			m_PointSrc[TYPE_HITROI_BOTTOMLEFT]	= PointZoom[TYPE_HITROI_BOTTOMLEFT / 2];
			m_PointSrc[TYPE_HITROI_LEFT]		= PointZoom[TYPE_HITROI_BOTTOMLEFT / 2];
			m_PointSrc[TYPE_HITROI_LEFT].m_fy = m_PointSrc[TYPE_HITROI_RIGHT].m_fy;

			m_PointSrc[TYPE_HITROI_CENTER].m_fx = m_PointSrc[TYPE_HITROI_TOP].m_fx;
			m_PointSrc[TYPE_HITROI_CENTER].m_fy = m_PointSrc[TYPE_HITROI_RIGHT].m_fy;
		}


		if (IsEnableRotate())
		{
			m_PointSrc[TYPE_HITROI_TOP].m_fy	-= ROTATE_POINT_DISTANCE;
			m_PointSrc[TYPE_HITROI_BOTTOM].m_fy+= ROTATE_POINT_DISTANCE;
			m_PointSrc[TYPE_HITROI_LEFT].m_fx	-= ROTATE_POINT_DISTANCE;
			m_PointSrc[TYPE_HITROI_RIGHT].m_fx += ROTATE_POINT_DISTANCE;
		}

	}

	if (bErase)
		Invalidate();

	m_eTransformRoi = TYPE_TRANSFORMROI_NONE;

	return eResult;
}

TYPE_RESULTROI CRectRoiTracker::OnMouseMessage(UINT msg, UINT nFlags, INFO_POINT point, float fZoom)
{
	// 0: TopLeft
	// 1: TopRight
	// 2: BottomRight
	// 3: BottomLeft
	const BOOL bShift = (::GetKeyState(VK_LSHIFT) & FLAG_LBUTTONDOWN || ::GetKeyState(VK_RSHIFT) & FLAG_LBUTTONDOWN);

	if (TYPE_TRANSFORMROI_CREATE == m_eTransformRoi)
	{
		m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fx = point.m_fx;
		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2] = point;
		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = point.m_fy;

		if (bShift)
		{
			SetRectanglePoint(point, 
				m_PointDest[TYPE_HITROI_TOPLEFT / 2], 
				m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2], 
				m_PointDest[TYPE_HITROI_TOPRIGHT / 2], 
				m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2]);
		}
	}
	else if (TYPE_TRANSFORMROI_SCALE == m_eTransformRoi)
	{
		// Resize rectangle...
		ResizeRectangle(m_eHitRoi, point);
	}
	else if (TYPE_TRANSFORMROI_MOVE == m_eTransformRoi)
	{
		const double w = m_stPoint.m_fx - m_stPreviousPoint.m_fx;
		const double h = m_stPoint.m_fy - m_stPreviousPoint.m_fy;
		
		for (int i = 0; i < RECT_POINT_COUNT; i++)
		{
			m_PointDest[i].m_fx += w;
			m_PointDest[i].m_fy += h;
		}
	}

	return CRoiTracker::OnMouseMessage( msg, nFlags, point, fZoom);
}

TYPE_RESULTROI CRectRoiTracker::OnMessage(MSG& msg)
{
	TYPE_RESULTROI eResult = TYPE_RESULTROI_FAILED;
	return eResult;
}

void CRectRoiTracker::OnUpdate(CDC* pDC, UINT nMode, float fZoom)
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
		this->DrawPolygon(pDC, m_PointDest, RECT_POINT_COUNT);
		pDC->SelectObject(pOldPen);

		delete pTrackPen;
	}

}

BOOL CRectRoiTracker::SetCursor(CDC * pDC, float fZoom)
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

BOOL CRectRoiTracker::SetCursor(TYPE_HITROI eHit)
{
	BOOL bResult = FALSE;

	int nIdx = (int)eHit;
	if (m_hCur[nIdx])
	{
		::SetCursor(m_hCur[nIdx]);
		bResult = TRUE;
	}

	return bResult;
}

void CRectRoiTracker::SetInitState(BOOL bInit)
{
	m_bInit = bInit;
}

void CRectRoiTracker::SwapDestPoint(BOOL bW, BOOL bH)
{
	if (!bW && !bH)
		return;

	if (TYPE_TRANSFORMROI_CREATE == m_eTransformRoi)
	{
		if (bW && bH)
		{
			MirrorDestPointH();
			MirrorDestPointV();
		}
		else if (bW)
		{
			MirrorDestPointH();
		}
		else if (bH)
		{
			MirrorDestPointV();
		}

		/*//
		const INFO_POINT stStart = m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2];
		const INFO_POINT stEnd = m_PointDest[TYPE_HITROI_TOPLEFT / 2];

		for (int i = 0; i < 4; i++)
			m_PointDest[i] = stStart;

		m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fx = stEnd.m_fx;
		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2] = stEnd;
		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = stEnd.m_fy;
		//*/

	}
	else if (TYPE_TRANSFORMROI_SCALE == m_eTransformRoi)
	{
		if (TYPE_HITROI_TOP == m_eHitRoi || TYPE_HITROI_BOTTOM == m_eHitRoi)
		{
			MirrorDestPointV();			
		}
		else if (TYPE_HITROI_RIGHT == m_eHitRoi || TYPE_HITROI_LEFT == m_eHitRoi)
		{
			MirrorDestPointH();
		}
		else if (TYPE_HITROI_TOPLEFT == m_eHitRoi || 
				 TYPE_HITROI_TOPRIGHT == m_eHitRoi || 
				 TYPE_HITROI_BOTTOMRIGHT == m_eHitRoi || 
				 TYPE_HITROI_BOTTOMLEFT == m_eHitRoi )
		{
			if (bW && bH)
			{
				MirrorDestPointH();
				MirrorDestPointV();
			}
			else if (bW)
			{
				MirrorDestPointH();
			}
			else if (bH)
			{
				MirrorDestPointV();
			}
		}

	}
	else if (TYPE_TRANSFORMROI_MOVE == m_eTransformRoi)
	{
		// do nothing...
	}

}

void CRectRoiTracker::MirrorDestPointH()
{
	const INFO_POINT stStart = m_PointDest[TYPE_HITROI_TOPLEFT / 2];
	const INFO_POINT stEnd = m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2];

	m_PointDest[TYPE_HITROI_TOPLEFT / 2] = m_PointDest[TYPE_HITROI_TOPRIGHT / 2];
	m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2] = m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2];

	m_PointDest[TYPE_HITROI_TOPRIGHT / 2] = stStart;
	m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2] = stEnd;
}

void CRectRoiTracker::MirrorDestPointV()
{
	const INFO_POINT stStart = m_PointDest[TYPE_HITROI_TOPLEFT / 2];
	const INFO_POINT stEnd = m_PointDest[TYPE_HITROI_TOPRIGHT / 2];

	m_PointDest[TYPE_HITROI_TOPLEFT / 2] = m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2];
	m_PointDest[TYPE_HITROI_TOPRIGHT / 2] = m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2];

	m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2] = stStart;
	m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2] = stEnd;
}

void CRectRoiTracker::ResizeRectangle(TYPE_HITROI eHitRoi, INFO_POINT point)
{
	const BOOL bShift = (::GetKeyState(VK_LSHIFT) & FLAG_LBUTTONDOWN || ::GetKeyState(VK_RSHIFT) & FLAG_LBUTTONDOWN);

	if (TYPE_HITROI_TOPLEFT == eHitRoi)
	{
		m_PointDest[TYPE_HITROI_TOPLEFT / 2] = point;
		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fx = point.m_fx;
		m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fy = point.m_fy;

		if (bShift)
		{
			SetRectanglePoint(point, 
				m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2],
				m_PointDest[TYPE_HITROI_TOPLEFT / 2],
				m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2],
				m_PointDest[TYPE_HITROI_TOPRIGHT / 2] );
		}
	}
	else if (TYPE_HITROI_TOPRIGHT == eHitRoi)
	{
		m_PointDest[TYPE_HITROI_TOPRIGHT / 2] = point;
		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = point.m_fx;
		m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy = point.m_fy;

		if (bShift)
		{
			SetRectanglePoint(point,
				m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2],
				m_PointDest[TYPE_HITROI_TOPRIGHT / 2],
				m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2],
				m_PointDest[TYPE_HITROI_TOPLEFT / 2]);
		}
	}
	else if (TYPE_HITROI_BOTTOMRIGHT == eHitRoi)
	{
		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2] = point;
		m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fx = point.m_fx;
		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = point.m_fy;

		if (bShift)
		{
			SetRectanglePoint(point,
				m_PointDest[TYPE_HITROI_TOPLEFT / 2],
				m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2],
				m_PointDest[TYPE_HITROI_TOPRIGHT / 2],
				m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2]);
		}

	}
	else if (TYPE_HITROI_BOTTOMLEFT == eHitRoi)
	{
		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2] = point;
		m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx = point.m_fx;
		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = point.m_fy;

		if (bShift)
		{
			SetRectanglePoint(point,
				m_PointDest[TYPE_HITROI_TOPRIGHT / 2],
				m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2],
				m_PointDest[TYPE_HITROI_TOPLEFT / 2],
				m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2]);
		}
	}

	///
	else if (TYPE_HITROI_TOP == eHitRoi)
	{
		m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy = point.m_fy;
		m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fy = point.m_fy;

		if (bShift)
		{
			const double r = (m_PointSrc[TYPE_HITROI_BOTTOM].m_fy - point.m_fy) / 2;

			m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx = m_PointSrc[eHitRoi].m_fx - r;
			m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fx = m_PointSrc[eHitRoi].m_fx - r;
			m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fx = m_PointSrc[eHitRoi].m_fx + r;
			m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = m_PointSrc[eHitRoi].m_fx + r;
		}
	}
	else if (TYPE_HITROI_RIGHT == eHitRoi)
	{
		m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fx = point.m_fx;
		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = point.m_fx;

		if (bShift)
		{
			const double r = (m_PointSrc[TYPE_HITROI_LEFT].m_fx - point.m_fx) / 2 * -1;

			m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy = m_PointSrc[eHitRoi].m_fy - r;
			m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fy = m_PointSrc[eHitRoi].m_fy - r;
			m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = m_PointSrc[eHitRoi].m_fy + r;
			m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = m_PointSrc[eHitRoi].m_fy + r;
		}

	}
	else if (TYPE_HITROI_BOTTOM == eHitRoi)
	{
		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = point.m_fy;
		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = point.m_fy;

		if (bShift)
		{
			const double r = (m_PointSrc[TYPE_HITROI_TOP].m_fy - point.m_fy) / 2 * -1;

			m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx = m_PointSrc[eHitRoi].m_fx - r;
			m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fx = m_PointSrc[eHitRoi].m_fx - r;
			m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fx = m_PointSrc[eHitRoi].m_fx + r;
			m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = m_PointSrc[eHitRoi].m_fx + r;
		}
	}
	else if (TYPE_HITROI_LEFT == eHitRoi)
	{
		m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx = point.m_fx;
		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fx = point.m_fx;

		if (bShift)
		{
			const double r = (m_PointSrc[TYPE_HITROI_RIGHT].m_fx - point.m_fx) / 2;

			m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy = m_PointSrc[eHitRoi].m_fy - r;
			m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fy = m_PointSrc[eHitRoi].m_fy - r;
			m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = m_PointSrc[eHitRoi].m_fy + r;
			m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = m_PointSrc[eHitRoi].m_fy + r;
		}
	}
	//*/

}

void CRectRoiTracker::SetRectanglePoint(const INFO_POINT point, const INFO_POINT ptFix, INFO_POINT& ptMove, INFO_POINT& ptX, INFO_POINT& ptY)
{
	const double w = std::abs(point.m_fx - ptFix.m_fx);
	const double h = std::abs(point.m_fy - ptFix.m_fy);
	const double n = min(w, h);

	if (point.m_fx > ptFix.m_fx)
	{
		ptX.m_fx		= ptFix.m_fx + n;
		ptMove.m_fx	= ptFix.m_fx + n;
	}
	else if (point.m_fx < ptFix.m_fx)
	{
		ptX.m_fx		= ptFix.m_fx - n;
		ptMove.m_fx	= ptFix.m_fx - n;
	}

	if (point.m_fy > ptFix.m_fy)
	{
		ptMove.m_fy	= ptFix.m_fy + n;
		ptY.m_fy		= ptFix.m_fy + n;
	}
	else if (point.m_fy < ptFix.m_fy)
	{
		ptMove.m_fy	= ptFix.m_fy - n;
		ptY.m_fy		= ptFix.m_fy - n;
	}
}

int CRectRoiTracker::GetPoint(LPINFO_POINT pPoint, int nLen)
{
	if (FALSE == IsInit())
	{
		return -1;
	}
	else
	{
		if (NULL == pPoint || RECT_POINT_COUNT > nLen)
			return RECT_POINT_COUNT;
	}

	int idx = 0;

	pPoint[idx] = m_PointSrc[TYPE_HITROI_TOPLEFT];		idx++;
	pPoint[idx] = m_PointSrc[TYPE_HITROI_TOPRIGHT];		idx++;
	pPoint[idx] = m_PointSrc[TYPE_HITROI_BOTTOMRIGHT];	idx++;
	pPoint[idx] = m_PointSrc[TYPE_HITROI_BOTTOMLEFT];	idx++;

	return RECT_POINT_COUNT;
}

int CRectRoiTracker::SetPoint(const LPINFO_POINT pPoint, const int nLen, float fZoom, BOOL bErase)
{
	if (NULL == pPoint || RECT_POINT_COUNT > nLen)
		return RECT_POINT_COUNT;

	int idx = 0;

	INFO_POINT PointZoom[RECT_POINT_COUNT];
	ConvertPointPixelToDraw(pPoint, PointZoom, RECT_POINT_COUNT, fZoom);

	m_PointDest[TYPE_HITROI_TOPLEFT / 2]	= PointZoom[idx];	idx++;
	m_PointDest[TYPE_HITROI_TOPRIGHT / 2]	= PointZoom[idx];	idx++;
	m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2]= PointZoom[idx];	idx++;
	m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2] = PointZoom[idx];	idx++;

	OnEndTrack(TYPE_RESULTROI_SUCCEEDED, fZoom, bErase);

	return RECT_POINT_COUNT;
}


BOOL CRectRoiTracker::SetWidth(DWORD dwWidth)
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
		pPointList[TYPE_HITROI_TOPRIGHT / 2].m_fx = pPointList[TYPE_HITROI_TOPLEFT / 2].m_fx + dwWidth;
		pPointList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = pPointList[TYPE_HITROI_BOTTOMLEFT / 2].m_fx + dwWidth;

		SetPoint(pPointList, nLen, 1.0f);
	}

	delete[] pPointList;
	return TRUE;
}

BOOL CRectRoiTracker::SetHeight(DWORD dwHeight)
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
		pPointList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = pPointList[TYPE_HITROI_TOPLEFT / 2].m_fy + dwHeight;
		pPointList[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = pPointList[TYPE_HITROI_TOPRIGHT / 2].m_fy + dwHeight;

		SetPoint(pPointList, nLen, 1.0f);
	}

	delete[] pPointList;
	return TRUE;
}

BOOL CRectRoiTracker::MovePoint(int cx, int cy)
{
	if (FALSE == IsInit())
		return FALSE;

	for (int i = 0; i < ROIRECT_POINT_COUNT; i++)
	{
		m_PointSrc[i].m_fx += cx;
		m_PointSrc[i].m_fy += cy;
	}
	return TRUE;
}