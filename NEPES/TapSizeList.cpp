// TapSizeList.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "TapSizeList.h"
#include "afxdialogex.h"

#include "CaptureManager.h"
#include "Util/Util.h"
#include "stringres.h"

// CTapSizeList dialog

IMPLEMENT_DYNAMIC(CTapSizeList, CDialogEx)

CTapSizeList::CTapSizeList(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTapSizeList::IDD, pParent)
{
	memset(&m_stDistanceFirst, 0x00, sizeof(OUTPUT_DISTANCE)* TYPE_GEOMETRY_DISTANCE_MAX);
	memset(&m_stDistanceSecond, 0x00, sizeof(OUTPUT_DISTANCE)* TYPE_GEOMETRY_DISTANCE_MAX);
}

CTapSizeList::~CTapSizeList()
{
}

void CTapSizeList::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_SAMPLE_A, m_ctlListSampleFirst);
	DDX_Control(pDX, IDC_LIST_SAMPLE_B, m_ctlListSampleSecond);
	DDX_Control(pDX, IDC_STATIC_SAMPLEA, m_ctlMessureSampleFirst);
	DDX_Control(pDX, IDC_STATIC_SAMPLEB, m_ctlMessureSampleSecond);
}


BOOL CTapSizeList::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (IDOK == wParam)
	{
		return TRUE;
	}
	return CDialogEx::OnCommand(wParam, lParam);
}

BOOL CTapSizeList::PreTranslateMessage(MSG* pMsg)
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

