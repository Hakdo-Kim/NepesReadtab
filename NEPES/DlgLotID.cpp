// DlgLotID.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "DlgLotID.h"
#include "afxdialogex.h"

#include "CaptureManager.h"
#include "Util/Util.h"
#include "stringres.h"

// CDlgLotID dialog

IMPLEMENT_DYNAMIC(CDlgLotID, CDialogEx)

CDlgLotID::CDlgLotID(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgLotID::IDD, pParent)
{
}

CDlgLotID::~CDlgLotID()
{
}

void CDlgLotID::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL CDlgLotID::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	GetDlgItem(IDC_EDIT_LOTID)->SetWindowText(m_szLotID);
	GetDlgItem(IDC_EDIT_LOTID)->SetFocus();
	((CEdit*)GetDlgItem(IDC_EDIT_LOTID))->SetSel(0, -1, TRUE);

	GotoDlgCtrl(GetDlgItem(IDC_EDIT_LOTID));

	return FALSE;
}

BEGIN_MESSAGE_MAP(CDlgLotID, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgLotID::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgLotID message handlers

void CDlgLotID::OnBnClickedOk()
{
	GetDlgItem(IDC_EDIT_LOTID)->GetWindowText(m_szLotID);
	m_szLotID.Trim();

	if (1 > m_szLotID.GetLength())
	{
		AfxMessageBox(STR_MSG_FAIL_INPUT_LOTID);
		return;
	}
	if (64 < m_szLotID.GetLength())
	{
		AfxMessageBox(STR_MSG_FAIL_LOTID_LENGTH64);
		return;
	}

	m_szLotID.MakeUpper();

	CDialogEx::OnOK();
}
