// FirstDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Sharetest.h"
#include "FirstDlg.h"
#include "afxdialogex.h"


// CFirstDlg 对话框

IMPLEMENT_DYNAMIC(CFirstDlg, CDialog)

CFirstDlg::CFirstDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFirstDlg::IDD, pParent)
{

}

CFirstDlg::~CFirstDlg()
{
}

void CFirstDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC1, m_static1);
	DDX_Control(pDX, IDC_STATIC2, m_static2);
	DDX_Control(pDX, IDC_STATIC3, m_static3);
	DDX_Control(pDX, IDC_STATIC4, m_static4);
	DDX_Control(pDX, IDC_BUTTON1, m_save);
}


BEGIN_MESSAGE_MAP(CFirstDlg, CDialog)
END_MESSAGE_MAP()


// CFirstDlg 消息处理程序


BOOL CFirstDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_static1.SetWindowText(_T("first1"));
	m_static2.SetWindowText(_T("first2"));
	m_static3.SetWindowText(_T("first3"));
	m_static4.SetWindowText(_T("first4"));
	m_save.SetWindowText(_T("SaveFrist"));

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
