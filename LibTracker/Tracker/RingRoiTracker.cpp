#include "stdafx.h"
#include "RingRoiTracker.h"

#include "RoiTrackerDC.h"

#include "../Common/Tracker/VideoOutArrow.h"

#include <cmath>


CRingRoiTracker::CRingRoiTracker(CWnd* pWnd)
	: CRoiTracker(pWnd)
{
	m_bInit = FALSE;

	m_eHitRoi = TYPE_HITROI_NONE;
	m_eTransformRoi = TYPE_TRANSFORMROI_NONE;

	memset(m_PointSrc, 0x00, sizeof(INFO_POINT)*ROIRING_POINT_COUNT);
	memset(m_PointDest, 0x00, sizeof(INFO_POINT)*RING_POINT_COUNT);

	memset(m_hCur, 0x00, sizeof(HCURSOR)*ROIRING_POINT_COUNT);

	m_rgbTrack = RGB(0, 0, 0);
	m_rgbRoiRect = RGB(0, 0, 0);
	m_rgbRoiRing = RGB(0, 0, 0);


	UINT CursorIDs[] =
	{
		AFX_IDC_TRACKNWSE,
		AFX_IDC_TRACKNS,
		AFX_IDC_TRACKNESW,
		AFX_IDC_TRACKWE,
		AFX_IDC_MOVE4WAY,
	};

	for (int i = 0; i < ROIRING_POINT_COUNT; i++)
	{
		m_hCur[i] = ::AfxGetApp()->LoadCursor(CursorIDs[i]);
	}

	m_pTrackRing = NULL;
}

CRingRoiTracker::~CRingRoiTracker()
{
	for (int i = 0; i < ROIRING_POINT_COUNT; i++)
	{
		if (m_hCur[i])
		{
			::DestroyCursor(m_hCur[i]);
		}
	}

	if (m_pTrackRing)
		delete[] m_pTrackRing;
	m_pTrackRing = NULL;
}

void CRingRoiTracker::Clear()
{
	m_bInit = FALSE;

	m_eHitRoi = TYPE_HITROI_NONE;
	m_eTransformRoi = TYPE_TRANSFORMROI_NONE;

	memset(m_PointSrc, 0x00, sizeof(INFO_POINT)*ROIRING_POINT_COUNT);
	memset(m_PointDest, 0x00, sizeof(INFO_POINT)*ROIRING_POINT_COUNT);

	if (m_pTrackRing)
		delete[] m_pTrackRing;
	m_pTrackRing = NULL;

	Invalidate();
}

//
BOOL CRingRoiTracker::IsInit()
{
	return m_bInit;
}

void CRingRoiTracker::Draw(CDC* pDC, float fZoom)
{
	if (NULL == pDC)
		return;

	int nOldRop = pDC->SetROP2(R2_NOTXORPEN);

	DrawRoiRing(pDC, fZoom);

	pDC->SetROP2(nOldRop);
}

void CRingRoiTracker::DrawRoi(CDC* pDC, INFO_SIZE stSize, float fZoom, void* pReserved)
{
	if (NULL == pDC || FALSE == IsInit())
		return;

	BOOL bDrawForFile = FALSE;
	if (pReserved)
	{
		INFO_RESERVED* pstReserved = (INFO_RESERVED*)pReserved;
		bDrawForFile = pstReserved->m_bDrawForFile;
	}

	INFO_POINT PointZoom[ROIRING_POINT_COUNT];
	memset(PointZoom, 0x00, sizeof(INFO_POINT)*ROIRING_POINT_COUNT);
	ConvertPointPixelToDrawForRoi(m_PointSrc, PointZoom, ROIRING_POINT_COUNT, stSize, fZoom, bDrawForFile);


	const INFO_POINT ptCenter = PointZoom[TYPE_HITROI_CENTER / 2];

	const double outR = GetRadious(ptCenter, PointZoom[TYPE_HITROI_TOPRIGHT / 2]);
	const double inR = GetRadious(ptCenter, PointZoom[TYPE_HITROI_TOPLEFT / 2]);

	// ROI Inner Line - Edge
	DrawRoiEdgeLine(pDC, stSize, PointZoom, fZoom, pReserved);


	INFO_RECT rtArc;
	INFO_POINT ptStart;
	INFO_POINT ptEnd;

	// Draw Outter Arc
	rtArc.m_fleft = ptCenter.m_fx - outR;
	rtArc.m_ftop = ptCenter.m_fy - outR;
	rtArc.m_fright = ptCenter.m_fx + outR;
	rtArc.m_fbottom = ptCenter.m_fy + outR;

	ptStart = PointZoom[TYPE_HITROI_TOPRIGHT / 2];
	ptEnd = PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2];

	DrawArc(pDC, rtArc, ptStart, ptEnd);

	// Draw Inner Arc
	rtArc.m_fleft = ptCenter.m_fx - inR;
	rtArc.m_ftop = ptCenter.m_fy - inR;
	rtArc.m_fright = ptCenter.m_fx + inR;
	rtArc.m_fbottom = ptCenter.m_fy + inR;

	ptStart = PointZoom[TYPE_HITROI_TOPLEFT / 2];
	ptEnd = PointZoom[TYPE_HITROI_BOTTOMLEFT / 2];

	DrawArc(pDC, rtArc, ptStart, ptEnd);
	


	// Draw Line
	this->DrawLine(pDC, PointZoom[TYPE_HITROI_TOPLEFT / 2], PointZoom[TYPE_HITROI_TOPRIGHT / 2]);

	if (PointZoom[TYPE_HITROI_TOPRIGHT / 2].m_fx == PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx &&
		PointZoom[TYPE_HITROI_TOPRIGHT / 2].m_fy == PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy)
	{
		// do not draw line...
	}
	else
	{
		this->DrawLine(pDC, PointZoom[TYPE_HITROI_BOTTOMLEFT / 2], PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2]);
	}
}

void CRingRoiTracker::DrawRoiEdgeLine(CDC* pDC, INFO_SIZE stSize, LPINFO_POINT pPointList, float fZoom, void* pReserved)
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
		TYPE_DIRECT_CW,			// ClockWise
		TYPE_DIRECT_CCW,		// CounterClockWise

		} TYPE_DIRECT;
		//*/

		if (!(5 == pstReserved->m_dwDirection || 6 == pstReserved->m_dwDirection || 7 == pstReserved->m_dwDirection || 8 == pstReserved->m_dwDirection))
			return;


		double w = stSize.m_fcx;
		double h = stSize.m_fcy;

		CDC maskDC;
		maskDC.CreateCompatibleDC(pDC);
		maskDC.SelectObject(pstReserved->m_hInLine);
		if (pstReserved->m_hInBrush)
			maskDC.SelectObject(pstReserved->m_hInBrush);

		VOID *pvBits = NULL;;          // pointer to DIB section
		HBITMAP hBitmap = CreateEdgeBitmap(maskDC.m_hDC, (int)w, (int)h, &pvBits);
		HBITMAP hOldBitmap = (HBITMAP)::SelectObject(maskDC.m_hDC, hBitmap);

		const INFO_POINT ptCenter = pPointList[TYPE_HITROI_CENTER / 2];

		const double outR = GetRadious(ptCenter, pPointList[TYPE_HITROI_TOPRIGHT / 2]);
		const double inR = GetRadious(ptCenter, pPointList[TYPE_HITROI_TOPLEFT / 2]);

		ARROWSTRUCT stArrow;
		stArrow.nWidth = (int)(ARROWWIDTH * fZoom);
		stArrow.fTheta = 0.3f;
		stArrow.bFill = TRUE;

		if (5 == pstReserved->m_dwDirection || 6 == pstReserved->m_dwDirection)	// TYPE_DIRECT_IN2OUT, TYPE_DIRECT_OUT2IN
		{
			const int nStep = pstReserved->m_dwStep;

			int nStart = (int)GetAngle(pPointList[TYPE_HITROI_BOTTOMRIGHT / 2], ptCenter, TRUE);
			int nEnd = (int)GetAngle(pPointList[TYPE_HITROI_TOPRIGHT / 2], ptCenter, TRUE);
			if (nStart == nEnd)
				nEnd += 360;
			else if (0 > nEnd || nStart > nEnd)
				nEnd += 360;

			INFO_POINT pt1;
			INFO_POINT pt2;

			int nIdx = 0;

			for (int i = nStart; i < nEnd; i += nStep)
			{
				pt1 = ptCenter;
				pt2 = ptCenter;

				pt1.m_fx += (inR * cos(i * 2 * VALUE_PI / 360));
				pt1.m_fy += (inR * sin(i * 2 * VALUE_PI / 360));

				pt2.m_fx += (outR * cos(i * 2 * VALUE_PI / 360));
				pt2.m_fy += (outR * sin(i * 2 * VALUE_PI / 360));

				if (0 == nIdx % 2)
				{
					double x1 = pt1.m_fx;
					double y1 = pt1.m_fy;
					double x2 = pt2.m_fx;
					double y2 = pt2.m_fy;

					if (6 == pstReserved->m_dwDirection)	// TYPE_DIRECT_OUT2IN
					{
						x1 = pt2.m_fx;
						y1 = pt2.m_fy;
						x2 = pt1.m_fx;
						y2 = pt1.m_fy;
					}
					::MoveToEx(maskDC.m_hDC, (int)x1, (int)y1, NULL);
					ArrowTo(maskDC.m_hDC, (int)x2, (int)y2, &stArrow);
				}
				else
				{
					maskDC.MoveTo((int)pt1.m_fx, (int)pt1.m_fy);
					maskDC.LineTo((int)pt2.m_fx, (int)pt2.m_fy);
				}
				nIdx++;
			}
		}
		else if (7 == pstReserved->m_dwDirection || 8 == pstReserved->m_dwDirection)	// TYPE_DIRECT_CW, TYPE_DIRECT_CCW
		{
			double nStep = (pstReserved->m_dwStep * fZoom);
			if (1.0f > nStep)
				nStep = 1.0f;

			int nStart = (int)GetAngle(pPointList[TYPE_HITROI_BOTTOMRIGHT / 2], ptCenter, TRUE);
			int nEnd = (int)GetAngle(pPointList[TYPE_HITROI_TOPRIGHT / 2], ptCenter, TRUE);
			if (nStart == nEnd)
				nEnd += 360;
			else if (0 > nEnd || nStart > nEnd)
				nEnd += 360;

			const double fStart = nStart * (VALUE_PI / 180);
			const double fEnd = nEnd * (VALUE_PI / 180);

			INFO_RECT rtArc;
			INFO_POINT ptStart;
			INFO_POINT ptEnd;

			int nIdx = 0;

			for (double i = inR; i < outR; i += nStep)
			{
				rtArc.m_fleft = ptCenter.m_fx - i;
				rtArc.m_ftop = ptCenter.m_fy - i;
				rtArc.m_fright = ptCenter.m_fx + i;
				rtArc.m_fbottom = ptCenter.m_fy + i;

				ptStart.m_fx = (i * cos(fStart) + ptCenter.m_fx);
				ptStart.m_fy = (i * sin(fStart) + ptCenter.m_fy);
				ptEnd.m_fx = (i * cos(fEnd) + ptCenter.m_fx);
				ptEnd.m_fy = (i * sin(fEnd) + ptCenter.m_fy);

				DrawArc(&maskDC, rtArc, ptEnd, ptStart);

				if (0 == nIdx % 2)	// Arrow
				{
					INFO_POINT ptTemp;
					int nArrowLen = (int)(ARROWWIDTH * fZoom);
					if (1 > nArrowLen)
						nArrowLen = ARROWWIDTH;

					if (7 == pstReserved->m_dwDirection)		// TYPE_DIRECT_CW
					{
						ptTemp.m_fx = (ptEnd.m_fx - nArrowLen * cos(fEnd + VALUE_PI / 2));
						ptTemp.m_fy = (ptEnd.m_fy - nArrowLen * sin(fEnd + VALUE_PI / 2));

						::MoveToEx(maskDC.m_hDC, (int)ptTemp.m_fx, (int)ptTemp.m_fy, NULL);
						ArrowTo(maskDC.m_hDC, (int)ptEnd.m_fx, (int)ptEnd.m_fy, &stArrow);
					}
					else if (8 == pstReserved->m_dwDirection)	// TYPE_DIRECT_CCW
					{
						ptTemp.m_fx = (ptStart.m_fx + nArrowLen * cos(fStart + VALUE_PI / 2));
						ptTemp.m_fy = (ptStart.m_fy + nArrowLen * sin(fStart + VALUE_PI / 2));

						::MoveToEx(maskDC.m_hDC, (int)ptTemp.m_fx, (int)ptTemp.m_fy, NULL);
						ArrowTo(maskDC.m_hDC, (int)ptStart.m_fx, (int)ptStart.m_fy, &stArrow);
					}
				}
				nIdx++;
			}
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
		::AlphaBlend(pDC->m_hDC, 0, 0, (int)w, (int)h, maskDC.m_hDC, 0, 0, (int)w, (int)h, bf);

		::SelectObject(maskDC.m_hDC, hOldBitmap);
		if (hBitmap)
			::DeleteObject(hBitmap);
		maskDC.DeleteDC();
	}
	pDC->SelectObject(pstReserved->m_hOutLine);

}

