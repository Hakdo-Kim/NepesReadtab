
// NEPES.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CNEPESApp:
// See NEPES.cpp for the implementation of this class
//

class CNEPESApp : public CWinApp
{
public:
	CNEPESApp();

protected:
	HANDLE		 m_hMutex;

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CNEPESApp theApp;