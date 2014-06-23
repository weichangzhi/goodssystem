; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=Dialog_UserInfo
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "GoodsManageSystem.h"

ClassCount=12
Class1=CGoodsManageSystemApp
Class2=CGoodsManageSystemDlg
Class3=CAboutDlg

ResourceCount=13
Resource1=IDD_DIALOG_SELL
Resource2=IDR_MAINFRAME
Resource3=IDR_MENU1
Resource4=IDD_DIALOG_USERINFO
Resource5=IDD_DIALOG_INPUT_SELL
Class4=CDialog_SELL
Class5=CDIALOG_CLIENT
Class6=CDIALOG_BUY
Class7=CSelTab
Resource6=IDD_GOODSMANAGESYSTEM_DIALOG
Class8=CDIALOG_INPUT_CLIENT
Resource7=IDD_ABOUTBOX
Class9=CDialog_InputSell
Resource8=IDD_DIALOG_BUY
Class10=CDialog_InputBuy
Resource9=IDD_DIALOG_INPUT_CLIENT
Resource10=IDD_DIGPREVIEW
Resource11=IDD_DIALOG_CLIENT
Class11=CPreview
Resource12=IDD_DIALOG_INPUT_BUY
Class12=Dialog_UserInfo
Resource13=IDR_MENUMAIN

[CLS:CGoodsManageSystemApp]
Type=0
HeaderFile=GoodsManageSystem.h
ImplementationFile=GoodsManageSystem.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC
LastObject=CGoodsManageSystemApp

[CLS:CGoodsManageSystemDlg]
Type=0
HeaderFile=GoodsManageSystemDlg.h
ImplementationFile=GoodsManageSystemDlg.cpp
Filter=D
LastObject=CGoodsManageSystemDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=GoodsManageSystemDlg.h
ImplementationFile=GoodsManageSystemDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352

[DLG:IDD_GOODSMANAGESYSTEM_DIALOG]
Type=1
Class=CGoodsManageSystemDlg
ControlCount=1
Control1=IDC_TAB1,SysTabControl32,1342193920

[DLG:IDD_DIALOG_CLIENT]
Type=1
Class=CDIALOG_CLIENT
ControlCount=6
Control1=IDC_EDIT_CLIENT,edit,1350631552
Control2=IDC_BUTTON_CLIENT_SELECT,button,1342242817
Control3=IDC_BUTTON_CLIENT_ADD,button,1342242816
Control4=IDC_COMBO_CLIENT,combobox,1344340227
Control5=IDC_LIST_CLIENT,SysListView32,1350631425
Control6=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG_SELL]
Type=1
Class=CDialog_SELL
ControlCount=6
Control1=IDC_EDIT_SELL,edit,1350631552
Control2=IDC_BUTTON_SELL_SELECT,button,1342242817
Control3=IDC_BUTTON_SELL_ADD,button,1342242816
Control4=IDC_COMBO_SELL,combobox,1344340227
Control5=IDC_LIST_SELL,SysListView32,1350631425
Control6=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG_BUY]
Type=1
Class=CDIALOG_BUY
ControlCount=6
Control1=IDC_EDIT_BUY,edit,1350631552
Control2=IDC_BUTTON_BUY_SELECT,button,1342242817
Control3=IDC_BUTTON_BUY_ADD,button,1342242816
Control4=IDC_COMBO_BUY,combobox,1344340227
Control5=IDC_STATIC,static,1342308352
Control6=IDC_LIST_BUY,SysListView32,1350631425

[CLS:CDialog_SELL]
Type=0
HeaderFile=Dialog_SELL.h
ImplementationFile=Dialog_SELL.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LIST_SELL
VirtualFilter=dWC

[CLS:CDIALOG_CLIENT]
Type=0
HeaderFile=DIALOG_CLIENT.h
ImplementationFile=DIALOG_CLIENT.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_LIST_CLIENT

[CLS:CDIALOG_BUY]
Type=0
HeaderFile=DIALOG_BUY.h
ImplementationFile=DIALOG_BUY.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_LIST_BUY

[CLS:CSelTab]
Type=0
HeaderFile=SelTab.h
ImplementationFile=SelTab.cpp
BaseClass=CTabCtrl
Filter=W
VirtualFilter=UWC
LastObject=CSelTab

[DLG:IDD_DIALOG_INPUT_CLIENT]
Type=1
Class=CDIALOG_INPUT_CLIENT
ControlCount=16
Control1=IDC_EDIT_COMPANYNAME,edit,1350631552
Control2=IDC_EDIT_TAXINDEX,edit,1350631552
Control3=IDC_EDIT_BANKNO,edit,1350631552
Control4=IDC_EDIT_ADDRESSPHONE,edit,1350631552
Control5=IDC_EDIT_RECEIVER,edit,1350631552
Control6=IDC_EDIT_MAILADDRESSPHONE,edit,1350631552
Control7=IDOK,button,1342242817
Control8=IDCANCEL,button,1342242816
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_EDIT_CLIENT_LOGID,edit,1484849280

[CLS:CDIALOG_INPUT_CLIENT]
Type=0
HeaderFile=DIALOG_INPUT_CLIENT.h
ImplementationFile=DIALOG_INPUT_CLIENT.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDIALOG_INPUT_CLIENT

[DLG:IDD_DIALOG_INPUT_SELL]
Type=1
Class=CDialog_InputSell
ControlCount=46
Control1=IDC_EDIT_INPUTSELL_COMPANYNAME,edit,1350631552
Control2=IDC_EDIT_INPUTSELL_USERADDRESS,edit,1350631552
Control3=IDC_EDIT_INPUTSELL_USERPHONE,edit,1350631552
Control4=IDC_EDIT_INPUTSELL_USERNAME,edit,1350631552
Control5=IDC_EDIT_INPUTSELL_SELLNAME,edit,1350631552
Control6=IDC_EDIT_INPUTSELL_SELLPHONE,edit,1350631552
Control7=IDC_EDIT_INPUTSELL_PRODUCTMODEL,edit,1350631552
Control8=IDC_EDIT_INPUTSELL_PROPRICE,edit,1350631552
Control9=IDC_EDIT_INPUTSELL_PRONUM,edit,1350631552
Control10=IDC_EDIT_INPUTSELL_UINT,edit,1350631552
Control11=IDC_EDIT_INPUTSELL_MONEY,edit,1350631552
Control12=IDC_EDIT_INPUTSELL_TIPS,edit,1350631552
Control13=IDC_EDIT_INPUTSELL_TOTALPRICE,edit,1350631552
Control14=IDC_EDIT_INPUTSELL_SELLPRICE,edit,1350631552
Control15=IDOK,button,1342242817
Control16=IDCANCEL,button,1342242816
Control17=IDC_BUTPREVIEW,button,1073807360
Control18=IDC_BUTPRINT,button,1073807360
Control19=IDC_DATETIMEPICKER1,SysDateTimePick32,1342242848
Control20=IDC_BUTTON_ADD,button,1342242816
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC,static,1342308352
Control25=IDC_STATIC,static,1342308352
Control26=IDC_STATIC,static,1342308352
Control27=IDC_STATIC,static,1342308352
Control28=IDC_STATIC,button,1342177287
Control29=IDC_STATIC,button,1342177287
Control30=IDC_LIST_Product,SysListView32,1350631433
Control31=IDC_STATIC,static,1342308352
Control32=IDC_STATIC,static,1342308352
Control33=IDC_STATIC,static,1342308352
Control34=IDC_STATIC,static,1342308352
Control35=IDC_EDIT_SELL_LOGID,edit,1484849280
Control36=IDC_STATIC,button,1342177287
Control37=IDC_STATIC,static,1342308352
Control38=IDC_STATIC,static,1342308352
Control39=IDC_STATIC,static,1342308352
Control40=IDC_STATIC,button,1342177287
Control41=IDC_STATIC,static,1342308352
Control42=IDC_STATIC,static,1342308352
Control43=IDC_STATIC,static,1342308352
Control44=IDC_STATIC,static,1342308352
Control45=IDC_STATIC,static,1342308352
Control46=IDC_STATIC,static,1342308352

[CLS:CDialog_InputSell]
Type=0
HeaderFile=Dialog_InputSell.h
ImplementationFile=Dialog_InputSell.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDialog_InputSell

[DLG:IDD_DIALOG_INPUT_BUY]
Type=1
Class=CDialog_InputBuy
ControlCount=25
Control1=IDC_DATETIMEPICKER2,SysDateTimePick32,1342242848
Control2=IDC_EDIT_INPUTBUY_COMPANYNAME,edit,1350631552
Control3=IDC_EDIT_INPUTBUY_PRODUCTMODEL,edit,1350631552
Control4=IDC_EDIT_INPUTBUY_PRONUM,edit,1350631552
Control5=IDC_EDIT_INPUTBUY_PROPRICE,edit,1350631552
Control6=IDC_BUTTON_ADD2,button,1342242816
Control7=IDC_EDIT_INPUTBUY_TOTALPRICE,edit,1350631552
Control8=IDC_EDIT_INPUTBUY_SELLPRICE,edit,1350631552
Control9=IDOK,button,1342242817
Control10=IDCANCEL,button,1342242816
Control11=IDC_LIST_Product2,SysListView32,1350631425
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,button,1342177287
Control20=IDC_STATIC,button,1342177287
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC,static,1342308352
Control25=IDC_EDIT_BUY_LOGID,edit,1484849280

[CLS:CDialog_InputBuy]
Type=0
HeaderFile=Dialog_InputBuy.h
ImplementationFile=Dialog_InputBuy.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDialog_InputBuy

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_MENUITEM_INPUTSELL
CommandCount=1

[MNU:IDR_MENUMAIN]
Type=1
Class=?
Command1=IDM_CLIENT_ADD
Command2=IDM_CLIENT_QUERY
Command3=IDM_SELL_ADD
Command4=IDM_SELL_QUERY
Command5=IDM_BUY_ADD
Command6=IDM_BUY_QUERY
Command7=IDM_HELP
CommandCount=7

[DLG:IDD_DIGPREVIEW]
Type=1
Class=CPreview
ControlCount=0

[CLS:CPreview]
Type=0
HeaderFile=Preview.h
ImplementationFile=Preview.cpp
BaseClass=CDialog
Filter=D
LastObject=CPreview
VirtualFilter=dWC

[DLG:IDD_DIALOG_USERINFO]
Type=1
Class=Dialog_UserInfo
ControlCount=6
Control1=IDC_EDIT_USERNAME,edit,1350631552
Control2=IDC_EDIT_PASSWD,edit,1350631584
Control3=IDOK,button,1342242817
Control4=IDCANCEL,button,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[CLS:Dialog_UserInfo]
Type=0
HeaderFile=Dialog_UserInfo.h
ImplementationFile=Dialog_UserInfo.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=Dialog_UserInfo

