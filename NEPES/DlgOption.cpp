// DlgOption.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "DlgOption.h"
#include "DlgStepName.h"
#include "DlgSizeName.h"
#include "afxdialogex.h"

#include "CaptureManager.h"
#include "Util/Util.h"

#include "stringres.h"


// CDlgOption dialog

IMPLEMENT_DYNAMIC(CDlgOption, CDialogEx)

CDlgOption::CDlgOption(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgOption::IDD, pParent)
{
	memset(&m_stOption, 0x00, sizeof(INFO_OPTION));
}

CDlgOption::~CDlgOption()
{
}

void CDlgOption::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	//
	int idx = 0;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE1, m_ctlEditMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE2, m_ctlEditMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE3, m_ctlEditMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE4, m_ctlEditMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE5, m_ctlEditMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE6, m_ctlEditMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE7, m_ctlEditMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE8, m_ctlEditMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE9, m_ctlEditMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE10, m_ctlEditMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE11, m_ctlEditMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE12, m_ctlEditMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE13, m_ctlEditMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE14, m_ctlEditMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE15, m_ctlEditMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE16, m_ctlEditMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE17, m_ctlEditMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE18, m_ctlEditMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE19, m_ctlEditMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE20, m_ctlEditMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE21, m_ctlEditMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE22, m_ctlEditMin[idx]); idx++;
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE23, m_ctlEditMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE24, m_ctlEditMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE25, m_ctlEditMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE26, m_ctlEditMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE27, m_ctlEditMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE28, m_ctlEditMin[idx]); idx++;

	//
	idx = 0;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE1, m_ctlEditMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE2, m_ctlEditMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE3, m_ctlEditMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE4, m_ctlEditMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE5, m_ctlEditMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE6, m_ctlEditMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE7, m_ctlEditMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE8, m_ctlEditMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE9, m_ctlEditMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE10, m_ctlEditMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE11, m_ctlEditMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE12, m_ctlEditMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE13, m_ctlEditMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE14, m_ctlEditMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE15, m_ctlEditMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE16, m_ctlEditMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE17, m_ctlEditMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE18, m_ctlEditMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE19, m_ctlEditMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE20, m_ctlEditMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE21, m_ctlEditMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE22, m_ctlEditMax[idx]); idx++;
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE23, m_ctlEditMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE24, m_ctlEditMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE25, m_ctlEditMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE26, m_ctlEditMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE27, m_ctlEditMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE28, m_ctlEditMax[idx]); idx++;

	//
	idx = 0;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE_SECOND_1, m_ctlEditMinSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE_SECOND_2, m_ctlEditMinSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE_SECOND_3, m_ctlEditMinSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE_SECOND_4, m_ctlEditMinSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE_SECOND_5, m_ctlEditMinSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE_SECOND_6, m_ctlEditMinSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE_SECOND_7, m_ctlEditMinSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE_SECOND_8, m_ctlEditMinSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE_SECOND_9, m_ctlEditMinSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE_SECOND_10, m_ctlEditMinSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE_SECOND_11, m_ctlEditMinSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE_SECOND_12, m_ctlEditMinSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE_SECOND_13, m_ctlEditMinSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE_SECOND_14, m_ctlEditMinSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE_SECOND_15, m_ctlEditMinSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE_SECOND_16, m_ctlEditMinSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE_SECOND_17, m_ctlEditMinSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE_SECOND_18, m_ctlEditMinSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE_SECOND_19, m_ctlEditMinSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE_SECOND_20, m_ctlEditMinSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE_SECOND_21, m_ctlEditMinSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE_SECOND_22, m_ctlEditMinSecond[idx]); idx++;
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE_SECOND_23, m_ctlEditMinSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE_SECOND_24, m_ctlEditMinSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE_SECOND_25, m_ctlEditMinSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE_SECOND_26, m_ctlEditMinSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE_SECOND_27, m_ctlEditMinSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEMEASURE_SECOND_28, m_ctlEditMinSecond[idx]); idx++;

	//
	idx = 0;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE_SECOND_1, m_ctlEditMaxSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE_SECOND_2, m_ctlEditMaxSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE_SECOND_3, m_ctlEditMaxSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE_SECOND_4, m_ctlEditMaxSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE_SECOND_5, m_ctlEditMaxSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE_SECOND_6, m_ctlEditMaxSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE_SECOND_7, m_ctlEditMaxSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE_SECOND_8, m_ctlEditMaxSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE_SECOND_9, m_ctlEditMaxSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE_SECOND_10, m_ctlEditMaxSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE_SECOND_11, m_ctlEditMaxSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE_SECOND_12, m_ctlEditMaxSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE_SECOND_13, m_ctlEditMaxSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE_SECOND_14, m_ctlEditMaxSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE_SECOND_15, m_ctlEditMaxSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE_SECOND_16, m_ctlEditMaxSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE_SECOND_17, m_ctlEditMaxSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE_SECOND_18, m_ctlEditMaxSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE_SECOND_19, m_ctlEditMaxSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE_SECOND_20, m_ctlEditMaxSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE_SECOND_21, m_ctlEditMaxSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE_SECOND_22, m_ctlEditMaxSecond[idx]); idx++;
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE_SECOND_23, m_ctlEditMaxSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE_SECOND_24, m_ctlEditMaxSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE_SECOND_25, m_ctlEditMaxSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE_SECOND_26, m_ctlEditMaxSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE_SECOND_27, m_ctlEditMaxSecond[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEMEASURE_SECOND_28, m_ctlEditMaxSecond[idx]); idx++;

	//
	idx = 0;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZESPEC1, m_ctlEditSpecMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZESPEC2, m_ctlEditSpecMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZESPEC3, m_ctlEditSpecMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZESPEC4, m_ctlEditSpecMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZESPEC5, m_ctlEditSpecMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZESPEC6, m_ctlEditSpecMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZESPEC7, m_ctlEditSpecMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZESPEC8, m_ctlEditSpecMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZESPEC9, m_ctlEditSpecMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZESPEC10, m_ctlEditSpecMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZESPEC11, m_ctlEditSpecMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZESPEC12, m_ctlEditSpecMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZESPEC13, m_ctlEditSpecMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZESPEC14, m_ctlEditSpecMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZESPEC15, m_ctlEditSpecMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZESPEC16, m_ctlEditSpecMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZESPEC17, m_ctlEditSpecMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZESPEC18, m_ctlEditSpecMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZESPEC19, m_ctlEditSpecMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZESPEC20, m_ctlEditSpecMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZESPEC21, m_ctlEditSpecMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZESPEC22, m_ctlEditSpecMin[idx]); idx++;
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	DDX_Control(pDX, IDC_EDIT_MIN_SIZESPEC23, m_ctlEditSpecMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZESPEC24, m_ctlEditSpecMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZESPEC25, m_ctlEditSpecMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZESPEC26, m_ctlEditSpecMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZESPEC27, m_ctlEditSpecMin[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MIN_SIZESPEC28, m_ctlEditSpecMin[idx]); idx++;

	//
	idx = 0;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZESPEC1, m_ctlEditSpecMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZESPEC2, m_ctlEditSpecMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZESPEC3, m_ctlEditSpecMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZESPEC4, m_ctlEditSpecMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZESPEC5, m_ctlEditSpecMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZESPEC6, m_ctlEditSpecMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZESPEC7, m_ctlEditSpecMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZESPEC8, m_ctlEditSpecMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZESPEC9, m_ctlEditSpecMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZESPEC10, m_ctlEditSpecMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZESPEC11, m_ctlEditSpecMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZESPEC12, m_ctlEditSpecMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZESPEC13, m_ctlEditSpecMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZESPEC14, m_ctlEditSpecMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZESPEC15, m_ctlEditSpecMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZESPEC16, m_ctlEditSpecMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZESPEC17, m_ctlEditSpecMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZESPEC18, m_ctlEditSpecMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZESPEC19, m_ctlEditSpecMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZESPEC20, m_ctlEditSpecMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZESPEC21, m_ctlEditSpecMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZESPEC22, m_ctlEditSpecMax[idx]); idx++;
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	DDX_Control(pDX, IDC_EDIT_MAX_SIZESPEC23, m_ctlEditSpecMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZESPEC24, m_ctlEditSpecMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZESPEC25, m_ctlEditSpecMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZESPEC26, m_ctlEditSpecMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZESPEC27, m_ctlEditSpecMax[idx]); idx++;
	DDX_Control(pDX, IDC_EDIT_MAX_SIZESPEC28, m_ctlEditSpecMax[idx]); idx++;

	//
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEVALID1, m_ctlEditValidMin1);
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEVALID1, m_ctlEditValidMax1);
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEVALID2, m_ctlEditValidMin2);
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEVALID2, m_ctlEditValidMax2);

	// Version 1.3.6.5 (치수 영역 추가 없이 PLC 통신 데이터 추가 (X1-X2, L))
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEVALID3, m_ctlEditValidMin3);
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEVALID3, m_ctlEditValidMax3);
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEVALID4, m_ctlEditValidMin4);
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEVALID4, m_ctlEditValidMax4);
	// Ver1.3.7.2 (치수 영역 추가 없이 PLC 통신 데이터 추가 (M1, M2)) 
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEVALID5, m_ctlEditValidMin5);
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEVALID5, m_ctlEditValidMax5);
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEVALID6, m_ctlEditValidMin6);
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEVALID6, m_ctlEditValidMax6);
	// Ver1.3.7.2 (치수 영역 추가 없이 PLC 통신 데이터 추가 (M1, M2)) 
	DDX_Control(pDX, IDC_EDIT_MIN_SIZEVALID7, m_ctlEditValidMin7);
	DDX_Control(pDX, IDC_EDIT_MAX_SIZEVALID7, m_ctlEditValidMax7);

