// TapMainScenario.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "TapMainScenario.h"
#include "afxdialogex.h"

#include "Util/Util.h"
#include "stringres.h"

// CTapMainScenario dialog

IMPLEMENT_DYNAMIC(CTapMainScenario, CDialogEx)

CTapMainScenario::CTapMainScenario(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTapMainScenario::IDD, pParent)
{
	memset(&m_rtView, 0x00, sizeof(RECT));
	memset(&m_rtFirstView, 0x00, sizeof(RECT));
	memset(&m_rtSecondView, 0x00, sizeof(RECT));

}

CTapMainScenario::~CTapMainScenario()
{
}

void CTapMainScenario::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_FIRSTTITLE, m_ctlFirstTitle);
	DDX_Control(pDX, IDC_STATIC_SECONDTITLE, m_ctlSecondTitle);
}

BOOL CTapMainScenario::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (IDOK == wParam)
	{
		return TRUE;
	}
	return CDialogEx::OnCommand(wParam, lParam);
}

BOOL CTapMainScenario::PreTranslateMessage(MSG* pMsg)
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

BOOL CTapMainScenario::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//
	m_ctlFirstTitle.SetTextFont(_T("MS Shell Dlg"), 20, FW_BOLD);
	m_ctlSecondTitle.SetTextFont(_T("MS Shell Dlg"), 20, FW_BOLD);

	m_ctlFirstTitle.SetMessage(STR_MSG_FIRSTCAMERA);
	m_ctlSecondTitle.SetMessage(STR_MSG_SECONDCAMERA);


	//
	m_pViewList[FIRST_VIEW].Create(CTapView::IDD, this);
	m_pViewList[SECOND_VIEW].Create(CTapView::IDD, this);

	m_pViewList[FIRST_VIEW].ShowWindow(SW_SHOW);
	m_pViewList[SECOND_VIEW].ShowWindow(SW_SHOW);

	m_pViewList[FIRST_VIEW].EnableWindow(TRUE);
	m_pViewList[SECOND_VIEW].EnableWindow(TRUE);

	m_pViewList[FIRST_VIEW].SetCameraPos(TYPE_CAMERAPOS_FIRST);
	m_pViewList[SECOND_VIEW].SetCameraPos(TYPE_CAMERAPOS_SECOND);

	return TRUE;  // return TRUE  unless you set the focus to a control
}



BEGIN_MESSAGE_MAP(CTapMainScenario, CDialogEx)
	ON_WM_SIZE()
	ON_WM_PAINT()

	// Command
	ON_MESSAGE(WM_NOTIFY_EDIT, &CTapMainScenario::OnMsgEdit)
	ON_MESSAGE(WM_NOTIFY_GRAB, &CTapMainScenario::OnMsgGrab)
	ON_MESSAGE(WM_NOTIFY_GRABEDIT, &CTapMainScenario::OnMsgGrabEdit)
	ON_MESSAGE(WM_NOTIFY_STROBE, &CTapMainScenario::OnMsgStrobe)
END_MESSAGE_MAP()


// CTapMainScenario message handlers
void CTapMainScenario::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	
	AdjustLayout();
	this->Invalidate();
}


void CTapMainScenario::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CRect rect;
	GetClientRect(&rect);

	const int nClientWidth = rect.Width();
	const int nClientHeight = rect.Height();



	//DrawLayout(&dc, m_rtView, RGB(200, 200, 200), IDB_STATIC_GUARD_LEFTTOP, IDB_STATIC_GUARD_LEFTBOTTOM, IDB_STATIC_GUARD_RIGHTTOP, IDB_STATIC_GUARD_RIGHTBOTTOM);
	DrawLayout(&dc, m_rtFirstView, RGB(200, 200, 200), IDB_STATIC_GUARD_LEFTTOP, IDB_STATIC_GUARD_LEFTBOTTOM, IDB_STATIC_GUARD_RIGHTTOP, IDB_STATIC_GUARD_RIGHTBOTTOM);
	DrawLayout(&dc, m_rtSecondView, RGB(200, 200, 200), IDB_STATIC_GUARD_LEFTTOP, IDB_STATIC_GUARD_LEFTBOTTOM, IDB_STATIC_GUARD_RIGHTTOP, IDB_STATIC_GUARD_RIGHTBOTTOM);

	CDialogEx::OnPaint();
}


// Message
LRESULT CTapMainScenario::OnMsgEdit(WPARAM wParam, LPARAM lParam) // WPARAM: Windows Handle
{
	CWnd* pParent = this->GetParent();

	LRESULT hRes = S_OK;
	if (pParent)
	{
		hRes = pParent->SendMessage(WM_NOTIFY_EDIT, wParam, lParam);
	}
	return hRes;
}

LRESULT CTapMainScenario::OnMsgGrab(WPARAM wParam, LPARAM lParam)
{
	CWnd* pParent = this->GetParent();

	LRESULT hRes = S_OK;
	if (pParent)
	{
		hRes = pParent->SendMessage(WM_NOTIFY_GRAB, wParam, lParam);
	}
	return hRes;
}

