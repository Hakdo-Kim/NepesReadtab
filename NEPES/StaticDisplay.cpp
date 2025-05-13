#include "stdafx.h"
#include "StaticDisplay.h"

#include "inc/PixelFormat.h"
#include "Util/Util.h"


IMPLEMENT_DYNAMIC(CStaticDisplay, CStatic)

CStaticDisplay::CStaticDisplay()
{
	::InitializeCriticalSection(&m_CriticalSection);
	::InitializeCriticalSection(&m_CriticalSectionPaint);

	memset(&m_stVideo, 0x00, sizeof(INFO_VIDEO));
	m_fZoom = 1.0f;
	m_bkColor = RGB(0, 0, 0);

	m_bClearDevice = TRUE;
	m_ePosType = TYPE_CAMERAPOS_NONE;
}

CStaticDisplay::~CStaticDisplay()
{
	::DeleteCriticalSection(&m_CriticalSection);
	::DeleteCriticalSection(&m_CriticalSectionPaint);
	this->Deinit();
}

BOOL CStaticDisplay::DisplayVideoDevice(const INFO_IMAGE* pstImage, const DWORD dwCurFlag, const INFO_CAPTURE_PROCESS* pstCapture)
{
	if (NULL == pstImage )
		return FALSE;
	::EnterCriticalSection(&m_CriticalSection);
	m_bClearDevice = FALSE;

	if (FALSE == IsEnableVideo() || FALSE == CheckVideoDevice(pstImage))
	{
		// Deinit
		this->Deinit();

		// Init
		BOOL bResult = Init(pstImage);
		if (!bResult)
			return FALSE;
	}
	this->Blt(m_stVideo.m_stFrameDC, pstImage);
	CUtil::PumpMessage();

	if (pstCapture && pstCapture->m_bStart)
	{
		this->Invalidate();
	}
	else
	{
		this->Invalidate();
		CUtil::WaitnSleep(WAIT_DISPLAY);
	}
	::LeaveCriticalSection(&m_CriticalSection);
	return TRUE;
}

void CStaticDisplay::ClearVideoDevice()
{
	m_bClearDevice = TRUE;
	this->Invalidate();
}

BOOL CStaticDisplay::IsClearVideoDevice()
{
	return m_bClearDevice;
}

BEGIN_MESSAGE_MAP(CStaticDisplay, CStatic)
	ON_WM_SIZE()
	ON_WM_PAINT()
END_MESSAGE_MAP()

void CStaticDisplay::OnSize(UINT nType, int cx, int cy)
{
	CStatic::OnSize(nType, cx, cy);

	const float fZoom = this->CalcFitZoom();
	this->SetZoom(fZoom);

	this->Invalidate();
}

void CStaticDisplay::OnPaint()
{
	// Validate Window
	CRect rect;
	GetClientRect(&rect);

	if (FALSE == IsEnableVideo())
	{
		this->ValidateRect(&rect);
		return;
	}

	::EnterCriticalSection(&m_CriticalSectionPaint);
	{
		HDC hDC = m_stVideo.m_hDC;
		HDC hMemDC = ::CreateCompatibleDC(hDC);
		if (NULL == hMemDC)
		{
			if (m_bClearDevice)
			{
				CPaintDC dc(this);
				dc.FillSolidRect(&rect, m_bkColor);
			}
			::LeaveCriticalSection(&m_CriticalSectionPaint);
			return;
		}

		this->ValidateRect(&rect);

		const int width = rect.Width();
		const int height = rect.Height();

		HBITMAP hBitmap;       // bitmap handle 
		BITMAPINFO bmi;        // bitmap header 
		VOID *pvBits;          // pointer to DIB section 

		ZeroMemory(&bmi, sizeof(BITMAPINFO));
		bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		bmi.bmiHeader.biWidth = width;
		bmi.bmiHeader.biHeight = -height;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biBitCount = 32;
		bmi.bmiHeader.biCompression = BI_RGB;
		bmi.bmiHeader.biSizeImage = width * height * 4;

		hBitmap = CreateDIBSection(hMemDC, &bmi, DIB_RGB_COLORS, &pvBits, NULL, 0x0);
		if (hBitmap)
		{
			HBITMAP hOldBitmap = (HBITMAP)::SelectObject(hMemDC, hBitmap);
			{
				HBRUSH hBrush = ::CreateSolidBrush(m_bkColor);
				HBRUSH hOldBrush = (HBRUSH)::SelectObject(hMemDC, hBrush);

				::FillRect(hMemDC, &rect, hBrush);
				::SelectObject(hMemDC, hOldBrush);
				::DeleteObject(hBrush);
			}
			if (FALSE == m_bClearDevice)
			{
				RedrawVideoDevice(hMemDC);
			}
			::BitBlt(hDC, 0, 0, width, height, hMemDC, 0, 0, SRCCOPY);

			::SelectObject(hMemDC, hOldBitmap);
			::DeleteObject(hBitmap);
		}
		::DeleteDC(hMemDC);
	}
	::LeaveCriticalSection(&m_CriticalSectionPaint);
}

