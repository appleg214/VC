// 2008Combotest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy2008CombotestApp:
// �йش����ʵ�֣������ 2008Combotest.cpp
//

class CMy2008CombotestApp : public CWinApp
{
public:
	CMy2008CombotestApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy2008CombotestApp theApp;