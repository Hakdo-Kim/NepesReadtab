// TapCameraCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "TapCameraCtrl.h"
#include "afxdialogex.h"

#include "UserInterfaceDef.h"
#include "CaptureManager.h"
#include "Util/Util.h"

#include "stringres.h"

// CTapCameraCtrl dialog

IMPLEMENT_DYNAMIC(CTapCameraCtrl, CDialogEx)

CTapCameraCtrl::CTapCameraCtrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTapCameraCtrl::IDD, pParent)
{
	SCROLLHEIGHT = -1;
}

CTapCameraCtrl::~CTapCameraCtrl()
{
}

void CTapCameraCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_OPT_CAM_GAIN1, m_ctlStaticDigitalGain);
	DDX_Control(pDX, IDC_OPT_CAM_GAIN2, m_ctlStaticAnalogGain);
	DDX_Control(pDX, IDC_OPT_CAM_EXPOSURE, m_ctlStaticExposure);
	DDX_Control(pDX, IDC_OPT_CAM_FPS, m_ctlFramerate);
	DDX_Control(pDX, IDC_OPT_CAM_SYMMETRY, m_ctlSymmetry);
	DDX_Control(pDX, IDC_OPT_CAM_ROI, m_ctlStaticRoi);
	DDX_Control(pDX, IDC_OPT_CAM_TRIGGER, m_ctlStaticTrigger);
	DDX_Control(pDX, IDC_OPT_CAM_STROBE, m_ctlStrobe);
	DDX_Control(pDX, IDC_OPT_CAM_MTU, m_ctlStaticMtu);
	DDX_Control(pDX, IDC_OPT_CAM_USERSET, m_ctlStaticUserset);
	DDX_Control(pDX, IDC_COMBO_TRIGGER_SOURCE, m_ctlTriggerSource);
	DDX_Control(pDX, IDC_COMBO_TRIGGER_TYPE, m_ctlTriggerType);
	DDX_Control(pDX, IDC_COMBO_STROBE_SYNC, m_ctlStrobeSync);
	DDX_Control(pDX, IDC_COMBO_STROBE_POLARITY, m_ctlStrobePolarity);
	DDX_Control(pDX, IDC_COMBO_USERSET, m_ctlUserset);
	DDX_Control(pDX, IDC_SLIDER_CAMGAIN1, m_ctlSliderGain1);
	DDX_Control(pDX, IDC_SPIN_CAMGAIN1, m_ctlSpinGain1);
	DDX_Control(pDX, IDC_SLIDER_CAMGAIN2, m_ctlSliderGain2);
	DDX_Control(pDX, IDC_SPIN_CAMGAIN2, m_ctlSpinGain2);
	DDX_Control(pDX, IDC_SLIDER_CAMEXPOSURE, m_ctlSliderExposure);
	DDX_Control(pDX, IDC_SPIN_CAMEXPOSURE, m_ctlSpinExposure);
	DDX_Control(pDX, IDC_SLIDER_CAMFPS, m_ctlSliderFps);
	DDX_Control(pDX, IDC_SPIN_CAMFPS, m_ctlSpinFps);
	DDX_Control(pDX, IDC_SPIN_TRIGGER_DELAY, m_ctlSpinTriggerDelay);
	DDX_Control(pDX, IDC_SPIN_STROBE_DELAY, m_ctlSpinStrobeDelay);
	DDX_Control(pDX, IDC_SPIN_STROBE_WIDTH, m_ctlSpinStrobeWidth);
	DDX_Control(pDX, IDC_COMBO_TRIGGER_POLARITY, m_ctlTriggerPolarity);
	DDX_Control(pDX, IDC_COMBO_STARTUPUSERSET, m_ctlStartupUserset);
	DDX_Control(pDX, IDC_COMBO_MTU, m_ctlMtu);
	DDX_Control(pDX, IDC_STATIC_ROIINFO, m_ctlStaticRoiInfo);
}

BOOL CTapCameraCtrl::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (IDOK == wParam)
	{
		return TRUE;
	}
	return CDialogEx::OnCommand(wParam, lParam);
}

BOOL CTapCameraCtrl::PreTranslateMessage(MSG* pMsg)
{
	if (WM_KEYDOWN == pMsg->message)
	{
		if (VK_ESCAPE == pMsg->wParam)
		{
			return TRUE;
		}
		else if (VK_RETURN == pMsg->wParam)
		{
			const HWND hWnd = GetFocus()->m_hWnd;
			if (hWnd == GetDlgItem(IDC_EDIT_CAMGAIN1)->m_hWnd)
				OnEnKillfocusEditCamgain1();
			else if (hWnd == GetDlgItem(IDC_EDIT_CAMGAIN2)->m_hWnd)
				OnEnKillfocusEditCamgain2();
			else if (hWnd == GetDlgItem(IDC_EDIT_CAMEXPOSURE)->m_hWnd)
				OnEnKillfocusEditCamexposure();
			else if (hWnd == GetDlgItem(IDC_EDIT_CAMFPS)->m_hWnd)
				OnEnKillfocusEditCamfps();
			else if (hWnd == GetDlgItem(IDC_EDIT_TRIGGER_DELAY)->m_hWnd)
				OnEnKillfocusEditTriggerDelay();
			else if (hWnd == GetDlgItem(IDC_EDIT_STROBE_DELAY)->m_hWnd)
				OnEnKillfocusEditStrobeDelay();
			else if (hWnd == GetDlgItem(IDC_EDIT_STROBE_WIDTH)->m_hWnd)
				OnEnKillfocusEditStrobeWidth();
			else if (hWnd == GetDlgItem(IDC_EDIT_ROI_X)->m_hWnd)
				OnEnKillfocusEditRoiX();
			else if (hWnd == GetDlgItem(IDC_EDIT_ROI_Y)->m_hWnd)
				OnEnKillfocusEditRoiY();
			else if (hWnd == GetDlgItem(IDC_EDIT_ROI_WIDTH)->m_hWnd)
				OnEnKillfocusEditRoiWidth();
			else if (hWnd == GetDlgItem(IDC_EDIT_ROI_HEIGHT)->m_hWnd)
				OnEnKillfocusEditRoiHeight();
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

BOOL CTapCameraCtrl::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Gain 1
	m_ctlStaticDigitalGain.SetText(_T("DIGITAL GAIN"));
	UpdateValue(IDC_EDIT_CAMGAIN1, 0);

	// Gain 2
	m_ctlStaticAnalogGain.SetText(_T("ANALOG GAIN"));
	UpdateValue(IDC_EDIT_CAMGAIN2, 0);

	// Exposure
	m_ctlStaticExposure.SetText(_T("EXPOSURE"));
	UpdateValue(IDC_EDIT_CAMEXPOSURE, 0);

	// Framerate
	m_ctlFramerate.SetText(_T("FRAME RATE"));
	UpdateValue(IDC_EDIT_CAMFPS, 0);

	// Symmetry
	m_ctlSymmetry.SetText(_T("SYMMETRY"));

	// Roi
	m_ctlStaticRoi.SetText(_T("ROI"));

	m_dlgRoi.Create(CDlgCamRoi::IDD, this);
	{
		RECT rect;
		memset(&rect, 0x00, sizeof(RECT));
		GetDlgItem(IDC_STATIC_ROIDISPLAY)->GetWindowRect(&rect);
		this->ScreenToClient(&rect);

		int x = rect.left;
		int y = rect.top;
		int cx = rect.right - rect.left;
		int cy = rect.bottom - rect.top;

		m_dlgRoi.SetWindowPos(NULL, x, y, cx, cy, SWP_NOACTIVATE | SWP_NOZORDER);
		m_dlgRoi.ShowWindow(SW_SHOW);
	}

	UpdateValue(IDC_EDIT_ROI_X, 0);
	UpdateValue(IDC_EDIT_ROI_Y, 0);
	UpdateValue(IDC_EDIT_ROI_WIDTH, 640);
	UpdateValue(IDC_EDIT_ROI_HEIGHT, 480);
	
	// Trigger
	m_ctlStaticTrigger.SetText(_T("TRIGGER"));
	UpdateValue(IDC_EDIT_TRIGGER_DELAY, 0);

	m_ctlTriggerSource.ResetContent();
	m_ctlTriggerSource.AddString(_T("LINE"));
	m_ctlTriggerSource.AddString(_T("SW TRIGGER"));

	m_ctlTriggerType.ResetContent();
	m_ctlTriggerType.AddString(_T("EDGE"));
	m_ctlTriggerType.AddString(_T("LEVEL"));

	m_ctlTriggerPolarity.ResetContent();
	m_ctlTriggerPolarity.AddString(_T("NEGATIVE"));
	m_ctlTriggerPolarity.AddString(_T("POSITIVE"));

	m_ctlTriggerSource.SetCurSel(0);
	m_ctlTriggerType.SetCurSel(0);
	m_ctlTriggerPolarity.SetCurSel(0);

	// Strobe
	m_ctlStrobe.SetText(_T("STROBE"));
	UpdateValue(IDC_EDIT_STROBE_DELAY, 0);
	UpdateValue(IDC_EDIT_STROBE_WIDTH, 0);

	m_ctlStrobeSync.ResetContent();
	m_ctlStrobeSync.AddString(_T("EXPOSURE"));
	m_ctlStrobeSync.AddString(_T("BYPASS"));
	m_ctlStrobeSync.SetCurSel(0);

	m_ctlStrobePolarity.ResetContent();
	m_ctlStrobePolarity.AddString(_T("NEGATIVE"));
	m_ctlStrobePolarity.AddString(_T("POSITIVE"));
	m_ctlStrobePolarity.SetCurSel(0);

	// MTU
	m_ctlStaticMtu.SetText(_T("MTU"));

	// USERSET
	m_ctlStaticUserset.SetText(_T("USERSET"));

	m_ctlUserset.ResetContent();
	m_ctlUserset.AddString(_T("DEFAULT"));
	m_ctlUserset.SetCurSel(0);
	GetDlgItem(IDC_BTN_USERSET_SAVE)->EnableWindow(FALSE);

	m_ctlStartupUserset.ResetContent();
	m_ctlStartupUserset.AddString(_T("DEFAULT"));
	m_ctlStartupUserset.SetCurSel(0);


	UpdateInformation(NULL);

	return TRUE;
}


BEGIN_MESSAGE_MAP(CTapCameraCtrl, CDialogEx)
	ON_MESSAGE(WM_NOTIFY_TRACK_CHANGE_RECT, &CTapCameraCtrl::OnNotifyChangeTrackRect)

	ON_WM_SIZE()
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()

	ON_EN_KILLFOCUS(IDC_EDIT_CAMGAIN1, &CTapCameraCtrl::OnEnKillfocusEditCamgain1)
	ON_EN_KILLFOCUS(IDC_EDIT_CAMGAIN2, &CTapCameraCtrl::OnEnKillfocusEditCamgain2)
	ON_EN_KILLFOCUS(IDC_EDIT_CAMEXPOSURE, &CTapCameraCtrl::OnEnKillfocusEditCamexposure)
	ON_EN_KILLFOCUS(IDC_EDIT_CAMFPS, &CTapCameraCtrl::OnEnKillfocusEditCamfps)
	ON_EN_KILLFOCUS(IDC_EDIT_TRIGGER_DELAY, &CTapCameraCtrl::OnEnKillfocusEditTriggerDelay)
	ON_EN_KILLFOCUS(IDC_EDIT_STROBE_DELAY, &CTapCameraCtrl::OnEnKillfocusEditStrobeDelay)
	ON_EN_KILLFOCUS(IDC_EDIT_STROBE_WIDTH, &CTapCameraCtrl::OnEnKillfocusEditStrobeWidth)
	ON_EN_KILLFOCUS(IDC_EDIT_ROI_X, &CTapCameraCtrl::OnEnKillfocusEditRoiX)
	ON_EN_KILLFOCUS(IDC_EDIT_ROI_Y, &CTapCameraCtrl::OnEnKillfocusEditRoiY)
	ON_EN_KILLFOCUS(IDC_EDIT_ROI_WIDTH, &CTapCameraCtrl::OnEnKillfocusEditRoiWidth)
	ON_EN_KILLFOCUS(IDC_EDIT_ROI_HEIGHT, &CTapCameraCtrl::OnEnKillfocusEditRoiHeight)

	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_CAMGAIN1, &CTapCameraCtrl::OnDeltaposSpinCamgain1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_CAMGAIN2, &CTapCameraCtrl::OnDeltaposSpinCamgain2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_CAMEXPOSURE, &CTapCameraCtrl::OnDeltaposSpinCamexposure)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_CAMFPS, &CTapCameraCtrl::OnDeltaposSpinCamfps)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_TRIGGER_DELAY, &CTapCameraCtrl::OnDeltaposSpinTriggerDelay)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_STROBE_DELAY, &CTapCameraCtrl::OnDeltaposSpinStrobeDelay)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_STROBE_WIDTH, &CTapCameraCtrl::OnDeltaposSpinStrobeWidth)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER_CAMGAIN1, &CTapCameraCtrl::OnNMReleasedcaptureSliderCamgain1)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER_CAMGAIN2, &CTapCameraCtrl::OnNMReleasedcaptureSliderCamgain2)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER_CAMEXPOSURE, &CTapCameraCtrl::OnNMReleasedcaptureSliderCamexposure)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER_CAMFPS, &CTapCameraCtrl::OnNMReleasedcaptureSliderCamfps)

	ON_CBN_SELCHANGE(IDC_COMBO_TRIGGER_SOURCE, &CTapCameraCtrl::OnCbnSelchangeComboTriggerSource)
	ON_CBN_SELCHANGE(IDC_COMBO_TRIGGER_TYPE, &CTapCameraCtrl::OnCbnSelchangeComboTriggerType)
	ON_CBN_SELCHANGE(IDC_COMBO_TRIGGER_POLARITY, &CTapCameraCtrl::OnCbnSelchangeComboTriggerPolarity)
	ON_CBN_SELCHANGE(IDC_COMBO_STROBE_POLARITY, &CTapCameraCtrl::OnCbnSelchangeComboStrobePolarity)
	ON_CBN_SELCHANGE(IDC_COMBO_USERSET, &CTapCameraCtrl::OnCbnSelchangeComboUserset)
	ON_CBN_SELCHANGE(IDC_COMBO_STROBE_SYNC, &CTapCameraCtrl::OnCbnSelchangeComboStrobeSync)
	ON_CBN_SELCHANGE(IDC_COMBO_MTU, &CTapCameraCtrl::OnCbnSelchangeComboMtu)

	ON_BN_CLICKED(IDC_CHECK_TRIGGERENABLE, &CTapCameraCtrl::OnBnClickedCheckTriggerenable)
	ON_BN_CLICKED(IDC_CHECK_STROBEENABLE, &CTapCameraCtrl::OnBnClickedCheckStrobeenable)
	ON_BN_CLICKED(IDC_BTN_TRIGGER_EXE, &CTapCameraCtrl::OnBnClickedBtnTriggerExe)
	ON_BN_CLICKED(IDC_CHECK_SYMMETRY_X, &CTapCameraCtrl::OnBnClickedCheckSymmetryX)
	ON_BN_CLICKED(IDC_CHECK_SYMMETRY_Y, &CTapCameraCtrl::OnBnClickedCheckSymmetryY)
	ON_BN_CLICKED(IDC_BTN_ROI_QUART, &CTapCameraCtrl::OnBnClickedBtnRoiQuart)
	ON_BN_CLICKED(IDC_BTN_ROI_HALF, &CTapCameraCtrl::OnBnClickedBtnRoiHalf)
	ON_BN_CLICKED(IDC_BTN_ROI_FULL, &CTapCameraCtrl::OnBnClickedBtnRoiFull)
	ON_BN_CLICKED(IDC_BTN_ROI_CENTER, &CTapCameraCtrl::OnBnClickedBtnRoiCenter)
	ON_BN_CLICKED(IDC_BTN_ROI, &CTapCameraCtrl::OnBnClickedBtnRoi)
	ON_BN_CLICKED(IDC_BTN_USERSET_LOAD, &CTapCameraCtrl::OnBnClickedBtnUsersetLoad)
	ON_BN_CLICKED(IDC_BTN_USERSET_SAVE, &CTapCameraCtrl::OnBnClickedBtnUsersetSave)
	ON_BN_CLICKED(IDC_BTN_USERSET_APPLY, &CTapCameraCtrl::OnBnClickedBtnUsersetApply)
	ON_BN_CLICKED(IDC_BTN_TIMEOUT, &CTapCameraCtrl::OnBnClickedBtnTimeout)
	ON_BN_CLICKED(IDC_BTN_MTU_CONFIG, &CTapCameraCtrl::OnBnClickedBtnMtuConfig)

END_MESSAGE_MAP()

// CTapCameraCtrl message handlers
LRESULT CTapCameraCtrl::OnNotifyChangeTrackRect(WPARAM wParam, LPARAM lParam)
{
	INFO_ROI_PARA* pstRoi = (INFO_ROI_PARA*)wParam;
	if (pstRoi)
	{
		UpdateValue(IDC_EDIT_ROI_X, pstRoi->nXstart);
		UpdateValue(IDC_EDIT_ROI_Y, pstRoi->nYstart);
		UpdateValue(IDC_EDIT_ROI_WIDTH, pstRoi->nWidth);
		UpdateValue(IDC_EDIT_ROI_HEIGHT, pstRoi->nHeight);
	}

	return S_OK;
}

void CTapCameraCtrl::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	if (0 < SCROLLHEIGHT)
	{
		UpdateScrollInfo();
	}
}

void CTapCameraCtrl::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if (m_ctlSliderGain1.m_hWnd == pScrollBar->m_hWnd)
	{
		const int nPos = m_ctlSliderGain1.GetPos();
		UpdateValue(IDC_EDIT_CAMGAIN1, nPos);
	}
	else if (m_ctlSliderGain2.m_hWnd == pScrollBar->m_hWnd)
	{
		const int nPos = m_ctlSliderGain2.GetPos();
		UpdateValue(IDC_EDIT_CAMGAIN2, nPos);
	}
	else if (m_ctlSliderExposure.m_hWnd == pScrollBar->m_hWnd)
	{
		const int nPos = m_ctlSliderExposure.GetPos();
		UpdateValue(IDC_EDIT_CAMEXPOSURE, nPos);
	}
	else if (m_ctlSliderFps.m_hWnd == pScrollBar->m_hWnd)
	{
		const int nPos = m_ctlSliderFps.GetPos();
		UpdateValue(IDC_EDIT_CAMFPS, nPos);
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CTapCameraCtrl::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if (NULL == pScrollBar || 0 > SCROLLHEIGHT)
	{
		CRect rect;
		this->GetClientRect(rect);

		int nDelta = 0;
		int nMaxPos = SCROLLHEIGHT - rect.Height();

		switch (nSBCode)
		{
		case SB_LINEDOWN:
			if (m_nVPos >= nMaxPos)
				return;
			nDelta = min(nMaxPos / 100, nMaxPos - m_nVPos);
			break;

		case SB_LINEUP:
			if (m_nVPos <= 0)
				return;
			nDelta = -min(nMaxPos / 100, m_nVPos);
			break;

		case SB_PAGEDOWN:
			if (m_nVPos >= nMaxPos)
				return;
			nDelta = min(nMaxPos / 10, nMaxPos - m_nVPos);
			break;

		case SB_THUMBPOSITION:
			nDelta = (int)nPos - m_nVPos;
			break;

		case SB_PAGEUP:
			if (m_nVPos <= 0)
				return;
			nDelta = -min(nMaxPos / 10, m_nVPos);
			break;

		default:
			return;
		}
		m_nVPos += nDelta;
		SetScrollPos(SB_VERT, m_nVPos, TRUE);
		ScrollWindow(0, -nDelta);
	}

	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CTapCameraCtrl::OnEnKillfocusEditCamgain1()
{
	int min = m_stDefDev.m_stDefGain01.m_stRange.m_nFrom;
	int max = m_stDefDev.m_stDefGain01.m_stRange.m_nTo;

	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_CAMGAIN1);
	CheckValue(pEdit, min, max);

	const int value = GetValue(IDC_EDIT_CAMGAIN1);
	m_ctlSliderGain1.SetPos(value);

	//
	const int nGainType = 1;

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	pCaptureManager->SetGain(m_stDefDev.m_eNetwork, m_nProcID, nGainType, value);

}

void CTapCameraCtrl::OnEnKillfocusEditCamgain2()
{
	int min = m_stDefDev.m_stDefGain02.m_stRange.m_nFrom;
	int max = m_stDefDev.m_stDefGain02.m_stRange.m_nTo;

	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_CAMGAIN2);
	CheckValue(pEdit, min, max);

	const int value = GetValue(IDC_EDIT_CAMGAIN2);
	m_ctlSliderGain2.SetPos(value);

	//
	const int nGainType = 2;

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	pCaptureManager->SetGain(m_stDefDev.m_eNetwork, m_nProcID, nGainType, value);
}

void CTapCameraCtrl::OnEnKillfocusEditCamexposure()
{
	int min = m_ctlSliderExposure.GetRangeMin(); //m_stDefDev.m_stDefExposure.m_stRange.m_nFrom;
	int max = m_ctlSliderExposure.GetRangeMax(); //m_stDefDev.m_stDefExposure.m_stRange.m_nTo;

	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_CAMEXPOSURE);
	CheckValue(pEdit, min, max);

	const int value = GetValue(IDC_EDIT_CAMEXPOSURE);
	m_ctlSliderExposure.SetPos(value);

	//
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	{
		unsigned int nCur = 0;
		BOOL bResult = pCaptureManager->GetExposureTime(m_stDefDev.m_eNetwork, m_nProcID, &nCur);
		if (bResult && nCur == value)
			return;
	}

	pCaptureManager->SetExposureTime(m_stDefDev.m_eNetwork, m_nProcID, value);

	{
		const int minVal = m_ctlSliderExposure.GetRangeMin(); //m_stDefDev.m_stDefExposure.m_stRange.m_nFrom;
		const int maxVal = m_ctlSliderExposure.GetRangeMax(); //m_stDefDev.m_stDefExposure.m_stRange.m_nTo;

		double fUsec = 0;
		pCaptureManager->ConvertExposureTime(m_stDefDev.m_eNetwork, m_nProcID, value, &fUsec);

		TCHAR szText[128] = { 0, };
		GetDlgItem(IDC_STATIC_EXPOSURE_RANGE)->ShowWindow(SW_SHOW);
		CUtil::StringFormat(szText, 128, _T("(RANGE: %d ~ %d, TIME: %d usec))"), minVal, maxVal, (int)fUsec);
		GetDlgItem(IDC_STATIC_EXPOSURE_RANGE)->SetWindowText(szText);
	}
}

void CTapCameraCtrl::OnEnKillfocusEditCamfps()
{
	int min = m_ctlSliderFps.GetRangeMin(); //m_stDefDev.m_stDefFrameRate.m_stRange.m_nFrom;
	int max = m_ctlSliderFps.GetRangeMax(); //m_stDefDev.m_stDefFrameRate.m_stRange.m_nTo;

	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_CAMFPS);
	CheckValue(pEdit, min, max);

	const int value = GetValue(IDC_EDIT_CAMFPS);
	m_ctlSliderFps.SetPos(value);

	//
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	{
		unsigned int nCur = 0;
		BOOL bResult = pCaptureManager->GetFrameRate(m_stDefDev.m_eNetwork, m_nProcID, &nCur);
		if (bResult && nCur == value)
			return;

#ifdef USE_BASLER_CAMERA
		if (TYPE_NETWORK_BASLER == m_stDefDev.m_eNetwork)
#endif
#ifdef USE_GIGE_CAMERA
		if (TYPE_NETWORK_GIGE == m_stDefDev.m_eNetwork)
#endif
		{
			BOOL bEnable = FALSE;
			bResult = pCaptureManager->GetEnableFrameRate(m_stDefDev.m_eNetwork, m_nProcID, &bEnable);
			if (bResult && !bEnable)
				pCaptureManager->SetEnableFrameRate(m_stDefDev.m_eNetwork, m_nProcID, TRUE);
		}
	}

	pCaptureManager->SetFrameRate(m_stDefDev.m_eNetwork, m_nProcID, value);

	UpdateExposureRange(value);

}

void CTapCameraCtrl::OnEnKillfocusEditTriggerDelay()
{
	int min = m_stDefDev.m_stDefTrigger.m_stDelayRange.m_nFrom;
	int max = m_stDefDev.m_stDefTrigger.m_stDelayRange.m_nTo;

	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_TRIGGER_DELAY);
	CheckValue(pEdit, min, max);

	const int value = GetValue(IDC_EDIT_TRIGGER_DELAY);

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	pCaptureManager->SetTriggerDelay(m_stDefDev.m_eNetwork, m_nProcID, value);

	//
	//SendTriggerCommand();


}

void CTapCameraCtrl::OnEnKillfocusEditStrobeDelay()
{
	int min = m_stDefDev.m_stDefStrobe.m_stDelayRange.m_nFrom;
	int max = m_stDefDev.m_stDefStrobe.m_stDelayRange.m_nTo;

	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_STROBE_DELAY);
	CheckValue(pEdit, min, max);

	const int value = GetValue(IDC_EDIT_STROBE_DELAY);

	//
	SendStrobeCommand();
}

void CTapCameraCtrl::OnEnKillfocusEditStrobeWidth()
{
	int min = m_stDefDev.m_stDefStrobe.m_stWidthRange.m_nFrom;
	int max = m_stDefDev.m_stDefStrobe.m_stWidthRange.m_nTo;

	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_STROBE_WIDTH);
	CheckValue(pEdit, min, max);

	const int value = GetValue(IDC_EDIT_STROBE_WIDTH);

	//
	SendStrobeCommand();

}

void CTapCameraCtrl::OnEnKillfocusEditRoiX()
{
	INFO_ROI_PARA stRoi;
	memset(&stRoi, 0x00, sizeof(INFO_ROI_PARA));
	m_dlgRoi.GetRoi(&stRoi);

	// Check Range
	{
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_ROI_X);
		CheckValue(pEdit, 0, stRoi.nMaxWidth);
	}

	GetRoiValue(&stRoi);
	UpdateRoiValue(&stRoi);

}

void CTapCameraCtrl::OnEnKillfocusEditRoiY()
{
	INFO_ROI_PARA stRoi;
	memset(&stRoi, 0x00, sizeof(INFO_ROI_PARA));
	m_dlgRoi.GetRoi(&stRoi);

	// Check Range
	{
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_ROI_Y);
		CheckValue(pEdit, 0, stRoi.nMaxHeight);
	}

	GetRoiValue(&stRoi);
	UpdateRoiValue(&stRoi);
}

void CTapCameraCtrl::OnEnKillfocusEditRoiWidth()
{
	INFO_ROI_PARA stRoi;
	memset(&stRoi, 0x00, sizeof(INFO_ROI_PARA));
	m_dlgRoi.GetRoi(&stRoi);

	// Check Range
	{
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_ROI_WIDTH);
		CheckValue(pEdit, 0, stRoi.nMaxWidth);
	}

	GetRoiValue(&stRoi);
	UpdateRoiValue(&stRoi);
}

void CTapCameraCtrl::OnEnKillfocusEditRoiHeight()
{
	INFO_ROI_PARA stRoi;
	memset(&stRoi, 0x00, sizeof(INFO_ROI_PARA));
	m_dlgRoi.GetRoi(&stRoi);

	// Check Range
	{
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_ROI_HEIGHT);
		CheckValue(pEdit, 0, stRoi.nMaxHeight);
	}

	GetRoiValue(&stRoi);
	UpdateRoiValue(&stRoi);
}

void CTapCameraCtrl::OnDeltaposSpinCamgain1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	*pResult = 0;

	int min = m_stDefDev.m_stDefGain01.m_stRange.m_nFrom;
	int max = m_stDefDev.m_stDefGain01.m_stRange.m_nTo;
	ScrollValue(IDC_EDIT_CAMGAIN1, pNMUpDown->iDelta, min, max);

	OnEnKillfocusEditCamgain1();

}

void CTapCameraCtrl::OnDeltaposSpinCamgain2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	*pResult = 0;

	int min = m_stDefDev.m_stDefGain02.m_stRange.m_nFrom;
	int max = m_stDefDev.m_stDefGain02.m_stRange.m_nTo;
	ScrollValue(IDC_EDIT_CAMGAIN2, pNMUpDown->iDelta, min, max);

	OnEnKillfocusEditCamgain2();
}

void CTapCameraCtrl::OnDeltaposSpinCamexposure(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	*pResult = 0;

	int min = m_ctlSliderExposure.GetRangeMin(); //m_stDefDev.m_stDefExposure.m_stRange.m_nFrom;
	int max = m_ctlSliderExposure.GetRangeMax(); //m_stDefDev.m_stDefExposure.m_stRange.m_nTo;
	ScrollValue(IDC_EDIT_CAMEXPOSURE, pNMUpDown->iDelta, min, max);

	OnEnKillfocusEditCamexposure();
}

void CTapCameraCtrl::OnDeltaposSpinCamfps(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	*pResult = 0;

	int min = m_ctlSliderFps.GetRangeMin(); //m_stDefDev.m_stDefFrameRate.m_stRange.m_nFrom;
	int max = m_ctlSliderFps.GetRangeMax(); //m_stDefDev.m_stDefFrameRate.m_stRange.m_nTo;
	ScrollValue(IDC_EDIT_CAMFPS, pNMUpDown->iDelta, min, max);

	OnEnKillfocusEditCamfps();
}

void CTapCameraCtrl::OnDeltaposSpinTriggerDelay(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	*pResult = 0;

	int min = m_stDefDev.m_stDefTrigger.m_stDelayRange.m_nFrom;
	int max = m_stDefDev.m_stDefTrigger.m_stDelayRange.m_nTo;
	ScrollValue(IDC_EDIT_TRIGGER_DELAY, pNMUpDown->iDelta, min, max);

	OnEnKillfocusEditTriggerDelay();
}

void CTapCameraCtrl::OnDeltaposSpinStrobeDelay(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	*pResult = 0;

	int min = m_stDefDev.m_stDefStrobe.m_stDelayRange.m_nFrom;
	int max = m_stDefDev.m_stDefStrobe.m_stDelayRange.m_nTo;
	ScrollValue(IDC_EDIT_STROBE_DELAY, pNMUpDown->iDelta, min, max);

	OnEnKillfocusEditStrobeDelay();
}

void CTapCameraCtrl::OnDeltaposSpinStrobeWidth(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	*pResult = 0;

	int min = m_stDefDev.m_stDefStrobe.m_stWidthRange.m_nFrom;
	int max = m_stDefDev.m_stDefStrobe.m_stWidthRange.m_nTo;
	ScrollValue(IDC_EDIT_STROBE_WIDTH, pNMUpDown->iDelta, min, max);

	OnEnKillfocusEditStrobeWidth();
}

void CTapCameraCtrl::OnNMReleasedcaptureSliderCamgain1(NMHDR *pNMHDR, LRESULT *pResult)
{
	*pResult = 0;

	OnEnKillfocusEditCamgain1();
}

void CTapCameraCtrl::OnNMReleasedcaptureSliderCamgain2(NMHDR *pNMHDR, LRESULT *pResult)
{
	*pResult = 0;

	OnEnKillfocusEditCamgain2();
}

void CTapCameraCtrl::OnNMReleasedcaptureSliderCamexposure(NMHDR *pNMHDR, LRESULT *pResult)
{
	*pResult = 0;

	OnEnKillfocusEditCamexposure();
}

void CTapCameraCtrl::OnNMReleasedcaptureSliderCamfps(NMHDR *pNMHDR, LRESULT *pResult)
{
	*pResult = 0;

	OnEnKillfocusEditCamfps();
}

void CTapCameraCtrl::OnCbnSelchangeComboTriggerSource()
{
	const int nCur = m_ctlTriggerSource.GetCurSel();
	if (TRIGGER_SRC_SW == nCur)
	{
		if (TYPE_NETWORK_GIGE == m_stDefDev.m_eNetwork || TYPE_NETWORK_USB == m_stDefDev.m_eNetwork || TYPE_NETWORK_BASLER == m_stDefDev.m_eNetwork)
		{
			m_ctlTriggerType.EnableWindow(FALSE);
			m_ctlTriggerPolarity.EnableWindow(FALSE);
			m_ctlTriggerPolarity.SetCurSel(1);
		}
		else
		{
			m_ctlTriggerType.EnableWindow(TRUE);
			m_ctlTriggerPolarity.EnableWindow(TRUE);
		}

		GetDlgItem(IDC_BTN_TRIGGER_EXE)->EnableWindow(TRUE);	// SW
		GetDlgItem(IDC_BTN_TIMEOUT)->EnableWindow(TRUE);
	}
	else
	{
		m_ctlTriggerType.EnableWindow(TRUE);
		m_ctlTriggerPolarity.EnableWindow(TRUE);

		GetDlgItem(IDC_BTN_TRIGGER_EXE)->EnableWindow(FALSE);	// Line
		GetDlgItem(IDC_BTN_TIMEOUT)->EnableWindow(FALSE);
	}

	SendTriggerCommand();
}

void CTapCameraCtrl::OnCbnSelchangeComboTriggerType()
{
	SendTriggerCommand();
}

void CTapCameraCtrl::OnCbnSelchangeComboTriggerPolarity()
{
	SendTriggerCommand();
}

void CTapCameraCtrl::OnCbnSelchangeComboStrobeSync()
{
	SendStrobeCommand();
}

void CTapCameraCtrl::OnCbnSelchangeComboStrobePolarity()
{
	SendStrobeCommand();
}

void CTapCameraCtrl::OnCbnSelchangeComboUserset()
{
	const int nCur = m_ctlUserset.GetCurSel();


	// Save
	if (0 == nCur)
		GetDlgItem(IDC_BTN_USERSET_SAVE)->EnableWindow(FALSE);
	else
		GetDlgItem(IDC_BTN_USERSET_SAVE)->EnableWindow(TRUE);

	// Load
	const BOOL bSupportStartup = m_stDefDev.m_stDefUserset.m_bSupportStartup;
	const int nCount = m_stDefDev.m_stDefUserset.m_stRange.m_nTo - m_stDefDev.m_stDefUserset.m_stRange.m_nFrom + 1;

	if (0 == nCur)
		GetDlgItem(IDC_BTN_USERSET_LOAD)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_BTN_USERSET_LOAD)->EnableWindow(bSupportStartup);

}

void CTapCameraCtrl::OnBnClickedCheckTriggerenable()
{
	if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_TRIGGERENABLE))->GetCheck())
		EnableTrigger(TRUE);
	else
		EnableTrigger(FALSE);

	SendTriggerCommand();
}

