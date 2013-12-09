// Combol60.h : main header file for the COMBOL60 application
//

#if !defined(AFX_COMBOL60_H__83177253_040D_47A0_83B8_5BCC2F10B5DF__INCLUDED_)
#define AFX_COMBOL60_H__83177253_040D_47A0_83B8_5BCC2F10B5DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCombol60App:
// See Combol60.cpp for the implementation of this class
//

class CCombol60App : public CWinApp
{
public:
	CCombol60App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCombol60App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCombol60App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOL60_H__83177253_040D_47A0_83B8_5BCC2F10B5DF__INCLUDED_)
