// CustomScrollView.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "CustomScrollView.h"

#include "UserInterfaceDef.h"
#include "CaptureManager.h"
#include "Util/Util.h"

#include "Video/ConvertColor.h"
#include "inc/PixelFormat.h"

#include "stringres.h"

#include <gdiplus.h>
#pragma comment(lib, "Gdiplus.lib")

// CCustomScrollView

IMPLEMENT_DYNCREATE(CCustomScrollView, CScrollView)

CCustomScrollView::CCustomScrollView()
{
	::InitializeCriticalSection(&m_CriticalSection);
	::InitializeCriticalSection(&m_CriticalSection_ImageBuffer);

	/// Init Gdi Plus
	Gdiplus::GdiplusStartupInput input;
	Gdiplus::GdiplusStartup(&m_GdiPlusToken, &input, NULL);

	
	m_bFitZoom = TRUE;
	m_fZoom = 1.0f;
	m_eCameraPos = TYPE_CAMERAPOS_NONE;

#ifdef USE_BASLER_CAMERA
	m_pColorBuffer = NULL;
	m_nColorBufLen = 0;
	m_pBuffer = NULL;
	m_nBufLen = 0;
#endif

	ClearStepOutput();
}

CCustomScrollView::~CCustomScrollView()
{
	::DeleteCriticalSection(&m_CriticalSection);

#ifdef USE_BASLER_CAMERA
	if (m_pColorBuffer)
		delete[] m_pColorBuffer;
	m_pColorBuffer = NULL;
	m_nColorBufLen = 0;
	m_pBuffer = NULL;
	m_nBufLen = 0;
#endif

	ClearImage();
	ClearStepOutput();
	::DeleteCriticalSection(&m_CriticalSection_ImageBuffer);
}


BEGIN_MESSAGE_MAP(CCustomScrollView, CScrollView)
	ON_WM_RBUTTONUP()
	ON_WM_CONTEXTMENU()
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()

	ON_COMMAND(ID_VIEW_EDIT, &CCustomScrollView::OnCommandEdit)
	ON_COMMAND(ID_VIEW_GRAB, &CCustomScrollView::OnCommandGrab)
	ON_COMMAND(ID_STROBE_OFF, &CCustomScrollView::OnCommandStrobeOff)
	ON_COMMAND(ID_STROBE_COAXIAL, &CCustomScrollView::OnCommandStrobeCoaxial)
	ON_COMMAND(ID_STROBE_RING, &CCustomScrollView::OnCommandStrobeRing)
	ON_COMMAND(ID_STROBE_BAR, &CCustomScrollView::OnCommandStrobeBar)
	ON_COMMAND(ID_VIEW_TEST_SIZE, &CCustomScrollView::OnCommandTestSize)
	ON_COMMAND(ID_VIEW_TEST_STEP2, &CCustomScrollView::OnCommandTestStep2)
	ON_COMMAND(ID_VIEW_TEST_STEP3, &CCustomScrollView::OnCommandTestStep3)
	ON_COMMAND(ID_VIEW_TEST_STEP4, &CCustomScrollView::OnCommandTestStep4)

END_MESSAGE_MAP()


// CCustomScrollView drawing

void CCustomScrollView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	sizeTotal.cx = sizeTotal.cy = 1;
	SetScrollSizes(MM_TEXT, sizeTotal);
	IplImage* pSrc = ::cvCreateImage(cvSize(5472, 3648), IPL_DEPTH_8U, 1);
	IplImage* pDest = ::cvCreateImage(cvSize(5472, 3648), IPL_DEPTH_8U, 3);
	IplImage* pTemp = ::cvCreateImage(cvSize(5472, 3648), IPL_DEPTH_8U, 3);
	memset(pSrc->imageData, 0, pSrc->widthStep * pSrc->height);

	ConvertColor(GVSP_PIX_BAYERGB8, pSrc, pDest, pTemp, 5472, 3648);

	::cvReleaseImage(&pSrc);
	::cvReleaseImage(&pDest);
	::cvReleaseImage(&pTemp);
}

void CCustomScrollView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
}


// CCustomScrollView diagnostics

#ifdef _DEBUG
void CCustomScrollView::AssertValid() const
{
	CScrollView::AssertValid();
}

#ifndef _WIN32_WCE
void CCustomScrollView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif
#endif //_DEBUG


// CCustomScrollView message handlers
void CCustomScrollView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCustomScrollView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
	CMenu Menu;
	Menu.LoadMenu(IDR_MENU_POPUPVIEW);

	CMenu* pSubMenu = Menu.GetSubMenu(0);
	if (pSubMenu)
	{
		pSubMenu->ModifyMenu(ID_VIEW_TEST_SIZE, MF_BYCOMMAND, ID_VIEW_TEST_SIZE, STR_MAINVIEW_BTN_SIZE);
#ifdef DEF_SECONDCAMERA_CHECKSIZE
		// do nothing..
#else
		if (TYPE_CAMERAPOS_SECOND == this->m_eCameraPos)
		{
			pSubMenu->EnableMenuItem(ID_VIEW_TEST_SIZE, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
		}
#endif
		pSubMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
	}
	Menu.DestroyMenu();

}

void CCustomScrollView::OnSize(UINT nType, int cx, int cy)
{
	CScrollView::OnSize(nType, cx, cy);

	if (m_bFitZoom)
	{
		this->SetFitZoom(m_bFitZoom);
	}
	UpdateScrollSize();
}

void CCustomScrollView::OnPaint()
{
	///
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_OPTION* pstOption = pCaptureManager->GetOption();

	INFO_OPT_INSPECTSTEP* pstOptStep = NULL;
	if (TYPE_CAMERAPOS_FIRST == m_eCameraPos)
		pstOptStep = (INFO_OPT_INSPECTSTEP*)&pstOption->m_stFirstCameraStep;
	else if (TYPE_CAMERAPOS_SECOND == m_eCameraPos)
		pstOptStep = (INFO_OPT_INSPECTSTEP*)&pstOption->m_stSecondCameraStep;
	//*/

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

		CInspection* pInspection = pCaptureManager->GetInspection();
		const BOOL bStart = pInspection->IsStart();

		// Image Display
		//if (TYPE_STEP_NONE == m_stDisplayOutput.m_eStep || TYPE_STEP_001 == m_stDisplayOutput.m_eStep || TYPE_STEP_007 == m_stDisplayOutput.m_eStep || FALSE == bStart)
		if (TYPE_STEP_NONE == m_stDisplayOutput.m_eStep || TYPE_STEP_001 == m_stDisplayOutput.m_eStep || TYPE_STEP_007 == m_stDisplayOutput.m_eStep)
		{
#ifdef USE_BASLER_CAMERA
			DrawBaslerImage(&MemDC);
#else
			DrawImage8bit(&MemDC);
#endif
		}
		else
		{
			if ((pstOptStep->m_bStep002 && TYPE_STEP_002 == m_stDisplayOutput.m_eStep) ||
				(pstOptStep->m_bStep003 && TYPE_STEP_003 == m_stDisplayOutput.m_eStep) ||
				(pstOptStep->m_bStep004 && TYPE_STEP_004 == m_stDisplayOutput.m_eStep) ||
				(pstOptStep->m_bStep005 && TYPE_STEP_005 == m_stDisplayOutput.m_eStep) ||
				(pstOptStep->m_bStep006 && TYPE_STEP_006 == m_stDisplayOutput.m_eStep))
			{
#ifdef USE_BASLER_CAMERA
				DrawBaslerImage24bit(&MemDC);
#else
				DrawImage24bit(&MemDC);
#endif
			}
			else
			{
#ifdef USE_BASLER_CAMERA
				DrawBaslerImage(&MemDC);
#else
				DrawImage8bit(&MemDC);
#endif
			}
		}

		dc.BitBlt(0, 0, nClientWidth, nClientHeight, &MemDC, 0, 0, SRCCOPY);

		::SelectObject(MemDC.m_hDC, hOldBitmap);
		::DeleteObject(hBitmap);

		m_stDisplayOutput.m_eStep = TYPE_STEP_NONE;
	}
}

#ifdef USE_BASLER_CAMERA
BOOL CCustomScrollView::CreateColorBuffer(const INFO_IMAGE* pImage)
{
	if (NULL == pImage)
		return FALSE;

	const INFO_FRAME* pFrame = &pImage->m_stFrame;
	const int nChannel = 3;

	const int nPitch = (nChannel*pImage->m_stFrame.m_dwWidth + 3 ) / 4 * 4;
	const int nBufLen = nPitch*pImage->m_stFrame.m_dwHeight;

	if (m_pColorBuffer && nBufLen > m_nColorBufLen)
	{
		delete[] m_pColorBuffer;
		m_pColorBuffer = NULL;
		m_nColorBufLen = 0;
	}

	if (NULL == m_pColorBuffer)
	{
		m_nColorBufLen = nBufLen;
		m_pColorBuffer = new unsigned char[m_nColorBufLen];
	}

	BYTE * pIdx = (BYTE*)m_pColorBuffer;

	// Make Buffer...
	if (TYPE_DATABIT_08 == pFrame->m_eDataBit && TYPE_CAMCOLOR_COLOR == pFrame->m_eColor)
	{
		IplImage* pSrc = ::cvCreateImage(cvSize(pFrame->m_dwWidth, pFrame->m_dwHeight), IPL_DEPTH_8U, 1);
		IplImage* pDest = ::cvCreateImage(cvSize(pFrame->m_dwWidth, pFrame->m_dwHeight), IPL_DEPTH_8U, 3);
		IplImage* pTemp = ::cvCreateImage(cvSize(pFrame->m_dwWidth, pFrame->m_dwHeight), IPL_DEPTH_8U, 3);

		for (int y = 0; y < pFrame->m_dwHeight; y++)
			memcpy(pSrc->imageData + y*pSrc->widthStep, pImage->m_pBuffer + y*pFrame->m_dwPitch, pFrame->m_dwPitch);

		if (TYPE_CAMCOLORFORMAT_BAYER_GR == pFrame->m_eColorFormat)
			ConvertColor(GVSP_PIX_BAYERGR8, pSrc, pDest, pTemp, pFrame->m_dwWidth, pFrame->m_dwHeight);
		else if (TYPE_CAMCOLORFORMAT_BAYER_RG == pFrame->m_eColorFormat)
			ConvertColor(GVSP_PIX_BAYERRG8, pSrc, pDest, pTemp, pFrame->m_dwWidth, pFrame->m_dwHeight);
		else if (TYPE_CAMCOLORFORMAT_BAYER_GB == pFrame->m_eColorFormat)
			ConvertColor(GVSP_PIX_BAYERGB8, pSrc, pDest, pTemp, pFrame->m_dwWidth, pFrame->m_dwHeight);
		else if (TYPE_CAMCOLORFORMAT_BAYER_BG == pFrame->m_eColorFormat)
			ConvertColor(GVSP_PIX_BAYERBG8, pSrc, pDest, pTemp, pFrame->m_dwWidth, pFrame->m_dwHeight);

		else if (TYPE_CAMCOLORFORMAT_YUV == pFrame->m_eColorFormat)
			ConvertColor(BAYERGR8, pSrc, pDest, pTemp, pFrame->m_dwWidth, pFrame->m_dwHeight);	// ???

		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
		if (m_eCameraPos == TYPE_CAMERAPOS_FIRST)
		{
			if (pCaptureManager->GetFirstCameraReverseX() && pCaptureManager->GetFirstCameraReverseY())
			{
				cvFlip(pDest, pDest, -1);
			}
			else if (pCaptureManager->GetFirstCameraReverseX())
			{
				cvFlip(pDest, pDest, 1);
			}
			else if (pCaptureManager->GetFirstCameraReverseY())
			{
				cvFlip(pDest, pDest, 0);
			}
		}
		else if (m_eCameraPos == TYPE_CAMERAPOS_SECOND)
		{
			if (pCaptureManager->GetSecondCameraReverseX() && pCaptureManager->GetSecondCameraReverseY())
			{
				cvFlip(pDest, pDest, -1);
			}
			else if (pCaptureManager->GetSecondCameraReverseX())
			{
				cvFlip(pDest, pDest, 1);
			}
			else if (pCaptureManager->GetSecondCameraReverseY())
			{
				cvFlip(pDest, pDest, 0);
			}
		}

		for (int y = 0; y < pFrame->m_dwHeight; y++)
			memcpy(pIdx + y*nPitch, pDest->imageData + y*pDest->widthStep, pDest->widthStep);

		::cvReleaseImage(&pSrc);
		::cvReleaseImage(&pDest);
		::cvReleaseImage(&pTemp);
	}

	return TRUE;
}
#endif


