// TapMainSize.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "TapMainSize.h"
#include "afxdialogex.h"

#include "CaptureManager.h"
#include "Util/Util.h"
#include "stringres.h"

// CTapMainSize dialog

IMPLEMENT_DYNAMIC(CTapMainSize, CDialogEx)

CTapMainSize::CTapMainSize(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTapMainSize::IDD, pParent)
{
	memset(&m_rtView, 0x00, sizeof(RECT));
	memset(&m_rtFirstView, 0x00, sizeof(RECT));
	memset(&m_rtSecondView, 0x00, sizeof(RECT));

	m_hFileSample_First = INVALID_HANDLE_VALUE;
	m_hFileSample_Second = INVALID_HANDLE_VALUE;
	m_hFileSample_Total = INVALID_HANDLE_VALUE;
}

CTapMainSize::~CTapMainSize()
{
	// First Camera
	if (INVALID_HANDLE_VALUE != m_hFileSample_First)
		::CloseHandle(m_hFileSample_First);
	m_hFileSample_First = INVALID_HANDLE_VALUE;

	// Second Camera
	if (INVALID_HANDLE_VALUE != m_hFileSample_Second)
		::CloseHandle(m_hFileSample_Second);
	m_hFileSample_Second = INVALID_HANDLE_VALUE;

	// Total
	if (INVALID_HANDLE_VALUE != m_hFileSample_Total)
		::CloseHandle(m_hFileSample_Total);
	m_hFileSample_Total = INVALID_HANDLE_VALUE;
}

void CTapMainSize::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_TITLESAMPLEA, m_ctlTitleSampleFirst);
	DDX_Control(pDX, IDC_STATIC_TITLESAMPLEB, m_ctlTitleSampleSecond);
}

BOOL CTapMainSize::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (IDOK == wParam)
	{
		return TRUE;
	}
	return CDialogEx::OnCommand(wParam, lParam);
}

BOOL CTapMainSize::PreTranslateMessage(MSG* pMsg)
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

BOOL CTapMainSize::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//
	m_ctlTitleSampleFirst.SetTextFont(_T("MS Shell Dlg"), 20, FW_BOLD);
	m_ctlTitleSampleSecond.SetTextFont(_T("MS Shell Dlg"), 20, FW_BOLD);

	m_ctlTitleSampleFirst.SetMessage(STR_TAPVIEW_SAMPLE_FIRST);
	m_ctlTitleSampleSecond.SetMessage(STR_TAPVIEW_SAMPLE_SECOND);

	//
	CRuntimeClass* pClass = RUNTIME_CLASS(CCustomScrollViewSize);
	m_pScrollViewList[FIRST_VIEW] = (CCustomScrollViewSize*)pClass->CreateObject();
	if (m_pScrollViewList[FIRST_VIEW])
	{
		RECT rect;
		memset(&rect, 0x00, sizeof(RECT));
		rect.right = 10;
		rect.bottom = 10;

		m_pScrollViewList[FIRST_VIEW]->Create(NULL, NULL, WS_CHILD, rect, this, AFX_IDW_PANE_FIRST + 1, NULL);
		m_pScrollViewList[FIRST_VIEW]->SendMessage(WM_INITIALUPDATE);
		m_pScrollViewList[FIRST_VIEW]->ShowWindow(SW_SHOW);
		m_pScrollViewList[FIRST_VIEW]->EnableWindow(FALSE);
	}

	pClass = RUNTIME_CLASS(CCustomScrollViewSize);
	m_pScrollViewList[SECOND_VIEW] = (CCustomScrollViewSize*)pClass->CreateObject();
	if (m_pScrollViewList[SECOND_VIEW])
	{
		RECT rect;
		memset(&rect, 0x00, sizeof(RECT));
		rect.right = 10;
		rect.bottom = 10;

		m_pScrollViewList[SECOND_VIEW]->Create(NULL, NULL, WS_CHILD, rect, this, AFX_IDW_PANE_FIRST + 1, NULL);
		m_pScrollViewList[SECOND_VIEW]->SendMessage(WM_INITIALUPDATE);
		m_pScrollViewList[SECOND_VIEW]->ShowWindow(SW_SHOW);
		m_pScrollViewList[SECOND_VIEW]->EnableWindow(FALSE);
	}


	m_TapSizeList.Create(CTapSizeList::IDD, this);
	m_TapSizeList.ShowWindow(SW_SHOW);

	AdjustLayout();
	return TRUE;  // return TRUE  unless you set the focus to a control
}



