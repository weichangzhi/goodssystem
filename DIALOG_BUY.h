#if !defined(AFX_DIALOG_BUY_H__5F7B3A19_7393_4919_8E50_7B38A7AEC5F9__INCLUDED_)
#define AFX_DIALOG_BUY_H__5F7B3A19_7393_4919_8E50_7B38A7AEC5F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DIALOG_BUY.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDIALOG_BUY dialog

class CDIALOG_BUY : public CDialog
{
// Construction
public:
	CDIALOG_BUY(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDIALOG_BUY)
	enum { IDD = IDD_DIALOG_BUY };
	CListCtrl	m_list_Buy;
	CComboBox	m_com_buy;
	CString	m_strInput;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDIALOG_BUY)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDIALOG_BUY)
	afx_msg void OnButtonBuyAdd();
	afx_msg void OnButtonBuySelect();
	afx_msg void OnDblclkListBuy(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	afx_msg void OnRclickListBuy(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDelete();
	afx_msg void OnColumnclickListBuy(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_BUY_H__5F7B3A19_7393_4919_8E50_7B38A7AEC5F9__INCLUDED_)