void CRingRoiTracker::DrawRoiRing(CDC* pDC, float fZoom)
{
	if (pDC && IsInit())
	{
		CGdiObject * pOldPen = NULL;

		INFO_POINT PointZoom[ROIRING_POINT_COUNT];
		memset(PointZoom, 0x00, sizeof(INFO_POINT)*ROIRING_POINT_COUNT);
		ConvertPointPixelToDraw(m_PointSrc, PointZoom, ROIRING_POINT_COUNT, fZoom);

		///
		{
			CPen* pCirclePen = new CPen(PS_SOLID, 1, m_rgbRoiRing);
			pOldPen = pDC->SelectObject(pCirclePen);
			CGdiObject * pOldBrush = pDC->SelectStockObject(NULL_BRUSH);

			const INFO_POINT ptCenter = PointZoom[TYPE_HITROI_CENTER / 2];

			const double outR = GetRadious(ptCenter, PointZoom[TYPE_HITROI_TOPRIGHT / 2]);
			const double inR = GetRadious(ptCenter, PointZoom[TYPE_HITROI_TOPLEFT / 2]);

			INFO_RECT rtArc;
			INFO_POINT ptStart;
			INFO_POINT ptEnd;

			// Draw Outter Arc
			rtArc.m_fleft = ptCenter.m_fx - outR;
			rtArc.m_ftop = ptCenter.m_fy - outR;
			rtArc.m_fright = ptCenter.m_fx + outR;
			rtArc.m_fbottom = ptCenter.m_fy + outR;

			ptStart = PointZoom[TYPE_HITROI_TOPRIGHT / 2];
			ptEnd = PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2];
			
			DrawArc(pDC, rtArc, ptStart, ptEnd);

			// Draw Inner Arc
			rtArc.m_fleft = ptCenter.m_fx - inR;
			rtArc.m_ftop = ptCenter.m_fy - inR;
			rtArc.m_fright = ptCenter.m_fx + inR;
			rtArc.m_fbottom = ptCenter.m_fy + inR;

			ptStart = PointZoom[TYPE_HITROI_TOPLEFT / 2];
			ptEnd = PointZoom[TYPE_HITROI_BOTTOMLEFT / 2];

			DrawArc(pDC, rtArc, ptStart, ptEnd);


			// Draw Line
			this->DrawLine(pDC, PointZoom[TYPE_HITROI_TOPLEFT / 2], PointZoom[TYPE_HITROI_TOPRIGHT / 2]);

			if (PointZoom[TYPE_HITROI_TOPRIGHT / 2].m_fx == PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx &&
				PointZoom[TYPE_HITROI_TOPRIGHT / 2].m_fy == PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy)
			{
				// do not draw line...
			}
			else
			{
				this->DrawLine(pDC, PointZoom[TYPE_HITROI_BOTTOMLEFT / 2], PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2]);
			}

			pDC->SelectObject(pOldPen);
			pDC->SelectObject(pOldBrush);

			delete pCirclePen;
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
				if (TYPE_HITROI_TOP == i || TYPE_HITROI_BOTTOM == i || 
					TYPE_HITROI_LEFT == i || TYPE_HITROI_RIGHT == i )
				{
					continue;
				}

				INFO_RECT rect = GetHitRect((TYPE_HITROI)i, fZoom);

				if (TYPE_HITROI_BOTTOMLEFT == i)
				{
					CPoint pt1((int)PointZoom[TYPE_HITROI_TOPLEFT / 2].m_fx, (int)PointZoom[TYPE_HITROI_TOPLEFT / 2].m_fy);
					CPoint pt2((int)PointZoom[TYPE_HITROI_BOTTOMLEFT / 2].m_fx, (int)PointZoom[TYPE_HITROI_BOTTOMLEFT / 2].m_fy);
					
					if (pt1 == pt2)
						continue;
				}
				else if (TYPE_HITROI_BOTTOMRIGHT == i)
				{
					CPoint pt1((int)PointZoom[TYPE_HITROI_TOPRIGHT / 2].m_fx, (int)PointZoom[TYPE_HITROI_TOPRIGHT / 2].m_fy);
					CPoint pt2((int)PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx, (int)PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy);

					if (pt1 == pt2)
						continue;
				}

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

void CRingRoiTracker::DrawTracker(CDC* pDC, INFO_POINT pt1, INFO_POINT pt2, float fZoom, BOOL bDone)
{
	if (NULL == pDC || FALSE == IsInit())
		return;

	const int x = GetHScrollPos();
	const int y = GetVScrollPos();

	if (bDone && m_pTrackRing)
	{
		INFO_POINT PointZoom[ROIRING_POINT_COUNT];
		memset(PointZoom, 0x00, sizeof(POINT)*ROIRING_POINT_COUNT);
		ConvertPointDrawToPixel(m_pTrackRing, PointZoom, ROIRING_POINT_COUNT, fZoom);

		m_PointSrc[TYPE_HITROI_CENTER / 2] = PointZoom[TYPE_HITROI_CENTER / 2];

		m_PointSrc[TYPE_HITROI_TOPLEFT / 2] = PointZoom[TYPE_HITROI_TOPLEFT / 2];
		m_PointSrc[TYPE_HITROI_TOPRIGHT / 2] = PointZoom[TYPE_HITROI_TOPRIGHT / 2];
		m_PointSrc[TYPE_HITROI_BOTTOMRIGHT / 2] = PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2];
		m_PointSrc[TYPE_HITROI_BOTTOMLEFT / 2] = PointZoom[TYPE_HITROI_BOTTOMLEFT / 2];


		const int nStart = (int)GetAngle(m_PointSrc[TYPE_HITROI_BOTTOMRIGHT / 2], m_PointSrc[TYPE_HITROI_BOTTOMLEFT / 2], TRUE);
		const int nEnd = (int)GetAngle(m_PointSrc[TYPE_HITROI_TOPRIGHT / 2], m_PointSrc[TYPE_HITROI_TOPLEFT / 2], TRUE);
		if (MATCH_MARGIN >= std::abs(nStart - nEnd))
		{
			m_PointSrc[TYPE_HITROI_TOPRIGHT / 2].m_fx = m_PointSrc[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx;
			m_PointSrc[TYPE_HITROI_TOPRIGHT / 2].m_fy = m_PointSrc[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy;

			m_PointSrc[TYPE_HITROI_TOPLEFT / 2].m_fx = m_PointSrc[TYPE_HITROI_BOTTOMLEFT / 2].m_fx;
			m_PointSrc[TYPE_HITROI_TOPLEFT / 2].m_fy = m_PointSrc[TYPE_HITROI_BOTTOMLEFT / 2].m_fy;
		}

		delete[] m_pTrackRing;
		m_pTrackRing = NULL;

		return;
	}

	CRoiTrackerDC* pRDC = new CRoiTrackerDC(pDC, NOTSRCINVERT);
	pRDC->SetROP2(R2_NOTXORPEN);

	INFO_POINT pPt[RING_POINT_COUNT];
	pPt[TYPE_HITROI_TOPLEFT / 2] = GetTrackerPointFromSrc(m_PointSrc[TYPE_HITROI_TOPLEFT / 2], fZoom);
	pPt[TYPE_HITROI_TOPRIGHT / 2] = GetTrackerPointFromSrc(m_PointSrc[TYPE_HITROI_TOPRIGHT / 2], fZoom);
	pPt[TYPE_HITROI_BOTTOMRIGHT / 2] = GetTrackerPointFromSrc(m_PointSrc[TYPE_HITROI_BOTTOMRIGHT / 2], fZoom);
	pPt[TYPE_HITROI_BOTTOMLEFT / 2] = GetTrackerPointFromSrc(m_PointSrc[TYPE_HITROI_BOTTOMLEFT / 2], fZoom);
	pPt[TYPE_HITROI_CENTER / 2] = GetTrackerPointFromSrc(m_PointSrc[TYPE_HITROI_CENTER / 2], fZoom);

	if (NULL == m_pTrackRing)
	{
		m_pTrackRing = new INFO_POINT[RING_POINT_COUNT];
		for (int i = 0; i < RING_POINT_COUNT; i++)
		{
			m_pTrackRing[i] = pPt[i];
		}
	}
	else
	{
		DrawTrackRing(pRDC, m_pTrackRing, RING_POINT_COUNT);
	}

	pPt[TYPE_HITROI_TOPLEFT / 2] = GetTrackerPointFromSrc(m_PointSrc[TYPE_HITROI_TOPLEFT / 2], pt1, pt2, fZoom);
	pPt[TYPE_HITROI_TOPRIGHT / 2] = GetTrackerPointFromSrc(m_PointSrc[TYPE_HITROI_TOPRIGHT / 2], pt1, pt2, fZoom);
	pPt[TYPE_HITROI_BOTTOMRIGHT / 2] = GetTrackerPointFromSrc(m_PointSrc[TYPE_HITROI_BOTTOMRIGHT / 2], pt1, pt2, fZoom);
	pPt[TYPE_HITROI_BOTTOMLEFT / 2] = GetTrackerPointFromSrc(m_PointSrc[TYPE_HITROI_BOTTOMLEFT / 2], pt1, pt2, fZoom);
	pPt[TYPE_HITROI_CENTER / 2] = GetTrackerPointFromSrc(m_PointSrc[TYPE_HITROI_CENTER / 2], pt1, pt2, fZoom);


	DrawTrackRing(pRDC, pPt, RING_POINT_COUNT);
	if (m_pTrackRing)
	{
		for (int i = 0; i < RING_POINT_COUNT; i++)
		{
			m_pTrackRing[i] = pPt[i];
		}
	}

	delete pRDC;
}

void CRingRoiTracker::DrawTrackRing(CDC* pDC, LPINFO_POINT pPtList, int nPtLen)
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


	const INFO_POINT ptCenter = pPtList[TYPE_HITROI_CENTER / 2];
	const double r = GetRadious(ptCenter, pPtList[TYPE_HITROI_TOPRIGHT / 2]);

	const double inR = GetRadious(ptCenter, pPtList[TYPE_HITROI_TOPLEFT / 2]);
	const double outR = GetRadious(ptCenter, pPtList[TYPE_HITROI_TOPRIGHT / 2]);

	INFO_RECT rtArc;
	INFO_POINT ptStart;
	INFO_POINT ptEnd;

	// Draw Outter Arc
	rtArc.m_fleft = ptCenter.m_fx - outR;
	rtArc.m_ftop = ptCenter.m_fy - outR;
	rtArc.m_fright = ptCenter.m_fx + outR;
	rtArc.m_fbottom = ptCenter.m_fy + outR;

	ptStart = pPtList[TYPE_HITROI_TOPRIGHT / 2];
	ptEnd = pPtList[TYPE_HITROI_BOTTOMRIGHT / 2];

	DrawArc(pDC, rtArc, ptStart, ptEnd);

	// Draw Inner Arc
	rtArc.m_fleft = ptCenter.m_fx - inR;
	rtArc.m_ftop = ptCenter.m_fy - inR;
	rtArc.m_fright = ptCenter.m_fx + inR;
	rtArc.m_fbottom = ptCenter.m_fy + inR;

	ptStart = pPtList[TYPE_HITROI_TOPLEFT / 2];
	ptEnd = pPtList[TYPE_HITROI_BOTTOMLEFT / 2];

	DrawArc(pDC, rtArc, ptStart, ptEnd);


	// Draw Line
	this->DrawLine(pDC, pPtList[TYPE_HITROI_TOPLEFT / 2], pPtList[TYPE_HITROI_TOPRIGHT / 2]);

	if (pPtList[TYPE_HITROI_TOPRIGHT / 2].m_fx == pPtList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx &&
		pPtList[TYPE_HITROI_TOPRIGHT / 2].m_fy == pPtList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy)
	{
		// do not draw line...
	}
	else
	{
		this->DrawLine(pDC, pPtList[TYPE_HITROI_BOTTOMLEFT / 2], pPtList[TYPE_HITROI_BOTTOMRIGHT / 2]);
	}

	pDC->SelectObject(pOldPen);
	delete pTrackPen;
}


TYPE_HITROI CRingRoiTracker::HitTest(INFO_POINT point, float fZoom)
{
	TYPE_HITROI eHitRoi = TYPE_HITROI_NONE;
	if (FALSE == IsInit())
		return eHitRoi;

#if 1
	TYPE_HITROI pHitArray[RING_POINT_COUNT] = { TYPE_HITROI_TOPRIGHT, TYPE_HITROI_BOTTOMRIGHT, TYPE_HITROI_TOPLEFT, TYPE_HITROI_BOTTOMLEFT, TYPE_HITROI_CENTER };
	BOOL bFound = FALSE;
	int i = TYPE_HITROI_BODY;
	for (int r = 0; r < RING_POINT_COUNT; r++)
	{
		INFO_RECT rect = GetHitRect(pHitArray[r], fZoom);
		if (TRUE == CheckPointInRect(rect, point, fZoom))
		{
			i = pHitArray[r];
			break;
		}
	}
#else
	int i = 0;
	for (i = 0; i < TYPE_HITROI_BODY; i++)
	{
		if (TYPE_HITROI_TOP == i || TYPE_HITROI_BOTTOM == i || 
			TYPE_HITROI_LEFT == i || TYPE_HITROI_RIGHT == i)
		{
			continue;
		}

		INFO_RECT rect = GetHitRect((TYPE_HITROI)i, fZoom);
		if (TRUE == CheckPointInRect(rect, point, fZoom))
		{
			break;
		}
	}
#endif
	eHitRoi = (TYPE_HITROI)i;

	if (TYPE_HITROI_BODY <= i)
	{
		eHitRoi = TYPE_HITROI_NONE;

		eHitRoi = HitLineTest(point, TYPE_HITROI_TOPLEFT, TYPE_HITROI_TOPRIGHT, fZoom);
		if (TYPE_HITROI_NONE != eHitRoi)
		{
			return TYPE_HITROI_LINE_TOPANGLE;
		}

		eHitRoi = HitLineTest(point, TYPE_HITROI_BOTTOMLEFT, TYPE_HITROI_BOTTOMRIGHT, fZoom);
		if (TYPE_HITROI_NONE != eHitRoi)
		{
			return TYPE_HITROI_LINE_BOTTOMANGLE;
		}

		{
			const int x = GetHScrollPos();
			const int y = GetVScrollPos();
			
			INFO_POINT ptCur;
			ptCur.m_fx = ((point.m_fx + x) / fZoom);
			ptCur.m_fy = ((point.m_fy + y) / fZoom);


			INFO_POINT ptCenter = m_PointSrc[TYPE_HITROI_CENTER / 2];
			
			double nTemp = GetAngle(ptCenter, m_PointSrc[TYPE_HITROI_TOPLEFT / 2], TRUE) + 180;
			const double nStart = this->GetRemainder(nTemp, 360.f);// nTemp % 360.f;

			nTemp = GetAngle(ptCenter, m_PointSrc[TYPE_HITROI_BOTTOMLEFT / 2], TRUE) + 180;
			const double nEnd = this->GetRemainder(nTemp, 360.f);//nTemp % 360.f;

			nTemp = GetAngle(ptCenter, ptCur, TRUE) + 180;
			const double nCurAngle = this->GetRemainder(nTemp, 360.f);//nTemp % 360.f;
			

			if ( (nStart == nEnd) || 
				(nStart > nEnd && nEnd < nCurAngle && nStart > nCurAngle) ||
				(nStart < nEnd && !(nStart <= nCurAngle && nEnd >= nCurAngle)))
			{
				const int x = GetHScrollPos();
				const int y = GetVScrollPos();


				const double nOutR = GetRadious(ptCenter, m_PointSrc[TYPE_HITROI_TOPRIGHT / 2]);
				const double nInR = GetRadious(ptCenter, m_PointSrc[TYPE_HITROI_TOPLEFT / 2]);
				const double nCurR = GetRadious(ptCenter, ptCur);

				if ((nOutR - VALUE_INFLATE) < nCurR && (nOutR + VALUE_INFLATE) > nCurR)
				{
					return TYPE_HITROI_LINE_OUTER;
				}
				else if ((nInR - VALUE_INFLATE) < nCurR && (nInR + VALUE_INFLATE) > nCurR)
				{
					return TYPE_HITROI_LINE_INNER;
				}


			}
		}
	}

	return eHitRoi;
}

TYPE_HITROI CRingRoiTracker::HitLineTest(INFO_POINT point, TYPE_HITROI eStart, TYPE_HITROI eEnd, float fZoom)
{
	const int x = GetHScrollPos();
	const int y = GetVScrollPos();

	point.m_fx = ((point.m_fx + x) / fZoom);
	point.m_fy = ((point.m_fy + y) / fZoom);

	INFO_POINT stStart = GetHitPoint(m_PointSrc, eStart);
	INFO_POINT stEnd = GetHitPoint(m_PointSrc, eEnd);

	return HitTest(point, stStart, stEnd, fZoom);
}

TYPE_HITROI CRingRoiTracker::HitTest(INFO_POINT point, INFO_POINT stStart, INFO_POINT stEnd, float fZoom)
{
	const double fPhi = GetAngle(stStart, stEnd, TRUE);
	
	// Transform
	m_Transform.Reset();
	m_Transform.Translate((REAL)-stStart.m_fx, (REAL)-stStart.m_fy);
	m_Transform.Rotate( (REAL)(fPhi*-1), MatrixOrderAppend);
	
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


INFO_RECT CRingRoiTracker::GetHitRect(TYPE_HITROI eHit, float fZoom)
{
	if (NULL == m_pWnd)
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

INFO_POINT CRingRoiTracker::GetHitPoint(LPINFO_POINT pPoint, TYPE_HITROI eHit)
{
	// Handles are numbered clockwise, like this:
	// 
	// Draw arc, counterclockwise.
	//
	//			0		   1
	//			*----------*
	//	*4
	//			3		   2
	//			*----------*
	//
	// The center point is handle 4

	int idx = (int)eHit/2;
	if (TYPE_HITROI_CENTER / 2 < idx)
		idx = TYPE_HITROI_CENTER / 2;

	INFO_POINT pnt = pPoint[idx];
	return pnt;
}

TYPE_RESULTROI CRingRoiTracker::OnBeginTrack(UINT nFlags, INFO_POINT point, float fZoom)
{
	m_eHitRoi = HitTest(point, fZoom);

	if (TYPE_HITROI_NONE == m_eHitRoi)
	{
		m_eTransformRoi = TYPE_TRANSFORMROI_CREATE;

		for (int i = 0; i < RING_POINT_COUNT; i++)
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
		INFO_POINT PointZoom[ROIRING_POINT_COUNT];
		memset(PointZoom, 0x00, sizeof(INFO_POINT)*ROIRING_POINT_COUNT);
		ConvertPointPixelToDraw(m_PointSrc, PointZoom, ROIRING_POINT_COUNT, fZoom);

		m_PointDest[TYPE_HITROI_TOPLEFT / 2] = PointZoom[TYPE_HITROI_TOPLEFT / 2];
		m_PointDest[TYPE_HITROI_TOPRIGHT / 2] = PointZoom[TYPE_HITROI_TOPRIGHT / 2];
		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2] = PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2];
		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2] = PointZoom[TYPE_HITROI_BOTTOMLEFT / 2];

		m_PointDest[TYPE_HITROI_CENTER / 2] = PointZoom[TYPE_HITROI_CENTER / 2];
	}

	return TYPE_RESULTROI_CONTINUE;
}