void CStaticDisplay::RedrawVideoDevice(HDC hViewDC)
{
	if (FALSE == IsEnableVideo() || NULL == hViewDC)
		return;

	CRect rect;
	GetClientRect(&rect);

	const int nClientWidth = rect.Width();
	const int nClientHeight = rect.Height();

	const int nImgWidth = m_stVideo.m_nWidth;
	const int nImgHeight = m_stVideo.m_nHeight;

	const float fZoom = GetZoom();


#if 1
	int x = 0;
	if (TYPE_CAMERAPOS_FIRST == m_ePosType)
	{
		x = nClientWidth - (nImgWidth * fZoom);
		int nGap = nClientWidth - (x + (int)(nImgWidth * fZoom));
		x += nGap;
	}
	if (TYPE_CAMERAPOS_SECOND == m_ePosType)
	{
		x = 0;
	}
#else
	int x = (nClientWidth - (nImgWidth * fZoom))/2;
	if (0 > x)	x = 0;
#endif
	int y = (nClientHeight - (nImgHeight * fZoom))/2;
	if (0 > y)	y = 0;

	HDC hFrmDC = m_stVideo.m_stFrameDC.m_hDC;
	if (hFrmDC)
	{
		::SetStretchBltMode(hViewDC, STRETCH_HALFTONE);
		::StretchBlt(hViewDC, x, y, nImgWidth * fZoom, nImgHeight * fZoom, hFrmDC, 0, 0, nImgWidth, nImgHeight, SRCCOPY);

		CUtil::PumpMessage();
	}
}

BOOL CStaticDisplay::GetPrimaryClientRect(RECT& stPrimary, RECT& stOffscreen, const float fZoom)
{
	const int x = 0;
	const int y = 0;

	const int nDisplayWidth = m_stVideo.m_nWidth;
	const int nDisplayHeight = m_stVideo.m_nHeight;

	HWND hWnd = this->m_hWnd;
	HWND hParent = ::GetParent(hWnd);

	RECT rtClient;
	memset(&rtClient, 0x00, sizeof(RECT));
	::GetClientRect(hWnd, &rtClient);

	if (DEFAULT_ZOOM_FACTOR >= fZoom)
	{
		rtClient.right = (LONG)(rtClient.left + nDisplayWidth * fZoom);
		rtClient.bottom = (LONG)(rtClient.top + nDisplayHeight * fZoom);
	}
	else if (DEFAULT_ZOOM_FACTOR<fZoom)
	{
		rtClient.right -= x;
		rtClient.bottom -= y;

		stOffscreen.left = (LONG)(x / fZoom);
		stOffscreen.top = (LONG)(y / fZoom);
		stOffscreen.right = nDisplayWidth;
		stOffscreen.bottom = nDisplayHeight;
	}
	stPrimary = rtClient;

	return TRUE;
}

BOOL CStaticDisplay::IsEnableVideo()
{
	if (NULL == m_stVideo.m_hDC)
		return FALSE;

	return TRUE;
}

