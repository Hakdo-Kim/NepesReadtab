#include "stdafx.h"
#include "RoiTracker.h"

#include "afxpriv.h"
#include "RoiTrackerDC.h"


#pragma comment (lib, "Gdiplus.lib")

CRoiTracker::CRoiTracker(CWnd* pWnd)
{
	/// Init Gdi Plus
	Gdiplus::GdiplusStartupInput input;
	Gdiplus::GdiplusStartup(&m_GdiPlusToken, &input, NULL);

	memset(&m_stPoint, 0x00, sizeof(INFO_POINT));
	memset(&m_stPreviousPoint, 0x00, sizeof(INFO_POINT));
	memset(&m_stStartPoint, 0x00, sizeof(INFO_POINT));

	m_pWnd = pWnd;
	m_bTracking = FALSE;
	m_bDirty = FALSE;
	m_bOuterScroll = FALSE;
	m_bBaseSelection = FALSE;
}

CRoiTracker::~CRoiTracker()
{
	/// Deinit Gdi Plus
	Gdiplus::GdiplusShutdown(m_GdiPlusToken);
	//*/
}

BOOL CRoiTracker::IsInit()
{
	return FALSE;
}

BOOL CRoiTracker::IsEnableRotate()
{
	return FALSE;
}

BOOL CRoiTracker::SetCursor(CDC* pDC, float fZoom)
{
	return FALSE;
}

void CRoiTracker::Clear()
{
	;
}

TYPE_HITROI CRoiTracker::HitTest(INFO_POINT point, float fZoom)
{
	return TYPE_HITROI_NONE;
}

INFO_RECT CRoiTracker::GetPointRect(INFO_POINT point)
{
	INFO_RECT rect = GetInflateRect(point, VALUE_INFLATE, VALUE_INFLATE);
	return rect;
}

void CRoiTracker::Draw(CDC* pDC, float fZoom)
{
	;
}

void CRoiTracker::DrawRoi(CDC* pDC, INFO_SIZE stSize, float fZoom, void* pReserved)
{
	;
}

void CRoiTracker::DrawTracker(CDC* pDC, INFO_POINT pt1, INFO_POINT pt2, float fZoom, BOOL bDone)
{
	;
}

TYPE_RESULTROI CRoiTracker::Track(CDC* pDC, UINT nFlags, INFO_POINT point, float fZoom, BOOL bErase)
{
	if (::GetCapture())
		return TYPE_RESULTROI_FAILED;

	TYPE_RESULTROI eResult = OnBeginTrack(nFlags, point, fZoom);
	if (TYPE_RESULTROI_CONTINUE != eResult)
		return eResult;

	m_bDirty = FALSE;

	m_stPoint = point;
	m_stPreviousPoint = m_stPoint;
	m_stStartPoint = m_stPoint;

	nFlags &= TYPE_FLAGROI_MOUSE;
	m_bTracking = TRUE;

	//
	::AfxLockTempMaps();

	int oldROP2 = R2_COPYPEN;
	COLORREF oldBkColor = RGB(0, 0, 0);
	if (pDC)
	{
		oldROP2 = pDC->SetROP2(R2_NOTXORPEN);
		oldBkColor = pDC->SetBkColor(RGB(255, 255, 255));
	}

	OnUpdate(pDC, nFlags | TYPE_FLAGROI_DRAW | TYPE_FLAGROI_FIRST, fZoom);

	m_pWnd->SetCapture();

	ASSERT(CWnd::GetCapture() == m_pWnd);
	ASSERT(TYPE_RESULTROI_CONTINUE == eResult);

	while (TYPE_RESULTROI_CONTINUE == eResult)
	{
		MSG msg;

		int cnt = 0;
		while (!::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (0 == cnt)
			{
				::AfxGetMainWnd()->SendMessageToDescendants(WM_IDLEUPDATECMDUI, TRUE);
			}
			cnt++;
		}

		if (CWnd::GetCapture() != m_pWnd || WM_CANCELMODE == msg.message)
		{
			eResult = TYPE_RESULTROI_FAILED;
		}
		else if (WM_MOUSEFIRST <= msg.message && WM_MOUSELAST >= msg.message)
		{
			CRoiTrackerDC* pRDC = NULL;
			if (pDC)
			{
				pRDC = new CRoiTrackerDC(pDC, NOTSRCINVERT);
				pRDC->SetROP2(R2_NOTXORPEN);
			}

			OnUpdate(pRDC, nFlags | TYPE_FLAGROI_REMOVE | TYPE_FLAGROI_ENTER, fZoom);

			const int x = (int)(short)LOWORD(msg.lParam);
			const int y = (int)(short)HIWORD(msg.lParam);

			INFO_POINT point;
			point.m_fx = x;
			point.m_fy = y;
			if (pDC)
			{
				POINT ptDraw;
				ptDraw.x = x;
				ptDraw.y = y;
				pDC->DPtoLP(&ptDraw);
			}

			m_stPreviousPoint = m_stPoint;
			m_stPoint = point;

			if (point.m_fx != m_stPreviousPoint.m_fx || point.m_fy != m_stPreviousPoint.m_fy)
			{
				m_bDirty = TRUE;
			}

			nFlags = (UINT)msg.wParam & TYPE_FLAGROI_MOUSE;

			eResult = OnMouseMessage(msg.message, nFlags, point, fZoom);

			OnUpdate(pRDC, nFlags | TYPE_FLAGROI_DRAW | TYPE_FLAGROI_LEAVE, fZoom);
			if (pDC)
			{
				delete pRDC;
			}
		}
		else if (WM_KEYFIRST <= msg.message && WM_KEYLAST >= msg.message)
		{
			eResult = OnKeyMessage(msg.message, (UINT)msg.wParam, (UINT)LOWORD(msg.lParam), (UINT)HIWORD(msg.lParam));
		}
		else
		{
			//eResult = OnMessage(msg);
		}
	}

	VERIFY(::ReleaseCapture());
	
	::AfxUnlockTempMaps();
	m_bTracking = FALSE;

	// 
	OnUpdate(pDC, nFlags | TYPE_FLAGROI_REMOVE | TYPE_FLAGROI_LAST, fZoom);

	if (0 < eResult && !m_bDirty)
	{
		eResult = TYPE_RESULTROI_NOMOVE;
	}

	eResult = OnEndTrack(eResult, fZoom, bErase);

	if (pDC)
	{
		pDC->SetROP2(oldROP2);
		pDC->SetBkColor(oldBkColor);
	}
	return eResult;
}

