#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "CommonCapture.h"
#include "NumberEdit.h"

// CDlgCalibrate dialog

class CDlgCalibrate : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgCalibrate)

public:
	CDlgCalibrate(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgCalibrate();

	//INFO_CALIBRATION* m_pstCalibrate;

// Dialog Data
	enum { IDD = IDD_DLG_CALIBRATE };
protected:
	TYPE_CAMERAPOS m_eCameraPos;
	const TYPE_STEP m_eStep = TYPE_STEP_001;
	const TYPE_STEP m_eStepSecond = TYPE_STEP_007;

	const int MIN_SPIN = 1;
	const int MAX_SPIN = 100000;

	// Edit Control의 값 = Spin Control의 값 / 100
	const double MIN_WIDTH = 0.01;
	const double MAX_WIDTH = 1000.00; // 1000.00로 변환 됨
	const double MIN_HEIGHT = 0.01;
	const double MAX_HEIGHT = 1000.00; // 1000.00로 변환 됨

	const int MIN_GRIDROWS = 1;
	const int MAX_GRIDROWS = 100;

	const int MIN_GRIDCOLS = 1;
	const int MAX_GRIDCOLS = 100;

	// Edit Control의 값 = Spin Control의 값 / 100
	const double MIN_SPACING = 0.01;
	const double MAX_SPACING = 1000.00;

	const double DOUBLE_CORRECTION = 0.000001; // double 오차 보정


	CListCtrl m_ctlFilePathList;

	CSpinButtonCtrl m_ctlWidth;
	CSpinButtonCtrl m_ctlHeight;
	CComboBox m_ctlComboPixelUnit;
	CSpinButtonCtrl m_ctlGridRows;
	CSpinButtonCtrl m_ctlGridCols;
	CNumberEdit m_EditSpacing;
	CSpinButtonCtrl m_ctlSpacing;
	CComboBox m_ctlComboChessUnit;

	int m_iMethod;
	
	double m_dWidth;
	double m_dHeight;
	int m_iPixelUnit;

	int m_iRow;
	int m_iCol;
	double m_dSpacing;
	int m_iChessUnit;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

	afx_msg void OnBnClickedRadioMethod();
	afx_msg void OnCommandAdd();
	afx_msg void OnCommandDelete();
	afx_msg void OnCommandReference();
	afx_msg void OnDeltaposSpinSpacing(NMHDR *pNMHDR, LRESULT *pResult);

	int m_iImgWidth;
	int m_iImgHeight;

	const INFO_CALIBRATION* m_pstCalibratePrev;

public:
	void UpdateCameraPos(TYPE_CAMERAPOS ePos);
	void SetImageSize(const int width, const int height) { m_iImgWidth = width; m_iImgHeight = height; }
	void SetInfoCalibration(const INFO_CALIBRATION* pstCalibrate) { m_pstCalibratePrev = pstCalibrate; }

protected:
	BOOL CalibrateStepSize(const INFO_CALIBRATION* pstInfo);
	int GetCalibrationResult();

	void SetEnableControls(BOOL bEnable);
	void SetEnablePixelControls(BOOL bEnable);
	void SetEnableChessControls(BOOL bEnable);

	void Log(char* pszLog, ...);
public:
	afx_msg void OnDeltaposSpinWidth(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinHeight(NMHDR *pNMHDR, LRESULT *pResult);
};
