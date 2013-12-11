
// IMenuTestView.cpp : CIMenuTestView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "IMenuTest.h"
#endif

#include "IMenuTestDoc.h"
#include "IMenuTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CIMenuTestView

IMPLEMENT_DYNCREATE(CIMenuTestView, CView)

BEGIN_MESSAGE_MAP(CIMenuTestView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CIMenuTestView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CIMenuTestView ����/����

CIMenuTestView::CIMenuTestView()
{
	// TODO: �ڴ˴���ӹ������

}

CIMenuTestView::~CIMenuTestView()
{
}

BOOL CIMenuTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CIMenuTestView ����

void CIMenuTestView::OnDraw(CDC* /*pDC*/)
{
	CIMenuTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CIMenuTestView ��ӡ


void CIMenuTestView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CIMenuTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CIMenuTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CIMenuTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CIMenuTestView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CIMenuTestView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CIMenuTestView ���

#ifdef _DEBUG
void CIMenuTestView::AssertValid() const
{
	CView::AssertValid();
}

void CIMenuTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CIMenuTestDoc* CIMenuTestView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIMenuTestDoc)));
	return (CIMenuTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CIMenuTestView ��Ϣ�������
