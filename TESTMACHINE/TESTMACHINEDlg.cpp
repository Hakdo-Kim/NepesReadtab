
// TESTMACHINEDlg.cpp : implementation file
//

#include "stdafx.h"
#include "afxdialogex.h"

#include "TESTMACHINE.h"
#include "TESTMACHINEDlg.h"

#include "Common.h"
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


// CTESTMACHINEDlg dialog

BOOL CTESTMACHINEDlg::FuncNotifyEthernetListener(DWORD dwListener, void* pArg)
{
	if (NULL == pArg)
		return FALSE;
	CTESTMACHINEDlg* pDlg = (CTESTMACHINEDlg*)pArg;

	const BOOL bStarted = pDlg->IsStarted();
	if (bStarted)
	{
		CEthernetClient* pEthernetClient = dynamic_cast<CEthernetClient*>(pDlg->m_pCommunicate);
		if (NULL == pEthernetClient)		// Server
		{
			CEthernetServer* pEthernetServer = dynamic_cast<CEthernetServer*>(pDlg->m_pCommunicate);
			if (pEthernetServer)
			{
				pEthernetClient = pEthernetServer->GetConnectedClinet(0);
			}
		}

		if (pEthernetClient)
		{
			TCHAR szMessage[MAX_TEXT_LEN] = { 0, };
			const TCHAR* pszInput = pEthernetClient->GetInputString();

			CUtil::StringCopy(szMessage, pszInput);
			if (CUtil::StringSearch(szMessage, _T("AT+ALARM")))
			{
				pDlg->UpdateMessage(_T("ALARM MESSAMGE"));
			}
			else
			{
				const BOOL bSkipSecond = pDlg->IsSkipSecondCamera();

				const int nCameraIdx = pDlg->ParseResultInspect(szMessage);
				if (TRUE == bSkipSecond && pDlg->FIRSTCAMERA == nCameraIdx ||
					FALSE == bSkipSecond && pDlg->SECONDCAMERA == nCameraIdx)
				{
					BYTE pReqBuf[128] = { 0, };
					int nReqLen = 128;
					BYTE pResBuf[128] = { 0, };
					int nResLen = 128;

					CUtil::StringFormat((TCHAR*)pReqBuf, 128, _T("AT+COUNT=A%d,B%d\r\n"), pDlg->m_nSampleACount, pDlg->m_nSampleBCount);
					nReqLen = CUtil::StringLength((TCHAR*)pReqBuf);
					pEthernetClient->SendCommand(pReqBuf, nReqLen, pResBuf, nResLen);
					
					if (pDlg->m_nCassetteCount <= pDlg->m_nSampleBCount && pDlg->m_nCassetteCount <= pDlg->m_nSampleBCount)
					{
						CUtil::StringFormat((TCHAR*)pReqBuf, 128, _T("AT+MOVE\r\n"));
						nReqLen = CUtil::StringLength((TCHAR*)pReqBuf);
						pEthernetClient->SendCommand(pReqBuf, nReqLen, pResBuf, nResLen);

						pDlg->m_nSampleACount = 0;
						pDlg->m_nSampleBCount = 0;
					}
				}
			}
		}
	}
	else
	{
		CUtil::PrintDebugString(_T("not started skiped message \r\n"));
	}
	return TRUE;
}



CTESTMACHINEDlg::CTESTMACHINEDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTESTMACHINEDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pCommunicate = NULL;
	
	m_bStart = FALSE;
	m_nInspectionCount = 0;

	m_nCassetteCount = 50;
	m_nSampleACount = 0;
	m_nSampleBCount = 0;

	//
	m_eCurPos = TYPE_POS_NONE;
	m_eCurShape = TYPE_SHAPE_NONE;

}

void CTESTMACHINEDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IPADDRESS, m_ctlIpAddress);
	DDX_Control(pDX, IDC_EDIT_PORT, m_ctlPort);
	DDX_Control(pDX, IDC_COMBO_PROTOCOL, m_ctlProtocol);
	DDX_Control(pDX, IDC_COMBO_TYPE, m_ctlType);
}

