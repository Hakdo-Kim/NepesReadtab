// TapMainSummary.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "TapMainSummary.h"
#include "afxdialogex.h"
#include "DlgLotID.h"
#include "DlgLotIDOnce.h"

#include "CaptureManager.h"

#include "Util/Util.h"
#include "stringres.h"


// CTapMainSummary dialog

IMPLEMENT_DYNAMIC(CTapMainSummary, CDialogEx)

CTapMainSummary::CTapMainSummary(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTapMainSummary::IDD, pParent)
{
	memset(&m_rtView, 0x00, sizeof(RECT));
	memset(&m_rtFirstView, 0x00, sizeof(RECT));
	memset(&m_rtSecondView, 0x00, sizeof(RECT));

}

CTapMainSummary::~CTapMainSummary()
{
}

void CTapMainSummary::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_TITLESAMPLE_TOTAL, m_ctlTitleSampleTotal);
	DDX_Control(pDX, IDC_STATIC_TITLESAMPLEA, m_ctlTitleSampleFirst);
	DDX_Control(pDX, IDC_STATIC_TITLESAMPLEB, m_ctlTitleSampleSecond);
	DDX_Control(pDX, IDC_STATIC_ERRORSHAPE_SAMPLE_A, m_ctlErrorShapeSampleFirst);
	DDX_Control(pDX, IDC_STATIC_ERRORSHAPE_SAMPLE_B, m_ctlErrorShapeSampleSecond);
	DDX_Control(pDX, IDC_STATIC_ERRORSIZE_SAMPLE_A, m_ctlErrorSizeSampleFirst);
	DDX_Control(pDX, IDC_STATIC_ERRORSIZE_SAMPLE_B, m_ctlErrorSizeSampleSecond);
	DDX_Control(pDX, IDC_LIST_COUNT_SAMPLE_TOTAL, m_ctlListCountSampleTotal);
	DDX_Control(pDX, IDC_LIST_COUNT_SAMPLE_A, m_ctlListCountSampleFirst);
	DDX_Control(pDX, IDC_LIST_COUNT_SAMPLE_B, m_ctlListCountSampleSecond);
	DDX_Control(pDX, IDC_LIST_ERRORSHAPE_SAMPLE_A, m_ctlListErrorShapeSampleFirst);
	DDX_Control(pDX, IDC_LIST_ERRORSHAPE_SAMPLE_B, m_ctlListErrorShapeSampleSecond);
	DDX_Control(pDX, IDC_LIST_ERRORSIZE_SAMPLE_A, m_ctlListErrorSizeSampleFirst);
	DDX_Control(pDX, IDC_LIST_ERRORSIZE_SAMPLE_B, m_ctlListErrorSizeSampleSecond);
}

BOOL CTapMainSummary::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (IDOK == wParam)
	{
		return TRUE;
	}
	return CDialogEx::OnCommand(wParam, lParam);
}

BOOL CTapMainSummary::PreTranslateMessage(MSG* pMsg)
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

