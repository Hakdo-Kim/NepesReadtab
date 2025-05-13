// DlgSequence.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "DlgSequence.h"
#include "DlgStrobeBrightness.h"
#include "afxdialogex.h"

#include "CaptureManager.h"
#include "stringres.h"
#include "Util/Util.h"

// CDlgSequence dialog

IMPLEMENT_DYNAMIC(CDlgSequence, CDialogEx)

CDlgSequence::CDlgSequence(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgSequence::IDD, pParent)
{
	memset(&m_rtStep, 0x00, sizeof(RECT));
	memset(&m_rtTool, 0x00, sizeof(RECT));	
	memset(&m_rtBar, 0x00, sizeof(RECT));

	memset(m_pStepList, 0x00, sizeof(CCustomStep*)*TYPE_STEP_MAX);

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pCustomView = NULL;
	m_eSelectedStep = TYPE_STEP_NONE;
}

CDlgSequence::~CDlgSequence()
{
}

void CDlgSequence::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_TITLE, m_ctlStaticTitle);
}

BOOL CDlgSequence::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (IDOK == wParam)
	{
		return TRUE;
	}
	return CDialogEx::OnCommand(wParam, lParam);
}

BOOL CDlgSequence::PreTranslateMessage(MSG* pMsg)
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

BOOL CDlgSequence::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	m_ctlStaticTitle.SetTextFont(_T("MS Shell Dlg"), 20, FW_BOLD);
	m_ctlStaticTitle.SetMessage(_T("CAMERA TITLE"));

	if (TYPE_CAMERAPOS_FIRST == m_eCameraType)
		m_ctlStaticTitle.SetMessage(STR_MSG_FIRSTCAMERA);
	else if (TYPE_CAMERAPOS_SECOND == m_eCameraType)
		m_ctlStaticTitle.SetMessage(STR_MSG_SECONDCAMERA);

	//
	CRuntimeClass* pClass = RUNTIME_CLASS(CCustomScrollViewEdit);
	m_pCustomView = (CCustomScrollViewEdit*)pClass->CreateObject();
	if (m_pCustomView)
	{
		RECT rect;
		memset(&rect, 0x00, sizeof(RECT));
		rect.right = 10;
		rect.bottom = 10;

		m_pCustomView->Create(NULL, NULL, WS_CHILD, rect, this, AFX_IDW_PANE_FIRST + 1, NULL);
		m_pCustomView->SendMessage(WM_INITIALUPDATE);
		m_pCustomView->ShowWindow(SW_SHOW);

#ifdef USE_BASLER_CAMERA
		m_pCustomView->DisplayEditImage(m_pImagePointer);
#else
		m_pCustomView->DisplayImage(m_pImagePointer);
#endif
	}

	
	//
	DWORD dwStyle = WS_CHILD | WS_VISIBLE;
	RECT rect;
	memset(&rect, 0x00, sizeof(RECT));
	for (int i = (int)TYPE_STEP_001; i <= (int)TYPE_STEP_006; i++)
	{
		m_pStepList[i] = new CCustomStep();
		m_pStepList[i]->Create(_T(""), dwStyle, rect, this, GetDlgCtrlID());

		m_pStepList[i]->SetTextFont(_T("MS Shell Dlg"), 16, FW_HEAVY);
	}

	UpdateTitleStep();

	m_dlgStepSize.Create(CDlgStepSize::IDD, this);
	m_dlgStepStain.Create(CDlgStepStain::IDD, this);
	m_dlgStepDiffer.Create(CDlgStepDiffer::IDD, this);
	m_dlgStepBubble.Create(CDlgStepBubble::IDD, this);
	m_dlgStepScratch.Create(CDlgStepScratch::IDD, this);
	m_dlgStepStamp.Create(CDlgStepStamp::IDD, this);


	if (TYPE_CAMERAPOS_FIRST == m_eCameraType)
	{
		TYPE_STEP eStepOutput = TYPE_STEP_NONE;
		if (m_pCustomView)
		{
			m_pCustomView->GetDisplayStepOutput(eStepOutput);
			m_pCustomView->SetDisplayStep(m_eCameraType, eStepOutput);
		}
		SetSelectedStep(eStepOutput);
	}
	else if (TYPE_CAMERAPOS_SECOND == m_eCameraType)
	{
		if (m_pCustomView)
			m_pCustomView->DisplayStepOutput(TYPE_STEP_NONE, NULL);
		SetSelectedStep(TYPE_STEP_NONE);
	}

	{
		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
		const TCHAR* pFilePath = pCaptureManager->GetInspectionFilePath(m_eCameraType);
		if (CUtil::IsExistFile(pFilePath))
			GetDlgItem(IDC_STATIC_FILEPATH)->SetWindowText(pFilePath);
		else
			GetDlgItem(IDC_STATIC_FILEPATH)->SetWindowText(_T("NONE"));
	}

	AdjustLayout();
	return TRUE;
}

