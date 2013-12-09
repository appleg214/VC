// Another.cpp : 实现文件
//

#include "stdafx.h"
#include "Brush1.h"
#include "Another.h"
#include "afxdialogex.h"


// CAnother 对话框

IMPLEMENT_DYNAMIC(CAnother, CDialog)

CAnother::CAnother(CWnd* pParent /*=NULL*/)
	: CDialog(CAnother::IDD, pParent)
{

}

CAnother::~CAnother()
{
}

void CAnother::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAnother, CDialog)
END_MESSAGE_MAP()


// CAnother 消息处理程序


BOOL CAnother::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
