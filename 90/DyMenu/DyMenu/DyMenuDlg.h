
// DyMenuDlg.h : ͷ�ļ�
//

#pragma once


// CDyMenuDlg �Ի���
class CDyMenuDlg : public CDialogEx
{
// ����
public:
	CDyMenuDlg(CWnd* pParent = NULL);	// ��׼���캯��
	CMenu m_menu;
// �Ի�������
	enum { IDD = IDD_DYMENU_DIALOG };

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
	afx_msg void OnOperator();
	DECLARE_MESSAGE_MAP()
};
