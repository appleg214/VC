#pragma once


// CFirstDlg �Ի���

class CFirstDlg : public CDialog
{
	DECLARE_DYNAMIC(CFirstDlg)

public:
	CFirstDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFirstDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_SHARE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_static1;
	CStatic m_static2;
	CStatic m_static3;
	CStatic m_static4;
	CButton m_save;
	virtual BOOL OnInitDialog();
};
