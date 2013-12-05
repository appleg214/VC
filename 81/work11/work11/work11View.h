
// work11View.h : CDocViewPrintView ��Ľӿ�
//

#pragma once

#include "MainDlg.h"

class CDocViewPrintView : public CView
{
protected: // �������л�����
	CDocViewPrintView();
	DECLARE_DYNCREATE(CDocViewPrintView)
	CFont m_titlefont;
	CFont m_bodyfont;  //��������

	int screenx,screeny; //��ȡ����ÿӢ��������
	int printx,printy; //��ȡ��ӡ��ÿӢ��������
	double xrate,yrate; //��ӡ������Ļ�����ر���

	int pageheight; //��ӡֽ�߶�
	int pagewidth; //��ӡֽ���

	int leftmargin,rightmargin; //��ӡֽ���ұ߾�
	BOOL isPreview; //�Ƿ���Ԥ��״̬

// ����
public:
	CDocViewPrintDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CDocViewPrintView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // work11View.cpp �еĵ��԰汾
inline CDocViewPrintDoc* CDocViewPrintView::GetDocument() const
   { return reinterpret_cast<CDocViewPrintDoc*>(m_pDocument); }
#endif

