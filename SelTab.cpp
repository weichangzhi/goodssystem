// SelTab.cpp : implementation file
//

#include "stdafx.h"
#include "GoodsManageSystem.h"
#include "SelTab.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSelTab

CSelTab::CSelTab()
{
}

CSelTab::~CSelTab()
{
	delete m_pClient;
	delete m_pSell;
	delete m_pbuy;
}


BEGIN_MESSAGE_MAP(CSelTab, CTabCtrl)
	//{{AFX_MSG_MAP(CSelTab)
	ON_NOTIFY_REFLECT(TCN_SELCHANGE, OnSelchange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSelTab message handlers

void CSelTab::OnSelchange(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CRect rect;
	GetClientRect(rect); //获取客户区域
	rect.DeflateRect(1,30,2,2);
	int cursel = this->GetCurSel(); //获取当前标签索引 
	switch (cursel)
	{
	case 0: 
		{
			m_pSell->ShowWindow(SW_HIDE); 
			m_pbuy->ShowWindow(SW_HIDE); 
			m_pClient->MoveWindow(rect);	
			m_pClient->ShowWindow(SW_SHOW);
			break;
		}
	case 1: 
		{
			m_pClient->ShowWindow(SW_HIDE);
			m_pbuy->ShowWindow(SW_HIDE);
			m_pSell->MoveWindow(rect);
			m_pSell->ShowWindow(SW_SHOW);
			break;
		}
	case 2:
		{
			m_pClient->ShowWindow(SW_HIDE);
			m_pSell->ShowWindow(SW_HIDE);
			m_pbuy->MoveWindow(rect);
			m_pbuy->ShowWindow(SW_SHOW);
			break;
		}		

	*pResult = 0;
	}
}
