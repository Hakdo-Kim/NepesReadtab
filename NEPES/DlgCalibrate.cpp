// DlgCalibrate.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "DlgCalibrate.h"
#include "afxdialogex.h"

#include "CaptureManager.h"
#include "stringres.h"

#include "Util/Util.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#define REFERENCE_CHECK _T("O")

using namespace std;

// CDlgCalibrate dialog

IMPLEMENT_DYNAMIC(CDlgCalibrate, CDialogEx)

CDlgCalibrate::CDlgCalibrate(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgCalibrate::IDD, pParent)
	, m_iRow(0)
	, m_iCol(0)
	, m_dSpacing(0)
	, m_iChessUnit(0)
	, m_iMethod(0)
	, m_dWidth(0)
	, m_dHeight(0)
	, m_iPixelUnit(0)
{
	m_pstCalibratePrev = NULL;

	m_iImgWidth = 0;
	m_iImgHeight = 0;
}

CDlgCalibrate::~CDlgCalibrate()
{
}

void CDlgCalibrate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_FILELIST, m_ctlFilePathList);
	DDX_Control(pDX, IDC_SPIN_GRIDROW, m_ctlGridRows);
	DDX_Control(pDX, IDC_SPIN_GRIDCOL, m_ctlGridCols);
	DDX_Control(pDX, IDC_SPIN_SPACING, m_ctlSpacing);
	DDX_Control(pDX, IDC_COMBO_CHESSUNIT, m_ctlComboChessUnit);
	DDX_Text(pDX, IDC_EDIT_GRIDROW, m_iRow);
	DDX_Text(pDX, IDC_EDIT_GRIDCOL, m_iCol);
	DDX_Text(pDX, IDC_EDIT_SPACING, m_dSpacing);
	DDX_CBIndex(pDX, IDC_COMBO_CHESSUNIT, m_iChessUnit);
	DDX_Control(pDX, IDC_EDIT_SPACING, m_EditSpacing);
	DDX_Radio(pDX, IDC_RADIO_PIXEL, m_iMethod);
	DDV_MinMaxInt(pDX, m_iMethod, 0, 1);
	DDX_Text(pDX, IDC_EDIT_WIDTH, m_dWidth);
	DDV_MinMaxDouble(pDX, m_dWidth, 0, 1000.00);
	DDX_Text(pDX, IDC_EDIT_HEIGHT, m_dHeight);
	DDV_MinMaxDouble(pDX, m_dHeight, 0, 1000.00);
	DDX_Control(pDX, IDC_SPIN_WIDTH, m_ctlWidth);
	DDX_Control(pDX, IDC_SPIN_HEIGHT, m_ctlHeight);
	DDX_CBIndex(pDX, IDC_COMBO_PIXELUNIT, m_iPixelUnit);
	DDX_Control(pDX, IDC_COMBO_PIXELUNIT, m_ctlComboPixelUnit);
}

