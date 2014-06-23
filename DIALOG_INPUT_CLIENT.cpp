// DIALOG_INPUT_CLIENT.cpp : implementation file
//

#include "stdafx.h"
#include "GoodsManageSystem.h"
#include "DIALOG_INPUT_CLIENT.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDIALOG_INPUT_CLIENT dialog


CDIALOG_INPUT_CLIENT::CDIALOG_INPUT_CLIENT(CWnd* pParent /*=NULL*/)
	: CDialog(CDIALOG_INPUT_CLIENT::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDIALOG_INPUT_CLIENT)
	m_strAddress = _T("");
	m_strBank = _T("");
	m_strCompanyName = _T("");
	m_strMail = _T("");
	m_strReceiver = _T("");
	m_strTaxIndex = _T("");
	m_bModify = 0;
	m_dLogId = 0;
	//}}AFX_DATA_INIT
}


void CDIALOG_INPUT_CLIENT::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDIALOG_INPUT_CLIENT)
	DDX_Text(pDX, IDC_EDIT_ADDRESSPHONE, m_strAddress);
	DDX_Text(pDX, IDC_EDIT_BANKNO, m_strBank);
	DDX_Text(pDX, IDC_EDIT_COMPANYNAME, m_strCompanyName);
	DDX_Text(pDX, IDC_EDIT_MAILADDRESSPHONE, m_strMail);
	DDX_Text(pDX, IDC_EDIT_RECEIVER, m_strReceiver);
	DDX_Text(pDX, IDC_EDIT_TAXINDEX, m_strTaxIndex);
	DDX_Text(pDX, IDC_EDIT_CLIENT_LOGID, m_dLogId);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDIALOG_INPUT_CLIENT, CDialog)
	//{{AFX_MSG_MAP(CDIALOG_INPUT_CLIENT)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDIALOG_INPUT_CLIENT message handlers

BOOL CDIALOG_INPUT_CLIENT::OnInitDialog() 
{
	CDialog::OnInitDialog();
	if (m_bModify)
	{
		SetWindowText("修改客户资料");
		//((CWnd*)GetDlgItem(IDC_EDIT_COMPANYNAME))->EnableWindow(FALSE);
	}		
	else
	{
		SetWindowText("添加客户资料");
		CString sql;
		sql.Format("select * from client order by logid desc");
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
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDIALOG_INPUT_CLIENT::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	if (!m_bModify)
	{
		CString sql;
		sql.Format("insert into client(logid,companyname,taxindex,bank_no,address_pho,receiver,mail_phone) values (%d,\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\")",
			m_dLogId,m_strCompanyName,m_strTaxIndex,m_strBank,m_strAddress,m_strReceiver,m_strMail);
		if(!g_adoDataSet.ExecSql(sql))
		{
			MessageBox("插入数据库失败","提示",MB_OK);
			return ;
		}
	}	
	CDialog::OnOK();
}

void CDIALOG_INPUT_CLIENT::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CDIALOG_INPUT_CLIENT::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnClose();
	//CDialog::OnCancel();
}
