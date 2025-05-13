// TapView.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "TapView.h"
#include "afxdialogex.h"

#include "stringres.h"
#include "CaptureManager.h"
#include "Util/Util.h"

// CTapView dialog

IMPLEMENT_DYNAMIC(CTapView, CDialogEx)

CTapView::CTapView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTapView::IDD, pParent)
{
	m_pCustomView = NULL;

	m_eCameraPos = TYPE_CAMERAPOS_NONE;
	m_eStep = TYPE_STEP_NONE;

	memset(&m_rtBar, 0x00, sizeof(RECT));
	memset(m_pStepResultList, 0x00, sizeof(BOOL)*TYPE_STEP_MAX);
}

CTapView::~CTapView()
{
}

void CTapView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL CTapView::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (IDOK == wParam)
	{
		return TRUE;
	}
	return CDialogEx::OnCommand(wParam, lParam);
}

BOOL CTapView::PreTranslateMessage(MSG* pMsg)
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

BOOL CTapView::OnInitDialog()
{
	CDialog::OnInitDialog();

	CRuntimeClass* pClass = RUNTIME_CLASS(CCustomScrollView);
	m_pCustomView = (CCustomScrollView*)pClass->CreateObject();
	if (m_pCustomView)
	{
		RECT rect;
		memset(&rect, 0x00, sizeof(RECT));
		rect.right = 10;
		rect.bottom = 10;

		m_pCustomView->Create(NULL, NULL, WS_CHILD, rect, this, AFX_IDW_PANE_FIRST + 1, NULL);
		m_pCustomView->SendMessage(WM_INITIALUPDATE);
		m_pCustomView->ShowWindow(SW_SHOW);
	}


	DWORD dwStyle = WS_CHILD | WS_VISIBLE;
	RECT rect;
	memset(&rect, 0x00, sizeof(RECT));
	for (int i = (int)TYPE_STEP_001; i <= (int)TYPE_STEP_006; i++)
	{
		m_pCustomStepList[i].Create(_T(""), dwStyle, rect, this, GetDlgCtrlID());
		m_pCustomStepList[i].SetTextFont(_T("MS Shell Dlg"), 16, FW_HEAVY);
	}

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const TCHAR* pTitleStep1 = pCaptureManager->GetTitleStep(m_eCameraPos, TYPE_STEP_001);
	const TCHAR* pTitleStep2 = pCaptureManager->GetTitleStep(m_eCameraPos, TYPE_STEP_002);
	const TCHAR* pTitleStep3 = pCaptureManager->GetTitleStep(m_eCameraPos, TYPE_STEP_003);
	const TCHAR* pTitleStep4 = pCaptureManager->GetTitleStep(m_eCameraPos, TYPE_STEP_004);
	const TCHAR* pTitleStep5 = pCaptureManager->GetTitleStep(m_eCameraPos, TYPE_STEP_005);
	const TCHAR* pTitleStep6 = pCaptureManager->GetTitleStep(m_eCameraPos, TYPE_STEP_006);

	m_pCustomStepList[TYPE_STEP_001].SetMessage((TCHAR*)pTitleStep1);
	m_pCustomStepList[TYPE_STEP_002].SetMessage((TCHAR*)pTitleStep2);
	m_pCustomStepList[TYPE_STEP_003].SetMessage((TCHAR*)pTitleStep3);
	m_pCustomStepList[TYPE_STEP_004].SetMessage((TCHAR*)pTitleStep4);
	m_pCustomStepList[TYPE_STEP_005].SetMessage((TCHAR*)pTitleStep5);
	m_pCustomStepList[TYPE_STEP_006].SetMessage((TCHAR*)pTitleStep6);

	m_pCustomStepList[TYPE_STEP_001].ShowWindow(SW_HIDE);
	m_pCustomStepList[TYPE_STEP_002].ShowWindow(SW_HIDE);
	m_pCustomStepList[TYPE_STEP_003].ShowWindow(SW_HIDE);
	m_pCustomStepList[TYPE_STEP_004].ShowWindow(SW_HIDE);
	m_pCustomStepList[TYPE_STEP_005].ShowWindow(SW_HIDE);
	m_pCustomStepList[TYPE_STEP_006].ShowWindow(SW_HIDE);

	return TRUE;
}