TYPE_RESULTROI CRingRoiTracker::OnEndTrack(TYPE_RESULTROI eResult, float fZoom, BOOL bErase)
{
	if (TYPE_RESULTROI_SUCCEEDED == eResult)
	{
		SetInitState(TRUE);

		INFO_POINT PointZoom[ROIRING_POINT_COUNT];
		memset(PointZoom, 0x00, sizeof(INFO_POINT)*ROIRING_POINT_COUNT);
		ConvertPointDrawToPixel(m_PointDest, PointZoom, ROIRING_POINT_COUNT, fZoom);

		m_PointSrc[TYPE_HITROI_CENTER / 2] = PointZoom[TYPE_HITROI_CENTER / 2];

		m_PointSrc[TYPE_HITROI_TOPLEFT / 2] = PointZoom[TYPE_HITROI_TOPLEFT / 2];
		m_PointSrc[TYPE_HITROI_TOPRIGHT / 2] = PointZoom[TYPE_HITROI_TOPRIGHT / 2];
		m_PointSrc[TYPE_HITROI_BOTTOMRIGHT / 2] = PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2];
		m_PointSrc[TYPE_HITROI_BOTTOMLEFT / 2] = PointZoom[TYPE_HITROI_BOTTOMLEFT / 2];


		const int nStart = (int)GetAngle(m_PointSrc[TYPE_HITROI_BOTTOMRIGHT / 2], m_PointSrc[TYPE_HITROI_BOTTOMLEFT / 2], TRUE);
		const int nEnd = (int)GetAngle(m_PointSrc[TYPE_HITROI_TOPRIGHT / 2], m_PointSrc[TYPE_HITROI_TOPLEFT / 2], TRUE);
		if (MATCH_MARGIN >= std::abs(nStart - nEnd))
		{
			m_PointSrc[TYPE_HITROI_TOPRIGHT / 2].m_fx = m_PointSrc[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx;
			m_PointSrc[TYPE_HITROI_TOPRIGHT / 2].m_fy = m_PointSrc[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy;

			m_PointSrc[TYPE_HITROI_TOPLEFT / 2].m_fx = m_PointSrc[TYPE_HITROI_BOTTOMLEFT / 2].m_fx;
			m_PointSrc[TYPE_HITROI_TOPLEFT / 2].m_fy = m_PointSrc[TYPE_HITROI_BOTTOMLEFT / 2].m_fy;
		}

	}
	
	if (bErase)
	{
		Invalidate();
	}

	m_eTransformRoi = TYPE_TRANSFORMROI_NONE;

	return eResult;
}

TYPE_RESULTROI CRingRoiTracker::OnMouseMessage(UINT msg, UINT nFlags, INFO_POINT point, float fZoom)
{
	// 0: TopLeft
	// 1: TopRight
	// 2: BottomRight
	// 3: BottomLeft
	// 4: Center
	//  TYPE_HITROI_LINE_INNER = 14,
	//	TYPE_HITROI_LINE_OUTER = 15,
	//	TYPE_HITROI_LINE_TOPANGLE = 16,
	//	TYPE_HITROI_LINE_BOTTOMANGLE = 17,
			
	if (TYPE_TRANSFORMROI_CREATE == m_eTransformRoi)
	{
		const double r = GetRadious(m_PointDest[TYPE_HITROI_CENTER / 2], point);

		m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fx = m_PointDest[TYPE_HITROI_CENTER / 2].m_fx + r;
		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = m_PointDest[TYPE_HITROI_CENTER / 2].m_fx + r;

		m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx = m_PointDest[TYPE_HITROI_CENTER / 2].m_fx + r / 2;
		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fx = m_PointDest[TYPE_HITROI_CENTER / 2].m_fx + r / 2;

	}
	else if (TYPE_TRANSFORMROI_SCALE == m_eTransformRoi)
	{
		INFO_POINT PointZoom[ROIRING_POINT_COUNT];
		memset(PointZoom, 0x00, sizeof(INFO_POINT)*ROIRING_POINT_COUNT);
		ConvertPointPixelToDraw(m_PointSrc, PointZoom, ROIRING_POINT_COUNT, fZoom);
	
		const INFO_POINT ptCenter = m_PointDest[TYPE_HITROI_CENTER / 2];

		//
		if (TYPE_HITROI_TOPRIGHT == m_eHitRoi || TYPE_HITROI_BOTTOMRIGHT == m_eHitRoi )
		{
			m_PointDest[m_eHitRoi / 2] = point;

			const double outR = GetRadious(ptCenter, point);
			REAL phi = (REAL)GetAngle(point, ptCenter);

			if (TYPE_HITROI_TOPRIGHT == m_eHitRoi)
			{
				const double inR = GetRadious(ptCenter, PointZoom[TYPE_HITROI_BOTTOMLEFT / 2]);
				
				m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx = (inR * cos(phi) + ptCenter.m_fx);
				m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy = (inR * sin(phi) + ptCenter.m_fy);

				phi = (REAL)GetAngle(PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2], ptCenter);
				m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = (outR * cos(phi) + ptCenter.m_fx);
				m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = (outR * sin(phi) + ptCenter.m_fy);
			}
			else if (TYPE_HITROI_BOTTOMRIGHT == m_eHitRoi)
			{
				const double inR = GetRadious(ptCenter, PointZoom[TYPE_HITROI_TOPLEFT / 2]);

				m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fx = (inR * cos(phi) + ptCenter.m_fx);
				m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = (inR * sin(phi) + ptCenter.m_fy);

				phi = (REAL)GetAngle(PointZoom[TYPE_HITROI_TOPRIGHT / 2], ptCenter);
				m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fx = (outR * cos(phi) + ptCenter.m_fx);
				m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fy = (outR * sin(phi) + ptCenter.m_fy);
			}
		}
		else if (TYPE_HITROI_TOPLEFT == m_eHitRoi || TYPE_HITROI_BOTTOMLEFT == m_eHitRoi)
		{
			m_PointDest[m_eHitRoi / 2] = point;

			const double inR = GetRadious(ptCenter, point);
			REAL phi = (REAL)GetAngle(point, ptCenter);

			if (TYPE_HITROI_TOPLEFT == m_eHitRoi)
			{
				const double outR = GetRadious(ptCenter, PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2]);

				m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fx = (outR * cos(phi) + ptCenter.m_fx);
				m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fy = (outR * sin(phi) + ptCenter.m_fy);

				phi = (REAL)GetAngle(PointZoom[TYPE_HITROI_BOTTOMLEFT / 2], ptCenter);
				m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fx = (inR * cos(phi) + ptCenter.m_fx);
				m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = (inR * sin(phi) + ptCenter.m_fy);
			}
			else if (TYPE_HITROI_BOTTOMLEFT == m_eHitRoi)
			{
				const double outR = GetRadious(ptCenter, PointZoom[TYPE_HITROI_TOPRIGHT / 2]);

				m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = (outR * cos(phi) + ptCenter.m_fx);
				m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = (outR * sin(phi) + ptCenter.m_fy);

				phi = (REAL)GetAngle(PointZoom[TYPE_HITROI_TOPLEFT / 2], ptCenter);
				m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx = (inR * cos(phi) + ptCenter.m_fx);
				m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy = (inR * sin(phi) + ptCenter.m_fy);
			}
		}

		// Change Radious
		else if (TYPE_HITROI_LINE_INNER == m_eHitRoi || TYPE_HITROI_LINE_OUTER == m_eHitRoi)
		{
			if (TYPE_HITROI_LINE_INNER == m_eHitRoi)
			{
				const double outR = GetRadious(ptCenter, m_PointDest[TYPE_HITROI_TOPRIGHT / 2]);
				double inR = GetRadious(ptCenter, point);

				if (2 < inR && outR > inR+2)
				{
					REAL phi = (REAL)GetAngle(PointZoom[TYPE_HITROI_TOPLEFT / 2], ptCenter);
					m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx = (inR * cos(phi) + ptCenter.m_fx);
					m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy = (inR * sin(phi) + ptCenter.m_fy);


					phi = (REAL)GetAngle(PointZoom[TYPE_HITROI_BOTTOMLEFT / 2], ptCenter);
					m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fx = (inR * cos(phi) + ptCenter.m_fx);
					m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = (inR * sin(phi) + ptCenter.m_fy);
				}
				else
				{
					// do nothing...
				}
			}
			else if (TYPE_HITROI_LINE_OUTER == m_eHitRoi)
			{
				const double inR = GetRadious(ptCenter, m_PointDest[TYPE_HITROI_TOPLEFT / 2]);
				double outR = GetRadious(ptCenter, point);

				if (inR+2 < outR)
				{
					REAL phi = (REAL)GetAngle(PointZoom[TYPE_HITROI_TOPRIGHT / 2], ptCenter);
					m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fx = (outR * cos(phi) + ptCenter.m_fx);
					m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fy = (outR * sin(phi) + ptCenter.m_fy);

					phi = (REAL)GetAngle(PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2], ptCenter);
					m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = (outR * cos(phi) + ptCenter.m_fx);
					m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = (outR * sin(phi) + ptCenter.m_fy);
				}
				else
				{
					// do nothing...
				}
			}
		}

		// Change Angle.
		if (TYPE_HITROI_LINE_TOPANGLE == m_eHitRoi || TYPE_HITROI_LINE_BOTTOMANGLE == m_eHitRoi)
		{
			REAL phi = (REAL)GetAngle(point, ptCenter);

			if (TYPE_HITROI_LINE_TOPANGLE == m_eHitRoi)
			{
				const double outR = GetRadious(ptCenter, m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2]);
				const double inR = GetRadious(ptCenter, m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2]);

				m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fx = (outR * cos(phi) + ptCenter.m_fx);
				m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fy = (outR * sin(phi) + ptCenter.m_fy);

				m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx = (inR * cos(phi) + ptCenter.m_fx);
				m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy = (inR * sin(phi) + ptCenter.m_fy);
			}
			else if (TYPE_HITROI_LINE_BOTTOMANGLE == m_eHitRoi)
			{
				const double outR = GetRadious(ptCenter, m_PointDest[TYPE_HITROI_TOPRIGHT / 2]);
				const double inR = GetRadious(ptCenter, m_PointDest[TYPE_HITROI_TOPLEFT / 2]);

				m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = (outR * cos(phi) + ptCenter.m_fx);
				m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = (outR * sin(phi) + ptCenter.m_fy);

				m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fx = (inR * cos(phi) + ptCenter.m_fx);
				m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = (inR * sin(phi) + ptCenter.m_fy);
			}
		}

	}
	else if (TYPE_TRANSFORMROI_MOVE == m_eTransformRoi)
	{
		const double w = m_stPoint.m_fx - m_stPreviousPoint.m_fx;
		const double h = m_stPoint.m_fy - m_stPreviousPoint.m_fy;

		for (int i = 0; i < RING_POINT_COUNT; i++)
		{
			m_PointDest[i].m_fx += w;
			m_PointDest[i].m_fy += h;
		}
	}

	return CRoiTracker::OnMouseMessage(msg, nFlags, point, fZoom);
}

