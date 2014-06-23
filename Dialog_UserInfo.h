#if !defined(AFX_DIALOG_USERINFO_H__F7A4BF68_4784_40B6_9B4B_BFA647AFA789__INCLUDED_)
#define AFX_DIALOG_USERINFO_H__F7A4BF68_4784_40B6_9B4B_BFA647AFA789__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog_UserInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Dialog_UserInfo dialog

class Dialog_UserInfo : public CDialog
{
// Construction
public:
	Dialog_UserInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Dialog_UserInfo)
	enum { IDD = IDD_DIALOG_USERINFO };
	CString	m_strPassed;
	CString	m_strUserName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Dialog_UserInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Dialog_UserInfo)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_USERINFO_H__F7A4BF68_4784_40B6_9B4B_BFA647AFA789__INCLUDED_)