#ifdef DEF_DELAY_CAPTURE
	DDX_Control(pDX, IDC_EDIT_CAPTURE_DELAY, m_ctlEditCaptureDelay);
#endif
}

BOOL CDlgOption::OnInitDialog()
{
	CDialogEx::OnInitDialog();

#ifdef DEF_DELAY_CAPTURE
	GetDlgItem(IDC_STATIC_CAPTURE)->SetWindowText(STR_OPT_CAPTURE);
	GetDlgItem(IDC_STATIC_CAPTURE_DELAY)->SetWindowText(STR_OPT_CAPTURE_DELAY);
#endif

	GetDlgItem(IDC_STATIC_SIZE_RANGE)->SetWindowText(STR_OPT_ARARM_SIZERANGE);
	GetDlgItem(IDC_STATIC_SIZE_RANGE_SECOND)->SetWindowText(STR_OPT_ARARM_SIZERANGE_SECOND);
	GetDlgItem(IDC_STATIC_SIZE_SPEC)->SetWindowText(STR_OPT_ARARM_SIZESPEC);

	GetDlgItem(IDC_BTN_STEPNAME)->SetWindowText(STR_OPT_STEP_TITLE);
	GetDlgItem(IDC_BTN_SIZENAME)->SetWindowText(STR_OPT_SIZE_NAME);

	{
		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
		const INFO_OPTION* pstOption = pCaptureManager->GetOption();
		m_stOption = *pstOption;

		// Enable Step
		GetDlgItem(IDC_STATIC_STEPOPT)->SetWindowText(STR_OPT_STEP_ENABLE);
		GetDlgItem(IDC_STATIC_STEPFIRST)->SetWindowText(STR_MSG_FIRSTCAMERA);
		GetDlgItem(IDC_STATIC_STEPSECOND)->SetWindowText(STR_MSG_SECONDCAMERA);
		// Version 1.3.6.9 Update
		GetDlgItem(IDC_STATIC_SHAPETOSIZE)->SetWindowText(STR_MSG_SHAPETOSIZE);
		
		UpdateOptions();

		m_szFilePath = pCaptureManager->GetOptionFilePath();
		GetDlgItem(IDC_EDIT_FILEPATH)->SetWindowText(m_szFilePath);
	}
	return TRUE;
}

BEGIN_MESSAGE_MAP(CDlgOption, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgOption::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BTN_STEPNAME, &CDlgOption::OnBnClickedBtnStepname)
	ON_BN_CLICKED(IDC_BTN_SIZENAME, &CDlgOption::OnBnClickedBtnSizename)
	ON_BN_CLICKED(IDC_BTN_SAVE, &CDlgOption::OnBnClickedBtnSave)
	ON_BN_CLICKED(IDC_BTN_LOAD, &CDlgOption::OnBnClickedBtnLoad)
	ON_BN_CLICKED(IDC_BTN_SAVEAS, &CDlgOption::OnBnClickedBtnSaveas)
END_MESSAGE_MAP()


// CDlgOption message handlers

void CDlgOption::OnBnClickedOk()
{
	ApplyOptions();

	CDialogEx::OnOK();
}

void CDlgOption::OnBnClickedBtnStepname()
{
	CDlgStepName dlgName;
	dlgName.SetStepNames(&m_stOption);
	if (IDOK == dlgName.DoModal())
	{
		CUtil::StringCopy(m_stOption.m_stFirstCameraStep.m_szTitleStep01, (LPTSTR)(LPCTSTR)dlgName.m_szFirstStep01);
		CUtil::StringCopy(m_stOption.m_stFirstCameraStep.m_szTitleStep02, (LPTSTR)(LPCTSTR)dlgName.m_szFirstStep02);
		CUtil::StringCopy(m_stOption.m_stFirstCameraStep.m_szTitleStep03, (LPTSTR)(LPCTSTR)dlgName.m_szFirstStep03);
		CUtil::StringCopy(m_stOption.m_stFirstCameraStep.m_szTitleStep04, (LPTSTR)(LPCTSTR)dlgName.m_szFirstStep04);
		CUtil::StringCopy(m_stOption.m_stFirstCameraStep.m_szTitleStep05, (LPTSTR)(LPCTSTR)dlgName.m_szFirstStep05);
		CUtil::StringCopy(m_stOption.m_stFirstCameraStep.m_szTitleStep06, (LPTSTR)(LPCTSTR)dlgName.m_szFirstStep06);

#ifdef DEF_SECONDCAMERA_CHECKSIZE
		CUtil::StringCopy(m_stOption.m_stSecondCameraStep.m_szTitleStep01, (LPTSTR)(LPCTSTR)dlgName.m_szFirstStep01);
#endif
		CUtil::StringCopy(m_stOption.m_stSecondCameraStep.m_szTitleStep02, (LPTSTR)(LPCTSTR)dlgName.m_szSecondStep02);
		CUtil::StringCopy(m_stOption.m_stSecondCameraStep.m_szTitleStep03, (LPTSTR)(LPCTSTR)dlgName.m_szSecondStep03);
		CUtil::StringCopy(m_stOption.m_stSecondCameraStep.m_szTitleStep04, (LPTSTR)(LPCTSTR)dlgName.m_szSecondStep04);
		CUtil::StringCopy(m_stOption.m_stSecondCameraStep.m_szTitleStep05, (LPTSTR)(LPCTSTR)dlgName.m_szSecondStep05);
		CUtil::StringCopy(m_stOption.m_stSecondCameraStep.m_szTitleStep06, (LPTSTR)(LPCTSTR)dlgName.m_szSecondStep06);

		// Version 1.3.6.9
		CUtil::StringCopy(m_stOption.m_stShapeToSize.m_szTitleStep01, (LPTSTR)(LPCTSTR)dlgName.m_szFirstStep01);
		CUtil::StringCopy(m_stOption.m_stShapeToSize.m_szTitleStep02, (LPTSTR)(LPCTSTR)dlgName.m_szFirstStep02);
		CUtil::StringCopy(m_stOption.m_stShapeToSize.m_szTitleStep03, (LPTSTR)(LPCTSTR)dlgName.m_szFirstStep03);
		CUtil::StringCopy(m_stOption.m_stShapeToSize.m_szTitleStep04, (LPTSTR)(LPCTSTR)dlgName.m_szFirstStep04);
		CUtil::StringCopy(m_stOption.m_stShapeToSize.m_szTitleStep05, (LPTSTR)(LPCTSTR)dlgName.m_szFirstStep05);
		CUtil::StringCopy(m_stOption.m_stShapeToSize.m_szTitleStep06, (LPTSTR)(LPCTSTR)dlgName.m_szFirstStep06);

		UpdateTitleStep();
	}
}

