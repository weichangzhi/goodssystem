// Dialog_InputSell.cpp : implementation file
//

#include "stdafx.h"
#include "GoodsManageSystem.h"
#include "Dialog_InputSell.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialog_InputSell dialog


CDialog_InputSell::CDialog_InputSell(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_InputSell::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog_InputSell)
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
	m_bModify = 0;
	m_strLogId = _T("");
	m_bBtnModify = 0;
	m_bSortAscending = 1;
	m_strMoney = _T("");
	m_strSellName = _T("");
	m_strSellPhone = _T("");
	m_strTips = _T("");
	m_strUint = _T("");
	m_strUserAddress = _T("");
	m_strUserName = _T("");
	m_strUserPhone = _T("");
	m_dModifyProCount = 0;
	//}}AFX_DATA_INIT
}


void CDialog_InputSell::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog_InputSell)
	DDX_Control(pDX, IDC_LIST_Product, m_list_Product);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_time);
	DDX_Text(pDX, IDC_EDIT_INPUTSELL_COMPANYNAME, m_strComName);
	DDX_Text(pDX, IDC_EDIT_INPUTSELL_PRODUCTMODEL, m_strProductModel);
	DDX_Text(pDX, IDC_EDIT_INPUTSELL_PRONUM, m_strProductNum);
	DDX_Text(pDX, IDC_EDIT_INPUTSELL_PROPRICE, m_strProductPrice);
	DDX_Text(pDX, IDC_EDIT_INPUTSELL_SELLPRICE, m_strSellPrice);
	DDX_Text(pDX, IDC_EDIT_INPUTSELL_TOTALPRICE, m_strTotalPrice);
	DDX_Text(pDX, IDC_EDIT_SELL_LOGID, m_strLogId);
	DDX_Text(pDX, IDC_EDIT_INPUTSELL_MONEY, m_strMoney);
	DDX_Text(pDX, IDC_EDIT_INPUTSELL_SELLNAME, m_strSellName);
	DDX_Text(pDX, IDC_EDIT_INPUTSELL_SELLPHONE, m_strSellPhone);
	DDX_Text(pDX, IDC_EDIT_INPUTSELL_TIPS, m_strTips);
	DDX_Text(pDX, IDC_EDIT_INPUTSELL_UINT, m_strUint);
	DDX_Text(pDX, IDC_EDIT_INPUTSELL_USERADDRESS, m_strUserAddress);
	DDX_Text(pDX, IDC_EDIT_INPUTSELL_USERNAME, m_strUserName);
	DDX_Text(pDX, IDC_EDIT_INPUTSELL_USERPHONE, m_strUserPhone);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog_InputSell, CDialog)
	//{{AFX_MSG_MAP(CDialog_InputSell)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnAddToList)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_Product, OnRclickLISTProduct)
	ON_COMMAND(ID_MENUITEM_INPUTSELL,OnDelete) 
	ON_EN_SETFOCUS(IDC_EDIT_INPUTSELL_TOTALPRICE, OnSetfocusEditInputsellTotalprice)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_Product, OnDblclkLISTProduct)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTPREVIEW, OnButpreview)
	ON_BN_CLICKED(IDC_BUTPRINT, OnButprint)
	ON_EN_SETFOCUS(IDC_EDIT_INPUTSELL_MONEY, OnSetfocusEditInputsellMoney)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog_InputSell message handlers