BOOL CDlgCalibrate::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_ctlFilePathList.DeleteAllItems();
	m_ctlFilePathList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES);
	m_ctlFilePathList.InsertColumn(0, _T("NO"), LVCFMT_LEFT, 50, -1);
	m_ctlFilePathList.InsertColumn(1, _T("FILE NAME"), LVCFMT_LEFT, 150, -1);
	m_ctlFilePathList.InsertColumn(2, _T("REF"), LVCFMT_LEFT, 50, -1);


	m_ctlWidth.SetRange32(MIN_SPIN, MAX_SPIN);
	m_ctlHeight.SetRange32(MIN_SPIN, MAX_SPIN);
	m_ctlGridRows.SetRange32(MIN_GRIDROWS, MAX_GRIDROWS);
	m_ctlGridCols.SetRange32(MIN_GRIDCOLS, MAX_GRIDCOLS);
	m_ctlSpacing.SetRange32(MIN_SPIN, MAX_SPIN);

	m_ctlWidth.SetPos32(MIN_SPIN);
	m_ctlHeight.SetPos32(MAX_SPIN);
	m_ctlGridRows.SetPos32(MIN_GRIDROWS);
	m_ctlGridCols.SetPos32(MIN_GRIDCOLS);
	m_ctlSpacing.SetPos32(MIN_SPIN);

	m_ctlComboPixelUnit.AddString(_T("millimeter"));
	m_ctlComboPixelUnit.SetCurSel(0);
	m_ctlComboChessUnit.AddString(_T("millimeter"));
	m_ctlComboChessUnit.SetCurSel(0);

	// 이전 설정이 있을 경우 해당 설정으로 초기화
	if (m_pstCalibratePrev)
	{
		this->m_iMethod = m_pstCalibratePrev->m_iMethod;

		this->m_dWidth = m_pstCalibratePrev->m_dWidth;
		this->m_dHeight = m_pstCalibratePrev->m_dHeight;
		this->m_iPixelUnit = m_pstCalibratePrev->m_iPixelUnit;

		for (int i = 0; i < m_pstCalibratePrev->m_nListCount; i++)
		{
			CString strIdx;
			int idx = m_ctlFilePathList.GetItemCount();

			strIdx.Format(_T("%d"), idx);
			m_ctlFilePathList.InsertItem(idx, strIdx);
			m_ctlFilePathList.SetItemText(idx, 1, m_pstCalibratePrev->m_pszFilePathList[i]);
			m_ctlFilePathList.SetItemText(idx, 2, _T(""));
			if (idx == m_pstCalibratePrev->m_nIdxReference)
				m_ctlFilePathList.SetItemText(idx, 2, REFERENCE_CHECK);
		}

		this->m_iRow = m_pstCalibratePrev->m_iRow;
		this->m_iCol = m_pstCalibratePrev->m_iCol;
		this->m_dSpacing = m_pstCalibratePrev->m_dSpacing;
		this->m_iChessUnit = 0; // millimeter로 고정

		// double 오차 보정
		this->m_dWidth += DOUBLE_CORRECTION;
		m_ctlWidth.SetPos32(static_cast<int>(this->m_dWidth * 100));
		this->m_dWidth = static_cast<double>(m_ctlWidth.GetPos32()) / 100;
		this->m_dHeight += DOUBLE_CORRECTION;
		m_ctlHeight.SetPos32(static_cast<int>(this->m_dHeight * 100));
		this->m_dHeight = static_cast<double>(m_ctlHeight.GetPos32()) / 100;
		this->m_dSpacing += DOUBLE_CORRECTION;
		m_ctlSpacing.SetPos32(static_cast<int>(this->m_dSpacing * 100));
		this->m_dSpacing = static_cast<double>(m_ctlSpacing.GetPos32()) / 100;

		UpdateData(FALSE);
	}

	OnBnClickedRadioMethod();

	return TRUE;
}

BEGIN_MESSAGE_MAP(CDlgCalibrate, CDialogEx)
	ON_WM_CONTEXTMENU()
	ON_BN_CLICKED(IDOK, &CDlgCalibrate::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDlgCalibrate::OnBnClickedCancel)

	ON_COMMAND(ID_CALIBRATE_ADD, &CDlgCalibrate::OnCommandAdd)
	ON_COMMAND(ID_CALIBRATE_DELETE, &CDlgCalibrate::OnCommandDelete)
	ON_COMMAND(ID_CALIBRATE_REFERENCE, &CDlgCalibrate::OnCommandReference)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_SPACING, &CDlgCalibrate::OnDeltaposSpinSpacing)
	ON_BN_CLICKED(IDC_RADIO_PIXEL, &CDlgCalibrate::OnBnClickedRadioMethod)
	ON_BN_CLICKED(IDC_RADIO_CHESS, &CDlgCalibrate::OnBnClickedRadioMethod)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_WIDTH, &CDlgCalibrate::OnDeltaposSpinWidth)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_HEIGHT, &CDlgCalibrate::OnDeltaposSpinHeight)
END_MESSAGE_MAP()


