// DlgConfig.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "DlgConfig.h"
#include "afxdialogex.h"

#include "DlgCameraControl.h"
#include "DlgMessage.h"
//#include "DlgOption.h"
#include "DlgPasswd.h"


#include "Util/Util.h"

#include "UserInterfaceDef.h"
#include "stringres.h"

// CDlgConfig dialog

IMPLEMENT_DYNAMIC(CDlgConfig, CDialogEx)

CDlgConfig::CDlgConfig(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgConfig::IDD, pParent)
{
	m_bFirstCamImageReverseX = FALSE;
	m_bFirstCamImageReverseY = FALSE;
	m_bSecondCamImageReverseX = FALSE;
	m_bSecondCamImageReverseY = FALSE;
}

CDlgConfig::~CDlgConfig()
{
}

void CDlgConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_FIRST,				m_ctlComboFirst);
	DDX_Control(pDX, IDC_COMBO_SECOND,				m_ctlComboSecond);
	DDX_Control(pDX, IDC_STATIC_TITLEFIRST,			m_ctlTitleFirst);
	DDX_Control(pDX, IDC_STATIC_FIRSTCOMPORT,		m_ctlSerialPortFirst);
	DDX_Control(pDX, IDC_STATIC_FIRSTSPEED,			m_ctlSerialSpeedFirst);
	DDX_Control(pDX, IDC_COMBO_FIRSTCOMPORT,		m_ctlComboSerialFirst);
	DDX_Control(pDX, IDC_COMBO_FIRSTSPEED,			m_ctlComboSpeedFirst);
	DDX_Control(pDX, IDC_STATIC_FIRSTSTROBE,		m_ctlStrobeFirst);
	DDX_Control(pDX, IDC_STATIC_TITLESECOND,		m_ctlTitleSecond);
	DDX_Control(pDX, IDC_STATIC_SECONDCOMPORT,		m_ctlSerialPortSecond);
	DDX_Control(pDX, IDC_STATIC_SECONDSPEED,		m_ctlSerialSpeedSecond);
	DDX_Control(pDX, IDC_COMBO_SECONDCOMPORT,		m_ctlComboSerialSecond);
	DDX_Control(pDX, IDC_COMBO_SECONDSPEED,			m_ctlComboSpeedSecond);
	DDX_Control(pDX, IDC_STATIC_SECONDSTROBE,		m_ctlStrobeSecond);
	DDX_Control(pDX, IDC_STATIC_FIRSTRESTITLE,		m_ctlTitleFirstResult);
	DDX_Control(pDX, IDC_STATIC_FIRSTRESIP,			m_ctlIpFirstRes);
	DDX_Control(pDX, IDC_STATIC_FIRSTRESPORT,		m_ctlPortFirstRes);
	DDX_Control(pDX, IDC_STATIC_FIRSTRESTYPE,		m_ctlTypeFirstRes);
	DDX_Control(pDX, IDC_STATIC_TITLESCENARIO,		m_ctlScenarioTitle);
	DDX_Control(pDX, IDC_COMBO_FIRSTSTROBE,			m_ctlComboStrobeFirst);
	DDX_Control(pDX, IDC_COMBO_SECONDSTROBE,		m_ctlComboStrobeSecond);

	DDX_Control(pDX, IDC_COMBO_FIRSTRESTYPE,		m_ctlComboTypeFirstRes);
	DDX_Control(pDX, IDC_STATIC_FIRSTRESPROTOCOL,	m_ctlProtocolFirstRes);
	DDX_Control(pDX, IDC_COMBO_FIRSTRESPROTOCOL,	m_ctlComboProtocolFirstRes);
	DDX_Control(pDX, IDC_FIRSTRES_IPADDR,			m_ctlIpAddrFirstRes);
	DDX_Control(pDX, IDC_EDIT_FIRSTRES_PORT,		m_ctlEditPortFirstRes);
	DDX_Control(pDX, IDC_STATIC_FIRSTBRIGHTNESS,	m_ctlStrobeBrightFirst);
	DDX_Control(pDX, IDC_STATIC_SECONDBRIGHTNESS,	m_ctlStrobeBrightSecond);
	DDX_Control(pDX, IDC_COMBO_SECONDROTATE,		m_ctlSecondCameraRotate);
	DDX_Control(pDX, IDC_STATIC_LINE_NAME,			m_ctlLine1);
	DDX_Control(pDX, IDC_STATIC_LINE_CONF,			m_ctlLineType);
	DDX_Check(pDX,	 IDC_CHK_FREVERSEX,				m_bFirstCamImageReverseX);
	DDX_Check(pDX,	 IDC_CHK_FREVERSEY,				m_bFirstCamImageReverseY);
	DDX_Check(pDX,	 IDC_CHK_SREVERSEX,				m_bSecondCamImageReverseX);
	DDX_Check(pDX,	 IDC_CHK_SREVERSEY,				m_bSecondCamImageReverseY);

	//DDX_Control(pDX, IDC_COMBO_STROBETYPE, m_ctlComboStrobeControllerType);
	DDX_Control(pDX, IDC_COMBO_STROBECONTROLLERTYPE, m_ctlComboStrobeControllerType);
}

BOOL CDlgConfig::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (IDOK == wParam)
	{
		if (IsFreerunCamera())
		{
			MessageBox(STR_MSG_CAPTUREMODE);
			return TRUE;
		}
		else
		{
			//return TRUE;
		}
	}
	return CDialogEx::OnCommand(wParam, lParam);
}

