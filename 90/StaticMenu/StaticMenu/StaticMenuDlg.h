
// StaticMenuDlg.h : 头文件
//

#pragma once


// CStaticMenuDlg 对话框
class CStaticMenuDlg : public CDialogEx
{
// 构造
public:
	CStaticMenuDlg(CWnd* pParent = NULL);	// 标准构造函数
	~CStaticMenuDlg();
	CMenu *m_menu;
// 对话框数据
	enum { IDD = IDD_STATICMENU_DIALOG };

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
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};
