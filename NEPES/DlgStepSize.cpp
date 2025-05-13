// DlgStep01.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "DlgStepSize.h"
#include "DlgCalibrate.h"
#include "DlgSizeGain.h"
#include "DlgStrobe.h"
#include "DlgPasswd.h"
#include "afxdialogex.h"

#include "CaptureManager.h"
#include "stringres.h"

#include "Util/Util.h"
#include <opencv/highgui.h>

const CString CDlgStepSize::m_strFindLineName[TYPE_FINDLINE_MAX] = {
	_T("Metal - Top"),
	_T("Metal - Right"),
	_T("Metal - Bottom"),
	_T("Metal - Left"),

	_T("Tape - Left Top"),
	_T("Tape - Left Middle"),
	_T("Tape - Left Bottom"),

	_T("Tape - Center Top"),
	_T("Tape - Center Top Left"),
	_T("Tape - Center Top Right"),
	_T("Tape - Center Bottom"),
	_T("Tape - Center Bottom Left"),
	_T("Tape - Center Bottom Right"),

	_T("Tape - Right Top"),
	_T("Tape - Right Middle"),
	_T("Tape - Right Bottom"),
};

// CDlgStepSize dialog

IMPLEMENT_DYNAMIC(CDlgStepSize, CDialogEx)

CDlgStepSize::CDlgStepSize(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgStepSize::IDD, pParent)
	, m_iPolarity(0)
	, m_iLookFor(0)
	, m_iStrengthThreshold(0)
	, m_iSampling(0)
	, m_iKernelSize(0)
	, m_bSearchAngle(FALSE)
	, m_iMinAngle(0)
	, m_iMaxAngle(0)
	, m_iDistanceThreshold(0)
	, m_iDirection(0)
{
	m_eCameraPos = TYPE_CAMERAPOS_NONE;
	memset(m_pstFindLineParameter, 0, sizeof(INFO_FINDLINE_PARAMETER) * TYPE_FINDLINE_MAX);
}

CDlgStepSize::~CDlgStepSize()
{
}

void CDlgStepSize::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_FINDLINE, m_ctlListFindLine);
	DDX_Control(pDX, IDC_COMBO_DIRECTION, m_ctlDirection);
	DDX_Control(pDX, IDC_COMBO_POLARITY, m_ctlPolarity);
	DDX_Control(pDX, IDC_COMBO_LOOKFOR, m_ctlLookFor);
	DDX_Control(pDX, IDC_COMBO_SELECTSHOTSTEP, m_ctlSelectShotStep);   //7-23 추가
	DDX_Control(pDX, IDC_SPIN_THRESHOLD, m_ctlSpenStrength);
	DDX_Control(pDX, IDC_SPIN_SAMPLE, m_ctlSpinSample);
	DDX_Control(pDX, IDC_SPIN_KERNEL, m_ctlSpinKernel);
	DDX_Control(pDX, IDC_SPIN_MINANGLE, m_ctlSpinMinAngle);
	DDX_Control(pDX, IDC_SPIN_MAXANGLE, m_ctlSpinMaxAngle);
	DDX_Control(pDX, IDC_SPIN_DISTANCE, m_ctlSpinDistance);
	DDX_Control(pDX, IDC_LIST_SIZERESULT, m_ctlListSizeResult);
	DDX_CBIndex(pDX, IDC_COMBO_DIRECTION, m_iDirection);
	DDX_CBIndex(pDX, IDC_COMBO_POLARITY, m_iPolarity);
	DDX_CBIndex(pDX, IDC_COMBO_LOOKFOR, m_iLookFor);
	DDX_CBIndex(pDX, IDC_COMBO_SELECTSHOTSTEP, m_iSelectShotStep);
	DDX_Text(pDX, IDC_EDIT_THRESHOLD, m_iStrengthThreshold);
	DDX_Text(pDX, IDC_EDIT_SAMPLE, m_iSampling);
	DDX_Text(pDX, IDC_EDIT_KERNEL, m_iKernelSize);
	DDX_Check(pDX, IDC_CHECK_SEARCHANGLE, m_bSearchAngle);
	DDX_Text(pDX, IDC_EDIT_MINANGLE, m_iMinAngle);
	DDX_Text(pDX, IDC_EDIT_MAXANGLE, m_iMaxAngle);
	DDX_Text(pDX, IDC_EDIT_DISTANCE, m_iDistanceThreshold);
	
}

BOOL CDlgStepSize::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (IDOK == wParam)
	{
		return TRUE;
	}
	return CDialogEx::OnCommand(wParam, lParam);
}

BOOL CDlgStepSize::PreTranslateMessage(MSG* pMsg)
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

