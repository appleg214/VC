
// work11View.cpp : CDocViewPrintView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "work11.h"
#endif

#include "work11Doc.h"
#include "work11View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDocViewPrintView

IMPLEMENT_DYNCREATE(CDocViewPrintView, CView)

BEGIN_MESSAGE_MAP(CDocViewPrintView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDocViewPrintView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CDocViewPrintView 构造/析构

CDocViewPrintView::CDocViewPrintView()
{
	isPreview = FALSE;		// TODO: 在此处添加构造代码

}

CDocViewPrintView::~CDocViewPrintView()
{
}

BOOL CDocViewPrintView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDocViewPrintView 绘制

void CDocViewPrintView::OnDraw(CDC* pDC)
{
	m_titlefont.CreatePointFont(200,_T("楷体_GB2312"),pDC);
	m_bodyfont.CreatePointFont(100,_T("楷体_GB2312"),pDC);

	screenx =pDC->GetDeviceCaps(LOGPIXELSX);
	screeny =pDC->GetDeviceCaps(LOGPIXELSY);

	CDocViewPrintDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDC->SelectObject(&m_titlefont);
	CRect m_rect;

	this->GetClientRect(m_rect);
	m_rect.DeflateRect(0,20,0,0);

	//绘制标题
	pDC->DrawText(_T("学生成绩单"),m_rect,DT_CENTER);

	//绘制报表数据
	CMainDlg* pmaindlg = ((CDocViewPrintApp*)(AfxGetApp()))->tempdlg;
	pDC->SelectObject(&m_bodyfont);

	WCHAR* pchar = new WCHAR[100];
	LVCOLUMN column;
	column.mask = LVCF_TEXT;
	column.pszText = pchar;
	column.cchTextMax = 100;


	CString str;

	CRect m_temprect (m_rect.left+60,m_rect.top+60,60+(m_rect.Width())/6,m_rect.bottom);
	
	CRect m_itemrect;

	m_rect.DeflateRect(60,40);


	int width = m_temprect.Width();
	for (int i = 0;i< 6;i++)
	{

		if (pmaindlg->m_list.GetColumn(i,&column))
			str =  column.pszText;

		pDC->DrawText(str,m_temprect,DT_LEFT);

		m_itemrect.CopyRect(m_temprect);

		for (int row = 0;row <10;row++)
		{
			m_itemrect.DeflateRect(0,30);
			str = pmaindlg->m_list.GetItemText(row,i);

			pDC->DrawText(str,m_itemrect,DT_LEFT);
		
		}

		m_temprect.DeflateRect(width,0,0,0);

		m_temprect.InflateRect(0,0,width,0);

	}
	delete []pchar;
	m_titlefont.DeleteObject();
	m_bodyfont.DeleteObject();
	// TODO: 在此处为本机数据添加绘制代码
}


// CDocViewPrintView 打印


void CDocViewPrintView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDocViewPrintView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDocViewPrintView::OnBeginPrinting(CDC* pDC, CPrintInfo* /*pInfo*/)
{

	printx =pDC->GetDeviceCaps(LOGPIXELSX);
	printy =pDC->GetDeviceCaps(LOGPIXELSY);	

	xrate = (double)printx /screenx; //确定打印机与屏幕的比率
	yrate = (double)printy /screeny;

	pageheight =pDC->GetDeviceCaps(VERTRES);
	pagewidth =pDC->GetDeviceCaps(HORZRES);
	//获取打印机的左右边距
	
	leftmargin = pDC->GetDeviceCaps(PHYSICALOFFSETX);//获取左边距
	
	int phywidth= pDC->GetDeviceCaps(PHYSICALWIDTH);

	rightmargin = phywidth-pagewidth-leftmargin;
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDocViewPrintView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CDocViewPrintView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDocViewPrintView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDocViewPrintView 诊断

#ifdef _DEBUG
void CDocViewPrintView::AssertValid() const
{
	CView::AssertValid();
}

void CDocViewPrintView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDocViewPrintDoc* CDocViewPrintView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDocViewPrintDoc)));
	return (CDocViewPrintDoc*)m_pDocument;
}
#endif //_DEBUG


// CDocViewPrintView 消息处理程序
