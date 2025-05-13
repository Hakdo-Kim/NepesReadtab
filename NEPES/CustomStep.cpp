// CustomStep.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "CustomStep.h"


// CCustomStep

IMPLEMENT_DYNAMIC(CCustomStep, CStatic)

CCustomStep::CCustomStep()
{
	m_rgbBk = RGB(25, 25, 25);
	m_rgbTxt = RGB(255, 255, 255);

	//
	m_nFontHeight = 32;
	m_nFontWeight = FW_BOLD;
	m_szFontName = _T("MS Shell Dlg");

	//
	m_szMessage = _T("NOT");
}

CCustomStep::~CCustomStep()
{
}

void CCustomStep::SetTextFont(TCHAR* pszName, int nHeight, int nWeight)
{
	if (NULL == pszName)
		return;

	m_nFontHeight = nHeight;
	m_nFontWeight = nWeight;
	m_szFontName = pszName;

	if (this->m_hWnd)
		this->Invalidate(FALSE);
	return;
}

void CCustomStep::SetTextColor(COLORREF rgb)
{
	m_rgbTxt = rgb;
}

void CCustomStep::SetMessage(TCHAR* pszMsg)
{
	if (NULL == pszMsg)
		m_szMessage = _T("");
	else
		m_szMessage = pszMsg;

	if (this->m_hWnd)
		this->Invalidate(FALSE);
}


BEGIN_MESSAGE_MAP(CCustomStep, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CCustomStep message handlers
void CCustomStep::PreSubclassWindow()
{
	CStatic::PreSubclassWindow();
}

void CCustomStep::OnPaint()
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

void CCustomStep::DrawMessage(CDC* pMemDC)
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

	
	pMemDC->SetBkMode(TRANSPARENT);
	pMemDC->SetTextColor(m_rgbTxt);


	const int nMsgLen = GetStringLength(&m_szMessage);
	if (4 > nMsgLen)
	{
		RECT rtRect;
		rtRect.left = rect.left + MARGIN;
		rtRect.right = rect.right - MARGIN;

		rtRect.top = rect.top + MARGIN * 4 + 3;
		rtRect.bottom = rect.bottom - MARGIN;

		pMemDC->DrawText(m_szMessage, &rtRect, DT_CENTER | DT_SINGLELINE);
	}
	else
	{
		RECT rtTop;
		rtTop.left = rect.left + MARGIN;
		rtTop.right = rect.right - MARGIN;
		rtTop.top = rect.top + MARGIN;
		rtTop.bottom = rect.top + (rect.Height() - MARGIN * 3) / 2;

		RECT rtDown = rtTop;
		rtDown.top = rtTop.bottom + MARGIN;
		rtDown.bottom = rtDown.top + (rect.Height() - MARGIN * 3) / 2;


		CString szTop = GetString(&m_szMessage, 0, 2);
		CString szBottom = GetString(&m_szMessage, 3, m_szMessage.GetLength());

		pMemDC->DrawText(szTop, &rtTop, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		pMemDC->DrawText(szBottom, &rtDown, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}

	pMemDC->SelectObject(pOlfFont);

}

void CCustomStep::DrawBackground(CDC* pMemDC)
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

	HBITMAP hBmpLeftTop = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BMP_DISPLAYSTEP_LEFTTOP));
	if (hBmpLeftTop)
	{
		::GetObject(hBmpLeftTop, sizeof(BITMAP), &bm);

		HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpLeftTop);
		pMemDC->BitBlt(0, 0, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

		MemDC.SelectObject(hOld);
		::DeleteObject(hBmpLeftTop);
	}

	HBITMAP hBmpLeftBottom = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BMP_DISPLAYSTEP_LEFTBOTTOM));
	if (hBmpLeftBottom)
	{
		::GetObject(hBmpLeftBottom, sizeof(BITMAP), &bm);

		HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpLeftBottom);
		pMemDC->BitBlt(0, h - bm.bmHeight, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

		MemDC.SelectObject(hOld);
		::DeleteObject(hBmpLeftBottom);
	}

	HBITMAP hBmpRightTop = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BMP_DISPLAYSTEP_RIGHTTOP));
	if (hBmpRightTop)
	{
		::GetObject(hBmpRightTop, sizeof(BITMAP), &bm);

		HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpRightTop);
		pMemDC->BitBlt(w - bm.bmWidth, 0, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

		MemDC.SelectObject(hOld);
		::DeleteObject(hBmpRightTop);
	}

	HBITMAP hBmpRightBottom = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BMP_DISPLAYSTEP_RIGHTBOTTOM));
	if (hBmpRightBottom)
	{
		::GetObject(hBmpRightBottom, sizeof(BITMAP), &bm);

		HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpRightBottom);
		pMemDC->BitBlt(w - bm.bmWidth, h - bm.bmHeight, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

		MemDC.SelectObject(hOld);
		::DeleteObject(hBmpRightBottom);
	}


}


int CCustomStep::GetStringLength(CString* pString)
{
	if (NULL == pString)
		return -1;

	int nLen = 0;

	const int nMax = pString->GetLength();
	for (int i = 0; i < nMax; i++)
	{
		const char ch = pString->GetAt(i);
		if (IsDBCSLeadByte(ch))
			i++;
		nLen++;
	}
	return nLen;
}

CString CCustomStep::GetString(CString* pString, const int nStart, const int nEnd)
{
	CString szPart = _T("");
	if (NULL == pString)
		return szPart;

	int nLen = 0;

	TCHAR szTemp[MAX_PATH] = { 0, };
	int idx = 0;

	const int nMax = pString->GetLength();
	for (int i = 0; i < nMax; i++)
	{
		char ch = pString->GetAt(i);
		if (nStart <= nLen && nEnd >= nLen)
		{
			szTemp[idx] = ch; idx++;
		}

		if (IsDBCSLeadByte(ch))
		{
			i++;
			if (nStart <= nLen && nEnd >= nLen)
			{
				ch = pString->GetAt(i);
				szTemp[idx] = ch; idx++;
			}
		}
		nLen++;
	}

	szPart = szTemp;
	return szPart;
}