// ResultText.cpp : implementation file
//

#include "stdafx.h"
#include "StaticText.h"


// CStaticResult

IMPLEMENT_DYNAMIC(CStaticText, CStatic)

CStaticText::CStaticText()
{
	memset(&m_stBk, 0x00, sizeof(INFO_BK));
	memset(&m_stText, 0x00, sizeof(INFO_TEXT));

	InitBkInfo(m_stBk, RGB(0, 0, 0));
	InitTextInfo(m_stText, (LPTSTR)SYSTEMFONT, 12, TRUE, RGB(255, 255, 255));

	m_szTxt = _T("READY");
	m_nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE;


	m_bBreakPoint = FALSE;

}

CStaticText::~CStaticText()
{
	DeinitTextInfo(m_stText);
	DeinitBkInfo(m_stBk);
}

BEGIN_MESSAGE_MAP(CStaticText, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CStaticText message handlers
void CStaticText::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CRect rect;
	this->GetWindowRect(rect);
	ScreenToClient(rect);

	const int w = rect.Width();
	const int h = rect.Height();

	CDC memDC;
	CBitmap bitmap;

	memDC.CreateCompatibleDC(&dc);
	bitmap.CreateCompatibleBitmap(&dc, w, h);
	memDC.SelectObject(&bitmap);

	{
		// Draw Background
		if (m_stBk.m_pBrush)
		{
			memDC.FillRect(rect, m_stBk.m_pBrush);
		}

		// Draw Bitmap...
		DrawBackground(&memDC, &m_stBk);
		
		// Draw Text.
		memDC.SetBkMode(TRANSPARENT);

		CFont* pOldFont = NULL;
		CPen* pOldPen = NULL;

		if (m_stText.m_pFont)
			pOldFont = (CFont*)memDC.SelectObject(m_stText.m_pFont);

		memDC.SetTextColor(m_stText.m_rgbTxt);
		memDC.DrawText(m_szTxt, rect, m_nFormat);

		if (pOldFont)
			memDC.SelectObject(pOldFont);
	}

	dc.BitBlt(0, 0, w, h, &memDC, 0, 0, SRCCOPY);
}

BOOL CStaticText::SetTextInfo(TCHAR* pszFont, int nSize, BOOL bBold, COLORREF rgb)
{
	BOOL bResult = InitTextInfo(m_stText, pszFont, nSize, bBold, rgb);
	return bResult;
}

BOOL CStaticText::SetBkInfo(COLORREF rgb, HBITMAP* pBmpList, int nBmpLen, TYPE_BKALIGN eBmpAlign)
{
	BOOL bResult = InitBkInfo(m_stBk, rgb, pBmpList, nBmpLen, eBmpAlign);
	return bResult;
}

BOOL CStaticText::SetBkColor(COLORREF rgb)
{
	if (rgb == m_stBk.m_rgbBrush)
		return TRUE;

	m_stBk.m_rgbBrush = rgb;

	if (m_stBk.m_pBrush)
	{
		delete m_stBk.m_pBrush;
		m_stBk.m_pBrush = NULL;
	}
	m_stBk.m_pBrush = new CBrush(rgb);

	return TRUE;
}

BOOL CStaticText::SetText(TCHAR* pszText, DWORD dwAlign)
{
	if (NULL == pszText)
		m_szTxt = _T("");
	else
		m_szTxt = pszText;

	m_nFormat = dwAlign;

	if (this->m_hWnd)
		this->Invalidate();

	return TRUE;
}

BOOL CStaticText::SetText(TCHAR* pszText)
{
	if (NULL == pszText)
		m_szTxt = _T("");
	else
		m_szTxt = pszText;

	if (this->m_hWnd)
		this->Invalidate();

	return TRUE;
}

BOOL CStaticText::SetTextColor(COLORREF rgb)
{
	m_stText.m_rgbTxt = rgb;
	if(this->m_hWnd)
		this->Invalidate();

	return TRUE;
}

void CStaticText::SetBreakPoint(BOOL bBreak)
{
	m_bBreakPoint = bBreak;
	if (this->m_hWnd)
		this->Invalidate();
}