BOOL CTESTMACHINEDlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (IDOK == wParam)
	{
		return TRUE;
	}
	return CDialogEx::OnCommand(wParam, lParam);
}

BOOL CTESTMACHINEDlg::PreTranslateMessage(MSG* pMsg)
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


BOOL CTESTMACHINEDlg::OnInitDialog()
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

	//
	m_ctlIpAddress.SetWindowText(_T("127.0.0.1"));
	m_ctlPort.SetWindowText(_T("5000"));

	m_ctlProtocol.AddString(_T("TCP"));
	m_ctlProtocol.AddString(_T("UDP"));
	m_ctlProtocol.SetCurSel(0);
	m_ctlProtocol.EnableWindow(FALSE);

	m_ctlType.AddString(_T("CLIENT"));
	m_ctlType.AddString(_T("SERVER"));
	m_ctlType.SetCurSel(0);

	
	CString szCount;
	szCount.Format(_T("%d"), m_nCassetteCount);
	GetDlgItem(IDC_EDIT_CASSETTECOUNT)->SetWindowText(szCount);


	UpdateConnectState(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

BEGIN_MESSAGE_MAP(CTESTMACHINEDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BTN_CONNECT, &CTESTMACHINEDlg::OnBnClickedBtnConnect)
	ON_BN_CLICKED(IDC_BTN_DISCONNECT, &CTESTMACHINEDlg::OnBnClickedBtnDisconnect)
	ON_BN_CLICKED(IDC_BTN_START, &CTESTMACHINEDlg::OnBnClickedBtnStart)
	ON_BN_CLICKED(IDC_BTN_STOP, &CTESTMACHINEDlg::OnBnClickedBtnStop)
END_MESSAGE_MAP()


// CTESTMACHINEDlg message handlers


void CTESTMACHINEDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTESTMACHINEDlg::OnPaint()
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
HCURSOR CTESTMACHINEDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CTESTMACHINEDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (TIMERID_FIRST == nIDEvent)
	{
		this->KillTimer(TIMERID_FIRST);
		InspectFirstCamera();
	}

	if (TIMERID_SECOND == nIDEvent)
	{
		this->KillTimer(TIMERID_SECOND);

		const int nSize = (int)m_SecondCameraQueue.size();
		if (0 < nSize)
		{
			INFO_SAMPLE* pSample = m_SecondCameraQueue.front();
			if (pSample && FALSE == pSample->m_stSecond.m_bDoneInspect && FALSE == pSample->m_stSecond.m_bInspecting)
			{
				InspectSecondCamera();
			}
		}
	}

}

void CTESTMACHINEDlg::OnClose()
{
	OnBnClickedBtnDisconnect();
	CDialogEx::OnOK();
}

void CTESTMACHINEDlg::OnBnClickedBtnConnect()
{
	CString szIpAddr;
	CString szPort;
	CString szProtocol;
	CString szType;

	GetDlgItem(IDC_IPADDRESS)->GetWindowText(szIpAddr);
	GetDlgItem(IDC_EDIT_PORT)->GetWindowText(szPort);
	GetDlgItem(IDC_COMBO_PROTOCOL)->GetWindowText(szProtocol);
	GetDlgItem(IDC_COMBO_TYPE)->GetWindowText(szType);

	if (m_pCommunicate)
	{
		m_pCommunicate->Close();
		delete m_pCommunicate;
	}
	m_pCommunicate = NULL;


	if (_T("CLIENT") == szType)
	{
		m_pCommunicate = new CEthernetClient;
	}
	else if (_T("SERVER") == szType)
	{
		m_pCommunicate = new CEthernetServer;
	}
	else
	{
		AfxMessageBox(_T("Fail to connect..."));
		return;
	}

	if (NULL == m_pCommunicate)
	{
		AfxMessageBox(_T("Fail to connect..."));
		return;
	}

	BOOL bResult = m_pCommunicate->Open(szIpAddr, szPort, szProtocol, FuncNotifyEthernetListener, this);
	UpdateConnectState(bResult);

	if (FALSE == bResult)
	{
		delete m_pCommunicate;
		m_pCommunicate = NULL;

		AfxMessageBox(_T("Fail to connect..."));
	}

}