BOOL CTapMainSummary::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	m_ctlTitleSampleTotal.SetTextFont(_T("MS Shell Dlg"), 20, FW_BOLD);
	m_ctlTitleSampleFirst.SetTextFont(_T("MS Shell Dlg"), 20, FW_BOLD);
	m_ctlTitleSampleSecond.SetTextFont(_T("MS Shell Dlg"), 20, FW_BOLD);

	m_ctlErrorShapeSampleFirst.SetTextFont(_T("MS Shell Dlg"), 20, FW_BOLD);
	m_ctlErrorShapeSampleSecond.SetTextFont(_T("MS Shell Dlg"), 20, FW_BOLD);
	m_ctlErrorSizeSampleFirst.SetTextFont(_T("MS Shell Dlg"), 20, FW_BOLD);
	m_ctlErrorSizeSampleSecond.SetTextFont(_T("MS Shell Dlg"), 20, FW_BOLD);

	m_ctlTitleSampleTotal.SetMessage(STR_TAPVIEW_SUMMARY_SAMPLE_TOTAL);
	m_ctlTitleSampleFirst.SetMessage(STR_TAPVIEW_SUMMARY_SAMPLEA);
	m_ctlTitleSampleSecond.SetMessage(STR_TAPVIEW_SUMMARY_SAMPLEB);

	m_ctlErrorShapeSampleFirst.SetMessage(STR_TAPVIEW_SUMMARY_ERRORSHAPE_SAMPLEA);
	m_ctlErrorShapeSampleSecond.SetMessage(STR_TAPVIEW_SUMMARY_ERRORSHAPE_SAMPLEB);
	m_ctlErrorSizeSampleFirst.SetMessage(STR_TAPVIEW_SUMMARY_ERRORSIZE_SAMPLEA);
	m_ctlErrorSizeSampleSecond.SetMessage(STR_TAPVIEW_SUMMARY_ERRORSIZE_SAMPLEB);

	m_ctlTitleSampleTotal.SetMessage(STR_TAPVIEW_SUMMARY_SAMPLE_TOTAL);
	m_ctlTitleSampleFirst.SetMessage(STR_TAPVIEW_SUMMARY_SAMPLE_FIRST);
	m_ctlTitleSampleSecond.SetMessage(STR_TAPVIEW_SUMMARY_SAMPLE_SECOND);

	m_ctlErrorShapeSampleFirst.SetMessage(STR_TAPVIEW_SUMMARY_ERRORSHAPE_SAMPLE_FIRST);
	m_ctlErrorShapeSampleSecond.SetMessage(STR_TAPVIEW_SUMMARY_ERRORSHAPE_SAMPLE_SECOND);
	m_ctlErrorSizeSampleFirst.SetMessage(STR_TAPVIEW_SUMMARY_ERRORSIZE_SAMPLE_FIRST);
	m_ctlErrorSizeSampleSecond.SetMessage(STR_TAPVIEW_SUMMARY_ERRORSIZE_SAMPLE_SECOND);

	GetDlgItem(IDC_BTN_LOTID_SAMPLE_A)->SetWindowText(STR_SUMMARY_BTN_LOTID);
	//GetDlgItem(IDC_BTN_LOTID_SAMPLE_B)->SetWindowText(STR_SUMMARY_BTN_LOTID);

	GetDlgItem(IDC_RADIO_SUMMARYTOTAL)->SetWindowText(STR_TAPVIEW_SUMMARY_SAMPLE_TOTAL);
	GetDlgItem(IDC_RADIO_SUMMARYCOUNT)->SetWindowText(STR_TAPVIEW_SUMMARY_SAMPLE_COUNT);

	((CButton*)GetDlgItem(IDC_RADIO_SUMMARYTOTAL))->SetCheck(BST_CHECKED);


	// List Control
	m_ctlListCountSampleTotal.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_ctlListCountSampleFirst.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_ctlListCountSampleSecond.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_ctlListErrorShapeSampleFirst.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_ctlListErrorShapeSampleSecond.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_ctlListErrorSizeSampleFirst.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_ctlListErrorSizeSampleSecond.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	const TCHAR* pTitleStep2 = pCaptureManager->GetTitleStep(TYPE_CAMERAPOS_FIRST, TYPE_STEP_002);
	const TCHAR* pTitleStep3 = pCaptureManager->GetTitleStep(TYPE_CAMERAPOS_FIRST, TYPE_STEP_003);
	const TCHAR* pTitleStep4 = pCaptureManager->GetTitleStep(TYPE_CAMERAPOS_FIRST, TYPE_STEP_004);
	const TCHAR* pTitleStep5 = pCaptureManager->GetTitleStep(TYPE_CAMERAPOS_FIRST, TYPE_STEP_005);
	const TCHAR* pTitleStep6 = pCaptureManager->GetTitleStep(TYPE_CAMERAPOS_FIRST, TYPE_STEP_006);

	int idx = 0;
	// Insert Column
	idx = 0;
	m_ctlListCountSampleTotal.InsertColumn(idx, _T(""), LVCFMT_LEFT, 100, -1);							idx++;
	m_ctlListCountSampleTotal.InsertColumn(idx, STR_SUMMARY_COL_COUNT, LVCFMT_LEFT, 150, -1);			idx++;
	m_ctlListCountSampleTotal.InsertColumn(idx, STR_SUMMARY_COL_ERRORRATIO, LVCFMT_LEFT, 150, -1);		idx++;

	idx = 0;
	m_ctlListCountSampleFirst.InsertColumn(idx, _T(""), LVCFMT_LEFT, 100, -1);							idx++;
	m_ctlListCountSampleFirst.InsertColumn(idx, STR_SUMMARY_COL_COUNT, LVCFMT_LEFT, 150, -1);			idx++;
	m_ctlListCountSampleFirst.InsertColumn(idx, STR_SUMMARY_COL_ERRORRATIO, LVCFMT_LEFT, 150, -1);		idx++;

	idx = 0;
	m_ctlListCountSampleSecond.InsertColumn(idx, _T(""), LVCFMT_LEFT, 100, -1);							idx++;
	m_ctlListCountSampleSecond.InsertColumn(idx, STR_SUMMARY_COL_COUNT, LVCFMT_LEFT, 150, -1);			idx++;
	m_ctlListCountSampleSecond.InsertColumn(idx, STR_SUMMARY_COL_ERRORRATIO, LVCFMT_LEFT, 150, -1);		idx++;

	idx = 0;
	m_ctlListErrorShapeSampleFirst.InsertColumn(idx, pTitleStep2, LVCFMT_LEFT, 70, -1);		idx++;
	m_ctlListErrorShapeSampleFirst.InsertColumn(idx, pTitleStep3, LVCFMT_LEFT, 70, -1);		idx++;
	m_ctlListErrorShapeSampleFirst.InsertColumn(idx, pTitleStep4, LVCFMT_LEFT, 70, -1);		idx++;
	m_ctlListErrorShapeSampleFirst.InsertColumn(idx, pTitleStep5, LVCFMT_LEFT, 70, -1);		idx++;
	m_ctlListErrorShapeSampleFirst.InsertColumn(idx, pTitleStep6, LVCFMT_LEFT, 70, -1);		idx++;
	m_ctlListErrorShapeSampleFirst.InsertColumn(idx, STR_SUMMARY_COL_ETC, LVCFMT_LEFT, 70, -1);			idx++;

	idx = 0;
	m_ctlListErrorShapeSampleSecond.InsertColumn(idx, pTitleStep2, LVCFMT_LEFT, 70, -1);		idx++;
	m_ctlListErrorShapeSampleSecond.InsertColumn(idx, pTitleStep3, LVCFMT_LEFT, 70, -1);		idx++;
	m_ctlListErrorShapeSampleSecond.InsertColumn(idx, pTitleStep4, LVCFMT_LEFT, 70, -1);		idx++;
	m_ctlListErrorShapeSampleSecond.InsertColumn(idx, pTitleStep5, LVCFMT_LEFT, 70, -1);		idx++;
	m_ctlListErrorShapeSampleSecond.InsertColumn(idx, pTitleStep6, LVCFMT_LEFT, 70, -1);		idx++;
	m_ctlListErrorShapeSampleSecond.InsertColumn(idx, STR_SUMMARY_COL_ETC, LVCFMT_LEFT, 70, -1);			idx++;

	idx = 0;
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3 // Size 50 -> 30
	m_ctlListErrorSizeSampleFirst.InsertColumn(idx, STR_SIZEMEASURE_01, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleFirst.InsertColumn(idx, STR_SIZEMEASURE_02, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleFirst.InsertColumn(idx, STR_SIZEMEASURE_03, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleFirst.InsertColumn(idx, STR_SIZEMEASURE_04, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleFirst.InsertColumn(idx, STR_SIZEMEASURE_05, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleFirst.InsertColumn(idx, STR_SIZEMEASURE_06, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleFirst.InsertColumn(idx, STR_SIZEMEASURE_07, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleFirst.InsertColumn(idx, STR_SIZEMEASURE_08, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleFirst.InsertColumn(idx, STR_SIZEMEASURE_09, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleFirst.InsertColumn(idx, STR_SIZEMEASURE_10, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleFirst.InsertColumn(idx, STR_SIZEMEASURE_11, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleFirst.InsertColumn(idx, STR_SIZEMEASURE_12, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleFirst.InsertColumn(idx, STR_SIZEMEASURE_13, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleFirst.InsertColumn(idx, STR_SIZEMEASURE_14, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleFirst.InsertColumn(idx, STR_SIZEMEASURE_15, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleFirst.InsertColumn(idx, STR_SIZEMEASURE_16, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleFirst.InsertColumn(idx, STR_SIZEMEASURE_17, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleFirst.InsertColumn(idx, STR_SIZEMEASURE_18, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleFirst.InsertColumn(idx, STR_SIZEMEASURE_19, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleFirst.InsertColumn(idx, STR_SIZEMEASURE_20, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleFirst.InsertColumn(idx, STR_SIZEMEASURE_21, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleFirst.InsertColumn(idx, STR_SIZEMEASURE_22, LVCFMT_LEFT, 35, -1);			idx++;
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3											  
	m_ctlListErrorSizeSampleFirst.InsertColumn(idx, STR_SIZEMEASURE_23, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleFirst.InsertColumn(idx, STR_SIZEMEASURE_24, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleFirst.InsertColumn(idx, STR_SIZEMEASURE_25, LVCFMT_LEFT, 55, -1);			idx++;
	m_ctlListErrorSizeSampleFirst.InsertColumn(idx, STR_SIZEMEASURE_26, LVCFMT_LEFT, 55, -1);			idx++;
	m_ctlListErrorSizeSampleFirst.InsertColumn(idx, STR_SIZEMEASURE_27, LVCFMT_LEFT, 55, -1);			idx++;
	m_ctlListErrorSizeSampleFirst.InsertColumn(idx, STR_SIZEMEASURE_28, LVCFMT_LEFT, 55, -1);			idx++;
	// Version 1.3.8.0 Resin Count Add (First)

	idx = 0;
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3 // Size 50 -> 30
	m_ctlListErrorSizeSampleSecond.InsertColumn(idx, STR_SIZEMEASURE_01, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleSecond.InsertColumn(idx, STR_SIZEMEASURE_02, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleSecond.InsertColumn(idx, STR_SIZEMEASURE_03, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleSecond.InsertColumn(idx, STR_SIZEMEASURE_04, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleSecond.InsertColumn(idx, STR_SIZEMEASURE_05, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleSecond.InsertColumn(idx, STR_SIZEMEASURE_06, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleSecond.InsertColumn(idx, STR_SIZEMEASURE_07, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleSecond.InsertColumn(idx, STR_SIZEMEASURE_08, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleSecond.InsertColumn(idx, STR_SIZEMEASURE_09, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleSecond.InsertColumn(idx, STR_SIZEMEASURE_10, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleSecond.InsertColumn(idx, STR_SIZEMEASURE_11, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleSecond.InsertColumn(idx, STR_SIZEMEASURE_12, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleSecond.InsertColumn(idx, STR_SIZEMEASURE_13, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleSecond.InsertColumn(idx, STR_SIZEMEASURE_14, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleSecond.InsertColumn(idx, STR_SIZEMEASURE_15, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleSecond.InsertColumn(idx, STR_SIZEMEASURE_16, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleSecond.InsertColumn(idx, STR_SIZEMEASURE_17, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleSecond.InsertColumn(idx, STR_SIZEMEASURE_18, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleSecond.InsertColumn(idx, STR_SIZEMEASURE_19, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleSecond.InsertColumn(idx, STR_SIZEMEASURE_20, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleSecond.InsertColumn(idx, STR_SIZEMEASURE_21, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleSecond.InsertColumn(idx, STR_SIZEMEASURE_22, LVCFMT_LEFT, 35, -1);			idx++;
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3											   
	m_ctlListErrorSizeSampleSecond.InsertColumn(idx, STR_SIZEMEASURE_23, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleSecond.InsertColumn(idx, STR_SIZEMEASURE_24, LVCFMT_LEFT, 35, -1);			idx++;
	m_ctlListErrorSizeSampleSecond.InsertColumn(idx, STR_SIZEMEASURE_25, LVCFMT_LEFT, 55, -1);			idx++;
	m_ctlListErrorSizeSampleSecond.InsertColumn(idx, STR_SIZEMEASURE_26, LVCFMT_LEFT, 55, -1);			idx++;
	m_ctlListErrorSizeSampleSecond.InsertColumn(idx, STR_SIZEMEASURE_27, LVCFMT_LEFT, 55, -1);			idx++;
	m_ctlListErrorSizeSampleSecond.InsertColumn(idx, STR_SIZEMEASURE_28, LVCFMT_LEFT, 55, -1);			idx++;


	// Add Item Title
	idx = 0;
	m_ctlListCountSampleTotal.InsertItem(idx, STR_SUMMARY_ROW_TOTAL);			idx++;
	m_ctlListCountSampleTotal.InsertItem(idx, STR_SUMMARY_ROW_ERRORSIZE);		idx++;
	m_ctlListCountSampleTotal.InsertItem(idx, STR_SUMMARY_ROW_ERRORSHAPE);		idx++;

	idx = 0;
	m_ctlListCountSampleFirst.InsertItem(idx, STR_SUMMARY_ROW_TOTAL);			idx++;
	m_ctlListCountSampleFirst.InsertItem(idx, STR_SUMMARY_ROW_ERRORSIZE);		idx++;
	m_ctlListCountSampleFirst.InsertItem(idx, STR_SUMMARY_ROW_ERRORSHAPE);		idx++;

	idx = 0;
	m_ctlListCountSampleSecond.InsertItem(idx, STR_SUMMARY_ROW_TOTAL);			idx++;
	m_ctlListCountSampleSecond.InsertItem(idx, STR_SUMMARY_ROW_ERRORSIZE);		idx++;
	m_ctlListCountSampleSecond.InsertItem(idx, STR_SUMMARY_ROW_ERRORSHAPE);		idx++;

	m_ctlListErrorShapeSampleFirst.InsertItem(0, _T(""));
	m_ctlListErrorShapeSampleSecond.InsertItem(0, _T(""));

	m_ctlListErrorSizeSampleFirst.InsertItem(0, _T(""));
	m_ctlListErrorSizeSampleSecond.InsertItem(0, _T(""));

	

	UpdateSummary();
	UpdateTotalSummary();
	UpdateSizeName();
	AdjustLayout();
	return TRUE;  // return TRUE  unless you set the focus to a control
}



BEGIN_MESSAGE_MAP(CTapMainSummary, CDialogEx)
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BTN_LOTID_SAMPLE_A, &CTapMainSummary::OnBnClickedBtnLotidSample)
	ON_BN_CLICKED(IDC_BTN_SUMMARYCOUNT_RESET, &CTapMainSummary::OnBnClickedBtnSummarycountReset)
	ON_BN_CLICKED(IDC_RADIO_SUMMARYTOTAL, &CTapMainSummary::OnBnClickedRadioSummarytotal)
	ON_BN_CLICKED(IDC_RADIO_SUMMARYCOUNT, &CTapMainSummary::OnBnClickedRadioSummarycount)
END_MESSAGE_MAP()


// CTapMainSummary message handlers
void CTapMainSummary::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	AdjustLayout();
	this->Invalidate();
}

void CTapMainSummary::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CRect rect;
	GetClientRect(&rect);

	const int nClientWidth = rect.Width();
	const int nClientHeight = rect.Height();


	
	DrawLayout(&dc, m_rtView, RGB(200, 200, 200), IDB_STATIC_GUARD_LEFTTOP, IDB_STATIC_GUARD_LEFTBOTTOM, IDB_STATIC_GUARD_RIGHTTOP, IDB_STATIC_GUARD_RIGHTBOTTOM);

	CDialogEx::OnPaint();
}





void CTapMainSummary::AdjustLayout()
{
	if (NULL == m_ctlTitleSampleFirst.GetSafeHwnd() || NULL == m_ctlTitleSampleSecond.GetSafeHwnd())
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

	const int cx = (m_rtView.right - m_rtView.left - MARGIN) / 2;

	m_rtFirstView = m_rtView;
	m_rtFirstView.left = MARGIN;
	m_rtFirstView.right = m_rtFirstView.left + cx;

	m_rtSecondView = m_rtView;
	m_rtSecondView.left = m_rtSecondView.right - cx;


	RECT rtTitleSampleTotal;

	RECT rtTitleSampleA;
	RECT rtTitleSampleB;

	RECT rtListSampleA;
	RECT rtListSampleB;

	{
		RECT rtTemp;
		RECT rtBtn;
		GetDlgItem(IDC_BTN_LOTID_SAMPLE_A)->GetClientRect(&rtBtn);

		rtTemp.left = m_rtFirstView.left + MARGIN * 2;
		rtTemp.top = m_rtFirstView.top + MARGIN * 2;
		rtTemp.right = rtTemp.left + (rtBtn.right - rtBtn.left);
		rtTemp.bottom = rtTemp.top + (rtBtn.bottom - rtBtn.top);
		GetDlgItem(IDC_BTN_LOTID_SAMPLE_A)->MoveWindow(&rtTemp);
		
		long tempSize = rtTemp.right - rtTemp.left;
		rtTemp.right = m_rtSecondView.right - MARGIN * 2;
		rtTemp.left = rtTemp.right - tempSize;
		GetDlgItem(IDC_BTN_SUMMARYCOUNT_RESET)->MoveWindow(&rtTemp);

		GetDlgItem(IDC_RADIO_SUMMARYCOUNT)->GetClientRect(&rtBtn);
		rtTemp.right = rtTemp.left - MARGIN * 2;
		rtTemp.left = rtTemp.right - (rtBtn.right - rtBtn.left);
		GetDlgItem(IDC_RADIO_SUMMARYCOUNT)->MoveWindow(&rtTemp);
		
		GetDlgItem(IDC_RADIO_SUMMARYTOTAL)->GetClientRect(&rtBtn);
		rtTemp.right = rtTemp.left - MARGIN * 2;
		rtTemp.left = rtTemp.right - (rtBtn.right - rtBtn.left);
		GetDlgItem(IDC_RADIO_SUMMARYTOTAL)->MoveWindow(&rtTemp);

		GetDlgItem(IDC_BTN_LOTID_SAMPLE_A)->GetClientRect(&rtBtn);
		rtTemp.right = rtTemp.left - MARGIN * 2;
		rtTemp.left = rtBtn.right + MARGIN * 4;
		GetDlgItem(IDC_EDIT_LOTID_SAMPLE_A)->MoveWindow(&rtTemp);

		rtTemp.top = rtTemp.bottom + MARGIN * 3;
		rtTemp.bottom = rtTemp.top + MARGIN * 6;
		rtTemp.left = m_rtFirstView.left + MARGIN * 2;
		rtTemp.right = m_rtSecondView.right - MARGIN * 2;
		m_ctlTitleSampleTotal.MoveWindow(&rtTemp);
		rtTitleSampleTotal = rtTemp;

		rtTemp.top = rtTemp.bottom + MARGIN * 3;
		rtTemp.bottom = rtTemp.top + MARGIN * 18;
		m_ctlListCountSampleTotal.MoveWindow(&rtTemp);

		rtTemp.left = m_rtFirstView.left + MARGIN * 2;
		rtTemp.top = rtTemp.bottom + MARGIN * 3;
		rtTemp.right = m_rtFirstView.right - MARGIN * 2;
		rtTemp.bottom = rtTemp.top + MARGIN * 6;
		m_ctlTitleSampleFirst.MoveWindow(&rtTemp);
		rtTitleSampleA = rtTemp;

		rtTemp.left = m_rtSecondView.left + MARGIN * 2;
		rtTemp.top = rtTitleSampleA.top;
		rtTemp.right = m_rtSecondView.right - MARGIN * 2;
		rtTemp.bottom = rtTitleSampleA.bottom;
		m_ctlTitleSampleSecond.MoveWindow(&rtTemp);
		rtTitleSampleB = rtTemp;


		rtTemp.left = rtTitleSampleA.left;
		rtTemp.right = rtTitleSampleA.right;
		rtTemp.top = rtTemp.bottom + MARGIN * 3;
		rtTemp.bottom = rtTemp.top + MARGIN * 18;
		m_ctlListCountSampleFirst.MoveWindow(&rtTemp);
		rtListSampleA = rtTemp;

		rtTemp.left = rtTitleSampleB.left;
		rtTemp.right = rtTitleSampleB.right;
		m_ctlListCountSampleSecond.MoveWindow(&rtTemp);
		rtListSampleB = rtTemp;
	}

	RECT rtEShapeSampleFirst;
	RECT rtEShapeSampleSecond;

	RECT rtEShapeSampleA;
	RECT rtEShapeSampleB;

	{
		RECT rtTemp;

		rtTemp.left = rtListSampleA.left;
		rtTemp.right = rtListSampleA.right;
		rtTemp.top = rtListSampleA.bottom + MARGIN * 5;
		rtTemp.bottom = rtTemp.top + MARGIN * 6;
		m_ctlErrorShapeSampleFirst.MoveWindow(&rtTemp);

		rtTemp.top = rtTemp.bottom + MARGIN * 3;
		rtTemp.bottom = rtTemp.top + MARGIN * 11;
		m_ctlListErrorShapeSampleFirst.MoveWindow(&rtTemp);
		rtEShapeSampleA = rtTemp;


		rtTemp.left = rtListSampleB.left;
		rtTemp.right = rtListSampleB.right;
		rtTemp.top = rtListSampleB.bottom + MARGIN * 5;
		rtTemp.bottom = rtTemp.top + MARGIN * 6;
		m_ctlErrorShapeSampleSecond.MoveWindow(&rtTemp);

		rtTemp.top = rtTemp.bottom + MARGIN * 3;
		rtTemp.bottom = rtTemp.top + MARGIN * 11;
		m_ctlListErrorShapeSampleSecond.MoveWindow(&rtTemp);
		rtEShapeSampleB = rtTemp;
	}

	{
		RECT rtTemp;

		rtTemp.left = rtClient.left + MARGIN * 2;
		rtTemp.right = rtClient.right - MARGIN * 2;
		rtTemp.top = rtEShapeSampleA.bottom + MARGIN * 5;
		rtTemp.bottom = rtTemp.top + MARGIN * 6;
		m_ctlErrorSizeSampleFirst.MoveWindow(&rtTemp);

		rtTemp.top = rtTemp.bottom + MARGIN * 3;
		rtTemp.bottom = rtTemp.top + MARGIN * 11;
		m_ctlListErrorSizeSampleFirst.MoveWindow(&rtTemp);


		rtTemp.top = rtTemp.bottom + MARGIN * 3;
		rtTemp.bottom = rtTemp.top + MARGIN * 6;
		m_ctlErrorSizeSampleSecond.MoveWindow(&rtTemp);

		rtTemp.top = rtTemp.bottom + MARGIN * 3;
		rtTemp.bottom = rtTemp.top + MARGIN * 11;
		m_ctlListErrorSizeSampleSecond.MoveWindow(&rtTemp);
	}
}

void CTapMainSummary::DrawLayout(CDC* pDC, CRect rect, COLORREF rgbBk, DWORD dwLT, DWORD dwLB, DWORD dwRT, DWORD dwRB)
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

void CTapMainSummary::OnBnClickedBtnLotidSample()
{
	ChangeLotid();
}


void CTapMainSummary::ChangeLotid()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	INFO_SUMMARY* pstSummary = pCaptureManager->GetResultSummary();
	INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();

	if (0 < CUtil::StringLength(pstSummary->m_szLotId))
	{
		if (IDCANCEL == AfxMessageBox(STR_MSG_CHANGE_LOTID, MB_OKCANCEL))
			return;

		const INFO_OPTIONETC* pstOptEtc = pCaptureManager->GetOptionEtc();
		// Save summary
		TCHAR szSummaryPath[MAX_FILE_PATH_LEN] = { 0, };

		SYSTEMTIME stTime;
		::GetLocalTime(&stTime);
		CUtil::StringFormat(szSummaryPath, MAX_FILE_PATH_LEN, _T("%s\\%04d%02d%02d_%02d%02d%02d_lotid_%s.csv"),
			pstOptEtc->m_szLotIdPath,
			stTime.wYear, stTime.wMonth, stTime.wDay, stTime.wHour, stTime.wMinute, stTime.wSecond,
			pstSummary->m_szLotId);

		SaveSummary(szSummaryPath, &pstSummary->m_stSummaryFirst, &pstSummary->m_stSummarySecond);

		// Print Log
		{
			if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
			{
				stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Save LotID (%s)", pstSummary->m_szLotId);
				stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "File Path (%s)", szSummaryPath);
			}
		}
	}

	CDlgLotID dlgLotID;
	dlgLotID.m_szLotID = pstSummary->m_szLotId;

	if (IDOK == dlgLotID.DoModal())
	{
		memset(&pstSummary->m_stSummaryFirst, 0x00, sizeof(INFO_SUMMARY_SAMPLE));
		memset(&pstSummary->m_stSummarySecond, 0x00, sizeof(INFO_SUMMARY_SAMPLE));
		memset(&pstSummary->m_stSummaryTotal, 0x00, sizeof(INFO_SUMMARY_TOTAL));
		memset(&SummaryCount.m_stSummaryFirst, 0x00, sizeof(INFO_SUMMARY_SAMPLE));
		memset(&SummaryCount.m_stSummarySecond, 0x00, sizeof(INFO_SUMMARY_SAMPLE));
		memset(&SummaryCount.m_stSummaryTotal, 0x00, sizeof(INFO_SUMMARY_TOTAL));
		pCaptureManager->ClearSummaryQueue();

		CUtil::StringCopy(pstSummary->m_szLotId, (LPCTSTR)(LPCSTR)dlgLotID.m_szLotID);

		GetDlgItem(IDC_EDIT_LOTID_SAMPLE_A)->SetWindowText(dlgLotID.m_szLotID);
		UpdateSummary();
		UpdateTotalSummary();

		// Clear Queue...
		CInspection* pInspection = pCaptureManager->GetInspection();
		// Print Log
		{
			if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
			{
				stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Set LotID (%s)", (LPCTSTR)dlgLotID.m_szLotID);
			}
		}
	}
}

void CTapMainSummary::UpdateSummary()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	INFO_SUMMARY* pstSummary = pCaptureManager->GetResultSummary();

	TCHAR szValue[MAX_NAME_LEN] = { 0, };
	int i = 0;

	if (((CButton*)GetDlgItem(IDC_RADIO_SUMMARYTOTAL))->GetCheck()){
		// Total Count - First Camera
		i = 0;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummaryFirst.m_nSampleCount);
		m_ctlListCountSampleFirst.SetItemText(i, 1, szValue);		i++;

		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummaryFirst.m_nSampleCountErrorSize);
		m_ctlListCountSampleFirst.SetItemText(i, 1, szValue);
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%.02f"), pstSummary->m_stSummaryFirst.m_fSampleRatioErrorSize);
		m_ctlListCountSampleFirst.SetItemText(i, 2, szValue);		i++;

		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummaryFirst.m_nSampleCountErrorShape);
		m_ctlListCountSampleFirst.SetItemText(i, 1, szValue);
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%.02f"), pstSummary->m_stSummaryFirst.m_fSampleRatioErrorShape);
		m_ctlListCountSampleFirst.SetItemText(i, 2, szValue);		i++;

		// Shape Error Count - First Camera
		i = 0;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummaryFirst.m_pListErrorShape[TYPE_STEP_002]);
		m_ctlListErrorShapeSampleFirst.SetItemText(0, i, szValue); i++;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummaryFirst.m_pListErrorShape[TYPE_STEP_003]);
		m_ctlListErrorShapeSampleFirst.SetItemText(0, i, szValue); i++;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummaryFirst.m_pListErrorShape[TYPE_STEP_004]);
		m_ctlListErrorShapeSampleFirst.SetItemText(0, i, szValue); i++;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummaryFirst.m_pListErrorShape[TYPE_STEP_005]);
		m_ctlListErrorShapeSampleFirst.SetItemText(0, i, szValue); i++;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummaryFirst.m_pListErrorShape[TYPE_STEP_006]);
		m_ctlListErrorShapeSampleFirst.SetItemText(0, i, szValue); i++;
		m_ctlListErrorShapeSampleFirst.SetItemText(0, i, _T("0")); i++;

		// Size Error Count - First Camera
		for (i = 0; i < MAX_SIZE_MEASURECOUNT; i++)
		{
			CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummaryFirst.m_pListErrorSize[i]);
			m_ctlListErrorSizeSampleFirst.SetItemText(0, i, szValue);
		}
		// Version 1.3.8.0 Resin Count Add (First)

		// Total Count - Second Camera
		i = 0;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummarySecond.m_nSampleCount);
		m_ctlListCountSampleSecond.SetItemText(i, 1, szValue);		i++;

		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummarySecond.m_nSampleCountErrorSize);
		m_ctlListCountSampleSecond.SetItemText(i, 1, szValue);
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%.02f"), pstSummary->m_stSummarySecond.m_fSampleRatioErrorSize);
		m_ctlListCountSampleSecond.SetItemText(i, 2, szValue);		i++;

		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummarySecond.m_nSampleCountErrorShape);
		m_ctlListCountSampleSecond.SetItemText(i, 1, szValue);
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%.02f"), pstSummary->m_stSummarySecond.m_fSampleRatioErrorShape);
		m_ctlListCountSampleSecond.SetItemText(i, 2, szValue);		i++;

		// Shape Error Count - Second Camera
		i = 0;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummarySecond.m_pListErrorShape[TYPE_STEP_002]);
		m_ctlListErrorShapeSampleSecond.SetItemText(0, i, szValue); i++;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummarySecond.m_pListErrorShape[TYPE_STEP_003]);
		m_ctlListErrorShapeSampleSecond.SetItemText(0, i, szValue); i++;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummarySecond.m_pListErrorShape[TYPE_STEP_004]);
		m_ctlListErrorShapeSampleSecond.SetItemText(0, i, szValue); i++;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummarySecond.m_pListErrorShape[TYPE_STEP_005]);
		m_ctlListErrorShapeSampleSecond.SetItemText(0, i, szValue); i++;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummarySecond.m_pListErrorShape[TYPE_STEP_006]);
		m_ctlListErrorShapeSampleSecond.SetItemText(0, i, szValue); i++;
		m_ctlListErrorShapeSampleSecond.SetItemText(0, i, _T("0")); i++;

		// Size Error Count - Second Camera
		for (i = 0; i < MAX_SIZE_MEASURECOUNT; i++)
		{
			CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummarySecond.m_pListErrorSize[i]);
			m_ctlListErrorSizeSampleSecond.SetItemText(0, i, szValue);
		}
	}
	else
	{
		// Total Count - First Camera
		i = 0;
		double Ratio = 0.f;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummaryFirst.m_nSampleCount - SummaryCount.m_stSummaryFirst.m_nSampleCount);
		m_ctlListCountSampleFirst.SetItemText(i, 1, szValue);		i++;

		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummaryFirst.m_nSampleCountErrorSize - SummaryCount.m_stSummaryFirst.m_nSampleCountErrorSize);
		m_ctlListCountSampleFirst.SetItemText(i, 1, szValue);
		
		if (0 != pstSummary->m_stSummaryFirst.m_nSampleCount - SummaryCount.m_stSummaryFirst.m_nSampleCount)
			Ratio = ((double)(pstSummary->m_stSummaryFirst.m_nSampleCountErrorSize - SummaryCount.m_stSummaryFirst.m_nSampleCountErrorSize)) / ((double)(pstSummary->m_stSummaryFirst.m_nSampleCount - SummaryCount.m_stSummaryFirst.m_nSampleCount)) * 100.0f;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%.02f"), Ratio);
		m_ctlListCountSampleFirst.SetItemText(i, 2, szValue);		i++;

		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummaryFirst.m_nSampleCountErrorShape - SummaryCount.m_stSummaryFirst.m_nSampleCountErrorShape);
		m_ctlListCountSampleFirst.SetItemText(i, 1, szValue);

		Ratio = 0.f;
		if (0 != pstSummary->m_stSummaryFirst.m_nSampleCount - SummaryCount.m_stSummaryFirst.m_nSampleCount)
			Ratio = ((double)(pstSummary->m_stSummaryFirst.m_nSampleCountErrorShape - SummaryCount.m_stSummaryFirst.m_nSampleCountErrorShape)) / ((double)(pstSummary->m_stSummaryFirst.m_nSampleCount - SummaryCount.m_stSummaryFirst.m_nSampleCount)) * 100.0f;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%.02f"), Ratio);
		m_ctlListCountSampleFirst.SetItemText(i, 2, szValue);		i++;

		// Shape Error Count - First Camera
		i = 0;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummaryFirst.m_pListErrorShape[TYPE_STEP_002] - SummaryCount.m_stSummaryFirst.m_pListErrorShape[TYPE_STEP_002]);
		m_ctlListErrorShapeSampleFirst.SetItemText(0, i, szValue); i++;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummaryFirst.m_pListErrorShape[TYPE_STEP_003] - SummaryCount.m_stSummaryFirst.m_pListErrorShape[TYPE_STEP_003]);
		m_ctlListErrorShapeSampleFirst.SetItemText(0, i, szValue); i++;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummaryFirst.m_pListErrorShape[TYPE_STEP_004] - SummaryCount.m_stSummaryFirst.m_pListErrorShape[TYPE_STEP_004]);
		m_ctlListErrorShapeSampleFirst.SetItemText(0, i, szValue); i++;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummaryFirst.m_pListErrorShape[TYPE_STEP_005] - SummaryCount.m_stSummaryFirst.m_pListErrorShape[TYPE_STEP_005]);
		m_ctlListErrorShapeSampleFirst.SetItemText(0, i, szValue); i++;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummaryFirst.m_pListErrorShape[TYPE_STEP_006] - SummaryCount.m_stSummaryFirst.m_pListErrorShape[TYPE_STEP_006]);
		m_ctlListErrorShapeSampleFirst.SetItemText(0, i, szValue); i++;
		m_ctlListErrorShapeSampleFirst.SetItemText(0, i, _T("0")); i++;

		// Size Error Count - First Camera
		for (i = 0; i < MAX_SIZE_MEASURECOUNT; i++)
		{
			CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummaryFirst.m_pListErrorSize[i] - SummaryCount.m_stSummaryFirst.m_pListErrorSize[i]);
			m_ctlListErrorSizeSampleFirst.SetItemText(0, i, szValue);
		}

		// Total Count - Second Camera
		i = 0;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummarySecond.m_nSampleCount - SummaryCount.m_stSummarySecond.m_nSampleCount);
		m_ctlListCountSampleSecond.SetItemText(i, 1, szValue);		i++;

		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummarySecond.m_nSampleCountErrorSize - SummaryCount.m_stSummarySecond.m_nSampleCountErrorSize);
		m_ctlListCountSampleSecond.SetItemText(i, 1, szValue);

		Ratio = 0.f;
		if (0 != pstSummary->m_stSummarySecond.m_nSampleCount - SummaryCount.m_stSummarySecond.m_nSampleCount)
			Ratio = ((double)(pstSummary->m_stSummarySecond.m_nSampleCountErrorSize - SummaryCount.m_stSummarySecond.m_nSampleCountErrorSize)) / ((double)(pstSummary->m_stSummarySecond.m_nSampleCount - SummaryCount.m_stSummarySecond.m_nSampleCount)) * 100.0f;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%.02f"), Ratio);
		m_ctlListCountSampleSecond.SetItemText(i, 2, szValue);		i++;

		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummarySecond.m_nSampleCountErrorShape - SummaryCount.m_stSummarySecond.m_nSampleCountErrorShape);
		m_ctlListCountSampleSecond.SetItemText(i, 1, szValue);

		Ratio = 0.f;
		if (0 != pstSummary->m_stSummarySecond.m_nSampleCount - SummaryCount.m_stSummarySecond.m_nSampleCount)
			Ratio = ((double)(pstSummary->m_stSummarySecond.m_nSampleCountErrorShape - SummaryCount.m_stSummarySecond.m_nSampleCountErrorShape)) / ((double)(pstSummary->m_stSummarySecond.m_nSampleCount - SummaryCount.m_stSummarySecond.m_nSampleCount)) * 100.0f;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%.02f"), Ratio);
		m_ctlListCountSampleSecond.SetItemText(i, 2, szValue);		i++;

		// Shape Error Count - Second Camera
		i = 0;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummarySecond.m_pListErrorShape[TYPE_STEP_002] - SummaryCount.m_stSummarySecond.m_pListErrorShape[TYPE_STEP_002]);
		m_ctlListErrorShapeSampleSecond.SetItemText(0, i, szValue); i++;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummarySecond.m_pListErrorShape[TYPE_STEP_003] - SummaryCount.m_stSummarySecond.m_pListErrorShape[TYPE_STEP_003]);
		m_ctlListErrorShapeSampleSecond.SetItemText(0, i, szValue); i++;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummarySecond.m_pListErrorShape[TYPE_STEP_004] - SummaryCount.m_stSummarySecond.m_pListErrorShape[TYPE_STEP_004]);
		m_ctlListErrorShapeSampleSecond.SetItemText(0, i, szValue); i++;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummarySecond.m_pListErrorShape[TYPE_STEP_005] - SummaryCount.m_stSummarySecond.m_pListErrorShape[TYPE_STEP_005]);
		m_ctlListErrorShapeSampleSecond.SetItemText(0, i, szValue); i++;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummarySecond.m_pListErrorShape[TYPE_STEP_006] - SummaryCount.m_stSummarySecond.m_pListErrorShape[TYPE_STEP_006]);
		m_ctlListErrorShapeSampleSecond.SetItemText(0, i, szValue); i++;
		m_ctlListErrorShapeSampleSecond.SetItemText(0, i, _T("0")); i++;

		// Size Error Count - Second Camera
		for (i = 0; i < MAX_SIZE_MEASURECOUNT; i++)
		{
			CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummarySecond.m_pListErrorSize[i] - SummaryCount.m_stSummarySecond.m_pListErrorSize[i]);
			m_ctlListErrorSizeSampleSecond.SetItemText(0, i, szValue);
		}
	}
}

void CTapMainSummary::UpdateTotalSummary()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	INFO_SUMMARY* pstSummary = pCaptureManager->GetResultSummary();

	TCHAR szValue[MAX_NAME_LEN] = { 0, };
	int i = 0;

	// Total Count
	//CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d : %d"), pstSummary->m_stSummaryTotal.first_queue_size, pstSummary->m_stSummaryTotal.second_queue_size);
	//m_ctlTitleSampleTotal.SetMessage(szValue);

	if (((CButton*)GetDlgItem(IDC_RADIO_SUMMARYTOTAL))->GetCheck()){
		i = 0;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummaryTotal.m_nSampleCount);
		m_ctlListCountSampleTotal.SetItemText(i, 1, szValue);		i++;

		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummaryTotal.m_nSampleCountErrorSize);
		m_ctlListCountSampleTotal.SetItemText(i, 1, szValue);
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%.02f"), pstSummary->m_stSummaryTotal.m_fSampleRatioErrorSize);
		m_ctlListCountSampleTotal.SetItemText(i, 2, szValue);		i++;

		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummaryTotal.m_nSampleCountErrorShape);
		m_ctlListCountSampleTotal.SetItemText(i, 1, szValue);
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%.02f"), pstSummary->m_stSummaryTotal.m_fSampleRatioErrorShape);
		m_ctlListCountSampleTotal.SetItemText(i, 2, szValue);		i++;
	}
	else
	{
		i = 0;
		double Ratio = 0.f;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummaryTotal.m_nSampleCount - SummaryCount.m_stSummaryTotal.m_nSampleCount);
		m_ctlListCountSampleTotal.SetItemText(i, 1, szValue);		i++;

		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummaryTotal.m_nSampleCountErrorSize - SummaryCount.m_stSummaryTotal.m_nSampleCountErrorSize);
		m_ctlListCountSampleTotal.SetItemText(i, 1, szValue);
		
		if (0 != pstSummary->m_stSummaryTotal.m_nSampleCount - SummaryCount.m_stSummaryTotal.m_nSampleCount)
			Ratio = ((double)(pstSummary->m_stSummaryTotal.m_nSampleCountErrorSize - SummaryCount.m_stSummaryTotal.m_nSampleCountErrorSize)) / ((double)(pstSummary->m_stSummaryTotal.m_nSampleCount - SummaryCount.m_stSummaryTotal.m_nSampleCount)) * 100.0f;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%.02f"), Ratio);
		m_ctlListCountSampleTotal.SetItemText(i, 2, szValue);		i++;

		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%d"), pstSummary->m_stSummaryTotal.m_nSampleCountErrorShape - SummaryCount.m_stSummaryTotal.m_nSampleCountErrorShape);
		m_ctlListCountSampleTotal.SetItemText(i, 1, szValue);

		Ratio = 0.f;
		if (0 != pstSummary->m_stSummaryTotal.m_nSampleCount - SummaryCount.m_stSummaryTotal.m_nSampleCount)
			Ratio = ((double)(pstSummary->m_stSummaryTotal.m_fSampleRatioErrorShape - SummaryCount.m_stSummaryTotal.m_fSampleRatioErrorShape)) / ((double)(pstSummary->m_stSummaryTotal.m_nSampleCount - SummaryCount.m_stSummaryTotal.m_nSampleCount)) * 100.0f;
		CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%.02f"), Ratio);
		m_ctlListCountSampleTotal.SetItemText(i, 2, szValue);		i++;
	}
	//HANDLE hFile = pCaptureManager->m_hFile_Total;
	//SaveTotalSummary(hFile);
	SaveTotalSummary(pCaptureManager->GetTotalLogHandle());
}