TYPE_RESULTROI CRingRoiTracker::OnMessage(MSG& msg)
{
	TYPE_RESULTROI eResult = TYPE_RESULTROI_FAILED;
	return eResult;
}

void CRingRoiTracker::OnUpdate(CDC* pDC, UINT nMode, float fZoom)
{
	if (NULL == pDC)
		return;

	if (TYPE_TRANSFORMROI_NONE != m_eTransformRoi)
	{
		LOGBRUSH stLb;
		memset(&stLb, 0x00, sizeof(LOGBRUSH));
		stLb.lbColor = m_rgbTrack;
		stLb.lbHatch = 0;
		stLb.lbStyle = BS_SOLID;

		CPen* pTrackPen = new CPen(PS_COSMETIC | PS_ALTERNATE, 1, &stLb);
		CGdiObject * pOldPen = pDC->SelectObject(pTrackPen);


		const INFO_POINT ptCenter = m_PointDest[TYPE_HITROI_CENTER / 2];
		const double r = GetRadious(ptCenter, m_PointDest[TYPE_HITROI_TOPRIGHT / 2]);

		if (TYPE_TRANSFORMROI_CREATE == m_eTransformRoi)
		{
			RECT rtDraw;
			rtDraw.left = (long)(ptCenter.m_fx - r);
			rtDraw.top = (long)(ptCenter.m_fy - r);
			rtDraw.right = (long)(ptCenter.m_fx + r);
			rtDraw.bottom = (long)(ptCenter.m_fy + r);
			pDC->Ellipse(&rtDraw);

			rtDraw.left = (long)(ptCenter.m_fx - r / 2);
			rtDraw.top = (long)(ptCenter.m_fy - r / 2);
			rtDraw.right = (long)(ptCenter.m_fx + r / 2);
			rtDraw.bottom = (long)(ptCenter.m_fy + r / 2);
			pDC->Ellipse(&rtDraw);
		}
		else if (TYPE_TRANSFORMROI_MOVE == m_eTransformRoi || TYPE_TRANSFORMROI_SCALE == m_eTransformRoi)
		{
			double inR = 0;
			//if (TYPE_TRANSFORMROI_MOVE == m_eTransformRoi || (TYPE_HITROI_TOPLEFT == m_eHitRoi || TYPE_HITROI_BOTTOMLEFT == m_eHitRoi) )
				inR = GetRadious(ptCenter, m_PointDest[TYPE_HITROI_TOPLEFT / 2]);
			//else
			//	inR = GetRadious(ptCenter, m_PointSrc[TYPE_HITROI_TOPLEFT / 2]);

			const double outR = GetRadious(ptCenter, m_PointDest[TYPE_HITROI_TOPRIGHT / 2]);
			
			INFO_RECT rtArc;
			INFO_POINT ptStart;
			INFO_POINT ptEnd;

			// Draw Outter Arc
			rtArc.m_fleft = ptCenter.m_fx - outR;
			rtArc.m_ftop = ptCenter.m_fy - outR;
			rtArc.m_fright = ptCenter.m_fx + outR;
			rtArc.m_fbottom = ptCenter.m_fy + outR;

			ptStart = m_PointDest[TYPE_HITROI_TOPRIGHT / 2];
			ptEnd = m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2];

			DrawArc(pDC, rtArc, ptStart, ptEnd);

			// Draw Inner Arc
			rtArc.m_fleft = ptCenter.m_fx - inR;
			rtArc.m_ftop = ptCenter.m_fy - inR;
			rtArc.m_fright = ptCenter.m_fx + inR;
			rtArc.m_fbottom = ptCenter.m_fy + inR;

			ptStart = m_PointDest[TYPE_HITROI_TOPLEFT / 2];
			ptEnd = m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2];

			DrawArc(pDC, rtArc, ptStart, ptEnd);


			// Draw Line
			this->DrawLine(pDC, m_PointDest[TYPE_HITROI_TOPLEFT / 2], m_PointDest[TYPE_HITROI_TOPRIGHT / 2]);

			if (m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fx == m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx &&
				m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fy == m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy)
			{
				// do not draw line...
			}
			else
			{
				this->DrawLine(pDC, m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2], m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2]);
			}

		}

		pDC->SelectObject(pOldPen);
		delete pTrackPen;
	}

}

