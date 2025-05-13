// DlgSizeGain.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "DlgSizeGain.h"
#include "afxdialogex.h"
#include "DlgStepSize.h"
#include "CaptureManager.h"

#include "Util/Util.h"


// CDlgSizeGain dialog

IMPLEMENT_DYNAMIC(CDlgSizeGain, CDialogEx)

CDlgSizeGain::CDlgSizeGain(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgSizeGain::IDD, pParent)
	, m_dd(1.0)
	, m_dL(1.0)
	, m_dW(1.0)
	, m_dI1(1.0)
	, m_dI2(1.0)
	, m_dI3(1.0)
	, m_dM1(1.0)
	, m_dM2(1.0)
	, m_dS1(1.0)
	, m_dS2(1.0)
	, m_dS3(1.0)
	, m_dS4(1.0)
	, m_dS5(1.0)
	, m_dX1(1.0)
	, m_dX2(1.0)
	, m_dR1(1.0)
	, m_dR2(1.0)
	, m_dR3(1.0)
	, m_dR4(1.0)
	// Version 1.3.7.8
	, m_dR5(1.0)
	, m_dR6(1.0)
	, m_dSS1(1.0)
	, m_dSS2(1.0)
	, m_dSS3(1.0)
{

}

CDlgSizeGain::~CDlgSizeGain()
{
}

