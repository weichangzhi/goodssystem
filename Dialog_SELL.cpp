// Dialog_SELL.cpp : implementation file
//

#include "stdafx.h"
#include "GoodsManageSystem.h"
#include "Dialog_SELL.h"
#include "Dialog_InputSell.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialog_SELL dialog


CDialog_SELL::CDialog_SELL(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_SELL::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog_SELL)
	m_strInput = _T("");
	//}}AFX_DATA_INIT
}


void CDialog_SELL::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog_SELL)
	DDX_Control(pDX, IDC_COMBO_SELL, m_com_Sell);
	DDX_Control(pDX, IDC_LIST_SELL, m_list_Sell);
	DDX_Text(pDX, IDC_EDIT_SELL, m_strInput);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog_SELL, CDialog)
	//{{AFX_MSG_MAP(CDialog_SELL)
	ON_BN_CLICKED(IDC_BUTTON_SELL_ADD, OnButtonSellAdd)
	ON_BN_CLICKED(IDC_BUTTON_SELL_SELECT, OnButtonSellSelect)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_SELL, OnDblclkListSell)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_SELL, OnRclickListSell)
	ON_COMMAND(ID_MENUITEM_INPUTSELL,OnDelete) 
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST_SELL, OnColumnclickListSell)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog_SELL message handlers

BOOL CDialog_SELL::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_com_Sell.InsertString(0,"日期");
	m_com_Sell.InsertString(1,"公司名称");
	m_com_Sell.InsertString(2,"产品型号");
	m_com_Sell.SetCurSel(1);
	
	m_list_Sell.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_list_Sell.InsertColumn(0, _T("出货单号"), LVCFMT_LEFT,120);
	m_list_Sell.InsertColumn(1, _T("日期"), LVCFMT_LEFT,100);
	m_list_Sell.InsertColumn(2, _T("公司名称"), LVCFMT_LEFT,150);
	m_list_Sell.InsertColumn(3, _T("产品型号(数量*价格)"), LVCFMT_LEFT,475);
	m_list_Sell.InsertColumn(4, _T("总价[元]"), LVCFMT_LEFT,90);
	m_list_Sell.InsertColumn(5, _T("出货价格[元]"), LVCFMT_LEFT,90);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDialog_SELL::OnButtonSellAdd() 
{
	// TODO: Add your control notification handler code here
	CDialog_InputSell InputSell;
	if (InputSell.DoModal()==IDOK)
	{
		m_list_Sell.DeleteAllItems();
		m_list_Sell.InsertItem(0,InputSell.m_strLogId);
		m_list_Sell.SetItemText(0,1,InputSell.m_strTime);
		m_list_Sell.SetItemText(0,2,InputSell.m_strComName);
		m_list_Sell.SetItemText(0,3,InputSell.m_strProduct);
		m_list_Sell.SetItemText(0,4,InputSell.m_strTotalPrice);
		m_list_Sell.SetItemText(0,5,InputSell.m_strSellPrice);

// 		CString sql;
// 		sql.Format("insert into sellproduct(logid,strdate,companyname,productinfo,totalprice,sellprice) values (%d,\"%s\",\"%s\",\"%s\",\"%s\",\"%s\")",
// 			InputSell.m_dLogId,InputSell.m_strTime,InputSell.m_strComName,InputSell.m_strProduct,InputSell.m_strTotalPrice,InputSell.m_strSellPrice);
// 		if(!g_adoDataSet.ExecSql(sql))
// 		{
// 			MessageBox("插入数据库失败","提示",MB_OK);
// 			return ;
// 		}
	}
}

