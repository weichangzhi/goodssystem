// DIALOG_CLIENT.cpp : implementation file
//

#include "stdafx.h"
#include "GoodsManageSystem.h"
#include "DIALOG_CLIENT.h"
#include "DIALOG_INPUT_CLIENT.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDIALOG_CLIENT dialog


CDIALOG_CLIENT::CDIALOG_CLIENT(CWnd* pParent /*=NULL*/)
	: CDialog(CDIALOG_CLIENT::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDIALOG_CLIENT)
	m_strInput = _T("");
	//}}AFX_DATA_INIT
}


void CDIALOG_CLIENT::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDIALOG_CLIENT)
	DDX_Control(pDX, IDC_LIST_CLIENT, m_list_Clinet);
	DDX_Control(pDX, IDC_COMBO_CLIENT, m_com_Client);
	DDX_Text(pDX, IDC_EDIT_CLIENT, m_strInput);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDIALOG_CLIENT, CDialog)
	//{{AFX_MSG_MAP(CDIALOG_CLIENT)
	ON_BN_CLICKED(IDC_BUTTON_CLIENT_ADD, OnButtonClientAdd)
	ON_BN_CLICKED(IDC_BUTTON_CLIENT_SELECT, OnButtonClientSelect)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_CLIENT, OnDblclkListClient)
	ON_COMMAND(ID_MENUITEM_INPUTSELL,OnDelete)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_CLIENT, OnRclickListClient)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST_CLIENT, OnColumnclickListClient)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDIALOG_CLIENT message handlers

BOOL CDIALOG_CLIENT::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_com_Client.InsertString(0,"公司名称");
	m_com_Client.InsertString(1,"纳税人识别号");
	m_com_Client.InsertString(2,"开户行和账号");
	m_com_Client.InsertString(3,"地址和电话");
	m_com_Client.SetCurSel(0);

	CRect rect;
    GetClientRect(&rect);
	//m_list_Clinet = new CSortListCtrl();
	//m_list_Clinet.Create(WS_CHILD|WS_VISIBLE|WS_BORDER|LVS_REPORT,
		//CRect(0,30,rect.Width(),rect.Height()-30),this,IDC_LIST_CLIENT);
	m_list_Clinet.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_list_Clinet.InsertColumn(0, _T("记录号"), LVCFMT_LEFT,50);
	m_list_Clinet.InsertColumn(1, _T("公司名称"), LVCFMT_LEFT,150);
	m_list_Clinet.InsertColumn(2, _T("纳税人识别号"), LVCFMT_LEFT,150);
	m_list_Clinet.InsertColumn(3, _T("开户行和账号"), LVCFMT_LEFT,200);
    m_list_Clinet.InsertColumn(4, _T("地址和电话"), LVCFMT_LEFT,200);
	m_list_Clinet.InsertColumn(5, _T("收货人"), LVCFMT_LEFT,60);
	m_list_Clinet.InsertColumn(6, _T("邮寄地址和电话"), LVCFMT_LEFT,200);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CDIALOG_CLIENT::OnButtonClientAdd() 
{
	// TODO: Add your control notification handler code here
	CDIALOG_INPUT_CLIENT InputClient;
	if (InputClient.DoModal()==IDOK)
	{
		m_list_Clinet.DeleteAllItems();
		CString strLogID;
		strLogID.Format("%d",InputClient.m_dLogId);
		m_list_Clinet.InsertItem(0,strLogID);
		m_list_Clinet.SetItemText(0,1,InputClient.m_strCompanyName);
		m_list_Clinet.SetItemText(0,2,InputClient.m_strTaxIndex);
		m_list_Clinet.SetItemText(0,3,InputClient.m_strBank);
		m_list_Clinet.SetItemText(0,4,InputClient.m_strAddress);
		m_list_Clinet.SetItemText(0,5,InputClient.m_strReceiver);
		m_list_Clinet.SetItemText(0,6,InputClient.m_strMail);

// 		CString sql;
// 		sql.Format("insert into client(logid,companyname,taxindex,bank_no,address_pho,receiver,mail_phone) values (%d,\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\")",
// 		          InputClient.m_dLogId,InputClient.m_strCompanyName,InputClient.m_strTaxIndex,InputClient.m_strBank,InputClient.m_strAddress,InputClient.m_strReceiver,InputClient.m_strMail);
// 		if(!g_adoDataSet.ExecSql(sql))
// 		{
// 			MessageBox("插入数据库失败","提示",MB_OK);
// 			return ;
// 		}
	}
	else
	{
		return;
	}
}

