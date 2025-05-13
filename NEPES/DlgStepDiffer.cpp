// DlgStepDiffer.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "DlgStepDiffer.h"
#include "DlgStrobe.h"
#include "DlgPasswd.h"
#include "afxdialogex.h"

#include "CaptureManager.h"
#include "stringres.h"

#include "Util/Util.h"

// CDlgStepDiffer dialog

IMPLEMENT_DYNAMIC(CDlgStepDiffer, CDialogEx)

CDlgStepDiffer::CDlgStepDiffer(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgStepDiffer::IDD, pParent)
	, m_iProbability(0)
	, m_iBlobSize(0)
{
	m_eCameraPos = TYPE_CAMERAPOS_NONE;
}

CDlgStepDiffer::~CDlgStepDiffer()
{
}

void CDlgStepDiffer::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Slider(pDX, IDC_SLIDER_PROBABILITY, m_iProbability);
	DDX_Slider(pDX, IDC_SLIDER_BLOB, m_iBlobSize);
	DDX_Control(pDX, IDC_SLIDER_PROBABILITY, m_ctlSliderProbability);
	DDX_Control(pDX, IDC_SLIDER_BLOB, m_ctlSliderBlobSize);
}

BOOL CDlgStepDiffer::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (IDOK == wParam)
	{
		return TRUE;
	}
	return CDialogEx::OnCommand(wParam, lParam);
}

BOOL CDlgStepDiffer::PreTranslateMessage(MSG* pMsg)
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

BOOL CDlgStepDiffer::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_ctlSliderProbability.SetRange(0, 255);
	m_ctlSliderBlobSize.SetRange(0, 100);

	{
		const INFO_INSPECTION_DIFFER* pInfoDiffer = GetInspectionInfo();
		UpdateCtrlStepDiffer(pInfoDiffer);				
	}


	{
		CButton *pWnd = (CButton *)GetDlgItem(IDC_DIFFER_IMG_LOG);

		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
		CInspection* pInspection = pCaptureManager->GetInspection();
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
		CStepDiffer* pStepDiffer = dynamic_cast<CStepDiffer*>(pStep);

		if (pStepDiffer)
		{			
			if (pStepDiffer->m_bImgLog){
				pWnd->SetCheck(true);
			}
			else{
				pWnd->SetCheck(false);
			}
		}
	}


	return TRUE;
}



BEGIN_MESSAGE_MAP(CDlgStepDiffer, CDialogEx)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BTN_APPLY, &CDlgStepDiffer::OnBnClickedBtnApply)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_PROBABILITY, &CDlgStepDiffer::OnNMCustomdrawSliderProbability)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_BLOB, &CDlgStepDiffer::OnNMCustomdrawSliderBlob)
	ON_BN_CLICKED(IDC_DIFFER_IMG_LOG, &CDlgStepDiffer::OnCheckImgLog)
	ON_BN_CLICKED(IDC_BTN_STROBE, &CDlgStepDiffer::OnBnClickedBtnStrobe)
END_MESSAGE_MAP()


// CDlgStepDiffer message handlers
void CDlgStepDiffer::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CRect rect;
	GetClientRect(&rect);
}

void CDlgStepDiffer::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
}

