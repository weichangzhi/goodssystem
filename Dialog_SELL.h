#if !defined(AFX_DIALOG_SELL_H__0C1CF9A8_0E6F_4CCB_9F6D_24AD0C560637__INCLUDED_)
#define AFX_DIALOG_SELL_H__0C1CF9A8_0E6F_4CCB_9F6D_24AD0C560637__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog_SELL.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog_SELL dialog

class CDialog_SELL : public CDialog
{
// Construction
public:
	CDialog_SELL(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog_SELL)
	enum { IDD = IDD_DIALOG_SELL };
	CComboBox	m_com_Sell;
	CListCtrl	m_list_Sell;
	CString	m_strInput;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog_SELL)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog_SELL)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonSellAdd();
	afx_msg void OnButtonSellSelect();
	afx_msg void OnDblclkListSell(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnCancel();
	afx_msg void OnRclickListSell(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDelete();
	afx_msg void OnColumnclickListSell(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_SELL_H__0C1CF9A8_0E6F_4CCB_9F6D_24AD0C560637__INCLUDED_)
