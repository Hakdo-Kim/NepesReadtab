
// TESTMACHINE_MXCOMPONENTDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TESTMACHINE_MXCOMPONENT.h"
#include "TESTMACHINE_MXCOMPONENTDlg.h"
#include "afxdialogex.h"
#include "Util/Util.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTESTMACHINE_MXCOMPONENTDlg dialog
CTESTMACHINE_MXCOMPONENTDlg::CTESTMACHINE_MXCOMPONENTDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTESTMACHINE_MXCOMPONENTDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_bStart = FALSE;

	m_bRealTestStarted = FALSE;

	m_nSampleFirstCount = 0;
	m_nSampleSecondCount = 0;

	m_eSelectLine = TYPE_LINE_1;

	m_nPLCStationNumber = 0;
	m_pLPMXComponectPLCCtrl = NULL;

	m_eStatePLC = TYPE_STATE_PLC_NONE;
	m_hThreadCommPLC = NULL;

	m_bStartFlag = TRUE;
}

void CTESTMACHINE_MXCOMPONENTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ED_STATIONNUM, m_nPLCStationNumber);
	DDX_Radio(pDX, IDC_RDO_LINE1, m_eSelectLine);
}

BEGIN_MESSAGE_MAP(CTESTMACHINE_MXCOMPONENTDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BTN_OPENCOM, &CTESTMACHINE_MXCOMPONENTDlg::OnBnClickedBtnOpencom)
	ON_BN_CLICKED(IDC_BTN_CLOSECOM, &CTESTMACHINE_MXCOMPONENTDlg::OnBnClickedBtnClosecom)
	ON_BN_CLICKED(IDC_BTN_START, &CTESTMACHINE_MXCOMPONENTDlg::OnBnClickedBtnStart)
	ON_BN_CLICKED(IDC_BTN_STOP, &CTESTMACHINE_MXCOMPONENTDlg::OnBnClickedBtnStop)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_RDO_LINE1, &CTESTMACHINE_MXCOMPONENTDlg::OnBnClickedRdoLine1)
	ON_BN_CLICKED(IDC_RDO_LINE2, &CTESTMACHINE_MXCOMPONENTDlg::OnBnClickedRdoLine2)
	ON_WM_COPYDATA()
END_MESSAGE_MAP()


// CTESTMACHINE_MXCOMPONENTDlg message handlers
BOOL CTESTMACHINE_MXCOMPONENTDlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (IDOK == wParam)
	{
		return TRUE;
	}
	return CDialogEx::OnCommand(wParam, lParam);
}

