
// LPMXComponentNetPassDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LPMXComponentNetPass.h"
#include "LPMXComponentNetPassDlg.h"
#include "afxdialogex.h"
#include "LPMxComponentPLCCtrl.h"

#include "Util/Util.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//COPYDATASTRUCT gLPMxComponentDS;

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


// CLPMXComponentNetPassDlg dialog

CLPMXComponentNetPassDlg::CLPMXComponentNetPassDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLPMXComponentNetPassDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	::InitializeCriticalSection(&m_CriticalSection);

	m_hTargetWnd = NULL;
	m_pLPMXComponectPLCCtrl = NULL;
	m_lCpuCode = 0;
	m_nProtocolType = PLC_DEFAULT_CONTROLTYPE;
	m_nControlType = PLC_DEFAULT_CONTROLTYPE;
	m_strHostAddress = _T("");
	m_nPortNum = 0;

	m_strGetDeviceName = _T("");
	m_strSetDeviceName = _T("");
	m_lSetValue = 0;

	m_nPLCStationNumber = PLC_DEFAULT_STATIONNUMBER;
	m_bFirstOpenCommunication = FALSE;
}

void CLPMXComponentNetPassDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLPMXComponentNetPassDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_WM_CLOSE()
	ON_WM_COPYDATA()
	ON_WM_TIMER()
END_MESSAGE_MAP()

BOOL CLPMXComponentNetPassDlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (IDOK == wParam)
	{
		return TRUE;
	}
	return CDialogEx::OnCommand(wParam, lParam);
}

BOOL CLPMXComponentNetPassDlg::PreTranslateMessage(MSG* pMsg)
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

// CLPMXComponentNetPassDlg message handlers
BOOL CLPMXComponentNetPassDlg::OnInitDialog()
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

	// TODO: Add extra initialization here

	ModifyStyleEx(WS_EX_APPWINDOW, WS_EX_TOOLWINDOW);

	////
	SetWindowText(TARGETWINDOWTITLE);

	m_hTargetWnd = ::FindWindow(NULL, NETPASSWINDOWTITLE);

	if (!m_pLPMXComponectPLCCtrl)
	{
		m_pLPMXComponectPLCCtrl = new CLPMxComponentPLCCtrl();
		if (!m_pLPMXComponectPLCCtrl->CreateLPMxComponenetPLCCtrl())
		{
			AfxMessageBox(_T("PLC MXComponent Object Create Fail !!!"));

			delete m_pLPMXComponectPLCCtrl;
			m_pLPMXComponectPLCCtrl = NULL;

			return FALSE;
		}
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLPMXComponentNetPassDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLPMXComponentNetPassDlg::OnPaint()
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
HCURSOR CLPMXComponentNetPassDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CLPMXComponentNetPassDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (TIMERID_CLOSEPROGRAM == nIDEvent)
	{
		KillTimer(TIMERID_CLOSEPROGRAM);
		OnClose();

		return;
	}

	CDialogEx::OnTimer(nIDEvent);
}

void CLPMXComponentNetPassDlg::OnDestroy()
{
	CDialogEx::OnDestroy();
}

void CLPMXComponentNetPassDlg::OnClose()
{
	long lRet;
	if (m_pLPMXComponectPLCCtrl)
	{
		if (m_pLPMXComponectPLCCtrl->GetPLCControlOpen())
			m_pLPMXComponectPLCCtrl->CloseLPMxComponenetPLCCtrl(&lRet);

		m_pLPMXComponectPLCCtrl->ReleaseLPMxComponenetPLCCtrl();
		delete m_pLPMXComponectPLCCtrl;
	}

	m_pLPMXComponectPLCCtrl = NULL;

	::DeleteCriticalSection(&m_CriticalSection);

	CDialogEx::OnOK();
}

BOOL CLPMXComponentNetPassDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct)
{
	UpdateData(TRUE);

	DWORD dw = 0;
	CString strReceiveMessage = _T("");
	CString strTraceMessage = _T("");
	m_LPMxComponentDS = *(PCOPYDATASTRUCT)pCopyDataStruct;

	switch (((stLPMXComponentCommnd*)(m_LPMxComponentDS.lpData))->nCommandType)
	{
		case TYPE_COMMAND_SETTING:
		{
			m_nProtocolType = ((stLPMXComponentCommnd*)(m_LPMxComponentDS.lpData))->nPLCProtocolType;
			m_nControlType = ((stLPMXComponentCommnd*)(m_LPMxComponentDS.lpData))->nPLCControlType;
			m_strHostAddress.Format(_T("%s"), ((stLPMXComponentCommnd*)(m_LPMxComponentDS.lpData))->szHostAddress);
			m_nPortNum = ((stLPMXComponentCommnd*)(m_LPMxComponentDS.lpData))->nPortNum;
			m_nPLCStationNumber = ((stLPMXComponentCommnd*)(m_LPMxComponentDS.lpData))->nPLCStationNumber;

#ifdef USE_MESSAGE_TRACE
			strReceiveMessage.Format(_T("TYPE_COMMAND_SETTING : Protocol : %d, Control : %d, StationNum : %d"), m_nProtocolType, m_nControlType, m_nPLCStationNumber);
#endif			
		}
		break;
		case TYPE_COMMAND_OPENCOM:
		{
#ifdef USE_MESSAGE_TRACE
			strReceiveMessage.Format(_T("TYPE_COMMAND_OPENCOM"));
#endif
			if (!m_hTargetWnd)
				m_hTargetWnd = ::FindWindow(NULL, NETPASSWINDOWTITLE);

			if (m_hTargetWnd)
			{
				BeginWaitCursor();

				if (!m_bFirstOpenCommunication)
				{
					OpenCommunication();
					Sleep(1);
					CloseCommunication();
					Sleep(1);
					OpenCommunication();
					Sleep(1);
					CloseCommunication();
					Sleep(1);
					OpenCommunication();
					Sleep(1);
					CloseCommunication();
					Sleep(1);

					m_bFirstOpenCommunication = TRUE;
				}
				OpenCommunication();

				EndWaitCursor();

				stLPMXComponentCommnd stComponenetCommand;
				stComponenetCommand.nCommandType = TYPE_COMMAND_OPENCOM;
				stComponenetCommand.bControlOpened = m_pLPMXComponectPLCCtrl->GetPLCControlOpen();

				m_LPMxComponentDS.dwData = NULL;
				m_LPMxComponentDS.cbData = sizeof(stComponenetCommand);
				m_LPMxComponentDS.lpData = &stComponenetCommand;

				//::SendMessage(m_hTargetWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)(LPVOID)&m_LPMxComponentDS);
				::SendMessageTimeout(m_hTargetWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)(LPVOID)&m_LPMxComponentDS, SMTO_NORMAL, TIMEOUT_MS, &dw);

#ifdef USE_MESSAGE_TRACE
				strTraceMessage.Format(_T("OpenCommunication : Open : %d"), m_pLPMXComponectPLCCtrl->GetPLCControlOpen());
#endif
			}
		}
		break;
		case TYPE_COMMAND_GETCPUTYPE:
		{
#ifdef USE_MESSAGE_TRACE
			strReceiveMessage.Format(_T("TYPE_COMMAND_GETCPUTYPE"));
#endif
			if (!m_hTargetWnd)
				m_hTargetWnd = ::FindWindow(NULL, NETPASSWINDOWTITLE);

			if (m_hTargetWnd)
			{
				CString strCpuName;
				long lCpuCode;
				long lRet;
				if (GetCPUType(&strCpuName, &lCpuCode, &lRet))
				{
					stLPMXComponentCommnd stComponenetCommand;
					stComponenetCommand.nCommandType = TYPE_COMMAND_GETCPUTYPE;
					memcpy(stComponenetCommand.szCpuName, strCpuName, strCpuName.GetLength());
					stComponenetCommand.lCpuCode = lCpuCode;
					stComponenetCommand.lRet = lRet;

					m_LPMxComponentDS.dwData = NULL;
					m_LPMxComponentDS.cbData = sizeof(stComponenetCommand);
					m_LPMxComponentDS.lpData = &stComponenetCommand;

					//::SendMessage(m_hTargetWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)(LPVOID)&m_LPMxComponentDS);
					::SendMessageTimeout(m_hTargetWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)(LPVOID)&m_LPMxComponentDS, SMTO_NORMAL, TIMEOUT_MS, &dw);

#ifdef USE_MESSAGE_TRACE
					strTraceMessage.Format(_T("GetCPUType : %s, %d, %d"), strCpuName, lCpuCode, lRet);
#endif
				}
			}
		}
		break;
		case TYPE_COMMAND_GETDEVICE:
		{
			CString strGetDeviceName = _T("");
			long lGetValue = 0;
			long lRet = 0;
			strGetDeviceName.Format(_T("%s"), ((stLPMXComponentCommnd*)(m_LPMxComponentDS.lpData))->szDeviceName);
			int nCurCameraPos = ((stLPMXComponentCommnd*)(m_LPMxComponentDS.lpData))->nCameraPos;
#ifdef USE_MESSAGE_TRACE
			strReceiveMessage.Format(_T("NEPES : TYPE_COMMAND_GETDEVICE : DeviceName : %s\\r\n"), strGetDeviceName);
			OutputDebugString(strReceiveMessage);
#endif		
			if (!m_hTargetWnd)
				m_hTargetWnd = ::FindWindow(NULL, NETPASSWINDOWTITLE);

			if (m_hTargetWnd)
			{
#ifdef USE_MESSAGE_TRACE
				strTraceMessage.Format(_T("NEPES : GetDevice Success 0: %s, %d, %d\r\n"), strGetDeviceName, lGetValue, lRet);
				OutputDebugString(strTraceMessage);
#endif
				if (GetDevice(strGetDeviceName, &lGetValue, &lRet))
				{
					stLPMXComponentCommnd stComponenetCommand;
					stComponenetCommand.nCommandType = TYPE_COMMAND_GETDEVICE;
					memcpy(stComponenetCommand.szDeviceName, strGetDeviceName, strGetDeviceName.GetLength());
					stComponenetCommand.lGetValue = lGetValue;
					stComponenetCommand.lRet = lRet;
					stComponenetCommand.nCameraPos = nCurCameraPos;

					m_LPMxComponentDS.dwData = NULL;
					m_LPMxComponentDS.cbData = sizeof(stComponenetCommand);
					m_LPMxComponentDS.lpData = &stComponenetCommand;
#ifdef USE_MESSAGE_TRACE
					strTraceMessage.Format(_T("NEPES : GetDevice Success 1: %s, %d, %d\r\n"), strGetDeviceName, lGetValue, lRet);
					OutputDebugString(strTraceMessage);
#endif

					//::SendMessage(m_hTargetWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)(LPVOID)&m_LPMxComponentDS);
					::SendMessageTimeout(m_hTargetWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)(LPVOID)&m_LPMxComponentDS, SMTO_NORMAL, TIMEOUT_MS, &dw);

#ifdef USE_MESSAGE_TRACE
					strTraceMessage.Format(_T("NEPES : GetDevice Success 2: %s, %d, %d\r\n"), strGetDeviceName, lGetValue, lRet);
					OutputDebugString(strTraceMessage);
#endif

#ifdef USE_MESSAGE_TRACE
					GetDlgItem(IDC_STC_RECEIVE)->SetWindowText(strReceiveMessage);
					GetDlgItem(IDC_STC_TRACE)->SetWindowText(strTraceMessage);
#endif
					UpdateData(FALSE);

					return CDialogEx::OnCopyData(pWnd, pCopyDataStruct);
				}
				else
				{
					strTraceMessage.Format(_T("NEPES : GetDevice Fail: %s, %d, %d\r\n"), strGetDeviceName, lGetValue, lRet);
					OutputDebugString(strTraceMessage);

					return CDialogEx::OnCopyData(pWnd, pCopyDataStruct);
				}
			}
		}
		break;
		case TYPE_COMMAND_SETDEVICE:
		{
			CString strSetDeviceName = _T("");
			long lSetValue = 0;
			long lRet = 0;
			strSetDeviceName.Format(_T("%s"), ((stLPMXComponentCommnd*)(m_LPMxComponentDS.lpData))->szDeviceName);
			lSetValue = ((stLPMXComponentCommnd*)(m_LPMxComponentDS.lpData))->lSetValue;
			int nCurCameraPos = ((stLPMXComponentCommnd*)(m_LPMxComponentDS.lpData))->nCameraPos;
#ifdef USE_MESSAGE_TRACE
			strReceiveMessage.Format(_T("NEPES : TYPE_COMMAND_SETDEVICE : DeviceName : %s, SetValue : %d\r\n"), strSetDeviceName, lSetValue);
			OutputDebugString(strReceiveMessage);
#endif
			if (!m_hTargetWnd)
				m_hTargetWnd = ::FindWindow(NULL, NETPASSWINDOWTITLE);

			if (m_hTargetWnd)
			{
#ifdef USE_MESSAGE_TRACE
				strTraceMessage.Format(_T("NEPES : SetDevice Success 0 : %s, %d, %d\r\n"), strSetDeviceName, lSetValue, lRet);
				OutputDebugString(strTraceMessage);
#endif
				if (SetDevice(strSetDeviceName, lSetValue, &lRet))
				{
					stLPMXComponentCommnd stComponenetCommand;
					stComponenetCommand.nCommandType = TYPE_COMMAND_SETDEVICE;
					memcpy(stComponenetCommand.szDeviceName, strSetDeviceName, strSetDeviceName.GetLength());
					stComponenetCommand.lSetValue = lSetValue;
					stComponenetCommand.lRet = lRet;
					stComponenetCommand.nCameraPos = nCurCameraPos;

					m_LPMxComponentDS.dwData = NULL;
					m_LPMxComponentDS.cbData = sizeof(stComponenetCommand);
					m_LPMxComponentDS.lpData = &stComponenetCommand;
#ifdef USE_MESSAGE_TRACE
					strTraceMessage.Format(_T("NEPES : SetDevice Success 1 : %s, %d, %d\r\n"), strSetDeviceName, lSetValue, lRet);
					OutputDebugString(strTraceMessage);
#endif
					//::SendMessage(m_hTargetWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)(LPVOID)&m_LPMxComponentDS);
					::SendMessageTimeout(m_hTargetWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)(LPVOID)&m_LPMxComponentDS, SMTO_NORMAL, TIMEOUT_MS, &dw);

#ifdef USE_MESSAGE_TRACE
					strTraceMessage.Format(_T("NEPES : SetDevice Success 2 : %s, %d, %d\r\n"), strSetDeviceName, lSetValue, lRet);
					OutputDebugString(strTraceMessage);
#endif

#ifdef USE_MESSAGE_TRACE
					GetDlgItem(IDC_STC_RECEIVE)->SetWindowText(strReceiveMessage);
					GetDlgItem(IDC_STC_TRACE)->SetWindowText(strTraceMessage);
#endif
					UpdateData(FALSE);

					return CDialogEx::OnCopyData(pWnd, pCopyDataStruct);
				}
				else
				{
					strTraceMessage.Format(_T("NEPES : SetDevice Fail : %s, %d, %d\r\n"), strSetDeviceName, lSetValue, lRet);
					OutputDebugString(strReceiveMessage);

					return CDialogEx::OnCopyData(pWnd, pCopyDataStruct);
				}
			}
		}
		break;
		case TYPE_COMMAND_CLOSECOM:
		{
#ifdef USE_MESSAGE_TRACE
			strReceiveMessage.Format(_T("TYPE_COMMAND_CLOSECOM"));
#endif
			if (!m_hTargetWnd)
				m_hTargetWnd = ::FindWindow(NULL, NETPASSWINDOWTITLE);

			if (m_hTargetWnd)
			{
				CloseCommunication();

				stLPMXComponentCommnd stComponenetCommand;
				stComponenetCommand.nCommandType = TYPE_COMMAND_CLOSECOM;
				stComponenetCommand.bControlOpened = m_pLPMXComponectPLCCtrl->GetPLCControlOpen();

				m_LPMxComponentDS.dwData = NULL;
				m_LPMxComponentDS.cbData = sizeof(stComponenetCommand);
				m_LPMxComponentDS.lpData = &stComponenetCommand;

				//::SendMessage(m_hTargetWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)(LPVOID)&m_LPMxComponentDS);
				::SendMessageTimeout(m_hTargetWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)(LPVOID)&m_LPMxComponentDS, SMTO_NORMAL, TIMEOUT_MS, &dw);

#ifdef USE_MESSAGE_TRACE
				strTraceMessage.Format(_T("CloseCommunication : Close : %d"), m_pLPMXComponectPLCCtrl->GetPLCControlOpen());
#endif	
			}
		}
		break;
		case TYPE_COMMAND_CLOSEPROGRAM:
		{
			CloseProgram();
#ifdef USE_MESSAGE_TRACE
			strReceiveMessage.Format(_T("TYPE_COMMAND_CLOSEPROGRAM"));
#endif
		}
		break;
		case TYPE_COMMAND_WINDOWSHOWHIDE:
		{
			WindowShowHide(((stLPMXComponentCommnd*)(m_LPMxComponentDS.lpData))->bWindowShow);
#ifdef USE_MESSAGE_TRACE
			strReceiveMessage.Format(_T("TYPE_COMMAND_WINDOWSHOWHIDE"));
#endif
		}
		break;
	}

