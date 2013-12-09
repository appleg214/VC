#pragma once


// CAnother 对话框

class CAnother : public CDialog
{
	DECLARE_DYNAMIC(CAnother)

public:
	CAnother(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAnother();

// 对话框数据
	enum { IDD = IDD_ANOTHER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