void CTapCameraCtrl::OnBnClickedCheckStrobeenable()
{
	if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_STROBEENABLE))->GetCheck())
		EnableStrobe(TRUE);
	else
		EnableStrobe(FALSE);

	SendStrobeCommand();
}

void CTapCameraCtrl::OnBnClickedBtnTriggerExe()
{
	// MODE   - 0: off,  1: on
	// SOURCE - 0: Line, 1: SW Trigger

	INFO_TRIGGER_PARA stTrigger;
	memset(&stTrigger, 0x00, sizeof(INFO_TRIGGER_PARA));
	GetTrigger(stTrigger);

	if (TRIGGER_OFF == stTrigger.nTriggerMode || TRIGGER_SRC_LINE == stTrigger.nTriggerSource)
	{
		return;
	}

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	pCaptureManager->SetSWTrigger(m_stDefDev.m_eNetwork, m_nProcID);

}

void CTapCameraCtrl::OnBnClickedCheckSymmetryX()
{
	int nVal = 0;
	GetSymmetry(nVal);

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	pCaptureManager->SetFlipMode(m_stDefDev.m_eNetwork, m_nProcID, nVal);
}

void CTapCameraCtrl::OnBnClickedCheckSymmetryY()
{
	int nVal = 0;
	GetSymmetry(nVal);

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	pCaptureManager->SetFlipMode(m_stDefDev.m_eNetwork, m_nProcID, nVal);
}

void CTapCameraCtrl::OnBnClickedBtnRoiQuart()
{
	INFO_ROI_PARA stRoi;
	memset(&stRoi, 0x00, sizeof(INFO_ROI_PARA));
	m_dlgRoi.GetRoi(&stRoi);

	const DWORD dwMaxWidth = stRoi.nMaxWidth;
	const DWORD dwMaxHeight = stRoi.nMaxHeight;

	int w = dwMaxWidth / 4;
	int h = dwMaxHeight / 4;
	int x = (dwMaxWidth - w) / 2;
	int y = (dwMaxHeight - h) / 2;

	m_dlgRoi.SetRoiPosition(x, y, w, h);


	{
		m_dlgRoi.GetRoi(&stRoi);
		UpdateValue(IDC_EDIT_ROI_X, stRoi.nXstart);
		UpdateValue(IDC_EDIT_ROI_Y, stRoi.nYstart);
		UpdateValue(IDC_EDIT_ROI_WIDTH, stRoi.nWidth);
		UpdateValue(IDC_EDIT_ROI_HEIGHT, stRoi.nHeight);
	}
}

void CTapCameraCtrl::OnBnClickedBtnRoiHalf()
{
	INFO_ROI_PARA stRoi;
	memset(&stRoi, 0x00, sizeof(INFO_ROI_PARA));
	m_dlgRoi.GetRoi(&stRoi);

	const DWORD dwMaxWidth = stRoi.nMaxWidth;
	const DWORD dwMaxHeight = stRoi.nMaxHeight;

	int w = dwMaxWidth / 2;
	int h = dwMaxHeight / 2;
	int x = (dwMaxWidth - w) / 2;
	int y = (dwMaxHeight - h) / 2;

	m_dlgRoi.SetRoiPosition(x, y, w, h);

	{
		m_dlgRoi.GetRoi(&stRoi);
		UpdateValue(IDC_EDIT_ROI_X, stRoi.nXstart);
		UpdateValue(IDC_EDIT_ROI_Y, stRoi.nYstart);
		UpdateValue(IDC_EDIT_ROI_WIDTH, stRoi.nWidth);
		UpdateValue(IDC_EDIT_ROI_HEIGHT, stRoi.nHeight);
	}
}

void CTapCameraCtrl::OnBnClickedBtnRoiFull()
{
	INFO_ROI_PARA stRoi;
	memset(&stRoi, 0x00, sizeof(INFO_ROI_PARA));
	m_dlgRoi.GetRoi(&stRoi);

	const DWORD dwMaxWidth = stRoi.nMaxWidth;
	const DWORD dwMaxHeight = stRoi.nMaxHeight;

	int w = dwMaxWidth;
	int h = dwMaxHeight;
	int x = 0;
	int y = 0;

	m_dlgRoi.SetRoiPosition(x, y, w, h);

	{
		m_dlgRoi.GetRoi(&stRoi);
		UpdateValue(IDC_EDIT_ROI_X, stRoi.nXstart);
		UpdateValue(IDC_EDIT_ROI_Y, stRoi.nYstart);
		UpdateValue(IDC_EDIT_ROI_WIDTH, stRoi.nWidth);
		UpdateValue(IDC_EDIT_ROI_HEIGHT, stRoi.nHeight);
	}
}

void CTapCameraCtrl::OnBnClickedBtnRoiCenter()
{
	INFO_ROI_PARA stRoi;
	memset(&stRoi, 0x00, sizeof(INFO_ROI_PARA));
	m_dlgRoi.GetRoi(&stRoi);

	const DWORD dwMaxWidth = stRoi.nMaxWidth;
	const DWORD dwMaxHeight = stRoi.nMaxHeight;

	int w = stRoi.nWidth;
	int h = stRoi.nHeight;
	int x = (dwMaxWidth - w) / 2;
	int y = (dwMaxHeight - h) / 2;

	m_dlgRoi.SetRoiPosition(x, y, w, h);

	{
		m_dlgRoi.GetRoi(&stRoi);
		UpdateValue(IDC_EDIT_ROI_X, stRoi.nXstart);
		UpdateValue(IDC_EDIT_ROI_Y, stRoi.nYstart);
		UpdateValue(IDC_EDIT_ROI_WIDTH, stRoi.nWidth);
		UpdateValue(IDC_EDIT_ROI_HEIGHT, stRoi.nHeight);
	}
}

void CTapCameraCtrl::OnBnClickedBtnRoi()
{
	BOOL bResult = SendRoiCommand();
	if (bResult)
	{
		INFO_ROI_PARA stRoi;
		memset(&stRoi, 0x00, sizeof(INFO_ROI_PARA));
		this->GetRoi(stRoi);

		// Set Max Framerate
		const int nFps = UpdateFramerateRange(stRoi.nWidth, stRoi.nHeight);
		if (0<nFps)
		{
			this->SetFramerate(nFps);
			OnEnKillfocusEditCamfps();
		}

		// SW TRIGGER -> Update Image...
		{
			INFO_TRIGGER_PARA stParam;
			memset(&stParam, 0x00, sizeof(INFO_TRIGGER_PARA));

			CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
			pCaptureManager->GetTriggerMode(m_stDefDev.m_eNetwork, m_nProcID, &stParam);
			if (TRIGGER_ON == stParam.nTriggerMode && TRIGGER_SRC_SW == stParam.nTriggerSource)
			{
				pCaptureManager->SetSWTrigger(m_stDefDev.m_eNetwork, m_nProcID);
			}

		}
	}
}

void CTapCameraCtrl::OnBnClickedBtnUsersetLoad()
{
	StopnWaitCamera();

	const unsigned char nVal = m_ctlUserset.GetCurSel();

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	pCaptureManager->LoadUserset(m_stDefDev.m_eNetwork, m_nProcID, nVal);
	CUtil::Sleep(500);

	UpdateInformationFromDevice(&m_stDefDev, m_nProcID, TRUE);
	this->Start();

	MessageBox(_T("Complete..."));
}

void CTapCameraCtrl::OnBnClickedBtnUsersetSave()
{
	int nVal = m_ctlUserset.GetCurSel();

#ifdef USE_BASLER_CAMERA
	if (TYPE_NETWORK_BASLER == m_stDefDev.m_eNetwork && FALSE == m_stDefDev.m_stDefUserset.m_bSupportStartup)
#endif
#ifdef USE_GIGE_CAMERA
	if (TYPE_NETWORK_GIGE == m_stDefDev.m_eNetwork && FALSE == m_stDefDev.m_stDefUserset.m_bSupportStartup)
#endif
		nVal = -1;

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	pCaptureManager->SaveUserset(m_stDefDev.m_eNetwork, m_nProcID, nVal);

	MessageBox(_T("Complete..."));
}

void CTapCameraCtrl::OnBnClickedBtnUsersetApply()
{
	unsigned char nVal = m_ctlStartupUserset.GetCurSel();

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	pCaptureManager->SetUsersetStartNo(m_stDefDev.m_eNetwork, m_nProcID, nVal);

}

void CTapCameraCtrl::OnCbnSelchangeComboMtu()
{
	unsigned int nMtu = 1444;

	const int nIdx = m_ctlMtu.GetCurSel();
	if (0 == nIdx)			nMtu = 1444;
	else if (1 == nIdx)		nMtu = 1828;
	else if (2 == nIdx)		nMtu = 2852;
	else if (3 == nIdx)		nMtu = 3876;
	else if (4 == nIdx)		nMtu = 4900;
	else if (5 == nIdx)		nMtu = 5924;
	else if (6 == nIdx)		nMtu = 6948;
	else if (7 == nIdx)		nMtu = 7972;
	else if (8 == nIdx)		nMtu = 8996;

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	StopnWaitCamera();
	pCaptureManager->SetMTU(m_stDefDev.m_eNetwork, m_nProcID, nMtu);
	pCaptureManager->Start(m_stDefDev.m_eNetwork, m_nProcID);

}

void CTapCameraCtrl::OnBnClickedBtnTimeout()
{
	//CDlgTimeOut dlgTimeOut;
	//dlgTimeOut.DoModal();

}

void CTapCameraCtrl::OnBnClickedBtnMtuConfig()
{
	//CDlgMtu dlgMtu;
	//dlgMtu.DoModal();

}

void CTapCameraCtrl::SetMaxScrollHeight(int h)
{
	SCROLLHEIGHT = h;

	UpdateScrollInfo();
}

void CTapCameraCtrl::UpdateScrollInfo()
{
	CRect rect;
	this->GetClientRect(&rect);

	SCROLLINFO si;
	memset(&si, 0x00, sizeof(SCROLLINFO));
	si.cbSize = sizeof(SCROLLINFO);
	si.fMask = SIF_ALL; // SIF_ALL = SIF_PAGE | SIF_RANGE | SIF_POS;
	si.nMax = SCROLLHEIGHT;
	si.nPage = rect.Height() / 2;

	SetScrollInfo(SB_VERT, &si, TRUE);
	this->SendMessage(WM_VSCROLL, MAKEWPARAM(SB_THUMBPOSITION, 0));
}

void CTapCameraCtrl::UpdateInformation(const INFO_DEFDEV* pstDefDev, const int nProcID)
{
	if (pstDefDev)
	{
		m_stDefDev = *pstDefDev;
		m_nProcID = nProcID;
	}
	else
	{
		m_nProcID = -1;
	}

	UpdateGain1(pstDefDev);
	UpdateGain2(pstDefDev);
	UpdateExposure(pstDefDev, FALSE);
	UpdateFramerate(pstDefDev);
	UpdateTrigger(pstDefDev);
	UpdateStrobe(pstDefDev);
	UpdateSymmetry(pstDefDev);
	UpdateRoi(pstDefDev);
	UpdateUserset(pstDefDev);
	UpdateMtu(pstDefDev);

	UpdateInformationFromDevice(pstDefDev, nProcID);

	if (pstDefDev)
	{
		m_dlgRoi.UpdateInformation(&pstDefDev->m_stDefROI);
	}
}

