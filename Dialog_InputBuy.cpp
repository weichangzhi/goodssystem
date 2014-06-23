// Dialog_InputBuy.cpp : implementation file
//

#include "stdafx.h"
#include "GoodsManageSystem.h"
#include "Dialog_InputBuy.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialog_InputBuy dialog


CDialog_InputBuy::CDialog_InputBuy(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_InputBuy::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog_InputBuy)
	m_time = 0;//CTime::GetCurrentTime(); 
	m_strComName = _T("");
	m_strProductModel = _T("");
	m_strProductNum = _T("");
	m_strProductPrice = _T("");
	m_strSellPrice = _T("");
	m_strTotalPrice = _T("");
	m_strTime = _T("");
	m_dProductindex = 0;
	m_strProduct = "";
	m_dLogId = 0;
	m_bModify = 0;
	m_bBtnModify = 0;
	//}}AFX_DATA_INIT
}


void CDialog_InputBuy::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog_InputBuy)
	DDX_Control(pDX, IDC_LIST_Product2, m_list_Product);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER2, m_time);
	DDX_Text(pDX, IDC_EDIT_INPUTBUY_COMPANYNAME, m_strComName);
	DDX_Text(pDX, IDC_EDIT_INPUTBUY_PRODUCTMODEL, m_strProductModel);
	DDX_Text(pDX, IDC_EDIT_INPUTBUY_PRONUM, m_strProductNum);
	DDX_Text(pDX, IDC_EDIT_INPUTBUY_PROPRICE, m_strProductPrice);
	DDX_Text(pDX, IDC_EDIT_INPUTBUY_SELLPRICE, m_strSellPrice);
	DDX_Text(pDX, IDC_EDIT_INPUTBUY_TOTALPRICE, m_strTotalPrice);
	DDX_Text(pDX, IDC_EDIT_BUY_LOGID, m_dLogId);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog_InputBuy, CDialog)
	//{{AFX_MSG_MAP(CDialog_InputBuy)
	ON_BN_CLICKED(IDC_BUTTON_ADD2, OnButtonAdd2)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_Product2, OnDblclkLISTProduct2)
	ON_EN_SETFOCUS(IDC_EDIT_INPUTBUY_TOTALPRICE, OnSetfocusEditInputbuyTotalprice)
	ON_COMMAND(ID_MENUITEM_INPUTSELL,OnDelete)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_Product2, OnRclickLISTProduct2)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog_InputBuy message handlers