BEGIN_MESSAGE_MAP(CDlgSequence, CDialogEx)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_GETMINMAXINFO()
	ON_WM_CLOSE()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEWHEEL()
	ON_BN_CLICKED(IDC_BTN_DEFAULT, &CDlgSequence::OnBnClickedBtnDefault)
	ON_BN_CLICKED(IDC_BTN_LOAD, &CDlgSequence::OnBnClickedBtnLoad)
	ON_BN_CLICKED(IDC_BTN_SAVE, &CDlgSequence::OnBnClickedBtnSave)
	ON_BN_CLICKED(IDC_BTN_SAVEAS, &CDlgSequence::OnBnClickedBtnSaveas)
	ON_BN_CLICKED(IDC_BTN_CANCEL, &CDlgSequence::OnBnClickedBtnCancel)
	ON_MESSAGE(WM_NOTIFY_GRABEDIT, &CDlgSequence::OnMsgGrabEdit)
	ON_MESSAGE(WM_NOTIFY_STROBE, &CDlgSequence::OnMsgStrobe)
	ON_MESSAGE(WM_NOTIFY_SEQUENCE_REQUESET, &CDlgSequence::OnMsgRequestImage)
	// Version 1.3.7.8
	ON_MESSAGE(WM_NOTIFY_SEQUENCE_REQUESET_FIRST, &CDlgSequence::OnMsgRequestResult)
	//
	ON_MESSAGE(WM_NOTIFY_SEQUENCE_EDIT_STEPDONE, &CDlgSequence::OnMsgEditStepDone)
	ON_MESSAGE(WM_NOTIFY_STEPSIZE_ROI_SELECTED, &CDlgSequence::OnMsgStepSizeRoiSelected)
	ON_MESSAGE(WM_NOTIFY_STEPSIZE_ROI_CHANGED, &CDlgSequence::OnMsgStepSizeRoiChanged)
END_MESSAGE_MAP()


// CDlgSequence message handlers
void CDlgSequence::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CRect rect;
	GetClientRect(&rect);

	DrawBarLayout(&dc, m_rtStep, RGB(200, 200, 200), IDB_STATIC_GUARD_LEFTTOP, IDB_STATIC_GUARD_LEFTBOTTOM, IDB_STATIC_GUARD_RIGHTTOP, IDB_STATIC_GUARD_RIGHTBOTTOM);

	//
	if (m_pStepList[m_eSelectedStep])
	{
		CRect rtStep;
		m_pStepList[m_eSelectedStep]->GetWindowRect(rtStep);
		ScreenToClient(rtStep);

		int nGap = 3;
		rtStep.left -= nGap;
		rtStep.top -= nGap;
		rtStep.right += nGap;
		rtStep.bottom += nGap;
		dc.FillSolidRect(rtStep, RGB(119, 191, 62));
	}

	DrawLayout(&dc, m_rtBar, RGB(200, 200, 200), IDB_STATIC_GUARD_LEFTTOP, IDB_STATIC_GUARD_LEFTBOTTOM, IDB_STATIC_GUARD_RIGHTTOP, IDB_STATIC_GUARD_RIGHTBOTTOM);

}

void CDlgSequence::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	AdjustLayout();
	this->Invalidate();
}

void CDlgSequence::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	lpMMI->ptMinTrackSize.x = MINWIDTH;
	lpMMI->ptMinTrackSize.y = MINHEIGHT;

	CDialogEx::OnGetMinMaxInfo(lpMMI);
}

void CDlgSequence::OnClose()
{
	for (int i = 0; i < (int)TYPE_STEP_MAX; i++)
	{
		if (m_pStepList[i])
		{
			delete m_pStepList[i];
		}
	}
	CDialogEx::OnClose();
}

void CDlgSequence::OnLButtonDown(UINT nFlags, CPoint point)
{
	TYPE_STEP eStep = TYPE_STEP_NONE;
	CRect rtStep;
	
	for (int i = 0; i < (int)TYPE_STEP_MAX; i++)
	{
		if (NULL == m_pStepList[i])
			continue;

		m_pStepList[i]->GetWindowRect(rtStep);
		this->ScreenToClient(rtStep);

		if (rtStep.PtInRect(point))
		{
			eStep = (TYPE_STEP)i;
			break;
		}
	}

	//
	CRect rtStepBar = m_rtStep;

	if (TYPE_STEP_NONE == eStep && rtStepBar.PtInRect(point))
	{
		SetSelectedStep(TYPE_STEP_NONE);
		m_pCustomView->SetDisplayStep(m_eCameraType, TYPE_STEP_NONE);

		m_pCustomView->DisplayStepOutput(eStep, NULL);
	}
	else if (TYPE_STEP_NONE != eStep)
	{
		SetSelectedStep(eStep);
		m_pCustomView->SetDisplayStep(m_eCameraType, eStep);

		m_pCustomView->DisplayStepOutput(eStep, NULL);
	}

	CDialogEx::OnLButtonDown(nFlags, point);
}






