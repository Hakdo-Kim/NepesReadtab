// DlgLotIDOnce.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "DlgLotIDOnce.h"
#include "afxdialogex.h"


// CDlgLotIDOnce dialog

IMPLEMENT_DYNAMIC(CDlgLotIDOnce, CDialogEx)

CDlgLotIDOnce::CDlgLotIDOnce(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgLotIDOnce::IDD, pParent)
{

}

CDlgLotIDOnce::~CDlgLotIDOnce()
{
}

void CDlgLotIDOnce::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BOOL CDlgLotIDOnce::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	GetDlgItem(IDC_EDIT_LOTID_A)->SetWindowText(m_szLotID_A);
	GetDlgItem(IDC_EDIT_LOTID_B)->SetWindowText(m_szLotID_B);

	const int nLenA = m_szLotID_A.GetLength();
	const int nLenB = m_szLotID_B.GetLength();

	if (nLenA == nLenB)
	{
		CString szSameLot;
		for (int i = 0; i < nLenA; i++)
		{
			if (m_szLotID_A[i] == m_szLotID_B[i])
			{
				szSameLot += m_szLotID_A[i];
			}
		}
		GetDlgItem(IDC_EDIT_LOTID)->SetWindowText(szSameLot);
	}


	GetDlgItem(IDC_EDIT_LOTID)->SetFocus();
	((CEdit*)GetDlgItem(IDC_EDIT_LOTID))->SetSel(0, -1, TRUE);

	GotoDlgCtrl(GetDlgItem(IDC_EDIT_LOTID));

	return FALSE;
}


BEGIN_MESSAGE_MAP(CDlgLotIDOnce, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgLotIDOnce::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT_LOTID, &CDlgLotIDOnce::OnEnChangeEditLotid)
END_MESSAGE_MAP()


// CDlgLotIDOnce message handlers


void CDlgLotIDOnce::OnBnClickedOk()
{
	GetDlgItemText(IDC_EDIT_LOTID_A, m_szLotID_A);
	GetDlgItemText(IDC_EDIT_LOTID_B, m_szLotID_B);

	CDialogEx::OnOK();
}


void CDlgLotIDOnce::OnEnChangeEditLotid()
{
	CString szTxt;
	GetDlgItemText(IDC_EDIT_LOTID, szTxt);

	m_szLotID_A = szTxt + _T("a");
	m_szLotID_B = szTxt + _T("b");

	SetDlgItemText(IDC_EDIT_LOTID_A, m_szLotID_A);
	SetDlgItemText(IDC_EDIT_LOTID_B, m_szLotID_B);

}