BOOL CRoiTracker::IsTracking()
{
	return m_bTracking;
}

TYPE_RESULTROI CRoiTracker::OnBeginTrack(UINT nFlags, INFO_POINT point, float fZoom)
{
	return TYPE_RESULTROI_CONTINUE;
}

TYPE_RESULTROI CRoiTracker::OnEndTrack(TYPE_RESULTROI eResult, float fZoom, BOOL bErase)
{
	return eResult;
}

TYPE_RESULTROI CRoiTracker::OnMouseMessage(UINT msg, UINT nFlags, INFO_POINT point, float fZoom)
{
	if (WM_LBUTTONUP == msg)
		return (nFlags & MK_CONTROL) ? TYPE_RESULTROI_COPY : TYPE_RESULTROI_SUCCEEDED;
	if (WM_LBUTTONDOWN == msg)
		return TYPE_RESULTROI_CANCELLED;

	return TYPE_RESULTROI_CONTINUE;

}

TYPE_RESULTROI CRoiTracker::OnMessage(MSG& msg)
{
	::DispatchMessage(&msg);
	return TYPE_RESULTROI_CONTINUE;
}

TYPE_RESULTROI CRoiTracker::OnKeyMessage(UINT msg, UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (msg == WM_KEYDOWN && nChar == VK_ESCAPE)
		return TYPE_RESULTROI_CANCELLED;
	return TYPE_RESULTROI_CONTINUE;
}

void CRoiTracker::OnUpdate(CDC* pDC, UINT nMode, float fZoom)
{
	;
}

void CRoiTracker::Invalidate(BOOL bErase)
{
	if (m_pWnd)
	{
		CWnd* pParentWnd = m_pWnd->GetParent();
		if (pParentWnd)
		{
			pParentWnd->Invalidate(bErase);
		}
	}
}

int CRoiTracker::GetPoint(LPINFO_POINT pPoint, int nLen)
{
	return 0;
}

int CRoiTracker::SetPoint(const LPINFO_POINT pPoint, const int nLen, float fZoom, BOOL bErase)
{
	return 0;
}

void CRoiTracker::ConvertPointPixelToDraw(const LPINFO_POINT pSrcPoint, LPINFO_POINT pDestPoint, const int nLen, const float fZoom)
{
	if (NULL == pSrcPoint || NULL == pDestPoint || NULL == m_pWnd)
		return;

	const int x = GetHScrollPos();
	const int y = GetVScrollPos();

	for (int i = 0; i < nLen; i++)
	{
		pDestPoint[i].m_fx = (pSrcPoint[i].m_fx * fZoom - x);
		pDestPoint[i].m_fy = (pSrcPoint[i].m_fy * fZoom - y);
	}

}

