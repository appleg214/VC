#pragma once


// CSecondDlg �Ի���

class CSecondDlg : public CDialog
{
	DECLARE_DYNAMIC(CSecondDlg)

public:
	CSecondDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSecondDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_SHARE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CButton m_save;
	CStatic m_static1;
	CStatic m_static2;
	CStatic m_static3;
	CStatic m_static4;
	virtual BOOL OnInitDialog();
};