BOOL CDialog_InputSell::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_list_Product.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_list_Product.InsertColumn(0, _T("产品型号"), LVCFMT_LEFT,65);
	m_list_Product.InsertColumn(1, _T("价格"), LVCFMT_LEFT,40);
	m_list_Product.InsertColumn(2, _T("数量"), LVCFMT_LEFT,40);
	m_list_Product.InsertColumn(3, _T("单位"), LVCFMT_LEFT,40);
	m_list_Product.InsertColumn(4, _T("金额"), LVCFMT_LEFT,50);
	m_list_Product.InsertColumn(5, _T("备注"), LVCFMT_LEFT,45);

	if (m_bModify)
	{
		CString csSql;
		csSql.Format("select * from sellproduct where logid=\"%s\" ",m_strLogId);	
		if (!g_adoDataSet.Open(csSql,CADODataset::openQuery))
			return FALSE;
		
		DWORD dwCnt	 = g_adoDataSet.GetRecordCount();	
		if (dwCnt<=0)
			return FALSE;
		
		if(!g_adoDataSet.GetCollect("strdate",m_strTime)) return FALSE;
		if(!g_adoDataSet.GetCollect("companyname",m_strComName)) return FALSE;
		if(!g_adoDataSet.GetCollect("productinfo",m_strProduct)) return FALSE;
		if(!g_adoDataSet.GetCollect("totalprice",m_strTotalPrice)) return FALSE;
		if(!g_adoDataSet.GetCollect("sellprice",m_strSellPrice)) return FALSE;
		if(!g_adoDataSet.GetCollect("useraddress",m_strUserAddress)) return FALSE;
		if(!g_adoDataSet.GetCollect("userphone",m_strUserPhone)) return FALSE;
		if(!g_adoDataSet.GetCollect("username",m_strUserName)) return FALSE;
		if(!g_adoDataSet.GetCollect("sellername",m_strSellName)) return FALSE;
		if(!g_adoDataSet.GetCollect("sellerphone",m_strSellPhone)) return FALSE;

		csSql.Format("select * from oneproduct where logid=\"%s\" ",m_strLogId);	
		if (!g_adoDataSet.Open(csSql,CADODataset::openQuery))
			return FALSE;
		dwCnt	 = g_adoDataSet.GetRecordCount();	
		if (dwCnt<=0)
			return FALSE;
		int index=0;
		CString strType,strPrice,strCount,strUint,strMoney,strTips;
		while (!g_adoDataSet.IsEof())
		{
			if(!g_adoDataSet.GetCollect("protype",strType)) return FALSE;
			if(!g_adoDataSet.GetCollect("proprice",strPrice)) return FALSE;
			if(!g_adoDataSet.GetCollect("procount",strCount)) return FALSE;
			if(!g_adoDataSet.GetCollect("prouint",strUint)) return FALSE;
			if(!g_adoDataSet.GetCollect("promoney",strMoney)) return FALSE;
			if(!g_adoDataSet.GetCollect("protips",strTips)) return FALSE;
			m_list_Product.InsertItem(index,strType);
			m_list_Product.SetItemText(index,1,strPrice);
			m_list_Product.SetItemText(index,2,strCount);
			m_list_Product.SetItemText(index,3,strUint);
			m_list_Product.SetItemText(index,4,strMoney);
			m_list_Product.SetItemText(index,5,strTips);
			index++;
			g_adoDataSet.MoveNext();
		}
		m_dModifyProCount = --index;
		CTime timeTmp(atoi(m_strTime.Mid(0,4)),atoi(m_strTime.Mid(5,2)),atoi(m_strTime.Mid(8,2)),0,0,0,0);
		m_time = timeTmp;
		SetWindowText("修改出货记录");
		UpdateData(FALSE);
	}
	else
	{
		m_time = CTime::GetCurrentTime();
     	m_strTime.Format("%04d-%02d-%02d",m_time.GetYear(),m_time.GetMonth(),m_time.GetDay());
		SetWindowText("添加出货记录");
		CString sql;
		sql.Format("select * from sellproduct order by logid desc");
		BOOL bRlt = g_adoDataSet.Open(sql,CADODataset::openQuery);	
		if(!bRlt)
		{
			return FALSE;
		}
		DWORD dwCnt	 = g_adoDataSet.GetRecordCount();
		CString strProductIndex;
		bRlt = g_adoDataSet.GetCollect("logid",strProductIndex);
		//出货单号格式：DB-20100521-0001
		CString strCurTime;
		strCurTime.Format("%04d%02d%02d",m_time.GetYear(),m_time.GetMonth(),m_time.GetDay());
		if (strProductIndex.GetLength()==16)
		{
			CString strLastTime = strProductIndex.Mid(3,8);
			if (strLastTime.Compare(strCurTime)==0)//同一天
			{
				CString strIndex = strProductIndex.Mid(12,4);
				int dIndex = atoi(strIndex);
				dIndex++;
				m_strLogId.Format("DB-%s-%04d",strCurTime,dIndex);
			}
			else
			{
				m_strLogId.Format("DB-%s-0001",strCurTime);
			}
		}
		else
		{
			m_strLogId.Format("DB-%s-0001",strCurTime);
		}
    	UpdateData(FALSE);
	}	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL isInteger(CString str)//是整数
{
	int len  = str.GetLength();
	int index = 0;
	for (index=0;index<len;index++)
	{
		char tmp = str.GetAt(index);
		if ( ( tmp < '0' ) || ( tmp > '9') )
		{
			return FALSE;
		}
	}
	return TRUE;
}

