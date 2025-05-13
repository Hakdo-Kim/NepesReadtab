// ViewRoi.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ViewRoi.h"

#include "UserInterfaceDef.h"

#define MAX_GRID_ROI			10
#define LINE_MARGIN_ROI			2


// CViewRoi

IMPLEMENT_DYNAMIC(CViewRoi, CStatic)

CViewRoi::CViewRoi()
{
	m_BkColor		= RGB(255,255,255);
	m_GuideColor	= RGB(0,0,255);
	m_LineColor		= RGB(0,0,255);
	
	m_RoiColor		= RGB(150,150,150);

	m_pTracker		= NULL;

	memset(&m_stRoi, 0x00, sizeof(INFO_ROI_PARA));

	memset(&m_stDefRoi, 0x00, sizeof(INFO_DEFROI));
	m_bDefInit = FALSE;

}

CViewRoi::~CViewRoi()
{
	if(m_pTracker)
		delete m_pTracker;
}


BEGIN_MESSAGE_MAP(CViewRoi, CStatic)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEACTIVATE()
	ON_WM_PAINT()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// CViewRoi 메시지 처리기입니다.
void CViewRoi::OnLButtonDown(UINT nFlags, CPoint point)
{
	if(m_pTracker)
	{
		// Resize
		if ((m_pTracker->HitTest(point)) == CRoiRectTracker::hitNothing)
		{
			// do nothing
		}
		else
		{
			RECT rtStart;
			m_pTracker->GetTrueRect(&rtStart);

			const int nStartWidth	= rtStart.right - rtStart.left - 2;
			const int nStartHeight	= rtStart.bottom - rtStart.top - 2;


			if(m_pTracker->Track(this, point, false))
			{
				RECT rtTrack;
				m_pTracker->GetTrueRect(&rtTrack);

				const int nEndWidth = rtTrack.right - rtTrack.left - 2;
				const int nEndHeight= rtTrack.bottom - rtTrack.top - 2;

				// Update ROI
				INFO_ROI_PARA stRoi;
				memset(&stRoi, 0x00, sizeof(INFO_ROI_PARA));

				if(nStartWidth!=nEndWidth || nStartHeight!=nEndHeight)
				{
					GetRoi(&stRoi, &rtTrack);

					if(rtStart.left==rtTrack.left)
						stRoi.nXstart = m_stRoi.nXstart;
					if(rtStart.top==rtTrack.top)
						stRoi.nYstart = m_stRoi.nYstart;

					// Resize
					m_stRoi.nXstart = stRoi.nXstart;
					m_stRoi.nYstart = stRoi.nYstart;
					m_stRoi.nWidth = stRoi.nWidth;
					m_stRoi.nHeight = stRoi.nHeight;

					if ((m_stRoi.nXstart + m_stRoi.nWidth) > m_stRoi.nMaxWidth)
					{
						if (m_stDefRoi.m_nMinWidth == m_stRoi.nWidth)
							m_stRoi.nXstart = m_stRoi.nMaxWidth - m_stRoi.nWidth;
						else
							m_stRoi.nWidth = m_stRoi.nMaxWidth - m_stRoi.nXstart;
					}

					if ((m_stRoi.nYstart + m_stRoi.nHeight) > m_stRoi.nMaxHeight)
					{
						if (m_stDefRoi.m_nMinHeight == m_stRoi.nHeight)
							m_stRoi.nYstart = m_stRoi.nMaxHeight - m_stRoi.nHeight;
						else
							m_stRoi.nHeight = m_stRoi.nMaxHeight - m_stRoi.nYstart;
					}

					// Check position: Rect tracker...
					RECT rtRect;
					GetRect(&m_stRoi, &rtRect);
					m_pTracker->SetPosition(&rtRect);

					this->Invalidate();
					this->GetParent()->SendMessage(WM_NOTIFY_TRACK_CHANGE_RECT, (WPARAM)&m_stRoi, 0);
				}
				else
				{
					GetRoi(&stRoi, &rtTrack, &m_stRoi);

					// Move
					m_stRoi.nXstart = stRoi.nXstart;
					m_stRoi.nYstart = stRoi.nYstart;

					// Check position: Rect tracker..
					RECT rtRect;
					GetRect(&stRoi, &rtRect);

					rtTrack.left	= rtRect.left;
					rtTrack.top		= rtRect.top;
					rtTrack.right	= rtTrack.left+nEndWidth;
					rtTrack.bottom	= rtTrack.top+nEndHeight;
					m_pTracker->SetPosition(&rtTrack);

					this->Invalidate();
					this->GetParent()->SendMessage(WM_NOTIFY_TRACK_CHANGE_RECT, (WPARAM)&m_stRoi, 0);
				}

				// REDRAW ROI
				this->GetParent()->Invalidate();
				
			}
		
		}
	}

	CStatic::OnLButtonDown(nFlags, point);
}