void CTapMainSummary::SetStateStartInspection()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	BOOL bStart = pInspection->IsStart();

	GetDlgItem(IDC_BTN_LOTID_SAMPLE_A)->EnableWindow(!bStart);
	//GetDlgItem(IDC_BTN_SUMMARYCOUNT_RESET)->EnableWindow(!bStart);
}

void CTapMainSummary::UpdateTitleStep()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	const TCHAR* pTitleStep2 = pCaptureManager->GetTitleStep(TYPE_CAMERAPOS_FIRST, TYPE_STEP_002);
	const TCHAR* pTitleStep3 = pCaptureManager->GetTitleStep(TYPE_CAMERAPOS_FIRST, TYPE_STEP_003);
	const TCHAR* pTitleStep4 = pCaptureManager->GetTitleStep(TYPE_CAMERAPOS_FIRST, TYPE_STEP_004);
	const TCHAR* pTitleStep5 = pCaptureManager->GetTitleStep(TYPE_CAMERAPOS_FIRST, TYPE_STEP_005);
	const TCHAR* pTitleStep6 = pCaptureManager->GetTitleStep(TYPE_CAMERAPOS_FIRST, TYPE_STEP_006);


	LVCOLUMN stColumn;
	memset(&stColumn, 0x00, sizeof(LVCOLUMN));
	stColumn.mask = LVCF_TEXT;

	int idx = 0;
	stColumn.pszText = (TCHAR*)pTitleStep2;
	m_ctlListErrorShapeSampleFirst.SetColumn(idx, &stColumn); idx++;
	stColumn.pszText = (TCHAR*)pTitleStep3;
	m_ctlListErrorShapeSampleFirst.SetColumn(idx, &stColumn); idx++;
	stColumn.pszText = (TCHAR*)pTitleStep4;
	m_ctlListErrorShapeSampleFirst.SetColumn(idx, &stColumn); idx++;
	stColumn.pszText = (TCHAR*)pTitleStep5;
	m_ctlListErrorShapeSampleFirst.SetColumn(idx, &stColumn); idx++;
	stColumn.pszText = (TCHAR*)pTitleStep6;
	m_ctlListErrorShapeSampleFirst.SetColumn(idx, &stColumn); idx++;

	idx = 0;
	stColumn.pszText = (TCHAR*)pTitleStep2;
	m_ctlListErrorShapeSampleSecond.SetColumn(idx, &stColumn); idx++;
	stColumn.pszText = (TCHAR*)pTitleStep3;
	m_ctlListErrorShapeSampleSecond.SetColumn(idx, &stColumn); idx++;
	stColumn.pszText = (TCHAR*)pTitleStep4;
	m_ctlListErrorShapeSampleSecond.SetColumn(idx, &stColumn); idx++;
	stColumn.pszText = (TCHAR*)pTitleStep5;
	m_ctlListErrorShapeSampleSecond.SetColumn(idx, &stColumn); idx++;
	stColumn.pszText = (TCHAR*)pTitleStep6;
	m_ctlListErrorShapeSampleSecond.SetColumn(idx, &stColumn); idx++;
		
}

