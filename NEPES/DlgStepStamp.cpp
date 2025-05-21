// DlgStep01.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "DlgStepStamp.h"
#include "DlgStrobe.h"
#include "DlgPasswd.h"
#include "afxdialogex.h"

#include "CaptureManager.h"
#include "stringres.h"

#include "Util/Util.h"
#include "Inspection\until_func.h"

// CDlgStepStamp dialog

IMPLEMENT_DYNAMIC(CDlgStepStamp, CDialogEx)

CDlgStepStamp::CDlgStepStamp(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgStepStamp::IDD, pParent)
	, m_iProbability(0)
	, m_iBlobSize(0)
{
	m_eCameraPos = TYPE_CAMERAPOS_NONE;
}

CDlgStepStamp::~CDlgStepStamp()
{
}

void CDlgStepStamp::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Slider(pDX, IDC_SLIDER_PROBABILITY, m_iProbability);
	DDX_Slider(pDX, IDC_SLIDER_BLOB, m_iBlobSize);
	DDX_Control(pDX, IDC_SLIDER_PROBABILITY, m_ctlSliderProbability);
	DDX_Control(pDX, IDC_SLIDER_BLOB, m_ctlSliderBlobSize);
}

BOOL CDlgStepStamp::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (IDOK == wParam)
	{
		return TRUE;
	}
	return CDialogEx::OnCommand(wParam, lParam);
}

BOOL CDlgStepStamp::PreTranslateMessage(MSG* pMsg)
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

BOOL CDlgStepStamp::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_ctlSliderProbability.SetRange(0, 255);
	m_ctlSliderBlobSize.SetRange(0, 100);

	{
		const INFO_INSPECTION_STAMP* pInfoStamp = GetInspectionInfo();
		UpdateCtrlStepStamp(pInfoStamp);		
	}

	// check box : image log
	{
		CButton *pWnd = (CButton *)GetDlgItem(IDC_STAMP_IMG_LOG);
		// Version 1.3.8.1
		CButton *pWndCompress = (CButton *)GetDlgItem(IDC_STAMP_IMG_COMPRESS);

		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
		CInspection* pInspection = pCaptureManager->GetInspection();
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
		CStepStamp* pStepStamp = dynamic_cast<CStepStamp*>(pStep);

		if (pStepStamp)
		{
			if (pStepStamp->GetInformation()->m_stParaStampImage.imageWrite)
			{
				pWnd->SetCheck(true);
			}
			else
			{
				pWnd->SetCheck(false);
			}
			// Version 1.3.8.1
			if (pStepStamp->GetInformation()->m_stParaStampImage.imageCompress)
			{
				pWndCompress->SetCheck(true);
			}
			else
			{
				pWndCompress->SetCheck(false);
			}
		}
	}

	return TRUE;
}


BEGIN_MESSAGE_MAP(CDlgStepStamp, CDialogEx)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BTN_APPLY, &CDlgStepStamp::OnBnClickedBtnApply)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_PROBABILITY, &CDlgStepStamp::OnNMCustomdrawSliderProbability)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_BLOB, &CDlgStepStamp::OnNMCustomdrawSliderBlob)
	ON_BN_CLICKED(IDC_STAMP_IMG_LOG, &CDlgStepStamp::OnCheckImgLog)
	ON_BN_CLICKED(IDC_BTN_STROBE, &CDlgStepStamp::OnBnClickedBtnStrobe)
	// Version 1.3.8.1
	ON_BN_CLICKED(IDC_STAMP_IMG_COMPRESS, &CDlgStepStamp::OnCheckImgCompress)
END_MESSAGE_MAP()


// CDlgStepStamp message handlers
void CDlgStepStamp::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CRect rect;
	GetClientRect(&rect);

}

void CDlgStepStamp::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

}

