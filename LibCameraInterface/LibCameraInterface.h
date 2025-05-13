// LibCameraInterface.h : main header file for the LibCameraInterface DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CLibCameraInterfaceApp
// See LibCameraInterface.cpp for the implementation of this class
//

class CLibCameraInterfaceApp : public CWinApp
{
public:
	CLibCameraInterfaceApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
