#include "stdafx.h"
#include "RotateRectRoiTracker.h"

#include "RoiTrackerDC.h"

#include "../Common/Tracker/VideoOutArrow.h"

#include <vector>

CRotateRectRoiTracker::CRotateRectRoiTracker(CWnd* pWnd)
	: CRectRoiTracker(pWnd)
{
	m_Transform.Reset();
	m_StartPhi = 0;

}

CRotateRectRoiTracker::~CRotateRectRoiTracker()
{
}

BOOL CRotateRectRoiTracker::IsEnableRotate()
{
	return TRUE;
}

void CRotateRectRoiTracker::Draw(CDC* pDC, float fZoom)
{
	if (NULL == pDC)
		return;

	int nOldRop = pDC->SetROP2(R2_NOTXORPEN);
	DrawRoiRectangle(pDC, fZoom);
	pDC->SetROP2(nOldRop);

}

void CRotateRectRoiTracker::DrawRoi(CDC* pDC, INFO_SIZE stSize, float fZoom, void* pReserved)
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

void CRotateRectRoiTracker::DrawRoiEdgeLine(CDC* pDC, INFO_SIZE stSize, LPINFO_POINT pPointList, float fZoom, void* pReserved)
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

		int w = (int)stSize.m_fcx;
		int h = (int)stSize.m_fcy;

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

		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				UINT32& dwColor = ((UINT32 *)pvBits)[x + y * w];

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

void CRotateRectRoiTracker::DrawRoiHStepLine(CDC* pDC, LPINFO_POINT pPointList, DWORD dwStep, float fZoom, BOOL bLtoR)
{
	if (NULL == pDC || NULL == pPointList)
		return;
	
	const double w = pPointList[TYPE_HITROI_TOPRIGHT].m_fx - pPointList[TYPE_HITROI_TOPLEFT].m_fx;
	const double h = pPointList[TYPE_HITROI_BOTTOMLEFT].m_fy - pPointList[TYPE_HITROI_TOPLEFT].m_fy;

	const double fPhi = GetAngle(pPointList[TYPE_HITROI_TOPRIGHT], pPointList[TYPE_HITROI_TOPLEFT], TRUE);
	const float fStep = dwStep * fZoom;

	INFO_POINT ptCenter;
	ptCenter.m_fx = pPointList[TYPE_HITROI_TOPLEFT].m_fx + w / 2;
	ptCenter.m_fy = pPointList[TYPE_HITROI_TOPLEFT].m_fy + h / 2;


	//
	INFO_POINT pTransPoint[RECT_POINT_COUNT];
	pTransPoint[0] = pPointList[TYPE_HITROI_TOPLEFT];
	pTransPoint[1] = pPointList[TYPE_HITROI_TOPRIGHT];
	pTransPoint[2] = pPointList[TYPE_HITROI_BOTTOMRIGHT];
	pTransPoint[3] = pPointList[TYPE_HITROI_BOTTOMLEFT];

	// Transform
	m_Transform.Reset();
	m_Transform.Translate((REAL)-ptCenter.m_fx, (REAL)-ptCenter.m_fy);
	m_Transform.Rotate((REAL)(fPhi*-1), MatrixOrderAppend);
	m_Transform.Translate((REAL)ptCenter.m_fx, (REAL)ptCenter.m_fy, MatrixOrderAppend);

	{
		PointF pPtF[RECT_POINT_COUNT];
		for (int i = 0; i < RECT_POINT_COUNT; i++)
		{
			pPtF[i] = PointF((REAL)pTransPoint[i].m_fx, (REAL)pTransPoint[i].m_fy);
		}
		
		// Transfrom point...
		m_Transform.TransformPoints(pPtF, RECT_POINT_COUNT);
		
		for (int i = 0; i < RECT_POINT_COUNT; i++)
		{
			pTransPoint[i] = this->GetPointFromPointF(pPtF[i]);
		}
		
	}

	std::vector<INFO_LINE> EdgeList;

	{
		const INFO_POINT ptStart = pTransPoint[TYPE_HITROI_TOPLEFT / 2];
		const INFO_POINT ptEnd = pTransPoint[TYPE_HITROI_TOPRIGHT / 2];

		const double nEdgeW = pTransPoint[TYPE_HITROI_TOPRIGHT / 2].m_fx - pTransPoint[TYPE_HITROI_TOPLEFT / 2].m_fx;
		const double nEdgeH = pTransPoint[TYPE_HITROI_BOTTOMLEFT / 2].m_fy - pTransPoint[TYPE_HITROI_TOPLEFT / 2].m_fy;

		INFO_LINE stLine;
		stLine.m_ptStart = ptStart;
		stLine.m_ptEnd = ptEnd;

		for (float y = fStep; y < nEdgeH; y += fStep)
		{
			stLine.m_ptStart.m_fy = (ptStart.m_fy + y);
			stLine.m_ptEnd.m_fy = (ptEnd.m_fy + y);

			EdgeList.push_back(stLine);
		}
	}

	// Transform
	m_Transform.Reset();
	m_Transform.Translate((REAL)-ptCenter.m_fx, (REAL)-ptCenter.m_fy);
	m_Transform.Rotate((REAL)fPhi, MatrixOrderAppend);
	m_Transform.Translate((REAL)ptCenter.m_fx, (REAL)ptCenter.m_fy, MatrixOrderAppend);

	ARROWSTRUCT stArrow;
	stArrow.nWidth = (int)(ARROWWIDTH * fZoom);
	stArrow.fTheta = 0.3f;
	stArrow.bFill = TRUE;

	int nIdx = 0;


	int nCount = EdgeList.size();
	for (int i = 0; i < nCount; i++)
	{
		INFO_POINT pt1 = EdgeList[i].m_ptStart;
		INFO_POINT pt2 = EdgeList[i].m_ptEnd;

		PointF ptf01 = PointF((REAL)pt1.m_fx, (REAL)pt1.m_fy);
		PointF ptf02 = PointF((REAL)pt2.m_fx, (REAL)pt2.m_fy);

		m_Transform.TransformPoints(&ptf01, 1);
		m_Transform.TransformPoints(&ptf02, 1);

		pt1 = this->GetPointFromPointF(ptf01);
		pt2 = this->GetPointFromPointF(ptf02);

		if (0 == nIdx % 2)
		{
			double x1 = pt1.m_fx;
			double y1 = pt1.m_fy;
			double x2 = pt2.m_fx;
			double y2 = pt2.m_fy;

			if (FALSE == bLtoR)
			{
				x1 = pt2.m_fx;
				y1 = pt2.m_fy;
				x2 = pt1.m_fx;
				y2 = pt1.m_fy;
			}

			::MoveToEx(pDC->m_hDC, (int)x1, (int)y1, NULL);
			ArrowTo(pDC->m_hDC, (int)x2, (int)y2, &stArrow);
		}
		else
		{
			this->DrawLine(pDC, pt1, pt2);
		}

		nIdx++;
	}

	EdgeList.clear();

}