void CDlgOption::OnBnClickedBtnSizename()
{
	CDlgSizeName dlgName;
	dlgName.SetInfoSizeName(&(m_stOption.m_stSizeName));
	if (IDOK == dlgName.DoModal())
	{
		memcpy(&m_stOption.m_stSizeName, &dlgName.m_stInfoSizeName, sizeof(INFO_OPT_SIZENAME));
		UpdateSizeName();
	}
}

void CDlgOption::UpdateOptions()
{
#ifdef DEF_DELAY_CAPTURE
	UpdateCapture();
#endif
	UpdateRange();
	UpdateRangeSecond();
	UpdateSpec();
	UpdateValid();
	UpdateStepEnable();
	UpdateTitleStep();
	UpdateSizeName();
}

#ifdef DEF_DELAY_CAPTURE
void CDlgOption::UpdateCapture()
{
	CString szValue;
	szValue.Format(_T("%d"), m_stOption.m_stCapture.m_nDelay);
	GetDlgItem(IDC_EDIT_CAPTURE_DELAY)->SetWindowText(szValue);
}
#endif

void CDlgOption::UpdateSizeName()
{
	// Range Size Name
	int idx = 0;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE1)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE2)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE3)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE4)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE5)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE6)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE7)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE8)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE9)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE10)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE11)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE12)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE13)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE14)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE15)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE16)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE17)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE18)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE19)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE20)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE21)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE22)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE23)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE24)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;

	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE25)->SetWindowText(m_stOption.m_stSizeName.GetNameX1X2());
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE26)->SetWindowText(m_stOption.m_stSizeName.GetNameS1S3());
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE27)->SetWindowText(m_stOption.m_stSizeName.GetNameM1M2());
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE28)->SetWindowText(m_stOption.m_stSizeName.GetNameSS1SS3());

	// Range Second Size Name
	idx = 0;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE_SECOND_1)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE_SECOND_2)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE_SECOND_3)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE_SECOND_4)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE_SECOND_5)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE_SECOND_6)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE_SECOND_7)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE_SECOND_8)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE_SECOND_9)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE_SECOND_10)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE_SECOND_11)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE_SECOND_12)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE_SECOND_13)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE_SECOND_14)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE_SECOND_15)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE_SECOND_16)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE_SECOND_17)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE_SECOND_18)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE_SECOND_19)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;

	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE_SECOND_20)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE_SECOND_21)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE_SECOND_22)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE_SECOND_23)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE_SECOND_24)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
			   
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE_SECOND_25)->SetWindowText(m_stOption.m_stSizeName.GetNameX1X2());
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE_SECOND_26)->SetWindowText(m_stOption.m_stSizeName.GetNameS1S3());
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE_SECOND_27)->SetWindowText(m_stOption.m_stSizeName.GetNameM1M2());
	GetDlgItem(IDC_STATIC_MIN_SIZEMEASURE_SECOND_28)->SetWindowText(m_stOption.m_stSizeName.GetNameSS1SS3());

	// Spec Size Name
	idx = 0;
	GetDlgItem(IDC_STATIC_MIN_SIZESPEC1)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZESPEC2)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZESPEC3)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZESPEC4)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZESPEC5)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZESPEC6)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZESPEC7)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZESPEC8)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZESPEC9)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZESPEC10)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZESPEC11)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZESPEC12)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZESPEC13)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZESPEC14)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZESPEC15)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZESPEC16)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZESPEC17)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZESPEC18)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZESPEC19)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;

	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	GetDlgItem(IDC_STATIC_MIN_SIZESPEC20)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZESPEC21)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZESPEC22)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZESPEC23)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;
	GetDlgItem(IDC_STATIC_MIN_SIZESPEC24)->SetWindowText(m_stOption.m_stSizeName.m_szName[idx]); idx++;

	GetDlgItem(IDC_STATIC_MIN_SIZESPEC25)->SetWindowText(m_stOption.m_stSizeName.GetNameX1X2());
	GetDlgItem(IDC_STATIC_MIN_SIZESPEC26)->SetWindowText(m_stOption.m_stSizeName.GetNameS1S3());
	GetDlgItem(IDC_STATIC_MIN_SIZESPEC27)->SetWindowText(m_stOption.m_stSizeName.GetNameM1M2());
	GetDlgItem(IDC_STATIC_MIN_SIZESPEC28)->SetWindowText(m_stOption.m_stSizeName.GetNameSS1SS3());


#ifdef USE_VALID_RANGE
	CString szName;
	szName.Append(m_stOption.m_stSizeName.m_szName[TYPE_GEOMETRY_DISTANCE_S1]);
	szName.AppendChar(_T(' '));
	szName.Append(m_stOption.m_stSizeName.m_szName[TYPE_GEOMETRY_DISTANCE_S2]);
	szName.AppendChar(_T(' '));
	szName.Append(m_stOption.m_stSizeName.m_szName[TYPE_GEOMETRY_DISTANCE_S3]);
	GetDlgItem(IDC_STATIC_MIN_SIZEVALID1)->SetWindowText(szName);
	GetDlgItem(IDC_STATIC_MIN_SIZEVALID2)->SetWindowText(m_stOption.m_stSizeName.m_szName[TYPE_GEOMETRY_DISTANCE_D]);
	// Version 1.3.6.5 (치수 영역 추가 없이 PLC 통신 데이터 추가 (X1-X2, L))
	GetDlgItem(IDC_STATIC_MIN_SIZEVALID3)->SetWindowText(m_stOption.m_stSizeName.m_szName[TYPE_GEOMETRY_DISTANCE_L]);
	GetDlgItem(IDC_STATIC_MIN_SIZEVALID4)->SetWindowText(m_stOption.m_stSizeName.GetNameX1X2());
	// Ver1.3.7.2 (치수 영역 추가 없이 PLC 통신 데이터 추가 (M1, M2)) 
	GetDlgItem(IDC_STATIC_MIN_SIZEVALID5)->SetWindowText(m_stOption.m_stSizeName.m_szName[TYPE_GEOMETRY_DISTANCE_M1]);
	GetDlgItem(IDC_STATIC_MIN_SIZEVALID6)->SetWindowText(m_stOption.m_stSizeName.m_szName[TYPE_GEOMETRY_DISTANCE_M2]);
	// Ver1.3.7.4 (치수 영역 추가 없이 PLC 통신 데이터 추가 (S1S3)) 
	GetDlgItem(IDC_STATIC_MIN_SIZEVALID7)->SetWindowText(m_stOption.m_stSizeName.GetNameS1S3());
