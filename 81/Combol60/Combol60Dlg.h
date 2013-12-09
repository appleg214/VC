// Combol60Dlg.h : header file
//

#if !defined(AFX_COMBOL60DLG_H__F8533A8D_EC67_4E55_AA68_2EBA3E596AFA__INCLUDED_)
#define AFX_COMBOL60DLG_H__F8533A8D_EC67_4E55_AA68_2EBA3E596AFA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCombol60Dlg dialog

class CCombol60Dlg : public CDialog
{
// Construction
public:
	CCombol60Dlg(CWnd* pParent = NULL);	// standard constructor
	CComboBox m_combol;
// Dialog Data
	//{{AFX_DATA(CCombol60Dlg)
	enum { IDD = IDD_COMBOL60_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCombol60Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCombol60Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOL60DLG_H__F8533A8D_EC67_4E55_AA68_2EBA3E596AFA__INCLUDED_)
