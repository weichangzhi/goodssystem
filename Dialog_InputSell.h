#if !defined(AFX_DIALOG_INPUTSELL_H__4D5F9C6F_E7B0_4878_85B5_F18780233ACA__INCLUDED_)
#define AFX_DIALOG_INPUTSELL_H__4D5F9C6F_E7B0_4878_85B5_F18780233ACA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog_InputSell.h : header file
//
#include "Preview.h"
/////////////////////////////////////////////////////////////////////////////
// CDialog_InputSell dialog

struct SortList{
	CListCtrl *listctrl;                 //CListCtrl控件指针
	int isub;        //l列号
	int seq;        //1为升序，0为降序
};

class CDialog_InputSell : public CDialog
{
// Construction
public:
	CDialog_InputSell(CWnd* pParent = NULL);   // standard constructor
	
// Dialog Data
	//{{AFX_DATA(CDialog_InputSell)
	enum { IDD = IDD_DIALOG_INPUT_SELL };
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
	CString m_strProduct;//一次出货的记录
	BOOL m_bModify;
	CString	m_strLogId;
	BOOL m_bBtnModify;
	BOOL m_bSortAscending;
	CString	m_strMoney;
	CString	m_strSellName;
	CString	m_strSellPhone;
	CString	m_strTips;
	CString	m_strUint;
	CString	m_strUserAddress;
	CString	m_strUserName;
	CString	m_strUserPhone;
	int     m_dModifyProCount;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog_InputSell)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

	int CALLBACK CompareFunc(LPARAM lParam1, LPARAM lParam2,LPARAM lParamSort);
	void SetPreviewDlg(CPreview *PreviewDlg);
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog_InputSell)
	virtual BOOL OnInitDialog();
	afx_msg void OnAddToList();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnRclickLISTProduct(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDelete();
	afx_msg void OnSetfocusEditInputsellTotalprice();
	afx_msg void OnDblclkLISTProduct(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClose();
	afx_msg void OnButpreview();
	afx_msg void OnButprint();
	afx_msg void OnSetfocusEditInputsellMoney();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_INPUTSELL_H__4D5F9C6F_E7B0_4878_85B5_F18780233ACA__INCLUDED_)