void CDlgSequence::AdjustLayout()
{
	if (!m_ctlStaticTitle.GetSafeHwnd())
		return;

	CRect rect;
	GetClientRect(&rect);

	RECT rtTitle;
	rtTitle.left = MARGIN;
	rtTitle.top = MARGIN;
	rtTitle.right = rect.right - MARGIN;
	rtTitle.bottom = rtTitle.top + MARGIN * 8;

	m_ctlStaticTitle.MoveWindow(&rtTitle);

	//
	m_rtStep.left = rect.left + MARGIN;
	m_rtStep.top = rect.top + MARGIN * 10;
	m_rtStep.right = m_rtStep.left + MARGIN * 17;
	m_rtStep.bottom = rect.bottom - MARGIN;

	//
	const int cy = MARGIN * 12;
	RECT rtCtl;
	rtCtl.left = m_rtStep.left + MARGIN;
	rtCtl.right = m_rtStep.right - MARGIN;
	rtCtl.top = m_rtStep.top + MARGIN;
	rtCtl.bottom = rtCtl.top + cy;

	for (int i = (int)TYPE_STEP_001; i <= (int)TYPE_STEP_006; i++)
	{
#ifdef DEF_SECONDCAMERA_CHECKSIZE
		// do nothing..
#else
		if (TYPE_CAMERAPOS_SECOND == m_eCameraType && TYPE_STEP_001 == (TYPE_STEP)i)
		{
			m_pStepList[i]->ShowWindow(SW_HIDE);
			continue;
		}
#endif

		m_pStepList[i]->MoveWindow(&rtCtl);

		rtCtl.top += (cy + MARGIN);
		rtCtl.bottom = rtCtl.top + cy;
	}


	//
	RECT rtView;
	rtView.left = m_rtStep.right + MARGIN;
	rtView.top = rtTitle.bottom + MARGIN;
	rtView.right = rect.right - MARGIN;
	rtView.bottom = rect.bottom - MARGIN - 240;

	if (m_pCustomView && m_pCustomView->GetSafeHwnd())
	{
		m_pCustomView->MoveWindow(&rtView);
	}


	//
	CRect rtBtn;
	GetDlgItem(IDC_BTN_DEFAULT)->GetClientRect(rtBtn);

	const int btncx = rtBtn.Width();
	const int btncy = rtBtn.Height();

	RECT rtTemp;
	memset(&rtTemp, 0x00, sizeof(RECT));

	rtTemp.top = rect.bottom - MARGIN * 2 - btncy;
	rtTemp.bottom = rect.bottom - MARGIN * 2;
	rtTemp.right = rect.right - MARGIN * 2;
	rtTemp.left = rtTemp.right - btncx;
	GetDlgItem(IDC_BTN_CANCEL)->MoveWindow(&rtTemp);
	
	rtTemp.left = rtView.left + MARGIN;
	rtTemp.right = rtTemp.left + btncx;
	GetDlgItem(IDC_BTN_DEFAULT)->MoveWindow(&rtTemp);

	rtTemp.left += (MARGIN + btncx);
	rtTemp.right = rtTemp.left + btncx;
	GetDlgItem(IDC_BTN_LOAD)->MoveWindow(&rtTemp);

	rtTemp.left += (MARGIN + btncx);
	rtTemp.right = rtTemp.left + btncx;
	GetDlgItem(IDC_BTN_SAVE)->MoveWindow(&rtTemp);

	rtTemp.left += (MARGIN + btncx);
	rtTemp.right = rtTemp.left + btncx;
	GetDlgItem(IDC_BTN_SAVEAS)->MoveWindow(&rtTemp);
	

	const int cypath = MARGIN * 3;
	rtTemp.top -= (MARGIN * 2 + cypath);
	rtTemp.bottom = rtTemp.top + cypath;
	rtTemp.left = rtView.left + MARGIN * 2;
	rtTemp.right = rect.right - MARGIN * 3;
	GetDlgItem(IDC_STATIC_FILEPATH)->MoveWindow(&rtTemp);
	

	// 
	m_rtTool.left = m_rtStep.right + MARGIN * 2;
	m_rtTool.top = rtView.bottom + MARGIN;
	m_rtTool.right = rect.right - MARGIN;
	m_rtTool.bottom = rect.bottom - MARGIN * 5 - btncy - cypath;

	m_dlgStepSize.MoveWindow(&m_rtTool);
	m_dlgStepStain.MoveWindow(&m_rtTool);
	m_dlgStepDiffer.MoveWindow(&m_rtTool);
	m_dlgStepBubble.MoveWindow(&m_rtTool);
	m_dlgStepScratch.MoveWindow(&m_rtTool);
	m_dlgStepStamp.MoveWindow(&m_rtTool);


	m_rtBar.left = m_rtStep.right + MARGIN;
	m_rtBar.right = rect.right - MARGIN;
	m_rtBar.top = m_rtTool.bottom;
	m_rtBar.bottom = rect.bottom - MARGIN;

	this->Invalidate(FALSE);
}

void CDlgSequence::DrawBarLayout(CDC* pDC, CRect rect, COLORREF rgbBk, DWORD dwLT, DWORD dwLB, DWORD dwRT, DWORD dwRB)
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


