// DlgStep01.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "DlgStepBubble.h"
#include "DlgStrobe.h"
#include "DlgPasswd.h"
#include "afxdialogex.h"

#include "CaptureManager.h"
#include "stringres.h"

#include "Util/Util.h"

// CDlgStepBubble dialog

IMPLEMENT_DYNAMIC(CDlgStepBubble, CDialogEx)

CDlgStepBubble::CDlgStepBubble(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgStepBubble::IDD, pParent)
	, m_iProbability(0)
	, m_iBlobSize(0)
{
	m_eCameraPos = TYPE_CAMERAPOS_NONE;
}

CDlgStepBubble::~CDlgStepBubble()
{
}

void CDlgStepBubble::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Slider(pDX, IDC_SLIDER_PROBABILITY, m_iProbability);
	DDX_Slider(pDX, IDC_SLIDER_BLOB, m_iBlobSize);
	DDX_Control(pDX, IDC_SLIDER_PROBABILITY, m_ctlSliderProbability);
	DDX_Control(pDX, IDC_SLIDER_BLOB, m_ctlSliderBlobSize);
}

BOOL CDlgStepBubble::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (IDOK == wParam)
	{
		return TRUE;
	}
	return CDialogEx::OnCommand(wParam, lParam);
}

BOOL CDlgStepBubble::PreTranslateMessage(MSG* pMsg)
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

BOOL CDlgStepBubble::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_ctlSliderProbability.SetRange(0, 255);
	m_ctlSliderBlobSize.SetRange(0, 100);
		
	{
		const INFO_INSPECTION_BUBBLE* pInfoBubble = GetInspectionInfo();
		UpdateCtrlStepBubble(pInfoBubble);		
	}

	{
		CButton *pWnd = (CButton *)GetDlgItem(IDC_BUBBLE_IMG_LOG);

		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
		CInspection* pInspection = pCaptureManager->GetInspection();
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
		CStepBubble* pStepBubble = dynamic_cast<CStepBubble*>(pStep);

		if (pStepBubble)
		{
			if (pStepBubble->m_bImgLog){
				pWnd->SetCheck(true);
			}
			else{
				pWnd->SetCheck(false);
			}
		}
	}

	return TRUE;
}



BEGIN_MESSAGE_MAP(CDlgStepBubble, CDialogEx)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BTN_APPLY, &CDlgStepBubble::OnBnClickedBtnApply)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_PROBABILITY, &CDlgStepBubble::OnNMCustomdrawSliderProbability)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_BLOB, &CDlgStepBubble::OnNMCustomdrawSliderBlob)
	ON_BN_CLICKED(IDC_BUBBLE_IMG_LOG, &CDlgStepBubble::OnCheckImgLog)
	ON_BN_CLICKED(IDC_BTN_STROBE, &CDlgStepBubble::OnBnClickedBtnStrobe)
END_MESSAGE_MAP()


// CDlgStepBubble message handlers
void CDlgStepBubble::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CRect rect;
	GetClientRect(&rect);

}

void CDlgStepBubble::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

}

