#include "stdafx.h"
#include "CircleRoiTracker.h"

#include "RoiTrackerDC.h"

#include "../Common/Tracker/VideoOutArrow.h"

#include <cmath>

CCircleRoiTracker::CCircleRoiTracker(CWnd* pWnd)
	: CRoiTracker(pWnd)
{
	m_bInit = FALSE;

	m_eHitRoi = TYPE_HITROI_NONE;
	m_eTransformRoi = TYPE_TRANSFORMROI_NONE;

	memset(m_PointSrc, 0x00, sizeof(INFO_POINT)*ROICIRCLE_POINT_COUNT);
	memset(m_PointDest, 0x00, sizeof(INFO_POINT)*CIRCLE_POINT_COUNT);

	memset(m_hCur, 0x00, sizeof(HCURSOR)*ROICIRCLE_POINT_COUNT);

	m_rgbTrack = RGB(0, 0, 0);
	m_rgbRoiRect = RGB(0, 0, 0);
	m_rgbRoiCircle = RGB(0, 0, 0);

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

	for (int i = 0; i < ROICIRCLE_POINT_COUNT; i++)
	{
		m_hCur[i] = ::AfxGetApp()->LoadCursor(CursorIDs[i]);
	}
#ifdef DEF_ROTATE
	m_Transform.Reset();
	m_StartPhi = 0;
#endif

	m_pTrackCircle = NULL;

}

CCircleRoiTracker::~CCircleRoiTracker()
{
	for (int i = 0; i < ROICIRCLE_POINT_COUNT; i++)
	{
		if (m_hCur[i])
		{
			::DestroyCursor(m_hCur[i]);
		}
	}

	if (m_pTrackCircle)
		delete[] m_pTrackCircle;
	m_pTrackCircle = NULL;
}

BOOL CCircleRoiTracker::IsEnableRotate()
{
#ifdef DEF_ROTATE
	return TRUE;
#else
	return FALSE;
#endif
}

void CCircleRoiTracker::Clear()
{
	m_bInit = FALSE;

	m_eHitRoi = TYPE_HITROI_NONE;
	m_eTransformRoi = TYPE_TRANSFORMROI_NONE;

	memset(m_PointSrc, 0x00, sizeof(INFO_POINT)*ROICIRCLE_POINT_COUNT);
	memset(m_PointDest, 0x00, sizeof(INFO_POINT)*CIRCLE_POINT_COUNT);

	Invalidate();

	if (m_pTrackCircle)
		delete[] m_pTrackCircle;
	m_pTrackCircle = NULL;
}

//
BOOL CCircleRoiTracker::IsInit()
{
	return m_bInit;
}

void CCircleRoiTracker::Draw(CDC* pDC, float fZoom)
{
	if (NULL == pDC)
		return;

	int nOldRop = pDC->SetROP2(R2_NOTXORPEN);
	DrawRoiCircle(pDC, fZoom);
	pDC->SetROP2(nOldRop);
}

void CCircleRoiTracker::DrawRoi(CDC* pDC, INFO_SIZE stSize, float fZoom, void* pReserved)
{
	if (NULL == pDC || FALSE == IsInit())
		return;

	BOOL bDrawForFile = FALSE;
	if (pReserved)
	{
		INFO_RESERVED* pstReserved = (INFO_RESERVED*)pReserved;
		bDrawForFile = pstReserved->m_bDrawForFile;
	}


	INFO_POINT PointZoom[ROICIRCLE_POINT_COUNT];
	memset(PointZoom, 0x00, sizeof(INFO_POINT)*ROICIRCLE_POINT_COUNT);
	ConvertPointPixelToDrawForRoi(m_PointSrc, PointZoom, ROICIRCLE_POINT_COUNT, stSize, fZoom, bDrawForFile);

	const double w = PointZoom[TYPE_HITROI_TOPRIGHT].m_fx - PointZoom[TYPE_HITROI_TOPLEFT].m_fx;
	const double h = PointZoom[TYPE_HITROI_BOTTOMLEFT].m_fy - PointZoom[TYPE_HITROI_TOPLEFT].m_fy;

	INFO_POINT ptCenter;
	ptCenter.m_fx = PointZoom[TYPE_HITROI_TOPLEFT].m_fx + w / 2;
	ptCenter.m_fy = PointZoom[TYPE_HITROI_TOPLEFT].m_fy + h / 2;

	const double outR = GetRadious(ptCenter, PointZoom[TYPE_HITROI_TOPRIGHT]);
	if (pReserved)
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

		INFO_RESERVED* pstReserved = (INFO_RESERVED*)pReserved;
		pDC->SelectObject(pstReserved->m_hOutLine);
	}
	CGdiObject * pOldBrush = pDC->SelectStockObject(NULL_BRUSH);

#ifndef DEF_ROTATE
	pDC->Ellipse((int)PointZoom[TYPE_HITROI_TOPLEFT].m_fx,
		(int)PointZoom[TYPE_HITROI_TOPLEFT].m_fy,
		(int)PointZoom[TYPE_HITROI_BOTTOMRIGHT].m_fx,
		(int)PointZoom[TYPE_HITROI_BOTTOMRIGHT].m_fy);
#else
	{
		INFO_SIZE sz = this->GetSize(PointZoom[TYPE_HITROI_TOPRIGHT], PointZoom[TYPE_HITROI_TOPLEFT]);
		REAL phi = 180.0f * (REAL)atan2((REAL)sz.m_fcy, (REAL)sz.m_fcx) / (REAL)VALUE_PI;
		if (0 == phi)
		{
			pDC->Ellipse(PointZoom[TYPE_HITROI_TOPLEFT].m_fx,
				PointZoom[TYPE_HITROI_TOPLEFT].m_fy,
				PointZoom[TYPE_HITROI_BOTTOMRIGHT].m_fx,
				PointZoom[TYPE_HITROI_BOTTOMRIGHT].m_fy);
		}
		else
		{
			POINT PointCircle[ROICIRCLE_POINT_COUNT];
			memcpy(PointCircle, PointZoom, sizeof(POINT)*ROICIRCLE_POINT_COUNT);
			
			Matrix mCircle;
			mCircle.Reset();
			mCircle.Translate((REAL)-m_FixedPoint.m_fx, (REAL)-m_FixedPoint.m_fy);
			mCircle.Rotate(phi*(-1), MatrixOrderAppend);
			mCircle.Translate((REAL)m_FixedPoint.m_fx, (REAL)m_FixedPoint.m_fy, MatrixOrderAppend);
			mCircle.TransformPoints((Point *)PointCircle, ROICIRCLE_POINT_COUNT);

			Pen pen(Color(255, GetRValue(m_rgbRoiCircle), GetRValue(m_rgbRoiCircle), GetRValue(m_rgbRoiCircle)), 1);

			Graphics graph(pDC->m_hDC);
			graph.SetTransform(&m_Transform);
			graph.DrawEllipse(&pen,
				PointCircle[TYPE_HITROI_TOPLEFT].m_fx,
				PointCircle[TYPE_HITROI_TOPLEFT].m_fy,
				abs(PointCircle[TYPE_HITROI_BOTTOMRIGHT].m_fx - PointCircle[TYPE_HITROI_TOPLEFT].m_fx),
				abs(PointCircle[TYPE_HITROI_BOTTOMRIGHT].m_fy - PointCircle[TYPE_HITROI_TOPLEFT].m_fy));

		}
	}