void CRoiTracker::ConvertPointPixelToDrawForRoi(const LPINFO_POINT pSrcPoint, LPINFO_POINT pDestPoint, const int nLen, const INFO_SIZE stSize, const float fZoom, BOOL bDrawForFile)
{
	if (NULL == pSrcPoint || NULL == pDestPoint || NULL == m_pWnd)
		return;

	const int x = GetHScrollPos();
	const int y = GetVScrollPos();
	if (bDrawForFile)
	{
		(int)x = 0;
		(int)y = 0;
	}

	for (int i = 0; i < nLen; i++)
	{
		pDestPoint[i].m_fx = (pSrcPoint[i].m_fx * fZoom - x);
		if ((0 < ((pSrcPoint[i].m_fx * fZoom - x) - pDestPoint[i].m_fx)) && (stSize.m_fcx - 1 > pDestPoint[i].m_fx))
		{
			pDestPoint[i].m_fx++;
		}

		pDestPoint[i].m_fy = (pSrcPoint[i].m_fy * fZoom - y);
		if ((0 < ((pSrcPoint[i].m_fy * fZoom - y) - pDestPoint[i].m_fy)) && (stSize.m_fcy - 1 < pDestPoint[i].m_fy))
		{
			pDestPoint[i].m_fy++;
		}

	}
}

void CRoiTracker::ConvertPointDrawToPixel(const LPINFO_POINT pSrcPoint, LPINFO_POINT pDestPoint, const int nLen, const float fZoom)
{
	if (NULL == pSrcPoint || NULL == pDestPoint || NULL == m_pWnd)
		return;

	const int x = GetHScrollPos();
	const int y = GetVScrollPos();

	for (int i = 0; i < nLen; i++)
	{
		pDestPoint[i].m_fx = ((pSrcPoint[i].m_fx + x) / fZoom);
		if (0 < ((pSrcPoint[i].m_fx + x) / fZoom - pDestPoint[i].m_fx))
			pDestPoint[i].m_fx++;

		pDestPoint[i].m_fy = ((pSrcPoint[i].m_fy + y) / fZoom);
		if (0 < ((pSrcPoint[i].m_fy + y) / fZoom - pDestPoint[i].m_fy))
			pDestPoint[i].m_fy++;
	}
}

double CRoiTracker::GetRadious(INFO_POINT pt1, INFO_POINT pt2)
{
	INFO_SIZE sz = GetSize(pt1, pt2);

	const double r = (int)(sqrt(pow((double)sz.m_fcx, 2) + pow((double)sz.m_fcy, 2)));

	return r;
}

double CRoiTracker::GetAngle(INFO_POINT pt1, INFO_POINT pt2, BOOL bDegree)
{
	INFO_SIZE sz = GetSize(pt1, pt2);

	REAL phi = 0.0f;
	if (bDegree)
	{
		phi = (REAL)(180.0f * atan2((REAL)sz.m_fcy, (REAL)sz.m_fcx) / (REAL)VALUE_PI);
		while (-180.0f >= phi)
		{
			phi += 360.0f;	// (-180, 180)
		}
	}
	else
	{
		phi = (REAL)atan2((REAL)sz.m_fcy, (REAL)sz.m_fcx);
	}

	return phi;
}

void CRoiTracker::SetOuterScroll(BOOL bOuter)
{
	m_bOuterScroll = bOuter;
}

BOOL CRoiTracker::IsOuterScroll()
{
	return m_bOuterScroll;
}

void CRoiTracker::SetBaseSelection(BOOL bBase)
{
	m_bBaseSelection = bBase;
}

BOOL CRoiTracker::IsBaseSelection()
{
	return m_bBaseSelection;
}

RECT CRoiTracker::GetRectangle(const INFO_RECT& rect)
{
	RECT rtRect;
	rtRect.left = (long)rect.m_fleft;
	rtRect.top = (long)rect.m_ftop;
	rtRect.right = (long)rect.m_fright;
	rtRect.bottom = (long)rect.m_fbottom;

	return rtRect;
}

POINT CRoiTracker::GetPoint(const INFO_POINT& point)
{
	POINT pt;
	pt.x = (long)point.m_fx;
	pt.y = (long)point.m_fy;

	return pt;
}

BOOL CRoiTracker::IsPointInRectangle(const INFO_RECT& rect, const INFO_POINT& point)
{
	double fmin = min(rect.m_fleft, rect.m_fright);
	double fmax = max(rect.m_fleft, rect.m_fright);

	if (point.m_fx < fmin || point.m_fx > fmax)
		return FALSE;

	fmin = min(rect.m_ftop, rect.m_fbottom);
	fmax = max(rect.m_ftop, rect.m_fbottom);

	if (point.m_fy < fmin || point.m_fy > fmax)
		return FALSE;

	return TRUE;
}