void CDlgStepBubble::OnBnClickedBtnStrobe()
{
	CDlgPasswd dlgPasswd;
	if (IDOK == dlgPasswd.DoModal())
	{
		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
		const INFO_INSPECTION_BUBBLE* pstCurInfo = GetInspectionInfo();

		CDlgStrobe dlg;
		for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
		{
			dlg.m_pstStepStrobe[i].m_eStrobeType = pstCurInfo->m_pstStepStrobe[i].m_eStrobeType;
			dlg.m_pstStepStrobe[i].m_nStrobeBrightness = pstCurInfo->m_pstStepStrobe[i].m_nStrobeBrightness;
		}

		if (IDOK == dlg.DoModal())
		{
			INFO_INSPECTION_BUBBLE stInspectionBubble;
			const INFO_INSPECTION_BUBBLE* pstCurInfo = GetInspectionInfo();
			memcpy(&stInspectionBubble, pstCurInfo, sizeof(INFO_INSPECTION_BUBBLE));

			for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
			{
				stInspectionBubble.m_pstStepStrobe[i].m_eStrobeType = dlg.m_pstStepStrobe[i].m_eStrobeType;
				stInspectionBubble.m_pstStepStrobe[i].m_nStrobeBrightness = dlg.m_pstStepStrobe[i].m_nStrobeBrightness;
			}

			SetInspectionInfo(&stInspectionBubble);

			// Strobe Type & Brightness
			{
#ifdef DEF_APPLY_SETTING
				CString szStrobe01;

				if (TYPE_STROBE_COXIAL == stInspectionBubble.m_pstStepStrobe[0].m_eStrobeType)
					szStrobe01.Format(_T("%s (%d)"), STR_STROBE_COAXIAL, stInspectionBubble.m_pstStepStrobe[0].m_nStrobeBrightness);
				else if (TYPE_STROBE_RING == stInspectionBubble.m_pstStepStrobe[0].m_eStrobeType)
					szStrobe01.Format(_T("%s (%d)"), STR_STROBE_RING, stInspectionBubble.m_pstStepStrobe[0].m_nStrobeBrightness);
				else if (TYPE_STROBE_BAR == stInspectionBubble.m_pstStepStrobe[0].m_eStrobeType)
					szStrobe01.Format(_T("%s (%d)"), STR_STROBE_BAR, stInspectionBubble.m_pstStepStrobe[0].m_nStrobeBrightness);
				else
					szStrobe01.Format(_T("%s"), STR_STROBE_OFF);
				GetDlgItem(IDC_EDIT_STROBE01)->SetWindowText(szStrobe01);

				CString szStrobe02;

				if (TYPE_STROBE_COXIAL == stInspectionBubble.m_pstStepStrobe[1].m_eStrobeType)
					szStrobe02.Format(_T("%s (%d)"), STR_STROBE_COAXIAL, stInspectionBubble.m_pstStepStrobe[1].m_nStrobeBrightness);
				else if (TYPE_STROBE_RING == stInspectionBubble.m_pstStepStrobe[1].m_eStrobeType)
					szStrobe02.Format(_T("%s (%d)"), STR_STROBE_RING, stInspectionBubble.m_pstStepStrobe[1].m_nStrobeBrightness);
				else if (TYPE_STROBE_BAR == stInspectionBubble.m_pstStepStrobe[1].m_eStrobeType)
					szStrobe02.Format(_T("%s (%d)"), STR_STROBE_BAR, stInspectionBubble.m_pstStepStrobe[1].m_nStrobeBrightness);
				else
					szStrobe02.Format(_T("%s"), STR_STROBE_OFF);
				GetDlgItem(IDC_EDIT_STROBE02)->SetWindowText(szStrobe02);
#endif
			}
		}
	}
}