void CDlgSizeGain::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_GAIN_D, m_dd);		DDV_MinMaxDouble(pDX, m_dd, 0.001, 100.000);
	DDX_Text(pDX, IDC_EDIT_GAIN_L, m_dL);		DDV_MinMaxDouble(pDX, m_dL, 0.001, 100.000);
	DDX_Text(pDX, IDC_EDIT_GAIN_W, m_dW);		DDV_MinMaxDouble(pDX, m_dW, 0.001, 100.000);
	DDX_Text(pDX, IDC_EDIT_GAIN_I1, m_dI1);		DDV_MinMaxDouble(pDX, m_dI1, 0.001, 100.000);
	DDX_Text(pDX, IDC_EDIT_GAIN_I2, m_dI2);		DDV_MinMaxDouble(pDX, m_dI2, 0.001, 100.000);
	DDX_Text(pDX, IDC_EDIT_GAIN_I3, m_dI3);		DDV_MinMaxDouble(pDX, m_dI3, 0.001, 100.000);
	DDX_Text(pDX, IDC_EDIT_GAIN_M1, m_dM1);		DDV_MinMaxDouble(pDX, m_dM1, 0.001, 100.000);
	DDX_Text(pDX, IDC_EDIT_GAIN_M2, m_dM2);		DDV_MinMaxDouble(pDX, m_dM2, 0.001, 100.000);
	DDX_Text(pDX, IDC_EDIT_GAIN_S1, m_dS1);		DDV_MinMaxDouble(pDX, m_dS1, 0.001, 100.000);
	DDX_Text(pDX, IDC_EDIT_GAIN_S2, m_dS2);		DDV_MinMaxDouble(pDX, m_dS2, 0.001, 100.000);
	DDX_Text(pDX, IDC_EDIT_GAIN_S3, m_dS3);		DDV_MinMaxDouble(pDX, m_dS3, 0.001, 100.000);
	DDX_Text(pDX, IDC_EDIT_GAIN_S4, m_dS4);		DDV_MinMaxDouble(pDX, m_dS4, 0.001, 100.000);
	DDX_Text(pDX, IDC_EDIT_GAIN_S5, m_dS5);		DDV_MinMaxDouble(pDX, m_dS5, 0.001, 100.000);
	DDX_Text(pDX, IDC_EDIT_GAIN_X1, m_dX1);		DDV_MinMaxDouble(pDX, m_dX1, 0.001, 100.000);
	DDX_Text(pDX, IDC_EDIT_GAIN_X2, m_dX2);		DDV_MinMaxDouble(pDX, m_dX2, 0.001, 100.000);
	DDX_Text(pDX, IDC_EDIT_GAIN_R1, m_dR1);		DDV_MinMaxDouble(pDX, m_dR1, 0.001, 100.000);
	DDX_Text(pDX, IDC_EDIT_GAIN_R2, m_dR2);		DDV_MinMaxDouble(pDX, m_dR2, 0.001, 100.000);
	DDX_Text(pDX, IDC_EDIT_GAIN_R3, m_dR3);		DDV_MinMaxDouble(pDX, m_dR3, 0.001, 100.000);
	DDX_Text(pDX, IDC_EDIT_GAIN_R4, m_dR4);		DDV_MinMaxDouble(pDX, m_dR4, 0.001, 100.000);
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	DDX_Text(pDX, IDC_EDIT_GAIN_R5, m_dR5);		DDV_MinMaxDouble(pDX, m_dR5, 0.001, 100.000);
	DDX_Text(pDX, IDC_EDIT_GAIN_R6, m_dR6);		DDV_MinMaxDouble(pDX, m_dR6, 0.001, 100.000);
	DDX_Text(pDX, IDC_EDIT_GAIN_SS1, m_dSS1);	DDV_MinMaxDouble(pDX, m_dSS1, 0.001, 100.000);
	DDX_Text(pDX, IDC_EDIT_GAIN_SS2, m_dSS2);	DDV_MinMaxDouble(pDX, m_dSS2, 0.001, 100.000);
	DDX_Text(pDX, IDC_EDIT_GAIN_SS3, m_dSS3);	DDV_MinMaxDouble(pDX, m_dSS3, 0.001, 100.000);

	DDX_Control(pDX, IDC_EDIT_GAIN_D, m_Editd);
	DDX_Control(pDX, IDC_EDIT_GAIN_L, m_EditL);
	DDX_Control(pDX, IDC_EDIT_GAIN_W, m_EditW);
	DDX_Control(pDX, IDC_EDIT_GAIN_I1, m_EditI1);
	DDX_Control(pDX, IDC_EDIT_GAIN_I2, m_EditI2);
	DDX_Control(pDX, IDC_EDIT_GAIN_I3, m_EditI3);
	DDX_Control(pDX, IDC_EDIT_GAIN_M1, m_EditM1);
	DDX_Control(pDX, IDC_EDIT_GAIN_M2, m_EditM2);
	DDX_Control(pDX, IDC_EDIT_GAIN_S1, m_EditS1);
	DDX_Control(pDX, IDC_EDIT_GAIN_S2, m_EditS2);
	DDX_Control(pDX, IDC_EDIT_GAIN_S3, m_EditS3);
	DDX_Control(pDX, IDC_EDIT_GAIN_S4, m_EditS4);
	DDX_Control(pDX, IDC_EDIT_GAIN_S5, m_EditS5);
	DDX_Control(pDX, IDC_EDIT_GAIN_X1, m_EditX1);
	DDX_Control(pDX, IDC_EDIT_GAIN_X2, m_EditX2);
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	DDX_Control(pDX, IDC_EDIT_GAIN_R1, m_EditR1);
	DDX_Control(pDX, IDC_EDIT_GAIN_R2, m_EditR2);
	DDX_Control(pDX, IDC_EDIT_GAIN_R3, m_EditR3);
	DDX_Control(pDX, IDC_EDIT_GAIN_R4, m_EditR4);
	DDX_Control(pDX, IDC_EDIT_GAIN_R5, m_EditR5);
	DDX_Control(pDX, IDC_EDIT_GAIN_R6, m_EditR6);
	DDX_Control(pDX, IDC_EDIT_GAIN_SS1, m_EditSS1);
	DDX_Control(pDX, IDC_EDIT_GAIN_SS2, m_EditSS2);
	DDX_Control(pDX, IDC_EDIT_GAIN_SS3, m_EditSS3);
}


BEGIN_MESSAGE_MAP(CDlgSizeGain, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgSizeGain::OnBnClickedOk)
	ON_BN_CLICKED(1313, &CDlgSizeGain::OnBnApplyClick)     //#define IDC_APPLY_BUTTON  1313
END_MESSAGE_MAP()


// CDlgSizeGain message handlers


