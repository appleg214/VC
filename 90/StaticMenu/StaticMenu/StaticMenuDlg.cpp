
// StaticMenuDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StaticMenu.h"
#include "StaticMenuDlg.h"
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


// CStaticMenuDlg �Ի���




CStaticMenuDlg::CStaticMenuDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStaticMenuDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_menu = new CMenu;
	m_menu->CreatePopupMenu();
	m_menu->AppendMenu(MF_STRING,IDM_ITEM0,_T("����"));
	m_menu->AppendMenu(MF_STRING,IDM_ITEM1,_T("����"));
	m_menu->AppendMenu(MF_STRING,IDM_ITEM2,_T("ճ��"));
	m_menu->AppendMenu(MF_SEPARATOR,IDM_ITEM3,_T(""));
	m_menu->AppendMenu(MF_STRING,IDM_ITEM4,_T("ȫѡ"));
	m_menu->AppendMenu(MF_SEPARATOR,IDM_ITEM3,_T(""));
	m_menu->AppendMenu(MF_STRING,IDM_ITEM5,_T("ɾ��"));

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


// CStaticMenuDlg ��Ϣ�������

BOOL CStaticMenuDlg::OnInitDialog()
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
	//m_menu.LoadMenu(IDR_MENU1);
//	SetMenu(&m_menu);
	//CListBox* m_myList = (CListBox*)GetDlgItem(IDC_MY_LIST);
	//m_myList->AddString(_T(""))
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CStaticMenuDlg::OnPaint()
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect rect;
	GetWindowRect(&rect);
	m_menu->TrackPopupMenu(TPM_RIGHTALIGN,point.x+rect.left,point.y+rect.top,this,NULL);
}