BOOL CTapSizeList::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//
	m_ctlMessureSampleFirst.SetTextFont(_T("MS Shell Dlg"), 20, FW_BOLD);
	m_ctlMessureSampleSecond.SetTextFont(_T("MS Shell Dlg"), 20, FW_BOLD);
	//m_ctlMessureAB.SetTextFont(_T("MS Shell Dlg"), 20, FW_BOLD);

	m_ctlMessureSampleFirst.SetMessage(STR_TAPVIEW_MEASURE_SAMPLEA);
	m_ctlMessureSampleSecond.SetMessage(STR_TAPVIEW_MEASURE_SAMPLEB);
	//m_ctlMessureAB.SetMessage(STR_TAPVIEW_MEASURE_AB);


	// List Control
	m_ctlListSampleFirst.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_ctlListSampleSecond.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	//m_ctlListMeasure.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// Insert Column
	m_ctlListSampleFirst.InsertColumn(0, STR_SIZEMEASURE_COL_TITLE, LVCFMT_LEFT, 50, -1);
	m_ctlListSampleFirst.InsertColumn(1, STR_SIZEMEASURE_COL_LSL, LVCFMT_LEFT, 80, -1);
	m_ctlListSampleFirst.InsertColumn(2, STR_SIZEMEASURE_COL_USL, LVCFMT_LEFT, 80, -1);
	m_ctlListSampleFirst.InsertColumn(3, STR_SIZEMEASURE_COL_MEASURE, LVCFMT_LEFT, 80, -1);
	m_ctlListSampleFirst.InsertColumn(4, STR_SIZEMEASURE_COL_RESULT, LVCFMT_LEFT, 80, -1);

	m_ctlListSampleSecond.InsertColumn(0, STR_SIZEMEASURE_COL_TITLE, LVCFMT_LEFT, 50, -1);
	m_ctlListSampleSecond.InsertColumn(1, STR_SIZEMEASURE_COL_LSL, LVCFMT_LEFT, 80, -1);
	m_ctlListSampleSecond.InsertColumn(2, STR_SIZEMEASURE_COL_USL, LVCFMT_LEFT, 80, -1);
	m_ctlListSampleSecond.InsertColumn(3, STR_SIZEMEASURE_COL_MEASURE, LVCFMT_LEFT, 80, -1);
	m_ctlListSampleSecond.InsertColumn(4, STR_SIZEMEASURE_COL_RESULT, LVCFMT_LEFT, 80, -1);

	//m_ctlListMeasure.InsertColumn(0, STR_SIZEMEASURE_COL_TITLE, LVCFMT_LEFT, 50, -1);
	//m_ctlListMeasure.InsertColumn(1, STR_SIZEMEASURE_COL_RESULTAB, LVCFMT_LEFT, 80, -1);

	// Add Item Title
	int idx = 0;
	m_ctlListSampleFirst.InsertItem(idx, STR_SIZEMEASURE_01);
	m_ctlListSampleSecond.InsertItem(idx, STR_SIZEMEASURE_01);
	idx++;
	//m_ctlListMeasure.InsertItem(idx, STR_SIZEMEASURE_01);	idx++;

	m_ctlListSampleFirst.InsertItem(idx, STR_SIZEMEASURE_02);
	m_ctlListSampleSecond.InsertItem(idx, STR_SIZEMEASURE_02);
	idx++;
	//m_ctlListMeasure.InsertItem(idx, STR_SIZEMEASURE_02);	idx++;

	m_ctlListSampleFirst.InsertItem(idx, STR_SIZEMEASURE_03);
	m_ctlListSampleSecond.InsertItem(idx, STR_SIZEMEASURE_03);
	idx++;
	//m_ctlListMeasure.InsertItem(idx, STR_SIZEMEASURE_03);	idx++;

	m_ctlListSampleFirst.InsertItem(idx, STR_SIZEMEASURE_04);
	m_ctlListSampleSecond.InsertItem(idx, STR_SIZEMEASURE_04);
	idx++;
	//m_ctlListMeasure.InsertItem(idx, STR_SIZEMEASURE_04);	idx++;

	m_ctlListSampleFirst.InsertItem(idx, STR_SIZEMEASURE_05);
	m_ctlListSampleSecond.InsertItem(idx, STR_SIZEMEASURE_05);
	idx++;
	//m_ctlListMeasure.InsertItem(idx, STR_SIZEMEASURE_05);	idx++;

	m_ctlListSampleFirst.InsertItem(idx, STR_SIZEMEASURE_06);
	m_ctlListSampleSecond.InsertItem(idx, STR_SIZEMEASURE_06);
	idx++;
	//m_ctlListMeasure.InsertItem(idx, STR_SIZEMEASURE_06);	idx++;

	m_ctlListSampleFirst.InsertItem(idx, STR_SIZEMEASURE_07);
	m_ctlListSampleSecond.InsertItem(idx, STR_SIZEMEASURE_07);
	idx++;
	//m_ctlListMeasure.InsertItem(idx, STR_SIZEMEASURE_07);	idx++;

	m_ctlListSampleFirst.InsertItem(idx, STR_SIZEMEASURE_08);
	m_ctlListSampleSecond.InsertItem(idx, STR_SIZEMEASURE_08);
	idx++;
	//m_ctlListMeasure.InsertItem(idx, STR_SIZEMEASURE_08);	idx++;

	m_ctlListSampleFirst.InsertItem(idx, STR_SIZEMEASURE_09);
	m_ctlListSampleSecond.InsertItem(idx, STR_SIZEMEASURE_09);
	idx++;
	///_ctlListMeasure.InsertItem(idx, STR_SIZEMEASURE_09);	idx++;

	m_ctlListSampleFirst.InsertItem(idx, STR_SIZEMEASURE_10);
	m_ctlListSampleSecond.InsertItem(idx, STR_SIZEMEASURE_10);
	idx++;
	//m_ctlListMeasure.InsertItem(idx, STR_SIZEMEASURE_10);	idx++;

	m_ctlListSampleFirst.InsertItem(idx, STR_SIZEMEASURE_11);
	m_ctlListSampleSecond.InsertItem(idx, STR_SIZEMEASURE_11);
	idx++;
	//m_ctlListMeasure.InsertItem(idx, STR_SIZEMEASURE_11);	idx++;

	m_ctlListSampleFirst.InsertItem(idx, STR_SIZEMEASURE_12);
	m_ctlListSampleSecond.InsertItem(idx, STR_SIZEMEASURE_12);
	idx++;
	//m_ctlListMeasure.InsertItem(idx, STR_SIZEMEASURE_12);	idx++;

	m_ctlListSampleFirst.InsertItem(idx, STR_SIZEMEASURE_13);
	m_ctlListSampleSecond.InsertItem(idx, STR_SIZEMEASURE_13);
	idx++;
	//m_ctlListMeasure.InsertItem(idx, STR_SIZEMEASURE_13);	idx++;

	m_ctlListSampleFirst.InsertItem(idx, STR_SIZEMEASURE_14);
	m_ctlListSampleSecond.InsertItem(idx, STR_SIZEMEASURE_14);
	idx++;
	//m_ctlListMeasure.InsertItem(idx, STR_SIZEMEASURE_14);	idx++;

	m_ctlListSampleFirst.InsertItem(idx, STR_SIZEMEASURE_15);
	m_ctlListSampleSecond.InsertItem(idx, STR_SIZEMEASURE_15);
	idx++;
	//m_ctlListMeasure.InsertItem(idx, STR_SIZEMEASURE_15);	idx++;

	m_ctlListSampleFirst.InsertItem(idx, STR_SIZEMEASURE_16);
	m_ctlListSampleSecond.InsertItem(idx, STR_SIZEMEASURE_16);
	idx++;
	//m_ctlListMeasure.InsertItem(idx, STR_SIZEMEASURE_16);	idx++;

	m_ctlListSampleFirst.InsertItem(idx, STR_SIZEMEASURE_17);
	m_ctlListSampleSecond.InsertItem(idx, STR_SIZEMEASURE_17);
	idx++;
	//m_ctlListMeasure.InsertItem(idx, STR_SIZEMEASURE_17);	idx++;

	m_ctlListSampleFirst.InsertItem(idx, STR_SIZEMEASURE_18);
	m_ctlListSampleSecond.InsertItem(idx, STR_SIZEMEASURE_18);
	idx++;
	//m_ctlListMeasure.InsertItem(idx, STR_SIZEMEASURE_18);	idx++;

	m_ctlListSampleFirst.InsertItem(idx, STR_SIZEMEASURE_19);
	m_ctlListSampleSecond.InsertItem(idx, STR_SIZEMEASURE_19);
	idx++;
	//m_ctlListMeasure.InsertItem(idx, STR_SIZEMEASURE_19);	idx++;

	m_ctlListSampleFirst.InsertItem(idx, STR_SIZEMEASURE_20);
	m_ctlListSampleSecond.InsertItem(idx, STR_SIZEMEASURE_20);
	idx++;
	//m_ctlListMeasure.InsertItem(idx, STR_SIZEMEASURE_20);	idx++;

	m_ctlListSampleFirst.InsertItem(idx, STR_SIZEMEASURE_21);
	m_ctlListSampleSecond.InsertItem(idx, STR_SIZEMEASURE_21);
	idx++;
	//m_ctlListMeasure.InsertItem(idx, STR_SIZEMEASURE_21);	idx++;

	m_ctlListSampleFirst.InsertItem(idx, STR_SIZEMEASURE_22);
	m_ctlListSampleSecond.InsertItem(idx, STR_SIZEMEASURE_22);
	idx++;
	//m_ctlListMeasure.InsertItem(idx, STR_SIZEMEASURE_22);	idx++;

	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	m_ctlListSampleFirst.InsertItem(idx, STR_SIZEMEASURE_23);
	m_ctlListSampleSecond.InsertItem(idx, STR_SIZEMEASURE_23);
	idx++;
	//m_ctlListMeasure.InsertItem(idx, STR_SIZEMEASURE_23);	idx++;

	m_ctlListSampleFirst.InsertItem(idx, STR_SIZEMEASURE_24);
	m_ctlListSampleSecond.InsertItem(idx, STR_SIZEMEASURE_24);
	idx++;
	//m_ctlListMeasure.InsertItem(idx, STR_SIZEMEASURE_24);	idx++;

	m_ctlListSampleFirst.InsertItem(idx, STR_SIZEMEASURE_25);
	m_ctlListSampleSecond.InsertItem(idx, STR_SIZEMEASURE_25);
	idx++;
	//m_ctlListMeasure.InsertItem(idx, STR_SIZEMEASURE_25);	idx++;
	
	m_ctlListSampleFirst.InsertItem(idx, STR_SIZEMEASURE_26);
	m_ctlListSampleSecond.InsertItem(idx, STR_SIZEMEASURE_26);
	idx++;
	//m_ctlListMeasure.InsertItem(idx, STR_SIZEMEASURE_26);	idx++;

	m_ctlListSampleFirst.InsertItem(idx, STR_SIZEMEASURE_27);
	m_ctlListSampleSecond.InsertItem(idx, STR_SIZEMEASURE_27);
	idx++;
	//m_ctlListMeasure.InsertItem(idx, STR_SIZEMEASURE_27);	idx++;

	m_ctlListSampleFirst.InsertItem(idx, STR_SIZEMEASURE_28);
	m_ctlListSampleSecond.InsertItem(idx, STR_SIZEMEASURE_28);
	idx++;
	//m_ctlListMeasure.InsertItem(idx, STR_SIZEMEASURE_28);	idx++;
	AdjustLayout();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

