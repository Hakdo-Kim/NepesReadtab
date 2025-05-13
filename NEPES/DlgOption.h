#pragma once
#include "CommonCapture.h"
#include "afxwin.h"

#include "NumberEdit.h"

// CDlgOption dialog

class CDlgOption : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgOption)

public:
	CDlgOption(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgOption();

	CString m_szFilePath;
	INFO_OPTION m_stOption;

// Dialog Data
	enum { IDD = IDD_DLG_OPTION };
protected:
	CNumberEdit m_ctlEditMin[TYPE_GEOMETRY_DISTANCE_MAX];
	CNumberEdit m_ctlEditMax[TYPE_GEOMETRY_DISTANCE_MAX];
	CNumberEdit m_ctlEditMinSecond[TYPE_GEOMETRY_DISTANCE_MAX];
	CNumberEdit m_ctlEditMaxSecond[TYPE_GEOMETRY_DISTANCE_MAX];
	CNumberEdit m_ctlEditSpecMin[TYPE_GEOMETRY_DISTANCE_MAX];
	CNumberEdit m_ctlEditSpecMax[TYPE_GEOMETRY_DISTANCE_MAX];

#ifdef DEF_DELAY_CAPTURE
	void UpdateCapture();
#endif
	void UpdateSizeName();
	void UpdateRange();
	void UpdateRangeSecond();
	void UpdateSpec();
	void UpdateStepEnable();
	void UpdateTitleStep();

#ifdef USE_VALID_RANGE
	void UpdateValid();
#endif

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBtnStepname();
	afx_msg void OnBnClickedBtnSizename();

	afx_msg void OnBnClickedBtnSave();
	afx_msg void OnBnClickedBtnLoad();
	afx_msg void OnBnClickedBtnSaveas();

	void ApplyOptions();
	void UpdateOptions();
public:
	CNumberEdit m_ctlEditValidMin1;
	CNumberEdit m_ctlEditValidMax1;
	CNumberEdit m_ctlEditValidMin2;
	CNumberEdit m_ctlEditValidMax2;
	// Version 1.3.6.5 (치수 영역 추가 없이 PLC 통신 데이터 추가 (X1-X2, L))
	CNumberEdit m_ctlEditValidMin3;
	CNumberEdit m_ctlEditValidMax3;
	CNumberEdit m_ctlEditValidMin4;
	CNumberEdit m_ctlEditValidMax4;
	// Ver1.3.7.2 (치수 영역 추가 없이 PLC 통신 데이터 추가 (M1, M2)) 
	CNumberEdit m_ctlEditValidMin5;
	CNumberEdit m_ctlEditValidMax5;
	CNumberEdit m_ctlEditValidMin6;
	CNumberEdit m_ctlEditValidMax6;
	// Ver1.3.7.4 (치수 영역 추가 없이 PLC 통신 데이터 추가 (S1S3)) 
	CNumberEdit m_ctlEditValidMin7;
	CNumberEdit m_ctlEditValidMax7;

	const double MIN_SIZE = -10000.0;
	const double MAX_SIZE = 10000.0;
	const double MIN_SUB_SIZE = -10000.0;
	const double MAX_SUB_SIZE = 10000.0;
#ifdef DEF_DELAY_CAPTURE
	CNumberEdit m_ctlEditCaptureDelay;
	const int MIN_CAPTURE_DELAY = 0;
	const int MAX_CAPTURE_DELAY = 1000;
#endif
};
