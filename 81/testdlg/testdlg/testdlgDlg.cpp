
// testdlgDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "testdlg.h"
#include "testdlgDlg.h"
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


// CtestdlgDlg 对话框




CtestdlgDlg::CtestdlgDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CtestdlgDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtestdlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(CtestdlgDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CtestdlgDlg 消息处理程序

BOOL CtestdlgDlg::OnInitDialog()
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
		//LONG lStyle;
		//lStyle = GetWindowLong(m_list.m_hWnd, GWL_STYLE);//获取当前窗口style
		//lStyle &= ~LVS_TYPEMASK; //清除显示方式位
		//lStyle |= LVS_REPORT; //设置style
		//SetWindowLong(m_list.m_hWnd, GWL_STYLE, lStyle);//设置style
		//DWORD dwStyle = m_list.GetExtendedStyle();
		//dwStyle |= LVS_EX_FULLROWSELECT;//选中某行使整行高亮（只适用与report风格的listctrl）
		//dwStyle |= LVS_EX_GRIDLINES;//网格线（只适用与report风格的listctrl）
		//dwStyle |= LVS_EX_CHECKBOXES;//item前生成checkbox控件
		//m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_CHECKBOXES); //设置扩展风格
		m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_FLATSB); //设置扩展风格

	//m_list.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);

	m_list.InsertColumn(100,_T("列1"),LVCFMT_LEFT,100);
	m_list.InsertColumn(100,_T("列2"),LVCFMT_LEFT,70);
	m_list.InsertColumn(100,_T("列3"),LVCFMT_LEFT,70);	
	m_list.InsertColumn(100,_T("列4"),LVCFMT_LEFT,70);
	m_list.InsertColumn(100,_T("列5"),LVCFMT_LEFT,70);	
	m_list.InsertColumn(100,_T("列6"),LVCFMT_LEFT,70);

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

	m_list.SetItemText(0,0,_T("一"));
	m_list.SetItemText(1,0,_T("二"));
	m_list.SetItemText(2,0,_T("三"));
	m_list.SetItemText(3,0,_T("四"));
	m_list.SetItemText(4,0,_T("五"));
	m_list.SetItemText(5,0,_T("六"));
	m_list.SetItemText(6,0,_T("七"));
	m_list.SetItemText(7,0,_T("八"));
	m_list.SetItemText(8,0,_T("九"));
	m_list.SetItemText(9,0,_T("十"));

	//m_list.SetItemText(0,0,_T("数据一"));    //修改第0条数据的其他信息。
	//m_list.SetItemText(0,1,_T("数据二"));    //修改第0条数据的其他信息。
	//m_list.SetItemText(0,2,_T("数据三"));
	//m_list.SetItemText(0,3,_T("数据四"));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CtestdlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CtestdlgDlg::OnPaint()
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
HCURSOR CtestdlgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

