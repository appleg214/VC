
// ControlText1Dlg.h : ͷ�ļ�
//

#pragma once


// CControlText1Dlg �Ի���
class CControlText1Dlg : public CDialogEx
{
// ����
public:
	CControlText1Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	CListBox m_list;
	CEdit m_edit;
// �Ի�������
	enum { IDD = IDD_CONTROLTEXT1_DIALOG };

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
	afx_msg void OnBnClickedDeleteallButton();
	afx_msg void OnBnClickedAddButton();
	afx_msg void OnBnClickedReinputButton();
	afx_msg void OnBnClickedUpButton();
};
