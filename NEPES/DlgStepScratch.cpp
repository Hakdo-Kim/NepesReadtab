// DlgStep01.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "DlgStepScratch.h"
#include "DlgStrobe.h"
#include "DlgPasswd.h"
#include "afxdialogex.h"

#include "CaptureManager.h"
#include "stringres.h"

#include "Util/Util.h"


// CDlgStepScratch dialog

IMPLEMENT_DYNAMIC(CDlgStepScratch, CDialogEx)

CDlgStepScratch::CDlgStepScratch(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgStepScratch::IDD, pParent)
	, m_iProbability(0)
	, m_iBlobSize(0)
{
	m_eCameraPos = TYPE_CAMERAPOS_NONE;
}

CDlgStepScratch::~CDlgStepScratch()
{
}

void CDlgStepScratch::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Slider(pDX, IDC_SLIDER_PROBABILITY, m_iProbability);
	DDX_Slider(pDX, IDC_SLIDER_BLOB, m_iBlobSize);
	DDX_Control(pDX, IDC_SLIDER_PROBABILITY, m_ctlSliderProbability);
	DDX_Control(pDX, IDC_SLIDER_BLOB, m_ctlSliderBlobSize);
}

BOOL CDlgStepScratch::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (IDOK == wParam)
	{
		return TRUE;
	}
	return CDialogEx::OnCommand(wParam, lParam);
}

BOOL CDlgStepScratch::PreTranslateMessage(MSG* pMsg)
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

BOOL CDlgStepScratch::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_ctlSliderProbability.SetRange(0, 255);
	m_ctlSliderBlobSize.SetRange(0, 100);

	{
		const INFO_INSPECTION_SCRATCH* pInfoScratch = GetInspectionInfo();
		UpdateCtrlStepScratch(pInfoScratch);				
	}

	// check box : image log
	{
		CButton *pWnd = (CButton *)GetDlgItem(IDC_SCRATCH_IMG_LOG);

		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
		CInspection* pInspection = pCaptureManager->GetInspection();
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
		CStepScratch* pStepScratch = dynamic_cast<CStepScratch*>(pStep);

		if (pStepScratch)
		{			
			if (pStepScratch->m_bImgLog){
				pWnd->SetCheck(true);
			}
			else{
				pWnd->SetCheck(false);
			}
		}
	}
	

	return TRUE;
}


BEGIN_MESSAGE_MAP(CDlgStepScratch, CDialogEx)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BTN_APPLY, &CDlgStepScratch::OnBnClickedBtnApply)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_PROBABILITY, &CDlgStepScratch::OnNMCustomdrawSliderProbability)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_BLOB, &CDlgStepScratch::OnNMCustomdrawSliderBlob)
	ON_BN_CLICKED(IDC_SCRATCH_IMG_LOG, &CDlgStepScratch::OnCheckImgLog)
	ON_BN_CLICKED(IDC_BTN_STROBE, &CDlgStepScratch::OnBnClickedBtnStrobe)
END_MESSAGE_MAP()


// CDlgStepScratch message handlers
void CDlgStepScratch::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CRect rect;
	GetClientRect(&rect);

}

void CDlgStepScratch::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

}

