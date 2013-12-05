
// work11View.h : CDocViewPrintView 类的接口
//

#pragma once

#include "MainDlg.h"

class CDocViewPrintView : public CView
{
protected: // 仅从序列化创建
	CDocViewPrintView();
	DECLARE_DYNCREATE(CDocViewPrintView)
	CFont m_titlefont;
	CFont m_bodyfont;  //正文字体

	int screenx,screeny; //获取窗口每英寸像素数
	int printx,printy; //获取打印机每英寸像素数
	double xrate,yrate; //打印机与屏幕的像素比率

	int pageheight; //打印纸高度
	int pagewidth; //打印纸宽度

	int leftmargin,rightmargin; //打印纸左右边距
	BOOL isPreview; //是否处于预览状态

// 特性
public:
	CDocViewPrintDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CDocViewPrintView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // work11View.cpp 中的调试版本
inline CDocViewPrintDoc* CDocViewPrintView::GetDocument() const
   { return reinterpret_cast<CDocViewPrintDoc*>(m_pDocument); }
#endif

