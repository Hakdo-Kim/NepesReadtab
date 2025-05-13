// DlgOptionEtc.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "DlgOptionEtc.h"
#include "afxdialogex.h"

#include "CaptureManager.h"
#include "Util/Util.h"

// CDlgOptionEtc dialog

IMPLEMENT_DYNAMIC(CDlgOptionEtc, CDialogEx)

CDlgOptionEtc::CDlgOptionEtc(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgOptionEtc::IDD, pParent)
{
	memset(&m_stEtcOption, 0x00, sizeof(INFO_OPTIONETC));

}

CDlgOptionEtc::~CDlgOptionEtc()
{
}

void CDlgOptionEtc::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL CDlgOptionEtc::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_OPTIONETC* pstOptEtc = pCaptureManager->GetOptionEtc();
	memcpy(&m_stEtcOption, pstOptEtc, sizeof(INFO_OPTIONETC));

	// Lot Id
	GetDlgItem(IDC_EDIT_LOTIDPATH)->SetWindowText(m_stEtcOption.m_szLotIdPath);

	// Log
	GetDlgItem(IDC_EDIT_LOGPATH)->SetWindowText(m_stEtcOption.m_stLogInfo.m_szLogPath);

	if (m_stEtcOption.m_stLogInfo.m_bSaveTextLog)
		((CButton*)GetDlgItem(IDC_CHECK_LOGTEXT))->SetCheck(BST_CHECKED);
	else
		((CButton*)GetDlgItem(IDC_CHECK_LOGTEXT))->SetCheck(BST_UNCHECKED);

	if (m_stEtcOption.m_stLogInfo.m_bSaveErrorImage)
		((CButton*)GetDlgItem(IDC_CHECK_ERRORIMAGE))->SetCheck(BST_CHECKED);
	else
		((CButton*)GetDlgItem(IDC_CHECK_ERRORIMAGE))->SetCheck(BST_UNCHECKED);
	
	if (m_stEtcOption.m_stLogInfo.m_bSaveProbImage)
		((CButton*)GetDlgItem(IDC_CHECK_PROBIMAGE))->SetCheck(BST_CHECKED);
	else
		((CButton*)GetDlgItem(IDC_CHECK_PROBIMAGE))->SetCheck(BST_UNCHECKED);
	
	GetDlgItem(IDC_EDIT_SAVEIMAGECOUNTER)->SetWindowText("0");

	CheckSaveErrorImage();

	CInspection* pInspection = pCaptureManager->GetInspection();
	BOOL bStart = pInspection->IsStart();
	
	GetDlgItem(IDC_BTN_SELECTLOTID)->EnableWindow(!bStart);
	GetDlgItem(IDC_BTN_SELECT)->EnableWindow(!bStart);
	GetDlgItem(IDC_CHECK_LOGTEXT)->EnableWindow(!bStart);

#ifdef IDC_EDIT_SAVEIMAGEFORMAT
	// 2022-03-31 추가 : 이미지 저장 형식 변경
	GetDlgItem(IDC_EDIT_SAVEIMAGEFORMAT)->SetWindowText(pstOptEtc->m_stLogInfo.m_szSaveImageFormat);
	// 기본 포멧을 가장 먼저 추가. png가 기본형이므로 png를 가장 먼저 추가
	((CComboBox*)GetDlgItem(IDC_EDIT_SAVEIMAGEFORMAT))->AddString(".png");
	((CComboBox*)GetDlgItem(IDC_EDIT_SAVEIMAGEFORMAT))->AddString(".jpg");

	// Ver 1.3.6.7
	CString count = "";
	count.Format(_T("%d"), pstOptEtc->m_stLogInfo.m_nUserSetCount);
	GetDlgItem(IDC_EDIT_PNGCOUNT)->SetWindowText(count);
#endif

#ifdef IDC_EDIT_SAVEOKIMAGE
	if (m_stEtcOption.m_stLogInfo.m_bSaveOKImage)
		((CButton*)GetDlgItem(IDC_EDIT_SAVEOKIMAGE))->SetCheck(BST_CHECKED);
	else
		((CButton*)GetDlgItem(IDC_EDIT_SAVEOKIMAGE))->SetCheck(BST_UNCHECKED);
#endif
	// Version 1.3.7.6 Save OK Image Period
	if (m_stEtcOption.m_stLogInfo.m_bSaveOKImage_Period)
		((CButton*)GetDlgItem(IDC_EDIT_SAVEOKPERIOD))->SetCheck(BST_CHECKED);
	else
		((CButton*)GetDlgItem(IDC_EDIT_SAVEOKIMAGE))->SetCheck(BST_UNCHECKED);

	CString periodetime = "";
	periodetime.Format(_T("%d"), pstOptEtc->m_stLogInfo.m_nSavePeriodTime);
	GetDlgItem(IDC_EDIT_PERIODTIME)->SetWindowText(periodetime);

	return TRUE;
}