void CDlgSequence::DrawLayout(CDC* pDC, CRect rect, COLORREF rgbBk, DWORD dwLT, DWORD dwLB, DWORD dwRT, DWORD dwRB)
{
	if (NULL == pDC)
		return;

	CRect rtClient = rect;
	{
		//pDC->FillSolidRect(&rtClient, rgbBk);

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

void CDlgSequence::SetSelectedStep(TYPE_STEP eStep)
{
	m_eSelectedStep = eStep;

	m_dlgStepSize.ShowWindow(SW_HIDE);
	m_dlgStepStain.ShowWindow(SW_HIDE);
	m_dlgStepDiffer.ShowWindow(SW_HIDE);
	m_dlgStepBubble.ShowWindow(SW_HIDE);
	m_dlgStepScratch.ShowWindow(SW_HIDE);
	m_dlgStepStamp.ShowWindow(SW_HIDE);

	BOOL bDefault = TRUE;

	if (TYPE_STEP_001 == m_eSelectedStep
		|| TYPE_STEP_007 == m_eSelectedStep)
	{
		m_dlgStepSize.ShowWindow(SW_SHOW);
	}
	else if (TYPE_STEP_002 == m_eSelectedStep)
	{
		m_dlgStepStain.ShowWindow(SW_SHOW);
	}
	else if (TYPE_STEP_003 == m_eSelectedStep)
	{
		m_dlgStepDiffer.ShowWindow(SW_SHOW);
	}
	else if (TYPE_STEP_004 == m_eSelectedStep)
	{
		m_dlgStepBubble.ShowWindow(SW_SHOW);
	}
	else if (TYPE_STEP_005 == m_eSelectedStep)
	{
		m_dlgStepScratch.ShowWindow(SW_SHOW);
	}
	else if (TYPE_STEP_006 == m_eSelectedStep)
	{
		m_dlgStepStamp.ShowWindow(SW_SHOW);
	}
	else
	{
		bDefault = FALSE;
	}
	//GetDlgItem(IDC_BTN_DEFAULT)->EnableWindow(bDefault);
	GetDlgItem(IDC_BTN_DEFAULT)->EnableWindow(FALSE);


	this->InvalidateRect(&m_rtStep);
}

void CDlgSequence::OnBnClickedBtnDefault()
{
	if (TYPE_STEP_001 == m_eSelectedStep && m_dlgStepSize.IsWindowVisible())
	{
		m_dlgStepSize.SetDefaultValue();
	}
	else if (TYPE_STEP_002 == m_eSelectedStep && m_dlgStepStain.IsWindowVisible())
	{
		m_dlgStepStain.SetDefaultValue();
	}
	else if (TYPE_STEP_003 == m_eSelectedStep && m_dlgStepDiffer.IsWindowVisible())
	{
		m_dlgStepDiffer.SetDefaultValue();
	}
	else if (TYPE_STEP_004 == m_eSelectedStep && m_dlgStepBubble.IsWindowVisible())
	{
		m_dlgStepBubble.SetDefaultValue();
	}
	else if (TYPE_STEP_005 == m_eSelectedStep && m_dlgStepScratch.IsWindowVisible())
	{
		m_dlgStepScratch.SetDefaultValue();
	}
	else if (TYPE_STEP_006 == m_eSelectedStep && m_dlgStepStamp.IsWindowVisible())
	{
		m_dlgStepStamp.SetDefaultValue();
	}
}

void CDlgSequence::OnBnClickedBtnLoad()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	TCHAR szLocation[MAX_PATH] = { 0, };
	TCHAR szFilePath[MAX_PATH] = { 0, };

	CUtil::GetCurrentDirectory(szLocation, MAX_PATH);
	if (CUtil::SelectFile(NULL, szFilePath, MAX_PATH, _T("*.xml"), _T("Insepct Files (*.xml)|*.xml|"), NULL, TRUE))
	{
		INFO_INSPECTION stInspection;
		memset(&stInspection, 0x00, sizeof(INFO_INSPECTION));

		BOOL bResult = pCaptureManager->m_Xml.LoadInspection(szFilePath, stInspection);
		if (bResult)
		{
			if (TYPE_CAMERAPOS_FIRST == m_eCameraType)
			{
				if (TYPE_CAMERAPOS_FIRST != stInspection.m_nCameraNum)
				{
					MessageBox(STR_MSG_CAMERA_SELECT_FIRST);
				}
				else{
					GetDlgItem(IDC_STATIC_FILEPATH)->SetWindowText(szFilePath);
					pCaptureManager->UpdateInspection(m_eCameraType, szFilePath, &stInspection);

					UpdateCurrentInspectionInfo(m_eCameraType, &stInspection);

					// Update Loaded information
					if (m_dlgStepSize.GetSelectedShotStep() == 0)
						m_dlgStepSize.UpdateCtrlStepSize(&stInspection.m_stSize);
					else if (m_dlgStepSize.GetSelectedShotStep() == 1)
						m_dlgStepSize.UpdateCtrlStepSize(&stInspection.m_stSizeSecond);
					m_dlgStepStain.UpdateCtrlStepStain(&stInspection.m_stStain);
					m_dlgStepDiffer.UpdateCtrlStepDiffer(&stInspection.m_stDiffer);
					m_dlgStepBubble.UpdateCtrlStepBubble(&stInspection.m_stBubble);
					m_dlgStepScratch.UpdateCtrlStepScratch(&stInspection.m_stScratch);
					m_dlgStepStamp.UpdateCtrlStepStamp(&stInspection.m_stStamp);
				}
			}
			else if (TYPE_CAMERAPOS_SECOND == m_eCameraType)
			{
				if (TYPE_CAMERAPOS_SECOND != stInspection.m_nCameraNum)
				{
					MessageBox(STR_MSG_CAMERA_SELECT_SECOND);
				}
				else{
					GetDlgItem(IDC_STATIC_FILEPATH)->SetWindowText(szFilePath);
					pCaptureManager->UpdateInspection(m_eCameraType, szFilePath, &stInspection);

					UpdateCurrentInspectionInfo(m_eCameraType, &stInspection);

					// Update Loaded information
					if (m_dlgStepSize.GetSelectedShotStep() == 0)
						m_dlgStepSize.UpdateCtrlStepSize(&stInspection.m_stSize);
					else if (m_dlgStepSize.GetSelectedShotStep() == 1)
						m_dlgStepSize.UpdateCtrlStepSize(&stInspection.m_stSizeSecond);
					m_dlgStepStain.UpdateCtrlStepStain(&stInspection.m_stStain);
					m_dlgStepDiffer.UpdateCtrlStepDiffer(&stInspection.m_stDiffer);
					m_dlgStepBubble.UpdateCtrlStepBubble(&stInspection.m_stBubble);
					m_dlgStepScratch.UpdateCtrlStepScratch(&stInspection.m_stScratch);
					m_dlgStepStamp.UpdateCtrlStepStamp(&stInspection.m_stStamp);
				}
			}
		}
		else
		{
			MessageBox(STR_MSG_ELOAD_INSPECTION);
		}
	}

}

void CDlgSequence::OnBnClickedBtnSave()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	CString szPath;
	GetDlgItem(IDC_STATIC_FILEPATH)->GetWindowText(szPath);

	const BOOL bExist = CUtil::IsExistFile(szPath);
	if (FALSE == bExist)
	{
		TCHAR szLocation[MAX_PATH] = { 0, };
		TCHAR szFilePath[MAX_PATH] = { 0, };

		CUtil::GetCurrentDirectory(szLocation, MAX_PATH);
		if (CUtil::SelectFile(NULL, szFilePath, MAX_PATH, _T("*.xml"), _T("Insepct Files(*.xml) | *.xml|"), NULL, FALSE))
		{
			szPath = szFilePath;

			const int nLen = CUtil::StringLength(szFilePath);
			if (FALSE == CUtil::StringICompare((szFilePath + nLen - 4), _T(".xml")))
				szPath += _T(".xml");
		}
		else
		{
			return;
		}
	}

	INFO_INSPECTION stCurInfo = GetCurrentInspectionInfo(m_eCameraType);
	BOOL bResult = pCaptureManager->m_Xml.SaveInspection((LPTSTR)(LPCTSTR)szPath, stCurInfo, m_eCameraType);
	if (bResult)
	{
		if (FALSE == bExist)
		{
			GetDlgItem(IDC_STATIC_FILEPATH)->SetWindowText(szPath);
			pCaptureManager->UpdateInspection(m_eCameraType, szPath, &stCurInfo);
		}

		/*//
		m_dlgStepSize.UpdateCtrlStepSize(&stCurInfo.m_stSize);
		m_dlgStepStain.UpdateCtrlStepStain(&stCurInfo.m_stStain);
		m_dlgStepDiffer.UpdateCtrlStepDiffer(&stCurInfo.m_stDiffer);
		m_dlgStepBubble.UpdateCtrlStepBubble(&stCurInfo.m_stBubble);
		m_dlgStepScratch.UpdateCtrlStepScratch(&stCurInfo.m_stScratch);
		m_dlgStepStamp.UpdateCtrlStepStamp(&stCurInfo.m_stStamp);
		//*/
	}

}