BEGIN_MESSAGE_MAP(CTapSizeList, CDialogEx)
	ON_WM_SIZE()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST_SAMPLE_A, &CTapSizeList::OnNMCustomdrawListSampleA)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST_SAMPLE_B, &CTapSizeList::OnNMCustomdrawListSampleB)
END_MESSAGE_MAP()


// CTapSizeList message handlers
void CTapSizeList::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	AdjustLayout();
	this->Invalidate();
}

void CTapSizeList::OnNMCustomdrawListSampleA(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);

	*pResult = CDRF_DODEFAULT;

	if (pNMCD->dwDrawStage == CDDS_PREPAINT)
	{
		*pResult = (LRESULT)CDRF_NOTIFYITEMDRAW;
	}
	else if (pNMCD->dwDrawStage == CDDS_ITEMPREPAINT)
	{
		// pNMCD->dwItemSpec 행 전체의 설정
		if (m_ctlListSampleFirst.GetItemData(pNMCD->dwItemSpec) == 0)
		{
			*pResult = (LRESULT)CDRF_NOTIFYSUBITEMDRAW;
		}
		else
		{
			// When all matrices are already made.
			*pResult = (LRESULT)CDRF_NEWFONT;
		}
	}
	else if (pNMCD->dwDrawStage == (CDDS_SUBITEM | CDDS_ITEMPREPAINT)){
		// pNMCD->dwItemSpec 행,  pDraw->iSubItem 열의 설정
		NMLVCUSTOMDRAW *pDraw = (NMLVCUSTOMDRAW*)(pNMHDR);
		CString szText = m_ctlListSampleFirst.GetItemText(pNMCD->dwItemSpec, pDraw->iSubItem);
		if (!szText.IsEmpty())
		{
			if (pNMCD->dwItemSpec < TYPE_GEOMETRY_DISTANCE_MAX &&
				(pDraw->iSubItem == 3 || pDraw->iSubItem == 4))
			{
				if (m_stDistanceFirst[pNMCD->dwItemSpec].m_bOK == false)
					pDraw->clrText = RGB(255, 0, 0);
				if (m_stDistanceFirst[pNMCD->dwItemSpec].m_bSpec == false)
					pDraw->clrTextBk = RGB(255, 242, 0);
			}
		}

		*pResult = (LRESULT)CDRF_NEWFONT;
	}
}