BOOL CStaticDisplay::Init(const INFO_IMAGE* pstImage)
{
	if (NULL == pstImage)
		return FALSE;

	// Init GDI...
	HDC hDC = ::GetDC(this->m_hWnd);
	if (NULL == hDC)
	{
		this->Deinit();
		return FALSE;
	}
	m_stVideo.m_hDC = hDC;

	const DWORD w = pstImage->m_stFrame.m_dwWidth;
	const DWORD h = pstImage->m_stFrame.m_dwHeight;

	TYPE_VIDEOFORMAT eVideoFormat = TYPE_VIDEOFORMAT_NONE;

	if (TYPE_CAMCOLOR_MONO == pstImage->m_stFrame.m_eColor)	// Mono
	{
		if (TYPE_DATABIT_08 == pstImage->m_stFrame.m_eDataBit ||
			TYPE_DATABIT_10 == pstImage->m_stFrame.m_eDataBit ||
			TYPE_DATABIT_12 == pstImage->m_stFrame.m_eDataBit)
		{
			eVideoFormat = TYPE_VIDEOFORMAT_RGB08;
		}
		else
		{
			this->Deinit();
			return FALSE;
		}
	}
	else if (TYPE_CAMCOLOR_COLOR == pstImage->m_stFrame.m_eColor) // Color
	{
		eVideoFormat = TYPE_VIDEOFORMAT_RGB24;
	}
	else
	{
		this->Deinit();
		return FALSE;
	}

	BOOL bResult = this->Init(m_stVideo.m_stFrameDC, m_stVideo.m_hDC, w, h, eVideoFormat);
	if (!bResult)
	{
		this->Deinit();
	}
	m_stVideo.m_nWidth = w;
	m_stVideo.m_nHeight = h;

	// Set Fit Zoom...
	const float fZoom = CalcFitZoom();
	SetZoom(fZoom);

	return bResult;
}

void CStaticDisplay::Deinit()
{
	this->Deinit(m_stVideo.m_stFrameDC);
	if (m_stVideo.m_hDC)
	{
		::ReleaseDC(this->m_hWnd, m_stVideo.m_hDC);
		m_stVideo.m_hDC = NULL;
	}
	memset(&m_stVideo, 0x00, sizeof(INFO_VIDEO));

}


BOOL CStaticDisplay::Init(INFO_VIDEODC& stVideoDC, HDC hDC, int nW, int nH, TYPE_VIDEOFORMAT eVideoFormat)
{
	if (NULL == hDC)
		return FALSE;

	stVideoDC.m_hDC = ::CreateCompatibleDC(hDC);
	if (NULL == stVideoDC.m_hDC)
		return FALSE;

	::SetBkMode(stVideoDC.m_hDC, TRANSPARENT);

	int nBit = 0;
	DWORD dwPitch = 0;

	if (TYPE_VIDEOFORMAT_RGB08 == eVideoFormat || TYPE_VIDEOFORMAT_RGB12 == eVideoFormat)
	{
		const int COLOR = 256;

		stVideoDC.m_pstBmpInfo = (BITMAPINFO*) new BYTE[sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD)*COLOR];
		if (NULL == stVideoDC.m_pstBmpInfo)
			return FALSE;
		stVideoDC.m_pstBmpInfo->bmiHeader.biClrUsed = COLOR;

		for (int i = 0; i<COLOR; i++)
		{
			stVideoDC.m_pstBmpInfo->bmiColors[i].rgbBlue = i;
			stVideoDC.m_pstBmpInfo->bmiColors[i].rgbGreen = i;
			stVideoDC.m_pstBmpInfo->bmiColors[i].rgbRed = i;
			stVideoDC.m_pstBmpInfo->bmiColors[i].rgbReserved = i;
		}

		nBit = 8;
		dwPitch = (nW * nBit / 8 + 3) / 4 * 4;
	}
	else if (TYPE_VIDEOFORMAT_RGB16 == eVideoFormat || TYPE_VIDEOFORMAT_RGB24 == eVideoFormat)
	{
		stVideoDC.m_pstBmpInfo = (BITMAPINFO*) new BYTE[sizeof(BITMAPINFO)];
		if (NULL == stVideoDC.m_pstBmpInfo)
			return FALSE;
		stVideoDC.m_pstBmpInfo->bmiHeader.biClrUsed = 0;

		nBit = 24;
		dwPitch = (nW * nBit / 8 + 3) / 4 * 4;
	}
	else if (TYPE_VIDEOFORMAT_RGB32 == eVideoFormat)
	{
		stVideoDC.m_pstBmpInfo = (BITMAPINFO*) new BYTE[sizeof(BITMAPINFO)];
		if (NULL == stVideoDC.m_pstBmpInfo)
			return FALSE;
		stVideoDC.m_pstBmpInfo->bmiHeader.biClrUsed = 0;

		nBit = 32;
		dwPitch = (nW * nBit / 8 + 3) / 4 * 4;
	}
	else
	{
		return FALSE;
	}


	stVideoDC.m_pstBmpInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	stVideoDC.m_pstBmpInfo->bmiHeader.biWidth = nW;
	stVideoDC.m_pstBmpInfo->bmiHeader.biHeight = -nH;
	stVideoDC.m_pstBmpInfo->bmiHeader.biBitCount = nBit; // four 8-bit components
	stVideoDC.m_pstBmpInfo->bmiHeader.biSizeImage = nH * dwPitch;
	stVideoDC.m_pstBmpInfo->bmiHeader.biCompression = BI_RGB;
	stVideoDC.m_pstBmpInfo->bmiHeader.biPlanes = 1;

	stVideoDC.m_hBmp = ::CreateDIBSection(stVideoDC.m_hDC, stVideoDC.m_pstBmpInfo, DIB_RGB_COLORS, &stVideoDC.m_pRaster, NULL, 0x0);
	if (NULL == stVideoDC.m_hBmp)
		return FALSE;

	::SelectObject(stVideoDC.m_hDC, stVideoDC.m_hBmp);

	return TRUE;
}