// CDlgCalibrate message handlers
void CDlgCalibrate::OnContextMenu(CWnd* pWnd, CPoint point)
{

	CRect rtList;
	m_ctlFilePathList.GetWindowRect(rtList);

	if (rtList.PtInRect(point))
	{
		const int nCur = m_ctlFilePathList.GetNextItem(-1, LVNI_SELECTED);

		CMenu Menu;
		Menu.LoadMenu(IDR_MENU_POPUPCALIBRATE);

		CMenu* pSubMenu = Menu.GetSubMenu(0);
		if (pSubMenu)
		{
			if (0 > nCur)
			{
				pSubMenu->EnableMenuItem(ID_CALIBRATE_DELETE, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
				pSubMenu->EnableMenuItem(ID_CALIBRATE_REFERENCE, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
			}
			pSubMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
		}
		Menu.DestroyMenu();
	}

}

void CDlgCalibrate::OnBnClickedOk()
{
	if (!UpdateData(TRUE))
		return;

	BOOL bInputValueError = FALSE;

	if (m_iMethod < 0)
	{
		m_iMethod = 0; bInputValueError = TRUE;
	}
	if (m_iMethod > 1)
	{
		m_iMethod = 1; bInputValueError = TRUE;
	}
	if (m_dWidth < MIN_WIDTH)
	{
		m_dWidth = MIN_WIDTH; bInputValueError = TRUE;
	}
	if (m_dWidth > MAX_WIDTH)
	{
		m_dWidth = MAX_WIDTH; bInputValueError = TRUE;
	}
	if (m_dHeight < MIN_HEIGHT)
	{
		m_dHeight = MIN_HEIGHT; bInputValueError = TRUE;
	}
	if (m_dHeight > MAX_HEIGHT)
	{
		m_dHeight = MAX_HEIGHT; bInputValueError = TRUE;
	}

	if (bInputValueError)
	{
		UpdateData(FALSE);
	}

	SetEnableControls(FALSE);
	GetDlgItem(IDOK)->EnableWindow(FALSE);
	SetDlgItemText(IDOK, _T("Calibrating..."));
	GetDlgItem(IDCANCEL)->EnableWindow(FALSE);

	INFO_CALIBRATION stCalibrate;
	memset(&stCalibrate, 0, sizeof(INFO_CALIBRATION));

	stCalibrate.m_iMethod = this->m_iMethod;

	stCalibrate.m_iImgWidth = this->m_iImgWidth;
	stCalibrate.m_iImgHeight = this->m_iImgHeight;

	stCalibrate.m_dWidth = this->m_dWidth;
	stCalibrate.m_dHeight = this->m_dHeight;
	stCalibrate.m_iPixelUnit = this->m_iPixelUnit;

	stCalibrate.m_nListCount = m_ctlFilePathList.GetItemCount();
	for (int i = 0; i < stCalibrate.m_nListCount; i++)
	{
		CString path = m_ctlFilePathList.GetItemText(i, 1);
		_tcscpy_s(stCalibrate.m_pszFilePathList[i], MAX_FILE_PATH_LEN, path);

		CString ref = m_ctlFilePathList.GetItemText(i, 2);
		if (ref.Compare(REFERENCE_CHECK) == 0)
			stCalibrate.m_nIdxReference = i;
	}

	stCalibrate.m_iRow = this->m_iRow;
	stCalibrate.m_iCol = this->m_iCol;
	stCalibrate.m_dSpacing = this->m_dSpacing;
	stCalibrate.m_iChessUnit = this->m_iChessUnit;

	Log("SetCalibration");
	CalibrateStepSize(&stCalibrate);
	int iCalResult = GetCalibrationResult();
	Log("Calibration Result: (Error code: %d)", iCalResult);

	CString msg;
	switch (GetCalibrationResult())
	{
	case 0: // ERR_SUCCESS
		msg.Format(_T("Success to calibrate"));
		AfxMessageBox(msg);
		break;
	case -1:
		msg.Format(_T("Error: Step is not initialized\n(Error code: %d)"), iCalResult);
		AfxMessageBox(msg);
		break;
	case 1001:
		msg.Format(_T("Error: 2 images or more are required\n(Error code: %d)"), iCalResult);
		AfxMessageBox(msg);
		break;
	case 1002:
		msg.Format(_T("Error: Parameters are not valid\n(Error code: %d)"), iCalResult);
		AfxMessageBox(msg);
		break;
	case 1003:
		msg.Format(_T("Error: Enter a exact chess board cols and rows\n(Error code: %d)"), iCalResult);
		AfxMessageBox(msg);
		break;
	case 1004:
		msg.Format(_T("Error: Cannot get chess board corners from reference image\n(Error code: %d)"), iCalResult);
		AfxMessageBox(msg);
		break;
	case 1005:
		msg.Format(_T("Error: Error to calculate pixel distance\n(Error code: %d)"), iCalResult);
		AfxMessageBox(msg);
		break;
	default:
		msg.Format(_T("Error: Unexpected error occured\n(Error code: %d)"), iCalResult);
		AfxMessageBox(msg);
		break;
	}

	GetDlgItem(IDOK)->EnableWindow(TRUE);
	SetDlgItemText(IDOK, _T("OK"));
	GetDlgItem(IDCANCEL)->EnableWindow(TRUE);

	CDialogEx::OnOK();
}

void CDlgCalibrate::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
}


void CDlgCalibrate::OnCommandAdd()
{
	const int iMaxFileCount = MAX_CALIBRATE_FILECOUNT;

	CFileDialog FileDlg(TRUE, NULL, NULL, OFN_ALLOWMULTISELECT, "이미지 파일(*.jpg;*.bmp;*.png;)|*.jpg;*.bmp;*.png;|All Files(*.*)|*.*||");

	char cfilename[MAX_FILE_PATH_LEN * MAX_CALIBRATE_FILECOUNT];
	memset(cfilename, 0, sizeof(cfilename));
	FileDlg.m_ofn.lpstrFile = cfilename;
	FileDlg.m_ofn.nMaxFile = sizeof(cfilename);

	cv::Mat img;

	if (FileDlg.DoModal() == IDOK)
	{
		POSITION pos = FileDlg.GetStartPosition();

		while (pos)
		{
			CString FilePath;
			string sFilePath;

			FilePath = FileDlg.GetNextPathName(pos);
			sFilePath = std::string(CT2CA(FilePath.operator LPCSTR()));

			if (FilePath.IsEmpty())
			{
				continue;
			}
			else
			{
				img = cv::imread(sFilePath, CV_LOAD_IMAGE_GRAYSCALE);

				if (img.empty())
				{
					CString msg;
					msg = _T("Cannot read image\n");
					msg += FilePath;
					AfxMessageBox(msg);
					break;
				}
				if (img.cols != m_iImgWidth ||
					img.rows != m_iImgHeight)
				{
					CString msg;
					msg = _T("Load image is not same size\n");
					msg += FilePath;
					AfxMessageBox(msg);
					break;
				}
			}

			CString strIdx;
			int idx = m_ctlFilePathList.GetItemCount();

			strIdx.Format(_T("%d"), idx);
			m_ctlFilePathList.InsertItem(idx, strIdx);
			m_ctlFilePathList.SetItemText(idx, 1, FilePath);
			m_ctlFilePathList.SetItemText(idx, 2, _T(""));
			if (idx == 0)
				m_ctlFilePathList.SetItemText(idx, 2, REFERENCE_CHECK);
		}
	}
}

void CDlgCalibrate::OnCommandDelete()
{
	// 체크된 항목 삭제
	for (int i = m_ctlFilePathList.GetItemCount(); i >= 0; --i)
	{
		if (TRUE == m_ctlFilePathList.GetCheck(i))
			m_ctlFilePathList.DeleteItem(i);
	}

	// Index 갱신, Reference image가 지정되어 있지 않을 경우 0번 지정
	bool bRef = false;
	for (int i = 0; i < m_ctlFilePathList.GetItemCount(); i++)
	{
		CString strIdx;
		strIdx.Format(_T("%d"), i);
		m_ctlFilePathList.SetItemText(i, 0, strIdx);

		CString ref = m_ctlFilePathList.GetItemText(i, 2);
		if (ref.Compare(REFERENCE_CHECK) == 0)
			bRef = true;
	}
	if (!bRef && m_ctlFilePathList.GetItemCount() > 0)
	{
		m_ctlFilePathList.SetItemText(0, 2, REFERENCE_CHECK);
	}
}

void CDlgCalibrate::OnCommandReference()
{
	POSITION pos = m_ctlFilePathList.GetFirstSelectedItemPosition();
	if (pos == NULL)
		return;

	int idx = m_ctlFilePathList.GetNextSelectedItem(pos);
	if (idx < 0)
		return;

	for (int i = 0; i < m_ctlFilePathList.GetItemCount(); i++)
		m_ctlFilePathList.SetItemText(i, 2, _T(""));

	m_ctlFilePathList.SetItemText(idx, 2, REFERENCE_CHECK);
}

void CDlgCalibrate::OnDeltaposSpinWidth(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);

	UpdateData();

	m_dWidth += (static_cast<double>(pNMUpDown->iDelta) / 100) + DOUBLE_CORRECTION;
	m_ctlSpacing.SetPos32(static_cast<int>(m_dWidth * 100));
	m_dWidth = static_cast<double>(m_ctlSpacing.GetPos32()) / 100;

	UpdateData(FALSE);

	*pResult = 0;
}