BOOL CTESTMACHINE_MXCOMPONENTDlg::PreTranslateMessage(MSG* pMsg)
{
	if (WM_KEYDOWN == pMsg->message)
	{
		if (VK_ESCAPE == pMsg->wParam)
		{
			return TRUE;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


BOOL CTESTMACHINE_MXCOMPONENTDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	//UpdateConnectState(FALSE);

/// mxComponenet
	m_nPLCStationNumber = 0;
	if (!m_pLPMXComponectPLCCtrl)
	{
		m_pLPMXComponectPLCCtrl = new CLPMxComponentPLCCtrl();
		if (!m_pLPMXComponectPLCCtrl->CreateLPMxComponenetPLCCtrl())
		{
			AfxMessageBox(_T("PLC MXComponent Object 생성 실패 !!!"));

			delete m_pLPMXComponectPLCCtrl;
			m_pLPMXComponectPLCCtrl = NULL;

			return FALSE;
		}
	}


#ifdef USE_PLC_COPYDATA
	m_hTargetWnd = ::FindWindow(NULL, TARGETWINDOWTITLE);
#endif

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTESTMACHINE_MXCOMPONENTDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTESTMACHINE_MXCOMPONENTDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTESTMACHINE_MXCOMPONENTDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CTESTMACHINE_MXCOMPONENTDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (TIMERID_CLOSECOMMUNICATION == nIDEvent)
	{
		KillTimer(TIMERID_CLOSECOMMUNICATION);

		long lRet;
		if (m_pLPMXComponectPLCCtrl && m_pLPMXComponectPLCCtrl->GetPLCControlOpen())
			m_pLPMXComponectPLCCtrl->CloseLPMxComponenetPLCCtrl(&lRet);

		UpdateConnectState(FALSE);
	}

	if (TIMERID_INSPECTIONSTOP == nIDEvent)
	{
		KillTimer(TIMERID_INSPECTIONSTOP);
		OnBnClickedBtnStop();
	}
}

void CTESTMACHINE_MXCOMPONENTDlg::OnClose()
{
	OnBnClickedBtnClosecom();

	CDialogEx::OnOK();
}

void CTESTMACHINE_MXCOMPONENTDlg::OnBnClickedBtnOpencom()
{
	UpdateData(TRUE);
#ifdef USE_PLC_COPYDATA
#else
	{
		long lRet;
		long lCpuCode;
		CString strCpuName = _T("");

		if (!m_pLPMXComponectPLCCtrl)
			return;

		m_pLPMXComponectPLCCtrl->SetPLCProtocolType(PLC_DEFAULT_PROTOCOLTYPE);
		m_pLPMXComponectPLCCtrl->SetPLCContorlType(PLC_DEFAULT_CONTROLTYPE);
		//m_pLPMXComponectPLCCtrl->SetPLCContorlType(TYPE_PLCCONTROL_Utility);
		//m_pLPMXComponectPLCCtrl->SetPLCContorlType(TYPE_PLCCONTROL_Program);
		m_pLPMXComponectPLCCtrl->SetLogicalStationNumber(m_nPLCStationNumber);
		m_pLPMXComponectPLCCtrl->SetHostAddress(PLC_DEFAULT_HOSTADDRESS);

		BOOL bResult = m_pLPMXComponectPLCCtrl->OpenLPMxComponenetPLCCtrl(&lRet);
		UpdateConnectState(bResult);

		if (!bResult)
		{
			AfxMessageBox(_T("PLC Open Fail !!!  Check PLC Machine !!!")); return;
		}

		CString strLogMessage = _T("");
		strLogMessage.Format("OpenLPMxComponenet : 0x%08x", lRet);
		UpdateMessage(strLogMessage.GetBuffer());
		strLogMessage.ReleaseBuffer();

		if (!m_pLPMXComponectPLCCtrl->GetLPMxComponenetPLCCtrlCPUType(&strCpuName, &lCpuCode, &lRet))
		{
			AfxMessageBox(_T("Get PLC Cpu Info Fail !!!!!")); return;
		}

		strLogMessage.Format("Get CPU Type : Name : %s, CpuCode: 0x%x(%d),  0x%08x", strCpuName, lCpuCode, lCpuCode, lRet);
		UpdateMessage(strLogMessage.GetBuffer());
		strLogMessage.ReleaseBuffer();
	}
#endif

	UpdateData(FALSE);
}


void CTESTMACHINE_MXCOMPONENTDlg::OnBnClickedBtnClosecom()
{
#ifdef USE_PLC_COPYDATA
#else
	if (m_bStart)
		OnBnClickedBtnStop();

	m_nSampleFirstCount = 0;
	m_nSampleSecondCount = 0;

	SetTimer(TIMERID_CLOSECOMMUNICATION, 500, NULL);
#endif
}


void CTESTMACHINE_MXCOMPONENTDlg::OnBnClickedBtnStart()
{
	UpdateData(TRUE);

#ifdef USE_PLC_COPYDATA
#else
	AllClearPLCMemoryMap(m_eSelectLine);

	m_eStatePLC = TYPE_STATE_PLC_WAITING_READY;

	BOOL bFirstStart	= InspectFirstCamera();
	BOOL bSecondStart	= InspectSecondCamera();
	if (bFirstStart && bSecondStart)
	{
		UpdateStartState(TRUE);
		m_bStart = TRUE;
	}
	else
		AfxMessageBox(_T("Fail to start..."));

	m_hThreadCommPLC = ::CreateThread(0, 0, ThreadCommPLC, LPVOID(this), 0, &m_dwThreadIdCommPLC);
#endif

	UpdateData(FALSE);
}


void CTESTMACHINE_MXCOMPONENTDlg::OnBnClickedBtnStop()
{
	UpdateData(TRUE);

#ifdef USE_PLC_COPYDATA
#else
	UpdateStartState(FALSE);

	m_eStatePLC = TYPE_STATE_PLC_NONE;

	m_bStart = FALSE;

	switch (::WaitForSingleObject(m_hThreadCommPLC, 10000))
	{
	case WAIT_OBJECT_0:
		break;
	case WAIT_TIMEOUT:
		::TerminateThread(m_hThreadCommPLC, 0);
		break;
	}

	::CloseHandle(m_hThreadCommPLC);
	m_hThreadCommPLC = NULL;

	m_nSampleFirstCount = 0;
	m_nSampleSecondCount = 0;

	AllClearPLCMemoryMap(m_eSelectLine);
#endif

	GetDlgItem(IDC_EDIT_SECONDCAMERA)->SetWindowText("");
	GetDlgItem(IDC_EDIT_FIRSTCAMERA)->SetWindowText("");
	UpdateMessage("");

	UpdateData(FALSE);

}

const BOOL CTESTMACHINE_MXCOMPONENTDlg::IsStarted()
{
	return m_bStart;
}

//TYPE_STATE_VISION_SENDINSPECTION,			// W0
//TYPE_STATE_PLC_SENDINSPECTION,			// w20
//TYPE_STATE_ALL_RESULTSIZE,				// W2
//TYPE_STATE_ALL_RESULTSHAPE,				// W3
//TYPE_STATE_ALL_AVERAGESIZE,				// W4
//TYPE_STATE_ALL_VALUESIZE,					// W5
//TPYE_STATE_VISION_LIVEBIT,				// W6
//TPYE_STATE_TEMPERATURE,					// WA
//TPYE_STATE_TEMPERATURE_SUB,				// W40

CString CTESTMACHINE_MXCOMPONENTDlg::MakeDeviceInfo(int eSelectLine, int eCurPos, int eActionState, int eHeaterNumber)
{
	CString strDeviceMemoryMap = _T("");

	switch (eActionState)
	{
		case TYPE_STATE_VISION_SENDINSPECTION:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + eCurPos * 0x10 + MEMORY0;
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
			return strDeviceMemoryMap;
		}
		break;
		case TYPE_STATE_PLC_SENDINSPECTION:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + eCurPos * 0x10 + MEMORY1;
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
			return strDeviceMemoryMap;
		}
		break;
		case TYPE_STATE_ALL_RESULTSIZE:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + eCurPos * 0x10 + MEMORY2;
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
			return strDeviceMemoryMap;
		}
		break;
		case TYPE_STATE_ALL_RESULTSHAPE:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + eCurPos * 0x10 + MEMORY3;
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
			return strDeviceMemoryMap;
		}
		break;
		case TYPE_STATE_ALL_AVERAGESIZE:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + eCurPos * 0x10 + MEMORY4;
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
			return strDeviceMemoryMap;
		}
		break;
		case TYPE_STATE_ALL_VALUESIZE:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + eCurPos * 0x10 + MEMORY5;
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
			return strDeviceMemoryMap;
		}
		break;
		case TPYE_STATE_VISION_LIVEBIT:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + MEMORY6; // 상하면 구분 없음
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
			return strDeviceMemoryMap;
		}
		break;
		// 온도 기록 준비
		case TPYE_STATE_TEMPERATURE:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + MEMORY7;
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
			return strDeviceMemoryMap;
		}
		break;
		// 온도 기록 요청
		case TPYE_STATE_TEMPERATURE_REQUEST:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + MEMORY8;
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
			return strDeviceMemoryMap;
		}
		// 현재 온도
		case TPYE_STATE_TEMPERATURE_SUB:
		{
			int nMemoryMapIndex = eSelectLine * 0x0100 + MEMORY9 + eHeaterNumber;
			strDeviceMemoryMap.Format(_T("%s%X"), PLC_MEMORY_PREFIX, nMemoryMapIndex);
		}
		break;
	}

	return strDeviceMemoryMap;
}