#ifdef USE_MESSAGE_TRACE
	GetDlgItem(IDC_STC_RECEIVE)->SetWindowText(strReceiveMessage);
	GetDlgItem(IDC_STC_TRACE)->SetWindowText(strTraceMessage);
#endif

	UpdateData(FALSE);

	return CDialogEx::OnCopyData(pWnd, pCopyDataStruct);
}

BOOL  CLPMXComponentNetPassDlg::OpenCommunication()
{
	long lRet;

	if (!m_pLPMXComponectPLCCtrl)
		return FALSE;

	m_pLPMXComponectPLCCtrl->SetPLCProtocolType(m_nProtocolType);
	m_pLPMXComponectPLCCtrl->SetPLCContorlType(m_nControlType);
	m_pLPMXComponectPLCCtrl->SetHostAddress(m_strHostAddress);
	m_pLPMXComponectPLCCtrl->SetLogicalStationNumber(m_nPLCStationNumber);

	BOOL bResult = m_pLPMXComponectPLCCtrl->OpenLPMxComponenetPLCCtrl(&lRet);
	if (!bResult)
	{
		//AfxMessageBox(_T("PLC Open Fail !!!  Check PLC Machine !!!"));

		return FALSE;
	}

	return TRUE;
}

BOOL  CLPMXComponentNetPassDlg::CloseCommunication()
{
	long lRet;
	if (m_pLPMXComponectPLCCtrl && m_pLPMXComponectPLCCtrl->GetPLCControlOpen())
		m_pLPMXComponectPLCCtrl->CloseLPMxComponenetPLCCtrl(&lRet);

	return TRUE;
}