BEGIN_MESSAGE_MAP(CTapMainSize, CDialogEx)
	ON_WM_SIZE()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CTapMainSize message handlers
void CTapMainSize::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	AdjustLayout();
	this->Invalidate();
}

void CTapMainSize::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CRect rect;
	GetClientRect(&rect);

	const int nClientWidth = rect.Width();
	const int nClientHeight = rect.Height();


	//DrawLayout(&dc, m_rtView, RGB(200, 200, 200), IDB_STATIC_GUARD_LEFTTOP, IDB_STATIC_GUARD_LEFTBOTTOM, IDB_STATIC_GUARD_RIGHTTOP, IDB_STATIC_GUARD_RIGHTBOTTOM);
	//DrawLayout(&dc, m_rtFirstView, RGB(200, 200, 200), IDB_STATIC_GUARD_LEFTTOP, IDB_STATIC_GUARD_LEFTBOTTOM, IDB_STATIC_GUARD_RIGHTTOP, IDB_STATIC_GUARD_RIGHTBOTTOM);
	//DrawLayout(&dc, m_rtSecondView, RGB(200, 200, 200), IDB_STATIC_GUARD_LEFTTOP, IDB_STATIC_GUARD_LEFTBOTTOM, IDB_STATIC_GUARD_RIGHTTOP, IDB_STATIC_GUARD_RIGHTBOTTOM);

	CDialogEx::OnPaint();
}


void CTapMainSize::AdjustLayout()
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
	m_rtFirstView.right = m_rtFirstView.left + cx;

	m_rtSecondView = m_rtView;
	m_rtSecondView.left = m_rtSecondView.right - cx;


	const int nListHeight = 360;

	CRect rtTapSizeList;
	{
		RECT rtTemp = m_rtView;
		rtTemp.top = rtTemp.bottom - nListHeight;

		m_TapSizeList.MoveWindow(&rtTemp);
		rtTapSizeList = rtTemp;
	}

	{
		RECT rtTitle;
		rtTitle.left = m_rtFirstView.left + MARGIN * 2;
		rtTitle.top = m_rtFirstView.top + MARGIN * 2;
		rtTitle.right = m_rtFirstView.right - MARGIN * 2;
		rtTitle.bottom = rtTitle.top + MARGIN * 6;
		m_ctlTitleSampleFirst.MoveWindow(&rtTitle);


		rtTitle.left = m_rtSecondView.left + MARGIN * 2;
		rtTitle.top = m_rtSecondView.top + MARGIN * 2;
		rtTitle.right = m_rtSecondView.right - MARGIN * 2;
		rtTitle.bottom = rtTitle.top + MARGIN * 6;
		m_ctlTitleSampleSecond.MoveWindow(&rtTitle);


		RECT rtTemp = m_rtFirstView;
		rtTemp.left += (MARGIN * 2);
		rtTemp.top += (MARGIN * 10);
		rtTemp.right -= (MARGIN * 2);
		rtTemp.bottom = rtTapSizeList.top - MARGIN * 2;
		m_pScrollViewList[FIRST_VIEW]->MoveWindow(&rtTemp);

		rtTemp = m_rtSecondView;
		rtTemp.left += (MARGIN * 2);
		rtTemp.top += (MARGIN * 10);
		rtTemp.right -= (MARGIN * 2);
		rtTemp.bottom = rtTapSizeList.top - MARGIN * 2;
		m_pScrollViewList[SECOND_VIEW]->MoveWindow(&rtTemp);

	}


}

void CTapMainSize::DrawLayout(CDC* pDC, CRect rect, COLORREF rgbBk, DWORD dwLT, DWORD dwLB, DWORD dwRT, DWORD dwRB)
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

void CTapMainSize::UpdateRangeValue(TYPE_CAMERAPOS eCameraPos)
{
	if (m_TapSizeList.m_hWnd)
	{
		m_TapSizeList.UpdateRangeValue(eCameraPos);
	}
}

