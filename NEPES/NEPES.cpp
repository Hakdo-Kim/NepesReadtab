
// NEPES.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "NEPES.h"
#include "NEPESDlg.h"

#ifdef _DEBUG
#include "CrtDbgLeakCheck.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#ifdef _DEBUG
#define MEMORYLEAKCHECK
#endif

#ifdef MEMORYLEAKCHECK
#include "MemLeakDetect.h"
#endif

// CNEPESApp

BEGIN_MESSAGE_MAP(CNEPESApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CNEPESApp construction

CNEPESApp::CNEPESApp()
{
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance

	m_hMutex = NULL;
}


#ifdef MEMORYLEAKCHECK
CMemLeakDetect memLeakDetect;
#endif

// The one and only CNEPESApp object

CNEPESApp theApp;


// CNEPESApp initialization

BOOL CNEPESApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	{
		m_hMutex = CreateMutex(NULL, TRUE, _T("LaonPeople NEPES Program"));
		if (ERROR_ALREADY_EXISTS == GetLastError())
		{
			::MessageBox(NULL, _T("LaonPeople NEPES Program Running..."), _T("NEPES"), MB_OK | MB_ICONWARNING);

			ReleaseMutex(m_hMutex);
			return FALSE;
		}
	}
	CWinApp::InitInstance();

#ifdef _DEBUG
	// Disable Memory Leak Detection of MFC
	AfxEnableMemoryLeakDump(FALSE);
	// Enable CRTDBG Memory Leak Detection
	//EnableCrtDbgLeakCheck();
	EnableCrtDbgDumpObject();
#endif

	AfxEnableControlContainer();

	// Create the shell manager, in case the dialog contains
	// any shell tree view or shell list view controls.
	CShellManager *pShellManager = new CShellManager;

	// Activate "Windows Native" visual manager for enabling themes in MFC controls
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	CNEPESDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "Warning: dialog creation failed, so application is terminating unexpectedly.\n");
		TRACE(traceAppMsg, 0, "Warning: if you are using MFC controls on the dialog, you cannot #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}

	// Delete the shell manager created above.
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

