#pragma once
#include "afxwin.h"
#include "afxcmn.h"

#include "CustomMessage.h"

#include "CommonCapture.h"

// CTapMainSummary dialog

class CTapMainSummary : public CDialogEx
{
	DECLARE_DYNAMIC(CTapMainSummary)

public:
	CTapMainSummary(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTapMainSummary();

	void UpdateSummary();
	void UpdateTotalSummary();
	void SetStateStartInspection();
	void UpdateTitleStep();
	void UpdateSizeName();

// Dialog Data
	enum { IDD = IDD_TAP_MAINSUMMARY };
protected:
	const int MARGIN = 5;

	RECT m_rtView;
	RECT m_rtFirstView;
	RECT m_rtSecondView;

	CCustomMessage m_ctlTitleSampleTotal;
	CCustomMessage m_ctlTitleSampleFirst;
	CCustomMessage m_ctlTitleSampleSecond;
	CCustomMessage m_ctlErrorShapeSampleFirst;
	CCustomMessage m_ctlErrorShapeSampleSecond;
	CCustomMessage m_ctlErrorSizeSampleFirst;
	CCustomMessage m_ctlErrorSizeSampleSecond;

	CListCtrl m_ctlListCountSampleTotal;
	CListCtrl m_ctlListCountSampleFirst;
	CListCtrl m_ctlListCountSampleSecond;
	CListCtrl m_ctlListErrorShapeSampleFirst;
	CListCtrl m_ctlListErrorShapeSampleSecond;
	CListCtrl m_ctlListErrorSizeSampleFirst;
	CListCtrl m_ctlListErrorSizeSampleSecond;

	INFO_SUMMARY SummaryCount;

	void ChangeLotid();

	void AdjustLayout();
	void DrawLayout(CDC* pDC, CRect rect, COLORREF rgbBk, DWORD dwLT, DWORD dwLB, DWORD dwRT, DWORD dwRB);

	void SaveSummary(TCHAR* pszFilePath, TYPE_CAMERAPOS eCameraPos, INFO_SUMMARY_SAMPLE* pstSummarySample);
	void SaveSummary(HANDLE hFile, TYPE_CAMERAPOS eCameraPos, INFO_SUMMARY_SAMPLE* pstSummarySample);
	void SaveSummary(TCHAR* pszFilePath, INFO_SUMMARY_SAMPLE* pstSummarySampleA, INFO_SUMMARY_SAMPLE* pstSummarySampleB);
	void SaveSummaryTitle(HANDLE hFile);
	void SaveTotalSummary(HANDLE hFile);

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg void OnBnClickedBtnLotidSample();
public:
	afx_msg void OnBnClickedBtnSummarycountReset();
	afx_msg void OnBnClickedRadioSummarytotal();
	afx_msg void OnBnClickedRadioSummarycount();
};
