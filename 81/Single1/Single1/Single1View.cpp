
// Single1View.cpp : CSingle1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSingle1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CSingle1View ����/����

CSingle1View::CSingle1View()
{
	// TODO: �ڴ˴���ӹ������

}

CSingle1View::~CSingle1View()
{
}

BOOL CSingle1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSingle1View ����

void CSingle1View::OnDraw(CDC* pDC)
{
	m_titlefont.CreatePointFont(200,_T("΢���ź�"),pDC);
	CSingle1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->SelectObject(&m_titlefont);
	this->GetClientRect(m_rect);
	m_rect.DeflateRect(0,20,0,0);

	pDC->DrawText(_T("kengdiea!"),m_rect,DT_CENTER);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CSingle1View ��ӡ


void CSingle1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSingle1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSingle1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSingle1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// CSingle1View ���

#ifdef _DEBUG
void CSingle1View::AssertValid() const
{
	CView::AssertValid();
}

void CSingle1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSingle1Doc* CSingle1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSingle1Doc)));
	return (CSingle1Doc*)m_pDocument;
}
#endif //_DEBUG


// CSingle1View ��Ϣ�������
