
// ControlTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ControlTest.h"
#include "ControlTestDlg.h"
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


// CControlTestDlg �Ի���




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


// CControlTestDlg ��Ϣ�������

BOOL CControlTestDlg::OnInitDialog()
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CControlTestDlg::OnPaint()
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
HCURSOR CControlTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CControlTestDlg::OnBnClickedButton1()
{
	CEdit* m_edit1 = (CEdit*)GetDlgItem(IDC_EDIT1);
	m_edit1->SetWindowText(_T("kengdieaaa!"));
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

	// TODO: �ڴ���ӿؼ�֪ͨ����������
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


	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CControlTestDlg::OnBnClickedDisplayButton()
{
	CEdit* m_edit = (CEdit*)GetDlgItem(IDC_EDIT2);
	CListBox* m_list2 = (CListBox*)GetDlgItem(IDC_LIST);
	int index1 = m_list2->GetCurSel();
	int ListLong1 = m_list2->GetCount();
	CString Displaytxt;
	// ��ǰδѡ����ʾ��δѡ��
	if (index1 == -1)
		m_edit->SetWindowText(_T("No Selection"));
	else
	{
		m_list2->GetText(index1,Displaytxt);
		m_edit->SetWindowText(Displaytxt);
	}
}
