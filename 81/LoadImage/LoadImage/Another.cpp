// Another.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LoadImage.h"
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
	ON_WM_CTLCOLOR()
	//ON_WM_DESTROY()
//	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CAnother ��Ϣ�������


BOOL CAnother::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP2);
	m_anotherBrsh.CreatePatternBrush(&bmp);
	bmp.DeleteObject();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


HBRUSH CAnother::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if (pWnd == this) 
		return m_anotherBrsh;
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


//void CAnother::OnOK()
//{
//	// TODO: �ڴ����ר�ô����/����û���
//	CDialog::OnOK();
//	AfxMessageBox(_T("call OK this"));
//	DestroyWindow();
//}
//
//
//void CAnother::OnCancel()
//{
//	// TODO: �ڴ����ר�ô����/����û���
//	CDialog::OnCancel();
//	AfxMessageBox(_T("call Cancel this"));
//	DestroyWindow();
//}
//
//
//void CAnother::OnDestroy()
//{
//	CDialog::OnDestroy();
//	AfxMessageBox(_T("call delete this"));
//	delete this;
//
//	// TODO: �ڴ˴������Ϣ����������
//}