void CDialog_SELL::OnButtonSellSelect() 
{
	// TODO: Add your control notification handler code here
	m_list_Sell.DeleteAllItems();
	UpdateData();
	CString csSql;
	m_strInput.TrimLeft();
	m_strInput.TrimRight();
	if (m_strInput.IsEmpty())
	{	
		csSql.Format("select * from sellproduct");	
	}
	else
	{
		int indexSel = m_com_Sell.GetCurSel();
		switch(indexSel)
		{
		case 0:
			csSql = "select * from sellproduct where strdate like '%"+m_strInput+"%'";
			break;
		case 1:
			csSql = "select * from sellproduct where companyname like '%"+m_strInput+"%'";
			break;
		case 2:
			csSql = "select * from sellproduct where productinfo like '%"+m_strInput+"%'";
			break;
		default:
			;
		}	
	}
	if (!g_adoDataSet.Open(csSql,CADODataset::openQuery))
		return ;
	
	DWORD dwCnt	 = g_adoDataSet.GetRecordCount();	
	if (dwCnt<=0)
		return ;
	int index=0;
	CString strLogId,strComName,strdate,strProductInfo,strTotalPri,strSellPri;
	while (!g_adoDataSet.IsEof())
	{
		if(!g_adoDataSet.GetCollect("logid",strLogId)) return;
		if(!g_adoDataSet.GetCollect("strdate",strdate)) return;
		if(!g_adoDataSet.GetCollect("companyname",strComName)) return;
		if(!g_adoDataSet.GetCollect("productinfo",strProductInfo)) return;
		if(!g_adoDataSet.GetCollect("totalprice",strTotalPri)) return;
		if(!g_adoDataSet.GetCollect("sellprice",strSellPri)) return;
		m_list_Sell.InsertItem(index,strLogId);
		m_list_Sell.SetItemText(index,1,strdate);
		m_list_Sell.SetItemText(index,2,strComName);
		m_list_Sell.SetItemText(index,3,strProductInfo);
		m_list_Sell.SetItemText(index,4,strTotalPri);
		m_list_Sell.SetItemText(index,5,strSellPri);
		index++;
		g_adoDataSet.MoveNext();
	}
}

void CDialog_SELL::OnDblclkListSell(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int sel=m_list_Sell.GetSelectionMark();
	if(sel==-1) return;
	CDialog_InputSell InputSell;
	InputSell.m_bModify       = 1;
	InputSell.m_strLogId        = m_list_Sell.GetItemText(sel,0);
// 	InputSell.m_strTime       = m_list_Sell.GetItemText(sel,1);
// 	InputSell.m_strComName    = m_list_Sell.GetItemText(sel,2);
// 	InputSell.m_strProduct    = m_list_Sell.GetItemText(sel,3);
// 	InputSell.m_strTotalPrice = m_list_Sell.GetItemText(sel,4);
// 	InputSell.m_strSellPrice  = m_list_Sell.GetItemText(sel,5);
	if(InputSell.DoModal()==IDOK)
	{
		//if(MessageBox("确定要修改出货资料?","提示",MB_OKCANCEL)==IDOK)
		{
// 			CString sql;	
// 			sql.Format("update sellproduct set strdate=\"%s\",companyname=\"%s\",productinfo=\"%s\",totalprice=\"%s\",sellprice=\"%s\" where logid=\"%s\"",
// 				InputSell.m_strTime,InputSell.m_strComName,InputSell.m_strProduct,InputSell.m_strTotalPrice,InputSell.m_strSellPrice,InputSell.m_strLogId);
// 			if(!g_adoDataSet.ExecSql(sql))
// 			{
// 				MessageBox("修改数据库失败","提示",MB_OK);
// 				return ;
// 			}
			m_list_Sell.SetItemText(sel,0,InputSell.m_strLogId);
			m_list_Sell.SetItemText(sel,1,InputSell.m_strTime);
			m_list_Sell.SetItemText(sel,2,InputSell.m_strComName);
			m_list_Sell.SetItemText(sel,3,InputSell.m_strProduct);
			m_list_Sell.SetItemText(sel,4,InputSell.m_strTotalPrice);
			m_list_Sell.SetItemText(sel,5,InputSell.m_strSellPrice);
	
// 			CString sql;
// 			sql.Format("insert into sellproduct(logid,strdate,companyname,productinfo,totalprice,sellprice,useraddress,userphone,username,sellername,sellerphone)values(\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\")", 
// 				m_strLogId,m_strTime,m_strComName,m_strProduct,m_strTotalPrice,m_strSellPrice,m_strUserAddress,m_strUserPhone,m_strUserName,m_strSellName,m_strSellPhone);
// 			if(!g_adoDataSet.ExecSql(sql))
// 			{
// 				MessageBox("插入数据库失败","提示",MB_OK);
// 				return ;
// 			}
// 			
// 			
// 			sql.Format("select * from oneproduct order by productindex desc");
// 			BOOL bRlt = g_adoDataSet.Open(sql,CADODataset::openQuery);	
// 			if(!bRlt)
// 			{
// 				return ;
// 			}
// 			DWORD dwCnt	 = g_adoDataSet.GetRecordCount();
// 			CString strProductIndex;
// 			bRlt = g_adoDataSet.GetCollect("productindex",strProductIndex);
// 			int dProductIndex = atoi(strProductIndex);
// 			int index = 0;
// 			for (index = 0; index < nCount; index++)
// 			{
// 				CString strProType  = m_list_Product.GetItemText(index,0);
// 				CString strProPrice = m_list_Product.GetItemText(index,1);
// 				CString strProCount = m_list_Product.GetItemText(index,2);
// 				CString strUint     = m_list_Product.GetItemText(index,3);
// 				CString strMoney    = m_list_Product.GetItemText(index,4);
// 				CString strTips     = m_list_Product.GetItemText(index,5);
// 				
// 				sql.Format("insert into oneproduct(productindex,logid,protype,proprice,procount,prouint,promoney,protips) values (%d,\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\")",
// 					++dProductIndex,m_strLogId,strProType,strProPrice,strProCount,strUint,strMoney,strTips);
// 				if(!g_adoDataSet.ExecSql(sql))
// 				{
// 					MessageBox("插入数据库失败","提示",MB_OK);
// 					return ;
// 				}
// 			}


		}
	}
	
	*pResult = 0;
}

