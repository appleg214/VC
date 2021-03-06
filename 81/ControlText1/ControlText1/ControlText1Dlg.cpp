
// ControlText1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ControlText1.h"
#include "ControlText1Dlg.h"
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


// CControlText1Dlg 对话框




CControlText1Dlg::CControlText1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CControlText1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CControlText1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX,IDC_LIST,m_list);
	DDX_Control(pDX,IDC_ADD_EDIT,m_edit);
	DDX_Control(pDX,IDC_COMBO,m_combo);
}

BEGIN_MESSAGE_MAP(CControlText1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_DELETEALL_BUTTON, &CControlText1Dlg::OnBnClickedDeleteallButton)
	ON_BN_CLICKED(IDC_ADD_BUTTON, &CControlText1Dlg::OnBnClickedAddButton)
	ON_BN_CLICKED(IDC_REINPUT_BUTTON, &CControlText1Dlg::OnBnClickedReinputButton)
	ON_BN_CLICKED(IDC_UP_BUTTON, &CControlText1Dlg::OnBnClickedUpButton)
	ON_BN_CLICKED(IDC_ADDCOM_BUTTON, &CControlText1Dlg::OnBnClickedAddcomButton)
END_MESSAGE_MAP()


// CControlText1Dlg 消息处理程序

BOOL CControlText1Dlg::OnInitDialog()
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
	m_combo.AddString(_T("the 1 line have a look!"));
	m_combo.AddString(_T("the 2 line have a look!"));
	m_combo.AddString(_T("the 3 line have a look!"));
	m_combo.AddString(_T("the 4 line have a look!"));
	m_combo.AddString(_T("the 5 line have a look!"));
	//m_combo.SetTopIndex(2);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CControlText1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CControlText1Dlg::OnPaint()
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
HCURSOR CControlText1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CControlText1Dlg::OnBnClickedDeleteallButton()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CControlText1Dlg::OnBnClickedAddButton()
{
	CString addText,tempStr,msgTxt,msgCap;
	BOOL tagInsert;
	tagInsert = TRUE;
	m_edit.GetWindowText(addText);
	addText.Trim(_T(" "));
	int m_count = m_list.GetCount();
	if (m_count ==0)
	{
		m_list.AddString(addText);
		m_edit.SetWindowText(NULL);
	}
	else
	{
		for (int i=0;i<m_count;i++)
		{
			m_list.GetText(i,tempStr);
			if(tempStr == addText)
			{
				tagInsert = FALSE;
				msgCap.LoadString(IDS_MSGCAP);
				msgTxt.LoadString(IDS_MSGTXT);
				MessageBox(msgTxt,msgCap);
				return;
			}
		}
		m_list.AddString(addText);
		m_edit.SetWindowText(NULL);
	}

}


void CControlText1Dlg::OnBnClickedReinputButton()
{
	m_edit.SetWindowText(NULL);
}


void CControlText1Dlg::OnBnClickedUpButton()
{
	//CString stext;
	//stext.Format(_T("%d"),m_list.GetCurSel());
	//m_edit.SetWindowText(stext);
	if (m_list.GetCurSel() == -1||m_list.GetCurSel()==0)
		return;
	else
	{
		MessageBox(_T("letmegoahead"));
	}
	
}


void CControlText1Dlg::OnBnClickedAddcomButton()
{
	CString displaytxt;
	int indexCombo;
	//m_combo.AddString(_T("the 1 line have a look!"));
	//m_combo.AddString(_T("the 2 line have a look!"));
	//m_combo.AddString(_T("the 3 line have a look!"));
	//m_combo.AddString(_T("the 4 line have a look!"));
	//m_combo.AddString(_T("the 5 line have a look!"));
	//m_combo.SetTopIndex(m_combo.GetCount()/2);
	//m_combo.GetLBText(2,displaytxt);
	m_combo.SetTopIndex(3);
	indexCombo = m_combo.GetTopIndex();
	displaytxt.Format(_T("%d"),indexCombo);
	MessageBox(displaytxt);

}
