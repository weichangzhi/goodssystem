// Dialog_UserInfo.cpp : implementation file
//

#include "stdafx.h"
#include "GoodsManageSystem.h"
#include "Dialog_UserInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dialog_UserInfo dialog


Dialog_UserInfo::Dialog_UserInfo(CWnd* pParent /*=NULL*/)
	: CDialog(Dialog_UserInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(Dialog_UserInfo)
	m_strPassed = _T("");
	m_strUserName = _T("");
	//}}AFX_DATA_INIT
}


void Dialog_UserInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Dialog_UserInfo)
	DDX_Text(pDX, IDC_EDIT_PASSWD, m_strPassed);
	DDX_Text(pDX, IDC_EDIT_USERNAME, m_strUserName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Dialog_UserInfo, CDialog)
	//{{AFX_MSG_MAP(Dialog_UserInfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Dialog_UserInfo message handlers

void Dialog_UserInfo::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	CString csSql;
	m_strUserName.TrimLeft();
	m_strUserName.TrimRight();
	csSql.Format("select * from userinfo where username=\"%s\" ", m_strUserName);
	if (!g_adoDataSet.Open(csSql,CADODataset::openQuery))
		return ;
	
	DWORD dwCnt	 = g_adoDataSet.GetRecordCount();	
	if (dwCnt<=0)
	{
		MessageBox("此用户名不存在,请重新输入！","提示",MB_OK);
		(CEdit*)GetDlgItem(IDC_EDIT_USERNAME)->SetFocus();
		((CEdit*)GetDlgItem(IDC_EDIT_USERNAME))->SetSel(0, -1);
		return;
	}
	int index=0;
	CString strPasswd;
	while (!g_adoDataSet.IsEof())
	{
		if(!g_adoDataSet.GetCollect("passwd",strPasswd)) return;
		index++;
		g_adoDataSet.MoveNext();
	}
	if(m_strPassed.Compare(strPasswd)!=0)
	{
		MessageBox("密码不正确，请重新输入","提示",MB_OK);
		(CEdit*)GetDlgItem(IDC_EDIT_PASSWD)->SetFocus();
		((CEdit*)GetDlgItem(IDC_EDIT_PASSWD))->SetSel(0, -1);
		return;
	}
	FILE * fp = fopen("userinfo.ini","wb+");
	if(fp==NULL)
	{
		return;
	}
	fwrite("LastUserName=",13,1,fp);
	fwrite(m_strUserName,m_strUserName.GetLength(),1,fp);
	fclose(fp);

	CDialog::OnOK();
}

BOOL Dialog_UserInfo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	FILE * fp = fopen("userinfo.ini","r");
	if(fp==NULL)
	{
		return TRUE;
	}
	char temp[255] = {0} ;
	fgets(temp,255,fp);
	fclose(fp);
	char *ip = strstr(temp,"=");
	m_strUserName.Format("%s",ip+1);
	
	//m_ipaddress.SetWindowText(m_strip);
	UpdateData(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