void CTapMainSize::UpdateSizeName()
{
	if (m_TapSizeList.m_hWnd)
	{
		m_TapSizeList.UpdateSizeName();
	}
}

void CTapMainSize::SetStateStartInspection()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();
	INFO_SUMMARY* pstSummary = pCaptureManager->GetResultSummary();

	// First Camera
	if (INVALID_HANDLE_VALUE != m_hFileSample_First)
		::CloseHandle(m_hFileSample_First);
	m_hFileSample_First = INVALID_HANDLE_VALUE;

	// Second Camera
	if (INVALID_HANDLE_VALUE != m_hFileSample_Second)
		::CloseHandle(m_hFileSample_Second);
	m_hFileSample_Second = INVALID_HANDLE_VALUE;

	// Total
	if (INVALID_HANDLE_VALUE != m_hFileSample_Total)
		::CloseHandle(m_hFileSample_Total);
	m_hFileSample_Total = INVALID_HANDLE_VALUE;


	BOOL bStart = pInspection->IsStart();
	if (bStart)
	{
		SYSTEMTIME stTime;
		::GetLocalTime(&stTime);

		// Save summary
		TCHAR szSizeLogPath[MAX_FILE_PATH_LEN] = { 0, };
		const INFO_OPTIONETC* pstOptEtc = pCaptureManager->GetOptionEtc();

		// First Camera
		{
			CUtil::StringFormat(szSizeLogPath, MAX_FILE_PATH_LEN, _T("%s\\%04d%02d%02d_%02d%02d%02d_size_info_first_%s.csv"),
				pstOptEtc->m_szLotIdPath,
				stTime.wYear, stTime.wMonth, stTime.wDay, stTime.wHour, stTime.wMinute, stTime.wSecond, pstSummary->m_szLotId);

			m_hFileSample_First = ::CreateFile(szSizeLogPath,
				GENERIC_READ | GENERIC_WRITE,
				FILE_SHARE_READ | FILE_SHARE_WRITE,
				NULL,
				CREATE_ALWAYS,
				FILE_FLAG_WRITE_THROUGH,
				NULL);
			if (INVALID_HANDLE_VALUE == m_hFileSample_First)
			{
				CString szMsg = STR_MSG_SIZE_ELOG;
				AfxMessageBox(szMsg);
			}
		}

		// Second Camera
		{
			CUtil::StringFormat(szSizeLogPath, MAX_FILE_PATH_LEN, _T("%s\\%04d%02d%02d_%02d%02d%02d_size_info_second_%s.csv"),
				pstOptEtc->m_szLotIdPath,
				stTime.wYear, stTime.wMonth, stTime.wDay, stTime.wHour, stTime.wMinute, stTime.wSecond, pstSummary->m_szLotId);

			m_hFileSample_Second = ::CreateFile(szSizeLogPath,
				GENERIC_READ | GENERIC_WRITE,
				FILE_SHARE_READ | FILE_SHARE_WRITE,
				NULL,
				CREATE_ALWAYS,
				FILE_FLAG_WRITE_THROUGH,
				NULL);
			if (INVALID_HANDLE_VALUE == m_hFileSample_Second)
			{
				CString szMsg = STR_MSG_SIZE_ELOG;
				AfxMessageBox(szMsg);
			}
		}

		//Total Count
		{
			CUtil::StringFormat(szSizeLogPath, MAX_FILE_PATH_LEN, _T("%s\\%04d%02d%02d_%02d%02d%02d_size_info_total_%s.csv"),
				pstOptEtc->m_szLotIdPath,
				stTime.wYear, stTime.wMonth, stTime.wDay, stTime.wHour, stTime.wMinute, stTime.wSecond, pstSummary->m_szLotId);

			m_hFileSample_Total = ::CreateFile(szSizeLogPath,
				GENERIC_READ | GENERIC_WRITE,
				FILE_SHARE_READ | FILE_SHARE_WRITE,
				NULL,
				CREATE_ALWAYS,
				FILE_FLAG_WRITE_THROUGH,
				NULL);
			if (INVALID_HANDLE_VALUE == m_hFileSample_Total)
			{
				CString szMsg = STR_MSG_SIZE_ELOG;
				AfxMessageBox(szMsg);
			}
		}

		const INFO_OPTION* pstOption = pCaptureManager->GetOption();
		TCHAR szString[MAX_TEXT_LEN] = { 0, };

		CUtil::StringFormat(szString, MAX_TEXT_LEN, _T("%s,,"), pstSummary->m_szLotId);

		int nIdx = 0;
		for (; nIdx < MAX_GEOMETRY_DISTANCELINE_COUNT; nIdx++){
			CUtil::StringFormat(szString, MAX_TEXT_LEN, _T("%s%s,,"), szString, pstOption->m_stSizeName.m_szName[nIdx]);
		}

		CUtil::StringFormat(szString, MAX_TEXT_LEN, _T("%s%s,,"), szString, pstOption->m_stSizeName.GetNameX1X2());
		CUtil::StringFormat(szString, MAX_TEXT_LEN, _T("%s%s,,"), szString, pstOption->m_stSizeName.GetNameS1S3());
		CUtil::StringFormat(szString, MAX_TEXT_LEN, _T("%s%s,,"), szString, pstOption->m_stSizeName.GetNameM1M2());

		CUtil::StringFormat(szString, MAX_TEXT_LEN, _T("%s\r\n"), szString);

		WriteSizeLog(TYPE_CAMERAPOS_FIRST, szString, CUtil::StringLength(szString));
		WriteSizeLog(TYPE_CAMERAPOS_SECOND, szString, CUtil::StringLength(szString));

		CUtil::StringFormat(szString, MAX_TEXT_LEN, _T("%s,,%s,%s,%s,%s,%s,%s,%s\r\n"),
			pstSummary->m_szLotId, STR_SUMMARY_ROW_TOTAL,
			STR_SUMMARY_LOG_ERRORSIZE_COUNT, STR_SUMMARY_LOG_ERRORSIZE_RATIO,
			STR_SUMMARY_LOG_ERRORSHAPE_COUNT, STR_SUMMARY_LOG_ERRORSHAPERATIO,
			STR_SUMMARY_LOG_ERRORSIZE, STR_SUMMARY_LOG_ERRORSHAPE);

		WriteSizeLog(TYPE_CAMERAPOS_NONE, szString, CUtil::StringLength(szString));

		//pCaptureManager->m_hFile_Total = m_hFileSample_Total;
		pCaptureManager->SetTotalLogHandle(m_hFileSample_Total);
	}
}