#endif
}

void CDlgOption::UpdateRange()
{
	CString szValue;

	// Update Range (MIN)
	int idx = 0;
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE1)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE2)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE3)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE4)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE5)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE6)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE7)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE8)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE9)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE10)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE11)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE12)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE13)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE14)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE15)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE16)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE17)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE18)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE19)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE20)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE21)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE22)->SetWindowText(szValue);
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE23)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE24)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE25)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE26)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE27)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE28)->SetWindowText(szValue);

	// Update Range (MAX)
	idx = 0;
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE1)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE2)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE3)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE4)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE5)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE6)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE7)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE8)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE9)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE10)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE11)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE12)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE13)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE14)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE15)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE16)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE17)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE18)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE19)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE20)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE21)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE22)->SetWindowText(szValue);
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE23)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE24)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE25)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE26)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE27)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[0][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE28)->SetWindowText(szValue);
}

void CDlgOption::UpdateRangeSecond()
{
	CString szValue;

	// Update Range (MIN)
	int idx = 0;
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_1)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_2)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_3)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_4)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_5)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_6)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_7)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_8)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_9)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_10)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_11)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_12)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_13)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_14)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_15)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_16)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_17)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_18)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_19)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_20)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_21)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_22)->SetWindowText(szValue);
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_23)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_24)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_25)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_26)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_27)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_28)->SetWindowText(szValue);

	// Update Range (MAX)
	idx = 0;
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_1)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_2)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_3)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_4)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_5)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_6)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_7)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_8)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_9)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_10)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_11)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_12)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_13)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_14)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_15)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_16)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_17)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_18)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_19)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_20)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_21)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_22)->SetWindowText(szValue);
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_23)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_24)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_25)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_26)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_27)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRange[1][idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_28)->SetWindowText(szValue);
}

#ifdef USE_VALID_RANGE
void CDlgOption::UpdateValid()
{
	CString szValue;

	// Update Valid Range (MIN)
	int idx = 0;
	szValue.Format(_T("%.3f"), m_stOption.m_pstValidRange[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEVALID1)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstValidRange[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEVALID2)->SetWindowText(szValue);
	// Version 1.3.6.5 (치수 영역 추가 없이 PLC 통신 데이터 추가 (X1-X2, L))
	szValue.Format(_T("%.3f"), m_stOption.m_pstValidRange[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEVALID3)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstValidRange[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEVALID4)->SetWindowText(szValue);
	// Ver1.3.7.2 (치수 영역 추가 없이 PLC 통신 데이터 추가 (M1, M2)) 
	szValue.Format(_T("%.3f"), m_stOption.m_pstValidRange[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEVALID5)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstValidRange[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEVALID6)->SetWindowText(szValue);
	// Ver1.3.7.4 (치수 영역 추가 없이 PLC 통신 데이터 추가 (S1S3)) 
	szValue.Format(_T("%.3f"), m_stOption.m_pstValidRange[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEVALID7)->SetWindowText(szValue);

	// Update Valid Range (MAX)
	idx = 0;
	szValue.Format(_T("%.3f"), m_stOption.m_pstValidRange[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEVALID1)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstValidRange[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEVALID2)->SetWindowText(szValue);
	// Version 1.3.6.5 (치수 영역 추가 없이 PLC 통신 데이터 추가 (X1-X2, L))
	szValue.Format(_T("%.3f"), m_stOption.m_pstValidRange[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEVALID3)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstValidRange[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEVALID4)->SetWindowText(szValue);
	// Ver1.3.7.2 (치수 영역 추가 없이 PLC 통신 데이터 추가 (M1, M2)) 
	szValue.Format(_T("%.3f"), m_stOption.m_pstValidRange[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEVALID5)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstValidRange[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEVALID6)->SetWindowText(szValue);
	// Ver1.3.7.4 (치수 영역 추가 없이 PLC 통신 데이터 추가 (S1S3)) 
	szValue.Format(_T("%.3f"), m_stOption.m_pstValidRange[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEVALID7)->SetWindowText(szValue);
}
#endif

void CDlgOption::UpdateSpec()
{
	CString szValue;

	// Update Range (MIN)
	int idx = 0;
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC1)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC2)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC3)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC4)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC5)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC6)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC7)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC8)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC9)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC10)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC11)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC12)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC13)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC14)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC15)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC16)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC17)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC18)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC19)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC20)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC21)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC22)->SetWindowText(szValue);
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC23)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC24)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC25)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC26)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC27)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMin);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC28)->SetWindowText(szValue);

	// Update Range (MAX)
	idx = 0;
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC1)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC2)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC3)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC4)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC5)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC6)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC7)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC8)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC9)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC10)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC11)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC12)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC13)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC14)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC15)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC16)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC17)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC18)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC19)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC20)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC21)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC22)->SetWindowText(szValue);
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC23)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC24)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC25)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC26)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC27)->SetWindowText(szValue);
	szValue.Format(_T("%.3f"), m_stOption.m_pstRangeSpec[idx].m_fMax);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC28)->SetWindowText(szValue);
}

