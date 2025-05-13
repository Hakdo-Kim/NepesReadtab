// DlgStepName.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "DlgStepName.h"
#include "afxdialogex.h"

#include "CaptureManager.h"
#include "Util/Util.h"

#include "stringres.h"


// CDlgStepName dialog

IMPLEMENT_DYNAMIC(CDlgStepName, CDialogEx)

CDlgStepName::CDlgStepName(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgStepName::IDD, pParent)
{
}

CDlgStepName::~CDlgStepName()
{
}

void CDlgStepName::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL CDlgStepName::OnCommand(WPARAM wParam, LPARAM lParam)
{
	return CDialogEx::OnCommand(wParam, lParam);
}

BOOL CDlgStepName::PreTranslateMessage(MSG* pMsg)
{
	if (VK_RETURN == pMsg->wParam)
	{
		if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_SAMENAME))->GetCheck())
		{
			CString szValue;

			const HWND hWnd = GetFocus()->m_hWnd;
			if (hWnd == GetDlgItem(IDC_EDIT_FIRSTSTEP2)->m_hWnd)
			{
				GetDlgItem(IDC_EDIT_FIRSTSTEP2)->GetWindowText(szValue);
				GetDlgItem(IDC_EDIT_SECONDSTEP2)->SetWindowText(szValue);
			}
			else if (hWnd == GetDlgItem(IDC_EDIT_FIRSTSTEP3)->m_hWnd)
			{
				GetDlgItem(IDC_EDIT_FIRSTSTEP3)->GetWindowText(szValue);
				GetDlgItem(IDC_EDIT_SECONDSTEP3)->SetWindowText(szValue);
			}
			else if (hWnd == GetDlgItem(IDC_EDIT_FIRSTSTEP4)->m_hWnd)
			{
				GetDlgItem(IDC_EDIT_FIRSTSTEP4)->GetWindowText(szValue);
				GetDlgItem(IDC_EDIT_SECONDSTEP4)->SetWindowText(szValue);
			}
			else if (hWnd == GetDlgItem(IDC_EDIT_FIRSTSTEP5)->m_hWnd)
			{
				GetDlgItem(IDC_EDIT_FIRSTSTEP5)->GetWindowText(szValue);
				GetDlgItem(IDC_EDIT_SECONDSTEP5)->SetWindowText(szValue);
			}
			else if (hWnd == GetDlgItem(IDC_EDIT_FIRSTSTEP6)->m_hWnd)
			{
				GetDlgItem(IDC_EDIT_FIRSTSTEP6)->GetWindowText(szValue);
				GetDlgItem(IDC_EDIT_SECONDSTEP6)->SetWindowText(szValue);
			}
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

BOOL CDlgStepName::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	GetDlgItem(IDC_STATIC_FIRSTCAMERA)->SetWindowText(STR_MSG_FIRSTCAMERA);
	GetDlgItem(IDC_STATIC_SECONDCAMERA)->SetWindowText(STR_MSG_SECONDCAMERA);
	GetDlgItem(IDC_CHECK_SAMENAME)->SetWindowText(STR_MSG_SAMENAME);

	GetDlgItem(IDC_EDIT_FIRSTSTEP1)->SetWindowText(m_szFirstStep01);
	GetDlgItem(IDC_EDIT_FIRSTSTEP2)->SetWindowText(m_szFirstStep02);
	GetDlgItem(IDC_EDIT_FIRSTSTEP3)->SetWindowText(m_szFirstStep03);
	GetDlgItem(IDC_EDIT_FIRSTSTEP4)->SetWindowText(m_szFirstStep04);
	GetDlgItem(IDC_EDIT_FIRSTSTEP5)->SetWindowText(m_szFirstStep05);
	GetDlgItem(IDC_EDIT_FIRSTSTEP6)->SetWindowText(m_szFirstStep06);

#ifdef DEF_SECONDCAMERA_CHECKSIZE
	GetDlgItem(IDC_EDIT_SECONDSTEP1)->SetWindowText(m_szFirstStep01);
#endif
	GetDlgItem(IDC_EDIT_SECONDSTEP2)->SetWindowText(m_szSecondStep02);
	GetDlgItem(IDC_EDIT_SECONDSTEP3)->SetWindowText(m_szSecondStep03);
	GetDlgItem(IDC_EDIT_SECONDSTEP4)->SetWindowText(m_szSecondStep04);
	GetDlgItem(IDC_EDIT_SECONDSTEP5)->SetWindowText(m_szSecondStep05);
	GetDlgItem(IDC_EDIT_SECONDSTEP6)->SetWindowText(m_szSecondStep06);

	if (m_szFirstStep02 == m_szSecondStep02 &&
		m_szFirstStep03 == m_szSecondStep03 &&
		m_szFirstStep04 == m_szSecondStep04 &&
		m_szFirstStep05 == m_szSecondStep05 &&
		m_szFirstStep06 == m_szSecondStep06)
	{
		((CButton*)GetDlgItem(IDC_CHECK_SAMENAME))->SetCheck(BST_CHECKED);

		((CEdit*)GetDlgItem(IDC_EDIT_SECONDSTEP2))->SetReadOnly(TRUE);
		((CEdit*)GetDlgItem(IDC_EDIT_SECONDSTEP3))->SetReadOnly(TRUE);
		((CEdit*)GetDlgItem(IDC_EDIT_SECONDSTEP4))->SetReadOnly(TRUE);
		((CEdit*)GetDlgItem(IDC_EDIT_SECONDSTEP5))->SetReadOnly(TRUE);
		((CEdit*)GetDlgItem(IDC_EDIT_SECONDSTEP6))->SetReadOnly(TRUE);
	}
	else
	{
		((CButton*)GetDlgItem(IDC_CHECK_SAMENAME))->SetCheck(BST_UNCHECKED);

		((CEdit*)GetDlgItem(IDC_EDIT_SECONDSTEP2))->SetReadOnly(FALSE);
		((CEdit*)GetDlgItem(IDC_EDIT_SECONDSTEP3))->SetReadOnly(FALSE);
		((CEdit*)GetDlgItem(IDC_EDIT_SECONDSTEP4))->SetReadOnly(FALSE);
		((CEdit*)GetDlgItem(IDC_EDIT_SECONDSTEP5))->SetReadOnly(FALSE);
		((CEdit*)GetDlgItem(IDC_EDIT_SECONDSTEP6))->SetReadOnly(FALSE);
	}

	((CButton*)GetDlgItem(IDC_CHECK_SAMENAME))->SetCheck(BST_CHECKED);
	GetDlgItem(IDC_CHECK_SAMENAME)->EnableWindow(FALSE);

	GetDlgItem(IDC_EDIT_SECONDSTEP2)->SetWindowText(m_szFirstStep02);
	GetDlgItem(IDC_EDIT_SECONDSTEP3)->SetWindowText(m_szFirstStep03);
	GetDlgItem(IDC_EDIT_SECONDSTEP4)->SetWindowText(m_szFirstStep04);
	GetDlgItem(IDC_EDIT_SECONDSTEP5)->SetWindowText(m_szFirstStep05);
	GetDlgItem(IDC_EDIT_SECONDSTEP6)->SetWindowText(m_szFirstStep06);

	return TRUE;
}

