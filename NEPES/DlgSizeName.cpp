// DlgSizeGain.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "DlgSizeName.h"
#include "afxdialogex.h"

#include "CaptureManager.h"
#include "stringres.h"

#include "Util/Util.h"


// CDlgSizeName dialog

IMPLEMENT_DYNAMIC(CDlgSizeName, CDialogEx)

CDlgSizeName::CDlgSizeName(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgSizeName::IDD, pParent)
{
	m_szName[0] = STR_SIZEMEASURE_01;
	m_szName[1] = STR_SIZEMEASURE_02;
	m_szName[2] = STR_SIZEMEASURE_03;
	m_szName[3] = STR_SIZEMEASURE_04;
	m_szName[4] = STR_SIZEMEASURE_05;
	m_szName[5] = STR_SIZEMEASURE_06;
	m_szName[6] = STR_SIZEMEASURE_07;
	m_szName[7] = STR_SIZEMEASURE_08;
	m_szName[8] = STR_SIZEMEASURE_09;
	m_szName[9] = STR_SIZEMEASURE_10;
	m_szName[10] = STR_SIZEMEASURE_11;
	m_szName[11] = STR_SIZEMEASURE_12;
	m_szName[12] = STR_SIZEMEASURE_13;
	m_szName[13] = STR_SIZEMEASURE_14;
	m_szName[14] = STR_SIZEMEASURE_15;
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	m_szName[15] = STR_SIZEMEASURE_16;
	m_szName[16] = STR_SIZEMEASURE_17;
	m_szName[17] = STR_SIZEMEASURE_18;
	m_szName[18] = STR_SIZEMEASURE_19;
	m_szName[19] = STR_SIZEMEASURE_20;
	m_szName[20] = STR_SIZEMEASURE_21;
	m_szName[21] = STR_SIZEMEASURE_22;
	m_szName[22] = STR_SIZEMEASURE_23;
	m_szName[23] = STR_SIZEMEASURE_24;
	// 치수 연산은 제외
	/*m_szName[24] = STR_SIZEMEASURE_25;
	m_szName[25] = STR_SIZEMEASURE_26;
	m_szName[26] = STR_SIZEMEASURE_27;
	m_szName[27] = STR_SIZEMEASURE_28;*/
}

CDlgSizeName::~CDlgSizeName()
{
}

void CDlgSizeName::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME_D, m_szName[0]);
	DDV_MaxChars(pDX, m_szName[0], 128);
	DDX_Text(pDX, IDC_EDIT_NAME_L, m_szName[1]);
	DDV_MaxChars(pDX, m_szName[1], 128);
	DDX_Text(pDX, IDC_EDIT_NAME_W, m_szName[2]);
	DDV_MaxChars(pDX, m_szName[2], 128);
	DDX_Text(pDX, IDC_EDIT_NAME_I1, m_szName[3]);
	DDV_MaxChars(pDX, m_szName[3], 128);
	DDX_Text(pDX, IDC_EDIT_NAME_I2, m_szName[4]);
	DDV_MaxChars(pDX, m_szName[4], 128);
	DDX_Text(pDX, IDC_EDIT_NAME_I3, m_szName[5]);
	DDV_MaxChars(pDX, m_szName[5], 128);
	DDX_Text(pDX, IDC_EDIT_NAME_M1, m_szName[6]);
	DDV_MaxChars(pDX, m_szName[6], 128);
	DDX_Text(pDX, IDC_EDIT_NAME_M2, m_szName[7]);
	DDV_MaxChars(pDX, m_szName[7], 128);
	DDX_Text(pDX, IDC_EDIT_NAME_S1, m_szName[8]);
	DDV_MaxChars(pDX, m_szName[8], 128);
	DDX_Text(pDX, IDC_EDIT_NAME_S2, m_szName[9]);
	DDV_MaxChars(pDX, m_szName[9], 128);
	DDX_Text(pDX, IDC_EDIT_NAME_S3, m_szName[10]);
	DDV_MaxChars(pDX, m_szName[10], 128);
	DDX_Text(pDX, IDC_EDIT_NAME_S4, m_szName[11]);
	DDV_MaxChars(pDX, m_szName[11], 128);
	DDX_Text(pDX, IDC_EDIT_NAME_S5, m_szName[12]);
	DDV_MaxChars(pDX, m_szName[12], 128);
	DDX_Text(pDX, IDC_EDIT_NAME_X1, m_szName[13]);
	DDV_MaxChars(pDX, m_szName[13], 128);
	DDX_Text(pDX, IDC_EDIT_NAME_X2, m_szName[14]);
	DDV_MaxChars(pDX, m_szName[14], 128);
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	DDX_Text(pDX, IDC_EDIT_NAME_R1, m_szName[15]);
	DDV_MaxChars(pDX, m_szName[15], 128);
	DDX_Text(pDX, IDC_EDIT_NAME_R2, m_szName[16]);
	DDV_MaxChars(pDX, m_szName[16], 128);
	DDX_Text(pDX, IDC_EDIT_NAME_R3, m_szName[17]);
	DDV_MaxChars(pDX, m_szName[17], 128);
	DDX_Text(pDX, IDC_EDIT_NAME_R4, m_szName[18]);
	DDV_MaxChars(pDX, m_szName[18], 128);
	DDX_Text(pDX, IDC_EDIT_NAME_R5, m_szName[19]);
	DDV_MaxChars(pDX, m_szName[19], 128);
	DDX_Text(pDX, IDC_EDIT_NAME_R6, m_szName[20]);
	DDV_MaxChars(pDX, m_szName[20], 128);
	DDX_Text(pDX, IDC_EDIT_NAME_SS1, m_szName[21]);
	DDV_MaxChars(pDX, m_szName[21], 128);
	DDX_Text(pDX, IDC_EDIT_NAME_SS2, m_szName[22]);
	DDV_MaxChars(pDX, m_szName[22], 128);
	DDX_Text(pDX, IDC_EDIT_NAME_SS3, m_szName[23]);
	DDV_MaxChars(pDX, m_szName[23], 128);
}


BEGIN_MESSAGE_MAP(CDlgSizeName, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgSizeName::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgSizeName message handlers


BOOL CDlgSizeName::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgSizeName::OnBnClickedOk()
{
	UpdateData();

	for (int i = 0; i < MAX_GEOMETRY_DISTANCELINE_COUNT; i++)
	{
		CUtil::StringCopy(m_stInfoSizeName.m_szName[i], m_szName[i], MAX_NAME_LEN);
	}

	CDialogEx::OnOK();
}

void CDlgSizeName::SetInfoSizeName(const INFO_OPT_SIZENAME *stInfoSizeName)
{
	for (int i = 0; i < MAX_GEOMETRY_DISTANCELINE_COUNT; i++)
	{
		m_szName[i] = stInfoSizeName->m_szName[i];
	}
}

void CDlgSizeName::Log(char* pszLog, ...)
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

		stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "SIZE NAME DIALOG", szLog);
	}
}