void CDlgSequence::OnBnClickedBtnSaveas()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	TCHAR szLocation[MAX_PATH] = { 0, };
	TCHAR szFilePath[MAX_PATH] = { 0, };

	CUtil::GetCurrentDirectory(szLocation, MAX_PATH);
	if (CUtil::SelectFile(NULL, szFilePath, MAX_PATH, _T("*.xml"), _T("Insepct Files(*.xml) | *.xml|"), NULL, FALSE))
	{
		CString szPath = szFilePath;

		const int nLen = CUtil::StringLength(szFilePath);
		if (FALSE == CUtil::StringICompare((szFilePath + nLen - 4), _T(".xml")))
			szPath += _T(".xml");

		INFO_INSPECTION stCurInfo = GetCurrentInspectionInfo(m_eCameraType);
		BOOL bResult = pCaptureManager->m_Xml.SaveInspection((LPTSTR)(LPCTSTR)szPath, stCurInfo, m_eCameraType);
		if (bResult)
		{
			GetDlgItem(IDC_STATIC_FILEPATH)->SetWindowText(szPath);
			pCaptureManager->UpdateInspection(m_eCameraType, (LPTSTR)(LPCTSTR)szPath, &stCurInfo);

			/*//
			m_dlgStepSize.UpdateCtrlStepSize(&stCurInfo.m_stSize);
			m_dlgStepStain.UpdateCtrlStepStain(&stCurInfo.m_stStain);
			m_dlgStepDiffer.UpdateCtrlStepDiffer(&stCurInfo.m_stDiffer);
			m_dlgStepBubble.UpdateCtrlStepBubble(&stCurInfo.m_stBubble);
			m_dlgStepScratch.UpdateCtrlStepScratch(&stCurInfo.m_stScratch);
			m_dlgStepStamp.UpdateCtrlStepStamp(&stCurInfo.m_stStamp);
			//*/
		}
	}
}


void CDlgSequence::OnBnClickedBtnCancel()
{
	this->PostMessage(WM_CLOSE);
}

BOOL CDlgSequence::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	if (MK_CONTROL & nFlags)
	{
		if (m_pCustomView && m_pCustomView->m_hWnd)
		{
			CRect rtView;
			m_pCustomView->GetWindowRect(rtView);

			if (rtView.PtInRect(pt))
				m_pCustomView->OnMouseWheel(nFlags, zDelta, pt);
		}
	}
	return TRUE;
}



// Command Function
LRESULT CDlgSequence::OnMsgGrabEdit(WPARAM wParam, LPARAM lParam)
{
	CWnd* pWnd = this->GetParent();
	if (pWnd)
	{
		pWnd->SendMessage(WM_NOTIFY_GRABEDIT, (WPARAM)m_eCameraType);
	}
	return S_OK;
}

LRESULT CDlgSequence::OnMsgStrobe(WPARAM wParam, LPARAM lParam)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CSerialCtrl* pSerialCtrl = pCaptureManager->GetStrobeControlPort(m_eCameraType);

	const TYPE_STROBE eStrobe = (TYPE_STROBE)lParam;
	if (TYPE_STROBE_COXIAL == eStrobe || TYPE_STROBE_RING == eStrobe || TYPE_STROBE_BAR == eStrobe)
	{
		CDlgStrobeBrightness dlgStrobe;
		dlgStrobe.m_eCameraPos = m_eCameraType;
		dlgStrobe.m_eStrobe = eStrobe;
		if (IDOK == dlgStrobe.DoModal())
		{
			pCaptureManager->ControlStrobeBrightness(pSerialCtrl, m_eCameraType, eStrobe, dlgStrobe.m_nBrightness);
		}
	}
	else if (TYPE_STROBE_OFF == eStrobe)
	{
		pCaptureManager->ControlStrobeBrightness(pSerialCtrl, m_eCameraType, TYPE_STROBE_OFF, 0);
	}
	//pCaptureManager->ControlStrobeOnOff(pSerialCtrl, m_eCameraType, eStrobe);

	return S_OK;
}

LRESULT CDlgSequence::OnMsgRequestImage(WPARAM wParam, LPARAM lParam)
{
	INFO_IMAGE** ppRequest = (INFO_IMAGE**)wParam;
	*ppRequest = m_pCustomView->GetImage();

	return S_OK;
}

// Version 1.3.7.8
LRESULT CDlgSequence::OnMsgRequestResult(WPARAM wParam, LPARAM lParam)
{
	CSampleSide* ppRequest = (CSampleSide*)wParam;
	if (!ppRequest) ppRequest = new CSampleSide();
	ppRequest->CopyFrom(*m_Sample);

	return S_OK;
}

LRESULT CDlgSequence::OnMsgEditStepDone(WPARAM wParam, LPARAM lParam)
{
	const TYPE_STEP eStep = (TYPE_STEP)wParam;

	// Update Display
	m_pCustomView->DisplayStepOutput(eStep, (void*)lParam);
	m_pCustomView->SetFocus();

	{
		if (m_eSelectedStep != eStep &&
			(m_dlgStepSize.m_hWnd && 
			m_dlgStepStain.m_hWnd && 
			m_dlgStepDiffer.m_hWnd &&
			m_dlgStepBubble.m_hWnd &&
			m_dlgStepScratch.m_hWnd &&
			m_dlgStepStamp.m_hWnd))
		{
			SetSelectedStep(eStep);
		}
	}

	return S_OK;
}


LRESULT CDlgSequence::OnMsgStepSizeRoiSelected(WPARAM wParam, LPARAM lParam)
{
	int nCur = (int)wParam;
	m_pCustomView->SelectSteSizeRoi(nCur);

	return S_OK;
}