void CDlgCalibrate::OnDeltaposSpinHeight(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);

	UpdateData();

	m_dHeight += (static_cast<double>(pNMUpDown->iDelta) / 100) + DOUBLE_CORRECTION;
	m_ctlSpacing.SetPos32(static_cast<int>(m_dHeight * 100));
	m_dHeight = static_cast<double>(m_ctlSpacing.GetPos32()) / 100;

	UpdateData(FALSE);

	*pResult = 0;
}

void CDlgCalibrate::OnDeltaposSpinSpacing(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);

	UpdateData();

	m_dSpacing += (static_cast<double>(pNMUpDown->iDelta) / 100) + DOUBLE_CORRECTION;
	m_ctlSpacing.SetPos32(static_cast<int>(m_dSpacing * 100));
	m_dSpacing = static_cast<double>(m_ctlSpacing.GetPos32()) / 100;

	UpdateData(FALSE);

	*pResult = 0;
}

void CDlgCalibrate::UpdateCameraPos(TYPE_CAMERAPOS ePos)
{
	m_eCameraPos = ePos;
}

BOOL CDlgCalibrate::CalibrateStepSize(const INFO_CALIBRATION* pstInfo)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	BOOL bResult = TRUE;
	CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
	CStepSize* pStepSize = dynamic_cast<CStepSize*>(pStep);
	if (pStepSize)
	{
		bResult &= pStepSize->SetCalibration(pstInfo);
	}

	pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStepSecond);
	CStepSizeSecond* pStepSizeSecond = dynamic_cast<CStepSizeSecond*>(pStep);
	if (pStepSizeSecond)
	{
		bResult &= pStepSizeSecond->SetCalibration(pstInfo);
	}

	CInspectionCamera* pCamera = pInspection->GetInspectionCamera(m_eCameraPos);
	CStepSizeCalculation* pStepCalc = pCamera->GetStepSizeCalc();
	if (pStepCalc)
	{
		bResult &= pStepCalc->SetCalibration(pstInfo);
	}

	return bResult;
}

