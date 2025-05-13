#pragma once
#include "CommonCapture.h"
#include "CustomMessage.h"
#include "Inspection/Sample.h"

// CTapSizeList dialog

class CTapSizeList : public CDialogEx
{
	DECLARE_DYNAMIC(CTapSizeList)

public:
	CTapSizeList(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTapSizeList();

	void UpdateResultSize(TYPE_CAMERAPOS eCameraPos, CSampleSide* pSample);
	void UpdateRangeValue(TYPE_CAMERAPOS eCameraPos);
	void UpdateSizeName();

// Dialog Data
	enum { IDD = IDD_TAP_SIZELIST };

protected:
	const int MARGIN = 5;

	OUTPUT_DISTANCE m_stDistanceFirst[TYPE_GEOMETRY_DISTANCE_MAX];
	OUTPUT_DISTANCE m_stDistanceSecond[TYPE_GEOMETRY_DISTANCE_MAX];

	CCustomMessage m_ctlMessureSampleFirst;
	CCustomMessage m_ctlMessureSampleSecond;

	CListCtrl m_ctlListSampleFirst;
	CListCtrl m_ctlListSampleSecond;

	void AdjustLayout();

	void UpdateList();
	void UpdateList(TYPE_CAMERAPOS eCameraPos);

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg void OnNMCustomdrawListSampleA(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawListSampleB(NMHDR *pNMHDR, LRESULT *pResult);
};
