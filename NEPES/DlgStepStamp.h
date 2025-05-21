#pragma once
#include "afxwin.h"
#include "CommonCapture.h"
#include "Proc/ProcessDef.h"
#include "afxcmn.h"

// CDlgStepStamp dialog
class CDlgStepStamp : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgStepStamp)

public:
	CDlgStepStamp(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgStepStamp();

	void UpdateCameraPos(TYPE_CAMERAPOS ePos);
	void UpdateSelectedRoiPos(const INFO_RECT_ROI* pROI);
	
	void SetDefaultValue();
	void UpdateCtrlStepStamp(const INFO_INSPECTION_STAMP* pInspectStamp);

// Dialog Data
	enum { IDD = IDD_DLG_STEP06 };
protected:
	TYPE_CAMERAPOS m_eCameraPos;
	const TYPE_STEP m_eStep = TYPE_STEP_006;

	const INFO_INSPECTION_STAMP* GetInspectionInfo();
	BOOL SetInspectionInfo(const INFO_INSPECTION_STAMP* pstInfo);

	void UpdateInspectionInfoBackup();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedBtnStrobe();
	afx_msg void OnBnClickedBtnApply();

public:
	int m_iProbability;
	int m_iBlobSize;
	afx_msg void OnNMCustomdrawSliderProbability(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderBlob(NMHDR *pNMHDR, LRESULT *pResult);
	CSliderCtrl m_ctlSliderProbability;
	CSliderCtrl m_ctlSliderBlobSize;
	afx_msg void OnBnClickedButtonTrain();
	void CDlgStepStamp::SetParameter(const INFO_MARS_PARA* pstInfo);
	
	
	afx_msg void OnCheckImgLog();
	// Version 1.3.8.1
	afx_msg void OnCheckImgCompress();
	
};