void CDIALOG_CLIENT::OnButtonClientSelect() 
{
	// TODO: Add your control notification handler code here
	m_list_Clinet.DeleteAllItems();
	UpdateData();
	CString csSql;
	m_strInput.TrimLeft();
	m_strInput.TrimRight();
	if (m_strInput.IsEmpty())
	{	
		csSql.Format("select * from client");	
	}
	else
	{
		int indexSel = m_com_Client.GetCurSel();
		switch(indexSel)
		{
		case 0:
			csSql = "select * from client where companyname like '%"+m_strInput+"%'";
			break;
		case 1:
			csSql = "select * from client where taxindex like '%"+m_strInput+"%'";
			break;
		case 2:
			csSql = "select * from client where bank_no like '%"+m_strInput+"%'";
			break;
		case 3:
			csSql = "select * from client where address_pho like '%"+m_strInput+"%'";
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
	CString strid,strComName,strTax,strBank,strAddress,strReceiver,strMail;
	while (!g_adoDataSet.IsEof())
	{
		if(!g_adoDataSet.GetCollect("logid",strid)) return;
		if(!g_adoDataSet.GetCollect("companyname",strComName)) return;
		if(!g_adoDataSet.GetCollect("taxindex",strTax)) return;
		if(!g_adoDataSet.GetCollect("bank_no",strBank)) return;
		if(!g_adoDataSet.GetCollect("address_pho",strAddress)) return;
		if(!g_adoDataSet.GetCollect("receiver",strReceiver)) return;
		if(!g_adoDataSet.GetCollect("mail_phone",strMail)) return;
		m_list_Clinet.InsertItem(index,strid);
		m_list_Clinet.SetItemText(index,1,strComName);
		m_list_Clinet.SetItemText(index,2,strTax);
		m_list_Clinet.SetItemText(index,3,strBank);
		m_list_Clinet.SetItemText(index,4,strAddress);
		m_list_Clinet.SetItemText(index,5,strReceiver);
		m_list_Clinet.SetItemText(index,6,strMail);
		index++;
		g_adoDataSet.MoveNext();
	}
}


void CDIALOG_CLIENT::OnDblclkListClient(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int sel=m_list_Clinet.GetSelectionMark();
	if(sel==-1) return ;
	CDIALOG_INPUT_CLIENT InputClient;
	InputClient.m_bModify = 1;
	InputClient.m_dLogId         = atoi(m_list_Clinet.GetItemText(sel,0));
	InputClient.m_strCompanyName = m_list_Clinet.GetItemText(sel,1);
	InputClient.m_strTaxIndex    = m_list_Clinet.GetItemText(sel,2);
	InputClient.m_strBank        = m_list_Clinet.GetItemText(sel,3);
	InputClient.m_strAddress     = m_list_Clinet.GetItemText(sel,4);
	InputClient.m_strReceiver    = m_list_Clinet.GetItemText(sel,5);
	InputClient.m_strMail        = m_list_Clinet.GetItemText(sel,6);
	if(InputClient.DoModal()==IDOK)
	{
		if(MessageBox("确定要修改用户资料?","提示",MB_OKCANCEL)==IDOK)
		{
			CString sql;	
			sql.Format("update client set companyname=\"%s\",taxindex=\"%s\",bank_no=\"%s\",address_pho=\"%s\",receiver=\"%s\",mail_phone=\"%s\" where logid=%d",
				InputClient.m_strCompanyName,InputClient.m_strTaxIndex,InputClient.m_strBank,InputClient.m_strAddress,InputClient.m_strReceiver,InputClient.m_strMail,InputClient.m_dLogId);
			if(!g_adoDataSet.ExecSql(sql))
			{
				MessageBox("修改数据库失败","提示",MB_OK);
				return ;
			}
			CString strLogID ;
			strLogID.Format("%d",InputClient.m_dLogId);
			m_list_Clinet.SetItemText(sel,0,strLogID);
			m_list_Clinet.SetItemText(sel,1,InputClient.m_strCompanyName);
			m_list_Clinet.SetItemText(sel,2,InputClient.m_strTaxIndex);
			m_list_Clinet.SetItemText(sel,3,InputClient.m_strBank);
			m_list_Clinet.SetItemText(sel,4,InputClient.m_strAddress);
			m_list_Clinet.SetItemText(sel,5,InputClient.m_strReceiver);
			m_list_Clinet.SetItemText(sel,6,InputClient.m_strMail);
		}
	}
	*pResult = 0;
}

void CDIALOG_CLIENT::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	//CDialog::OnCancel();
}

void CDIALOG_CLIENT::OnRclickListClient(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CMenu       menu ,* pSubMenu;//定义下面要用到的cmenu对象	
	menu.LoadMenu(IDR_MENU1);//装载自定义的右键菜单
	pSubMenu = menu.GetSubMenu(0);//获取第一个弹出菜单，所以第一个菜单必须有子菜单	
    CPoint oPoint;//定义一个用于确定光标位置的位置	
    GetCursorPos( &oPoint);//获取当前光标的位置，以便使得菜单可以跟随光标
	int istat=m_list_Clinet.GetSelectionMark();//用istat存放当前选定的是第几项	
	if(istat == -1) return;
	pSubMenu->TrackPopupMenu (TPM_LEFTALIGN, oPoint.x, oPoint.y, this); //在指定位置显示弹出菜单
	*pResult = 0;
}

void CDIALOG_CLIENT::OnDelete()
{
	int istat=m_list_Clinet.GetSelectionMark();
	if(istat == -1) return;
	CString strComName = m_list_Clinet.GetItemText(istat,1);
	CString strTips ;
	strTips.Format("确定要删除%s这个客户吗?",strComName);
	int ret = MessageBox(strTips,"提示",MB_OKCANCEL);
	if (ret==IDOK)
	{
		int dLogID  = atoi(m_list_Clinet.GetItemText(istat,0));
		CString sql;
		sql.Format("delete from client where logid=%d",dLogID);
		if(!g_adoDataSet.ExecSql(sql))
		{
			MessageBox("删除数据库失败","提示",MB_OK);
			return ;
		}
		m_list_Clinet.DeleteItem(istat);
		strTips.Format("删除客户%s成功.",strComName);
		MessageBox(strTips,"提示",MB_OK);
	}
	
}

void CDIALOG_CLIENT::OnColumnclickListClient(NMHDR* pNMHDR, LRESULT* pResult) 
{
	//NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	
	int i,nItemCounter; 
	NM_LISTVIEW * pNMListView = (NM_LISTVIEW*)pNMHDR; 
	CListCtrl * pListCtrl = &m_list_Clinet; 
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