INFO_RECT CRingRoiTracker::GetPositionRect(LPINFO_POINT pPointList, int nLen)
{
	INFO_RECT rtRect;
	memset(&rtRect, 0x00, sizeof(INFO_RECT));

	if (NULL == pPointList || 5 > nLen )
		return rtRect;

	const double nLargeR = GetRadious(pPointList[TYPE_HITROI_CENTER / 2], pPointList[TYPE_HITROI_TOPRIGHT / 2]);

	rtRect.m_fleft = pPointList[TYPE_HITROI_CENTER / 2].m_fx - nLargeR;
	rtRect.m_ftop = pPointList[TYPE_HITROI_CENTER / 2].m_fy - nLargeR;
	rtRect.m_fright = pPointList[TYPE_HITROI_CENTER / 2].m_fx + nLargeR;
	rtRect.m_fbottom = pPointList[TYPE_HITROI_CENTER / 2].m_fy + nLargeR;

	// nStart -> nEnd: Clockwise
	const double nStart = ((int)GetAngle(pPointList[TYPE_HITROI_BOTTOMRIGHT / 2], pPointList[TYPE_HITROI_CENTER / 2], TRUE) + 360) % 360;
	const double nEnd = ((int)GetAngle(pPointList[TYPE_HITROI_TOPRIGHT / 2], pPointList[TYPE_HITROI_CENTER / 2], TRUE) + 360) % 360;
	
	if (nStart != nEnd)
	{
		INFO_POINT ptCenter = pPointList[TYPE_HITROI_CENTER / 2];

		const double x1 = (nLargeR * cos(nStart * VALUE_PI / 180));
		const double y1 = (nLargeR * sin(nStart * VALUE_PI / 180));
		const double x2 = (nLargeR * cos(nEnd * VALUE_PI / 180));
		const double y2 = (nLargeR * sin(nEnd * VALUE_PI / 180));

		// nStart -> nEnd: Clockwise
		double nGap = nEnd - nStart;
		if (nEnd < nStart)
		{
			nGap = 360 - nStart + nEnd;
		}

		if (90 >= nGap)
		{
			if ( (270 < nStart && 360 >= nStart || 0 == nStart) && (0 <= nEnd && 90 >= nEnd) )
				rtRect = SetRectangle(ptCenter.m_fx, ptCenter.m_fy + min(y1, y2), ptCenter.m_fx + nLargeR, ptCenter.m_fy + max(y1, y2));
			else if (90 >= nStart && 90 <= nEnd)
				rtRect = SetRectangle(ptCenter.m_fx + min(x1, x2), ptCenter.m_fy, ptCenter.m_fx + max(x1, x2), ptCenter.m_fy + nLargeR);
			else if (180 >= nStart && 180 <= nEnd)
				rtRect = SetRectangle(ptCenter.m_fx - nLargeR, ptCenter.m_fy + min(y1, y2), ptCenter.m_fx, ptCenter.m_fy + max(y1, y2));
			else if (270 >= nStart && 270 <= nEnd)
				rtRect = SetRectangle(ptCenter.m_fx + min(x1, x2), ptCenter.m_fy - nLargeR, ptCenter.m_fx + max(x1, x2), ptCenter.m_fy);
			else if (90 > nEnd)
				rtRect = SetRectangle(ptCenter.m_fx, ptCenter.m_fy, ptCenter.m_fx + max(x1, x2), ptCenter.m_fy + max(y1, y2));
			else if (180 > nEnd)
				rtRect = SetRectangle(ptCenter.m_fx + min(x1, x2), ptCenter.m_fy, ptCenter.m_fx, ptCenter.m_fy + max(y1, y2));
			else if (270 > nEnd)
				rtRect = SetRectangle(ptCenter.m_fx + min(x1, x2), ptCenter.m_fy + min(y1, y2), ptCenter.m_fx, ptCenter.m_fy);
			else if (360 > nEnd)
				rtRect = SetRectangle(ptCenter.m_fx, ptCenter.m_fy + min(y1, y2), ptCenter.m_fx + max(x1, x2), ptCenter.m_fy);
		}
		else if (180 >= nGap)
		{
			if (270 < nStart && 360 >= nStart || 0 == nStart)
			{
				rtRect = SetRectangle(min(ptCenter.m_fx, ptCenter.m_fx + min(x1, x2)), ptCenter.m_fy + min(y1, y2), ptCenter.m_fx + nLargeR, ptCenter.m_fy + nLargeR);
			}
			else if (90 >= nStart)
			{
				if (180<=nEnd)
					rtRect = SetRectangle(ptCenter.m_fx - nLargeR, min(ptCenter.m_fy, ptCenter.m_fy + min(y1, y2)), ptCenter.m_fx + max(x1, x2), ptCenter.m_fy + nLargeR);
				else
					rtRect = SetRectangle(ptCenter.m_fx + min(x1, x2), min(ptCenter.m_fy, ptCenter.m_fy + min(y1, y2)), ptCenter.m_fx + max(x1, x2), ptCenter.m_fy + nLargeR);
			}
			else if (180 >= nStart)
			{
				if (270 <= nEnd)
					rtRect = SetRectangle(ptCenter.m_fx - nLargeR, ptCenter.m_fy - nLargeR, max(ptCenter.m_fx, ptCenter.m_fx + max(x1, x2)), ptCenter.m_fy + max(y1, y2));
				else
					rtRect = SetRectangle(ptCenter.m_fx - nLargeR, ptCenter.m_fy + min(y1, y2), max(ptCenter.m_fx, ptCenter.m_fx + max(x1, x2)), ptCenter.m_fy + max(y1, y2));

			}
			else if (270 >= nStart)
			{
				rtRect = SetRectangle(ptCenter.m_fx + min(x1, x2), ptCenter.m_fy - nLargeR, ptCenter.m_fx + max(x1, x2), max(ptCenter.m_fy, ptCenter.m_fy + max(y1, y2)));
			}
		}		
		else if (270 >= nGap)
		{
			if (270 < nStart && 360 >= nStart || 0 == nStart)
				rtRect = SetRectangle(ptCenter.m_fx + min(x1, x2), ptCenter.m_fy + min(y1, y2), ptCenter.m_fx + nLargeR, ptCenter.m_fy + nLargeR);
			else if (90 >= nStart)
				rtRect = SetRectangle(ptCenter.m_fx - nLargeR, ptCenter.m_fy + min(y1, y2), ptCenter.m_fx + max(x1, x2), ptCenter.m_fy + nLargeR);
			else if (180 >= nStart)
				rtRect = SetRectangle(ptCenter.m_fx - nLargeR, ptCenter.m_fy - nLargeR, ptCenter.m_fx + max(x1, x2), ptCenter.m_fy + max(y1, y2));
			else if (270 >= nStart)
				rtRect = SetRectangle(ptCenter.m_fx + min(x1, x2), ptCenter.m_fy - nLargeR, ptCenter.m_fx + nLargeR, ptCenter.m_fy + max(y1, y2));
		}
		else //if (360 >= nGap)
		{
			if ((90 > nStart && 90 > nEnd) ||
				(180 > nStart && 90 < nStart && 180 > nEnd && 90 < nEnd) ||
				(270 > nStart && 180 < nStart && 270 > nEnd && 180 < nEnd) ||
				(270 < nStart && 270 < nEnd))
			{
				// do nothing...;
			}
			else if (90 > nStart && 270 < nEnd)
				rtRect = SetRectangle(ptCenter.m_fx - nLargeR, ptCenter.m_fy - nLargeR, ptCenter.m_fx + max(x1, x2), ptCenter.m_fy + nLargeR);
			else if (180 > nStart && 90 > nEnd)
				rtRect = SetRectangle(ptCenter.m_fx - nLargeR, ptCenter.m_fy - nLargeR, ptCenter.m_fx + nLargeR, ptCenter.m_fy + max(y1, y2));
			else if (270 > nStart && 180 > nEnd)
				rtRect = SetRectangle(ptCenter.m_fx + min(x1, x2), ptCenter.m_fy - nLargeR, ptCenter.m_fx + nLargeR, ptCenter.m_fy + nLargeR);
			else if (270 < nStart && 180 < nEnd)
				rtRect = SetRectangle(ptCenter.m_fx - nLargeR, ptCenter.m_fy + min(y1, y2), ptCenter.m_fx + nLargeR, ptCenter.m_fy + nLargeR);
		}
	}

	return rtRect;
}