void CDlgStepDiffer::OnBnClickedBtnStrobe()
{
	CDlgPasswd dlgPasswd;
	if (IDOK == dlgPasswd.DoModal())
	{
		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
		const INFO_INSPECTION_DIFFER* pstCurInfo = GetInspectionInfo();

		CDlgStrobe dlg;
		for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
		{
			dlg.m_pstStepStrobe[i].m_eStrobeType = pstCurInfo->m_pstStepStrobe[i].m_eStrobeType;
			dlg.m_pstStepStrobe[i].m_nStrobeBrightness = pstCurInfo->m_pstStepStrobe[i].m_nStrobeBrightness;
		}

		if (IDOK == dlg.DoModal())
		{
			INFO_INSPECTION_DIFFER stInspectionDiffer;
			const INFO_INSPECTION_DIFFER* pstCurInfo = GetInspectionInfo();
			memcpy(&stInspectionDiffer, pstCurInfo, sizeof(INFO_INSPECTION_DIFFER));

			for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
			{
				stInspectionDiffer.m_pstStepStrobe[i].m_eStrobeType = dlg.m_pstStepStrobe[i].m_eStrobeType;
				stInspectionDiffer.m_pstStepStrobe[i].m_nStrobeBrightness = dlg.m_pstStepStrobe[i].m_nStrobeBrightness;
			}

			SetInspectionInfo(&stInspectionDiffer);

			// Strobe Type & Brightness
			{
#ifdef DEF_APPLY_SETTING
				CString szStrobe01;

				if (TYPE_STROBE_COXIAL == stInspectionDiffer.m_pstStepStrobe[0].m_eStrobeType)
					szStrobe01.Format(_T("%s (%d)"), STR_STROBE_COAXIAL, stInspectionDiffer.m_pstStepStrobe[0].m_nStrobeBrightness);
				else if (TYPE_STROBE_RING == stInspectionDiffer.m_pstStepStrobe[0].m_eStrobeType)
					szStrobe01.Format(_T("%s (%d)"), STR_STROBE_RING, stInspectionDiffer.m_pstStepStrobe[0].m_nStrobeBrightness);
				else if (TYPE_STROBE_BAR == stInspectionDiffer.m_pstStepStrobe[0].m_eStrobeType)
					szStrobe01.Format(_T("%s (%d)"), STR_STROBE_BAR, stInspectionDiffer.m_pstStepStrobe[0].m_nStrobeBrightness);
				else
					szStrobe01.Format(_T("%s"), STR_STROBE_OFF);
				GetDlgItem(IDC_EDIT_STROBE01)->SetWindowText(szStrobe01);

				CString szStrobe02;

				if (TYPE_STROBE_COXIAL == stInspectionDiffer.m_pstStepStrobe[1].m_eStrobeType)
					szStrobe02.Format(_T("%s (%d)"), STR_STROBE_COAXIAL, stInspectionDiffer.m_pstStepStrobe[1].m_nStrobeBrightness);
				else if (TYPE_STROBE_RING == stInspectionDiffer.m_pstStepStrobe[1].m_eStrobeType)
					szStrobe02.Format(_T("%s (%d)"), STR_STROBE_RING, stInspectionDiffer.m_pstStepStrobe[1].m_nStrobeBrightness);
				else if (TYPE_STROBE_BAR == stInspectionDiffer.m_pstStepStrobe[1].m_eStrobeType)
					szStrobe02.Format(_T("%s (%d)"), STR_STROBE_BAR, stInspectionDiffer.m_pstStepStrobe[1].m_nStrobeBrightness);
				else
					szStrobe02.Format(_T("%s"), STR_STROBE_OFF);
				GetDlgItem(IDC_EDIT_STROBE02)->SetWindowText(szStrobe02);
#endif
			}
		}
	}
}


void CDlgStepDiffer::OnBnClickedBtnApply()
{
	UpdateData();

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	INFO_INSPECTION_DIFFER stInspectionDiffer;
	const INFO_INSPECTION_DIFFER* pstCurInfo = GetInspectionInfo();
	memcpy(&stInspectionDiffer, pstCurInfo, sizeof(INFO_INSPECTION_DIFFER));

	{
		stInspectionDiffer.m_stParaDiffer.prob_thres = static_cast<float>(m_iProbability);
		stInspectionDiffer.m_stParaDiffer.blobSize_thres = static_cast<float>(m_iBlobSize);
		SetInspectionInfo(&stInspectionDiffer);

		INFO_IMAGE* pRefImage = NULL;
		this->GetParent()->SendMessage(WM_NOTIFY_SEQUENCE_REQUESET, (WPARAM)(&pRefImage), (LPARAM)0);
		cv::Mat tmpImg = cv::Mat(pRefImage->m_stFrame.m_dwHeight, pRefImage->m_stFrame.m_dwWidth, CV_8UC3, pRefImage->m_pBuffer, pRefImage->m_stFrame.m_dwPitch);
		cv::Mat matImg = tmpImg.clone();

		// Test run application
		CSampleSide sample;

		if (TYPE_CAMERAPOS_FIRST == m_eCameraPos)
			sample.m_pRefImage = pRefImage;
		else if (TYPE_CAMERAPOS_SECOND == m_eCameraPos)
			sample.m_pRefImage = pRefImage;
		//BOOL bResult = pInspection->InspectCamera(m_eCameraPos, m_eStep, sample);
		BOOL bResult = pInspection->InspectCamera(m_eCameraPos, m_eStep, sample, matImg);
		if (bResult)
		{
			LPARAM lParam = NULL;
			if (TYPE_CAMERAPOS_FIRST == m_eCameraPos)
				lParam = (LPARAM)&sample.m_DifferResult;
			else if (TYPE_CAMERAPOS_SECOND == m_eCameraPos)
				lParam = (LPARAM)&sample.m_DifferResult;
			this->GetParent()->SendMessage(WM_NOTIFY_SEQUENCE_EDIT_STEPDONE, (WPARAM)(m_eStep), lParam);
			if (sample.m_DifferResult.m_bResult == false)
			{
				AfxMessageBox(STR_MSG_DEFECT_DETECTED);
			}
		}
		else
		{
			AfxMessageBox(STR_MSG_FAIL_INSPECTION);
		}
	}
}