void CCustomScrollView::DrawImage8bit(CDC* pDC)
{
	///
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_OPTION* pstOption = pCaptureManager->GetOption();

	INFO_OPT_INSPECTSTEP* pstOptStep = NULL;
	if (TYPE_CAMERAPOS_FIRST == m_eCameraPos)
		pstOptStep = (INFO_OPT_INSPECTSTEP*)&pstOption->m_stFirstCameraStep;
	else if (TYPE_CAMERAPOS_SECOND == m_eCameraPos)
		pstOptStep = (INFO_OPT_INSPECTSTEP*)&pstOption->m_stSecondCameraStep;
	//*/

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

		CInspection* pInspection = pCaptureManager->GetInspection();
		const BOOL bStart = pInspection->IsStart();

		// Pixel Buffer Copy
		if (TYPE_STEP_NONE == m_stDisplayOutput.m_eStep ||
			TYPE_STEP_001 == m_stDisplayOutput.m_eStep && (FALSE == pstOptStep->m_bStep001) || 
			TYPE_STEP_002 == m_stDisplayOutput.m_eStep && (FALSE == pstOptStep->m_bStep002 || m_stDisplayOutput.m_stOutputStain.m_pProbImage.empty()) ||
			TYPE_STEP_003 == m_stDisplayOutput.m_eStep && (FALSE == pstOptStep->m_bStep003 || m_stDisplayOutput.m_stOutputDiffer.m_pProbImage.empty()) ||
			TYPE_STEP_004 == m_stDisplayOutput.m_eStep && (FALSE == pstOptStep->m_bStep004 || m_stDisplayOutput.m_stOutputBubble.m_pProbImage.empty()) ||
			TYPE_STEP_005 == m_stDisplayOutput.m_eStep && (FALSE == pstOptStep->m_bStep005 || m_stDisplayOutput.m_stOutputScratch.m_pProbImage.empty()) ||
			TYPE_STEP_006 == m_stDisplayOutput.m_eStep && (FALSE == pstOptStep->m_bStep006 || m_stDisplayOutput.m_stOutputStamp.m_pProbImage.empty()) ||
			FALSE == bStart)
		{
			// Captured image from camera...
			for (int y = 0; y < h; y++)
			{
				pDest = (BYTE*)pvBits + y*pitch;
				pSrc = m_pstDisplayImage->m_pBuffer + y * w;
				memcpy(pDest, pSrc, w);
			}
		}
		else
		{
			// Output Image...
			CopyPixelBuffer8Bit(m_stDisplayOutput.m_eStep, w, h, pitch, pvBits);
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
		double fZoom = GetZoom();

		/// Output Roi
		if (TYPE_STEP_001 == m_stDisplayOutput.m_eStep)
		{
#if 1
			const OUTPUT_SIZE* pstOutputSize = &m_stDisplayOutput.m_stOutputSize;

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
				const stLine* pLine = &pstOutputSize->m_stResultLine[i];
				Gdiplus::REAL x1 = pLine->m_fStartX * fZoom;
				Gdiplus::REAL y1 = pLine->m_fStartY * fZoom;
				Gdiplus::REAL x2 = pLine->m_fEndX * fZoom;
				Gdiplus::REAL y2 = pLine->m_fEndY * fZoom;
				graphics.DrawLine(&penOutLine, x1, y1, x2, y2);
			}
			{
				const stLine* pLine = &pstOutputSize->m_stResultLine[5];
				Gdiplus::REAL x1 = pLine->m_fStartX * fZoom;
				Gdiplus::REAL y1 = pLine->m_fStartY * fZoom;
				Gdiplus::REAL x2 = pLine->m_fEndX * fZoom;
				Gdiplus::REAL y2 = pLine->m_fEndY * fZoom;
				graphics.DrawLine(&penOutLine, x1, y1, x2, y2);
			}
			{
				const stLine* pLine = &pstOutputSize->m_stResultLine[10];
				Gdiplus::REAL x1 = pLine->m_fStartX * fZoom;
				Gdiplus::REAL y1 = pLine->m_fStartY * fZoom;
				Gdiplus::REAL x2 = pLine->m_fEndX * fZoom;
				Gdiplus::REAL y2 = pLine->m_fEndY * fZoom;
				graphics.DrawLine(&penOutLine, x1, y1, x2, y2);
			}

			// Line (OK, NG)
			{
				INFO_LINE_GDIPLUS stLineGdiPlus;
				stPOINT ptText;

				for (int i = 0; i < MAX_GEOMETRY_DISTANCELINE_COUNT; i++)
				{
					const OUTPUT_DISTANCE* pstOutput = &pstOutputSize->m_stDistance[i];
					if (TYPE_GEOMETRY_DISTANCE_D == i)			GetLineDistance_d(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_L == i)		GetLineDistance_L(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_W == i)		GetLineDistance_W(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_I1 == i)	GetLineDistance_I1(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_I2 == i)	GetLineDistance_I2(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_I3 == i)	GetLineDistance_I3(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_M1 == i)	GetLineDistance_M1(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_M2 == i)	GetLineDistance_M2(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_S1 == i)	GetLineDistance_S1(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_S2 == i)	GetLineDistance_S2(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_S3 == i)	GetLineDistance_S3(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_S4 == i)	GetLineDistance_S4(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_S5 == i)	GetLineDistance_S5(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_X1 == i)	GetLineDistance_X1(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_X2 == i)	GetLineDistance_X2(pstOutputSize, i, stLineGdiPlus, ptText);
					// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
					else if (TYPE_GEOMETRY_DISTANCE_SS1 == i)	GetLineDistance_SS1(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_SS2 == i)	GetLineDistance_SS2(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_SS3 == i)	GetLineDistance_SS3(pstOutputSize, i, stLineGdiPlus, ptText);
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
			Gdiplus::Graphics graphics(pDC->m_hDC);
			COLORREF rgbLine = RGB(0x00, 0xFF, 0x00);
			COLORREF rgbError = RGB(0xFF, 0x00, 0x00);

			Gdiplus::Color clrLine(Gdiplus::Color::MakeARGB(0xFF, GetRValue(rgbLine), GetGValue(rgbLine), GetBValue(rgbLine)));
			Gdiplus::Color clrError(Gdiplus::Color::MakeARGB(0xFF, GetRValue(rgbError), GetGValue(rgbError), GetBValue(rgbError)));
			Gdiplus::REAL width = 2.0f;

			Gdiplus::Pen penLine(clrLine, width);
			Gdiplus::Pen penError(clrError, width);

			for (int i = 0; i < TYPE_FINDLINE_MAX; i++)
			{
				const OUTPUT_DISTANCE* pstOutput = &m_stDisplayOutput.m_stOutputSize.m_stDistance[i];
				const stLine* pLine = &m_stDisplayOutput.m_stOutputSize.m_stResultLine[i];

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
		//*/
	}

}

void CCustomScrollView::DrawImage24bit(CDC* pDC)
{
	if (NULL == pDC || NULL == m_pstDisplayImage)
		return;

	CRect rect;
	GetClientRect(&rect);
	const int nClientWidth = rect.Width();
	const int nClientHeight = rect.Height();

	int scrlx = 0;
	int scrly = 0;


	// Image
	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);

	const int w = m_pstDisplayImage->m_stFrame.m_dwWidth;
	const int h = m_pstDisplayImage->m_stFrame.m_dwHeight;
	const int pitch = (w * 3 + 3) / 4 * 4;

	HBITMAP hBitmap;       // bitmap handle 
	VOID *pvBits;          // pointer to DIB section 

	BITMAPINFO* pstBmpInfo = new BITMAPINFO;

	pstBmpInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	pstBmpInfo->bmiHeader.biWidth = w;
	pstBmpInfo->bmiHeader.biHeight = -h;
	pstBmpInfo->bmiHeader.biPlanes = 1;
	pstBmpInfo->bmiHeader.biBitCount = 24;
	pstBmpInfo->bmiHeader.biCompression = BI_RGB;
	pstBmpInfo->bmiHeader.biSizeImage = pitch * h;

	hBitmap = CreateDIBSection(MemDC.m_hDC, pstBmpInfo, DIB_RGB_COLORS, &pvBits, NULL, 0x0);
	if (hBitmap)
	{
		BYTE* pSrc = NULL;
		BYTE* pDest = NULL;

		HBITMAP hOldBitmap = (HBITMAP)::SelectObject(MemDC.m_hDC, hBitmap);

		// Pixel Buffer Copy
		if (TYPE_STEP_NONE == m_stDisplayOutput.m_eStep)
		{
			// Captured image from camera...
			for (int y = 0; y < h; y++)
			{
				pDest = (BYTE*)pvBits + y*pitch;
				pSrc = m_pstDisplayImage->m_pBuffer + y * w;
				memcpy(pDest, pSrc, w);
			}
		}
		else
		{
			// Output Image...
			CopyPixelBuffer24Bit(m_stDisplayOutput.m_eStep, w, h, pitch, pvBits);
		}

		const double fZoom = this->GetZoom();

		int x1 = 0;
		int y1 = 0;
		int cx1 = (int)(w * fZoom);
		int cy1 = (int)(h * fZoom);

		int x2 = 0;
		int y2 = 0;

		if (DEFAULT_ZOOM_FACTOR == fZoom)
		{
			x2 = GetScrollPos(SB_HORZ);
			y2 = GetScrollPos(SB_VERT);
			pDC->BitBlt(x1, y1, cx1, cy1, &MemDC, x2, y2, SRCCOPY);
		}
		else if (m_bFitZoom)
		{
			pDC->SetStretchBltMode(STRETCH_HALFTONE);
			pDC->StretchBlt(x1, y1, cx1, cy1, &MemDC, 0, 0, w, h, SRCCOPY);
		}
		else
		{
			x2 = (int)(GetScrollPos(SB_HORZ) / fZoom);
			y2 = (int)(GetScrollPos(SB_VERT) / fZoom);
			int cx2 = (int)(nClientWidth / fZoom);
			int cy2 = (int)(nClientHeight / fZoom);

			if (cx1 > nClientWidth)		cx1 = nClientWidth;
			if (cy1 > nClientHeight)	cy1 = nClientHeight;

			if (w < (x2 + cx2))			cx2 = w - x2;
			if (h < (y2 + cy2))			cy2 = h - y2;

			pDC->SetStretchBltMode(STRETCH_HALFTONE);
			pDC->StretchBlt(x1, y1, cx1, cy1, &MemDC, x2, y2, cx2, cy2, SRCCOPY);
		}

		scrlx = x2;
		scrly = y2;

		::SelectObject(MemDC.m_hDC, hOldBitmap);
		::DeleteObject(hBitmap);
	}
	delete[] pstBmpInfo;
}

#ifdef USE_BASLER_CAMERA
void CCustomScrollView::DrawBaslerImage(CDC* pDC)
{
	if (NULL == pDC || NULL == m_pstDisplayImage)
		return;

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_OPTION* pstOption = pCaptureManager->GetOption();

	INFO_OPT_INSPECTSTEP* pstOptStep = NULL;
	if (TYPE_CAMERAPOS_FIRST == m_eCameraPos)
		pstOptStep = (INFO_OPT_INSPECTSTEP*)&pstOption->m_stFirstCameraStep;
	else if (TYPE_CAMERAPOS_SECOND == m_eCameraPos)
		pstOptStep = (INFO_OPT_INSPECTSTEP*)&pstOption->m_stSecondCameraStep;

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

		CInspection* pInspection = pCaptureManager->GetInspection();
		const BOOL bStart = pInspection->IsStart();
		/////
		CUtil::PrintDebugString("DrawBaslerImage START : m_eCameraPos[%d], m_stDisplayOutput.m_eStep[%d]", m_eCameraPos, m_stDisplayOutput.m_eStep);
		// Pixel Buffer Copy
		if (TYPE_STEP_NONE == m_stDisplayOutput.m_eStep ||
			TYPE_STEP_001 == m_stDisplayOutput.m_eStep && (FALSE == pstOptStep->m_bStep001) ||
			TYPE_STEP_002 == m_stDisplayOutput.m_eStep && (FALSE == pstOptStep->m_bStep002 || m_stDisplayOutput.m_stOutputStain.m_pProbImage.empty()) ||
			TYPE_STEP_003 == m_stDisplayOutput.m_eStep && (FALSE == pstOptStep->m_bStep003 || m_stDisplayOutput.m_stOutputDiffer.m_pProbImage.empty()) ||
			TYPE_STEP_004 == m_stDisplayOutput.m_eStep && (FALSE == pstOptStep->m_bStep004 || m_stDisplayOutput.m_stOutputBubble.m_pProbImage.empty()) ||
			TYPE_STEP_005 == m_stDisplayOutput.m_eStep && (FALSE == pstOptStep->m_bStep005 || m_stDisplayOutput.m_stOutputScratch.m_pProbImage.empty()) ||
			TYPE_STEP_006 == m_stDisplayOutput.m_eStep && (FALSE == pstOptStep->m_bStep006 || m_stDisplayOutput.m_stOutputStamp.m_pProbImage.empty()) ||
			FALSE == bStart)
		{
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
				//// Captured image from camera...
				for (int y = 0; y < nFrameHeight; y++)
				{
					pDest = (BYTE*)pvBits + y*nFramePitch;
					pSrc = m_pstDisplayImage->m_pBuffer + y * nFramePitch;
					memcpy(pDest, pSrc, nFramePitch);
				}
			}
		}
		else
		{
			// Output Image...
			CopyPixelBuffer8Bit(m_stDisplayOutput.m_eStep, nFrameWidth, nFrameHeight, n24BitPitch, pvBits);
		}
		/////
		CUtil::PrintDebugString("DrawBaslerImage END \n");
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
		double fZoom = GetZoom();

		/// Output Roi
//		if (TYPE_STEP_001 == m_stDisplayOutput.m_eStep)
//		{
//#if 1
//			const OUTPUT_SIZE* pstOutputSize = &m_stDisplayOutput.m_stOutputSize;
//
//			COLORREF rgbOutLine = RGB(0xFF, 0xFF, 0x00);
//			COLORREF rgbLine = RGB(0x00, 0xFF, 0x00);
//			COLORREF rgbError = RGB(0xFF, 0x00, 0x00);
//			int nOutLine = 1;
//			int nLine = 2;
//
//			Gdiplus::Graphics graphics(pDC->m_hDC);
//			graphics.SetSmoothingMode(Gdiplus::SmoothingModeAntiAlias);
//
//			Gdiplus::Color clrOutLine(Gdiplus::Color::MakeARGB(0xFF, GetRValue(rgbOutLine), GetGValue(rgbOutLine), GetBValue(rgbOutLine)));
//			Gdiplus::Color clrLine(Gdiplus::Color::MakeARGB(0xFF, GetRValue(rgbLine), GetGValue(rgbLine), GetBValue(rgbLine)));
//			Gdiplus::Color clrError(Gdiplus::Color::MakeARGB(0xFF, GetRValue(rgbError), GetGValue(rgbError), GetBValue(rgbError)));
//
//			Gdiplus::Pen penOutLine(clrOutLine, (Gdiplus::REAL)nOutLine);
//			Gdiplus::Pen penLine(clrLine, (Gdiplus::REAL)nLine);
//			Gdiplus::Pen penError(clrError, (Gdiplus::REAL)nLine);
//
//			penLine.SetStartCap(Gdiplus::LineCapRoundAnchor);
//			penLine.SetEndCap(Gdiplus::LineCapRoundAnchor);
//			penError.SetStartCap(Gdiplus::LineCapRoundAnchor);
//			penError.SetEndCap(Gdiplus::LineCapRoundAnchor);
//
//			// OutLine
//			penOutLine.SetDashStyle(Gdiplus::DashStyleDash);
//			for (int i = 0; i < 4; i++)
//			{
//				const stLine* pLine = &pstOutputSize->m_stResultLine[i];
//				Gdiplus::REAL x1 = pLine->m_fStartX * fZoom;
//				Gdiplus::REAL y1 = pLine->m_fStartY * fZoom;
//				Gdiplus::REAL x2 = pLine->m_fEndX * fZoom;
//				Gdiplus::REAL y2 = pLine->m_fEndY * fZoom;
//				graphics.DrawLine(&penOutLine, x1, y1, x2, y2);
//			}
//			{
//				const stLine* pLine = &pstOutputSize->m_stResultLine[5];
//				Gdiplus::REAL x1 = pLine->m_fStartX * fZoom;
//				Gdiplus::REAL y1 = pLine->m_fStartY * fZoom;
//				Gdiplus::REAL x2 = pLine->m_fEndX * fZoom;
//				Gdiplus::REAL y2 = pLine->m_fEndY * fZoom;
//				graphics.DrawLine(&penOutLine, x1, y1, x2, y2);
//			}
//			{
//				const stLine* pLine = &pstOutputSize->m_stResultLine[10];
//				Gdiplus::REAL x1 = pLine->m_fStartX * fZoom;
//				Gdiplus::REAL y1 = pLine->m_fStartY * fZoom;
//				Gdiplus::REAL x2 = pLine->m_fEndX * fZoom;
//				Gdiplus::REAL y2 = pLine->m_fEndY * fZoom;
//				graphics.DrawLine(&penOutLine, x1, y1, x2, y2);
//			}
//
//			// Line (OK, NG)
//			{
//				INFO_LINE_GDIPLUS stLineGdiPlus;
//				stPOINT ptText;
//
//				for (int i = 0; i < MAX_GEOMETRY_DISTANCELINE_COUNT; i++)
//				{
//					const OUTPUT_DISTANCE* pstOutput = &pstOutputSize->m_stDistance[i];
//					if (TYPE_GEOMETRY_DISTANCE_D == i)			GetLineDistance_d(pstOutputSize, i, stLineGdiPlus, ptText);
//					else if (TYPE_GEOMETRY_DISTANCE_L == i)		GetLineDistance_L(pstOutputSize, i, stLineGdiPlus, ptText);
//					else if (TYPE_GEOMETRY_DISTANCE_W == i)		GetLineDistance_W(pstOutputSize, i, stLineGdiPlus, ptText);
//					else if (TYPE_GEOMETRY_DISTANCE_I1 == i)	GetLineDistance_I1(pstOutputSize, i, stLineGdiPlus, ptText);
//					else if (TYPE_GEOMETRY_DISTANCE_I2 == i)	GetLineDistance_I2(pstOutputSize, i, stLineGdiPlus, ptText);
//					else if (TYPE_GEOMETRY_DISTANCE_I3 == i)	GetLineDistance_I3(pstOutputSize, i, stLineGdiPlus, ptText);
//					else if (TYPE_GEOMETRY_DISTANCE_M1 == i)	GetLineDistance_M1(pstOutputSize, i, stLineGdiPlus, ptText);
//					else if (TYPE_GEOMETRY_DISTANCE_M2 == i)	GetLineDistance_M2(pstOutputSize, i, stLineGdiPlus, ptText);
//					else if (TYPE_GEOMETRY_DISTANCE_S1 == i)	GetLineDistance_S1(pstOutputSize, i, stLineGdiPlus, ptText);
//					else if (TYPE_GEOMETRY_DISTANCE_S2 == i)	GetLineDistance_S2(pstOutputSize, i, stLineGdiPlus, ptText);
//					else if (TYPE_GEOMETRY_DISTANCE_S3 == i)	GetLineDistance_S3(pstOutputSize, i, stLineGdiPlus, ptText);
//					else if (TYPE_GEOMETRY_DISTANCE_S4 == i)	GetLineDistance_S4(pstOutputSize, i, stLineGdiPlus, ptText);
//					else if (TYPE_GEOMETRY_DISTANCE_S5 == i)	GetLineDistance_S5(pstOutputSize, i, stLineGdiPlus, ptText);
//					else if (TYPE_GEOMETRY_DISTANCE_X1 == i)	GetLineDistance_X1(pstOutputSize, i, stLineGdiPlus, ptText);
//					else if (TYPE_GEOMETRY_DISTANCE_X2 == i)	GetLineDistance_X2(pstOutputSize, i, stLineGdiPlus, ptText);
//					else if (TYPE_GEOMETRY_DISTANCE_R1 == i)	GetLineDistance_R(pstOutputSize, i, stLineGdiPlus, ptText);
//					else if (TYPE_GEOMETRY_DISTANCE_R2 == i)	GetLineDistance_R(pstOutputSize, i, stLineGdiPlus, ptText);
//					else if (TYPE_GEOMETRY_DISTANCE_R3 == i)	GetLineDistance_R(pstOutputSize, i, stLineGdiPlus, ptText);
//					else if (TYPE_GEOMETRY_DISTANCE_R4 == i)	GetLineDistance_R(pstOutputSize, i, stLineGdiPlus, ptText);
//					else										continue;
//
//					Gdiplus::REAL x1 = stLineGdiPlus.m_fx1 * fZoom;
//					Gdiplus::REAL y1 = stLineGdiPlus.m_fy1 * fZoom;
//					Gdiplus::REAL x2 = stLineGdiPlus.m_fx2 * fZoom;
//					Gdiplus::REAL y2 = stLineGdiPlus.m_fy2 * fZoom;
//
//					{
//						Gdiplus::Font font(L"MS Shell Dlg", 10, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
//						Gdiplus::SolidBrush brFont(clrLine);
//						Gdiplus::SolidBrush brFontE(clrError);
//
//						WCHAR szText[MAX_NAME_LEN] = { 0, };
//
//#ifndef _UNICODE
//						size_t cnt;
//						WCHAR szWName[MAX_NAME_LEN] = { 0, };
//						mbstowcs_s(&cnt, szWName, sizeof(szWName) / sizeof(wchar_t), pstOption->m_stSizeName.m_szName[i], sizeof(szWName));
//						swprintf(szText, L"%s(%.03f)", szWName, pstOutput->m_dValue);
//#else
//						swprintf(szText, L"%s(%.03f)", pstOption->m_stSizeName.m_szName[i], pstOutput->m_dValue);
//#endif
//
//						Gdiplus::PointF ptF;
//						ptF.X = ptText.m_fX * fZoom;
//						ptF.Y = ptText.m_fY * fZoom;
//						if (pstOutput->m_bOK)
//						{
//							graphics.DrawLine(&penLine, x1, y1, x2, y2);
//							graphics.DrawString(szText, wcslen(szText), &font, ptF, &brFont);
//						}
//						else
//						{
//							graphics.DrawLine(&penError, x1, y1, x2, y2);
//							graphics.DrawString(szText, wcslen(szText), &font, ptF, &brFontE);
//						}
//					}
//				}
//			}
//#else
//			Gdiplus::Graphics graphics(pDC->m_hDC);
//			COLORREF rgbLine = RGB(0x00, 0xFF, 0x00);
//			COLORREF rgbError = RGB(0xFF, 0x00, 0x00);
//
//			Gdiplus::Color clrLine(Gdiplus::Color::MakeARGB(0xFF, GetRValue(rgbLine), GetGValue(rgbLine), GetBValue(rgbLine)));
//			Gdiplus::Color clrError(Gdiplus::Color::MakeARGB(0xFF, GetRValue(rgbError), GetGValue(rgbError), GetBValue(rgbError)));
//			Gdiplus::REAL width = 2.0f;
//
//			Gdiplus::Pen penLine(clrLine, width);
//			Gdiplus::Pen penError(clrError, width);
//
//			for (int i = 0; i < TYPE_FINDLINE_MAX; i++)
//			{
//				const OUTPUT_DISTANCE* pstOutput = &m_stDisplayOutput.m_stOutputSize.m_stDistance[i];
//				const stLine* pLine = &m_stDisplayOutput.m_stOutputSize.m_stResultLine[i];
//
//				Gdiplus::REAL x1 = pLine->m_fStartX * fZoom;
//				Gdiplus::REAL y1 = pLine->m_fStartY * fZoom;
//				Gdiplus::REAL x2 = pLine->m_fEndX * fZoom;
//				Gdiplus::REAL y2 = pLine->m_fEndY * fZoom;
//
//				if (pstOutput->m_bOK)
//					graphics.DrawLine(&penLine, x1, y1, x2, y2);!
//				else
//					graphics.DrawLine(&penError, x1, y1, x2, y2);
//			}
//#endif
//		}
//		else if (TYPE_STEP_007 == m_stDisplayOutput.m_eStep)
		if (TYPE_STEP_007 == m_stDisplayOutput.m_eStep)
		{
#if 1
			const OUTPUT_SIZE* pstOutputSize = &m_stDisplayOutput.m_stOutputSizeCalc;

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
				const stLine* pLine = &pstOutputSize->m_stResultLine[i];
				Gdiplus::REAL x1 = pLine->m_fStartX * fZoom;
				Gdiplus::REAL y1 = pLine->m_fStartY * fZoom;
				Gdiplus::REAL x2 = pLine->m_fEndX * fZoom;
				Gdiplus::REAL y2 = pLine->m_fEndY * fZoom;
				graphics.DrawLine(&penOutLine, x1, y1, x2, y2);
			}
			{
				const stLine* pLine = &pstOutputSize->m_stResultLine[5];
				Gdiplus::REAL x1 = pLine->m_fStartX * fZoom;
				Gdiplus::REAL y1 = pLine->m_fStartY * fZoom;
				Gdiplus::REAL x2 = pLine->m_fEndX * fZoom;
				Gdiplus::REAL y2 = pLine->m_fEndY * fZoom;
				graphics.DrawLine(&penOutLine, x1, y1, x2, y2);
			}
			{
				const stLine* pLine = &pstOutputSize->m_stResultLine[10];
				Gdiplus::REAL x1 = pLine->m_fStartX * fZoom;
				Gdiplus::REAL y1 = pLine->m_fStartY * fZoom;
				Gdiplus::REAL x2 = pLine->m_fEndX * fZoom;
				Gdiplus::REAL y2 = pLine->m_fEndY * fZoom;
				graphics.DrawLine(&penOutLine, x1, y1, x2, y2);
			}

			// Line (OK, NG)
			{
				INFO_LINE_GDIPLUS stLineGdiPlus;
				stPOINT ptText;

				for (int i = 0; i < MAX_GEOMETRY_DISTANCELINE_COUNT; i++)
				{
					const OUTPUT_DISTANCE* pstOutput = &pstOutputSize->m_stDistance[i];
					if (TYPE_GEOMETRY_DISTANCE_D == i)			GetLineDistance_d(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_L == i)		GetLineDistance_L(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_W == i)		GetLineDistance_W(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_I1 == i)	GetLineDistance_I1(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_I2 == i)	GetLineDistance_I2(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_I3 == i)	GetLineDistance_I3(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_M1 == i)	GetLineDistance_M1(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_M2 == i)	GetLineDistance_M2(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_S1 == i)	GetLineDistance_S1(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_S2 == i)	GetLineDistance_S2(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_S3 == i)	GetLineDistance_S3(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_S4 == i)	GetLineDistance_S4(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_S5 == i)	GetLineDistance_S5(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_X1 == i)	GetLineDistance_X1(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_X2 == i)	GetLineDistance_X2(pstOutputSize, i, stLineGdiPlus, ptText);
					// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
					/*else if (TYPE_GEOMETRY_DISTANCE_R1 == i)	GetLineDistance_R(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_R2 == i)	GetLineDistance_R(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_R3 == i)	GetLineDistance_R(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_R4 == i)	GetLineDistance_R(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_R5 == i)	GetLineDistance_R(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_R6 == i)	GetLineDistance_R(pstOutputSize, i, stLineGdiPlus, ptText);*/
					// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
					else if (TYPE_GEOMETRY_DISTANCE_SS1 == i)	GetLineDistance_SS1(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_SS2 == i)	GetLineDistance_SS2(pstOutputSize, i, stLineGdiPlus, ptText);
					else if (TYPE_GEOMETRY_DISTANCE_SS3 == i)	GetLineDistance_SS3(pstOutputSize, i, stLineGdiPlus, ptText);
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
			Gdiplus::Graphics graphics(pDC->m_hDC);
			COLORREF rgbLine = RGB(0x00, 0xFF, 0x00);
			COLORREF rgbError = RGB(0xFF, 0x00, 0x00);

			Gdiplus::Color clrLine(Gdiplus::Color::MakeARGB(0xFF, GetRValue(rgbLine), GetGValue(rgbLine), GetBValue(rgbLine)));
			Gdiplus::Color clrError(Gdiplus::Color::MakeARGB(0xFF, GetRValue(rgbError), GetGValue(rgbError), GetBValue(rgbError)));
			Gdiplus::REAL width = 2.0f;

			Gdiplus::Pen penLine(clrLine, width);
			Gdiplus::Pen penError(clrError, width);

			for (int i = 0; i < TYPE_FINDLINE_MAX; i++)
			{
				const OUTPUT_DISTANCE* pstOutput = &m_stDisplayOutput.m_stOutputSize.m_stDistance[i];
				const stLine* pLine = &m_stDisplayOutput.m_stOutputSize.m_stResultLine[i];

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

void CCustomScrollView::DrawBaslerImage24bit(CDC* pDC)
{
	if (NULL == pDC || NULL == m_pstDisplayImage)
		return;

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	CRect rect;
	GetClientRect(&rect);
	const int nClientWidth = rect.Width();
	const int nClientHeight = rect.Height();

	int scrlx = 0;
	int scrly = 0;

	// Image
	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);

	const INFO_FRAME* pFrame = &m_pstDisplayImage->m_stFrame;
	const int nBit = pCaptureManager->GetBitCount(m_pstDisplayImage->m_stFrame.m_eDataBit);
	const int nFrameWidth = m_pstDisplayImage->m_stFrame.m_dwWidth;
	const int nFrameHeight = m_pstDisplayImage->m_stFrame.m_dwHeight;

	const int n24BitPitch = (nFrameWidth * 3 +3) / 4 * 4;
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
	pstBmpInfo->bmiHeader.biSizeImage = n24BitPitch * nFrameHeight;

	hBitmap = CreateDIBSection(MemDC.m_hDC, pstBmpInfo, DIB_RGB_COLORS, &pvBits, NULL, 0x0);
	if (hBitmap)
	{
		BYTE* pSrc = NULL;
		BYTE* pDest = NULL;

		HBITMAP hOldBitmap = (HBITMAP)::SelectObject(MemDC.m_hDC, hBitmap);

		// Pixel Buffer Copy
		if (TYPE_STEP_NONE == m_stDisplayOutput.m_eStep)
		{
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
				//// Captured image from camera...
				for (int y = 0; y < nFrameHeight; y++)
				{
					pDest = (BYTE*)pvBits + y*nFramePitch;
					pSrc = m_pstDisplayImage->m_pBuffer + y * nFramePitch;
					memcpy(pDest, pSrc, nFramePitch);
				}
			}
		}
		else
		{
			// Output Image...
			CopyPixelBuffer24Bit(m_stDisplayOutput.m_eStep, nFrameWidth, nFrameHeight, n24BitPitch, pvBits);
		}

		const double fZoom = this->GetZoom();

		int x1 = 0;
		int y1 = 0;
		int cx1 = (int)(nFrameWidth * fZoom);
		int cy1 = (int)(nFrameHeight * fZoom);

		int x2 = 0;
		int y2 = 0;

		if (DEFAULT_ZOOM_FACTOR == fZoom)
		{
			x2 = GetScrollPos(SB_HORZ);
			y2 = GetScrollPos(SB_VERT);
			pDC->BitBlt(x1, y1, cx1, cy1, &MemDC, x2, y2, SRCCOPY);
		}
		else if (m_bFitZoom)
		{
			pDC->SetStretchBltMode(STRETCH_HALFTONE);
			pDC->StretchBlt(x1, y1, cx1, cy1, &MemDC, 0, 0, nFrameWidth, nFrameHeight, SRCCOPY);
		}
		else
		{
			x2 = (int)(GetScrollPos(SB_HORZ) / fZoom);
			y2 = (int)(GetScrollPos(SB_VERT) / fZoom);
			int cx2 = (int)(nClientWidth / fZoom);
			int cy2 = (int)(nClientHeight / fZoom);

			if (cx1 > nClientWidth)		cx1 = nClientWidth;
			if (cy1 > nClientHeight)	cy1 = nClientHeight;

			if (nFrameWidth < (x2 + cx2))			cx2 = nFrameWidth - x2;
			if (nFrameHeight < (y2 + cy2))			cy2 = nFrameHeight - y2;

			pDC->SetStretchBltMode(STRETCH_HALFTONE);
			pDC->StretchBlt(x1, y1, cx1, cy1, &MemDC, x2, y2, cx2, cy2, SRCCOPY);
		}

		scrlx = x2;
		scrly = y2;

		::SelectObject(MemDC.m_hDC, hOldBitmap);
		::DeleteObject(hBitmap);
	}
	delete[] pstBmpInfo;
}
#endif

void CCustomScrollView::UpdateScrollSize()
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

void CCustomScrollView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CScrollView::OnHScroll(nSBCode, nPos, pScrollBar);
	this->Invalidate(FALSE);
}

void CCustomScrollView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CScrollView::OnVScroll(nSBCode, nPos, pScrollBar);
	this->Invalidate(FALSE);
}



// Command Function - Edit
void  CCustomScrollView::OnCommandEdit()
{
	CWnd* pWnd = this->GetParent();
	if (pWnd)
	{
		pWnd->SendMessage(WM_NOTIFY_EDIT);
	}
}

// Command Function - Grab
void CCustomScrollView::OnCommandGrab()
{
	CWnd* pWnd = this->GetParent();
	if (pWnd)
	{
		pWnd->SendMessage(WM_NOTIFY_GRAB);
	}
}

void CCustomScrollView::OnCommandStrobeOff()
{
	CWnd* pWnd = this->GetParent();
	if (pWnd)
	{
		WPARAM wParam = 0;
		LPARAM lParam = TYPE_STROBE_OFF;
		pWnd->SendMessage(WM_NOTIFY_STROBE, wParam, lParam);
	}
}

void CCustomScrollView::OnCommandStrobeCoaxial()
{
	CWnd* pWnd = this->GetParent();
	if (pWnd)
	{
		WPARAM wParam = 0;
		LPARAM lParam = TYPE_STROBE_COXIAL;
		pWnd->SendMessage(WM_NOTIFY_STROBE, wParam, lParam);
	}
}

void CCustomScrollView::OnCommandStrobeRing()
{
	CWnd* pWnd = this->GetParent();
	if (pWnd)
	{
		WPARAM wParam = 0;
		LPARAM lParam = TYPE_STROBE_RING;
		pWnd->SendMessage(WM_NOTIFY_STROBE, wParam, lParam);
	}
}

void CCustomScrollView::OnCommandStrobeBar()
{
	CWnd* pWnd = this->GetParent();
	if (pWnd)
	{
		WPARAM wParam = 0;
		LPARAM lParam = TYPE_STROBE_BAR;
		pWnd->SendMessage(WM_NOTIFY_STROBE, wParam, lParam);
	}
}

//테스트 사이즈
// Version 1.3.7.8 AutoGain - 이미지 업로드 (First, Second)
void CCustomScrollView::OnCommandTestSize()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CSerialCtrl* pSerialCtrl = pCaptureManager->GetStrobeControlPort(m_eCameraPos);
	CInspection* pInspection = pCaptureManager->GetInspection();

	cv::Mat tmpImg;
	cv::Mat firstImg;
	cv::Mat secondImg;

	/////첫번째 조명 촬영
	{
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, TYPE_STEP_001);
		CStepSize* pStepSize = dynamic_cast<CStepSize*>(pStep);
		const INFO_INSPECTION_SIZE* pstSizeInfo = pStepSize->GetInformation();

		// Strobe Setting
		// OFF Strobe
		pCaptureManager->ControlStrobeOnOff(pSerialCtrl, m_eCameraPos, TYPE_STROBE_OFF);
		// Control Strobe.
		for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
		{
			const TYPE_STROBE eStrobe = pstSizeInfo->m_pstStepStrobe[i].m_eStrobeType;
			const int nStrobeBrightness = pstSizeInfo->m_pstStepStrobe[i].m_nStrobeBrightness;
			if (TYPE_STROBE_COXIAL == eStrobe || TYPE_STROBE_RING == eStrobe || TYPE_STROBE_BAR == eStrobe)
			{
				//pCaptureManager->ControlStrobeOnOff(pSerialCtrl, m_eCameraPos, eStrobe);
				pCaptureManager->ControlStrobeBrightness(pSerialCtrl, m_eCameraPos, eStrobe, nStrobeBrightness);
			}
		}

#ifdef DEF_DELAY_CAPTURE
		const INFO_OPTION* pstOption = pCaptureManager->GetOption();
		int delay = pstOption->m_stCapture.m_nDelay;
		if (delay > 0)
			CUtil::WaitnSleep(delay);
#endif

		// Grab Image;
		OnCommandGrab();
		CUtil::WaitnSleep(100);
	}

	const INFO_IMAGE* pImage1 = this->GetDisplayImage();
	tmpImg = cv::Mat(pImage1->m_stFrame.m_dwHeight, pImage1->m_stFrame.m_dwWidth, CV_8UC3, pImage1->m_pBuffer, pImage1->m_stFrame.m_dwPitch);
	firstImg = tmpImg.clone();