BEGIN_MESSAGE_MAP(CDlgOptionEtc, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgOptionEtc::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BTN_SELECTLOTID, &CDlgOptionEtc::OnBnClickedBtnSelectlotid)
	ON_BN_CLICKED(IDC_BTN_SELECT, &CDlgOptionEtc::OnBnClickedBtnSelect)
	ON_BN_CLICKED(IDC_CHECK_ERRORIMAGE, &CDlgOptionEtc::OnBnClickedCheckErrorimage)
	ON_BN_CLICKED(IDC_CHECK_PROBIMAGE, &CDlgOptionEtc::OnBnClickedCheckProbimage)
	ON_BN_CLICKED(IDC_EDIT_SAVEOKPERIOD, &CDlgOptionEtc::OnBnClickedEditSaveokperiod)
	ON_BN_CLICKED(IDC_EDIT_SAVEOKIMAGE, &CDlgOptionEtc::OnBnClickedEditSaveokimage)
END_MESSAGE_MAP()


// CDlgOptionEtc message handlers
void CDlgOptionEtc::OnBnClickedOk()
{
	// SaveImageFormat 선택 안 할 경우를 대비하여 이전 Format 저장
	TCHAR loadSaveFormat[MAX_FILE_PATH_LEN];
	CUtil::StringCopy(loadSaveFormat, m_stEtcOption.m_stLogInfo.m_szSaveImageFormat);

	memset(&m_stEtcOption, 0x00, sizeof(INFO_OPTIONETC));

	// Lot Id
	GetDlgItem(IDC_EDIT_LOTIDPATH)->GetWindowText(m_stEtcOption.m_szLotIdPath, MAX_FILE_PATH_LEN);

	// Log
	GetDlgItem(IDC_EDIT_LOGPATH)->GetWindowText(m_stEtcOption.m_stLogInfo.m_szLogPath, MAX_FILE_PATH_LEN);

	if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_LOGTEXT))->GetCheck())
		m_stEtcOption.m_stLogInfo.m_bSaveTextLog = TRUE;
	else
		m_stEtcOption.m_stLogInfo.m_bSaveTextLog = FALSE;

	if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_ERRORIMAGE))->GetCheck())
		m_stEtcOption.m_stLogInfo.m_bSaveErrorImage = TRUE;
	else
		m_stEtcOption.m_stLogInfo.m_bSaveErrorImage = FALSE;

	if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_PROBIMAGE))->GetCheck()){
		m_stEtcOption.m_stLogInfo.m_bSaveProbImage = TRUE;

		TCHAR szTemp[MAX_FILE_PATH_LEN] = "";
		GetDlgItem(IDC_EDIT_SAVEIMAGECOUNTER)->GetWindowText(szTemp, MAX_FILE_PATH_LEN);

		try
		{
			m_stEtcOption.m_stLogInfo.m_nSaveProbImageCount = stoi(szTemp);
		}
		catch (std::invalid_argument const& ex)
		{
			m_stEtcOption.m_stLogInfo.m_nSaveProbImageCount = 0;
		}

		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
		pCaptureManager->m_nCountSaveProbImage = 0;
	}
	else
		m_stEtcOption.m_stLogInfo.m_bSaveProbImage = FALSE;

#ifdef IDC_EDIT_SAVEIMAGEFORMAT
	// Save Image Format
	// 2022-03-31 추가 : 이미지 저장 형식 변경
	// 2022-04-08 추가 : 신규 자료형을 추가할 경우(ex. .bmp) AddString 함수를 사용하면 추가된 자료형이 상단에 생성
	// 추가 선택하지 않을 경우 이전 Format 사용
	if (((CComboBox*)GetDlgItem(IDC_EDIT_SAVEIMAGEFORMAT))->GetCurSel() == -1)
	{
		CUtil::StringCopy(m_stEtcOption.m_stLogInfo.m_szSaveImageFormat, loadSaveFormat);
	}
	// 추가 선택할 경우 해당 Format으로 변경
	else
	{
		CString temp;
		((CComboBox*)GetDlgItem(IDC_EDIT_SAVEIMAGEFORMAT))->GetLBText(((CComboBox*)GetDlgItem(IDC_EDIT_SAVEIMAGEFORMAT))->GetCurSel(), temp);
		CUtil::StringCopy(m_stEtcOption.m_stLogInfo.m_szSaveImageFormat, temp);
	}

	// Ver 1.3.6.7
	// Png 20 EA Save -> jpg Change
	if (CUtil::StringCompare(m_stEtcOption.m_stLogInfo.m_szSaveImageFormat, ".png")) m_stEtcOption.m_stLogInfo.m_nFormatCount = 0;
	{
		TCHAR* temp = new TCHAR[MAX_FILE_PATH_LEN];
		GetDlgItem(IDC_EDIT_PNGCOUNT)->GetWindowText(temp, MAX_FILE_PATH_LEN);
		m_stEtcOption.m_stLogInfo.m_nUserSetCount = atoi(temp);
	}
	
#endif

#ifdef IDC_EDIT_SAVEOKIMAGE
	if (((CButton*)GetDlgItem(IDC_EDIT_SAVEOKIMAGE))->GetCheck())
		m_stEtcOption.m_stLogInfo.m_bSaveOKImage = TRUE;
	else
		m_stEtcOption.m_stLogInfo.m_bSaveOKImage = FALSE;
