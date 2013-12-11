
// LoadImageDlg.h : 头文件
//
#include "Another.h"
#pragma once


// CLoadImageDlg 对话框
class CLoadImageDlg : public CDialogEx
{
// 构造
public:
	CLoadImageDlg(CWnd* pParent = NULL);	// 标准构造函数
	CAnother anotherDlg;

// 对话框数据
	enum { IDD = IDD_LOADIMAGE_DIALOG };

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
	CStatic m_Image;
	afx_msg void OnBnClickedOk();
};