//
BOOL CStaticText::InitTextInfo(INFO_TEXT& stText, TCHAR* pszFont, int nSize, BOOL bBold, COLORREF rgb)
{
	if (NULL == pszFont)
		return FALSE;

	DeinitTextInfo(stText);

	//
	SetTextColor(rgb);

	///
	LOGFONT stLf;
	memset(&stLf, 0x00, sizeof(LOGFONT));
	stLf.lfHeight = nSize;
	if (bBold)
		stLf.lfWeight = FW_BOLD;
	else
		stLf.lfWeight = FW_NORMAL;
	_tcsncpy_s(stLf.lfFaceName, LF_FACESIZE, pszFont, _tcslen(pszFont));

	stText.m_pFont = new CFont();
	stText.m_pFont->CreateFontIndirect(&stLf);
	//*/

	return TRUE;
}

void CStaticText::DeinitTextInfo(INFO_TEXT& stText)
{
	if (stText.m_pFont)
		delete stText.m_pFont;
	stText.m_pFont = NULL;

}


BOOL CStaticText::InitBkInfo(INFO_BK& stBk, COLORREF rgb, HBITMAP* pBmpList, int nBmpLen, TYPE_BKALIGN eBmpAlign)
{
	DeinitBkInfo(m_stBk);

	//
	stBk.m_rgbBrush = rgb;
	stBk.m_pBrush = new CBrush(stBk.m_rgbBrush);

	//
	if (NULL != pBmpList && 0 < nBmpLen)
	{
		stBk.m_eBmpAlign = eBmpAlign;
		for (int i = 0; i < MAX_BKIMAGE || i < nBmpLen; i++)
		{
			stBk.m_BmpList[i] = pBmpList[i];
		}
	}

	return TRUE;
}

void CStaticText::DeinitBkInfo(INFO_BK& stBk)
{
	if (stBk.m_pBrush)
		delete stBk.m_pBrush;

	stBk.m_pBrush = NULL;
	stBk.m_eBmpAlign = TYPE_BKALIGN_NONE;

	for (int i = 0; i < MAX_BKIMAGE; i++)
	{
		if (stBk.m_BmpList[i])
			::DeleteObject(stBk.m_BmpList[i]);
		stBk.m_BmpList[i] = NULL;
	}
}

void CStaticText::DrawBackground(CDC* pDC, const INFO_BK* pstBk)
{
	if (NULL == pDC || NULL == pstBk)
		return;

	CRect rect;
	this->GetClientRect(rect);

	const int nW = rect.Width();
	const int nH = rect.Height();

	if ( (TYPE_BKALIGN_SINGLE & pstBk->m_eBmpAlign) && pstBk->m_BmpList[0])
	{
		BITMAPINFO bmi;
		memset(&bmi, 0x00, sizeof(BITMAPINFO));
		bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		::GetDIBits(pDC->m_hDC, pstBk->m_BmpList[0], 0, 1, NULL, (BITMAPINFO *)&bmi, DIB_RGB_COLORS);

		CDC memDC;
		memDC.CreateCompatibleDC(pDC);
		HBITMAP hOldBmp = (HBITMAP)memDC.SelectObject(pstBk->m_BmpList[0]);

		int x = 0;
		int y = 0;
		const int w = bmi.bmiHeader.biWidth;
		const int h = bmi.bmiHeader.biHeight;

		if (TYPE_BKALIGN_LEFT & pstBk->m_eBmpAlign)			x = 0;
		else if (TYPE_BKALIGN_RIGHT & pstBk->m_eBmpAlign)	x = nW - w;
		else if (TYPE_BKALIGN_CENTER & pstBk->m_eBmpAlign)	x = (nW - w)/2;

		if (TYPE_BKALIGN_TOP & pstBk->m_eBmpAlign)			y = 0;
		else if (TYPE_BKALIGN_BOTTOM & pstBk->m_eBmpAlign)	y = nH - h;
		else if (TYPE_BKALIGN_VCENTER & pstBk->m_eBmpAlign)	y = (nH - h)/2;

		pDC->BitBlt(x, y, w, h, &memDC, 0, 0, SRCCOPY);

		memDC.SelectObject(hOldBmp);

		if (m_bBreakPoint)
		{
			const int len = 10;

			RECT rtEllipse;
			rtEllipse.left = w - len;
			rtEllipse.top = h - len;
			rtEllipse.right = w;
			rtEllipse.bottom = h;

			CBrush brush;
			brush.CreateSolidBrush(RGB(255, 0, 0));

			CBrush* pOldBrush = pDC->SelectObject(&brush);
			pDC->Ellipse(&rtEllipse);
			pDC->SelectObject(pOldBrush);
		}

	}
	else if (TYPE_BKALIGN_SINGLETILE & pstBk->m_eBmpAlign)
	{
		;
	}
	else if (TYPE_BKALIGN_PIECES & pstBk->m_eBmpAlign)
	{
		;
	}

	
}