BEGIN_MESSAGE_MAP(CTapView, CDialogEx)
	ON_MESSAGE(WM_NOTIFY_EDIT, &CTapView::OnMsgEdit)
	ON_MESSAGE(WM_NOTIFY_GRAB, &CTapView::OnMsgGrab)
	ON_MESSAGE(WM_NOTIFY_STROBE, &CTapView::OnMsgStrobe)
	ON_WM_SIZE()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CTapView message handlers
LRESULT CTapView::OnMsgEdit(WPARAM wParam, LPARAM lParam) // WPARAM: Windows Handle
{
	LRESULT hRes = S_OK;

	CWnd* pWnd = this->GetParent();
	if (pWnd)
	{
		WPARAM wParam = (WPARAM)this;
		hRes = pWnd->SendMessage(WM_NOTIFY_EDIT, wParam);
	}
	return hRes;
}

LRESULT CTapView::OnMsgGrab(WPARAM wParam, LPARAM lParam)
{
	LRESULT hRes = S_OK;
	CWnd* pWnd = this->GetParent();
	if (pWnd)
	{
		WPARAM wParam = (WPARAM)this;
		hRes = pWnd->SendMessage(WM_NOTIFY_GRAB, wParam);
	}
	return hRes;
}

LRESULT CTapView::OnMsgStrobe(WPARAM wParam, LPARAM lParam)
{
	LRESULT hRes = S_OK;
	CWnd* pWnd = this->GetParent();
	if (pWnd)
	{
		WPARAM wParam = (WPARAM)this;
		hRes = pWnd->SendMessage(WM_NOTIFY_STROBE, wParam, lParam);
	}
	return hRes;
}



void CTapView::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	
	AdjustLayout();
}