BOOL CDlgStepSize::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_ctlListFindLine.DeleteAllItems();
	m_ctlListFindLine.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_ctlListFindLine.InsertColumn(0, _T("NO"), LVCFMT_LEFT, 30, -1);
	m_ctlListFindLine.InsertColumn(1, _T("NAME"), LVCFMT_LEFT, 120, -1);

	m_ctlDirection.AddString(_T("Left to Right"));
	m_ctlDirection.AddString(_T("Right to Left"));
	m_ctlDirection.AddString(_T("Up to Down"));
	m_ctlDirection.AddString(_T("Down to Up"));
	m_ctlDirection.SetCurSel(0);

	m_ctlPolarity.AddString(_T("Bright to Dark"));
	m_ctlPolarity.AddString(_T("All"));
	m_ctlPolarity.AddString(_T("Dark to Bright"));
	m_ctlPolarity.SetCurSel(0);

	m_ctlLookFor.AddString(_T("FIRST"));
	m_ctlLookFor.AddString(_T("BEST"));
	m_ctlLookFor.SetCurSel(0);

	m_ctlSelectShotStep.AddString(_T("First"));
	m_ctlSelectShotStep.AddString(_T("Second"));
	m_ctlSelectShotStep.SetCurSel(0);

	m_ctlSpenStrength.SetRange32(MIN_STRENGTH_THRESHOLD, MAX_STRENGTH_THRESHOLD);
	m_ctlSpinSample.SetRange32(MIN_SAMPLE, MAX_SAMPLE);
	m_ctlSpinKernel.SetRange32(MIN_KERNEL, MAX_KERNEL);
	m_ctlSpinMinAngle.SetRange32(MIN_MINANGLE, MAX_MINANGLE);
	m_ctlSpinMaxAngle.SetRange32(MIN_MAXANGLE, MAX_MAXANGLE);
	m_ctlSpinDistance.SetRange32(MIN_DISTANCE_THRESHOLD, MAX_DISTANCE_THRESHOLD);

	m_ctlSpenStrength.SetPos32(MIN_STRENGTH_THRESHOLD);
	m_ctlSpinSample.SetPos32(MIN_SAMPLE);
	m_ctlSpinKernel.SetPos32(MIN_KERNEL);
	m_ctlSpinMinAngle.SetPos32(MIN_MINANGLE);
	m_ctlSpinMaxAngle.SetPos32(MIN_MAXANGLE);
	m_ctlSpinDistance.SetPos32(MIN_DISTANCE_THRESHOLD);


	BOOL bEnable = FALSE;
	SetEnableFindLine(bEnable);
	
	m_ctlListFindLine.EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_APPLY)->EnableWindow(TRUE);

	CString szNum;
	//CString szRoiName = _T("Rectangle");

	for (int i = 0; i < TYPE_FINDLINE_MAX; i++)
	{
		szNum.Format(_T("%d"), i + 1);

		m_ctlListFindLine.InsertItem(i, szNum);
		m_ctlListFindLine.SetItem(i, 1, LVIF_TEXT, m_strFindLineName[i], 0, 0, 0, NULL);
	}

	m_ctlListSizeResult.DeleteAllItems();
	m_ctlListSizeResult.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_ctlListSizeResult.InsertColumn(0, _T("NAME"), LVCFMT_LEFT, 45, -1);
	m_ctlListSizeResult.InsertColumn(1, _T("RESULT"), LVCFMT_LEFT, 65, -1);

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_OPTION* pstOption = pCaptureManager->GetOption();

	for (int i = 0; i < TYPE_GEOMETRY_DISTANCE_MAX; i++)
	{
		if (i < MAX_GEOMETRY_DISTANCELINE_COUNT)
		{
			m_ctlListSizeResult.InsertItem(i, pstOption->m_stSizeName.m_szName[i]);
		}
		else
		{
			if (i == TYPE_GEOMETRY_DISTANCE_X1X2)
				m_ctlListSizeResult.InsertItem(i, pstOption->m_stSizeName.GetNameX1X2());
			else if (i == TYPE_GEOMETRY_DISTANCE_S1S3)
				m_ctlListSizeResult.InsertItem(i, pstOption->m_stSizeName.GetNameS1S3());
			else if (i == TYPE_GEOMETRY_DISTANCE_M1M2)
				m_ctlListSizeResult.InsertItem(i, pstOption->m_stSizeName.GetNameM1M2());
			// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
			else if (i == TYPE_GEOMETRY_DISTANCE_SS1SS3)
				m_ctlListSizeResult.InsertItem(i, pstOption->m_stSizeName.GetNameSS1SS3());
		}
		m_ctlListSizeResult.SetItem(i, 1, LVIF_TEXT, _T("0.0"), 0, 0, 0, NULL);
	}

	// Update Image
	{
		UpdateImageFromDisplay(TRUE);
	}

	// Update Control
	{
		const INFO_INSPECTION_SIZE* pInspectSize = GetInspectionInfo(0);
		UpdateCtrlStepSize(pInspectSize);
	}

	return TRUE;
}


BEGIN_MESSAGE_MAP(CDlgStepSize, CDialogEx)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_CONTEXTMENU()
	ON_BN_CLICKED(IDC_CHECK_SEARCHANGLE, &CDlgStepSize::OnBnClickedCheckSearchangle)
	ON_BN_CLICKED(IDC_BTN_APPLY, &CDlgStepSize::OnBnClickedBtnApply)
	ON_NOTIFY(NM_THEMECHANGED, IDC_LIST_FINDLINE, &CDlgStepSize::OnNMThemeChangedListFindline)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_KERNEL, &CDlgStepSize::OnDeltaposSpinKernel)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_FINDLINE, &CDlgStepSize::OnLvnItemchangedListFindline)
	ON_BN_CLICKED(IDC_BTN_CALIBRATE, &CDlgStepSize::OnBnClickedBtnCalibrate)
	ON_CBN_SELCHANGE(IDC_COMBO_DIRECTION, &CDlgStepSize::OnParameterControlChange)
	ON_CBN_SELCHANGE(IDC_COMBO_POLARITY, &CDlgStepSize::OnParameterControlChange)
	ON_CBN_SELCHANGE(IDC_COMBO_LOOKFOR, &CDlgStepSize::OnParameterControlChange)
	ON_EN_CHANGE(IDC_EDIT_THRESHOLD, &CDlgStepSize::OnParameterControlChange)
	ON_EN_CHANGE(IDC_EDIT_SAMPLE, &CDlgStepSize::OnParameterControlChange)
	ON_EN_CHANGE(IDC_EDIT_KERNEL, &CDlgStepSize::OnParameterControlChange)
	ON_EN_CHANGE(IDC_EDIT_DISTANCE, &CDlgStepSize::OnParameterControlChange)
	ON_EN_CHANGE(IDC_EDIT_MINANGLE, &CDlgStepSize::OnParameterControlChange)
	ON_EN_CHANGE(IDC_EDIT_MAXANGLE, &CDlgStepSize::OnParameterControlChange)
	ON_BN_CLICKED(IDC_BTN_STROBE, &CDlgStepSize::OnBnClickedBtnStrobe)
	ON_BN_CLICKED(IDC_BTN_GAIN, &CDlgStepSize::OnBnClickedBtnGain)
	ON_CBN_SELCHANGE(IDC_COMBO_SELECTSHOTSTEP, &CDlgStepSize::OnCbnSelchangeComboSelectshotstep)
	// Version 1.3.7.8