BOOL  CLPMXComponentNetPassDlg::GetCPUType(CString* pstrCpuName, long*plCpuCode, long* plRet)
{
	if (!m_pLPMXComponectPLCCtrl)
		return FALSE;

	if (!m_pLPMXComponectPLCCtrl->GetLPMxComponenetPLCCtrlCPUType(pstrCpuName, plCpuCode, plRet))
		return FALSE;

	return TRUE;
}

BOOL  CLPMXComponentNetPassDlg::GetDevice(CString strDeviceName, long*plValue, long* plRet)
{
	if (!m_pLPMXComponectPLCCtrl)
		return FALSE;

	// EnterCriticalSection(&m_CriticalSection);

	if (!m_pLPMXComponectPLCCtrl->GetLPMxComponenetPLCCtrlDevice(strDeviceName, plValue, plRet))
	{
		//LeaveCriticalSection(&m_CriticalSection);

		return FALSE;
	}

	// LeaveCriticalSection(&m_CriticalSection);

	return TRUE;
}

BOOL  CLPMXComponentNetPassDlg::SetDevice(CString strDeviceName, long lValue, long* plRet)
{
	if (!m_pLPMXComponectPLCCtrl)
		return FALSE;

	//EnterCriticalSection(&m_CriticalSection);

	if (!m_pLPMXComponectPLCCtrl->SetLPMxComponenetPLCCtrlDevice(strDeviceName, lValue, plRet))
	{
		//LeaveCriticalSection(&m_CriticalSection);
		return FALSE;
	}

	//LeaveCriticalSection(&m_CriticalSection);

	return TRUE;
}

void CLPMXComponentNetPassDlg::CloseProgram()
{
	SetTimer(TIMERID_CLOSEPROGRAM, 100, NULL);
}

void CLPMXComponentNetPassDlg::WindowShowHide(BOOL bShow)
{
	ShowWindow(bShow);
}