void CTapCameraCtrl::UpdateInformationFromDevice(const INFO_DEFDEV* pstDefDev, const int nProcID, BOOL bLoaded)
{
	if (NULL == pstDefDev || 0 > nProcID)
		return;

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	DWORD dwErrorCount = 0;

	if (pstDefDev->m_stDefGain01.m_bSupport)
	{
		const int nGainType = 1;
		int nVal = 0;

		BOOL bResult = pCaptureManager->GetGain(pstDefDev->m_eNetwork, nProcID, nGainType, &nVal);
		if (bResult)
		{
			SetGain1(nVal);
		}
		else
		{
			dwErrorCount++;
		}
	}

	if (pstDefDev->m_stDefGain02.m_bSupport)
	{
		const int nGainType = 2;
		int nVal = 0;

		BOOL bResult = pCaptureManager->GetGain(pstDefDev->m_eNetwork, nProcID, nGainType, &nVal);
		if (bResult)
		{
			SetGain2(nVal);
		}
		else
		{
			dwErrorCount++;
		}
	}

	if (pstDefDev->m_stDefTrigger.m_bSupport)
	{
		INFO_TRIGGER_PARA stParam;
		memset(&stParam, 0x00, sizeof(INFO_TRIGGER_PARA));

		m_ctlTriggerType.ResetContent();
		if (pstDefDev->m_stDefTrigger.m_bTriggerTypeSupport[TYPE_TRIGGERTYPE_EDGE])
			m_ctlTriggerType.AddString(_T("EDGE"));
		if (pstDefDev->m_stDefTrigger.m_bTriggerTypeSupport[TYPE_TRIGGERTYPE_LEVEL])
			m_ctlTriggerType.AddString(_T("LEVEL"));
		m_ctlTriggerType.SetCurSel(0);

		BOOL bResult = pCaptureManager->GetTriggerMode(pstDefDev->m_eNetwork, nProcID, &stParam);
		if (bResult)
		{
			SetTrigger(stParam);
		}
		else
		{
			dwErrorCount++;
		}
	}

	if (pstDefDev->m_stDefStrobe.m_bSupport)
	{
		INFO_STROBE_PARA stParam;
		memset(&stParam, 0x00, sizeof(INFO_STROBE_PARA));

		BOOL bResult = pCaptureManager->GetStrobeMode(pstDefDev->m_eNetwork, nProcID, &stParam);
		if (bResult)
		{
			SetStrobe(stParam);
		}
		else
		{
			dwErrorCount++;
		}
	}

	if (pstDefDev->m_stDefSymmetry.m_bSupport)
	{
		unsigned short nSymmetry = 0;
		BOOL bResult = pCaptureManager->GetFlipMode(pstDefDev->m_eNetwork, nProcID, &nSymmetry);
		if (bResult)
		{
			SetSymmetry(nSymmetry);
		}
		else
		{
			dwErrorCount++;
		}
	}

	if (pstDefDev->m_stDefROI.m_bSupport)
	{
		INFO_ROI_PARA stParam;
		memset(&stParam, 0x00, sizeof(INFO_ROI_PARA));

		BOOL bResult = pCaptureManager->GetROI(pstDefDev->m_eNetwork, nProcID, &stParam);
		if (bResult)
		{
			if (bLoaded)
			{
				pCaptureManager->SetROI(pstDefDev->m_eNetwork, nProcID, stParam);
			}

			SetRoi(stParam);
			UpdateFramerateRange(stParam.nWidth, stParam.nHeight);
		}
		else
		{
			dwErrorCount++;
		}
	}

	// Framerate & Exposure...
	{
		//if (pstDefDev->m_stDefFrameRate.m_bSupport)
		{
			unsigned int nVal = 0;
			BOOL bResult = pCaptureManager->GetFrameRate(pstDefDev->m_eNetwork, nProcID, &nVal);
			if (bResult)
			{
				if (pstDefDev->m_stDefFrameRate.m_bSupport)
				{
					const int nMinFps = m_ctlSliderFps.GetRangeMin();
					const int nMaxFps = m_ctlSliderFps.GetRangeMax();

					if (nMinFps > nVal)			nVal = nMinFps;
					else if (nMaxFps < nVal)	nVal = nMaxFps;

					SetFramerate(nVal);
				}
				else
				{
					UpdateValue(IDC_EDIT_CAMFPS, nVal);
				}
			}
			else
			{
				if (pstDefDev->m_stDefFrameRate.m_bSupport)
					dwErrorCount++;
			}
		}

		if (pstDefDev->m_stDefExposure.m_bSupport)
		{
			unsigned int nVal = 0;
			BOOL bResult = pCaptureManager->GetExposureTime(pstDefDev->m_eNetwork, nProcID, &nVal);
			if (bResult)
			{
				SetExposure(nVal);
			}
			else
			{
				dwErrorCount++;
			}

			// Update Exposure Range
			int nCurFps = 0;
			this->GetFramerate(nCurFps);
			UpdateExposureRange(nCurFps);
		}
	}



	if (pstDefDev->m_stDefUserset.m_bSupport)
	{
		const int nFrom = pstDefDev->m_stDefUserset.m_stRange.m_nFrom;
		const int nTo = pstDefDev->m_stDefUserset.m_stRange.m_nTo;

		m_ctlUserset.ResetContent();
		m_ctlStartupUserset.ResetContent();

		m_ctlUserset.AddString(_T("DEFAULT"));
		m_ctlStartupUserset.AddString(_T("DEFAULT"));

		TCHAR szTxt[16] = { 0, };

		for (int i = nFrom; i <= nTo; i++)
		{
			CUtil::StringFormat(szTxt, 16, _T("USERSET %d"), i);

			m_ctlUserset.AddString(szTxt);
			m_ctlStartupUserset.AddString(szTxt);

		}

		m_ctlUserset.SetCurSel(0);
		m_ctlStartupUserset.SetCurSel(0);
		GetDlgItem(IDC_BTN_USERSET_SAVE)->EnableWindow(FALSE);

		if (pstDefDev->m_stDefUserset.m_bSupportStartup)
		{
			unsigned char nVal = 0;
			BOOL bResult = pCaptureManager->GetUsersetStartNo(pstDefDev->m_eNetwork, nProcID, &nVal);
			if (bResult)
			{
				SetStartupUserset(nVal);
			}
			else
			{
				dwErrorCount++;
			}
		}
	}

	if (pstDefDev->m_stDefMTU.m_bSupport)
	{
		m_ctlMtu.ResetContent();

		m_ctlMtu.AddString(_T("1500"));
		m_ctlMtu.AddString(_T("2K"));
		m_ctlMtu.AddString(_T("3K"));
		m_ctlMtu.AddString(_T("4K"));
		m_ctlMtu.AddString(_T("5K"));
		m_ctlMtu.AddString(_T("6K"));
		m_ctlMtu.AddString(_T("7K"));
		m_ctlMtu.AddString(_T("8K"));
		m_ctlMtu.AddString(_T("9K"));

		m_ctlMtu.SetCurSel(0);
	}

	if (pstDefDev->m_stDefMTU.m_bSupport)
	{
		unsigned int nMtu = 0;
		pCaptureManager->GetMTU(pstDefDev->m_eNetwork, nProcID, &nMtu);

		int nIdx = 0;

		if (1500 >= nMtu)			nIdx = 0;
		else if (1024 * 2 >= nMtu)	nIdx = 1;
		else if (1024 * 3 >= nMtu)	nIdx = 2;
		else if (1024 * 4 >= nMtu)	nIdx = 3;
		else if (1024 * 5 >= nMtu)	nIdx = 4;
		else if (1024 * 6 >= nMtu)	nIdx = 5;
		else if (1024 * 7 >= nMtu)	nIdx = 6;
		else if (1024 * 8 >= nMtu)	nIdx = 7;
		else if (1024 * 9 >= nMtu)	nIdx = 8;

		m_ctlMtu.SetCurSel(nIdx);
	}

	if (0<dwErrorCount)
	{
		AfxMessageBox(_T("Fail to load information."));
	}
}


void CTapCameraCtrl::LimitRange(CEdit* pEdit, int* pnValue, const int nMin, const int nMax)
{
	if (NULL == pEdit || NULL == pnValue)
		return;

	TCHAR szTemp[16] = { 0, };
	pEdit->GetWindowText(szTemp, 16);

	int val = CUtil::StringToInt(szTemp, 16);
	if (nMin>val)
	{
		*pnValue = nMin;
		CUtil::StringFormat(szTemp, 16, _T("%d"), *pnValue);
		pEdit->SetWindowText(szTemp);

		// Error message
		CUtil::DisplayRangeMessage(this->m_hWnd, nMin, nMax);
	}
	else if (nMax<val)
	{
		*pnValue = nMax;
		CUtil::StringFormat(szTemp, 16, _T("%d"), *pnValue);
		pEdit->SetWindowText(szTemp);

		// Error message
		CUtil::DisplayRangeMessage(this->m_hWnd, nMin, nMax);
	}
	else
	{
		*pnValue = val;
	}
}

void CTapCameraCtrl::CheckValue(CEdit* pEdit, const int nMin, const int nMax)
{
	TCHAR szTemp[MAX_NAME_LEN] = { 0, };
	pEdit->GetWindowText(szTemp, MAX_NAME_LEN);
	int nValue = CUtil::StringToInt(szTemp, MAX_NAME_LEN);

	LimitRange(pEdit, &nValue, nMin, nMax);
}

void CTapCameraCtrl::UpdateValue(const DWORD dwCtrlID, const int nValue)
{
	TCHAR szText[MAX_NAME_LEN] = { 0, };

	CUtil::StringFormat(szText, MAX_NAME_LEN, _T("%d"), nValue);
	GetDlgItem(dwCtrlID)->SetWindowText(szText);
}

int CTapCameraCtrl::GetValue(const DWORD dwCtrlID)
{
	TCHAR szText[MAX_NAME_LEN] = { 0, };
	GetDlgItem(dwCtrlID)->GetWindowText(szText, MAX_NAME_LEN);

	return CUtil::StringToInt(szText, MAX_NAME_LEN);
}

void CTapCameraCtrl::ScrollValue(const DWORD dwEditID, int nDelta, const int nMin, const int nMax)
{
	int nValue = GetValue(dwEditID);
	nValue += nDelta;

	if (nMin>nValue)		nValue = nMin;
	if (nMax<nValue)		nValue = nMax;

	UpdateValue(dwEditID, nValue);
}

void CTapCameraCtrl::UpdateRoiValue(const INFO_ROI_PARA* pstParam)
{
	if (NULL == pstParam)
		return;

	INFO_ROI_PARA stRoi;
	memset(&stRoi, 0x00, sizeof(INFO_ROI_PARA));
	m_dlgRoi.GetRoi(&stRoi);

	stRoi.nXstart = pstParam->nXstart;
	stRoi.nYstart = pstParam->nYstart;
	stRoi.nWidth = pstParam->nWidth;
	stRoi.nHeight = pstParam->nHeight;

	UpdateValue(IDC_EDIT_ROI_X, stRoi.nXstart);
	UpdateValue(IDC_EDIT_ROI_Y, stRoi.nYstart);
	UpdateValue(IDC_EDIT_ROI_WIDTH, stRoi.nWidth);
	UpdateValue(IDC_EDIT_ROI_HEIGHT, stRoi.nHeight);

	m_dlgRoi.SetRoi(&stRoi);

}

BOOL CTapCameraCtrl::GetRoiValue(INFO_ROI_PARA* pstParam)
{
	if (NULL == pstParam)
		return FALSE;

	INFO_ROI_PARA stRoi;
	memset(&stRoi, 0x00, sizeof(INFO_ROI_PARA));
	m_dlgRoi.GetRoi(&stRoi);

	pstParam->nXstart = GetValue(IDC_EDIT_ROI_X);
	pstParam->nYstart = GetValue(IDC_EDIT_ROI_Y);
	pstParam->nWidth = GetValue(IDC_EDIT_ROI_WIDTH);
	pstParam->nHeight = GetValue(IDC_EDIT_ROI_HEIGHT);

	pstParam->nMaxWidth = stRoi.nMaxWidth;
	pstParam->nMaxHeight = stRoi.nMaxHeight;

	m_dlgRoi.CorrectRoi(pstParam);

	return TRUE;

}