LRESULT CDlgSequence::OnMsgStepSizeRoiChanged(WPARAM wParam, LPARAM lParam)
{
	if (0xFF == lParam)
	{
		INFO_RECT_ROI *pROI = reinterpret_cast<INFO_RECT_ROI*>(wParam);

		if (m_dlgStepStain.IsWindowVisible())
			m_dlgStepStain.UpdateSelectedRoiPos(pROI);

		else if (m_dlgStepDiffer.IsWindowVisible())
			m_dlgStepDiffer.UpdateSelectedRoiPos(pROI);

		else if (m_dlgStepBubble.IsWindowVisible())
			m_dlgStepBubble.UpdateSelectedRoiPos(pROI);

		else if (m_dlgStepScratch.IsWindowVisible())
			m_dlgStepScratch.UpdateSelectedRoiPos(pROI);

		else if (m_dlgStepStamp.IsWindowVisible())
			m_dlgStepStamp.UpdateSelectedRoiPos(pROI);
	}
	else
	{
		INFO_FINDLINE_ROI *pROI = reinterpret_cast<INFO_FINDLINE_ROI*>(wParam);
		int nCur = (int)lParam;
		if (m_dlgStepSize.IsWindowVisible())
		{
			m_dlgStepSize.UpdateSelectedRoiPos(nCur, pROI);
		}
	}

	return S_OK;
}

void CDlgSequence::UpdateInformation(TYPE_CAMERAPOS eCameraType, const INFO_IMAGE* pImage)
{
	m_eCameraType = eCameraType;
	m_pImagePointer = (INFO_IMAGE*)pImage;

	m_dlgStepSize.UpdateCameraPos(eCameraType);
	m_dlgStepStain.UpdateCameraPos(eCameraType);
	m_dlgStepDiffer.UpdateCameraPos(eCameraType);
	m_dlgStepBubble.UpdateCameraPos(eCameraType);
	m_dlgStepScratch.UpdateCameraPos(eCameraType);
	m_dlgStepStamp.UpdateCameraPos(eCameraType);
}

// Version 1.3.7.8
void CDlgSequence::UpdateInformation(TYPE_CAMERAPOS eCameraType, CSampleSide* sample, const INFO_IMAGE* pImage, const INFO_IMAGE* pImage1, const INFO_IMAGE* pImage2)
{
	m_eCameraType = eCameraType;
	m_pImagePointer = (INFO_IMAGE*)pImage;
	m_pImagePointer1 = (INFO_IMAGE*)pImage1;
	m_pImagePointer2 = (INFO_IMAGE*)pImage2;
	if (!m_Sample) m_Sample.reset(new CSampleSide());
	m_Sample->CopyFrom(*sample);

	m_dlgStepSize.UpdateCameraPos(eCameraType);
	m_dlgStepStain.UpdateCameraPos(eCameraType);
	m_dlgStepDiffer.UpdateCameraPos(eCameraType);
	m_dlgStepBubble.UpdateCameraPos(eCameraType);
	m_dlgStepScratch.UpdateCameraPos(eCameraType);
	m_dlgStepStamp.UpdateCameraPos(eCameraType);
}

void CDlgSequence::DisplayImage(const INFO_IMAGE* pImage)
{
	m_pCustomView->DisplayImage(pImage);
}

INFO_INSPECTION CDlgSequence::GetCurrentInspectionInfo(TYPE_CAMERAPOS ePos)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	// Get Current information....
	INFO_INSPECTION stInspection;
	memset(&stInspection, 0x00, sizeof(INFO_INSPECTION));
	stInspection.m_bInit = TRUE;

	// Size
#ifdef DEF_SECONDCAMERA_CHECKSIZE
	// do nothing..
#else
	if (TYPE_CAMERAPOS_FIRST == m_eCameraType)
#endif
	{
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraType, TYPE_STEP_001);
		CStepSize* pStepSize = dynamic_cast<CStepSize*>(pStep);
		if (pStepSize)
		{
			pStepSize->Get(&stInspection);
		}
	}
	// Stain
	{
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraType, TYPE_STEP_002);
		CStepStain* pStepStain = dynamic_cast<CStepStain*>(pStep);
		if (pStepStain)
		{
			pStepStain->Get(&stInspection);
		}
	}
	// Differ
	{
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraType, TYPE_STEP_003);
		CStepDiffer* pStepDiffer = dynamic_cast<CStepDiffer*>(pStep);
		if (pStepDiffer)
		{
			pStepDiffer->Get(&stInspection);
		}
	}
	// Bubble
	{
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraType, TYPE_STEP_004);
		CStepBubble* pStepBubble = dynamic_cast<CStepBubble*>(pStep);
		if (pStepBubble)
		{
			pStepBubble->Get(&stInspection);
		}
	}
	// Scratch
	{
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraType, TYPE_STEP_005);
		CStepScratch* pStepScratch = dynamic_cast<CStepScratch*>(pStep);
		if (pStepScratch)
		{
			pStepScratch->Get(&stInspection);
		}
	}
	// Stamp
	{
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraType, TYPE_STEP_006);
		CStepStamp* pStepStamp = dynamic_cast<CStepStamp*>(pStep);
		if (pStepStamp)
		{
			pStepStamp->Get(&stInspection);
		}
	}
	// SizeSecond
	{
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraType, TYPE_STEP_007);
		CStepSizeSecond* pStepSizeSecond = dynamic_cast<CStepSizeSecond*>(pStep);
		if (pStepSizeSecond)
		{
			pStepSizeSecond->Get(&stInspection);
		}
	}
	// SizeCalc
	{
		CInspectionCamera* pCamera = pInspection->GetInspectionCamera(m_eCameraType);
		if (pCamera)
		{
			CStepSizeCalculation* pStepCalc = pCamera->GetStepSizeCalc();
			if (pStepCalc)
			{
				pStepCalc->Get(&stInspection);
			}
		}
	}
	
	return stInspection;
}

