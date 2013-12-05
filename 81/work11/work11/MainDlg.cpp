// MainDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "work11.h"
#include "MainDlg.h"
#include "afxdialogex.h"

// CMainDlg �Ի���

IMPLEMENT_DYNAMIC(CMainDlg, CDialog)

CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMainDlg::IDD, pParent)
{

}

CMainDlg::~CMainDlg()
{
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);

}


BEGIN_MESSAGE_MAP(CMainDlg, CDialog)
	ON_BN_CLICKED(IDC_PRINT, OnPrint)
	ON_BN_CLICKED(IDC_QUIT, OnQuit)
END_MESSAGE_MAP()


// CMainDlg ��Ϣ�������


BOOL CMainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	//CListCtrl m_list; 
	//m_list = (CListCtrl)GetDlgItem(IDC_LIST1);
	m_list.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);

	m_list.InsertColumn(100,_T("����"),LVCFMT_LEFT,100);
	m_list.InsertColumn(100,_T("����"),LVCFMT_LEFT,70);
	m_list.InsertColumn(100,_T("��ѧ"),LVCFMT_LEFT,70);
	m_list.InsertColumn(100,_T("Ӣ��"),LVCFMT_LEFT,70);
	m_list.InsertColumn(100,_T("����"),LVCFMT_LEFT,70);
	m_list.InsertColumn(100,_T("��ʷ"),LVCFMT_LEFT,70);

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

	m_list.SetItemText(0,0,_T("��ƽ"));
	m_list.SetItemText(1,0,_T("���"));
	m_list.SetItemText(2,0,_T("�ź�"));
	m_list.SetItemText(3,0,_T("����"));
	m_list.SetItemText(4,0,_T("���"));
	m_list.SetItemText(5,0,_T("����"));
	m_list.SetItemText(6,0,_T("���л�"));
	m_list.SetItemText(7,0,_T("�ο�ƽ"));
	m_list.SetItemText(8,0,_T("����"));
	m_list.SetItemText(9,0,_T("���"));
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
void CMainDlg::OnPrint()
{
	AfxGetApp()->m_pMainWnd = NULL;
	AfxGetApp()->m_pDocManager->OnFileNew();
	IsPreview = TRUE;
}

void CMainDlg::OnQuit() 
{
	OnCancel();	
}
