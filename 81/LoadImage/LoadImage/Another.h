#pragma once


// CAnother �Ի���

class CAnother : public CDialog
{
	DECLARE_DYNAMIC(CAnother)

public:
	CAnother(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAnother();
	CBrush m_anotherBrsh;
// �Ի�������
	enum { IDD = IDD_ANOTHER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//virtual void OnOK();
	//virtual void OnCancel();
	//afx_msg void OnDestroy();
//	afx_msg void OnClose();
};