BOOL CTESTMACHINE_MXCOMPONENTDlg::AllClearPLCMemoryMap(int eSelectLine)
{
	BOOL result = TRUE;
	for (int nPosInfo = 0; nPosInfo < 2; nPosInfo++)
	{
		CString strDeviceInfo = MakeDeviceInfo(m_eSelectLine, nPosInfo, TYPE_STATE_PLC_SENDINSPECTION);

		long lRet = 0;
		long lValue = 0;

		if (m_pLPMXComponectPLCCtrl->SetLPMxComponenetPLCCtrlDevice(strDeviceInfo, lValue, &lRet) == FALSE)
			result = FALSE;
	}

	return result;
}

BOOL CTESTMACHINE_MXCOMPONENTDlg::ReadInspectionState(int& nStateFirst, int& nStateSecond)
{
	BOOL result = TRUE;

	long lRet = 0;
	long lReturnValue = 0;

	CString strDeviceInfo = MakeDeviceInfo(m_eSelectLine, 0, TYPE_STATE_VISION_SENDINSPECTION);
	if (m_pLPMXComponectPLCCtrl->GetLPMxComponenetPLCCtrlDevice(strDeviceInfo, &lReturnValue, &lRet))
		nStateFirst = lReturnValue;
	else
		result = FALSE;

	strDeviceInfo = MakeDeviceInfo(m_eSelectLine, 1, TYPE_STATE_VISION_SENDINSPECTION);
	if (m_pLPMXComponectPLCCtrl->GetLPMxComponenetPLCCtrlDevice(strDeviceInfo, &lReturnValue, &lRet))
		nStateSecond = lReturnValue;
	else
		result = FALSE;

	return result;
}

