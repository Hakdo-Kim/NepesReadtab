// CustomScrollViewEdit.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "CustomScrollViewEdit.h"

#include "CommonCapture.h"
#include "CaptureManager.h"

#include "Video/ConvertColor.h"
#include "inc/PixelFormat.h"

#include <gdiplus.h>
#pragma comment(lib, "Gdiplus.lib")

// CCustomScrollViewEdit

IMPLEMENT_DYNCREATE(CCustomScrollViewEdit, CScrollView)

CCustomScrollViewEdit::CCustomScrollViewEdit()
{
	::InitializeCriticalSection(&m_CriticalSection);

	m_bFitZoom = TRUE;
	m_fZoom = 1.0f;

	// Insepction
	m_eCameraType = TYPE_CAMERAPOS_NONE;
	m_eStep = TYPE_STEP_NONE;
	m_nTrackerIdxForEdit = -1;

#ifdef USE_BASLER_CAMERA
	m_pColorBuffer = NULL;
	m_nColorBufLen = 0;
#endif

	ClearStepOutput();
}

CCustomScrollViewEdit::~CCustomScrollViewEdit()
{
	::DeleteCriticalSection(&m_CriticalSection);

#ifdef USE_BASLER_CAMERA
	if (m_pColorBuffer)
		delete[] m_pColorBuffer;
	m_pColorBuffer = NULL;
	m_nColorBufLen = 0;
#endif

	ClearImage();
	ClearStepOutput();
}


BEGIN_MESSAGE_MAP(CCustomScrollViewEdit, CScrollView)
	ON_WM_RBUTTONUP()
	ON_WM_CONTEXTMENU()
	ON_WM_ERASEBKGND()
	ON_WM_MOUSEWHEEL()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_SETCURSOR()

	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()

	ON_COMMAND(ID_ZOOM_ZOOMIN, &CCustomScrollViewEdit::OnCommandZoomIn)
	ON_COMMAND(ID_ZOOM_ZOOMOUT, &CCustomScrollViewEdit::OnCommandZoomOut)
	ON_COMMAND(ID_ZOOM_ZOOMFIT, &CCustomScrollViewEdit::OnCommandZoomFit)
	ON_COMMAND(ID_ZOOM_ZOOM100, &CCustomScrollViewEdit::OnCommandZoom100)

	ON_COMMAND(ID_EDIT_GRAB, &CCustomScrollViewEdit::OnCommandGrabEdit)
	ON_COMMAND(ID_STROBE_OFF, &CCustomScrollViewEdit::OnCommandStrobeOff)
	ON_COMMAND(ID_STROBE_COAXIAL, &CCustomScrollViewEdit::OnCommandStrobeCoaxial)
	ON_COMMAND(ID_STROBE_RING, &CCustomScrollViewEdit::OnCommandStrobeRing)
	ON_COMMAND(ID_STROBE_BAR, &CCustomScrollViewEdit::OnCommandStrobeBar)

END_MESSAGE_MAP()


// CCustomScrollViewEdit drawing

void CCustomScrollViewEdit::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	sizeTotal.cx = sizeTotal.cy = 1;
	SetScrollSizes(MM_TEXT, sizeTotal);

	for (int i = 0; i < TYPE_FINDLINE_MAX; i++)
	{
		m_pTrackerFindLine[i].Init(TYPE_TRACKER_RECT_ROTATE);
	}

	m_TrackerStain.Init(TYPE_TRACKER_RECT);
	m_TrackerDiffer.Init(TYPE_TRACKER_RECT);
	m_TrackerBubble.Init(TYPE_TRACKER_RECT);
	m_TrackerScratch.Init(TYPE_TRACKER_RECT);
	m_TrackerStamp.Init(TYPE_TRACKER_RECT);

}

void CCustomScrollViewEdit::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
}


// CCustomScrollViewEdit diagnostics

#ifdef _DEBUG
void CCustomScrollViewEdit::AssertValid() const
{
	CScrollView::AssertValid();
}

#ifndef _WIN32_WCE
void CCustomScrollViewEdit::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif
#endif //_DEBUG


// CCustomScrollViewEdit message handlers
void CCustomScrollViewEdit::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCustomScrollViewEdit::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
	CMenu Menu;
	Menu.LoadMenu(IDR_MENU_POPUPEDIT);

	CMenu* pSubMenu = Menu.GetSubMenu(0);
	if (pSubMenu)
	{
		if (m_bFitZoom)
			pSubMenu->CheckMenuItem(ID_VIEW_ZOOMFIT, MF_CHECKED);
		else if (DEFAULT_ZOOM_FACTOR == m_fZoom)
			pSubMenu->CheckMenuItem(ID_VIEW_ZOOM100, MF_CHECKED);

		pSubMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
	}
	Menu.DestroyMenu();

}

BOOL CCustomScrollViewEdit::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	if (MK_CONTROL & nFlags)
	{
		SetFitZoom(FALSE);

		if (0 > zDelta)
			OnCommandZoomOut();
		else
			OnCommandZoomIn();
	}

	return TRUE;
}

