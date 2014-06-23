// GoodsManageSystemDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GoodsManageSystem.h"
#include "GoodsManageSystemDlg.h"
#include "DIALOG_INPUT_CLIENT.h"
#include "Dialog_InputSell.h"
#include "Dialog_InputBuy.h"
#include "Dialog_UserInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGoodsManageSystemDlg dialog

CGoodsManageSystemDlg::CGoodsManageSystemDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGoodsManageSystemDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGoodsManageSystemDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGoodsManageSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGoodsManageSystemDlg)
	DDX_Control(pDX, IDC_TAB1, m_tab);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGoodsManageSystemDlg, CDialog)
	//{{AFX_MSG_MAP(CGoodsManageSystemDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_WM_SIZE()
	ON_COMMAND(IDM_HELP, OnHelp)
	ON_COMMAND(IDM_CLIENT_ADD, OnClientAdd)
	ON_COMMAND(IDM_CLIENT_QUERY, OnClientQuery)
	ON_COMMAND(IDM_SELL_ADD, OnSellAdd)
	ON_COMMAND(IDM_SELL_QUERY, OnSellQuery)
	ON_COMMAND(IDM_BUY_ADD, OnBuyAdd)
	ON_COMMAND(IDM_BUY_QUERY, OnBuyQuery)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGoodsManageSystemDlg message handlers

BOOL CGoodsManageSystemDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	SetWindowText("货物管理系统");

	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);
	CRect rectSc(0,0,width,height);
	//MoveWindow(&rectSc);
	//CRect recttab(0,20,width,height);
	//m_tab.MoveWindow(&recttab);
	m_imagelist.Create(24,24,ILC_COLOR24|ILC_MASK,1,0);
	
	//向图像列表中添加图标
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON3));
	
	//将图像列表关联到标签控件中
	m_tab.SetImageList(&m_imagelist);
	
	//添加标签页
	m_tab.InsertItem(0,"客户资料",0);
	m_tab.InsertItem(1,"出货信息",1);
	m_tab.InsertItem(2,"进货信息",2);
	
	CDIALOG_CLIENT* pClient = new CDIALOG_CLIENT();
	m_tab.m_pClient = pClient;
	pClient->Create(IDD_DIALOG_CLIENT,&m_tab);
	
	CDialog_SELL*  pSell = new CDialog_SELL();
	m_tab.m_pSell = pSell;
	pSell->Create(IDD_DIALOG_SELL,&m_tab);	
	
	CDIALOG_BUY*  pBuy = new CDIALOG_BUY();
	m_tab.m_pbuy = pBuy;
	pBuy->Create(IDD_DIALOG_BUY,&m_tab);
	
	CRect rect;
	m_tab.GetClientRect(rect);
	rect.InflateRect(-1,-30,-2,-2);
	pSell->MoveWindow(rect);
	pSell->ShowWindow(SW_SHOW);
	m_tab.SetCurSel(1);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
	}
	
void CGoodsManageSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGoodsManageSystemDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGoodsManageSystemDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGoodsManageSystemDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	//CDialog::OnCancel();
}

void CGoodsManageSystemDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
//	AnimateWindow(this->GetSafeHwnd(),800,AW_HOR_NEGATIVE|AW_HIDE|AW_VER_POSITIVE);
	CDialog::OnClose();
	CDialog::OnCancel();
}

void CGoodsManageSystemDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	
}

void CGoodsManageSystemDlg::OnHelp() 
{
	// TODO: Add your command handler code here
	CAboutDlg dlg;
	dlg.DoModal();
}

void CGoodsManageSystemDlg::OnClientAdd() 
{
	// TODO: Add your command handler code here
	CRect rect;
	GetClientRect(rect); //获取客户区域
	rect.DeflateRect(1,30,2,2);
	m_tab.m_pSell->ShowWindow(SW_HIDE); 
	m_tab.m_pbuy->ShowWindow(SW_HIDE); 
	m_tab.m_pClient->MoveWindow(rect);	
	m_tab.m_pClient->ShowWindow(SW_SHOW);
	m_tab.SetCurSel(0);

	CDIALOG_INPUT_CLIENT InputClient;
	if (InputClient.DoModal()==IDOK)
	{
		m_tab.m_pClient->m_list_Clinet.DeleteAllItems();
		CString strLogID;
		strLogID.Format("%d",InputClient.m_dLogId);
		m_tab.m_pClient->m_list_Clinet.InsertItem(0,strLogID);
		m_tab.m_pClient->m_list_Clinet.SetItemText(0,1,InputClient.m_strCompanyName);
		m_tab.m_pClient->m_list_Clinet.SetItemText(0,2,InputClient.m_strTaxIndex);
		m_tab.m_pClient->m_list_Clinet.SetItemText(0,3,InputClient.m_strBank);
		m_tab.m_pClient->m_list_Clinet.SetItemText(0,4,InputClient.m_strAddress);
		m_tab.m_pClient->m_list_Clinet.SetItemText(0,5,InputClient.m_strReceiver);
		m_tab.m_pClient->m_list_Clinet.SetItemText(0,6,InputClient.m_strMail);
	}
	
}