void CDlgOption::UpdateStepEnable()
{
	if (m_stOption.m_stFirstCameraStep.m_bStep001)
		((CButton*)GetDlgItem(IDC_CHECK_FIRSTSTEP1))->SetCheck(BST_CHECKED);
	else
		((CButton*)GetDlgItem(IDC_CHECK_FIRSTSTEP1))->SetCheck(BST_UNCHECKED);

	if (m_stOption.m_stFirstCameraStep.m_bStep002)
		((CButton*)GetDlgItem(IDC_CHECK_FIRSTSTEP2))->SetCheck(BST_CHECKED);
	else
		((CButton*)GetDlgItem(IDC_CHECK_FIRSTSTEP2))->SetCheck(BST_UNCHECKED);

	if (m_stOption.m_stFirstCameraStep.m_bStep003)
		((CButton*)GetDlgItem(IDC_CHECK_FIRSTSTEP3))->SetCheck(BST_CHECKED);
	else
		((CButton*)GetDlgItem(IDC_CHECK_FIRSTSTEP3))->SetCheck(BST_UNCHECKED);

	if (m_stOption.m_stFirstCameraStep.m_bStep004)
		((CButton*)GetDlgItem(IDC_CHECK_FIRSTSTEP4))->SetCheck(BST_CHECKED);
	else
		((CButton*)GetDlgItem(IDC_CHECK_FIRSTSTEP4))->SetCheck(BST_UNCHECKED);

	if (m_stOption.m_stFirstCameraStep.m_bStep005)
		((CButton*)GetDlgItem(IDC_CHECK_FIRSTSTEP5))->SetCheck(BST_CHECKED);
	else
		((CButton*)GetDlgItem(IDC_CHECK_FIRSTSTEP5))->SetCheck(BST_UNCHECKED);

	if (m_stOption.m_stFirstCameraStep.m_bStep006)
		((CButton*)GetDlgItem(IDC_CHECK_FIRSTSTEP6))->SetCheck(BST_CHECKED);
	else
		((CButton*)GetDlgItem(IDC_CHECK_FIRSTSTEP6))->SetCheck(BST_UNCHECKED);


#ifdef DEF_SECONDCAMERA_CHECKSIZE
	if (m_stOption.m_stSecondCameraStep.m_bStep001)
		((CButton*)GetDlgItem(IDC_CHECK_SECONDSTEP1))->SetCheck(BST_CHECKED);
	else
		((CButton*)GetDlgItem(IDC_CHECK_SECONDSTEP1))->SetCheck(BST_UNCHECKED);
#else
	((CButton*)GetDlgItem(IDC_CHECK_SECONDSTEP1))->SetCheck(BST_UNCHECKED);
	((CButton*)GetDlgItem(IDC_CHECK_SECONDSTEP1))->EnableWindow(FALSE);
#endif
	if (m_stOption.m_stSecondCameraStep.m_bStep002)
		((CButton*)GetDlgItem(IDC_CHECK_SECONDSTEP2))->SetCheck(BST_CHECKED);
	else
		((CButton*)GetDlgItem(IDC_CHECK_SECONDSTEP2))->SetCheck(BST_UNCHECKED);

	if (m_stOption.m_stSecondCameraStep.m_bStep003)
		((CButton*)GetDlgItem(IDC_CHECK_SECONDSTEP3))->SetCheck(BST_CHECKED);
	else
		((CButton*)GetDlgItem(IDC_CHECK_SECONDSTEP3))->SetCheck(BST_UNCHECKED);

	if (m_stOption.m_stSecondCameraStep.m_bStep004)
		((CButton*)GetDlgItem(IDC_CHECK_SECONDSTEP4))->SetCheck(BST_CHECKED);
	else
		((CButton*)GetDlgItem(IDC_CHECK_SECONDSTEP4))->SetCheck(BST_UNCHECKED);

	if (m_stOption.m_stSecondCameraStep.m_bStep005)
		((CButton*)GetDlgItem(IDC_CHECK_SECONDSTEP5))->SetCheck(BST_CHECKED);
	else
		((CButton*)GetDlgItem(IDC_CHECK_SECONDSTEP5))->SetCheck(BST_UNCHECKED);

	if (m_stOption.m_stSecondCameraStep.m_bStep006)
		((CButton*)GetDlgItem(IDC_CHECK_SECONDSTEP6))->SetCheck(BST_CHECKED);
	else
		((CButton*)GetDlgItem(IDC_CHECK_SECONDSTEP6))->SetCheck(BST_UNCHECKED);

	// Version 1.3.6.9 Update
	// 아이콘 추가 설정
	if (m_stOption.m_stShapeToSize.m_bStep001)
		((CButton*)GetDlgItem(IDC_CHECK_SHAPETOSIZE1))->SetCheck(BST_CHECKED);
	else
		((CButton*)GetDlgItem(IDC_CHECK_SHAPETOSIZE1))->SetCheck(BST_UNCHECKED);

	if (m_stOption.m_stShapeToSize.m_bStep002)
		((CButton*)GetDlgItem(IDC_CHECK_SHAPETOSIZE2))->SetCheck(BST_CHECKED);
	else
		((CButton*)GetDlgItem(IDC_CHECK_SHAPETOSIZE2))->SetCheck(BST_UNCHECKED);

	if (m_stOption.m_stShapeToSize.m_bStep003)
		((CButton*)GetDlgItem(IDC_CHECK_SHAPETOSIZE3))->SetCheck(BST_CHECKED);
	else
		((CButton*)GetDlgItem(IDC_CHECK_SHAPETOSIZE3))->SetCheck(BST_UNCHECKED);

	if (m_stOption.m_stShapeToSize.m_bStep004)
		((CButton*)GetDlgItem(IDC_CHECK_SHAPETOSIZE4))->SetCheck(BST_CHECKED);
	else
		((CButton*)GetDlgItem(IDC_CHECK_SHAPETOSIZE4))->SetCheck(BST_UNCHECKED);

	if (m_stOption.m_stShapeToSize.m_bStep005)
		((CButton*)GetDlgItem(IDC_CHECK_SHAPETOSIZE5))->SetCheck(BST_CHECKED);
	else
		((CButton*)GetDlgItem(IDC_CHECK_SHAPETOSIZE5))->SetCheck(BST_UNCHECKED);

	if (m_stOption.m_stShapeToSize.m_bStep006)
		((CButton*)GetDlgItem(IDC_CHECK_SHAPETOSIZE6))->SetCheck(BST_CHECKED);
	else
		((CButton*)GetDlgItem(IDC_CHECK_SHAPETOSIZE6))->SetCheck(BST_UNCHECKED);
}

void CDlgOption::UpdateTitleStep()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	//
	GetDlgItem(IDC_CHECK_FIRSTSTEP1)->SetWindowText(m_stOption.m_stFirstCameraStep.m_szTitleStep01);
	GetDlgItem(IDC_CHECK_FIRSTSTEP2)->SetWindowText(m_stOption.m_stFirstCameraStep.m_szTitleStep02);
	GetDlgItem(IDC_CHECK_FIRSTSTEP3)->SetWindowText(m_stOption.m_stFirstCameraStep.m_szTitleStep03);
	GetDlgItem(IDC_CHECK_FIRSTSTEP4)->SetWindowText(m_stOption.m_stFirstCameraStep.m_szTitleStep04);
	GetDlgItem(IDC_CHECK_FIRSTSTEP5)->SetWindowText(m_stOption.m_stFirstCameraStep.m_szTitleStep05);
	GetDlgItem(IDC_CHECK_FIRSTSTEP6)->SetWindowText(m_stOption.m_stFirstCameraStep.m_szTitleStep06);


	//
#ifdef DEF_SECONDCAMERA_CHECKSIZE
	GetDlgItem(IDC_CHECK_SECONDSTEP1)->SetWindowText(m_stOption.m_stFirstCameraStep.m_szTitleStep01);
#else
	GetDlgItem(IDC_CHECK_SECONDSTEP1)->SetWindowText(m_stOption.m_stFirstCameraStep.m_szTitleStep01);
#endif
	GetDlgItem(IDC_CHECK_SECONDSTEP2)->SetWindowText(m_stOption.m_stSecondCameraStep.m_szTitleStep02);
	GetDlgItem(IDC_CHECK_SECONDSTEP3)->SetWindowText(m_stOption.m_stSecondCameraStep.m_szTitleStep03);
	GetDlgItem(IDC_CHECK_SECONDSTEP4)->SetWindowText(m_stOption.m_stSecondCameraStep.m_szTitleStep04);
	GetDlgItem(IDC_CHECK_SECONDSTEP5)->SetWindowText(m_stOption.m_stSecondCameraStep.m_szTitleStep05);
	GetDlgItem(IDC_CHECK_SECONDSTEP6)->SetWindowText(m_stOption.m_stSecondCameraStep.m_szTitleStep06);

	// Version 1.3.6.9
	GetDlgItem(IDC_CHECK_SHAPETOSIZE1)->SetWindowText(m_stOption.m_stShapeToSize.m_szTitleStep01);
	GetDlgItem(IDC_CHECK_SHAPETOSIZE2)->SetWindowText(m_stOption.m_stShapeToSize.m_szTitleStep02);
	GetDlgItem(IDC_CHECK_SHAPETOSIZE3)->SetWindowText(m_stOption.m_stShapeToSize.m_szTitleStep03);
	GetDlgItem(IDC_CHECK_SHAPETOSIZE4)->SetWindowText(m_stOption.m_stShapeToSize.m_szTitleStep04);
	GetDlgItem(IDC_CHECK_SHAPETOSIZE5)->SetWindowText(m_stOption.m_stShapeToSize.m_szTitleStep05);
	GetDlgItem(IDC_CHECK_SHAPETOSIZE6)->SetWindowText(m_stOption.m_stShapeToSize.m_szTitleStep06);
}

