#if !defined(AFX_DIALOG_INPUT_CLIENT_H__E198BFDB_5158_474D_BAB0_A928954A44FD__INCLUDED_)
#define AFX_DIALOG_INPUT_CLIENT_H__E198BFDB_5158_474D_BAB0_A928954A44FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DIALOG_INPUT_CLIENT.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDIALOG_INPUT_CLIENT dialog

class CDIALOG_INPUT_CLIENT : public CDialog
{
// Construction
public:
	CDIALOG_INPUT_CLIENT(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDIALOG_INPUT_CLIENT)
	enum { IDD = IDD_DIALOG_INPUT_CLIENT };
	CString	m_strAddress;
	CString	m_strBank;
	CString	m_strCompanyName;
	CString	m_strMail;
	CString	m_strReceiver;
	CString	m_strTaxIndex;
	BOOL    m_bModify;
	long	m_dLogId;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDIALOG_INPUT_CLIENT)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDIALOG_INPUT_CLIENT)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_INPUT_CLIENT_H__E198BFDB_5158_474D_BAB0_A928954A44FD__INCLUDED_)