void CTapMainSize::UpdateResultSize(TYPE_CAMERAPOS eCameraPos, CSampleSide* pSample)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	BOOL bStart = pInspection->IsStart();
	if (FALSE == bStart)
		return;

	if (TYPE_CAMERAPOS_FIRST == eCameraPos)
	{
		if (m_pScrollViewList[FIRST_VIEW])
			m_pScrollViewList[FIRST_VIEW]->DisplayResult(pSample);
	}
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
	{
#ifdef DEF_SECONDCAMERA_CHECKSIZE
		if (m_pScrollViewList[SECOND_VIEW])
			m_pScrollViewList[SECOND_VIEW]->DisplayResult(pSample);
#else
		// do nothing
#endif
	}

	if (m_TapSizeList.m_hWnd)
	{
		m_TapSizeList.UpdateResultSize(eCameraPos, pSample);
	}

	if (pSample)
	{
		TCHAR szString[MAX_TEXT_LEN] = { 0, };
		TCHAR szSample[MAX_NAME_LEN] = { 0, };

		int nIndex = 0;

		SYSTEMTIME stTime;
		::GetLocalTime(&stTime);

		if (TYPE_CAMERAPOS_FIRST == eCameraPos)
		{
			nIndex = pCaptureManager->GetResultSummary()->m_stSummaryFirst.m_nSampleCount;
			CUtil::StringFormat(szSample, MAX_NAME_LEN, _T("FIRST"));
		}
		else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
		{
			nIndex = pCaptureManager->GetResultSummary()->m_stSummarySecond.m_nSampleCount;
			CUtil::StringFormat(szSample, MAX_NAME_LEN, _T("SECOND"));
		}

		CUtil::StringFormat(szString, MAX_TEXT_LEN, _T("%d,%04d%02d%02d %02d:%02d:%02d,"),
			nIndex,
			stTime.wYear, stTime.wMonth, stTime.wDay,
			stTime.wHour, stTime.wMinute, stTime.wSecond);

		WriteSizeLog(eCameraPos, szString, CUtil::StringLength(szString));

		{
			const INFO_OPTION* pstOption = pCaptureManager->GetOption();

			OUTPUT_DISTANCE* pstDistance = NULL;
			int nIdx = 0;


			for (; nIdx < MAX_GEOMETRY_DISTANCELINE_COUNT; nIdx++)
			{
				pstDistance = &(pSample->m_SizeCalculationResult.m_stDistance[nIdx]);
				FormatSizeLog(szString, MAX_TEXT_LEN, pstOption->m_stSizeName.m_szName[nIdx], pstDistance->m_dValue, pstDistance->m_bOK);
				WriteSizeLog(eCameraPos, szString, CUtil::StringLength(szString));
			}

			{
				pstDistance = &(pSample->m_SizeCalculationResult.m_stDistance[nIdx]);
				FormatSizeLog(szString, MAX_TEXT_LEN, pstOption->m_stSizeName.GetNameX1X2(), pstDistance->m_dValue, pstDistance->m_bOK);
				WriteSizeLog(eCameraPos, szString, CUtil::StringLength(szString)); nIdx++;

				pstDistance = &(pSample->m_SizeCalculationResult.m_stDistance[nIdx]);
				FormatSizeLog(szString, MAX_TEXT_LEN, pstOption->m_stSizeName.GetNameS1S3(), pstDistance->m_dValue, pstDistance->m_bOK);
				WriteSizeLog(eCameraPos, szString, CUtil::StringLength(szString)); nIdx++;

				pstDistance = &(pSample->m_SizeCalculationResult.m_stDistance[nIdx]);
				FormatSizeLog(szString, MAX_TEXT_LEN, pstOption->m_stSizeName.GetNameM1M2(), pstDistance->m_dValue, pstDistance->m_bOK);
				WriteSizeLog(eCameraPos, szString, CUtil::StringLength(szString)); nIdx++;
			}

			CUtil::StringFormat(szString, MAX_TEXT_LEN, _T("\r\n"));
			WriteSizeLog(eCameraPos, szString, CUtil::StringLength(szString));
		}
	}
}