void CTapMainSummary::UpdateSizeName()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_OPTION* pstOption = pCaptureManager->GetOption();

	LVCOLUMN stColumn;
	memset(&stColumn, 0x00, sizeof(LVCOLUMN));
	stColumn.mask = LVCF_TEXT;

	int idx = 0;
	for (idx = 0; idx < MAX_GEOMETRY_DISTANCELINE_COUNT; idx++)
	{
		stColumn.pszText = (TCHAR*)pstOption->m_stSizeName.m_szName[idx];
		m_ctlListErrorSizeSampleFirst.SetColumn(idx, &stColumn);
	}

	{
		CString name = pstOption->m_stSizeName.GetNameX1X2();
		stColumn.pszText = (LPSTR)(LPCTSTR)name;
		m_ctlListErrorSizeSampleFirst.SetColumn(idx, &stColumn); idx++;
		name = pstOption->m_stSizeName.GetNameS1S3();
		stColumn.pszText = (LPSTR)(LPCTSTR)name;
		m_ctlListErrorSizeSampleFirst.SetColumn(idx, &stColumn); idx++;
		name = pstOption->m_stSizeName.GetNameM1M2();
		stColumn.pszText = (LPSTR)(LPCTSTR)name;
		m_ctlListErrorSizeSampleFirst.SetColumn(idx, &stColumn); idx++;
		// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
		name = pstOption->m_stSizeName.GetNameSS1SS3();
		stColumn.pszText = (LPSTR)(LPCTSTR)name;
		m_ctlListErrorSizeSampleFirst.SetColumn(idx, &stColumn); idx++;
	}

	for (idx = 0; idx < MAX_GEOMETRY_DISTANCELINE_COUNT; idx++)
	{
		stColumn.pszText = (TCHAR*)pstOption->m_stSizeName.m_szName[idx];
		m_ctlListErrorSizeSampleSecond.SetColumn(idx, &stColumn);
	}

	{
		CString name = pstOption->m_stSizeName.GetNameX1X2();
		stColumn.pszText = (LPSTR)(LPCTSTR)name;
		m_ctlListErrorSizeSampleSecond.SetColumn(idx, &stColumn); idx++;
		name = pstOption->m_stSizeName.GetNameS1S3();
		stColumn.pszText = (LPSTR)(LPCTSTR)name;
		m_ctlListErrorSizeSampleSecond.SetColumn(idx, &stColumn); idx++;
		name = pstOption->m_stSizeName.GetNameM1M2();
		stColumn.pszText = (LPSTR)(LPCTSTR)name;
		m_ctlListErrorSizeSampleSecond.SetColumn(idx, &stColumn); idx++;
		// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
		name = pstOption->m_stSizeName.GetNameSS1SS3();
		stColumn.pszText = (LPSTR)(LPCTSTR)name;
		m_ctlListErrorSizeSampleSecond.SetColumn(idx, &stColumn); idx++;
	}

}