void CTapSizeList::OnNMCustomdrawListSampleB(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);

	*pResult = CDRF_DODEFAULT;

	if (pNMCD->dwDrawStage == CDDS_PREPAINT)
	{
		*pResult = (LRESULT)CDRF_NOTIFYITEMDRAW;
	}
	else if (pNMCD->dwDrawStage == CDDS_ITEMPREPAINT)
	{
		// pNMCD->dwItemSpec 행 전체의 설정
		if (m_ctlListSampleSecond.GetItemData(pNMCD->dwItemSpec) == 0)
		{
			*pResult = (LRESULT)CDRF_NOTIFYSUBITEMDRAW;
		}
		else
		{
			// When all matrices are already made.
			*pResult = (LRESULT)CDRF_NEWFONT;
		}
	}
	else if (pNMCD->dwDrawStage == (CDDS_SUBITEM | CDDS_ITEMPREPAINT)){
		// pNMCD->dwItemSpec 행,  pDraw->iSubItem 열의 설정
		NMLVCUSTOMDRAW *pDraw = (NMLVCUSTOMDRAW*)(pNMHDR);
		CString szText = m_ctlListSampleSecond.GetItemText(pNMCD->dwItemSpec, pDraw->iSubItem);
		if (!szText.IsEmpty())
		{
			if (pNMCD->dwItemSpec <= TYPE_GEOMETRY_DISTANCE_MAX &&
				/*(pDraw->iSubItem == 1 || pDraw->iSubItem == 2))*/
				(pDraw->iSubItem == 3 || pDraw->iSubItem == 4))
			{
				if (m_stDistanceSecond[pNMCD->dwItemSpec].m_bOK == false)
					pDraw->clrText = RGB(255, 0, 0);
				if (m_stDistanceSecond[pNMCD->dwItemSpec].m_bSpec == false)
					pDraw->clrTextBk = RGB(255, 242, 0);
			}
		}

		*pResult = (LRESULT)CDRF_NEWFONT;
	}
}