BOOL CDlgSequence::UpdateCurrentInspectionInfo(TYPE_CAMERAPOS ePos, const INFO_INSPECTION* pstInspection)
{
	if (NULL == pstInspection)
		return FALSE;

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	// Size
#ifdef DEF_SECONDCAMERA_CHECKSIZE
	// do nothing..
#else
	if (TYPE_CAMERAPOS_FIRST == m_eCameraType)
#endif
	{
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraType, TYPE_STEP_001);
		CStepSize* pStepSize = dynamic_cast<CStepSize*>(pStep);
		if (pStepSize)
		{
			pStepSize->Set(pstInspection);
		}
	}
	// Stain
	{
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraType, TYPE_STEP_002);
		CStepStain* pStepStain = dynamic_cast<CStepStain*>(pStep);
		if (pStepStain)
		{
			pStepStain->Set(pstInspection);
		}
	}
	// Differ
	{
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraType, TYPE_STEP_003);
		CStepDiffer* pStepDiffer = dynamic_cast<CStepDiffer*>(pStep);
		if (pStepDiffer)
		{
			pStepDiffer->Set(pstInspection);
		}
	}
	// Bubble
	{
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraType, TYPE_STEP_004);
		CStepBubble* pStepBubble = dynamic_cast<CStepBubble*>(pStep);
		if (pStepBubble)
		{
			pStepBubble->Set(pstInspection);
		}
	}
	// Scratch
	{
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraType, TYPE_STEP_005);
		CStepScratch* pStepScratch = dynamic_cast<CStepScratch*>(pStep);
		if (pStepScratch)
		{
			pStepScratch->Set(pstInspection);
		}
	}
	// Stamp
	{
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraType, TYPE_STEP_006);
		CStepStamp* pStepStamp = dynamic_cast<CStepStamp*>(pStep);
		if (pStepStamp)
		{
			pStepStamp->Set(pstInspection);
		}
	}
	// SizeSecond
	{
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraType, TYPE_STEP_007);
		CStepSizeSecond* pStepSizeSecond = dynamic_cast<CStepSizeSecond*>(pStep);
		if (pStepSizeSecond)
		{
			pStepSizeSecond->Set(pstInspection);
		}
	}
	// SizeCalc
	{
		CInspectionCamera* pCamera = pInspection->GetInspectionCamera(m_eCameraType);
		if (pCamera)
		{
			CStepSizeCalculation* pStepCalc = pCamera->GetStepSizeCalc();
			if (pStepCalc)
			{
				pStepCalc->Set(pstInspection);
			}
		}
	}



	return TRUE;
}

void CDlgSequence::UpdateTitleStep()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

#ifdef DEF_SECONDCAMERA_CHECKSIZE
	const TCHAR* pStep01Title = pCaptureManager->GetTitleStep(TYPE_CAMERAPOS_FIRST, TYPE_STEP_001);
#else
	const TCHAR* pStep01Title = pCaptureManager->GetTitleStep(m_eCameraType, TYPE_STEP_001);
#endif
	m_pStepList[TYPE_STEP_001]->SetMessage((TCHAR*)pStep01Title);

	const TCHAR* pStep02Title = pCaptureManager->GetTitleStep(m_eCameraType, TYPE_STEP_002);
	m_pStepList[TYPE_STEP_002]->SetMessage((TCHAR*)pStep02Title);

	const TCHAR* pStep03Title = pCaptureManager->GetTitleStep(m_eCameraType, TYPE_STEP_003);
	m_pStepList[TYPE_STEP_003]->SetMessage((TCHAR*)pStep03Title);

	const TCHAR* pStep04Title = pCaptureManager->GetTitleStep(m_eCameraType, TYPE_STEP_004);
	m_pStepList[TYPE_STEP_004]->SetMessage((TCHAR*)pStep04Title);

	const TCHAR* pStep05Title = pCaptureManager->GetTitleStep(m_eCameraType, TYPE_STEP_005);
	m_pStepList[TYPE_STEP_005]->SetMessage((TCHAR*)pStep05Title);

	const TCHAR* pStep06Title = pCaptureManager->GetTitleStep(m_eCameraType, TYPE_STEP_006);
	m_pStepList[TYPE_STEP_006]->SetMessage((TCHAR*)pStep06Title);

	/*const TCHAR* pStep07Title = pCaptureManager->GetTitleStep(m_eCameraType, TYPE_STEP_007);
	m_pStepList[TYPE_STEP_007]->SetMessage((TCHAR*)pStep07Title);*/
}