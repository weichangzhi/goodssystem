// GoodsManageSystemDlg.h : header file
//

#if !defined(AFX_GOODSMANAGESYSTEMDLG_H__A19BCE02_407D_4B17_84B1_7B0103988BEC__INCLUDED_)
#define AFX_GOODSMANAGESYSTEMDLG_H__A19BCE02_407D_4B17_84B1_7B0103988BEC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "SelTab.h"

/////////////////////////////////////////////////////////////////////////////
// CGoodsManageSystemDlg dialog

class CGoodsManageSystemDlg : public CDialog
{
// Construction
public:
	CGoodsManageSystemDlg(CWnd* pParent = NULL);	// standard constructor
	CImageList m_imagelist;

// Dialog Data
	//{{AFX_DATA(CGoodsManageSystemDlg)
	enum { IDD = IDD_GOODSMANAGESYSTEM_DIALOG };
	CSelTab	m_tab;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGoodsManageSystemDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGoodsManageSystemDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnCancel();
	afx_msg void OnClose();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnHelp();
	afx_msg void OnClientAdd();
	afx_msg void OnClientQuery();
	afx_msg void OnSellAdd();
	afx_msg void OnSellQuery();
	afx_msg void OnBuyAdd();
	afx_msg void OnBuyQuery();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GOODSMANAGESYSTEMDLG_H__A19BCE02_407D_4B17_84B1_7B0103988BEC__INCLUDED_)