BOOL CDlgConfig::PreTranslateMessage(MSG* pMsg)
{
	if (WM_KEYDOWN == pMsg->message)
	{
		if (VK_ESCAPE == pMsg->wParam)
		{
			return TRUE;
			if (IsFreerunCamera())
			{
				MessageBox(STR_MSG_CAPTUREMODE);
				return TRUE;
			}
		}
		else if (VK_RETURN == pMsg->wParam)
		{
			const HWND hWnd = GetFocus()->m_hWnd;
			if (hWnd == GetDlgItem(IDC_EDIT_FIRSTBRIGHTNESS)->m_hWnd)
				OnEnKillfocusEditFirstbrightness();
			else if (hWnd == GetDlgItem(IDC_EDIT_SECONDBRIGHTNESS)->m_hWnd)
				OnEnKillfocusEditSecondbrightness();
			
			return TRUE;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

BOOL CDlgConfig::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// First Camera & Strobe
	m_ctlTitleFirst.SetTextFont(_T("MS Shell Dlg"), 16, FW_BOLD);
	m_ctlSerialPortFirst.SetTextFont(_T("MS Shell Dlg"), 14, FW_BOLD);
	m_ctlSerialSpeedFirst.SetTextFont(_T("MS Shell Dlg"), 14, FW_BOLD);
	m_ctlStrobeFirst.SetTextFont(_T("MS Shell Dlg"), 14, FW_BOLD);
	m_ctlStrobeBrightFirst.SetTextFont(_T("MS Shell Dlg"), 14, FW_BOLD);

	m_ctlTitleFirst.SetMessage(STR_MSG_FIRSTCAMERA);
	m_ctlSerialPortFirst.SetMessage(STR_MSG_SERIALPORT);
	m_ctlSerialSpeedFirst.SetMessage(STR_MSG_SERIALSPEED);
	m_ctlStrobeFirst.SetMessage(STR_MSG_STROBETEST);
	m_ctlStrobeBrightFirst.SetMessage(STR_MSG_STROBEBRIGHTNESS);
	

	// Second Camera & Strobe
	m_ctlTitleSecond.SetTextFont(_T("MS Shell Dlg"), 16, FW_BOLD);
	m_ctlSerialPortSecond.SetTextFont(_T("MS Shell Dlg"), 14, FW_BOLD);
	m_ctlSerialSpeedSecond.SetTextFont(_T("MS Shell Dlg"), 14, FW_BOLD);
	m_ctlStrobeSecond.SetTextFont(_T("MS Shell Dlg"), 14, FW_BOLD);
	m_ctlStrobeBrightSecond.SetTextFont(_T("MS Shell Dlg"), 14, FW_BOLD);

	m_ctlTitleSecond.SetMessage(STR_MSG_SECONDCAMERA);
	m_ctlSerialPortSecond.SetMessage(STR_MSG_SERIALPORT);
	m_ctlSerialSpeedSecond.SetMessage(STR_MSG_SERIALSPEED);
	m_ctlStrobeSecond.SetMessage(STR_MSG_STROBETEST);
	m_ctlStrobeBrightSecond.SetMessage(STR_MSG_STROBEBRIGHTNESS);


	// 
	m_ctlTitleFirstResult.SetTextFont(_T("MS Shell Dlg"), 16, FW_BOLD);
	m_ctlIpFirstRes.SetTextFont(_T("MS Shell Dlg"), 14, FW_BOLD);
	m_ctlPortFirstRes.SetTextFont(_T("MS Shell Dlg"), 14, FW_BOLD);
	m_ctlProtocolFirstRes.SetTextFont(_T("MS Shell Dlg"), 14, FW_BOLD);
	m_ctlTypeFirstRes.SetTextFont(_T("MS Shell Dlg"), 14, FW_BOLD);

	m_ctlTitleFirstResult.SetMessage(STR_MSG_COMMUNICATEPORT);
	m_ctlIpFirstRes.SetMessage(STR_MSG_RESULTIP);
	m_ctlPortFirstRes.SetMessage(STR_MSG_RESULTPORT);
	m_ctlProtocolFirstRes.SetMessage(STR_MSG_RESULTPROTOCOL);
	m_ctlTypeFirstRes.SetMessage(STR_MSG_RESULTTYPE);


	// Scenario
	m_ctlScenarioTitle.SetTextFont(_T("MS Shell Dlg"), 16, FW_BOLD);
	m_ctlScenarioTitle.SetMessage(STR_MSG_SCENARIO);

	GetDlgItem(IDC_STATIC_SCE_FIRST)->SetWindowText(STR_MSG_FIRSTCAMERA);
	GetDlgItem(IDC_STATIC_SCE_SECOND)->SetWindowText(STR_MSG_SECONDCAMERA);


	//Line type
	m_ctlLineType.SetTextFont(_T("MS Shell Dlg"), 16, FW_BOLD);
	m_ctlLineType.SetMessage(STR_MSG_LINE_CONF);
	m_ctlLine1.SetTextFont(_T("MS Shell Dlg"), 14, FW_BOLD);
	m_ctlLine1.SetMessage(STR_MSG_LINE_TYPE);
	GetDlgItem(IDC_RADIO_LINE1)->SetWindowText(STR_MAINVIEW_LINE_1);
	GetDlgItem(IDC_RADIO_LINE2)->SetWindowText(STR_MAINVIEW_LINE_2);
	//
	const int nPortLen = CUtil::SearchSerialUart(NULL, 0);

	INFO_SERIALPORT* pstSerialPort = new INFO_SERIALPORT[nPortLen];
	memset(pstSerialPort, 0x00, sizeof(INFO_SERIALPORT)*nPortLen);
	CUtil::SearchSerialUart(pstSerialPort, nPortLen);

	for (int i = 0; i < nPortLen; i++)
	{
		m_ctlComboSerialFirst.AddString(pstSerialPort[i].m_szPortName);
		m_ctlComboSerialSecond.AddString(pstSerialPort[i].m_szPortName);
	}
	delete[] pstSerialPort;

	m_ctlComboSerialFirst.SetCurSel(0);
	m_ctlComboSerialSecond.SetCurSel(0);
	
	TCHAR* pszSpeed[] = {
		_T("9600"),
		_T("14400"),
		_T("19200"),
		_T("38400"),
		_T("56000"),
		_T("57600"),
		_T("115200"),
		_T("128000"),
		_T("256000"),
		NULL
	};

	int idx = 0;
	while (pszSpeed[idx])
	{
		m_ctlComboSpeedFirst.AddString(pszSpeed[idx]);
		m_ctlComboSpeedSecond.AddString(pszSpeed[idx]);
		idx++;
	}
	m_ctlComboSpeedFirst.SelectString(0, _T("115200"));
	m_ctlComboSpeedSecond.SelectString(0, _T("115200"));
	
	TCHAR* pszStrobeType[] = {
		_T("A TYPE"),
		_T("B TYPE"),
		NULL
	};

	idx = 0;
	while (pszStrobeType[idx])
	{
		m_ctlComboStrobeControllerType.AddString(pszStrobeType[idx]);
		idx++;
	}
	m_eStrobeControllerType = m_ctlComboStrobeControllerType.SelectString(0, _T("A TYPE"));
	
	m_ctlComboProtocolFirstRes.AddString(STR_PROTOCOL_TCP);
	m_ctlComboProtocolFirstRes.AddString(STR_PROTOCOL_UDP);

	m_ctlComboTypeFirstRes.AddString(STR_TYPE_CLIENT);
	m_ctlComboTypeFirstRes.AddString(STR_TYPE_SERVER);

	m_ctlComboProtocolFirstRes.SetCurSel(0);
	m_ctlComboTypeFirstRes.SetCurSel(0);

	{
		TCHAR szPortFirst[128] = { 0, };
		TCHAR szSpeedFirst[128] = { 0, };
		CUtil::GetRegString(REG_ROOT_PATH, REG_VALUE_SERIALPORT_FIRST, szPortFirst, 128);
		CUtil::GetRegString(REG_ROOT_PATH, REG_VALUE_SERIALSPEED_FIRST, szSpeedFirst, 128);

		TCHAR szPortSecond[128] = { 0, };
		TCHAR szSpeedSecond[128] = { 0, };
		CUtil::GetRegString(REG_ROOT_PATH, REG_VALUE_SERIALPORT_SECOND, szPortSecond, 128);
		CUtil::GetRegString(REG_ROOT_PATH, REG_VALUE_SERIALSPEED_SECOND, szSpeedSecond, 128);

		TCHAR szStrobeControllerType[128] = { 0, };
		CUtil::GetRegString(REG_ROOT_PATH, REG_VALUE_STROBECONTROLLERTYPE, szStrobeControllerType, 128);

		TCHAR szEthIpMachine[128] = { 0, };
		TCHAR szEthPortMachine[128] = { 0, };
		TCHAR szEthProtocolMachine[128] = { 0, };
		TCHAR szEthTypeMachine[128] = { 0, };
		CUtil::GetRegString(REG_ROOT_PATH, REG_VALUE_ETHERNETIP_MACHINE, szEthIpMachine, 128);

#ifdef USE_PLC_MXCOMPONENT
		TCHAR szPLCIpMachine[128] = { 0, };
		CUtil::GetRegString(REG_ROOT_PATH, RED_VALUE_PLC_TCPHOSTADDRESS, szPLCIpMachine, 128);
		int nPLCStationNumber = 1;
		DWORD dwValue = 0;
		CUtil::GetRegDword(REG_ROOT_PATH, RED_VALUE_PLC_STATIONNUMER, dwValue);
		nPLCStationNumber = (int)dwValue;
		int eLineNumber = 0;
		CUtil::GetRegDword(REG_ROOT_PATH, RED_VALUE_LINE_LINENUMER, dwValue);
		eLineNumber = (int)dwValue;

		dwValue = 0;
		CUtil::GetRegDword(REG_ROOT_PATH, REG_VALUE_FIRSTCAMERA_REVERSEX, dwValue);
		m_bFirstCamImageReverseX = (BOOL)dwValue;
		dwValue = 0;
		CUtil::GetRegDword(REG_ROOT_PATH, REG_VALUE_FIRSTCAMERA_REVERSEY, dwValue);
		m_bFirstCamImageReverseY = (BOOL)dwValue;

		dwValue = 0;
		CUtil::GetRegDword(REG_ROOT_PATH, REG_VALUE_SECONDCAMERA_REVERSEX, dwValue);
		m_bSecondCamImageReverseX = (BOOL)dwValue;
		dwValue = 0;
		CUtil::GetRegDword(REG_ROOT_PATH, REG_VALUE_SECONDCAMERA_REVERSEY, dwValue);
		m_bSecondCamImageReverseY = (BOOL)dwValue;
#else
		CUtil::GetRegString(REG_ROOT_PATH, REG_VALUE_ETHERNETPORT_MACHINE, szEthPortMachine, 128);
#endif

		CUtil::GetRegString(REG_ROOT_PATH, REG_VALUE_ETHERNETPROTOCOL_MACHINE, szEthProtocolMachine, 128);
		CUtil::GetRegString(REG_ROOT_PATH, REG_VALUE_ETHERNETTYPE_MACHINE, szEthTypeMachine, 128);


#ifdef USE_PLC_MXCOMPONENT
		if (eLineNumber == 0)
		{
			((CButton*)GetDlgItem(IDC_RADIO_LINE1))->SetCheck(BST_CHECKED);
			((CButton*)GetDlgItem(IDC_RADIO_LINE2))->SetCheck(BST_UNCHECKED);
		}
		else
		{
			((CButton*)GetDlgItem(IDC_RADIO_LINE1))->SetCheck(BST_UNCHECKED);
			((CButton*)GetDlgItem(IDC_RADIO_LINE2))->SetCheck(BST_CHECKED);
		}
       
		if (m_bFirstCamImageReverseX)
			((CButton*)GetDlgItem(IDC_CHK_FREVERSEX))->SetCheck(BST_CHECKED);

		if (m_bFirstCamImageReverseY)
			((CButton*)GetDlgItem(IDC_CHK_FREVERSEY))->SetCheck(BST_CHECKED);

		if (m_bSecondCamImageReverseX)
			((CButton*)GetDlgItem(IDC_CHK_SREVERSEX))->SetCheck(BST_CHECKED);

		if (m_bSecondCamImageReverseY)
			((CButton*)GetDlgItem(IDC_CHK_SREVERSEY))->SetCheck(BST_CHECKED);
#endif
	
#		ifdef DEF_ETHERNET_CLIENT
		CUtil::StringCopy(szEthTypeMachine, STR_TYPE_CLIENT);
#       endif
#		ifdef DEF_ETHERNET_SERVER
		CUtil::StringCopy(szEthTypeMachine, STR_TYPE_SERVER);
#		endif

		int nCur = 0;

		CString szValue;
		int nCount = 0;
		nCount = m_ctlComboSerialFirst.GetCount();
		for (int i = 0; i < nCount; i++)
		{
			m_ctlComboSerialFirst.GetLBText(i, szValue);
			if (szValue == szPortFirst)
			{
				nCur = i;
				break;
			}
		}
		m_ctlComboSerialFirst.SetCurSel(nCur);
		m_ctlComboSpeedFirst.SelectString(0, szSpeedFirst);

		nCount = m_ctlComboSerialSecond.GetCount();
		for (int i = 0; i < nCount; i++)
		{
			m_ctlComboSerialSecond.GetLBText(i, szValue);
			if (szValue == szPortSecond)
			{
				nCur = i;
				break;
			}
		}
		m_ctlComboSerialSecond.SetCurSel(nCur);
		m_ctlComboSpeedSecond.SelectString(0, szSpeedSecond);

		m_ctlComboStrobeControllerType.SelectString(0, szStrobeControllerType);
		m_eStrobeControllerType = m_ctlComboStrobeControllerType.GetCurSel();

#ifdef USE_PLC_MXCOMPONENT
		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

		// Result Port
		if (1 > CUtil::StringLength(szPLCIpMachine))
		{
			m_ctlIpAddrFirstRes.SetWindowText(PLC_DEFAULT_HOSTADDRESS);
			pCaptureManager->SetPLCHostAddress(PLC_DEFAULT_HOSTADDRESS);
		}
		else
		{
			m_ctlIpAddrFirstRes.SetWindowText(szPLCIpMachine);
			CString strPLCHostAddress = _T("");
			strPLCHostAddress.Format(_T("%s"), szPLCIpMachine);
			pCaptureManager->SetPLCHostAddress(strPLCHostAddress);
		}

		{
			CString strPLCStationNumber = _T("");
			strPLCStationNumber.Format(_T("%d"), nPLCStationNumber);
			m_ctlEditPortFirstRes.SetWindowText(strPLCStationNumber);
			pCaptureManager->SetPLCStationNumber(nPLCStationNumber);
		}
		{
			pCaptureManager->SetSelectLineInfo(eLineNumber);
		}
#else
		// Result Port
		if (1 > CUtil::StringLength(szEthIpMachine))
			m_ctlIpAddrFirstRes.SetWindowText(_T("127.0.0.1"));
		else
			m_ctlIpAddrFirstRes.SetWindowText(szEthIpMachine);

		if (1 > CUtil::StringLength(szEthPortMachine))
			m_ctlEditPortFirstRes.SetWindowText(_T("5000"));
		else
			m_ctlEditPortFirstRes.SetWindowText(szEthPortMachine);
#endif

		m_ctlComboProtocolFirstRes.SelectString(0, szEthProtocolMachine);
		m_ctlComboTypeFirstRes.SelectString(0, szEthTypeMachine);
	}



	m_ctlComboStrobeFirst.AddString(STR_STROBE_OFF);
	m_ctlComboStrobeFirst.AddString(STR_STROBE_COAXIAL);
	m_ctlComboStrobeFirst.AddString(STR_STROBE_RING);
	m_ctlComboStrobeFirst.AddString(STR_STROBE_BAR);

	m_ctlComboStrobeSecond.AddString(STR_STROBE_OFF);
	m_ctlComboStrobeSecond.AddString(STR_STROBE_COAXIAL);
	m_ctlComboStrobeSecond.AddString(STR_STROBE_RING);
	m_ctlComboStrobeSecond.AddString(STR_STROBE_BAR);
	
	m_ctlComboStrobeFirst.SetCurSel(0);
	m_ctlComboStrobeSecond.SetCurSel(0);


	{
		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

		const INFO_SCENARIO* pstScenario = pCaptureManager->GetScenario();
		GetDlgItem(IDC_EDIT_FIRST)->SetWindowText(pstScenario->m_szFirstFilePath);
		// 2022-05-06 퍼스트 검사 XML 불러오기
		if ('\0' != pstScenario->m_szFirstFilePath[0]) LoadNewFirst();

		GetDlgItem(IDC_EDIT_SECOND)->SetWindowText(pstScenario->m_szSecondFilePath);
		// 2022-05-06 세컨드 검사 XML 불러오기
		if ('\0' != pstScenario->m_szSecondFilePath[0]) LoadNewSecond();

		// Option
		const TCHAR* pszOptionFilePath = pCaptureManager->GetOptionFilePath();
		GetDlgItem(IDC_EDIT_OPTION)->SetWindowText(pszOptionFilePath);
		// 2022-05-06 옵션 XML 불러오기
		if ('\0' != pszOptionFilePath[0]) LoadNewOption();
	}

	AdjustLayout();

	// Check Camera Enable...
	UpdateCameraList();
	UpdateSerialPort();


	{
		// Second Camera Rotate Option
		m_ctlSecondCameraRotate.ResetContent();
		m_ctlSecondCameraRotate.AddString(_T("0 (None)"));
		m_ctlSecondCameraRotate.AddString(_T("90 (CW)"));
		m_ctlSecondCameraRotate.AddString(_T("-90 (CCW)"));

		DWORD dwValue = 0;
		CUtil::GetRegDword(REG_ROOT_PATH, REG_VALUE_SECOND_ROTATE, dwValue);

		if (90 == dwValue)
			m_ctlSecondCameraRotate.SetCurSel(1);
		else if (270 == dwValue)
			m_ctlSecondCameraRotate.SetCurSel(2);
		else //if (0 == dwValue)
			m_ctlSecondCameraRotate.SetCurSel(0);
	}


	// Check Ethernet Adaptor Enable
#ifdef DEF_ETHERNET_SERVER
#	ifdef DEF_TIMER_CHECK_ADAPTOR
	SetTimer(TIMERID_ETHERNET, MSEC_CHECK_ADAPTOR, NULL);
#	endif
#endif

	return TRUE;  // return TRUE  unless you set the focus to a control
}

BEGIN_MESSAGE_MAP(CDlgConfig, CDialogEx)
	ON_WM_TIMER()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDOK, &CDlgConfig::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BTN_CAMERACTRL, &CDlgConfig::OnBnClickedBtnCameractrl)
	ON_BN_CLICKED(IDC_BTN_RESEARCH, &CDlgConfig::OnBnClickedBtnResearch)
	ON_BN_CLICKED(IDC_BTN_DISCONNECT, &CDlgConfig::OnBnClickedBtnDisconnect)
	ON_CBN_SELCHANGE(IDC_COMBO_FIRST, &CDlgConfig::OnCbnSelchangeComboFirst)
	ON_CBN_SELCHANGE(IDC_COMBO_SECOND, &CDlgConfig::OnCbnSelchangeComboSecond)
	ON_BN_CLICKED(IDC_BTN_OPTION, &CDlgConfig::OnBnClickedBtnOption)
	ON_BN_CLICKED(IDC_CHECK_FIRST, &CDlgConfig::OnBnClickedCheckFirst)
	ON_BN_CLICKED(IDC_CHECK_SECOND, &CDlgConfig::OnBnClickedCheckSecond)
	ON_BN_CLICKED(IDC_CHECK_ALLCAMERA, &CDlgConfig::OnBnClickedCheckAllcamera)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BTN_FIRSTSERIALOPEN, &CDlgConfig::OnBnClickedBtnFirstserialopen)
	ON_BN_CLICKED(IDC_BTN_FIRSTSERIALCLOSE, &CDlgConfig::OnBnClickedBtnFirstserialclose)
	ON_BN_CLICKED(IDC_BTN_SECONDSERIALOPEN, &CDlgConfig::OnBnClickedBtnSecondserialopen)
	ON_BN_CLICKED(IDC_BTN_SECONDSERIALCLOSE, &CDlgConfig::OnBnClickedBtnSecondserialclose)
	ON_BN_CLICKED(IDC_BTN_FIRSTRESOPEN, &CDlgConfig::OnBnClickedBtnFirstresserialopen)
	ON_BN_CLICKED(IDC_BTN_FIRSTRESCLOSE, &CDlgConfig::OnBnClickedBtnFirstresserialclose)
	ON_CBN_SELCHANGE(IDC_COMBO_FIRSTSTROBE, &CDlgConfig::OnCbnSelchangeComboFirststrobe)
	ON_CBN_SELCHANGE(IDC_COMBO_SECONDSTROBE, &CDlgConfig::OnCbnSelchangeComboSecondstrobe)
	ON_BN_CLICKED(IDC_BTN_LOAD_FIRST, &CDlgConfig::OnBnClickedBtnLoadFirst)
	ON_BN_CLICKED(IDC_BTN_LOAD_SECOND, &CDlgConfig::OnBnClickedBtnLoadSecond)
	ON_BN_CLICKED(IDC_BTN_LOAD_OPTION, &CDlgConfig::OnBnClickedBtnLoadOption)
	ON_CBN_SELCHANGE(IDC_COMBO_FIRSTCOMPORT, &CDlgConfig::OnCbnSelchangeComboFirstcomport)
	ON_CBN_SELCHANGE(IDC_COMBO_FIRSTSPEED, &CDlgConfig::OnCbnSelchangeComboFirstspeed)
	ON_CBN_SELCHANGE(IDC_COMBO_SECONDCOMPORT, &CDlgConfig::OnCbnSelchangeComboSecondcomport)
	ON_CBN_SELCHANGE(IDC_COMBO_SECONDSPEED, &CDlgConfig::OnCbnSelchangeComboSecondspeed)

	ON_CBN_SELCHANGE(IDC_COMBO_FIRSTRESTYPE, &CDlgConfig::OnCbnSelchangeComboFirstrestype)
	ON_CBN_SELCHANGE(IDC_COMBO_FIRSTRESPROTOCOL, &CDlgConfig::OnCbnSelchangeComboFirstresprotocol)
	ON_EN_KILLFOCUS(IDC_EDIT_FIRSTBRIGHTNESS, &CDlgConfig::OnEnKillfocusEditFirstbrightness)
	ON_EN_KILLFOCUS(IDC_EDIT_SECONDBRIGHTNESS, &CDlgConfig::OnEnKillfocusEditSecondbrightness)
	ON_CBN_SELCHANGE(IDC_COMBO_SECONDROTATE, &CDlgConfig::OnCbnSelchangeComboSecondrotate)
	ON_BN_CLICKED(IDC_RADIO_LINE1, &CDlgConfig::OnBnClickedRadioLine1)
	ON_BN_CLICKED(IDC_RADIO_LINE2, &CDlgConfig::OnBnClickedRadioLine2)
	ON_BN_CLICKED(IDC_CHK_FREVERSEX, &CDlgConfig::OnBnClickedChkFirstReversex)
	ON_BN_CLICKED(IDC_CHK_FREVERSEY, &CDlgConfig::OnBnClickedChkFirstReversey)
	ON_BN_CLICKED(IDC_CHK_SREVERSEX, &CDlgConfig::OnBnClickedChkSecondReversex)
	ON_BN_CLICKED(IDC_CHK_SREVERSEY, &CDlgConfig::OnBnClickedChkSecondReversey)
	//ON_CBN_SELCHANGE(IDC_COMBO_STROBETYPE, &CDlgConfig::OnCbnSelchangeComboStrobetype)
	ON_CBN_SELCHANGE(IDC_COMBO_STROBECONTROLLERTYPE, &CDlgConfig::OnCbnSelchangeComboStrobecontrollertype)
END_MESSAGE_MAP()


// CDlgConfig message handlers
void CDlgConfig::OnTimer(UINT_PTR nIDEvent)
{
#ifdef DEF_TIMER_CHECK_ADAPTOR
	if (TIMERID_ETHERNET == nIDEvent)
	{
		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
		CEthernet* pEthernet = pCaptureManager->GetCommunicatePort();
		CEthernetServer* pEthernetServer = dynamic_cast<CEthernetServer*>(pEthernet);
		if (pEthernetServer && pEthernetServer->IsOpen())
		{
			BOOL bFound = FALSE;

			const TCHAR* pszIpAddr = pEthernetServer->GetIpAddress();
			CUtil::PrintDebugString(_T("Check Adaptor (ip:%s) \r\n"), pszIpAddr);

			{
				ULONG buflen = sizeof(IP_ADAPTER_INFO);
				IP_ADAPTER_INFO *pAdapterInfo = (IP_ADAPTER_INFO *)new BYTE[buflen];
				if (ERROR_BUFFER_OVERFLOW == ::GetAdaptersInfo(pAdapterInfo, &buflen))
				{
					delete[] pAdapterInfo;
					pAdapterInfo = (IP_ADAPTER_INFO *)new BYTE[buflen];
				}

				if (NO_ERROR == ::GetAdaptersInfo(pAdapterInfo, &buflen))
				{
					for (IP_ADAPTER_INFO *pAdapter = pAdapterInfo; pAdapter; pAdapter = pAdapter->Next) 
					{
						if (CUtil::StringCompare((TCHAR*)pszIpAddr, PLC_DEFAULT_HOSTADDRESS) ||
							CUtil::StringCompare(pAdapter->IpAddressList.IpAddress.String, (TCHAR*)pszIpAddr))
						{
							bFound = TRUE;
							break;
						}
					}
				}

				if (pAdapterInfo)
				{
					delete[] pAdapterInfo;
				}
			}
			
			if (FALSE == bFound)
			{
				// Close Ethernet
				OnBnClickedBtnFirstresserialclose();
			}
		}
	}
#endif
}

void CDlgConfig::OnPaint()
{
	//CDialogEx::OnPaint();

	CPaintDC dc(this);

#if 0
	DrawCameraLayout(&dc, IDC_STATIC_FIRST, RGB(200, 200, 200), IDB_BMP_CAMERAFIRST, IDB_STATIC_GUARD_LEFTTOP, IDB_STATIC_GUARD_LEFTBOTTOM, IDB_STATIC_GUARD_RIGHTTOP, IDB_STATIC_GUARD_RIGHTBOTTOM);
	DrawCameraLayout(&dc, IDC_STATIC_SECOND, RGB(200, 200, 200), IDB_BMP_CAMERASECOND, IDB_STATIC_GUARD_LEFTTOP, IDB_STATIC_GUARD_LEFTBOTTOM, IDB_STATIC_GUARD_RIGHTTOP, IDB_STATIC_GUARD_RIGHTBOTTOM);
#else
	DrawCameraLayout(&dc, IDC_STATIC_FIRST, RGB(200, 200, 200), IDB_BMP_CAMERAFIRST, 0, 0, 0, 0);
	DrawCameraLayout(&dc, IDC_STATIC_SECOND, RGB(200, 200, 200), IDB_BMP_CAMERASECOND, 0, 0, 0, 0);
	{
		CRect rtFirst;
		CRect rtSecond;
		GetDlgItem(IDC_STATIC_FIRST)->GetWindowRect(&rtFirst);
		ScreenToClient(&rtFirst);
		GetDlgItem(IDC_STATIC_SECOND)->GetWindowRect(&rtSecond);
		ScreenToClient(&rtSecond);

		CRect rect;
		rect.left = rtFirst.left;
		rect.top = rtFirst.top;
		rect.right = rtSecond.right;
		rect.bottom = rtSecond.bottom + 200;
		DrawSerialLayout(&dc, rect, RGB(200, 200, 200), IDB_STATIC_GUARD_LEFTTOP, IDB_STATIC_GUARD_LEFTBOTTOM, IDB_STATIC_GUARD_RIGHTTOP, IDB_STATIC_GUARD_RIGHTBOTTOM);
	}
	DrawCameraLayout(&dc, IDC_STATIC_FIRSTRES, RGB(200, 200, 200), NULL, IDB_STATIC_GUARD_LEFTTOP, IDB_STATIC_GUARD_LEFTBOTTOM, IDB_STATIC_GUARD_RIGHTTOP, IDB_STATIC_GUARD_RIGHTBOTTOM);
	{
		CRect rect;
		GetDlgItem(IDC_STATIC_LINE_TYPE)->GetWindowRect(rect);
		ScreenToClient(rect);
		DrawLineTypeLayout2(&dc, rect, RGB(200, 200, 200), IDB_STATIC_GUARD_LEFTTOP, IDB_STATIC_GUARD_LEFTBOTTOM, IDB_STATIC_GUARD_RIGHTTOP, IDB_STATIC_GUARD_RIGHTBOTTOM);
	}
#endif
		
	CRect rect;
	GetDlgItem(IDC_STATIC_SCENARIO)->GetWindowRect(rect);
	ScreenToClient(rect);
	DrawSerialLayout(&dc, rect, RGB(200, 200, 200), IDB_STATIC_GUARD_LEFTTOP, IDB_STATIC_GUARD_LEFTBOTTOM, IDB_STATIC_GUARD_RIGHTTOP, IDB_STATIC_GUARD_RIGHTBOTTOM);
}

