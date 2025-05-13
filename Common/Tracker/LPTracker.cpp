#include "stdafx.h"
#include "LPTracker.h"

#include <cmath>

#pragma comment (lib, "Gdiplus.lib")
#if defined(_WIN64)
	#ifdef _DEBUG
		#pragma comment (lib, "LibTrackerd_x64.lib")
	#else
	#pragma comment (lib, "LibTracker_x64.lib")
	#endif
#else
	#ifdef _DEBUG
		#pragma comment (lib, "LibTrackerd.lib")
	#else
		#pragma comment (lib, "LibTracker.lib")
	#endif
#endif

#define VALUE_PI		(4.0f * atan(1.0f))


CLPTracker::CLPTracker()
{
	m_hTracker = NULL;
	m_pWnd = NULL;
	m_bOuterScroll = FALSE;
	m_bSelected = FALSE;
	m_bBaseSelected = FALSE;
}

CLPTracker::CLPTracker(CWnd* pWnd)
{
	m_hTracker = NULL;
	m_pWnd = pWnd;
}

CLPTracker::~CLPTracker()
{
	Deinit();
}

BOOL CLPTracker::IsInit()
{
	return ::IsInitTracker(m_hTracker);
}

BOOL CLPTracker::Init(TYPE_TRACKER eTracker)
{
	if (NULL == m_pWnd)
		return FALSE;

	BOOL bResult = Init(eTracker, m_pWnd);
	return bResult;
}

BOOL CLPTracker::Init(TYPE_TRACKER eTracker, CWnd* pWnd)
{
	Deinit();
	m_pWnd = pWnd;

	m_hTracker = ::InitTracker(eTracker, pWnd);
	if (NULL == m_hTracker)
		return FALSE;

	return TRUE;
}

void CLPTracker::Deinit()
{
	::DeinitTracker(m_hTracker);
	m_hTracker = NULL;
}

void CLPTracker::Clear()
{
	::ClearTracker(m_hTracker);
}

TYPE_TRACKER CLPTracker::GetType()
{
	return ::GetTrackerType(m_hTracker);
}

TYPE_HITTRACKER CLPTracker::GetTrackerHitPosition(TRACKPOINT point, float fZoom)
{
	return ::GetTrackerHitPosition(m_hTracker, point, fZoom);
}

BOOL CLPTracker::SetCursor(CDC* pDC, float fZoom)
{
	return ::SetTrackerCursor(m_hTracker, pDC, fZoom);
}

BOOL CLPTracker::Track(CDC* pDC, UINT nFlags, TRACKPOINT point, float fZoom, BOOL bErase)
{
	return ::RunTracker(m_hTracker, pDC, nFlags, point, fZoom, bErase);
}

void CLPTracker::Draw(CDC* pDC, float fZoom)
{
	::DrawTracker(m_hTracker, pDC, fZoom);
}

void CLPTracker::Draw(CDC* pDC, TYPE_TRACKER eTracker, LPTRACKPOINT pPointList, int nLen, SIZE stSize, float fZoom, void* pReserved)
{
	Init(eTracker);
	SetCurOuterScrollWindow();

	SetPoint(pPointList, nLen, fZoom, FALSE);

	TRACKSIZE stTrackSize;
	stTrackSize.m_fcx = stSize.cx;
	stTrackSize.m_fcy = stSize.cy;

	::DrawRoi(m_hTracker, pDC, stTrackSize, fZoom, pReserved);
}

void CLPTracker::DrawTracker(CDC* pDC, TRACKPOINT pt1, TRACKPOINT pt2, float fZoom, BOOL bDone)
{
	::DrawMoveTracker(m_hTracker, pDC, pt1, pt2, fZoom, bDone);
}