void CTapMainSummary::SaveSummary(TCHAR* pszFilePath, INFO_SUMMARY_SAMPLE* pstSummarySampleFirst, INFO_SUMMARY_SAMPLE* pstSummarySampleSecond)
{
	HANDLE hFile = ::CreateFile(pszFilePath,
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CREATE_ALWAYS,
		FILE_FLAG_WRITE_THROUGH,
		NULL);
	if (INVALID_HANDLE_VALUE == hFile)
		return;

	SaveSummaryTitle(hFile);
	SaveSummary(hFile, TYPE_CAMERAPOS_FIRST, pstSummarySampleFirst);
	SaveSummary(hFile, TYPE_CAMERAPOS_SECOND, pstSummarySampleSecond);

	::CloseHandle(hFile);
}

void CTapMainSummary::SaveSummary(TCHAR* pszFilePath, TYPE_CAMERAPOS eCameraPos, INFO_SUMMARY_SAMPLE* pstSummarySample)
{
	if (NULL == pszFilePath || NULL == pstSummarySample)
		return;

	HANDLE hFile = ::CreateFile(pszFilePath,
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CREATE_ALWAYS,
		FILE_FLAG_WRITE_THROUGH,
		NULL);
	if (INVALID_HANDLE_VALUE == hFile)
		return;

	SaveSummary(hFile, eCameraPos, pstSummarySample);

	::CloseHandle(hFile);
}