void CRotateRectRoiTracker::DrawRoiVStepLine(CDC* pDC, LPINFO_POINT pPointList, DWORD dwStep, float fZoom, BOOL bTtoB)
{
	if (NULL == pDC || NULL == pPointList)
		return;

	const double w = pPointList[TYPE_HITROI_TOPRIGHT].m_fx - pPointList[TYPE_HITROI_TOPLEFT].m_fx;
	const double h = pPointList[TYPE_HITROI_BOTTOMLEFT].m_fy - pPointList[TYPE_HITROI_TOPLEFT].m_fy;

	const double fPhi = GetAngle(pPointList[TYPE_HITROI_TOPRIGHT], pPointList[TYPE_HITROI_TOPLEFT], TRUE);
	const float fStep = dwStep * fZoom;

	INFO_POINT ptCenter;
	ptCenter.m_fx = pPointList[TYPE_HITROI_TOPLEFT].m_fx + w / 2;
	ptCenter.m_fy = pPointList[TYPE_HITROI_TOPLEFT].m_fy + h / 2;

	//
	INFO_POINT pTransPoint[RECT_POINT_COUNT];
	pTransPoint[0] = pPointList[TYPE_HITROI_TOPLEFT];
	pTransPoint[1] = pPointList[TYPE_HITROI_TOPRIGHT];
	pTransPoint[2] = pPointList[TYPE_HITROI_BOTTOMRIGHT];
	pTransPoint[3] = pPointList[TYPE_HITROI_BOTTOMLEFT];

	// Transform
	m_Transform.Reset();
	m_Transform.Translate((REAL)-ptCenter.m_fx, (REAL)-ptCenter.m_fy);
	m_Transform.Rotate((REAL)(fPhi*-1), MatrixOrderAppend);
	m_Transform.Translate((REAL)ptCenter.m_fx, (REAL)ptCenter.m_fy, MatrixOrderAppend);
	{
		PointF pPtF[RECT_POINT_COUNT];
		for (int i = 0; i < RECT_POINT_COUNT; i++)
		{
			pPtF[i] = PointF((REAL)pTransPoint[i].m_fx, (REAL)pTransPoint[i].m_fy);
		}
		// Transfrom point...
		m_Transform.TransformPoints(pPtF, RECT_POINT_COUNT);
		for (int i = 0; i < RECT_POINT_COUNT; i++)
		{
			pTransPoint[i] = this->GetPointFromPointF(pPtF[i]);
		}
	}

	std::vector<INFO_LINE> EdgeList;
	{
		const INFO_POINT ptStart = pTransPoint[TYPE_HITROI_TOPLEFT / 2];
		const INFO_POINT ptEnd = pTransPoint[TYPE_HITROI_BOTTOMLEFT / 2];

		const double nEdgeW = pTransPoint[TYPE_HITROI_TOPRIGHT / 2].m_fx - pTransPoint[TYPE_HITROI_TOPLEFT / 2].m_fx;
		const double nEdgeH = pTransPoint[TYPE_HITROI_BOTTOMLEFT / 2].m_fy - pTransPoint[TYPE_HITROI_TOPLEFT / 2].m_fy;

		INFO_LINE stLine;
		stLine.m_ptStart = ptStart;
		stLine.m_ptEnd = ptEnd;

		for (float x = fStep; x < nEdgeW; x += fStep)
		{
			stLine.m_ptStart.m_fx = (ptStart.m_fx + x);
			stLine.m_ptEnd.m_fx = (ptEnd.m_fx + x);

			EdgeList.push_back(stLine);
		}
	}

	// Transform
	m_Transform.Reset();
	m_Transform.Translate((REAL)-ptCenter.m_fx, (REAL)-ptCenter.m_fy);
	m_Transform.Rotate((REAL)fPhi, MatrixOrderAppend);
	m_Transform.Translate((REAL)ptCenter.m_fx, (REAL)ptCenter.m_fy, MatrixOrderAppend);

	ARROWSTRUCT stArrow;
	stArrow.nWidth = (int)(ARROWWIDTH * fZoom);
	stArrow.fTheta = 0.3f;
	stArrow.bFill = TRUE;

	int nIdx = 0;

	int nCount = EdgeList.size();
	for (int i = 0; i < nCount; i++)
	{
		INFO_POINT pt1 = EdgeList[i].m_ptStart;
		INFO_POINT pt2 = EdgeList[i].m_ptEnd;

		PointF ptf01 = PointF((REAL)pt1.m_fx, (REAL)pt1.m_fy);
		PointF ptf02 = PointF((REAL)pt2.m_fx, (REAL)pt2.m_fy);

		m_Transform.TransformPoints(&ptf01, 1);
		m_Transform.TransformPoints(&ptf02, 1);

		pt1 = this->GetPointFromPointF(ptf01);
		pt2 = this->GetPointFromPointF(ptf02);

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

	EdgeList.clear();

}



void CRotateRectRoiTracker::DrawRoiRectangle(CDC* pDC, float fZoom)
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
				
				if (TYPE_HITROI_TOP == i)
				{
					if (!IsBaseSelection())
						pDC->SelectStockObject(BLACK_BRUSH);
					else
						pDC->SelectStockObject(NULL_BRUSH);

					RECT rtDraw = GetRectangle(rect);
					pDC->Rectangle(&rtDraw);
				}
				else
				{
					if (IsBaseSelection())
						pDC->SelectStockObject(BLACK_BRUSH);
					else
						pDC->SelectStockObject(NULL_BRUSH);

					RECT rtDraw = GetRectangle(rect);
					pDC->Rectangle(&rtDraw);
				}
			}

			pDC->SelectObject(pOldPen);
			pDC->SelectObject(pOldBrush);

			delete pRectPen;
		}
		//*/

	}
}

