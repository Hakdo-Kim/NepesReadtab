// DlgStrobeBrightness.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "DlgStrobeBrightness.h"
#include "afxdialogex.h"

#include "CaptureManager.h"
#include "stringres.h"
#include "Util/Util.h"


// CDlgStrobeBrightness dialog

IMPLEMENT_DYNAMIC(CDlgStrobeBrightness, CDialogEx)

CDlgStrobeBrightness::CDlgStrobeBrightness(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgStrobeBrightness::IDD, pParent)
{
	m_eCameraPos = TYPE_CAMERAPOS_NONE;
	m_eStrobe = TYPE_STROBE_NONE;
	m_nBrightness = 0;
}

CDlgStrobeBrightness::~CDlgStrobeBrightness()
{
}

void CDlgStrobeBrightness::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BOOL CDlgStrobeBrightness::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (IDOK == wParam)
	{
		//return TRUE;
	}
	return CDialogEx::OnCommand(wParam, lParam);
}

BOOL CDlgStrobeBrightness::PreTranslateMessage(MSG* pMsg)
{
	if (WM_KEYDOWN == pMsg->message)
	{
		if (VK_ESCAPE == pMsg->wParam)
		{
			//return TRUE;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

BOOL CDlgStrobeBrightness::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CString szTxt = _T("BRIGHTNESS");

	if (TYPE_STROBE_COXIAL == m_eStrobe)
	{
		if (TYPE_CAMERAPOS_FIRST == m_eCameraPos)
			szTxt.Format(_T("%s - %s"), STR_MSG_FIRSTCAMERA, STR_STROBE_COAXIAL);
		else if (TYPE_CAMERAPOS_SECOND == m_eCameraPos)
			szTxt.Format(_T("%s - %s"), STR_MSG_SECONDCAMERA, STR_STROBE_COAXIAL);
	}
	else if (TYPE_STROBE_RING == m_eStrobe)
	{
		if (TYPE_CAMERAPOS_FIRST == m_eCameraPos)
			szTxt.Format(_T("%s - %s"), STR_MSG_FIRSTCAMERA, STR_STROBE_RING);
		else if (TYPE_CAMERAPOS_SECOND == m_eCameraPos)
			szTxt.Format(_T("%s - %s"), STR_MSG_SECONDCAMERA, STR_STROBE_RING);
	}
	else if (TYPE_STROBE_BAR == m_eStrobe)
	{
		if (TYPE_CAMERAPOS_FIRST == m_eCameraPos)
			szTxt.Format(_T("%s - %s"), STR_MSG_FIRSTCAMERA, STR_STROBE_BAR);
		else if (TYPE_CAMERAPOS_SECOND == m_eCameraPos)
			szTxt.Format(_T("%s - %s"), STR_MSG_SECONDCAMERA, STR_STROBE_BAR);
	}
	this->SetWindowText(szTxt);


	GetDlgItem(IDC_STATIC_BRIGHTNESS)->SetWindowText(STR_MSG_CHANGE_BRIGHTNESS);


	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_STROBE* pstStrobe = pCaptureManager->GetCurrentStrobeInfo();

	if (TYPE_CAMERAPOS_FIRST == m_eCameraPos)
	{
		if (TYPE_STROBE_COXIAL == m_eStrobe)
			m_nBrightness = pstStrobe->m_stFirstStrobe.m_nBrightnessCoxial;
		else if (TYPE_STROBE_RING == m_eStrobe)
			m_nBrightness = pstStrobe->m_stFirstStrobe.m_nBrightnessRing;
		else if (TYPE_STROBE_BAR == m_eStrobe)
			m_nBrightness = pstStrobe->m_stFirstStrobe.m_nBrightnessBar;
	}
	else if (TYPE_CAMERAPOS_SECOND == m_eCameraPos)
	{
		if (TYPE_STROBE_COXIAL == m_eStrobe)
			m_nBrightness = pstStrobe->m_stSecondStrobe.m_nBrightnessCoxial;
		else if (TYPE_STROBE_RING == m_eStrobe)
			m_nBrightness = pstStrobe->m_stSecondStrobe.m_nBrightnessRing;
		else if (TYPE_STROBE_BAR == m_eStrobe)
			m_nBrightness = pstStrobe->m_stSecondStrobe.m_nBrightnessBar;
	}

	CString szBrightness;
	szBrightness.Format(_T("%d"), m_nBrightness);
	GetDlgItem(IDC_EDIT_BRIGHTNESS)->SetWindowText(szBrightness);

	return TRUE;
}

BEGIN_MESSAGE_MAP(CDlgStrobeBrightness, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgStrobeBrightness::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgStrobeBrightness message handlers


void CDlgStrobeBrightness::OnBnClickedOk()
{
	CString szBrightness;
	GetDlgItem(IDC_EDIT_BRIGHTNESS)->GetWindowText(szBrightness);

	m_nBrightness = CUtil::StringToInt((LPTSTR)(LPCTSTR)szBrightness, szBrightness.GetLength());

	CString szMsg;
	if (TYPE_STROBE_COXIAL == m_eStrobe)
	{
		if (0 > STROBE_MIN_BRIGHT_COAX || STROBE_MAX_BRIGHT_COAX < m_nBrightness)
		{
			szMsg.Format(_T("%s (%d ~ %d)"), STR_MSG_EVALUE_BRIGHTNESS, STROBE_MIN_BRIGHT_COAX, STROBE_MAX_BRIGHT_COAX);
			AfxMessageBox(szMsg);
			return;
		}
	}
	else if (TYPE_STROBE_RING == m_eStrobe)
	{
		if (0 > STROBE_MIN_BRIGHT_RING || STROBE_MAX_BRIGHT_RING < m_nBrightness)
		{
			szMsg.Format(_T("%s (%d ~ %d)"), STR_MSG_EVALUE_BRIGHTNESS, STROBE_MIN_BRIGHT_RING, STROBE_MAX_BRIGHT_RING);
			AfxMessageBox(szMsg);
			return;
		}
	}
	else if (TYPE_STROBE_BAR == m_eStrobe)
	{
		if (0 > STROBE_MIN_BRIGHT_BAR || STROBE_MAX_BRIGHT_BAR < m_nBrightness)
		{
			szMsg.Format(_T("%s (%d ~ %d)"), STR_MSG_EVALUE_BRIGHTNESS, STROBE_MIN_BRIGHT_BAR, STROBE_MAX_BRIGHT_BAR);
			AfxMessageBox(szMsg);
			return;
		}
	}
	
	CDialogEx::OnOK();
}