#ifdef DEF_LPAPP
BOOL CLPTracker::GetRoi(CLP_ROI* pRoi)
{
	const int nCount = GetPoint(NULL, 0);
	if (NULL == pRoi || 0 > nCount)
	{
		return FALSE;
	}
	
	const TYPE_TRACKER eTracker = GetType();
	BOOL bResult = FALSE;

	LPTRACKPOINT pPointList = new TRACKPOINT[nCount];
	if(NULL==pPointList)
		return FALSE;

	GetPoint(pPointList, nCount);

	if (TYPE_TRACKER_CIRCLE == eTracker)
	{
		//			0		   1
		//			*----------*
		//
		//			3		   2
		//			*----------*
		pRoi->m_eROIType = eROIType_Circle;
		pRoi->m_iCountPts = 4;

		pRoi->m_stPosROIStart.m_fX = (float)pPointList[0].m_fx;
		pRoi->m_stPosROIStart.m_fY = (float)pPointList[0].m_fy;

		pRoi->m_stPosROIEnd.m_fX = (float)pPointList[2].m_fx;
		pRoi->m_stPosROIEnd.m_fY = (float)pPointList[2].m_fy;

		pRoi->m_iROIWidth = (unsigned int)std::abs((int)pRoi->m_stPosROIEnd.m_fX - (int)pRoi->m_stPosROIStart.m_fX) + 1;
		pRoi->m_iROIHeight = (unsigned int)std::abs((int)pRoi->m_stPosROIEnd.m_fY - (int)pRoi->m_stPosROIStart.m_fY) + 1;

		pRoi->m_stPosROICenter.m_fX = (pRoi->m_stPosROIStart.m_fX + pRoi->m_iROIWidth / 2);
		pRoi->m_stPosROICenter.m_fY = (pRoi->m_stPosROIStart.m_fY + pRoi->m_iROIHeight / 2);


		stPOINT point;
		for (int i = 0; i < (int)pRoi->m_iCountPts; i++)
		{
			point.m_fX = (float)pPointList[i].m_fx;
			point.m_fY = (float)pPointList[i].m_fy;

			pRoi->m_pstPosArray.push_back(point);
		}

		int nBufLen = 0;
		int nW = 0;
		int nH = 0;
		bResult = GetMaskBuffer(eTracker, pPointList, nCount, &(pRoi->m_pMaskBuffer), &nBufLen, nW, nH);

		pRoi->m_iROIWidth = nW;
		pRoi->m_iROIHeight = min(pRoi->m_iROIHeight, nH);

		///
		pRoi->m_stPosROIStart.m_fX = (float)((int)pRoi->m_stPosROIStart.m_fX);
		pRoi->m_stPosROIStart.m_fY = (float)((int)pRoi->m_stPosROIStart.m_fY);
		pRoi->m_stPosROIEnd.m_fX = (float)((int)pRoi->m_stPosROIStart.m_fX + pRoi->m_iROIWidth - 1);
		pRoi->m_stPosROIEnd.m_fY = (float)((int)pRoi->m_stPosROIStart.m_fY + pRoi->m_iROIHeight - 1);
		
		pRoi->m_stPosROICenter.m_fX = (pRoi->m_stPosROIStart.m_fX + pRoi->m_iROIWidth / 2);
		pRoi->m_stPosROICenter.m_fY = (pRoi->m_stPosROIStart.m_fY + pRoi->m_iROIHeight / 2);
		//*/
	}
	else if (TYPE_TRACKER_LINE == eTracker)
	{
		pRoi->m_eROIType = eROIType_Line;
		pRoi->m_iCountPts = 2;

		pRoi->m_stPosROIStart.m_fX = (float)pPointList[0].m_fx;
		pRoi->m_stPosROIStart.m_fY = pPointList[0].m_fy;

		pRoi->m_stPosROIEnd.m_fX = (float)pPointList[1].m_fx;
		pRoi->m_stPosROIEnd.m_fY = (float)pPointList[1].m_fy;

		pRoi->m_iROIWidth = (unsigned int)std::abs((int)pRoi->m_stPosROIEnd.m_fX - (int)pRoi->m_stPosROIStart.m_fX) + 1;
		pRoi->m_iROIHeight = (unsigned int)std::abs((int)pRoi->m_stPosROIEnd.m_fY - (int)pRoi->m_stPosROIStart.m_fY) + 1;

		pRoi->m_stPosROICenter.m_fX = (pRoi->m_stPosROIStart.m_fX + pRoi->m_iROIWidth / 2);
		pRoi->m_stPosROICenter.m_fY = (pRoi->m_stPosROIStart.m_fY + pRoi->m_iROIHeight / 2);


		pRoi->m_pstPosArray.clear();
		pRoi->m_pstPosArray.push_back(pRoi->m_stPosROIStart);
		pRoi->m_pstPosArray.push_back(pRoi->m_stPosROIEnd);


		int nBufLen = 0;
		int nW = 0;
		int nH = 0;
		bResult = GetMaskBuffer(eTracker, pPointList, nCount, &(pRoi->m_pMaskBuffer), &nBufLen, nW, nH);

		pRoi->m_iROIWidth = nW;
		pRoi->m_iROIHeight = min(pRoi->m_iROIHeight, nH);

		///
		if (pRoi->m_stPosROIStart.m_fX < pRoi->m_stPosROIEnd.m_fX)
		{
			pRoi->m_stPosROIStart.m_fX = (float)((int)pRoi->m_stPosROIStart.m_fX);
			pRoi->m_stPosROIEnd.m_fX = (float)((int)pRoi->m_stPosROIStart.m_fX + (pRoi->m_iROIWidth - 1));
			pRoi->m_stPosROICenter.m_fX = (pRoi->m_stPosROIStart.m_fX + pRoi->m_iROIWidth / 2);
		}
		else
		{
			pRoi->m_stPosROIStart.m_fX = (float)((int)pRoi->m_stPosROIStart.m_fX);
			pRoi->m_stPosROIEnd.m_fX = (float)((int)pRoi->m_stPosROIStart.m_fX - (pRoi->m_iROIWidth - 1));
			pRoi->m_stPosROICenter.m_fX = (pRoi->m_stPosROIStart.m_fX - pRoi->m_iROIWidth / 2);
		}

		if (pRoi->m_stPosROIStart.m_fY < pRoi->m_stPosROIEnd.m_fY)
		{
			pRoi->m_stPosROIStart.m_fY = (float)((int)pRoi->m_stPosROIStart.m_fY);
			pRoi->m_stPosROIEnd.m_fY = (float)((int)pRoi->m_stPosROIStart.m_fY + (pRoi->m_iROIHeight - 1));
			pRoi->m_stPosROICenter.m_fY = (pRoi->m_stPosROIStart.m_fY + pRoi->m_iROIHeight / 2);

		}
		else
		{
			pRoi->m_stPosROIStart.m_fY = (float)((int)pRoi->m_stPosROIStart.m_fY);
			pRoi->m_stPosROIEnd.m_fY = (float)((int)pRoi->m_stPosROIStart.m_fY - (pRoi->m_iROIHeight - 1));
			pRoi->m_stPosROICenter.m_fY = (pRoi->m_stPosROIStart.m_fY - pRoi->m_iROIHeight / 2);
		}
		//*/
	}
	else if (TYPE_TRACKER_POINT == eTracker)
	{
		pRoi->m_eROIType = eROIType_Point;
		pRoi->m_iCountPts = 1;

		pRoi->m_stPosROIStart.m_fX = (float)pPointList[0].m_fx;
		pRoi->m_stPosROIStart.m_fY = (float)pPointList[0].m_fy;

		pRoi->m_stPosROIEnd = pRoi->m_stPosROIStart;
		pRoi->m_stPosROICenter = pRoi->m_stPosROIStart;

		pRoi->m_pstPosArray.clear();
		pRoi->m_pstPosArray.push_back(pRoi->m_stPosROIStart);

		pRoi->m_iROIWidth = 1;
		pRoi->m_iROIHeight = 1;

		int nBufLen = 0;
		int nW = 0;
		int nH = 0;
		bResult = GetMaskBuffer(eTracker, pPointList, nCount, &(pRoi->m_pMaskBuffer), &nBufLen, nW, nH);

		//pRoi->m_iROIWidth = nW;
		//pRoi->m_iROIHeight = min(pRoi->m_iROIHeight, nH);

	}
	else if (TYPE_TRACKER_POLYGON == eTracker)
	{
		pRoi->m_eROIType = eROIType_Polygon;
		pRoi->m_iCountPts = nCount;

		pRoi->m_pstPosArray.clear();
		for (int i = 0; i < nCount; i++)
		{
			stPOINT pt;
			pt.m_fX = (float)pPointList[i].m_fx;
			pt.m_fY = (float)pPointList[i].m_fy;

			pRoi->m_pstPosArray.push_back(pt);
		}

		RECT rtRect = GetPositionRect(pPointList, nCount);
		pRoi->m_iROIWidth = std::abs(rtRect.right - rtRect.left) + 1;
		pRoi->m_iROIHeight = std::abs(rtRect.bottom - rtRect.top) + 1;

		pRoi->m_stPosROIStart.m_fX = (float)rtRect.left;
		pRoi->m_stPosROIStart.m_fY = (float)rtRect.top;

		pRoi->m_stPosROIEnd.m_fX = (float)rtRect.right;
		pRoi->m_stPosROIEnd.m_fY = (float)rtRect.bottom;

		pRoi->m_stPosROICenter.m_fX = (float)(rtRect.left + pRoi->m_iROIWidth / 2);
		pRoi->m_stPosROICenter.m_fY = (float)(rtRect.top + pRoi->m_iROIHeight / 2);


		int nBufLen = 0;
		int nW = 0;
		int nH = 0;
		bResult = GetMaskBuffer(eTracker, pPointList, nCount, &(pRoi->m_pMaskBuffer), &nBufLen, nW, nH);

		pRoi->m_iROIWidth = nW;
		pRoi->m_iROIHeight = min(pRoi->m_iROIHeight, nH);

		///
		pRoi->m_stPosROIStart.m_fX = (float)((int)pRoi->m_stPosROIStart.m_fX);
		pRoi->m_stPosROIStart.m_fY = (float)((int)pRoi->m_stPosROIStart.m_fY);
		pRoi->m_stPosROIEnd.m_fX = (float)((int)pRoi->m_stPosROIStart.m_fX + pRoi->m_iROIWidth - 1);
		pRoi->m_stPosROIEnd.m_fY = (float)((int)pRoi->m_stPosROIStart.m_fY + pRoi->m_iROIHeight - 1);
		
		pRoi->m_stPosROICenter.m_fX = (pRoi->m_stPosROIStart.m_fX + pRoi->m_iROIWidth / 2);
		pRoi->m_stPosROICenter.m_fY = (pRoi->m_stPosROIStart.m_fY + pRoi->m_iROIHeight / 2);
		//*/
	}
	else if (TYPE_TRACKER_RECT == eTracker)
	{
		//			0		   1
		//			*----------*
		//
		//			3		   2
		//			*----------*
		pRoi->m_eROIType = eROIType_Rectangular;

		pRoi->m_stPosROIStart.m_fX = (float)pPointList[0].m_fx;
		pRoi->m_stPosROIStart.m_fY = (float)pPointList[0].m_fy;

		pRoi->m_stPosROIEnd.m_fX = (float)pPointList[2].m_fx;
		pRoi->m_stPosROIEnd.m_fY = (float)pPointList[2].m_fy;

		pRoi->m_iROIWidth = (unsigned int)(std::abs((int)pRoi->m_stPosROIEnd.m_fX - (int)pRoi->m_stPosROIStart.m_fX) + 1);
		pRoi->m_iROIHeight = (unsigned int)(std::abs((int)pRoi->m_stPosROIEnd.m_fY - (int)pRoi->m_stPosROIStart.m_fY) + 1);

		pRoi->m_stPosROICenter.m_fX = (pRoi->m_stPosROIStart.m_fX + pRoi->m_iROIWidth / 2);
		pRoi->m_stPosROICenter.m_fY = (pRoi->m_stPosROIStart.m_fY + pRoi->m_iROIHeight / 2);

		pRoi->m_iCountPts = 4;

		stPOINT point;

		for (int i = 0; i < (int)pRoi->m_iCountPts; i++)
		{
			point.m_fX = (float)pPointList[i].m_fx;
			point.m_fY = (float)pPointList[i].m_fy;

			pRoi->m_pstPosArray.push_back(point);
		}

		int nBufLen = 0;
		int nW = 0;
		int nH = 0;
		bResult = GetMaskBuffer(eTracker, pPointList, nCount, &(pRoi->m_pMaskBuffer), &nBufLen, nW, nH);

		pRoi->m_iROIWidth = nW;
		pRoi->m_iROIHeight = min(pRoi->m_iROIHeight, nH);

		///
		pRoi->m_stPosROIStart.m_fX = (float)((int)pRoi->m_stPosROIStart.m_fX);
		pRoi->m_stPosROIStart.m_fY = (float)((int)pRoi->m_stPosROIStart.m_fY);
		pRoi->m_stPosROIEnd.m_fX = (float)((int)pRoi->m_stPosROIStart.m_fX + pRoi->m_iROIWidth - 1);
		pRoi->m_stPosROIEnd.m_fY = (float)((int)pRoi->m_stPosROIStart.m_fY + pRoi->m_iROIHeight - 1);
		
		pRoi->m_stPosROICenter.m_fX = (pRoi->m_stPosROIStart.m_fX + pRoi->m_iROIWidth / 2);
		pRoi->m_stPosROICenter.m_fY = (pRoi->m_stPosROIStart.m_fY + pRoi->m_iROIHeight / 2);
		//*/
	}
	else if (TYPE_TRACKER_RECT_ROTATE == eTracker)
	{
		//			0		   1
		//			*----------*
		//
		//			3		   2
		//			*----------*
		pRoi->m_eROIType = eROIType_RectangularRotate;
		pRoi->m_iCountPts = nCount;

		pRoi->m_pstPosArray.clear();
		for (int i = 0; i < nCount; i++)
		{
			stPOINT pt;
			pt.m_fX = (float)pPointList[i].m_fx;
			pt.m_fY = (float)pPointList[i].m_fy;

			pRoi->m_pstPosArray.push_back(pt);
		}

		// Angle
		BOOL bDegree = TRUE;
		pRoi->m_dROIAngle = GetAngle(pPointList[2], pPointList[3], bDegree);

		if (0 > pRoi->m_dROIAngle)
			pRoi->m_dROIAngle += 360;


		RECT rtRect = GetPositionRect(pPointList, nCount);

		// 
		double minX = pPointList[0].m_fx;
		double minY = pPointList[0].m_fy;
		double maxX = pPointList[0].m_fx;
		double maxY = pPointList[0].m_fy;

		for (int i = 0; i < nCount; i++)
		{
			if (pPointList[i].m_fx < minX)		minX = pPointList[i].m_fx;
			if (pPointList[i].m_fy < minY)		minY = pPointList[i].m_fy;

			if (pPointList[i].m_fx > maxX)		maxX = pPointList[i].m_fx;
			if (pPointList[i].m_fy > maxY)		maxY = pPointList[i].m_fy;
		}
		
		pRoi->m_stPosROIStart.m_fX = (float)minX;
		pRoi->m_stPosROIStart.m_fY = (float)minY;
		pRoi->m_stPosROIEnd.m_fX = (float)maxX;
		pRoi->m_stPosROIEnd.m_fY = (float)maxY;

		pRoi->m_iROIWidth = std::abs((int)maxX - (int)minX) + 1;
		pRoi->m_iROIHeight = std::abs((int)maxY - (int)minY) + 1;

		pRoi->m_stPosROICenter.m_fX = pRoi->m_stPosROIStart.m_fX + pRoi->m_iROIWidth / 2;
		pRoi->m_stPosROICenter.m_fY = pRoi->m_stPosROIStart.m_fY + pRoi->m_iROIHeight / 2;


		int nBufLen = 0;
		int nW = 0;
		int nH = 0;
		bResult = GetMaskBuffer(eTracker, pPointList, nCount, &(pRoi->m_pMaskBuffer), &nBufLen, nW, nH);

		pRoi->m_iROIWidth = nW;
		pRoi->m_iROIHeight = min(pRoi->m_iROIHeight, nH);

		///
		pRoi->m_stPosROIStart.m_fX = (float)((int)pRoi->m_stPosROIStart.m_fX);
		pRoi->m_stPosROIStart.m_fY = (float)((int)pRoi->m_stPosROIStart.m_fY);
		pRoi->m_stPosROIEnd.m_fX = (float)((int)pRoi->m_stPosROIStart.m_fX + pRoi->m_iROIWidth - 1);
		pRoi->m_stPosROIEnd.m_fY = (float)((int)pRoi->m_stPosROIStart.m_fY + pRoi->m_iROIHeight - 1);
		
		pRoi->m_stPosROICenter.m_fX = (pRoi->m_stPosROIStart.m_fX + pRoi->m_iROIWidth / 2);
		pRoi->m_stPosROICenter.m_fY = (pRoi->m_stPosROIStart.m_fY + pRoi->m_iROIHeight / 2);
		//*/
	}
	else if (TYPE_TRACKER_RING == eTracker)
	{
		// Handles are numbered clockwise
		// Draw arc, counterclockwise.
		//
		//			0		   1
		//			*----------*
		//	*4
		//			3		   2
		//			*----------*
		// The center point is handle 4
		pRoi->m_eROIType = eROIType_Ring;
		pRoi->m_iCountPts = nCount;

		pRoi->m_pstPosArray.clear();
		for (int i = 0; i < nCount; i++)
		{
			stPOINT pt;
			pt.m_fX = (float)pPointList[i].m_fx;
			pt.m_fY = (float)pPointList[i].m_fy;

			pRoi->m_pstPosArray.push_back(pt);
		}

		//
		pRoi->m_dRadiusLarge = GetRadious(pPointList[1], pPointList[4]);
		pRoi->m_dRadiusSmall = GetRadious(pPointList[0], pPointList[4]);

		//
		pRoi->m_stPosROICenter.m_fX = (float)pPointList[4].m_fx;
		pRoi->m_stPosROICenter.m_fY = (float)pPointList[4].m_fy;

		pRoi->m_stPosROIStart.m_fX = (float)(pRoi->m_stPosROICenter.m_fX - pRoi->m_dRadiusLarge);
		pRoi->m_stPosROIStart.m_fY = (float)(pRoi->m_stPosROICenter.m_fY - pRoi->m_dRadiusLarge);

		pRoi->m_stPosROIEnd.m_fX = (pRoi->m_stPosROICenter.m_fX + pRoi->m_dRadiusLarge);
		pRoi->m_stPosROIEnd.m_fY = (float)(pRoi->m_stPosROICenter.m_fY + pRoi->m_dRadiusLarge);

		//
		pRoi->m_iROIWidth = (unsigned int)(std::abs((int)pRoi->m_stPosROIEnd.m_fX - (int)pRoi->m_stPosROIStart.m_fX) + 1);
		pRoi->m_iROIHeight = (unsigned int)(std::abs((int)pRoi->m_stPosROIEnd.m_fY - (int)pRoi->m_stPosROIStart.m_fY) + 1);

		BOOL bDegree = TRUE;
		pRoi->m_dAngleStart = GetAngle(pPointList[2], pPointList[4], bDegree);
		pRoi->m_dAngleEnd = GetAngle(pPointList[1], pPointList[4], bDegree);
		if (pRoi->m_dAngleStart == pRoi->m_dAngleEnd)
		{
			if (bDegree)
			{
				pRoi->m_dAngleEnd += 360;
			}
			else
			{
				pRoi->m_dAngleEnd += (2 * VALUE_PI);
			}
		}

		if (0 > pRoi->m_dAngleStart)
			pRoi->m_dAngleStart += 360;

		if (0 > pRoi->m_dAngleEnd)
			pRoi->m_dAngleEnd += 360;


		int nBufLen = 0;
		int nW = 0;
		int nH = 0;
		bResult = GetMaskBuffer(eTracker, pPointList, nCount, &(pRoi->m_pMaskBuffer), &nBufLen, nW, nH);

		pRoi->m_iROIWidth = nW;
		pRoi->m_iROIHeight = min(pRoi->m_iROIHeight, nH);

		///
		pRoi->m_stPosROIStart.m_fX = (float)((int)pRoi->m_stPosROIStart.m_fX);
		pRoi->m_stPosROIStart.m_fY = (float)((int)pRoi->m_stPosROIStart.m_fY);
		pRoi->m_stPosROIEnd.m_fX = (float)((int)pRoi->m_stPosROIStart.m_fX + pRoi->m_iROIWidth - 1);
		pRoi->m_stPosROIEnd.m_fY = (float)((int)pRoi->m_stPosROIStart.m_fY + pRoi->m_iROIHeight - 1);
		
		pRoi->m_stPosROICenter.m_fX = (pRoi->m_stPosROIStart.m_fX + pRoi->m_iROIWidth / 2);
		pRoi->m_stPosROICenter.m_fY = (pRoi->m_stPosROIStart.m_fY + pRoi->m_iROIHeight / 2);
		//*/
	}

	if (pPointList)
	{
		delete [] pPointList;
	}

	return bResult;
}
#endif