BOOL CDialog_InputBuy::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//m_strTime.Format("%04d-%02d-%02d",m_time.GetYear(),m_time.GetMonth(),m_time.GetDay());
	
	m_list_Product.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_list_Product.InsertColumn(0, _T("产品型号"), LVCFMT_LEFT,90);
	m_list_Product.InsertColumn(1, _T("数量"), LVCFMT_LEFT,60);
	m_list_Product.InsertColumn(2, _T("价格"), LVCFMT_LEFT,60);

	if (m_bModify)
	{
		CTime timeTmp(atoi(m_strTime.Mid(0,4)),atoi(m_strTime.Mid(5,2)),atoi(m_strTime.Mid(8,2)),0,0,0,0);
		m_time = timeTmp;
		SetWindowText("修改出货记录");
		if (!m_strProduct.IsEmpty())//解析产品信息，输入出到列表控件
		{
			CString strRight = m_strProduct;
			CString strLeft  = m_strProduct;
			int nindex = 0;
			while (!strLeft.IsEmpty())
			{
				int nlength = strRight.GetLength();
				int dleft = strRight.Find(',');
				strLeft = strRight.Mid(0,dleft);
				{
					int dSubLeft = strLeft.Find('(');
					int dSubLength = strLeft.GetLength();
					CString strProductModel = strLeft.Mid(0,dSubLeft);
					CString strSubRight = strLeft.Mid(dSubLeft+1,dSubLength-dSubLeft-1);
					int dSubRight = strSubRight.Find('*');
					CString strProductNo = strSubRight.Mid(0,dSubRight);
					CString strProductPrice = strSubRight.Mid(dSubRight+1,strSubRight.GetLength()-dSubRight-2);
					m_list_Product.InsertItem(nindex,strProductModel);
					m_list_Product.SetItemText(nindex,1,strProductNo);
					m_list_Product.SetItemText(nindex,2,strProductPrice);
				}
				strRight = strRight.Mid(dleft+1,nlength-dleft-1);
				nindex++;
			}
			{
				int dSubLeft = strRight.Find('(');
				int dSubLength = strRight.GetLength();
				CString strProductModel = strRight.Mid(0,dSubLeft);
				CString strSubRight = strRight.Mid(dSubLeft+1,dSubLength-dSubLeft-1);
				int dSubRight = strSubRight.Find('*');
				CString strProductNo = strSubRight.Mid(0,dSubRight);
				CString strProductPrice = strSubRight.Mid(dSubRight+1,strSubRight.GetLength()-dSubRight-2);
				m_list_Product.InsertItem(nindex-1,strProductModel);
				m_list_Product.SetItemText(nindex-1,1,strProductNo);
				m_list_Product.SetItemText(nindex-1,2,strProductPrice);
			}
		}
		UpdateData(FALSE);
	}
	else
	{
		m_time = CTime::GetCurrentTime();
     	m_strTime.Format("%04d-%02d-%02d",m_time.GetYear(),m_time.GetMonth(),m_time.GetDay());
		SetWindowText("添加出货记录");
		CString sql;
		sql.Format("select * from buyproduct order by logid desc");
		BOOL bRlt = g_adoDataSet.Open(sql,CADODataset::openQuery);	
		if(!bRlt)
		{
			return FALSE;
		}
		DWORD dwCnt	 = g_adoDataSet.GetRecordCount();
		CString strValue;
		bRlt = g_adoDataSet.GetCollect("logid",strValue);
		long index = atoi(strValue.GetBuffer(0));
		m_dLogId = ++index;
		UpdateData(FALSE);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDialog_InputBuy::OnButtonAdd2() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_strProductModel.TrimLeft();
	m_strProductModel.TrimRight();
	m_strProductNum.TrimLeft();
	m_strProductNum.TrimRight();
	m_strProductPrice.TrimLeft();
	m_strProductPrice.TrimRight();
	if (m_strProductModel.IsEmpty())
	{
		MessageBox("产品型号不能为空!","提示",MB_OK);
		return ;
	}
	if (m_bBtnModify)
	{
		int nSelect = m_list_Product.GetSelectionMark();
		m_list_Product.SetItemText(nSelect,0,m_strProductModel);
		m_list_Product.SetItemText(nSelect,1,m_strProductNum);
		m_list_Product.SetItemText(nSelect,2,m_strProductPrice);
	}
	else
	{
		int nCount = m_list_Product.GetItemCount();
		if (m_bModify) nCount--;
		m_list_Product.InsertItem(nCount,m_strProductModel);
		m_list_Product.SetItemText(nCount,1,m_strProductNum);
		m_list_Product.SetItemText(nCount,2,m_strProductPrice);
		m_dProductindex++;
	}
	
	m_strProductModel = "";
	m_strProductNum = "";
	m_strProductPrice = "";
	UpdateData(FALSE);
	SetDlgItemText(IDC_BUTTON_ADD2,"添加->");
	m_bBtnModify = 0;
	
}

void CDialog_InputBuy::OnDblclkLISTProduct2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int nSelect = m_list_Product.GetSelectionMark();
	if(nSelect == -1)
		return;
	SetDlgItemText(IDC_BUTTON_ADD2,"修改->");
	m_bBtnModify = 1;
	m_strProductModel = m_list_Product.GetItemText(nSelect,0);
	m_strProductNum   = m_list_Product.GetItemText(nSelect,1);
	m_strProductPrice = m_list_Product.GetItemText(nSelect,2);
	UpdateData(FALSE);
	*pResult = 0;
}

