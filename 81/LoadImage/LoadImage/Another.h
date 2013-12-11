#pragma once


// CAnother 对话框

class CAnother : public CDialog
{
	DECLARE_DYNAMIC(CAnother)

public:
	CAnother(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAnother();
	CBrush m_anotherBrsh;
// 对话框数据
	enum { IDD = IDD_ANOTHER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//virtual void OnOK();
	//virtual void OnCancel();
	//afx_msg void OnDestroy();
//	afx_msg void OnClose();
};