double CLPTracker::GetAngle(TRACKPOINT pt1, TRACKPOINT pt2, BOOL bDegree)
{
	CSize sz = CPoint((int)pt1.m_fx, (int)pt1.m_fy) - CPoint((int)pt2.m_fx, (int)pt2.m_fy);

	double phi = 0.0f;
	if (bDegree)
	{
		phi = 180.0f * atan2((double)sz.cy, (double)sz.cx) / (double)VALUE_PI;
		while (-180.0f >= phi)
		{
			phi += 360.0f;	// (-180, 180)
		}
	}
	else
	{
		phi = (double)atan2((double)sz.cy, (double)sz.cx);
	}

	return phi;
}

int CLPTracker::GetRadious(TRACKPOINT pt1, TRACKPOINT pt2)
{
	CSize sz = CPoint((int)pt1.m_fx, (int)pt1.m_fy) - CPoint((int)pt2.m_fx, (int)pt2.m_fy);
	const int r = (int)sqrt(pow((double)sz.cx, 2) + pow((double)sz.cy, 2));

	return r;
}

BOOL CLPTracker::GetMaskBuffer(TYPE_TRACKER eTracker, LPTRACKPOINT pPointList, int nLen, unsigned char** ppBuf, int* pBufLen, int& nW, int& nH)
{
	BOOL bResult = FALSE;

	if (TYPE_TRACKER_CIRCLE == eTracker)
	{
		bResult = GetCircleMaskBuffer(pPointList, nLen, ppBuf, pBufLen, nW, nH);
	}
	else if (TYPE_TRACKER_LINE == eTracker)
	{
		bResult = GetLineMaskBuffer(pPointList, nLen, ppBuf, pBufLen, nW, nH);
	}
	else if (TYPE_TRACKER_POINT == eTracker)
	{
		bResult = GetPointMaskBuffer(pPointList, nLen, ppBuf, pBufLen, nW, nH);
	}
	else if (TYPE_TRACKER_POLYGON == eTracker)
	{
		bResult = GetPolygonMaskBuffer(pPointList, nLen, ppBuf, pBufLen, nW, nH);
	}
	else if (TYPE_TRACKER_RECT == eTracker)
	{
		bResult = GetRectMaskBuffer(pPointList, nLen, ppBuf, pBufLen, nW, nH);
	}
	else if (TYPE_TRACKER_RECT_ROTATE == eTracker)
	{
		bResult = GetRectRotateMaskBuffer(pPointList, nLen, ppBuf, pBufLen, nW, nH);
	}
	else if (TYPE_TRACKER_RING == eTracker)
	{
		bResult = GetRingMaskBuffer(pPointList, nLen, ppBuf, pBufLen, nW, nH);
	}
	return bResult;
}

