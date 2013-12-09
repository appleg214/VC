// 2008CombotestDlg.h : 头文件
//

#pragma once


// CMy2008CombotestDlg 对话框
class CMy2008CombotestDlg : public CDialog
{
// 构造
public:
	CMy2008CombotestDlg(CWnd* pParent = NULL);	// 标准构造函数
	CComboBox m_combo;
// 对话框数据
	enum { IDD = IDD_MY2008COMBOTEST_DIALOG };

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
};
