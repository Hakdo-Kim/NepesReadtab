// DlgStrobe.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "DlgStrobe.h"
#include "afxdialogex.h"

#include "CaptureManager.h"
#include "stringres.h"

#include "Util/Util.h"

// CDlgStrobe dialog

IMPLEMENT_DYNAMIC(CDlgStrobe, CDialogEx)

CDlgStrobe::CDlgStrobe(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgStrobe::IDD, pParent)
{

}

CDlgStrobe::~CDlgStrobe()
{
}

void CDlgStrobe::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_STROBE1, m_ctlStrobe01);
	DDX_Control(pDX, IDC_COMBO_STROBE2, m_ctlStrobe02);
}

BOOL CDlgStrobe::OnCommand(WPARAM wParam, LPARAM lParam)
{
	return CDialogEx::OnCommand(wParam, lParam);
}

BOOL CDlgStrobe::PreTranslateMessage(MSG* pMsg)
{
	if (WM_KEYDOWN == pMsg->message)
	{
		if (VK_RETURN == pMsg->wParam)
		{
			const HWND hWnd = GetFocus()->m_hWnd;
			if (hWnd == GetDlgItem(IDC_EDIT_BRIGHTNESS1)->m_hWnd)
			{
				OnEnKillfocusEditBrightness1();
				return TRUE;
			}
			else if (hWnd == GetDlgItem(IDC_EDIT_BRIGHTNESS2)->m_hWnd)
			{
				OnEnKillfocusEditBrightness2();
				return TRUE;
			}
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

BOOL CDlgStrobe::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_ctlStrobe01.AddString(STR_STROBE_OFF);
	m_ctlStrobe01.AddString(STR_STROBE_COAXIAL);
	m_ctlStrobe01.AddString(STR_STROBE_RING);
	m_ctlStrobe01.AddString(STR_STROBE_BAR);
	m_ctlStrobe01.SetCurSel(0);

	m_ctlStrobe02.AddString(STR_STROBE_OFF);
	m_ctlStrobe02.AddString(STR_STROBE_COAXIAL);
	m_ctlStrobe02.AddString(STR_STROBE_RING);
	m_ctlStrobe02.AddString(STR_STROBE_BAR);
	m_ctlStrobe02.SetCurSel(0);


	if (TYPE_STROBE_OFF == m_pstStepStrobe[0].m_eStrobeType ||
		TYPE_STROBE_COXIAL == m_pstStepStrobe[0].m_eStrobeType ||
		TYPE_STROBE_RING == m_pstStepStrobe[0].m_eStrobeType ||
		TYPE_STROBE_BAR == m_pstStepStrobe[0].m_eStrobeType)
	{
		m_ctlStrobe01.SetCurSel((int)m_pstStepStrobe[0].m_eStrobeType - 1);
	}
	SetEditValue(IDC_EDIT_BRIGHTNESS1, m_pstStepStrobe[0].m_nStrobeBrightness);


	if (TYPE_STROBE_OFF == m_pstStepStrobe[1].m_eStrobeType ||
		TYPE_STROBE_COXIAL == m_pstStepStrobe[1].m_eStrobeType ||
		TYPE_STROBE_RING == m_pstStepStrobe[1].m_eStrobeType ||
		TYPE_STROBE_BAR == m_pstStepStrobe[1].m_eStrobeType)
	{
		m_ctlStrobe02.SetCurSel((int)m_pstStepStrobe[1].m_eStrobeType - 1);
	}
	SetEditValue(IDC_EDIT_BRIGHTNESS2, m_pstStepStrobe[1].m_nStrobeBrightness);

	return TRUE;
}



BEGIN_MESSAGE_MAP(CDlgStrobe, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_STROBE1, &CDlgStrobe::OnCbnSelchangeComboStrobe1)
	ON_CBN_SELCHANGE(IDC_COMBO_STROBE2, &CDlgStrobe::OnCbnSelchangeComboStrobe2)
	ON_EN_KILLFOCUS(IDC_EDIT_BRIGHTNESS1, &CDlgStrobe::OnEnKillfocusEditBrightness1)
	ON_EN_KILLFOCUS(IDC_EDIT_BRIGHTNESS2, &CDlgStrobe::OnEnKillfocusEditBrightness2)
	ON_BN_CLICKED(IDOK, &CDlgStrobe::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgStrobe message handlers


void CDlgStrobe::OnCbnSelchangeComboStrobe1()
{
	UpdateCtrlStrobe(&m_ctlStrobe01, IDC_EDIT_BRIGHTNESS1);
}

void CDlgStrobe::OnCbnSelchangeComboStrobe2()
{
	UpdateCtrlStrobe(&m_ctlStrobe02, IDC_EDIT_BRIGHTNESS2);
}


void CDlgStrobe::OnEnKillfocusEditBrightness1()
{
	static BOOL bSkipMsg = FALSE;
	if (bSkipMsg)
		return;
	bSkipMsg = TRUE;

	UpdateCtrlStrobe(&m_ctlStrobe01, IDC_EDIT_BRIGHTNESS1);

	bSkipMsg = FALSE;
}

void CDlgStrobe::OnEnKillfocusEditBrightness2()
{
	static BOOL bSkipMsg = FALSE;
	if (bSkipMsg)
		return;
	bSkipMsg = TRUE;

	UpdateCtrlStrobe(&m_ctlStrobe02, IDC_EDIT_BRIGHTNESS2);

	bSkipMsg = FALSE;
}

void CDlgStrobe::OnBnClickedOk()
{
	m_pstStepStrobe[0].m_eStrobeType = GetStrobeTypeFromControl(&m_ctlStrobe01);
	m_pstStepStrobe[0].m_nStrobeBrightness = GetEditValue(IDC_EDIT_BRIGHTNESS1);

	m_pstStepStrobe[1].m_eStrobeType = GetStrobeTypeFromControl(&m_ctlStrobe02);
	m_pstStepStrobe[1].m_nStrobeBrightness = GetEditValue(IDC_EDIT_BRIGHTNESS2);

	CDialogEx::OnOK();
}

void CDlgStrobe::UpdateCtrlStrobe(CComboBox* pCtlCombo, const DWORD dwCtrlID)
{
	const TYPE_STROBE eStrobe = GetStrobeTypeFromControl(pCtlCombo);
	if (TYPE_STROBE_COXIAL == eStrobe || TYPE_STROBE_RING == eStrobe || TYPE_STROBE_BAR == eStrobe)
	{
		GetDlgItem(dwCtrlID)->EnableWindow(TRUE);

		const int nValue = GetEditValue(dwCtrlID);
		BOOL bEnable = IsEnableBrightnessValue(eStrobe, nValue);
		if (FALSE == bEnable)
		{
			AfxMessageBox(STR_MSG_MATCH_BRIGHTNESS);

			if (TYPE_STROBE_COXIAL == eStrobe)
				SetEditValue(dwCtrlID, STROBE_MAX_BRIGHT_COAX);
			else if (TYPE_STROBE_RING == eStrobe)
				SetEditValue(dwCtrlID, STROBE_MAX_BRIGHT_RING);
			else if (TYPE_STROBE_BAR == eStrobe)
				SetEditValue(dwCtrlID, STROBE_MAX_BRIGHT_BAR);
		}
	}
	else
	{
		GetDlgItem(dwCtrlID)->EnableWindow(FALSE);
	}
}

TYPE_STROBE CDlgStrobe::GetStrobeTypeFromControl(CComboBox* pCtlCombo)
{
	if (NULL == pCtlCombo)
		return TYPE_STROBE_NONE;

	TYPE_STROBE eStrobe = (TYPE_STROBE)(pCtlCombo->GetCurSel() + 1);
	return eStrobe;;
}

BOOL CDlgStrobe::IsEnableBrightnessValue(TYPE_STROBE eStrobe, int nValue)
{
	BOOL bEnable = FALSE;
	if (TYPE_STROBE_COXIAL == eStrobe)
	{
		if (STROBE_MAX_BRIGHT_COAX >= nValue && STROBE_MIN_BRIGHT_COAX <= nValue)
			bEnable = TRUE;
	}
	else if (TYPE_STROBE_RING == eStrobe)
	{
		if (STROBE_MAX_BRIGHT_RING >= nValue && STROBE_MIN_BRIGHT_RING <= nValue)
			bEnable = TRUE;
	}
	else if (TYPE_STROBE_BAR == eStrobe)
	{
		if (STROBE_MAX_BRIGHT_BAR >= nValue && STROBE_MIN_BRIGHT_BAR <= nValue)
			bEnable = TRUE;
	}

	return bEnable;
}

int CDlgStrobe::GetEditValue(const DWORD dwCtrlID)
{
	CString szValue;
	GetDlgItem(dwCtrlID)->GetWindowText(szValue);

	int nValue = CUtil::StringToInt((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	return nValue;
}

void CDlgStrobe::SetEditValue(const DWORD dwCtrlID, int nValue)
{
	CString szValue;
	szValue.Format(_T("%d"), nValue);
	GetDlgItem(dwCtrlID)->SetWindowText(szValue);
}