void CRotateRectRoiTracker::DrawTracker(CDC* pDC, INFO_POINT pt1, INFO_POINT pt2, float fZoom, BOOL bDone)
{
	if (NULL == pDC || FALSE == IsInit())
		return;

	const int x = GetHScrollPos();
	const int y = GetVScrollPos();

	if (bDone && m_pTrackRect)
	{
		INFO_SIZE sz = this->GetSize(m_pTrackRect[TYPE_HITROI_TOPRIGHT / 2], m_pTrackRect[TYPE_HITROI_TOPLEFT / 2]);
		REAL phi = 180.0f * (REAL)atan2((REAL)sz.m_fcy, (REAL)sz.m_fcx) / (REAL)VALUE_PI;

		{
			INFO_POINT PointZoom;
			ConvertPointPixelToDraw(&m_FixedPoint, &PointZoom, 1, fZoom);

			/// Check Rotated position
			m_Transform.Reset();
			m_Transform.Translate((REAL)-PointZoom.m_fx, (REAL)-PointZoom.m_fy);
			m_Transform.Rotate(phi*-1, MatrixOrderAppend);
			m_Transform.Translate((REAL)PointZoom.m_fx, (REAL)PointZoom.m_fy, MatrixOrderAppend);
			
			{
				PointF pPtF[RECT_POINT_COUNT];
				for (int i = 0; i < RECT_POINT_COUNT; i++)
				{
					pPtF[i] = PointF((REAL)m_pTrackRect[i].m_fx, (REAL)m_pTrackRect[i].m_fy);
				}
				// Transfrom point...
				m_Transform.TransformPoints(pPtF, RECT_POINT_COUNT);
				for (int i = 0; i < RECT_POINT_COUNT; i++)
				{
					m_pTrackRect[i] = this->GetPointFromPointF(pPtF[i]);
				}
			}
			//*/
		}


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

		m_PointSrc[TYPE_HITROI_TOP].m_fy -= ROTATE_POINT_DISTANCE;
		m_PointSrc[TYPE_HITROI_BOTTOM].m_fy += ROTATE_POINT_DISTANCE;
		m_PointSrc[TYPE_HITROI_LEFT].m_fx -= ROTATE_POINT_DISTANCE;
		m_PointSrc[TYPE_HITROI_RIGHT].m_fx += ROTATE_POINT_DISTANCE;

		{
			/// Check Rotated position
			m_Transform.Reset();
			m_Transform.Translate((REAL)-m_FixedPoint.m_fx, (REAL)-m_FixedPoint.m_fy);
			m_Transform.Rotate(phi, MatrixOrderAppend);
			m_Transform.Translate((REAL)m_FixedPoint.m_fx, (REAL)m_FixedPoint.m_fy, MatrixOrderAppend);
			{
				PointF pPtF[ROIRECT_POINT_COUNT];
				for (int i = 0; i < ROIRECT_POINT_COUNT; i++)
				{
					pPtF[i] = PointF((REAL)m_PointSrc[i].m_fx, (REAL)m_PointSrc[i].m_fy);
				}
				// Transfrom point...
				m_Transform.TransformPoints(pPtF, ROIRECT_POINT_COUNT);
				for (int i = 0; i < ROIRECT_POINT_COUNT; i++)
				{
					m_PointSrc[i] = this->GetPointFromPointF(pPtF[i]);
				}

			}
			//*/
		}


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



TYPE_HITROI CRotateRectRoiTracker::HitTest(INFO_POINT point, float fZoom)
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
			return TYPE_HITROI_LINE_TOP;
		}

		eHitRoi = HitLineTest(point, TYPE_HITROI_TOPRIGHT, TYPE_HITROI_BOTTOMRIGHT, fZoom);
		if (TYPE_HITROI_NONE != eHitRoi)
		{
			return TYPE_HITROI_LINE_RIGHT;
		}

		eHitRoi = HitLineTest(point, TYPE_HITROI_BOTTOMLEFT, TYPE_HITROI_BOTTOMRIGHT, fZoom);
		if (TYPE_HITROI_NONE != eHitRoi)
		{
			return TYPE_HITROI_LINE_BOTTOM;
		}

		eHitRoi = HitLineTest(point, TYPE_HITROI_TOPLEFT, TYPE_HITROI_BOTTOMLEFT, fZoom);
		if (TYPE_HITROI_NONE != eHitRoi)
		{
			return TYPE_HITROI_LINE_LEFT;
		}
	}

	return eHitRoi;
}