BOOL CDlgSizeGain::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	UpdateData(FALSE);

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_OPTION* pstOption = pCaptureManager->GetOption();

	int idx = 0;
	GetDlgItem(IDC_STATIC_GAIN_D)->SetWindowText(pstOption->m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_GAIN_L)->SetWindowText(pstOption->m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_GAIN_W)->SetWindowText(pstOption->m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_GAIN_I1)->SetWindowText(pstOption->m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_GAIN_I2)->SetWindowText(pstOption->m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_GAIN_I3)->SetWindowText(pstOption->m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_GAIN_M1)->SetWindowText(pstOption->m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_GAIN_M2)->SetWindowText(pstOption->m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_GAIN_S1)->SetWindowText(pstOption->m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_GAIN_S2)->SetWindowText(pstOption->m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_GAIN_S3)->SetWindowText(pstOption->m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_GAIN_S4)->SetWindowText(pstOption->m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_GAIN_S5)->SetWindowText(pstOption->m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_GAIN_X1)->SetWindowText(pstOption->m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_GAIN_X2)->SetWindowText(pstOption->m_stSizeName.m_szName[idx]); idx++;
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	GetDlgItem(IDC_STATIC_GAIN_R1)->SetWindowText(pstOption->m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_GAIN_R2)->SetWindowText(pstOption->m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_GAIN_R3)->SetWindowText(pstOption->m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_GAIN_R4)->SetWindowText(pstOption->m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_GAIN_R5)->SetWindowText(pstOption->m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_GAIN_R6)->SetWindowText(pstOption->m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_GAIN_SS1)->SetWindowText(pstOption->m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_GAIN_SS2)->SetWindowText(pstOption->m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_GAIN_SS3)->SetWindowText(pstOption->m_stSizeName.m_szName[idx]); idx++;

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgSizeGain::OnBnClickedOk()
{
	UpdateData();

	BOOL bInputValueError = FALSE;

	MinMaxCheck(0.001, 100., m_dd, bInputValueError);
	MinMaxCheck(0.001, 100., m_dL, bInputValueError);
	MinMaxCheck(0.001, 100., m_dW, bInputValueError);
	MinMaxCheck(0.001, 100., m_dI1, bInputValueError);
	MinMaxCheck(0.001, 100., m_dI2, bInputValueError);
	MinMaxCheck(0.001, 100., m_dI3, bInputValueError);
	MinMaxCheck(0.001, 100., m_dM1, bInputValueError);
	MinMaxCheck(0.001, 100., m_dM2, bInputValueError);
	MinMaxCheck(0.001, 100., m_dS1, bInputValueError);
	MinMaxCheck(0.001, 100., m_dS2, bInputValueError);
	MinMaxCheck(0.001, 100., m_dS3, bInputValueError);
	MinMaxCheck(0.001, 100., m_dS4, bInputValueError);
	MinMaxCheck(0.001, 100., m_dS5, bInputValueError);
	MinMaxCheck(0.001, 100., m_dX1, bInputValueError);
	MinMaxCheck(0.001, 100., m_dX2, bInputValueError);
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	MinMaxCheck(0.001, 100., m_dR1, bInputValueError);
	MinMaxCheck(0.001, 100., m_dR2, bInputValueError);
	MinMaxCheck(0.001, 100., m_dR3, bInputValueError);
	MinMaxCheck(0.001, 100., m_dR4, bInputValueError);
	MinMaxCheck(0.001, 100., m_dR5, bInputValueError);
	MinMaxCheck(0.001, 100., m_dR6, bInputValueError);
	MinMaxCheck(0.001, 100., m_dSS1, bInputValueError);
	MinMaxCheck(0.001, 100., m_dSS2, bInputValueError);
	MinMaxCheck(0.001, 100., m_dSS3, bInputValueError);

	/*
	if (m_dd < 0.001)
	{
		m_dd = 0.001; bInputValueError = TRUE;
	}
	if (m_dd > 100.)
	{
		m_dd = 100.; bInputValueError = TRUE;
	}
	if (m_dL < 0.001)
	{
		m_dL = 0.001; bInputValueError = TRUE;
	}
	if (m_dL > 100.)
	{
		m_dL = 100.; bInputValueError = TRUE;
	}
	if (m_dW < 0.001)
	{
		m_dW = 0.001; bInputValueError = TRUE;
	}
	if (m_dW > 100.)
	{
		m_dW = 100.; bInputValueError = TRUE;
	}
	if (m_dI1 < 0.001)
	{
		m_dI1 = 0.001; bInputValueError = TRUE;
	}
	if (m_dI1 > 100.)
	{
		m_dI1 = 100.; bInputValueError = TRUE;
	}
	if (m_dI2 < 0.001)
	{
		m_dI2 = 0.001; bInputValueError = TRUE;
	}
	if (m_dI2 > 100.)
	{
		m_dI2 = 100.; bInputValueError = TRUE;
	}
	if (m_dI3 < 0.001)
	{
		m_dI3 = 0.001; bInputValueError = TRUE;
	}
	if (m_dI3 > 100.)
	{
		m_dI3 = 100.; bInputValueError = TRUE;
	}
	if (m_dM1 < 0.001)
	{
		m_dM1 = 0.001; bInputValueError = TRUE;
	}
	if (m_dM1 > 100.)
	{
		m_dM1 = 100.; bInputValueError = TRUE;
	}
	if (m_dM2 < 0.001)
	{
		m_dM2 = 0.001; bInputValueError = TRUE;
	}
	if (m_dM2 > 100.)
	{
		m_dM2 = 100.; bInputValueError = TRUE;
	}
	if (m_dS1 < 0.001)
	{
		m_dS1 = 0.001; bInputValueError = TRUE;
	}
	if (m_dS1 > 100.)
	{
		m_dS1 = 100.; bInputValueError = TRUE;
	}
	if (m_dS2 < 0.001)
	{
		m_dS2 = 0.001; bInputValueError = TRUE;
	}
	if (m_dS2 > 100.)
	{
		m_dS2 = 100.; bInputValueError = TRUE;
	}
	if (m_dS3 < 0.001)
	{
		m_dS3 = 0.001; bInputValueError = TRUE;
	}
	if (m_dS3 > 100.)
	{
		m_dS3 = 100.; bInputValueError = TRUE;
	}
	if (m_dS4 < 0.001)
	{
		m_dS4 = 0.001; bInputValueError = TRUE;
	}
	if (m_dS4 > 100.)
	{
		m_dS4 = 100.; bInputValueError = TRUE;
	}
	if (m_dS5 < 0.001)
	{
		m_dS5 = 0.001; bInputValueError = TRUE;
	}
	if (m_dS5 > 100.)
	{
		m_dS5 = 100.; bInputValueError = TRUE;
	}
	if (m_dX1 < 0.001)
	{
		m_dX1 = 0.001; bInputValueError = TRUE;
	}
	if (m_dX1 > 100.)
	{
		m_dX1 = 100.; bInputValueError = TRUE;
	}
	if (m_dX2 < 0.001)
	{
		m_dX2 = 0.001; bInputValueError = TRUE;
	}	
	if (m_dX2 > 100.)
	{
		m_dX2 = 100.; bInputValueError = TRUE;
	}
	if (m_dR1 < 0.001)
	{
		m_dR1 = 0.001; bInputValueError = TRUE;
	}
	if (m_dR1 > 100.)
	{
		m_dR1 = 100.; bInputValueError = TRUE;
	}
	if (m_dR2 < 0.001)
	{
		m_dR2 = 0.001; bInputValueError = TRUE;
	}
	if (m_dR2 > 100.)
	{
		m_dR2 = 100.; bInputValueError = TRUE;
	}
	if (m_dR3 < 0.001)
	{
		m_dR3 = 0.001; bInputValueError = TRUE;
	}
	if (m_dR3 > 100.)
	{
		m_dR3 = 100.; bInputValueError = TRUE;
	}
	if (m_dR4 < 0.001)
	{
		m_dR4 = 0.001; bInputValueError = TRUE;
	}
	if (m_dR4 > 100.)
	{
		m_dR4 = 100.; bInputValueError = TRUE;
	}
	*/
	UpdateData(FALSE);

	if (bInputValueError)
		return;

	m_stInfoSizeGain.m_stGainName.m_dd	= m_dd;
	m_stInfoSizeGain.m_stGainName.m_dL	= m_dL;
	m_stInfoSizeGain.m_stGainName.m_dW	= m_dW;
	m_stInfoSizeGain.m_stGainName.m_dI1 = m_dI1;
	m_stInfoSizeGain.m_stGainName.m_dI2 = m_dI2;
	m_stInfoSizeGain.m_stGainName.m_dI3 = m_dI3;
	m_stInfoSizeGain.m_stGainName.m_dM1 = m_dM1;
	m_stInfoSizeGain.m_stGainName.m_dM2 = m_dM2;
	m_stInfoSizeGain.m_stGainName.m_dS1 = m_dS1;
	m_stInfoSizeGain.m_stGainName.m_dS2 = m_dS2;
	m_stInfoSizeGain.m_stGainName.m_dS3 = m_dS3;
	m_stInfoSizeGain.m_stGainName.m_dS4 = m_dS4;
	m_stInfoSizeGain.m_stGainName.m_dS5 = m_dS5;
	m_stInfoSizeGain.m_stGainName.m_dX1 = m_dX1;
	m_stInfoSizeGain.m_stGainName.m_dX2 = m_dX2;
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	m_stInfoSizeGain.m_stGainName.m_dR1 = m_dR1;
	m_stInfoSizeGain.m_stGainName.m_dR2 = m_dR2;
	m_stInfoSizeGain.m_stGainName.m_dR3 = m_dR3;
	m_stInfoSizeGain.m_stGainName.m_dR4 = m_dR4;
	m_stInfoSizeGain.m_stGainName.m_dR5 = m_dR5;
	m_stInfoSizeGain.m_stGainName.m_dR6 = m_dR6;
	m_stInfoSizeGain.m_stGainName.m_dSS1 = m_dSS1;
	m_stInfoSizeGain.m_stGainName.m_dSS2 = m_dSS2;
	m_stInfoSizeGain.m_stGainName.m_dSS3 = m_dSS3;

	CDialogEx::OnOK();
}