#if 1
	auto starttime = chrono::high_resolution_clock::now();
	const int timeout = 3000;
	const int interval = 300;
	while (NULL == pImage1)
	{
		CUtil::WaitnSleep(interval);
		pImage1 = this->GetDisplayImage();
		tmpImg = cv::Mat(pImage1->m_stFrame.m_dwHeight, pImage1->m_stFrame.m_dwWidth, CV_8UC3, pImage1->m_pBuffer, pImage1->m_stFrame.m_dwPitch);
		firstImg = tmpImg.clone();

		auto nowtime = chrono::high_resolution_clock::now();
		int elapsedtime = static_cast<int>(chrono::duration<double, milli>(nowtime - starttime).count());

		if (elapsedtime > timeout)
		{
			break;
		}
	}
#endif
	if (NULL == pImage1)
	{
		AfxMessageBox(STR_MSG_ELOAD_IMAGE);
		return;
	}

	/////두번째 조명 촬영
	{
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, TYPE_STEP_007);
		CStepSizeSecond* pStepSize = dynamic_cast<CStepSizeSecond*>(pStep);
		const INFO_INSPECTION_SIZE* pstSizeInfo = pStepSize->GetInformation();

		// Strobe Setting
		// OFF Strobe
		pCaptureManager->ControlStrobeOnOff(pSerialCtrl, m_eCameraPos, TYPE_STROBE_OFF);
		// Control Strobe.
		for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
		{
			const TYPE_STROBE eStrobe = pstSizeInfo->m_pstStepStrobe[i].m_eStrobeType;
			const int nStrobeBrightness = pstSizeInfo->m_pstStepStrobe[i].m_nStrobeBrightness;
			if (TYPE_STROBE_COXIAL == eStrobe || TYPE_STROBE_RING == eStrobe || TYPE_STROBE_BAR == eStrobe)
			{
				//pCaptureManager->ControlStrobeOnOff(pSerialCtrl, m_eCameraPos, eStrobe);
				pCaptureManager->ControlStrobeBrightness(pSerialCtrl, m_eCameraPos, eStrobe, nStrobeBrightness);
			}
		}

