
// DyMenu.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDyMenuApp:
// �йش����ʵ�֣������ DyMenu.cpp
//

class CDyMenuApp : public CWinApp
{
public:
	CDyMenuApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDyMenuApp theApp;