BEGIN_MESSAGE_MAP(CDlgStepName, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK_SAMENAME, &CDlgStepName::OnBnClickedCheckSamename)
	ON_BN_CLICKED(IDOK, &CDlgStepName::OnBnClickedOk)
	ON_EN_KILLFOCUS(IDC_EDIT_FIRSTSTEP2, &CDlgStepName::OnEnKillfocusEditFirststep2)
	ON_EN_KILLFOCUS(IDC_EDIT_FIRSTSTEP3, &CDlgStepName::OnEnKillfocusEditFirststep3)
	ON_EN_KILLFOCUS(IDC_EDIT_FIRSTSTEP4, &CDlgStepName::OnEnKillfocusEditFirststep4)
	ON_EN_KILLFOCUS(IDC_EDIT_FIRSTSTEP5, &CDlgStepName::OnEnKillfocusEditFirststep5)
	ON_EN_KILLFOCUS(IDC_EDIT_FIRSTSTEP6, &CDlgStepName::OnEnKillfocusEditFirststep6)
END_MESSAGE_MAP()


// CDlgStepName message handlers
void CDlgStepName::OnBnClickedCheckSamename()
{
	if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_SAMENAME))->GetCheck())
	{
		CString szValue;

		GetDlgItem(IDC_EDIT_FIRSTSTEP2)->GetWindowText(szValue);
		GetDlgItem(IDC_EDIT_SECONDSTEP2)->SetWindowText(szValue);
		
		GetDlgItem(IDC_EDIT_FIRSTSTEP3)->GetWindowText(szValue);
		GetDlgItem(IDC_EDIT_SECONDSTEP3)->SetWindowText(szValue);
		
		GetDlgItem(IDC_EDIT_FIRSTSTEP4)->GetWindowText(szValue);
		GetDlgItem(IDC_EDIT_SECONDSTEP4)->SetWindowText(szValue);
		
		GetDlgItem(IDC_EDIT_FIRSTSTEP5)->GetWindowText(szValue);
		GetDlgItem(IDC_EDIT_SECONDSTEP5)->SetWindowText(szValue);
		
		GetDlgItem(IDC_EDIT_FIRSTSTEP6)->GetWindowText(szValue);
		GetDlgItem(IDC_EDIT_SECONDSTEP6)->SetWindowText(szValue);


		((CEdit*)GetDlgItem(IDC_EDIT_SECONDSTEP2))->SetReadOnly(TRUE);
		((CEdit*)GetDlgItem(IDC_EDIT_SECONDSTEP3))->SetReadOnly(TRUE);
		((CEdit*)GetDlgItem(IDC_EDIT_SECONDSTEP4))->SetReadOnly(TRUE);
		((CEdit*)GetDlgItem(IDC_EDIT_SECONDSTEP5))->SetReadOnly(TRUE);
		((CEdit*)GetDlgItem(IDC_EDIT_SECONDSTEP6))->SetReadOnly(TRUE);
	}
	else
	{
		((CEdit*)GetDlgItem(IDC_EDIT_SECONDSTEP2))->SetReadOnly(FALSE);
		((CEdit*)GetDlgItem(IDC_EDIT_SECONDSTEP3))->SetReadOnly(FALSE);
		((CEdit*)GetDlgItem(IDC_EDIT_SECONDSTEP4))->SetReadOnly(FALSE);
		((CEdit*)GetDlgItem(IDC_EDIT_SECONDSTEP5))->SetReadOnly(FALSE);
		((CEdit*)GetDlgItem(IDC_EDIT_SECONDSTEP6))->SetReadOnly(FALSE);
	}
}