void CStaticDisplay::Deinit(INFO_VIDEODC& stVideoDC)
{
	if (stVideoDC.m_hDC)
	{
		::DeleteDC(stVideoDC.m_hDC);
		stVideoDC.m_hDC = NULL;
	}

	if (stVideoDC.m_hBmp)
	{
		::DeleteObject(stVideoDC.m_hBmp);

		stVideoDC.m_hBmp = NULL;
		stVideoDC.m_pRaster = NULL;
	}

	if (stVideoDC.m_pstBmpInfo)
	{
		delete[] stVideoDC.m_pstBmpInfo;
		stVideoDC.m_pstBmpInfo = NULL;
	}
}

BOOL CStaticDisplay::Blt(INFO_VIDEODC& stVideoDC, const INFO_IMAGE* pstImg)
{
	if (FALSE == IsEnableVideo() || NULL == pstImg)
		return FALSE;

	const int nFrameWidth = m_stVideo.m_nWidth;
	const int nFrameHeight = m_stVideo.m_nHeight;
	const int nFramePitch = m_stVideo.m_stFrameDC.m_pstBmpInfo->bmiHeader.biSizeImage / nFrameHeight;

	const INFO_FRAME* pFrame = &pstImg->m_stFrame;

	if (TYPE_CAMCOLOR_MONO == pFrame->m_eColor)
	{
		if (TYPE_DATABIT_08 == pstImg->m_stFrame.m_eDataBit)
		{
			for (int y = 0; y < pFrame->m_dwHeight; y++)
			{
				memcpy(((BYTE*)stVideoDC.m_pRaster) + y*nFramePitch, pstImg->m_pBuffer + y*pFrame->m_dwPitch, pFrame->m_dwPitch);
				CUtil::PumpMessage();
			}
		}
		else if (TYPE_DATABIT_10 == pstImg->m_stFrame.m_eDataBit)
		{
			BYTE* pDest = (BYTE*)stVideoDC.m_pRaster;
			BYTE* pSrc = pstImg->m_pBuffer;

			int nSkip = 0;

			for (int y = 0; y < pFrame->m_dwHeight; y++)
			{
				nSkip = 0;
				for (int x = 0; x < pFrame->m_dwWidth; x++)
				{
					if (0 != x && 0 == x % 4)
						nSkip++;
					*(pDest + x) = *(pSrc + x + nSkip);

					CUtil::PumpMessage();
				}
				pDest += nFramePitch;
				pSrc += pFrame->m_dwPitch;

				CUtil::PumpMessage();
			}

		}
		else if (TYPE_DATABIT_12 == pstImg->m_stFrame.m_eDataBit)
		{
			if (TYPE_NETWORK_USB == pstImg->m_stFrame.m_eNetwork)
			{
				BYTE* pDest = (BYTE*)stVideoDC.m_pRaster;
				BYTE* pSrc = pstImg->m_pBuffer;

				int nSkip = 0;

				for (int y = 0; y < pFrame->m_dwHeight; y++)
				{
					nSkip = 0;
					for (int x = 0; x < pFrame->m_dwWidth; x++)
					{
						if (0 != x && 0 == x % 2)
							nSkip++;
						*(pDest + x) = *(pSrc + x + nSkip);

						CUtil::PumpMessage();
					}
					pDest += nFramePitch;
					pSrc += pFrame->m_dwPitch;

					CUtil::PumpMessage();
				}
			}
			else if (TYPE_NETWORK_GIGE == pstImg->m_stFrame.m_eNetwork)
			{
				if (TYPE_DATABIT_12 == pstImg->m_stFrame.m_eColorBit ||
					TYPE_DATABIT_10 == pstImg->m_stFrame.m_eColorBit)
				{
					BYTE* pDest = (BYTE*)stVideoDC.m_pRaster;
					BYTE* pSrc = pstImg->m_pBuffer;

					int nSkip = 0;

					for (int y = 0; y < pFrame->m_dwHeight; y++)
					{
						nSkip = 0;
						for (int x = 0; x < pFrame->m_dwWidth; x++)
						{
							*(pDest + x) = *(pSrc + x + nSkip);
							if (0 == x || 0 == x % 2)
								nSkip++;

							CUtil::PumpMessage();
						}
						pDest += nFramePitch;
						pSrc += pFrame->m_dwPitch;

						CUtil::PumpMessage();
					}
				}
			}
			else if (TYPE_NETWORK_BASLER == pstImg->m_stFrame.m_eNetwork)
			{
				if (TYPE_DATABIT_12 == pstImg->m_stFrame.m_eColorBit ||
					TYPE_DATABIT_10 == pstImg->m_stFrame.m_eColorBit)
				{
					BYTE* pDest = (BYTE*)stVideoDC.m_pRaster;
					BYTE* pSrc = pstImg->m_pBuffer;

					int nSkip = 0;

					for (int y = 0; y < pFrame->m_dwHeight; y++)
					{
						nSkip = 0;
						for (int x = 0; x < pFrame->m_dwWidth; x++)
						{
							*(pDest + x) = *(pSrc + x + nSkip);
							if (0 == x || 0 == x % 2)
								nSkip++;

							CUtil::PumpMessage();
						}
						pDest += nFramePitch;
						pSrc += pFrame->m_dwPitch;

						CUtil::PumpMessage();
					}
				}
			}
		}
		else
		{
			for (int y = 0; y < pFrame->m_dwHeight; y++)
			{
				memcpy(((BYTE*)stVideoDC.m_pRaster) + y*nFramePitch, pstImg->m_pBuffer + y*pFrame->m_dwPitch, pFrame->m_dwPitch);
				
				CUtil::PumpMessage();
			}
		}
	}

	return TRUE;
}