void CTapSizeList::AdjustLayout()
{
	if (NULL == m_ctlMessureSampleFirst.GetSafeHwnd() ||
		NULL == m_ctlMessureSampleSecond.GetSafeHwnd() ||
		NULL == m_ctlListSampleFirst.GetSafeHwnd() ||
		NULL == m_ctlListSampleSecond.GetSafeHwnd())
		return;

	CRect rtClient;
	this->GetClientRect(rtClient);

	const int nClientWidth = rtClient.Width();
	const int nClientHeight = rtClient.Height();

	//
	RECT rtView;
	rtView.left = MARGIN;
	rtView.top = MARGIN;
	rtView.right = rtClient.right - MARGIN;
	rtView.bottom = rtClient.bottom - MARGIN;

	const int cx = (rtView.right - rtView.left - MARGIN) / 2;

	RECT rtFirstView;
	rtFirstView = rtView;
	rtFirstView.right = rtFirstView.left + cx;

	RECT rtSecondView;
	rtSecondView = rtView;
	rtSecondView.left = rtSecondView.right - cx;

	const int nColumnWidth = (nClientWidth - MARGIN * 12) / 10;
	const int nStaticHeight = MARGIN * 6;

	CRect rtStaticSampleA;
	CRect rtStaticSampleB;
	CRect rtStaticMeasureAB;
	{
		RECT rtStatic;
		rtStatic.top = rtClient.top + MARGIN * 2;
		rtStatic.bottom = rtStatic.top + nStaticHeight;

		rtStatic.left = rtFirstView.left + MARGIN * 2;
		rtStatic.right = rtFirstView.right - MARGIN * 2;
		m_ctlMessureSampleFirst.MoveWindow(&rtStatic);
		rtStaticSampleA = rtStatic;

		rtStatic.left = rtSecondView.left + MARGIN * 2;
		rtStatic.right = rtSecondView.right - MARGIN * 2;
		m_ctlMessureSampleSecond.MoveWindow(&rtStatic);
		rtStaticSampleB = rtStatic;

		rtStatic.left = rtStatic.right + MARGIN * 3;
		rtStatic.right = rtSecondView.right - MARGIN * 2;
	}

	{
		RECT rtList;
		rtList.top = rtStaticSampleA.bottom + MARGIN * 2;
		rtList.bottom = rtClient.bottom - MARGIN;

		rtList.left = rtStaticSampleA.left;
		rtList.right = rtStaticSampleA.right;
		m_ctlListSampleFirst.MoveWindow(&rtList);

		rtList.left = rtStaticSampleB.left;
		rtList.right = rtStaticSampleB.right;
		m_ctlListSampleSecond.MoveWindow(&rtList);

		rtList.left = rtStaticMeasureAB.left;
		rtList.right = rtStaticMeasureAB.right;
	}
}

