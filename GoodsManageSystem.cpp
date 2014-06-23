// GoodsManageSystem.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "GoodsManageSystem.h"
#include "GoodsManageSystemDlg.h"
#include "Dialog_UserInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGoodsManageSystemApp

BEGIN_MESSAGE_MAP(CGoodsManageSystemApp, CWinApp)
	//{{AFX_MSG_MAP(CGoodsManageSystemApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGoodsManageSystemApp construction

CGoodsManageSystemApp::CGoodsManageSystemApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CGoodsManageSystemApp object

CGoodsManageSystemApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CGoodsManageSystemApp initialization

BOOL CGoodsManageSystemApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CHAR lpBuffer[FILENAME_MAX];
	GetModuleFileName(m_hInstance,lpBuffer,FILENAME_MAX);
	CString dir(lpBuffer);
	
	dir=dir.Left(dir.ReverseFind('\\')+1);
	CString dbDir=dir+_T("ManageSys.mdb");
	if(!g_adoConn.ConDB(dbDir,"111111"))
	{
		MessageBox(NULL,"数据库连接失败","提示",MB_OK);
		return FALSE;
	}
	g_adoDataSet.SetConnection(&g_adoConn);

	Dialog_UserInfo userinfo;
	if(userinfo.DoModal()==IDOK)
	{
		CGoodsManageSystemDlg dlg;
		m_pMainWnd = &dlg;
		int nResponse = dlg.DoModal();
		if (nResponse == IDOK)
		{
			// TODO: Place code here to handle when the dialog is
			//  dismissed with OK
		}
		else if (nResponse == IDCANCEL)
		{
			// TODO: Place code here to handle when the dialog is
			//  dismissed with Cancel
		}		
	}


	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

int CGoodsManageSystemApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	g_adoConn.Close();
	g_adoDataSet.Close();
	return CWinApp::ExitInstance();
}