#endif
	// Version 1.3.7.6 Save OK Image Period
	if (((CButton*)GetDlgItem(IDC_EDIT_SAVEOKPERIOD))->GetCheck())
		m_stEtcOption.m_stLogInfo.m_bSaveOKImage_Period = TRUE;
	else
		m_stEtcOption.m_stLogInfo.m_bSaveOKImage_Period = FALSE;

	TCHAR* tempPeriodTime = new TCHAR[MAX_FILE_PATH_LEN];
	GetDlgItem(IDC_EDIT_PERIODTIME)->GetWindowText(tempPeriodTime, MAX_FILE_PATH_LEN);
	m_stEtcOption.m_stLogInfo.m_nSavePeriodTime = atoi(tempPeriodTime);

	CDialogEx::OnOK();
}

void CDlgOptionEtc::OnBnClickedBtnSelectlotid()
{
	CString szTemp;
	GetDlgItem(IDC_EDIT_LOTIDPATH)->GetWindowText(szTemp);

	TCHAR cpath[128] = _T("");

	LPITEMIDLIST pDirList;
	BROWSEINFO browseInfo;
	browseInfo.hwndOwner = NULL;
	browseInfo.pidlRoot = NULL;
	browseInfo.lpszTitle = "Select Directory";
	browseInfo.pszDisplayName = cpath;
	browseInfo.ulFlags = BIF_RETURNONLYFSDIRS | BIF_STATUSTEXT | BIF_VALIDATE;
	browseInfo.lpfn = NULL;
	browseInfo.lParam = (LPARAM)(LPTSTR)(LPCTSTR)szTemp;

	pDirList = SHBrowseForFolder(&browseInfo);
	if (pDirList == NULL)
		return;

	BOOL bResult = SHGetPathFromIDList(pDirList, cpath);
	if (bResult)
	{
		GetDlgItem(IDC_EDIT_LOTIDPATH)->SetWindowText(cpath);
	}
}

void CDlgOptionEtc::OnBnClickedBtnSelect()
{
	CString szTemp;
	GetDlgItem(IDC_EDIT_LOGPATH)->GetWindowText(szTemp);

	TCHAR cpath[128] = _T("");

	LPITEMIDLIST pDirList;
	BROWSEINFO browseInfo;
	browseInfo.hwndOwner = NULL;
	browseInfo.pidlRoot = NULL;
	browseInfo.lpszTitle = "Select Directory";
	browseInfo.pszDisplayName = cpath;
	browseInfo.ulFlags = BIF_RETURNONLYFSDIRS | BIF_STATUSTEXT | BIF_VALIDATE;
	browseInfo.lpfn = NULL;
	browseInfo.lParam = (LPARAM)(LPTSTR)(LPCTSTR)szTemp;

	pDirList = SHBrowseForFolder(&browseInfo);
	if (pDirList == NULL)
		return;

	BOOL bResult = SHGetPathFromIDList(pDirList, cpath);
	if (bResult)
	{
		GetDlgItem(IDC_EDIT_LOGPATH)->SetWindowText(cpath);
	}
}

void CDlgOptionEtc::CheckSaveErrorImage()
{
	if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_ERRORIMAGE))->GetCheck())
	{
		GetDlgItem(IDC_CHECK_PROBIMAGE)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_SAVEIMAGECOUNTER)->EnableWindow(TRUE);
		//CheckSaveProbImage();
	}
	else
	{
		GetDlgItem(IDC_CHECK_PROBIMAGE)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_SAVEIMAGECOUNTER)->EnableWindow(FALSE);
	}
}

void CDlgOptionEtc::CheckSaveProbImage()
{
	if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_PROBIMAGE))->GetCheck())
		GetDlgItem(IDC_EDIT_SAVEIMAGECOUNTER)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_EDIT_SAVEIMAGECOUNTER)->EnableWindow(FALSE);
}

void CDlgOptionEtc::CheckSaveOKImage()
{
	if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_EDIT_SAVEOKIMAGE))->GetCheck())
		GetDlgItem(IDC_EDIT_PNGCOUNT)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_EDIT_PNGCOUNT)->EnableWindow(FALSE);
}

void CDlgOptionEtc::CheckSaveOKImagePeriod()
{
	if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_PROBIMAGE))->GetCheck())
		GetDlgItem(IDC_EDIT_PERIODTIME)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_EDIT_PERIODTIME)->EnableWindow(FALSE);
}

void CDlgOptionEtc::OnBnClickedCheckErrorimage()
{
	//CheckSaveErrorImage();
}

void CDlgOptionEtc::OnBnClickedCheckProbimage()
{
	//CheckSaveProbImage();
}


void CDlgOptionEtc::OnBnClickedEditSaveokimage()
{
	//CheckSaveOKImage();
}


void CDlgOptionEtc::OnBnClickedEditSaveokperiod()
{
	//CheckSaveOKImagePeriod();
}