void CDlgStepDiffer::UpdateCameraPos(TYPE_CAMERAPOS ePos)
{
	m_eCameraPos = ePos;
}

void CDlgStepDiffer::UpdateSelectedRoiPos(const INFO_RECT_ROI* pROI)
{
	if (NULL == pROI)
		return;

	INFO_INSPECTION_DIFFER stInspectionDiffer;
	const INFO_INSPECTION_DIFFER* pstCurInfo = GetInspectionInfo();
	memcpy(&stInspectionDiffer, pstCurInfo, sizeof(INFO_INSPECTION_DIFFER));

	stInspectionDiffer.m_stRoi = *pROI;		// Change Roi

	SetInspectionInfo(&stInspectionDiffer);

}

void CDlgStepDiffer::SetDefaultValue()
{
	;
}

void CDlgStepDiffer::UpdateCtrlStepDiffer(const INFO_INSPECTION_DIFFER* pInspectDiffer)
{
	if (NULL == pInspectDiffer)
		return;

	// Strobe Type & Brightness
	{
		CString szStrobe01;
#ifdef DEF_APPLY_SETTING
		if (TYPE_STROBE_COXIAL == pInspectDiffer->m_pstStepStrobe[0].m_eStrobeType)
			szStrobe01.Format(_T("%s (%d)"), STR_STROBE_COAXIAL, pInspectDiffer->m_pstStepStrobe[0].m_nStrobeBrightness);
		else if (TYPE_STROBE_RING == pInspectDiffer->m_pstStepStrobe[0].m_eStrobeType)
			szStrobe01.Format(_T("%s (%d)"), STR_STROBE_RING, pInspectDiffer->m_pstStepStrobe[0].m_nStrobeBrightness);
		else if (TYPE_STROBE_BAR == pInspectDiffer->m_pstStepStrobe[0].m_eStrobeType)
			szStrobe01.Format(_T("%s (%d)"), STR_STROBE_BAR, pInspectDiffer->m_pstStepStrobe[0].m_nStrobeBrightness);
		else
			szStrobe01.Format(_T("%s"), STR_STROBE_OFF);
#else
		szStrobe01.Format(_T("%s (%d)"), STR_STROBE_COAXIAL, 30);
#endif
		GetDlgItem(IDC_EDIT_STROBE01)->SetWindowText(szStrobe01);
	}
	{
		CString szStrobe02;
#ifdef DEF_APPLY_SETTING
		if (TYPE_STROBE_COXIAL == pInspectDiffer->m_pstStepStrobe[1].m_eStrobeType)
			szStrobe02.Format(_T("%s (%d)"), STR_STROBE_COAXIAL, pInspectDiffer->m_pstStepStrobe[1].m_nStrobeBrightness);
		else if (TYPE_STROBE_RING == pInspectDiffer->m_pstStepStrobe[1].m_eStrobeType)
			szStrobe02.Format(_T("%s (%d)"), STR_STROBE_RING, pInspectDiffer->m_pstStepStrobe[1].m_nStrobeBrightness);
		else if (TYPE_STROBE_BAR == pInspectDiffer->m_pstStepStrobe[1].m_eStrobeType)
			szStrobe02.Format(_T("%s (%d)"), STR_STROBE_BAR, pInspectDiffer->m_pstStepStrobe[1].m_nStrobeBrightness);
		else
			szStrobe02.Format(_T("%s"), STR_STROBE_OFF);
#else
		szStrobe02.Format(_T("%s"), STR_STROBE_OFF);
#endif
		GetDlgItem(IDC_EDIT_STROBE02)->SetWindowText(szStrobe02);
	}

	SetParameter(&pInspectDiffer->m_stParaDiffer);
}