void CDlgSizeGain::MinMaxCheck(double min, double max, double value, BOOL errorCheck)
{
	if (value < min)
	{
		value = min;
		errorCheck = TRUE;
	}
	if (value > max)
	{
		value = max;
		errorCheck = TRUE;
	}
}

void CDlgSizeGain::SetInfoSizeGain(const INFO_SIZE_GAIN *stInfoSizeGain)
{
	m_dd = stInfoSizeGain->m_stGainName.m_dd;
	m_dL = stInfoSizeGain->m_stGainName.m_dL;
	m_dW = stInfoSizeGain->m_stGainName.m_dW;
	m_dI1 = stInfoSizeGain->m_stGainName.m_dI1;
	m_dI2 = stInfoSizeGain->m_stGainName.m_dI2;
	m_dI3 = stInfoSizeGain->m_stGainName.m_dI3;
	m_dM1 = stInfoSizeGain->m_stGainName.m_dM1;
	m_dM2 = stInfoSizeGain->m_stGainName.m_dM2;
	m_dS1 = stInfoSizeGain->m_stGainName.m_dS1;
	m_dS2 = stInfoSizeGain->m_stGainName.m_dS2;
	m_dS3 = stInfoSizeGain->m_stGainName.m_dS3;
	m_dS4 = stInfoSizeGain->m_stGainName.m_dS4;
	m_dS5 = stInfoSizeGain->m_stGainName.m_dS5;
	m_dX1 = stInfoSizeGain->m_stGainName.m_dX1;
	m_dX2 = stInfoSizeGain->m_stGainName.m_dX2;
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	m_dR1 = stInfoSizeGain->m_stGainName.m_dR1;
	m_dR2 = stInfoSizeGain->m_stGainName.m_dR2;
	m_dR3 = stInfoSizeGain->m_stGainName.m_dR3;
	m_dR4 = stInfoSizeGain->m_stGainName.m_dR4;
	m_dR5 = stInfoSizeGain->m_stGainName.m_dR5;
	m_dR6 = stInfoSizeGain->m_stGainName.m_dR6;
	m_dSS1 = stInfoSizeGain->m_stGainName.m_dSS1;
	m_dSS2 = stInfoSizeGain->m_stGainName.m_dSS2;
	m_dSS3 = stInfoSizeGain->m_stGainName.m_dSS3;
}