void CDialog_SELL::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	//CDialog::OnCancel();
}

void CDialog_SELL::OnRclickListSell(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CMenu       menu ,* pSubMenu;//定义下面要用到的cmenu对象	
	menu.LoadMenu(IDR_MENU1);//装载自定义的右键菜单
	pSubMenu = menu.GetSubMenu(0);//获取第一个弹出菜单，所以第一个菜单必须有子菜单	
    CPoint oPoint;//定义一个用于确定光标位置的位置	
    GetCursorPos( &oPoint);//获取当前光标的位置，以便使得菜单可以跟随光标
	int istat=m_list_Sell.GetSelectionMark();//用istat存放当前选定的是第几项	
	if(istat == -1) return;
	pSubMenu->TrackPopupMenu (TPM_LEFTALIGN, oPoint.x, oPoint.y, this); //在指定位置显示弹出菜单
	*pResult = 0;
}

void CDialog_SELL::OnDelete()
{
	int istat=m_list_Sell.GetSelectionMark();
	if(istat == -1) return;
	CString strComName = m_list_Sell.GetItemText(istat,2);
	CString strTips ;
	strTips.Format("确定要删除%s这个客户记录吗?",strComName);
	int ret = MessageBox(strTips,"提示",MB_OKCANCEL);
	if (ret==IDOK)
	{
		int dLogID  = atoi(m_list_Sell.GetItemText(istat,0));
		CString sql;
		sql.Format("delete from sellproduct where logid=%d",dLogID);
		if(!g_adoDataSet.ExecSql(sql))
		{
			MessageBox("删除数据库失败","提示",MB_OK);
			return ;
		}
		m_list_Sell.DeleteItem(istat);
		strTips.Format("删除客户%s的记录成功.",strComName);
		MessageBox(strTips,"提示",MB_OK);
	}
}

void CDialog_SELL::OnColumnclickListSell(NMHDR* pNMHDR, LRESULT* pResult) 
{
	//NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	
	int i,nItemCounter; 
	NM_LISTVIEW * pNMListView = (NM_LISTVIEW*)pNMHDR; 
	CListCtrl * pListCtrl = &m_list_Sell; 
	nColToSort=pNMListView->iSubItem; 
	if(nLastColToSort!=nColToSort) 
	{ 
		bDesc=0; 
		nLastColToSort=nColToSort; 
	} 
	else 
		bDesc=bDesc?0:1; 
	nItemCounter=pListCtrl->GetItemCount(); 
	for(i=0;i<nItemCounter;i++) 
		pListCtrl->SetItemData(i,i); 
	pListCtrl->SortItems(SortLVProc,(LPARAM)pListCtrl); 
	*pResult = 0;
}