void CDlgConfig::OnClose()
{

#ifndef DEF_FREERUN_TEST
	if (FALSE == CheckConfigStatus())
		return;
#endif

	CDialogEx::OnOK();
}

void CDlgConfig::OnBnClickedOk()
{
	if (FALSE == CheckConfigStatus())
		return;
	
	CDialogEx::OnOK();
}

void CDlgConfig::OnBnClickedBtnDisconnect()
{
	CDlgMessage dlgMessage;
	dlgMessage.SetLoadType(TYPE_LOAD_DISCONNECTCAMERA);
	dlgMessage.DoModal();

	UpdateCameraList();

	this->GetParent()->PostMessage(WM_NOTIFY_CLEAR_DISPLAY, TYPE_CAMERAPOS_FIRST, 0);
	this->GetParent()->PostMessage(WM_NOTIFY_CLEAR_DISPLAY, TYPE_CAMERAPOS_SECOND, 0);

	{
		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
		INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();
		// Print Log
		{
			if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
			{
				stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Disconnect camera");
			}
		}
	}
}

void CDlgConfig::OnBnClickedBtnResearch()
{
	CDlgMessage dlgMessage;
	dlgMessage.SetLoadType(TYPE_LOAD_CONNECTCAMERA);
	dlgMessage.DoModal();

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	{

		INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();
		// Print Log
		{
			if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
			{
				stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Connect camera");
			}
		}
	}

	UpdateCameraList();
	UpdateFreerunCameraFromCamera();
#ifdef USE_BASLER_CAMERA
	pCaptureManager->SetFirstCemaraReverseX(m_bFirstCamImageReverseX);
	pCaptureManager->SetFirstCemaraReverseY(m_bFirstCamImageReverseY);
	pCaptureManager->SetSecondCemaraReverseX(m_bSecondCamImageReverseX);
	pCaptureManager->SetSecondCemaraReverseY(m_bSecondCamImageReverseY);
#endif
}


void CDlgConfig::OnBnClickedBtnCameractrl()
{
	CDlgPasswd dlgPasswd;
	if (IDOK == dlgPasswd.DoModal())
	{
		CDlgCameraControl dlgControl;
		dlgControl.DoModal();

		if (dlgControl.m_bResearchCamera)
		{
			CDlgMessage dlgMessage;
			dlgMessage.SetLoadType(TYPE_LOAD_RESEARCHCAMERA);
			dlgMessage.DoModal();

			UpdateCameraList();
			UpdateFreerunCameraFromCamera();

		}
		else
		{
			BOOL bChangeTrigger = FALSE;
			DWORD dwPosFlag = 0;
			DWORD dwOptFlag = 0;

			DWORD dwTriggerMode = 0;
			DWORD dwTriggerSrc = 0;

			BOOL bResult = FALSE;

			// LEFT
			bResult = GetTriggerModeFromCamera(TYPE_CAMERAPOS_FIRST, dwTriggerMode, dwTriggerSrc);
			if (bResult)
			{
#ifdef DEF_FREERUN_CAPTURE
				if (TRIGGER_OFF != dwTriggerMode)
#else
				if (TRIGGER_ON == dwTriggerMode && TRIGGER_SRC_SW != dwTriggerSrc)
#endif
				{
					bChangeTrigger = TRUE;

					dwPosFlag |= FLAG_FIRST;
					dwOptFlag |= FLAG_OPT_FIRST;
				}
			}
			bResult = GetTriggerModeFromCamera(TYPE_CAMERAPOS_SECOND, dwTriggerMode, dwTriggerSrc);
			if (bResult)
			{
#ifdef DEF_FREERUN_CAPTURE
				if (TRIGGER_OFF != dwTriggerMode)
#else
				if (TRIGGER_ON == dwTriggerMode && TRIGGER_SRC_SW != dwTriggerSrc)
#endif
				{
					bChangeTrigger = TRUE;

					dwPosFlag |= FLAG_SECOND;
					dwOptFlag |= FLAG_OPT_SECOND;
				}
			}

			if (bChangeTrigger)
			{
				MessageBox(STR_MSG_TRIGGERMODE);

				CDlgMessage dlgMessage;
				dlgMessage.SetLoadType(TYPE_LOAD_TRIGGERMODE, dwPosFlag, dwOptFlag);
				dlgMessage.DoModal();
			}
			UpdateFreerunCameraFromCamera();			
		}
	}
}

void CDlgConfig::OnBnClickedBtnOption()
{
	//CDlgOption dlgOption;
	//dlgOption.DoModal();

	this->GetParent()->SendMessage(WM_NOTIFY_UPDATE_LOGPATH);

}

void CDlgConfig::OnBnClickedCheckFirst()
{
	UpdateFreerunCamera(TYPE_CAMERAPOS_FIRST, IDC_CHECK_FIRST);

	// Change Camera Trigger Mode...
	ChangeCameraTriggerMode(FLAG_FIRST);
}

void CDlgConfig::OnBnClickedCheckSecond()
{
	UpdateFreerunCamera(TYPE_CAMERAPOS_SECOND, IDC_CHECK_SECOND);

	// Change Camera Trigger Mode...
	ChangeCameraTriggerMode(FLAG_SECOND);
}

void CDlgConfig::OnBnClickedCheckAllcamera()
{
	// Freerun Camera: ALL Camera
	const int nCheckAllCamera = ((CButton*)GetDlgItem(IDC_CHECK_ALLCAMERA))->GetCheck();
	if (BST_CHECKED == nCheckAllCamera)
	{
		if (GetDlgItem(IDC_CHECK_FIRST)->IsWindowEnabled())
			((CButton*)GetDlgItem(IDC_CHECK_FIRST))->SetCheck(BST_CHECKED);
		if (GetDlgItem(IDC_CHECK_SECOND)->IsWindowEnabled())
			((CButton*)GetDlgItem(IDC_CHECK_SECOND))->SetCheck(BST_CHECKED);

		GetDlgItem(IDOK)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_FIRST)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_SECOND)->EnableWindow(FALSE);
	}
	else
	{
		((CButton*)GetDlgItem(IDC_CHECK_FIRST))->SetCheck(BST_UNCHECKED);
		((CButton*)GetDlgItem(IDC_CHECK_SECOND))->SetCheck(BST_UNCHECKED);

		GetDlgItem(IDOK)->EnableWindow(TRUE);
		GetDlgItem(IDC_COMBO_FIRST)->EnableWindow(TRUE);
		GetDlgItem(IDC_COMBO_SECOND)->EnableWindow(TRUE);
	}

	// Change Camera Trigger Mode...
	ChangeCameraTriggerMode(FLAG_FIRST | FLAG_SECOND);
}

void CDlgConfig::OnCbnSelchangeComboFirst()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	const int nSelectedIdx = m_ctlComboFirst.GetCurSel();
	if (0 == nSelectedIdx)
	{
		pCaptureManager->SetCapturePosition(TYPE_CAMERAPOS_FIRST, TYPE_NETWORK_NONE, -1);
		GetDlgItem(IDC_CHECK_FIRST)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHK_FREVERSEX)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHK_FREVERSEY)->EnableWindow(FALSE);

		this->GetParent()->PostMessage(WM_NOTIFY_CLEAR_DISPLAY, TYPE_CAMERAPOS_FIRST, 0);
	}
	else
	{
#ifdef USE_BASLER_CAMERA
		pCaptureManager->SetCapturePosition(TYPE_CAMERAPOS_FIRST, TYPE_NETWORK_BASLER, nSelectedIdx - 1);
#endif

#ifdef USE_GIGE_CAMERA
		pCaptureManager->SetCapturePosition(TYPE_CAMERAPOS_FIRST, TYPE_NETWORK_GIGE, nSelectedIdx - 1);
#endif

		GetDlgItem(IDC_CHECK_FIRST)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHK_FREVERSEX)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHK_FREVERSEY)->EnableWindow(TRUE);
	}

	{
		CString szDevice;
		GetDlgItem(IDC_COMBO_FIRST)->GetWindowText(szDevice);

		CUtil::SetRegString(REG_ROOT_PATH, REG_VALUE_CAMERA_FIRST, (LPTSTR)(LPCTSTR)szDevice);
	}

	UpdateGigECameraList(TYPE_CAMERAPOS_FIRST, nSelectedIdx);


	//
	UpdateFreerunCameraFromCamera(TYPE_CAMERAPOS_FIRST, IDC_CHECK_FIRST);
}

void CDlgConfig::OnCbnSelchangeComboSecond()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	const int nSelectedIdx = m_ctlComboSecond.GetCurSel();
	if (0 == nSelectedIdx)
	{
		pCaptureManager->SetCapturePosition(TYPE_CAMERAPOS_SECOND, TYPE_NETWORK_NONE, -1);
		GetDlgItem(IDC_CHECK_SECOND)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHK_SREVERSEX)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHK_SREVERSEY)->EnableWindow(FALSE);

		this->GetParent()->PostMessage(WM_NOTIFY_CLEAR_DISPLAY, TYPE_CAMERAPOS_SECOND, 0);
	}
	else
	{
#ifdef USE_BASLER_CAMERA
		pCaptureManager->SetCapturePosition(TYPE_CAMERAPOS_SECOND, TYPE_NETWORK_BASLER, nSelectedIdx - 1);
#endif

#ifdef USE_GIGE_CAMERA
		pCaptureManager->SetCapturePosition(TYPE_CAMERAPOS_SECOND, TYPE_NETWORK_GIGE, nSelectedIdx - 1);
#endif
		GetDlgItem(IDC_CHECK_SECOND)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHK_SREVERSEX)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHK_SREVERSEY)->EnableWindow(TRUE);
	}

	{
		CString szDevice;
		GetDlgItem(IDC_COMBO_SECOND)->GetWindowText(szDevice);
		CUtil::SetRegString(REG_ROOT_PATH, REG_VALUE_CAMERA_SECOND, (LPTSTR)(LPCTSTR)szDevice);
	}

	UpdateGigECameraList(TYPE_CAMERAPOS_SECOND, nSelectedIdx);

	//
	UpdateFreerunCameraFromCamera(TYPE_CAMERAPOS_SECOND, IDC_CHECK_SECOND);
}



void CDlgConfig::OnBnClickedBtnFirstserialopen()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CSerialCtrl* pSerialPort = pCaptureManager->GetStrobeControlPort(TYPE_CAMERAPOS_FIRST);
	INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();
	pCaptureManager->m_eStrobeControllerType = m_eStrobeControllerType;

	CString szSerial;
	CString szSpeed;
	m_ctlComboSerialFirst.GetWindowText(szSerial);
	m_ctlComboSpeedFirst.GetWindowText(szSpeed);

	DWORD dwSpeed = CUtil::StringToInt((LPTSTR)(LPCTSTR)szSpeed, szSpeed.GetLength());
	BOOL bResult = pSerialPort->Open((LPCTSTR)szSerial, dwSpeed);
	if (bResult)
	{
		BOOL bReadBrightness = pCaptureManager->ReadStrobeBrightness(pSerialPort);
		// Print Log
		{
			if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
			{
				stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Open serial (strobe: %s, %s)", (LPCTSTR)szSerial, (LPCTSTR)szSpeed);
				if (bReadBrightness)
				{
					const INFO_STROBE* pstStrobe = pCaptureManager->GetCurrentStrobeInfo();

					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Read strobe brightness.");
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "   First Coaxial (%d)", pstStrobe->m_stFirstStrobe.m_nBrightnessCoxial);
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "   First Ring (%d)", pstStrobe->m_stFirstStrobe.m_nBrightnessRing);
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "   First Bar (%d)", pstStrobe->m_stFirstStrobe.m_nBrightnessBar);

					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "   Second Coaxial (%d)", pstStrobe->m_stSecondStrobe.m_nBrightnessCoxial);
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "   Second Ring (%d)", pstStrobe->m_stSecondStrobe.m_nBrightnessRing);
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "   Second Bar (%d)", pstStrobe->m_stSecondStrobe.m_nBrightnessBar);
				}
				else
				{
					stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Fail to read strobe brightness.");
				}
			}
		}
		if (!bReadBrightness)
		{
			AfxMessageBox(STR_MSG_EREAD_BRIGHTNESS);
		}
	}
	else
	{
		AfxMessageBox(STR_MSG_ERROR_SERIAL);
		// Print Log
		{
			if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
			{
				stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Fail to open serial. (strobe)");
			}
		}
	}

	UpdateSerialPort();

	{
		int nCur = m_ctlComboStrobeFirst.GetCurSel();
		UpdateCtrlCurrentStrobeBrightness(TYPE_CAMERAPOS_FIRST, (TYPE_STROBE)(nCur + 1));

		nCur = m_ctlComboStrobeSecond.GetCurSel();
		UpdateCtrlCurrentStrobeBrightness(TYPE_CAMERAPOS_SECOND, (TYPE_STROBE)(nCur + 1));
	}

}

void CDlgConfig::OnBnClickedBtnFirstserialclose()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CSerialCtrl* pSerialPort = pCaptureManager->GetStrobeControlPort(TYPE_CAMERAPOS_FIRST);
	INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();

	pSerialPort->Close();
	UpdateSerialPort();

	// Print Log
	{
		if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
		{
			stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Close serial (strobe)");
		}
	}
}

void CDlgConfig::OnBnClickedBtnSecondserialopen()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CSerialCtrl* pSerialPort = pCaptureManager->GetStrobeControlPort(TYPE_CAMERAPOS_SECOND);

	CString szSerial;
	CString szSpeed;
	m_ctlComboSerialSecond.GetWindowText(szSerial);
	m_ctlComboSpeedSecond.GetWindowText(szSpeed);

	DWORD dwSpeed = CUtil::StringToInt((LPTSTR)(LPCTSTR)szSpeed, szSpeed.GetLength());
	BOOL bResult = pSerialPort->Open((LPCTSTR)szSerial, dwSpeed);
	if (FALSE == bResult)
	{
		AfxMessageBox(STR_MSG_ERROR_SERIAL);
	}

	UpdateSerialPort();
}

void CDlgConfig::OnBnClickedBtnSecondserialclose()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	CSerialCtrl* pSerialPort = pCaptureManager->GetStrobeControlPort(TYPE_CAMERAPOS_SECOND);
	pSerialPort->Close();

	UpdateSerialPort();
}

void CDlgConfig::OnBnClickedBtnFirstresserialopen()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

#ifdef USE_PLC_MXCOMPONENT
	int nPLCProtocolType = PLC_DEFAULT_PROTOCOLTYPE;
	int nPLCControlType = PLC_DEFAULT_CONTROLTYPE;
	int nPLCStationNum = PLC_DEFAULT_STATIONNUMBER;
	CString strHostAddress = PLC_DEFAULT_HOSTADDRESS;
	int nTCPPortNum = 5000;
	int eLineNumber = 0;

	////
	TCHAR szPort[MAX_NAME_LEN] = { 0, };
	m_ctlEditPortFirstRes.GetWindowText(szPort, MAX_NAME_LEN);
	nPLCStationNum = atoi(szPort);
	pCaptureManager->SetPLCStationNumber(nPLCStationNum);

	if (((CButton*)GetDlgItem(IDC_RADIO_LINE1))->GetCheck())
		eLineNumber = TYPE_LINE_1;
	else
		eLineNumber = TYPE_LINE_2;
	pCaptureManager->SetSelectLineInfo(eLineNumber);

	///
	TCHAR szIpAddr[MAX_NAME_LEN] = { 0, };
	m_ctlIpAddrFirstRes.GetWindowText(szIpAddr, MAX_NAME_LEN);
	strHostAddress.Format(_T("%s"), szIpAddr);
	pCaptureManager->SetPLCHostAddress(strHostAddress);

	///
	pCaptureManager->LPMxComponentConfigSetting(nPLCProtocolType, nPLCControlType, nPLCStationNum, strHostAddress, nTCPPortNum);
	pCaptureManager->LPMxComOpenCommunication();

	// Registry
	{
		CUtil::SetRegDword(REG_ROOT_PATH, RED_VALUE_LINE_LINENUMER, (DWORD)eLineNumber);
		CUtil::SetRegDword(REG_ROOT_PATH, REG_VALUE_PLC_PROTOCOLTYPE, (DWORD)nPLCProtocolType);
		CUtil::SetRegDword(REG_ROOT_PATH, RED_VALUE_PLC_CONTROLTYPE, (DWORD)nPLCControlType);
		CUtil::SetRegDword(REG_ROOT_PATH, RED_VALUE_PLC_STATIONNUMER, (DWORD)nPLCStationNum);
		CUtil::SetRegString(REG_ROOT_PATH, RED_VALUE_PLC_TCPHOSTADDRESS, strHostAddress.GetBuffer());
		CUtil::SetRegDword(REG_ROOT_PATH, RED_VALUE_PLC_TCPPORTUMER, (DWORD)nTCPPortNum);
		strHostAddress.ReleaseBuffer();
	}

	INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();
		// Print Log
		{
			if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
			{
				stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Open PLC Com (Station Num : %d, Protocol Type : %d)", nPLCStationNum, nPLCProtocolType);
			}
		}