void CDlgStepStamp::OnBnClickedBtnStrobe()
{
	CDlgPasswd dlgPasswd;
	if (IDOK == dlgPasswd.DoModal())
	{
		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
		const INFO_INSPECTION_STAMP* pstCurInfo = GetInspectionInfo();

		CDlgStrobe dlg;
		for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
		{
			dlg.m_pstStepStrobe[i].m_eStrobeType = pstCurInfo->m_pstStepStrobe[i].m_eStrobeType;
			dlg.m_pstStepStrobe[i].m_nStrobeBrightness = pstCurInfo->m_pstStepStrobe[i].m_nStrobeBrightness;
		}

		if (IDOK == dlg.DoModal())
		{
			INFO_INSPECTION_STAMP stInspectionStamp;
			const INFO_INSPECTION_STAMP* pstCurInfo = GetInspectionInfo();
			memcpy(&stInspectionStamp, pstCurInfo, sizeof(INFO_INSPECTION_STAMP));

			for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
			{
				stInspectionStamp.m_pstStepStrobe[i].m_eStrobeType = dlg.m_pstStepStrobe[i].m_eStrobeType;
				stInspectionStamp.m_pstStepStrobe[i].m_nStrobeBrightness = dlg.m_pstStepStrobe[i].m_nStrobeBrightness;
			}

			SetInspectionInfo(&stInspectionStamp);

			// Strobe Type & Brightness
			{
				CString szStrobe01;

				if (TYPE_STROBE_COXIAL == stInspectionStamp.m_pstStepStrobe[0].m_eStrobeType)
					szStrobe01.Format(_T("%s (%d)"), STR_STROBE_COAXIAL, stInspectionStamp.m_pstStepStrobe[0].m_nStrobeBrightness);
				else if (TYPE_STROBE_RING == stInspectionStamp.m_pstStepStrobe[0].m_eStrobeType)
					szStrobe01.Format(_T("%s (%d)"), STR_STROBE_RING, stInspectionStamp.m_pstStepStrobe[0].m_nStrobeBrightness);
				else if (TYPE_STROBE_BAR == stInspectionStamp.m_pstStepStrobe[0].m_eStrobeType)
					szStrobe01.Format(_T("%s (%d)"), STR_STROBE_BAR, stInspectionStamp.m_pstStepStrobe[0].m_nStrobeBrightness);
				else
					szStrobe01.Format(_T("%s"), STR_STROBE_OFF);
				GetDlgItem(IDC_EDIT_STROBE01)->SetWindowText(szStrobe01);

				CString szStrobe02;

				if (TYPE_STROBE_COXIAL == stInspectionStamp.m_pstStepStrobe[1].m_eStrobeType)
					szStrobe02.Format(_T("%s (%d)"), STR_STROBE_COAXIAL, stInspectionStamp.m_pstStepStrobe[1].m_nStrobeBrightness);
				else if (TYPE_STROBE_RING == stInspectionStamp.m_pstStepStrobe[1].m_eStrobeType)
					szStrobe02.Format(_T("%s (%d)"), STR_STROBE_RING, stInspectionStamp.m_pstStepStrobe[1].m_nStrobeBrightness);
				else if (TYPE_STROBE_BAR == stInspectionStamp.m_pstStepStrobe[1].m_eStrobeType)
					szStrobe02.Format(_T("%s (%d)"), STR_STROBE_BAR, stInspectionStamp.m_pstStepStrobe[1].m_nStrobeBrightness);
				else
					szStrobe02.Format(_T("%s"), STR_STROBE_OFF);
				GetDlgItem(IDC_EDIT_STROBE02)->SetWindowText(szStrobe02);
			}
		}
	}
}

