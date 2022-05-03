
// EarthOrbit.h : main header file for the EarthOrbit application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CEarthOrbitApp:
// See EarthOrbit.cpp for the implementation of this class
//

class CEarthOrbitApp : public CWinApp
{
public:
	CEarthOrbitApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CEarthOrbitApp theApp;