BOOL CLPTracker::GetCircleMaskBuffer(LPTRACKPOINT pPointList, int nLen, unsigned char** ppBuf, int* pBufLen, int& nW, int& nH)
{
	const int POINTCOUNT = 4;

	if (NULL == pPointList || POINTCOUNT > nLen)
		return FALSE;

	const RECT rtPos = GetPositionRect(pPointList, nLen);

	const int w = rtPos.right - rtPos.left + 1;
	const int h = rtPos.bottom - rtPos.top + 1;
	nW = w;
	nH = h;

	Bitmap bmp(w, h + MASKPAD, PixelFormat8bppIndexed);
	ColorPalette* pPalette =  GetPalette();
	bmp.SetPalette(pPalette);


	Graphics* pGraph = Graphics::FromImage(&bmp);
		
	SolidBrush brWhite(Color(0xFF, 0xFF, 0xFF));  // R, G, B
	SolidBrush brBlack(Color(0x00, 0x00, 0x00));  // R, G, B
	
	pGraph->FillRectangle(&brBlack, 0, 0, w, h);
	pGraph->FillEllipse(&brWhite, 0, 0, w, h);
	
	GetBuffer(bmp, ppBuf, pBufLen, nW, nH);

	if (pPalette)
		delete[] pPalette;
	if (pGraph)
		delete pGraph;

	return TRUE;
}