void CDlgStepName::OnBnClickedOk()
{
	GetDlgItem(IDC_EDIT_FIRSTSTEP1)->GetWindowText(m_szFirstStep01);
	GetDlgItem(IDC_EDIT_FIRSTSTEP2)->GetWindowText(m_szFirstStep02);
	GetDlgItem(IDC_EDIT_FIRSTSTEP3)->GetWindowText(m_szFirstStep03);
	GetDlgItem(IDC_EDIT_FIRSTSTEP4)->GetWindowText(m_szFirstStep04);
	GetDlgItem(IDC_EDIT_FIRSTSTEP5)->GetWindowText(m_szFirstStep05);
	GetDlgItem(IDC_EDIT_FIRSTSTEP6)->GetWindowText(m_szFirstStep06);

	GetDlgItem(IDC_EDIT_SECONDSTEP2)->GetWindowText(m_szSecondStep02);
	GetDlgItem(IDC_EDIT_SECONDSTEP3)->GetWindowText(m_szSecondStep03);
	GetDlgItem(IDC_EDIT_SECONDSTEP4)->GetWindowText(m_szSecondStep04);
	GetDlgItem(IDC_EDIT_SECONDSTEP5)->GetWindowText(m_szSecondStep05);
	GetDlgItem(IDC_EDIT_SECONDSTEP6)->GetWindowText(m_szSecondStep06);

	// First
	CString szMessage;
	int nLen = GetStringLength(&m_szFirstStep01);
	if (MAX_STEPNAME_LENGTH < nLen || 1 > nLen)
	{
		szMessage.Format(_T("%s (%s, Length:1~%d) )"), STR_MSG_CHAR_LENGTH, _T("STEP01"), MAX_STEPNAME_LENGTH);
		AfxMessageBox(szMessage);
		return;
	}
	nLen = GetStringLength(&m_szFirstStep02);
	if (MAX_STEPNAME_LENGTH < nLen || 1 > nLen)
	{
		szMessage.Format(_T("%s (%s, Length:1~%d) )"), STR_MSG_CHAR_LENGTH, _T("STEP02"), MAX_STEPNAME_LENGTH);
		AfxMessageBox(szMessage);
		return;
	}
	nLen = GetStringLength(&m_szFirstStep03);
	if (MAX_STEPNAME_LENGTH < nLen || 1 > nLen)
	{
		szMessage.Format(_T("%s (%s, Length:1~%d) )"), STR_MSG_CHAR_LENGTH, _T("STEP03"), MAX_STEPNAME_LENGTH);
		AfxMessageBox(szMessage);
		return;
	}
	nLen = GetStringLength(&m_szFirstStep04);
	if (MAX_STEPNAME_LENGTH < nLen || 1 > nLen)
	{
		szMessage.Format(_T("%s (%s, Length:1~%d) )"), STR_MSG_CHAR_LENGTH, _T("STEP04"), MAX_STEPNAME_LENGTH);
		AfxMessageBox(szMessage);
		return;
	}
	nLen = GetStringLength(&m_szFirstStep05);
	if (MAX_STEPNAME_LENGTH < nLen || 1 > nLen)
	{
		szMessage.Format(_T("%s (%s, Length:1~%d) )"), STR_MSG_CHAR_LENGTH, _T("STEP05"), MAX_STEPNAME_LENGTH);
		AfxMessageBox(szMessage);
		return;
	}
	nLen = GetStringLength(&m_szFirstStep06);
	if (MAX_STEPNAME_LENGTH < nLen || 1 > nLen)
	{
		szMessage.Format(_T("%s (%s, Length:1~%d) )"), STR_MSG_CHAR_LENGTH, _T("STEP06"), MAX_STEPNAME_LENGTH);
		AfxMessageBox(szMessage);
		return;
	}

	// Second
	nLen = GetStringLength(&m_szSecondStep02);
	if (MAX_STEPNAME_LENGTH < nLen || 1 > nLen)
	{
		szMessage.Format(_T("%s (%s, Length:1~%d) )"), STR_MSG_CHAR_LENGTH, _T("STEP02"), MAX_STEPNAME_LENGTH);
		AfxMessageBox(szMessage);
		return;
	}
	nLen = GetStringLength(&m_szSecondStep03);
	if (MAX_STEPNAME_LENGTH < nLen || 1 > nLen)
	{
		szMessage.Format(_T("%s (%s, Length:1~%d) )"), STR_MSG_CHAR_LENGTH, _T("STEP03"), MAX_STEPNAME_LENGTH);
		AfxMessageBox(szMessage);
		return;
	}
	nLen = GetStringLength(&m_szSecondStep04);
	if (MAX_STEPNAME_LENGTH < nLen || 1 > nLen)
	{
		szMessage.Format(_T("%s (%s, Length:1~%d)"), STR_MSG_CHAR_LENGTH, _T("STEP04"), MAX_STEPNAME_LENGTH);
		AfxMessageBox(szMessage);
		return;
	}
	nLen = GetStringLength(&m_szSecondStep05);
	if (MAX_STEPNAME_LENGTH < nLen || 1 > nLen)
	{
		szMessage.Format(_T("%s (%s, Length:1~%d)"), STR_MSG_CHAR_LENGTH, _T("STEP05"), MAX_STEPNAME_LENGTH);
		AfxMessageBox(szMessage);
		return;
	}
	nLen = GetStringLength(&m_szSecondStep06);
	if (MAX_STEPNAME_LENGTH < nLen || 1 > nLen)
	{
		szMessage.Format(_T("%s (%s, Length:1~%d)"), STR_MSG_CHAR_LENGTH, _T("STEP06"), MAX_STEPNAME_LENGTH);
		AfxMessageBox(szMessage);
		return;
	}

	CDialogEx::OnOK();
}