BOOL CTESTMACHINE_MXCOMPONENTDlg::ReadyInspection()
{
	BOOL result = TRUE;

	for (int nPosInfo = 0; nPosInfo < 2; nPosInfo++)
	{
		CString strDeviceInfo = MakeDeviceInfo(m_eSelectLine, nPosInfo, TYPE_STATE_PLC_SENDINSPECTION);

		long lRet = 0;
		long lValue = 0;

		if (m_pLPMXComponectPLCCtrl->SetLPMxComponenetPLCCtrlDevice(strDeviceInfo, lValue, &lRet) == FALSE || lRet != 0)
			result = FALSE;

		/// W2, W3, W4, W5 초기화
		strDeviceInfo = MakeDeviceInfo(m_eSelectLine, nPosInfo, TYPE_STATE_ALL_RESULTSIZE);
		m_pLPMXComponectPLCCtrl->SetLPMxComponenetPLCCtrlDevice(strDeviceInfo, 0, &lRet);
		strDeviceInfo = MakeDeviceInfo(m_eSelectLine, nPosInfo, TYPE_STATE_ALL_RESULTSHAPE);
		m_pLPMXComponectPLCCtrl->SetLPMxComponenetPLCCtrlDevice(strDeviceInfo, 0, &lRet);
		strDeviceInfo = MakeDeviceInfo(m_eSelectLine, nPosInfo, TYPE_STATE_ALL_AVERAGESIZE);
		m_pLPMXComponectPLCCtrl->SetLPMxComponenetPLCCtrlDevice(strDeviceInfo, 0, &lRet);
		strDeviceInfo = MakeDeviceInfo(m_eSelectLine, nPosInfo, TYPE_STATE_ALL_VALUESIZE);
		m_pLPMXComponectPLCCtrl->SetLPMxComponenetPLCCtrlDevice(strDeviceInfo, 0, &lRet);
	}

	if (result == TRUE)
	{
		m_nSampleFirstCount++;
		GetDlgItem(IDC_EDIT_FIRSTCAMERA)->SetWindowText(_T("First Camera Inspection End"));
		m_nSampleSecondCount++;
		GetDlgItem(IDC_EDIT_SECONDCAMERA)->SetWindowText(_T("Second Camera Inspection End"));

		m_eStatePLC = TYPE_STATE_PLC_MOVING;
	}

	return result;
}