void CTapMainSummary::SaveSummary(HANDLE hFile, TYPE_CAMERAPOS eCameraPos, INFO_SUMMARY_SAMPLE* pstSummarySample)
{
	if (INVALID_HANDLE_VALUE == hFile || NULL == pstSummarySample)
		return;

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_OPTION* pstOpt = pCaptureManager->GetOption();

	DWORD dwResult = 0;
	char szString[1024] = { 0, };

	// 상, 하면
	if (TYPE_CAMERAPOS_FIRST == eCameraPos)
		sprintf(szString, _T("%s,"), STR_TAPVIEW_SAMPLE_FIRST);
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
		sprintf(szString, _T("%s,"), STR_TAPVIEW_SAMPLE_SECOND);
	::WriteFile(hFile, szString, strlen(szString), &dwResult, NULL);

	// 진행 수량, 치수, 외관 불량 수량, 수율
	sprintf(szString, _T("%d,"), pstSummarySample->m_nSampleCount);
	::WriteFile(hFile, szString, strlen(szString), &dwResult, NULL);
	sprintf(szString, _T("%d,%.02f,"), pstSummarySample->m_nSampleCountErrorSize, pstSummarySample->m_fSampleRatioErrorSize);
	::WriteFile(hFile, szString, strlen(szString), &dwResult, NULL);
	sprintf(szString, _T("%d,%.02f,"), pstSummarySample->m_nSampleCountErrorShape, pstSummarySample->m_fSampleRatioErrorShape);
	::WriteFile(hFile, szString, strlen(szString), &dwResult, NULL);

	// 각 외관 불량 수량
	sprintf(szString, _T("%d,%d,%d,%d,%d,%d,"),
		pstSummarySample->m_pListErrorShape[TYPE_STEP_002],
		pstSummarySample->m_pListErrorShape[TYPE_STEP_003],
		pstSummarySample->m_pListErrorShape[TYPE_STEP_004],
		pstSummarySample->m_pListErrorShape[TYPE_STEP_005],
		pstSummarySample->m_pListErrorShape[TYPE_STEP_006],
		0);
	::WriteFile(hFile, szString, strlen(szString), &dwResult, NULL);

	// 각 치수 불량 수량
	int nIdx = 0;
	for (; nIdx < MAX_SIZE_MEASURECOUNT; nIdx++){
		sprintf(szString, _T("%d,"), pstSummarySample->m_pListErrorSize[nIdx]);
		::WriteFile(hFile, szString, strlen(szString), &dwResult, NULL);
	}

	sprintf(szString, _T("\r\n"));
	::WriteFile(hFile, szString, strlen(szString), &dwResult, NULL);
}


