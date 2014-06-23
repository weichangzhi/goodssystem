// DIALOG_BUY.cpp : implementation file
//

#include "stdafx.h"
#include "GoodsManageSystem.h"
#include "DIALOG_BUY.h"
#include "Dialog_InputBuy.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDIALOG_BUY dialog


CDIALOG_BUY::CDIALOG_BUY(CWnd* pParent /*=NULL*/)
	: CDialog(CDIALOG_BUY::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDIALOG_BUY)
	m_strInput = _T("");
	//}}AFX_DATA_INIT
}


void CDIALOG_BUY::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDIALOG_BUY)
	DDX_Control(pDX, IDC_LIST_BUY, m_list_Buy);
	DDX_Control(pDX, IDC_COMBO_BUY, m_com_buy);
	DDX_Text(pDX, IDC_EDIT_BUY, m_strInput);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDIALOG_BUY, CDialog)
	//{{AFX_MSG_MAP(CDIALOG_BUY)
	ON_BN_CLICKED(IDC_BUTTON_BUY_ADD, OnButtonBuyAdd)
	ON_BN_CLICKED(IDC_BUTTON_BUY_SELECT, OnButtonBuySelect)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_BUY, OnDblclkListBuy)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_BUY, OnRclickListBuy)
	ON_COMMAND(ID_MENUITEM_INPUTSELL,OnDelete)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST_BUY, OnColumnclickListBuy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDIALOG_BUY message handlers
BOOL CDIALOG_BUY::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_com_buy.InsertString(0,"����");
	m_com_buy.InsertString(1,"��˾����");
	m_com_buy.InsertString(2,"��Ʒ�ͺ�");
	m_com_buy.SetCurSel(1);
	
	m_list_Buy.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_list_Buy.InsertColumn(0, _T("��¼��"), LVCFMT_LEFT,50);
	m_list_Buy.InsertColumn(1, _T("����"), LVCFMT_LEFT,100);
	m_list_Buy.InsertColumn(2, _T("��˾����"), LVCFMT_LEFT,200);
	m_list_Buy.InsertColumn(3, _T("��Ʒ�ͺ�(����*�۸�)"), LVCFMT_LEFT,480);
	m_list_Buy.InsertColumn(4, _T("�ܼ�[Ԫ]"), LVCFMT_LEFT,90);
	m_list_Buy.InsertColumn(5, _T("�����۸�[Ԫ]"), LVCFMT_LEFT,90);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CDIALOG_BUY::OnButtonBuyAdd() 
{
	// TODO: Add your control notification handler code here
	CDialog_InputBuy Inputbuy;
	if (Inputbuy.DoModal()==IDOK)
	{
		m_list_Buy.DeleteAllItems();
		CString strLogId;
		strLogId.Format("%d",Inputbuy.m_dLogId);
		m_list_Buy.InsertItem(0,strLogId);
		m_list_Buy.SetItemText(0,1,Inputbuy.m_strTime);
		m_list_Buy.SetItemText(0,2,Inputbuy.m_strComName);
		m_list_Buy.SetItemText(0,3,Inputbuy.m_strProduct);
		m_list_Buy.SetItemText(0,4,Inputbuy.m_strTotalPrice);
		m_list_Buy.SetItemText(0,5,Inputbuy.m_strSellPrice);
// 		CString sql;
// 		sql.Format("insert into buyproduct(logid,strdate,companyname,productinfo,totalprice,sellprice) values (%d,\"%s\",\"%s\",\"%s\",\"%s\",\"%s\")",
// 			Inputbuy.m_dLogId,Inputbuy.m_strTime,Inputbuy.m_strComName,Inputbuy.m_strProduct,Inputbuy.m_strTotalPrice,Inputbuy.m_strSellPrice);
// 		if(!g_adoDataSet.ExecSql(sql))
// 		{
// 			MessageBox("�������ݿ�ʧ��","��ʾ",MB_OK);
// 			return ;
// 		}
	}
	
}