#endif
}

void CCircleRoiTracker::DrawRoiCircle(CDC* pDC, float fZoom)
{
	if (pDC && IsInit())
	{
		CGdiObject * pOldPen = NULL;


		INFO_POINT PointZoom[ROICIRCLE_POINT_COUNT];
		memset(PointZoom, 0x00, sizeof(INFO_POINT)*ROICIRCLE_POINT_COUNT);
		ConvertPointPixelToDraw(m_PointSrc, PointZoom, ROICIRCLE_POINT_COUNT, fZoom);

#ifndef DEF_ROTATE
		///
		{
			CPen* pCirclePen = new CPen(PS_SOLID, 1, m_rgbRoiCircle);
			pOldPen = pDC->SelectObject(pCirclePen);
			CGdiObject * pOldBrush = pDC->SelectStockObject(NULL_BRUSH);

			pDC->Ellipse((int)PointZoom[TYPE_HITROI_TOPLEFT].m_fx,
				(int)PointZoom[TYPE_HITROI_TOPLEFT].m_fy,
				(int)PointZoom[TYPE_HITROI_BOTTOMRIGHT].m_fx,
				(int)PointZoom[TYPE_HITROI_BOTTOMRIGHT].m_fy);

			pDC->SelectObject(pOldPen);
			pDC->SelectObject(pOldBrush);

			delete pCirclePen;
		}
		//*/
#else
		///
		{
			INFO_SIZE sz = this->GetSize(PointZoom[TYPE_HITROI_TOPRIGHT], PointZoom[TYPE_HITROI_TOPLEFT]);
			REAL phi = 180.0f * (REAL)atan2((REAL)sz.m_fcy, (REAL)sz.m_fcx) / (REAL)VALUE_PI;

			if (0 == phi)
			{
				CPen* pCirclePen = new CPen(PS_SOLID, 1, m_rgbRoiCircle);
				pOldPen = pDC->SelectObject(pCirclePen);
				CGdiObject * pOldBrush = pDC->SelectStockObject(NULL_BRUSH);

				pDC->Ellipse(PointZoom[TYPE_HITROI_TOPLEFT].m_fx,
					PointZoom[TYPE_HITROI_TOPLEFT].m_fy,
					PointZoom[TYPE_HITROI_BOTTOMRIGHT].m_fx,
					PointZoom[TYPE_HITROI_BOTTOMRIGHT].m_fy);

				pDC->SelectObject(pOldPen);
				pDC->SelectObject(pOldBrush);

				delete pCirclePen;
			}
			else
			{
				INFO_POINT PointCircle[ROICIRCLE_POINT_COUNT];
				memcpy(PointCircle, PointZoom, sizeof(INFO_POINT)*ROICIRCLE_POINT_COUNT);

				Matrix mCircle;
				mCircle.Reset();
				mCircle.Translate((REAL)-m_FixedPoint.m_fx, (REAL)-m_FixedPoint.m_fy);
				mCircle.Rotate(phi*(-1), MatrixOrderAppend);
				mCircle.Translate((REAL)m_FixedPoint.m_fx, (REAL)m_FixedPoint.m_fy, MatrixOrderAppend);
				mCircle.TransformPoints((Point *)PointCircle, ROICIRCLE_POINT_COUNT);

				Pen pen(Color(255, GetRValue(m_rgbRoiCircle), GetRValue(m_rgbRoiCircle), GetRValue(m_rgbRoiCircle)), 1);

				Graphics graph(pDC->m_hDC);
				graph.SetTransform(&m_Transform);
				graph.DrawEllipse(&pen,
					PointCircle[TYPE_HITROI_TOPLEFT].m_fx,
					PointCircle[TYPE_HITROI_TOPLEFT].m_fy,
					abs(PointCircle[TYPE_HITROI_BOTTOMRIGHT].m_fx - PointCircle[TYPE_HITROI_TOPLEFT].m_fx),
					abs(PointCircle[TYPE_HITROI_BOTTOMRIGHT].m_fy - PointCircle[TYPE_HITROI_TOPLEFT].m_fy));

			}
		}
		//*/

		/// Draw Line
		{
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
#endif

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
#ifdef DEF_CIRCLE
				if (TYPE_HITROI_TOPLEFT == i || TYPE_HITROI_TOPRIGHT == i ||
					TYPE_HITROI_BOTTOMRIGHT == i || TYPE_HITROI_BOTTOMLEFT == i)
				{
					continue;
				}
#endif

				INFO_RECT rect = GetHitRect((TYPE_HITROI)i, fZoom);
				RECT rtDraw = GetRectangle(rect);
#ifndef DEF_ROTATE
				pDC->Rectangle(&rtDraw);
#else
				if (TYPE_HITROI_TOP == i)
				{
					pDC->SelectStockObject(BLACK_BRUSH);
					pDC->Rectangle(&rtDraw);
					pDC->SelectStockObject(NULL_BRUSH);
				}
				else
				{
					pDC->Rectangle(&rtDraw);
				}
#endif
			}

			pDC->SelectObject(pOldPen);
			pDC->SelectObject(pOldBrush);

			delete pRectPen;
		}
		//*/

	}
}

