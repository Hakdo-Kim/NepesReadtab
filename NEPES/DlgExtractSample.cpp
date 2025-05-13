// DlgExtractSample.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "DlgExtractSample.h"
#include "afxdialogex.h"

#include "CaptureManager.h"
#include "stringres.h"
#include "Util/Util.h"

#include <string>


// CDlgExtractSample dialog

IMPLEMENT_DYNAMIC(CDlgExtractSample, CDialogEx)

CDlgExtractSample::CDlgExtractSample(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgExtractSample::IDD, pParent)
{
}

CDlgExtractSample::~CDlgExtractSample()
{
}

void CDlgExtractSample::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_FIRST, m_ctlFirstTitle);
	DDX_Control(pDX, IDC_STATIC_SECOND, m_ctlSecondTitle);
	DDX_Control(pDX, IDC_LIST_FIRSTQUEUE, m_ctlFirstQueue);
	DDX_Control(pDX, IDC_LIST_SECONDQUEUE, m_ctlSecondQueue);
}

BOOL CDlgExtractSample::OnCommand(WPARAM wParam, LPARAM lParam)
{
	return CDialogEx::OnCommand(wParam, lParam);
}

BOOL CDlgExtractSample::PreTranslateMessage(MSG* pMsg)
{
	return CDialogEx::PreTranslateMessage(pMsg);
}

BOOL CDlgExtractSample::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Title
	m_ctlFirstTitle.SetTextFont(_T("MS Shell Dlg"), 20, FW_BOLD);
	m_ctlSecondTitle.SetTextFont(_T("MS Shell Dlg"), 20, FW_BOLD);

	CString szFirst;
	CString szSecond;
	szFirst.Format(_T("%s (검사 대기 시료)"), STR_MSG_FIRSTCAMERA);
	szSecond.Format(_T("%s (검사 대기 시료)"), STR_MSG_SECONDCAMERA);

	m_ctlFirstTitle.SetMessage((LPTSTR)(LPCTSTR)szFirst);
	m_ctlSecondTitle.SetMessage((LPTSTR)(LPCTSTR)szSecond);


	// Sample Queue
	m_ctlFirstQueue.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_ctlSecondQueue.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	int idx = 0;
	m_ctlFirstQueue.InsertColumn(idx, _T("Idx"), LVCFMT_LEFT, 50, -1);		idx++;		// Index A or B
	m_ctlFirstQueue.InsertColumn(idx, _T("상면검사"), LVCFMT_LEFT, 150, -1);	idx++;
	m_ctlFirstQueue.InsertColumn(idx, _T("하면검사"), LVCFMT_LEFT, 150, -1);	idx++;

	m_ctlSecondQueue.InsertColumn(idx, _T("Idx"), LVCFMT_LEFT, 50, -1);			idx++;	// Index A or B
	m_ctlSecondQueue.InsertColumn(idx, _T("상면검사"), LVCFMT_LEFT, 150, -1);	idx++;
	m_ctlSecondQueue.InsertColumn(idx, _T("하면검사"), LVCFMT_LEFT, 150, -1);	idx++;


	const int nCurFirst = m_ctlFirstQueue.GetNextItem(-1, LVNI_SELECTED);
	if (-1 < nCurFirst)
		GetDlgItem(IDC_BTN_FIRST_DELETE)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_BTN_FIRST_DELETE)->EnableWindow(FALSE);

	const int nCurSecond = m_ctlSecondQueue.GetNextItem(-1, LVNI_SELECTED);
	if (-1 < nCurSecond)
		GetDlgItem(IDC_BTN_SECOND_DELETE)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_BTN_SECOND_DELETE)->EnableWindow(FALSE);

	UpdateListSampleQueue();

	return TRUE;
}


BEGIN_MESSAGE_MAP(CDlgExtractSample, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_FIRSTQUEUE, &CDlgExtractSample::OnLvnItemchangedListFirstqueue)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_SECONDQUEUE, &CDlgExtractSample::OnLvnItemchangedListSecondqueue)
	ON_BN_CLICKED(IDC_BTN_FIRST_DELETE, &CDlgExtractSample::OnBnClickedBtnFirstDelete)
	ON_BN_CLICKED(IDC_BTN_SECOND_DELETE, &CDlgExtractSample::OnBnClickedBtnSecondDelete)
