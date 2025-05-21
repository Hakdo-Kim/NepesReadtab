// DlgStep01.cpp : implementation file
//
#include "stdafx.h"
#include "NEPES.h"
#include "DlgStepStain.h"
#include "DlgStrobe.h"
#include "DlgPasswd.h"
#include "afxdialogex.h"

#include "CaptureManager.h"
#include "stringres.h"
#include "Util/Util.h"

// CDlgStepStain dialog

IMPLEMENT_DYNAMIC(CDlgStepStain, CDialogEx)

CDlgStepStain::CDlgStepStain(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgStepStain::IDD, pParent)
	, m_iProbability(0)
	, m_iBlobSize(0)
{
	m_eCameraPos = TYPE_CAMERAPOS_NONE;
}

CDlgStepStain::~CDlgStepStain()
{
}

void CDlgStepStain::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Slider(pDX, IDC_SLIDER_PROBABILITY, m_iProbability);
	DDX_Slider(pDX, IDC_SLIDER_BLOB, m_iBlobSize);
	DDX_Control(pDX, IDC_SLIDER_PROBABILITY, m_ctlSliderProbability);
	DDX_Control(pDX, IDC_SLIDER_BLOB, m_ctlSliderBlobSize);
}

BOOL CDlgStepStain::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (IDOK == wParam)
	{
		return TRUE;
	}
	return CDialogEx::OnCommand(wParam, lParam);
}

BOOL CDlgStepStain::PreTranslateMessage(MSG* pMsg)
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

BOOL CDlgStepStain::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_ctlSliderProbability.SetRange(0, 255);
	m_ctlSliderBlobSize.SetRange(0, 100);

	{
		const INFO_INSPECTION_STAIN* pInfoStain = GetInspectionInfo();
		UpdateCtrlStepStain(pInfoStain);

		SetParameter(&pInfoStain->m_stParaStain);
	}

	// check box : image log
	{
		CButton* pWnd			= (CButton*)GetDlgItem(IDC_STAIN_IMG_LOG);
		// Version 1.3.8.1
		CButton *pWndCompress	= (CButton *)GetDlgItem(IDC_STAIN_IMG_COMPRESS);

		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
		CInspection* pInspection = pCaptureManager->GetInspection();
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
		CStepStain* pStepStain = dynamic_cast<CStepStain*>(pStep);

		if (pStepStain)
		{
			if (pStepStain->GetInformation()->m_stParaStainImage.imageWrite)
			{
				pWnd->SetCheck(true);
			}
			else
			{
				pWnd->SetCheck(false);
			}
			// Version 1.3.8.1
			if (pStepStain->GetInformation()->m_stParaStainImage.imageCompress)
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


BEGIN_MESSAGE_MAP(CDlgStepStain, CDialogEx)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BTN_APPLY, &CDlgStepStain::OnBnClickedBtnApply)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_PROBABILITY, &CDlgStepStain::OnNMCustomdrawSliderProbability)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_BLOB, &CDlgStepStain::OnNMCustomdrawSliderBlob)
	ON_BN_CLICKED(IDC_STAIN_IMG_LOG, &CDlgStepStain::OnCheckImgLog)
	ON_BN_CLICKED(IDC_STEP1_PICTURE_TEST, &CDlgStepStain::OnStep1PictureTest)
	ON_BN_CLICKED(IDC_SET_TRAINED_FILE, &CDlgStepStain::OnSetTrainedFile)
	ON_BN_CLICKED(IDC_BTN_STROBE, &CDlgStepStain::OnBnClickedBtnStrobe)
	// Version 1.3.8.1
	ON_BN_CLICKED(IDC_STAIN_IMG_COMPRESS, &CDlgStepStain::OnCheckImgCompress)
END_MESSAGE_MAP()


// CDlgStepStain message handlers
void CDlgStepStain::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CRect rect;
	GetClientRect(&rect);

}

void CDlgStepStain::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

}