BOOL isNumber(CString str)//是数字
{
	int len  = str.GetLength();
	int index = 0;
	for (index=0;index<len;index++)
	{
		char tmp = str.GetAt(index);
		if ( ( ( tmp >= '0' ) && ( tmp <= '9') ) || (tmp == '.') )
		{
			continue;
		}
		else
		{
			return FALSE;
		}
	}
	return TRUE;
}

void CDialog_InputSell::OnAddToList() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_strProductModel.TrimLeft();
	m_strProductModel.TrimRight();
	m_strProductNum.TrimLeft();
	m_strProductNum.TrimRight();
	m_strProductPrice.TrimLeft();
	m_strProductPrice.TrimRight();
	m_strUint.TrimLeft();
	m_strUint.TrimRight();
	m_strMoney.TrimLeft();
	m_strMoney.TrimRight();
	m_strTips.TrimLeft();
	m_strTips.TrimRight();
	if (m_strProductModel.IsEmpty())
	{
		MessageBox("产品型号不能为空!","提示",MB_OK);
		((CEdit*)GetDlgItem(IDC_EDIT_INPUTSELL_PRODUCTMODEL))->SetFocus();
		return ;
	}
	if (!isNumber(m_strProductPrice))
	{
		MessageBox("产品价格必须为数字!","提示",MB_OK);
		((CEdit*)GetDlgItem(IDC_EDIT_INPUTSELL_PROPRICE))->SetFocus();
		((CEdit*)GetDlgItem(IDC_EDIT_INPUTSELL_PROPRICE))->SetSel(0,-1);
		return ;
	}
	if (!isInteger(m_strProductNum))
	{
		MessageBox("产品数量必须为正整数!","提示",MB_OK);
		((CEdit*)GetDlgItem(IDC_EDIT_INPUTSELL_PRONUM))->SetFocus();
		((CEdit*)GetDlgItem(IDC_EDIT_INPUTSELL_PRONUM))->SetSel(0,-1);
		return ;
	}
	
	if (m_bBtnModify)
	{
		int nSelect = m_list_Product.GetSelectionMark();
		m_list_Product.SetItemText(nSelect,0,m_strProductModel);
		m_list_Product.SetItemText(nSelect,1,m_strProductPrice);
		m_list_Product.SetItemText(nSelect,2,m_strProductNum);
		m_list_Product.SetItemText(nSelect,3,m_strUint);
		m_list_Product.SetItemText(nSelect,4,m_strMoney);
		m_list_Product.SetItemText(nSelect,5,m_strTips);
	}
	else
	{
		int nCount = m_list_Product.GetItemCount();
		if (m_bModify) nCount--;
		m_list_Product.InsertItem(nCount,m_strProductModel);
		m_list_Product.SetItemText(nCount,1,m_strProductPrice);
		m_list_Product.SetItemText(nCount,2,m_strProductNum);
		m_list_Product.SetItemText(nCount,3,m_strUint);
		m_list_Product.SetItemText(nCount,4,m_strMoney);
		m_list_Product.SetItemText(nCount,5,m_strTips);
		m_dProductindex++;
	}
	
	m_strProductModel = "";
	m_strProductNum = "";
	m_strProductPrice = "";
	m_strUint = "";
	m_strMoney = "";
	m_strTips = "";
	UpdateData(FALSE);
	SetDlgItemText(IDC_BUTTON_ADD,"添加->");
	m_bBtnModify = 0;	
}

void CDialog_InputSell::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}


void CDialog_InputSell::OnRclickLISTProduct(NMHDR* pNMHDR, LRESULT* pResult) 
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
	SetDlgItemText(IDC_BUTTON_ADD,"添加->");
}

void CDialog_InputSell::OnDelete()
{
	int istat=m_list_Product.GetSelectionMark();
	if(istat == -1) return;
	m_list_Product.DeleteItem(istat);
}
  