BOOL CStaticDisplay::CheckVideoDevice(const INFO_IMAGE* pstImage)
{
	if (FALSE == IsEnableVideo())
		return FALSE;

	const int width = m_stVideo.m_nWidth;
	const int height = m_stVideo.m_nHeight;

	if (pstImage->m_stFrame.m_dwWidth > width || pstImage->m_stFrame.m_dwHeight > height)
	{
		return FALSE;
	}

	HDC hDC = m_stVideo.m_hDC;
	HDC hMemDC = ::CreateCompatibleDC(hDC);
	if (hMemDC)
		::DeleteDC(hMemDC);
	else
		return FALSE;
	return TRUE;
}

const float CStaticDisplay::GetZoom()
{
	return m_fZoom;
}

void CStaticDisplay::SetZoom(float fZoom)
{
	m_fZoom = fZoom;
}

void CStaticDisplay::SetBkColor(COLORREF rgb)
{
	m_bkColor = rgb;
}

void CStaticDisplay::SetPostionType(TYPE_CAMERAPOS eType)
{
	m_ePosType = eType;
}

const float CStaticDisplay::CalcFitZoom()
{
	float fZoom = 1.0f;

	if (IsEnableVideo())
	{
		CRect rect;
		GetClientRect(&rect);

		const int nW = rect.Width();
		const int nH = rect.Height();

		const float fHRatio = (float)nW / (float)m_stVideo.m_nWidth;
		const float fVRatio = (float)nH / (float)m_stVideo.m_nHeight;

		if (fHRatio > fVRatio)
			fZoom = fVRatio;
		else
			fZoom = fHRatio;
	}
	
	return fZoom;
}