TYPE_HITROI CRotateRectRoiTracker::HitLineTest(INFO_POINT point, TYPE_HITROI eStart, TYPE_HITROI eEnd, float fZoom)
{
	const int x = GetHScrollPos();
	const int y = GetVScrollPos();

	point.m_fx = ((point.m_fx + x) / fZoom);
	point.m_fy = ((point.m_fy + y) / fZoom);

	INFO_POINT stStart = GetHitPoint(m_PointSrc, eStart);
	INFO_POINT stEnd = GetHitPoint(m_PointSrc, eEnd);

	return HitTest(point, stStart, stEnd, fZoom);
}


TYPE_HITROI CRotateRectRoiTracker::HitTest(INFO_POINT point, INFO_POINT stStart, INFO_POINT stEnd, float fZoom)
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

//
TYPE_RESULTROI CRotateRectRoiTracker::OnBeginTrack(UINT nFlags, INFO_POINT point, float fZoom)
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
		if (TYPE_HITROI_TOP == m_eHitRoi || TYPE_HITROI_BOTTOM == m_eHitRoi ||
			TYPE_HITROI_RIGHT == m_eHitRoi || TYPE_HITROI_LEFT == m_eHitRoi)
		{
			m_eTransformRoi = TYPE_TRANSFORMROI_ROTATE;
			m_Transform.Reset();

			m_FixedPoint	= m_PointSrc[TYPE_HITROI_CENTER];
			m_MovingPoint	= m_PointSrc[m_eHitRoi];

			INFO_SIZE sz = GetSize(m_MovingPoint, m_FixedPoint);
			m_StartPhi = 180.0f * (REAL)atan2((REAL)sz.m_fcy, (REAL)sz.m_fcx) / (REAL)VALUE_PI;
		}
		else
		{
			m_eTransformRoi = TYPE_TRANSFORMROI_SCALE;
		}		
	}

	if (TYPE_TRANSFORMROI_CREATE != m_eTransformRoi)
	{
		INFO_POINT PointZoom[ROIRECT_POINT_COUNT];
		memset(PointZoom, 0x00, sizeof(POINT)*ROIRECT_POINT_COUNT);
		ConvertPointPixelToDraw(m_PointSrc, PointZoom, ROIRECT_POINT_COUNT, fZoom);

		m_PointDest[TYPE_HITROI_TOPLEFT / 2] = PointZoom[TYPE_HITROI_TOPLEFT];
		m_PointDest[TYPE_HITROI_TOPRIGHT / 2] = PointZoom[TYPE_HITROI_TOPRIGHT];
		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2] = PointZoom[TYPE_HITROI_BOTTOMRIGHT];
		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2] = PointZoom[TYPE_HITROI_BOTTOMLEFT];
	}

	return TYPE_RESULTROI_CONTINUE;
}

TYPE_RESULTROI CRotateRectRoiTracker::OnEndTrack(TYPE_RESULTROI eResult, float fZoom, BOOL bErase)
{
	if (TYPE_RESULTROI_SUCCEEDED == eResult)
	{
		SetInitState(TRUE);

		// 0: TopLeft
		// 1: TopRight
		// 2: BottomRight
		// 3: BottomLeft

		INFO_SIZE sz = GetSize(m_PointDest[TYPE_HITROI_TOPRIGHT / 2], m_PointDest[TYPE_HITROI_TOPLEFT / 2]);
		REAL phi = 180.0f * (REAL)atan2((REAL)sz.m_fcy, (REAL)sz.m_fcx) / (REAL)VALUE_PI;

		{

			INFO_POINT PointZoom;
			ConvertPointPixelToDraw(&m_FixedPoint, &PointZoom, 1, fZoom);

			/// Check Rotated position
			m_Transform.Reset();
			m_Transform.Translate((REAL)-PointZoom.m_fx, (REAL)-PointZoom.m_fy);
			m_Transform.Rotate(phi*-1, MatrixOrderAppend);
			m_Transform.Translate((REAL)PointZoom.m_fx, (REAL)PointZoom.m_fy, MatrixOrderAppend);
			{
				PointF pPtF[RECT_POINT_COUNT];
				for (int i = 0; i < RECT_POINT_COUNT; i++)
				{
					pPtF[i] = PointF((REAL)m_PointDest[i].m_fx, (REAL)m_PointDest[i].m_fy);
				}
				// Transfrom pint...
				m_Transform.TransformPoints(pPtF, RECT_POINT_COUNT);
				for (int i = 0; i < RECT_POINT_COUNT; i++)
				{
					m_PointDest[i] = this->GetPointFromPointF(pPtF[i]);
				}
			}
			//*/
		}

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

		///
		m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fx = m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx;
		m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fy = m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy;
		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fx = m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx;
		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy;

		w = m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx - m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx;
		h = m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy - m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy;
		//*/

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

		m_PointSrc[TYPE_HITROI_BOTTOMRIGHT]	= PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2];
		m_PointSrc[TYPE_HITROI_BOTTOM]		= PointZoom[TYPE_HITROI_BOTTOMRIGHT / 2];
		m_PointSrc[TYPE_HITROI_BOTTOM].m_fx = m_PointSrc[TYPE_HITROI_TOP].m_fx;

		m_PointSrc[TYPE_HITROI_BOTTOMLEFT]	= PointZoom[TYPE_HITROI_BOTTOMLEFT / 2];
		m_PointSrc[TYPE_HITROI_LEFT]		= PointZoom[TYPE_HITROI_BOTTOMLEFT / 2];
		m_PointSrc[TYPE_HITROI_LEFT].m_fy = m_PointSrc[TYPE_HITROI_RIGHT].m_fy;

		m_PointSrc[TYPE_HITROI_CENTER].m_fx = m_PointSrc[TYPE_HITROI_TOP].m_fx;
		m_PointSrc[TYPE_HITROI_CENTER].m_fy = m_PointSrc[TYPE_HITROI_RIGHT].m_fy;


		m_PointSrc[TYPE_HITROI_TOP].m_fy -= ROTATE_POINT_DISTANCE;
		m_PointSrc[TYPE_HITROI_BOTTOM].m_fy += ROTATE_POINT_DISTANCE;
		m_PointSrc[TYPE_HITROI_LEFT].m_fx -= ROTATE_POINT_DISTANCE;
		m_PointSrc[TYPE_HITROI_RIGHT].m_fx += ROTATE_POINT_DISTANCE;
		
		{
			/// Check Rotated position
			m_Transform.Reset();
			m_Transform.Translate((REAL)-m_FixedPoint.m_fx, (REAL)-m_FixedPoint.m_fy);
			m_Transform.Rotate(phi, MatrixOrderAppend);
			m_Transform.Translate((REAL)m_FixedPoint.m_fx, (REAL)m_FixedPoint.m_fy, MatrixOrderAppend);
			{
				PointF pPtF[ROIRECT_POINT_COUNT];
				for (int i = 0; i < ROIRECT_POINT_COUNT; i++)
				{
					pPtF[i] = PointF((REAL)m_PointSrc[i].m_fx, (REAL)m_PointSrc[i].m_fy);
				}
				// Transfrom point...
				m_Transform.TransformPoints(pPtF, ROIRECT_POINT_COUNT);
				for (int i = 0; i < ROIRECT_POINT_COUNT; i++)
				{
					m_PointSrc[i] = this->GetPointFromPointF(pPtF[i]);
				}
			}
			//*/
		}
	}

	if (bErase)
		Invalidate();

	m_eTransformRoi = TYPE_TRANSFORMROI_NONE;

	return eResult;
}