//
void CTapCameraCtrl::UpdateGain1(const INFO_DEFDEV* pstDefDev)
{
	// Gain1
	BOOL bEnable = FALSE;

	if (pstDefDev && pstDefDev->m_stDefGain01.m_bSupport)
	{
		bEnable = TRUE;

		const int min = pstDefDev->m_stDefGain01.m_stRange.m_nFrom;
		const int max = pstDefDev->m_stDefGain01.m_stRange.m_nTo;

		m_ctlSliderGain1.SetRange(min, max);
		m_ctlSpinGain1.SetRange32(min, max);

		TCHAR szText[128] = { 0, };
		GetDlgItem(IDC_STATIC_GAIN1_RANGE)->ShowWindow(SW_SHOW);
		CUtil::StringFormat(szText, 128, _T("(RANGE: %d ~ %d)"), min, max);
		GetDlgItem(IDC_STATIC_GAIN1_RANGE)->SetWindowText(szText);

	}
	else
	{
		GetDlgItem(IDC_STATIC_GAIN1_RANGE)->ShowWindow(SW_HIDE);
	}

	EnableGain1(bEnable);

}

void CTapCameraCtrl::UpdateGain2(const INFO_DEFDEV* pstDefDev)
{
	// Gain2
	BOOL bEnable = FALSE;

	if (pstDefDev && pstDefDev->m_stDefGain02.m_bSupport)
	{
		bEnable = TRUE;

		const int min = pstDefDev->m_stDefGain02.m_stRange.m_nFrom;
		const int max = pstDefDev->m_stDefGain02.m_stRange.m_nTo;

		m_ctlSliderGain2.SetRange(min, max);
		m_ctlSpinGain2.SetRange32(min, max);


		TCHAR szText[128] = { 0, };
		GetDlgItem(IDC_STATIC_GAIN2_RANGE)->ShowWindow(SW_SHOW);
		CUtil::StringFormat(szText, 128, _T("(RANGE: %d ~ %d)"), min, max);
		GetDlgItem(IDC_STATIC_GAIN2_RANGE)->SetWindowText(szText);
	}
	else
	{
		GetDlgItem(IDC_STATIC_GAIN2_RANGE)->ShowWindow(SW_HIDE);
	}

	EnableGain2(bEnable);

}

void CTapCameraCtrl::UpdateExposure(const INFO_DEFDEV* pstDefDev, BOOL bUpdate)
{
	// Exposure
	BOOL bEnable = FALSE;

	if (pstDefDev && pstDefDev->m_stDefExposure.m_bSupport)
	{
		bEnable = TRUE;

		if (bUpdate)
		{
			CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

			const int min = pstDefDev->m_stDefExposure.m_stRange.m_nFrom;
			const int max = pstDefDev->m_stDefExposure.m_stRange.m_nTo;

			m_ctlSliderExposure.SetRange(min, max);
			m_ctlSpinExposure.SetRange32(min, max);

			m_ctlSliderExposure.SetPos(max);

			double fUsec = 0;
			pCaptureManager->ConvertExposureTime(m_stDefDev.m_eNetwork, m_nProcID, max, &fUsec);

			TCHAR szText[128] = { 0, };
			GetDlgItem(IDC_STATIC_EXPOSURE_RANGE)->ShowWindow(SW_SHOW);
			CUtil::StringFormat(szText, 128, _T("(RANGE: %d ~ %d, TIME: %d usec)"), min, max, (int)fUsec);
			GetDlgItem(IDC_STATIC_EXPOSURE_RANGE)->SetWindowText(szText);
		}
	}
	else
	{
		GetDlgItem(IDC_STATIC_EXPOSURE_RANGE)->ShowWindow(SW_HIDE);
	}

	EnableExposure(bEnable);

}

void CTapCameraCtrl::UpdateExposureRange(const int nFps)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	BOOL bWorking = pCaptureManager->IsWorkingCamera(m_nProcID);
	if (bWorking)
	{
		unsigned int min = m_stDefDev.m_stDefExposure.m_stRange.m_nFrom;
		unsigned int max = m_stDefDev.m_stDefExposure.m_stRange.m_nTo;

		pCaptureManager->GetExposureMaxTime(m_stDefDev.m_eNetwork, m_nProcID, nFps, &max);
		{
			m_ctlSliderExposure.SetRange(min, max);
			m_ctlSliderExposure.SetRangeMax(max, TRUE);
			m_ctlSpinExposure.SetRange32(min, max);

			const int minVal = m_ctlSliderExposure.GetRangeMin(); //m_stDefDev.m_stDefExposure.m_stRange.m_nFrom;
			const int maxVal = m_ctlSliderExposure.GetRangeMax(); //m_stDefDev.m_stDefExposure.m_stRange.m_nTo;

			// Check Current Exposure...
			unsigned int cur = maxVal;
			pCaptureManager->GetExposureTime(m_stDefDev.m_eNetwork, m_nProcID, &cur);
			if (maxVal < cur)
				cur = maxVal;
			SetExposure(cur);


			double fUsec = 0;
			pCaptureManager->ConvertExposureTime(m_stDefDev.m_eNetwork, m_nProcID, cur, &fUsec);

			TCHAR szText[128] = { 0, };
			GetDlgItem(IDC_STATIC_EXPOSURE_RANGE)->ShowWindow(SW_SHOW);
			CUtil::StringFormat(szText, 128, _T("(RANGE: %d ~ %d, TIME: %d usec))"), minVal, maxVal, (int)fUsec);
			GetDlgItem(IDC_STATIC_EXPOSURE_RANGE)->SetWindowText(szText);
		}
	}

}

void CTapCameraCtrl::UpdateFramerate(const INFO_DEFDEV* pstDefDev)
{
	// Fps
	BOOL bEnable = FALSE;

	if (pstDefDev && pstDefDev->m_stDefFrameRate.m_bSupport)
	{
		bEnable = TRUE;

		const int min = pstDefDev->m_stDefFrameRate.m_stRange.m_nFrom;
		const int max = pstDefDev->m_stDefFrameRate.m_stRange.m_nTo;

		m_ctlSliderFps.SetRange(min, max);
		m_ctlSpinFps.SetRange32(min, max);

		TCHAR szText[128] = { 0, };
		GetDlgItem(IDC_STATIC_FPS_RANGE)->ShowWindow(SW_SHOW);
		CUtil::StringFormat(szText, 128, _T("(RANGE: %d ~ %d)"), min, max);
		GetDlgItem(IDC_STATIC_FPS_RANGE)->SetWindowText(szText);

	}
	else
	{
		GetDlgItem(IDC_STATIC_FPS_RANGE)->ShowWindow(SW_HIDE);
	}

	EnableFramerate(bEnable);

}

int CTapCameraCtrl::UpdateFramerateRange(const int nWidth, const int nHeight)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	int nMaxFps = -1;

	if (m_stDefDev.m_stDefFrameRate.m_bSupport)
	{
		int min = m_stDefDev.m_stDefFrameRate.m_stRange.m_nFrom;
		int max = m_stDefDev.m_stDefFrameRate.m_stRange.m_nTo;

		DWORD dwMaxFps = 0;
		BOOL bResult = pCaptureManager->CalculateMaxFrameRate(&m_stDefDev, m_nProcID, nWidth, nHeight, &dwMaxFps);
		if (bResult)
		{
			max = (int)dwMaxFps;
		}

		m_ctlSliderFps.SetRange(min, max);
		m_ctlSpinFps.SetRange32(min, max);

		TCHAR szText[128] = { 0, };
		GetDlgItem(IDC_STATIC_FPS_RANGE)->ShowWindow(SW_SHOW);
		CUtil::StringFormat(szText, 128, _T("(RANGE: %d ~ %d)"), min, max);
		GetDlgItem(IDC_STATIC_FPS_RANGE)->SetWindowText(szText);

		nMaxFps = max;
	}
	else
	{
		DWORD dwMaxFps = 0;
		BOOL bResult = pCaptureManager->CalculateMaxFrameRate(&m_stDefDev, m_nProcID, nWidth, nHeight, &dwMaxFps);
		if (bResult)
		{
			UpdateValue(IDC_EDIT_CAMFPS, dwMaxFps);
		}
		GetDlgItem(IDC_STATIC_FPS_RANGE)->ShowWindow(SW_HIDE);
	}

	return nMaxFps;

}

void CTapCameraCtrl::UpdateTrigger(const INFO_DEFDEV* pstDefDev)
{
	// Trigger
	BOOL bEnable = FALSE;

	if (pstDefDev && pstDefDev->m_stDefTrigger.m_bSupport)
	{
		bEnable = TRUE;

		const int min = pstDefDev->m_stDefTrigger.m_stDelayRange.m_nFrom;
		const int max = pstDefDev->m_stDefTrigger.m_stDelayRange.m_nTo;

		m_ctlSpinTriggerDelay.SetRange32(min, max);

		GetDlgItem(IDC_STATIC_TRIGGER_DELAY_RANGE)->ShowWindow(SW_SHOW);
		TCHAR szText[128] = { 0, };
		if (TYPE_NETWORK_GIGE == pstDefDev->m_eNetwork)
			CUtil::StringFormat(szText, 128, _T("(RANGE: %d ~ %d usec)"), min, max);
		else if (TYPE_NETWORK_USB == pstDefDev->m_eNetwork || TYPE_NETWORK_CAMERALINK == pstDefDev->m_eNetwork)
			CUtil::StringFormat(szText, 128, _T("(RANGE: %d ~ %d msec)"), min, max);
		else if (TYPE_NETWORK_BASLER == pstDefDev->m_eNetwork)
			CUtil::StringFormat(szText, 128, _T("(RANGE: %d ~ %d usec)"), min, max);
		else
			CUtil::StringFormat(szText, 128, _T("(RANGE: %d ~ %d)"), min, max);
		GetDlgItem(IDC_STATIC_TRIGGER_DELAY_RANGE)->SetWindowText(szText);
	}
	else
	{
		GetDlgItem(IDC_STATIC_TRIGGER_DELAY_RANGE)->ShowWindow(SW_HIDE);
	}

	GetDlgItem(IDC_CHECK_TRIGGERENABLE)->EnableWindow(bEnable);

	if (bEnable && BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_TRIGGERENABLE))->GetCheck())
		EnableTrigger(TRUE);
	else
		EnableTrigger(FALSE);

}

