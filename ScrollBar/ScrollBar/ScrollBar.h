
// ScrollBar.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CScrollBarApp:
// �йش����ʵ�֣������ ScrollBar.cpp
//

class CScrollBarApp : public CWinApp
{
public:
	CScrollBarApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CScrollBarApp theApp;