END_MESSAGE_MAP()


// CDlgStepSize message handlers
void CDlgStepSize::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CRect rect;
	GetClientRect(&rect);

}

void CDlgStepSize::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	
	this->Invalidate();
}

void CDlgStepSize::OnContextMenu(CWnd* pWnd, CPoint point)
{
	/*//
	CRect rtList;
	m_ctlListFindLine.GetWindowRect(rtList);

	if (rtList.PtInRect(point))
	{
		CMenu Menu;
		Menu.LoadMenu(IDR_MENU_POPUPROI);

		CMenu* pSubMenu = Menu.GetSubMenu(0);
		if (pSubMenu)
		{
			pSubMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
		}
		Menu.DestroyMenu();
	}
	//*/
}

void CDlgStepSize::OnNMThemeChangedListFindline(NMHDR *pNMHDR, LRESULT *pResult)
{
	*pResult = 0;
}

void CDlgStepSize::OnBnClickedCheckSearchangle()
{
	BOOL bEnable = FALSE;
	if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_SEARCHANGLE))->GetCheck())
		bEnable = TRUE;
	SetEnableAngle(bEnable);

	OnParameterControlChange();
}

void CDlgStepSize::OnBnClickedBtnCalibrate()
{
	UpdateData();
	if (!(m_iSelectShotStep == 0 || m_iSelectShotStep == 1))
		return;

	INFO_IMAGE* pRefImage = NULL;
	this->GetParent()->SendMessage(WM_NOTIFY_SEQUENCE_REQUESET, (WPARAM)(&pRefImage), (LPARAM)0);

	const INFO_INSPECTION_SIZE* pstCurInfo = GetInspectionInfo(m_iSelectShotStep);

	CDlgCalibrate dlgCalibrate;
	dlgCalibrate.UpdateCameraPos(m_eCameraPos);
	dlgCalibrate.SetImageSize(pRefImage->m_stFrame.m_dwWidth, pRefImage->m_stFrame.m_dwHeight);
	dlgCalibrate.SetInfoCalibration(&pstCurInfo->m_stCalibration);
	if (IDOK == dlgCalibrate.DoModal())
	{
		UpdateImageFromDisplay();
		Process();
	}
}

void CDlgStepSize::OnBnClickedBtnGain()
{
	UpdateData();
	if (!(m_iSelectShotStep == 0 || m_iSelectShotStep == 1))
		return;

	const INFO_SIZE_GAIN* pstGain = GetSizeGain();
	INFO_IMAGE* pRefImage = NULL;
	this->GetParent()->SendMessage(WM_NOTIFY_SEQUENCE_REQUESET, (WPARAM)(&pRefImage), (LPARAM)0);

	// Version 1.3.7.8
	m_Sample.reset(new CSampleSide());
	CSampleSide tempSample;
	this->GetParent()->SendMessage(WM_NOTIFY_SEQUENCE_REQUESET_FIRST, (WPARAM)(&tempSample), (LPARAM)0);
	m_Sample->CopyFrom(tempSample);

	// Version 1.3.7.1
	UpdateImageFromDisplay(TRUE);

	CDlgSizeGain dlgSizeGain;
	dlgSizeGain.UpdateCameraPos(m_eCameraPos);
	dlgSizeGain.SetInfoSizeGain(pstGain);
	// 이미지 재취득
	//dlgSizeGain.UpdateImage(pRefImage, pRefImageFirst, pRefImageSecond);
	
	
	dlgSizeGain.UpdateResult(&tempSample);
	if (IDOK == dlgSizeGain.DoModal())
	{
		SetSizeGain(&dlgSizeGain.m_stInfoSizeGain);

		Process();
	}
}