void CDlgStepScratch::OnBnClickedBtnStrobe()
{
	CDlgPasswd dlgPasswd;
	if (IDOK == dlgPasswd.DoModal())
	{
		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
		const INFO_INSPECTION_SCRATCH* pstCurInfo = GetInspectionInfo();

		CDlgStrobe dlg;
		for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
		{
			dlg.m_pstStepStrobe[i].m_eStrobeType = pstCurInfo->m_pstStepStrobe[i].m_eStrobeType;
			dlg.m_pstStepStrobe[i].m_nStrobeBrightness = pstCurInfo->m_pstStepStrobe[i].m_nStrobeBrightness;
		}

		if (IDOK == dlg.DoModal())
		{
			INFO_INSPECTION_SCRATCH stInspectionScratch;
			const INFO_INSPECTION_SCRATCH* pstCurInfo = GetInspectionInfo();
			memcpy(&stInspectionScratch, pstCurInfo, sizeof(INFO_INSPECTION_SCRATCH));

			for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
			{
				stInspectionScratch.m_pstStepStrobe[i].m_eStrobeType = dlg.m_pstStepStrobe[i].m_eStrobeType;
				stInspectionScratch.m_pstStepStrobe[i].m_nStrobeBrightness = dlg.m_pstStepStrobe[i].m_nStrobeBrightness;
			}

			SetInspectionInfo(&stInspectionScratch);

			// Strobe Type & Brightness
			{
				CString szStrobe01;

				if (TYPE_STROBE_COXIAL == stInspectionScratch.m_pstStepStrobe[0].m_eStrobeType)
					szStrobe01.Format(_T("%s (%d)"), STR_STROBE_COAXIAL, stInspectionScratch.m_pstStepStrobe[0].m_nStrobeBrightness);
				else if (TYPE_STROBE_RING == stInspectionScratch.m_pstStepStrobe[0].m_eStrobeType)
					szStrobe01.Format(_T("%s (%d)"), STR_STROBE_RING, stInspectionScratch.m_pstStepStrobe[0].m_nStrobeBrightness);
				else if (TYPE_STROBE_BAR == stInspectionScratch.m_pstStepStrobe[0].m_eStrobeType)
					szStrobe01.Format(_T("%s (%d)"), STR_STROBE_BAR, stInspectionScratch.m_pstStepStrobe[0].m_nStrobeBrightness);
				else
					szStrobe01.Format(_T("%s"), STR_STROBE_OFF);
				GetDlgItem(IDC_EDIT_STROBE01)->SetWindowText(szStrobe01);

				CString szStrobe02;

				if (TYPE_STROBE_COXIAL == stInspectionScratch.m_pstStepStrobe[1].m_eStrobeType)
					szStrobe02.Format(_T("%s (%d)"), STR_STROBE_COAXIAL, stInspectionScratch.m_pstStepStrobe[1].m_nStrobeBrightness);
				else if (TYPE_STROBE_RING == stInspectionScratch.m_pstStepStrobe[1].m_eStrobeType)
					szStrobe02.Format(_T("%s (%d)"), STR_STROBE_RING, stInspectionScratch.m_pstStepStrobe[1].m_nStrobeBrightness);
				else if (TYPE_STROBE_BAR == stInspectionScratch.m_pstStepStrobe[1].m_eStrobeType)
					szStrobe02.Format(_T("%s (%d)"), STR_STROBE_BAR, stInspectionScratch.m_pstStepStrobe[1].m_nStrobeBrightness);
				else
					szStrobe02.Format(_T("%s"), STR_STROBE_OFF);
				GetDlgItem(IDC_EDIT_STROBE02)->SetWindowText(szStrobe02);
			}
		}
	}
}


