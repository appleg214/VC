
// Brushtest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CBrushtestApp:
// �йش����ʵ�֣������ Brushtest.cpp
//

class CBrushtestApp : public CWinApp
{
public:
	CBrushtestApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CBrushtestApp theApp;