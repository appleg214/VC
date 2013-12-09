
// ScrollBarDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ScrollBar.h"
#include "ScrollBarDlg.h"
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


// CScrollBarDlg �Ի���




CScrollBarDlg::CScrollBarDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CScrollBarDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CScrollBarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC_STATIC, m_Image);
}

BEGIN_MESSAGE_MAP(CScrollBarDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CScrollBarDlg ��Ϣ�������

BOOL CScrollBarDlg::OnInitDialog()
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
	HBITMAP m_hBitmap;
	BITMAP bmp;
	m_hBitmap =::LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP1));
	m_Image.SetBitmap(m_hBitmap);
	GetObject(m_hBitmap,sizeof(bmp),&bmp);
	CRect rect;
	GetClientRect(rect);
	int xpos = GetScrollPos(SB_HORZ);
	if(0!=xpos)
		ScrollWindow(xpos,0);
	int ypos = GetScrollPos(SB_VERT);
	if(0!=ypos)
		ScrollWindow(ypos,0);

	SCROLLINFO vinfo;
	vinfo.cbSize = sizeof(vinfo);
	vinfo.fMask = SIF_ALL;
	vinfo.nPage = bmp.bmHeight/10;
	vinfo.nMax = bmp.bmHeight-rect.Height()+bmp.bmHeight/10;
	vinfo.nMin = 0;
	vinfo.nTrackPos = 0;
	vinfo.nPos = 0;
	SetScrollInfo(SB_VERT,&vinfo);

	vinfo.cbSize = sizeof(vinfo);
	vinfo.fMask = SIF_ALL;
	vinfo.nPage = bmp.bmWidth/10;
	vinfo.nMax = bmp.bmWidth-rect.Width()+bmp.bmWidth/10;
	vinfo.nMin = 0;
	vinfo.nTrackPos = 0;
	vinfo.nPos = 0;
	SetScrollInfo(SB_HORZ,&vinfo);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CScrollBarDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CScrollBarDlg::OnPaint()
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
HCURSOR CScrollBarDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