void CDlgStepName::OnEnKillfocusEditFirststep2()
{
	if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_SAMENAME))->GetCheck())
	{
		CString szValue;
		GetDlgItem(IDC_EDIT_FIRSTSTEP2)->GetWindowText(szValue);
		GetDlgItem(IDC_EDIT_SECONDSTEP2)->SetWindowText(szValue);
	}
}

void CDlgStepName::OnEnKillfocusEditFirststep3()
{
	if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_SAMENAME))->GetCheck())
	{
		CString szValue;
		GetDlgItem(IDC_EDIT_FIRSTSTEP3)->GetWindowText(szValue);
		GetDlgItem(IDC_EDIT_SECONDSTEP3)->SetWindowText(szValue);
	}
}
void CDlgStepName::OnEnKillfocusEditFirststep4()
{
	if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_SAMENAME))->GetCheck())
	{
		CString szValue;
		GetDlgItem(IDC_EDIT_FIRSTSTEP4)->GetWindowText(szValue);
		GetDlgItem(IDC_EDIT_SECONDSTEP4)->SetWindowText(szValue);
	}
}
void CDlgStepName::OnEnKillfocusEditFirststep5()
{
	if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_SAMENAME))->GetCheck())
	{
		CString szValue;
		GetDlgItem(IDC_EDIT_FIRSTSTEP5)->GetWindowText(szValue);
		GetDlgItem(IDC_EDIT_SECONDSTEP5)->SetWindowText(szValue);
	}
}
void CDlgStepName::OnEnKillfocusEditFirststep6()
{
	if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_SAMENAME))->GetCheck())
	{
		CString szValue;
		GetDlgItem(IDC_EDIT_FIRSTSTEP6)->GetWindowText(szValue);
		GetDlgItem(IDC_EDIT_SECONDSTEP6)->SetWindowText(szValue);
	}
}


