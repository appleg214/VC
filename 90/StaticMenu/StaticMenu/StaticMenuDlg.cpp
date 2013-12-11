
// StaticMenuDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "StaticMenu.h"
#include "StaticMenuDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CStaticMenuDlg 对话框




CStaticMenuDlg::CStaticMenuDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStaticMenuDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_menu = new CMenu;
	m_menu->CreatePopupMenu();
	m_menu->AppendMenu(MF_STRING,IDM_ITEM0,_T("拷贝"));
	m_menu->AppendMenu(MF_STRING,IDM_ITEM1,_T("剪切"));
	m_menu->AppendMenu(MF_STRING,IDM_ITEM2,_T("粘贴"));
	m_menu->AppendMenu(MF_SEPARATOR,IDM_ITEM3,_T(""));
	m_menu->AppendMenu(MF_STRING,IDM_ITEM4,_T("全选"));
	m_menu->AppendMenu(MF_SEPARATOR,IDM_ITEM3,_T(""));
	m_menu->AppendMenu(MF_STRING,IDM_ITEM5,_T("删除"));

}

CStaticMenuDlg::~CStaticMenuDlg()
{
	m_menu->DestroyMenu();
	delete m_menu;
}

void CStaticMenuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CStaticMenuDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CREATE()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()


// CStaticMenuDlg 消息处理程序

BOOL CStaticMenuDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//m_menu.LoadMenu(IDR_MENU1);
//	SetMenu(&m_menu);
	//CListBox* m_myList = (CListBox*)GetDlgItem(IDC_MY_LIST);
	//m_myList->AddString(_T(""))
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CStaticMenuDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CStaticMenuDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CStaticMenuDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//int CStaticMenuDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
//{
//	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
//		return -1;
//	m_menu.LoadMenu(IDR_MENU1);
//	return 0;
//}


void CStaticMenuDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	//CDialogEx::OnRButtonDown(nFlags, point);
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect rect;
	GetWindowRect(&rect);
	m_menu->TrackPopupMenu(TPM_RIGHTALIGN,point.x+rect.left,point.y+rect.top,this,NULL);
}
