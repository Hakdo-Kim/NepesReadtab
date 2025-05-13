#pragma once
#include "afxwin.h"
#include "CustomScrollViewEdit.h"
#include "CustomMessage.h"
#include "CustomStep.h"

#include "DlgStepSize.h"
#include "DlgStepStain.h"
#include "DlgStepDiffer.h"
#include "DlgStepBubble.h"
#include "DlgStepScratch.h"
#include "DlgStepStamp.h"

#include "CommonCapture.h"
#include "UserInterfaceDef.h"
//Version 1.3.7.8
#include <memory>

// CDlgSequence dialog

class CDlgSequence : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgSequence)
public:
	CDlgSequence(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgSequence();

	void UpdateInformation(TYPE_CAMERAPOS eCameraType, const INFO_IMAGE* pImage);
	// Version 1.3.7.8
	void UpdateInformation(TYPE_CAMERAPOS eCameraType, CSampleSide* sample, const INFO_IMAGE* pImage, const INFO_IMAGE* pImage1, const INFO_IMAGE* pImage2);
	void DisplayImage(const INFO_IMAGE* pImage);
	void UpdateTitleStep();

// Dialog Data
	enum { IDD = IDD_DLG_SEQUENCE };
protected:
	HICON m_hIcon;

	TYPE_CAMERAPOS	m_eCameraType;
	INFO_IMAGE*		m_pImagePointer;
	// Version 1.3.7.8
	INFO_IMAGE*		m_pImagePointer1;
	INFO_IMAGE*		m_pImagePointer2;
	std::unique_ptr<CSampleSide> m_Sample;


	const int MINWIDTH = 960;
	const int MINHEIGHT = 600;
	const int MARGIN = 5;

	TYPE_STEP m_eSelectedStep;

	RECT m_rtStep;
	RECT m_rtTool;
	RECT m_rtBar;


	CCustomMessage m_ctlStaticTitle;

	CCustomScrollViewEdit* m_pCustomView;
	CCustomStep* m_pStepList[TYPE_STEP_MAX];

	CDlgStepSize m_dlgStepSize;
	CDlgStepStain m_dlgStepStain;
	CDlgStepDiffer m_dlgStepDiffer;
	CDlgStepBubble m_dlgStepBubble;
	CDlgStepScratch m_dlgStepScratch;
	CDlgStepStamp m_dlgStepStamp;


	void AdjustLayout();
	void DrawBarLayout(CDC* pDC, CRect rect, COLORREF rgbBk, DWORD dwLT, DWORD dwLB, DWORD dwRT, DWORD dwRB);
	void DrawLayout(CDC* pDC, CRect rect, COLORREF rgbBk, DWORD dwLT, DWORD dwLB, DWORD dwRT, DWORD dwRB);
	void SetSelectedStep(TYPE_STEP eStep);

	INFO_INSPECTION GetCurrentInspectionInfo(TYPE_CAMERAPOS ePos);
	BOOL UpdateCurrentInspectionInfo(TYPE_CAMERAPOS ePos, const INFO_INSPECTION* pstInspection);


	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg void OnClose();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedBtnDefault();
	afx_msg void OnBnClickedBtnLoad();
	afx_msg void OnBnClickedBtnSave();
	afx_msg void OnBnClickedBtnSaveas();
	afx_msg void OnBnClickedBtnCancel();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	// Command Function
	afx_msg LRESULT OnMsgGrabEdit(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMsgStrobe(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMsgRequestImage(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMsgEditStepDone(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMsgStepSizeRoiSelected(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMsgStepSizeRoiChanged(WPARAM wParam, LPARAM lParam);
	
	// Version 1.3.7.8
	afx_msg LRESULT OnMsgRequestResult(WPARAM wParam, LPARAM lParam);

};
