// SecondDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Sharetest.h"
#include "SecondDlg.h"
#include "afxdialogex.h"


// CSecondDlg �Ի���

IMPLEMENT_DYNAMIC(CSecondDlg, CDialog)

CSecondDlg::CSecondDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSecondDlg::IDD, pParent)
{

}

CSecondDlg::~CSecondDlg()
{
}

void CSecondDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_save);
	DDX_Control(pDX, IDC_STATIC1, m_static1);
	DDX_Control(pDX, IDC_STATIC2, m_static2);
	DDX_Control(pDX, IDC_STATIC3, m_static3);
	DDX_Control(pDX, IDC_STATIC4, m_static4);
}


BEGIN_MESSAGE_MAP(CSecondDlg, CDialog)
END_MESSAGE_MAP()


// CSecondDlg ��Ϣ�������


BOOL CSecondDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_static1.SetWindowText(_T("second1"));
	m_static2.SetWindowText(_T("second2"));
	m_static3.SetWindowText(_T("second3"));
	m_static4.SetWindowText(_T("second4"));
	m_save.SetWindowText(_T("SaveSecond"));

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
