
// StaticMenuDlg.h : ͷ�ļ�
//

#pragma once


// CStaticMenuDlg �Ի���
class CStaticMenuDlg : public CDialogEx
{
// ����
public:
	CStaticMenuDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CStaticMenuDlg();
	CMenu *m_menu;
// �Ի�������
	enum { IDD = IDD_STATICMENU_DIALOG };

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
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};