BOOL CTESTMACHINE_MXCOMPONENTDlg::StartInspection()
{
	BOOL result = TRUE;

	for (int nPosInfo = 0; nPosInfo < 2; nPosInfo++)
	{
		CString strDeviceInfo = MakeDeviceInfo(m_eSelectLine, nPosInfo, TYPE_STATE_PLC_SENDINSPECTION);
		
		long lRet = 0;
		long lValue = 1;

		/*if (m_bStartFlag == TRUE && nPosInfo == 1){
			m_bStartFlag = FALSE;
		}
		else{
			if (m_pLPMXComponectPLCCtrl->SetLPMxComponenetPLCCtrlDevice(strDeviceInfo, lValue, &lRet) == FALSE)
				result = FALSE;
		}*/

		if (m_pLPMXComponectPLCCtrl->SetLPMxComponenetPLCCtrlDevice(strDeviceInfo, lValue, &lRet) == FALSE)
			result = FALSE;
	}

	if (result == TRUE)
	{
		m_nSampleFirstCount++;
		GetDlgItem(IDC_EDIT_FIRSTCAMERA)->SetWindowText(_T("First Camera Inspection Start"));
		m_nSampleSecondCount++;
		GetDlgItem(IDC_EDIT_SECONDCAMERA)->SetWindowText(_T("Second Camera Inspection Start"));

		m_eStatePLC = TYPE_STATE_PLC_WAITING_INSPECTION;
	}

	return result;
}

void CTESTMACHINE_MXCOMPONENTDlg::UpdateConnectState(BOOL bConnect)
{
	GetDlgItem(IDC_BTN_OPENCOM)->EnableWindow(!bConnect);
	GetDlgItem(IDC_BTN_CLOSECOM)->EnableWindow(bConnect);

	//GetDlgItem(IDC_IPADDRESS)->EnableWindow(!bConnect);
	//GetDlgItem(IDC_EDIT_PORT)->EnableWindow(!bConnect);
	//GetDlgItem(IDC_COMBO_PROTOCOL)->EnableWindow(!bConnect);
	//GetDlgItem(IDC_COMBO_TYPE)->EnableWindow(!bConnect);

	GetDlgItem(IDC_ED_STATIONNUM)->EnableWindow(!bConnect);
	GetDlgItem(IDC_RDO_LINE1)->EnableWindow(!bConnect);
	GetDlgItem(IDC_RDO_LINE2)->EnableWindow(!bConnect);

	if (FALSE == bConnect)
	{
		GetDlgItem(IDC_BTN_START)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_STOP)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_BTN_START)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_STOP)->EnableWindow(FALSE);
	}

	//GetDlgItem(IDC_COMBO_PROTOCOL)->EnableWindow(FALSE);	// TCP ONLY
}

void CTESTMACHINE_MXCOMPONENTDlg::UpdateStartState(BOOL bStart)
{
	GetDlgItem(IDC_BTN_START)->EnableWindow(!bStart);
	GetDlgItem(IDC_BTN_STOP)->EnableWindow(bStart);
	GetDlgItem(IDC_CHECK_SKIP_SECOND)->EnableWindow(!bStart);
}

