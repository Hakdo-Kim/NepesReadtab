// CustomScrollViewSize.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "CustomScrollViewSize.h"

#include "CaptureManager.h"
#include "Util/Util.h"

#include "Video/ConvertColor.h"
#include "inc/PixelFormat.h"

#include <gdiplus.h>
#pragma comment(lib, "Gdiplus.lib")

// CCustomScrollViewSize

IMPLEMENT_DYNCREATE(CCustomScrollViewSize, CScrollView)

CCustomScrollViewSize::CCustomScrollViewSize()
{
	::InitializeCriticalSection(&m_CriticalSection);

	/// Init Gdi Plus
	Gdiplus::GdiplusStartupInput input;
	Gdiplus::GdiplusStartup(&m_GdiPlusToken, &input, NULL);


	m_bFitZoom = TRUE;
	m_fZoom = 1.0f;

	m_pstDisplayImage = NULL;
	m_pstOutputSize = NULL;
}

CCustomScrollViewSize::~CCustomScrollViewSize()
{
	::DeleteCriticalSection(&m_CriticalSection);
	ClearResult();


	GdiplusShutdown(m_GdiPlusToken);
}


BEGIN_MESSAGE_MAP(CCustomScrollViewSize, CScrollView)
	ON_WM_SIZE()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CCustomScrollViewSize drawing

void CCustomScrollViewSize::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CCustomScrollViewSize::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
}



// CCustomScrollViewSize diagnostics

#ifdef _DEBUG
void CCustomScrollViewSize::AssertValid() const
{
	CScrollView::AssertValid();
}

#ifndef _WIN32_WCE
void CCustomScrollViewSize::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif
#endif //_DEBUG


// CCustomScrollViewSize message handlers

void CCustomScrollViewSize::OnSize(UINT nType, int cx, int cy)
{
	CScrollView::OnSize(nType, cx, cy);

	if (m_bFitZoom)
	{
		this->SetFitZoom(m_bFitZoom);
	}
	UpdateScrollSize();
}

void CCustomScrollViewSize::OnPaint()
{
	CPaintDC dc(this);

	CRect rect;
	GetClientRect(&rect);
	const int nClientWidth = rect.Width();
	const int nClientHeight = rect.Height();

	CDC MemDC;
	MemDC.CreateCompatibleDC(&dc);

	HBITMAP hBitmap;       // bitmap handle 
	BITMAPINFO bmi;        // bitmap header 
	VOID *pvBits;          // pointer to DIB section 

	ZeroMemory(&bmi, sizeof(BITMAPINFO));
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = nClientWidth;
	bmi.bmiHeader.biHeight = -nClientHeight;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 24;
	bmi.bmiHeader.biCompression = BI_RGB;
	bmi.bmiHeader.biSizeImage = nClientWidth * nClientHeight * 3;

	hBitmap = CreateDIBSection(MemDC.m_hDC, &bmi, DIB_RGB_COLORS, &pvBits, NULL, 0x0);
	if (hBitmap)
	{
		HBITMAP hOldBitmap = (HBITMAP)::SelectObject(MemDC.m_hDC, hBitmap);

		CBrush Brush;
		Brush.CreateHatchBrush(HS_DIAGCROSS, RGB(191, 191, 191));
		FillOutsideRect(&MemDC, &Brush);

		// Image Display
#ifdef USE_BASLER_CAMERA
		DrawImage24bit(&MemDC);
#else
		DrawImage(&MemDC);
#endif

		dc.BitBlt(0, 0, nClientWidth, nClientHeight, &MemDC, 0, 0, SRCCOPY);

		::SelectObject(MemDC.m_hDC, hOldBitmap);
		::DeleteObject(hBitmap);
	}
}


