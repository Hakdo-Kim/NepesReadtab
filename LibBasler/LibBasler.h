// LibBasler.h : main header file for the LibBasler DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CLibBaslerApp
// See LibBasler.cpp for the implementation of this class
//

class CLibBaslerApp : public CWinApp
{
public:
	CLibBaslerApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
