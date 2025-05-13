// CustomCaptureDisplay.cpp : implementation file
//

#include "stdafx.h"
#include "CustomCaptureDisplay.h"
#include "Util/Util.h"

#include "Resource.h"

// CCustomCaptureDisplay

IMPLEMENT_DYNAMIC(CCustomCaptureDisplay, CStatic)

CCustomCaptureDisplay::CCustomCaptureDisplay()
{
	m_rgbBk = RGB(200, 200, 200);
	m_rgbTxt = RGB(0, 0, 0);
	m_rgbTxt = RGB(192, 192, 192);

	//
	m_szTitle = _T("CAPTURE");

	m_nFontHeight = 24;
	m_nFontWeight = FW_BOLD;
	m_szFontName = _T("MS Shell Dlg");

	//
	m_pctlDisplay = NULL;
	m_ePosType = TYPE_CAMERAPOS_NONE;

	m_pctlCount = NULL;
	m_dwFrameCount = 0;
}

CCustomCaptureDisplay::~CCustomCaptureDisplay()
{
	if (m_pctlDisplay)
		delete m_pctlDisplay;
	m_pctlDisplay = NULL;

	if (m_pctlCount)
		delete m_pctlCount;
	m_pctlCount = NULL;

}

void CCustomCaptureDisplay::SetTitle(TCHAR* pszTitle)
{
	if (pszTitle)
		m_szTitle = pszTitle;
	else
		m_szTitle = _T("");

	if(this->m_hWnd)
		this->Invalidate();
}

void CCustomCaptureDisplay::SetPostionType(TYPE_CAMERAPOS eType)
{
	m_ePosType = eType;
	if (m_pctlDisplay)
	{
		m_pctlDisplay->SetPostionType(eType);
	}
}

BOOL CCustomCaptureDisplay::DisplayImage(const INFO_IMAGE* pstImage, const DWORD dwCurFlag, const INFO_CAPTURE_PROCESS* pstCapture)
{
	BOOL bResult = FALSE;
	if (m_pctlDisplay && m_pctlDisplay->m_hWnd)
	{
		bResult = m_pctlDisplay->DisplayVideoDevice(pstImage, dwCurFlag, pstCapture);
	}
	return bResult;
}

void CCustomCaptureDisplay::ClearImage()
{
	if (m_pctlDisplay && m_pctlDisplay->m_hWnd)
	{
		m_pctlDisplay->ClearVideoDevice();
	}
}

BOOL CCustomCaptureDisplay::IsClearImage()
{
	BOOL bClear = TRUE;
	if (m_pctlDisplay && m_pctlDisplay->m_hWnd)
	{
		bClear = m_pctlDisplay->IsClearVideoDevice();
	}
	return bClear;
}

void CCustomCaptureDisplay::AddCount()
{
	if (0==m_dwFrameCount && m_pctlCount && m_pctlCount->m_hWnd)
	{
		m_pctlCount->ShowWindow(SW_SHOW);
	}
	if (m_pctlCount && m_pctlCount->m_hWnd)
	{
		m_dwFrameCount++;

		TCHAR szText[32] = { 0, };
		CUtil::StringFormat(szText, 32, _T("%d"), m_dwFrameCount);
		m_pctlCount->SetText(szText, DT_RIGHT | DT_VCENTER | DT_SINGLELINE);
	}
}

void CCustomCaptureDisplay::ClearCount()
{
	m_dwFrameCount = 0;
	if (m_pctlCount && m_pctlCount->m_hWnd)
	{
		m_pctlCount->ShowWindow(SW_HIDE);
	}
}

BEGIN_MESSAGE_MAP(CCustomCaptureDisplay, CStatic)
	ON_WM_SIZE()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CCustomCaptureDisplay message handlers
void CCustomCaptureDisplay::PreSubclassWindow()
{
	CStatic::PreSubclassWindow();
}

void CCustomCaptureDisplay::OnSize(UINT nType, int cx, int cy)
{
	CStatic::OnSize(nType, cx, cy);
	AdjustLayout();

}

void CCustomCaptureDisplay::OnPaint()
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
		DrawTitle(&MemDC);
	}

	dc.BitBlt(0, 0, ulWindowWidth, ulWindowHeight, &MemDC, 0, 0, SRCCOPY);
	DeleteObject(hBitmap);
}

void CCustomCaptureDisplay::DrawTitle(CDC* pMemDC)
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
	rtRect.left = rect.left + MARGIN;
	rtRect.top = rect.top + MARGIN;
	rtRect.right = rect.right - MARGIN;
	rtRect.bottom = rect.bottom - MARGIN;

	pMemDC->SetBkMode(TRANSPARENT);
	pMemDC->SetTextColor(m_rgbTxt);
	pMemDC->DrawText(m_szTitle, &rtRect, DT_CENTER | DT_SINGLELINE);
	pMemDC->SelectObject(pOlfFont);

}