TYPE_RESULTROI CRotateRectRoiTracker::OnMouseMessage(UINT msg, UINT nFlags, INFO_POINT point, float fZoom)
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
			const double w = abs(point.m_fx - m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx);
			const double h = abs(point.m_fy - m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy);
			const double n = min(w, h);

			const INFO_POINT ptBase = m_PointDest[TYPE_HITROI_TOPLEFT / 2];

			if (point.m_fx > m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx)
			{
				m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fx = ptBase.m_fx + n;
				m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = ptBase.m_fx + n;
			}
			else if (point.m_fx < m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx)
			{
				m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fx = ptBase.m_fx - n;
				m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = ptBase.m_fx - n;
			}

			if (point.m_fy > m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy)
			{
				m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = ptBase.m_fy + n;
				m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = ptBase.m_fy + n;
			}
			else if (point.m_fy < m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy)
			{
				m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = ptBase.m_fy - n;
				m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = ptBase.m_fy - n;
			}
		}
	}
	else if (TYPE_TRANSFORMROI_SCALE == m_eTransformRoi)
	{
		INFO_SIZE sz = GetSize(m_PointSrc[TYPE_HITROI_TOPRIGHT], m_PointSrc[TYPE_HITROI_TOPLEFT]);
		REAL phi = 180.0f * (REAL)atan2((REAL)sz.m_fcy, (REAL)sz.m_fcx) / (REAL)VALUE_PI;

		TYPE_HITROI eHitRoi = m_eHitRoi;

		if (TYPE_HITROI_LINE_TOP == m_eHitRoi)			eHitRoi = TYPE_HITROI_TOP;
		else if (TYPE_HITROI_LINE_RIGHT == m_eHitRoi)	eHitRoi = TYPE_HITROI_RIGHT;
		else if (TYPE_HITROI_LINE_BOTTOM == m_eHitRoi)	eHitRoi = TYPE_HITROI_BOTTOM;
		else if (TYPE_HITROI_LINE_LEFT == m_eHitRoi)	eHitRoi = TYPE_HITROI_LEFT;

		if (0 == phi)
		{
			// Resize rectangle...
			ResizeRectangle(eHitRoi, point);
		}
		else
		{
			// Resize rotated rectangle...
			ResizeRotatedRectangle(eHitRoi, point, fZoom);
		}
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
	else if (TYPE_TRANSFORMROI_ROTATE == m_eTransformRoi)
	{
		INFO_POINT PointZoom;
		ConvertPointPixelToDraw(&m_FixedPoint, &PointZoom, 1, fZoom);

		INFO_SIZE sz = GetSize(point, PointZoom);
		REAL phi = 180.0f * atan2((REAL)sz.m_fcy, (REAL)sz.m_fcx) / (REAL)VALUE_PI - m_StartPhi;
		while (-180.0f >= phi)
			phi += 360.0f;	// (-180, 180)

		m_Transform.Reset();
		m_Transform.Translate((REAL)-PointZoom.m_fx, (REAL)-PointZoom.m_fy);
		m_Transform.Rotate(phi, MatrixOrderAppend);
		m_Transform.Translate((REAL)PointZoom.m_fx, (REAL)PointZoom.m_fy, MatrixOrderAppend);
	}

	return CRoiTracker::OnMouseMessage( msg, nFlags, point, fZoom);
}