void CDialog_InputSell::OnSetfocusEditInputsellTotalprice() 
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

void CDialog_InputSell::OnDblclkLISTProduct(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int nSelect = m_list_Product.GetSelectionMark();
	if(nSelect == -1)
		return;
	SetDlgItemText(IDC_BUTTON_ADD,"修改->");
	m_bBtnModify = 1;
	m_strProductModel = m_list_Product.GetItemText(nSelect,0);
	m_strProductPrice = m_list_Product.GetItemText(nSelect,1);
	m_strProductNum   = m_list_Product.GetItemText(nSelect,2);
	m_strUint         = m_list_Product.GetItemText(nSelect,3);
	m_strMoney        = m_list_Product.GetItemText(nSelect,4);
	m_strTips         = m_list_Product.GetItemText(nSelect,5);
	
	UpdateData(FALSE);
	*pResult = 0;
}

void CDialog_InputSell::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnClose();
	//CDialog::OnCancel();
}

void CDialog_InputSell::OnOK() 
{
	// TODO: Add extra validation here
	m_strProduct = "";
	UpdateData();
	int nCount = m_list_Product.GetItemCount();
	//if(m_bModify) nCount--;
	CString strTmp;
	for (int i=0;i<nCount;i++)
	{	
		CString strProType  = m_list_Product.GetItemText(i,0);
		CString strProPrice = m_list_Product.GetItemText(i,1);
		CString strProCount = m_list_Product.GetItemText(i,2);
		if (m_strProduct.IsEmpty())
		{
			strTmp.Format("%s(%s*%s)",strProType,strProCount,strProPrice);
		}
		else
		{
			strTmp.Format(",%s(%s*%s)",strProType,strProCount,strProPrice);
		}
		m_strProduct += strTmp;
	}
	
	if (m_strComName.IsEmpty())
	{
		MessageBox("公司名称不能为空!","提示",MB_OK);
		m_strProduct = "";
		(CWnd*)(GetDlgItem(IDC_EDIT_INPUTSELL_COMPANYNAME))->SetFocus();
		return;
	}

	m_strTime.Format("%04d-%02d-%02d",m_time.GetYear(),m_time.GetMonth(),m_time.GetDay());
		
	if(!m_bModify)
	{
		CString sql;
		sql.Format("insert into sellproduct(logid,strdate,companyname,productinfo,totalprice,sellprice,useraddress,userphone,username,sellername,sellerphone)values(\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\")", 
			m_strLogId,m_strTime,m_strComName,m_strProduct,m_strTotalPrice,m_strSellPrice,m_strUserAddress,m_strUserPhone,m_strUserName,m_strSellName,m_strSellPhone);
		if(!g_adoDataSet.ExecSql(sql))
		{
			MessageBox("插入数据库失败","提示",MB_OK);
			return ;
		}


		sql.Format("select * from oneproduct order by productindex desc");
		BOOL bRlt = g_adoDataSet.Open(sql,CADODataset::openQuery);	
		if(!bRlt)
		{
			return ;
		}
		DWORD dwCnt	 = g_adoDataSet.GetRecordCount();
		CString strProductIndex;
		bRlt = g_adoDataSet.GetCollect("productindex",strProductIndex);
		int dProductIndex = atoi(strProductIndex);
		int index = 0;
		for (index = 0; index < nCount; index++)
		{
			CString strProType  = m_list_Product.GetItemText(index,0);
			CString strProPrice = m_list_Product.GetItemText(index,1);
			CString strProCount = m_list_Product.GetItemText(index,2);
			CString strUint     = m_list_Product.GetItemText(index,3);
			CString strMoney    = m_list_Product.GetItemText(index,4);
			CString strTips     = m_list_Product.GetItemText(index,5);

			sql.Format("insert into oneproduct(productindex,logid,protype,proprice,procount,prouint,promoney,protips) values (%d,\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\")",
				++dProductIndex,m_strLogId,strProType,strProPrice,strProCount,strUint,strMoney,strTips);
			if(!g_adoDataSet.ExecSql(sql))
			{
				MessageBox("插入数据库失败","提示",MB_OK);
				return ;
			}
		}		
	}
	else//修改
	{
		if(MessageBox("确定要修改出货资料?","提示",MB_OKCANCEL)==IDOK)
		{
			CString sql;	
			sql.Format("update sellproduct set strdate=\"%s\",companyname=\"%s\",productinfo=\"%s\",totalprice=\"%s\",sellprice=\"%s\" where logid=\"%s\"",
				m_strTime,m_strComName,m_strProduct,m_strTotalPrice,m_strSellPrice,m_strLogId);
			if(!g_adoDataSet.ExecSql(sql))
			{
				MessageBox("修改数据库失败","提示",MB_OK);
				return ;
			}
			
		}	
	}	
	CDialog::OnOK();
}

