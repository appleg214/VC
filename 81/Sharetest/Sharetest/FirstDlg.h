#pragma once


// CFirstDlg 对话框

class CFirstDlg : public CDialog
{
	DECLARE_DYNAMIC(CFirstDlg)

public:
	CFirstDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFirstDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_SHARE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_static1;
	CStatic m_static2;
	CStatic m_static3;
	CStatic m_static4;
	CButton m_save;
	virtual BOOL OnInitDialog();
};
