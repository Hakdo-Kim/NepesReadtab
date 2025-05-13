// CustomMessage.cpp : implementation file
//

#include "stdafx.h"
#include "CustomMessage.h"

#include "Resource.h"

// CCustomMessage

IMPLEMENT_DYNAMIC(CCustomMessage, CStatic)

CCustomMessage::CCustomMessage()
{
	m_rgbBk = RGB(25, 25, 25);
	m_rgbTxt = RGB(255, 255, 255);
	
	//
	m_nFontHeight = 32;
	m_nFontWeight = FW_BOLD;
	m_szFontName = _T("MS Shell Dlg");

	//
	m_szMessage = _T("NOT READY...");
}

CCustomMessage::~CCustomMessage()
{
}

void CCustomMessage::SetTextFont(TCHAR* pszName, int nHeight, int nWeight)
{
	if (NULL == pszName)
		return;

	m_nFontHeight = nHeight;
	m_nFontWeight = nWeight;
	m_szFontName = pszName;

	if (this->m_hWnd)
		this->Invalidate();
	return;
}

void CCustomMessage::SetTextColor(COLORREF rgb)
{
	m_rgbTxt = rgb;
}

void CCustomMessage::SetMessage(TCHAR* pszMsg)
{
	if (NULL == pszMsg)
		m_szMessage = _T("");
	else
		m_szMessage = pszMsg;

	if (this->m_hWnd)
		this->Invalidate();
}