void CDlgStepSize::OnBnClickedBtnApply()
{
	UpdateData();
	if (!(m_iSelectShotStep == 0 || m_iSelectShotStep == 1))
		return;

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	{
		SetEnableFindLine(FALSE);
		
		const int nCur = m_ctlListFindLine.GetNextItem(-1, LVNI_SELECTED);

		Log("Apply configuration - Cur: %d", nCur);

		for (int i = 0; i < TYPE_FINDLINE_MAX; i++)
			SetFindLineParameter(m_iSelectShotStep, &m_pstFindLineParameter[i], i);

		UpdateImageFromDisplay();
		Process();
		// TODO: else 루트의 SendMessage는 Process에 없으므로, 구현 방법 검토
		/*INFO_IMAGE* pRefImage = NULL;
		this->GetParent()->SendMessage(WM_NOTIFY_SEQUENCE_REQUESET, (WPARAM)(&pRefImage), (LPARAM)0);
		cv::Mat tmpImg = cv::Mat(pRefImage->m_stFrame.m_dwHeight, pRefImage->m_stFrame.m_dwWidth, CV_8UC3, pRefImage->m_pBuffer, pRefImage->m_stFrame.m_dwPitch);
		cv::Mat matImg = tmpImg.clone();

		// Test run application
		CSampleSide sample;
		sample.m_pRefImage = pRefImage;

		
		//BOOL bResult = pInspection->InspectCamera(m_eCameraPos, m_eStep, sample);
		BOOL bResult = pInspection->InspectCamera(m_eCameraPos, m_eStep, sample, matImg);
		if (bResult)
		{
			LPARAM lParam = NULL;
			lParam = (LPARAM)&sample.m_SizeResult;
			this->GetParent()->SendMessage(WM_NOTIFY_SEQUENCE_EDIT_STEPDONE, (WPARAM)(m_eStep), lParam);

			for (int i = 0; i < TYPE_GEOMETRY_DISTANCE_MAX; i++)
			{
				OUTPUT_DISTANCE *pstDistance = NULL;
				pstDistance = sample.m_SizeResult.m_stDistance;
				if (pstDistance)
				{
					CString str;
					str.Format(_T("%.3f"), pstDistance[i].m_dValue);
					m_ctlListSizeResult.SetItem(i, 1, LVIF_TEXT, str, 0, 0, 0, NULL);
				}
			}
		}
		else
		{
			AfxMessageBox(STR_MSG_FAIL_INSPECTION);

			LPARAM lParam = NULL;
			lParam = (LPARAM)&sample.m_SizeResult;
			this->GetParent()->SendMessage(WM_NOTIFY_SEQUENCE_EDIT_STEPDONE, (WPARAM)(m_eStep), lParam);

			for (int i = 0; i < TYPE_GEOMETRY_DISTANCE_MAX; i++)
			{
				m_ctlListSizeResult.SetItem(i, 1, LVIF_TEXT, _T("0.0"), 0, 0, 0, NULL);
			}
		}*/

		if (-1 < nCur)
		{
			SetEnableFindLine(TRUE);
		}
		else
		{
			SetEnableFindLine(FALSE);
			m_ctlListFindLine.EnableWindow(TRUE);
		}
	}

	/// Update Backup
	{
		UpdateInspectionInfoBackup();
	}
	//*/
}

void CDlgStepSize::SetDefaultValue()
{
	;
}

void CDlgStepSize::UpdateCtrlStepSize(const INFO_INSPECTION_SIZE* pInspectSize)
{
	if (NULL == pInspectSize)
		return;

	Log("Update controls");

	UpdateCtrlStrobe(pInspectSize);

	memcpy(m_pstFindLineParameter, pInspectSize->m_pstFindLineParameter, sizeof(INFO_FINDLINE_PARAMETER) * TYPE_FINDLINE_MAX);

	m_ctlListFindLine.SetItemState(-1, 0, LVIS_SELECTED);
#ifdef DEF_SECONDCAMERA_CHECKSIZE
	OnBnClickedBtnApply();
#else
	if (TYPE_CAMERAPOS_FIRST == m_eCameraPos)
	{
		OnBnClickedBtnApply();
	}
#endif
}

void CDlgStepSize::UpdateCtrlStrobe(const INFO_INSPECTION_SIZE* pInspectSize)
{
	// Strobe Type & Brightness
	{
		CString szStrobe01;

		if (TYPE_STROBE_COXIAL == pInspectSize->m_pstStepStrobe[0].m_eStrobeType)
			szStrobe01.Format(_T("%s (%d)"), STR_STROBE_COAXIAL, pInspectSize->m_pstStepStrobe[0].m_nStrobeBrightness);
		else if (TYPE_STROBE_RING == pInspectSize->m_pstStepStrobe[0].m_eStrobeType)
			szStrobe01.Format(_T("%s (%d)"), STR_STROBE_RING, pInspectSize->m_pstStepStrobe[0].m_nStrobeBrightness);
		else if (TYPE_STROBE_BAR == pInspectSize->m_pstStepStrobe[0].m_eStrobeType)
			szStrobe01.Format(_T("%s (%d)"), STR_STROBE_BAR, pInspectSize->m_pstStepStrobe[0].m_nStrobeBrightness);
		else
			szStrobe01.Format(_T("%s"), STR_STROBE_OFF);
		GetDlgItem(IDC_EDIT_STROBE01)->SetWindowText(szStrobe01);
	}
	{
		CString szStrobe02;
		if (TYPE_STROBE_COXIAL == pInspectSize->m_pstStepStrobe[1].m_eStrobeType)
			szStrobe02.Format(_T("%s (%d)"), STR_STROBE_COAXIAL, pInspectSize->m_pstStepStrobe[1].m_nStrobeBrightness);
		else if (TYPE_STROBE_RING == pInspectSize->m_pstStepStrobe[1].m_eStrobeType)
			szStrobe02.Format(_T("%s (%d)"), STR_STROBE_RING, pInspectSize->m_pstStepStrobe[1].m_nStrobeBrightness);
		else if (TYPE_STROBE_BAR == pInspectSize->m_pstStepStrobe[1].m_eStrobeType)
			szStrobe02.Format(_T("%s (%d)"), STR_STROBE_BAR, pInspectSize->m_pstStepStrobe[1].m_nStrobeBrightness);
		else
			szStrobe02.Format(_T("%s"), STR_STROBE_OFF);
		GetDlgItem(IDC_EDIT_STROBE02)->SetWindowText(szStrobe02);
	}
}

int CDlgStepSize::GetSelectedShotStep()
{
	UpdateData();
	return m_iSelectShotStep;
}

