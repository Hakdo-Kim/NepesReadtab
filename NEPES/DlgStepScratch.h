#pragma once
#include "afxwin.h"
#include "CommonCapture.h"
#include "Proc/ProcessDef.h"
#include "afxcmn.h"

// CDlgStepScratch dialog
class CDlgStepScratch : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgStepScratch)

public:
	CDlgStepScratch(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgStepScratch();

	void UpdateCameraPos(TYPE_CAMERAPOS ePos);
	void UpdateSelectedRoiPos(const INFO_RECT_ROI* pROI);
	
	void SetDefaultValue();
	void UpdateCtrlStepScratch(const INFO_INSPECTION_SCRATCH* pInspectScratch);

// Dialog Data
	enum { IDD = IDD_DLG_STEP05 };
protected:
	TYPE_CAMERAPOS m_eCameraPos;
	const TYPE_STEP m_eStep = TYPE_STEP_005;

	const INFO_INSPECTION_SCRATCH* GetInspectionInfo();
	BOOL SetInspectionInfo(const INFO_INSPECTION_SCRATCH* pstInfo);

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
	void CDlgStepScratch::SetParameter(const INFO_MARS_PARA* pstInfo);
	
	
	afx_msg void OnCheckImgLog();
	
};