void CDlgSizeGain::UpdateCameraPos(TYPE_CAMERAPOS ePos)
{
	m_eCameraPos = ePos;
}

void CDlgSizeGain::Log(char* pszLog, ...)
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

// Version 1.3.7.8
//void CDlgSizeGain::UpdateImage(INFO_IMAGE* image, cv::Mat captureimage[2])
//{
//	m_tempImage = image;
//	m_CaptureImage[0] = captureimage[0];
//	m_CaptureImage[1] = captureimage[1];
//}
//// Version 1.3.7.8
//void CDlgSizeGain::UpdateImage(INFO_IMAGE* image, INFO_IMAGE* image1, INFO_IMAGE* image2)
//{
//	m_tempImage = image;
//	m_tempImageFirst  = image1;
//	m_tempImageSecond = image2;
//}
// Version 1.3.7.8
void CDlgSizeGain::UpdateResult(const CSampleSide* sample)
{
	if (!m_Sample) m_Sample.reset(new CSampleSide());

	m_Sample->CopyFrom(*sample);
}


// Version 1.3.7.3 Gain -> Real 계산
// Version 1.3.7.8 Real -> Gain 계산
void CDlgSizeGain::OnBnApplyClick()
{
	// Gain 입력
	CString str;
	int i = 0;
	double stRealValue[TYPE_GEOMETRY_DISTANCE_MAX];
	GetDlgItemText(IDC_EDIT_REAL_D, str);		stRealValue[i] = _tstof(str); i++;
	GetDlgItemText(IDC_EDIT_REAL_L, str);		stRealValue[i] = _tstof(str); i++;
	GetDlgItemText(IDC_EDIT_REAL_W, str);		stRealValue[i] = _tstof(str); i++;
	GetDlgItemText(IDC_EDIT_REAL_I1, str);		stRealValue[i] = _tstof(str); i++;
	GetDlgItemText(IDC_EDIT_REAL_I2, str);		stRealValue[i] = _tstof(str); i++;
	GetDlgItemText(IDC_EDIT_REAL_I3, str);		stRealValue[i] = _tstof(str); i++;
	GetDlgItemText(IDC_EDIT_REAL_M1, str);		stRealValue[i] = _tstof(str); i++;
	GetDlgItemText(IDC_EDIT_REAL_M2, str);		stRealValue[i] = _tstof(str); i++;
	GetDlgItemText(IDC_EDIT_REAL_S1, str);		stRealValue[i] = _tstof(str); i++;
	GetDlgItemText(IDC_EDIT_REAL_S2, str);		stRealValue[i] = _tstof(str); i++;
	GetDlgItemText(IDC_EDIT_REAL_S3, str);		stRealValue[i] = _tstof(str); i++;
	GetDlgItemText(IDC_EDIT_REAL_S4, str);		stRealValue[i] = _tstof(str); i++;
	GetDlgItemText(IDC_EDIT_REAL_S5, str);		stRealValue[i] = _tstof(str); i++;
	GetDlgItemText(IDC_EDIT_REAL_X1, str);		stRealValue[i] = _tstof(str); i++;
	GetDlgItemText(IDC_EDIT_REAL_X2, str);		stRealValue[i] = _tstof(str); i++;
	GetDlgItemText(IDC_EDIT_REAL_R1, str);		stRealValue[i] = _tstof(str); i++;
	GetDlgItemText(IDC_EDIT_REAL_R2, str);		stRealValue[i] = _tstof(str); i++;
	GetDlgItemText(IDC_EDIT_REAL_R3, str);		stRealValue[i] = _tstof(str); i++;
	GetDlgItemText(IDC_EDIT_REAL_R4, str);		stRealValue[i] = _tstof(str); i++;
	GetDlgItemText(IDC_EDIT_REAL_R5, str);		stRealValue[i] = _tstof(str); i++;
	GetDlgItemText(IDC_EDIT_REAL_R6, str);		stRealValue[i] = _tstof(str); i++;
	GetDlgItemText(IDC_EDIT_REAL_SS1, str);		stRealValue[i] = _tstof(str); i++;
	GetDlgItemText(IDC_EDIT_REAL_SS2, str);		stRealValue[i] = _tstof(str); i++;
	GetDlgItemText(IDC_EDIT_REAL_SS3, str);		stRealValue[i] = _tstof(str); i++;

	CCaptureManager* pCaptureManager	= CCaptureManager::GetInstance();
	CInspection* pInspection			= pCaptureManager->GetInspection();
	CInspectionCamera* pCamera			= pInspection->GetInspectionCamera(m_eCameraPos);

	// Gain 정보 얻기
	const INFO_SIZE_GAIN* pGain			= NULL;
	CStepSizeCalculation* pStepCalc		= pCamera->GetStepSizeCalc();

	if (pStepCalc)
	{
		pGain = &pStepCalc->GetInformation()->m_stSizeGain;
	}

	CString stGainValue[TYPE_GEOMETRY_DISTANCE_MAX];

	CSampleSide sample;
	sample.CopyFrom(*m_Sample);

	for (int i = 0; i < TYPE_GEOMETRY_DISTANCE_MAX; i++)
	{
		OUTPUT_DISTANCE *pstDistance = NULL;
		pstDistance = sample.m_SizeCalculationResult.m_stDistance;
		if (pstDistance)
		{
			double tempGain;
			if (stRealValue[i] != 0 && pstDistance[i].m_dValue != 0 && pGain->m_dGain[i] != 0)
			{
				// 실측값 먼저 받은 후에 결과 // 거리 * Gain  -> 결과 / (측정 값 / 이전 Gain) = Gain
				//tempGain = stRealValue[i] / (pstDistance[i].m_dValue / pGain->m_dGain[i]);
				// 실제 현장에서 사용 방식 : 실측 값 = 검사기 측정 값 * Gain --> Gain = 실측 값 / 검사기 측정 값 * 이전 Gain(값 증감을 위해)
				tempGain = stRealValue[i] / pstDistance[i].m_dValue * pGain->m_dGain[i];
			}
			else
			{
				tempGain = 1;
			}
			if (tempGain == 1)	stGainValue[i].Format(_T("%.3f"),	tempGain);
			else				stGainValue[i].Format(_T("%.17f"),	tempGain);
		}
	}

	i = 0;
	// 거리 표시 -> Gain 표시
	GetDlgItem(IDC_EDIT_GAIN_D)->SetWindowText(stGainValue[i]);		i++;
	GetDlgItem(IDC_EDIT_GAIN_L)->SetWindowText(stGainValue[i]);		i++;
	GetDlgItem(IDC_EDIT_GAIN_W)->SetWindowText(stGainValue[i]);		i++;
	GetDlgItem(IDC_EDIT_GAIN_I1)->SetWindowText(stGainValue[i]);	i++;
	GetDlgItem(IDC_EDIT_GAIN_I2)->SetWindowText(stGainValue[i]);	i++;
	GetDlgItem(IDC_EDIT_GAIN_I3)->SetWindowText(stGainValue[i]);	i++;
	GetDlgItem(IDC_EDIT_GAIN_M1)->SetWindowText(stGainValue[i]);	i++;
	GetDlgItem(IDC_EDIT_GAIN_M2)->SetWindowText(stGainValue[i]);	i++;
	GetDlgItem(IDC_EDIT_GAIN_S1)->SetWindowText(stGainValue[i]);	i++;
	GetDlgItem(IDC_EDIT_GAIN_S2)->SetWindowText(stGainValue[i]);	i++;
	GetDlgItem(IDC_EDIT_GAIN_S3)->SetWindowText(stGainValue[i]);	i++;
	GetDlgItem(IDC_EDIT_GAIN_S4)->SetWindowText(stGainValue[i]);	i++;
	GetDlgItem(IDC_EDIT_GAIN_S5)->SetWindowText(stGainValue[i]);	i++;
	GetDlgItem(IDC_EDIT_GAIN_X1)->SetWindowText(stGainValue[i]);	i++;
	GetDlgItem(IDC_EDIT_GAIN_X2)->SetWindowText(stGainValue[i]);	i++;
	GetDlgItem(IDC_EDIT_GAIN_R1)->SetWindowText(stGainValue[i]);	i++;
	GetDlgItem(IDC_EDIT_GAIN_R2)->SetWindowText(stGainValue[i]);	i++;
	GetDlgItem(IDC_EDIT_GAIN_R3)->SetWindowText(stGainValue[i]);	i++;
	GetDlgItem(IDC_EDIT_GAIN_R4)->SetWindowText(stGainValue[i]);	i++;
	GetDlgItem(IDC_EDIT_GAIN_R5)->SetWindowText(stGainValue[i]);	i++;
	GetDlgItem(IDC_EDIT_GAIN_R6)->SetWindowText(stGainValue[i]);	i++;
	GetDlgItem(IDC_EDIT_GAIN_SS1)->SetWindowText(stGainValue[i]);	i++;
	GetDlgItem(IDC_EDIT_GAIN_SS2)->SetWindowText(stGainValue[i]);	i++;
	GetDlgItem(IDC_EDIT_GAIN_SS3)->SetWindowText(stGainValue[i]);	i++;
}
