#pragma once


// CAnother �Ի���

class CAnother : public CDialog
{
	DECLARE_DYNAMIC(CAnother)

public:
	CAnother(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAnother();

// �Ի�������
	enum { IDD = IDD_ANOTHER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