void CCircleRoiTracker::DrawTracker(CDC* pDC, INFO_POINT pt1, INFO_POINT pt2, float fZoom, BOOL bDone)
{
	if (NULL == pDC || FALSE == IsInit())
		return;

	const int x = GetHScrollPos();
	const int y = GetVScrollPos();

	if (bDone && m_pTrackCircle)
	{
		INFO_POINT PointZoom[ROICIRCLE_POINT_COUNT];
		memset(PointZoom, 0x00, sizeof(INFO_POINT)*ROICIRCLE_POINT_COUNT);
		ConvertPointDrawToPixel(m_pTrackCircle, PointZoom, ROICIRCLE_POINT_COUNT, fZoom);

		double w = PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx - PointZoom[TYPE_HITROI_TOPLEFT / 2].m_fx;
		double h = PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy - PointZoom[TYPE_HITROI_TOPLEFT / 2].m_fy;


		m_PointSrc[TYPE_HITROI_TOPLEFT] = PointZoom[0];
		m_PointSrc[TYPE_HITROI_TOP] = PointZoom[0];
		m_PointSrc[TYPE_HITROI_TOP].m_fx += w / 2;

		m_PointSrc[TYPE_HITROI_TOPRIGHT] = PointZoom[1];
		m_PointSrc[TYPE_HITROI_RIGHT] = PointZoom[1];
		m_PointSrc[TYPE_HITROI_RIGHT].m_fy += h / 2;


		m_PointSrc[TYPE_HITROI_BOTTOMRIGHT] = PointZoom[2];
		m_PointSrc[TYPE_HITROI_BOTTOM] = PointZoom[2];
		m_PointSrc[TYPE_HITROI_BOTTOM].m_fx = m_PointSrc[TYPE_HITROI_TOP].m_fx;

		m_PointSrc[TYPE_HITROI_BOTTOMLEFT] = PointZoom[3];
		m_PointSrc[TYPE_HITROI_LEFT] = PointZoom[3];
		m_PointSrc[TYPE_HITROI_LEFT].m_fy = m_PointSrc[TYPE_HITROI_RIGHT].m_fy;

		m_PointSrc[TYPE_HITROI_CENTER].m_fx = m_PointSrc[TYPE_HITROI_TOP].m_fx;
		m_PointSrc[TYPE_HITROI_CENTER].m_fy = m_PointSrc[TYPE_HITROI_RIGHT].m_fy;


		delete[] m_pTrackCircle;
		m_pTrackCircle = NULL;

		return;
	}

	CRoiTrackerDC* pRDC = new CRoiTrackerDC(pDC, NOTSRCINVERT);
	pRDC->SetROP2(R2_NOTXORPEN);

	INFO_POINT pPt[CIRCLE_POINT_COUNT];
	pPt[TYPE_HITROI_TOPLEFT / 2] = GetTrackerPointFromSrc(m_PointSrc[TYPE_HITROI_TOPLEFT], fZoom);
	pPt[TYPE_HITROI_TOPRIGHT / 2] = GetTrackerPointFromSrc(m_PointSrc[TYPE_HITROI_TOPRIGHT], fZoom);
	pPt[TYPE_HITROI_BOTTOMRIGHT / 2] = GetTrackerPointFromSrc(m_PointSrc[TYPE_HITROI_BOTTOMRIGHT], fZoom);
	pPt[TYPE_HITROI_BOTTOMLEFT / 2] = GetTrackerPointFromSrc(m_PointSrc[TYPE_HITROI_BOTTOMLEFT], fZoom);
	pPt[TYPE_HITROI_CENTER / 2] = GetTrackerPointFromSrc(m_PointSrc[TYPE_HITROI_CENTER], fZoom);

	if (NULL == m_pTrackCircle)
	{
		m_pTrackCircle = new INFO_POINT[CIRCLE_POINT_COUNT];
		for (int i = 0; i < CIRCLE_POINT_COUNT; i++)
		{
			m_pTrackCircle[i] = pPt[i];
		}
	}
	else
	{
		DrawTrackCircle(pRDC, m_pTrackCircle, CIRCLE_POINT_COUNT);
	}

	pPt[TYPE_HITROI_TOPLEFT / 2] = GetTrackerPointFromSrc(m_PointSrc[TYPE_HITROI_TOPLEFT], pt1, pt2, fZoom);
	pPt[TYPE_HITROI_TOPRIGHT / 2] = GetTrackerPointFromSrc(m_PointSrc[TYPE_HITROI_TOPRIGHT], pt1, pt2, fZoom);
	pPt[TYPE_HITROI_BOTTOMRIGHT / 2] = GetTrackerPointFromSrc(m_PointSrc[TYPE_HITROI_BOTTOMRIGHT], pt1, pt2, fZoom);
	pPt[TYPE_HITROI_BOTTOMLEFT / 2] = GetTrackerPointFromSrc(m_PointSrc[TYPE_HITROI_BOTTOMLEFT], pt1, pt2, fZoom);
	pPt[TYPE_HITROI_CENTER / 2] = GetTrackerPointFromSrc(m_PointSrc[TYPE_HITROI_CENTER], pt1, pt2, fZoom);


	DrawTrackCircle(pRDC, pPt, CIRCLE_POINT_COUNT);
	if (m_pTrackCircle)
	{
		for (int i = 0; i < CIRCLE_POINT_COUNT; i++)
		{
			m_pTrackCircle[i] = pPt[i];
		}
	}

	delete pRDC;
}