void CDlgStepStain::OnBnClickedBtnStrobe()
{
	CDlgPasswd dlgPasswd;
	if (IDOK == dlgPasswd.DoModal())
	{
		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
		const INFO_INSPECTION_STAIN* pstCurInfo = GetInspectionInfo();

		CDlgStrobe dlg;
		for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
		{
			dlg.m_pstStepStrobe[i].m_eStrobeType = pstCurInfo->m_pstStepStrobe[i].m_eStrobeType;
			dlg.m_pstStepStrobe[i].m_nStrobeBrightness = pstCurInfo->m_pstStepStrobe[i].m_nStrobeBrightness;
		}

		if (IDOK == dlg.DoModal())
		{
			INFO_INSPECTION_STAIN stInspectionStain;
			const INFO_INSPECTION_STAIN* pstCurInfo = GetInspectionInfo();
			memcpy(&stInspectionStain, pstCurInfo, sizeof(INFO_INSPECTION_STAIN));

			for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
			{
				stInspectionStain.m_pstStepStrobe[i].m_eStrobeType = dlg.m_pstStepStrobe[i].m_eStrobeType;
				stInspectionStain.m_pstStepStrobe[i].m_nStrobeBrightness = dlg.m_pstStepStrobe[i].m_nStrobeBrightness;
			}

			SetInspectionInfo(&stInspectionStain);

			// Strobe Type & Brightness
			{
#ifdef DEF_APPLY_SETTING
				CString szStrobe01;

				if (TYPE_STROBE_COXIAL == stInspectionStain.m_pstStepStrobe[0].m_eStrobeType)
					szStrobe01.Format(_T("%s (%d)"), STR_STROBE_COAXIAL, stInspectionStain.m_pstStepStrobe[0].m_nStrobeBrightness);
				else if (TYPE_STROBE_RING == stInspectionStain.m_pstStepStrobe[0].m_eStrobeType)
					szStrobe01.Format(_T("%s (%d)"), STR_STROBE_RING, stInspectionStain.m_pstStepStrobe[0].m_nStrobeBrightness);
				else if (TYPE_STROBE_BAR == stInspectionStain.m_pstStepStrobe[0].m_eStrobeType)
					szStrobe01.Format(_T("%s (%d)"), STR_STROBE_BAR, stInspectionStain.m_pstStepStrobe[0].m_nStrobeBrightness);
				else
					szStrobe01.Format(_T("%s"), STR_STROBE_OFF);
				GetDlgItem(IDC_EDIT_STROBE01)->SetWindowText(szStrobe01);

				CString szStrobe02;

				if (TYPE_STROBE_COXIAL == stInspectionStain.m_pstStepStrobe[1].m_eStrobeType)
					szStrobe02.Format(_T("%s (%d)"), STR_STROBE_COAXIAL, stInspectionStain.m_pstStepStrobe[1].m_nStrobeBrightness);
				else if (TYPE_STROBE_RING == stInspectionStain.m_pstStepStrobe[1].m_eStrobeType)
					szStrobe02.Format(_T("%s (%d)"), STR_STROBE_RING, stInspectionStain.m_pstStepStrobe[1].m_nStrobeBrightness);
				else if (TYPE_STROBE_BAR == stInspectionStain.m_pstStepStrobe[1].m_eStrobeType)
					szStrobe02.Format(_T("%s (%d)"), STR_STROBE_BAR, stInspectionStain.m_pstStepStrobe[1].m_nStrobeBrightness);
				else
					szStrobe02.Format(_T("%s"), STR_STROBE_OFF);
				GetDlgItem(IDC_EDIT_STROBE02)->SetWindowText(szStrobe02);
#endif
			}
		}
	}
}