void CTapMainSize::FormatSizeLog(TCHAR* pStr, const int nStrLen, const TCHAR* pszSizeTitle, const double fSizeValue, const BOOL bSizeResult)
{
	if (NULL == pStr || NULL == pszSizeTitle)
		return;

	if (bSizeResult)
		//CUtil::StringFormat(pStr, nStrLen, _T("%s value %.03f result(OK) \r\n"), pszSizeTitle, fSizeValue);
		CUtil::StringFormat(pStr, nStrLen, _T("%.03f,OK,"), fSizeValue);
	else
		//CUtil::StringFormat(pStr, nStrLen, _T("%s value %.03f result(NG) \r\n"), pszSizeTitle, fSizeValue);
		CUtil::StringFormat(pStr, nStrLen, _T("%.03f,NG,"), fSizeValue);
}

void CTapMainSize::WriteSizeLog(TYPE_CAMERAPOS eCameraPos, TCHAR* pString, int nLen)
{
	DWORD dwResult = 0;
	if (TYPE_CAMERAPOS_FIRST == eCameraPos)
	{
		if (INVALID_HANDLE_VALUE == m_hFileSample_First)
			return;
		::WriteFile(m_hFileSample_First, pString, nLen, &dwResult, NULL);
	}
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
	{
		if (INVALID_HANDLE_VALUE == m_hFileSample_Second)
			return;
		::WriteFile(m_hFileSample_Second, pString, nLen, &dwResult, NULL);
	}
	else if (TYPE_CAMERAPOS_NONE == eCameraPos)
	{
		if (INVALID_HANDLE_VALUE == m_hFileSample_Total)
			return;
		::WriteFile(m_hFileSample_Total, pString, nLen, &dwResult, NULL);
	}
}
