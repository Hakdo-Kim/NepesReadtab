// TapMainCount.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "TapMainCount.h"
#include "afxdialogex.h"
#include "stringres.h"



// CTabMainCount dialog

IMPLEMENT_DYNAMIC(CTapMainCount, CDialogEx)

CTapMainCount::CTapMainCount(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTapMainCount::IDD, pParent)
{
	memset(&m_rtView, 0x00, sizeof(RECT));
}

CTapMainCount::~CTapMainCount()
{
}

void CTapMainCount::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTapMainCount, CDialogEx)
	ON_WM_SIZE()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CTabMainCount message handlers


void CTapMainCount::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	AdjustLayout();
	this->Invalidate();
}


BOOL CTapMainCount::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (IDOK == wParam)
	{
		return TRUE;
	}
	return CDialogEx::OnCommand(wParam, lParam);
}


BOOL CTapMainCount::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	//
	m_TapSizeList.Create(CTapSizeList::IDD, this);
	m_TapSizeList.ShowWindow(SW_SHOW);
	
	//TapMainScenario
	m_pViewList[FIRST_VIEW].Create(CTapView::IDD, this);
	m_pViewList[SECOND_VIEW].Create(CTapView::IDD, this);
	
	m_pViewList[FIRST_VIEW].ShowWindow(SW_SHOW);
	m_pViewList[SECOND_VIEW].ShowWindow(SW_SHOW);

	m_pViewList[FIRST_VIEW].EnableWindow(TRUE);
	m_pViewList[SECOND_VIEW].EnableWindow(TRUE);

	m_pViewList[FIRST_VIEW].SetCameraPos(TYPE_CAMERAPOS_FIRST);
	m_pViewList[SECOND_VIEW].SetCameraPos(TYPE_CAMERAPOS_SECOND);

	m_pViewList[FIRST_VIEW].GetScrollView()->ShowWindow(SW_HIDE);
	m_pViewList[SECOND_VIEW].GetScrollView()->ShowWindow(SW_HIDE);
	
	// Version 1.366
	// Label Create
	for (int i = 0; i < MAX_TYPE_MONITORING; i++)
	{
		m_label[i] = new CStatic;
		m_label[i]->Create("", WS_CHILD | WS_VISIBLE, CRect(30, 30, 30, 30), this);
		m_label[i]->ShowWindow(SW_SHOW);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


BOOL CTapMainCount::PreTranslateMessage(MSG* pMsg)
{
	if (WM_KEYDOWN == pMsg->message)
	{
		if (VK_ESCAPE == pMsg->wParam)
		{
			return TRUE;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CTapMainCount::AdjustLayout()
{
	if (NULL == m_TapSizeList.GetSafeHwnd())
		return;

	CRect rtClient;
	this->GetClientRect(rtClient);

	const int nClientWidth = rtClient.Width();
	const int nClientHeight = rtClient.Height();

	//
	m_rtView.left = MARGIN;
	m_rtView.top = MARGIN;
	m_rtView.right = rtClient.right - MARGIN;
	m_rtView.bottom = rtClient.bottom - MARGIN;

	const double fListHeight = 7. / 11.;

	const int nListHeightMin = 600;
	
	CRect rtTapSizeList;
	{
		int nListHeight = std::max((int)((nClientHeight - MARGIN * 2) * fListHeight), nListHeightMin);

		RECT rtTemp = m_rtView;
		rtTemp.top += MARGIN;
		rtTemp.bottom = rtTemp.top + nListHeight;

		m_TapSizeList.MoveWindow(&rtTemp);
		rtTapSizeList = rtTemp;
	}

	{
		RECT rtTemp = m_rtView;
		rtTemp.top = rtTapSizeList.bottom + MARGIN;
		rtTemp.left += MARGIN;
		rtTemp.right = rtClient.Width() / 2 - (MARGIN * 2);
		rtTemp.bottom -= MARGIN;
		m_pViewList[FIRST_VIEW].MoveWindow(&rtTemp);

		rtTemp.left = rtClient.Width() / 2 + MARGIN;
		rtTemp.right = rtTemp.left + rtClient.Width() / 2 - (MARGIN * 3);
		m_pViewList[SECOND_VIEW].MoveWindow(&rtTemp);
		
	}
	
	// Version 1.366
	// Monitoring UI Location Set
	for (int labelNum = 1; labelNum < MAX_TYPE_MONITORING; labelNum++)
	{
		CRect rtTemp = m_rtView;
		rtTemp.top = (rtTapSizeList.bottom + (MARGIN * 4 * labelNum));
		rtTemp.left = (MARGIN * 4);
		rtTemp.right = rtTapSizeList.right;
		rtTemp.bottom = (rtTapSizeList.bottom + (MARGIN * 4 * (labelNum + 1)));

		m_label[labelNum]->MoveWindow(&rtTemp);
	}
}

void CTapMainCount::UpdateResultSize(TYPE_CAMERAPOS eCameraPos, CSampleSide* pSample)
{
	if (m_TapSizeList.m_hWnd)
	{
		m_TapSizeList.UpdateResultSize(eCameraPos, pSample);
	}
}

void CTapMainCount::UpdateRangeValue(TYPE_CAMERAPOS eCameraPos)
{
	if (m_TapSizeList.m_hWnd)
	{
		m_TapSizeList.UpdateRangeValue(eCameraPos);
	}
}

void CTapMainCount::UpdateSizeName()
{
	if (m_TapSizeList.m_hWnd)
	{
		m_TapSizeList.UpdateSizeName();
	}
}

void CTapMainCount::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	/*
	CRect rect;
	GetClientRect(&rect);

	const int nClientWidth = rect.Width();
	const int nClientHeight = rect.Height();*/

	//DrawLayout(&dc, m_rtView, RGB(200, 200, 200), IDB_STATIC_GUARD_LEFTTOP, IDB_STATIC_GUARD_LEFTBOTTOM, IDB_STATIC_GUARD_RIGHTTOP, IDB_STATIC_GUARD_RIGHTBOTTOM);
	//DrawLayout(&dc, m_rtFirstView, RGB(200, 200, 200), IDB_STATIC_GUARD_LEFTTOP, IDB_STATIC_GUARD_LEFTBOTTOM, IDB_STATIC_GUARD_RIGHTTOP, IDB_STATIC_GUARD_RIGHTBOTTOM);
	//DrawLayout(&dc, m_rtSecondView, RGB(200, 200, 200), IDB_STATIC_GUARD_LEFTTOP, IDB_STATIC_GUARD_LEFTBOTTOM, IDB_STATIC_GUARD_RIGHTTOP, IDB_STATIC_GUARD_RIGHTBOTTOM);

	CDialogEx::OnPaint();
}

/*CCustomScrollView* CTapMainCount::GetScrollView(TYPE_CAMERAPOS eCameraPos)
{
	CCustomScrollView* pScrollView = NULL;

	if (TYPE_CAMERAPOS_FIRST == eCameraPos)
		pScrollView = m_pViewList[FIRST_VIEW].GetScrollView();
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
		pScrollView = m_pViewList[SECOND_VIEW].GetScrollView();

	return pScrollView;
}*/

/*const TYPE_CAMERAPOS CTapMainCount::GetViewFromMessage(CWnd* pWnd)
{
	TYPE_CAMERAPOS ePos = TYPE_CAMERAPOS_NONE;

	CTapView* pTapView = dynamic_cast<CTapView*>(pWnd);
	if (pTapView)
	{
		ePos = pTapView->GetCameraPos();
	}
	return ePos;
}*/

void CTapMainCount::SetStepState(TYPE_CAMERAPOS eCameraPos, TYPE_STEP eStep, BOOL bResult)
{
	if (TYPE_CAMERAPOS_FIRST == eCameraPos)
		m_pViewList[FIRST_VIEW].SetStepState(eStep, bResult);
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
		m_pViewList[SECOND_VIEW].SetStepState(eStep, bResult);
}

void CTapMainCount::UpdateEnableStep()
{
	/*m_pViewList[FIRST_VIEW].UpdateEnableStep();
	m_pViewList[SECOND_VIEW].UpdateEnableStep();*/
}

void CTapMainCount::UpdateResult(TYPE_CAMERAPOS eCameraPos, TYPE_STEP eStep, CSampleSide* pSample)
{
	/*CCustomScrollView* pScrollView = GetScrollView(eCameraPos);
	if (pScrollView)
	{
		CSampleSide* pSampleSide = NULL;
		void* pstOutput = NULL;

		if (pSample)
		{
			if (TYPE_STEP_001 == eStep)			pstOutput = &pSample->m_SizeResult;
			else if (TYPE_STEP_002 == eStep)	pstOutput = &pSample->m_StainResult;
			else if (TYPE_STEP_003 == eStep)	pstOutput = &pSample->m_DifferResult;
			else if (TYPE_STEP_004 == eStep)	pstOutput = &pSample->m_BubbleResult;
			else if (TYPE_STEP_005 == eStep)	pstOutput = &pSample->m_ScratchResult;
			else if (TYPE_STEP_006 == eStep)	pstOutput = &pSample->m_StampResult;
		}
		pScrollView->DisplayStepOutput(eStep, pstOutput);
	}*/
}

void CTapMainCount::DrawLayout(CDC* pDC, CRect rect, COLORREF rgbBk, DWORD dwLT, DWORD dwLB, DWORD dwRT, DWORD dwRB)
{
	/*
	if (NULL == pDC)
		return;

	CRect rtClient = rect;
	{
		CPen pen;
		pen.CreatePen(PS_SOLID, 3, rgbBk);
		CPen* pOldPen = pDC->SelectObject(&pen);

		const int gap = 2;

		pDC->MoveTo(rtClient.left + gap, rtClient.top + gap);
		pDC->LineTo(rtClient.right - gap, rtClient.top + gap);
		pDC->LineTo(rtClient.right - gap, rtClient.bottom - gap);
		pDC->LineTo(rtClient.left + gap, rtClient.bottom - gap);
		pDC->LineTo(rtClient.left + gap, rtClient.top + gap);
	}

	//const int w = rtClient.Width();
	//const int h = rtClient.Height();
	const int w = 547;
	const int h = 100;

	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);

	BITMAP bm;
	HBITMAP hBmpLeftTop = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(dwLT));
	if (hBmpLeftTop)
	{
		::GetObject(hBmpLeftTop, sizeof(BITMAP), &bm);

		HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpLeftTop);
		pDC->BitBlt(rtClient.left, rtClient.top, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

		MemDC.SelectObject(hOld);
		::DeleteObject(hBmpLeftTop);
	}

	HBITMAP hBmpLeftBottom = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(dwLB));
	if (hBmpLeftBottom)
	{
		::GetObject(hBmpLeftBottom, sizeof(BITMAP), &bm);

		HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpLeftBottom);
		pDC->BitBlt(rtClient.left, rtClient.bottom - bm.bmHeight, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

		MemDC.SelectObject(hOld);
		::DeleteObject(hBmpLeftBottom);
	}

	HBITMAP hBmpRightTop = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(dwRT));
	if (hBmpRightTop)
	{
		::GetObject(hBmpRightTop, sizeof(BITMAP), &bm);

		HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpRightTop);
		pDC->BitBlt(rtClient.right - bm.bmWidth, rtClient.top, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

		MemDC.SelectObject(hOld);
		::DeleteObject(hBmpRightTop);
	}

	HBITMAP hBmpRightBottom = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(dwRB));
	if (hBmpRightBottom)
	{
		::GetObject(hBmpRightBottom, sizeof(BITMAP), &bm);

		HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpRightBottom);
		pDC->BitBlt(rtClient.right - bm.bmWidth, rtClient.bottom - bm.bmHeight, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

		MemDC.SelectObject(hOld);
		::DeleteObject(hBmpRightBottom);
	}*/
}


// Version 1.366
// Path List Update
void CTapMainCount::UpdateMonitoring(CString FirstMonitoring, CString SecondMonitoring, CString OptionMonitoring, CString ImageFormatMonitoring)
{
	for (int labelNum = 1; labelNum < MAX_TYPE_MONITORING; labelNum++)
	{
		CString labelText = "";

		switch (labelNum)
		{
		case 1: labelText = _T("퍼스트 검사	: ")		+ FirstMonitoring;			break;
		case 2: labelText = _T("세컨드 검사	: ")		+ SecondMonitoring;			break;
		case 3: labelText = _T("OPTION		: ")		+ OptionMonitoring;			break;
		case 4: labelText = _T("Image Format	: ")	+ ImageFormatMonitoring;	break;
		}
		m_label[labelNum]->SetWindowTextA(labelText);
	}
	return;
}