#ifdef DEF_DELAY_CAPTURE
		const INFO_OPTION* pstOption = pCaptureManager->GetOption();
		int delay = pstOption->m_stCapture.m_nDelay;
		if (delay > 0)
			CUtil::WaitnSleep(delay);
#endif

		// Grab Image;
		OnCommandGrab();
		CUtil::WaitnSleep(100);
	}

	const INFO_IMAGE* pImage2 = this->GetDisplayImage();
	tmpImg = cv::Mat(pImage2->m_stFrame.m_dwHeight, pImage2->m_stFrame.m_dwWidth, CV_8UC3, pImage2->m_pBuffer, pImage2->m_stFrame.m_dwPitch);
	secondImg = tmpImg.clone();

#if 1
	while (NULL == pImage2)
	{
		CUtil::WaitnSleep(interval);
		tmpImg = cv::Mat(pImage2->m_stFrame.m_dwHeight, pImage2->m_stFrame.m_dwWidth, CV_8UC3, pImage2->m_pBuffer, pImage2->m_stFrame.m_dwPitch);
		secondImg = tmpImg.clone();

		auto nowtime = chrono::high_resolution_clock::now();
		int elapsedtime = static_cast<int>(chrono::duration<double, milli>(nowtime - starttime).count());

		if (elapsedtime > timeout)
		{
			break;
		}
	}
