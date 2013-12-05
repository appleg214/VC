
// ControlTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ControlTest.h"
#include "ControlTestDlg.h"
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


// CControlTestDlg 对话框




CControlTestDlg::CControlTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CControlTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CControlTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CControlTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CControlTestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CControlTestDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_ADD_BUTTON, &CControlTestDlg::OnBnClickedAddButton)
	ON_BN_CLICKED(IDC_SELECT_BUTTON, &CControlTestDlg::OnBnClickedSelectButton)
	ON_BN_CLICKED(IDC_DISPLAY_BUTTON, &CControlTestDlg::OnBnClickedDisplayButton)
END_MESSAGE_MAP()


// CControlTestDlg 消息处理程序

BOOL CControlTestDlg::OnInitDialog()
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CControlTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CControlTestDlg::OnPaint()
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
HCURSOR CControlTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CControlTestDlg::OnBnClickedButton1()
{
	CEdit* m_edit1 = (CEdit*)GetDlgItem(IDC_EDIT1);
	m_edit1->SetWindowText(_T("kengdieaaa!"));
	// TODO: 在此添加控件通知处理程序代码
}


void CControlTestDlg::OnBnClickedButton2()
{
	CEdit* m_edit2 = (CEdit*)GetDlgItem(IDC_EDIT2);
	m_edit2->SetWindowText(NULL);
}


void CControlTestDlg::OnBnClickedAddButton()
{
	CListBox* m_list1 = (CListBox*)GetDlgItem(IDC_LIST);
	m_list1->AddString(_T("FirstOne"));
	m_list1->AddString(_T("SecondTwo"));
	m_list1->AddString(_T("ThirdThree"));
	m_list1->AddString(_T("FourthFour"));
	m_list1->AddString(_T("FifthFive"));

	// TODO: 在此添加控件通知处理程序代码
}


void CControlTestDlg::OnBnClickedSelectButton()
{
	CListBox* m_list2 = (CListBox*)GetDlgItem(IDC_LIST);
	int index1 = m_list2->GetCurSel();
	int ListLong1 = m_list2->GetCount();
	if(index1 == ListLong1-1)
		m_list2->SetCurSel(0);
	else
		m_list2->SetCurSel(index1+1);


	// TODO: 在此添加控件通知处理程序代码
}


void CControlTestDlg::OnBnClickedDisplayButton()
{
	CEdit* m_edit = (CEdit*)GetDlgItem(IDC_EDIT2);
	CListBox* m_list2 = (CListBox*)GetDlgItem(IDC_LIST);
	int index1 = m_list2->GetCurSel();
	int ListLong1 = m_list2->GetCount();
	CString Displaytxt;
	// 当前未选择显示“未选择”
	if (index1 == -1)
		m_edit->SetWindowText(_T("No Selection"));
	else
	{
		m_list2->GetText(index1,Displaytxt);
		m_edit->SetWindowText(Displaytxt);
	}
}