void CCustomScrollViewEdit::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);

	const double fZoom = GetZoom();
	TRACKPOINT stPoint;
	stPoint.m_fx = point.x;
	stPoint.m_fy = point.y;

	if ((TYPE_STEP_001 == m_eStep || TYPE_STEP_007 == m_eStep) && -1 < m_nTrackerIdxForEdit)
	{
		const TYPE_HITTRACKER eHit = m_pTrackerFindLine[m_nTrackerIdxForEdit].GetTrackerHitPosition(stPoint, fZoom);
		if (TYPE_HITTRACKER_NONE == eHit)
			return;

		if (TRUE == m_pTrackerFindLine[m_nTrackerIdxForEdit].Track(&dc, nFlags, stPoint, fZoom))
		{
			const int nLen = m_pTrackerFindLine[m_nTrackerIdxForEdit].GetPoint(NULL, 0);
			LPTRACKPOINT pPoint = new TRACKPOINT[nLen];

			m_pTrackerFindLine[m_nTrackerIdxForEdit].GetPoint(pPoint, nLen);

			INFO_FINDLINE_ROI roi;
			memset(&roi, 0, sizeof(INFO_FINDLINE_ROI));
			roi.m_eTrackerType = m_pTrackerFindLine[m_nTrackerIdxForEdit].GetType();
			if (roi.m_eTrackerType == TYPE_TRACKER_RECT)
			{
				roi.m_stCenterPt.m_fX = static_cast<float>(pPoint[0].m_fx + pPoint[2].m_fx + 0.5);
				roi.m_stCenterPt.m_fY = static_cast<float>(pPoint[0].m_fy + pPoint[2].m_fy + 0.5);
				roi.m_fWidth = static_cast<float>(pPoint[2].m_fx - pPoint[0].m_fx + 1);
				roi.m_fHeight = static_cast<float>(pPoint[2].m_fy - pPoint[0].m_fy + 1);
				roi.m_dAngle = 0;
			}
			if (roi.m_eTrackerType == TYPE_TRACKER_RECT_ROTATE)
			{
				float x = 0, y = 0;
				for (int i = 0; i < nLen; i++)
				{
					x += static_cast<float>(pPoint[i].m_fx);
					y += static_cast<float>(pPoint[i].m_fy);
				}

				roi.m_stCenterPt.m_fX = x / nLen;
				roi.m_stCenterPt.m_fY = y / nLen;
				roi.m_fWidth = sqrt((pPoint[1].m_fx - pPoint[0].m_fx) * (pPoint[1].m_fx - pPoint[0].m_fx) + (pPoint[1].m_fy - pPoint[0].m_fy) * (pPoint[1].m_fy - pPoint[0].m_fy));
				roi.m_fHeight = sqrt((pPoint[3].m_fx - pPoint[0].m_fx) * (pPoint[3].m_fx - pPoint[0].m_fx) + (pPoint[3].m_fy - pPoint[0].m_fy) * (pPoint[3].m_fy - pPoint[0].m_fy));
				roi.m_dAngle = static_cast<double>(atan2(pPoint[3].m_fx - pPoint[0].m_fx, pPoint[3].m_fy - pPoint[0].m_fy)); // CLPTracker::GetAngle 참조
				roi.m_dAngle = 180.0 * roi.m_dAngle / (4.0f * atan(1.0f));
				while (-180.0 >= roi.m_dAngle)
					roi.m_dAngle += 360; // (-180, 180)
			}

			// Update Roi position value...
			CWnd* pWnd = GetParent();
			if (pWnd)
			{
				pWnd->SendMessage(WM_NOTIFY_STEPSIZE_ROI_CHANGED, (WPARAM)&roi, (LPARAM)m_nTrackerIdxForEdit);
			}

			if (pPoint)
			{
				delete[] pPoint;
			}
		}
	}
	else if (TYPE_STEP_002 == m_eStep || TYPE_STEP_003 == m_eStep || TYPE_STEP_004 == m_eStep || TYPE_STEP_005 == m_eStep || TYPE_STEP_006 == m_eStep )
	{
		CLPTracker* pTracker = NULL;
		if (TYPE_STEP_002 == m_eStep)		pTracker = &m_TrackerStain;
		else if (TYPE_STEP_003 == m_eStep)	pTracker = &m_TrackerDiffer;
		else if (TYPE_STEP_004 == m_eStep)	pTracker = &m_TrackerBubble;
		else if (TYPE_STEP_005 == m_eStep)	pTracker = &m_TrackerScratch;
		else if (TYPE_STEP_006 == m_eStep)	pTracker = &m_TrackerStamp;
		else return;

		const TYPE_HITTRACKER eHit = pTracker->GetTrackerHitPosition(stPoint, fZoom);
		if (TYPE_HITTRACKER_NONE == eHit)
			return;

		if (TRUE == pTracker->Track(&dc, nFlags, stPoint, fZoom))
		{
			const int nLen = pTracker->GetPoint(NULL, 0);
			LPTRACKPOINT pPoint = new TRACKPOINT[nLen];
			pTracker->GetPoint(pPoint, nLen);

			INFO_RECT_ROI stRectRoi;
			memset(&stRectRoi, 0x00, sizeof(INFO_RECT_ROI));

			stRectRoi.m_eTrackerType;			
			stRectRoi.m_rtRoi.left = (LONG)pPoint[0].m_fx;
			stRectRoi.m_rtRoi.top = (LONG)pPoint[0].m_fy;
			stRectRoi.m_rtRoi.right = (LONG)pPoint[2].m_fx;
			stRectRoi.m_rtRoi.bottom = (LONG)pPoint[2].m_fy;

			// Update Roi position value...
			CWnd* pWnd = GetParent();
			if (pWnd)
			{
				pWnd->SendMessage(WM_NOTIFY_STEPSIZE_ROI_CHANGED, (WPARAM)&stRectRoi, (LPARAM)0xFF);
			}

			if (pPoint)
			{
				delete[] pPoint;
			}
		}
	}
	else
	{

	}
}

void CCustomScrollViewEdit::OnLButtonUp(UINT nFlags, CPoint point)
{
}



BOOL CCustomScrollViewEdit::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	CClientDC dc(this);

	BOOL bResult = FALSE;
	const double fZoom = GetZoom();
	
	if ((TYPE_STEP_001 == m_eStep || TYPE_STEP_007 == m_eStep) && -1< m_nTrackerIdxForEdit)
	{
		bResult = m_pTrackerFindLine[m_nTrackerIdxForEdit].SetCursor(&dc, (float)fZoom);
	}
	else if (TYPE_STEP_002 == m_eStep || TYPE_STEP_003 == m_eStep || TYPE_STEP_004 == m_eStep || TYPE_STEP_005 == m_eStep || TYPE_STEP_006 == m_eStep)
	{
		CLPTracker* pTracker = NULL;
		if (TYPE_STEP_002 == m_eStep)		pTracker = &m_TrackerStain;
		else if (TYPE_STEP_003 == m_eStep)	pTracker = &m_TrackerDiffer;
		else if (TYPE_STEP_004 == m_eStep)	pTracker = &m_TrackerBubble;
		else if (TYPE_STEP_005 == m_eStep)	pTracker = &m_TrackerScratch;
		else if (TYPE_STEP_006 == m_eStep)	pTracker = &m_TrackerStamp;
		else return TRUE;

		bResult = pTracker->SetCursor(&dc, (float)fZoom);
	}
	
	if (FALSE == bResult)
	{
		bResult = CScrollView::OnSetCursor(pWnd, nHitTest, message);
	}
	return bResult;
}

void CCustomScrollViewEdit::OnMouseMove(UINT nFlags, CPoint point)
{
	CScrollView::OnMouseMove(nFlags, point);
}


void CCustomScrollViewEdit::OnSize(UINT nType, int cx, int cy)
{
	CScrollView::OnSize(nType, cx, cy);

	if (m_bFitZoom)
	{
		this->SetFitZoom(m_bFitZoom);
	}
	UpdateScrollSize();
}

