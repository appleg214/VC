// MainDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "work11.h"
#include "MainDlg.h"
#include "afxdialogex.h"

// CMainDlg 对话框

IMPLEMENT_DYNAMIC(CMainDlg, CDialog)

CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMainDlg::IDD, pParent)
{

}

CMainDlg::~CMainDlg()
{
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);

}


BEGIN_MESSAGE_MAP(CMainDlg, CDialog)
	ON_BN_CLICKED(IDC_PRINT, OnPrint)
	ON_BN_CLICKED(IDC_QUIT, OnQuit)
END_MESSAGE_MAP()


// CMainDlg 消息处理程序


BOOL CMainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	//CListCtrl m_list; 
	//m_list = (CListCtrl)GetDlgItem(IDC_LIST1);
	m_list.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);

	m_list.InsertColumn(100,_T("姓名"),LVCFMT_LEFT,100);
	m_list.InsertColumn(100,_T("语文"),LVCFMT_LEFT,70);
	m_list.InsertColumn(100,_T("数学"),LVCFMT_LEFT,70);
	m_list.InsertColumn(100,_T("英语"),LVCFMT_LEFT,70);
	m_list.InsertColumn(100,_T("政治"),LVCFMT_LEFT,70);
	m_list.InsertColumn(100,_T("历史"),LVCFMT_LEFT,70);

	CString temp;
	int grade;
	//add data to list
	for (int i = 0;i<10;i++)
	{
		m_list.InsertItem(i,_T(""));
		for (int c = 1;c<6;c++)
		{
			grade = c*2+80+i;
			temp.Format(_T("%d"),grade);
			m_list.SetItemText(i,c,temp);
		}

	}

	m_list.SetItemText(0,0,_T("王平"));
	m_list.SetItemText(1,0,_T("李可"));
	m_list.SetItemText(2,0,_T("张红"));
	m_list.SetItemText(3,0,_T("周亮"));
	m_list.SetItemText(4,0,_T("孙军"));
	m_list.SetItemText(5,0,_T("刘海"));
	m_list.SetItemText(6,0,_T("王中华"));
	m_list.SetItemText(7,0,_T("宋可平"));
	m_list.SetItemText(8,0,_T("张男"));
	m_list.SetItemText(9,0,_T("李菊"));
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
void CMainDlg::OnPrint()
{
	AfxGetApp()->m_pMainWnd = NULL;
	AfxGetApp()->m_pDocManager->OnFileNew();
	IsPreview = TRUE;
}

void CMainDlg::OnQuit() 
{
	OnCancel();	
}
