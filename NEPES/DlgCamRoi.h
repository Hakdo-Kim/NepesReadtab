#pragma once
#include "ViewRoi.h"

// CDlgCamRoi dialog

class CDlgCamRoi : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgCamRoi)

public:
	CDlgCamRoi(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgCamRoi();

// Dialog Data
	enum { IDD = IDD_DLG_CAMROI };

	void UpdateInformation(const INFO_DEFROI* pDefROI);


	void SetRoi(const INFO_ROI_PARA* pstRoi);
	void SetRoiPosition(int x, int y, int w, int h);

	void GetRoi(INFO_ROI_PARA* pstRoi);
	void CorrectRoi(INFO_ROI_PARA* pstRoi);


protected:
	CViewRoi m_RoiView;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	DECLARE_MESSAGE_MAP()
	LRESULT OnNotifyChangeTrackRect(WPARAM wParam, LPARAM lParam);
	afx_msg void OnSize(UINT nType, int cx, int cy);



};