BOOL CRingRoiTracker::SetCursor(CDC * pDC, float fZoom)
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

	BOOL bResult = SetCursor(eHitRoi, fZoom);
	return bResult;
}

BOOL CRingRoiTracker::SetCursor(TYPE_HITROI eHit, float fZoom)
{
	BOOL bResult = FALSE;

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

	double nDegree = 0;
	int nIdx = 0;

	if (TYPE_HITROI_CENTER != eHit)
	{
		if (TYPE_HITROI_LINE_INNER == eHit || TYPE_HITROI_LINE_OUTER == eHit)
		{
			CPoint point;
			::GetCursorPos(&point);
			this->m_pWnd->ScreenToClient(&point);

			const int x = GetHScrollPos();
			const int y = GetVScrollPos();

			INFO_POINT pt;
			pt.m_fx = ((point.x + x) / fZoom);
			pt.m_fy = ((point.y + y) / fZoom);
			
			nDegree = GetAngle(pt, m_PointSrc[4], TRUE) + 360;
		}
		else if (TYPE_HITROI_LINE_TOPANGLE == eHit)
		{
			nDegree = GetAngle(m_PointSrc[1], m_PointSrc[0], TRUE) + 360;
			nDegree += 90;

		}
		else if (TYPE_HITROI_LINE_BOTTOMANGLE == eHit)
		{
			nDegree = GetAngle(m_PointSrc[3], m_PointSrc[2], TRUE) + 360;
			nDegree += 90;
		}

		else if (TYPE_HITROI_TOPLEFT == eHit || TYPE_HITROI_TOPRIGHT == eHit)
		{
			nDegree = (int)GetAngle(m_PointSrc[1], m_PointSrc[0], TRUE) + 360;
		}
		else if (TYPE_HITROI_BOTTOMRIGHT == eHit || TYPE_HITROI_BOTTOMLEFT == eHit)
		{
			nDegree = (int)GetAngle(m_PointSrc[3], m_PointSrc[2], TRUE) + 360;
		}

		nDegree = this->GetRemainder(nDegree, 360.f);//nDegree %= 360;

		if ((45 - 23) < nDegree && (45 + 23) > nDegree || (225 - 23) < nDegree && (225 + 23) > nDegree)
			nIdx = 0;
		else if ((90 - 23) < nDegree && (90 + 23) > nDegree || (270 - 23) < nDegree && (270 + 23) > nDegree)
			nIdx = 1;
		else if ((135 - 23) < nDegree && (135 + 23) > nDegree || (315 - 23) < nDegree && (315 + 23) > nDegree)
			nIdx = 2;
		else
			nIdx = 3;
	}
	else
	{
		nIdx = 4;
	}

	if (m_hCur[nIdx])
	{
		::SetCursor(m_hCur[nIdx]);
		bResult = TRUE;
	}

	return bResult;
}

