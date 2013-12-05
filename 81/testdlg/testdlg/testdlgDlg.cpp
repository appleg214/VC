
// testdlgDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "testdlg.h"
#include "testdlgDlg.h"
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


// CtestdlgDlg �Ի���




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


// CtestdlgDlg ��Ϣ�������

BOOL CtestdlgDlg::OnInitDialog()
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
		//LONG lStyle;
		//lStyle = GetWindowLong(m_list.m_hWnd, GWL_STYLE);//��ȡ��ǰ����style
		//lStyle &= ~LVS_TYPEMASK; //�����ʾ��ʽλ
		//lStyle |= LVS_REPORT; //����style
		//SetWindowLong(m_list.m_hWnd, GWL_STYLE, lStyle);//����style
		//DWORD dwStyle = m_list.GetExtendedStyle();
		//dwStyle |= LVS_EX_FULLROWSELECT;//ѡ��ĳ��ʹ���и�����ֻ������report����listctrl��
		//dwStyle |= LVS_EX_GRIDLINES;//�����ߣ�ֻ������report����listctrl��
		//dwStyle |= LVS_EX_CHECKBOXES;//itemǰ����checkbox�ؼ�
		//m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_CHECKBOXES); //������չ���
		m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_FLATSB); //������չ���

	//m_list.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);

	m_list.InsertColumn(100,_T("��1"),LVCFMT_LEFT,100);
	m_list.InsertColumn(100,_T("��2"),LVCFMT_LEFT,70);
	m_list.InsertColumn(100,_T("��3"),LVCFMT_LEFT,70);	
	m_list.InsertColumn(100,_T("��4"),LVCFMT_LEFT,70);
	m_list.InsertColumn(100,_T("��5"),LVCFMT_LEFT,70);	
	m_list.InsertColumn(100,_T("��6"),LVCFMT_LEFT,70);

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

	m_list.SetItemText(0,0,_T("һ"));
	m_list.SetItemText(1,0,_T("��"));
	m_list.SetItemText(2,0,_T("��"));
	m_list.SetItemText(3,0,_T("��"));
	m_list.SetItemText(4,0,_T("��"));
	m_list.SetItemText(5,0,_T("��"));
	m_list.SetItemText(6,0,_T("��"));
	m_list.SetItemText(7,0,_T("��"));
	m_list.SetItemText(8,0,_T("��"));
	m_list.SetItemText(9,0,_T("ʮ"));

	//m_list.SetItemText(0,0,_T("����һ"));    //�޸ĵ�0�����ݵ�������Ϣ��
	//m_list.SetItemText(0,1,_T("���ݶ�"));    //�޸ĵ�0�����ݵ�������Ϣ��
	//m_list.SetItemText(0,2,_T("������"));
	//m_list.SetItemText(0,3,_T("������"));

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CtestdlgDlg::OnPaint()
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
HCURSOR CtestdlgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