void CTapMainSummary::SaveSummaryTitle(HANDLE hFile)
{
	if (INVALID_HANDLE_VALUE == hFile)
		return;

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_OPTION* pstOpt = pCaptureManager->GetOption();
	INFO_SUMMARY* pstSummary = pCaptureManager->GetResultSummary();

	DWORD dwResult = 0;
	char szString[1024] = { 0, };

	// LOT ID
	sprintf(szString, _T("%s,"), pstSummary->m_szLotId);
	::WriteFile(hFile, szString, strlen(szString), &dwResult, NULL);

	// 진행 수량, 치수, 외관 불량 수량, 수율
	sprintf(szString, _T("%s,"), STR_SUMMARY_ROW_TOTAL);
	::WriteFile(hFile, szString, strlen(szString), &dwResult, NULL);
	sprintf(szString, _T("%s,%s,"), STR_SUMMARY_LOG_ERRORSIZE_COUNT, STR_SUMMARY_LOG_ERRORSIZE_RATIO);
	::WriteFile(hFile, szString, strlen(szString), &dwResult, NULL);
	sprintf(szString, _T("%s,%s,"), STR_SUMMARY_LOG_ERRORSHAPE_COUNT, STR_SUMMARY_LOG_ERRORSHAPERATIO);
	::WriteFile(hFile, szString, strlen(szString), &dwResult, NULL);

	/*
	// 각 외관 불량 수량
	if (TYPE_CAMERAPOS_FIRST == eCameraPos)
		sprintf(szString, _T("  %s\r\n"), STR_TAPVIEW_SUMMARY_ERRORSHAPE_SAMPLE_FIRST);
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
		sprintf(szString, _T("  %s\r\n"), STR_TAPVIEW_SUMMARY_ERRORSHAPE_SAMPLE_SECOND);
	::WriteFile(hFile, szString, strlen(szString), &dwResult, NULL);
	*/

	sprintf(szString, _T("%s,%s,%s,%s,%s,%s,"),
		pstOpt->m_stFirstCameraStep.m_szTitleStep02,
		pstOpt->m_stFirstCameraStep.m_szTitleStep03,
		pstOpt->m_stFirstCameraStep.m_szTitleStep04,
		pstOpt->m_stFirstCameraStep.m_szTitleStep05,
		pstOpt->m_stFirstCameraStep.m_szTitleStep06,
		STR_SUMMARY_COL_ETC);
	::WriteFile(hFile, szString, strlen(szString), &dwResult, NULL);

	/*
	// 각 치수 불량 수량
	if (TYPE_CAMERAPOS_FIRST == eCameraPos)
		sprintf(szString, _T("  %s\r\n"), STR_TAPVIEW_SUMMARY_ERRORSIZE_SAMPLE_FIRST);
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
		sprintf(szString, _T("  %s\r\n"), STR_TAPVIEW_SUMMARY_ERRORSIZE_SAMPLE_SECOND);
	::WriteFile(hFile, szString, strlen(szString), &dwResult, NULL);
	*/

	const INFO_OPTION* pstOption = pCaptureManager->GetOption();

	int nIdx = 0;
	for (; nIdx < MAX_GEOMETRY_DISTANCELINE_COUNT; nIdx++){
		sprintf(szString, _T("%s,"), pstOption->m_stSizeName.m_szName[nIdx]);
		::WriteFile(hFile, szString, strlen(szString), &dwResult, NULL);
	}

	sprintf(szString, _T("%s,"), pstOption->m_stSizeName.GetNameX1X2());
	::WriteFile(hFile, szString, strlen(szString), &dwResult, NULL);
	sprintf(szString, _T("%s,"), pstOption->m_stSizeName.GetNameS1S3());
	::WriteFile(hFile, szString, strlen(szString), &dwResult, NULL);
	sprintf(szString, _T("%s\r\n"), pstOption->m_stSizeName.GetNameM1M2());
	::WriteFile(hFile, szString, strlen(szString), &dwResult, NULL);
	/*
	sprintf(szString, _T("%s"), szString);

	sprintf(szString, _T("    %s(%d), %s(%d), %s(%d), %s(%d), %s(%d), %s(%d), %s(%d), %s(%d), %s(%d), %s(%d), "
							 "%s(%d), %s(%d), %s(%d), %s(%d), %s(%d), %s(%d), %s(%d), %s(%d), %s(%d), %s(%d), "
							 "%s(%d), %s(%d)\r\n"),
		STR_SIZEMEASURE_01, pstSummarySample->m_pListErrorSize[0],
		STR_SIZEMEASURE_02, pstSummarySample->m_pListErrorSize[1],
		STR_SIZEMEASURE_03, pstSummarySample->m_pListErrorSize[2],
		STR_SIZEMEASURE_04, pstSummarySample->m_pListErrorSize[3],
		STR_SIZEMEASURE_05, pstSummarySample->m_pListErrorSize[4],
		STR_SIZEMEASURE_06, pstSummarySample->m_pListErrorSize[5],
		STR_SIZEMEASURE_07, pstSummarySample->m_pListErrorSize[6],
		STR_SIZEMEASURE_08, pstSummarySample->m_pListErrorSize[7],
		STR_SIZEMEASURE_09, pstSummarySample->m_pListErrorSize[8],
		STR_SIZEMEASURE_10, pstSummarySample->m_pListErrorSize[9],
		STR_SIZEMEASURE_11, pstSummarySample->m_pListErrorSize[10],
		STR_SIZEMEASURE_12, pstSummarySample->m_pListErrorSize[11],
		STR_SIZEMEASURE_13, pstSummarySample->m_pListErrorSize[12],
		STR_SIZEMEASURE_14, pstSummarySample->m_pListErrorSize[13],
		STR_SIZEMEASURE_15, pstSummarySample->m_pListErrorSize[14],
		STR_SIZEMEASURE_16, pstSummarySample->m_pListErrorSize[15],
		STR_SIZEMEASURE_17, pstSummarySample->m_pListErrorSize[16],
		STR_SIZEMEASURE_18, pstSummarySample->m_pListErrorSize[17],
		STR_SIZEMEASURE_19, pstSummarySample->m_pListErrorSize[18],
		STR_SIZEMEASURE_20, pstSummarySample->m_pListErrorSize[19],
		STR_SIZEMEASURE_21, pstSummarySample->m_pListErrorSize[20],
		STR_SIZEMEASURE_22, pstSummarySample->m_pListErrorSize[21]);
	::WriteFile(hFile, szString, strlen(szString), &dwResult, NULL);
	*/
}