void CDlgStepStamp::OnBnClickedBtnApply()
{
	UpdateData();
	
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	INFO_INSPECTION_STAMP stInspectionStamp;
	const INFO_INSPECTION_STAMP* pstCurInfo = GetInspectionInfo();
	memcpy(&stInspectionStamp, pstCurInfo, sizeof(INFO_INSPECTION_STAMP));

	{
		stInspectionStamp.m_stParaStamp.prob_thres = static_cast<float>(m_iProbability);
		stInspectionStamp.m_stParaStamp.blobSize_thres = static_cast<float>(m_iBlobSize);
		SetInspectionInfo(&stInspectionStamp);

		INFO_IMAGE* pRefImage = NULL;
		this->GetParent()->SendMessage(WM_NOTIFY_SEQUENCE_REQUESET, (WPARAM)(&pRefImage), (LPARAM)0);

		// Test run application
		CSampleSide sample;
		cv::Mat tmpImg = cv::Mat(pRefImage->m_stFrame.m_dwHeight, pRefImage->m_stFrame.m_dwWidth, CV_8UC3, pRefImage->m_pBuffer, pRefImage->m_stFrame.m_dwPitch);
		cv::Mat matImg = tmpImg.clone();

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
				lParam = (LPARAM)&sample.m_StampResult;
			else if (TYPE_CAMERAPOS_SECOND == m_eCameraPos)
				lParam = (LPARAM)&sample.m_StampResult;
			this->GetParent()->SendMessage(WM_NOTIFY_SEQUENCE_EDIT_STEPDONE, (WPARAM)(m_eStep), lParam);
			if (sample.m_StampResult.m_bResult == false)
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


void CDlgStepStamp::UpdateCameraPos(TYPE_CAMERAPOS ePos)
{
	m_eCameraPos = ePos;
}

void CDlgStepStamp::UpdateSelectedRoiPos(const INFO_RECT_ROI* pROI)
{
	if (NULL == pROI)
		return;

	INFO_INSPECTION_STAMP stInspectionStamp;
	const INFO_INSPECTION_STAMP* pstCurInfo = GetInspectionInfo();
	memcpy(&stInspectionStamp, pstCurInfo, sizeof(INFO_INSPECTION_STAMP));

	stInspectionStamp.m_stRoi = *pROI;		// Change Roi;
	
	SetInspectionInfo(&stInspectionStamp);

}

void CDlgStepStamp::SetDefaultValue()
{
	;
}

void CDlgStepStamp::UpdateCtrlStepStamp(const INFO_INSPECTION_STAMP* pInspectStamp)
{
	if (NULL == pInspectStamp)
		return;

	// Strobe Type & Brightness
	{
		CString szStrobe01;

		if (TYPE_STROBE_COXIAL == pInspectStamp->m_pstStepStrobe[0].m_eStrobeType)
			szStrobe01.Format(_T("%s (%d)"), STR_STROBE_COAXIAL, pInspectStamp->m_pstStepStrobe[0].m_nStrobeBrightness);
		else if (TYPE_STROBE_RING == pInspectStamp->m_pstStepStrobe[0].m_eStrobeType)
			szStrobe01.Format(_T("%s (%d)"), STR_STROBE_RING, pInspectStamp->m_pstStepStrobe[0].m_nStrobeBrightness);
		else if (TYPE_STROBE_BAR == pInspectStamp->m_pstStepStrobe[0].m_eStrobeType)
			szStrobe01.Format(_T("%s (%d)"), STR_STROBE_BAR, pInspectStamp->m_pstStepStrobe[0].m_nStrobeBrightness);
		else
			szStrobe01.Format(_T("%s"), STR_STROBE_OFF);
		GetDlgItem(IDC_EDIT_STROBE01)->SetWindowText(szStrobe01);
	}
	{
		CString szStrobe02;

		if (TYPE_STROBE_COXIAL == pInspectStamp->m_pstStepStrobe[1].m_eStrobeType)
			szStrobe02.Format(_T("%s (%d)"), STR_STROBE_COAXIAL, pInspectStamp->m_pstStepStrobe[1].m_nStrobeBrightness);
		else if (TYPE_STROBE_RING == pInspectStamp->m_pstStepStrobe[1].m_eStrobeType)
			szStrobe02.Format(_T("%s (%d)"), STR_STROBE_RING, pInspectStamp->m_pstStepStrobe[1].m_nStrobeBrightness);
		else if (TYPE_STROBE_BAR == pInspectStamp->m_pstStepStrobe[1].m_eStrobeType)
			szStrobe02.Format(_T("%s (%d)"), STR_STROBE_BAR, pInspectStamp->m_pstStepStrobe[1].m_nStrobeBrightness);
		else
			szStrobe02.Format(_T("%s"), STR_STROBE_OFF);
		GetDlgItem(IDC_EDIT_STROBE02)->SetWindowText(szStrobe02);
	}

	// Version 1.3.8.1
	((CButton*)GetDlgItem(IDC_STAMP_IMG_LOG))->SetCheck(pInspectStamp->m_stParaStampImage.imageWrite);
	((CButton*)GetDlgItem(IDC_STAMP_IMG_COMPRESS))->SetCheck(pInspectStamp->m_stParaStampImage.imageCompress);

	SetParameter(&pInspectStamp->m_stParaStamp);
}


const INFO_INSPECTION_STAMP* CDlgStepStamp::GetInspectionInfo()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
	CStepStamp* pStepStamp = dynamic_cast<CStepStamp*>(pStep);
	if (pStepStamp)
	{
		const INFO_INSPECTION_STAMP* pStampInfo = pStepStamp->GetInformation();
		return pStampInfo;
	}
	return NULL;
}

BOOL CDlgStepStamp::SetInspectionInfo(const INFO_INSPECTION_STAMP* pstInfo)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	BOOL bResult = FALSE;
	CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
	CStepStamp* pStepStamp = dynamic_cast<CStepStamp*>(pStep);
	if (pStepStamp)
	{
		bResult = pStepStamp->SetInformation(pstInfo);
	}

	/// Update Backup
	{
		UpdateInspectionInfoBackup();
	}
	//*/
	return bResult;
}