void CCircleRoiTracker::DrawTrackCircle(CDC* pDC, LPINFO_POINT pPtList, int nPtLen)
{
	if (NULL == pDC)
		return;

	LOGBRUSH stLb;
	memset(&stLb, 0x00, sizeof(LOGBRUSH));
	stLb.lbColor = m_rgbTrack;
	stLb.lbHatch = 0;
	stLb.lbStyle = BS_SOLID;

	CPen* pTrackPen = new CPen(PS_COSMETIC | PS_ALTERNATE, 1, &stLb);

#ifndef DEF_ROTATE	
	CGdiObject * pOldPen = pDC->SelectObject(pTrackPen);
	pDC->Ellipse((int)pPtList[TYPE_HITROI_TOPLEFT / 2].m_fx,
		(int)pPtList[TYPE_HITROI_TOPLEFT / 2].m_fy,
		(int)pPtList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx,
		(int)pPtList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy);
	pDC->SelectObject(pOldPen);
#else
	if (TYPE_TRANSFORMROI_ROTATE == m_eTransformRoi)
	{
		INFO_POINT PointZoom[ROICIRCLE_POINT_COUNT];
		memset(PointZoom, 0x00, sizeof(INFO_POINT)*ROICIRCLE_POINT_COUNT);
		ConvertPointPixelToDraw(m_PointSrc, PointZoom, ROICIRCLE_POINT_COUNT, fZoom);

		pPtList[TYPE_HITROI_TOPLEFT / 2] = PointZoom[TYPE_HITROI_TOPLEFT];
		pPtList[TYPE_HITROI_TOPRIGHT / 2] = PointZoom[TYPE_HITROI_TOPRIGHT];
		pPtList[TYPE_HITROI_BOTTOMRIGHT / 2] = PointZoom[TYPE_HITROI_BOTTOMRIGHT];
		pPtList[TYPE_HITROI_BOTTOMLEFT / 2] = PointZoom[TYPE_HITROI_BOTTOMLEFT];
		pPtList[TYPE_HITROI_CENTER / 2] = PointZoom[TYPE_HITROI_CENTER];

		m_Transform.TransformPoints((Point *)pPtList, CIRCLE_POINT_COUNT);
	}

	INFO_SIZE sz = this->GetSize(pPtList[TYPE_HITROI_TOPRIGHT / 2], pPtList[TYPE_HITROI_TOPLEFT / 2]);
	REAL phi = 180.0f * (REAL)atan2((REAL)sz.m_fcy, (REAL)sz.m_fcx) / (REAL)VALUE_PI;
	if (0 == phi)
	{
		CGdiObject * pOldPen = pDC->SelectObject(pTrackPen);
		pDC->Ellipse(pPtList[TYPE_HITROI_TOPLEFT / 2].m_fx,
			pPtList[TYPE_HITROI_TOPLEFT / 2].m_fy,
			pPtList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx,
			pPtList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy);
		pDC->SelectObject(pOldPen);
	}
	else
	{
		INFO_POINT PointCircle[CIRCLE_POINT_COUNT];
		memcpy(PointCircle, pPtList, sizeof(INFO_POINT)*CIRCLE_POINT_COUNT);

		m_FixedPoint = PointCircle[TYPE_HITROI_CENTER / 2];

		Matrix mCircle;
		mCircle.Reset();
		mCircle.Translate((REAL)-m_FixedPoint.m_fx, (REAL)-m_FixedPoint.m_fy);
		mCircle.Rotate(phi*(-1), MatrixOrderAppend);
		mCircle.Translate((REAL)m_FixedPoint.m_fx, (REAL)m_FixedPoint.m_fy, MatrixOrderAppend);
		mCircle.TransformPoints((Point *)PointCircle, CIRCLE_POINT_COUNT);

		mCircle.Reset();
		mCircle.Translate((REAL)-m_FixedPoint.m_fx, (REAL)-m_FixedPoint.m_fy);
		mCircle.Rotate(phi, MatrixOrderAppend);
		mCircle.Translate((REAL)m_FixedPoint.m_fx, (REAL)m_FixedPoint.m_fy, MatrixOrderAppend);

		Pen pen(Color(255, GetRValue(m_rgbTrack), GetRValue(m_rgbTrack), GetRValue(m_rgbTrack)), 1);

		Graphics graph(pDC->m_hDC);
		graph.SetTransform(&mCircle);
		graph.DrawEllipse(&pen,
			PointCircle[TYPE_HITROI_TOPLEFT / 2].m_fx,
			PointCircle[TYPE_HITROI_TOPLEFT / 2].m_fy,
			abs(PointCircle[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx - PointCircle[TYPE_HITROI_TOPLEFT / 2].m_fx),
			abs(PointCircle[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy - PointCircle[TYPE_HITROI_TOPLEFT / 2].m_fy));
	}
#endif

	delete pTrackPen;

}


TYPE_HITROI CCircleRoiTracker::HitTest(INFO_POINT point, float fZoom)
{
	TYPE_HITROI eHitRoi = TYPE_HITROI_NONE;
	if (FALSE == IsInit())
		return eHitRoi;

	int i = 0;
	for (i = 0; i < TYPE_HITROI_BODY; i++)
	{
#ifdef DEF_CIRCLE
		if (TYPE_HITROI_TOPLEFT == i || TYPE_HITROI_TOPRIGHT == i ||
			TYPE_HITROI_BOTTOMRIGHT == i ||	TYPE_HITROI_BOTTOMLEFT == i )
		{
			continue;
		}
#endif
		INFO_RECT rect = GetHitRect((TYPE_HITROI)i, fZoom);
		if (TRUE == CheckPointInRect(rect, point, fZoom))
		{
			break;
		}
	}

	eHitRoi = (TYPE_HITROI)i;
	if (TYPE_HITROI_BODY <= i)
		eHitRoi = TYPE_HITROI_NONE;

#ifdef DEF_CIRCLE
	if (TYPE_HITROI_NONE == eHitRoi)
	{
		const int x = GetHScrollPos();
		const int y = GetVScrollPos();
		point.m_fx += (x / fZoom);
		point.m_fy += (y / fZoom);

		const double nCur = GetRadious(m_PointSrc[TYPE_HITROI_CENTER], m_PointSrc[TYPE_HITROI_LEFT]);
		const double r = GetRadious(m_PointSrc[TYPE_HITROI_CENTER], point);

		double nGap = std::abs(nCur - r);
		if (VALUE_INFLATE > nGap)
		{
			return TYPE_HITROI_CENTER;
		}

	}
#endif

	return eHitRoi;
}

INFO_RECT CCircleRoiTracker::GetHitRect(TYPE_HITROI eHit, float fZoom)
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

INFO_POINT CCircleRoiTracker::GetHitPoint(LPINFO_POINT pPoint, TYPE_HITROI eHit)
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

TYPE_RESULTROI CCircleRoiTracker::OnBeginTrack(UINT nFlags, INFO_POINT point, float fZoom)
{
	m_eHitRoi = HitTest(point, fZoom);

	if (TYPE_HITROI_NONE == m_eHitRoi)
	{
		m_eTransformRoi = TYPE_TRANSFORMROI_CREATE;

		for (int i = 0; i < CIRCLE_POINT_COUNT; i++)
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
#ifndef DEF_ROTATE
		m_eTransformRoi = TYPE_TRANSFORMROI_SCALE;
#else	
		if (IsEnableRotate())
		{
			if (TYPE_HITROI_TOP == m_eHitRoi)
			{
				m_eTransformRoi = TYPE_TRANSFORMROI_ROTATE;
				m_Transform.Reset();

				m_FixedPoint = m_PointSrc[TYPE_HITROI_CENTER];
				m_MovingPoint = m_PointSrc[m_eHitRoi];

				INFO_SIZE sz = this->GetSize(m_MovingPoint, m_FixedPoint);
				m_StartPhi = 180.0f * (REAL)atan2((REAL)sz.m_fcy, (REAL)sz.m_fcx) / (REAL)VALUE_PI;
			}
			else
			{
				m_eTransformRoi = TYPE_TRANSFORMROI_SCALE;
			}
		}
		else
		{
			m_eTransformRoi = TYPE_TRANSFORMROI_SCALE;
		}
#endif
	}

	if (TYPE_TRANSFORMROI_CREATE != m_eTransformRoi)
	{
		INFO_POINT PointZoom[ROICIRCLE_POINT_COUNT];
		memset(PointZoom, 0x00, sizeof(INFO_POINT)*ROICIRCLE_POINT_COUNT);
		ConvertPointPixelToDraw(m_PointSrc, PointZoom, ROICIRCLE_POINT_COUNT, fZoom);

		m_PointDest[TYPE_HITROI_TOPLEFT / 2] = PointZoom[TYPE_HITROI_TOPLEFT];
		m_PointDest[TYPE_HITROI_TOPRIGHT / 2] = PointZoom[TYPE_HITROI_TOPRIGHT];
		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2] = PointZoom[TYPE_HITROI_BOTTOMRIGHT];
		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2] = PointZoom[TYPE_HITROI_BOTTOMLEFT];
	}


	return TYPE_RESULTROI_CONTINUE;
}