void CViewRoi::OnLButtonUp(UINT nFlags, CPoint point)
{
	CStatic::OnLButtonUp(nFlags, point);
}

void CViewRoi::OnMouseMove(UINT nFlags, CPoint point)
{
	CStatic::OnMouseMove(nFlags, point);
}

int CViewRoi::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message)
{
	return CStatic::OnMouseActivate(pDesktopWnd, nHitTest, message);
}

BOOL CViewRoi::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// Set the tracker cursor on resize
	if (m_pTracker)
	{
		if (pWnd == this && m_pTracker->SetCursor(this, nHitTest))
		{
			return TRUE;
		}
	}

	return CStatic::OnSetCursor(pWnd, nHitTest, message);
}


void CViewRoi::OnPaint()
{
	CPaintDC dc(this);

	CRect Rect;
	GetClientRect(&Rect);

	CDC MemDC;
	MemDC.CreateCompatibleDC(&dc);

	HBITMAP hbitmap;       // bitmap handle 
	BITMAPINFO bmi;        // bitmap header 
	VOID *pvBits;          // pointer to DIB section 
	const ULONG ulWindowWidth = Rect.Width();
	const ULONG ulWindowHeight = Rect.Height();

	const ULONG ulBitmapWidth = ulWindowWidth;
	const ULONG ulBitmapHeight = ulWindowHeight;

	ZeroMemory(&bmi, sizeof(BITMAPINFO));
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = ulBitmapWidth;
	bmi.bmiHeader.biHeight = ulBitmapHeight*-1;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;         // four 8-bit components 
	bmi.bmiHeader.biCompression = BI_RGB;
	bmi.bmiHeader.biSizeImage = ulBitmapWidth * ulBitmapHeight * 4;

	hbitmap = CreateDIBSection(MemDC.m_hDC, &bmi, DIB_RGB_COLORS, &pvBits, NULL, 0x0);
	if (NULL == hbitmap)
		return;
	::SelectObject(MemDC.m_hDC, hbitmap);


	{
		DrawBackground(&MemDC);

		// Grid
		DrawLine(&MemDC);

	}


	dc.BitBlt(0, 0, ulWindowWidth, ulWindowHeight, &MemDC, 0, 0, SRCCOPY);

	DeleteObject(hbitmap);

	if(m_pTracker)
	{
		m_pTracker->Draw(&dc);
	}

}


void CViewRoi::DrawBackground(CDC* pDc)
{
	if (NULL == pDc)
		return;

	// Draw Rect
	CRect Rect;
	GetClientRect(&Rect);

	CDC MemDC;
	MemDC.CreateCompatibleDC(pDc);

	HBITMAP hbitmap;       // bitmap handle 
	BITMAPINFO bmi;        // bitmap header 
	VOID *pvBits;          // pointer to DIB section 
	const ULONG ulWindowWidth = Rect.Width();
	const ULONG ulWindowHeight = Rect.Height();

	const ULONG ulBitmapWidth = ulWindowWidth;
	const ULONG ulBitmapHeight = ulWindowHeight;

	ZeroMemory(&bmi, sizeof(BITMAPINFO));
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = ulBitmapWidth;
	bmi.bmiHeader.biHeight = ulBitmapHeight * -1;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;         // four 8-bit components 
	bmi.bmiHeader.biCompression = BI_RGB;
	bmi.bmiHeader.biSizeImage = ulBitmapWidth * ulBitmapHeight * 4;

	hbitmap = CreateDIBSection(MemDC.m_hDC, &bmi, DIB_RGB_COLORS, &pvBits, NULL, 0x0);
	if (NULL == hbitmap)
		return;
	::SelectObject(MemDC.m_hDC, hbitmap);

	{
		// Draw Background
		CBrush FillBrush;
		FillBrush.CreateSolidBrush(m_BkColor);
		MemDC.FillRect(&Rect, &FillBrush);
	}

	pDc->BitBlt(0, 0, ulWindowWidth, ulWindowHeight, &MemDC, 0, 0, SRCCOPY);

	DeleteObject(hbitmap);
}

