
// ControlText1Dlg.h : 头文件
//

#pragma once


// CControlText1Dlg 对话框
class CControlText1Dlg : public CDialogEx
{
// 构造
public:
	CControlText1Dlg(CWnd* pParent = NULL);	// 标准构造函数
	CListBox m_list;
	CEdit m_edit;
// 对话框数据
	enum { IDD = IDD_CONTROLTEXT1_DIALOG };

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
	afx_msg void OnBnClickedDeleteallButton();
	afx_msg void OnBnClickedAddButton();
	afx_msg void OnBnClickedReinputButton();
	afx_msg void OnBnClickedUpButton();
};