void CDlgStepStamp::UpdateInspectionInfoBackup()
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

void CDlgStepStamp::OnNMCustomdrawSliderProbability(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);

	UpdateData();
	CString str;
	str.Format("%d", m_iProbability);
	SetDlgItemText(IDC_STATIC_PROBABILITY, str);

	*pResult = 0;
}

void CDlgStepStamp::OnNMCustomdrawSliderBlob(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);

	UpdateData();
	CString str;
	str.Format("%d", m_iBlobSize);
	SetDlgItemText(IDC_STATIC_BLOB, str);

	*pResult = 0;
}

void CDlgStepStamp::SetParameter(const INFO_MARS_PARA* pstInfo)
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


void CDlgStepStamp::OnCheckImgLog()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
	CStepStamp* pStepStamp = dynamic_cast<CStepStamp*>(pStep);
	if (pStepStamp)
	{
		CButton *pWnd = (CButton *)GetDlgItem(IDC_STAMP_IMG_LOG);
		if (pWnd->GetCheck())
			pStepStamp->m_bImgLog = TRUE;
		else
			pStepStamp->m_bImgLog = FALSE;
	}

	// Version 1.3.8.1
	INFO_INSPECTION_STAMP stInspectionStamp;
	const INFO_INSPECTION_STAMP* pstCurInfo = GetInspectionInfo();
	memcpy(&stInspectionStamp, pstCurInfo, sizeof(INFO_INSPECTION_STAMP));

	stInspectionStamp.m_stParaStampImage.imageWrite = pStepStamp->m_bImgLog;

	SetInspectionInfo(&stInspectionStamp);
}

// Version 1.3.8.1
void CDlgStepStamp::OnCheckImgCompress()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
	CStepStamp* pStepStamp = dynamic_cast<CStepStamp*>(pStep);
	if (pStepStamp)
	{
		CButton *pWnd = (CButton *)GetDlgItem(IDC_STAMP_IMG_COMPRESS);
		if (pWnd->GetCheck())
			pStepStamp->m_bImgCompress = TRUE;
		else
			pStepStamp->m_bImgCompress = FALSE;
	}

	// Version 1.3.8.1
	INFO_INSPECTION_STAMP stInspectionStamp;
	const INFO_INSPECTION_STAMP* pstCurInfo = GetInspectionInfo();
	memcpy(&stInspectionStamp, pstCurInfo, sizeof(INFO_INSPECTION_STAMP));

	stInspectionStamp.m_stParaStampImage.imageCompress = pStepStamp->m_bImgCompress;

	SetInspectionInfo(&stInspectionStamp);
}