END_MESSAGE_MAP()


// CDlgExtractSample message handlers
void CDlgExtractSample::OnLvnItemchangedListFirstqueue(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	*pResult = 0;

	const int nCur = m_ctlFirstQueue.GetNextItem(-1, LVNI_SELECTED);
	if (-1 < nCur)
		GetDlgItem(IDC_BTN_FIRST_DELETE)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_BTN_FIRST_DELETE)->EnableWindow(FALSE);
}

void CDlgExtractSample::OnLvnItemchangedListSecondqueue(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	*pResult = 0;

	const int nCur = m_ctlSecondQueue.GetNextItem(-1, LVNI_SELECTED);
	if (-1 < nCur)
		GetDlgItem(IDC_BTN_SECOND_DELETE)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_BTN_SECOND_DELETE)->EnableWindow(FALSE);
}

void CDlgExtractSample::OnBnClickedBtnFirstDelete()
{
	const int nCur = m_ctlFirstQueue.GetNextItem(-1, LVNI_SELECTED);
	if (0 > nCur)
		return;

	// Delete Selected item...
	{
		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
		CInspection* pInspection = pCaptureManager->GetInspection();
		CInspectionCamera* pFirstCamera = pInspection->GetInspectionCamera(TYPE_CAMERAPOS_FIRST);

		//////////////////////pFirstCamera->DeleteSampleFromSampleQueue(nCur);
	}

	// Update List Control
	m_ctlFirstQueue.DeleteAllItems();
	m_ctlSecondQueue.DeleteAllItems();
	UpdateListSampleQueue();
}

void CDlgExtractSample::OnBnClickedBtnSecondDelete()
{
	const int nCur = m_ctlSecondQueue.GetNextItem(-1, LVNI_SELECTED);
	if (0 > nCur)
		return;

	// Delete Selected item...
	{
		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
		CInspection* pInspection = pCaptureManager->GetInspection();
		CInspectionCamera* pSecondCamera = pInspection->GetInspectionCamera(TYPE_CAMERAPOS_SECOND);

		if (!pCaptureManager->m_SummaryFirstQueue.empty()){
			pCaptureManager->m_SummaryFirstQueue.pop();
		}

		///////////////////////pSecondCamera->DeleteSampleFromSampleQueue(nCur);
	}

	// Update List Control
	m_ctlFirstQueue.DeleteAllItems();
	m_ctlSecondQueue.DeleteAllItems();
	UpdateListSampleQueue();
}