#endif
	if (NULL == pImage2)
	{
		AfxMessageBox(STR_MSG_ELOAD_IMAGE);
		return;
	}

	// Inspection Size
	{
		const INFO_OPTION* pstOption = pCaptureManager->GetOption();

		CSampleSide sample;
		memcpy(sample.m_pstRefOptRangeSpecList, pstOption->m_pstRangeSpec, sizeof(INFO_OPT_RANGE)*MAX_SIZE_MEASURECOUNT);
		if (TYPE_CAMERAPOS_FIRST == m_eCameraPos)
			memcpy(sample.m_pstRefOptRangeList, pstOption->m_pstRange[0], sizeof(INFO_OPT_RANGE)*MAX_SIZE_MEASURECOUNT);
		else
			memcpy(sample.m_pstRefOptRangeList, pstOption->m_pstRange[1], sizeof(INFO_OPT_RANGE)*MAX_SIZE_MEASURECOUNT);

		CSampleSide* pSample = NULL;
		pSample = &sample;

		sample.m_pRefImage = (INFO_IMAGE*)pImage1;
		BOOL bResult = pInspection->InspectCamera(m_eCameraPos, TYPE_STEP_001, sample, firstImg);

		sample.m_pRefImage = (INFO_IMAGE*)pImage2;
		bResult = pInspection->InspectCamera(m_eCameraPos, TYPE_STEP_007, sample, secondImg);

		pInspection->CalculationSize(m_eCameraPos, sample);

		// Version 1.3.7.8
		m_Sample.reset(new CSampleSide);
		m_Sample->CopyFrom(sample);

		if (bResult)
		{
			DisplayStepOutput(TYPE_STEP_007, &(sample.m_SizeCalculationResult));

			{
				SYSTEMTIME stTime;
				::GetLocalTime(&stTime);

				// Save Test Result
				TCHAR szSizeLogPath[MAX_FILE_PATH_LEN] = { 0, };
				const INFO_OPTIONETC* pstOptEtc = pCaptureManager->GetOptionEtc();

				if (TYPE_CAMERAPOS_FIRST == m_eCameraPos)
				{
					CUtil::StringFormat(szSizeLogPath, MAX_FILE_PATH_LEN, _T("%s\\%04d%02d%02d_%02d%02d%02d_test_size_result_first.txt"),
						pstOptEtc->m_szLotIdPath,
						stTime.wYear, stTime.wMonth, stTime.wDay, stTime.wHour, stTime.wMinute, stTime.wSecond);
				}
				else
				{
					CUtil::StringFormat(szSizeLogPath, MAX_FILE_PATH_LEN, _T("%s\\%04d%02d%02d_%02d%02d%02d_test_size_result_second.txt"),
						pstOptEtc->m_szLotIdPath,
						stTime.wYear, stTime.wMonth, stTime.wDay, stTime.wHour, stTime.wMinute, stTime.wSecond);
				}

				HANDLE hFile = ::CreateFile(szSizeLogPath,
					GENERIC_READ | GENERIC_WRITE,
					FILE_SHARE_READ | FILE_SHARE_WRITE,
					NULL,
					CREATE_ALWAYS,
					FILE_FLAG_WRITE_THROUGH,
					NULL);
				if (INVALID_HANDLE_VALUE != hFile)
				{
					TCHAR szString[MAX_TEXT_LEN] = { 0, };
					DWORD dwResult = 0;

					CUtil::StringFormat(szString, MAX_TEXT_LEN, _T("%04d%02d%02d %02d:%02d:%02d test result \r\n"),
						stTime.wYear, stTime.wMonth, stTime.wDay, stTime.wHour, stTime.wMinute, stTime.wSecond);
					::WriteFile(hFile, szString, CUtil::StringLength(szString), &dwResult, NULL);

					{
						OUTPUT_DISTANCE* pstDistance = NULL;
						int nIdx = 0;

						for (; nIdx < MAX_GEOMETRY_DISTANCELINE_COUNT; nIdx++)
						{
							pstDistance = &(sample.m_SizeCalculationResult.m_stDistance[nIdx]);
							FormatSizeLog(szString, MAX_TEXT_LEN, pstOption->m_stSizeName.m_szName[nIdx], pstDistance->m_dValue, pstDistance->m_bOK);
							::WriteFile(hFile, szString, CUtil::StringLength(szString), &dwResult, NULL);
						}

						{
							pstDistance = &(sample.m_SizeCalculationResult.m_stDistance[nIdx]);
							FormatSizeLog(szString, MAX_TEXT_LEN, pstOption->m_stSizeName.GetNameX1X2(), pstDistance->m_dValue, pstDistance->m_bOK);
							::WriteFile(hFile, szString, CUtil::StringLength(szString), &dwResult, NULL); nIdx++;

							pstDistance = &(sample.m_SizeCalculationResult.m_stDistance[nIdx]);
							FormatSizeLog(szString, MAX_TEXT_LEN, pstOption->m_stSizeName.GetNameS1S3(), pstDistance->m_dValue, pstDistance->m_bOK);
							::WriteFile(hFile, szString, CUtil::StringLength(szString), &dwResult, NULL); nIdx++;

							pstDistance = &(sample.m_SizeCalculationResult.m_stDistance[nIdx]);
							FormatSizeLog(szString, MAX_TEXT_LEN, pstOption->m_stSizeName.GetNameM1M2(), pstDistance->m_dValue, pstDistance->m_bOK);
							::WriteFile(hFile, szString, CUtil::StringLength(szString), &dwResult, NULL); nIdx++;
						}


						CUtil::StringFormat(szString, MAX_TEXT_LEN, _T("\r\n"));
						::WriteFile(hFile, szString, CUtil::StringLength(szString), &dwResult, NULL);
					}
					::CloseHandle(hFile);
				}
			}
		}
		else
		{
			AfxMessageBox(STR_MSG_FAIL_INSPECTION);
		}
	}
}

