
// work11View.cpp : CDocViewPrintView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDocViewPrintView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CDocViewPrintView ����/����

CDocViewPrintView::CDocViewPrintView()
{
	isPreview = FALSE;		// TODO: �ڴ˴���ӹ������

}

CDocViewPrintView::~CDocViewPrintView()
{
}

BOOL CDocViewPrintView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CDocViewPrintView ����

void CDocViewPrintView::OnDraw(CDC* pDC)
{
	m_titlefont.CreatePointFont(200,_T("����_GB2312"),pDC);
	m_bodyfont.CreatePointFont(100,_T("����_GB2312"),pDC);

	screenx =pDC->GetDeviceCaps(LOGPIXELSX);
	screeny =pDC->GetDeviceCaps(LOGPIXELSY);

	CDocViewPrintDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDC->SelectObject(&m_titlefont);
	CRect m_rect;

	this->GetClientRect(m_rect);
	m_rect.DeflateRect(0,20,0,0);

	//���Ʊ���
	pDC->DrawText(_T("ѧ���ɼ���"),m_rect,DT_CENTER);

	//���Ʊ�������
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
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CDocViewPrintView ��ӡ


void CDocViewPrintView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDocViewPrintView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CDocViewPrintView::OnBeginPrinting(CDC* pDC, CPrintInfo* /*pInfo*/)
{

	printx =pDC->GetDeviceCaps(LOGPIXELSX);
	printy =pDC->GetDeviceCaps(LOGPIXELSY);	

	xrate = (double)printx /screenx; //ȷ����ӡ������Ļ�ı���
	yrate = (double)printy /screeny;

	pageheight =pDC->GetDeviceCaps(VERTRES);
	pagewidth =pDC->GetDeviceCaps(HORZRES);
	//��ȡ��ӡ�������ұ߾�
	
	leftmargin = pDC->GetDeviceCaps(PHYSICALOFFSETX);//��ȡ��߾�
	
	int phywidth= pDC->GetDeviceCaps(PHYSICALWIDTH);

	rightmargin = phywidth-pagewidth-leftmargin;
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CDocViewPrintView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// CDocViewPrintView ���

#ifdef _DEBUG
void CDocViewPrintView::AssertValid() const
{
	CView::AssertValid();
}

void CDocViewPrintView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDocViewPrintDoc* CDocViewPrintView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDocViewPrintDoc)));
	return (CDocViewPrintDoc*)m_pDocument;
}
#endif //_DEBUG


// CDocViewPrintView ��Ϣ�������
