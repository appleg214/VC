
// Brush1Dlg.h : 头文件
//
#include "Another.h"
#pragma once


// CBrush1Dlg 对话框
class CBrush1Dlg : public CDialogEx
{
// 构造
public:
	CBrush1Dlg(CWnd* pParent = NULL);	// 标准构造函数
	CBrush picBrush;
	CAnother anotherDlg;
// 对话框数据
	enum { IDD = IDD_BRUSH1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedOk();
};