void CDlgStepSize::SetEnableFindLine(BOOL bEnable)
{
	m_ctlListFindLine.EnableWindow(bEnable);

	GetDlgItem(IDC_COMBO_DIRECTION)->EnableWindow(bEnable);
	GetDlgItem(IDC_COMBO_POLARITY)->EnableWindow(bEnable);
	GetDlgItem(IDC_COMBO_LOOKFOR)->EnableWindow(bEnable);
	GetDlgItem(IDC_EDIT_THRESHOLD)->EnableWindow(bEnable);
	GetDlgItem(IDC_SPIN_THRESHOLD)->EnableWindow(bEnable);

	GetDlgItem(IDC_EDIT_SAMPLE)->EnableWindow(bEnable);
	GetDlgItem(IDC_SPIN_SAMPLE)->EnableWindow(bEnable);

	GetDlgItem(IDC_EDIT_KERNEL)->EnableWindow(bEnable);
	GetDlgItem(IDC_SPIN_KERNEL)->EnableWindow(bEnable);

	GetDlgItem(IDC_CHECK_SEARCHANGLE)->EnableWindow(bEnable);

	GetDlgItem(IDC_EDIT_DISTANCE)->EnableWindow(bEnable);
	GetDlgItem(IDC_SPIN_DISTANCE)->EnableWindow(bEnable);

	GetDlgItem(IDC_BTN_APPLY)->EnableWindow(bEnable);
	
	BOOL bEnableAngle = FALSE;
	if (bEnable && BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_SEARCHANGLE))->GetCheck())
		bEnableAngle = TRUE;
	SetEnableAngle(bEnableAngle);
}

void CDlgStepSize::SetEnableAngle(BOOL bEnable)
{
	GetDlgItem(IDC_EDIT_MINANGLE)->EnableWindow(bEnable);
	GetDlgItem(IDC_EDIT_MAXANGLE)->EnableWindow(bEnable);

	GetDlgItem(IDC_SPIN_MINANGLE)->EnableWindow(bEnable);
	GetDlgItem(IDC_SPIN_MINANGLE)->EnableWindow(bEnable);

}

void CDlgStepSize::OnDeltaposSpinKernel(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	*pResult = 0;
	
	int nPos = m_ctlSpinKernel.GetPos32();
	if (0 > pNMUpDown->iDelta)
	{
		nPos -= 1;
	}
	else
	{
		nPos += 1;
	}
	m_ctlSpinKernel.SetPos32(nPos);
}


void CDlgStepSize::OnLvnItemchangedListFindline(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	*pResult = 0;

	BOOL bEnable = FALSE;

	const int nCur = m_ctlListFindLine.GetNextItem(-1, LVNI_SELECTED);
	if (-1 < nCur)
	{
		SetControlFindLineParameter(&m_pstFindLineParameter[nCur]);

		bEnable = TRUE;
	}
	SetEnableFindLine(bEnable);
	m_ctlListFindLine.EnableWindow(TRUE);


	// Notify
	CWnd* pWnd = GetParent();
	if (pWnd)
	{
		pWnd->SendMessage(WM_NOTIFY_STEPSIZE_ROI_SELECTED, nCur, 0);
	}
}



void CDlgStepSize::UpdateCameraPos(TYPE_CAMERAPOS ePos)
{
	m_eCameraPos = ePos;
}

void CDlgStepSize::UpdateSelectedRoiPos(const int nCur, const INFO_FINDLINE_ROI* pROI)
{
	UpdateData();
	if (!(m_iSelectShotStep == 0 || m_iSelectShotStep == 1))
		return;
	if (0 > nCur || TYPE_FINDLINE_MAX <= nCur || NULL == pROI)
		return;

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	// Update Information
	INFO_INSPECTION_SIZE stInspectionSize;
	const INFO_INSPECTION_SIZE* pstCurInfo = GetInspectionInfo(m_iSelectShotStep);
	memcpy(&stInspectionSize, pstCurInfo, sizeof(INFO_INSPECTION_SIZE));

	{
		SetEnableFindLine(FALSE);

		Log("Update ROI - Cur: %d");

		stInspectionSize.m_pstFindLineROI[nCur] = *pROI;

		INFO_IMAGE* pRefImage = NULL;
		this->GetParent()->SendMessage(WM_NOTIFY_SEQUENCE_REQUESET, (WPARAM)(&pRefImage), (LPARAM)0);

		SetFindLineROI(m_iSelectShotStep, &stInspectionSize.m_pstFindLineROI[nCur], pRefImage, nCur);

		UpdateImageFromDisplay();
		Process();

		SetEnableFindLine(TRUE);
	}
}

const INFO_INSPECTION_SIZE* CDlgStepSize::GetInspectionInfo(const int iStepIndex)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	if (iStepIndex == 0)
	{
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
		CStepSize* pStepSize = dynamic_cast<CStepSize*>(pStep);
		if (pStepSize)
		{
			const INFO_INSPECTION_SIZE* pSizeInfo = pStepSize->GetInformation();
			return pSizeInfo;
		}
	}
	else if (iStepIndex == 1)
	{
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStepSecond);
		CStepSizeSecond* pStepSize = dynamic_cast<CStepSizeSecond*>(pStep);
		if (pStepSize)
		{
			const INFO_INSPECTION_SIZE* pSizeInfo = pStepSize->GetInformation();
			return pSizeInfo;
		}
	}
		
	return NULL;
}

const INFO_SIZE_GAIN* CDlgStepSize::GetSizeGain()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();
	CInspectionCamera* pCamera = pInspection->GetInspectionCamera(m_eCameraPos);

	const INFO_SIZE_GAIN* pGain = NULL;
	if (pCamera)
	{
		CStepSizeCalculation* pStepCalc = pCamera->GetStepSizeCalc();
		if (pStepCalc)
		{
			pGain = &pStepCalc->GetInformation()->m_stSizeGain;
		}
	}

	return pGain;
}

