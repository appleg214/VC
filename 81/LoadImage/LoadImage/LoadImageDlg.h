
// LoadImageDlg.h : ͷ�ļ�
//
#include "Another.h"
#pragma once


// CLoadImageDlg �Ի���
class CLoadImageDlg : public CDialogEx
{
// ����
public:
	CLoadImageDlg(CWnd* pParent = NULL);	// ��׼���캯��
	CAnother anotherDlg;

// �Ի�������
	enum { IDD = IDD_LOADIMAGE_DIALOG };

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
	CStatic m_Image;
	afx_msg void OnBnClickedOk();
};
