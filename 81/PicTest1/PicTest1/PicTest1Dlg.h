
// PicTest1Dlg.h : ͷ�ļ�
//

#pragma once


// CPicTest1Dlg �Ի���
class CPicTest1Dlg : public CDialogEx
{
// ����
public:
	CPicTest1Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	CBrush m_brbk;
// �Ի�������
	enum { IDD = IDD_PICTEST1_DIALOG };

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
};