BOOL CDlgStepSize::SetInspectionInfo(const int iStepIndex, const INFO_INSPECTION_SIZE* pstInfo)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	BOOL bResult = FALSE;
	if (iStepIndex == 0)
	{
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
		CStepSize* pStepSize = dynamic_cast<CStepSize*>(pStep);
		if (pStepSize)
		{
			bResult = pStepSize->SetInformation(pstInfo);
		}
	}
	else if (iStepIndex == 1)
	{
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStepSecond);
		CStepSizeSecond* pStepSize = dynamic_cast<CStepSizeSecond*>(pStep);
		if (pStepSize)
		{
			bResult = pStepSize->SetInformation(pstInfo);
		}
	}


	/// Update Backup
	{
		UpdateInspectionInfoBackup();
	}
	//*/
	return bResult;
}

void CDlgStepSize::UpdateInspectionInfoBackup()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	INFO_INSPECTION stChanged;
	memset(&stChanged, 0x00, sizeof(INFO_INSPECTION));

	CStepSize* pStepSize = dynamic_cast<CStepSize*>(pInspection->GetInsectionStep(m_eCameraPos, TYPE_STEP_001));
	CStepStain* pStepStain = dynamic_cast<CStepStain*>(pInspection->GetInsectionStep(m_eCameraPos, TYPE_STEP_002));
	CStepDiffer* pStepDiffer = dynamic_cast<CStepDiffer*>(pInspection->GetInsectionStep(m_eCameraPos, TYPE_STEP_003));
	CStepBubble* pStepBubble = dynamic_cast<CStepBubble*>(pInspection->GetInsectionStep(m_eCameraPos, TYPE_STEP_004));
	CStepScratch* pStepScratch = dynamic_cast<CStepScratch*>(pInspection->GetInsectionStep(m_eCameraPos, TYPE_STEP_005));
	CStepStamp* pStepStamp = dynamic_cast<CStepStamp*>(pInspection->GetInsectionStep(m_eCameraPos, TYPE_STEP_006));
	CStepSizeSecond* pStepSizeSecond = dynamic_cast<CStepSizeSecond*>(pInspection->GetInsectionStep(m_eCameraPos, TYPE_STEP_007));

	CStepSizeCalculation* pStepCalc = NULL;
	CInspectionCamera* pCamera = pInspection->GetInspectionCamera(m_eCameraPos);
	if (pCamera)
	{
		pStepCalc = pCamera->GetStepSizeCalc();
	}

	if (pStepSize && pStepStain && pStepDiffer && pStepBubble && pStepScratch && pStepStamp && pStepSizeSecond
		&& pStepCalc)
	{
		stChanged.m_bInit = TRUE;
		stChanged.m_stSize = *pStepSize->GetInformation();
		stChanged.m_stStain = *pStepStain->GetInformation();
		stChanged.m_stDiffer = *pStepDiffer->GetInformation();
		stChanged.m_stBubble = *pStepBubble->GetInformation();
		stChanged.m_stScratch = *pStepScratch->GetInformation();
		stChanged.m_stStamp = *pStepStamp->GetInformation();
		stChanged.m_stSizeSecond = *pStepSizeSecond->GetInformation();
		stChanged.m_stSizeCalc = *pStepCalc->GetInformation();

		pCaptureManager->UpdateInspection(m_eCameraPos, NULL, &stChanged);
	}
}

BOOL CDlgStepSize::SetFindLineROI(const int iStepIndex, const INFO_FINDLINE_ROI* pstInfo, const INFO_IMAGE* pRefImage, const int iLineIndex)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	BOOL bResult = FALSE;
	if (iStepIndex == 0)
	{
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
		CStepSize* pStepSize = dynamic_cast<CStepSize*>(pStep);
		if (pStepSize)
		{
			bResult = pStepSize->SetInfoFindLineROI(pstInfo, pRefImage, iLineIndex);
		}
	}
	else if (iStepIndex == 1)
	{
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStepSecond);
		CStepSizeSecond* pStepSize = dynamic_cast<CStepSizeSecond*>(pStep);
		if (pStepSize)
		{
			bResult = pStepSize->SetInfoFindLineROI(pstInfo, pRefImage, iLineIndex);
		}
	}
	return bResult;
}

BOOL CDlgStepSize::SetFindLineParameter(const int iStepIndex, const INFO_FINDLINE_PARAMETER* pstInfo, const int iLineIndex)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	BOOL bResult = FALSE;
	if (iStepIndex == 0)
	{
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
		CStepSize* pStepSize = dynamic_cast<CStepSize*>(pStep);
		if (pStepSize)
		{
			bResult = pStepSize->SetInfoFindLineParameter(pstInfo, iLineIndex);
		}
	}
	else if (iStepIndex == 1)
	{
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStepSecond);
		CStepSizeSecond* pStepSize = dynamic_cast<CStepSizeSecond*>(pStep);
		if (pStepSize)
		{
			bResult = pStepSize->SetInfoFindLineParameter(pstInfo, iLineIndex);
		}
	}

	return bResult;
}

BOOL CDlgStepSize::SetSizeGain(const INFO_SIZE_GAIN* pstInfo)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();
	CInspectionCamera* pCamera = pInspection->GetInspectionCamera(m_eCameraPos);

	BOOL bResult = FALSE;
	if (pCamera)
	{
		CStepSizeCalculation* pStepCalc = pCamera->GetStepSizeCalc();
		if (pStepCalc)
		{
			bResult = pStepCalc->SetSizeGain(pstInfo);
		}
	}
	return bResult;
}

void CDlgStepSize::SetControlFindLineParameter(const INFO_FINDLINE_PARAMETER* pstInfo)
{
	if (NULL == pstInfo)
		return;
	
	// Set Control Values
	this->m_iDirection = pstInfo->m_iDirection;
	this->m_iPolarity = pstInfo->m_iPolarity;
	this->m_iLookFor = pstInfo->m_iLookFor;
	this->m_iStrengthThreshold = pstInfo->m_iStrengthThreshold;
	this->m_iSampling = pstInfo->m_iSampling;
	this->m_iKernelSize = pstInfo->m_iKernelSize;
	this->m_bSearchAngle = pstInfo->m_bSearchAngle;
	this->m_iMinAngle = pstInfo->m_iMinAngle;
	this->m_iMaxAngle = pstInfo->m_iMaxAngle;
	this->m_iDistanceThreshold = pstInfo->m_iDistanceThreshold;

	UpdateData(FALSE);
}