void CViewRoi::DrawLine(CDC* pMemDC)
{
	if(NULL==pMemDC)
		return;

	CRect rtLine;
	GetClientRect(&rtLine);

	const ULONG ulWindowWidth = rtLine.Width();
	const ULONG ulWindowHeight = rtLine.Height();

	const int nGridW = (ulWindowWidth-LINE_MARGIN_ROI*2) / (MAX_GRID_ROI);
	const int nGridH = (ulWindowHeight-LINE_MARGIN_ROI*2) / (MAX_GRID_ROI);

	const int nRemainW = (ulWindowWidth-LINE_MARGIN_ROI*2) % (MAX_GRID_ROI);
	const int nRemainH = (ulWindowHeight-LINE_MARGIN_ROI*2) % (MAX_GRID_ROI);


	const POINT ptStart = GetStartPoint();
	const POINT ptEnd	= GetEndPoint();

	// Guide Line
	{
		CPen LinePen;
		LinePen.CreatePen(PS_SOLID , 1, m_GuideColor);
		pMemDC->SelectObject(&LinePen);

		int nX = 0;
		int nY = 0;

		for(int i=0; i<=MAX_GRID_ROI; i++)
		{
			// H
			nY = ptStart.y + (nGridH*i);
			if(nRemainH>=i)		nY+=i;
			else				nY+=nRemainH;

			pMemDC->MoveTo(ptStart.x,	nY );
			pMemDC->LineTo(ptEnd.x,		nY );


			// V
			nX = ptStart.x + (nGridW*i);
			if(nRemainW>=i)		nX+=i;
			else				nX+=nRemainW;

			pMemDC->MoveTo(nX, ptStart.y);
			pMemDC->LineTo(nX, ptEnd.y);
		}

	}

	// ROI Draw
	{
		if(m_pTracker)
		{
			RECT rtRect;
			memset(&rtRect, 0x00, sizeof(RECT));
			m_pTracker->GetTrueRect(&rtRect);

			CBrush brush;
			brush.CreateSolidBrush(m_RoiColor);
			pMemDC->SelectObject(&brush);
			pMemDC->Rectangle(&rtRect);

		}
		
	}


}


const POINT CViewRoi::GetStartPoint()
{
	POINT ptStart;
	ptStart.x = LINE_MARGIN_ROI;
	ptStart.y = LINE_MARGIN_ROI;

	return ptStart;

}

const POINT CViewRoi::GetEndPoint()
{
	CRect rtRect;
	GetClientRect(&rtRect);

	const ULONG ulWindowWidth = rtRect.Width();
	const ULONG ulWindowHeight = rtRect.Height();

	POINT ptEnd;
	ptEnd.x = ulWindowWidth - LINE_MARGIN_ROI;
	ptEnd.y = ulWindowHeight- LINE_MARGIN_ROI;

	return ptEnd;
}


void CViewRoi::UpdateInformation(const INFO_DEFROI* pDefROI)
{
	if (NULL == pDefROI)
		return;

	memcpy(&m_stDefRoi, pDefROI, sizeof(INFO_DEFROI));
	m_bDefInit = TRUE;
}

void CViewRoi::SetRoi(const INFO_ROI_PARA* pstRoi)
{
	if(NULL==pstRoi)
		return;
	m_stRoi = *pstRoi;

	RECT stRect;
	memset(&stRect, 0x00, sizeof(RECT));

	GetRect(pstRoi, &stRect);

	const int nW = stRect.right  - stRect.left;
	const int nH = stRect.bottom - stRect.top;

	if( nW>0 && nH>0 )
	{
		if(NULL==m_pTracker)
			m_pTracker = new CRoiRectTracker(this, &stRect);
		else
			m_pTracker->SetPosition(&stRect);

		m_pTracker->GetTrueRect(&stRect);
		this->Invalidate();
	}

}

void CViewRoi::SetRoiPosition(int x, int y, int w, int h)
{
	m_stRoi.nXstart	= x;
	m_stRoi.nYstart	= y;
	m_stRoi.nWidth	= w;
	m_stRoi.nHeight	= h;

	CorrectRoi(&m_stRoi);
	SetRoi(&m_stRoi);
	
}


void CViewRoi::GetRoi(INFO_ROI_PARA* pstRoi)
{
	if(NULL==pstRoi || NULL==m_pTracker)
		return;

	*pstRoi = m_stRoi;

}


void CViewRoi::GetRect(const INFO_ROI_PARA* pstRoi, RECT* pRect)
{
	if(NULL==pstRoi || NULL==pRect)
		return;

	const int nWidth = m_stRoi.nMaxWidth;
	const int nHeight = m_stRoi.nMaxHeight;


	CRect rtView;
	GetClientRect(&rtView);

	const int nViewW = rtView.Width()  - LINE_MARGIN_ROI*2;
	const int nViewH = rtView.Height() - LINE_MARGIN_ROI*2;

	const float fWidth = (float)nWidth/(float)nViewW;
	const float fHeight = (float)nHeight/(float)nViewH;

	pRect->left = (LONG)(pstRoi->nXstart / fWidth + LINE_MARGIN_ROI);
	pRect->top = (LONG)(pstRoi->nYstart / fHeight + LINE_MARGIN_ROI);

	pRect->right = (LONG)((pstRoi->nXstart + pstRoi->nWidth) / fWidth + LINE_MARGIN_ROI);
	pRect->bottom = (LONG)((pstRoi->nYstart + pstRoi->nHeight) / fHeight + LINE_MARGIN_ROI);

}