LRESULT CTapMainScenario::OnMsgGrabEdit(WPARAM wParam, LPARAM lParam)
{
	CWnd* pParent = this->GetParent();

	LRESULT hRes = S_OK;
	if (pParent)
	{
		hRes = pParent->SendMessage(WM_NOTIFY_GRABEDIT, wParam, lParam);
	}
	return hRes;
}

LRESULT CTapMainScenario::OnMsgStrobe(WPARAM wParam, LPARAM lParam)
{
	CWnd* pParent = this->GetParent();
	
	LRESULT hRes = S_OK;
	if (pParent)
	{
		hRes = pParent->SendMessage(WM_NOTIFY_STROBE, wParam, lParam);
	}
	return hRes;
}


CCustomScrollView* CTapMainScenario::GetScrollView(TYPE_CAMERAPOS eCameraPos)
{
	CCustomScrollView* pScrollView = NULL;

	if (TYPE_CAMERAPOS_FIRST == eCameraPos)
		pScrollView = m_pViewList[FIRST_VIEW].GetScrollView();
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
		pScrollView = m_pViewList[SECOND_VIEW].GetScrollView();

	return pScrollView;
}

const TYPE_CAMERAPOS CTapMainScenario::GetViewFromMessage(CWnd* pWnd)
{
	TYPE_CAMERAPOS ePos = TYPE_CAMERAPOS_NONE;

	CTapView* pTapView = dynamic_cast<CTapView*>(pWnd);
	if (pTapView)
	{
		ePos = pTapView->GetCameraPos();
	}
	return ePos;
}

void CTapMainScenario::SetStepState(TYPE_CAMERAPOS eCameraPos, TYPE_STEP eStep, BOOL bResult)
{
	if (TYPE_CAMERAPOS_FIRST == eCameraPos)
		m_pViewList[FIRST_VIEW].SetStepState(eStep, bResult);
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
		m_pViewList[SECOND_VIEW].SetStepState(eStep, bResult);
}

void CTapMainScenario::UpdateResult(TYPE_CAMERAPOS eCameraPos, TYPE_STEP eStep, CSampleSide* pSample)
{
	CCustomScrollView* pScrollView = GetScrollView(eCameraPos);
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
			//else if (TYPE_STEP_007 == eStep)	pstOutput = &pSample->m_SizeSecondResult;
			else if (TYPE_STEP_007 == eStep)	pstOutput = &pSample->m_SizeCalculationResult;
		}
		pScrollView->DisplayStepOutput(eStep, pstOutput);
	}
}

void CTapMainScenario::UpdateEnableStep()
{
	m_pViewList[FIRST_VIEW].UpdateEnableStep();
	m_pViewList[SECOND_VIEW].UpdateEnableStep();
}


void CTapMainScenario::AdjustLayout()
{
	if (NULL == m_ctlFirstTitle.GetSafeHwnd() || NULL == m_ctlSecondTitle.GetSafeHwnd())
		return;

	CRect rtClient;
	this->GetClientRect(rtClient);

	const int nClientWidth = rtClient.Width();
	const int nClientHeight = rtClient.Height();

	const int nCassette = 200;

	//
	m_rtView.left = MARGIN;
	m_rtView.top = MARGIN;
	m_rtView.right = rtClient.right - MARGIN;
	m_rtView.bottom = rtClient.bottom - MARGIN;
	const int cx = (m_rtView.right - m_rtView.left - MARGIN) / 2;

	m_rtFirstView = m_rtView;
	m_rtFirstView.left = MARGIN;
	m_rtFirstView.right = m_rtFirstView.left + cx;

	m_rtSecondView = m_rtView;
	m_rtSecondView.left = m_rtSecondView.right - cx;

	{
		RECT rtTitle;
		rtTitle.left = m_rtFirstView.left + MARGIN * 2;
		rtTitle.top = m_rtFirstView.top + MARGIN * 2;
		rtTitle.right = m_rtFirstView.right - MARGIN * 2;
		rtTitle.bottom = rtTitle.top + MARGIN * 6;

		m_ctlFirstTitle.MoveWindow(&rtTitle);


		rtTitle.left = m_rtSecondView.left + MARGIN * 2;
		rtTitle.top = m_rtSecondView.top + MARGIN * 2;
		rtTitle.right = m_rtSecondView.right - MARGIN * 2;
		rtTitle.bottom = rtTitle.top + MARGIN * 6;

		m_ctlSecondTitle.MoveWindow(&rtTitle);


		RECT rtTemp = m_rtFirstView;
		rtTemp.left += MARGIN;
		rtTemp.top += (MARGIN * 10);
		rtTemp.right -= MARGIN;
		rtTemp.bottom -= MARGIN;
		m_pViewList[FIRST_VIEW].MoveWindow(&rtTemp);

		rtTemp = m_rtSecondView;
		rtTemp.left += MARGIN;
		rtTemp.top += (MARGIN * 10);
		rtTemp.right -= MARGIN;
		rtTemp.bottom -= MARGIN;
		m_pViewList[SECOND_VIEW].MoveWindow(&rtTemp);

	}
}

void CTapMainScenario::DrawLayout(CDC* pDC, CRect rect, COLORREF rgbBk, DWORD dwLT, DWORD dwLB, DWORD dwRT, DWORD dwRB)
{
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

	const int w = rtClient.Width();
	const int h = rtClient.Height();

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
	}
}