//테스트 step2 얼룩
void CCustomScrollView::OnCommandTestStep2()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CSerialCtrl* pSerialCtrl = pCaptureManager->GetStrobeControlPort(m_eCameraPos);
	CInspection* pInspection = pCaptureManager->GetInspection();

	{
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, TYPE_STEP_002);
		CStepStain* pStepStain = dynamic_cast<CStepStain*>(pStep);
		const INFO_INSPECTION_STAIN* pstStainInfo = pStepStain->GetInformation();

		// Strobe Setting
		// OFF Strobe
		pCaptureManager->ControlStrobeOnOff(pSerialCtrl, m_eCameraPos, TYPE_STROBE_OFF);
		// Control Strobe.
		for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
		{
			const TYPE_STROBE eStrobe = pstStainInfo->m_pstStepStrobe[i].m_eStrobeType;
			const int nStrobeBrightness = pstStainInfo->m_pstStepStrobe[i].m_nStrobeBrightness;
			if (TYPE_STROBE_COXIAL == eStrobe || TYPE_STROBE_RING == eStrobe || TYPE_STROBE_BAR == eStrobe)
			{
				//pCaptureManager->ControlStrobeOnOff(pSerialCtrl, m_eCameraPos, eStrobe);
				pCaptureManager->ControlStrobeBrightness(pSerialCtrl, m_eCameraPos, eStrobe, nStrobeBrightness);
			}
		}

#ifdef DEF_DELAY_CAPTURE
		const INFO_OPTION* pstOption = pCaptureManager->GetOption();
		int delay = pstOption->m_stCapture.m_nDelay;
		if (delay > 0)
			CUtil::WaitnSleep(delay);
#endif

		// Grab Image;
		OnCommandGrab();
		CUtil::WaitnSleep(100);
	}

	cv::Mat tmpImg;
	cv::Mat firstImg;

	const INFO_IMAGE* pImage = this->GetDisplayImage();
	
#if 1
	auto starttime = chrono::high_resolution_clock::now();
	const int timeout = 3000;
	const int interval = 300;
	while (NULL == pImage)
	{
		CUtil::WaitnSleep(interval);
		pImage = this->GetDisplayImage();

		auto nowtime = chrono::high_resolution_clock::now();
		int elapsedtime = static_cast<int>(chrono::duration<double, milli>(nowtime - starttime).count());

		if (elapsedtime > timeout)
		{
			break;
		}
	}
#endif
	if (NULL == pImage)
	{
		AfxMessageBox(STR_MSG_ELOAD_IMAGE);
		return;
	}

	// Inspection Size
	{
		CSampleSide sample;

		sample.m_pRefImage = (INFO_IMAGE*)pImage;
		BOOL bResult = pInspection->InspectCamera(m_eCameraPos, TYPE_STEP_002, sample);
		if (bResult)
		{
			DisplayStepOutput(TYPE_STEP_002, &(sample.m_StainResult));
		}
		else
		{
			AfxMessageBox(STR_MSG_FAIL_INSPECTION);
		}
	}
}

//테스트 step3 이물
void CCustomScrollView::OnCommandTestStep3()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CSerialCtrl* pSerialCtrl = pCaptureManager->GetStrobeControlPort(m_eCameraPos);
	CInspection* pInspection = pCaptureManager->GetInspection();

	{
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, TYPE_STEP_003);
		CStepDiffer* pStepDiffer = dynamic_cast<CStepDiffer*>(pStep);
		const INFO_INSPECTION_DIFFER* pstDifferInfo = pStepDiffer->GetInformation();

		// Strobe Setting
		// OFF Strobe
		pCaptureManager->ControlStrobeOnOff(pSerialCtrl, m_eCameraPos, TYPE_STROBE_OFF);
		// Control Strobe.
		for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
		{
			const TYPE_STROBE eStrobe = pstDifferInfo->m_pstStepStrobe[i].m_eStrobeType;
			const int nStrobeBrightness = pstDifferInfo->m_pstStepStrobe[i].m_nStrobeBrightness;
			if (TYPE_STROBE_COXIAL == eStrobe || TYPE_STROBE_RING == eStrobe || TYPE_STROBE_BAR == eStrobe)
			{
				//pCaptureManager->ControlStrobeOnOff(pSerialCtrl, m_eCameraPos, eStrobe);
				pCaptureManager->ControlStrobeBrightness(pSerialCtrl, m_eCameraPos, eStrobe, nStrobeBrightness);
			}
		}

#ifdef DEF_DELAY_CAPTURE
		const INFO_OPTION* pstOption = pCaptureManager->GetOption();
		int delay = pstOption->m_stCapture.m_nDelay;
		if (delay > 0)
			CUtil::WaitnSleep(delay);
#endif

		// Grab Image;
		OnCommandGrab();
		CUtil::WaitnSleep(100);
	}

	cv::Mat tmpImg;
	cv::Mat firstImg;

	const INFO_IMAGE* pImage = this->GetDisplayImage();

#if 1
	auto starttime = chrono::high_resolution_clock::now();
	const int timeout = 3000;
	const int interval = 300;
	while (NULL == pImage)
	{
		CUtil::WaitnSleep(interval);
		pImage = this->GetDisplayImage();

		auto nowtime = chrono::high_resolution_clock::now();
		int elapsedtime = static_cast<int>(chrono::duration<double, milli>(nowtime - starttime).count());

		if (elapsedtime > timeout)
		{
			break;
		}
	}
#endif
	if (NULL == pImage)
	{
		AfxMessageBox(STR_MSG_ELOAD_IMAGE);
		return;
	}

	// Inspection Size
	{
		CSampleSide sample;

		sample.m_pRefImage = (INFO_IMAGE*)pImage;
		BOOL bResult = pInspection->InspectCamera(m_eCameraPos, TYPE_STEP_003, sample);
		if (bResult)
		{
			DisplayStepOutput(TYPE_STEP_003, &(sample.m_DifferResult));
		}
		else
		{
			AfxMessageBox(STR_MSG_FAIL_INSPECTION);
		}
	}
}

//테스트 step4 기포
void CCustomScrollView::OnCommandTestStep4()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CSerialCtrl* pSerialCtrl = pCaptureManager->GetStrobeControlPort(m_eCameraPos);
	CInspection* pInspection = pCaptureManager->GetInspection();

	{
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, TYPE_STEP_004);
		CStepBubble* pStepBubble = dynamic_cast<CStepBubble*>(pStep);
		const INFO_INSPECTION_BUBBLE* pstBubbleInfo = pStepBubble->GetInformation();

		// Strobe Setting
		// OFF Strobe
		pCaptureManager->ControlStrobeOnOff(pSerialCtrl, m_eCameraPos, TYPE_STROBE_OFF);
		// Control Strobe.
		for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
		{
			const TYPE_STROBE eStrobe = pstBubbleInfo->m_pstStepStrobe[i].m_eStrobeType;
			const int nStrobeBrightness = pstBubbleInfo->m_pstStepStrobe[i].m_nStrobeBrightness;
			if (TYPE_STROBE_COXIAL == eStrobe || TYPE_STROBE_RING == eStrobe || TYPE_STROBE_BAR == eStrobe)
			{
				//pCaptureManager->ControlStrobeOnOff(pSerialCtrl, m_eCameraPos, eStrobe);
				pCaptureManager->ControlStrobeBrightness(pSerialCtrl, m_eCameraPos, eStrobe, nStrobeBrightness);
			}
		}

#ifdef DEF_DELAY_CAPTURE
		const INFO_OPTION* pstOption = pCaptureManager->GetOption();
		int delay = pstOption->m_stCapture.m_nDelay;
		if (delay > 0)
			CUtil::WaitnSleep(delay);
#endif

		// Grab Image;
		OnCommandGrab();
		CUtil::WaitnSleep(100);
	}

	cv::Mat tmpImg;
	cv::Mat firstImg;

	const INFO_IMAGE* pImage = this->GetDisplayImage();

#if 1
	auto starttime = chrono::high_resolution_clock::now();
	const int timeout = 3000;
	const int interval = 300;
	while (NULL == pImage)
	{
		CUtil::WaitnSleep(interval);
		pImage = this->GetDisplayImage();

		auto nowtime = chrono::high_resolution_clock::now();
		int elapsedtime = static_cast<int>(chrono::duration<double, milli>(nowtime - starttime).count());

		if (elapsedtime > timeout)
		{
			break;
		}
	}
