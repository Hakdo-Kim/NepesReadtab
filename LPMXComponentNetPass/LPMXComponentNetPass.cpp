
// LPMXComponentNetPass.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "LPMXComponentNetPass.h"
#include "LPMXComponentNetPassDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLPMXComponentNetPassApp

BEGIN_MESSAGE_MAP(CLPMXComponentNetPassApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CLPMXComponentNetPassApp construction

CLPMXComponentNetPassApp::CLPMXComponentNetPassApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	m_hMutex = NULL;
}


// The one and only CLPMXComponentNetPassApp object

CLPMXComponentNetPassApp theApp;


// CLPMXComponentNetPassApp initialization

BOOL CLPMXComponentNetPassApp::InitInstance()
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

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	{
		m_hMutex = CreateMutex(NULL, TRUE, _T("LaonPeople LPMXCOMPONENT"));
		if (ERROR_ALREADY_EXISTS == GetLastError())
		{
			//::MessageBox(NULL, _T("LaonPeople LPMXCOMPONENT Running..."), _T("LPMXCOMPONENT"), MB_OK | MB_ICONWARNING);

			ReleaseMutex(m_hMutex);
			return FALSE;
		}
	}

	CWinApp::InitInstance();

	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	/***************************************************/
	/* Initialize OLE Library                         */
	if (!AfxOleInit())
	{
		AfxMessageBox("AfxOleInit() Failed.");
		return FALSE;
	}
	/***************************************************/

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

	CLPMXComponentNetPassDlg dlg;
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