BEGIN_MESSAGE_MAP(CCustomMessage, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CCustomMessage message handlers
void CCustomMessage::PreSubclassWindow()
{
	CStatic::PreSubclassWindow();
}

void CCustomMessage::OnPaint()
{
	CPaintDC dc(this);

	CDC MemDC;
	MemDC.CreateCompatibleDC(&dc);

	CRect rect;
	GetClientRect(&rect);

	HBITMAP hBitmap;
	BITMAPINFO bmi;
	VOID *pvBits;
	const ULONG ulWindowWidth = rect.Width();
	const ULONG ulWindowHeight = rect.Height();

	const int ulBitmapWidth = ulWindowWidth;
	const int ulBitmapHeight = ulWindowHeight;

	ZeroMemory(&bmi, sizeof(BITMAPINFO));
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = ulBitmapWidth;
	bmi.bmiHeader.biHeight = -ulBitmapHeight;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;         // four 8-bit components 
	bmi.bmiHeader.biCompression = BI_RGB;
	bmi.bmiHeader.biSizeImage = ulBitmapWidth * ulBitmapHeight * 4;

	hBitmap = CreateDIBSection(MemDC.m_hDC, &bmi, DIB_RGB_COLORS, &pvBits, NULL, 0x0);
	if (NULL == hBitmap)
		return;
	::SelectObject(MemDC.m_hDC, hBitmap);

	{
		DrawBackground(&MemDC);
		DrawMessage(&MemDC);
	}

	dc.BitBlt(0, 0, ulWindowWidth, ulWindowHeight, &MemDC, 0, 0, SRCCOPY);
	DeleteObject(hBitmap);
}

void CCustomMessage::DrawMessage(CDC* pMemDC)
{
	if (NULL == pMemDC)
		return;

	CRect rect;
	GetClientRect(&rect);

	// Draw Text
	CFont font;

	LOGFONT stLf;
	memset(&stLf, 0x00, sizeof(LOGFONT));
	stLf.lfHeight = m_nFontHeight;
	stLf.lfWeight = m_nFontWeight;
	_tcsncpy_s(stLf.lfFaceName, LF_FACESIZE, (LPTSTR)(LPCTSTR)m_szFontName, _tcslen((LPTSTR)(LPCTSTR)m_szFontName));

	font.CreateFontIndirect(&stLf);
	CFont* pOlfFont = pMemDC->SelectObject(&font);

	RECT rtRect;
	rtRect.left = rect.left + MARGIN * 4;
	rtRect.top = rect.top + MARGIN;
	rtRect.right = rect.right - MARGIN;
	rtRect.bottom = rect.bottom - MARGIN;

	pMemDC->SetBkMode(TRANSPARENT);
	pMemDC->SetTextColor(m_rgbTxt);
	pMemDC->DrawText(m_szMessage, &rtRect, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
	pMemDC->SelectObject(pOlfFont);

}

void CCustomMessage::DrawBackground(CDC* pMemDC)
{
	if (NULL == pMemDC)
		return;

	CRect rect;
	this->GetClientRect(&rect);

	const int w = rect.Width();
	const int h = rect.Height();

	pMemDC->FillSolidRect(&rect, m_rgbBk);

	CDC MemDC;
	MemDC.CreateCompatibleDC(pMemDC);

	BITMAP bm;

	HBITMAP hBmpLeft = ::LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BMP_DISPLAY_LEFT));
	if (hBmpLeft)
	{
		::GetObject(hBmpLeft, sizeof(BITMAP), &bm);
		
		HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpLeft);
		for (int y = 0; y < h; y += bm.bmHeight)
		{
			pMemDC->BitBlt(0, y, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);
		}

		MemDC.SelectObject(hOld);
		::DeleteObject(hBmpLeft);
	}

	HBITMAP hBmpRight = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BMP_DISPLAY_RIGHT));
	if (hBmpRight)
	{
		::GetObject(hBmpRight, sizeof(BITMAP), &bm);

		HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpRight);
		for (int y = 0; y < h; y += bm.bmHeight)
		{
			pMemDC->BitBlt(w - bm.bmWidth, y, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);
		}

		MemDC.SelectObject(hOld);
		::DeleteObject(hBmpRight);
	}

	HBITMAP hBmpTop = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BMP_DISPLAY_TOP));
	if (hBmpTop)
	{
		::GetObject(hBmpTop, sizeof(BITMAP), &bm);

		HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpTop);
		for (int x = 0; x < w; x += bm.bmWidth)
		{
			pMemDC->BitBlt(x, 0, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);
		}

		MemDC.SelectObject(hOld);
		::DeleteObject(hBmpTop);
	}

	HBITMAP hBmpBottom = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BMP_DISPLAY_BOTTOM));
	if (hBmpBottom)
	{
		::GetObject(hBmpBottom, sizeof(BITMAP), &bm);

		HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpBottom);
		for (int x = 0; x < w; x += bm.bmWidth)
		{
			pMemDC->BitBlt(x, h - bm.bmHeight, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);
		}

		MemDC.SelectObject(hOld);
		::DeleteObject(hBmpBottom);
	}

	HBITMAP hBmpLeftTop = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BMP_DISPLAY_LEFTTOP));
	if (hBmpLeftTop)
	{
		::GetObject(hBmpLeftTop, sizeof(BITMAP), &bm);

		HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpLeftTop);
		pMemDC->BitBlt(0, 0, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

		MemDC.SelectObject(hOld);
		::DeleteObject(hBmpLeftTop);
	}

	HBITMAP hBmpLeftBottom = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BMP_DISPLAY_LEFTBOTTOM));
	if (hBmpLeftBottom)
	{
		::GetObject(hBmpLeftBottom, sizeof(BITMAP), &bm);

		HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpLeftBottom);
		pMemDC->BitBlt(0, h - bm.bmHeight, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

		MemDC.SelectObject(hOld);
		::DeleteObject(hBmpLeftBottom);
	}

	HBITMAP hBmpRightTop = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BMP_DISPLAY_RIGHTTOP));
	if (hBmpRightTop)
	{
		::GetObject(hBmpRightTop, sizeof(BITMAP), &bm);

		HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpRightTop);
		pMemDC->BitBlt(w - bm.bmWidth, 0, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

		MemDC.SelectObject(hOld);
		::DeleteObject(hBmpRightTop);
	}

	HBITMAP hBmpRightBottom = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BMP_DISPLAY_RIGHTBOTTOM));
	if (hBmpRightBottom)
	{
		::GetObject(hBmpRightBottom, sizeof(BITMAP), &bm);

		HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpRightBottom);
		pMemDC->BitBlt(w - bm.bmWidth, h - bm.bmHeight, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

		MemDC.SelectObject(hOld);
		::DeleteObject(hBmpRightBottom);
	}


}
