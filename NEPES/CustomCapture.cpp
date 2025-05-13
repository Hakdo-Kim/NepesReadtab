// CustomCapture.cpp : implementation file
//

#include "stdafx.h"
#include "CustomCapture.h"

#include "Resource.h"
#include "stringres.h"

// CCustomCapture

IMPLEMENT_DYNAMIC(CCustomCapture, CStatic)

CCustomCapture::CCustomCapture()
{
	m_rgbBk = RGB(240, 240, 240);
	m_rgbTxt = RGB(0, 0, 0);

	//
	m_szTitle = _T("");

	m_nFontHeight = 24;
	m_nFontWeight = FW_BOLD;
	m_szFontName = _T("MS Shell Dlg");
}

CCustomCapture::~CCustomCapture()
{
	for (int i = 0; i < MAX_CAPTUREDISPLAY; i++)
	{
		if (m_pctlCaptureDisplay[i])
			delete m_pctlCaptureDisplay[i];
	}
}

BOOL CCustomCapture::DisplayImage(const TYPE_CAMERAPOS eType, const INFO_IMAGE* pstImage, const DWORD dwCurFlag, const INFO_CAPTURE_PROCESS* pstCapture)
{
	BOOL bResult = FALSE;

	if (TYPE_CAMERAPOS_FIRST == eType && m_pctlCaptureDisplay[0])
		bResult = m_pctlCaptureDisplay[0]->DisplayImage(pstImage, dwCurFlag, pstCapture);
	else if (TYPE_CAMERAPOS_SECOND == eType && m_pctlCaptureDisplay[1])
		bResult = m_pctlCaptureDisplay[1]->DisplayImage(pstImage, dwCurFlag, pstCapture);
	
	return bResult;
}

void CCustomCapture::ClearImage(const TYPE_CAMERAPOS eType)
{
	if (TYPE_CAMERAPOS_FIRST == eType && m_pctlCaptureDisplay[0])
		m_pctlCaptureDisplay[0]->ClearImage();
	else if (TYPE_CAMERAPOS_SECOND == eType && m_pctlCaptureDisplay[1])
		m_pctlCaptureDisplay[1]->ClearImage();
}

BOOL CCustomCapture::IsClearImage(const TYPE_CAMERAPOS eType)
{
	BOOL bClear = TRUE;

	if (TYPE_CAMERAPOS_FIRST == eType && m_pctlCaptureDisplay[0])
		bClear = m_pctlCaptureDisplay[0]->IsClearImage();
	else if (TYPE_CAMERAPOS_SECOND == eType && m_pctlCaptureDisplay[1])
		bClear = m_pctlCaptureDisplay[1]->IsClearImage();

	return bClear;
}

void CCustomCapture::AddCount(const TYPE_CAMERAPOS eType)
{
	if (TYPE_CAMERAPOS_FIRST == eType && m_pctlCaptureDisplay[0])
		m_pctlCaptureDisplay[0]->AddCount();
	else if (TYPE_CAMERAPOS_SECOND == eType && m_pctlCaptureDisplay[1])
		m_pctlCaptureDisplay[1]->AddCount();
}
void CCustomCapture::ClearCount(const TYPE_CAMERAPOS eType)
{
	if (TYPE_CAMERAPOS_FIRST == eType && m_pctlCaptureDisplay[0])
		m_pctlCaptureDisplay[0]->ClearCount();
	else if (TYPE_CAMERAPOS_SECOND == eType && m_pctlCaptureDisplay[1])
		m_pctlCaptureDisplay[1]->ClearCount();
}



BEGIN_MESSAGE_MAP(CCustomCapture, CStatic)
	ON_WM_SIZE()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CCustomCapture message handlers
void CCustomCapture::PreSubclassWindow()
{
	CStatic::PreSubclassWindow();

	const DWORD dwCtrlId = this->GetDlgCtrlID();
	const DWORD dwStyle = WS_CHILD | WS_VISIBLE;

	CRect rtClient;
	GetClientRect(&rtClient);

	int nWidth = rtClient.Width();
	int nHeight = rtClient.Height();

	const int nDisplayWidth = (nWidth - MARGIN * 4) / 3;
	
	RECT rtCtrl;
	int nIdx = 0;
	// Left (Index 0)
	m_pctlCaptureDisplay[nIdx] = new CCustomCaptureDisplay;
	m_pctlCaptureDisplay[nIdx]->SetTitle(STR_MSG_FIRSTCAMERA);
	m_pctlCaptureDisplay[nIdx]->SetPostionType(TYPE_CAMERAPOS_FIRST);

	rtCtrl.left = MARGIN;
	rtCtrl.top = MARGIN;
	rtCtrl.right = rtCtrl.left + nDisplayWidth;
	rtCtrl.bottom = nHeight - MARGIN;
	m_pctlCaptureDisplay[nIdx]->Create(_T(""), dwStyle, rtCtrl, this, dwCtrlId + nIdx);		nIdx++;

	// Right (Index 1)
	m_pctlCaptureDisplay[nIdx] = new CCustomCaptureDisplay;
	m_pctlCaptureDisplay[nIdx]->SetTitle(STR_MSG_SECONDCAMERA);
	m_pctlCaptureDisplay[nIdx]->SetPostionType(TYPE_CAMERAPOS_SECOND);

	rtCtrl.left = nWidth - nDisplayWidth - MARGIN;
	rtCtrl.top = MARGIN;
	rtCtrl.right = rtCtrl.left + nDisplayWidth;
	rtCtrl.bottom = nHeight - MARGIN;
	m_pctlCaptureDisplay[nIdx]->Create(_T(""), dwStyle, rtCtrl, this, dwCtrlId + nIdx);		nIdx++;

}

void CCustomCapture::OnSize(UINT nType, int cx, int cy)
{
	CStatic::OnSize(nType, cx, cy);
	AdjustLayout();

}

void CCustomCapture::OnPaint()
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

void CCustomCapture::DrawTitle(CDC* pMemDC)
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

void CCustomCapture::DrawBackground(CDC* pMemDC)
{
	if (NULL == pMemDC)
		return;

	CRect rect;
	this->GetClientRect(&rect);

	const int w = rect.Width();
	const int h = rect.Height();

	pMemDC->FillSolidRect(&rect, m_rgbBk);
}

void CCustomCapture::AdjustLayout()
{
	CRect rtClient;
	GetClientRect(&rtClient);

	int nWidth = rtClient.Width();
	int nHeight = rtClient.Height();

	const int TOPMARGIN = m_nFontHeight + MARGIN;

	const int nDisplayWidth = (nWidth - MARGIN * 2) / 2;
	const int nDisplayHeight = (nHeight - MARGIN * 3);

	RECT rtCtrl;
	int nIdx = 0;
	int nRightPos = 0;

	// Left
	rtCtrl.top = MARGIN + TOPMARGIN;
	rtCtrl.bottom = rtCtrl.top + nDisplayHeight - MARGIN * 4;

	rtCtrl.left = MARGIN;
	rtCtrl.right = rtCtrl.left + nDisplayWidth;
	if (m_pctlCaptureDisplay[nIdx])
	{
		m_pctlCaptureDisplay[nIdx]->MoveWindow(&rtCtrl);
	}
	nIdx++;
	nRightPos = rtCtrl.right;


	// Right
	rtCtrl.left = nRightPos;
	rtCtrl.right = rtCtrl.left + nDisplayWidth;
	if (m_pctlCaptureDisplay[nIdx])
	{
		m_pctlCaptureDisplay[nIdx]->MoveWindow(&rtCtrl);
	}
	nIdx++;
	
}