void CTESTMACHINEDlg::OnBnClickedBtnDisconnect()
{
	if (m_pCommunicate)
	{
		m_pCommunicate->Close();
		delete m_pCommunicate;
	}
	m_pCommunicate = NULL;

	UpdateConnectState(FALSE);
	this->ClearQueue();
}

void CTESTMACHINEDlg::OnBnClickedBtnStart()
{
	m_nInspectionCount = 0;
	ClearQueue();

	BOOL bStart = InspectFirstCamera();
	if (bStart)
	{
		CString szCount;
		GetDlgItem(IDC_EDIT_CASSETTECOUNT)->GetWindowText(szCount);
		m_nCassetteCount = CUtil::StringToInt((LPTSTR)(LPCTSTR)szCount, szCount.GetLength());

		UpdateStartState(TRUE);
		m_bStart = TRUE;
	}
	else
	{
		AfxMessageBox(_T("Fail to start..."));
	}
}

void CTESTMACHINEDlg::OnBnClickedBtnStop()
{
	this->KillTimer(TIMERID_FIRST);		// Second Camera Check Timer
	this->KillTimer(TIMERID_SECOND);	// Second Camera Check Timer

	UpdateStartState(FALSE);
	m_bStart = FALSE;
	
}


const BOOL CTESTMACHINEDlg::IsStarted()
{
	return m_bStart;
}

void CTESTMACHINEDlg::UpdateConnectState(BOOL bConnect)
{
	GetDlgItem(IDC_BTN_CONNECT)->EnableWindow(!bConnect);
	GetDlgItem(IDC_BTN_DISCONNECT)->EnableWindow(bConnect);

	GetDlgItem(IDC_IPADDRESS)->EnableWindow(!bConnect);
	GetDlgItem(IDC_EDIT_PORT)->EnableWindow(!bConnect);
	GetDlgItem(IDC_COMBO_PROTOCOL)->EnableWindow(!bConnect);
	GetDlgItem(IDC_COMBO_TYPE)->EnableWindow(!bConnect);

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
	GetDlgItem(IDC_COMBO_PROTOCOL)->EnableWindow(FALSE);	// TCP ONLY
}

void CTESTMACHINEDlg::UpdateStartState(BOOL bStart)
{
	GetDlgItem(IDC_BTN_START)->EnableWindow(!bStart);
	GetDlgItem(IDC_BTN_STOP)->EnableWindow(bStart);

	GetDlgItem(IDC_CHECK_SKIP_SECOND)->EnableWindow(!bStart);
}


void CTESTMACHINEDlg::ClearQueue()
{
	INFO_SAMPLE* pInfo = NULL;

	// First Queue
	int nCount = (int)m_FirstCameraQueue.size();
	for (int i = 0; i < nCount; i++)
	{
		pInfo = m_FirstCameraQueue.front();
		m_FirstCameraQueue.pop();

		if (pInfo)
			delete pInfo;
	}
	m_FirstCameraQueue.empty();


	// Second Queue
	nCount = (int)m_SecondCameraQueue.size();
	for (int i = 0; i < nCount; i++)
	{
		pInfo = m_SecondCameraQueue.front();
		m_SecondCameraQueue.pop();

		if (pInfo)
			delete pInfo;
	}
	m_SecondCameraQueue.empty();

}


BOOL CTESTMACHINEDlg::InspectFirstCamera()
{
	m_nInspectionCount++;

	INFO_SAMPLE* pSample = new INFO_SAMPLE;
	memset(pSample, 0x00, sizeof(INFO_SAMPLE));
	pSample->m_nIndex = m_nInspectionCount;

	if (pSample->m_nIndex % 2)
		pSample->m_eShape = TYPE_SHAPE_A;
	else
		pSample->m_eShape = TYPE_SHAPE_B;

	///
	m_eCurPos = TYPE_POS_FIRST;
	m_eCurShape = pSample->m_eShape;
	//*/

	m_FirstCameraQueue.push(pSample);

	// Send Command 
	BOOL bResult = RunInspect(FIRSTCAMERA);
	pSample->m_stFirst.m_bInspecting = bResult;
	if (bResult)
	{
		CUtil::PrintDebugString(_T("Start inspection (First %d)  \r\n"), pSample->m_nIndex);
	}
	else
	{
		CUtil::PrintDebugString(_T("Fail to start inspection (First)  \r\n"));
	}

	return bResult;
}

