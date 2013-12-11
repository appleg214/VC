// Another.cpp : 实现文件
//

#include "stdafx.h"
#include "LoadImage.h"
#include "Another.h"
#include "afxdialogex.h"


// CAnother 对话框

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


// CAnother 消息处理程序


BOOL CAnother::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  在此添加额外的初始化
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP2);
	m_anotherBrsh.CreatePatternBrush(&bmp);
	bmp.DeleteObject();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


HBRUSH CAnother::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd == this) 
		return m_anotherBrsh;
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


//void CAnother::OnOK()
//{
//	// TODO: 在此添加专用代码和/或调用基类
//	CDialog::OnOK();
//	AfxMessageBox(_T("call OK this"));
//	DestroyWindow();
//}
//
//
//void CAnother::OnCancel()
//{
//	// TODO: 在此添加专用代码和/或调用基类
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
//	// TODO: 在此处添加消息处理程序代码
//}


