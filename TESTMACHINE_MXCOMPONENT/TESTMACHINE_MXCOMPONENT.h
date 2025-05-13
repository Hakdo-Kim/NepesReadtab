
// TESTMACHINE_MXCOMPONENT.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CTESTMACHINE_MXCOMPONENTApp:
// See TESTMACHINE_MXCOMPONENT.cpp for the implementation of this class
//

class CTESTMACHINE_MXCOMPONENTApp : public CWinApp
{
public:
	CTESTMACHINE_MXCOMPONENTApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CTESTMACHINE_MXCOMPONENTApp theApp;