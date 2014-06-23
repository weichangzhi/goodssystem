#if !defined(AFX_DIALOG_INPUTBUY_H__B6BF0EBD_C119_47C9_B146_698183560B6C__INCLUDED_)
#define AFX_DIALOG_INPUTBUY_H__B6BF0EBD_C119_47C9_B146_698183560B6C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog_InputBuy.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog_InputBuy dialog

class CDialog_InputBuy : public CDialog
{
// Construction
public:
	CDialog_InputBuy(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog_InputBuy)
	enum { IDD = IDD_DIALOG_INPUT_BUY };
	CListCtrl	m_list_Product;
	CTime	m_time;
	CString	m_strComName;
	CString	m_strProductModel;
	CString	m_strProductNum;
	CString	m_strProductPrice;
	CString	m_strSellPrice;
	CString	m_strTotalPrice;
	CString m_strTime;
	int     m_dProductindex;
	CString m_strProduct;
	long	m_dLogId;
	BOOL m_bModify;
	BOOL m_bBtnModify;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog_InputBuy)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog_InputBuy)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonAdd2();
	afx_msg void OnDblclkLISTProduct2(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnSetfocusEditInputbuyTotalprice();
	afx_msg void OnDelete();
	afx_msg void OnRclickLISTProduct2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_INPUTBUY_H__B6BF0EBD_C119_47C9_B146_698183560B6C__INCLUDED_)