BOOL CLPTracker::GetLineMaskBuffer(LPTRACKPOINT pPointList, int nLen, unsigned char** ppBuf, int* pBufLen, int& nW, int& nH)
{
	const int POINTCOUNT = 2;

	if (NULL == pPointList || POINTCOUNT > nLen)
		return FALSE;

	const RECT rtPos = GetPositionRect(pPointList, nLen);

	const int w = rtPos.right - rtPos.left + 1;
	const int h = rtPos.bottom - rtPos.top + 1;
	nW = w;
	nH = h;

	Bitmap bmp(w, h + MASKPAD, PixelFormat8bppIndexed);
	ColorPalette* pPalette = GetPalette();
	bmp.SetPalette(pPalette);


	Graphics* pGraph = Graphics::FromImage(&bmp);

	SolidBrush brWhite(Color(0xFF, 0xFF, 0xFF));  // R, G, B
	SolidBrush brBlack(Color(0x00, 0x00, 0x00));  // R, G, B
	Pen pen(&brWhite);

	pGraph->FillRectangle(&brBlack, 0, 0, w, h);

	const int x1 = (int)pPointList[0].m_fx - rtPos.left;
	const int y1 = (int)pPointList[0].m_fy - rtPos.top;
	const int x2 = (int)pPointList[1].m_fx - rtPos.left;
	const int y2 = (int)pPointList[1].m_fy - rtPos.top;

	pGraph->DrawLine(&pen, x1, y1, x2, y2);

	GetBuffer(bmp, ppBuf, pBufLen, nW, nH);

	if (pPalette)
		delete[] pPalette;

	if (pGraph)
		delete pGraph;

	return TRUE;
}