void CTapSizeList::UpdateSizeName()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_OPTION* pstOption = pCaptureManager->GetOption();

	LVCOLUMN stColumn;
	memset(&stColumn, 0x00, sizeof(LVCOLUMN));
	stColumn.mask = LVCF_TEXT;

	CString szName;

	int i = 0;
	for (i = 0; i < MAX_GEOMETRY_DISTANCELINE_COUNT; i++)
	{
		szName = pstOption->m_stSizeName.m_szName[i];
		m_ctlListSampleFirst.SetItemText(i, 0, szName);
		m_ctlListSampleSecond.SetItemText(i, 0, szName);
	}

	{
		szName = pstOption->m_stSizeName.GetNameX1X2();
		m_ctlListSampleFirst.SetItemText(i, 0, szName);
		m_ctlListSampleSecond.SetItemText(i, 0, szName); i++;

		szName = pstOption->m_stSizeName.GetNameS1S3();
		m_ctlListSampleFirst.SetItemText(i, 0, szName);
		m_ctlListSampleSecond.SetItemText(i, 0, szName); i++;

		szName = pstOption->m_stSizeName.GetNameM1M2();
		m_ctlListSampleFirst.SetItemText(i, 0, szName);
		m_ctlListSampleSecond.SetItemText(i, 0, szName); i++;

		// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
		szName = pstOption->m_stSizeName.GetNameSS1SS3();
		m_ctlListSampleFirst.SetItemText(i, 0, szName);
		m_ctlListSampleSecond.SetItemText(i, 0, szName); i++;
	}
}

void CTapSizeList::UpdateRangeValue(TYPE_CAMERAPOS eCameraPos)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_OPTION* pstOption = pCaptureManager->GetOption();

	int cameraIdx = -1;
	if (eCameraPos == TYPE_CAMERAPOS_FIRST)
		cameraIdx = 0;
	else if (eCameraPos == TYPE_CAMERAPOS_SECOND)
		cameraIdx = 1;

	//if (cameraIdx == 0 || cameraIdx == 1)
	//{
		CString szValue;
		for (int i = 0; i < MAX_SIZE_MEASURECOUNT; i++)
		{
			//////szValue.Format(_T("%.3f"), pstOption->m_pstRange[cameraIdx][i].m_fMin);
			szValue.Format(_T("%.3f"), pstOption->m_pstRange[0][i].m_fMin);
			m_ctlListSampleFirst.SetItemText(i, 1, szValue);

			//////szValue.Format(_T("%.3f"), pstOption->m_pstRange[cameraIdx][i].m_fMax);
			szValue.Format(_T("%.3f"), pstOption->m_pstRange[0][i].m_fMax);
			m_ctlListSampleFirst.SetItemText(i, 2, szValue);

			//////szValue.Format(_T("%.3f"), pstOption->m_pstRange[cameraIdx][i].m_fMin);
			szValue.Format(_T("%.3f"), pstOption->m_pstRange[1][i].m_fMin);
			m_ctlListSampleSecond.SetItemText(i, 1, szValue);

			//////szValue.Format(_T("%.3f"), pstOption->m_pstRange[cameraIdx][i].m_fMax);
			szValue.Format(_T("%.3f"), pstOption->m_pstRange[1][i].m_fMax);
			m_ctlListSampleSecond.SetItemText(i, 2, szValue);
		}
	//}
}