void CTapView::OnPaint()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_OPTION* pstOpt = pCaptureManager->GetOption();

	//CDialogEx::OnPaint();
	CPaintDC dc(this);
	DrawBarLayout(&dc, m_rtBar, RGB(200, 200, 200), IDB_STATIC_GUARD_LEFTTOP, IDB_STATIC_GUARD_LEFTBOTTOM, IDB_STATIC_GUARD_RIGHTTOP, IDB_STATIC_GUARD_RIGHTBOTTOM);

	CPen penLine;
	penLine.CreatePen(PS_SOLID, 4, RGB(119, 191, 62));
	CPen penLineError;
	penLineError.CreatePen(PS_SOLID, 4, RGB(255, 0, 0));

	CPen* pOldPen = NULL;

	if (TYPE_STEP_001 == m_eStep ||
		TYPE_STEP_002 == m_eStep ||
		TYPE_STEP_003 == m_eStep ||
		TYPE_STEP_004 == m_eStep ||
		TYPE_STEP_005 == m_eStep ||
		TYPE_STEP_006 == m_eStep ||
		TYPE_STEP_007 == m_eStep)
	{
		BOOL bEnable = FALSE;

		for (int i = (int)TYPE_STEP_001; i <= (int)m_eStep; i++)
		{
			CRect rtStep;
			if ((int)TYPE_STEP_007 == i)
				m_pCustomStepList[(int)TYPE_STEP_001].GetWindowRect(rtStep);
			else
				m_pCustomStepList[i].GetWindowRect(rtStep);
			
			ScreenToClient(rtStep);

			int nGap = 2;
			rtStep.left -= nGap;
			rtStep.top -= nGap;
			rtStep.right += nGap;
			rtStep.bottom += nGap;

			{
				if (TYPE_CAMERAPOS_FIRST == m_eCameraPos)
				{
					if ((int)TYPE_STEP_001 == i)		bEnable = pstOpt->m_stFirstCameraStep.m_bStep001;
					else if ((int)TYPE_STEP_002 == i)	bEnable = pstOpt->m_stFirstCameraStep.m_bStep002;
					else if ((int)TYPE_STEP_003 == i)	bEnable = pstOpt->m_stFirstCameraStep.m_bStep003;
					else if ((int)TYPE_STEP_004 == i)	bEnable = pstOpt->m_stFirstCameraStep.m_bStep004;
					else if ((int)TYPE_STEP_005 == i)	bEnable = pstOpt->m_stFirstCameraStep.m_bStep005;
					else if ((int)TYPE_STEP_006 == i)	bEnable = pstOpt->m_stFirstCameraStep.m_bStep006;
					else if ((int)TYPE_STEP_007 == i)	bEnable = pstOpt->m_stFirstCameraStep.m_bStep001;  //step1과 같게 설정
				}
				else if (TYPE_CAMERAPOS_SECOND == m_eCameraPos)
				{
					if ((int)TYPE_STEP_002 == i)		bEnable = pstOpt->m_stSecondCameraStep.m_bStep002;
					else if ((int)TYPE_STEP_003 == i)	bEnable = pstOpt->m_stSecondCameraStep.m_bStep003;
					else if ((int)TYPE_STEP_004 == i)	bEnable = pstOpt->m_stSecondCameraStep.m_bStep004;
					else if ((int)TYPE_STEP_005 == i)	bEnable = pstOpt->m_stSecondCameraStep.m_bStep005;
					else if ((int)TYPE_STEP_006 == i)	bEnable = pstOpt->m_stSecondCameraStep.m_bStep006;
					else if ((int)TYPE_STEP_007 == i)	bEnable = pstOpt->m_stSecondCameraStep.m_bStep001; //step1과 같게 설정
#ifdef DEF_SECONDCAMERA_CHECKSIZE
					else if ((int)TYPE_STEP_001 == i)	bEnable = pstOpt->m_stSecondCameraStep.m_bStep001;
#endif
				}
			}
			if (i == 1)
			{
				;
			}
			else{
				if (m_pStepResultList[i])
					pOldPen = dc.SelectObject(&penLine);
				else
					pOldPen = dc.SelectObject(&penLineError);
			}
			if (FALSE == bEnable)
				pOldPen = dc.SelectObject(&penLine);

			dc.MoveTo(rtStep.left, rtStep.top);
			dc.LineTo(rtStep.right, rtStep.top);
			dc.LineTo(rtStep.right, rtStep.bottom);
			dc.LineTo(rtStep.left, rtStep.bottom);
			dc.LineTo(rtStep.left, rtStep.top);

			dc.SelectObject(&pOldPen);
		}
	}
	{
		CFont font;
		LOGFONT stLf;
		memset(&stLf, 0x00, sizeof(LOGFONT));
		stLf.lfHeight = 16;
		stLf.lfWeight = FW_HEAVY;
		_tcsncpy_s(stLf.lfFaceName, LF_FACESIZE, _T("MS Shell Dlg"), _tcslen(_T("MS Shell Dlg")));

		font.CreateFontIndirect(&stLf);
		CFont* pOlfFont = dc.SelectObject(&font);

		dc.SetBkMode(TRANSPARENT);
		dc.SetTextColor(RGB(255,255,255));

		BOOL bEnable = FALSE;

		for (int i = (int)TYPE_STEP_001; i <= TYPE_STEP_006; i++)
		{
#ifdef DEF_SECONDCAMERA_CHECKSIZE
#else
			if (TYPE_CAMERAPOS_SECOND == m_eCameraPos && (int)TYPE_STEP_001 == i)
				continue;
#endif

			if (TYPE_CAMERAPOS_FIRST == m_eCameraPos)
			{
				if ((int)TYPE_STEP_001 == i)		bEnable = pstOpt->m_stFirstCameraStep.m_bStep001;
				else if ((int)TYPE_STEP_002 == i)	bEnable = pstOpt->m_stFirstCameraStep.m_bStep002;
				else if ((int)TYPE_STEP_003 == i)	bEnable = pstOpt->m_stFirstCameraStep.m_bStep003;
				else if ((int)TYPE_STEP_004 == i)	bEnable = pstOpt->m_stFirstCameraStep.m_bStep004;
				else if ((int)TYPE_STEP_005 == i)	bEnable = pstOpt->m_stFirstCameraStep.m_bStep005;
				else if ((int)TYPE_STEP_006 == i)	bEnable = pstOpt->m_stFirstCameraStep.m_bStep006;
			}
			else if (TYPE_CAMERAPOS_SECOND == m_eCameraPos)
			{
				if ((int)TYPE_STEP_002 == i)		bEnable = pstOpt->m_stSecondCameraStep.m_bStep002;
				else if ((int)TYPE_STEP_003 == i)	bEnable = pstOpt->m_stSecondCameraStep.m_bStep003;
				else if ((int)TYPE_STEP_004 == i)	bEnable = pstOpt->m_stSecondCameraStep.m_bStep004;
				else if ((int)TYPE_STEP_005 == i)	bEnable = pstOpt->m_stSecondCameraStep.m_bStep005;
				else if ((int)TYPE_STEP_006 == i)	bEnable = pstOpt->m_stSecondCameraStep.m_bStep006;
#ifdef DEF_SECONDCAMERA_CHECKSIZE
				else if ((int)TYPE_STEP_001 == i)	bEnable = pstOpt->m_stSecondCameraStep.m_bStep001;
#endif
			}

			if(bEnable)
				dc.SetTextColor(RGB(255, 255, 255));
			else
				dc.SetTextColor(RGB(100, 100, 100));

			CRect rtStep;
			m_pCustomStepList[i].GetWindowRect(rtStep);
			ScreenToClient(rtStep);

			CRect rtStepTop;
			rtStepTop.left = rtStep.left + MARGIN;
			rtStepTop.right = rtStep.right - MARGIN;
			rtStepTop.top = rtStep.top + MARGIN + MARGIN;
			rtStepTop.bottom = rtStep.top + (rtStep.Height() - MARGIN * 3) / 2 + MARGIN;

			CRect rtStepDown = rtStepTop;
			rtStepDown.top = rtStepTop.bottom + MARGIN;
			rtStepDown.bottom = rtStepDown.top + (rtStep.Height() - MARGIN * 3) / 2 + MARGIN;

			DrawBarLayout(&dc, &rtStep, RGB(0, 0, 0), IDB_BMP_DISPLAYSTEP_LEFTTOP, IDB_BMP_DISPLAYSTEP_LEFTBOTTOM, IDB_BMP_DISPLAYSTEP_RIGHTTOP, IDB_BMP_DISPLAYSTEP_RIGHTBOTTOM);
		
			if ((int)TYPE_STEP_001 == i)
			{
#ifdef DEF_SECONDCAMERA_CHECKSIZE
				const TCHAR* pTitle = pCaptureManager->GetTitleStep(TYPE_CAMERAPOS_FIRST, (TYPE_STEP)i);
#else
				const TCHAR* pTitle = pCaptureManager->GetTitleStep(m_eCameraPos, (TYPE_STEP)i);
#endif
				dc.DrawText(pTitle, &rtStep, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			}
			else if((int)TYPE_STEP_002 == i || (int)TYPE_STEP_003 == i || (int)TYPE_STEP_004 == i ||
			 	(int)TYPE_STEP_005 == i || (int)TYPE_STEP_006 == i )
			{
				CString szTitle;
				if ((int)TYPE_STEP_002 == i)
				{
					const TCHAR* pTitle = pCaptureManager->GetTitleStep(m_eCameraPos, (TYPE_STEP)i);
					szTitle = pTitle;
				}
				else if ((int)TYPE_STEP_003 == i)
				{
					const TCHAR* pTitle = pCaptureManager->GetTitleStep(m_eCameraPos, (TYPE_STEP)i);
					szTitle = pTitle;
				}
				else if ((int)TYPE_STEP_004 == i)
				{
					const TCHAR* pTitle = pCaptureManager->GetTitleStep(m_eCameraPos, (TYPE_STEP)i);
					szTitle = pTitle;
				}
				else if ((int)TYPE_STEP_005 == i)
				{
					const TCHAR* pTitle = pCaptureManager->GetTitleStep(m_eCameraPos, (TYPE_STEP)i);
					szTitle = pTitle;
				}
				else if ((int)TYPE_STEP_006 == i)
				{
					const TCHAR* pTitle = pCaptureManager->GetTitleStep(m_eCameraPos, (TYPE_STEP)i);
					szTitle = pTitle;
				}
				
				const int nLen = GetStringLength(&szTitle);
				if (4 >= nLen)
				{
					dc.DrawText(szTitle, &rtStep, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				}
				else
				{
					CString szTop = GetString(&szTitle, 0, 2);
					CString szBottom = GetString(&szTitle, 3, szTitle.GetLength());
					dc.DrawText((LPCTSTR)szTop, rtStepTop, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					dc.DrawText((LPCTSTR)szBottom, rtStepDown, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				}
			}
		}
		dc.SelectObject(pOlfFont);
	}

}

CCustomScrollView* CTapView::GetScrollView()
{
	return m_pCustomView;
}

void CTapView::AdjustLayout()
{
	if (NULL == m_pCustomView || NULL == m_pCustomView->m_hWnd)
		return;

	RECT rtClient;
	this->GetWindowRect(&rtClient);
	this->ScreenToClient(&rtClient);

	RECT rtView;
	rtView.left = MARGIN;
	rtView.top = 0;
	rtView.right = rtClient.right - MARGIN;
	rtView.bottom = rtClient.bottom - MARGIN *2 - BARHEIGHT;
	m_pCustomView->MoveWindow(&rtView);

	m_rtBar.left = MARGIN;
	m_rtBar.top = rtClient.bottom - MARGIN - BARHEIGHT;
	m_rtBar.right = rtClient.right - MARGIN;
	m_rtBar.bottom = rtClient.bottom - MARGIN;



	// Bar
	RECT rect;
	rect.left = m_rtBar.left + MARGIN * 2;
	rect.top = m_rtBar.top + MARGIN * 2;
	rect.right = rect.left + STEPWIDTH;
	rect.bottom = m_rtBar.bottom - MARGIN * 2;

	for (int i = (int)TYPE_STEP_001; i <= (int)TYPE_STEP_006; i++)
	{
		if (TYPE_CAMERAPOS_FIRST == m_eCameraPos)
		{
			if ((int)TYPE_STEP_001 < i)
			{
				rect.left += (STEPWIDTH + MARGIN * 2);
				rect.right = (rect.left + STEPWIDTH);
			}
		}
		else
		{
#ifdef DEF_SECONDCAMERA_CHECKSIZE
			if ((int)TYPE_STEP_001 < i)
			{
				rect.left += (STEPWIDTH + MARGIN * 2);
				rect.right = (rect.left + STEPWIDTH);
			}
#else

			if (TYPE_CAMERAPOS_SECOND == m_eCameraPos && TYPE_STEP_001 == (TYPE_STEP)i)
			{
				m_pCustomStepList[i].ShowWindow(SW_HIDE);
				continue;
			}
			else
			{
				if ((int)TYPE_STEP_002 < i)
				{
					rect.left += (STEPWIDTH + MARGIN * 2);
					rect.right = (rect.left + STEPWIDTH);
				}
			}
#endif
		}

		if (m_pCustomStepList[i])
		{
			m_pCustomStepList[i].MoveWindow(&rect);
		}
	}
}

void CTapView::DrawBarLayout(CDC* pDC, CRect rect, COLORREF rgbBk, DWORD dwLT, DWORD dwLB, DWORD dwRT, DWORD dwRB)
{
	if (NULL == pDC)
		return;

	CRect rtClient = rect;
	{
		pDC->FillSolidRect(&rtClient, rgbBk);

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

void CTapView::SetCameraPos(TYPE_CAMERAPOS ePos)
{
	m_eCameraPos = ePos;
	if (m_pCustomView)
	{
		m_pCustomView->SetCameraPos(ePos);
	}
}

const TYPE_CAMERAPOS CTapView::GetCameraPos()
{
	return m_eCameraPos;
}

void CTapView::SetStepState(TYPE_STEP eStep, BOOL bResult)
{
	m_eStep = eStep;
	m_pStepResultList[eStep] = bResult;

	//if (TYPE_STEP_006 == eStep)
		this->InvalidateRect(&m_rtBar, FALSE);
}

void CTapView::UpdateEnableStep()
{
	this->InvalidateRect(&m_rtBar, FALSE);
}

int CTapView::GetStringLength(CString* pString)
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

CString CTapView::GetString(CString* pString, const int nStart, const int nEnd)
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