BOOL CTESTMACHINE_MXCOMPONENTDlg::InspectFirstCamera()
{
	BOOL bResult = RunInspect(TYPE_POS_FIRST);

	if (bResult)
		CUtil::PrintDebugString(_T("Start inspection (First)  \r\n"));
	else
		CUtil::PrintDebugString(_T("Fail to start inspection (First)  \r\n"));

	return bResult;
}

BOOL CTESTMACHINE_MXCOMPONENTDlg::InspectSecondCamera()
{ 
	BOOL bResult = RunInspect(TYPE_POS_SECOND);

	if (bResult)
		CUtil::PrintDebugString(_T("Start inspection (Second)  \r\n"));
	else
		CUtil::PrintDebugString(_T("Fail to start inspection (Second)  \r\n"));

	return bResult;
}

BOOL CTESTMACHINE_MXCOMPONENTDlg::RunInspect(TYPE_POS eCameraPos)
{
	long nRet = 0;
	BOOL bResult = FALSE;
	if (TYPE_POS_FIRST == eCameraPos || TYPE_POS_SECOND == eCameraPos)
	{
		if (m_pLPMXComponectPLCCtrl && m_pLPMXComponectPLCCtrl->GetPLCControlOpen())
		{
			m_eActionState = TYPE_STATE_PLC_SENDINSPECTION;
			CString strDeviceInfo = MakeDeviceInfo(m_eSelectLine, eCameraPos, m_eActionState);
			bResult = m_pLPMXComponectPLCCtrl->SetLPMxComponenetPLCCtrlDevice(strDeviceInfo, 1, &nRet);

			if (!bResult)
				CUtil::PrintDebugString(_T("Fail to Start Inspection (Send Error) \r\n"));
		}
	}
	else
	{
		CUtil::PrintDebugString(_T("Fail to Start Inspection (Known Camera)  \r\n"));
		return FALSE;
	}

	return bResult;
}

void CTESTMACHINE_MXCOMPONENTDlg::OnDestroy()
{
	__super::OnDestroy();

	long lRet;
	if (m_pLPMXComponectPLCCtrl)
	{
		if (m_pLPMXComponectPLCCtrl->GetPLCControlOpen())
		{
			//KillTimer(TIMERID_VISIONKEEPALIVE);
			m_pLPMXComponectPLCCtrl->CloseLPMxComponenetPLCCtrl(&lRet);
		}

		m_pLPMXComponectPLCCtrl->ReleaseLPMxComponenetPLCCtrl();
		delete m_pLPMXComponectPLCCtrl;
	}
	m_pLPMXComponectPLCCtrl = NULL;
}

void CTESTMACHINE_MXCOMPONENTDlg::UpdateMessage(TCHAR* pszMessage)
{
	if (NULL == pszMessage)
		return;

	GetDlgItem(IDC_STATIC_MSG)->SetWindowText(pszMessage);
}


void CTESTMACHINE_MXCOMPONENTDlg::OnBnClickedRdoLine1()
{
	UpdateData(TRUE);

	m_eSelectLine = TYPE_LINE_1;

	UpdateData(FALSE);
}


void CTESTMACHINE_MXCOMPONENTDlg::OnBnClickedRdoLine2()
{
	UpdateData(TRUE);

	m_eSelectLine = TYPE_LINE_2;

	UpdateData(FALSE);
}


BOOL CTESTMACHINE_MXCOMPONENTDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct)
{
#ifdef USE_PLC_COPYDATA
#endif

	return __super::OnCopyData(pWnd, pCopyDataStruct);
}