#else
	FuncNotifyEthernetListener pFunc = NULL;
	void* pArg = NULL;
	pCaptureManager->GetCommunicateNotifyHandler(&pFunc, &pArg);

	///
	TCHAR szIpAddr[MAX_NAME_LEN] = { 0, };
	TCHAR szPort[MAX_NAME_LEN] = { 0, };
	TCHAR szProtocol[MAX_NAME_LEN] = { 0, };
	TCHAR szType[MAX_NAME_LEN] = { 0, };

	m_ctlIpAddrFirstRes.GetWindowText(szIpAddr, MAX_NAME_LEN);
	m_ctlEditPortFirstRes.GetWindowText(szPort, MAX_NAME_LEN);
	m_ctlComboProtocolFirstRes.GetWindowText(szProtocol, MAX_NAME_LEN);
	m_ctlComboTypeFirstRes.GetWindowText(szType, MAX_NAME_LEN);


	// Registry
	{
		CUtil::SetRegString(REG_ROOT_PATH, REG_VALUE_ETHERNETIP_MACHINE, szIpAddr);
		CUtil::SetRegString(REG_ROOT_PATH, REG_VALUE_ETHERNETPORT_MACHINE, szPort);
	}

	BOOL bResult = FALSE;
	CEthernet* pEthernet = pCaptureManager->CreateCommunicatePort(szType);
	if (pEthernet)
	{
		bResult = pEthernet->Open(szIpAddr, szPort, szProtocol, pFunc, pArg);
	}

	INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();
	if (bResult)
	{
		// Print Log
		{
			if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
			{
				stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Open ethernet (%s,%s,%s,%s)", szIpAddr, szPort, szProtocol, szType);
			}
		}
	}
	else
	{
		AfxMessageBox(STR_MSG_ERROR_ETHERNET);
		// Print Log
		{
			if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
			{
				stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Fail to open ethernet");
			}
		}
	}
#endif

	//UpdateSerialPort();
}

void CDlgConfig::OnBnClickedBtnFirstresserialclose()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
#ifdef USE_PLC_MXCOMPONENT
	pCaptureManager->LPMXComCloseCommunication();
#else
	pCaptureManager->DeleteCommunicatePort();
	UpdateSerialPort();
#endif

	INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();
	// Print Log
	{
		if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
		{
#ifdef USE_PLC_MXCOMPONENT
			stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "PLC Close Com");
#else
			stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Close ethernet");
#endif
		}
	}

}

void CDlgConfig::OnCbnSelchangeComboFirststrobe()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	
	CSerialCtrl* pSerialPort = pCaptureManager->GetStrobeControlPort(TYPE_CAMERAPOS_FIRST);
	if (NULL == pSerialPort || FALSE == pSerialPort->IsOpen())
	{
		AfxMessageBox(STR_MSG_ERROR_SERIAL);
		return;
	}

	const int nCur = m_ctlComboStrobeFirst.GetCurSel();
	const TYPE_STROBE eStrobe = (TYPE_STROBE)(nCur + 1);

	BOOL bResult = pCaptureManager->ControlStrobeOnOff(pSerialPort, TYPE_CAMERAPOS_FIRST, eStrobe);
	if (FALSE == bResult)
	{
		AfxMessageBox(STR_MSG_ERROR_STROBE);
	}

	// Current Brightness
	UpdateCtrlCurrentStrobeBrightness(TYPE_CAMERAPOS_FIRST, eStrobe);

}


void CDlgConfig::OnCbnSelchangeComboSecondstrobe()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	
	CSerialCtrl* pSerialPort = pCaptureManager->GetStrobeControlPort(TYPE_CAMERAPOS_SECOND);
	if (NULL == pSerialPort || FALSE == pSerialPort->IsOpen())
	{
		AfxMessageBox(STR_MSG_ERROR_SERIAL);
		return;
	}

	const int nCur = m_ctlComboStrobeSecond.GetCurSel();
	const TYPE_STROBE eStrobe = (TYPE_STROBE)(nCur + 1);

	BOOL bResult = pCaptureManager->ControlStrobeOnOff(pSerialPort, TYPE_CAMERAPOS_SECOND, eStrobe);
	if (FALSE == bResult)
	{
		AfxMessageBox(STR_MSG_ERROR_STROBE);
	}

	// Currnet Brightness
	UpdateCtrlCurrentStrobeBrightness(TYPE_CAMERAPOS_SECOND, eStrobe);

}

void CDlgConfig::OnEnKillfocusEditFirstbrightness()
{
	static BOOL bSkipMsg = FALSE;
	if (bSkipMsg)
		return;
	bSkipMsg = TRUE;

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_STROBE* pstStrobe = pCaptureManager->GetCurrentStrobeInfo();

	TYPE_CAMERAPOS ePos = TYPE_CAMERAPOS_FIRST;

	const int nCur = m_ctlComboStrobeFirst.GetCurSel();
	const TYPE_STROBE eStrobe = (TYPE_STROBE)(nCur + 1);

	const int nCurValue = GetCurrentStrobeBrightness(ePos, eStrobe);
	const int nBrightness = GetEditValue(IDC_EDIT_FIRSTBRIGHTNESS);
	if (nCurValue == nBrightness)
	{
		bSkipMsg = FALSE;
		return;
	}

	const BOOL bEnable = IsEnableBrightnessValue(ePos, eStrobe, nBrightness);
	if (FALSE == bEnable)
	{
		AfxMessageBox(STR_MSG_EVALUE_BRIGHTNESS);
		UpdateCtrlCurrentStrobeBrightness(ePos, eStrobe);
		bSkipMsg = FALSE;
		return;
	}
	
	CSerialCtrl* pSerialCtrl = pCaptureManager->GetStrobeControlPort(ePos);

	BOOL bResult = pCaptureManager->ControlStrobeBrightness(pSerialCtrl, ePos, eStrobe, nBrightness);
	if (bResult)
	{
		// do nothing
	}
	else
	{
		AfxMessageBox(STR_MSG_EWRITE_BRIGHTNESS);
	}
	bSkipMsg = FALSE;
}

void CDlgConfig::OnEnKillfocusEditSecondbrightness()
{
	static BOOL bSkipMsg = FALSE;
	if (bSkipMsg)
		return;
	bSkipMsg = TRUE;

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_STROBE* pstStrobe = pCaptureManager->GetCurrentStrobeInfo();

	TYPE_CAMERAPOS ePos = TYPE_CAMERAPOS_SECOND;

	const int nCur = m_ctlComboStrobeSecond.GetCurSel();
	const TYPE_STROBE eStrobe = (TYPE_STROBE)(nCur + 1);

	const int nCurValue = GetCurrentStrobeBrightness(ePos, eStrobe);
	const int nBrightness = GetEditValue(IDC_EDIT_SECONDBRIGHTNESS);
	if (nCurValue == nBrightness)
	{
		bSkipMsg = FALSE;
		return;
	}

	const BOOL bEnable = IsEnableBrightnessValue(ePos, eStrobe, nBrightness);
	if (FALSE == bEnable)
	{
		AfxMessageBox(STR_MSG_EVALUE_BRIGHTNESS);
		UpdateCtrlCurrentStrobeBrightness(ePos, eStrobe);
		bSkipMsg = FALSE;
		return;
	}

	CSerialCtrl* pSerialCtrl = pCaptureManager->GetStrobeControlPort(ePos);
	BOOL bResult = pCaptureManager->ControlStrobeBrightness(pSerialCtrl, ePos, eStrobe, nBrightness);
	if (bResult)
	{
		// do nothing
	}
	else
	{
		AfxMessageBox(STR_MSG_EWRITE_BRIGHTNESS);
	}
	bSkipMsg = FALSE;
}



void CDlgConfig::UpdateCtrlCurrentStrobeBrightness(TYPE_CAMERAPOS ePos, TYPE_STROBE eStrobe)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_STROBE* pstStrobe = pCaptureManager->GetCurrentStrobeInfo();

	if (TYPE_CAMERAPOS_FIRST == ePos)
	{
		if (TYPE_STROBE_COXIAL == eStrobe || TYPE_STROBE_RING == eStrobe || TYPE_STROBE_BAR == eStrobe)
		{
			GetDlgItem(IDC_EDIT_FIRSTBRIGHTNESS)->EnableWindow(TRUE);
			if (TYPE_STROBE_COXIAL == eStrobe)
				SetEditValue(IDC_EDIT_FIRSTBRIGHTNESS, pstStrobe->m_stFirstStrobe.m_nBrightnessCoxial);
			else if (TYPE_STROBE_RING == eStrobe)
				SetEditValue(IDC_EDIT_FIRSTBRIGHTNESS, pstStrobe->m_stFirstStrobe.m_nBrightnessRing);
			else if (TYPE_STROBE_BAR == eStrobe)
				SetEditValue(IDC_EDIT_FIRSTBRIGHTNESS, pstStrobe->m_stFirstStrobe.m_nBrightnessBar);
		}
		else
		{
			GetDlgItem(IDC_EDIT_FIRSTBRIGHTNESS)->EnableWindow(FALSE);
			GetDlgItem(IDC_EDIT_FIRSTBRIGHTNESS)->SetWindowText(_T(""));
		}
	}
	else if (TYPE_CAMERAPOS_SECOND == ePos)
	{
		if (TYPE_STROBE_COXIAL == eStrobe || TYPE_STROBE_RING == eStrobe || TYPE_STROBE_BAR == eStrobe)
		{
			GetDlgItem(IDC_EDIT_SECONDBRIGHTNESS)->EnableWindow(TRUE);

			if (TYPE_STROBE_COXIAL == eStrobe)
				SetEditValue(IDC_EDIT_SECONDBRIGHTNESS, pstStrobe->m_stSecondStrobe.m_nBrightnessCoxial);
			else if (TYPE_STROBE_RING == eStrobe)
				SetEditValue(IDC_EDIT_SECONDBRIGHTNESS, pstStrobe->m_stSecondStrobe.m_nBrightnessRing);
			else if (TYPE_STROBE_BAR == eStrobe)
				SetEditValue(IDC_EDIT_SECONDBRIGHTNESS, pstStrobe->m_stSecondStrobe.m_nBrightnessBar);
		}
		else
		{
			GetDlgItem(IDC_EDIT_SECONDBRIGHTNESS)->EnableWindow(FALSE);
			GetDlgItem(IDC_EDIT_SECONDBRIGHTNESS)->SetWindowText(_T(""));
		}
	}
}

BOOL CDlgConfig::IsEnableBrightnessValue(TYPE_CAMERAPOS ePos, TYPE_STROBE eStrobe, int nValue)
{
	BOOL bEnable = FALSE;
	if (TYPE_STROBE_COXIAL == eStrobe)
	{
		if (STROBE_MAX_BRIGHT_COAX >= nValue && STROBE_MIN_BRIGHT_COAX <= nValue)
			bEnable = TRUE;
	}
	else if (TYPE_STROBE_RING == eStrobe)
	{
		if (STROBE_MAX_BRIGHT_RING >= nValue && STROBE_MIN_BRIGHT_RING <= nValue)
			bEnable = TRUE;
	}
	else if (TYPE_STROBE_BAR == eStrobe)
	{
		if (STROBE_MAX_BRIGHT_BAR >= nValue && STROBE_MIN_BRIGHT_BAR <= nValue)
			bEnable = TRUE;
	}
	
	return bEnable;
}

int CDlgConfig::GetCurrentStrobeBrightness(TYPE_CAMERAPOS ePos, TYPE_STROBE eStrobe)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_STROBE* pstStrobe = pCaptureManager->GetCurrentStrobeInfo();

	int nValue = -1;

	if (TYPE_CAMERAPOS_FIRST == ePos)
	{
		if (TYPE_STROBE_COXIAL == eStrobe)
			nValue = pstStrobe->m_stFirstStrobe.m_nBrightnessCoxial;
		else if (TYPE_STROBE_RING == eStrobe)
			nValue = pstStrobe->m_stFirstStrobe.m_nBrightnessRing;
		else if (TYPE_STROBE_BAR == eStrobe)
			nValue = pstStrobe->m_stFirstStrobe.m_nBrightnessBar;
	}
	else if (TYPE_CAMERAPOS_SECOND == ePos)
	{
		if (TYPE_STROBE_COXIAL == eStrobe)
			nValue = pstStrobe->m_stSecondStrobe.m_nBrightnessCoxial;
		else if (TYPE_STROBE_RING == eStrobe)
			nValue = pstStrobe->m_stSecondStrobe.m_nBrightnessRing;
		else if (TYPE_STROBE_BAR == eStrobe)
			nValue = pstStrobe->m_stSecondStrobe.m_nBrightnessBar;
	}

	return nValue;
}


int CDlgConfig::GetEditValue(const DWORD dwCtrlID)
{
	CString szValue;
	GetDlgItem(dwCtrlID)->GetWindowText(szValue);

	int nValue = CUtil::StringToInt((LPTSTR)(LPCTSTR)szValue, szValue.GetLength());
	return nValue;
}

void CDlgConfig::SetEditValue(const DWORD dwCtrlID, int nValue)
{
	CString szValue;
	szValue.Format(_T("%d"), nValue);
	GetDlgItem(dwCtrlID)->SetWindowText(szValue);
}