INFO_FINDLINE_PARAMETER CDlgStepSize::GetControlFindLineParameter()
{
	INFO_FINDLINE_PARAMETER stInfo;
	memset(&stInfo, 0x00, sizeof(INFO_FINDLINE_PARAMETER));

	UpdateData();
	ModifyParams();

	// Get Control Values
	stInfo.m_iDirection = this->m_iDirection;
	stInfo.m_iPolarity = this->m_iPolarity;
	stInfo.m_iLookFor = this->m_iLookFor;
	stInfo.m_iStrengthThreshold = this->m_iStrengthThreshold;
	stInfo.m_iSampling = this->m_iSampling;
	stInfo.m_iKernelSize = this->m_iKernelSize;
	stInfo.m_bSearchAngle = this->m_bSearchAngle;
	stInfo.m_iMinAngle = this->m_iMinAngle;
	stInfo.m_iMaxAngle = this->m_iMaxAngle;
	stInfo.m_iDistanceThreshold = this->m_iDistanceThreshold;

	UpdateData(FALSE);

	return stInfo;
}

int CDlgStepSize::GetEditValue(const DWORD dwCtrlID)
{
	CString szValue;
	GetDlgItem(dwCtrlID)->GetWindowText(szValue);

	int nValue = CUtil::StringToInt((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	return nValue;
}

void CDlgStepSize::SetEditValue(const DWORD dwCtrlID, int nValue)
{
	CString szValue;
	szValue.Format(_T("%d"), nValue);
	GetDlgItem(dwCtrlID)->SetWindowText(szValue);
}

void CDlgStepSize::UpdateImageFromDisplay(BOOL both)
{
	if (!(m_iSelectShotStep == 0 || m_iSelectShotStep == 1))
		return;

	INFO_IMAGE* pRefImage = NULL;
	this->GetParent()->SendMessage(WM_NOTIFY_SEQUENCE_REQUESET, (WPARAM)(&pRefImage), (LPARAM)0);
	cv::Mat displayedImg = cv::Mat(pRefImage->m_stFrame.m_dwHeight, pRefImage->m_stFrame.m_dwWidth, CV_8UC3, pRefImage->m_pBuffer, pRefImage->m_stFrame.m_dwPitch);
	if (both)
	{
		// Version 1.3.7.8
		//this->GetParent()->SendMessage(WM_NOTIFY_SEQUENCE_REQUESET_FIRST, (WPARAM)(&pRefImageFirst), (LPARAM)0);
		//this->GetParent()->SendMessage(WM_NOTIFY_SEQUENCE_REQUESET_SECOND, (WPARAM)(&pRefImageSecond), (LPARAM)0);
		
		//cv::Mat displayedImg1 = cv::Mat(pRefImageFirst->m_stFrame.m_dwHeight, pRefImageFirst->m_stFrame.m_dwWidth, CV_8UC3, pRefImageFirst->m_pBuffer, pRefImageFirst->m_stFrame.m_dwPitch);
		//cv::Mat displayedImg2 = cv::Mat(pRefImageSecond->m_stFrame.m_dwHeight, pRefImageSecond->m_stFrame.m_dwWidth, CV_8UC3, pRefImageSecond->m_pBuffer, pRefImageSecond->m_stFrame.m_dwPitch);
		
		m_CapturedImg[0] = displayedImg.clone();
		m_CapturedImg[1] = displayedImg.clone();
	}
	else
	{
		m_CapturedImg[m_iSelectShotStep] = displayedImg.clone();
	}
}

void CDlgStepSize::Process()
{
	UpdateData(true);

	if (!(m_iSelectShotStep == 0 || m_iSelectShotStep == 1))
		return;

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	INFO_IMAGE* pRefImage = NULL;
	this->GetParent()->SendMessage(WM_NOTIFY_SEQUENCE_REQUESET, (WPARAM)(&pRefImage), (LPARAM)0);
	// Test run application
	CSampleSide sample;
	BOOL bResult = false;

	//this->GetParent()->SendMessage(WM_NOTIFY_SEQUENCE_REQUESET_FIRST, (WPARAM)(&pRefImage), (LPARAM)0);
	sample.m_pRefImage = pRefImage;
	bResult = pInspection->InspectCamera(m_eCameraPos, m_eStep, sample);
	bResult = pInspection->InspectCamera(m_eCameraPos, m_eStepSecond, sample);

	if (bResult)
	{
		memcpy(&m_OutputSize[0], &sample.m_SizeResult, sizeof(OUTPUT_SIZE));
		memcpy(&m_OutputSize[1], &sample.m_SizeSecondResult, sizeof(OUTPUT_SIZE));

		LPARAM lParam = NULL;
		lParam = (LPARAM)&m_OutputSize[m_iSelectShotStep];

		if (m_iSelectShotStep == 0)
			this->GetParent()->SendMessage(WM_NOTIFY_SEQUENCE_EDIT_STEPDONE, (WPARAM)(m_eStep), lParam);
		else if (m_iSelectShotStep == 1)
			this->GetParent()->SendMessage(WM_NOTIFY_SEQUENCE_EDIT_STEPDONE, (WPARAM)(m_eStepSecond), lParam);

		pInspection->CalculationSize(m_eCameraPos, sample);

		for (int i = 0; i < TYPE_GEOMETRY_DISTANCE_MAX; i++)
		{
			OUTPUT_DISTANCE *pstDistance = NULL;
			pstDistance = sample.m_SizeCalculationResult.m_stDistance;
			if (pstDistance)
			{
				CString str;
				str.Format(_T("%.3f"), pstDistance[i].m_dValue);
				m_ctlListSizeResult.SetItem(i, 1, LVIF_TEXT, str, 0, 0, 0, NULL);
			}
		}
	}
	else
	{
		AfxMessageBox(STR_MSG_FAIL_INSPECTION);
		for (int i = 0; i < TYPE_GEOMETRY_DISTANCE_MAX; i++)
			m_ctlListSizeResult.SetItem(i, 1, LVIF_TEXT, _T("0.0"), 0, 0, 0, NULL);
	}
}

void CDlgStepSize::ModifyParams()
{
	m_iStrengthThreshold = (m_iStrengthThreshold < MIN_STRENGTH_THRESHOLD) ? MIN_STRENGTH_THRESHOLD : m_iStrengthThreshold;
	m_iStrengthThreshold = (m_iStrengthThreshold > MAX_STRENGTH_THRESHOLD) ? MAX_STRENGTH_THRESHOLD : m_iStrengthThreshold;

	m_iSampling = (m_iSampling < MIN_SAMPLE) ? MIN_SAMPLE : m_iSampling;
	m_iSampling = (m_iSampling > MAX_SAMPLE) ? MAX_SAMPLE : m_iSampling;

	m_iKernelSize = (m_iKernelSize / 2) * 2 + 1;
	m_iKernelSize = (m_iKernelSize < MIN_KERNEL) ? MIN_KERNEL : m_iKernelSize;
	m_iKernelSize = (m_iKernelSize > MAX_KERNEL) ? MAX_KERNEL : m_iKernelSize;

	m_iMinAngle = (m_iMinAngle < MIN_MINANGLE) ? MIN_MINANGLE : m_iMinAngle;
	m_iMinAngle = (m_iMinAngle > MAX_MINANGLE) ? MAX_MINANGLE : m_iMinAngle;

	m_iMaxAngle = (m_iMaxAngle < m_iMinAngle + 1) ? m_iMinAngle + 1 : m_iMaxAngle;
	m_iMaxAngle = (m_iMaxAngle > MAX_MAXANGLE) ? MAX_MAXANGLE : m_iMaxAngle;

	m_iDistanceThreshold = (m_iDistanceThreshold < MIN_DISTANCE_THRESHOLD) ? MIN_DISTANCE_THRESHOLD : m_iDistanceThreshold;
	m_iDistanceThreshold = (m_iDistanceThreshold > MAX_DISTANCE_THRESHOLD) ? MAX_DISTANCE_THRESHOLD : m_iDistanceThreshold;
}

void CDlgStepSize::OnParameterControlChange()
{
	if (!m_ctlListFindLine.GetSafeHwnd())
		return;

	const int nCur = m_ctlListFindLine.GetNextItem(-1, LVNI_SELECTED);
	if (-1 < nCur)
	{
		INFO_FINDLINE_PARAMETER stLineParameter = GetControlFindLineParameter();  // Current Value...

		m_pstFindLineParameter[nCur] = stLineParameter;
	}
}

void CDlgStepSize::OnBnClickedBtnStrobe()
{
	CDlgPasswd dlgPasswd;
	if (IDOK == dlgPasswd.DoModal())
	{
		UpdateData();
		if (!(m_iSelectShotStep == 0 || m_iSelectShotStep == 1))
			return;

		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
		const INFO_INSPECTION_SIZE* pstCurInfo = GetInspectionInfo(m_iSelectShotStep);

		CDlgStrobe dlg;
		for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
		{
			dlg.m_pstStepStrobe[i].m_eStrobeType = pstCurInfo->m_pstStepStrobe[i].m_eStrobeType;
			dlg.m_pstStepStrobe[i].m_nStrobeBrightness = pstCurInfo->m_pstStepStrobe[i].m_nStrobeBrightness;
		}

		if (IDOK == dlg.DoModal())
		{
			INFO_INSPECTION_SIZE stInspectionSize;
			const INFO_INSPECTION_SIZE* pstCurInfo = GetInspectionInfo(m_iSelectShotStep);
			memcpy(&stInspectionSize, pstCurInfo, sizeof(INFO_INSPECTION_SIZE));

			for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
			{
				stInspectionSize.m_pstStepStrobe[i].m_eStrobeType = dlg.m_pstStepStrobe[i].m_eStrobeType;
				stInspectionSize.m_pstStepStrobe[i].m_nStrobeBrightness = dlg.m_pstStepStrobe[i].m_nStrobeBrightness;
			}

			SetInspectionInfo(m_iSelectShotStep, &stInspectionSize);

			UpdateCtrlStrobe(&stInspectionSize);
		}
	}
}

void CDlgStepSize::Log(char* pszLog, ...)
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


void CDlgStepSize::OnCbnSelchangeComboSelectshotstep()
{
	UpdateData();
	if (!(m_iSelectShotStep == 0 || m_iSelectShotStep == 1))
		return;

	int nCur = m_ctlListFindLine.GetNextItem(-1, LVNI_SELECTED);
	while (-1 < nCur)
	{
		m_ctlListFindLine.SetItemState(nCur, 0);
		nCur = m_ctlListFindLine.GetNextItem(nCur, LVNI_SELECTED);
	}

	// Update Image
	{
		UpdateImageFromDisplay();
	}

	// Update Control
	{
		const INFO_INSPECTION_SIZE* pInspectSize = GetInspectionInfo(m_iSelectShotStep);
		UpdateCtrlStepSize(pInspectSize);
	}
}


