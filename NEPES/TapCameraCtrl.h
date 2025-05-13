#pragma once
#include "afxwin.h"

#include "Camera/CameraDev.h"
#include "StaticText.h"
#include "ViewRoi.h"

#include "DlgCamRoi.h"

// CTapCameraCtrl dialog

class CTapCameraCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CTapCameraCtrl)

public:
	CTapCameraCtrl(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTapCameraCtrl();


	void UpdateInformation(const INFO_DEFDEV* pstDefDev, const int nProcID = -1);
	void UpdateInformationFromDevice(const INFO_DEFDEV* pstDefDev, const int nProcID, BOOL bLoaded = FALSE);

	void SetMaxScrollHeight(int h);
	void UpdateScrollInfo();

// Dialog Data
	enum { IDD = IDD_TAP_CAMERACTRL };
protected:
	INFO_DEFDEV m_stDefDev;
	int m_nProcID;

	int SCROLLHEIGHT;
	int m_nVPos;

	CStaticText m_ctlStaticRoiInfo;
	CDlgCamRoi m_dlgRoi;

	CStaticText m_ctlStaticDigitalGain;
	CStaticText m_ctlStaticAnalogGain;
	CStaticText m_ctlStaticExposure;
	CStaticText m_ctlFramerate;
	CStaticText m_ctlSymmetry;
	CStaticText m_ctlStaticRoi;
	CStaticText m_ctlStaticTrigger;
	CStaticText m_ctlStrobe;
	CStaticText m_ctlStaticMtu;
	CStaticText m_ctlStaticUserset;

	CSliderCtrl m_ctlSliderGain1;
	CSpinButtonCtrl m_ctlSpinGain1;

	CSliderCtrl m_ctlSliderGain2;
	CSpinButtonCtrl m_ctlSpinGain2;

	CSliderCtrl m_ctlSliderExposure;
	CSpinButtonCtrl m_ctlSpinExposure;

	CSliderCtrl m_ctlSliderFps;
	CSpinButtonCtrl m_ctlSpinFps;

	CComboBox m_ctlTriggerSource;
	CComboBox m_ctlTriggerType;
	CComboBox m_ctlTriggerPolarity;
	CSpinButtonCtrl m_ctlSpinTriggerDelay;

	CComboBox m_ctlStrobeSync;
	CComboBox m_ctlStrobePolarity;
	CSpinButtonCtrl m_ctlSpinStrobeDelay;
	CSpinButtonCtrl m_ctlSpinStrobeWidth;

	CComboBox m_ctlMtu;

	CComboBox m_ctlUserset;
	CComboBox m_ctlStartupUserset;

protected:
	void LimitRange(CEdit* pEdit, int* pnValue, const int nMin, const int nMax);
	void CheckValue(CEdit* pEdit, const int nMin, const int nMax);

	void UpdateValue(const DWORD dwCtrlID, const int nValue);
	int  GetValue(const DWORD dwCtrlID);

	void ScrollValue(const DWORD dwEditID, int nDelta, const int nMin, const int nMax);

	void UpdateRoiValue(const INFO_ROI_PARA* pstParam);
	BOOL GetRoiValue(INFO_ROI_PARA* pstParam);

	//
	void UpdateGain1(const INFO_DEFDEV* pstDefDev);
	void UpdateGain2(const INFO_DEFDEV* pstDefDev);
	void UpdateExposure(const INFO_DEFDEV* pstDefDev, BOOL bUpdate = TRUE);
	void UpdateExposureRange(const int nFps);
	void UpdateFramerate(const INFO_DEFDEV* pstDefDev);
	int UpdateFramerateRange(const int nWidth, const int nHeight);
	void UpdateTrigger(const INFO_DEFDEV* pstDefDev);
	void UpdateStrobe(const INFO_DEFDEV* pstDefDev);
	void UpdateSymmetry(const INFO_DEFDEV* pstDefDev);
	void UpdateRoi(const INFO_DEFDEV* pstDefDev);
	void UpdateUserset(const INFO_DEFDEV* pstDefDev);
	void UpdateMtu(const INFO_DEFDEV* pstDefDev);

	void EnableGain1(BOOL bEnable);
	void EnableGain2(BOOL bEnable);
	void EnableExposure(BOOL bEnable);
	void EnableFramerate(BOOL bEnable);
	void EnableTrigger(BOOL bEnable);
	void EnableStrobe(BOOL bEnable);
	void EnableSymmetry(BOOL bEnable, const INFO_DEFSYMMETRY* pstDefSymmetry);
	void EnableRoi(BOOL bEnable);
	void EnableUserset(BOOL bEnable, const INFO_DEFUSERSET* pstDefUserset);

	//
	void SetGain1(int nVal);
	void SetGain2(int nVal);
	void SetExposure(int nVal);
	void SetFramerate(int nVal);
	void SetStartupUserset(int nVal);
	void SetTrigger(INFO_TRIGGER_PARA stParam);
	void SetStrobe(INFO_STROBE_PARA stParam);
	void SetRoi(INFO_ROI_PARA stParam);
	void SetSymmetry(int nVal);
	void SetDataBit(int nVal);
	void SetColor(const TCHAR* pszTxt);

	void GetGain1(int& nVal);
	void GetGain2(int& nVal);
	void GetExposure(int& nVal);
	void GetFramerate(int& nVal);
	void GetTrigger(INFO_TRIGGER_PARA& stParam);
	void GetStrobe(INFO_STROBE_PARA& stParam);
	void GetRoi(INFO_ROI_PARA& stParam);
	void GetSymmetry(int& nVal);
	void GetDataBit(int& nVal);

	BOOL SendTriggerCommand();
	BOOL SendStrobeCommand();
	BOOL SendRoiCommand();

	void Start();
	void Stop();
	void StopnWaitCamera();

	void CheckDataBitCameraLink(INFO_DEFDATABIT& stDataBit, const TCHAR* pszName);


	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	DECLARE_MESSAGE_MAP()
	afx_msg LRESULT OnNotifyChangeTrackRect(WPARAM wParam, LPARAM lParam);
	
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

	afx_msg void OnEnKillfocusEditCamgain1();
	afx_msg void OnEnKillfocusEditCamgain2();
	afx_msg void OnEnKillfocusEditCamexposure();
	afx_msg void OnEnKillfocusEditCamfps();
	afx_msg void OnEnKillfocusEditTriggerDelay();
	afx_msg void OnEnKillfocusEditStrobeDelay();
	afx_msg void OnEnKillfocusEditStrobeWidth();
	afx_msg void OnEnKillfocusEditRoiX();
	afx_msg void OnEnKillfocusEditRoiY();
	afx_msg void OnEnKillfocusEditRoiWidth();
	afx_msg void OnEnKillfocusEditRoiHeight();
	
	afx_msg void OnDeltaposSpinCamgain1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinCamgain2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinCamexposure(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinCamfps(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinTriggerDelay(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinStrobeDelay(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinStrobeWidth(NMHDR *pNMHDR, LRESULT *pResult);

	afx_msg void OnNMReleasedcaptureSliderCamgain1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSliderCamgain2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSliderCamexposure(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSliderCamfps(NMHDR *pNMHDR, LRESULT *pResult);

	afx_msg void OnCbnSelchangeComboTriggerSource();
	afx_msg void OnCbnSelchangeComboTriggerType();
	afx_msg void OnCbnSelchangeComboTriggerPolarity();
	afx_msg void OnCbnSelchangeComboStrobeSync();
	afx_msg void OnCbnSelchangeComboStrobePolarity();
	afx_msg void OnCbnSelchangeComboUserset();
	afx_msg void OnCbnSelchangeComboMtu();

	afx_msg void OnBnClickedCheckTriggerenable();
	afx_msg void OnBnClickedCheckStrobeenable();
	afx_msg void OnBnClickedBtnTriggerExe();
	afx_msg void OnBnClickedCheckSymmetryX();
	afx_msg void OnBnClickedCheckSymmetryY();
	afx_msg void OnBnClickedBtnRoiQuart();
	afx_msg void OnBnClickedBtnRoiHalf();
	afx_msg void OnBnClickedBtnRoiFull();
	afx_msg void OnBnClickedBtnRoiCenter();
	afx_msg void OnBnClickedBtnRoi();
	afx_msg void OnBnClickedBtnUsersetLoad();
	afx_msg void OnBnClickedBtnUsersetSave();
	afx_msg void OnBnClickedBtnUsersetApply();
	afx_msg void OnBnClickedBtnTimeout();
	afx_msg void OnBnClickedBtnMtuConfig();

};