void CCustomScrollViewEdit::OnPaint()
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
		if (TYPE_STEP_NONE == m_stDisplayOutput.m_eStep ||
			TYPE_STEP_001 == m_stDisplayOutput.m_eStep || TYPE_STEP_007 == m_stDisplayOutput.m_eStep ||
			TYPE_STEP_002 == m_stDisplayOutput.m_eStep && m_stDisplayOutput.m_stOutputStain.m_pProbImage.empty() ||
			TYPE_STEP_003 == m_stDisplayOutput.m_eStep && m_stDisplayOutput.m_stOutputDiffer.m_pProbImage.empty() ||
			TYPE_STEP_004 == m_stDisplayOutput.m_eStep && m_stDisplayOutput.m_stOutputBubble.m_pProbImage.empty() ||
			TYPE_STEP_005 == m_stDisplayOutput.m_eStep && m_stDisplayOutput.m_stOutputScratch.m_pProbImage.empty() ||
			TYPE_STEP_006 == m_stDisplayOutput.m_eStep && m_stDisplayOutput.m_stOutputStamp.m_pProbImage.empty())
		{
#ifdef USE_BASLER_CAMERA
			DrawBaslerImage(&MemDC);
#else
			DrawImage8bit(&MemDC);
#endif
		}
		else
		{
#ifdef USE_BASLER_CAMERA
			DrawBaslerImage24bit(&MemDC);
#else
			DrawImage24bit(&MemDC);
#endif
		}

		dc.BitBlt(0, 0, nClientWidth, nClientHeight, &MemDC, 0, 0, SRCCOPY);

		::SelectObject(MemDC.m_hDC, hOldBitmap);
		::DeleteObject(hBitmap);
	}
}

#ifdef USE_BASLER_CAMERA
BOOL CCustomScrollViewEdit::CreateColorBuffer(const INFO_IMAGE* pImage)
{
	if (NULL == pImage)
		return FALSE;

	const INFO_FRAME* pFrame = &pImage->m_stFrame;
	const int nChannel = 3;

	const int nPitch = (nChannel*pImage->m_stFrame.m_dwWidth + 3) / 4 * 4;
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
			ConvertColor(BAYERGR8, pSrc, pDest, pTemp, pFrame->m_dwWidth, pFrame->m_dwHeight);

		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
		if (m_eCameraType == TYPE_CAMERAPOS_FIRST)
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
		else if (m_eCameraType == TYPE_CAMERAPOS_SECOND)
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

void CCustomScrollViewEdit::DrawImage8bit(CDC* pDC)
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

		// Pixel Buffer Copy
		if (TYPE_STEP_NONE == m_stDisplayOutput.m_eStep ||
			TYPE_STEP_002 == m_stDisplayOutput.m_eStep && m_stDisplayOutput.m_stOutputStain.m_pProbImage.empty() ||
			TYPE_STEP_003 == m_stDisplayOutput.m_eStep && m_stDisplayOutput.m_stOutputDiffer.m_pProbImage.empty() ||
			TYPE_STEP_004 == m_stDisplayOutput.m_eStep && m_stDisplayOutput.m_stOutputBubble.m_pProbImage.empty() ||
			TYPE_STEP_005 == m_stDisplayOutput.m_eStep && m_stDisplayOutput.m_stOutputScratch.m_pProbImage.empty() ||
			TYPE_STEP_006 == m_stDisplayOutput.m_eStep && m_stDisplayOutput.m_stOutputStamp.m_pProbImage.empty() )
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

	// Draw Roi
	{
		//double fZoom = 1.0f;
		double fZoom = GetZoom();
		if (TYPE_STEP_001 == m_eStep || TYPE_STEP_007 == m_eStep)
		{
			DrawTrackerForSize(pDC, w, h, fZoom);
		}
		else if (TYPE_STEP_002 == m_eStep || TYPE_STEP_003 == m_eStep || TYPE_STEP_004 == m_eStep || TYPE_STEP_005 == m_eStep || TYPE_STEP_006 == m_eStep)
		{
			DrawTrackerForOther(pDC, w, h, fZoom);
		}


		/// Output Roi
		if (TYPE_STEP_001 == m_stDisplayOutput.m_eStep || TYPE_STEP_007 == m_stDisplayOutput.m_eStep)
		{
			Gdiplus::Graphics graphics(pDC->m_hDC);
			COLORREF rgbLine = RGB(0x00, 0xFF, 0x00);
			COLORREF rgbError = RGB(0xFF, 0x00, 0x00);
			
			Gdiplus::Color clrLine(Gdiplus::Color::MakeARGB(0xFF, GetRValue(rgbLine), GetGValue(rgbLine), GetBValue(rgbLine)));
			Gdiplus::Color clrError(Gdiplus::Color::MakeARGB(0xFF, GetRValue(rgbError), GetGValue(rgbError), GetBValue(rgbError)));
			Gdiplus::REAL width = 2.0f;

			Gdiplus::Pen penLine(clrLine, width);
			Gdiplus::Pen penError(clrError, width);

			int nSelectedIdx = -1;
			for (int i = 0; i < TYPE_FINDLINE_MAX; i++)
			{
				if (m_pTrackerFindLine[i].GetSelectedState())
				{
					nSelectedIdx = i;
					break;
				}
			}

			if (-1 < nSelectedIdx)
			{
				const stLine* pLine = &m_stDisplayOutput.m_stOutputSize.m_stResultLine[nSelectedIdx];

				Gdiplus::REAL x1 = (pLine->m_fStartX - scrlx) * fZoom;
				Gdiplus::REAL y1 = (pLine->m_fStartY - scrly) * fZoom;
				Gdiplus::REAL x2 = (pLine->m_fEndX - scrlx) * fZoom;
				Gdiplus::REAL y2 = (pLine->m_fEndY - scrly) * fZoom;

				graphics.DrawLine(&penLine, x1, y1, x2, y2);
			}
			else
			{
				for (int i = 0; i < TYPE_FINDLINE_MAX; i++)
				{
					const stLine* pLine = &m_stDisplayOutput.m_stOutputSize.m_stResultLine[i];

					Gdiplus::REAL x1 = (pLine->m_fStartX - scrlx) * fZoom;
					Gdiplus::REAL y1 = (pLine->m_fStartY - scrly) * fZoom;
					Gdiplus::REAL x2 = (pLine->m_fEndX - scrlx) * fZoom;
					Gdiplus::REAL y2 = (pLine->m_fEndY - scrly) * fZoom;

					graphics.DrawLine(&penLine, x1, y1, x2, y2);
				}
			}
		}
		//*/

	}
}