void CDIALOG_BUY::OnButtonBuySelect() 
{
	// TODO: Add your control notification handler code here
	m_list_Buy.DeleteAllItems();
	UpdateData();
	CString csSql;
	m_strInput.TrimLeft();
	m_strInput.TrimRight();
	if (m_strInput.IsEmpty())
	{	
		csSql.Format("select * from buyproduct");	
	}
	else
	{
		int indexSel = m_com_buy.GetCurSel();
		switch(indexSel)
		{
		case 0:
			csSql = "select * from buyproduct where strdate like '%"+m_strInput+"%'";
			break;
		case 1:
			csSql = "select * from buyproduct where companyname like '%"+m_strInput+"%'";
			break;
		case 2:
			csSql = "select * from buyproduct where productinfo like '%"+m_strInput+"%'";
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
		m_list_Buy.InsertItem(index,strLogId);
		m_list_Buy.SetItemText(index,1,strdate);
		m_list_Buy.SetItemText(index,2,strComName);
		m_list_Buy.SetItemText(index,3,strProductInfo);
		m_list_Buy.SetItemText(index,4,strTotalPri);
		m_list_Buy.SetItemText(index,5,strSellPri);
		index++;
		g_adoDataSet.MoveNext();
	}
}

void CDIALOG_BUY::OnDblclkListBuy(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int sel=m_list_Buy.GetSelectionMark();
	if(sel==-1) return;
	CDialog_InputBuy Inputbuy;
	Inputbuy.m_bModify       = 1;
	Inputbuy.m_dLogId        = atoi(m_list_Buy.GetItemText(sel,0));
	Inputbuy.m_strTime       = m_list_Buy.GetItemText(sel,1);
	Inputbuy.m_strComName    = m_list_Buy.GetItemText(sel,2);
	Inputbuy.m_strProduct    = m_list_Buy.GetItemText(sel,3);
	Inputbuy.m_strTotalPrice = m_list_Buy.GetItemText(sel,4);
	Inputbuy.m_strSellPrice  = m_list_Buy.GetItemText(sel,5);
	if(Inputbuy.DoModal()==IDOK)
	{
		if(MessageBox("ȷ��Ҫ�޸Ľ�������?","��ʾ",MB_OKCANCEL)==IDOK)
		{
			CString sql;	
			sql.Format("update buyproduct set strdate=\"%s\",companyname=\"%s\",productinfo=\"%s\",totalprice=\"%s\",sellprice=\"%s\" where logid=%d",
				Inputbuy.m_strTime,Inputbuy.m_strComName,Inputbuy.m_strProduct,Inputbuy.m_strTotalPrice,Inputbuy.m_strSellPrice,Inputbuy.m_dLogId);
			if(!g_adoDataSet.ExecSql(sql))
			{
				MessageBox("�޸����ݿ�ʧ��","��ʾ",MB_OK);
				return ;
			}
			CString strLogID;
			strLogID.Format("%d",Inputbuy.m_dLogId);
			m_list_Buy.SetItemText(sel,0,strLogID);
			m_list_Buy.SetItemText(sel,1,Inputbuy.m_strTime);
			m_list_Buy.SetItemText(sel,2,Inputbuy.m_strComName);
			m_list_Buy.SetItemText(sel,3,Inputbuy.m_strProduct);
			m_list_Buy.SetItemText(sel,4,Inputbuy.m_strTotalPrice);
			m_list_Buy.SetItemText(sel,5,Inputbuy.m_strSellPrice);
		}
	}
	*pResult = 0;
}

void CDIALOG_BUY::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	//CDialog::OnCancel();
}

void CDIALOG_BUY::OnRclickListBuy(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CMenu       menu ,* pSubMenu;//��������Ҫ�õ���cmenu����	
	menu.LoadMenu(IDR_MENU1);//װ���Զ�����Ҽ��˵�
	pSubMenu = menu.GetSubMenu(0);//��ȡ��һ�������˵������Ե�һ���˵��������Ӳ˵�	
    CPoint oPoint;//����һ������ȷ�����λ�õ�λ��	
    GetCursorPos( &oPoint);//��ȡ��ǰ����λ�ã��Ա�ʹ�ò˵����Ը�����
	int istat=m_list_Buy.GetSelectionMark();//��istat��ŵ�ǰѡ�����ǵڼ���	
	if(istat == -1) return;
	pSubMenu->TrackPopupMenu (TPM_LEFTALIGN, oPoint.x, oPoint.y, this); //��ָ��λ����ʾ�����˵�
	*pResult = 0;
}

void CDIALOG_BUY::OnDelete()
{
	int istat=m_list_Buy.GetSelectionMark();
	if(istat == -1) return;
	CString strComName = m_list_Buy.GetItemText(istat,2);
	CString strTips ;
	strTips.Format("ȷ��Ҫɾ���ͻ�%s�ļ�¼��?",strComName);
	int ret = MessageBox(strTips,"��ʾ",MB_OKCANCEL);
	if (ret==IDOK)
	{
		int dLogID  = atoi(m_list_Buy.GetItemText(istat,0));
		CString sql;
		sql.Format("delete from buyproduct where logid=%d",dLogID);
		if(!g_adoDataSet.ExecSql(sql))
		{
			MessageBox("ɾ�����ݿ�ʧ��","��ʾ",MB_OK);
			return ;
		}
		m_list_Buy.DeleteItem(istat);
		strTips.Format("ɾ���ͻ�%s�ļ�¼�ɹ�.",strComName);
		MessageBox(strTips,"��ʾ",MB_OK);
	}
}

void CDIALOG_BUY::OnColumnclickListBuy(NMHDR* pNMHDR, LRESULT* pResult) 
{
	//NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	
	int i,nItemCounter; 
	NM_LISTVIEW * pNMListView = (NM_LISTVIEW*)pNMHDR; 
	CListCtrl * pListCtrl = &m_list_Buy; 
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
