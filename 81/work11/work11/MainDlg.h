#pragma once


// CMainDlg �Ի���

class CMainDlg : public CDialog
{
	DECLARE_DYNAMIC(CMainDlg)

public:
	CMainDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMainDlg();
	
	BOOL IsPreview;

// �Ի�������
	enum { IDD = IDD_MAINDLG };
	CListCtrl m_list;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	afx_msg void OnPrint();
	afx_msg void OnQuit();

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
