// DlgPasswd.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "DlgPasswd.h"
#include "afxdialogex.h"


// CDlgPasswd dialog

IMPLEMENT_DYNAMIC(CDlgPasswd, CDialogEx)

CDlgPasswd::CDlgPasswd(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgPasswd::IDD, pParent)
{

}

CDlgPasswd::~CDlgPasswd()
{
}

void CDlgPasswd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgPasswd, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgPasswd::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgPasswd message handlers


void CDlgPasswd::OnBnClickedOk()
{
	GetDlgItem(IDC_EDIT_PASSWD)->GetWindowText(m_szPasswd);
	
	if (_T("1111") != m_szPasswd)
	{
		AfxMessageBox(_T("패스워드가 일치하지 않습니다."));
		SetDlgItemTextA(IDC_EDIT_PASSWD, _T(""));
		return;
	}
	CDialogEx::OnOK();
}