TYPE_RESULTROI CRotateRectRoiTracker::OnMessage(MSG& msg)
{
	TYPE_RESULTROI eResult = TYPE_RESULTROI_FAILED;
	return eResult;
}

void CRotateRectRoiTracker::OnUpdate(CDC* pDC, UINT nMode, float fZoom)
{
	if (NULL == pDC)
		return;

	// Draw Tracking Rectangle.
	if (TYPE_TRANSFORMROI_NONE != m_eTransformRoi)
	{
		if (TYPE_TRANSFORMROI_ROTATE == m_eTransformRoi)
		{
			INFO_POINT PointZoom[ROIRECT_POINT_COUNT];
			memset(PointZoom, 0x00, sizeof(INFO_POINT)*ROIRECT_POINT_COUNT);
			ConvertPointPixelToDraw(m_PointSrc, PointZoom, ROIRECT_POINT_COUNT, fZoom);

			m_PointDest[TYPE_HITROI_TOPLEFT / 2] = PointZoom[TYPE_HITROI_TOPLEFT];
			m_PointDest[TYPE_HITROI_TOPRIGHT / 2] = PointZoom[TYPE_HITROI_TOPRIGHT];
			m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2] = PointZoom[TYPE_HITROI_BOTTOMRIGHT];
			m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2] = PointZoom[TYPE_HITROI_BOTTOMLEFT];
			{
				PointF pPtF[RECT_POINT_COUNT];
				for (int i = 0; i < RECT_POINT_COUNT; i++)
				{
					pPtF[i] = PointF((REAL)m_PointDest[i].m_fx, (REAL)m_PointDest[i].m_fy);
				}
				// Transfrom point...
				m_Transform.TransformPoints(pPtF, RECT_POINT_COUNT);
				for (int i = 0; i < RECT_POINT_COUNT; i++)
				{
					m_PointDest[i] = this->GetPointFromPointF(pPtF[i]);
				}
			}
		}

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

BOOL CRotateRectRoiTracker::SetCursor(CDC * pDC, float fZoom)
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

BOOL CRotateRectRoiTracker::SetCursor(TYPE_HITROI eHit)
{
	BOOL bResult = FALSE;

	int nIdx = (int)eHit;

	if (TYPE_HITROI_LINE_TOP == eHit || TYPE_HITROI_LINE_BOTTOM == eHit)
		nIdx = (int)TYPE_HITROI_TOP;
	else if (TYPE_HITROI_LINE_RIGHT == eHit || TYPE_HITROI_LINE_LEFT == eHit)
		nIdx = (int)TYPE_HITROI_RIGHT;

	if (m_hCur[nIdx])
	{
		int nDegree = (int)(GetAngle(m_PointSrc[TYPE_HITROI_TOPRIGHT], m_PointSrc[TYPE_HITROI_TOPLEFT], TRUE) + 360);
		nDegree %= 360;

		if ((45 < nDegree && 135 > nDegree) || (215 < nDegree && 315 > nDegree))
		{
			if (TYPE_HITROI_TOP == nIdx)
				nIdx = TYPE_HITROI_RIGHT;
			else if (TYPE_HITROI_RIGHT == nIdx)
				nIdx = TYPE_HITROI_TOP;

			if (TYPE_HITROI_TOPLEFT == nIdx || TYPE_HITROI_BOTTOMRIGHT == nIdx)
				nIdx = TYPE_HITROI_TOPRIGHT;
			else if (TYPE_HITROI_TOPRIGHT == nIdx || TYPE_HITROI_BOTTOMLEFT == nIdx)
				nIdx = TYPE_HITROI_TOPLEFT;
		}

		::SetCursor(m_hCur[nIdx]);
		bResult = TRUE;
	}

	return bResult;
}


