#if !defined(AFX_SELTAB_H__F628BAE5_CA06_48D4_8B92_3B652CD1D06D__INCLUDED_)
#define AFX_SELTAB_H__F628BAE5_CA06_48D4_8B92_3B652CD1D06D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SelTab.h : header file
//
#include "DIALOG_CLIENT.h"
#include "Dialog_SELL.h"
#include "DIALOG_BUY.h"
/////////////////////////////////////////////////////////////////////////////
// CSelTab window

class CSelTab : public CTabCtrl
{
// Construction
public:
	CSelTab();
	CDIALOG_CLIENT* m_pClient;
	CDialog_SELL*   m_pSell;
	CDIALOG_BUY*    m_pbuy;
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSelTab)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSelTab();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSelTab)
	afx_msg void OnSelchange(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELTAB_H__F628BAE5_CA06_48D4_8B92_3B652CD1D06D__INCLUDED_)