BOOL CLPTracker::GetPointMaskBuffer(LPTRACKPOINT pPointList, int nLen, unsigned char** ppBuf, int* pBufLen, int& nW, int& nH)
{
	const int POINTCOUNT = 1;

	if (NULL == pPointList || POINTCOUNT > nLen)
		return FALSE;
	
	nW = 1;
	nH = 1;

	*ppBuf = new unsigned char[1];
	if (NULL == ppBuf)
		return FALSE;

	unsigned char* pBuf = *ppBuf;
	pBuf[0] = 0xFF;

	return TRUE;
}

BOOL CLPTracker::GetPolygonMaskBuffer(LPTRACKPOINT pPointList, int nLen, unsigned char** ppBuf, int* pBufLen, int& nW, int& nH)
{
	const int POINTCOUNT = 2;	// Minimum

	if (NULL == pPointList || POINTCOUNT > nLen)
		return FALSE;

	const RECT rtPos = GetPositionRect(pPointList, nLen);

	const int w = rtPos.right - rtPos.left + 1;
	const int h = rtPos.bottom - rtPos.top + 1;
	nW = w;
	nH = h;

	Bitmap bmp(w, h + MASKPAD, PixelFormat8bppIndexed);
	ColorPalette* pPalette = GetPalette();
	bmp.SetPalette(pPalette);

	Point* pPtList = new Point[nLen];
	if (NULL == pPtList)
		return FALSE;

	for (int i = 0; nLen > i; i++)
	{
		pPtList[i].X = (int)pPointList[i].m_fx - rtPos.left;
		pPtList[i].Y = (int)pPointList[i].m_fy - rtPos.top;
	}


	Graphics* pGraph = Graphics::FromImage(&bmp);

	SolidBrush brWhite(Color(0xFF, 0xFF, 0xFF));  // R, G, B
	SolidBrush brBlack(Color(0x00, 0x00, 0x00));  // R, G, B

	pGraph->FillRectangle(&brBlack, 0, 0, w, h);
	pGraph->FillPolygon(&brWhite, pPtList, nLen);

	GetBuffer(bmp, ppBuf, pBufLen, nW, nH);

	if (pPalette)
		delete[] pPalette;

	if (pPtList)
		delete[] pPtList;

	if (pGraph)
		delete pGraph;

	return TRUE;
}