void CRingRoiTracker::SetInitState(BOOL bInit)
{
	m_bInit = bInit;
}




int CRingRoiTracker::GetPoint(LPINFO_POINT pPoint, int nLen)
{
	if (FALSE == IsInit())
	{
		return -1;
	}
	else
	{
		if (NULL == pPoint || RING_POINT_COUNT > nLen)
			return RING_POINT_COUNT;
	}

	int idx = 0;

	pPoint[idx] = m_PointSrc[TYPE_HITROI_TOPLEFT / 2];		idx++;
	pPoint[idx] = m_PointSrc[TYPE_HITROI_TOPRIGHT / 2];		idx++;
	pPoint[idx] = m_PointSrc[TYPE_HITROI_BOTTOMRIGHT / 2];	idx++;
	pPoint[idx] = m_PointSrc[TYPE_HITROI_BOTTOMLEFT / 2];	idx++;
	pPoint[idx] = m_PointSrc[TYPE_HITROI_CENTER / 2];		idx++;

	return RING_POINT_COUNT;
}

int CRingRoiTracker::SetPoint(const LPINFO_POINT pPoint, const int nLen, float fZoom, BOOL bErase)
{
	if (NULL == pPoint || RING_POINT_COUNT > nLen)
		return RING_POINT_COUNT;

	INFO_POINT PointZoom[RING_POINT_COUNT];
	ConvertPointPixelToDraw(pPoint, PointZoom, RING_POINT_COUNT, fZoom);

	int idx = 0;
	m_PointDest[TYPE_HITROI_TOPLEFT / 2]	= PointZoom[idx];	idx++;
	m_PointDest[TYPE_HITROI_TOPRIGHT / 2]	= PointZoom[idx];	idx++;
	m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2]= PointZoom[idx];	idx++;
	m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2] = PointZoom[idx];	idx++;
	m_PointDest[TYPE_HITROI_CENTER / 2]		= PointZoom[idx];	idx++;

	OnEndTrack(TYPE_RESULTROI_SUCCEEDED, fZoom, bErase);

	return RING_POINT_COUNT;
}

void CRingRoiTracker::SetAlign(TYPE_ALIGN eAlign, INFO_RECT rtPos)
{
	const double w = rtPos.m_fright - rtPos.m_fleft;
	const double h = rtPos.m_fbottom - rtPos.m_ftop;

	int nLen = this->GetPoint(NULL, 0);
	LPINFO_POINT pPointList = new INFO_POINT[nLen];
	memset(pPointList, 0x00, sizeof(INFO_POINT)*nLen);
	this->GetPoint(pPointList, nLen);


	INFO_RECT rtRoi = this->GetPositionRect(pPointList, nLen);

	const double nRoiW = rtRoi.m_fright - rtRoi.m_fleft;
	const double nRoiH = rtRoi.m_fbottom - rtRoi.m_ftop;

	double cx = 0;
	double cy = 0;

	if (TYPE_ALIGN_LEFT == eAlign)
	{
		cx = rtPos.m_fleft - rtRoi.m_fleft;
	}
	else if (TYPE_ALIGN_RIGHT == eAlign)
	{
		cx = rtPos.m_fright - rtRoi.m_fright;
	}
	else if (TYPE_ALIGN_CENTER == eAlign)
	{
		cx = (rtPos.m_fleft + w / 2) - (rtRoi.m_fleft + nRoiW / 2);
	}

	else if (TYPE_ALIGN_TOP == eAlign)
	{
		cy = rtPos.m_ftop - rtRoi.m_ftop;
	}
	else if (TYPE_ALIGN_BOTTOM == eAlign)
	{
		cy = rtPos.m_fbottom - rtRoi.m_fbottom;
	}
	else if (TYPE_ALIGN_MIDDLE == eAlign)
	{
		cy = (rtPos.m_ftop + h / 2) - (rtRoi.m_ftop + nRoiH / 2);
	}

	for (int i = 0; i < nLen; i++)
	{
		pPointList[i].m_fx += cx;
		pPointList[i].m_fy += cy;
	}
	this->SetPoint(pPointList, nLen, 1.0f, TRUE);

	if (pPointList)
		delete[] pPointList;
	pPointList = NULL;
}