void CDlgOption::OnBnClickedBtnLoad()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	TCHAR szLocation[MAX_PATH] = { 0, };
	TCHAR szFilePath[MAX_PATH] = { 0, };

	CUtil::GetCurrentDirectory(szLocation, MAX_PATH);
	if (CUtil::SelectFile(NULL, szFilePath, MAX_PATH, _T("*.xml"), _T("Option Files (*.xml)|*.xml|"), NULL, TRUE))
	{
		INFO_OPTION stOption;
		memset(&stOption, 0x00, sizeof(INFO_OPTION));

		BOOL bResult = pCaptureManager->m_Xml.LoadOption(szFilePath, stOption);
		if (bResult)
		{
			m_stOption = stOption;
			m_szFilePath = szFilePath;

			GetDlgItem(IDC_EDIT_FILEPATH)->SetWindowText(m_szFilePath);
			UpdateOptions();
		}
		else
		{
			MessageBox(STR_MSG_ELOAD_INSPECTION);
		}
	}
}

void CDlgOption::OnBnClickedBtnSave()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	CString szPath;
	GetDlgItem(IDC_EDIT_FILEPATH)->GetWindowText(szPath);

	const BOOL bExist = CUtil::IsExistFile(szPath);
	if (FALSE == bExist)
	{
		TCHAR szLocation[MAX_PATH] = { 0, };
		TCHAR szFilePath[MAX_PATH] = { 0, };

		CUtil::GetCurrentDirectory(szLocation, MAX_PATH);
		if (CUtil::SelectFile(NULL, szFilePath, MAX_PATH, _T("*.xml"), _T("Option Files (*.xml)|*.xml|"), NULL, FALSE))
		{
			szPath = szFilePath;

			const int nLen = CUtil::StringLength(szFilePath);
			if (FALSE == CUtil::StringICompare((szFilePath + nLen - 4), _T(".xml")))
				szPath += _T(".xml");
		}
		else
		{
			return;
		}
	}

	ApplyOptions();
	BOOL bResult = pCaptureManager->m_Xml.SaveOption((LPTSTR)(LPCTSTR)szPath, m_stOption);
	if (TRUE == bResult)
	{
		m_szFilePath = szPath;
		GetDlgItem(IDC_EDIT_FILEPATH)->SetWindowText(szPath);
	}
	else
	{
		AfxMessageBox(STR_MSG_FAIL_SAVE_OPTION);
	}
}

void CDlgOption::OnBnClickedBtnSaveas()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	TCHAR szLocation[MAX_PATH] = { 0, };
	TCHAR szFilePath[MAX_PATH] = { 0, };

	CUtil::GetCurrentDirectory(szLocation, MAX_PATH);
	if (CUtil::SelectFile(NULL, szFilePath, MAX_PATH, _T("*.xml"), _T("Option Files (*.xml)|*.xml|"), NULL, FALSE))
	{
		CString szPath = szFilePath;

		const int nLen = CUtil::StringLength(szFilePath);
		if (FALSE == CUtil::StringICompare((szFilePath + nLen - 4), _T(".xml")))
			szPath += _T(".xml");

		ApplyOptions();
		BOOL bResult = pCaptureManager->m_Xml.SaveOption((LPTSTR)(LPCTSTR)szPath, m_stOption);
		if (TRUE == bResult)
		{
			m_szFilePath = szPath;
			GetDlgItem(IDC_EDIT_FILEPATH)->SetWindowText(szPath);
		}
		else
		{
			AfxMessageBox(STR_MSG_FAIL_SAVE_OPTION);
		}
	}
}

template<typename T1, typename T2, typename T3>
auto _MinMax(T1 value, T2 min, T3 max)->decltype(value){
	auto tmp = (value < min) ? min : value;
	tmp = (tmp > max) ? max : tmp;
	return tmp;
}