BOOL CLPTracker::GetRectMaskBuffer(LPTRACKPOINT pPointList, int nLen, unsigned char** ppBuf, int* pBufLen, int& nW, int& nH)
{
	const int POINTCOUNT = 4;

	if (NULL == pPointList || POINTCOUNT > nLen)
		return FALSE;
	
	const RECT rtPos = GetPositionRect(pPointList, nLen);

	const int w = rtPos.right - rtPos.left + 1;
	const int h = rtPos.bottom - rtPos.top + 1;
	nW = w;
	nH = h;

	Bitmap bmp(w, h + MASKPAD, PixelFormat8bppIndexed);
	ColorPalette* pPalette = GetPalette();
	bmp.SetPalette(pPalette);


	Graphics* pGraph = Graphics::FromImage(&bmp);

	SolidBrush brWhite(Color(0xFF, 0xFF, 0xFF));  // R, G, B
	SolidBrush brBlack(Color(0x00, 0x00, 0x00));  // R, G, B

	//pGraph->FillRectangle(&brBlack, 0, 0, w, h);
	pGraph->FillRectangle(&brWhite, 0, 0, w, h);


	BOOL bResult = GetBuffer(bmp, ppBuf, pBufLen, nW, nH);

	if (pPalette)
		delete[] pPalette;

	if (pGraph)
		delete pGraph;

	return bResult;
}

BOOL CLPTracker::GetRectRotateMaskBuffer(LPTRACKPOINT pPointList, int nLen, unsigned char** ppBuf, int* pBufLen, int& nW, int& nH)
{
	const int POINTCOUNT = 4;

	if (NULL == pPointList || POINTCOUNT > nLen)
		return FALSE;

	GetPolygonMaskBuffer(pPointList, nLen, ppBuf, pBufLen, nW, nH);

	return TRUE;
}

BOOL CLPTracker::GetRingMaskBuffer(LPTRACKPOINT pPointList, int nLen, unsigned char** ppBuf, int* pBufLen, int& nW, int& nH)
{
	const int POINTCOUNT = 5;

	const int nRectLen = 2;
	RECT pRect[nRectLen];

	const int nLargeIdx = 0;
	const int nSmallIdx = 1;

	if (NULL == pPointList || POINTCOUNT > nLen)
		return FALSE;

	// Handles are numbered clockwise, like this:
	// 
	// Draw arc, counterclockwise.
	//
	//			0		   1
	//			*----------*		// End
	//	*4
	//			3		   2
	//			*----------*		// Start
	//
	// The center point is handle 4
	if (FALSE == GetPositionRectFromRing(pPointList, nLen, pRect, nRectLen))
		return FALSE;
	
	BOOL bDegree = TRUE;
	const int w = pRect[nLargeIdx].right - pRect[nLargeIdx].left + 1;
	const int h = pRect[nLargeIdx].bottom - pRect[nLargeIdx].top + 1;
	
	nW = w;
	nH = h;

	Bitmap bmp(w, h + MASKPAD, PixelFormat8bppIndexed);
	ColorPalette* pPalette = GetPalette();
	bmp.SetPalette(pPalette);

	Graphics* pGraph = Graphics::FromImage(&bmp);
	SolidBrush brWhite(Color(0xFF, 0xFF, 0xFF));  // R, G, B
	SolidBrush brBlack(Color(0x00, 0x00, 0x00));  // R, G, B

	pGraph->FillRectangle(&brBlack, 0, 0, w, h);

	double fStart = GetAngle(pPointList[4], pPointList[2], bDegree);
	double fEnd = GetAngle(pPointList[4], pPointList[1], bDegree);
	if (0 > fStart)
		fStart += 360;
	if (0 > fEnd)
		fEnd += 360;

	double fSweep = fEnd - fStart;
	if (fStart == fEnd)
		fSweep = 360;
	else if (fEnd < fStart)
		fSweep = 360 + fSweep;
	
	fStart += 180;
	if (fStart+0.0001f > 360)
		fStart -= 360;
	pGraph->FillPie(&brWhite, 0, 0, w, h, (REAL)fStart, (REAL)fSweep);


	pGraph->FillEllipse(&brBlack, 
		pRect[nSmallIdx].left,
		pRect[nSmallIdx].top,
		pRect[nSmallIdx].right - pRect[nSmallIdx].left,
		pRect[nSmallIdx].bottom - pRect[nSmallIdx].top);

	GetBuffer(bmp, ppBuf, pBufLen, nW, nH);

	if (pPalette)
		delete[] pPalette;

	if (pGraph)
		delete pGraph;

	return TRUE;
}

BOOL CLPTracker::GetPositionRectFromRing(LPTRACKPOINT pPointList, int nLen, RECT* pRect, int nRectLen)
{
	if (NULL == pPointList || 5 > nLen || NULL == pRect || 2>nRectLen)
		return FALSE;

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

	const int nLarge = 0;
	const int nSmall = 1;

	// Large Rect
	const int nLargeR	= GetRadious(pPointList[4], pPointList[1]);
	pRect[nLarge].left	= 0;
	pRect[nLarge].top	= 0;
	pRect[nLarge].right	= nLargeR * 2;
	pRect[nLarge].bottom= nLargeR * 2;

	// Small Rect
	const int nSmallR	= GetRadious(pPointList[4], pPointList[0]);
	pRect[nSmall].left	= nLargeR - nSmallR;
	pRect[nSmall].top	= nLargeR - nSmallR;
	pRect[nSmall].right = nLargeR + nSmallR;
	pRect[nSmall].bottom= nLargeR + nSmallR;

	return TRUE;
}