void CTapMainSummary::SaveTotalSummary(HANDLE hFile)
{
	if (INVALID_HANDLE_VALUE == hFile)
		return;

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	INFO_SUMMARY* pstSummary = pCaptureManager->GetResultSummary();

	DWORD dwResult = 0;
	char szString[1024] = { 0, };

	int nIndex = 0;

	SYSTEMTIME stTime;
	::GetLocalTime(&stTime);

	nIndex = pstSummary->m_stSummarySecond.m_nSampleCount;
	//nIndex = pstSummary->m_stSummaryTotal.m_nSampleCount;

	sprintf(szString, _T("%d,%04d%02d%02d %02d:%02d:%02d,"),
		nIndex,
		stTime.wYear, stTime.wMonth, stTime.wDay,
		stTime.wHour, stTime.wMinute, stTime.wSecond);

	sprintf(szString, _T("%s%d,"), szString, pstSummary->m_stSummaryTotal.m_nSampleCount);

	sprintf(szString, _T("%s%d,"), szString, pstSummary->m_stSummaryTotal.m_nSampleCountErrorSize);
	sprintf(szString, _T("%s%.02f,"), szString, pstSummary->m_stSummaryTotal.m_fSampleRatioErrorSize);

	sprintf(szString, _T("%s%d,"), szString, pstSummary->m_stSummaryTotal.m_nSampleCountErrorShape);
	sprintf(szString, _T("%s%.02f,"), szString, pstSummary->m_stSummaryTotal.m_fSampleRatioErrorShape);

	/////////////////20211230 치수 판정 외관 판정
	sprintf(szString, _T("%s%d,"), szString, pstSummary->m_stSummaryTotal.ErrorSize);
	sprintf(szString, _T("%s%d\r\n"), szString, pstSummary->m_stSummaryTotal.ShapeSize);

	::WriteFile(hFile, szString, strlen(szString), &dwResult, NULL);
}

void CTapMainSummary::OnBnClickedBtnSummarycountReset()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	INFO_SUMMARY* pstSummary = pCaptureManager->GetResultSummary();

	memcpy(&SummaryCount.m_stSummaryFirst, &pstSummary->m_stSummaryFirst, sizeof(INFO_SUMMARY_SAMPLE));
	memcpy(&SummaryCount.m_stSummarySecond, &pstSummary->m_stSummarySecond, sizeof(INFO_SUMMARY_SAMPLE));
	memcpy(&SummaryCount.m_stSummaryTotal, &pstSummary->m_stSummaryTotal, sizeof(INFO_SUMMARY_TOTAL));

	UpdateSummary();
	UpdateTotalSummary();
}


void CTapMainSummary::OnBnClickedRadioSummarytotal()
{
	UpdateSummary();
	UpdateTotalSummary();
}


void CTapMainSummary::OnBnClickedRadioSummarycount()
{
	UpdateSummary();
	UpdateTotalSummary();
}