TYPE_RESULTROI CCircleRoiTracker::OnEndTrack(TYPE_RESULTROI eResult, float fZoom, BOOL bErase)
{

	if (TYPE_RESULTROI_SUCCEEDED == eResult)
	{
		SetInitState(TRUE);

		// 0: TopLeft
		// 1: TopRight
		// 2: BottomRight
		// 3: BottomLeft
#ifdef DEF_ROTATE
		INFO_SIZE sz = this->GetSize(m_PointDest[TYPE_HITROI_TOPRIGHT / 2], m_PointDest[TYPE_HITROI_TOPLEFT / 2]);
		REAL phi = 180.0f * (REAL)atan2((REAL)sz.m_fcy, (REAL)sz.m_fcx) / (REAL)VALUE_PI;

		if (IsEnableRotate())
		{
			INFO_POINT PointZoom;
			ConvertPointPixelToDraw(&m_FixedPoint, &PointZoom, 1, fZoom);

			/// Check Rotated position
			m_Transform.Reset();
			m_Transform.Translate((REAL)-PointZoom.m_fx, (REAL)-PointZoom.m_fy);
			m_Transform.Rotate(phi*-1, MatrixOrderAppend);
			m_Transform.Translate((REAL)PointZoom.m_fx, (REAL)PointZoom.m_fy, MatrixOrderAppend);
			m_Transform.TransformPoints((Point *)m_PointDest, CIRCLE_POINT_COUNT);
			//*/
		}
#endif

		double w = m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx - m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx;
		double h = m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy - m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy;

		BOOL bW = FALSE;
		BOOL bH = FALSE;
		if (0>w)	bW = TRUE;
		if (0>h)	bH = TRUE;

		if (bW || bH)
		{
			SwapDestPoint(bW, bH);

			w = m_PointDest[2].m_fx - m_PointDest[0].m_fx;
			h = m_PointDest[2].m_fy - m_PointDest[0].m_fy;
		}

		{
			INFO_POINT PointZoom[ROICIRCLE_POINT_COUNT];
			memset(PointZoom, 0x00, sizeof(INFO_POINT)*ROICIRCLE_POINT_COUNT);
			ConvertPointDrawToPixel(m_PointDest, PointZoom, ROICIRCLE_POINT_COUNT, fZoom);

			w = PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx - PointZoom[TYPE_HITROI_TOPLEFT / 2].m_fx;
			h = PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy - PointZoom[TYPE_HITROI_TOPLEFT / 2].m_fy;


			m_PointSrc[TYPE_HITROI_TOPLEFT] = PointZoom[0];
			m_PointSrc[TYPE_HITROI_TOP] = PointZoom[0];
			m_PointSrc[TYPE_HITROI_TOP].m_fx += w / 2;

			m_PointSrc[TYPE_HITROI_TOPRIGHT] = PointZoom[1];
			m_PointSrc[TYPE_HITROI_RIGHT] = PointZoom[1];
			m_PointSrc[TYPE_HITROI_RIGHT].m_fy += h / 2;


			m_PointSrc[TYPE_HITROI_BOTTOMRIGHT] = PointZoom[2];
			m_PointSrc[TYPE_HITROI_BOTTOM] = PointZoom[2];
			m_PointSrc[TYPE_HITROI_BOTTOM].m_fx = m_PointSrc[TYPE_HITROI_TOP].m_fx;

			m_PointSrc[TYPE_HITROI_BOTTOMLEFT] = PointZoom[3];
			m_PointSrc[TYPE_HITROI_LEFT] = PointZoom[3];
			m_PointSrc[TYPE_HITROI_LEFT].m_fy = m_PointSrc[TYPE_HITROI_RIGHT].m_fy;

			m_PointSrc[TYPE_HITROI_CENTER].m_fx = m_PointSrc[TYPE_HITROI_TOP].m_fx;
			m_PointSrc[TYPE_HITROI_CENTER].m_fy = m_PointSrc[TYPE_HITROI_RIGHT].m_fy;
		}
#ifdef DEF_ROTATE
		if (IsEnableRotate())
		{
			m_PointSrc[TYPE_HITROI_TOP].m_fy -= ROTATE_POINT_DISTANCE;
			/// Check Rotated position
			m_Transform.Reset();
			m_Transform.Translate((REAL)-m_FixedPoint.m_fx, (REAL)-m_FixedPoint.m_fy);
			m_Transform.Rotate(phi, MatrixOrderAppend);
			m_Transform.Translate((REAL)m_FixedPoint.m_fx, (REAL)m_FixedPoint.m_fy, MatrixOrderAppend);
			m_Transform.TransformPoints((Point *)m_PointSrc, ROICIRCLE_POINT_COUNT);
			//*/
		}
#endif
	}

	if (bErase)
		Invalidate();

	m_eTransformRoi = TYPE_TRANSFORMROI_NONE;

	return eResult;
}

TYPE_RESULTROI CCircleRoiTracker::OnMouseMessage(UINT msg, UINT nFlags, INFO_POINT point, float fZoom)
{
	// 0: TopLeft
	// 1: TopRight
	// 2: BottomRight
	// 3: BottomLeft

	if (TYPE_TRANSFORMROI_CREATE == m_eTransformRoi)
	{
		const double r = GetRadious(m_PointDest[TYPE_HITROI_CENTER / 2], point);

		m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx = m_PointDest[TYPE_HITROI_CENTER / 2].m_fx - r;
		m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy = m_PointDest[TYPE_HITROI_CENTER / 2].m_fy - r;

		m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fx = m_PointDest[TYPE_HITROI_CENTER / 2].m_fx + r ;
		m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fy = m_PointDest[TYPE_HITROI_CENTER / 2].m_fy - r;

		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = m_PointDest[TYPE_HITROI_CENTER / 2].m_fx + r;
		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = m_PointDest[TYPE_HITROI_CENTER / 2].m_fy + r;

		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fx = m_PointDest[TYPE_HITROI_CENTER / 2].m_fx - r;
		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = m_PointDest[TYPE_HITROI_CENTER / 2].m_fy + r;

	}
	else if (TYPE_TRANSFORMROI_SCALE == m_eTransformRoi)
	{
#ifndef DEF_ROTATE
	#ifndef DEF_CIRCLE
		if (TYPE_HITROI_TOPLEFT == m_eHitRoi)
		{
			m_PointDest[TYPE_HITROI_TOPLEFT / 2] = point;

			m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fx = point.m_fx;
			m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fy = point.m_fy;
		}
		else if (TYPE_HITROI_TOP == m_eHitRoi)
		{
			m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy = point.m_fy;
			m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fy = point.m_fy;
		}
		else if (TYPE_HITROI_TOPRIGHT == m_eHitRoi)
		{
			m_PointDest[TYPE_HITROI_TOPRIGHT / 2] = point;

			m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = point.m_fx;
			m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy = point.m_fy;
		}
		else if (TYPE_HITROI_RIGHT == m_eHitRoi)
		{
			m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fx = point.m_fx;
			m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = point.m_fx;
		}
		else if (TYPE_HITROI_BOTTOMRIGHT == m_eHitRoi)
		{
			m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2] = point;

			m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fx = point.m_fx;
			m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = point.m_fy;
		}
		else if (TYPE_HITROI_BOTTOM == m_eHitRoi)
		{
			m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = point.m_fy;
			m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = point.m_fy;
		}
		else if (TYPE_HITROI_BOTTOMLEFT == m_eHitRoi)
		{
			m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2] = point;

			m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx = point.m_fx;
			m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = point.m_fy;

		}
		else if (TYPE_HITROI_LEFT == m_eHitRoi)
		{
			m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx = point.m_fx;
			m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fx = point.m_fx;
		}
	#else
		const double w = m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fx - m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx;
		const double h = m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fy - m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy;

		m_PointDest[TYPE_HITROI_CENTER / 2].m_fx = m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx + w / 2;
		m_PointDest[TYPE_HITROI_CENTER / 2].m_fy = m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy + h / 2;


		const double r = GetRadious(m_PointDest[TYPE_HITROI_CENTER / 2], point);

		m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx = m_PointDest[TYPE_HITROI_CENTER / 2].m_fx - r;
		m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy = m_PointDest[TYPE_HITROI_CENTER / 2].m_fy - r;

		m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fx = m_PointDest[TYPE_HITROI_CENTER / 2].m_fx + r;
		m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fy = m_PointDest[TYPE_HITROI_CENTER / 2].m_fy - r;

		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = m_PointDest[TYPE_HITROI_CENTER / 2].m_fx + r;
		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = m_PointDest[TYPE_HITROI_CENTER / 2].m_fy + r;

		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fx = m_PointDest[TYPE_HITROI_CENTER / 2].m_fx - r;
		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = m_PointDest[TYPE_HITROI_CENTER / 2].m_fy + r;
	#endif