void CDlgStepScratch::OnBnClickedBtnApply()
{
	UpdateData();

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	INFO_INSPECTION_SCRATCH stInspectionScratch;
	const INFO_INSPECTION_SCRATCH* pstCurInfo = GetInspectionInfo();
	memcpy(&stInspectionScratch, pstCurInfo, sizeof(INFO_INSPECTION_SCRATCH));

	{
		stInspectionScratch.m_stParaScratch.prob_thres = static_cast<float>(m_iProbability);
		stInspectionScratch.m_stParaScratch.blobSize_thres = static_cast<float>(m_iBlobSize);
		SetInspectionInfo(&stInspectionScratch);

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
				lParam = (LPARAM)&sample.m_ScratchResult;
			else if (TYPE_CAMERAPOS_SECOND == m_eCameraPos)
				lParam = (LPARAM)&sample.m_ScratchResult;
			this->GetParent()->SendMessage(WM_NOTIFY_SEQUENCE_EDIT_STEPDONE, (WPARAM)(m_eStep), lParam);
			if (sample.m_ScratchResult.m_bResult == false)
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


void CDlgStepScratch::UpdateCameraPos(TYPE_CAMERAPOS ePos)
{
	m_eCameraPos = ePos;
}

void CDlgStepScratch::UpdateSelectedRoiPos(const INFO_RECT_ROI* pROI)
{
	if (NULL == pROI)
		return;

	INFO_INSPECTION_SCRATCH stInspectionScratch;
	const INFO_INSPECTION_SCRATCH* pstCurInfo = GetInspectionInfo();
	memcpy(&stInspectionScratch, pstCurInfo, sizeof(INFO_INSPECTION_SCRATCH));

	stInspectionScratch.m_stRoi = *pROI;

	SetInspectionInfo(&stInspectionScratch);
	
}

void CDlgStepScratch::SetDefaultValue()
{
	;
}

void CDlgStepScratch::UpdateCtrlStepScratch(const INFO_INSPECTION_SCRATCH* pInspectScratch)
{
	if (NULL == pInspectScratch)
		return;

	// Strobe Type & Brightness
	{
		CString szStrobe01;

		if (TYPE_STROBE_COXIAL == pInspectScratch->m_pstStepStrobe[0].m_eStrobeType)
			szStrobe01.Format(_T("%s (%d)"), STR_STROBE_COAXIAL, pInspectScratch->m_pstStepStrobe[0].m_nStrobeBrightness);
		else if (TYPE_STROBE_RING == pInspectScratch->m_pstStepStrobe[0].m_eStrobeType)
			szStrobe01.Format(_T("%s (%d)"), STR_STROBE_RING, pInspectScratch->m_pstStepStrobe[0].m_nStrobeBrightness);
		else if (TYPE_STROBE_BAR == pInspectScratch->m_pstStepStrobe[0].m_eStrobeType)
			szStrobe01.Format(_T("%s (%d)"), STR_STROBE_BAR, pInspectScratch->m_pstStepStrobe[0].m_nStrobeBrightness);
		else
			szStrobe01.Format(_T("%s"), STR_STROBE_OFF);
		GetDlgItem(IDC_EDIT_STROBE01)->SetWindowText(szStrobe01);
	}
	{
		CString szStrobe02;

		if (TYPE_STROBE_COXIAL == pInspectScratch->m_pstStepStrobe[1].m_eStrobeType)
			szStrobe02.Format(_T("%s (%d)"), STR_STROBE_COAXIAL, pInspectScratch->m_pstStepStrobe[1].m_nStrobeBrightness);
		else if (TYPE_STROBE_RING == pInspectScratch->m_pstStepStrobe[1].m_eStrobeType)
			szStrobe02.Format(_T("%s (%d)"), STR_STROBE_RING, pInspectScratch->m_pstStepStrobe[1].m_nStrobeBrightness);
		else if (TYPE_STROBE_BAR == pInspectScratch->m_pstStepStrobe[1].m_eStrobeType)
			szStrobe02.Format(_T("%s (%d)"), STR_STROBE_BAR, pInspectScratch->m_pstStepStrobe[1].m_nStrobeBrightness);
		else
			szStrobe02.Format(_T("%s"), STR_STROBE_OFF);
		GetDlgItem(IDC_EDIT_STROBE02)->SetWindowText(szStrobe02);
	}

	SetParameter(&pInspectScratch->m_stParaScratch);
}


const INFO_INSPECTION_SCRATCH* CDlgStepScratch::GetInspectionInfo()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();
	

	CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
	CStepScratch* pStepScratch = dynamic_cast<CStepScratch*>(pStep);
	if (pStepScratch)
	{
		const INFO_INSPECTION_SCRATCH* pScratchInfo = pStepScratch->GetInformation();
		return pScratchInfo;
	}
	return NULL;
}

BOOL CDlgStepScratch::SetInspectionInfo(const INFO_INSPECTION_SCRATCH* pstInfo)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	BOOL bResult = FALSE;
	CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
	CStepScratch* pStepScratch = dynamic_cast<CStepScratch*>(pStep);
	if (pStepScratch)
	{
		bResult = pStepScratch->SetInformation(pstInfo);
	}

	/// Update Backup
	{
		UpdateInspectionInfoBackup();
	}
	//*/
	return bResult;
}

void CDlgStepScratch::UpdateInspectionInfoBackup()
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

void CDlgStepScratch::OnNMCustomdrawSliderProbability(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);

	UpdateData();
	CString str;
	str.Format("%d", m_iProbability);
	SetDlgItemText(IDC_STATIC_PROBABILITY, str);

	*pResult = 0;
}

void CDlgStepScratch::OnNMCustomdrawSliderBlob(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);

	UpdateData();
	CString str;
	str.Format("%d", m_iBlobSize);
	SetDlgItemText(IDC_STATIC_BLOB, str);

	*pResult = 0;
}

void CDlgStepScratch::SetParameter(const INFO_MARS_PARA* pstInfo)
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

void CDlgStepScratch::OnCheckImgLog()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
	CStepScratch* pStepScratch = dynamic_cast<CStepScratch*>(pStep);
	if (pStepScratch)
	{
		CButton *pWnd = (CButton *)GetDlgItem(IDC_SCRATCH_IMG_LOG);
		if (pWnd->GetCheck())
			pStepScratch->m_bImgLog = TRUE;
		else
			pStepScratch->m_bImgLog = FALSE;
	}
}