void CCustomScrollViewEdit::DrawImage24bit(CDC* pDC)
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
void CCustomScrollViewEdit::DrawBaslerImage(CDC* pDC)
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

		// Pixel Buffer Copy
		if (TYPE_STEP_NONE == m_stDisplayOutput.m_eStep ||
			TYPE_STEP_001 == m_stDisplayOutput.m_eStep || TYPE_STEP_007 == m_stDisplayOutput.m_eStep || // TODO: 이 줄을 제거하고 아래 분기에서 step size의 캘리브레이션 이미지를 사용하도록 재검토
			TYPE_STEP_002 == m_stDisplayOutput.m_eStep && m_stDisplayOutput.m_stOutputStain.m_pProbImage.empty() ||
			TYPE_STEP_003 == m_stDisplayOutput.m_eStep && m_stDisplayOutput.m_stOutputDiffer.m_pProbImage.empty() ||
			TYPE_STEP_004 == m_stDisplayOutput.m_eStep && m_stDisplayOutput.m_stOutputBubble.m_pProbImage.empty() ||
			TYPE_STEP_005 == m_stDisplayOutput.m_eStep && m_stDisplayOutput.m_stOutputScratch.m_pProbImage.empty() ||
			TYPE_STEP_006 == m_stDisplayOutput.m_eStep && m_stDisplayOutput.m_stOutputStamp.m_pProbImage.empty())
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

	// Draw Roi
	{
		//double fZoom = 1.0f;
		double fZoom = GetZoom();
		if (TYPE_STEP_001 == m_eStep || TYPE_STEP_007 == m_eStep)
		{
			DrawTrackerForSize(pDC, nFrameWidth, nFrameHeight, fZoom);
		}
		else if (TYPE_STEP_002 == m_eStep || TYPE_STEP_003 == m_eStep || TYPE_STEP_004 == m_eStep || TYPE_STEP_005 == m_eStep || TYPE_STEP_006 == m_eStep)
		{
			DrawTrackerForOther(pDC, nFrameWidth, nFrameHeight, fZoom);
		}

		/// Output Roi
		if (TYPE_STEP_001 == m_stDisplayOutput.m_eStep || TYPE_STEP_007 == m_stDisplayOutput.m_eStep)
		{
			Gdiplus::Graphics graphics(pDC->m_hDC);
			COLORREF rgbLine = RGB(0x00, 0xFF, 0x00);
			COLORREF rgbError = RGB(0xFF, 0x00, 0x00);

			Gdiplus::Color clrLine(Gdiplus::Color::MakeARGB(0xFF, GetRValue(rgbLine), GetGValue(rgbLine), GetBValue(rgbLine)));
			Gdiplus::Color clrError(Gdiplus::Color::MakeARGB(0xFF, GetRValue(rgbError), GetGValue(rgbError), GetBValue(rgbError)));
			Gdiplus::REAL width = 2.0f;

			Gdiplus::Pen penLine(clrLine, width);
			Gdiplus::Pen penError(clrError, width);

			int nSelectedIdx = -1;
			for (int i = 0; i < TYPE_FINDLINE_MAX; i++)
			{
				if (m_pTrackerFindLine[i].GetSelectedState())
				{
					nSelectedIdx = i;
					break;
				}
			}

			if (-1 < nSelectedIdx)
			{
				const stLine* pLine = &m_stDisplayOutput.m_stOutputSize.m_stResultLine[nSelectedIdx];

				Gdiplus::REAL x1 = (pLine->m_fStartX - scrlx) * fZoom;
				Gdiplus::REAL y1 = (pLine->m_fStartY - scrly) * fZoom;
				Gdiplus::REAL x2 = (pLine->m_fEndX - scrlx) * fZoom;
				Gdiplus::REAL y2 = (pLine->m_fEndY - scrly) * fZoom;

				graphics.DrawLine(&penLine, x1, y1, x2, y2);
			}
			else
			{
				for (int i = 0; i < TYPE_FINDLINE_MAX; i++)
				{
					const stLine* pLine = &m_stDisplayOutput.m_stOutputSize.m_stResultLine[i];

					Gdiplus::REAL x1 = (pLine->m_fStartX - scrlx) * fZoom;
					Gdiplus::REAL y1 = (pLine->m_fStartY - scrly) * fZoom;
					Gdiplus::REAL x2 = (pLine->m_fEndX - scrlx) * fZoom;
					Gdiplus::REAL y2 = (pLine->m_fEndY - scrly) * fZoom;

					graphics.DrawLine(&penLine, x1, y1, x2, y2);
				}
			}
		}
	}

}

void CCustomScrollViewEdit::DrawBaslerImage24bit(CDC* pDC)
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

	// Draw Roi
	{
		//double fZoom = 1.0f;
		double fZoom = GetZoom();
		if (TYPE_STEP_001 == m_eStep || TYPE_STEP_007 == m_eStep)
		{
			DrawTrackerForSize(pDC, nFrameWidth, nFrameHeight, fZoom);
		}
		else if (TYPE_STEP_002 == m_eStep || TYPE_STEP_003 == m_eStep || TYPE_STEP_004 == m_eStep || TYPE_STEP_005 == m_eStep || TYPE_STEP_006 == m_eStep)
		{
			DrawTrackerForOther(pDC, nFrameWidth, nFrameHeight, fZoom);
		}

		/// Output Roi
		if (TYPE_STEP_001 == m_stDisplayOutput.m_eStep || TYPE_STEP_007 == m_stDisplayOutput.m_eStep)
		{
			Gdiplus::Graphics graphics(pDC->m_hDC);
			COLORREF rgbLine = RGB(0x00, 0xFF, 0x00);
			COLORREF rgbError = RGB(0xFF, 0x00, 0x00);

			Gdiplus::Color clrLine(Gdiplus::Color::MakeARGB(0xFF, GetRValue(rgbLine), GetGValue(rgbLine), GetBValue(rgbLine)));
			Gdiplus::Color clrError(Gdiplus::Color::MakeARGB(0xFF, GetRValue(rgbError), GetGValue(rgbError), GetBValue(rgbError)));
			Gdiplus::REAL width = 2.0f;

			Gdiplus::Pen penLine(clrLine, width);
			Gdiplus::Pen penError(clrError, width);

			int nSelectedIdx = -1;
			for (int i = 0; i < TYPE_FINDLINE_MAX; i++)
			{
				if (m_pTrackerFindLine[i].GetSelectedState())
				{
					nSelectedIdx = i;
					break;
				}
			}

			if (-1 < nSelectedIdx)
			{
				const stLine* pLine = &m_stDisplayOutput.m_stOutputSize.m_stResultLine[nSelectedIdx];

				Gdiplus::REAL x1 = (pLine->m_fStartX - scrlx) * fZoom;
				Gdiplus::REAL y1 = (pLine->m_fStartY - scrly) * fZoom;
				Gdiplus::REAL x2 = (pLine->m_fEndX - scrlx) * fZoom;
				Gdiplus::REAL y2 = (pLine->m_fEndY - scrly) * fZoom;

				graphics.DrawLine(&penLine, x1, y1, x2, y2);
			}
			else
			{
				for (int i = 0; i < TYPE_FINDLINE_MAX; i++)
				{
					const stLine* pLine = &m_stDisplayOutput.m_stOutputSize.m_stResultLine[i];

					Gdiplus::REAL x1 = (pLine->m_fStartX - scrlx) * fZoom;
					Gdiplus::REAL y1 = (pLine->m_fStartY - scrly) * fZoom;
					Gdiplus::REAL x2 = (pLine->m_fEndX - scrlx) * fZoom;
					Gdiplus::REAL y2 = (pLine->m_fEndY - scrly) * fZoom;

					graphics.DrawLine(&penLine, x1, y1, x2, y2);
				}
			}
		}
	}

}
#endif

