
// ControlText1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ControlText1.h"
#include "ControlText1Dlg.h"
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


// CControlText1Dlg �Ի���




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
}

BEGIN_MESSAGE_MAP(CControlText1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_DELETEALL_BUTTON, &CControlText1Dlg::OnBnClickedDeleteallButton)
	ON_BN_CLICKED(IDC_ADD_BUTTON, &CControlText1Dlg::OnBnClickedAddButton)
	ON_BN_CLICKED(IDC_REINPUT_BUTTON, &CControlText1Dlg::OnBnClickedReinputButton)
	ON_BN_CLICKED(IDC_UP_BUTTON, &CControlText1Dlg::OnBnClickedUpButton)
END_MESSAGE_MAP()


// CControlText1Dlg ��Ϣ�������

BOOL CControlText1Dlg::OnInitDialog()
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CControlText1Dlg::OnPaint()
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
HCURSOR CControlText1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CControlText1Dlg::OnBnClickedDeleteallButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CControlText1Dlg::OnBnClickedAddButton()
{
	CString addText,tempStr;
	BOOL tagInsert;
	m_edit.GetWindowText(addText);
	m_edit.SetWindowText(NULL);
	int m_count = m_list.GetCount();
	if (m_count ==0)
		m_list.AddString(addText);

	for (int i=0;i<m_count||tagInsert==FALSE;i++)
	{
		m_list.GetText(i,tempStr);
		if(tempStr == addText)
			tagInsert = FALSE;
	}
	if (tagInsert == TRUE) m_list.AddString(addText);
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
	if (m_list.GetCurSel() == -1)
		return;
	else
	{
//		MessageBox(_T("letmegoahead"));
	}
	
}
