// 2008CombotestDlg.h : ͷ�ļ�
//

#pragma once


// CMy2008CombotestDlg �Ի���
class CMy2008CombotestDlg : public CDialog
{
// ����
public:
	CMy2008CombotestDlg(CWnd* pParent = NULL);	// ��׼���캯��
	CComboBox m_combo;
// �Ի�������
	enum { IDD = IDD_MY2008COMBOTEST_DIALOG };

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
};