const INFO_INSPECTION_DIFFER* CDlgStepDiffer::GetInspectionInfo()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
	CStepDiffer* pStepDiffer = dynamic_cast<CStepDiffer*>(pStep);
	if (pStepDiffer)
	{
		const INFO_INSPECTION_DIFFER* pDifferInfo = pStepDiffer->GetInformation();
		return pDifferInfo;
	}
	return NULL;
}

BOOL CDlgStepDiffer::SetInspectionInfo(const INFO_INSPECTION_DIFFER* pstInfo)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	BOOL bResult = FALSE;
	CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
	CStepDiffer* pStepDiffer = dynamic_cast<CStepDiffer*>(pStep);
	if (pStepDiffer)
	{
		bResult = pStepDiffer->SetInformation(pstInfo);
	}

	/// Update Backup
	{
		UpdateInspectionInfoBackup();
	}
	//*/
	return bResult;
}

void CDlgStepDiffer::UpdateInspectionInfoBackup()
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

	if (pStepSize && pStepStain && pStepDiffer && pStepBubble && pStepScratch && pStepStamp && pStepSizeSecond)
	{
		stChanged.m_bInit = TRUE;
		stChanged.m_stSize = *pStepSize->GetInformation();
		stChanged.m_stStain = *pStepStain->GetInformation();
		stChanged.m_stDiffer = *pStepDiffer->GetInformation();
		stChanged.m_stBubble = *pStepBubble->GetInformation();
		stChanged.m_stScratch = *pStepScratch->GetInformation();
		stChanged.m_stStamp = *pStepStamp->GetInformation();
		stChanged.m_stSizeSecond = *pStepSizeSecond->GetInformation();

		pCaptureManager->UpdateInspection(m_eCameraPos, NULL, &stChanged);
	}
}

void CDlgStepDiffer::OnNMCustomdrawSliderProbability(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);

	UpdateData();
	CString str;
	str.Format("%d", m_iProbability);
	SetDlgItemText(IDC_STATIC_PROBABILITY, str);

	*pResult = 0;
}

void CDlgStepDiffer::OnNMCustomdrawSliderBlob(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);

	UpdateData();
	CString str;
	str.Format("%d", m_iBlobSize);
	SetDlgItemText(IDC_STATIC_BLOB, str);

	*pResult = 0;
}

void CDlgStepDiffer::SetParameter(const INFO_MARS_PARA* pstInfo)
{
	if (NULL == pstInfo)
		return;

	// Set Control Values
	this->m_iBlobSize = pstInfo->blobSize_thres;
	this->m_iProbability = pstInfo->prob_thres;


	UpdateData(FALSE);

	CString str;
	str.Format("%d", m_iBlobSize);
	SetDlgItemText(IDC_STATIC_BLOB, str);
	str.Format("%d", m_iProbability);
	SetDlgItemText(IDC_STATIC_PROBABILITY, str);
}

void CDlgStepDiffer::OnCheckImgLog()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();
		
	CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
	CStepDiffer* pStepDiffer = dynamic_cast<CStepDiffer*>(pStep);
	if (pStepDiffer)
	{
		CButton *pWnd = (CButton *)GetDlgItem(IDC_DIFFER_IMG_LOG);
		if (pWnd->GetCheck())
			pStepDiffer->m_bImgLog = TRUE;
		else
			pStepDiffer->m_bImgLog = FALSE;
	}
}