void CDialog_InputSell::SetPreviewDlg(CPreview *PreviewDlg)
{
	UpdateData();
	int nCount = m_list_Product.GetItemCount();
	//if(m_bModify) nCount--;
	PreviewDlg->m_dProCount = nCount;
	if (nCount>0)
	{
		PreviewDlg->m_pProInfo = new ProductInfo[nCount];
		long lTotalCount = 0;
		for (int i=0;i<nCount;i++)
		{	
			CString strProType  = m_list_Product.GetItemText(i,0);
			CString strProPrice = m_list_Product.GetItemText(i,1);
			CString strProCount = m_list_Product.GetItemText(i,2);
			CString strUint     = m_list_Product.GetItemText(i,3);
			CString strMoney    = m_list_Product.GetItemText(i,4);
			CString strTips     = m_list_Product.GetItemText(i,5);
			
			PreviewDlg->m_pProInfo[i].strProType   = strProType;
			PreviewDlg->m_pProInfo[i].strCount     = strProCount;
			PreviewDlg->m_pProInfo[i].strPrice     = strProPrice;
			PreviewDlg->m_pProInfo[i].strUint      = strUint;
			PreviewDlg->m_pProInfo[i].strMoney     = strMoney;
			PreviewDlg->m_pProInfo[i].strTips      = strTips;

			long tmpCount = atol(strProCount.GetBuffer(strProCount.GetLength()));
			lTotalCount += tmpCount;	
		}
		PreviewDlg->m_strTotalCount.Format("%d",lTotalCount);
	}
		
	
	PreviewDlg->m_strTime.Format("%04d年%02d月%02d日",m_time.GetYear(),m_time.GetMonth(),m_time.GetDay());
	PreviewDlg->m_strIndex       = m_strLogId;	
	PreviewDlg->m_strCompanyName = m_strComName;
	PreviewDlg->m_strUserAddress = m_strUserAddress;
	PreviewDlg->m_strUserPhone   = m_strUserPhone;
	PreviewDlg->m_strUserName    = m_strUserName;
	PreviewDlg->m_strSellName    = m_strSellName;
	PreviewDlg->m_strSellPhone   = m_strSellPhone;	
	
	PreviewDlg->m_strSellPrice   = m_strSellPrice;
	if (nCount>0)
	{
		PreviewDlg->m_strTotalPrice  = m_strTotalPrice + " 元";
	}
	else
	{
		PreviewDlg->m_strTotalPrice  = m_strTotalPrice;
	}
	 
}

void CDialog_InputSell::OnButpreview() 
{
	CPreview PreviewDlg;
	SetPreviewDlg(&PreviewDlg);
	PreviewDlg.DoModal();
}

void CDialog_InputSell::OnButprint() 
{
	CPreview PreviewDlg;
	SetPreviewDlg(&PreviewDlg);
	CPrintDialog m_printdlg(false);
	if (m_printdlg.DoModal()==IDOK)
	{
		CDC dc1;		
		dc1.Attach(m_printdlg.GetPrinterDC());			
		int leftmargin;
		leftmargin = dc1.GetDeviceCaps(PHYSICALOFFSETX);
		CRect m_rect(-leftmargin,0,dc1.GetDeviceCaps(PHYSICALWIDTH)-leftmargin,dc1.GetDeviceCaps(PHYSICALHEIGHT)) ;		
		PreviewDlg.DrawReport(m_rect,&dc1,true);
	}	
}

void CDialog_InputSell::OnSetfocusEditInputsellMoney() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	double fMoney = atof(m_strProductPrice) * atoi(m_strProductNum);
	m_strMoney.Format("%g",fMoney);
	UpdateData(FALSE);
}