RECT CLPTracker::GetPositionRect(LPTRACKPOINT pPointList, int nLen)
{
	RECT rtRect;
	memset(&rtRect, 0x00, sizeof(RECT));

	if (NULL == pPointList || 0 >= nLen)
		return rtRect;
		
	if (m_hTracker)
	{
		TRACKRECT rtTrackRect = ::GetPositionRect(m_hTracker, pPointList, nLen);
		rtRect.left = (long)(rtTrackRect.m_fleft + 0.00015);
		rtRect.top = (long)(rtTrackRect.m_ftop + 0.00015);
		rtRect.right = (long)(rtTrackRect.m_fright + 0.00015);
		rtRect.bottom = (long)(rtTrackRect.m_fbottom + 0.00015);
	}
	else
	{
		double minX = pPointList[0].m_fx;
		double maxX = pPointList[0].m_fx;
		double minY = pPointList[0].m_fy;
		double maxY = pPointList[0].m_fy;

		for (int i = 0; nLen > i; i++)
		{
			// X
			if (minX > pPointList[i].m_fx)
				minX = pPointList[i].m_fx;
			if (maxX < pPointList[i].m_fx)
				maxX = pPointList[i].m_fx;

			// Y
			if (minY > pPointList[i].m_fy)
				minY = pPointList[i].m_fy;
			if (maxY < pPointList[i].m_fy)
				maxY = pPointList[i].m_fy;
		}
		rtRect.left = (long)(minX + 0.00015);
		rtRect.top = (long)(minY + 0.00015);
		rtRect.right = (long)(maxX + 0.00015);
		rtRect.bottom = (long)(maxY + 0.00015);
	}

	return rtRect;
}



int CLPTracker::GetPoint(LPTRACKPOINT pPoint, int nLen)
{
	const int nCount = ::GetTrackerPoint(m_hTracker, pPoint, nLen);
	return nCount;
}

int CLPTracker::SetPoint(LPTRACKPOINT pPoint, int nLen, float fZoom, BOOL bErase)
{
	const int nCount = ::SetTrackerPoint(m_hTracker, pPoint, nLen, fZoom, bErase);
	return nCount;
}

ColorPalette* CLPTracker::GetPalette()
{
	ColorPalette* pPalette = (ColorPalette*)malloc(sizeof(ColorPalette) + 256 * sizeof(ARGB));
	pPalette->Count = 256;
	pPalette->Flags = PaletteFlagsGrayScale;
	ARGB* pColor = &pPalette->Entries[0];
	for (int i = 0; i < 256; i++)
	{
		pColor[i] = Color::MakeARGB(0xFF, i, i, i);
	}

	return pPalette;
}

BOOL CLPTracker::GetBuffer(Bitmap& bmp, unsigned char** ppBuf, int* pBufLen, const int nW, const int nH)
{
	BitmapData bitmapData;
	Rect rtBmp(0, 0, nW, nH);

	if (Gdiplus::Ok == bmp.LockBits(&rtBmp, Gdiplus::ImageLockModeRead, bmp.GetPixelFormat(), &bitmapData))
	{
		const int len = bitmapData.Height * std::abs(bitmapData.Stride);

		*pBufLen = nW * nH;
		if (*ppBuf)
		{
			delete[](*ppBuf);
			(*ppBuf) = NULL;
		}
		*ppBuf = new unsigned char[len];
		if (NULL == *ppBuf)
			return FALSE;

		unsigned char* pSrc = (unsigned char*)bitmapData.Scan0;
		unsigned char* pDest = *ppBuf;

		// Line Dump...
		for (int y = 0; y < nH; y++)
		{
			memcpy(pDest, pSrc, nW);

			pSrc += abs(bitmapData.Stride);
			pDest += nW;
		}
		bmp.UnlockBits(&bitmapData);
	}


	return TRUE;
}

void CLPTracker::SetOuterScrollWindow(BOOL bOuter)
{
	m_bOuterScroll = bOuter;
	::SetOuterScroll(m_hTracker, bOuter);
}

BOOL CLPTracker::GetOuterScrollWindow()
{
	return m_bOuterScroll;
}

void CLPTracker::SetSelectedState(BOOL bSelected)
{
	m_bSelected = bSelected;
}

BOOL CLPTracker::GetSelectedState()
{
	return m_bSelected;
}

void CLPTracker::SetBaseSelected(BOOL bBase)
{
	m_bBaseSelected = bBase;
	::SetBaseSelection(m_hTracker, bBase);
}

BOOL CLPTracker::IsBaseSelected()
{
	return m_bBaseSelected;
}


void CLPTracker::SetCurOuterScrollWindow()
{
	::SetOuterScroll(m_hTracker, m_bOuterScroll);
}

void CLPTracker::SetAlign(TYPE_ALIGNTRACKER eAlign, RECT rtPos)
{
	TRACKRECT rtTrackReect;
	memset(&rtTrackReect, 0x00, sizeof(TRACKRECT));

	rtTrackReect.m_fleft = rtPos.left;
	rtTrackReect.m_ftop = rtPos.top;
	rtTrackReect.m_fright = rtPos.right;
	rtTrackReect.m_fbottom = rtPos.bottom;

	::SetTrackerAlign(m_hTracker, eAlign, rtTrackReect);
}

BOOL CLPTracker::SetWidth(DWORD dwWidth)
{
	BOOL bResult = ::SetWidth(m_hTracker, dwWidth);
	return bResult;
}

BOOL CLPTracker::SetHeight(DWORD dwHeight)
{
	BOOL bResult = ::SetHeight(m_hTracker, dwHeight);
	return bResult;
}

BOOL CLPTracker::MovePoint(int cx, int cy)
{
	BOOL bResult = ::MoveRoi(m_hTracker, cx, cy);
	return bResult;;
}