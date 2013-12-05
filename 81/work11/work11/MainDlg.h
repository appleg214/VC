#pragma once


// CMainDlg 对话框

class CMainDlg : public CDialog
{
	DECLARE_DYNAMIC(CMainDlg)

public:
	CMainDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMainDlg();
	
	BOOL IsPreview;

// 对话框数据
	enum { IDD = IDD_MAINDLG };
	CListCtrl m_list;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	afx_msg void OnPrint();
	afx_msg void OnQuit();

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