BOOL CDlgStepName::SetStepNames(INFO_OPTION* pstOption)
{
	if (NULL == pstOption)
		return FALSE;

	m_szFirstStep01 = pstOption->m_stFirstCameraStep.m_szTitleStep01;
	m_szFirstStep02 = pstOption->m_stFirstCameraStep.m_szTitleStep02;
	m_szFirstStep03 = pstOption->m_stFirstCameraStep.m_szTitleStep03;
	m_szFirstStep04 = pstOption->m_stFirstCameraStep.m_szTitleStep04;
	m_szFirstStep05 = pstOption->m_stFirstCameraStep.m_szTitleStep05;
	m_szFirstStep06 = pstOption->m_stFirstCameraStep.m_szTitleStep06;

	m_szSecondStep02 = pstOption->m_stSecondCameraStep.m_szTitleStep02;
	m_szSecondStep03 = pstOption->m_stSecondCameraStep.m_szTitleStep03;
	m_szSecondStep04 = pstOption->m_stSecondCameraStep.m_szTitleStep04;
	m_szSecondStep05 = pstOption->m_stSecondCameraStep.m_szTitleStep05;
	m_szSecondStep06 = pstOption->m_stSecondCameraStep.m_szTitleStep06;

	return TRUE;
}


int CDlgStepName::GetStringLength(CString* pString)
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