void CCustomScrollViewSize::DrawImage(CDC* pDC)
{
	if (NULL == pDC || NULL == m_pstDisplayImage)
		return;

	CRect rect;
	GetClientRect(&rect);
	const int nClientWidth = rect.Width();
	const int nClientHeight = rect.Height();


	// Image
	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);

	const int w = m_pstDisplayImage->m_stFrame.m_dwWidth;
	const int h = m_pstDisplayImage->m_stFrame.m_dwHeight;
	const int pitch = (w + 3) / 4 * 4;

	HBITMAP hBitmap;       // bitmap handle 
	VOID *pvBits;          // pointer to DIB section 

	const int COLOR = 256;
	BITMAPINFO* pstBmpInfo = (BITMAPINFO*) new BYTE[sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD)*COLOR];
	pstBmpInfo->bmiHeader.biClrUsed = COLOR;

	for (int i = 0; i<COLOR; i++)
	{
		pstBmpInfo->bmiColors[i].rgbBlue = i;
		pstBmpInfo->bmiColors[i].rgbGreen = i;
		pstBmpInfo->bmiColors[i].rgbRed = i;
		pstBmpInfo->bmiColors[i].rgbReserved = i;
	}

	pstBmpInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	pstBmpInfo->bmiHeader.biWidth = w;
	pstBmpInfo->bmiHeader.biHeight = -h;
	pstBmpInfo->bmiHeader.biPlanes = 1;
	pstBmpInfo->bmiHeader.biBitCount = 8;
	pstBmpInfo->bmiHeader.biCompression = BI_RGB;
	pstBmpInfo->bmiHeader.biSizeImage = pitch * h;

	hBitmap = CreateDIBSection(MemDC.m_hDC, pstBmpInfo, DIB_RGB_COLORS, &pvBits, NULL, 0x0);
	if (hBitmap)
	{
		BYTE* pSrc = NULL;
		BYTE* pDest = NULL;

		HBITMAP hOldBitmap = (HBITMAP)::SelectObject(MemDC.m_hDC, hBitmap);
		for (int y = 0; y < h; y++)
		{
			pDest = (BYTE*)pvBits + y*pitch;
			pSrc = m_pstDisplayImage->m_pBuffer + y * w;

			memcpy(pDest, pSrc, w);
		}


		const double fZoom = this->GetZoom();

		int x1 = 0;
		int y1 = 0;
		int cx1 = (int)(w * fZoom);
		int cy1 = (int)(h * fZoom);

		if (DEFAULT_ZOOM_FACTOR == fZoom)
		{
			int x2 = GetScrollPos(SB_HORZ);
			int y2 = GetScrollPos(SB_VERT);
			pDC->BitBlt(x1, y1, cx1, cy1, &MemDC, x2, y2, SRCCOPY);
		}
		else if (m_bFitZoom)
		{
			pDC->SetStretchBltMode(STRETCH_HALFTONE);
			pDC->StretchBlt(x1, y1, cx1, cy1, &MemDC, 0, 0, w, h, SRCCOPY);
		}
		else
		{
			int x2 = (int)(GetScrollPos(SB_HORZ) / fZoom);
			int y2 = (int)(GetScrollPos(SB_VERT) / fZoom);
			int cx2 = (int)(nClientWidth / fZoom);
			int cy2 = (int)(nClientHeight / fZoom);

			if (cx1 > nClientWidth)
				cx1 = nClientWidth;
			if (cy1 > nClientHeight)
				cy1 = nClientHeight;

			if (w < (x2 + cx2))
				cx2 = w - x2;
			if (h < (y2 + cy2))
				cy2 = h - y2;

			pDC->SetStretchBltMode(STRETCH_HALFTONE);
			pDC->StretchBlt(x1, y1, cx1, cy1, &MemDC, x2, y2, cx2, cy2, SRCCOPY);
		}

		::SelectObject(MemDC.m_hDC, hOldBitmap);
		::DeleteObject(hBitmap);
	}
	delete[] pstBmpInfo;



	// Draw Roi
	{
		//double fZoom = 1.0f;
		double fZoom = GetZoom();
		// Output Roi
		if (m_pstOutputSize)
		{
			COLORREF rgbOutLine = RGB(0xFF, 0xFF, 0x00);
			COLORREF rgbLine = RGB(0x00, 0xFF, 0x00);
			COLORREF rgbError = RGB(0xFF, 0x00, 0x00);
			int nOutLine = 1;
			int nLine = 2;

			Gdiplus::Graphics graphics(pDC->m_hDC);
			graphics.SetSmoothingMode(Gdiplus::SmoothingModeAntiAlias);

			Gdiplus::Color clrOutLine(Gdiplus::Color::MakeARGB(0xFF, GetRValue(rgbOutLine), GetGValue(rgbOutLine), GetBValue(rgbOutLine)));
			Gdiplus::Color clrLine(Gdiplus::Color::MakeARGB(0xFF, GetRValue(rgbLine), GetGValue(rgbLine), GetBValue(rgbLine)));
			Gdiplus::Color clrError(Gdiplus::Color::MakeARGB(0xFF, GetRValue(rgbError), GetGValue(rgbError), GetBValue(rgbError)));

			Gdiplus::Pen penOutLine(clrOutLine, (Gdiplus::REAL)nOutLine);
			Gdiplus::Pen penLine(clrLine, (Gdiplus::REAL)nLine);
			Gdiplus::Pen penError(clrError, (Gdiplus::REAL)nLine);

			penLine.SetStartCap(Gdiplus::LineCapRoundAnchor);
			penLine.SetEndCap(Gdiplus::LineCapRoundAnchor);
			penError.SetStartCap(Gdiplus::LineCapRoundAnchor);
			penError.SetEndCap(Gdiplus::LineCapRoundAnchor);

			// OutLine
			penOutLine.SetDashStyle(Gdiplus::DashStyleDash);
			for (int i = 0; i < 4; i++)
			{
				const stLine* pLine = &m_pstOutputSize->m_stResultLine[i];
				Gdiplus::REAL x1 = pLine->m_fStartX * fZoom;
				Gdiplus::REAL y1 = pLine->m_fStartY * fZoom;
				Gdiplus::REAL x2 = pLine->m_fEndX * fZoom;
				Gdiplus::REAL y2 = pLine->m_fEndY * fZoom;
				graphics.DrawLine(&penOutLine, x1, y1, x2, y2);
			}
			{
				const stLine* pLine = &m_pstOutputSize->m_stResultLine[5];
				Gdiplus::REAL x1 = pLine->m_fStartX * fZoom;
				Gdiplus::REAL y1 = pLine->m_fStartY * fZoom;
				Gdiplus::REAL x2 = pLine->m_fEndX * fZoom;
				Gdiplus::REAL y2 = pLine->m_fEndY * fZoom;
				graphics.DrawLine(&penOutLine, x1, y1, x2, y2);
			}
			{
				const stLine* pLine = &m_pstOutputSize->m_stResultLine[10];
				Gdiplus::REAL x1 = pLine->m_fStartX * fZoom;
				Gdiplus::REAL y1 = pLine->m_fStartY * fZoom;
				Gdiplus::REAL x2 = pLine->m_fEndX * fZoom;
				Gdiplus::REAL y2 = pLine->m_fEndY * fZoom;
				graphics.DrawLine(&penOutLine, x1, y1, x2, y2);
			}

			// Line (OK, NG)
#if 1
			{
				INFO_LINE_GDIPLUS stLineGdiPlus;
				stPOINT ptText;

				CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
				const INFO_OPTION* pstOption = pCaptureManager->GetOption();

				for (int i = 0; i < MAX_GEOMETRY_DISTANCELINE_COUNT; i++)
				{
					const OUTPUT_DISTANCE* pstOutput = &m_pstOutputSize->m_stDistance[i];
					if (TYPE_GEOMETRY_DISTANCE_D == i)			GetLineDistance_d(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_L == i)		GetLineDistance_L(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_W == i)		GetLineDistance_W(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_I1 == i)	GetLineDistance_I1(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_I2 == i)	GetLineDistance_I2(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_I3 == i)	GetLineDistance_I3(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_M1 == i)	GetLineDistance_M1(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_M2 == i)	GetLineDistance_M2(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_S1 == i)	GetLineDistance_S1(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_S2 == i)	GetLineDistance_S2(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_S3 == i)	GetLineDistance_S3(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_S4 == i)	GetLineDistance_S4(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_S5 == i)	GetLineDistance_S5(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_X1 == i)	GetLineDistance_X1(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_X2 == i)	GetLineDistance_X2(m_pstOutputSize, i, stLineGdiPlus, ptText);
					// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
					/*else if (TYPE_GEOMETRY_DISTANCE_R1 == i)	GetLineDistance_R(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_R2 == i)	GetLineDistance_R(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_R3 == i)	GetLineDistance_R(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_R4 == i)	GetLineDistance_R(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_R5 == i)	GetLineDistance_R(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_R6 == i)	GetLineDistance_R(m_pstOutputSize, i, stLineGdiPlus, ptText);*/
					else if (TYPE_GEOMETRY_DISTANCE_SS1 == i)	GetLineDistance_SS1(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_SS2 == i)	GetLineDistance_SS2(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_SS3 == i)	GetLineDistance_SS3(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else				continue;

					Gdiplus::REAL x1 = stLineGdiPlus.m_fx1 * fZoom;
					Gdiplus::REAL y1 = stLineGdiPlus.m_fy1 * fZoom;
					Gdiplus::REAL x2 = stLineGdiPlus.m_fx2 * fZoom;
					Gdiplus::REAL y2 = stLineGdiPlus.m_fy2 * fZoom;

					{
						Gdiplus::Font font(L"MS Shell Dlg", 10, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
						Gdiplus::SolidBrush brFont(clrLine);
						Gdiplus::SolidBrush brFontE(clrError);
						
						WCHAR szText[MAX_NAME_LEN] = { 0, };

#ifndef _UNICODE
						size_t cnt;
						WCHAR szWName[MAX_NAME_LEN] = { 0, };
						mbstowcs_s(&cnt, szWName, sizeof(szWName) / sizeof(wchar_t), pstOption->m_stSizeName.m_szName[i], sizeof(szWName));
						swprintf(szText, L"%s(%.03f)", szWName, pstOutput->m_dValue);
#else
						swprintf(szText, L"%s(%.03f)", pstOption->m_stSizeName.m_szName[i], pstOutput->m_dValue);
#endif

						Gdiplus::PointF ptF;
						ptF.X = ptText.m_fX * fZoom;
						ptF.Y = ptText.m_fY * fZoom;
						if (pstOutput->m_bOK)
						{
							graphics.DrawLine(&penLine, x1, y1, x2, y2);
							graphics.DrawString(szText, wcslen(szText), &font, ptF, &brFont);
						}
						else
						{
							graphics.DrawLine(&penError, x1, y1, x2, y2);
							graphics.DrawString(szText, wcslen(szText), &font, ptF, &brFontE);
						}
					}
				}
			}
#else
			for (int i = 0; i < MAX_GEOMETRY_DISTANCELINE_COUNT; i++)
			{
				const OUTPUT_DISTANCE* pstOutput = &m_pstOutputSize->m_stDistance[i];
				const stLine* pLine = &m_pstOutputSize->m_stDistanceLine[i];

				Gdiplus::REAL x1 = pLine->m_fStartX * fZoom;
				Gdiplus::REAL y1 = pLine->m_fStartY * fZoom;
				Gdiplus::REAL x2 = pLine->m_fEndX * fZoom;
				Gdiplus::REAL y2 = pLine->m_fEndY * fZoom;

				if (pstOutput->m_bOK)
					graphics.DrawLine(&penLine, x1, y1, x2, y2);
				else
					graphics.DrawLine(&penError, x1, y1, x2, y2);
			}
#endif
		}
	}
}

void CCustomScrollViewSize::DrawImage24bit(CDC* pDC)
{
	if (NULL == pDC || NULL == m_pstDisplayImage)
		return;

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	CRect rect;
	GetClientRect(&rect);
	const int nClientWidth = rect.Width();
	const int nClientHeight = rect.Height();


	// Image
	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);

	const INFO_FRAME* pFrame = &m_pstDisplayImage->m_stFrame;
	const int nBit = pCaptureManager->GetBitCount(m_pstDisplayImage->m_stFrame.m_eDataBit);
	const int nFrameWidth = m_pstDisplayImage->m_stFrame.m_dwWidth;
	const int nFrameHeight = m_pstDisplayImage->m_stFrame.m_dwHeight;

	const int n24BitPitch = (nFrameWidth * 3 + 3) / 4 * 4;
	const int nFramePitch = (nFrameWidth * nBit / 8 + 3) / 4 * 4;

	HBITMAP hBitmap;       // bitmap handle 
	VOID *pvBits;          // pointer to DIB section 

	BITMAPINFO* pstBmpInfo = new BITMAPINFO;

	pstBmpInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	pstBmpInfo->bmiHeader.biWidth = nFrameWidth;
	pstBmpInfo->bmiHeader.biHeight = -nFrameHeight;
	pstBmpInfo->bmiHeader.biPlanes = 1;
	pstBmpInfo->bmiHeader.biBitCount = 24;
	pstBmpInfo->bmiHeader.biCompression = BI_RGB;
	pstBmpInfo->bmiHeader.biSizeImage = n24BitPitch*nFrameHeight;

	hBitmap = CreateDIBSection(MemDC.m_hDC, pstBmpInfo, DIB_RGB_COLORS, &pvBits, NULL, 0x0);
	if (hBitmap)
	{
		BYTE* pSrc = NULL;
		BYTE* pDest = NULL;

		HBITMAP hOldBitmap = (HBITMAP)::SelectObject(MemDC.m_hDC, hBitmap);

		///
		pDest = (BYTE*)pvBits;

		if (TYPE_CAMCOLOR_COLOR == pFrame->m_eColor)
		{
			if (TYPE_DATABIT_08 == pFrame->m_eDataBit || TYPE_DATABIT_10 == pFrame->m_eDataBit || TYPE_DATABIT_12 == pFrame->m_eDataBit)
			{
				for (int y = 0; y < pFrame->m_dwHeight; y++)
					memcpy(pDest + y*n24BitPitch, m_pstDisplayImage->m_pBuffer + y*n24BitPitch, n24BitPitch);
			}
		}
		else
		{
			// Captured image from camera...
			for (int y = 0; y < nFrameHeight; y++)
			{
				pDest = (BYTE*)pvBits + y*nFramePitch;
				pSrc = m_pstDisplayImage->m_pBuffer + y * nFramePitch;
				memcpy(pDest, pSrc, nFramePitch);
			}
		}

		const double fZoom = this->GetZoom();

		int x1 = 0;
		int y1 = 0;
		int cx1 = (int)(nFrameWidth * fZoom);
		int cy1 = (int)(nFrameHeight * fZoom);

		if (DEFAULT_ZOOM_FACTOR == fZoom)
		{
			int x2 = GetScrollPos(SB_HORZ);
			int y2 = GetScrollPos(SB_VERT);
			pDC->BitBlt(x1, y1, cx1, cy1, &MemDC, x2, y2, SRCCOPY);
		}
		else if (m_bFitZoom)
		{
			pDC->SetStretchBltMode(STRETCH_HALFTONE);
			pDC->StretchBlt(x1, y1, cx1, cy1, &MemDC, 0, 0, nFrameWidth, nFrameHeight, SRCCOPY);
		}
		else
		{
			int x2 = (int)(GetScrollPos(SB_HORZ) / fZoom);
			int y2 = (int)(GetScrollPos(SB_VERT) / fZoom);
			int cx2 = (int)(nClientWidth / fZoom);
			int cy2 = (int)(nClientHeight / fZoom);

			if (cx1 > nClientWidth)
				cx1 = nClientWidth;
			if (cy1 > nClientHeight)
				cy1 = nClientHeight;

			if (nFrameWidth < (x2 + cx2))
				cx2 = nFrameWidth - x2;
			if (nFrameHeight < (y2 + cy2))
				cy2 = nFrameHeight - y2;

			pDC->SetStretchBltMode(STRETCH_HALFTONE);
			pDC->StretchBlt(x1, y1, cx1, cy1, &MemDC, x2, y2, cx2, cy2, SRCCOPY);
		}

		::SelectObject(MemDC.m_hDC, hOldBitmap);
		::DeleteObject(hBitmap);
	}
	delete[] pstBmpInfo;

	// Draw Roi
	{
		//double fZoom = 1.0f;
		double fZoom = GetZoom();

		// Output Roi
		if (m_pstOutputSize)
		{
			COLORREF rgbOutLine = RGB(0xFF, 0xFF, 0x00);
			COLORREF rgbLine = RGB(0x00, 0xFF, 0x00);
			COLORREF rgbError = RGB(0xFF, 0x00, 0x00);
			int nOutLine = 1;
			int nLine = 2;

			Gdiplus::Graphics graphics(pDC->m_hDC);
			graphics.SetSmoothingMode(Gdiplus::SmoothingModeAntiAlias);

			Gdiplus::Color clrOutLine(Gdiplus::Color::MakeARGB(0xFF, GetRValue(rgbOutLine), GetGValue(rgbOutLine), GetBValue(rgbOutLine)));
			Gdiplus::Color clrLine(Gdiplus::Color::MakeARGB(0xFF, GetRValue(rgbLine), GetGValue(rgbLine), GetBValue(rgbLine)));
			Gdiplus::Color clrError(Gdiplus::Color::MakeARGB(0xFF, GetRValue(rgbError), GetGValue(rgbError), GetBValue(rgbError)));

			Gdiplus::Pen penOutLine(clrOutLine, (Gdiplus::REAL)nOutLine);
			Gdiplus::Pen penLine(clrLine, (Gdiplus::REAL)nLine);
			Gdiplus::Pen penError(clrError, (Gdiplus::REAL)nLine);

			penLine.SetStartCap(Gdiplus::LineCapRoundAnchor);
			penLine.SetEndCap(Gdiplus::LineCapRoundAnchor);
			penError.SetStartCap(Gdiplus::LineCapRoundAnchor);
			penError.SetEndCap(Gdiplus::LineCapRoundAnchor);

			// OutLine
			penOutLine.SetDashStyle(Gdiplus::DashStyleDash);
			for (int i = 0; i < 4; i++)
			{
				const stLine* pLine = &m_pstOutputSize->m_stResultLine[i];
				Gdiplus::REAL x1 = pLine->m_fStartX * fZoom;
				Gdiplus::REAL y1 = pLine->m_fStartY * fZoom;
				Gdiplus::REAL x2 = pLine->m_fEndX * fZoom;
				Gdiplus::REAL y2 = pLine->m_fEndY * fZoom;
				graphics.DrawLine(&penOutLine, x1, y1, x2, y2);
			}
			{
				const stLine* pLine = &m_pstOutputSize->m_stResultLine[5];
				Gdiplus::REAL x1 = pLine->m_fStartX * fZoom;
				Gdiplus::REAL y1 = pLine->m_fStartY * fZoom;
				Gdiplus::REAL x2 = pLine->m_fEndX * fZoom;
				Gdiplus::REAL y2 = pLine->m_fEndY * fZoom;
				graphics.DrawLine(&penOutLine, x1, y1, x2, y2);
			}
			{
				const stLine* pLine = &m_pstOutputSize->m_stResultLine[10];
				Gdiplus::REAL x1 = pLine->m_fStartX * fZoom;
				Gdiplus::REAL y1 = pLine->m_fStartY * fZoom;
				Gdiplus::REAL x2 = pLine->m_fEndX * fZoom;
				Gdiplus::REAL y2 = pLine->m_fEndY * fZoom;
				graphics.DrawLine(&penOutLine, x1, y1, x2, y2);
			}

			// Line (OK, NG)
#if 1
			{
				INFO_LINE_GDIPLUS stLineGdiPlus;
				stPOINT ptText;

				CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
				const INFO_OPTION* pstOption = pCaptureManager->GetOption();

				for (int i = 0; i < MAX_GEOMETRY_DISTANCELINE_COUNT; i++)
				{
					const OUTPUT_DISTANCE* pstOutput = &m_pstOutputSize->m_stDistance[i];
					if (TYPE_GEOMETRY_DISTANCE_D == i)			GetLineDistance_d(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_L == i)		GetLineDistance_L(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_W == i)		GetLineDistance_W(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_I1 == i)	GetLineDistance_I1(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_I2 == i)	GetLineDistance_I2(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_I3 == i)	GetLineDistance_I3(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_M1 == i)	GetLineDistance_M1(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_M2 == i)	GetLineDistance_M2(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_S1 == i)	GetLineDistance_S1(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_S2 == i)	GetLineDistance_S2(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_S3 == i)	GetLineDistance_S3(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_S4 == i)	GetLineDistance_S4(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_S5 == i)	GetLineDistance_S5(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_X1 == i)	GetLineDistance_X1(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_X2 == i)	GetLineDistance_X2(m_pstOutputSize, i, stLineGdiPlus, ptText);
					// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
					else if (TYPE_GEOMETRY_DISTANCE_R1 == i)	GetLineDistance_R(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_R2 == i)	GetLineDistance_R(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_R3 == i)	GetLineDistance_R(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_R4 == i)	GetLineDistance_R(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_R5 == i)	GetLineDistance_R(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_R6 == i)	GetLineDistance_R(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_SS1 == i)	GetLineDistance_SS1(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_SS2 == i)	GetLineDistance_SS2(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_SS3 == i)	GetLineDistance_SS3(m_pstOutputSize, i, stLineGdiPlus, ptText);
					else										continue;

					Gdiplus::REAL x1 = stLineGdiPlus.m_fx1 * fZoom;
					Gdiplus::REAL y1 = stLineGdiPlus.m_fy1 * fZoom;
					Gdiplus::REAL x2 = stLineGdiPlus.m_fx2 * fZoom;
					Gdiplus::REAL y2 = stLineGdiPlus.m_fy2 * fZoom;

					{
						Gdiplus::Font font(L"MS Shell Dlg", 10, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
						Gdiplus::SolidBrush brFont(clrLine);
						Gdiplus::SolidBrush brFontE(clrError);

						WCHAR szText[MAX_NAME_LEN] = { 0, };

#ifndef _UNICODE
						size_t cnt;
						WCHAR szWName[MAX_NAME_LEN] = { 0, };
						mbstowcs_s(&cnt, szWName, sizeof(szWName) / sizeof(wchar_t), pstOption->m_stSizeName.m_szName[i], sizeof(szWName));
						swprintf(szText, L"%s(%.03f)", szWName, pstOutput->m_dValue);
#else
						swprintf(szText, L"%s(%.03f)", pstOption->m_stSizeName.m_szName[i], pstOutput->m_dValue);
#endif

						Gdiplus::PointF ptF;
						ptF.X = ptText.m_fX * fZoom;
						ptF.Y = ptText.m_fY * fZoom;
						if (pstOutput->m_bOK)
						{
							graphics.DrawLine(&penLine, x1, y1, x2, y2);
							graphics.DrawString(szText, wcslen(szText), &font, ptF, &brFont);
						}
						else
						{
							graphics.DrawLine(&penError, x1, y1, x2, y2);
							graphics.DrawString(szText, wcslen(szText), &font, ptF, &brFontE);
						}
					}
				}
			}
#else
			for (int i = 0; i < MAX_GEOMETRY_DISTANCELINE_COUNT; i++)
			{
				const OUTPUT_DISTANCE* pstOutput = &m_pstOutputSize->m_stDistance[i];
				const stLine* pLine = &m_pstOutputSize->m_stDistanceLine[i];

				Gdiplus::REAL x1 = pLine->m_fStartX * fZoom;
				Gdiplus::REAL y1 = pLine->m_fStartY * fZoom;
				Gdiplus::REAL x2 = pLine->m_fEndX * fZoom;
				Gdiplus::REAL y2 = pLine->m_fEndY * fZoom;

				if (pstOutput->m_bOK)
					graphics.DrawLine(&penLine, x1, y1, x2, y2);
				else
					graphics.DrawLine(&penError, x1, y1, x2, y2);
			}
#endif
		}
	}

}

void CCustomScrollViewSize::UpdateScrollSize()
{
	SIZE size;
	memset(&size, 0x00, sizeof(SIZE));
	size.cx = 1;
	size.cy = 1;


	const double fZoom = this->GetZoom();
	if (m_pstDisplayImage)
	{
		size.cx = (long)(m_pstDisplayImage->m_stFrame.m_dwWidth * fZoom);
		size.cy = (long)(m_pstDisplayImage->m_stFrame.m_dwHeight * fZoom);
	}

	SetScrollSizes(MM_TEXT, size);
	this->Invalidate(FALSE);
}

void CCustomScrollViewSize::GetLineDistance_d(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
{
	memset(&stLineGdiPlus, 0x00, sizeof(INFO_LINE_GDIPLUS));
	if (NULL == pstOutputSize)
		return;

	const double PI = 3.14159265;

	// Base Point
	const int nPtIndex = 0;
	const stPOINT* pBasePoint = &pstOutputSize->m_stResultPoint[nPtIndex];

	// Line
	const stLine* pLine = &pstOutputSize->m_stDistanceLine[nIdx];

	const double fDeltaX = pBasePoint->m_fX - pLine->m_fStartX;
	const double fDeltaY = pBasePoint->m_fY - pLine->m_fStartY;

	stLineGdiPlus.m_fx1 = pLine->m_fStartX + fDeltaX;
	stLineGdiPlus.m_fy1 = pLine->m_fStartY + fDeltaY;
	stLineGdiPlus.m_fx2 = pLine->m_fEndX + fDeltaX;
	stLineGdiPlus.m_fy2 = pLine->m_fEndY + fDeltaY;


	// Move line position
	{
		const int cx = 200;

		POINT pt1;
		pt1.x = stLineGdiPlus.m_fx1;
		pt1.y = stLineGdiPlus.m_fy1;
		POINT pt2;
		pt2.x = stLineGdiPlus.m_fx2;
		pt2.y = stLineGdiPlus.m_fy2;

		//       270
		//       |
		// 180 -------- 0
		//       |
		//       90

		const double fDegree = abs(CUtil::GetAngle(pt1, pt2, TRUE));
		if (90 > fDegree)
		{
			double cy = cx * tan((90 - fDegree) * PI / 180);

			stLineGdiPlus.m_fy1 -= cy;
			stLineGdiPlus.m_fy2 -= cy;
		}
		else if (90 < fDegree)
		{
			double cy = cx * tan((fDegree - 90) * PI / 180);

			stLineGdiPlus.m_fy1 += cy;
			stLineGdiPlus.m_fy2 += cy;
		}

		stLineGdiPlus.m_fx1 -= cx;
		stLineGdiPlus.m_fx2 -= cx;
	}
	

	// Text Position
	ptText.m_fX = stLineGdiPlus.m_fx1 + abs(stLineGdiPlus.m_fx1 - stLineGdiPlus.m_fx2) / 2;
	ptText.m_fY = stLineGdiPlus.m_fy1 + abs(stLineGdiPlus.m_fy1 - stLineGdiPlus.m_fy2) / 2;
	ptText.m_fX -= 230;
}

void CCustomScrollViewSize::GetLineDistance_L(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
{
	memset(&stLineGdiPlus, 0x00, sizeof(INFO_LINE_GDIPLUS));
	if (NULL == pstOutputSize)
		return;

	const double PI = 3.14159265;

	// Base Point
	const int nPtIndex = 0;
	const stPOINT* pBasePoint = &pstOutputSize->m_stResultPoint[nPtIndex];

	// Line
	const stLine* pLine = &pstOutputSize->m_stDistanceLine[nIdx];

	const double fDeltaX = pBasePoint->m_fX - pLine->m_fStartX;
	const double fDeltaY = pBasePoint->m_fY - pLine->m_fStartY;

	stLineGdiPlus.m_fx1 = pLine->m_fStartX + fDeltaX;
	stLineGdiPlus.m_fy1 = pLine->m_fStartY + fDeltaY;
	stLineGdiPlus.m_fx2 = pLine->m_fEndX + fDeltaX;
	stLineGdiPlus.m_fy2 = pLine->m_fEndY + fDeltaY;


	// Move line position
	{
		const int cy = 200;

		POINT pt1;
		pt1.x = stLineGdiPlus.m_fx1;
		pt1.y = stLineGdiPlus.m_fy1;
		POINT pt2;
		pt2.x = stLineGdiPlus.m_fx2;
		pt2.y = stLineGdiPlus.m_fy2;

		//       270
		//       |
		// 180 -------- 0
		//       |
		//       90

		const double fDegree = CUtil::GetAngle(pt2, pt1, TRUE);
		if (0 < fDegree)
		{
			double cx = cy * tan((180 - fDegree) * PI / 180);

			stLineGdiPlus.m_fx1 -= cx;
			stLineGdiPlus.m_fx2 -= cx;
		}
		else if (0 > fDegree)
		{
			double cx = cy * tan((180 + fDegree) * PI / 180);

			stLineGdiPlus.m_fx1 += cx;
			stLineGdiPlus.m_fx2 += cx;
		}

		stLineGdiPlus.m_fy1 -= 200;
		stLineGdiPlus.m_fy2 -= 200;
	}

	// Text Position
	ptText.m_fX = stLineGdiPlus.m_fx1 + abs(stLineGdiPlus.m_fx1 - stLineGdiPlus.m_fx2) / 2;
	ptText.m_fY = stLineGdiPlus.m_fy1 + abs(stLineGdiPlus.m_fy1 - stLineGdiPlus.m_fy2) / 2;

	if (100 <= abs(stLineGdiPlus.m_fy1 - stLineGdiPlus.m_fy2))
		ptText.m_fY = min(stLineGdiPlus.m_fy1, stLineGdiPlus.m_fy2);
	else
		ptText.m_fY -= 80;

}

void CCustomScrollViewSize::GetLineDistance_W(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
{
	memset(&stLineGdiPlus, 0x00, sizeof(INFO_LINE_GDIPLUS));
	if (NULL == pstOutputSize)
		return;


	const stLine* pResLine = &pstOutputSize->m_stResultLine[5];

	// Line
	const stLine* pLine = &pstOutputSize->m_stDistanceLine[nIdx];

	const double fDeltaX = pResLine->m_fEndX - pLine->m_fStartX;
	const double fDeltaY = pResLine->m_fEndY - pLine->m_fStartY;

	stLineGdiPlus.m_fx1 = pLine->m_fStartX + fDeltaX;
	stLineGdiPlus.m_fy1 = pLine->m_fStartY + fDeltaY;
	stLineGdiPlus.m_fx2 = pLine->m_fEndX + fDeltaX;
	stLineGdiPlus.m_fy2 = pLine->m_fEndY + fDeltaY;


	// Text Position
	ptText.m_fX = stLineGdiPlus.m_fx2 + abs(stLineGdiPlus.m_fx1 - stLineGdiPlus.m_fx2) / 2;
	ptText.m_fY = stLineGdiPlus.m_fy2 + abs(stLineGdiPlus.m_fy1 - stLineGdiPlus.m_fy2) / 2;
	ptText.m_fY -= 200;
}

void CCustomScrollViewSize::GetLineDistance_I1(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
{
	memset(&stLineGdiPlus, 0x00, sizeof(INFO_LINE_GDIPLUS));
	if (NULL == pstOutputSize)
		return;

	// Line
	const stLine* pLine = &pstOutputSize->m_stDistanceLine[nIdx];

	stLineGdiPlus.m_fx1 = pLine->m_fStartX;
	stLineGdiPlus.m_fy1 = pLine->m_fStartY;
	stLineGdiPlus.m_fx2 = pLine->m_fEndX;
	stLineGdiPlus.m_fy2 = pLine->m_fEndY;


	// Text Position
	ptText.m_fX = stLineGdiPlus.m_fx2;
	ptText.m_fY = stLineGdiPlus.m_fy2;
}

void CCustomScrollViewSize::GetLineDistance_I2(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
{
	memset(&stLineGdiPlus, 0x00, sizeof(INFO_LINE_GDIPLUS));
	if (NULL == pstOutputSize)
		return;

	// Line
	const stLine* pLine = &pstOutputSize->m_stDistanceLine[nIdx];

	stLineGdiPlus.m_fx1 = pLine->m_fStartX;
	stLineGdiPlus.m_fy1 = pLine->m_fStartY;
	stLineGdiPlus.m_fx2 = pLine->m_fEndX;
	stLineGdiPlus.m_fy2 = pLine->m_fEndY;


	// Text Position
	ptText.m_fX = stLineGdiPlus.m_fx1;
	ptText.m_fY = stLineGdiPlus.m_fy1;
}

void CCustomScrollViewSize::GetLineDistance_I3(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
{
	memset(&stLineGdiPlus, 0x00, sizeof(INFO_LINE_GDIPLUS));
	if (NULL == pstOutputSize)
		return;

	// Line
	const stLine* pLine = &pstOutputSize->m_stDistanceLine[nIdx];

	stLineGdiPlus.m_fx1 = pLine->m_fStartX;
	stLineGdiPlus.m_fy1 = pLine->m_fStartY;
	stLineGdiPlus.m_fx2 = pLine->m_fEndX;
	stLineGdiPlus.m_fy2 = pLine->m_fEndY;


	// Text Position
	ptText.m_fX = stLineGdiPlus.m_fx1;
	ptText.m_fY = stLineGdiPlus.m_fy1;
	ptText.m_fY -= 70;
}

void CCustomScrollViewSize::GetLineDistance_M1(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
{
	memset(&stLineGdiPlus, 0x00, sizeof(INFO_LINE_GDIPLUS));
	if (NULL == pstOutputSize)
		return;

	// Line
	const stLine* pLine = &pstOutputSize->m_stDistanceLine[nIdx];

	stLineGdiPlus.m_fx1 = pLine->m_fStartX;
	stLineGdiPlus.m_fy1 = pLine->m_fStartY;
	stLineGdiPlus.m_fx2 = pLine->m_fEndX;
	stLineGdiPlus.m_fy2 = pLine->m_fEndY;


	// Text Position
	ptText.m_fX = stLineGdiPlus.m_fx2;
	ptText.m_fY = stLineGdiPlus.m_fy2;
}

void CCustomScrollViewSize::GetLineDistance_M2(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
{
	memset(&stLineGdiPlus, 0x00, sizeof(INFO_LINE_GDIPLUS));
	if (NULL == pstOutputSize)
		return;

	// Line
	const stLine* pLine = &pstOutputSize->m_stDistanceLine[nIdx];

	stLineGdiPlus.m_fx1 = pLine->m_fStartX;
	stLineGdiPlus.m_fy1 = pLine->m_fStartY;
	stLineGdiPlus.m_fx2 = pLine->m_fEndX;
	stLineGdiPlus.m_fy2 = pLine->m_fEndY;


	// Text Position
	ptText.m_fX = stLineGdiPlus.m_fx2;
	ptText.m_fY = stLineGdiPlus.m_fy2;
}

void CCustomScrollViewSize::GetLineDistance_S1(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
{
	memset(&stLineGdiPlus, 0x00, sizeof(INFO_LINE_GDIPLUS));
	if (NULL == pstOutputSize)
		return;

	// Line
	const stLine* pLine = &pstOutputSize->m_stDistanceLine[nIdx];

	stLineGdiPlus.m_fx1 = pLine->m_fStartX;
	stLineGdiPlus.m_fy1 = pLine->m_fStartY;
	stLineGdiPlus.m_fx2 = pLine->m_fEndX;
	stLineGdiPlus.m_fy2 = pLine->m_fEndY;


	// Text Position
	ptText.m_fX = stLineGdiPlus.m_fx1;
	ptText.m_fY = stLineGdiPlus.m_fy1;

	ptText.m_fX -= 150;
}

void CCustomScrollViewSize::GetLineDistance_S2(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
{
	memset(&stLineGdiPlus, 0x00, sizeof(INFO_LINE_GDIPLUS));
	if (NULL == pstOutputSize)
		return;

	// Line
	const stLine* pLine = &pstOutputSize->m_stDistanceLine[nIdx];

	stLineGdiPlus.m_fx1 = pLine->m_fStartX;
	stLineGdiPlus.m_fy1 = pLine->m_fStartY;
	stLineGdiPlus.m_fx2 = pLine->m_fEndX;
	stLineGdiPlus.m_fy2 = pLine->m_fEndY;


	// Text Position
	ptText.m_fX = stLineGdiPlus.m_fx2;
	ptText.m_fY = stLineGdiPlus.m_fy2;

	ptText.m_fX -= 150;
}

void CCustomScrollViewSize::GetLineDistance_S3(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
{
	memset(&stLineGdiPlus, 0x00, sizeof(INFO_LINE_GDIPLUS));
	if (NULL == pstOutputSize)
		return;

	// Line
	const stLine* pLine = &pstOutputSize->m_stDistanceLine[nIdx];

	stLineGdiPlus.m_fx1 = pLine->m_fStartX;
	stLineGdiPlus.m_fy1 = pLine->m_fStartY;
	stLineGdiPlus.m_fx2 = pLine->m_fEndX;
	stLineGdiPlus.m_fy2 = pLine->m_fEndY;


	// Text Position
	ptText.m_fX = stLineGdiPlus.m_fx1;
	ptText.m_fY = stLineGdiPlus.m_fy1;

	ptText.m_fX -= 150;
}

void CCustomScrollViewSize::GetLineDistance_S4(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
{
	memset(&stLineGdiPlus, 0x00, sizeof(INFO_LINE_GDIPLUS));
	if (NULL == pstOutputSize)
		return;

	// Line
	const stLine* pLine = &pstOutputSize->m_stDistanceLine[nIdx];

	stLineGdiPlus.m_fx1 = pLine->m_fStartX;
	stLineGdiPlus.m_fy1 = pLine->m_fStartY;
	stLineGdiPlus.m_fx2 = pLine->m_fEndX;
	stLineGdiPlus.m_fy2 = pLine->m_fEndY;


	// Text Position
	ptText.m_fX = stLineGdiPlus.m_fx1;
	ptText.m_fY = stLineGdiPlus.m_fy1;

	ptText.m_fX -= 150;
}

void CCustomScrollViewSize::GetLineDistance_S5(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
{
	memset(&stLineGdiPlus, 0x00, sizeof(INFO_LINE_GDIPLUS));
	if (NULL == pstOutputSize)
		return;

	// Line
	const stLine* pLine = &pstOutputSize->m_stDistanceLine[nIdx];

	stLineGdiPlus.m_fx1 = pLine->m_fStartX;
	stLineGdiPlus.m_fy1 = pLine->m_fStartY;
	stLineGdiPlus.m_fx2 = pLine->m_fEndX;
	stLineGdiPlus.m_fy2 = pLine->m_fEndY;


	// Text Position
	ptText.m_fX = stLineGdiPlus.m_fx1;
	ptText.m_fY = stLineGdiPlus.m_fy1;

	ptText.m_fX -= 150;
}

void CCustomScrollViewSize::GetLineDistance_X1(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
{
	memset(&stLineGdiPlus, 0x00, sizeof(INFO_LINE_GDIPLUS));
	if (NULL == pstOutputSize)
		return;

	// Line
	const stLine* pLine = &pstOutputSize->m_stDistanceLine[nIdx];

	stLineGdiPlus.m_fx1 = pLine->m_fStartX;
	stLineGdiPlus.m_fy1 = pLine->m_fStartY;
	stLineGdiPlus.m_fx2 = pLine->m_fEndX;
	stLineGdiPlus.m_fy2 = pLine->m_fEndY;


	// Text Position
	ptText.m_fX = stLineGdiPlus.m_fx1;
	ptText.m_fY = stLineGdiPlus.m_fy1;
}

void CCustomScrollViewSize::GetLineDistance_X2(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
{
	memset(&stLineGdiPlus, 0x00, sizeof(INFO_LINE_GDIPLUS));
	if (NULL == pstOutputSize)
		return;

	// Line
	const stLine* pLine = &pstOutputSize->m_stDistanceLine[nIdx];

	stLineGdiPlus.m_fx1 = pLine->m_fStartX;
	stLineGdiPlus.m_fy1 = pLine->m_fStartY;
	stLineGdiPlus.m_fx2 = pLine->m_fEndX;
	stLineGdiPlus.m_fy2 = pLine->m_fEndY;


	// Text Position
	ptText.m_fX = stLineGdiPlus.m_fx2;
	ptText.m_fY = stLineGdiPlus.m_fy2;
}

void CCustomScrollViewSize::GetLineDistance_R(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
{
	memset(&stLineGdiPlus, 0x00, sizeof(INFO_LINE_GDIPLUS));
	if (NULL == pstOutputSize)
		return;

	// Line
	const stLine* pLine = &pstOutputSize->m_stDistanceLine[nIdx];

	stLineGdiPlus.m_fx1 = pLine->m_fStartX;
	stLineGdiPlus.m_fy1 = pLine->m_fStartY;
	stLineGdiPlus.m_fx2 = pLine->m_fEndX;
	stLineGdiPlus.m_fy2 = pLine->m_fEndY;


	// Text Position
	ptText.m_fX = stLineGdiPlus.m_fx2;
	ptText.m_fY = stLineGdiPlus.m_fy2;
}

// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
void CCustomScrollViewSize::GetLineDistance_SS1(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
{
	memset(&stLineGdiPlus, 0x00, sizeof(INFO_LINE_GDIPLUS));
	if (NULL == pstOutputSize)
		return;

	// Line
	const stLine* pLine = &pstOutputSize->m_stDistanceLine[nIdx];

	stLineGdiPlus.m_fx1 = pLine->m_fStartX;
	stLineGdiPlus.m_fy1 = pLine->m_fStartY;
	stLineGdiPlus.m_fx2 = pLine->m_fEndX;
	stLineGdiPlus.m_fy2 = pLine->m_fEndY;


	// Text Position
	ptText.m_fX = stLineGdiPlus.m_fx2;
	ptText.m_fY = stLineGdiPlus.m_fy2;
}
// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
void CCustomScrollViewSize::GetLineDistance_SS2(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
{
	memset(&stLineGdiPlus, 0x00, sizeof(INFO_LINE_GDIPLUS));
	if (NULL == pstOutputSize)
		return;

	// Line
	const stLine* pLine = &pstOutputSize->m_stDistanceLine[nIdx];

	stLineGdiPlus.m_fx1 = pLine->m_fStartX;
	stLineGdiPlus.m_fy1 = pLine->m_fStartY;
	stLineGdiPlus.m_fx2 = pLine->m_fEndX;
	stLineGdiPlus.m_fy2 = pLine->m_fEndY;


	// Text Position
	ptText.m_fX = stLineGdiPlus.m_fx2;
	ptText.m_fY = stLineGdiPlus.m_fy2;
}
// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
void CCustomScrollViewSize::GetLineDistance_SS3(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
{
	memset(&stLineGdiPlus, 0x00, sizeof(INFO_LINE_GDIPLUS));
	if (NULL == pstOutputSize)
		return;

	// Line
	const stLine* pLine = &pstOutputSize->m_stDistanceLine[nIdx];

	stLineGdiPlus.m_fx1 = pLine->m_fStartX;
	stLineGdiPlus.m_fy1 = pLine->m_fStartY;
	stLineGdiPlus.m_fx2 = pLine->m_fEndX;
	stLineGdiPlus.m_fy2 = pLine->m_fEndY;


	// Text Position
	ptText.m_fX = stLineGdiPlus.m_fx2;
	ptText.m_fY = stLineGdiPlus.m_fy2;
}


void CCustomScrollViewSize::DisplayResult(CSampleSide* pSampleSide)
{
#ifndef DEF_DISABLE_DISPLAY_SKIP
	static BOOL bWork = FALSE;

	HWND hWnd = this->GetSafeHwnd();
	if (NULL == hWnd || bWork)
		return;

	bWork = TRUE;
#else
	HWND hWnd = this->GetSafeHwnd();
	if (NULL == hWnd)
		return;
#endif
	::EnterCriticalSection(&m_CriticalSection);
	if (NULL == pSampleSide || NULL == pSampleSide->m_pRefImage)
	{
		// Clear Display
		ClearResult();
	}
	else
	{
		INFO_IMAGE* pstImage = pSampleSide->m_pRefImage;

		// Check Buffer Length
#ifdef USE_BASLER_CAMERA
		if (NULL != m_pstDisplayImage && m_pstDisplayImage->m_nBufLen != pstImage->m_nBufLen)
#else
		if (NULL != m_pstDisplayImage && m_pstDisplayImage->m_nBufLen != pstImage->m_stFrame.m_dwMaxWidth * pstImage->m_stFrame.m_dwMaxHeight)
#endif
			ClearResult();

		BOOL bUpdateScroll = FALSE;

		// Display Image
		if (NULL == m_pstDisplayImage)
		{
			m_pstDisplayImage = new INFO_IMAGE;
			memset(m_pstDisplayImage, 0x00, sizeof(INFO_IMAGE));

#ifdef USE_BASLER_CAMERA
			m_pstDisplayImage->m_nBufLen = pstImage->m_nBufLen;
			m_pstDisplayImage->m_pBuffer = new BYTE[m_pstDisplayImage->m_nBufLen];
#else
			m_pstDisplayImage->m_nBufLen = pstImage->m_stFrame.m_dwMaxWidth * pstImage->m_stFrame.m_dwMaxHeight;
			m_pstDisplayImage->m_pBuffer = new BYTE[m_pstDisplayImage->m_nBufLen];
#endif
			bUpdateScroll = TRUE;
		}

		m_pstDisplayImage->m_stFrame = pstImage->m_stFrame;
		m_pstDisplayImage->m_nLen = pstImage->m_nLen;
		memcpy(m_pstDisplayImage->m_pBuffer, pstImage->m_pBuffer, pstImage->m_nLen);

		SetFitZoom(m_bFitZoom);

		// Size Output
		if (NULL == m_pstOutputSize)
		{
			m_pstOutputSize = new OUTPUT_SIZE;
			memset(m_pstOutputSize, 0x00, sizeof(OUTPUT_SIZE));
		}
		memcpy(m_pstOutputSize, &pSampleSide->m_SizeCalculationResult, sizeof(OUTPUT_SIZE));

		if (bUpdateScroll)
		{
			//UpdateScrollSize();
		}
	}
	::LeaveCriticalSection(&m_CriticalSection);
#ifndef DEF_DISABLE_DISPLAY_SKIP
	bWork = FALSE;
#endif
	this->Invalidate(FALSE);
}

void CCustomScrollViewSize::ClearResult()
{
	if (m_pstDisplayImage)
	{
		if (m_pstDisplayImage->m_pBuffer)
			delete[] m_pstDisplayImage->m_pBuffer;

		delete m_pstDisplayImage;
	}
	m_pstDisplayImage = NULL;

	if (m_pstOutputSize)
	{
		delete m_pstOutputSize;
	}
	m_pstOutputSize = NULL;

}

const double CCustomScrollViewSize::GetZoom()
{
	return m_fZoom;
}

void CCustomScrollViewSize::SetZoom(double fZoom)
{
	m_fZoom = fZoom;
}

void CCustomScrollViewSize::SetFitZoom(BOOL bFit)
{
	m_bFitZoom = bFit;
	if (m_bFitZoom)
	{
		double fFitZoom = GetFitZoom();
		SetZoom(fFitZoom);
	}
}

const double CCustomScrollViewSize::GetFitZoom()
{
	double fFitZoom = 1.0f;

	CRect rect;
	GetClientRect(&rect);

	const int nW = rect.Width();
	const int nH = rect.Height();

	if (m_pstDisplayImage)
	{
		const int cx = m_pstDisplayImage->m_stFrame.m_dwWidth;
		const int cy = m_pstDisplayImage->m_stFrame.m_dwHeight;

		const double fh = (double)nW / (double)cx;
		const double fv = (double)nH / (double)cy;

		if (fh > fv)
			fFitZoom = fv;
		else
			fFitZoom = fh;
	}

	return fFitZoom;
}