void CDlgStepStain::OnBnClickedBtnApply()
{
	UpdateData();

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	INFO_INSPECTION_STAIN stInspectionStain;
	const INFO_INSPECTION_STAIN* pstCurInfo = GetInspectionInfo();
	memcpy(&stInspectionStain, pstCurInfo, sizeof(INFO_INSPECTION_STAIN));

	{
		stInspectionStain.m_stParaStain.prob_thres = static_cast<float>(m_iProbability);
		stInspectionStain.m_stParaStain.blobSize_thres = static_cast<float>(m_iBlobSize);
		SetInspectionInfo(&stInspectionStain);

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
				lParam = (LPARAM)&sample.m_StainResult;
			else if (TYPE_CAMERAPOS_SECOND == m_eCameraPos)
				lParam = (LPARAM)&sample.m_StainResult;

			this->GetParent()->SendMessage(WM_NOTIFY_SEQUENCE_EDIT_STEPDONE, (WPARAM)(m_eStep), lParam);
			if (sample.m_StainResult.m_bResult == false)
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



void CDlgStepStain::UpdateCameraPos(TYPE_CAMERAPOS ePos)
{
	m_eCameraPos = ePos;
}

void CDlgStepStain::UpdateSelectedRoiPos(const INFO_RECT_ROI* pROI)
{
	if (NULL == pROI)
		return;
	
	INFO_INSPECTION_STAIN stInspectionStain;
	const INFO_INSPECTION_STAIN* pstCurInfo = GetInspectionInfo();
	memcpy(&stInspectionStain, pstCurInfo, sizeof(INFO_INSPECTION_STAIN));

	stInspectionStain.m_stRoi = *pROI;		// Change Roi

	SetInspectionInfo(&stInspectionStain);
}

void CDlgStepStain::SetDefaultValue()
{
	;
}

void CDlgStepStain::UpdateCtrlStepStain(const INFO_INSPECTION_STAIN* pInspectStain)
{
	if (NULL == pInspectStain)
		return;

	// Strobe Type & Brightness
	{
		CString szStrobe01;
#ifdef DEF_APPLY_SETTING
		if (TYPE_STROBE_COXIAL == pInspectStain->m_pstStepStrobe[0].m_eStrobeType)
			szStrobe01.Format(_T("%s (%d)"), STR_STROBE_COAXIAL, pInspectStain->m_pstStepStrobe[0].m_nStrobeBrightness);
		else if (TYPE_STROBE_RING == pInspectStain->m_pstStepStrobe[0].m_eStrobeType)
			szStrobe01.Format(_T("%s (%d)"), STR_STROBE_RING, pInspectStain->m_pstStepStrobe[0].m_nStrobeBrightness);
		else if (TYPE_STROBE_BAR == pInspectStain->m_pstStepStrobe[0].m_eStrobeType)
			szStrobe01.Format(_T("%s (%d)"), STR_STROBE_BAR, pInspectStain->m_pstStepStrobe[0].m_nStrobeBrightness);
		else
			szStrobe01.Format(_T("%s"), STR_STROBE_OFF);
#else
		szStrobe01.Format(_T("%s (%d)"), STR_STROBE_RING, 50);
#endif 
		GetDlgItem(IDC_EDIT_STROBE01)->SetWindowText(szStrobe01);
	}
	{
		CString szStrobe02;
#ifdef DEF_APPLY_SETTING
		if (TYPE_STROBE_COXIAL == pInspectStain->m_pstStepStrobe[1].m_eStrobeType)
			szStrobe02.Format(_T("%s (%d)"), STR_STROBE_COAXIAL, pInspectStain->m_pstStepStrobe[1].m_nStrobeBrightness);
		else if (TYPE_STROBE_RING == pInspectStain->m_pstStepStrobe[1].m_eStrobeType)
			szStrobe02.Format(_T("%s (%d)"), STR_STROBE_RING, pInspectStain->m_pstStepStrobe[1].m_nStrobeBrightness);
		else if (TYPE_STROBE_BAR == pInspectStain->m_pstStepStrobe[1].m_eStrobeType)
			szStrobe02.Format(_T("%s (%d)"), STR_STROBE_BAR, pInspectStain->m_pstStepStrobe[1].m_nStrobeBrightness);
		else
			szStrobe02.Format(_T("%s"), STR_STROBE_OFF);
#else
		szStrobe02.Format(_T("%s"), STR_STROBE_OFF);
#endif
		GetDlgItem(IDC_EDIT_STROBE02)->SetWindowText(szStrobe02);
	}

	// Version 1.3.8.1
	((CButton*)GetDlgItem(IDC_STAIN_IMG_LOG))->SetCheck(pInspectStain->m_stParaStainImage.imageWrite);
	((CButton*)GetDlgItem(IDC_STAIN_IMG_COMPRESS))->SetCheck(pInspectStain->m_stParaStainImage.imageCompress);

	SetParameter(&pInspectStain->m_stParaStain);
}

const INFO_INSPECTION_STAIN* CDlgStepStain::GetInspectionInfo()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();
	

	CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
	CStepStain* pStepStain = dynamic_cast<CStepStain*>(pStep);
	if (pStepStain)
	{
		const INFO_INSPECTION_STAIN* pStainInfo = pStepStain->GetInformation();
		return pStainInfo;
	}
	return NULL;
}

BOOL CDlgStepStain::SetInspectionInfo(const INFO_INSPECTION_STAIN* pstInfo)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	BOOL bResult = FALSE;
	CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
	CStepStain* pStepStain = dynamic_cast<CStepStain*>(pStep);
	if (pStepStain)
	{
		bResult = pStepStain->SetInformation(pstInfo);
	}

	/// Update Backup
	{
		UpdateInspectionInfoBackup();
	}
	//*/
	return bResult;
}

