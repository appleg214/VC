#pragma once


// CSecondDlg 对话框

class CSecondDlg : public CDialog
{
	DECLARE_DYNAMIC(CSecondDlg)

public:
	CSecondDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSecondDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_SHARE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CButton m_save;
	CStatic m_static1;
	CStatic m_static2;
	CStatic m_static3;
	CStatic m_static4;
	virtual BOOL OnInitDialog();
};