void CDialog_InputBuy::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CDialog_InputBuy::OnOK() 
{
	// TODO: Add extra validation here
	m_strProduct = "";
	int nCount = m_list_Product.GetItemCount();
	if(m_bModify) nCount--;
	CString strTmp;
	for (int i=0;i<nCount;i++)
	{	
		if (m_strProduct.IsEmpty())
		{
			strTmp.Format("%s(%s*%s)",m_list_Product.GetItemText(i,0),m_list_Product.GetItemText(i,1),m_list_Product.GetItemText(i,2));
		}
		else
		{
			strTmp.Format(",%s(%s*%s)",m_list_Product.GetItemText(i,0),m_list_Product.GetItemText(i,1),m_list_Product.GetItemText(i,2));
		}
		m_strProduct += strTmp;
	}

	UpdateData();
	m_strTime.Format("%04d-%02d-%02d",m_time.GetYear(),m_time.GetMonth(),m_time.GetDay());
	if (!m_bModify)
	{
		CString sql;
		sql.Format("insert into buyproduct(logid,strdate,companyname,productinfo,totalprice,sellprice) values (%d,\"%s\",\"%s\",\"%s\",\"%s\",\"%s\")",
			m_dLogId,m_strTime,m_strComName,m_strProduct,m_strTotalPrice,m_strSellPrice);
		if(!g_adoDataSet.ExecSql(sql))
		{
			MessageBox("插入数据库失败","提示",MB_OK);
			return ;
		}
	}	
	CDialog::OnOK();
}

void CDialog_InputBuy::OnSetfocusEditInputbuyTotalprice() 
{
	// TODO: Add your control notification handler code here
	int nCount = m_list_Product.GetItemCount();
	CString strTmp;
	double TotalPrice = 0.0;
	for (int i=0;i<nCount;i++)
	{		
		TotalPrice += atof(m_list_Product.GetItemText(i,1)) * atof(m_list_Product.GetItemText(i,2));
	}
	m_strTotalPrice.Format("%g",TotalPrice);
	UpdateData(FALSE);
}

void CDialog_InputBuy::OnRclickLISTProduct2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CMenu       menu ,* pSubMenu;//定义下面要用到的cmenu对象	
	menu.LoadMenu(IDR_MENU1);//装载自定义的右键菜单
	pSubMenu = menu.GetSubMenu(0);//获取第一个弹出菜单，所以第一个菜单必须有子菜单	
    CPoint oPoint;//定义一个用于确定光标位置的位置	
    GetCursorPos( &oPoint);//获取当前光标的位置，以便使得菜单可以跟随光标
	int istat=m_list_Product.GetSelectionMark();//用istat存放当前选定的是第几项	
	if(istat == -1) return;
	pSubMenu->TrackPopupMenu (TPM_LEFTALIGN, oPoint.x, oPoint.y, this); //在指定位置显示弹出菜单
	*pResult = 0;
	
	m_strProductModel = "";
	m_strProductNum = "";
	m_strProductPrice = "";
	UpdateData(FALSE);
	SetDlgItemText(IDC_BUTTON_ADD2,"添加->");
}

void CDialog_InputBuy::OnDelete()
{
	int istat=m_list_Product.GetSelectionMark();
	if(istat == -1) return;
	m_list_Product.DeleteItem(istat);
}
  

// void CDialog_InputBuy::OnClickLISTProduct2(NMHDR* pNMHDR, LRESULT* pResult) 
// {
// 	// TODO: Add your control notification handler code here
// 	int nSelect = m_list_Product.GetSelectionMark();
// 	if(nSelect == -1)
// 		return;
// 	SetDlgItemText(IDC_BUTTON_ADD2,"修改->");
// 	m_bBtnModify = 1;
// 	m_strProductModel = m_list_Product.GetItemText(nSelect,0);
// 	m_strProductNum   = m_list_Product.GetItemText(nSelect,1);
// 	m_strProductPrice = m_list_Product.GetItemText(nSelect,2);
// 	UpdateData(FALSE);
// 	*pResult = 0;
// }

void CDialog_InputBuy::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnClose();
	//CDialog::OnCancel();
}