int CDlgCalibrate::GetCalibrationResult()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	int bResult = -1;
	CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
	CStepSize* pStepSize = dynamic_cast<CStepSize*>(pStep);
	if (pStepSize)
	{
		bResult = pStepSize->GetCalibrationResult();
	}

	if (bResult == 0)
	{
		pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStepSecond);
		CStepSizeSecond* pStepSizeSecond = dynamic_cast<CStepSizeSecond*>(pStep);
		if (pStepSizeSecond)
		{
			bResult = pStepSizeSecond->GetCalibrationResult();
		}
	}

	if (bResult == 0)
	{
		CInspectionCamera* pCamera = pInspection->GetInspectionCamera(m_eCameraPos);
		CStepSizeCalculation* pStepCalc = pCamera->GetStepSizeCalc();
		if (pStepCalc)
		{
			bResult = pStepCalc->GetCalibrationResult();
		}
	}

	return bResult;
}

void CDlgCalibrate::SetEnableControls(BOOL bEnable)
{
	GetDlgItem(IDC_RADIO_PIXEL)->EnableWindow(bEnable);
	GetDlgItem(IDC_RADIO_CHESS)->EnableWindow(bEnable);
	SetEnablePixelControls(bEnable);
	SetEnableChessControls(bEnable);
}

void CDlgCalibrate::SetEnablePixelControls(BOOL bEnable)
{
	GetDlgItem(IDC_EDIT_WIDTH)->EnableWindow(bEnable);
	m_ctlWidth.EnableWindow(bEnable);
	GetDlgItem(IDC_EDIT_HEIGHT)->EnableWindow(bEnable);
	m_ctlHeight.EnableWindow(bEnable);
	m_ctlComboPixelUnit.EnableWindow(bEnable);
}
void CDlgCalibrate::SetEnableChessControls(BOOL bEnable)
{
	m_ctlFilePathList.EnableWindow(bEnable);
	GetDlgItem(IDC_EDIT_GRIDROW)->EnableWindow(bEnable);
	m_ctlGridRows.EnableWindow(bEnable);
	GetDlgItem(IDC_EDIT_GRIDCOL)->EnableWindow(bEnable);
	m_ctlGridCols.EnableWindow(bEnable);
	GetDlgItem(IDC_EDIT_SPACING)->EnableWindow(bEnable);
	m_ctlSpacing.EnableWindow(bEnable);
	m_ctlComboChessUnit.EnableWindow(bEnable);
}
void CDlgCalibrate::OnBnClickedRadioMethod()
{
	UpdateData();

	SetEnablePixelControls(FALSE);
	SetEnableChessControls(FALSE);
	if (m_iMethod == 0)
		SetEnablePixelControls(TRUE);
	else if (m_iMethod == 1)
		SetEnableChessControls(TRUE);
}

void CDlgCalibrate::Log(char* pszLog, ...)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();

	if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
	{
		char szLog[MAX_TEXT_LEN] = { 0, };

		va_list arg;
		va_start(arg, pszLog);
		_vsntprintf(szLog, sizeof(szLog), pszLog, arg);
		va_end(arg);

		stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, this->m_eCameraPos, "SIZE DIALOG", szLog);
	}
}