#endif
	if (NULL == pImage)
	{
		AfxMessageBox(STR_MSG_ELOAD_IMAGE);
		return;
	}

	// Inspection Size
	{
		CSampleSide sample;

		sample.m_pRefImage = (INFO_IMAGE*)pImage;
		BOOL bResult = pInspection->InspectCamera(m_eCameraPos, TYPE_STEP_004, sample);
		if (bResult)
		{
			DisplayStepOutput(TYPE_STEP_004, &(sample.m_BubbleResult));
		}
		else
		{
			AfxMessageBox(STR_MSG_FAIL_INSPECTION);
		}
	}
}

void CCustomScrollView::FormatSizeLog(TCHAR* pStr, const int nStrLen, const TCHAR* pszSizeTitle, const double fSizeValue, const BOOL bSizeResult)
{
	if (NULL == pStr || NULL == pszSizeTitle)
		return;

	if (bSizeResult)
		CUtil::StringFormat(pStr, nStrLen, _T("%s value %.03f result(OK) \r\n"), pszSizeTitle, fSizeValue);
	else
		CUtil::StringFormat(pStr, nStrLen, _T("%s value %.03f result(NG) \r\n"), pszSizeTitle, fSizeValue);
}



void CCustomScrollView::DisplayImage(const INFO_IMAGE* pstImage)
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
	if (NULL == pstImage)
	{
		// Clear Display
		ClearImage();
	}
	else
	{
#ifdef USE_BASLER_CAMERA
		const int nChannel = 3;
		const int nPitch = (nChannel*pstImage->m_stFrame.m_dwWidth + 3) / 4 * 4;
		if (pstImage->m_stFrame.m_eColor == TYPE_CAMCOLOR_COLOR && pstImage->m_stFrame.m_eColorBit == TYPE_DATABIT_08)
		{
			if (!CreateColorBuffer(pstImage))
			{
				::LeaveCriticalSection(&m_CriticalSection);
				return;
			}
		}
#endif

		// Check Buffer Length
#ifdef USE_BASLER_CAMERA
		if (NULL != m_pstDisplayImage && m_pstDisplayImage->m_nBufLen != m_nColorBufLen)
#else
		if (NULL != m_pstDisplayImage && m_pstDisplayImage->m_nBufLen != pstImage->m_stFrame.m_dwMaxWidth * pstImage->m_stFrame.m_dwMaxHeight)
#endif
			ClearImage();

		BOOL bUpdateScroll = FALSE;

		// Display Image
		if (NULL == m_pstDisplayImage)
		{
			m_pstDisplayImage = new INFO_IMAGE;
			memset(m_pstDisplayImage, 0x00, sizeof(INFO_IMAGE));

#ifdef USE_BASLER_CAMERA
			m_pstDisplayImage->m_nBufLen = m_nColorBufLen;;
#else
			m_pstDisplayImage->m_nBufLen = pstImage->m_stFrame.m_dwMaxWidth * pstImage->m_stFrame.m_dwMaxHeight;
#endif
			m_pstDisplayImage->m_pBuffer = new BYTE[m_pstDisplayImage->m_nBufLen];

			bUpdateScroll = TRUE;
		}
		m_pstDisplayImage->m_stFrame = pstImage->m_stFrame;
#ifdef USE_BASLER_CAMERA
		m_pstDisplayImage->m_stFrame.m_dwMaxPitch = nPitch;
		m_pstDisplayImage->m_stFrame.m_dwPitch = nPitch;
		m_pstDisplayImage->m_nLen = m_nColorBufLen;
		memcpy(m_pstDisplayImage->m_pBuffer, m_pColorBuffer, m_nColorBufLen);
#else
		m_pstDisplayImage->m_nLen = pstImage->m_nLen;
		memcpy(m_pstDisplayImage->m_pBuffer, pstImage->m_pBuffer, pstImage->m_nLen);
#endif

		SetFitZoom(m_bFitZoom);
		
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

const INFO_IMAGE* CCustomScrollView::GetDisplayImage()
{
	return m_pstDisplayImage;
}

void CCustomScrollView::ClearImage()
{
	if (m_pstDisplayImage)
	{
		if (m_pstDisplayImage->m_pBuffer)
			delete[] m_pstDisplayImage->m_pBuffer;

		delete m_pstDisplayImage;
	}
	m_pstDisplayImage = NULL;
}

const double CCustomScrollView::GetZoom()
{
	return m_fZoom;
}

void CCustomScrollView::SetZoom(double fZoom)
{
	m_fZoom = fZoom;
}

void CCustomScrollView::SetFitZoom(BOOL bFit)
{
	m_bFitZoom = bFit;
	if (m_bFitZoom)
	{
		double fFitZoom = GetFitZoom();
		SetZoom(fFitZoom);
	}
}

const double CCustomScrollView::GetFitZoom()
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


void CCustomScrollView::DisplayStepOutput(TYPE_STEP eStep, void* pstOutput)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_OPTION* pstOpt = pCaptureManager->GetOption();

	BOOL bEnable = FALSE;
	if (TYPE_CAMERAPOS_FIRST == m_eCameraPos)
	{
		if (TYPE_STEP_001 == eStep)		bEnable = pstOpt->m_stFirstCameraStep.m_bStep001;
		else if (TYPE_STEP_002 == eStep)	bEnable = pstOpt->m_stFirstCameraStep.m_bStep002;
		else if (TYPE_STEP_003 == eStep)	bEnable = pstOpt->m_stFirstCameraStep.m_bStep003;
		else if (TYPE_STEP_004 == eStep)	bEnable = pstOpt->m_stFirstCameraStep.m_bStep004;
		else if (TYPE_STEP_005 == eStep)	bEnable = pstOpt->m_stFirstCameraStep.m_bStep005;
		else if (TYPE_STEP_006 == eStep)	bEnable = pstOpt->m_stFirstCameraStep.m_bStep006;
		else if (TYPE_STEP_007 == eStep)	bEnable = pstOpt->m_stFirstCameraStep.m_bStep001;
	}
	else if (TYPE_CAMERAPOS_SECOND == m_eCameraPos)
	{
		if (TYPE_STEP_002 == eStep)		bEnable = pstOpt->m_stSecondCameraStep.m_bStep002;
		else if (TYPE_STEP_003 == eStep)	bEnable = pstOpt->m_stSecondCameraStep.m_bStep003;
		else if (TYPE_STEP_004 == eStep)	bEnable = pstOpt->m_stSecondCameraStep.m_bStep004;
		else if (TYPE_STEP_005 == eStep)	bEnable = pstOpt->m_stSecondCameraStep.m_bStep005;
		else if (TYPE_STEP_006 == eStep)	bEnable = pstOpt->m_stSecondCameraStep.m_bStep006;
#ifdef DEF_SECONDCAMERA_CHECKSIZE
		else if (TYPE_STEP_001 == eStep)	bEnable = pstOpt->m_stSecondCameraStep.m_bStep001;
		else if (TYPE_STEP_007 == eStep)	bEnable = pstOpt->m_stSecondCameraStep.m_bStep001;
#endif
	}
	if (FALSE == bEnable)
		return;

	::EnterCriticalSection(&m_CriticalSection);
	m_stDisplayOutput.m_eStep = eStep;
	if (TYPE_STEP_001 == eStep  && pstOutput)
	{
		::EnterCriticalSection(&m_CriticalSection_ImageBuffer);
		OUTPUT_SIZE* pstSize = (OUTPUT_SIZE*)pstOutput;
		memcpy(&m_stDisplayOutput.m_stOutputSize, pstSize, sizeof(OUTPUT_SIZE));

		const int nBufLen = pstSize->m_stCalibratedImage.m_iImageSize;

		if (m_pBuffer && nBufLen > m_nBufLen)
		{
			delete[] m_pBuffer;
			m_pBuffer = NULL;
			m_nBufLen = 0;
		}

		if (NULL == m_pBuffer)
		{
			m_nBufLen = nBufLen;
			m_pBuffer = new unsigned char[m_nBufLen];
		}

		memcpy(m_pBuffer, pstSize->m_stCalibratedImage.m_pSrcImage, m_nBufLen);
		m_stDisplayOutput.m_stOutputSize.m_stCalibratedImage.m_pSrcImage = m_pBuffer;

		::LeaveCriticalSection(&m_CriticalSection_ImageBuffer);
	}
	else if (TYPE_STEP_007 == eStep  && pstOutput)
	{
		::EnterCriticalSection(&m_CriticalSection_ImageBuffer);
		OUTPUT_SIZE* pstSize = (OUTPUT_SIZE*)pstOutput;
		memcpy(&m_stDisplayOutput.m_stOutputSizeCalc, pstSize, sizeof(OUTPUT_SIZE));

		const int nBufLen = pstSize->m_stCalibratedImage.m_iImageSize;

		if (m_pBuffer && nBufLen > m_nBufLen)
		{
			delete[] m_pBuffer;
			m_pBuffer = NULL;
			m_nBufLen = 0;
		}

		if (NULL == m_pBuffer)
		{
			m_nBufLen = nBufLen;
			m_pBuffer = new unsigned char[m_nBufLen];
		}

		memcpy(m_pBuffer, pstSize->m_stCalibratedImage.m_pSrcImage, m_nBufLen);
		m_stDisplayOutput.m_stOutputSizeCalc.m_stCalibratedImage.m_pSrcImage = m_pBuffer;

		::LeaveCriticalSection(&m_CriticalSection_ImageBuffer);
	}
	else if (TYPE_STEP_002 == eStep && pstOutput)
	{
		::EnterCriticalSection(&m_CriticalSection_ImageBuffer);
		OUTPUT_STAIN* pstStain = (OUTPUT_STAIN*)pstOutput;

		// Clear
		m_stDisplayOutput.m_stOutputStain.m_pProbImage.release();
		m_stDisplayOutput.m_stOutputStain.m_fMaxDefectSize.clear();

		// Copy
		m_stDisplayOutput.m_stOutputStain.m_bResult = pstStain->m_bResult;

		const int nSize = pstStain->m_fMaxDefectSize.size();
		if (0 < nSize)
		{
			m_stDisplayOutput.m_stOutputStain.m_fMaxDefectSize.resize(nSize);
			std::copy(pstStain->m_fMaxDefectSize.begin(), pstStain->m_fMaxDefectSize.end(), m_stDisplayOutput.m_stOutputStain.m_fMaxDefectSize.begin());
		}
		m_stDisplayOutput.m_stOutputStain.m_pProbImage = pstStain->m_pProbImage.clone();
		::LeaveCriticalSection(&m_CriticalSection_ImageBuffer);
	}
	else if (TYPE_STEP_003 == eStep && pstOutput)
	{
		::EnterCriticalSection(&m_CriticalSection_ImageBuffer);
		OUTPUT_DIFFER* pstDiffer = (OUTPUT_DIFFER*)pstOutput;

		// Clear
		m_stDisplayOutput.m_stOutputDiffer.m_pProbImage.release();
		m_stDisplayOutput.m_stOutputDiffer.m_fMaxDefectSize.clear();

		// Copy
		m_stDisplayOutput.m_stOutputDiffer.m_bResult = pstDiffer->m_bResult;

		const int nSize = pstDiffer->m_fMaxDefectSize.size();
		if (0 < nSize)
		{
			m_stDisplayOutput.m_stOutputDiffer.m_fMaxDefectSize.resize(nSize);
			std::copy(pstDiffer->m_fMaxDefectSize.begin(), pstDiffer->m_fMaxDefectSize.end(), m_stDisplayOutput.m_stOutputDiffer.m_fMaxDefectSize.begin());
		}
		m_stDisplayOutput.m_stOutputDiffer.m_pProbImage = pstDiffer->m_pProbImage.clone();
		::LeaveCriticalSection(&m_CriticalSection_ImageBuffer);
	}
	else if (TYPE_STEP_004 == eStep && pstOutput)
	{
		::EnterCriticalSection(&m_CriticalSection_ImageBuffer);
		OUTPUT_BUBBLE* pstBubble = (OUTPUT_BUBBLE*)pstOutput;

		// Clear
		m_stDisplayOutput.m_stOutputBubble.m_pProbImage.release();
		m_stDisplayOutput.m_stOutputBubble.m_fMaxDefectSize.clear();
		// Copy
		m_stDisplayOutput.m_stOutputBubble.m_bResult = pstBubble->m_bResult;

		const int nSize = pstBubble->m_fMaxDefectSize.size();
		if (0 < nSize)
		{
			m_stDisplayOutput.m_stOutputBubble.m_fMaxDefectSize.resize(nSize);
			std::copy(pstBubble->m_fMaxDefectSize.begin(), pstBubble->m_fMaxDefectSize.end(), m_stDisplayOutput.m_stOutputBubble.m_fMaxDefectSize.begin());
		}
		m_stDisplayOutput.m_stOutputBubble.m_pProbImage = pstBubble->m_pProbImage.clone();
		::LeaveCriticalSection(&m_CriticalSection_ImageBuffer);
	}
	else if (TYPE_STEP_005 == eStep && pstOutput)
	{
		::EnterCriticalSection(&m_CriticalSection_ImageBuffer);
		OUTPUT_SCRATCH* pstScratch = (OUTPUT_SCRATCH*)pstOutput;

		// Clear
		m_stDisplayOutput.m_stOutputScratch.m_pProbImage.release();
		m_stDisplayOutput.m_stOutputScratch.m_fMaxDefectSize.clear();
		// Copy
		m_stDisplayOutput.m_stOutputScratch.m_bResult = pstScratch->m_bResult;
		
		const int nSize = pstScratch->m_fMaxDefectSize.size();
		if (0 < nSize){
			m_stDisplayOutput.m_stOutputScratch.m_fMaxDefectSize.resize(nSize);
			std::copy(pstScratch->m_fMaxDefectSize.begin(), pstScratch->m_fMaxDefectSize.end(), m_stDisplayOutput.m_stOutputScratch.m_fMaxDefectSize.begin());
		}
		m_stDisplayOutput.m_stOutputScratch.m_pProbImage = pstScratch->m_pProbImage.clone();
		::LeaveCriticalSection(&m_CriticalSection_ImageBuffer);
	}
	else if (TYPE_STEP_006 == eStep && pstOutput)
	{
		::EnterCriticalSection(&m_CriticalSection_ImageBuffer);
		OUTPUT_STAMP* pstStamp = (OUTPUT_STAMP*)pstOutput;

		// Clear
		m_stDisplayOutput.m_stOutputStamp.m_pProbImage.release();
		m_stDisplayOutput.m_stOutputStamp.m_fMaxDefectSize.clear();
		// Copy
		m_stDisplayOutput.m_stOutputStamp.m_bResult = pstStamp->m_bResult;

		const int nSize = pstStamp->m_fMaxDefectSize.size();
		if (0 < nSize)
		{
			m_stDisplayOutput.m_stOutputStamp.m_fMaxDefectSize.resize(nSize);
			std::copy(pstStamp->m_fMaxDefectSize.begin(), pstStamp->m_fMaxDefectSize.end(), m_stDisplayOutput.m_stOutputStamp.m_fMaxDefectSize.begin());
		}
		m_stDisplayOutput.m_stOutputStamp.m_pProbImage = pstStamp->m_pProbImage.clone();
		::LeaveCriticalSection(&m_CriticalSection_ImageBuffer);
	}
	else
	{
		m_stDisplayOutput.m_eStep = TYPE_STEP_NONE;
	}

	this->Invalidate(FALSE);
	::LeaveCriticalSection(&m_CriticalSection);
}