void CCustomScrollViewEdit::DrawTrackerForSize(CDC* pDC, const int w, const int h, const double fZoom)
{
	if (NULL == pDC)
		return;

	COLORREF rgb = RGB(0, 0, 255);

	INFO_RESERVEDROI stReserved;
	memset(&stReserved, 0x00, sizeof(INFO_RESERVEDROI));
	stReserved.m_hOutLine = ::CreatePen(PS_SOLID, 2, rgb);
	stReserved.m_rgbOutLine = rgb;
	stReserved.m_dwOutLine = 2;

	SIZE stSize;
	stSize.cx = w;
	stSize.cy = h;

	for (int i = 0; i < TYPE_FINDLINE_MAX; i++)
	{
		if (m_pTrackerFindLine[i].GetSelectedState())
		{
			m_pTrackerFindLine[i].Draw(pDC, fZoom);
		}
		/*//
		else
		{
			TYPE_TRACKER eType = m_pTrackerFindLine[i].GetType();

			int nPtLen = m_pTrackerFindLine[i].GetPoint(NULL, 0);
			if (1 > nPtLen)
				continue;

			LPTRACKPOINT pPoint = new TRACKPOINT[nPtLen];
			if (pPoint)
			{
				memset(pPoint, 0x00, sizeof(TRACKPOINT) * nPtLen);

				m_pTrackerFindLine[i].GetPoint(pPoint, nPtLen);

				CLPTracker tracker(this);
				tracker.Draw(pDC, eType, pPoint, nPtLen, stSize, fZoom, &stReserved);

				delete[] pPoint;
				pPoint = NULL;
			}
		}
		//*/
	}

	if (stReserved.m_hOutLine)
		::DeleteObject(stReserved.m_hOutLine);
	stReserved.m_hOutLine = NULL;

}

void CCustomScrollViewEdit::DrawTrackerForOther(CDC* pDC, const int w, const int h, const double fZoom)
{
	if (NULL == pDC)
		return;

	CLPTracker* pTracker = NULL;
	if (TYPE_STEP_002 == m_eStep)		pTracker = &m_TrackerStain;
	else if (TYPE_STEP_003 == m_eStep)	pTracker = &m_TrackerDiffer;
	else if (TYPE_STEP_004 == m_eStep)	pTracker = &m_TrackerBubble;
	else if (TYPE_STEP_005 == m_eStep)	pTracker = &m_TrackerScratch;
	else if (TYPE_STEP_006 == m_eStep)	pTracker = &m_TrackerStamp;
	else return;

	pTracker->Draw(pDC, fZoom);

}



void CCustomScrollViewEdit::UpdateScrollSize()
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

void CCustomScrollViewEdit::CopyPixelBuffer8Bit(TYPE_STEP eStep, const int w, const int h, const int pitch, void* pvBits)
{
	if (NULL == pvBits)
		return;

	if (TYPE_STEP_001 == eStep || TYPE_STEP_007 == eStep)
	{
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
	}
}

void CCustomScrollViewEdit::CopyPixelBuffer24Bit(TYPE_STEP eStep, const int w, const int h, const int pitch, void* pvBits)
{
	if (NULL == pvBits)
		return;

	cv::Mat* pMat = NULL;

	if (TYPE_STEP_002 == eStep)
	{
		OUTPUT_STAIN* pstOutStain = &m_stDisplayOutput.m_stOutputStain;
		pMat = &pstOutStain->m_pProbImage;
	}
	else if (TYPE_STEP_003 == eStep)
	{
		OUTPUT_DIFFER* pstOutDiffer = &m_stDisplayOutput.m_stOutputDiffer;
		pMat = &pstOutDiffer->m_pProbImage;
	}
	else if (TYPE_STEP_004 == eStep)
	{
		OUTPUT_BUBBLE* pstOutBubble = &m_stDisplayOutput.m_stOutputBubble;
		pMat = &pstOutBubble->m_pProbImage;
	}
	else if (TYPE_STEP_005 == eStep)
	{
		OUTPUT_SCRATCH* pstOutScratch = &m_stDisplayOutput.m_stOutputScratch;
		pMat = &pstOutScratch->m_pProbImage;
	}
	else if (TYPE_STEP_006 == eStep)
	{
		OUTPUT_STAMP* pstOutStamp = &m_stDisplayOutput.m_stOutputStamp;
		pMat = &pstOutStamp->m_pProbImage;
	}

	if (pMat)
	{
		const int nSrcW = pMat->cols;
		const int nSrcH = pMat->rows;
		const int nChannel = pMat->channels();
		const int nSrcPitch = pMat->step;
		BYTE* pSrc = NULL;
		BYTE* pDest = NULL;

		for (int y = 0; y < h; y++)
		{
			pDest = (BYTE*)pvBits + y*pitch;
			pSrc = pMat->data + y * nSrcPitch;

			memcpy(pDest, pSrc, nSrcPitch);
		}
	}

}



void CCustomScrollViewEdit::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CScrollView::OnHScroll(nSBCode, nPos, pScrollBar);
	this->Invalidate(FALSE);
}

void CCustomScrollViewEdit::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CScrollView::OnVScroll(nSBCode, nPos, pScrollBar);
	this->Invalidate(FALSE);
}


// Command Function - Zoom
void  CCustomScrollViewEdit::OnCommandZoomIn()
{
	CWnd* pWnd = this->GetParent();
	if (pWnd)
	{
		double fZoom = GetZoom();
		if (m_bFitZoom)
			fZoom += (INC_ZOOM_FACTOR * 2);
		else
			fZoom += (INC_ZOOM_FACTOR + 0.000015);

		if (MAX_ZOOM_FACTOR < fZoom)
			fZoom = MAX_ZOOM_FACTOR;
		if (MIN_ZOOM_FACTOR > fZoom)
			fZoom = MIN_ZOOM_FACTOR;

		{
			int temp = (int)(fZoom * 100);
			fZoom = temp / 100.0;
		}

		SetFitZoom(FALSE);
		SetZoom(fZoom);

		UpdateScrollSize();
	}
}

void  CCustomScrollViewEdit::OnCommandZoomOut()
{
	CWnd* pWnd = this->GetParent();
	if (pWnd)
	{
		double fZoom = GetZoom();
		if (m_bFitZoom)
			fZoom -= (INC_ZOOM_FACTOR * 2);
		else
			fZoom -= INC_ZOOM_FACTOR;

		if (MAX_ZOOM_FACTOR < fZoom)
			fZoom = MAX_ZOOM_FACTOR;
		if (MIN_ZOOM_FACTOR > fZoom)
			fZoom = MIN_ZOOM_FACTOR;

		{
			int temp = (int)(fZoom * 100);
			fZoom = temp / 100.0;
		}

		SetFitZoom(FALSE);
		SetZoom(fZoom);

		UpdateScrollSize();
	}
}

void  CCustomScrollViewEdit::OnCommandZoomFit()
{
	CWnd* pWnd = this->GetParent();
	if (pWnd)
	{
		SetFitZoom(TRUE);
		UpdateScrollSize();
	}
}