void CViewRoi::GetRoi(INFO_ROI_PARA* pstRoi, RECT* pRect, const INFO_ROI_PARA* pstCur)
{
	if(NULL==pstRoi || NULL==pRect)
		return;

	const int nWidth = m_stRoi.nMaxWidth;
	const int nHeight = m_stRoi.nMaxHeight;

	if (0 > pRect->left) pRect->left = 0;
	if (0 > pRect->top) pRect->top = 0;

	CRect rtView;
	GetClientRect(&rtView);

	const int nViewW = rtView.Width()  - LINE_MARGIN_ROI*2;
	const int nViewH = rtView.Height() - LINE_MARGIN_ROI*2;

	//pRect->left  +=LINE_MARGIN_ROI;
	//pRect->top   +=LINE_MARGIN_ROI;
	//pRect->right -=LINE_MARGIN_ROI;
	//pRect->bottom-=LINE_MARGIN_ROI;

	const float fWidth = (float)nWidth/(float)nViewW;
	const float fHeight = (float)nHeight/(float)nViewH;


	int w = (DWORD)((pRect->right - pRect->left)* fWidth);
	int h = (DWORD)((pRect->bottom - pRect->top) * fHeight);

	int x = (DWORD)(pRect->left* fWidth);
	int y = (DWORD)(pRect->top * fHeight);

	if (0 > x || 0 > y || nWidth  < w || nHeight < h ||
		nWidth  < (w + x) || nHeight < (h + y))
	{
		if (0 > x) x = 0;
		if (0 > y) y = 0;

		if (nWidth  < w)	w = nWidth;
		if (nHeight < h)	h = nHeight;

		if (nWidth < (w + x))
		{
			if(pstCur)
				x = nWidth - pstCur->nWidth;
			else
				x = nWidth - w;
		}

		if (nHeight < (h + y))
		{
			if(pstCur)
				y = nHeight - pstCur->nHeight;
			else
				y = nHeight - h;
		}

	}

	pstRoi->nXstart	= x / ROI_HFACTOR*ROI_HFACTOR;
	pstRoi->nWidth	= w / ROI_HFACTOR*ROI_HFACTOR;

	pstRoi->nYstart = y / ROI_VFACTOR*ROI_VFACTOR;
	pstRoi->nHeight = h / ROI_VFACTOR*ROI_VFACTOR;


	CorrectRoi(pstRoi);

}

void CViewRoi::CorrectRoi(INFO_ROI_PARA* pstRoi)
{
	if(NULL==pstRoi)
		return;

	int FACTOR_X = 16;
	int FACTOR_Y = ROI_VFACTOR;
	int FACTOR_W = 16;
	int FACTOR_H = ROI_VFACTOR;

	int MIN_W = FACTOR_W;
	int MIN_H = FACTOR_H;

	if (m_bDefInit)
	{
		FACTOR_X = m_stDefRoi.m_nUnitX;
		FACTOR_Y = m_stDefRoi.m_nUnitY;
		FACTOR_W = m_stDefRoi.m_nUnitW;
		FACTOR_H = m_stDefRoi.m_nUnitH;

		MIN_W = m_stDefRoi.m_nMinWidth;
		MIN_H = m_stDefRoi.m_nMinHeight;
	}

	const DWORD dwMaxWidth = m_stRoi.nMaxWidth;
	const DWORD dwMaxHeight = m_stRoi.nMaxHeight;

	
	pstRoi->nXstart = pstRoi->nXstart / FACTOR_X*FACTOR_X;
			
	if (dwMaxWidth < pstRoi->nXstart + pstRoi->nWidth)
		pstRoi->nWidth = dwMaxWidth - pstRoi->nXstart;

	pstRoi->nWidth = pstRoi->nWidth / FACTOR_W*FACTOR_W;
	if (MIN_W>pstRoi->nWidth)
		pstRoi->nWidth = MIN_W;

	// Y, Width : 2 * x
	pstRoi->nYstart = pstRoi->nYstart / FACTOR_Y*FACTOR_Y;
	if (dwMaxHeight < pstRoi->nYstart + pstRoi->nHeight)
		pstRoi->nHeight = dwMaxHeight - pstRoi->nYstart;
	pstRoi->nHeight = pstRoi->nHeight / FACTOR_H*FACTOR_H;

	if (MIN_H>pstRoi->nHeight)
		pstRoi->nHeight = MIN_H;

}