#else
		INFO_SIZE sz = this->GetSize(m_PointSrc[TYPE_HITROI_TOPRIGHT], m_PointSrc[TYPE_HITROI_TOPLEFT]);
		REAL phi = 180.0f * (REAL)atan2((REAL)sz.m_fcy, (REAL)sz.m_fcx) / (REAL)VALUE_PI;
		if (0 == phi)
			ResizeCircle(m_eHitRoi, point);
		else
			ResizeRotatedCircle(m_eHitRoi, point, fZoom);
#endif
	}
	else if (TYPE_TRANSFORMROI_MOVE == m_eTransformRoi)
	{
		const double w = m_stPoint.m_fx - m_stPreviousPoint.m_fx;
		const double h = m_stPoint.m_fy - m_stPreviousPoint.m_fy;

		for (int i = 0; i < CIRCLE_POINT_COUNT; i++)
		{
			m_PointDest[i].m_fx += w;
			m_PointDest[i].m_fy += h;
		}
	}
#ifdef DEF_ROTATE	
	else if (TYPE_TRANSFORMROI_ROTATE == m_eTransformRoi)
	{
		INFO_POINT PointZoom;
		ConvertPointPixelToDraw(&m_FixedPoint, &PointZoom, 1, fZoom);

		INFO_SIZE sz = this->GetSize(point, PointZoom);

		REAL phi = 180.0f * atan2((REAL)sz.m_fcy, (REAL)sz.m_fcx) / (REAL)VALUE_PI - m_StartPhi;
		while (-180.0f >= phi)
			phi += 360.0f;	// (-180, 180)

		m_Transform.Reset();
		m_Transform.Translate((REAL)-PointZoom.m_fx, (REAL)-PointZoom.m_fy);
		m_Transform.Rotate(phi, MatrixOrderAppend);
		m_Transform.Translate((REAL)PointZoom.m_fx, (REAL)PointZoom.m_fy, MatrixOrderAppend);
	}
#endif

	return CRoiTracker::OnMouseMessage(msg, nFlags, point, fZoom);
}

TYPE_RESULTROI CCircleRoiTracker::OnMessage(MSG& msg)
{
	TYPE_RESULTROI eResult = TYPE_RESULTROI_FAILED;
	return eResult;
}

void CCircleRoiTracker::OnUpdate(CDC* pDC, UINT nMode, float fZoom)
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

#ifndef DEF_ROTATE	
		CGdiObject * pOldPen = pDC->SelectObject(pTrackPen);
		pDC->Ellipse( (int)m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx,
			(int)m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy,
			(int)m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx,
			(int)m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy);
		pDC->SelectObject(pOldPen);
#else
		if (TYPE_TRANSFORMROI_ROTATE == m_eTransformRoi)
		{
			INFO_POINT PointZoom[ROICIRCLE_POINT_COUNT];
			memset(PointZoom, 0x00, sizeof(INFO_POINT)*ROICIRCLE_POINT_COUNT);
			ConvertPointPixelToDraw(m_PointSrc, PointZoom, ROICIRCLE_POINT_COUNT, fZoom);

			m_PointDest[TYPE_HITROI_TOPLEFT / 2] = PointZoom[TYPE_HITROI_TOPLEFT];
			m_PointDest[TYPE_HITROI_TOPRIGHT / 2] = PointZoom[TYPE_HITROI_TOPRIGHT];
			m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2] = PointZoom[TYPE_HITROI_BOTTOMRIGHT];
			m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2] = PointZoom[TYPE_HITROI_BOTTOMLEFT];
			m_PointDest[TYPE_HITROI_CENTER / 2] = PointZoom[TYPE_HITROI_CENTER];

			m_Transform.TransformPoints((Point *)m_PointDest, CIRCLE_POINT_COUNT);
		}

		INFO_SIZE sz = this->GetSize(m_PointDest[TYPE_HITROI_TOPRIGHT / 2], m_PointDest[TYPE_HITROI_TOPLEFT / 2]);
		REAL phi = 180.0f * (REAL)atan2((REAL)sz.m_fcy, (REAL)sz.m_fcx) / (REAL)VALUE_PI;
		if (0 == phi)
		{
			CGdiObject * pOldPen = pDC->SelectObject(pTrackPen);
			pDC->Ellipse(m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx,
				m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy,
				m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx,
				m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy);
			pDC->SelectObject(pOldPen);
		}
		else
		{
			INFO_POINT PointCircle[CIRCLE_POINT_COUNT];
			memcpy(PointCircle, m_PointDest, sizeof(POINT)*CIRCLE_POINT_COUNT);

			m_FixedPoint = PointCircle[TYPE_HITROI_CENTER / 2];

			Matrix mCircle;
			mCircle.Reset();
			mCircle.Translate((REAL)-m_FixedPoint.m_fx, (REAL)-m_FixedPoint.m_fy);
			mCircle.Rotate(phi*(-1), MatrixOrderAppend);
			mCircle.Translate((REAL)m_FixedPoint.m_fx, (REAL)m_FixedPoint.m_fy, MatrixOrderAppend);
			mCircle.TransformPoints((Point *)PointCircle, CIRCLE_POINT_COUNT);

			mCircle.Reset();
			mCircle.Translate((REAL)-m_FixedPoint.m_fx, (REAL)-m_FixedPoint.m_fy);
			mCircle.Rotate(phi, MatrixOrderAppend);
			mCircle.Translate((REAL)m_FixedPoint.m_fx, (REAL)m_FixedPoint.m_fy, MatrixOrderAppend);

			Pen pen(Color(255, GetRValue(m_rgbTrack), GetRValue(m_rgbTrack), GetRValue(m_rgbTrack)), 1);

			Graphics graph(pDC->m_hDC);
			graph.SetTransform(&mCircle);
			graph.DrawEllipse(&pen,
				PointCircle[TYPE_HITROI_TOPLEFT / 2].m_fx,
				PointCircle[TYPE_HITROI_TOPLEFT / 2].m_fy,
				abs(PointCircle[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx - PointCircle[TYPE_HITROI_TOPLEFT / 2].m_fx),
				abs(PointCircle[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy - PointCircle[TYPE_HITROI_TOPLEFT / 2].m_fy));
		}
#endif

		delete pTrackPen;
	}

}