void CDlgExtractSample::UpdateListSampleQueue()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	if (!pCaptureManager->m_SummaryFirstQueue.empty()){
		const int nSize = pCaptureManager->m_SummaryFirstQueue.size();

		INFO_SUMMARY_TOTAL_FLAG stFirstSummayResult = pCaptureManager->m_SummaryFirstQueue.front(); 

		TCHAR szTxt[MAX_NAME_LEN] = { 0, };

		CUtil::StringFormat(szTxt, MAX_NAME_LEN, _T("%d"), nSize);

		m_ctlSecondQueue.InsertItem(0, szTxt);

		if (stFirstSummayResult.m_bSizeResult == FALSE)
			CUtil::StringFormat(szTxt, MAX_NAME_LEN, _T("NG 치수"));
		else if (stFirstSummayResult.m_bShapeResult == FALSE)
			CUtil::StringFormat(szTxt, MAX_NAME_LEN, _T("NG 외관"));
		else
			CUtil::StringFormat(szTxt, MAX_NAME_LEN, _T("OK"));

		m_ctlSecondQueue.SetItem(0, 1, LVIF_TEXT, szTxt, 0, 0, 0, NULL);
	}

	//////////////////////////////////////////// 아래가 원본


	//CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	//const INFO_OPTION* pstOption = pCaptureManager->GetOption();

	//CInspection* pInspection = pCaptureManager->GetInspection();
	//TCHAR szTxt[MAX_NAME_LEN] = { 0, };
	//{
	//	CInspectionCamera* pFirstCamera = pInspection->GetInspectionCamera(TYPE_CAMERAPOS_FIRST);
	//	const int nSize = pFirstCamera->GetCountFromSampleQueue();
	//	for (int i = 0; i < nSize; i++)
	//	{
	//		CSample* pSample = pFirstCamera->GetSampleFromSampleQueue(i);
	//		if (NULL == pSample)
	//			continue;

	//		if (TYPE_SAMPLESHAPE_A == pSample->m_eSampleShape)
	//			CUtil::StringFormat(szTxt, MAX_NAME_LEN, _T("%d (A)"), pSample->m_nIndex);
	//		else if (TYPE_SAMPLESHAPE_B == pSample->m_eSampleShape)
	//			CUtil::StringFormat(szTxt, MAX_NAME_LEN, _T("%d (B)"), pSample->m_nIndex);
	//		else
	//			CUtil::StringFormat(szTxt, MAX_NAME_LEN, _T("%d"), pSample->m_nIndex);
	//		m_ctlFirstQueue.InsertItem(i, szTxt);

	//		// Result: First Camera
	//		m_ctlFirstQueue.SetItem(i, 1, LVIF_TEXT, _T("Ready"), 0, 0, 0, NULL);
	//		// Result: Second Camera
	//		m_ctlFirstQueue.SetItem(i, 2, LVIF_TEXT, _T("Ready"), 0, 0, 0, NULL);
	//	}
	//}
	//{
	//	CInspectionCamera* pSecondCamera = pInspection->GetInspectionCamera(TYPE_CAMERAPOS_SECOND);
	//	const int nSize = pSecondCamera->GetCountFromSampleQueue();
	//	for (int i = 0; i < nSize; i++)
	//	{
	//		CSample* pSample = pSecondCamera->GetSampleFromSampleQueue(i);
	//		if (NULL == pSample)
	//			continue;

	//		if (TYPE_SAMPLESHAPE_A == pSample->m_eSampleShape)
	//			CUtil::StringFormat(szTxt, MAX_NAME_LEN, _T("%d (A)"), pSample->m_nIndex);
	//		else if (TYPE_SAMPLESHAPE_B == pSample->m_eSampleShape)
	//			CUtil::StringFormat(szTxt, MAX_NAME_LEN, _T("%d (B)"), pSample->m_nIndex);
	//		else
	//			CUtil::StringFormat(szTxt, MAX_NAME_LEN, _T("%d"), pSample->m_nIndex);
	//		m_ctlSecondQueue.InsertItem(i, szTxt);

	//		// Result: First Camera
	//		{
	//			CString szFirst;
	//			CString szStepResult;
	//			if (pstOption->m_stFirstCameraStep.m_bStep001 || pstOption->m_stFirstCameraStep.m_bStep002 ||
	//				pstOption->m_stFirstCameraStep.m_bStep003 || pstOption->m_stFirstCameraStep.m_bStep004 ||
	//				pstOption->m_stFirstCameraStep.m_bStep005 || pstOption->m_stFirstCameraStep.m_bStep006)
	//			{
	//				if (pstOption->m_stFirstCameraStep.m_bStep001)
	//				{
	//					BOOL bResSize = TRUE;
	//					for (int s = 0; s < TYPE_GEOMETRY_DISTANCE_MAX; s++)
	//					{
	//						if (FALSE == pSample->m_FirstSample.m_SizeResult.m_stDistance[s].m_bOK)
	//						{
	//							bResSize = FALSE;
	//							break;
	//						}
	//					}
	//					szStepResult.Format(_T("%s(%d) "), pstOption->m_stFirstCameraStep.m_szTitleStep01, 
	//						(int)bResSize);
	//					szFirst = szStepResult;
	//				}
	//				if (pstOption->m_stFirstCameraStep.m_bStep002)
	//				{
	//					szStepResult.Format(_T("%s(%d) "), pstOption->m_stFirstCameraStep.m_szTitleStep02, 
	//						(int)pSample->m_FirstSample.m_StainResult.m_bResult);
	//					szFirst += szStepResult;
	//				}
	//				if (pstOption->m_stFirstCameraStep.m_bStep003)
	//				{
	//					szStepResult.Format(_T("%s(%d) "), pstOption->m_stFirstCameraStep.m_szTitleStep03,
	//						(int)pSample->m_FirstSample.m_DifferResult.m_bResult);
	//					szFirst += szStepResult;
	//				}
	//				if (pstOption->m_stFirstCameraStep.m_bStep004)
	//				{ 
	//					szStepResult.Format(_T("%s(%d) "), pstOption->m_stFirstCameraStep.m_szTitleStep04,
	//						(int)pSample->m_FirstSample.m_BubbleResult.m_bResult);
	//					szFirst += szStepResult;
	//				}
	//				if (pstOption->m_stFirstCameraStep.m_bStep005)
	//				{
	//					szStepResult.Format(_T("%s(%d) "), pstOption->m_stFirstCameraStep.m_szTitleStep05,
	//						(int)pSample->m_FirstSample.m_ScratchResult.m_bResult);
	//					szFirst += szStepResult;
	//				}
	//				if (pstOption->m_stFirstCameraStep.m_bStep006)
	//				{
	//					szStepResult.Format(_T("%s(%d) "), pstOption->m_stFirstCameraStep.m_szTitleStep06,
	//						(int)pSample->m_FirstSample.m_StampResult.m_bResult);
	//					szFirst += szStepResult;
	//				}
	//				m_ctlSecondQueue.SetItem(i, 1, LVIF_TEXT, szFirst, 0, 0, 0, NULL);
	//			}
	//			else
	//			{
	//				m_ctlSecondQueue.SetItem(i, 1, LVIF_TEXT, _T("Ready"), 0, 0, 0, NULL);
	//			}
	//		}
	//		

	//		// Result: Second Camera
	//		{
	//			/*//
	//			CString szSecond;
	//			CString szStepResult;
	//			if (pstOption->m_stSecondCameraStep.m_bStep002 ||
	//				pstOption->m_stSecondCameraStep.m_bStep003 || pstOption->m_stSecondCameraStep.m_bStep004 ||
	//				pstOption->m_stSecondCameraStep.m_bStep005 || pstOption->m_stSecondCameraStep.m_bStep006)
	//			{
	//				if (pstOption->m_stSecondCameraStep.m_bStep002)
	//				{
	//					szStepResult.Format(_T("%s(%d) "), pstOption->m_stSecondCameraStep.m_szTitleStep02,
	//						(int)pSample->m_SecondSample.m_StainResult.m_bResult);
	//					szSecond += szStepResult;
	//				}
	//				if (pstOption->m_stSecondCameraStep.m_bStep003)
	//				{
	//					szStepResult.Format(_T("%s(%d) "), pstOption->m_stSecondCameraStep.m_szTitleStep03,
	//						(int)pSample->m_SecondSample.m_DifferResult.m_bResult);
	//					szSecond += szStepResult;
	//				}
	//				if (pstOption->m_stSecondCameraStep.m_bStep004)
	//				{
	//					szStepResult.Format(_T("%s(%d) "), pstOption->m_stSecondCameraStep.m_szTitleStep04,
	//						(int)pSample->m_SecondSample.m_BubbleResult.m_bResult);
	//					szSecond += szStepResult;
	//				}
	//				if (pstOption->m_stSecondCameraStep.m_bStep005)
	//				{
	//					szStepResult.Format(_T("%s(%d) "), pstOption->m_stSecondCameraStep.m_szTitleStep05,
	//						(int)pSample->m_SecondSample.m_ScratchResult.m_bResult);
	//					szSecond += szStepResult;
	//				}
	//				if (pstOption->m_stSecondCameraStep.m_bStep006)
	//				{
	//					szStepResult.Format(_T("%s(%d) "), pstOption->m_stSecondCameraStep.m_szTitleStep06,
	//						(int)pSample->m_SecondSample.m_StampResult.m_bResult);
	//					szSecond += szStepResult;
	//				}
	//				m_ctlSecondQueue.SetItem(i, 2, LVIF_TEXT, szSecond, 0, 0, 0, NULL);
	//			}
	//			else
	//			//*/
	//			{
	//				m_ctlSecondQueue.SetItem(i, 2, LVIF_TEXT, _T("Ready"), 0, 0, 0, NULL);
	//			}
	//		}
	//	}
	//}
}