void CDlgConfig::AdjustLayout()
{
	if (NULL == m_ctlSecondCameraRotate.m_hWnd)
		return;


	SetCameraLayout(IDC_STATIC_FIRST, IDC_STATIC_TITLEFIRST, IDC_COMBO_FIRST, IDC_CHECK_FIRST);
	SetCameraLayout(IDC_STATIC_SECOND, IDC_STATIC_TITLESECOND, IDC_COMBO_SECOND, IDC_CHECK_SECOND);

	{
		//CRect rtCheck;
		//GetDlgItem(IDC_CHECK_SECOND)->GetWindowRect(rtCheck);
		//ScreenToClient(rtCheck);
		//GetDlgItem(IDC_CHECK_SECOND)->MoveWindow(rtCheck.left, rtCheck.top, rtCheck.Width() - 100, rtCheck.Height());

		//CRect rtCombo = rtCheck;
		//rtCombo.left += 100;

		//m_ctlSecondCameraRotate.MoveWindow(rtCombo);
	}

	//
	CRect rtFirst;
	GetDlgItem(IDC_STATIC_FIRST)->GetWindowRect(&rtFirst);
	ScreenToClient(&rtFirst);

	CRect rtMove;
	GetDlgItem(IDC_CHECK_ALLCAMERA)->GetWindowRect(&rtMove);
		
	const int w = rtMove.Width();
	const int h = rtMove.Height();
		
	rtMove.left = rtFirst.left + MARGIN;
	rtMove.top = rtFirst.bottom + MARGIN * 4;
	rtMove.right = rtMove.left + w;
	rtMove.bottom = rtMove.top + h;

	GetDlgItem(IDC_CHECK_ALLCAMERA)->MoveWindow(&rtMove);		


	
	//
	CRect rtGourp;
	GetDlgItem(IDC_STATIC_FIRSTRES)->GetWindowRect(rtGourp);
	this->ScreenToClient(rtGourp);
		
	CRect rtTitle;
	m_ctlTitleFirstResult.GetWindowRect(rtTitle);
	this->ScreenToClient(rtTitle);
	int cy = rtTitle.Height();

	rtTitle.top = rtGourp.top + 10;
	rtTitle.bottom = rtTitle.top + MARGIN * 6;
	m_ctlTitleFirstResult.MoveWindow(rtTitle);


	int nGap = 85;

	CRect rtLine;
	GetDlgItem(IDC_STATIC_LINE_TYPE)->GetWindowRect(rtLine);
	this->ScreenToClient(rtLine);

	CRect rtTitleLine;
	m_ctlLineType.GetWindowRect(rtTitleLine);
	this->ScreenToClient(rtTitleLine);
	int c = rtTitleLine.Height();

	rtTitleLine.top = rtLine.top;
	rtTitleLine.bottom = rtTitleLine.top + MARGIN * 6;
	m_ctlLineType.MoveWindow(rtTitleLine);

	CRect rtLine2;
	m_ctlLine1.GetWindowRect(rtLine2);
	ScreenToClient(rtLine2);
	rtLine2.top -= nGap;
	rtLine2.bottom -= nGap;
	m_ctlLine1.MoveWindow(rtLine2);

	CRect rtClient;
	m_ctlIpFirstRes.GetWindowRect(rtClient);
	ScreenToClient(rtClient);
	rtClient.top -= nGap;
	rtClient.bottom -= nGap;
	m_ctlIpFirstRes.MoveWindow(rtClient);

	m_ctlPortFirstRes.GetWindowRect(rtClient);
	ScreenToClient(rtClient);
	rtClient.top -= nGap;
	rtClient.bottom -= nGap;
	m_ctlPortFirstRes.MoveWindow(rtClient);

	m_ctlProtocolFirstRes.GetWindowRect(rtClient);
	ScreenToClient(rtClient);
	rtClient.top -= nGap;
	rtClient.bottom -= nGap;
	m_ctlProtocolFirstRes.MoveWindow(rtClient);

	m_ctlTypeFirstRes.GetWindowRect(rtClient);
	ScreenToClient(rtClient);
	rtClient.top -= nGap;
	rtClient.bottom -= nGap;
	m_ctlTypeFirstRes.MoveWindow(rtClient);

	m_ctlIpAddrFirstRes.GetWindowRect(rtClient);
	ScreenToClient(rtClient);
	rtClient.top -= nGap;
	rtClient.bottom -= nGap;
	m_ctlIpAddrFirstRes.MoveWindow(rtClient);

	m_ctlEditPortFirstRes.GetWindowRect(rtClient);
	ScreenToClient(rtClient);
	rtClient.top -= nGap;
	rtClient.bottom -= nGap;
	m_ctlEditPortFirstRes.MoveWindow(rtClient);

	m_ctlComboProtocolFirstRes.GetWindowRect(rtClient);
	ScreenToClient(rtClient);
	rtClient.top -= nGap;
	rtClient.bottom -= nGap;
	m_ctlComboProtocolFirstRes.MoveWindow(rtClient);

	m_ctlComboTypeFirstRes.GetWindowRect(rtClient);
	ScreenToClient(rtClient);
	rtClient.top -= nGap;
	rtClient.bottom -= nGap;
	m_ctlComboTypeFirstRes.MoveWindow(rtClient);


	GetDlgItem(IDC_BTN_FIRSTRESOPEN)->GetWindowRect(rtClient);
	ScreenToClient(rtClient);
	rtClient.top -= nGap;
	rtClient.bottom -= nGap;
	GetDlgItem(IDC_BTN_FIRSTRESOPEN)->MoveWindow(rtClient);

	GetDlgItem(IDC_BTN_FIRSTRESCLOSE)->GetWindowRect(rtClient);
	ScreenToClient(rtClient);
	rtClient.top -= nGap;
	rtClient.bottom -= nGap;
	GetDlgItem(IDC_BTN_FIRSTRESCLOSE)->MoveWindow(rtClient);
	

	// Scenario
	{
		CRect rtSce;
		GetDlgItem(IDC_STATIC_SCENARIO)->GetWindowRect(rtSce);
		ScreenToClient(rtSce);

		rtSce.left = rtFirst.left;
		rtSce.right = rtGourp.right;
		GetDlgItem(IDC_STATIC_SCENARIO)->MoveWindow(rtSce);


		RECT rtTemp;
		rtTemp.left = rtSce.left + MARGIN * 2;
		rtTemp.top = rtSce.top + MARGIN * 2;
		rtTemp.right = rtSce.right - MARGIN * 2;
		rtTemp.bottom = rtTemp.top + MARGIN * 5;

		m_ctlScenarioTitle.MoveWindow(&rtTemp);

		CRect posTitle;
		CRect posBtn;
		GetDlgItem(IDC_STATIC_SCE_FIRST)->GetWindowRect(posTitle);
		GetDlgItem(IDC_BTN_LOAD_FIRST)->GetWindowRect(posBtn);

		rtTemp.top = rtTemp.bottom + MARGIN * 2;
		rtTemp.bottom = rtTemp.top + posTitle.Height();

		rtTemp.left = rtSce.left + MARGIN * 2;
		rtTemp.right = rtTemp.left + posTitle.Width();
		GetDlgItem(IDC_STATIC_SCE_FIRST)->MoveWindow(&rtTemp);

		rtTemp.left = rtTemp.right + MARGIN * 2;
		rtTemp.right = rtSce.right - MARGIN * 4 - posBtn.Width();
		GetDlgItem(IDC_EDIT_FIRST)->MoveWindow(&rtTemp);

		rtTemp.left = rtTemp.right + MARGIN * 2;
		rtTemp.right = rtTemp.left + posBtn.Width();
		GetDlgItem(IDC_BTN_LOAD_FIRST)->MoveWindow(&rtTemp);



		rtTemp.top = rtTemp.bottom + MARGIN * 2;
		rtTemp.bottom = rtTemp.top + posTitle.Height();

		rtTemp.left = rtSce.left + MARGIN * 2;
		rtTemp.right = rtTemp.left + posTitle.Width();
		GetDlgItem(IDC_STATIC_SCE_SECOND)->MoveWindow(&rtTemp);

		rtTemp.left = rtTemp.right + MARGIN * 2;
		rtTemp.right = rtSce.right - MARGIN * 4 - posBtn.Width();
		GetDlgItem(IDC_EDIT_SECOND)->MoveWindow(&rtTemp);

		rtTemp.left = rtTemp.right + MARGIN * 2;
		rtTemp.right = rtTemp.left + posBtn.Width();
		GetDlgItem(IDC_BTN_LOAD_SECOND)->MoveWindow(&rtTemp);



		rtTemp.top = rtTemp.bottom + MARGIN * 2;
		rtTemp.bottom = rtTemp.top + posTitle.Height();

		rtTemp.left = rtSce.left + MARGIN * 2;
		rtTemp.right = rtTemp.left + posTitle.Width();
		GetDlgItem(IDC_STATIC_SCE_OPTION)->MoveWindow(&rtTemp);

		rtTemp.left = rtTemp.right + MARGIN * 2;
		rtTemp.right = rtSce.right - MARGIN * 4 - posBtn.Width();
		GetDlgItem(IDC_EDIT_OPTION)->MoveWindow(&rtTemp);

		rtTemp.left = rtTemp.right + MARGIN * 2;
		rtTemp.right = rtTemp.left + posBtn.Width();
		GetDlgItem(IDC_BTN_LOAD_OPTION)->MoveWindow(&rtTemp);
	}


	/*//
	{
		RECT rect;
		GetDlgItem(IDC_STATIC_SECONDCOMPORT)->GetWindowRect(&rect);
		ScreenToClient(&rect);

		int nTop = rect.top;


		RECT rtBtnOpen;
		GetDlgItem(IDC_BTN_SECONDSERIALOPEN)->GetWindowRect(&rtBtnOpen);
		ScreenToClient(&rtBtnOpen);

		RECT rtBtnClose;
		GetDlgItem(IDC_BTN_SECONDSERIALCLOSE)->GetWindowRect(&rtBtnClose);
		ScreenToClient(&rtBtnClose);

		int btnH = rtBtnOpen.bottom - rtBtnOpen.top;

		rect = rtBtnOpen;
		rect.top = nTop;
		rect.bottom = rect.top + btnH;
		GetDlgItem(IDC_BTN_FIRSTSERIALOPEN)->MoveWindow(&rect);

		rect = rtBtnClose;
		rect.top = nTop;
		rect.bottom = rect.top + btnH;
		GetDlgItem(IDC_BTN_FIRSTSERIALCLOSE)->MoveWindow(&rect);
	}
	//*/



}

void CDlgConfig::SetCameraLayout(DWORD dwGroupID, DWORD dwTitleID, DWORD dwComboID, DWORD dwCheckID)
{
	CRect rtGroup;
	CRect rtCtl;
	CRect rtMove;

	GetDlgItem(dwGroupID)->GetWindowRect(&rtGroup);
	ScreenToClient(&rtGroup);

	GetDlgItem(dwTitleID)->GetWindowRect(&rtCtl);
	rtMove.left = rtGroup.left + rtGroup.Width() - rtCtl.Width() - MARGIN * 2;
	rtMove.top = rtGroup.top + MARGIN * 2;
	rtMove.right = rtMove.left + rtCtl.Width();
	rtMove.bottom = rtMove.top + rtCtl.Height() + MARGIN * 2;
	GetDlgItem(dwTitleID)->MoveWindow(&rtMove);

	GetDlgItem(dwComboID)->GetWindowRect(&rtCtl);
	rtMove.top = rtMove.bottom + MARGIN;
	rtMove.right = rtMove.left + rtCtl.Width();
	rtMove.bottom = rtMove.top + rtCtl.Height();
	GetDlgItem(dwComboID)->MoveWindow(&rtMove);

	GetDlgItem(dwCheckID)->GetWindowRect(&rtCtl);
	rtMove.top = rtGroup.bottom - rtCtl.Height() - MARGIN * 5;
	rtMove.right = rtMove.left + rtCtl.Width();
	rtMove.bottom = rtMove.top + rtCtl.Height();
	GetDlgItem(dwCheckID)->MoveWindow(&rtMove);

	if (dwCheckID == IDC_CHECK_FIRST)
	{
		GetDlgItem(dwCheckID)->GetWindowRect(&rtCtl);
		rtMove.left = rtMove.left + 100;
		rtMove.top = rtGroup.bottom - rtCtl.Height() - MARGIN * 5;
		rtMove.right = rtMove.left + rtCtl.Width() + 5;
		rtMove.bottom = rtMove.top + rtCtl.Height();
		GetDlgItem(IDC_CHK_FREVERSEX)->MoveWindow(&rtMove);

		GetDlgItem(IDC_CHK_FREVERSEX)->GetWindowRect(&rtCtl);
		rtMove.top = rtMove.bottom + MARGIN * 2;
		rtMove.right = rtMove.left + rtCtl.Width() + 5;
		rtMove.bottom = rtMove.top + rtCtl.Height();
		GetDlgItem(IDC_CHK_FREVERSEY)->MoveWindow(&rtMove);
	}

	if (dwCheckID == IDC_CHECK_SECOND)
	{
		GetDlgItem(dwCheckID)->GetWindowRect(&rtCtl);
		rtMove.left = rtMove.left + 100;
		rtMove.top = rtGroup.bottom - rtCtl.Height() - MARGIN * 5;
		rtMove.right = rtMove.left + rtCtl.Width() + 5;
		rtMove.bottom = rtMove.top + rtCtl.Height();
		GetDlgItem(IDC_CHK_SREVERSEX)->MoveWindow(&rtMove);

		GetDlgItem(IDC_CHK_SREVERSEX)->GetWindowRect(&rtCtl);
		rtMove.top = rtMove.bottom + MARGIN * 2;
		rtMove.right = rtMove.left + rtCtl.Width() + 5;
		rtMove.bottom = rtMove.top + rtCtl.Height();
		GetDlgItem(IDC_CHK_SREVERSEY)->MoveWindow(&rtMove);
	}
}

void CDlgConfig::DrawCameraLayout(CDC* pDC, DWORD dwGroupID, COLORREF rgbBk, DWORD dwIcon, DWORD dwLT, DWORD dwLB, DWORD dwRT, DWORD dwRB)
{
	if (NULL == pDC)
		return;

	CRect rtClient;
	GetDlgItem(dwGroupID)->GetWindowRect(&rtClient);
	ScreenToClient(&rtClient);
	if (0 != dwIcon)
		rtClient.bottom += 160;
	else
		rtClient.bottom += 50;

	if (0 != dwLT && 0 != dwLB && 0 != dwRT && 0 != dwRB)
	{
		//pDC->FillSolidRect(&rtClient, rgbBk);

		CPen pen;
		pen.CreatePen(PS_SOLID, 3, rgbBk);
		CPen* pOldPen = pDC->SelectObject(&pen);

		const int gap = 2;

		pDC->MoveTo(rtClient.left + gap, rtClient.top + gap);
		pDC->LineTo(rtClient.right - gap, rtClient.top + gap);
		pDC->LineTo(rtClient.right - gap, rtClient.bottom - gap);
		pDC->LineTo(rtClient.left + gap, rtClient.bottom - gap);
		pDC->LineTo(rtClient.left + gap, rtClient.top + gap);
	}

	const int w = rtClient.Width();
	const int h = rtClient.Height();

	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);

	BITMAP bm;
	if (0 != dwIcon)
	{
		HBITMAP hBmpIcon = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(dwIcon));
		if (hBmpIcon)
		{
			::GetObject(hBmpIcon, sizeof(BITMAP), &bm);

			HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpIcon);
			pDC->TransparentBlt(rtClient.left + MARGIN * 2, rtClient.top + MARGIN * 3, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, bm.bmWidth, bm.bmHeight, RGB(255, 255, 255));

			MemDC.SelectObject(hOld);
			::DeleteObject(hBmpIcon);
		}
	}

	if (0 != dwLT && 0 != dwLB && 0 != dwRT && 0 != dwRB)
	{
		HBITMAP hBmpLeftTop = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(dwLT));
		if (hBmpLeftTop)
		{
			::GetObject(hBmpLeftTop, sizeof(BITMAP), &bm);

			HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpLeftTop);
			pDC->BitBlt(rtClient.left, rtClient.top, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

			MemDC.SelectObject(hOld);
			::DeleteObject(hBmpLeftTop);
		}


		HBITMAP hBmpLeftBottom = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(dwLB));
		if (hBmpLeftBottom)
		{
			::GetObject(hBmpLeftBottom, sizeof(BITMAP), &bm);

			HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpLeftBottom);
			pDC->BitBlt(rtClient.left, rtClient.bottom - bm.bmHeight, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

			MemDC.SelectObject(hOld);
			::DeleteObject(hBmpLeftBottom);
		}

		HBITMAP hBmpRightTop = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(dwRT));
		if (hBmpRightTop)
		{
			::GetObject(hBmpRightTop, sizeof(BITMAP), &bm);

			HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpRightTop);
			pDC->BitBlt(rtClient.right - bm.bmWidth, rtClient.top, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

			MemDC.SelectObject(hOld);
			::DeleteObject(hBmpRightTop);
		}

		HBITMAP hBmpRightBottom = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(dwRB));
		if (hBmpRightBottom)
		{
			::GetObject(hBmpRightBottom, sizeof(BITMAP), &bm);

			HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpRightBottom);
			pDC->BitBlt(rtClient.right - bm.bmWidth, rtClient.bottom - bm.bmHeight, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

			MemDC.SelectObject(hOld);
			::DeleteObject(hBmpRightBottom);
		}
	}
}

void CDlgConfig::DrawSerialLayout(CDC* pDC, CRect rect, COLORREF rgbBk, DWORD dwLT, DWORD dwLB, DWORD dwRT, DWORD dwRB)
{
	if (NULL == pDC)
		return;

	CRect rtClient = rect;
	{
		//pDC->FillSolidRect(&rtClient, rgbBk);

		CPen pen;
		pen.CreatePen(PS_SOLID, 3, rgbBk);
		CPen* pOldPen = pDC->SelectObject(&pen);

		const int gap = 2;

		pDC->MoveTo(rtClient.left + gap, rtClient.top + gap);
		pDC->LineTo(rtClient.right - gap, rtClient.top + gap);
		pDC->LineTo(rtClient.right - gap, rtClient.bottom - gap);
		pDC->LineTo(rtClient.left + gap, rtClient.bottom - gap);
		pDC->LineTo(rtClient.left + gap, rtClient.top + gap);
	}

	const int w = rtClient.Width();
	const int h = rtClient.Height();

	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);

	BITMAP bm;
	HBITMAP hBmpLeftTop = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(dwLT));
	if (hBmpLeftTop)
	{
		::GetObject(hBmpLeftTop, sizeof(BITMAP), &bm);

		HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpLeftTop);
		pDC->BitBlt(rtClient.left, rtClient.top, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

		MemDC.SelectObject(hOld);
		::DeleteObject(hBmpLeftTop);
	}

	HBITMAP hBmpLeftBottom = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(dwLB));
	if (hBmpLeftBottom)
	{
		::GetObject(hBmpLeftBottom, sizeof(BITMAP), &bm);

		HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpLeftBottom);
		pDC->BitBlt(rtClient.left, rtClient.bottom - bm.bmHeight, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

		MemDC.SelectObject(hOld);
		::DeleteObject(hBmpLeftBottom);
	}

	HBITMAP hBmpRightTop = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(dwRT));
	if (hBmpRightTop)
	{
		::GetObject(hBmpRightTop, sizeof(BITMAP), &bm);

		HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpRightTop);
		pDC->BitBlt(rtClient.right - bm.bmWidth, rtClient.top, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

		MemDC.SelectObject(hOld);
		::DeleteObject(hBmpRightTop);
	}

	HBITMAP hBmpRightBottom = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(dwRB));
	if (hBmpRightBottom)
	{
		::GetObject(hBmpRightBottom, sizeof(BITMAP), &bm);

		HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpRightBottom);
		pDC->BitBlt(rtClient.right - bm.bmWidth, rtClient.bottom - bm.bmHeight, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

		MemDC.SelectObject(hOld);
		::DeleteObject(hBmpRightBottom);
	}
}

