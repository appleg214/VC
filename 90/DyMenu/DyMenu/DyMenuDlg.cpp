
// DyMenuDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DyMenu.h"
#include "DyMenuDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CDyMenuDlg �Ի���




CDyMenuDlg::CDyMenuDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDyMenuDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDyMenuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDyMenuDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_MENUOPERATOR,OnOperator)
END_MESSAGE_MAP()


// CDyMenuDlg ��Ϣ�������

BOOL CDyMenuDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_menu.CreateMenu();
	CMenu popmenu;
	popmenu.CreatePopupMenu();
	popmenu.AppendMenu(MF_STRING,IDM_MENU1_ITEM1,_T("1.1"));
	popmenu.AppendMenu(MF_STRING,IDM_MENU1_ITEM3,_T("1.2"));
	popmenu.AppendMenu(MF_STRING,IDM_MENU1_ITEM3,_T("1.3"));
	popmenu.AppendMenu(MF_STRING,IDM_MENU1_ITEM4,_T("1.4"));
	m_menu.AppendMenu(MF_POPUP,(UINT)popmenu.m_hMenu,_T("һ"));
	m_menu.DeleteMenu((UINT)popmenu.m_hMenu,MF_BYCOMMAND);
	popmenu.DeleteMenu(IDM_MENU1_ITEM1,MF_BYCOMMAND);
	popmenu.AppendMenu(MF_STRING,IDM_MENU2_ITEM1,_T("2.1"));
	popmenu.AppendMenu(MF_STRING,IDM_MENU2_ITEM3,_T("2.2"));
	popmenu.AppendMenu(MF_STRING,IDM_MENU2_ITEM3,_T("2.3"));
	popmenu.AppendMenu(MF_STRING,IDM_MENU2_ITEM4,_T("2.4"));
	m_menu.AppendMenu(MF_POPUP,(UINT)popmenu.m_hMenu,_T("��"));

	SetMenu(&m_menu);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CDyMenuDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDyMenuDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CDyMenuDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CDyMenuDlg::OnOperator()
{
	MessageBox(_T("Just OK!"));
}