void CTapCameraCtrl::UpdateStrobe(const INFO_DEFDEV* pstDefDev)
{
	// Strobe
	BOOL bEnable = FALSE;

	if (pstDefDev && pstDefDev->m_stDefStrobe.m_bSupport)
	{
		TCHAR szText[128] = { 0, };
		bEnable = TRUE;

		//
		int min = pstDefDev->m_stDefStrobe.m_stDelayRange.m_nFrom;
		int max = pstDefDev->m_stDefStrobe.m_stDelayRange.m_nTo;

		m_ctlSpinStrobeDelay.SetRange32(min, max);

		GetDlgItem(IDC_STATIC_STROBE_DELAY_RANGE)->ShowWindow(SW_SHOW);
		if (TYPE_NETWORK_GIGE == pstDefDev->m_eNetwork)
			CUtil::StringFormat(szText, 128, _T("(RANGE: %d ~ %d usec)"), min, max);
		else if (TYPE_NETWORK_USB == pstDefDev->m_eNetwork || TYPE_NETWORK_CAMERALINK == pstDefDev->m_eNetwork)
			CUtil::StringFormat(szText, 128, _T("(RANGE: %d ~ %d msec)"), min, max);
		else if (TYPE_NETWORK_BASLER == pstDefDev->m_eNetwork)
			CUtil::StringFormat(szText, 128, _T("(RANGE: %d ~ %d usec)"), min, max);
		else
			CUtil::StringFormat(szText, 128, _T("(RANGE: %d ~ %d)"), min, max);
		GetDlgItem(IDC_STATIC_STROBE_DELAY_RANGE)->SetWindowText(szText);

		//
		min = pstDefDev->m_stDefStrobe.m_stWidthRange.m_nFrom;
		max = pstDefDev->m_stDefStrobe.m_stWidthRange.m_nTo;

		m_ctlSpinStrobeWidth.SetRange32(min, max);

		GetDlgItem(IDC_STATIC_STROBE_WIDTH_RANGE)->ShowWindow(SW_SHOW);
		if (TYPE_NETWORK_GIGE == pstDefDev->m_eNetwork)
			CUtil::StringFormat(szText, 128, _T("(RANGE: %d ~ %d usec)"), min, max);
		else if (TYPE_NETWORK_USB == pstDefDev->m_eNetwork || TYPE_NETWORK_CAMERALINK == pstDefDev->m_eNetwork)
			CUtil::StringFormat(szText, 128, _T("(RANGE: %d ~ %d msec)"), min, max);
		else if (TYPE_NETWORK_BASLER == pstDefDev->m_eNetwork)
			CUtil::StringFormat(szText, 128, _T("(RANGE: %d ~ %d usec)"), min, max);
		else
			CUtil::StringFormat(szText, 128, _T("(RANGE: %d ~ %d)"), min, max);
		GetDlgItem(IDC_STATIC_STROBE_WIDTH_RANGE)->SetWindowText(szText);

	}
	else
	{
		GetDlgItem(IDC_STATIC_STROBE_DELAY_RANGE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_STROBE_WIDTH_RANGE)->ShowWindow(SW_HIDE);
	}

	GetDlgItem(IDC_CHECK_STROBEENABLE)->EnableWindow(bEnable);

	if (bEnable && BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_STROBEENABLE))->GetCheck())
		EnableStrobe(TRUE);
	else
		EnableStrobe(FALSE);

}

void CTapCameraCtrl::UpdateSymmetry(const INFO_DEFDEV* pstDefDev)
{
	// Symmetry
	if (pstDefDev && pstDefDev->m_stDefSymmetry.m_bSupport)
		EnableSymmetry(TRUE, &pstDefDev->m_stDefSymmetry);
	else
		EnableSymmetry(FALSE, NULL);

}

void CTapCameraCtrl::UpdateRoi(const INFO_DEFDEV* pstDefDev)
{
	// Roi
	BOOL bEnable = FALSE;
	if (pstDefDev && pstDefDev->m_stDefROI.m_bSupport)
	{
		bEnable = TRUE;
	}

	EnableRoi(bEnable);

}

void CTapCameraCtrl::UpdateUserset(const INFO_DEFDEV* pstDefDev)
{
	// Userset
	if (pstDefDev && pstDefDev->m_stDefUserset.m_bSupport)
	{
		EnableUserset(TRUE, &pstDefDev->m_stDefUserset);
	}
	else
	{
		EnableUserset(FALSE, NULL);
	}
}

void CTapCameraCtrl::UpdateMtu(const INFO_DEFDEV* pstDefDev)
{
	m_ctlMtu.ResetContent();
	m_ctlMtu.AddString(_T("1500"));
	m_ctlMtu.SetCurSel(0);

	if (pstDefDev)
	{
		m_ctlMtu.EnableWindow(pstDefDev->m_stDefMTU.m_bSupport);
	}
	else
	{
		m_ctlMtu.EnableWindow(FALSE);
	}
}

void CTapCameraCtrl::EnableGain1(BOOL bEnable)
{
	GetDlgItem(IDC_EDIT_CAMGAIN1)->EnableWindow(bEnable);
	m_ctlSliderGain1.EnableWindow(bEnable);
	m_ctlSpinGain1.EnableWindow(bEnable);
}

void CTapCameraCtrl::EnableGain2(BOOL bEnable)
{
	GetDlgItem(IDC_EDIT_CAMGAIN2)->EnableWindow(bEnable);
	m_ctlSliderGain2.EnableWindow(bEnable);
	m_ctlSpinGain2.EnableWindow(bEnable);
}

void CTapCameraCtrl::EnableExposure(BOOL bEnable)
{
	GetDlgItem(IDC_EDIT_CAMEXPOSURE)->EnableWindow(bEnable);
	m_ctlSliderExposure.EnableWindow(bEnable);
	m_ctlSpinExposure.EnableWindow(bEnable);
}

void CTapCameraCtrl::EnableFramerate(BOOL bEnable)
{
	GetDlgItem(IDC_EDIT_CAMFPS)->EnableWindow(bEnable);
	m_ctlSliderFps.EnableWindow(bEnable);
	m_ctlSpinFps.EnableWindow(bEnable);
}

void CTapCameraCtrl::EnableTrigger(BOOL bEnable)
{
	m_ctlTriggerSource.EnableWindow(bEnable);

	if (bEnable)
	{
		const int nCur = m_ctlTriggerSource.GetCurSel();
		if (TRIGGER_SRC_SW == nCur)
		{
#ifdef USE_BASLER_CAMERA
			if (TYPE_NETWORK_BASLER == m_stDefDev.m_eNetwork)
#endif
#ifdef USE_GIGE_CAMERA
			if (TYPE_NETWORK_GIGE == m_stDefDev.m_eNetwork)
#endif
			{
				m_ctlTriggerType.EnableWindow(FALSE);
				m_ctlTriggerPolarity.EnableWindow(FALSE);
				m_ctlTriggerPolarity.SetCurSel(1);
			}
			else
			{
				m_ctlTriggerType.EnableWindow(FALSE);
				m_ctlTriggerPolarity.EnableWindow(FALSE);
			}

			GetDlgItem(IDC_BTN_TRIGGER_EXE)->EnableWindow(TRUE);	// SW Trigger
			GetDlgItem(IDC_BTN_TIMEOUT)->EnableWindow(TRUE);
		}
		else //if (TRIGGER_SRC_LINE == nCur)
		{
			m_ctlTriggerType.EnableWindow(TRUE);
			m_ctlTriggerPolarity.EnableWindow(TRUE);

			GetDlgItem(IDC_BTN_TRIGGER_EXE)->EnableWindow(FALSE);	// Line
			GetDlgItem(IDC_BTN_TIMEOUT)->EnableWindow(FALSE);
		}
	}
	else
	{
		m_ctlTriggerType.EnableWindow(bEnable);
		m_ctlTriggerPolarity.EnableWindow(bEnable);
		GetDlgItem(IDC_BTN_TRIGGER_EXE)->EnableWindow(bEnable);
		GetDlgItem(IDC_BTN_TIMEOUT)->EnableWindow(FALSE);
	}

	m_ctlSpinTriggerDelay.EnableWindow(bEnable);
	GetDlgItem(IDC_EDIT_TRIGGER_DELAY)->EnableWindow(bEnable);

}

void CTapCameraCtrl::EnableStrobe(BOOL bEnable)
{
	if (bEnable)
		m_ctlStrobeSync.EnableWindow(m_stDefDev.m_stDefStrobe.m_bSupportSync);
	else
		m_ctlStrobeSync.EnableWindow(bEnable);

	m_ctlStrobePolarity.EnableWindow(bEnable);
	m_ctlSpinStrobeDelay.EnableWindow(bEnable);
	m_ctlSpinStrobeWidth.EnableWindow(bEnable);
	GetDlgItem(IDC_EDIT_STROBE_DELAY)->EnableWindow(bEnable);
	GetDlgItem(IDC_EDIT_STROBE_WIDTH)->EnableWindow(bEnable);
}

void CTapCameraCtrl::EnableSymmetry(BOOL bEnable, const INFO_DEFSYMMETRY* pstDefSymmetry)
{
	if (bEnable && pstDefSymmetry)
	{
		GetDlgItem(IDC_CHECK_SYMMETRY_X)->EnableWindow(pstDefSymmetry->m_bSupportHorizontal);
		GetDlgItem(IDC_CHECK_SYMMETRY_Y)->EnableWindow(pstDefSymmetry->m_bSupportVertical);
	}
	else
	{
		GetDlgItem(IDC_CHECK_SYMMETRY_X)->EnableWindow(bEnable);
		GetDlgItem(IDC_CHECK_SYMMETRY_Y)->EnableWindow(bEnable);
	}
}

void CTapCameraCtrl::EnableRoi(BOOL bEnable)
{
	GetDlgItem(IDC_EDIT_ROI_X)->EnableWindow(bEnable);
	GetDlgItem(IDC_EDIT_ROI_Y)->EnableWindow(bEnable);
	GetDlgItem(IDC_EDIT_ROI_WIDTH)->EnableWindow(bEnable);
	GetDlgItem(IDC_EDIT_ROI_HEIGHT)->EnableWindow(bEnable);

	GetDlgItem(IDC_BTN_ROI_QUART)->EnableWindow(bEnable);
	GetDlgItem(IDC_BTN_ROI_HALF)->EnableWindow(bEnable);
	GetDlgItem(IDC_BTN_ROI_FULL)->EnableWindow(bEnable);
	GetDlgItem(IDC_BTN_ROI_CENTER)->EnableWindow(bEnable);

	GetDlgItem(IDC_BTN_ROI)->EnableWindow(bEnable);
}

void CTapCameraCtrl::EnableUserset(BOOL bEnable, const INFO_DEFUSERSET* pstDefUserset)
{
	m_ctlUserset.EnableWindow(bEnable);
	GetDlgItem(IDC_BTN_USERSET_LOAD)->EnableWindow(bEnable);
	if (0 == m_ctlUserset.GetCurSel())
		GetDlgItem(IDC_BTN_USERSET_SAVE)->EnableWindow(FALSE);
	else
		GetDlgItem(IDC_BTN_USERSET_SAVE)->EnableWindow(bEnable);

	//GetDlgItem(IDC_BTN_USERSET_FILELOAD)->EnableWindow(bEnable);
	//GetDlgItem(IDC_BTN_USERSET_FILESAVE)->EnableWindow(bEnable);
	//GetDlgItem(IDC_BTN_USERSET_FILELOAD)->EnableWindow(FALSE);
	//GetDlgItem(IDC_BTN_USERSET_FILESAVE)->EnableWindow(FALSE);

	if (pstDefUserset)
	{
		m_ctlStartupUserset.EnableWindow(pstDefUserset->m_bSupportStartup);
		GetDlgItem(IDC_BTN_USERSET_APPLY)->EnableWindow(pstDefUserset->m_bSupportStartup);
	}
	else
	{
		m_ctlStartupUserset.EnableWindow(bEnable);
		GetDlgItem(IDC_BTN_USERSET_APPLY)->EnableWindow(bEnable);
	}

}