void CDlgConfig::DrawLineTypeLayout2(CDC* pDC, CRect rect, COLORREF rgbBk, DWORD dwLT, DWORD dwLB, DWORD dwRT, DWORD dwRB)
{
	if (NULL == pDC)
		return;

	CRect rtClient = rect;
		
		rtClient.top += -10;
		//////rtClient.bottom += 60;
		rtClient.bottom += 70;

	{
		//pDC->FillSolidRect(&rtClient, rgbBk);

		CPen pen;
		pen.CreatePen(PS_SOLID, 3, rgbBk);
		CPen* pOldPen = pDC->SelectObject(&pen);

		const int gap = 2;

		pDC->MoveTo(rtClient.left + gap, rtClient.top + gap);
		pDC->LineTo(rtClient.right - gap, rtClient.top + gap);
		pDC->LineTo(rtClient.right - gap, rtClient.bottom - gap);
		pDC->LineTo(rtClient.left + gap, rtClient.bottom - gap);
		pDC->LineTo(rtClient.left + gap, rtClient.top + gap);
	}

	const int w = rtClient.Width();
	const int h = rtClient.Height();

	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);

	BITMAP bm;
	HBITMAP hBmpLeftTop = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(dwLT));
	if (hBmpLeftTop)
	{
		::GetObject(hBmpLeftTop, sizeof(BITMAP), &bm);

		HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpLeftTop);
		pDC->BitBlt(rtClient.left, rtClient.top, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

		MemDC.SelectObject(hOld);
		::DeleteObject(hBmpLeftTop);
	}

	HBITMAP hBmpLeftBottom = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(dwLB));
	if (hBmpLeftBottom)
	{
		::GetObject(hBmpLeftBottom, sizeof(BITMAP), &bm);

		HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpLeftBottom);
		pDC->BitBlt(rtClient.left, rtClient.bottom - bm.bmHeight, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

		MemDC.SelectObject(hOld);
		::DeleteObject(hBmpLeftBottom);
	}

	HBITMAP hBmpRightTop = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(dwRT));
	if (hBmpRightTop)
	{
		::GetObject(hBmpRightTop, sizeof(BITMAP), &bm);

		HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpRightTop);
		pDC->BitBlt(rtClient.right - bm.bmWidth, rtClient.top, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

		MemDC.SelectObject(hOld);
		::DeleteObject(hBmpRightTop);
	}

	HBITMAP hBmpRightBottom = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(dwRB));
	if (hBmpRightBottom)
	{
		::GetObject(hBmpRightBottom, sizeof(BITMAP), &bm);

		HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpRightBottom);
		pDC->BitBlt(rtClient.right - bm.bmWidth, rtClient.bottom - bm.bmHeight, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

		MemDC.SelectObject(hOld);
		::DeleteObject(hBmpRightBottom);
	}
}

void CDlgConfig::DrawLineTypeLayout(CDC* pDC, DWORD dwGroupID, COLORREF rgbBk, DWORD dwIcon, DWORD dwLT, DWORD dwLB, DWORD dwRT, DWORD dwRB)
{
	if (NULL == pDC)
		return;

	CRect rtClient;
	GetDlgItem(dwGroupID)->GetWindowRect(&rtClient);
	ScreenToClient(&rtClient);
	if (0 != dwIcon)
		rtClient.bottom += 160;
	else
		rtClient.bottom += 60;
	if (0 != dwLT && 0 != dwLB && 0 != dwRT && 0 != dwRB)
	{
		//pDC->FillSolidRect(&rtClient, rgbBk);

		CPen pen;
		pen.CreatePen(PS_SOLID, 3, rgbBk);
		CPen* pOldPen = pDC->SelectObject(&pen);

		const int gap = 2;

		pDC->MoveTo(rtClient.left + gap, rtClient.top + gap);
		pDC->LineTo(rtClient.right - gap, rtClient.top + gap);
		pDC->LineTo(rtClient.right - gap, rtClient.bottom - gap);
		pDC->LineTo(rtClient.left + gap, rtClient.bottom - gap);
		pDC->LineTo(rtClient.left + gap, rtClient.top + gap);
	}

	const int w = rtClient.Width();
	const int h = rtClient.Height();

	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);

	BITMAP bm;
	if (0 != dwIcon)
	{
		HBITMAP hBmpIcon = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(dwIcon));
		if (hBmpIcon)
		{
			::GetObject(hBmpIcon, sizeof(BITMAP), &bm);

			HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpIcon);
			pDC->TransparentBlt(rtClient.left + MARGIN * 2, rtClient.top + MARGIN * 3, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, bm.bmWidth, bm.bmHeight, RGB(255, 255, 255));

			MemDC.SelectObject(hOld);
			::DeleteObject(hBmpIcon);
		}
	}

	if (0 != dwLT && 0 != dwLB && 0 != dwRT && 0 != dwRB)
	{
		HBITMAP hBmpLeftTop = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(dwLT));
		if (hBmpLeftTop)
		{
			::GetObject(hBmpLeftTop, sizeof(BITMAP), &bm);

			HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpLeftTop);
			pDC->BitBlt(rtClient.left, rtClient.top, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

			MemDC.SelectObject(hOld);
			::DeleteObject(hBmpLeftTop);
		}


		HBITMAP hBmpLeftBottom = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(dwLB));
		if (hBmpLeftBottom)
		{
			::GetObject(hBmpLeftBottom, sizeof(BITMAP), &bm);

			HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpLeftBottom);
			pDC->BitBlt(rtClient.left, rtClient.bottom - bm.bmHeight, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

			MemDC.SelectObject(hOld);
			::DeleteObject(hBmpLeftBottom);
		}

		HBITMAP hBmpRightTop = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(dwRT));
		if (hBmpRightTop)
		{
			::GetObject(hBmpRightTop, sizeof(BITMAP), &bm);

			HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpRightTop);
			pDC->BitBlt(rtClient.right - bm.bmWidth, rtClient.top, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

			MemDC.SelectObject(hOld);
			::DeleteObject(hBmpRightTop);
		}

		HBITMAP hBmpRightBottom = LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(dwRB));
		if (hBmpRightBottom)
		{
			::GetObject(hBmpRightBottom, sizeof(BITMAP), &bm);

			HBITMAP hOld = (HBITMAP)MemDC.SelectObject(hBmpRightBottom);
			pDC->BitBlt(rtClient.right - bm.bmWidth, rtClient.bottom - bm.bmHeight, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);

			MemDC.SelectObject(hOld);
			::DeleteObject(hBmpRightBottom);
		}
	}
}

void CDlgConfig::UpdateCameraList()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();

#ifdef USE_BASLER_CAMERA
	BOOL bEnableGigE = pCaptureManager->IsEnableConnection(TYPE_NETWORK_BASLER);
#endif

#ifdef USE_GIGE_CAMERA
	BOOL bEnableGigE = pCaptureManager->IsEnableConnection(TYPE_NETWORK_GIGE);
#endif

	if (bEnableGigE)
	{
		GetDlgItem(IDC_BTN_RESEARCH)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_DISCONNECT)->EnableWindow(TRUE);
		//GetDlgItem(IDC_BTN_CAMERACTRL)->EnableWindow(TRUE);

		GetDlgItem(IDC_CHECK_FIRST)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHK_FREVERSEX)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHK_FREVERSEY)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK_SECOND)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHK_SREVERSEX)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHK_SREVERSEY)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK_ALLCAMERA)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_BTN_RESEARCH)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_DISCONNECT)->EnableWindow(FALSE);
		//GetDlgItem(IDC_BTN_CAMERACTRL)->EnableWindow(FALSE);

		GetDlgItem(IDC_CHECK_FIRST)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHK_FREVERSEX)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHK_FREVERSEY)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK_SECOND)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHK_SREVERSEX)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHK_SREVERSEY)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK_ALLCAMERA)->EnableWindow(FALSE);


		((CButton*)GetDlgItem(IDC_CHECK_ALLCAMERA))->SetCheck(BST_UNCHECKED);
		((CButton*)GetDlgItem(IDC_CHECK_FIRST))->SetCheck(BST_UNCHECKED);
		((CButton*)GetDlgItem(IDC_CHECK_SECOND))->SetCheck(BST_UNCHECKED);

		GetDlgItem(IDOK)->EnableWindow(TRUE);
	}

	// GigE Camera
	// Left
	m_ctlComboFirst.ResetContent();
	m_ctlComboFirst.AddString(STR_CAMERA_NOTSELECT);
	// Right
	m_ctlComboSecond.ResetContent();
	m_ctlComboSecond.AddString(STR_CAMERA_NOTSELECT);

	if (bEnableGigE)
	{
#ifdef USE_BASLER_CAMERA
		INFO_CONNECT_OTHER_MANUFACTURER stBasler;
		memset(&stBasler, 0x00, sizeof(INFO_CONNECT_OTHER_MANUFACTURER));
		stBasler.m_stArg.m_eNetwork = TYPE_NETWORK_BASLER;

		const int nCount = pCaptureManager->GetConnectedDeviceCount(TYPE_NETWORK_BASLER);
		for (int i = 0; i < nCount; i++)
		{
			BOOL bResult = pCaptureManager->GetConnectedDeviceInfo(TYPE_NETWORK_BASLER, i, (INFO_CONNECT_DEV*)&stBasler);
			if (bResult)
			{
				m_ctlComboFirst.AddString(stBasler.m_stArg.m_szArg);
				m_ctlComboSecond.AddString(stBasler.m_stArg.m_szArg);
			}
		}
#endif

#ifdef USE_GIGE_CAMERA
		INFO_CONNECT_GIGE stGigE;
		memset(&stGigE, 0x00, sizeof(INFO_CONNECT_GIGE));
		stGigE.m_stArg.m_eNetwork = TYPE_NETWORK_GIGE;

		const int nCount = pCaptureManager->GetConnectedDeviceCount(TYPE_NETWORK_GIGE);
		for (int i = 0; i < nCount; i++)
		{
			BOOL bResult = pCaptureManager->GetConnectedDeviceInfo(TYPE_NETWORK_GIGE, i, (INFO_CONNECT_DEV*)&stGigE);
			if (bResult)
			{
				m_ctlComboFirst.AddString(stGigE.m_stArg.m_szArg);
				m_ctlComboSecond.AddString(stGigE.m_stArg.m_szArg);
			}
		}
#endif

		const INFO_CAPTUREPROC* pLeftProc = pCaptureManager->GetCapturePosition(TYPE_CAMERAPOS_FIRST);
		if (pLeftProc)
		{
			m_ctlComboFirst.SetCurSel(pLeftProc->m_nCamID + 1);
			GetDlgItem(IDC_CHECK_FIRST)->EnableWindow(TRUE);
			GetDlgItem(IDC_CHK_FREVERSEX)->EnableWindow(TRUE);
			GetDlgItem(IDC_CHK_FREVERSEY)->EnableWindow(TRUE);
		}
		else
		{
			m_ctlComboFirst.SetCurSel(0);
			GetDlgItem(IDC_CHECK_FIRST)->EnableWindow(FALSE);
			GetDlgItem(IDC_CHK_FREVERSEX)->EnableWindow(FALSE);
			GetDlgItem(IDC_CHK_FREVERSEY)->EnableWindow(FALSE);
		}

		const INFO_CAPTUREPROC* pRightProc = pCaptureManager->GetCapturePosition(TYPE_CAMERAPOS_SECOND);
		if (pRightProc)
		{
			m_ctlComboSecond.SetCurSel(pRightProc->m_nCamID + 1);
			GetDlgItem(IDC_CHECK_SECOND)->EnableWindow(TRUE);
			GetDlgItem(IDC_CHK_SREVERSEX)->EnableWindow(TRUE);
			GetDlgItem(IDC_CHK_SREVERSEY)->EnableWindow(TRUE);
		}
		else
		{
			m_ctlComboSecond.SetCurSel(0);
			GetDlgItem(IDC_CHECK_SECOND)->EnableWindow(FALSE);
			GetDlgItem(IDC_CHK_SREVERSEX)->EnableWindow(FALSE);
			GetDlgItem(IDC_CHK_SREVERSEY)->EnableWindow(FALSE);
		}

		// Print Log
		{
			CString szFirst;
			CString szSecond;
			m_ctlComboFirst.GetWindowText(szFirst);
			m_ctlComboSecond.GetWindowText(szSecond);

			if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
			{
				stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "First camera(%s), Second camera(%s)", (LPCTSTR)szFirst, (LPCTSTR)szSecond);
			}
		}
	}
	else
	{
		m_ctlComboFirst.SetCurSel(0);
		m_ctlComboSecond.SetCurSel(0);

		GetDlgItem(IDC_CHECK_FIRST)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHK_FREVERSEX)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHK_FREVERSEY)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK_SECOND)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHK_SREVERSEX)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHK_SREVERSEY)->EnableWindow(FALSE);

		// Print Log
		{
			if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
			{
				stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Fail to find camera");
			}
		}
	}
}

void CDlgConfig::UpdateGigECameraList(const TYPE_CAMERAPOS ePos, const int nSelectedIdx)
{
	if (TYPE_CAMERAPOS_NONE == ePos || TYPE_CAMERAPOS_MAX == ePos || 1 > nSelectedIdx)
		return;

	if (TYPE_CAMERAPOS_FIRST == ePos)
	{
		int nCur = m_ctlComboSecond.GetCurSel();
		if (nSelectedIdx == nCur)
		{
			m_ctlComboSecond.SetCurSel(0);

			((CButton*)GetDlgItem(IDC_CHECK_SECOND))->SetCheck(BST_UNCHECKED);
			GetDlgItem(IDC_CHECK_SECOND)->EnableWindow(FALSE);
			GetDlgItem(IDC_CHK_SREVERSEX)->EnableWindow(FALSE);
			GetDlgItem(IDC_CHK_SREVERSEY)->EnableWindow(FALSE);
			{
				CUtil::SetRegString(REG_ROOT_PATH, REG_VALUE_CAMERA_SECOND, STR_CAMERA_NONE);
			}
			this->GetParent()->PostMessage(WM_NOTIFY_CLEAR_DISPLAY, TYPE_CAMERAPOS_SECOND, 0);
		}
	}
	else if (TYPE_CAMERAPOS_SECOND == ePos)
	{
		int nCur = m_ctlComboFirst.GetCurSel();
		if (nSelectedIdx == nCur)
		{
			m_ctlComboFirst.SetCurSel(0);

			((CButton*)GetDlgItem(IDC_CHECK_FIRST))->SetCheck(BST_UNCHECKED);
			GetDlgItem(IDC_CHECK_FIRST)->EnableWindow(FALSE);
			GetDlgItem(IDC_CHK_FREVERSEX)->EnableWindow(FALSE);
			GetDlgItem(IDC_CHK_FREVERSEY)->EnableWindow(FALSE);
			{
				CUtil::SetRegString(REG_ROOT_PATH, REG_VALUE_CAMERA_FIRST, STR_CAMERA_NONE);
			}
			this->GetParent()->PostMessage(WM_NOTIFY_CLEAR_DISPLAY, TYPE_CAMERAPOS_FIRST, 0);
		}
	}


	{
		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
		INFO_LOGFUNC stLogFunc = pCaptureManager->m_Log.GetLogInterface();
		// Print Log
		{
			CString szFirst;
			CString szSecond;
			m_ctlComboFirst.GetWindowText(szFirst);
			m_ctlComboSecond.GetWindowText(szSecond);

			if (stLogFunc.m_pFuncTextLog && stLogFunc.m_pArg)
			{
				stLogFunc.m_pFuncTextLog(stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Change - First camera(%s), Second camera(%s)", (LPCTSTR)szFirst, (LPCTSTR)szSecond);
			}
		}
	}

}

void CDlgConfig::UpdateFreerunCameraFromCamera()
{
	UpdateFreerunCameraFromCamera(TYPE_CAMERAPOS_FIRST, IDC_CHECK_FIRST);
	UpdateFreerunCameraFromCamera(TYPE_CAMERAPOS_SECOND, IDC_CHECK_SECOND);

	{
		BOOL bFreeRun = FALSE;
		if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_FIRST))->GetCheck())
			bFreeRun = TRUE;
		if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_SECOND))->GetCheck())
			bFreeRun = TRUE;

		GetDlgItem(IDOK)->EnableWindow(!bFreeRun);
		GetDlgItem(IDC_COMBO_FIRST)->EnableWindow(!bFreeRun);
		GetDlgItem(IDC_COMBO_SECOND)->EnableWindow(!bFreeRun);

		// All Camera
		if (bFreeRun)
		{
			BOOL bAllFreeRun = TRUE;

			if (GetDlgItem(IDC_CHECK_FIRST)->IsWindowEnabled() && BST_UNCHECKED == ((CButton*)GetDlgItem(IDC_CHECK_FIRST))->GetCheck())
				bAllFreeRun = FALSE;
			if (GetDlgItem(IDC_CHECK_SECOND)->IsWindowEnabled() && BST_UNCHECKED == ((CButton*)GetDlgItem(IDC_CHECK_SECOND))->GetCheck())
				bAllFreeRun = FALSE;

			if (bAllFreeRun)
				((CButton*)GetDlgItem(IDC_CHECK_ALLCAMERA))->SetCheck(BST_CHECKED);
			else
				((CButton*)GetDlgItem(IDC_CHECK_ALLCAMERA))->SetCheck(BST_UNCHECKED);
		}


	}
}

