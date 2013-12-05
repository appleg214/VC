
// Single1View.cpp : CSingle1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Single1.h"
#endif

#include "Single1Doc.h"
#include "Single1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSingle1View

IMPLEMENT_DYNCREATE(CSingle1View, CView)

BEGIN_MESSAGE_MAP(CSingle1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSingle1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CSingle1View 构造/析构

CSingle1View::CSingle1View()
{
	// TODO: 在此处添加构造代码

}

CSingle1View::~CSingle1View()
{
}

BOOL CSingle1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSingle1View 绘制

void CSingle1View::OnDraw(CDC* pDC)
{
	m_titlefont.CreatePointFont(200,_T("微软雅黑"),pDC);
	CSingle1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->SelectObject(&m_titlefont);
	this->GetClientRect(m_rect);
	m_rect.DeflateRect(0,20,0,0);

	pDC->DrawText(_T("kengdiea!"),m_rect,DT_CENTER);
	// TODO: 在此处为本机数据添加绘制代码
}


// CSingle1View 打印


void CSingle1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSingle1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSingle1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CSingle1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CSingle1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSingle1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSingle1View 诊断

#ifdef _DEBUG
void CSingle1View::AssertValid() const
{
	CView::AssertValid();
}

void CSingle1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSingle1Doc* CSingle1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSingle1Doc)));
	return (CSingle1Doc*)m_pDocument;
}
#endif //_DEBUG


// CSingle1View 消息处理程序