void CTapSizeList::UpdateResultSize(TYPE_CAMERAPOS eCameraPos, CSampleSide* pSample)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	BOOL bStart = pInspection->IsStart();
	if (FALSE == bStart)
		return;
	if (!pSample)
		return;

	if (TYPE_CAMERAPOS_FIRST == eCameraPos)
	{
		//memcpy(m_stDistanceFirst, pSample->m_SizeResult.m_stDistance, sizeof(OUTPUT_DISTANCE)* TYPE_GEOMETRY_DISTANCE_MAX);
		memcpy(m_stDistanceFirst, pSample->m_SizeCalculationResult.m_stDistance, sizeof(OUTPUT_DISTANCE)* TYPE_GEOMETRY_DISTANCE_MAX);
		UpdateList(TYPE_CAMERAPOS_FIRST);
	}
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
	{
#ifdef DEF_SECONDCAMERA_CHECKSIZE
		//memcpy(m_stDistanceSecond, pSample->m_SizeResult.m_stDistance, sizeof(OUTPUT_DISTANCE)* TYPE_GEOMETRY_DISTANCE_MAX);
		memcpy(m_stDistanceSecond, pSample->m_SizeCalculationResult.m_stDistance, sizeof(OUTPUT_DISTANCE)* TYPE_GEOMETRY_DISTANCE_MAX);
		UpdateList(TYPE_CAMERAPOS_SECOND);
#else
		// do nothing
#endif
	}
}

void CTapSizeList::UpdateList()
{

	UpdateList(TYPE_CAMERAPOS_FIRST);
	UpdateList(TYPE_CAMERAPOS_SECOND);

	TCHAR szValue[MAX_NAME_LEN] = { 0, };
	TCHAR szValueA[MAX_NAME_LEN] = { 0, };
	TCHAR szValueB[MAX_NAME_LEN] = { 0, };

	double fValueA = 0.0f;
	double fValueB = 0.0f;

	for (int i = 0; i < TYPE_GEOMETRY_DISTANCE_MAX; i++)
	{
		m_ctlListSampleFirst.GetItemText(i, 3, szValueA, MAX_NAME_LEN);
		m_ctlListSampleSecond.GetItemText(i, 1, szValueB, MAX_NAME_LEN);

		fValueA = CUtil::StringToDouble(szValueA, CUtil::StringLength(szValueA));
		fValueB = CUtil::StringToDouble(szValueB, CUtil::StringLength(szValueB));

		//CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%.03f"), abs(fValueA));

		//m_ctlListMeasure.SetItemText(i, 1, szValue);
	}
}

void CTapSizeList::UpdateList(TYPE_CAMERAPOS eCameraPos)
{
	OUTPUT_DISTANCE* pstDistance = NULL;

	if (TYPE_CAMERAPOS_FIRST == eCameraPos)
		pstDistance = m_stDistanceFirst;
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
		pstDistance = m_stDistanceSecond;
	if (pstDistance)
	{
		TCHAR szValue[MAX_NAME_LEN] = { 0, };
		TCHAR szResult[MAX_NAME_LEN] = { 0, };

		for (int i = 0; i < TYPE_GEOMETRY_DISTANCE_MAX; i++)
		{
			CUtil::StringFormat(szValue, MAX_NAME_LEN, _T("%.03f"), pstDistance[i].m_dValue);
			if (pstDistance[i].m_bOK)
				CUtil::StringFormat(szResult, MAX_NAME_LEN, _T("OK"));
			else
				CUtil::StringFormat(szResult, MAX_NAME_LEN, _T("NG"));

			//if (TYPE_SAMPLESHAPE_A == eSampleShape) // && pSample->m_FirstSample)
			if (TYPE_CAMERAPOS_FIRST == eCameraPos)
			{
				m_ctlListSampleFirst.SetItemText(i, 3, szValue);
				m_ctlListSampleFirst.SetItemText(i, 4, szResult);
			}
			//else if (TYPE_SAMPLESHAPE_B == eSampleShape)//  && pSample->m_SecondSample)
			else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
			{
				//////m_ctlListSampleSecond.SetItemText(i, 1, szValue);
				//////m_ctlListSampleSecond.SetItemText(i, 2, szResult);

				m_ctlListSampleSecond.SetItemText(i, 3, szValue);
				m_ctlListSampleSecond.SetItemText(i, 4, szResult);
			}
		}
	}
}