#ifndef DEF_FREERUN_CAPTURE
void CDlgConfig::UpdateFreerunCameraFromCamera(TYPE_CAMERAPOS ePos, DWORD dwCtrlID)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	INFO_TRIGGER_PARA stParam;
	memset(&stParam, 0x00, sizeof(INFO_TRIGGER_PARA));
	
	const INFO_CAPTUREPROC* pstProc = pCaptureManager->GetCapturePosition(ePos);
	if (pstProc)
	{
		BOOL bResult = pCaptureManager->GetTriggerMode(pstProc->m_eNetwork, pstProc->m_dwProcID, &stParam);
		if (bResult)
		{
			if (TRIGGER_ON == stParam.nTriggerMode)
			{
				((CButton*)GetDlgItem(dwCtrlID))->SetCheck(BST_UNCHECKED);

				if (TRIGGER_SRC_SW != stParam.nTriggerSource)
				{
					stParam.nTriggerSource = TRIGGER_SRC_SW;
					pCaptureManager->SetTriggerMode(pstProc->m_eNetwork, pstProc->m_dwProcID, stParam);
				}
			}
			else
			{
				((CButton*)GetDlgItem(dwCtrlID))->SetCheck(BST_CHECKED);
			}
		}
		else
		{
			((CButton*)GetDlgItem(dwCtrlID))->SetCheck(BST_CHECKED);
		}
	}
	else
	{
		((CButton*)GetDlgItem(dwCtrlID))->SetCheck(BST_UNCHECKED);
	}

}

#else
void CDlgConfig::UpdateFreerunCameraFromCamera(TYPE_CAMERAPOS ePos, DWORD dwCtrlID)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	INFO_TRIGGER_PARA stParam;
	memset(&stParam, 0x00, sizeof(INFO_TRIGGER_PARA));

	const INFO_CAPTUREPROC* pstProc = pCaptureManager->GetCapturePosition(ePos);
	if (pstProc)
	{
		BOOL bResult = pCaptureManager->GetTriggerMode(pstProc->m_eNetwork, pstProc->m_dwProcID, &stParam);
		if (bResult)
		{
			if (TRIGGER_ON == stParam.nTriggerMode)
			{
				((CButton*)GetDlgItem(dwCtrlID))->SetCheck(BST_UNCHECKED);

				if (TRIGGER_SRC_SW != stParam.nTriggerSource)
				{
					stParam.nTriggerSource = TRIGGER_SRC_SW;
					pCaptureManager->SetTriggerMode(pstProc->m_eNetwork, pstProc->m_dwProcID, stParam);
				}
			}
			else // TRIGGER OFF
			{
				((CButton*)GetDlgItem(dwCtrlID))->SetCheck(BST_UNCHECKED);
				pCaptureManager->SetReadySnapCapture(ePos, TRUE);
			}
		}
		else
		{
			((CButton*)GetDlgItem(dwCtrlID))->SetCheck(BST_UNCHECKED);
			pCaptureManager->SetReadySnapCapture(ePos, TRUE);
		}
	}
	else
	{
		((CButton*)GetDlgItem(dwCtrlID))->SetCheck(BST_UNCHECKED);
		pCaptureManager->SetReadySnapCapture(ePos, TRUE);
	}

}


#endif

BOOL CDlgConfig::GetTriggerModeFromCamera(TYPE_CAMERAPOS ePos, DWORD& dwTriggerMode, DWORD& dwTriggerSrc)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	INFO_TRIGGER_PARA stParam;
	memset(&stParam, 0x00, sizeof(INFO_TRIGGER_PARA));

	BOOL bResult = FALSE;

	const INFO_CAPTUREPROC* pstProc = pCaptureManager->GetCapturePosition(ePos);
	if (pstProc)
	{
		bResult = pCaptureManager->GetTriggerMode(pstProc->m_eNetwork, pstProc->m_dwProcID, &stParam);
		if (bResult)
		{
			dwTriggerMode = stParam.nTriggerMode;
			dwTriggerSrc = stParam.nTriggerSource;
		}
	}

	return bResult;
}



void CDlgConfig::UpdateFreerunCamera(TYPE_CAMERAPOS ePos, DWORD dwCtrlID)
{
	const int nCheck = ((CButton*)GetDlgItem(dwCtrlID))->GetCheck();
	if (BST_CHECKED == nCheck)
	{
		BOOL bAllCamera = TRUE;

		if (GetDlgItem(IDC_CHECK_FIRST)->IsWindowEnabled() && BST_CHECKED != ((CButton*)GetDlgItem(IDC_CHECK_FIRST))->GetCheck())
			bAllCamera = FALSE;
		if (GetDlgItem(IDC_CHECK_SECOND)->IsWindowEnabled() && BST_CHECKED != ((CButton*)GetDlgItem(IDC_CHECK_SECOND))->GetCheck())
			bAllCamera = FALSE;

		// Freerun Camera: Barcode 
		if (bAllCamera)
			((CButton*)GetDlgItem(IDC_CHECK_ALLCAMERA))->SetCheck(BST_CHECKED);
		else
			((CButton*)GetDlgItem(IDC_CHECK_ALLCAMERA))->SetCheck(BST_UNCHECKED);
	}
	else
	{
		((CButton*)GetDlgItem(IDC_CHECK_ALLCAMERA))->SetCheck(BST_UNCHECKED);
	}

	// Disable Stop
	{
		BOOL bFreerun = IsFreerunCamera();
		GetDlgItem(IDOK)->EnableWindow(!bFreerun);
		GetDlgItem(IDC_COMBO_FIRST)->EnableWindow(!bFreerun);
		GetDlgItem(IDC_COMBO_SECOND)->EnableWindow(!bFreerun);
	}
}

BOOL CDlgConfig::IsFreerunCamera()
{
	BOOL bFreerun = FALSE;

	if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_FIRST))->GetCheck())
		bFreerun = TRUE;
	if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_SECOND))->GetCheck())
		bFreerun = TRUE;

	return bFreerun;
}

#ifndef DEF_FREERUN_CAPTURE
BOOL CDlgConfig::ChangeCameraTriggerMode(DWORD dwPosFlag)
{
	DWORD dwOptFlag = 0;
	
	if (FLAG_FIRST & dwPosFlag)
	{
		if (BST_CHECKED != ((CButton*)GetDlgItem(IDC_CHECK_FIRST))->GetCheck())		// Checked Freerun...
			dwOptFlag |= FLAG_OPT_FIRST;
	}
	if (FLAG_SECOND & dwPosFlag)
	{
		if (BST_CHECKED != ((CButton*)GetDlgItem(IDC_CHECK_SECOND))->GetCheck())		// Checked Freerun...
			dwOptFlag |= FLAG_OPT_SECOND;
	}

	CDlgMessage dlgMessage;
	dlgMessage.SetLoadType(TYPE_LOAD_TRIGGERMODE, dwPosFlag, dwOptFlag);
	dlgMessage.DoModal();


	{
		BOOL bAllCamera = TRUE;

		if (GetDlgItem(IDC_CHECK_FIRST)->IsWindowEnabled() && BST_CHECKED != ((CButton*)GetDlgItem(IDC_CHECK_FIRST))->GetCheck())
			bAllCamera = FALSE;
		if (GetDlgItem(IDC_CHECK_SECOND)->IsWindowEnabled() && BST_CHECKED != ((CButton*)GetDlgItem(IDC_CHECK_SECOND))->GetCheck())
			bAllCamera = FALSE;

		if (bAllCamera)
			((CButton*)GetDlgItem(IDC_CHECK_ALLCAMERA))->SetCheck(BST_CHECKED);
		else
			((CButton*)GetDlgItem(IDC_CHECK_ALLCAMERA))->SetCheck(BST_UNCHECKED);
	}

	
	return TRUE;
}

#else
BOOL CDlgConfig::ChangeCameraTriggerMode(DWORD dwPosFlag)
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	DWORD dwOptFlag = 0;
	
	pCaptureManager->SetSingleSnapCapture(FALSE);
	if (FLAG_FIRST & dwPosFlag)
	{
		if (BST_CHECKED != ((CButton*)GetDlgItem(IDC_CHECK_FIRST))->GetCheck())		// Checked Freerun...
		{
			pCaptureManager->SetReadySnapCapture(TYPE_CAMERAPOS_FIRST, TRUE);
			dwOptFlag |= FLAG_OPT_FIRST;
		}
		else
		{
			pCaptureManager->SetReadySnapCapture(TYPE_CAMERAPOS_FIRST, FALSE);
		}
	}
	if (FLAG_SECOND & dwPosFlag)
	{
		if (BST_CHECKED != ((CButton*)GetDlgItem(IDC_CHECK_SECOND))->GetCheck())		// Checked Freerun...
		{
			pCaptureManager->SetReadySnapCapture(TYPE_CAMERAPOS_SECOND, TRUE);
			dwOptFlag |= FLAG_OPT_SECOND;
		}
		else
		{
			pCaptureManager->SetReadySnapCapture(TYPE_CAMERAPOS_SECOND, FALSE);
		}
	}

	CDlgMessage dlgMessage;
	dlgMessage.SetLoadType(TYPE_LOAD_TRIGGERMODE, dwPosFlag, dwOptFlag);
	dlgMessage.DoModal();

	{
		BOOL bAllCamera = TRUE;

		if (GetDlgItem(IDC_CHECK_FIRST)->IsWindowEnabled() && BST_CHECKED != ((CButton*)GetDlgItem(IDC_CHECK_FIRST))->GetCheck())
			bAllCamera = FALSE;
		if (GetDlgItem(IDC_CHECK_SECOND)->IsWindowEnabled() && BST_CHECKED != ((CButton*)GetDlgItem(IDC_CHECK_SECOND))->GetCheck())
			bAllCamera = FALSE;

		if (bAllCamera)
			((CButton*)GetDlgItem(IDC_CHECK_ALLCAMERA))->SetCheck(BST_CHECKED);
		else
			((CButton*)GetDlgItem(IDC_CHECK_ALLCAMERA))->SetCheck(BST_UNCHECKED);
	}
	return TRUE;
}
#endif


void CDlgConfig::UpdateSerialPort()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	
	CSerialCtrl* pStrobeFirst = pCaptureManager->GetStrobeControlPort(TYPE_CAMERAPOS_FIRST);
	if (pStrobeFirst && pStrobeFirst->IsOpen())
	{
		GetDlgItem(IDC_COMBO_FIRSTCOMPORT)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_FIRSTSPEED)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_FIRSTSTROBE)->EnableWindow(TRUE);
		if (0 == m_ctlComboStrobeFirst.GetCurSel())
			GetDlgItem(IDC_EDIT_FIRSTBRIGHTNESS)->EnableWindow(FALSE);
		else
			GetDlgItem(IDC_EDIT_FIRSTBRIGHTNESS)->EnableWindow(TRUE);

		GetDlgItem(IDC_BTN_FIRSTSERIALOPEN)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_FIRSTSERIALCLOSE)->EnableWindow(TRUE);


		GetDlgItem(IDC_COMBO_SECONDSTROBE)->EnableWindow(TRUE);
		if (0 == m_ctlComboStrobeSecond.GetCurSel())
			GetDlgItem(IDC_EDIT_SECONDBRIGHTNESS)->EnableWindow(FALSE);
		else
			GetDlgItem(IDC_EDIT_SECONDBRIGHTNESS)->EnableWindow(TRUE);

		GetDlgItem(IDC_COMBO_STROBECONTROLLERTYPE)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_COMBO_FIRSTCOMPORT)->EnableWindow(TRUE);
		GetDlgItem(IDC_COMBO_FIRSTSPEED)->EnableWindow(TRUE);
		GetDlgItem(IDC_COMBO_FIRSTSTROBE)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_FIRSTBRIGHTNESS)->EnableWindow(FALSE);

		GetDlgItem(IDC_BTN_FIRSTSERIALOPEN)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_FIRSTSERIALCLOSE)->EnableWindow(FALSE);


		GetDlgItem(IDC_COMBO_SECONDSTROBE)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_SECONDBRIGHTNESS)->EnableWindow(FALSE);

		GetDlgItem(IDC_COMBO_STROBECONTROLLERTYPE)->EnableWindow(TRUE);
	}

/*//
	CSerialCtrl* pStrobeSecond = pCaptureManager->GetStrobeControlPort(TYPE_CAMERAPOS_SECOND);
	if (pStrobeSecond && pStrobeSecond->IsOpen())
	{
		GetDlgItem(IDC_COMBO_SECONDCOMPORT)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_SECONDSPEED)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_SECONDSTROBE)->EnableWindow(TRUE);

		GetDlgItem(IDC_BTN_SECONDSERIALOPEN)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_SECONDSERIALCLOSE)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_COMBO_SECONDCOMPORT)->EnableWindow(TRUE);
		GetDlgItem(IDC_COMBO_SECONDSPEED)->EnableWindow(TRUE);
		GetDlgItem(IDC_COMBO_SECONDSTROBE)->EnableWindow(FALSE);

		GetDlgItem(IDC_BTN_SECONDSERIALOPEN)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_SECONDSERIALCLOSE)->EnableWindow(FALSE);
	}
//*/

/// PLC Open Check
#ifdef USE_PLC_MXCOMPONENT
	GetDlgItem(IDC_STATIC_FIRSTRESPROTOCOL)->ShowWindow(FALSE);
	GetDlgItem(IDC_COMBO_FIRSTRESPROTOCOL)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_FIRSTRESTYPE)->ShowWindow(FALSE);
	GetDlgItem(IDC_COMBO_FIRSTRESTYPE)->ShowWindow(FALSE);

	if (pCaptureManager->GetPLCProtocolType() == TYPE_PLCPROTOCOL_TCPIP && pCaptureManager->GetPLCControlType() == TYPE_PLCCONTROL_Program)
	{
		GetDlgItem(IDC_STATIC_FIRSTRESIP)->ShowWindow(TRUE);
		GetDlgItem(IDC_FIRSTRES_IPADDR)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_FIRSTRESPORT)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_FIRSTRES_PORT)->ShowWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_STATIC_FIRSTRESIP)->ShowWindow(FALSE);
		GetDlgItem(IDC_FIRSTRES_IPADDR)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_FIRSTRESPORT)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_FIRSTRES_PORT)->ShowWindow(TRUE);
	}

	if (pCaptureManager->GetMXComponentOpenCom())
	{
		GetDlgItem(IDC_FIRSTRES_IPADDR)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_FIRSTRES_PORT)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_FIRSTRESPROTOCOL)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_FIRSTRESTYPE)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_FIRSTRESOPEN)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_FIRSTRESCLOSE)->EnableWindow(TRUE);
	}
	else
	{
		if (pCaptureManager->GetPLCProtocolType() == TYPE_PLCPROTOCOL_TCPIP && pCaptureManager->GetPLCControlType() == TYPE_PLCCONTROL_Program)
		{
			GetDlgItem(IDC_FIRSTRES_IPADDR)->EnableWindow(TRUE);
			GetDlgItem(IDC_EDIT_FIRSTRES_PORT)->EnableWindow(FALSE);
		}
		else
		{
			GetDlgItem(IDC_FIRSTRES_IPADDR)->EnableWindow(FALSE);
			GetDlgItem(IDC_EDIT_FIRSTRES_PORT)->EnableWindow(TRUE);
		}

		GetDlgItem(IDC_COMBO_FIRSTRESPROTOCOL)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_FIRSTRESTYPE)->EnableWindow(FALSE);

		GetDlgItem(IDC_BTN_FIRSTRESOPEN)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_FIRSTRESCLOSE)->EnableWindow(FALSE);
	}
#else
	CEthernet* pEthernetPort = pCaptureManager->GetCommunicatePort();
	if (pEthernetPort && pEthernetPort->IsOpen())
	{
		GetDlgItem(IDC_FIRSTRES_IPADDR)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_FIRSTRES_PORT)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_FIRSTRESPROTOCOL)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_FIRSTRESTYPE)->EnableWindow(FALSE);

		GetDlgItem(IDC_BTN_FIRSTRESOPEN)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_FIRSTRESCLOSE)->EnableWindow(TRUE);

		
		m_ctlIpAddrFirstRes;
		m_ctlEditPortFirstRes;

	}
	else
	{
		GetDlgItem(IDC_FIRSTRES_IPADDR)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_FIRSTRES_PORT)->EnableWindow(TRUE);
		GetDlgItem(IDC_COMBO_FIRSTRESPROTOCOL)->EnableWindow(FALSE);	// Network Protocol
		GetDlgItem(IDC_COMBO_FIRSTRESTYPE)->EnableWindow(FALSE);		// Network Protocol

		GetDlgItem(IDC_BTN_FIRSTRESOPEN)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_FIRSTRESCLOSE)->EnableWindow(FALSE);
	}