void CDlgOption::ApplyOptions()
{
	CString szValue;
#ifdef DEF_DELAY_CAPTURE
	// Capture
	GetDlgItem(IDC_EDIT_CAPTURE_DELAY)->GetWindowText(szValue);
	m_stOption.m_stCapture.m_nDelay = CUtil::StringToInt((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_stCapture.m_nDelay = _MinMax(m_stOption.m_stCapture.m_nDelay, MIN_CAPTURE_DELAY, MAX_CAPTURE_DELAY);
#endif

	//Get Value (min)
	int idx = 0;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE1)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMin = _MinMax(m_stOption.m_pstRange[0][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE2)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMin = _MinMax(m_stOption.m_pstRange[0][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE3)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMin = _MinMax(m_stOption.m_pstRange[0][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE4)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMin = _MinMax(m_stOption.m_pstRange[0][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE5)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMin = _MinMax(m_stOption.m_pstRange[0][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE6)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMin = _MinMax(m_stOption.m_pstRange[0][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE7)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMin = _MinMax(m_stOption.m_pstRange[0][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE8)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMin = _MinMax(m_stOption.m_pstRange[0][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE9)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMin = _MinMax(m_stOption.m_pstRange[0][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE10)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMin = _MinMax(m_stOption.m_pstRange[0][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE11)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMin = _MinMax(m_stOption.m_pstRange[0][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE12)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMin = _MinMax(m_stOption.m_pstRange[0][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE13)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMin = _MinMax(m_stOption.m_pstRange[0][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE14)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMin = _MinMax(m_stOption.m_pstRange[0][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE15)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMin = _MinMax(m_stOption.m_pstRange[0][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE16)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMin = _MinMax(m_stOption.m_pstRange[0][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE17)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMin = _MinMax(m_stOption.m_pstRange[0][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE18)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMin = _MinMax(m_stOption.m_pstRange[0][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE19)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMin = _MinMax(m_stOption.m_pstRange[0][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE20)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMin = _MinMax(m_stOption.m_pstRange[0][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE21)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMin = _MinMax(m_stOption.m_pstRange[0][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE22)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMin = _MinMax(m_stOption.m_pstRange[0][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE23)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMin = _MinMax(m_stOption.m_pstRange[0][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE24)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMin = _MinMax(m_stOption.m_pstRange[0][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE25)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMin = _MinMax(m_stOption.m_pstRange[0][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE26)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMin = _MinMax(m_stOption.m_pstRange[0][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE27)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMin = _MinMax(m_stOption.m_pstRange[0][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE28)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMin = _MinMax(m_stOption.m_pstRange[0][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;

	//Get Value (min)

	// Get Value (max)
	idx = 0;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE1)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMax = _MinMax(m_stOption.m_pstRange[0][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE2)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMax = _MinMax(m_stOption.m_pstRange[0][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE3)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMax = _MinMax(m_stOption.m_pstRange[0][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE4)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMax = _MinMax(m_stOption.m_pstRange[0][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE5)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMax = _MinMax(m_stOption.m_pstRange[0][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE6)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMax = _MinMax(m_stOption.m_pstRange[0][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE7)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMax = _MinMax(m_stOption.m_pstRange[0][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE8)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMax = _MinMax(m_stOption.m_pstRange[0][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE9)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMax = _MinMax(m_stOption.m_pstRange[0][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE10)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMax = _MinMax(m_stOption.m_pstRange[0][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE11)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMax = _MinMax(m_stOption.m_pstRange[0][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE12)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMax = _MinMax(m_stOption.m_pstRange[0][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE13)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMax = _MinMax(m_stOption.m_pstRange[0][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE14)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMax = _MinMax(m_stOption.m_pstRange[0][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE15)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMax = _MinMax(m_stOption.m_pstRange[0][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE16)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMax = _MinMax(m_stOption.m_pstRange[0][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE17)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMax = _MinMax(m_stOption.m_pstRange[0][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE18)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMax = _MinMax(m_stOption.m_pstRange[0][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE19)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMax = _MinMax(m_stOption.m_pstRange[0][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE20)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMax = _MinMax(m_stOption.m_pstRange[0][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE21)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMax = _MinMax(m_stOption.m_pstRange[0][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE22)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMax = _MinMax(m_stOption.m_pstRange[0][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE23)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMax = _MinMax(m_stOption.m_pstRange[0][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE24)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMax = _MinMax(m_stOption.m_pstRange[0][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE25)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMax = _MinMax(m_stOption.m_pstRange[0][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE26)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMax = _MinMax(m_stOption.m_pstRange[0][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE27)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMax = _MinMax(m_stOption.m_pstRange[0][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE28)->GetWindowText(szValue);
	m_stOption.m_pstRange[0][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[0][idx].m_fMax = _MinMax(m_stOption.m_pstRange[0][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;

	// Get Value (min)
	idx = 0;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_1)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMin = _MinMax(m_stOption.m_pstRange[1][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_2)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());	
	m_stOption.m_pstRange[1][idx].m_fMin = _MinMax(m_stOption.m_pstRange[1][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_3)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());	
	m_stOption.m_pstRange[1][idx].m_fMin = _MinMax(m_stOption.m_pstRange[1][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_4)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());	
	m_stOption.m_pstRange[1][idx].m_fMin = _MinMax(m_stOption.m_pstRange[1][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_5)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());	
	m_stOption.m_pstRange[1][idx].m_fMin = _MinMax(m_stOption.m_pstRange[1][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_6)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMin = _MinMax(m_stOption.m_pstRange[1][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_7)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMin = _MinMax(m_stOption.m_pstRange[1][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_8)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMin = _MinMax(m_stOption.m_pstRange[1][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_9)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMin = _MinMax(m_stOption.m_pstRange[1][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_10)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMin = _MinMax(m_stOption.m_pstRange[1][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_11)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMin = _MinMax(m_stOption.m_pstRange[1][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_12)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMin = _MinMax(m_stOption.m_pstRange[1][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_13)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMin = _MinMax(m_stOption.m_pstRange[1][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_14)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMin = _MinMax(m_stOption.m_pstRange[1][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_15)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMin = _MinMax(m_stOption.m_pstRange[1][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_16)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMin = _MinMax(m_stOption.m_pstRange[1][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_17)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMin = _MinMax(m_stOption.m_pstRange[1][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_18)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMin = _MinMax(m_stOption.m_pstRange[1][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_19)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMin = _MinMax(m_stOption.m_pstRange[1][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_20)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMin = _MinMax(m_stOption.m_pstRange[1][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_21)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMin = _MinMax(m_stOption.m_pstRange[1][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_22)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMin = _MinMax(m_stOption.m_pstRange[1][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_23)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMin = _MinMax(m_stOption.m_pstRange[1][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_24)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMin = _MinMax(m_stOption.m_pstRange[1][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_25)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMin = _MinMax(m_stOption.m_pstRange[1][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_26)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMin = _MinMax(m_stOption.m_pstRange[1][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_27)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMin = _MinMax(m_stOption.m_pstRange[1][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEMEASURE_SECOND_28)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMin = _MinMax(m_stOption.m_pstRange[1][idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;

	// Get Value (max)
	idx = 0;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_1)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMax = _MinMax(m_stOption.m_pstRange[1][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_2)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMax = _MinMax(m_stOption.m_pstRange[1][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_3)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMax = _MinMax(m_stOption.m_pstRange[1][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_4)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMax = _MinMax(m_stOption.m_pstRange[1][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_5)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMax = _MinMax(m_stOption.m_pstRange[1][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_6)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMax = _MinMax(m_stOption.m_pstRange[1][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_7)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMax = _MinMax(m_stOption.m_pstRange[1][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_8)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMax = _MinMax(m_stOption.m_pstRange[1][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_9)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMax = _MinMax(m_stOption.m_pstRange[1][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_10)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMax = _MinMax(m_stOption.m_pstRange[1][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_11)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMax = _MinMax(m_stOption.m_pstRange[1][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_12)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMax = _MinMax(m_stOption.m_pstRange[1][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_13)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMax = _MinMax(m_stOption.m_pstRange[1][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_14)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMax = _MinMax(m_stOption.m_pstRange[1][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_15)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMax = _MinMax(m_stOption.m_pstRange[1][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_16)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMax = _MinMax(m_stOption.m_pstRange[1][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_17)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMax = _MinMax(m_stOption.m_pstRange[1][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_18)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMax = _MinMax(m_stOption.m_pstRange[1][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_19)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMax = _MinMax(m_stOption.m_pstRange[1][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_20)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMax = _MinMax(m_stOption.m_pstRange[1][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_21)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMax = _MinMax(m_stOption.m_pstRange[1][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_22)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMax = _MinMax(m_stOption.m_pstRange[1][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_23)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMax = _MinMax(m_stOption.m_pstRange[1][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_24)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMax = _MinMax(m_stOption.m_pstRange[1][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_25)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMax = _MinMax(m_stOption.m_pstRange[1][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_26)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMax = _MinMax(m_stOption.m_pstRange[1][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_27)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMax = _MinMax(m_stOption.m_pstRange[1][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEMEASURE_SECOND_28)->GetWindowText(szValue);
	m_stOption.m_pstRange[1][idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRange[1][idx].m_fMax = _MinMax(m_stOption.m_pstRange[1][idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;

	// Spec Range (min)
	idx = 0;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC1)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMin = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMin, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC2)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMin = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMin, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC3)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMin = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMin, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC4)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMin = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMin, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC5)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMin = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMin, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC6)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMin = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMin, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC7)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMin = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMin, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC8)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMin = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMin, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC9)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMin = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMin, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC10)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMin = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMin, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC11)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMin = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMin, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC12)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMin = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMin, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC13)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMin = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMin, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC14)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMin = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMin, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC15)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMin = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMin, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC16)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMin = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMin, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC17)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMin = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMin, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC18)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMin = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMin, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC19)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMin = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMin, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC20)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMin = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMin, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC21)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMin = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMin, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC22)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMin = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMin, MIN_SIZE, MAX_SIZE);		idx++;
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC23)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMin = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMin, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC24)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMin = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMin, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC25)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMin = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMin, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC26)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMin = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMin, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC27)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMin = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMin, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZESPEC28)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMin = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMin, MIN_SIZE, MAX_SIZE);		idx++;

	// Spec Range (max)
	idx = 0;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC1)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMax = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMax, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC2)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());	
	m_stOption.m_pstRangeSpec[idx].m_fMax = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMax, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC3)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());	
	m_stOption.m_pstRangeSpec[idx].m_fMax = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMax, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC4)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());	
	m_stOption.m_pstRangeSpec[idx].m_fMax = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMax, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC5)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());	
	m_stOption.m_pstRangeSpec[idx].m_fMax = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMax, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC6)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMax = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMax, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC7)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMax = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMax, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC8)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMax = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMax, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC9)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMax = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMax, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC10)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMax = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMax, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC11)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMax = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMax, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC12)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMax = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMax, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC13)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMax = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMax, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC14)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMax = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMax, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC15)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMax = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMax, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC16)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMax = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMax, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC17)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMax = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMax, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC18)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMax = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMax, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC19)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMax = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMax, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC20)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMax = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMax, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC21)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMax = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMax, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC22)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMax = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMax, MIN_SIZE, MAX_SIZE);		idx++;
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC23)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMax = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMax, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC24)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMax = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMax, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC25)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMax = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMax, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC26)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMax = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMax, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC27)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMax = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMax, MIN_SIZE, MAX_SIZE);		idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZESPEC28)->GetWindowText(szValue);
	m_stOption.m_pstRangeSpec[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstRangeSpec[idx].m_fMax = _MinMax(m_stOption.m_pstRangeSpec[idx].m_fMax, MIN_SIZE, MAX_SIZE);		idx++;

#ifdef USE_VALID_RANGE
	// Get Valid Value (min)
	idx = 0;
	GetDlgItem(IDC_EDIT_MIN_SIZEVALID1)->GetWindowText(szValue);
	m_stOption.m_pstValidRange[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstValidRange[idx].m_fMin = _MinMax(m_stOption.m_pstValidRange[idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEVALID2)->GetWindowText(szValue);
	m_stOption.m_pstValidRange[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstValidRange[idx].m_fMin = _MinMax(m_stOption.m_pstValidRange[idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	// Version 1.3.6.5 (치수 영역 추가 없이 PLC 통신 데이터 추가 (X1-X2, L))
	GetDlgItem(IDC_EDIT_MIN_SIZEVALID3)->GetWindowText(szValue);
	m_stOption.m_pstValidRange[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstValidRange[idx].m_fMin = _MinMax(m_stOption.m_pstValidRange[idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEVALID4)->GetWindowText(szValue);
	m_stOption.m_pstValidRange[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstValidRange[idx].m_fMin = _MinMax(m_stOption.m_pstValidRange[idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	// Ver1.3.7.2 (치수 영역 추가 없이 PLC 통신 데이터 추가 (M1, M2)) 
	GetDlgItem(IDC_EDIT_MIN_SIZEVALID5)->GetWindowText(szValue);
	m_stOption.m_pstValidRange[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstValidRange[idx].m_fMin = _MinMax(m_stOption.m_pstValidRange[idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MIN_SIZEVALID6)->GetWindowText(szValue);
	m_stOption.m_pstValidRange[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstValidRange[idx].m_fMin = _MinMax(m_stOption.m_pstValidRange[idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;
	// Ver1.3.7.4 (치수 영역 추가 없이 PLC 통신 데이터 추가 (S1S3)) 
	GetDlgItem(IDC_EDIT_MIN_SIZEVALID7)->GetWindowText(szValue);
	m_stOption.m_pstValidRange[idx].m_fMin = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstValidRange[idx].m_fMin = _MinMax(m_stOption.m_pstValidRange[idx].m_fMin, MIN_SIZE, MAX_SIZE);	idx++;

	// Get Valid Value (max)
	idx = 0;
	GetDlgItem(IDC_EDIT_MAX_SIZEVALID1)->GetWindowText(szValue);
	m_stOption.m_pstValidRange[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstValidRange[idx].m_fMax = _MinMax(m_stOption.m_pstValidRange[idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEVALID2)->GetWindowText(szValue);
	m_stOption.m_pstValidRange[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstValidRange[idx].m_fMax = _MinMax(m_stOption.m_pstValidRange[idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	// Version 1.3.6.5 (치수 영역 추가 없이 PLC 통신 데이터 추가 (X1-X2, L))
	GetDlgItem(IDC_EDIT_MAX_SIZEVALID3)->GetWindowText(szValue);
	m_stOption.m_pstValidRange[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstValidRange[idx].m_fMax = _MinMax(m_stOption.m_pstValidRange[idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEVALID4)->GetWindowText(szValue);
	m_stOption.m_pstValidRange[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstValidRange[idx].m_fMax = _MinMax(m_stOption.m_pstValidRange[idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	// Ver1.3.7.2 (치수 영역 추가 없이 PLC 통신 데이터 추가 (M1, M2)) 
	GetDlgItem(IDC_EDIT_MAX_SIZEVALID5)->GetWindowText(szValue);
	m_stOption.m_pstValidRange[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstValidRange[idx].m_fMax = _MinMax(m_stOption.m_pstValidRange[idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	GetDlgItem(IDC_EDIT_MAX_SIZEVALID6)->GetWindowText(szValue);
	m_stOption.m_pstValidRange[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstValidRange[idx].m_fMax = _MinMax(m_stOption.m_pstValidRange[idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;
	// Ver1.3.7.4 (치수 영역 추가 없이 PLC 통신 데이터 추가 (S1S3)) 
	GetDlgItem(IDC_EDIT_MAX_SIZEVALID7)->GetWindowText(szValue);
	m_stOption.m_pstValidRange[idx].m_fMax = CUtil::StringToDouble((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	m_stOption.m_pstValidRange[idx].m_fMax = _MinMax(m_stOption.m_pstValidRange[idx].m_fMax, MIN_SIZE, MAX_SIZE);	idx++;

#endif

	// Enable Step
	m_stOption.m_stFirstCameraStep.m_bStep001 = (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_FIRSTSTEP1))->GetCheck());
	m_stOption.m_stFirstCameraStep.m_bStep002 = (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_FIRSTSTEP2))->GetCheck());
	m_stOption.m_stFirstCameraStep.m_bStep003 = (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_FIRSTSTEP3))->GetCheck());
	m_stOption.m_stFirstCameraStep.m_bStep004 = (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_FIRSTSTEP4))->GetCheck());
	m_stOption.m_stFirstCameraStep.m_bStep005 = (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_FIRSTSTEP5))->GetCheck());
	m_stOption.m_stFirstCameraStep.m_bStep006 = (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_FIRSTSTEP6))->GetCheck());
	m_stOption.m_stFirstCameraStep.m_bStep007 = (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_FIRSTSTEP1))->GetCheck());

#ifdef DEF_SECONDCAMERA_CHECKSIZE
	m_stOption.m_stSecondCameraStep.m_bStep001 = (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_SECONDSTEP1))->GetCheck());
#else
	m_stOption.m_stSecondCameraStep.m_bStep001 = FALSE;
#endif
	m_stOption.m_stSecondCameraStep.m_bStep002 = (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_SECONDSTEP2))->GetCheck());
	m_stOption.m_stSecondCameraStep.m_bStep003 = (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_SECONDSTEP3))->GetCheck());
	m_stOption.m_stSecondCameraStep.m_bStep004 = (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_SECONDSTEP4))->GetCheck());
	m_stOption.m_stSecondCameraStep.m_bStep005 = (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_SECONDSTEP5))->GetCheck());
	m_stOption.m_stSecondCameraStep.m_bStep006 = (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_SECONDSTEP6))->GetCheck());
	m_stOption.m_stSecondCameraStep.m_bStep007 = (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_SECONDSTEP1))->GetCheck());

	// Version 1.3.6.9 Update
	m_stOption.m_stShapeToSize.m_bStep001 = (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_SHAPETOSIZE1))->GetCheck());
	m_stOption.m_stShapeToSize.m_bStep002 = (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_SHAPETOSIZE2))->GetCheck());
	m_stOption.m_stShapeToSize.m_bStep003 = (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_SHAPETOSIZE3))->GetCheck());
	m_stOption.m_stShapeToSize.m_bStep004 = (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_SHAPETOSIZE4))->GetCheck());
	m_stOption.m_stShapeToSize.m_bStep005 = (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_SHAPETOSIZE5))->GetCheck());
	m_stOption.m_stShapeToSize.m_bStep006 = (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_SHAPETOSIZE6))->GetCheck());
	m_stOption.m_stShapeToSize.m_bStep007 = (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_SHAPETOSIZE1))->GetCheck());
}