void CStaticDisplay::ConvertColorBit10to8(const TYPE_NETWORK eNetwork, const INFO_IMAGE* pFrom, BYTE* pTo, int nToPitch)
{
	if (NULL == pFrom || NULL == pTo)
		return;

	const INFO_FRAME* pFrame = &pFrom->m_stFrame;
	ConvertColorBit10to8(eNetwork, pFrame->m_dwWidth, pFrame->m_dwHeight, (BYTE*)pFrom->m_pBuffer, pFrame->m_dwPitch, pTo, nToPitch);
}

void CStaticDisplay::ConvertColorBit12to8(const TYPE_NETWORK eNetwork, const INFO_IMAGE* pFrom, BYTE* pTo, int nToPitch)
{
	if (NULL == pFrom || NULL == pTo)
		return;

	const INFO_FRAME* pFrame = &pFrom->m_stFrame;
	ConvertColorBit12to8(eNetwork, pFrame->m_dwWidth, pFrame->m_dwHeight, (BYTE*)pFrom->m_pBuffer, pFrame->m_dwPitch, pTo, nToPitch);
}


void CStaticDisplay::ConvertColorBit10to8(const TYPE_NETWORK eNetwork, const int nW, const int nH, BYTE* pFrom, int nFromPitch, BYTE* pTo, int nToPitch)
{
	if (NULL == pFrom || NULL == pTo)
		return;

	BYTE* pDestBuf = pTo;
	BYTE* pSrcBUf = pFrom;

	int nSkip = 0;

	for (int y = 0; y < nH; y++)
	{
		nSkip = 0;
		for (int x = 0; x < nW; x++)
		{
			if (0 != x && 0 == x % 4)
				nSkip++;
			*(pDestBuf + x) = *(pSrcBUf + x + nSkip);
		}
		pDestBuf += nToPitch;
		pSrcBUf += nFromPitch;
		
		CUtil::PumpMessage();
	}
}

void CStaticDisplay::ConvertColorBit12to8(const TYPE_NETWORK eNetwork, const int nW, const int nH, BYTE* pFrom, int nFromPitch, BYTE* pTo, int nToPitch)
{
	if (NULL == pFrom || NULL == pTo)
		return;

	BYTE* pDest = pTo;
	BYTE* pSrc = pFrom;

	int nSkip = 0;

	if (TYPE_NETWORK_USB == eNetwork)
	{
		for (int y = 0; y < nH; y++)
		{
			nSkip = 0;
			for (int x = 0; x < nW; x++)
			{
				if (0 != x && 0 == x % 2)
					nSkip++;
				*(pDest + x) = *(pSrc + x + nSkip);
			}
			pDest += nToPitch;
			pSrc += nFromPitch;
			
			CUtil::PumpMessage();
		}
	}
	else if (TYPE_NETWORK_GIGE == eNetwork)
	{
		for (int y = 0; y < nH; y++)
		{
			nSkip = 0;
			for (int x = 0; x < nW; x++)
			{
				*(pDest + x) = *(pSrc + x + nSkip);
				if (0 == x || 0 == x % 2)
					nSkip++;
			}
			pDest += nToPitch;
			pSrc += nFromPitch;
			
			CUtil::PumpMessage();
		}
	}
	else if (TYPE_NETWORK_BASLER == eNetwork)
	{
		for (int y = 0; y < nH; y++)
		{
			nSkip = 0;
			for (int x = 0; x < nW; x++)
			{
				*(pDest + x) = *(pSrc + x + nSkip);
				if (0 == x || 0 == x % 2)
					nSkip++;
			}
			pDest += nToPitch;
			pSrc += nFromPitch;

			CUtil::PumpMessage();
		}
	}
}