void CTESTMACHINEDlg::InspectSecondCamera()
{
	const int nCount = (int)m_SecondCameraQueue.size();
	if (1 > nCount)
	{
		CUtil::PrintDebugString(_T("Fail to start inspection (Second, no sample)  \r\n"));
		return;
	}

	INFO_SAMPLE* pSample = m_SecondCameraQueue.front();

	///
	m_eCurPos = TYPE_POS_SECOND;
	m_eCurShape = pSample->m_eShape;
	//*/

	// Send Command 
	BOOL bResult = RunInspect(SECONDCAMERA);
	pSample->m_stSecond.m_bInspecting = bResult;
	if (bResult)
	{
		CUtil::PrintDebugString(_T("Start inspection (Second %d)  \r\n"), pSample->m_nIndex);
	}
	else
	{
		CUtil::PrintDebugString(_T("Fail to start inspection (Second)  \r\n"));
	}
}


BOOL CTESTMACHINEDlg::RunInspect(int nIdx)	// 0: First Camera, 1: Second Camera
{
	TYPE_SHAPE eShape = TYPE_SHAPE_NONE;

	if (FIRSTCAMERA == nIdx)
	{
		INFO_SAMPLE* pSample = m_FirstCameraQueue.front();
		eShape = pSample->m_eShape;

		CString szMsg;
		szMsg.Format(_T("Start First Inspection (Sample:%d)"), pSample->m_nIndex);
		GetDlgItem(IDC_EDIT_FIRSTCAMERA)->SetWindowText(szMsg);
	}
	else if (SECONDCAMERA == nIdx)
	{
		INFO_SAMPLE* pSample = m_SecondCameraQueue.front();
		eShape = pSample->m_eShape;

		CString szMsg;
		szMsg.Format(_T("Start Second Inspection (Sample:%d)"), pSample->m_nIndex);
		GetDlgItem(IDC_EDIT_SECONDCAMERA)->SetWindowText(szMsg);
	}
	else
	{
		CUtil::PrintDebugString(_T("Fail to start inspection (Known Camera)  \r\n"));
		return FALSE;
	}

	// SendCommand: Start Inspection
	BOOL bResult = FALSE;
	{
		CEthernetClient* pEthernetClient = dynamic_cast<CEthernetClient*>(m_pCommunicate);
		if (NULL == pEthernetClient)		// Server
		{
			CEthernetServer* pEthernetServer = dynamic_cast<CEthernetServer*>(m_pCommunicate);
			if (pEthernetServer)
				pEthernetClient = pEthernetServer->GetConnectedClinet(0);
		}

		if (pEthernetClient)
		{
			BYTE pReqBuf[128] = { 0, };
			int nReqLen = 128;
			BYTE pResBuf[128] = { 0, };
			int nResLen = 128;

			if (TYPE_SHAPE_A == eShape)
				CUtil::StringFormat((TCHAR*)pReqBuf, 128, _T("AT+CAMERA=%dA\r\n"), nIdx);
			else if (TYPE_SHAPE_B == eShape)
				CUtil::StringFormat((TCHAR*)pReqBuf, 128, _T("AT+CAMERA=%dB\r\n"), nIdx);

			nReqLen = CUtil::StringLength((TCHAR*)pReqBuf);
			bResult = pEthernetClient->SendCommand(pReqBuf, nReqLen, pResBuf, nResLen);
			if (bResult)
			{
				///  do nothing...	// No Response
				/*// Check Respone Buffer
				bResult = CUtil::StringSearch((TCHAR*)pResBuf, _T("AT+OK"));
				if (FALSE == bResult)
				{
					CUtil::PrintDebugString(_T("Fail to start inspection (Response Error) \r\n"));
				}
				//*/
			}
			else
			{
				CUtil::PrintDebugString(_T("Fail to start inspection (Send Error) \r\n"));
			}
		}
		else
		{
			CUtil::PrintDebugString(_T("Fail to start inspection (Not Connected) \r\n"));
		}
	}

	return bResult;
}