void CRotateRectRoiTracker::ResizeRotatedRectangle(TYPE_HITROI eHitRoi, INFO_POINT point, float fZoom)
{
	const BOOL bShift = (::GetKeyState(VK_LSHIFT) & FLAG_LBUTTONDOWN || ::GetKeyState(VK_RSHIFT) & FLAG_LBUTTONDOWN);
	BOOL bReverse = FALSE;

	INFO_POINT PointZoom[ROIRECT_POINT_COUNT];
	memset(PointZoom, 0x00, sizeof(INFO_POINT)*ROIRECT_POINT_COUNT);
	ConvertPointPixelToDraw(m_PointSrc, PointZoom, ROIRECT_POINT_COUNT, fZoom);
	
	INFO_POINT ptFixed;
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
	INFO_SIZE sz = GetSize(PointZoom[TYPE_HITROI_TOPRIGHT], PointZoom[TYPE_HITROI_TOPLEFT]);
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
		{
			PointF pPtF[RECT_POINT_COUNT];
			for (int i = 0; i < RECT_POINT_COUNT; i++)
			{
				pPtF[i] = PointF((REAL)m_PointDest[i].m_fx, (REAL)m_PointDest[i].m_fy);
			}
			// Transfrom point...
			m_Transform.TransformPoints(pPtF, RECT_POINT_COUNT);
			for (int i = 0; i < RECT_POINT_COUNT; i++)
			{
				m_PointDest[i] = this->GetPointFromPointF(pPtF[i]);
			}
		}
	}
	PointF ptf = PointF((REAL)point.m_fx, (REAL)point.m_fy);
	m_Transform.TransformPoints(&ptf, 1);
	point = this->GetPointFromPointF(ptf);


	if (TYPE_HITROI_TOPLEFT == eHitRoi)
	{
		m_PointDest[TYPE_HITROI_TOPLEFT / 2] = point;

		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fx = point.m_fx;
		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = ptFixed.m_fy;
		m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fy = point.m_fy;
		m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fx = ptFixed.m_fx;

		if (bShift)
		{
			SetRectanglePoint(point,
				m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2],
				m_PointDest[TYPE_HITROI_TOPLEFT / 2],
				m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2],
				m_PointDest[TYPE_HITROI_TOPRIGHT / 2]);
		}

	}
	else if (TYPE_HITROI_TOPRIGHT == eHitRoi)
	{
		m_PointDest[TYPE_HITROI_TOPRIGHT / 2] = point;

		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = point.m_fx;
		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = ptFixed.m_fy;
		m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy = point.m_fy;
		m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fx = ptFixed.m_fx;

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
		m_PointDest[TYPE_HITROI_TOPRIGHT / 2].m_fy = ptFixed.m_fy;
		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = point.m_fy;
		m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2].m_fx = ptFixed.m_fx;

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
		m_PointDest[TYPE_HITROI_TOPLEFT / 2].m_fy = ptFixed.m_fy;
		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = point.m_fy;
		m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = ptFixed.m_fx;

		if (bShift)
		{
			SetRectanglePoint(point,
				m_PointDest[TYPE_HITROI_TOPRIGHT / 2],
				m_PointDest[TYPE_HITROI_BOTTOMLEFT / 2],
				m_PointDest[TYPE_HITROI_TOPLEFT / 2],
				m_PointDest[TYPE_HITROI_BOTTOMRIGHT / 2]);
		}
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
	{
		PointF pPtF[RECT_POINT_COUNT];
		for (int i = 0; i < RECT_POINT_COUNT; i++)
		{
			pPtF[i] = PointF((REAL)m_PointDest[i].m_fx, (REAL)m_PointDest[i].m_fy);
		}
		// Transfrom point...
		m_Transform.TransformPoints(pPtF, RECT_POINT_COUNT);
		for (int i = 0; i < RECT_POINT_COUNT; i++)
		{
			m_PointDest[i] = this->GetPointFromPointF(pPtF[i]);
		}

	}
}

BOOL CRotateRectRoiTracker::SetWidth(DWORD dwWidth)
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
		INFO_SIZE sz = GetSize(m_PointSrc[TYPE_HITROI_TOPRIGHT], m_PointSrc[TYPE_HITROI_TOPLEFT]);
		REAL phi = 180.0f * (REAL)atan2((REAL)sz.m_fcy, (REAL)sz.m_fcx) / (REAL)VALUE_PI;

		if (0 == phi)
		{
			pPointList[TYPE_HITROI_TOPRIGHT / 2].m_fx = pPointList[TYPE_HITROI_TOPLEFT / 2].m_fx + dwWidth;
			pPointList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = pPointList[TYPE_HITROI_BOTTOMLEFT / 2].m_fx + dwWidth;
		}
		else
		{
			double nLeft = 0;
			int nIdx = 0;
			for (int i = 0; i < nLen; i++)
			{
				if (0 == i)
				{
					nLeft = pPointList[i].m_fx;
					nIdx = i;
				}
				else
				{
					if (pPointList[i].m_fx < nLeft)
					{
						nLeft = pPointList[i].m_fx;
						nIdx = i;
					}
				}
			}
			int nIdxCross = (nIdx + 2) % 4;
			pPointList[nIdxCross].m_fx = nLeft + dwWidth;

			m_Transform.Reset();
			m_Transform.Translate((REAL)-pPointList[nIdx].m_fx, (REAL)-pPointList[nIdx].m_fy);
			m_Transform.Rotate(phi*-1, MatrixOrderAppend);
			m_Transform.Translate((REAL)pPointList[nIdx].m_fx, (REAL)pPointList[nIdx].m_fy, MatrixOrderAppend);
			{
				PointF* pPtF = new PointF[nLen];
				for (int i = 0; i < nLen; i++)
				{
					pPtF[i] = PointF((REAL)pPointList[i].m_fx, (REAL)pPointList[i].m_fy);
				}
				// Transfrom point...
				m_Transform.TransformPoints(pPtF, nLen);
				for (int i = 0; i < nLen; i++)
				{
					pPointList[i] = this->GetPointFromPointF(pPtF[i]);
				}

			}
			
			if (TYPE_HITROI_TOPLEFT / 2 == nIdx || TYPE_HITROI_BOTTOMRIGHT / 2 == nIdx)
			{
				pPointList[TYPE_HITROI_TOPRIGHT / 2].m_fx = pPointList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx;
				pPointList[TYPE_HITROI_TOPRIGHT / 2].m_fy = pPointList[TYPE_HITROI_TOPLEFT / 2].m_fy;

				pPointList[TYPE_HITROI_BOTTOMLEFT / 2].m_fx = pPointList[TYPE_HITROI_TOPLEFT / 2].m_fx;
				pPointList[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = pPointList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy;
			}
			else if (TYPE_HITROI_TOPRIGHT / 2 == nIdx || TYPE_HITROI_BOTTOMLEFT / 2 == nIdx)
			{
				pPointList[TYPE_HITROI_TOPLEFT / 2].m_fx = pPointList[TYPE_HITROI_BOTTOMLEFT / 2].m_fx;
				pPointList[TYPE_HITROI_TOPLEFT / 2].m_fy = pPointList[TYPE_HITROI_TOPRIGHT / 2].m_fy;

				pPointList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = pPointList[TYPE_HITROI_TOPRIGHT / 2].m_fx;
				pPointList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = pPointList[TYPE_HITROI_BOTTOMLEFT / 2].m_fy;

			}			

			m_Transform.Reset();
			m_Transform.Translate((REAL)-pPointList[nIdx].m_fx, (REAL)-pPointList[nIdx].m_fy);
			m_Transform.Rotate(phi, MatrixOrderAppend);
			m_Transform.Translate((REAL)pPointList[nIdx].m_fx, (REAL)pPointList[nIdx].m_fy, MatrixOrderAppend);
			{
				PointF* pPtF = new PointF[nLen];
				for (int i = 0; i < nLen; i++)
				{
					pPtF[i] = PointF((REAL)pPointList[i].m_fx, (REAL)pPointList[i].m_fy);
				}
				// Transfrom point...
				m_Transform.TransformPoints(pPtF, nLen);
				for (int i = 0; i < nLen; i++)
				{
					pPointList[i] = this->GetPointFromPointF(pPtF[i]);
				}
			}
		}

		SetPoint(pPointList, nLen, 1.0f);
	}

	delete[] pPointList;
	return TRUE;
}