void  CCustomScrollViewEdit::OnCommandZoom100()
{
	CWnd* pWnd = this->GetParent();
	if (pWnd)
	{
		SetFitZoom(FALSE);
		SetZoom(1.0f);
		UpdateScrollSize();
	}
}


void CCustomScrollViewEdit::OnCommandGrabEdit()
{
	TYPE_STEP eStep = m_stDisplayOutput.m_eStep;
	if (TYPE_STEP_002 == eStep)
	{
		m_stDisplayOutput.m_stOutputStain.m_pProbImage.release();
	}
	else if (TYPE_STEP_003 == eStep)
	{
		m_stDisplayOutput.m_stOutputDiffer.m_pProbImage.release();
	}
	else if (TYPE_STEP_004 == eStep)
	{
		m_stDisplayOutput.m_stOutputBubble.m_pProbImage.release();
	}
	else if (TYPE_STEP_005 == eStep)
	{
		m_stDisplayOutput.m_stOutputScratch.m_pProbImage.release();
	}
	else if (TYPE_STEP_006 == eStep)
	{
		m_stDisplayOutput.m_stOutputStamp.m_pProbImage.release();
	}

	CWnd* pWnd = this->GetParent();
	if (pWnd)
	{
		pWnd->SendMessage(WM_NOTIFY_GRABEDIT);
	}
}

void CCustomScrollViewEdit::OnCommandStrobeOff()
{
	CWnd* pWnd = this->GetParent();
	if (pWnd)
	{
		WPARAM wParam = 0;
		LPARAM lParam = TYPE_STROBE_OFF;
		pWnd->SendMessage(WM_NOTIFY_STROBE, wParam, lParam);
	}

}

void CCustomScrollViewEdit::OnCommandStrobeCoaxial()
{
	CWnd* pWnd = this->GetParent();
	if (pWnd)
	{
		WPARAM wParam = 0;
		LPARAM lParam = TYPE_STROBE_COXIAL;
		pWnd->SendMessage(WM_NOTIFY_STROBE, wParam, lParam);
	}
}

void CCustomScrollViewEdit::OnCommandStrobeRing()
{
	CWnd* pWnd = this->GetParent();
	if (pWnd)
	{
		WPARAM wParam = 0;
		LPARAM lParam = TYPE_STROBE_RING;
		pWnd->SendMessage(WM_NOTIFY_STROBE, wParam, lParam);
	}
}

void CCustomScrollViewEdit::OnCommandStrobeBar()
{
	CWnd* pWnd = this->GetParent();
	if (pWnd)
	{
		WPARAM wParam = 0;
		LPARAM lParam = TYPE_STROBE_BAR;
		pWnd->SendMessage(WM_NOTIFY_STROBE, wParam, lParam);
	}
}



void CCustomScrollViewEdit::DisplayImage(const INFO_IMAGE* pstImage)
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
				return;
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
			m_pstDisplayImage->m_nBufLen = m_nColorBufLen;
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

#ifdef USE_BASLER_CAMERA
void CCustomScrollViewEdit::DisplayEditImage(const INFO_IMAGE* pstImage)
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
		// Check Buffer Length
		if (NULL != m_pstDisplayImage && m_pstDisplayImage->m_nBufLen != pstImage->m_nBufLen)
			ClearImage();

		BOOL bUpdateScroll = FALSE;

		// Display Image
		if (NULL == m_pstDisplayImage)
		{
			m_pstDisplayImage = new INFO_IMAGE;
			memset(m_pstDisplayImage, 0x00, sizeof(INFO_IMAGE));

			m_pstDisplayImage->m_nBufLen = pstImage->m_nBufLen;
			m_pstDisplayImage->m_pBuffer = new BYTE[m_pstDisplayImage->m_nBufLen];

			bUpdateScroll = TRUE;
		}

		m_pstDisplayImage->m_stFrame = pstImage->m_stFrame;
		m_pstDisplayImage->m_nLen = pstImage->m_nLen;
		memcpy(m_pstDisplayImage->m_pBuffer, pstImage->m_pBuffer, pstImage->m_nLen);

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
#endif


void CCustomScrollViewEdit::ClearImage()
{
	if (m_pstDisplayImage)
	{
		if (m_pstDisplayImage->m_pBuffer)
			delete[] m_pstDisplayImage->m_pBuffer;

		delete m_pstDisplayImage;
	}
	m_pstDisplayImage = NULL;
}

INFO_IMAGE* CCustomScrollViewEdit::GetImage()
{
	return m_pstDisplayImage;
}

const double CCustomScrollViewEdit::GetZoom()
{
	return m_fZoom;
}

void CCustomScrollViewEdit::SetZoom(double fZoom)
{
	m_fZoom = fZoom;
}

void CCustomScrollViewEdit::SetFitZoom(BOOL bFit)
{
	m_bFitZoom = bFit;
	if (m_bFitZoom)
	{
		double fFitZoom = GetFitZoom();
		SetZoom(fFitZoom);
	}
}

const double CCustomScrollViewEdit::GetFitZoom()
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


void CCustomScrollViewEdit::SetDisplayStep(TYPE_CAMERAPOS eCameraType, TYPE_STEP eStep)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	m_eCameraType = eCameraType;
	m_eStep = eStep;

	if (TYPE_STEP_001 == m_eStep || TYPE_STEP_007 == m_eStep)
		SetDisplayStepSize();
	else if (TYPE_STEP_002 == m_eStep || TYPE_STEP_003 == m_eStep || TYPE_STEP_004 == m_eStep || TYPE_STEP_005 == m_eStep || TYPE_STEP_006 == m_eStep)
		SetDisplayStepOther(m_eStep);

	this->Invalidate(FALSE);
}

void CCustomScrollViewEdit::GetDisplayStep(TYPE_CAMERAPOS& eCameraType, TYPE_STEP& eStep)
{
	eCameraType = m_eCameraType;
	eStep = m_eStep;
}

