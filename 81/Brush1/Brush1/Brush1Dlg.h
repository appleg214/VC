
// Brush1Dlg.h : ͷ�ļ�
//
#include "Another.h"
#pragma once


// CBrush1Dlg �Ի���
class CBrush1Dlg : public CDialogEx
{
// ����
public:
	CBrush1Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	CBrush picBrush;
	CAnother anotherDlg;
// �Ի�������
	enum { IDD = IDD_BRUSH1_DIALOG };

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
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedOk();
};