void CCustomScrollView::ClearStepOutput()
{
	m_stDisplayOutput.m_eStep = TYPE_STEP_NONE;

	// Size
	memset(&(m_stDisplayOutput.m_stOutputSize), 0x00, sizeof(OUTPUT_SIZE));
	memset(&(m_stDisplayOutput.m_stOutputSizeSecond), 0x00, sizeof(OUTPUT_SIZE));
	
	::EnterCriticalSection(&m_CriticalSection_ImageBuffer);
	// Shape
	m_stDisplayOutput.m_stOutputStain.m_bResult = FALSE;
	m_stDisplayOutput.m_stOutputStain.m_pProbImage.release();
	m_stDisplayOutput.m_stOutputStain.m_fMaxDefectSize.clear();

	m_stDisplayOutput.m_stOutputDiffer.m_bResult = FALSE;
	m_stDisplayOutput.m_stOutputDiffer.m_pProbImage.release();
	m_stDisplayOutput.m_stOutputDiffer.m_fMaxDefectSize.clear();

	m_stDisplayOutput.m_stOutputBubble.m_bResult = FALSE;
	m_stDisplayOutput.m_stOutputBubble.m_pProbImage.release();
	m_stDisplayOutput.m_stOutputBubble.m_fMaxDefectSize.clear();

	m_stDisplayOutput.m_stOutputScratch.m_bResult = FALSE;
	m_stDisplayOutput.m_stOutputScratch.m_pProbImage.release();
	m_stDisplayOutput.m_stOutputScratch.m_fMaxDefectSize.clear();

	m_stDisplayOutput.m_stOutputStamp.m_bResult = FALSE;
	m_stDisplayOutput.m_stOutputStamp.m_pProbImage.release();
	m_stDisplayOutput.m_stOutputStamp.m_fMaxDefectSize.clear();
	::LeaveCriticalSection(&m_CriticalSection_ImageBuffer);
}

void CCustomScrollView::SetCameraPos(TYPE_CAMERAPOS ePos)
{
	m_eCameraPos = ePos;
}

void CCustomScrollView::CopyPixelBuffer8Bit(TYPE_STEP eStep, const int w, const int h, const int pitch, void* pvBits)
{
	if (NULL == pvBits)
		return;
	/////
	CUtil::PrintDebugString("CopyPixelBuffer8Bit START : m_eCameraPos[%d], m_stDisplayOutput.m_eStep[%d] \n", m_eCameraPos, m_stDisplayOutput.m_eStep);
	if (TYPE_STEP_001 == eStep || TYPE_STEP_007 == eStep)
	{
		::EnterCriticalSection(&m_CriticalSection_ImageBuffer);
		const OUTPUT_SIZE* pstOutSize = &m_stDisplayOutput.m_stOutputSize;

		const int nSrcW = pstOutSize->m_stCalibratedImage.m_iWidth;
		const int nSrcH = pstOutSize->m_stCalibratedImage.m_iHeight;
		const int nSrcPitch = pstOutSize->m_stCalibratedImage.m_iWidthStep;
		BYTE* pSrc = NULL;
		BYTE* pDest = NULL;

		const int nCopy = min(nSrcPitch, pitch);

		for (int y = 0; y < h; y++)
		{
			pDest = (BYTE*)pvBits + y*pitch;
			pSrc = pstOutSize->m_stCalibratedImage.m_pSrcImage + y * nSrcPitch;

			memcpy(pDest, pSrc, nCopy);
		}

		::LeaveCriticalSection(&m_CriticalSection_ImageBuffer);
	}
	CUtil::PrintDebugString("CopyPixelBuffer8Bit END \n");
	/////
}

void CCustomScrollView::CopyPixelBuffer24Bit(TYPE_STEP eStep, const int w, const int h, const int pitch, void* pvBits)
{
	if (NULL == pvBits)
		return;
	/////
	CUtil::PrintDebugString("CopyPixelBuffer24Bit START : m_eCameraPos[%d], m_stDisplayOutput.m_eStep[%d] \n", m_eCameraPos, m_stDisplayOutput.m_eStep);
	cv::Mat pMat;

	::EnterCriticalSection(&m_CriticalSection_ImageBuffer);
	if (TYPE_STEP_002 == eStep)
	{
		OUTPUT_STAIN* pstOutStain = &m_stDisplayOutput.m_stOutputStain;
		pMat = pstOutStain->m_pProbImage.clone();
	}
	else if (TYPE_STEP_003 == eStep)
	{
		OUTPUT_DIFFER* pstOutDiffer = &m_stDisplayOutput.m_stOutputDiffer;
		pMat = pstOutDiffer->m_pProbImage.clone();
	}
	else if (TYPE_STEP_004 == eStep)
	{
		OUTPUT_BUBBLE* pstOutBubble = &m_stDisplayOutput.m_stOutputBubble;
		pMat = pstOutBubble->m_pProbImage.clone();
	}
	else if (TYPE_STEP_005 == eStep)
	{
		OUTPUT_SCRATCH* pstOutScratch = &m_stDisplayOutput.m_stOutputScratch;
		pMat = pstOutScratch->m_pProbImage.clone();
	}
	else if (TYPE_STEP_006 == eStep)
	{
		OUTPUT_STAMP* pstOutStamp = &m_stDisplayOutput.m_stOutputStamp;
		pMat = pstOutStamp->m_pProbImage.clone();
	}

	if (pMat.data)
	{
		const int nSrcW = pMat.cols;
		const int nSrcH = pMat.rows;
		const int nChannel = pMat.channels();
		const int nSrcPitch = pMat.step;
		BYTE* pSrc = NULL;
		BYTE* pDest = NULL;

		for (int y = 0; y < h; y++)
		{
			pDest = (BYTE*)pvBits + y*pitch;
			pSrc = pMat.data + y * nSrcPitch;
			memcpy(pDest, pSrc, nSrcPitch);
		}
	}
	::LeaveCriticalSection(&m_CriticalSection_ImageBuffer);
	/////
	CUtil::PrintDebugString("CopyPixelBuffer24Bit END \n");
}


void CCustomScrollView::GetLineDistance_d(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
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

void CCustomScrollView::GetLineDistance_L(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
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

void CCustomScrollView::GetLineDistance_W(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
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

void CCustomScrollView::GetLineDistance_I1(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
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

void CCustomScrollView::GetLineDistance_I2(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
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

void CCustomScrollView::GetLineDistance_I3(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
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

void CCustomScrollView::GetLineDistance_M1(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
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

void CCustomScrollView::GetLineDistance_M2(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
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

void CCustomScrollView::GetLineDistance_S1(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
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

void CCustomScrollView::GetLineDistance_S2(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
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

void CCustomScrollView::GetLineDistance_S3(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
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

void CCustomScrollView::GetLineDistance_S4(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
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

void CCustomScrollView::GetLineDistance_S5(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
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

void CCustomScrollView::GetLineDistance_X1(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
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

void CCustomScrollView::GetLineDistance_X2(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
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

void CCustomScrollView::GetLineDistance_R(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
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
void CCustomScrollView::GetLineDistance_SS1(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
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
// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
void CCustomScrollView::GetLineDistance_SS2(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
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
// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
void CCustomScrollView::GetLineDistance_SS3(const OUTPUT_SIZE* pstOutputSize, const int nIdx, INFO_LINE_GDIPLUS& stLineGdiPlus, stPOINT& ptText)
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