void CCustomScrollViewEdit::SetDisplayStepSize()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	CInspection* pInspection = pCaptureManager->GetInspection();
	CStep* pStep = pInspection->GetInsectionStep(m_eCameraType, m_eStep);

	CStepSize* pStepSize = dynamic_cast<CStepSize*>(pStep);
	if (pStepSize)
	{
		const double fZoom = GetZoom();
		const INFO_INSPECTION_SIZE* pSizeInfo = pStepSize->GetInformation();
		const OUTPUT_ROI *roi = pStepSize->GetCurruntROIPoint();

		for (int i = 0; i < TYPE_FINDLINE_MAX; i++)
		{
			int nPtLen = 4;
			LPTRACKPOINT ptList = NULL;

			RECT rtPos;
			int idx = 0;

#if 0
			// INFO_INSPECTION_SIZE의 ROI 정보를 직접 사용하는 코드
			switch (pSizeInfo->m_pstFindLineROI[i].m_eTrackerType)
			{
			case TYPE_TRACKER_RECT:
				nPtLen = 4;
				ptList = new TRACKPOINT[nPtLen];

				rtPos.left = pSizeInfo->m_pstFindLineROI[i].m_stCenterPt.m_fX - pSizeInfo->m_pstFindLineROI[i].m_fWidth / 2;
				rtPos.top = pSizeInfo->m_pstFindLineROI[i].m_stCenterPt.m_fY - pSizeInfo->m_pstFindLineROI[i].m_fHeight / 2;
				rtPos.right = pSizeInfo->m_pstFindLineROI[i].m_stCenterPt.m_fX + pSizeInfo->m_pstFindLineROI[i].m_fWidth / 2;
				rtPos.bottom = pSizeInfo->m_pstFindLineROI[i].m_stCenterPt.m_fY + pSizeInfo->m_pstFindLineROI[i].m_fHeight / 2;

				ptList[idx].m_fx = rtPos.left;
				ptList[idx].m_fy = rtPos.top;
				idx++;

				ptList[idx].m_fx = rtPos.right;
				ptList[idx].m_fy = rtPos.top;
				idx++;

				ptList[idx].m_fx = rtPos.right;
				ptList[idx].m_fy = rtPos.bottom;
				idx++;

				ptList[idx].m_fx = rtPos.left;
				ptList[idx].m_fy = rtPos.bottom;
				idx++;

				break;
			case TYPE_TRACKER_RECT_ROTATE:
				nPtLen = 4;
				ptList = new TRACKPOINT[nPtLen];

				TRACKPOINT ptCenter;
				TRACKPOINT pt1;
				TRACKPOINT pt2;

				ptCenter.m_fx = pSizeInfo->m_pstFindLineROI[i].m_stCenterPt.m_fX;
				ptCenter.m_fy = pSizeInfo->m_pstFindLineROI[i].m_stCenterPt.m_fY;
				pt1.m_fx = pSizeInfo->m_pstFindLineROI[i].m_fWidth / 2;
				pt1.m_fy = 0;
				pt2.m_fx = 0;
				pt2.m_fy = pSizeInfo->m_pstFindLineROI[i].m_fHeight / 2;

				pt1.m_fx = pt1.m_fx * cos(-1 * pSizeInfo->m_pstFindLineROI[i].m_dAngle * LP_PI / 180.0);
				pt1.m_fy = pt1.m_fx * sin(-1 * pSizeInfo->m_pstFindLineROI[i].m_dAngle * LP_PI / 180.0);
				pt2.m_fx = pt2.m_fy * -1 * sin(-1 * pSizeInfo->m_pstFindLineROI[i].m_dAngle * LP_PI / 180.0);
				pt2.m_fy = pt2.m_fy * cos(-1 * pSizeInfo->m_pstFindLineROI[i].m_dAngle * LP_PI / 180.0);

				ptList[idx].m_fx = ptCenter.m_fx - pt1.m_fx - pt2.m_fx;
				ptList[idx].m_fy = ptCenter.m_fy - pt1.m_fy - pt2.m_fy;
				idx++;

				ptList[idx].m_fx = ptCenter.m_fx + pt1.m_fx - pt2.m_fx;
				ptList[idx].m_fy = ptCenter.m_fy + pt1.m_fy - pt2.m_fy;
				idx++;

				ptList[idx].m_fx = ptCenter.m_fx + pt1.m_fx + pt2.m_fx;
				ptList[idx].m_fy = ptCenter.m_fy + pt1.m_fy + pt2.m_fy;
				idx++;

				ptList[idx].m_fx = ptCenter.m_fx - pt1.m_fx + pt2.m_fx;
				ptList[idx].m_fy = ptCenter.m_fy - pt1.m_fy + pt2.m_fy;
				idx++;
			default:
				break;
			}
#else
			// StepSize의 마지막 Process의 상대 ROI 정보를 이용하는 코드
			switch (pSizeInfo->m_pstFindLineROI[i].m_eTrackerType)
			{
			case TYPE_TRACKER_RECT: // 사용되지 않음
				nPtLen = 4;
				ptList = new TRACKPOINT[nPtLen];

				rtPos.left = pSizeInfo->m_pstFindLineROI[i].m_stCenterPt.m_fX - pSizeInfo->m_pstFindLineROI[i].m_fWidth / 2;
				rtPos.top = pSizeInfo->m_pstFindLineROI[i].m_stCenterPt.m_fY - pSizeInfo->m_pstFindLineROI[i].m_fHeight / 2;
				rtPos.right = pSizeInfo->m_pstFindLineROI[i].m_stCenterPt.m_fX + pSizeInfo->m_pstFindLineROI[i].m_fWidth / 2;
				rtPos.bottom = pSizeInfo->m_pstFindLineROI[i].m_stCenterPt.m_fY + pSizeInfo->m_pstFindLineROI[i].m_fHeight / 2;

				ptList[idx].m_fx = rtPos.left;
				ptList[idx].m_fy = rtPos.top;
				idx++;

				ptList[idx].m_fx = rtPos.right;
				ptList[idx].m_fy = rtPos.top;
				idx++;

				ptList[idx].m_fx = rtPos.right;
				ptList[idx].m_fy = rtPos.bottom;
				idx++;

				ptList[idx].m_fx = rtPos.left;
				ptList[idx].m_fy = rtPos.bottom;
				idx++;

				break;
			case TYPE_TRACKER_RECT_ROTATE:
				nPtLen = 4;
				ptList = new TRACKPOINT[nPtLen];

				ptList[idx].m_fx = roi[i].m_pt[idx].m_fX;
				ptList[idx].m_fy = roi[i].m_pt[idx].m_fY;
				idx++;

				ptList[idx].m_fx = roi[i].m_pt[idx].m_fX;
				ptList[idx].m_fy = roi[i].m_pt[idx].m_fY;
				idx++;

				ptList[idx].m_fx = roi[i].m_pt[idx].m_fX;
				ptList[idx].m_fy = roi[i].m_pt[idx].m_fY;
				idx++;

				ptList[idx].m_fx = roi[i].m_pt[idx].m_fX;
				ptList[idx].m_fy = roi[i].m_pt[idx].m_fY;
				idx++;
			default:
				break;
			}
#endif

			m_pTrackerFindLine[i].Init(pSizeInfo->m_pstFindLineROI[i].m_eTrackerType, this);
			m_pTrackerFindLine[i].SetPoint(ptList, nPtLen, fZoom);

			if (ptList) delete[] ptList;
		}
	}
}