void CDlgStepBubble::OnBnClickedBtnApply()
{
	UpdateData();

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	INFO_INSPECTION_BUBBLE stInspectionBubble;
	const INFO_INSPECTION_BUBBLE* pstCurInfo = GetInspectionInfo();
	memcpy(&stInspectionBubble, pstCurInfo, sizeof(INFO_INSPECTION_BUBBLE));

	{
		stInspectionBubble.m_stParaBubble.prob_thres = static_cast<float>(m_iProbability);
		stInspectionBubble.m_stParaBubble.blobSize_thres = static_cast<float>(m_iBlobSize);
		SetInspectionInfo(&stInspectionBubble);

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
				lParam = (LPARAM)&sample.m_BubbleResult;
			else if (TYPE_CAMERAPOS_SECOND == m_eCameraPos)
				lParam = (LPARAM)&sample.m_BubbleResult;
			this->GetParent()->SendMessage(WM_NOTIFY_SEQUENCE_EDIT_STEPDONE, (WPARAM)(m_eStep), lParam);
			if (sample.m_BubbleResult.m_bResult == false)
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


void CDlgStepBubble::UpdateCameraPos(TYPE_CAMERAPOS ePos)
{
	m_eCameraPos = ePos;
}

void CDlgStepBubble::UpdateSelectedRoiPos(const INFO_RECT_ROI* pROI)
{
	if (NULL == pROI)
		return;

	INFO_INSPECTION_BUBBLE stInspectionBubble;
	const INFO_INSPECTION_BUBBLE* pstCurInfo = GetInspectionInfo();
	memcpy(&stInspectionBubble, pstCurInfo, sizeof(INFO_INSPECTION_BUBBLE));

	stInspectionBubble.m_stRoi = *pROI;			// Change Roi;
	
	SetInspectionInfo(&stInspectionBubble);
}

void CDlgStepBubble::SetDefaultValue()
{
	;
}

void CDlgStepBubble::UpdateCtrlStepBubble(const INFO_INSPECTION_BUBBLE* pInspectBubble)
{
	if (NULL == pInspectBubble)
		return;

	// Strobe Type & Brightness
	{
		CString szStrobe01;
#ifdef DEF_APPLY_SETTING
		if (TYPE_STROBE_COXIAL == pInspectBubble->m_pstStepStrobe[0].m_eStrobeType)
			szStrobe01.Format(_T("%s (%d)"), STR_STROBE_COAXIAL, pInspectBubble->m_pstStepStrobe[0].m_nStrobeBrightness);
		else if (TYPE_STROBE_RING == pInspectBubble->m_pstStepStrobe[0].m_eStrobeType)
			szStrobe01.Format(_T("%s (%d)"), STR_STROBE_RING, pInspectBubble->m_pstStepStrobe[0].m_nStrobeBrightness);
		else if (TYPE_STROBE_BAR == pInspectBubble->m_pstStepStrobe[0].m_eStrobeType)
			szStrobe01.Format(_T("%s (%d)"), STR_STROBE_BAR, pInspectBubble->m_pstStepStrobe[0].m_nStrobeBrightness);
		else
			szStrobe01.Format(_T("%s"), STR_STROBE_OFF);
#else
		szStrobe01.Format(_T("%s (%d)"), STR_STROBE_COAXIAL, 13);
#endif
		GetDlgItem(IDC_EDIT_STROBE01)->SetWindowText(szStrobe01);
	}
	{
		CString szStrobe02;
#ifdef DEF_APPLY_SETTING
		if (TYPE_STROBE_COXIAL == pInspectBubble->m_pstStepStrobe[1].m_eStrobeType)
			szStrobe02.Format(_T("%s (%d)"), STR_STROBE_COAXIAL, pInspectBubble->m_pstStepStrobe[1].m_nStrobeBrightness);
		else if (TYPE_STROBE_RING == pInspectBubble->m_pstStepStrobe[1].m_eStrobeType)
			szStrobe02.Format(_T("%s (%d)"), STR_STROBE_RING, pInspectBubble->m_pstStepStrobe[1].m_nStrobeBrightness);
		else if (TYPE_STROBE_BAR == pInspectBubble->m_pstStepStrobe[1].m_eStrobeType)
			szStrobe02.Format(_T("%s (%d)"), STR_STROBE_BAR, pInspectBubble->m_pstStepStrobe[1].m_nStrobeBrightness);
		else
			szStrobe02.Format(_T("%s"), STR_STROBE_OFF);
#else
		szStrobe02.Format(_T("%s"), STR_STROBE_OFF);
#endif
		GetDlgItem(IDC_EDIT_STROBE02)->SetWindowText(szStrobe02);
	}

	SetParameter(&pInspectBubble->m_stParaBubble);
}

const INFO_INSPECTION_BUBBLE* CDlgStepBubble::GetInspectionInfo()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
	CStepBubble* pStepBubble = dynamic_cast<CStepBubble*>(pStep);
	if (pStepBubble)
	{
		const INFO_INSPECTION_BUBBLE* pBubbleInfo = pStepBubble->GetInformation();
		return pBubbleInfo;
	}
	return NULL;
}

BOOL CDlgStepBubble::SetInspectionInfo(const INFO_INSPECTION_BUBBLE* pstInfo)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	BOOL bResult = FALSE;
	CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
	CStepBubble* pStepBubble = dynamic_cast<CStepBubble*>(pStep);
	if (pStepBubble)
	{
		bResult = pStepBubble->SetInformation(pstInfo);
	}

	/// Update Backup
	{
		UpdateInspectionInfoBackup();
	}
	//*/
	return bResult;
}

void CDlgStepBubble::UpdateInspectionInfoBackup()
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

void CDlgStepBubble::OnNMCustomdrawSliderProbability(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);

	UpdateData();
	CString str;
	str.Format("%d", m_iProbability);
	SetDlgItemText(IDC_STATIC_PROBABILITY, str);

	*pResult = 0;
}

void CDlgStepBubble::OnNMCustomdrawSliderBlob(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);

	UpdateData();
	CString str;
	str.Format("%d", m_iBlobSize);
	SetDlgItemText(IDC_STATIC_BLOB, str);

	*pResult = 0;
}

void CDlgStepBubble::SetParameter(const INFO_MARS_PARA* pstInfo)
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

void CDlgStepBubble::OnCheckImgLog()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
	CStepBubble* pStepBubble = dynamic_cast<CStepBubble*>(pStep);
	if (pStepBubble)
	{
		CButton *pWnd = (CButton *)GetDlgItem(IDC_BUBBLE_IMG_LOG);
		if (pWnd->GetCheck())
			pStepBubble->m_bImgLog = TRUE;
		else
			pStepBubble->m_bImgLog = FALSE;
	}
}
