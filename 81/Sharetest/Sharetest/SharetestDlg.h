
// SharetestDlg.h : ͷ�ļ�
//
#include "SecondDlg.h"
#include "FirstDlg.h"

#pragma once


// CSharetestDlg �Ի���
class CSharetestDlg : public CDialogEx
{
// ����
public:
	CSharetestDlg(CWnd* pParent = NULL);	// ��׼���캯��
	CFirstDlg firstdlg;
	CSecondDlg seconddlg;
// �Ի�������
	enum { IDD = IDD_SHARETEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