void CCustomScrollViewEdit::SetDisplayStepOther(TYPE_STEP eStep)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();
	CStep* pStep = pInspection->GetInsectionStep(m_eCameraType, m_eStep);

	CLPTracker* pTracker = NULL;
	INFO_RECT_ROI stRectRoi;
	memset(&stRectRoi, 0x00, sizeof(INFO_RECT_ROI));

	CStepStain* pStepStain = dynamic_cast<CStepStain*>(pStep);
	if (pStepStain)
	{
		pTracker = &m_TrackerStain;
		stRectRoi = pStepStain->GetInformation()->m_stRoi;
	}
	CStepDiffer* pStepDiffer = dynamic_cast<CStepDiffer*>(pStep);
	if (pStepDiffer)
	{
		pTracker = &m_TrackerDiffer;
		stRectRoi = pStepDiffer->GetInformation()->m_stRoi;
	}
	CStepBubble* pStepBubble = dynamic_cast<CStepBubble*>(pStep);
	if (pStepBubble)
	{
		pTracker = &m_TrackerBubble;
		stRectRoi = pStepBubble->GetInformation()->m_stRoi;
	}
	CStepScratch* pStepScratch = dynamic_cast<CStepScratch*>(pStep);
	if (pStepScratch)
	{
		pTracker = &m_TrackerScratch;
		stRectRoi = pStepScratch->GetInformation()->m_stRoi;
	}
	CStepStamp* pStepStamp = dynamic_cast<CStepStamp*>(pStep);
	if (pStepStamp)
	{
		pTracker = &m_TrackerStamp;
		stRectRoi = pStepStamp->GetInformation()->m_stRoi;
	}

	if (pTracker)
	{
		const double fZoom = GetZoom();

		TRACKPOINT pPointList[4];

		// Left Top;
		pPointList[0].m_fx = stRectRoi.m_rtRoi.left;
		pPointList[0].m_fy = stRectRoi.m_rtRoi.top;
		// Right Top;
		pPointList[1].m_fx = stRectRoi.m_rtRoi.right;
		pPointList[1].m_fy = stRectRoi.m_rtRoi.top;
		// Right Bottom
		pPointList[2].m_fx = stRectRoi.m_rtRoi.right;
		pPointList[2].m_fy = stRectRoi.m_rtRoi.bottom;
		// Left Bottom;
		pPointList[3].m_fx = stRectRoi.m_rtRoi.left;
		pPointList[3].m_fy = stRectRoi.m_rtRoi.bottom;

		pTracker->Init(TYPE_TRACKER_RECT, this);
		pTracker->SetPoint(pPointList, 4, fZoom);
	}

}


void CCustomScrollViewEdit::SelectSteSizeRoi(int nCur)
{
	m_nTrackerIdxForEdit = nCur;

	if (TYPE_FINDLINE_MAX > nCur && -1 < nCur)
	{
		m_pTrackerFindLine[nCur].SetSelectedState(TRUE);
	}
	else
	{
		for (int i = 0; i < TYPE_FINDLINE_MAX; i++)
		{
			m_pTrackerFindLine[i].SetSelectedState(FALSE);
		}
	}

	this->Invalidate(FALSE);
}

void CCustomScrollViewEdit::DisplayStepOutput(TYPE_STEP eStep, void* pstOutput)
{
	const double fZoom = this->GetZoom();

	m_stDisplayOutput.m_eStep = eStep;
	if (TYPE_STEP_001 == eStep || TYPE_STEP_002 == eStep || TYPE_STEP_003 == eStep ||
		TYPE_STEP_004 == eStep || TYPE_STEP_005 == eStep || TYPE_STEP_006 == eStep ||
		TYPE_STEP_007 == eStep)
	{
		if ((TYPE_STEP_001 == eStep || TYPE_STEP_007 == eStep) && pstOutput)
		{
			OUTPUT_SIZE* pstSize = (OUTPUT_SIZE*)pstOutput;
			memcpy(&m_stDisplayOutput.m_stOutputSize, pstSize, sizeof(OUTPUT_SIZE));

			TRACKPOINT pPtTrack[4];
			memset(pPtTrack, 0x00, sizeof(TRACKPOINT) * 4);

			// Update Roi
			for (int i = 0; i < TYPE_FINDLINE_MAX; i++)
			{
				pPtTrack[0].m_fx = pstSize->m_stROIPoint[i].m_pt[0].m_fX;
				pPtTrack[0].m_fy = pstSize->m_stROIPoint[i].m_pt[0].m_fY;

				pPtTrack[1].m_fx = pstSize->m_stROIPoint[i].m_pt[1].m_fX;
				pPtTrack[1].m_fy = pstSize->m_stROIPoint[i].m_pt[1].m_fY;

				pPtTrack[2].m_fx = pstSize->m_stROIPoint[i].m_pt[2].m_fX;
				pPtTrack[2].m_fy = pstSize->m_stROIPoint[i].m_pt[2].m_fY;

				pPtTrack[3].m_fx = pstSize->m_stROIPoint[i].m_pt[3].m_fX;
				pPtTrack[3].m_fy = pstSize->m_stROIPoint[i].m_pt[3].m_fY;

				m_pTrackerFindLine[i].SetPoint(pPtTrack, 4, fZoom);
			}

		}
		else if (TYPE_STEP_002 == eStep && pstOutput)
		{
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
		}
		else if (TYPE_STEP_003 == eStep && pstOutput)
		{
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
		}
		else if (TYPE_STEP_004 == eStep && pstOutput)
		{
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
		}
		else if (TYPE_STEP_005 == eStep && pstOutput)
		{
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

		}
		else if (TYPE_STEP_006 == eStep && pstOutput)
		{
			OUTPUT_STAMP* pstStamp = (OUTPUT_STAMP*)pstOutput;

			// Clear
			m_stDisplayOutput.m_stOutputStamp.m_pProbImage.release();
			m_stDisplayOutput.m_stOutputStamp.m_fMaxDefectSize.clear();
			// Copy
			m_stDisplayOutput.m_stOutputStamp.m_bResult = pstStamp->m_bResult;

			const int nSize = pstStamp->m_fMaxDefectSize.size();
			if (0 < nSize){
				m_stDisplayOutput.m_stOutputStamp.m_fMaxDefectSize.resize(nSize);
				std::copy(pstStamp->m_fMaxDefectSize.begin(), pstStamp->m_fMaxDefectSize.end(), m_stDisplayOutput.m_stOutputStamp.m_fMaxDefectSize.begin());
			}
			m_stDisplayOutput.m_stOutputStamp.m_pProbImage = pstStamp->m_pProbImage.clone();
		}
	}
	else
	{
		m_stDisplayOutput.m_eStep = TYPE_STEP_NONE;
	}

	this->Invalidate(FALSE);
}

void CCustomScrollViewEdit::GetDisplayStepOutput(TYPE_STEP& eStep)
{
	eStep = m_stDisplayOutput.m_eStep;
}

void CCustomScrollViewEdit::ClearStepOutput()
{
	m_stDisplayOutput.m_eStep = TYPE_STEP_NONE;

	// Size
	memset(&(m_stDisplayOutput.m_stOutputSize), 0x00, sizeof(OUTPUT_SIZE));

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


}