BOOL CCircleRoiTracker::SetCursor(CDC * pDC, float fZoom)
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

BOOL CCircleRoiTracker::SetCursor(TYPE_HITROI eHit)
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

void CCircleRoiTracker::SetInitState(BOOL bInit)
{
	m_bInit = bInit;
}

void CCircleRoiTracker::SwapDestPoint(BOOL bW, BOOL bH)
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
		const POINT stStart = m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2];
		const POINT stEnd = m_PointDest[TYPE_HITROI_TOPLEFT / 2];

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
			TYPE_HITROI_BOTTOMLEFT == m_eHitRoi)
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

void CCircleRoiTracker::MirrorDestPointH()
{
	const INFO_POINT stStart = m_PointDest[TYPE_HITROI_TOPLEFT / 2];
	const INFO_POINT stEnd = m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2];

	m_PointDest[TYPE_HITROI_TOPLEFT / 2] = m_PointDest[TYPE_HITROI_TOPRIGHT / 2];
	m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2] = m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2];

	m_PointDest[TYPE_HITROI_TOPRIGHT / 2] = stStart;
	m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2] = stEnd;
}

void CCircleRoiTracker::MirrorDestPointV()
{
	const INFO_POINT stStart = m_PointDest[TYPE_HITROI_TOPLEFT / 2];
	const INFO_POINT stEnd = m_PointDest[TYPE_HITROI_TOPRIGHT / 2];

	m_PointDest[TYPE_HITROI_TOPLEFT / 2] = m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2];
	m_PointDest[TYPE_HITROI_TOPRIGHT / 2] = m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2];

	m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2] = stStart;
	m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2] = stEnd;
}

int CCircleRoiTracker::GetPoint(LPINFO_POINT pPoint, int nLen)
{
	if (FALSE == IsInit())
	{
		return -1;
	}
	else
	{
		if (NULL == pPoint || CIRCLE_POINT_COUNT > nLen)
			return CIRCLE_POINT_COUNT;
	}

	int idx = 0;

	pPoint[idx] = m_PointSrc[TYPE_HITROI_TOPLEFT];		idx++;
	pPoint[idx] = m_PointSrc[TYPE_HITROI_TOPRIGHT];		idx++;
	pPoint[idx] = m_PointSrc[TYPE_HITROI_BOTTOMRIGHT];	idx++;
	pPoint[idx] = m_PointSrc[TYPE_HITROI_BOTTOMLEFT];	idx++;
	pPoint[idx] = m_PointSrc[TYPE_HITROI_CENTER];		idx++;

	return CIRCLE_POINT_COUNT;
}

int CCircleRoiTracker::SetPoint(const LPINFO_POINT pPoint, const int nLen, float fZoom, BOOL bErase)
{
	if (NULL == pPoint || CIRCLE_POINT_COUNT-1 > nLen)
		return CIRCLE_POINT_COUNT;

	int idx = 0;

	INFO_POINT PointZoom[CIRCLE_POINT_COUNT];
	ConvertPointPixelToDraw(pPoint, PointZoom, CIRCLE_POINT_COUNT, fZoom);

	m_PointDest[TYPE_HITROI_TOPLEFT / 2] = PointZoom[idx];		idx++;
	m_PointDest[TYPE_HITROI_TOPRIGHT / 2] = PointZoom[idx];		idx++;
	m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2] = PointZoom[idx];	idx++;
	m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2] = PointZoom[idx];	idx++;

	OnEndTrack(TYPE_RESULTROI_SUCCEEDED, fZoom, bErase);

	return CIRCLE_POINT_COUNT;
}


void CCircleRoiTracker::ResizeCircle(TYPE_HITROI eHitRoi, INFO_POINT point)
{
	if (TYPE_HITROI_TOPLEFT == eHitRoi)
	{
		m_PointDest[TYPE_HITROI_TOPLEFT / 2] = point;

		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fx = point.m_fx;
		m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fy = point.m_fy;
	}
	else if (TYPE_HITROI_TOP == eHitRoi)
	{
		m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy = point.m_fy;
		m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fy = point.m_fy;
	}
	else if (TYPE_HITROI_TOPRIGHT == eHitRoi)
	{
		m_PointDest[TYPE_HITROI_TOPRIGHT / 2] = point;

		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = point.m_fx;
		m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy = point.m_fy;
	}
	else if (TYPE_HITROI_RIGHT == eHitRoi)
	{
		m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fx = point.m_fx;
		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = point.m_fx;
	}
	else if (TYPE_HITROI_BOTTOMRIGHT == eHitRoi)
	{
		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2] = point;

		m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fx = point.m_fx;
		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = point.m_fy;
	}
	else if (TYPE_HITROI_BOTTOM == eHitRoi)
	{
		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = point.m_fy;
		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = point.m_fy;
	}
	else if (TYPE_HITROI_BOTTOMLEFT == eHitRoi)
	{
		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2] = point;

		m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx = point.m_fx;
		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = point.m_fy;

	}
	else if (TYPE_HITROI_LEFT == eHitRoi)
	{
		m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx = point.m_fx;
		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fx = point.m_fx;
	}
}