void CTESTMACHINE_MXCOMPONENTDlg::CheckTemperatureState(int nTimerCounter, long lTemperature){

	CString strDeviceInfo = MakeDeviceInfo(m_eSelectLine, TYPE_POS_FIRST, TPYE_STATE_TEMPERATURE);
	long lRet = 0;
	long lReturnValue = 0;

	m_pLPMXComponectPLCCtrl->GetLPMxComponenetPLCCtrlDevice(strDeviceInfo, &lReturnValue, &lRet);

	if (lReturnValue == 1){
		strDeviceInfo = MakeDeviceInfo(m_eSelectLine, TYPE_POS_FIRST, TPYE_STATE_TEMPERATURE_REQUEST);
		m_pLPMXComponectPLCCtrl->SetLPMxComponenetPLCCtrlDevice(strDeviceInfo, 0, &lRet);
	}
	else if (lReturnValue == 0 && nTimerCounter == 0)
	{
		for (int i = 0; i < PLC_HEATER_MAX; i++)
		{
			//Line1
			lRet = 0;
			strDeviceInfo = MakeDeviceInfo(0, TYPE_POS_FIRST, TPYE_STATE_TEMPERATURE_SUB, i);
			m_pLPMXComponectPLCCtrl->SetLPMxComponenetPLCCtrlDevice(strDeviceInfo, lTemperature, &lRet);

			//Line2
			strDeviceInfo = MakeDeviceInfo(1, TYPE_POS_FIRST, TPYE_STATE_TEMPERATURE_SUB, i);
			m_pLPMXComponectPLCCtrl->SetLPMxComponenetPLCCtrlDevice(strDeviceInfo, lTemperature + 100, &lRet);
		}

		strDeviceInfo = MakeDeviceInfo(m_eSelectLine, TYPE_POS_FIRST, TPYE_STATE_TEMPERATURE_REQUEST);
		m_pLPMXComponectPLCCtrl->SetLPMxComponenetPLCCtrlDevice(strDeviceInfo, 1, &lRet);
	}
}

DWORD CTESTMACHINE_MXCOMPONENTDlg::ThreadCommPLC(LPVOID pArg)
{
	if (NULL == pArg)
		return FALSE;
	CUtil::PrintDebugString(_T("[%d] ThreadCommSerial \r\n"), ::GetTickCount());
	TCHAR szMessage[MAX_TEXT_LEN] = { 0, };

	CTESTMACHINE_MXCOMPONENTDlg* pDlg = (CTESTMACHINE_MXCOMPONENTDlg*)pArg;

	int nTimerCounter = 0;
	long lTemperature = 0;
	do
	{
		if (pDlg->m_pLPMXComponectPLCCtrl && pDlg->m_pLPMXComponectPLCCtrl->GetPLCControlOpen())
		{
			if (pDlg->m_eStatePLC == TYPE_STATE_PLC_WAITING_INSPECTION ||
				pDlg->m_eStatePLC == TYPE_STATE_PLC_WAITING_READY)
			{
				int nStateFirst = -1;
				int nStateSecond = -1;
				if (pDlg->ReadInspectionState(nStateFirst, nStateSecond) == FALSE)
					continue;

				if (pDlg->m_eStatePLC == TYPE_STATE_PLC_WAITING_INSPECTION && nStateFirst == 2 && nStateSecond == 2)
				{
					if (pDlg->ReadyInspection() == TRUE)
						CUtil::Sleep(1000);
				}
				else if (pDlg->m_eStatePLC == TYPE_STATE_PLC_WAITING_READY && nStateFirst == 0 && nStateSecond == 0)
				{
					pDlg->StartInspection();
				}
			}
			else if (pDlg->m_eStatePLC == TYPE_STATE_PLC_MOVING)
			{
				pDlg->m_eStatePLC = TYPE_STATE_PLC_WAITING_READY;
			}
		}
		
		//온도 로그
		pDlg->CheckTemperatureState(nTimerCounter, lTemperature);
		nTimerCounter++;

		if (nTimerCounter >= 120){
			if (lTemperature++ >= 100){
				lTemperature = 0;
			}
			nTimerCounter = 0;
		}

		CUtil::Sleep(20);
	} while (pDlg->m_bStart != FALSE);

	return 0;
}