INFO_SIZE CRoiTracker::GetSize(const INFO_POINT& point1, const INFO_POINT& point2)
{
	INFO_SIZE stSize;
	stSize.m_fcx = point1.m_fx - point2.m_fx;
	stSize.m_fcy = point1.m_fy - point2.m_fy;

	return stSize;
}

INFO_RECT CRoiTracker::GetInflateRect(const INFO_POINT& point, double fx, double fy)
{
	INFO_RECT rect;
	rect.m_fleft = point.m_fx - fx;
	rect.m_fright = point.m_fx + fx;
	rect.m_ftop = point.m_fy - fy;
	rect.m_fbottom = point.m_fy + fy;
	
	return rect;
}


int CRoiTracker::GetHScrollPos()
{
	int x = 0;

	if (IsOuterScroll())
		x = ::GetScrollPos(::GetParent(m_pWnd->m_hWnd), SB_HORZ);
	else
		x = ::GetScrollPos(m_pWnd->m_hWnd, SB_HORZ);

	return x;
}
int CRoiTracker::GetVScrollPos()
{
	int y = 0;

	if (IsOuterScroll())
		y = ::GetScrollPos(::GetParent(m_pWnd->m_hWnd), SB_VERT);
	else
		y = ::GetScrollPos(m_pWnd->m_hWnd, SB_VERT);

	return y;
}

HBITMAP CRoiTracker::CreateEdgeBitmap(HDC hDC, const int nW, const int nH, void** ppBits)
{
	BITMAPINFO bmi;        // bitmap header 
	ZeroMemory(&bmi, sizeof(BITMAPINFO));
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = nW;
	bmi.bmiHeader.biHeight = -nH;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;         // four 8-bit components 
	bmi.bmiHeader.biCompression = BI_RGB;
	bmi.bmiHeader.biSizeImage = nW * nH * 4;

	HBITMAP hBitmap = CreateDIBSection(hDC, &bmi, DIB_RGB_COLORS, ppBits, NULL, 0x0);
	if (hBitmap)
	{
		for (int y = 0; y < nH; y++)
		{
			for (int x = 0; x < nW; x++)
			{
				UINT32& dwColor = ((UINT32 *)*ppBits)[x + y * nW];
				dwColor = 0x00BFBFBF;
			}
		}
	}
	
	return hBitmap;
}

BOOL CRoiTracker::CheckPointInRect(INFO_RECT rect, INFO_POINT point, float fZoom)
{
	/*//
	if (DEFAULT_ZOOM > fZoom)
	{
		rect.left -= VALUE_INFLATE / fZoom;
		rect.top -= VALUE_INFLATE / fZoom;
		rect.right += VALUE_INFLATE / fZoom;
		rect.bottom += VALUE_INFLATE / fZoom;
	}
	else
	//*/
	{
		rect.m_fleft -= VALUE_INFLATE;
		rect.m_ftop -= VALUE_INFLATE;
		rect.m_fright += VALUE_INFLATE;
		rect.m_fbottom += VALUE_INFLATE;
	}

	return  IsPointInRectangle(rect, point);
}


INFO_POINT CRoiTracker::GetTrackerPointFromSrc(INFO_POINT point, float fZoom)
{
	const int x = GetHScrollPos();
	const int y = GetVScrollPos();

	INFO_POINT ptTracker;
	ptTracker.m_fx = (point.m_fx * fZoom - x);
	ptTracker.m_fy = (point.m_fy * fZoom - y);

	return ptTracker;
}

INFO_POINT CRoiTracker::GetTrackerPointFromSrc(INFO_POINT point, INFO_POINT ptStart, INFO_POINT ptEnd, float fZoom)
{
	const int x = GetHScrollPos();
	const int y = GetVScrollPos();

	const double cx = ((ptEnd.m_fx - ptStart.m_fx) * fZoom - x);
	const double cy = ((ptEnd.m_fy - ptStart.m_fy) * fZoom - y);

	INFO_POINT ptTracker;
	ptTracker.m_fx = (point.m_fx * fZoom + cx);
	ptTracker.m_fy = (point.m_fy * fZoom + cy);

	return ptTracker;
}