void CTapCameraCtrl::SetGain1(int nVal)
{
	UpdateValue(IDC_EDIT_CAMGAIN1, nVal);
	m_ctlSliderGain1.SetPos(nVal);
}
void CTapCameraCtrl::SetGain2(int nVal)
{
	UpdateValue(IDC_EDIT_CAMGAIN2, nVal);
	m_ctlSliderGain2.SetPos(nVal);
}
void CTapCameraCtrl::SetExposure(int nVal)
{
	UpdateValue(IDC_EDIT_CAMEXPOSURE, nVal);
	m_ctlSliderExposure.SetPos(nVal);
}
void CTapCameraCtrl::SetFramerate(int nVal)
{
	UpdateValue(IDC_EDIT_CAMFPS, nVal);
	m_ctlSliderFps.SetPos(nVal);
}
void CTapCameraCtrl::SetStartupUserset(int nVal)
{
	m_ctlStartupUserset.SetCurSel(nVal);
}
void CTapCameraCtrl::SetTrigger(INFO_TRIGGER_PARA stParam)
{
	// MODE   - 0: off,  1: on
	// SOURCE - 0: Line, 1: SW Trigger

	if (TRIGGER_ON == stParam.nTriggerMode)
		((CButton*)GetDlgItem(IDC_CHECK_TRIGGERENABLE))->SetCheck(BST_CHECKED);
	else //if (TRIGGER_OFF==stParam.nTriggerMode)
		((CButton*)GetDlgItem(IDC_CHECK_TRIGGERENABLE))->SetCheck(BST_UNCHECKED);

	if (TYPE_NETWORK_GIGE == m_stDefDev.m_eNetwork)
	{
		m_ctlTriggerType.SetCurSel(0);
		m_ctlTriggerPolarity.SetCurSel(stParam.nTriggerTypePolarity);
	}
	else if (TYPE_NETWORK_BASLER == m_stDefDev.m_eNetwork)
	{
		m_ctlTriggerType.SetCurSel(0);
		m_ctlTriggerPolarity.SetCurSel(stParam.nTriggerTypePolarity);
	}
	else if (TYPE_NETWORK_USB == m_stDefDev.m_eNetwork || TYPE_NETWORK_CAMERALINK == m_stDefDev.m_eNetwork)
	{
		if (TRIGGER_EDGE_NEGATIVE == stParam.nTriggerTypePolarity || TRIGGER_EDGE_POSITIVE == stParam.nTriggerTypePolarity)
		{
			m_ctlTriggerType.SetCurSel(0);
			m_ctlTriggerPolarity.SetCurSel(stParam.nTriggerTypePolarity);
		}
		else if (TRIGGER_LEVEL_NEGATIVE == stParam.nTriggerTypePolarity || TRIGGER_LEVEL_POSITIVE == stParam.nTriggerTypePolarity)
		{
			m_ctlTriggerType.SetCurSel(1);
			m_ctlTriggerPolarity.SetCurSel(stParam.nTriggerTypePolarity - 2);
		}
	}
	else
	{
		m_ctlTriggerType.SetCurSel(0);
		m_ctlTriggerPolarity.SetCurSel(0);
	}

	m_ctlTriggerSource.SetCurSel(stParam.nTriggerSource);
	if (TRIGGER_SRC_SW == stParam.nTriggerSource)
	{
		m_ctlTriggerType.EnableWindow(TRUE);
		m_ctlTriggerPolarity.EnableWindow(TRUE);

		GetDlgItem(IDC_BTN_TRIGGER_EXE)->EnableWindow(TRUE);	// SW Trigger
	}
	else //if (TRIGGER_SRC_LINE == stParam.nTriggerSource)
	{
		m_ctlTriggerType.EnableWindow(TRUE);
		m_ctlTriggerPolarity.EnableWindow(TRUE);

		GetDlgItem(IDC_BTN_TRIGGER_EXE)->EnableWindow(FALSE);	// Line Trigger
	}

	int nTriggerDelay = stParam.nTriggerDelay;
	if (m_stDefDev.m_stDefTrigger.m_stDelayRange.m_nFrom > nTriggerDelay)
		nTriggerDelay = m_stDefDev.m_stDefTrigger.m_stDelayRange.m_nFrom;

	UpdateValue(IDC_EDIT_TRIGGER_DELAY, nTriggerDelay);

	if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_TRIGGERENABLE))->GetCheck())
		EnableTrigger(TRUE);
	else
		EnableTrigger(FALSE);


	if (TRIGGER_ON == stParam.nTriggerMode && TRIGGER_SRC_SW == stParam.nTriggerSource)
		GetDlgItem(IDC_BTN_TIMEOUT)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_BTN_TIMEOUT)->EnableWindow(FALSE);

}
void CTapCameraCtrl::SetStrobe(INFO_STROBE_PARA stParam)
{
	// MODE   - 0: off,  1: on

	if (STROBE_ON == stParam.nStrobeMode)
		((CButton*)GetDlgItem(IDC_CHECK_STROBEENABLE))->SetCheck(BST_CHECKED);
	else //if (STROBE_OFF==stParam.nStrobeMode)
		((CButton*)GetDlgItem(IDC_CHECK_STROBEENABLE))->SetCheck(BST_UNCHECKED);

	m_ctlStrobeSync.SetCurSel(stParam.nStrobeSync);
	m_ctlStrobePolarity.SetCurSel(stParam.nStrobePolarity);

	UpdateValue(IDC_EDIT_STROBE_DELAY, stParam.nStrobeDelay);
	UpdateValue(IDC_EDIT_STROBE_WIDTH, stParam.nStrobeWidth);

	if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_STROBEENABLE))->GetCheck())
		EnableStrobe(TRUE);
	else
		EnableStrobe(FALSE);


}
void CTapCameraCtrl::SetRoi(INFO_ROI_PARA stParam)
{
	TCHAR szResolution[128] = { 0, };
	CUtil::StringFormat(szResolution, 128, _T("%d x %d"), stParam.nMaxWidth, stParam.nMaxHeight);

	m_ctlStaticRoiInfo.SetText(szResolution, DT_LEFT | DT_VCENTER | DT_CENTER | DT_SINGLELINE);

	UpdateValue(IDC_EDIT_ROI_X, stParam.nXstart);
	UpdateValue(IDC_EDIT_ROI_Y, stParam.nYstart);

	UpdateValue(IDC_EDIT_ROI_WIDTH, stParam.nWidth);
	UpdateValue(IDC_EDIT_ROI_HEIGHT, stParam.nHeight);

	m_dlgRoi.SetRoi(&stParam);

}

void CTapCameraCtrl::SetSymmetry(int nVal)
{
	if (0x01 & nVal)
		((CButton*)GetDlgItem(IDC_CHECK_SYMMETRY_X))->SetCheck(BST_CHECKED);
	else
		((CButton*)GetDlgItem(IDC_CHECK_SYMMETRY_X))->SetCheck(BST_UNCHECKED);

	if ((0x01 << 1) &nVal)
		((CButton*)GetDlgItem(IDC_CHECK_SYMMETRY_Y))->SetCheck(BST_CHECKED);
	else
		((CButton*)GetDlgItem(IDC_CHECK_SYMMETRY_Y))->SetCheck(BST_UNCHECKED);
}

void CTapCameraCtrl::GetGain1(int& nVal)
{
	nVal = GetValue(IDC_EDIT_CAMGAIN1);
}
void CTapCameraCtrl::GetGain2(int& nVal)
{
	nVal = GetValue(IDC_EDIT_CAMGAIN2);
}
void CTapCameraCtrl::GetExposure(int& nVal)
{
	nVal = GetValue(IDC_EDIT_CAMEXPOSURE);
}
void CTapCameraCtrl::GetFramerate(int& nVal)
{
	nVal = GetValue(IDC_EDIT_CAMFPS);
}

void CTapCameraCtrl::GetTrigger(INFO_TRIGGER_PARA& stParam)
{
	// MODE   - 0: off,  1: on
	// SOURCE - 0: Line, 1: SW Trigger

	if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_TRIGGERENABLE))->GetCheck())
		stParam.nTriggerMode = TRIGGER_ON;
	else
		stParam.nTriggerMode = TRIGGER_OFF;

	stParam.nTriggerSource = m_ctlTriggerSource.GetCurSel();

	if (TYPE_NETWORK_GIGE == m_stDefDev.m_eNetwork)
	{
		stParam.nTriggerTypePolarity = m_ctlTriggerPolarity.GetCurSel();
	}
	else if (TYPE_NETWORK_BASLER == m_stDefDev.m_eNetwork)
	{
		stParam.nTriggerTypePolarity = m_ctlTriggerPolarity.GetCurSel();
	}
	else if (TYPE_NETWORK_USB == m_stDefDev.m_eNetwork ||
		TYPE_NETWORK_CAMERALINK == m_stDefDev.m_eNetwork)
	{
		const int nType = m_ctlTriggerType.GetCurSel();
		const int nPolarity = m_ctlTriggerPolarity.GetCurSel();
		if (1 == nType)
			stParam.nTriggerTypePolarity = nPolarity + 2;
		else
			stParam.nTriggerTypePolarity = nPolarity;
	}


	stParam.nTriggerDelay = GetValue(IDC_EDIT_TRIGGER_DELAY);

}
void CTapCameraCtrl::GetStrobe(INFO_STROBE_PARA& stParam)
{
	if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_STROBEENABLE))->GetCheck())
		stParam.nStrobeMode = STROBE_ON;
	else
		stParam.nStrobeMode = STROBE_OFF;

	stParam.nStrobeSync = m_ctlStrobeSync.GetCurSel();
	stParam.nStrobePolarity = m_ctlStrobePolarity.GetCurSel();
	stParam.nStrobeWidth = GetValue(IDC_EDIT_STROBE_WIDTH);
	stParam.nStrobeDelay = GetValue(IDC_EDIT_STROBE_DELAY);

}
void CTapCameraCtrl::GetRoi(INFO_ROI_PARA& stParam)
{
	stParam.nXstart = GetValue(IDC_EDIT_ROI_X);
	stParam.nYstart = GetValue(IDC_EDIT_ROI_Y);
	stParam.nWidth = GetValue(IDC_EDIT_ROI_WIDTH);
	stParam.nHeight = GetValue(IDC_EDIT_ROI_HEIGHT);
}

void CTapCameraCtrl::GetSymmetry(int& nVal)
{
	if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_SYMMETRY_X))->GetCheck())
		nVal = 0x01;
	if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_SYMMETRY_Y))->GetCheck())
		nVal |= 0x01 << 1;
}

BOOL CTapCameraCtrl::SendTriggerCommand()
{
	INFO_TRIGGER_PARA stTrigger;
	memset(&stTrigger, 0x00, sizeof(INFO_TRIGGER_PARA));

	GetTrigger(stTrigger);

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	StopnWaitCamera();

	BOOL bResult = pCaptureManager->SetTriggerMode(m_stDefDev.m_eNetwork, m_nProcID, stTrigger);
	pCaptureManager->Start(m_stDefDev.m_eNetwork, m_nProcID);

	return bResult;
}

BOOL CTapCameraCtrl::SendStrobeCommand()
{
	INFO_STROBE_PARA stStrobe;
	memset(&stStrobe, 0x00, sizeof(INFO_STROBE_PARA));

	GetStrobe(stStrobe);

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	BOOL bResult = pCaptureManager->SetStrobeMode(m_stDefDev.m_eNetwork, m_nProcID, stStrobe);

	return bResult;
}

BOOL CTapCameraCtrl::SendRoiCommand()
{
	INFO_ROI_PARA stRoi;
	memset(&stRoi, 0x00, sizeof(INFO_ROI_PARA));
	this->GetRoi(stRoi);

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	StopnWaitCamera();

	BOOL bResult = pCaptureManager->SetROI(m_stDefDev.m_eNetwork, m_nProcID, stRoi);
	pCaptureManager->Start(m_stDefDev.m_eNetwork, m_nProcID);

	return bResult;
}

void CTapCameraCtrl::Start()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	pCaptureManager->Start(m_stDefDev.m_eNetwork, m_nProcID);
}

void CTapCameraCtrl::Stop()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	pCaptureManager->Stop(m_stDefDev.m_eNetwork, m_nProcID);
}

void CTapCameraCtrl::StopnWaitCamera()
{
	int loop = 500;
	if (TYPE_NETWORK_NONE == m_stDefDev.m_eNetwork || 0 > m_nProcID)
		return;

	Stop();
	if (TYPE_NETWORK_USB == m_stDefDev.m_eNetwork)
		loop = 100;
	else if (TYPE_NETWORK_CAMERALINK == m_stDefDev.m_eNetwork)
		loop = 100;

	CUtil::WaitnSleep(loop);
}
