// Another.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Brush1.h"
#include "Another.h"
#include "afxdialogex.h"


// CAnother �Ի���

IMPLEMENT_DYNAMIC(CAnother, CDialog)

CAnother::CAnother(CWnd* pParent /*=NULL*/)
	: CDialog(CAnother::IDD, pParent)
{

}

CAnother::~CAnother()
{
}

void CAnother::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAnother, CDialog)
END_MESSAGE_MAP()


// CAnother ��Ϣ�������


BOOL CAnother::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