void CCustomCaptureDisplay::DrawBackground(CDC* pMemDC)
{
	if (NULL == pMemDC)
		return;

	CRect rect;
	this->GetClientRect(&rect);

	const int w = rect.Width();
	const int h = rect.Height();

	pMemDC->FillSolidRect(&rect, m_rgbBk);

	///
	CDC MemDC;
	MemDC.CreateCompatibleDC(pMemDC);

	BITMAP bm;
	if (TYPE_CAMERAPOS_FIRST == m_ePosType)
	{
		HBITMAP hBmpLeftTop = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_STATIC_GUARD_LEFTTOP));
		if (hBmpLeftTop)
		{
			::GetObject(hBmpLeftTop, sizeof(BITMAP), &bm);

			HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpLeftTop);
			pMemDC->BitBlt(0, 0, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

			MemDC.SelectObject(hOld);
			::DeleteObject(hBmpLeftTop);
		}

		HBITMAP hBmpLeftBottom = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_STATIC_GUARD_LEFTBOTTOM));
		if (hBmpLeftBottom)
		{
			::GetObject(hBmpLeftBottom, sizeof(BITMAP), &bm);

			HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpLeftBottom);
			pMemDC->BitBlt(0, h - bm.bmHeight, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

			MemDC.SelectObject(hOld);
			::DeleteObject(hBmpLeftBottom);
		}
	}

	if (TYPE_CAMERAPOS_SECOND == m_ePosType)
	{
		HBITMAP hBmpRightTop = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_STATIC_GUARD_RIGHTTOP));
		if (hBmpRightTop)
		{
			::GetObject(hBmpRightTop, sizeof(BITMAP), &bm);

			HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpRightTop);
			pMemDC->BitBlt(w - bm.bmWidth, 0, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

			MemDC.SelectObject(hOld);
			::DeleteObject(hBmpRightTop);
		}

		HBITMAP hBmpRightBottom = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_STATIC_GUARD_RIGHTBOTTOM));
		if (hBmpRightBottom)
		{
			::GetObject(hBmpRightBottom, sizeof(BITMAP), &bm);

			HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpRightBottom);
			pMemDC->BitBlt(w - bm.bmWidth, h - bm.bmHeight, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

			MemDC.SelectObject(hOld);
			::DeleteObject(hBmpRightBottom);
		}
	}
	//*/
}

void CCustomCaptureDisplay::AdjustLayout()
{
	CRect rtClient;
	GetClientRect(&rtClient);

	int nWidth = rtClient.Width();
	int nHeight = rtClient.Height();

	CRect rtCtrl;

	if (TYPE_CAMERAPOS_FIRST == m_ePosType)
	{
		rtCtrl.left = rtClient.left + MARGIN * 2;
		rtCtrl.right = rtClient.right;
	}
	else if (TYPE_CAMERAPOS_SECOND == m_ePosType)
	{
		rtCtrl.left = rtClient.left;
		rtCtrl.right = rtClient.right - MARGIN * 2;
	}
	rtCtrl.top = rtClient.top + MARGIN * 7;
	rtCtrl.bottom = rtClient.bottom - MARGIN * 2;

	CRect rtTxt;
	rtTxt.left = rtClient.right - MARGIN * 30;
	rtTxt.top = rtClient.top + MARGIN;
	rtTxt.right = rtTxt.left + MARGIN * 28;
	rtTxt.bottom = rtTxt.top + MARGIN * 6;

	if (NULL == m_pctlDisplay)
	{
		const DWORD dwCtrlId = this->GetDlgCtrlID();
		const DWORD dwStyle = WS_CHILD | WS_VISIBLE;

		m_pctlDisplay = new CStaticDisplay;
		m_pctlDisplay->Create(_T(""), dwStyle, rtCtrl, this, dwCtrlId);
		m_pctlDisplay->SetBkColor(m_rgbBk);
		m_pctlDisplay->SetPostionType(m_ePosType);
	}
	else
	{
		m_pctlDisplay->SetWindowPos(NULL, rtCtrl.left, rtCtrl.top, rtCtrl.Width(), rtCtrl.Height(), SWP_NOACTIVATE | SWP_NOZORDER);
	}

	if (NULL == m_pctlCount)
	{
		const DWORD dwCtrlId = this->GetDlgCtrlID();
		const DWORD dwStyle = WS_CHILD | WS_VISIBLE;

		m_pctlCount = new CStaticText;
		m_pctlCount->Create(_T(""), dwStyle, rtTxt, this, dwCtrlId);
		m_pctlCount->SetBkColor(m_rgbBk);
		m_pctlCount->SetTextInfo(_T("MS Shell Dlg"), 28, TRUE, RGB(0, 128, 0));

		m_pctlCount->SetText(_T("0"), DT_RIGHT | DT_VCENTER | DT_SINGLELINE);
	}
	else
	{
		m_pctlCount->SetWindowPos(NULL, rtTxt.left, rtTxt.top, rtTxt.Width(), rtTxt.Height(), SWP_NOACTIVATE | SWP_NOZORDER);
	}
}