#endif
}

void CDlgConfig::UpdateEthernetPort()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	CEthernet* pEthernetPort = pCaptureManager->GetCommunicatePort();
	if (pEthernetPort && pEthernetPort->IsOpen())
	{
		GetDlgItem(IDC_FIRSTRES_IPADDR)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_FIRSTRES_PORT)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_FIRSTRESPROTOCOL)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_FIRSTRESTYPE)->EnableWindow(FALSE);

		GetDlgItem(IDC_BTN_FIRSTRESOPEN)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_FIRSTRESCLOSE)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_FIRSTRES_IPADDR)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_FIRSTRES_PORT)->EnableWindow(TRUE);
		GetDlgItem(IDC_COMBO_FIRSTRESPROTOCOL)->EnableWindow(FALSE);	// Network Protocol
		GetDlgItem(IDC_COMBO_FIRSTRESTYPE)->EnableWindow(FALSE);		// Network Protocol

		GetDlgItem(IDC_BTN_FIRSTRESOPEN)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_FIRSTRESCLOSE)->EnableWindow(FALSE);
	}
}



BOOL CDlgConfig::CheckConfigStatus()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	if (IsFreerunCamera())
	{
		MessageBox(STR_MSG_CAPTUREMODE);
		return FALSE;
	}

#ifdef USE_BASLER_CAMERA
	BOOL bConnect = pCaptureManager->IsEnableConnection(TYPE_NETWORK_BASLER);
#endif
#ifdef USE_GIGE_CAMERA
	BOOL bConnect = pCaptureManager->IsEnableConnection(TYPE_NETWORK_GIGE);
#endif
	if (bConnect)
	{
		const INFO_CAPTUREPROC* pstProcFirst = pCaptureManager->GetCapturePosition(TYPE_CAMERAPOS_FIRST);
		const INFO_CAPTUREPROC* pstProcSecond = pCaptureManager->GetCapturePosition(TYPE_CAMERAPOS_SECOND);
		if (NULL == pstProcFirst || NULL == pstProcSecond)
		{
			MessageBox(STR_MSG_ECONNECT_CAMERA);
			return FALSE;
		}

		CSerialCtrl* pSerialFirst = pCaptureManager->GetStrobeControlPort(TYPE_CAMERAPOS_FIRST);
		CSerialCtrl* pSerialSecond = pCaptureManager->GetStrobeControlPort(TYPE_CAMERAPOS_SECOND);
		if (NULL == pSerialFirst || NULL == pSerialSecond ||
			FALSE == pSerialFirst->IsOpen() || FALSE == pSerialSecond->IsOpen())
		{
			MessageBox(STR_MSG_ECONNECT_STROBE);
			return FALSE;
		}

#ifdef USE_PLC_MXCOMPONENT
		if (!pCaptureManager->GetMXComponentOpenCom())
		{
			MessageBox(STR_MSG_ECONNECT_PLCMXCOMPONENT);
			return FALSE;
		}
#else
		CEthernet* pEthernetPort = pCaptureManager->GetCommunicatePort();
		if (NULL == pEthernetPort || FALSE == pEthernetPort->IsOpen())
		{
			MessageBox(STR_MSG_ECONNECT_COMMUNICATE);
			return FALSE;
		}
#endif
	}

	return TRUE;
}



void CDlgConfig::OnBnClickedBtnLoadFirst()
{
	TCHAR szLocation[MAX_PATH] = { 0, };
	TCHAR szFilePath[MAX_PATH] = { 0, };

	CUtil::GetCurrentDirectory(szLocation, MAX_PATH);
	if (CUtil::SelectFile(NULL, szFilePath, MAX_PATH, _T("*.xml"), _T("Insepct Files (*.xml)|*.xml|"), NULL, TRUE))
	{
		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

		INFO_INSPECTION stInspection;
		memset(&stInspection, 0x00, sizeof(INFO_INSPECTION));

		BOOL bResult = pCaptureManager->m_Xml.LoadInspection(szFilePath, stInspection);
		if (bResult)
		{
			if (stInspection.m_nCameraNum != TYPE_CAMERAPOS_FIRST)
			{
				MessageBox(STR_MSG_CAMERA_SELECT_FIRST);
			}
			else
			{
				pCaptureManager->UpdateInspection(TYPE_CAMERAPOS_FIRST, szFilePath, &stInspection);

				m_szFirstLoad = szFilePath;
				GetDlgItem(IDC_EDIT_FIRST)->SetWindowText(szFilePath); 
			}
		}
		else
		{
			MessageBox(STR_MSG_ELOAD_INSPECTION);
		}
	}
}

void CDlgConfig::OnBnClickedBtnLoadSecond()
{
	TCHAR szLocation[MAX_PATH] = { 0, };
	TCHAR szFilePath[MAX_PATH] = { 0, };

	CUtil::GetCurrentDirectory(szLocation, MAX_PATH);
	if (CUtil::SelectFile(NULL, szFilePath, MAX_PATH, _T("*.xml"), _T("Insepct Files (*.xml)|*.xml|"), NULL, TRUE))
	{
		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

		INFO_INSPECTION stInspection;
		memset(&stInspection, 0x00, sizeof(INFO_INSPECTION));

		BOOL bResult = pCaptureManager->m_Xml.LoadInspection(szFilePath, stInspection);
		if (bResult)
		{
			if (stInspection.m_nCameraNum != TYPE_CAMERAPOS_SECOND)
			{
				MessageBox(STR_MSG_CAMERA_SELECT_SECOND);
			}
			else
			{
				pCaptureManager->UpdateInspection(TYPE_CAMERAPOS_SECOND, szFilePath, &stInspection);

				m_szSecondLoad = szFilePath;
				GetDlgItem(IDC_EDIT_SECOND)->SetWindowText(szFilePath);
			}
		}
		else
		{
			MessageBox(STR_MSG_ELOAD_INSPECTION);
		}
	}
}

void CDlgConfig::OnBnClickedBtnLoadOption()
{
	TCHAR szLocation[MAX_PATH] = { 0, };
	TCHAR szFilePath[MAX_PATH] = { 0, };

	CUtil::GetCurrentDirectory(szLocation, MAX_PATH);
	if (CUtil::SelectFile(NULL, szFilePath, MAX_PATH, _T("*.xml"), _T("Option Files (*.xml)|*.xml|"), NULL, TRUE))
	{
		CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

		INFO_OPTION stOption;
		memset(&stOption, 0x00, sizeof(INFO_OPTION));

		BOOL bResult = pCaptureManager->m_Xml.LoadOption(szFilePath, stOption);
		if (bResult)
		{
			pCaptureManager->UpdateOption(&stOption);
			pCaptureManager->SetOptionFilePath(szFilePath);

			m_szOptionLoad = szFilePath;
			GetDlgItem(IDC_EDIT_OPTION)->SetWindowText(szFilePath);
		}
		else
		{
			MessageBox(STR_MSG_ELOAD_INSPECTION);
		}
	}
}

// Conifg 창 열 경우 XML파일 자동 불러오기
// 2022-05-06 수정
void CDlgConfig::LoadNewFirst()
{
	TCHAR szLocation[MAX_PATH] = { 0, };
	TCHAR szFilePath[MAX_PATH] = { 0, };

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_SCENARIO* pstScenario = pCaptureManager->GetScenario();
	memcpy(szFilePath, pstScenario->m_szFirstFilePath, MAX_PATH);

	INFO_INSPECTION stInspection;
	memset(&stInspection, 0x00, sizeof(INFO_INSPECTION));

	BOOL bResult = pCaptureManager->m_Xml.LoadInspection(szFilePath, stInspection);

	if (stInspection.m_nCameraNum != TYPE_CAMERAPOS_FIRST)
	{
		MessageBox(STR_MSG_CAMERA_SELECT_FIRST);
	}
	else
	{
		pCaptureManager->UpdateInspection(TYPE_CAMERAPOS_FIRST, szFilePath, &stInspection);

		m_szFirstLoad = szFilePath;
		GetDlgItem(IDC_EDIT_FIRST)->SetWindowText(szFilePath);
	}
}

void CDlgConfig::LoadNewSecond()
{
	TCHAR szLocation[MAX_PATH] = { 0, };
	TCHAR szFilePath[MAX_PATH] = { 0, };

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_SCENARIO* pstScenario = pCaptureManager->GetScenario();
	memcpy(szFilePath, pstScenario->m_szSecondFilePath, MAX_PATH);

	INFO_INSPECTION stInspection;
	memset(&stInspection, 0x00, sizeof(INFO_INSPECTION));

	BOOL bResult = pCaptureManager->m_Xml.LoadInspection(szFilePath, stInspection);

	if (stInspection.m_nCameraNum != TYPE_CAMERAPOS_SECOND)
	{
		MessageBox(STR_MSG_CAMERA_SELECT_SECOND);
	}
	else
	{
		pCaptureManager->UpdateInspection(TYPE_CAMERAPOS_SECOND, szFilePath, &stInspection);

		m_szSecondLoad = szFilePath;
		GetDlgItem(IDC_EDIT_SECOND)->SetWindowText(szFilePath);
	}
}

void CDlgConfig::LoadNewOption()
{
	TCHAR szLocation[MAX_PATH] = { 0, };
	TCHAR szFilePath[MAX_PATH] = { 0, };

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const TCHAR* pszOptionFilePath = pCaptureManager->GetOptionFilePath();
	memcpy(szFilePath, pszOptionFilePath, MAX_PATH);

	INFO_OPTION stOption;
	memset(&stOption, 0x00, sizeof(INFO_OPTION));

	BOOL bResult = pCaptureManager->m_Xml.LoadOption(szFilePath, stOption);

	pCaptureManager->UpdateOption(&stOption);
	pCaptureManager->SetOptionFilePath(szFilePath);

	m_szOptionLoad = szFilePath;
	GetDlgItem(IDC_EDIT_OPTION)->SetWindowText(szFilePath);
}


void CDlgConfig::OnCbnSelchangeComboFirstcomport()
{
	CString szText;
	m_ctlComboSerialFirst.GetWindowText(szText);

	CUtil::SetRegString(REG_ROOT_PATH, REG_VALUE_SERIALPORT_FIRST, (LPTSTR)(LPCTSTR)szText);

}
void CDlgConfig::OnCbnSelchangeComboFirstspeed()
{
	CString szText;
	m_ctlComboSpeedFirst.GetWindowText(szText);

	CUtil::SetRegString(REG_ROOT_PATH, REG_VALUE_SERIALSPEED_FIRST, (LPTSTR)(LPCTSTR)szText);
}


void CDlgConfig::OnCbnSelchangeComboSecondcomport()
{
	CString szText;
	m_ctlComboSerialSecond.GetWindowText(szText);

	CUtil::SetRegString(REG_ROOT_PATH, REG_VALUE_SERIALPORT_SECOND, (LPTSTR)(LPCTSTR)szText);
}
void CDlgConfig::OnCbnSelchangeComboSecondspeed()
{
	CString szText;
	m_ctlComboSpeedSecond.GetWindowText(szText);

	CUtil::SetRegString(REG_ROOT_PATH, REG_VALUE_SERIALSPEED_SECOND, (LPTSTR)(LPCTSTR)szText);
}

void CDlgConfig::OnCbnSelchangeComboFirstrestype()
{
	CString szText;
	m_ctlComboTypeFirstRes.GetWindowText(szText);

	CUtil::SetRegString(REG_ROOT_PATH, REG_VALUE_ETHERNETTYPE_MACHINE, (LPTSTR)(LPCTSTR)szText);
}

void CDlgConfig::OnCbnSelchangeComboFirstresprotocol()
{
	CString szText;
	m_ctlComboProtocolFirstRes.GetWindowText(szText);

	CUtil::SetRegString(REG_ROOT_PATH, REG_VALUE_ETHERNETPROTOCOL_MACHINE, (LPTSTR)(LPCTSTR)szText);
}

void CDlgConfig::OnCbnSelchangeComboSecondrotate()
{
	const int nCur = m_ctlSecondCameraRotate.GetCurSel();

	DWORD dwValue = 0;
	if (1 == nCur)
		dwValue = 90;
	else if (2 == nCur)
		dwValue = 270;
	else //if (0 == nCur)
		dwValue = 0;
	
	CUtil::SetRegDword(REG_ROOT_PATH, REG_VALUE_SECOND_ROTATE, dwValue);
}


void CDlgConfig::OnBnClickedRadioLine1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

#ifdef USE_PLC_MXCOMPONENT
	UpdateData(TRUE);

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	pCaptureManager->SetSelectLineInfo(TYPE_LINE_1);

	DWORD dwValue = TYPE_LINE_1;
	CUtil::SetRegDword(REG_ROOT_PATH, RED_VALUE_LINE_LINENUMER, dwValue);

	UpdateData(FALSE);
#endif

}


void CDlgConfig::OnBnClickedRadioLine2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

#ifdef USE_PLC_MXCOMPONENT
	UpdateData(TRUE);

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	pCaptureManager->SetSelectLineInfo(TYPE_LINE_2);

	DWORD dwValue = TYPE_LINE_2;
	CUtil::SetRegDword(REG_ROOT_PATH, RED_VALUE_LINE_LINENUMER, dwValue);

	UpdateData(FALSE);
#endif

}


void CDlgConfig::OnBnClickedChkFirstReversex()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
#ifdef USE_BASLER_CAMERA
	UpdateData(TRUE);

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_CAPTUREPROC* pstProc = pCaptureManager->GetCapturePosition(TYPE_CAMERAPOS_FIRST);
	if (pstProc)
	{
		//if (pCaptureManager->SetCameraPropertyReverseX(pstProc->m_dwProcID, m_bFirstCamImageReverseX))

		pCaptureManager->SetFirstCemaraReverseX(m_bFirstCamImageReverseX);
		CUtil::SetRegDword(REG_ROOT_PATH, REG_VALUE_FIRSTCAMERA_REVERSEX, (DWORD)m_bFirstCamImageReverseX);
	}

	UpdateData(FALSE);
#endif
}


void CDlgConfig::OnBnClickedChkFirstReversey()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

#ifdef USE_BASLER_CAMERA
	UpdateData(TRUE);

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_CAPTUREPROC* pstProc = pCaptureManager->GetCapturePosition(TYPE_CAMERAPOS_FIRST);
	if (pstProc)
	{
		//if (pCaptureManager->SetCameraPropertyReverseY(pstProc->m_dwProcID, m_bFirstCamImageReverseY))

		pCaptureManager->SetFirstCemaraReverseY(m_bFirstCamImageReverseY);
		CUtil::SetRegDword(REG_ROOT_PATH, REG_VALUE_FIRSTCAMERA_REVERSEY, (DWORD)m_bFirstCamImageReverseY);
	}

	UpdateData(FALSE);
#endif

}

void CDlgConfig::OnBnClickedChkSecondReversex()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
#ifdef USE_BASLER_CAMERA
	UpdateData(TRUE);

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_CAPTUREPROC* pstProc = pCaptureManager->GetCapturePosition(TYPE_CAMERAPOS_SECOND);
	if (pstProc)
	{
		//if (pCaptureManager->SetCameraPropertyReverseX(pstProc->m_dwProcID, m_bSecondCamImageReverseX))

		pCaptureManager->SetSecondCemaraReverseX(m_bSecondCamImageReverseX);
		CUtil::SetRegDword(REG_ROOT_PATH, REG_VALUE_SECONDCAMERA_REVERSEX, (DWORD)m_bSecondCamImageReverseX);
	}

	UpdateData(FALSE);
#endif
}


void CDlgConfig::OnBnClickedChkSecondReversey()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

#ifdef USE_BASLER_CAMERA
	UpdateData(TRUE);

	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	const INFO_CAPTUREPROC* pstProc = pCaptureManager->GetCapturePosition(TYPE_CAMERAPOS_SECOND);
	if (pstProc)
	{
		//if (pCaptureManager->SetCameraPropertyReverseY(pstProc->m_dwProcID, m_bSecondCamImageReverseY))

		pCaptureManager->SetSecondCemaraReverseY(m_bSecondCamImageReverseY);
		CUtil::SetRegDword(REG_ROOT_PATH, REG_VALUE_SECONDCAMERA_REVERSEY, (DWORD)m_bSecondCamImageReverseY);
	}

	UpdateData(FALSE);
#endif

}

void CDlgConfig::OnCbnSelchangeComboStrobecontrollertype()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_eStrobeControllerType = m_ctlComboStrobeControllerType.GetCurSel();

	CString szText;
	m_ctlComboStrobeControllerType.GetWindowText(szText);

	CUtil::SetRegString(REG_ROOT_PATH, REG_VALUE_STROBECONTROLLERTYPE, (LPTSTR)(LPCTSTR)szText);
}
