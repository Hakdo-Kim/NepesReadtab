#pragma once
#include "afxwin.h"

#include "CustomMessage.h"
#include "CaptureManager.h"
#include "afxcmn.h"


// CDlgConfig dialog

class CDlgConfig : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgConfig)

public:
	CDlgConfig(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgConfig();

	CString m_szFirstLoad;
	CString m_szSecondLoad;
	CString m_szOptionLoad;

	void UpdateEthernetPort();

// Dialog Data
	enum { IDD = IDD_DLG_CONFIG };
protected:
	CComboBox m_ctlComboStrobeControllerType;
	int m_eStrobeControllerType;
	
	// First Camera & Strobe
	CCustomMessage m_ctlTitleFirst;
	CComboBox m_ctlComboFirst;
	
	CCustomMessage m_ctlSerialPortFirst;
	CCustomMessage m_ctlSerialSpeedFirst;
	CComboBox m_ctlComboSerialFirst;
	CComboBox m_ctlComboSpeedFirst;
	CCustomMessage m_ctlStrobeFirst;
	CComboBox m_ctlComboStrobeFirst;
	CCustomMessage m_ctlStrobeBrightFirst;

	// Second Camera & Strobe
	CCustomMessage m_ctlTitleSecond;
	CComboBox m_ctlComboSecond;

	CCustomMessage m_ctlSerialPortSecond;
	CCustomMessage m_ctlSerialSpeedSecond;
	CComboBox m_ctlComboSerialSecond;
	CComboBox m_ctlComboSpeedSecond;
	CCustomMessage m_ctlStrobeSecond;
	CComboBox m_ctlComboStrobeSecond;
	CCustomMessage m_ctlStrobeBrightSecond;

	CComboBox m_ctlSecondCameraRotate;


	// Communicate Result Port
	CCustomMessage m_ctlTitleFirstResult;

	CCustomMessage m_ctlIpFirstRes;
	CCustomMessage m_ctlPortFirstRes;
	CCustomMessage m_ctlProtocolFirstRes;
	CCustomMessage m_ctlTypeFirstRes;

	CIPAddressCtrl m_ctlIpAddrFirstRes;
	CEdit m_ctlEditPortFirstRes;
	CComboBox m_ctlComboProtocolFirstRes;
	CComboBox m_ctlComboTypeFirstRes;
	


	// Scenario
	CCustomMessage m_ctlScenarioTitle;

	//Line type
	CCustomMessage m_ctlLineType;
	CCustomMessage m_ctlLine1;

	const int TIMERID_ETHERNET = 10;
	const int MARGIN = 5;

protected:
	BOOL m_bFirstCamImageReverseX;
	BOOL m_bFirstCamImageReverseY;
	BOOL m_bSecondCamImageReverseX;
	BOOL m_bSecondCamImageReverseY;
	void AdjustLayout();
	void SetCameraLayout(DWORD dwGroupID, DWORD dwTitleID, DWORD dwComboID, DWORD dwCheckID );
	void DrawCameraLayout(CDC* pDC, DWORD dwGroupID, COLORREF rgbBk, DWORD dwIcon, DWORD dwLT, DWORD dwLB, DWORD dwRT, DWORD dwRB);
	void DrawSerialLayout(CDC* pDC, CRect rect, COLORREF rgbBk, DWORD dwLT, DWORD dwLB, DWORD dwRT, DWORD dwRB);
	void DrawLineTypeLayout(CDC* pDC, DWORD dwGroupID, COLORREF rgbBk, DWORD dwIcon, DWORD dwLT, DWORD dwLB, DWORD dwRT, DWORD dwRB);
	void DrawLineTypeLayout2(CDC* pDC, CRect rect, COLORREF rgbBk, DWORD dwLT, DWORD dwLB, DWORD dwRT, DWORD dwRB);

public:
	void UpdateCameraList();
	void UpdateGigECameraList(const TYPE_CAMERAPOS ePos, const int nSelectedIdx);

	void UpdateFreerunCameraFromCamera();
	void UpdateFreerunCameraFromCamera(TYPE_CAMERAPOS ePos, DWORD dwCtrlID);
	BOOL GetTriggerModeFromCamera(TYPE_CAMERAPOS ePos, DWORD& dwTriggerMode, DWORD& dwTriggerSrc);

	void UpdateFreerunCamera(TYPE_CAMERAPOS ePos, DWORD dwCtrlID);

	BOOL IsFreerunCamera();
	BOOL ChangeCameraTriggerMode(DWORD dwPosFlag);

	//
	void UpdateSerialPort();
	BOOL CheckConfigStatus();
	

	int GetEditValue(const DWORD dwCtrlID);
	void SetEditValue(const DWORD dwCtrlID, int nValue);

	void UpdateCtrlCurrentStrobeBrightness(TYPE_CAMERAPOS ePos, TYPE_STROBE eStrobe);
	
	BOOL IsEnableBrightnessValue(TYPE_CAMERAPOS ePos, TYPE_STROBE eStrobe, int nValue);
	int GetCurrentStrobeBrightness(TYPE_CAMERAPOS ePos, TYPE_STROBE eStrobe);


	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	DECLARE_MESSAGE_MAP()
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnPaint();
	afx_msg void OnClose();
	afx_msg void OnBnClickedOk();
	
	afx_msg void OnBnClickedBtnDisconnect();
	afx_msg void OnBnClickedBtnResearch();
	afx_msg void OnBnClickedBtnCameractrl();
	afx_msg void OnBnClickedBtnOption();
	afx_msg void OnBnClickedCheckFirst();
	afx_msg void OnBnClickedCheckSecond();
	afx_msg void OnBnClickedCheckAllcamera();

	afx_msg void OnCbnSelchangeComboFirst();
	afx_msg void OnCbnSelchangeComboSecond();

	afx_msg void OnBnClickedBtnFirstserialopen();
	afx_msg void OnBnClickedBtnFirstserialclose();
	afx_msg void OnBnClickedBtnSecondserialopen();
	afx_msg void OnBnClickedBtnSecondserialclose();
	afx_msg void OnBnClickedBtnFirstresserialopen();
	afx_msg void OnBnClickedBtnFirstresserialclose();

	afx_msg void OnCbnSelchangeComboFirststrobe();
	afx_msg void OnCbnSelchangeComboSecondstrobe();

	afx_msg void OnEnKillfocusEditFirstbrightness();
	afx_msg void OnEnKillfocusEditSecondbrightness();

	afx_msg void OnBnClickedBtnLoadFirst();
	afx_msg void OnBnClickedBtnLoadSecond();
	afx_msg void OnBnClickedBtnLoadOption();

	// config xml load
	void LoadNewFirst();
	void LoadNewSecond();
	void LoadNewOption();
	
	afx_msg void OnCbnSelchangeComboFirstcomport();
	afx_msg void OnCbnSelchangeComboFirstspeed();
	afx_msg void OnCbnSelchangeComboSecondcomport();
	afx_msg void OnCbnSelchangeComboSecondspeed();

	afx_msg void OnCbnSelchangeComboFirstresprotocol();
	afx_msg void OnCbnSelchangeComboFirstrestype();
	
	afx_msg void OnCbnSelchangeComboSecondrotate();

	afx_msg void OnStnClickedStaticFirst();
	afx_msg void OnBnClickedRadioLine1();
	afx_msg void OnBnClickedRadioLine2();

	afx_msg void OnBnClickedChkFirstReversex();
	afx_msg void OnBnClickedChkFirstReversey();

	afx_msg void OnBnClickedChkSecondReversex();
	afx_msg void OnBnClickedChkSecondReversey();

	afx_msg void OnCbnSelchangeComboStrobecontrollertype();
};