void CGoodsManageSystemDlg::OnClientQuery() 
{
	// TODO: Add your command handler code here
	CRect rect;
	GetClientRect(rect); //获取客户区域
	rect.DeflateRect(1,30,2,2);
	m_tab.m_pSell->ShowWindow(SW_HIDE); 
	m_tab.m_pbuy->ShowWindow(SW_HIDE); 
	m_tab.m_pClient->MoveWindow(rect);	
	m_tab.m_pClient->ShowWindow(SW_SHOW);
	m_tab.SetCurSel(0);	
	//m_tab.m_pClient->m_list_Clinet.DeleteAllItems();
}

void CGoodsManageSystemDlg::OnSellAdd() 
{
	// TODO: Add your command handler code here
	CRect rect;
	GetClientRect(rect); //获取客户区域
	rect.DeflateRect(1,30,2,2);
	m_tab.m_pbuy->ShowWindow(SW_HIDE); 
	m_tab.m_pClient->ShowWindow(SW_HIDE); 
	m_tab.m_pSell->MoveWindow(rect);	
	m_tab.m_pSell->ShowWindow(SW_SHOW);
	m_tab.SetCurSel(1);

	CDialog_InputSell InputSell;
	if (InputSell.DoModal()==IDOK)
	{
		m_tab.m_pSell->m_list_Sell.DeleteAllItems();
		m_tab.m_pSell->m_list_Sell.InsertItem(0,InputSell.m_strLogId);
		m_tab.m_pSell->m_list_Sell.SetItemText(0,1,InputSell.m_strTime);
		m_tab.m_pSell->m_list_Sell.SetItemText(0,2,InputSell.m_strComName);
		m_tab.m_pSell->m_list_Sell.SetItemText(0,3,InputSell.m_strProduct);
		m_tab.m_pSell->m_list_Sell.SetItemText(0,4,InputSell.m_strTotalPrice);
		m_tab.m_pSell->m_list_Sell.SetItemText(0,5,InputSell.m_strSellPrice);
	}	
}

void CGoodsManageSystemDlg::OnSellQuery() 
{
	// TODO: Add your command handler code here
	CRect rect;
	GetClientRect(rect); //获取客户区域
	rect.DeflateRect(1,30,2,2);
	m_tab.m_pbuy->ShowWindow(SW_HIDE); 
	m_tab.m_pClient->ShowWindow(SW_HIDE); 
	m_tab.m_pSell->MoveWindow(rect);	
	m_tab.m_pSell->ShowWindow(SW_SHOW);
	m_tab.SetCurSel(1);	
	//m_tab.m_pSell->m_list_Sell.DeleteAllItems();
	
}

void CGoodsManageSystemDlg::OnBuyAdd() 
{
	// TODO: Add your command handler code here
	CRect rect;
	GetClientRect(rect); //获取客户区域
	rect.DeflateRect(1,30,2,2);
	m_tab.m_pSell->ShowWindow(SW_HIDE); 
	m_tab.m_pClient->ShowWindow(SW_HIDE); 
	m_tab.m_pbuy->MoveWindow(rect);	
	m_tab.m_pbuy->ShowWindow(SW_SHOW);
	m_tab.SetCurSel(2);

	CDialog_InputBuy Inputbuy;
	if (Inputbuy.DoModal()==IDOK)
	{
		m_tab.m_pbuy->m_list_Buy.DeleteAllItems();
		CString strLogId;
		strLogId.Format("%d",Inputbuy.m_dLogId);
		m_tab.m_pbuy->m_list_Buy.InsertItem(0,strLogId);
		m_tab.m_pbuy->m_list_Buy.SetItemText(0,1,Inputbuy.m_strTime);
		m_tab.m_pbuy->m_list_Buy.SetItemText(0,2,Inputbuy.m_strComName);
		m_tab.m_pbuy->m_list_Buy.SetItemText(0,3,Inputbuy.m_strProduct);
		m_tab.m_pbuy->m_list_Buy.SetItemText(0,4,Inputbuy.m_strTotalPrice);
		m_tab.m_pbuy->m_list_Buy.SetItemText(0,5,Inputbuy.m_strSellPrice);
	}
	
}

void CGoodsManageSystemDlg::OnBuyQuery() 
{
	// TODO: Add your command handler code here
	CRect rect;
	GetClientRect(rect); //获取客户区域
	rect.DeflateRect(1,30,2,2);
	m_tab.m_pSell->ShowWindow(SW_HIDE); 
	m_tab.m_pClient->ShowWindow(SW_HIDE); 
	m_tab.m_pbuy->MoveWindow(rect);	
	m_tab.m_pbuy->ShowWindow(SW_SHOW);
	m_tab.SetCurSel(2);	
	//m_tab.m_pbuy->m_list_Buy.DeleteAllItems();
}