int CTESTMACHINEDlg::ParseResultInspect(TCHAR* pszResponse)
{
	if (NULL == pszResponse)
	{
		CUtil::PrintDebugString(_T("Fail to parse result \r\n"));
		return -1;
	}
	const BOOL bSkipSecond = IsSkipSecondCamera();

	int nIdxCamera = -1;	// Camera Index

	BOOL bSize = FALSE;
	BOOL bShape = FALSE;
	BOOL bAlarm = FALSE;
	ParseResultInspect(pszResponse, nIdxCamera, bSize, bShape, bAlarm);
	
	if (FIRSTCAMERA == nIdxCamera)
	{
		const int nSize = m_FirstCameraQueue.size();
		if (1 > nSize)
		{
			GetDlgItem(IDC_EDIT_FIRSTCAMERA)->SetWindowText(_T("Error Message"));
			CUtil::PrintDebugString(_T("Error Result \r\n"));
			return -1;
		}


		INFO_SAMPLE* pstSample = m_FirstCameraQueue.front();
		m_FirstCameraQueue.pop();

		const int nSampleIdx = pstSample->m_nIndex;

		pstSample->m_stFirst.m_bDoneInspect = TRUE;
		pstSample->m_stFirst.m_bInspecting = FALSE;

		pstSample->m_stFirst.m_bSize = bSize;
		pstSample->m_stFirst.m_bShape = bShape;

#ifdef DEF_RUN2STEP
#else
		this->SetTimer(TIMERID_FIRST, MSEC_TIMER, NULL);
#endif
		if (FALSE == bSkipSecond)
		{
			m_SecondCameraQueue.push(pstSample);
#ifdef DEF_RUN2STEP
			if (TYPE_POS_FIRST == m_eCurPos && TYPE_SHAPE_A == m_eCurShape)
				this->SetTimer(TIMERID_FIRST, MSEC_TIMER, NULL);
			else if (TYPE_POS_FIRST == m_eCurPos && TYPE_SHAPE_B == m_eCurShape)
				this->SetTimer(TIMERID_SECOND, MSEC_TIMER, NULL);
#else
			this->SetTimer(TIMERID_SECOND, MSEC_TIMER, NULL);
#endif
		}
		else
		{
#ifdef DEF_RUN2STEP
			this->SetTimer(TIMERID_FIRST, MSEC_TIMER, NULL);
#endif
			if (pstSample->m_nIndex % 2)
				m_nSampleACount++;
			else
				m_nSampleBCount++;
			delete pstSample;

			if (bAlarm)
				UpdateMessage(_T("ALARAM ON MESSAMGE"));
			else
				UpdateMessage(_T("ALARAM OFF MESSAMGE"));

		}
		
		CString szMsg;
		szMsg.Format(_T("End First Inspection (Sample:%d)"), nSampleIdx);
		GetDlgItem(IDC_EDIT_FIRSTCAMERA)->SetWindowText(szMsg);

	}
	else if (SECONDCAMERA == nIdxCamera)
	{
		const int nSize = m_SecondCameraQueue.size();
		if (1 > nSize)
		{
			GetDlgItem(IDC_EDIT_FIRSTCAMERA)->SetWindowText(_T("Error Message"));
			CUtil::PrintDebugString(_T("Error Result \r\n"));
			return -1;
		}


		INFO_SAMPLE* pstSample = m_SecondCameraQueue.front();
		m_SecondCameraQueue.pop();

		pstSample->m_stSecond.m_bDoneInspect = TRUE;
		pstSample->m_stSecond.m_bInspecting = FALSE;

		pstSample->m_stSecond.m_bSize = bSize;
		pstSample->m_stSecond.m_bShape = bShape;

		CUtil::PrintDebugString(_T("\r\n    Sample [%d]\r\n"), pstSample->m_nIndex);

		CString szMsg;
		szMsg.Format(_T("End Second Inspection (Sample:%d)"), pstSample->m_nIndex);
		GetDlgItem(IDC_EDIT_SECONDCAMERA)->SetWindowText(szMsg);

		if(pstSample->m_nIndex % 2)
			m_nSampleACount++;
		else
			m_nSampleBCount++;

		delete pstSample;

		if (bAlarm)
			UpdateMessage(_T("ALARAM ON MESSAMGE"));
		else
			UpdateMessage(_T("ALARAM OFF MESSAMGE"));

#ifdef DEF_RUN2STEP
		if (TYPE_POS_SECOND == m_eCurPos && TYPE_SHAPE_A == m_eCurShape)
			this->SetTimer(TIMERID_SECOND, MSEC_TIMER, NULL);
		else if (TYPE_POS_SECOND == m_eCurPos && TYPE_SHAPE_B == m_eCurShape)
			this->SetTimer(TIMERID_FIRST, MSEC_TIMER, NULL);
#endif
	}

	return nIdxCamera;
	
}