BOOL CRotateRectRoiTracker::SetHeight(DWORD dwHeight)
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
		INFO_SIZE sz = GetSize(m_PointSrc[TYPE_HITROI_TOPRIGHT], m_PointSrc[TYPE_HITROI_TOPLEFT]);
		REAL phi = 180.0f * (REAL)atan2((REAL)sz.m_fcy, (REAL)sz.m_fcx) / (REAL)VALUE_PI;

		if (0 == phi)
		{
			pPointList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = pPointList[TYPE_HITROI_TOPLEFT / 2].m_fy + dwHeight;
			pPointList[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = pPointList[TYPE_HITROI_TOPRIGHT / 2].m_fy + dwHeight;

			SetPoint(pPointList, nLen, 1.0f);
		}
		else
		{
			double nTop = 0;
			int nIdx = 0;

			for (int i = 0; i < nLen; i++)
			{
				if (0 == i)
				{
					nTop = pPointList[i].m_fy;
					nIdx = i;
				}
				else
				{
					if (pPointList[i].m_fy < nTop)
					{
						nTop = pPointList[i].m_fy;
						nIdx = i;
					}
				}
			}
			
			int nIdxCross = (nIdx + 2) % 4;
			pPointList[nIdxCross].m_fy = nTop + dwHeight;

			m_Transform.Reset();
			m_Transform.Translate((REAL)-pPointList[nIdx].m_fx, (REAL)-pPointList[nIdx].m_fy);
			m_Transform.Rotate(phi*-1, MatrixOrderAppend);
			m_Transform.Translate((REAL)pPointList[nIdx].m_fx, (REAL)pPointList[nIdx].m_fy, MatrixOrderAppend);
			{
				PointF* pPtF = new PointF[nLen];
				for (int i = 0; i < nLen; i++)
				{
					pPtF[i] = PointF((REAL)pPointList[i].m_fx, (REAL)pPointList[i].m_fy);
				}
				// Transfrom point...
				m_Transform.TransformPoints(pPtF, nLen);
				for (int i = 0; i < nLen; i++)
				{
					pPointList[i] = this->GetPointFromPointF(pPtF[i]);
				}
			}

			if (TYPE_HITROI_TOPLEFT / 2 == nIdx || TYPE_HITROI_BOTTOMRIGHT / 2 == nIdx)
			{
				pPointList[TYPE_HITROI_TOPRIGHT / 2].m_fx = pPointList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx;
				pPointList[TYPE_HITROI_TOPRIGHT / 2].m_fy = pPointList[TYPE_HITROI_TOPLEFT / 2].m_fy;

				pPointList[TYPE_HITROI_BOTTOMLEFT / 2].m_fx = pPointList[TYPE_HITROI_TOPLEFT / 2].m_fx;
				pPointList[TYPE_HITROI_BOTTOMLEFT / 2].m_fy = pPointList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy;
			}
			else if (TYPE_HITROI_TOPRIGHT / 2 == nIdx || TYPE_HITROI_BOTTOMLEFT / 2 == nIdx)
			{
				pPointList[TYPE_HITROI_TOPLEFT / 2].m_fx = pPointList[TYPE_HITROI_BOTTOMLEFT / 2].m_fx;
				pPointList[TYPE_HITROI_TOPLEFT / 2].m_fy = pPointList[TYPE_HITROI_TOPRIGHT / 2].m_fy;

				pPointList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fx = pPointList[TYPE_HITROI_TOPRIGHT / 2].m_fx;
				pPointList[TYPE_HITROI_BOTTOMRIGHT / 2].m_fy = pPointList[TYPE_HITROI_BOTTOMLEFT / 2].m_fy;

			}

			m_Transform.Reset();
			m_Transform.Translate((REAL)-pPointList[nIdx].m_fx, (REAL)-pPointList[nIdx].m_fy);
			m_Transform.Rotate(phi, MatrixOrderAppend);
			m_Transform.Translate((REAL)pPointList[nIdx].m_fx, (REAL)pPointList[nIdx].m_fy, MatrixOrderAppend);
			{
				PointF* pPtF = new PointF[nLen];
				for (int i = 0; i < nLen; i++)
				{
					pPtF[i] = PointF((REAL)pPointList[i].m_fx, (REAL)pPointList[i].m_fy);
				}
				// Transfrom point...
				m_Transform.TransformPoints(pPtF, nLen);
				for (int i = 0; i < nLen; i++)
				{
					pPointList[i] = this->GetPointFromPointF(pPtF[i]);
				}
			}
		}


		SetPoint(pPointList, nLen, 1.0f);
	}

	delete[] pPointList;
	return TRUE;
}

