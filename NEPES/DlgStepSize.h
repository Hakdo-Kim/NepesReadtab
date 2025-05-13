#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "CommonCapture.h"
#include "Proc/ProcessDef.h"
#include "Inspection/Sample.h"

#include <opencv2/core.hpp>

// Version 1.3.7.8
#include <memory> 

// CDlgStepSize dialog

class CDlgStepSize : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgStepSize)

public:
	CDlgStepSize(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgStepSize();

	void UpdateCameraPos(TYPE_CAMERAPOS ePos);
	void UpdateSelectedRoiPos(const int nCur, const INFO_FINDLINE_ROI* pROI);

	void SetDefaultValue();
	void UpdateCtrlStepSize(const INFO_INSPECTION_SIZE* pInspectSize);
	void UpdateCtrlStrobe(const INFO_INSPECTION_SIZE* pInspectSize);
	void UpdateResultSize(TYPE_CAMERAPOS eCameraPos, CSampleSide* pSample);

	int GetSelectedShotStep();

// Dialog Data
	enum { IDD = IDD_DLG_STEP01 };

	// Version 1.3.7.1
	void GetRealValue(double dValues[]);

protected:
	// Version 1.3.7.8
	CSampleSide m_sampleData;
	cv::Mat m_CapturedImg[2];
	std::unique_ptr<CSampleSide> m_Sample;
	//

	TYPE_CAMERAPOS m_eCameraPos;
	const TYPE_STEP m_eStep = TYPE_STEP_001;
	const TYPE_STEP m_eStepSecond = TYPE_STEP_007;

	const int MAX_APP_COUNT = TYPE_FINDLINE_MAX;

	const int MIN_STRENGTH_THRESHOLD = 0;
	const int MAX_STRENGTH_THRESHOLD = 255;

	const int MIN_SAMPLE = 1;
	const int MAX_SAMPLE = 100;

	const int MIN_KERNEL = 3;
	const int MAX_KERNEL = 7;

	const int MIN_MINANGLE = 0;
	const int MAX_MAXANGLE = 180;

	const int MIN_MAXANGLE = MIN_MINANGLE + 1;
	const int MAX_MINANGLE = MAX_MAXANGLE -1;

	const int MIN_DISTANCE_THRESHOLD = 0;
	const int MAX_DISTANCE_THRESHOLD = 100;

	static const CString m_strFindLineName[TYPE_FINDLINE_MAX];


	CListCtrl m_ctlListFindLine;
	CComboBox m_ctlDirection;
	CComboBox m_ctlPolarity;
	CComboBox m_ctlLookFor;
	CComboBox m_ctlSelectShotStep;
	CListCtrl m_ctlListSizeResult;

	CSpinButtonCtrl m_ctlSpenStrength;
	CSpinButtonCtrl m_ctlSpinSample;
	CSpinButtonCtrl m_ctlSpinKernel;
	CSpinButtonCtrl m_ctlSpinMinAngle;
	CSpinButtonCtrl m_ctlSpinMaxAngle;
	CSpinButtonCtrl m_ctlSpinDistance;

	void SetEnableFindLine(BOOL bEnable);
	void SetEnableAngle(BOOL bEnable);

	const INFO_INSPECTION_SIZE* GetInspectionInfo(const int iStepIndex);
	const INFO_SIZE_GAIN* GetSizeGain();
	BOOL SetInspectionInfo(const int iStepIndex, const INFO_INSPECTION_SIZE* pstInfo);
	BOOL SetFindLineROI(const int iStepIndex, const INFO_FINDLINE_ROI* pstInfo, const INFO_IMAGE* pRefImage, const int iLineIndex);
	BOOL SetFindLineParameter(const int iStepIndex, const INFO_FINDLINE_PARAMETER* pstInfo, const int iLineIndex);
	BOOL SetSizeGain(const INFO_SIZE_GAIN* pstInfo);

	INFO_FINDLINE_PARAMETER m_pstFindLineParameter[TYPE_FINDLINE_MAX];
	void SetControlFindLineParameter(const INFO_FINDLINE_PARAMETER* pstInfo);
	INFO_FINDLINE_PARAMETER GetControlFindLineParameter();

	int GetEditValue(const DWORD dwCtrlID);
	void SetEditValue(const DWORD dwCtrlID, int nValue);


	void UpdateImageFromDisplay(BOOL both = FALSE);
	void Process();

	void UpdateInspectionInfoBackup();
		
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnNMThemeChangedListFindline(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedCheckSearchangle();
	afx_msg void OnBnClickedBtnCalibrate();
	afx_msg void OnBnClickedBtnApply();
	afx_msg void OnDeltaposSpinKernel(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedListFindline(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnParameterControlChange();
	afx_msg void OnBnClickedBtnStrobe();
	afx_msg void OnBnClickedBtnGain();
	afx_msg void OnCbnSelchangeComboSelectshotstep();

	int m_iDirection;
	int m_iPolarity;
	int m_iLookFor;
	int m_iStrengthThreshold;
	int m_iSampling;
	int m_iKernelSize;
	BOOL m_bSearchAngle;
	int m_iMinAngle;
	int m_iMaxAngle;
	int m_iDistanceThreshold;
	int m_iSelectShotStep;

	void ModifyParams();

	void Log(char* pszLog, ...);

	OUTPUT_SIZE m_OutputSize[2];
};