INFO_POINT CRoiTracker::GetSrcPointFromTracker(INFO_POINT point, float fZoom)
{
	const int x = GetHScrollPos();
	const int y = GetVScrollPos();

	INFO_POINT ptSrc;
	ptSrc.m_fx = ((point.m_fx + x) / fZoom);
	ptSrc.m_fy = ((point.m_fy + y) / fZoom);

	return ptSrc;
}

INFO_POINT CRoiTracker::GetPointFromPointF(PointF point)
{
	INFO_POINT pt;
	memset(&pt, 0x00, sizeof(INFO_POINT));
	pt.m_fx = point.X;
	pt.m_fy = point.Y;

	return pt;
}

INFO_RECT CRoiTracker::GetPositionRect(LPINFO_POINT pPointList, int nLen)
{
	INFO_RECT rtRect;
	memset(&rtRect, 0x00, sizeof(INFO_RECT));

	if (NULL == pPointList || 0 >= nLen)
		return rtRect;

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

	rtRect.m_fleft = minX;
	rtRect.m_ftop = minY;
	rtRect.m_fright = maxX;
	rtRect.m_fbottom = maxY;

	return rtRect;
}

void CRoiTracker::SetAlign(TYPE_ALIGN eAlign, INFO_RECT rtPos)
{
	const double w = rtPos.m_fright - rtPos.m_fleft;
	const double h = rtPos.m_fbottom - rtPos.m_ftop;

	int nLen = this->GetPoint(NULL, 0);
	LPINFO_POINT pPointList = new INFO_POINT[nLen];
	memset(pPointList, 0x00, sizeof(INFO_POINT)*nLen);
	this->GetPoint(pPointList, nLen);

	double cx = 0;
	double cy = 0;

	INFO_RECT rtRoi = this->GetPositionRect(pPointList, nLen);

	const double nRoiW = rtRoi.m_fright - rtRoi.m_fleft;
	const double nRoiH = rtRoi.m_fbottom - rtRoi.m_ftop;

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

INFO_RECT CRoiTracker::SetRectangle(double left, double top, double right, double bottom)
{
	INFO_RECT rect;
	rect.m_fleft = left;
	rect.m_ftop = top;
	rect.m_fright = right;
	rect.m_fbottom = bottom;

	return rect;
}

BOOL CRoiTracker::SetWidth(DWORD dwWidth)
{
	return FALSE;
}

BOOL CRoiTracker::SetHeight(DWORD dwHeight)
{
	return FALSE;
}

BOOL CRoiTracker::MovePoint(int cx, int cy)
{
	return FALSE;
}


// Draw 
void CRoiTracker::DrawLine(CDC* pDC, const INFO_POINT& point1, const INFO_POINT& point2)
{
	if (NULL == pDC)
		return;

	POINT pt1;
	POINT pt2;

	pt1.x = (int)point1.m_fx;
	pt1.y = (int)point1.m_fy;

	pt2.x = (int)point2.m_fx;
	pt2.y = (int)point2.m_fy;

	pDC->MoveTo(pt1);
	pDC->LineTo(pt2);
	
}

void CRoiTracker::DrawPolygon(CDC* pDC, INFO_POINT* pPointList, int nLen)
{
	if (NULL == pDC || NULL == pPointList)
		return;

	POINT* ptList = new POINT[nLen];

	for (int i = 0; i < nLen; i++)
	{
		ptList[i].x = (int)pPointList[i].m_fx;
		ptList[i].y = (int)pPointList[i].m_fy;
	}

	pDC->Polygon(ptList, nLen);

	delete[] ptList;
	ptList = NULL;

}

void CRoiTracker::DrawArc(CDC* pDC, const INFO_RECT& rect, const INFO_POINT& ptStart, const INFO_POINT& ptEnd)
{
	if (NULL == pDC)
		return;

	RECT rtRect = this->GetRectangle(rect);

	POINT pt1;
	POINT pt2;

	pt1.x = (int)ptStart.m_fx;
	pt1.y = (int)ptStart.m_fy;

	pt2.x = (int)ptEnd.m_fx;
	pt2.y = (int)ptEnd.m_fy;

	pDC->Arc(&rtRect, pt1, pt2);
}

DWORD CRoiTracker::GetRemainder(DWORD dwValue, DWORD dwDiv)
{
	DWORD dwResult = dwValue % dwDiv;
	return dwResult;
}

double CRoiTracker::GetRemainder(double fValue, double fDiv)
{
	int nRes = (int) (fValue / fDiv);

	double fResult = fValue - nRes * fDiv;
	return fResult;
}


int CRoiTracker::GetZoomWeight(int nWeight, float fZoom)
{
	int nResult = (int)(nWeight * fZoom);
	if (1 > nResult)
		nResult = 1;

	return nResult;
}