void CTESTMACHINEDlg::ParseResultInspect(TCHAR* pszResponse, int& nIdxCamera, BOOL& bSize, BOOL& bShape, BOOL& bAlarm)
{
	const int nResLen = CUtil::StringLength(pszResponse);

	BOOL bFind = CUtil::StringSearch(pszResponse, _T("AT+RESULT="));
	if (FALSE == bFind || 10 > nResLen)
	{
		CUtil::PrintDebugString(_T("Fail to parse result \r\n"));
		return;
	}


	/// Check Response
	int idx = 10;
	int nPos = 0;
	// Camera Index
	bFind = CUtil::StringSearch(pszResponse + idx, _T(","), &nPos);
	if (bFind && nResLen > (idx+nPos))
	{
		TCHAR szTemp[16] = { 0, };
		CUtil::StringCopy(szTemp, pszResponse + idx, nPos);
		nIdxCamera = CUtil::StringToInt(szTemp, nPos);
		idx += (nPos + 1);
	}

	// Size
	bFind = CUtil::StringSearch(pszResponse + idx, _T(","), &nPos);
	if (bFind && nResLen > (idx + nPos))
	{
		TCHAR szTemp[16] = { 0, };
		CUtil::StringCopy(szTemp, pszResponse + idx, nPos);
		if (CUtil::StringCompare(szTemp, _T("1")))
			bSize = TRUE;
		idx += (nPos + 1);
	}
	// bShape
	bFind = CUtil::StringSearch(pszResponse + idx, _T(","), &nPos);
	if (bFind && nResLen > (idx + nPos))
	{
		TCHAR szTemp[16] = { 0, };
		CUtil::StringCopy(szTemp, pszResponse + idx, nPos);
		if (CUtil::StringCompare(szTemp, _T("1")))
			bShape = TRUE;
		idx += (nPos + 1);
	}
	// Alaram
	bFind = CUtil::StringSearch(pszResponse + idx, _T("\r\n"), &nPos);
	if (bFind && nResLen > (idx + nPos))
	{
		TCHAR szTemp[16] = { 0, };
		CUtil::StringCopy(szTemp, pszResponse + idx, nPos);
		if (CUtil::StringCompare(szTemp, _T("2")))
			bAlarm = TRUE;
		idx += (nPos + 1);
	}
}

void CTESTMACHINEDlg::UpdateMessage(TCHAR* pszMessage)
{
	if (NULL == pszMessage)
		return;
	GetDlgItem(IDC_STATIC_MSG)->SetWindowText(pszMessage);
}

BOOL CTESTMACHINEDlg::IsSkipSecondCamera()
{
	BOOL bSkip = FALSE;
	if(BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_SKIP_SECOND))->GetCheck())
		bSkip = TRUE;
	return bSkip;
}