#ifdef DEF_ROTATE
void CCircleRoiTracker::ResizeRotatedCircle(TYPE_HITROI eHitRoi, INFO_POINT point, float fZoom)
{
	INFO_POINT PointZoom[ROICIRCLE_POINT_COUNT];
	memset(PointZoom, 0x00, sizeof(POINT)*ROICIRCLE_POINT_COUNT);
	ConvertPointPixelToDraw(m_PointSrc, PointZoom, ROICIRCLE_POINT_COUNT, fZoom);

	CPoint ptFixed;
	if (TYPE_HITROI_TOPLEFT == eHitRoi)
		ptFixed = PointZoom[TYPE_HITROI_BOTTOMRIGHT];
	else if (TYPE_HITROI_TOPRIGHT == eHitRoi)
		ptFixed = PointZoom[TYPE_HITROI_BOTTOMLEFT];
	else if (TYPE_HITROI_BOTTOMRIGHT == eHitRoi)
		ptFixed = PointZoom[TYPE_HITROI_TOPLEFT];
	else if (TYPE_HITROI_BOTTOMLEFT == eHitRoi)
		ptFixed = PointZoom[TYPE_HITROI_TOPRIGHT];

	else if (TYPE_HITROI_TOP == eHitRoi || TYPE_HITROI_RIGHT == eHitRoi)
		ptFixed = PointZoom[TYPE_HITROI_BOTTOMLEFT];
	else if (TYPE_HITROI_BOTTOM == eHitRoi || TYPE_HITROI_LEFT == eHitRoi)
		ptFixed = PointZoom[TYPE_HITROI_TOPRIGHT];


	/// Check Rotated position
	INFO_SIZE sz = this->GetSize(PointZoom[TYPE_HITROI_TOPRIGHT], PointZoom[TYPE_HITROI_TOPLEFT]);
	REAL phi = 180.0f * (REAL)atan2((REAL)sz.m_fcy, (REAL)sz.m_fcx) / (REAL)VALUE_PI;

	m_PointDest[TYPE_HITROI_TOPLEFT / 2] = PointZoom[TYPE_HITROI_TOPLEFT];
	m_PointDest[TYPE_HITROI_TOPRIGHT / 2] = PointZoom[TYPE_HITROI_TOPRIGHT];
	m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2] = PointZoom[TYPE_HITROI_BOTTOMRIGHT];
	m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2] = PointZoom[TYPE_HITROI_BOTTOMLEFT];

	m_Transform.Reset();
	m_Transform.Translate((REAL)-ptFixed.m_fx, (REAL)-ptFixed.m_fy);
	m_Transform.Rotate(phi*-1, MatrixOrderAppend);
	m_Transform.Translate((REAL)ptFixed.m_fx, (REAL)ptFixed.m_fy, MatrixOrderAppend);

	if (TYPE_HITROI_TOP == eHitRoi || TYPE_HITROI_RIGHT == eHitRoi ||
		TYPE_HITROI_BOTTOM == eHitRoi || TYPE_HITROI_LEFT == eHitRoi)
	{
		m_Transform.TransformPoints((Point *)m_PointDest, CIRCLE_POINT_COUNT);
	}
	m_Transform.TransformPoints((Point *)&point, 1);


	if (TYPE_HITROI_TOPLEFT == eHitRoi)
	{
		m_PointDest[TYPE_HITROI_TOPLEFT / 2] = point;

		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fx = point.m_fx;
		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = ptFixed.m_fy;
		m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fy = point.m_fy;
		m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fx = ptFixed.m_fx;
	}
	else if (TYPE_HITROI_TOPRIGHT == eHitRoi)
	{
		m_PointDest[TYPE_HITROI_TOPRIGHT / 2] = point;

		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = point.m_fx;
		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = ptFixed.m_fy;
		m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy = point.m_fy;
		m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx = ptFixed.m_fx;
	}
	else if (TYPE_HITROI_BOTTOMRIGHT == eHitRoi)
	{
		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2] = point;

		m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fx = point.m_fx;
		m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fy = ptFixed.m_fy;
		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = point.m_fy;
		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fx = ptFixed.m_fx;
	}
	else if (TYPE_HITROI_BOTTOMLEFT == eHitRoi)
	{
		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2] = point;

		m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx = point.m_fx;
		m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy = ptFixed.m_fy;
		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = point.m_fy;
		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = ptFixed.m_fx;
	}

	else if (TYPE_HITROI_TOP == eHitRoi)
	{
		m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy = point.m_fy;
		m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fy = point.m_fy;
	}
	else if (TYPE_HITROI_RIGHT == eHitRoi)
	{
		m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fx = point.m_fx;
		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = point.m_fx;
	}
	else if (TYPE_HITROI_BOTTOM == eHitRoi)
	{
		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = point.m_fy;
		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = point.m_fy;
	}
	else if (TYPE_HITROI_LEFT == eHitRoi)
	{
		m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx = point.m_fx;
		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fx = point.m_fx;
	}


	/// Check Rotated position
	m_Transform.Reset();
	m_Transform.Translate((REAL)-ptFixed.m_fx, (REAL)-ptFixed.m_fy);
	m_Transform.Rotate(phi, MatrixOrderAppend);
	m_Transform.Translate((REAL)ptFixed.m_fx, (REAL)ptFixed.m_fy, MatrixOrderAppend);
	m_Transform.TransformPoints((Point *)m_PointDest, CIRCLE_POINT_COUNT);

}
#endif



BOOL CCircleRoiTracker::SetWidth(DWORD dwWidth)
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
		// TYPE_HITROI_TOPLEFT
		// TYPE_HITROI_TOPRIGHT
		// TYPE_HITROI_BOTTOMRIGHT
		// TYPE_HITROI_BOTTOMLEFT
		// TYPE_HITROI_CENTER

#ifndef DEF_ROTATE
		pPointList[TYPE_HITROI_CENTER / 2].m_fx = pPointList[TYPE_HITROI_TOPLEFT / 2].m_fx + dwWidth / 2;
		pPointList[TYPE_HITROI_CENTER / 2].m_fy = pPointList[TYPE_HITROI_TOPLEFT / 2].m_fy + dwWidth / 2;

		pPointList[TYPE_HITROI_TOPRIGHT / 2].m_fx = pPointList[TYPE_HITROI_TOPLEFT / 2].m_fx + dwWidth;

		pPointList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = pPointList[TYPE_HITROI_TOPLEFT / 2].m_fx + dwWidth;
		pPointList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = pPointList[TYPE_HITROI_TOPLEFT / 2].m_fy + dwWidth;

		pPointList[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = pPointList[TYPE_HITROI_TOPLEFT / 2].m_fy + dwWidth;
#else
#endif

		SetPoint(pPointList, nLen, 1.0f);
	}

	delete[] pPointList;
	return TRUE;
}

BOOL CCircleRoiTracker::SetHeight(DWORD dwHeight)
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
		// TYPE_HITROI_TOPLEFT
		// TYPE_HITROI_TOPRIGHT
		// TYPE_HITROI_BOTTOMRIGHT
		// TYPE_HITROI_BOTTOMLEFT
		// TYPE_HITROI_CENTER
#ifndef DEF_ROTATE
		pPointList[TYPE_HITROI_CENTER / 2].m_fx = pPointList[TYPE_HITROI_TOPLEFT / 2].m_fx + dwHeight / 2;
		pPointList[TYPE_HITROI_CENTER / 2].m_fy = pPointList[TYPE_HITROI_TOPLEFT / 2].m_fy + dwHeight / 2;

		pPointList[TYPE_HITROI_TOPRIGHT / 2].m_fx = pPointList[TYPE_HITROI_TOPLEFT / 2].m_fx + dwHeight;

		pPointList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = pPointList[TYPE_HITROI_TOPLEFT / 2].m_fx + dwHeight;
		pPointList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = pPointList[TYPE_HITROI_TOPLEFT / 2].m_fy + dwHeight;

		pPointList[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = pPointList[TYPE_HITROI_TOPLEFT / 2].m_fy + dwHeight;
#else
#endif

		SetPoint(pPointList, nLen, 1.0f);
	}

	delete[] pPointList;
	return TRUE;
}

BOOL CCircleRoiTracker::MovePoint(int cx, int cy)
{
	if (FALSE == IsInit())
		return FALSE;

	for (int i = 0; i < ROICIRCLE_POINT_COUNT; i++)
	{
		m_PointSrc[i].m_fx += cx;
		m_PointSrc[i].m_fy += cy;
	}
	return TRUE;
}