void CDlgStepStain::UpdateInspectionInfoBackup()
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

void CDlgStepStain::OnNMCustomdrawSliderProbability(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);

	UpdateData();
	CString str;
	str.Format("%d", m_iProbability);
	SetDlgItemText(IDC_STATIC_PROBABILITY, str);

	*pResult = 0;
}

void CDlgStepStain::OnNMCustomdrawSliderBlob(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);

	UpdateData();
	CString str;
	str.Format("%d", m_iBlobSize);
	SetDlgItemText(IDC_STATIC_BLOB, str);

	*pResult = 0;
}

void CDlgStepStain::SetParameter(const INFO_MARS_PARA* pstInfo)
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

void CDlgStepStain::OnCheckImgLog()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
	CStepStain* pStepStain = dynamic_cast<CStepStain*>(pStep);
	if (pStepStain)
	{
		CButton *pWnd = (CButton *)GetDlgItem(IDC_STAIN_IMG_LOG);
		if (pWnd->GetCheck())
			pStepStain->m_bImgLog = TRUE;
		else
			pStepStain->m_bImgLog = FALSE;
	}

	// Version 1.3.7.1
	INFO_INSPECTION_STAIN stInspectionStain;
	const INFO_INSPECTION_STAIN* pstCurInfo = GetInspectionInfo();
	memcpy(&stInspectionStain, pstCurInfo, sizeof(INFO_INSPECTION_STAIN));

	stInspectionStain.m_stParaStainImage.imageWrite = pStepStain->m_bImgLog;

	SetInspectionInfo(&stInspectionStain);
}

// Version 1.3.8.1
void CDlgStepStain::OnCheckImgCompress()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
	CStepStain* pStepStain = dynamic_cast<CStepStain*>(pStep);
	if (pStepStain)
	{
		CButton *pWnd = (CButton *)GetDlgItem(IDC_STAIN_IMG_COMPRESS);
		if (pWnd->GetCheck())
			pStepStain->m_bImgCompress = TRUE;
		else
			pStepStain->m_bImgCompress = FALSE;
	}

	INFO_INSPECTION_STAIN stInspectionStain;
	const INFO_INSPECTION_STAIN* pstCurInfo = GetInspectionInfo();
	memcpy(&stInspectionStain, pstCurInfo, sizeof(INFO_INSPECTION_STAIN));

	stInspectionStain.m_stParaStainImage.imageCompress = pStepStain->m_bImgCompress;

	SetInspectionInfo(&stInspectionStain);
}


void CDlgStepStain::OnStep1PictureTest()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	TCHAR szLocation[MAX_PATH] = { 0, };
	TCHAR szFilePath[MAX_PATH] = { 0, };

	CUtil::GetCurrentDirectory(szLocation, MAX_PATH);

	if (CUtil::SelectFile(NULL, szFilePath, MAX_PATH, _T("*.PNG; *.BMP; *.JPEG;"), _T("Test Image Files(*.PNG; *.BMP; *.JPEG;) | *.PNG; *.BMP; *.JPEG;|"), NULL, TRUE))
	{
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
		CStepStain* pStepStain = dynamic_cast<CStepStain*>(pStep);
		if (pStepStain)
		{
			pStepStain->OnePictureTest(szFilePath);
		}
	}
}

void CDlgStepStain::OnSetTrainedFile()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CInspection* pInspection = pCaptureManager->GetInspection();

	TCHAR szLocation[MAX_PATH] = { 0, };
	TCHAR szFilePath[MAX_PATH] = { 0, };
	
	CUtil::GetCurrentDirectory(szLocation, MAX_PATH);
	if (CUtil::SelectFile(NULL, szFilePath, MAX_PATH, _T("*.dat"), _T("Train Files(*.dat) | *.dat|"), NULL, TRUE))
	{
		CStep* pStep = pInspection->GetInsectionStep(m_eCameraPos, m_eStep);
		CStepStain* pStepStain = dynamic_cast<CStepStain*>(pStep);
		if (pStepStain)
		{
			pStepStain->setTrainFile(szFilePath);
		}
	}
}