BOOL CRingRoiTracker::SetWidth(DWORD dwWidth)
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
	if (dwCurWidth != dwWidth && MINGAP < std::abs((int)(dwCurWidth - dwWidth)))
	{
		const INFO_POINT ptCenter = pPointList[TYPE_HITROI_CENTER / 2];

		const double outR = GetRadious(ptCenter, pPointList[TYPE_HITROI_TOPRIGHT / 2]);
		const double inR = GetRadious(ptCenter, pPointList[TYPE_HITROI_TOPLEFT / 2]);

		// nStart -> nEnd: Clockwise
		const double nStart = ((int)GetAngle(pPointList[TYPE_HITROI_BOTTOMRIGHT / 2], pPointList[TYPE_HITROI_CENTER / 2], TRUE) + 360) % 360;
		const double nEnd = ((int)GetAngle(pPointList[TYPE_HITROI_TOPRIGHT / 2], pPointList[TYPE_HITROI_CENTER / 2], TRUE) + 360) % 360;
		const float fRatio = (float)dwWidth / (float)(outR * 2);

		double nGap = nEnd - nStart;
		if (nEnd < nStart)
		{
			nGap = 360 - nStart + nEnd;
		}

		if (nStart == nEnd || 180 <= nGap && ((90 <= nStart && (0 <= nEnd || 360 == nEnd)) || ((270 <= nStart || 0 == nStart) && 180 <= nEnd)))
		{
			// TYPE_HITROI_TOPLEFT
			// TYPE_HITROI_TOPRIGHT
			// TYPE_HITROI_BOTTOMRIGHT
			// TYPE_HITROI_BOTTOMLEFT
			// TYPE_HITROI_CENTER

			const double nOut = dwWidth / 2;
			double nIn = inR;
			if (nOut <= nIn)
				nIn = nOut / 2;

			pPointList[TYPE_HITROI_CENTER / 2].m_fx += (nOut - outR);
			const INFO_POINT ptCenter = pPointList[TYPE_HITROI_CENTER / 2];

			pPointList[TYPE_HITROI_TOPLEFT / 2].m_fx = ptCenter.m_fx + (nIn * cos(nEnd * VALUE_PI / 180));
			pPointList[TYPE_HITROI_TOPLEFT / 2].m_fy = ptCenter.m_fy + (nIn * sin(nEnd * VALUE_PI / 180));

			pPointList[TYPE_HITROI_TOPRIGHT / 2].m_fx = ptCenter.m_fx + (nOut * cos(nEnd * VALUE_PI / 180));
			pPointList[TYPE_HITROI_TOPRIGHT / 2].m_fy = ptCenter.m_fy + (nOut * sin(nEnd * VALUE_PI / 180));

			pPointList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = ptCenter.m_fx + (nOut * cos(nStart * VALUE_PI / 180));
			pPointList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = ptCenter.m_fy + (nOut * sin(nStart * VALUE_PI / 180));

			pPointList[TYPE_HITROI_BOTTOMLEFT / 2].m_fx = ptCenter.m_fx + (nIn * cos(nStart * VALUE_PI / 180));
			pPointList[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = ptCenter.m_fy + (nIn * sin(nStart * VALUE_PI / 180));
		}
		else
		{
			const INFO_POINT ptCenter = pPointList[TYPE_HITROI_CENTER / 2];
			double nOut = 0;
			double nIn = 0;

			if (90 >= nGap)
			{
				if (270 <= nStart && (90 > nEnd || 0 == nEnd || 360 == nEnd) || (90 <= nStart && 180 > nStart) && 180 <= nEnd)
				{
					nOut = dwWidth;
				}
				else
				{
					if ((0 <= nStart && 90 > nStart || 360 == nStart) && 90 <= nEnd)
					{
						nOut = dwWidth / (std::abs(cos(nStart * VALUE_PI / 180)) + std::abs(cos(nEnd * VALUE_PI / 180)));
					}
					else if ((180 <= nStart && 270 > nStart) && 270 <= nEnd)
					{
						nOut = dwWidth / (std::abs(cos(nStart * VALUE_PI / 180)) + std::abs(cos(nEnd * VALUE_PI / 180)));
					}
					else
					{
						double nAngle = 0;
						if (0 < nStart && 90 > nStart || 180 < nStart && 270 > nStart)
							nAngle = nStart;
						else
							nAngle = nEnd;
						nOut = dwWidth / std::abs(cos(nAngle * VALUE_PI / 180));
					}
				}
			}
			else if (180 >= nGap)
			{
				if ((0 <= nStart || 360 == nStart) && 90 > nStart)
				{
					if (180 <= nEnd)
						nOut = dwWidth / (std::abs(cos(nStart * VALUE_PI / 180)) + 1);
					else
						nOut = dwWidth / (std::abs(cos(nStart * VALUE_PI / 180)) + std::abs(cos(nEnd * VALUE_PI / 180)));
				}
				else if (90 <= nStart && 180 > nStart)
				{
					if (270 >= nEnd)
						nOut = dwWidth;
					else
						nOut = dwWidth / (1 + std::abs(cos(nEnd * VALUE_PI / 180)));
				}
				else if (180 <= nStart && 270 > nStart)
				{
					if (360 > nEnd)
						nOut = dwWidth / (std::abs(cos(nStart * VALUE_PI / 180)) + std::abs(cos(nEnd * VALUE_PI / 180)));
					else
						nOut = dwWidth / (std::abs(cos(nStart * VALUE_PI / 180)) + 1);
				}
				else if (270 <= nStart && 360 > nStart)
				{
					if (90 >= nEnd)
						nOut = dwWidth;
					else
						nOut = dwWidth / (1 + std::abs(cos(nEnd * VALUE_PI / 180)));
				}

			}
			nIn = inR;
			if (nOut <= nIn)
				nIn = nOut / 2;
			
			pPointList[TYPE_HITROI_TOPLEFT / 2].m_fx = ptCenter.m_fx + (nIn * cos(nEnd * VALUE_PI / 180));
			pPointList[TYPE_HITROI_TOPLEFT / 2].m_fy = ptCenter.m_fy + (nIn * sin(nEnd * VALUE_PI / 180));

			pPointList[TYPE_HITROI_TOPRIGHT / 2].m_fx = ptCenter.m_fx + (nOut * cos(nEnd * VALUE_PI / 180));
			pPointList[TYPE_HITROI_TOPRIGHT / 2].m_fy = ptCenter.m_fy + (nOut * sin(nEnd * VALUE_PI / 180));

			pPointList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = ptCenter.m_fx + (nOut * cos(nStart * VALUE_PI / 180));
			pPointList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = ptCenter.m_fy + (nOut * sin(nStart * VALUE_PI / 180));

			pPointList[TYPE_HITROI_BOTTOMLEFT / 2].m_fx = ptCenter.m_fx + (nIn * cos(nStart * VALUE_PI / 180));
			pPointList[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = ptCenter.m_fy + (nIn * sin(nStart * VALUE_PI / 180));
		}

		SetPoint(pPointList, nLen, 1.0f);
	}

	delete[] pPointList;
	return TRUE;
}

BOOL CRingRoiTracker::SetHeight(DWORD dwHeight)
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
	if (dwCurHeight != dwHeight && MINGAP < std::abs((int)(dwCurHeight - dwHeight)))
	{
		const INFO_POINT ptCenter = pPointList[TYPE_HITROI_CENTER / 2];

		const double outR = GetRadious(ptCenter, pPointList[TYPE_HITROI_TOPRIGHT / 2]);
		const double inR = GetRadious(ptCenter, pPointList[TYPE_HITROI_TOPLEFT / 2]);

		// nStart -> nEnd: Clockwise
		const double nStart = this->GetRemainder((GetAngle(pPointList[TYPE_HITROI_BOTTOMRIGHT / 2], pPointList[TYPE_HITROI_CENTER / 2], TRUE) + 360), 360.f);
		const double nEnd = this->GetRemainder((GetAngle(pPointList[TYPE_HITROI_TOPRIGHT / 2], pPointList[TYPE_HITROI_CENTER / 2], TRUE) + 360), 360.f);
		const double fRatio = (float)dwHeight / (float)(outR * 2);

		double nGap = nEnd - nStart;
		if (nEnd < nStart)
		{
			nGap = 360 - nStart + nEnd;
		}

		if (nStart == nEnd || (180 <= nGap && (270 >= nStart && (90 <= nEnd)) || (90 >= nStart && 270 <= nEnd)))
		{
			// TYPE_HITROI_TOPLEFT
			// TYPE_HITROI_TOPRIGHT
			// TYPE_HITROI_BOTTOMRIGHT
			// TYPE_HITROI_BOTTOMLEFT
			// TYPE_HITROI_CENTER

			const double nOut = dwHeight / 2;
			double nIn = inR;
			if (nOut <= nIn)
				nIn = nOut / 2;

			pPointList[TYPE_HITROI_CENTER / 2].m_fy += (nOut - outR);
			const INFO_POINT ptCenter = pPointList[TYPE_HITROI_CENTER / 2];

			pPointList[TYPE_HITROI_TOPLEFT / 2].m_fx = ptCenter.m_fx + (nIn * cos(nEnd * VALUE_PI / 180));
			pPointList[TYPE_HITROI_TOPLEFT / 2].m_fy = ptCenter.m_fy + (nIn * sin(nEnd * VALUE_PI / 180));

			pPointList[TYPE_HITROI_TOPRIGHT / 2].m_fx = ptCenter.m_fx + (nOut * cos(nEnd * VALUE_PI / 180));
			pPointList[TYPE_HITROI_TOPRIGHT / 2].m_fy = ptCenter.m_fy + (nOut * sin(nEnd * VALUE_PI / 180));

			pPointList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = ptCenter.m_fx + (nOut * cos(nStart * VALUE_PI / 180));
			pPointList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = ptCenter.m_fy + (nOut * sin(nStart * VALUE_PI / 180));

			pPointList[TYPE_HITROI_BOTTOMLEFT / 2].m_fx = ptCenter.m_fx + (nIn * cos(nStart * VALUE_PI / 180));
			pPointList[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = ptCenter.m_fy + (nIn * sin(nStart * VALUE_PI / 180));
		}
		else
		{
			const INFO_POINT ptCenter = pPointList[TYPE_HITROI_CENTER / 2];

			double nOut = 0;
			double nIn = 0;

			if (90 >= nGap)
			{
				if ((0 <= nStart && 90 > nEnd || 360 == nStart) && 90 <= nEnd || (180 <= nStart && 270 > nStart) && 270 <= nEnd)
				{
					nOut = dwHeight;
				}
				else
				{
					if (270 <= nStart && (90 > nEnd || 0 == nEnd || 360 == nEnd) )
					{
						nOut = dwHeight / (std::abs(sin(nStart * VALUE_PI / 180)) + std::abs(sin(nEnd * VALUE_PI / 180)));
					}
					else if ((90 <= nStart && 180 > nStart) && 180 <= nEnd)
					{
						nOut = dwHeight / (std::abs(sin(nEnd * VALUE_PI / 180)) + std::abs(sin(nStart * VALUE_PI / 180)));
					}
					else
					{
						double nAngle = 0;
						if (0 < nStart && 90 > nStart || 180 < nStart && 270 > nStart)
							nAngle = nEnd;
						else
							nAngle = nStart;
						nOut = dwHeight / std::abs(sin(nAngle * VALUE_PI / 180));
					}
				}
			}
			else if (180 >= nGap)
			{
				if ((0 <= nStart || 360 == nStart) && 90 > nStart)
				{
					if (180 > nEnd)
						nOut = dwHeight;
					else
						nOut = dwHeight / (1 + std::abs(sin(nEnd * VALUE_PI / 180)));
				}
				else if (90 <= nStart && 180 > nStart)
				{
					if (270 > nEnd)
						nOut = dwHeight / (std::abs(sin(nStart * VALUE_PI / 180)) + std::abs(sin(nEnd * VALUE_PI / 180)));
					else
						nOut = dwHeight / (std::abs(sin(nStart * VALUE_PI / 180)) + 1);
				}
				else if (180 <= nStart && 270 > nStart)
				{
					if (360 > nEnd)
						nOut = dwHeight;
					else
						nOut = dwHeight / (1 + std::abs(sin(nEnd * VALUE_PI / 180)));
				}
				else if (270 <= nStart && 360 > nStart)
				{
					if (90 > nEnd)
						nOut = dwHeight;
					else
						nOut = dwHeight / (std::abs(sin(nStart * VALUE_PI / 180)) + 1);
				}
			}

			nIn = inR;
			if (nOut <= nIn)
				nIn = nOut / 2;

			pPointList[TYPE_HITROI_TOPLEFT / 2].m_fx = ptCenter.m_fx + (nIn * cos(nEnd * VALUE_PI / 180));
			pPointList[TYPE_HITROI_TOPLEFT / 2].m_fy = ptCenter.m_fy + (nIn * sin(nEnd * VALUE_PI / 180));

			pPointList[TYPE_HITROI_TOPRIGHT / 2].m_fx = ptCenter.m_fx + (nOut * cos(nEnd * VALUE_PI / 180));
			pPointList[TYPE_HITROI_TOPRIGHT / 2].m_fy = ptCenter.m_fy + (nOut * sin(nEnd * VALUE_PI / 180));

			pPointList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = ptCenter.m_fx + (nOut * cos(nStart * VALUE_PI / 180));
			pPointList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = ptCenter.m_fy + (nOut * sin(nStart * VALUE_PI / 180));

			pPointList[TYPE_HITROI_BOTTOMLEFT / 2].m_fx = ptCenter.m_fx + (nIn * cos(nStart * VALUE_PI / 180));
			pPointList[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = ptCenter.m_fy + (nIn * sin(nStart * VALUE_PI / 180));
		}

		SetPoint(pPointList, nLen, 1.0f);
	}

	delete[] pPointList;
	return TRUE;
}

BOOL CRingRoiTracker::MovePoint(int cx, int cy)
{
	if (FALSE == IsInit())
		return FALSE;

	for (int i = 0; i < ROIRING_POINT_COUNT; i++)
	{
		m_PointSrc[i].m_fx += cx;
		m_PointSrc[i].m_fy += cy;
	}
	return TRUE;
}