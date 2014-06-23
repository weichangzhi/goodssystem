# Microsoft Developer Studio Project File - Name="GoodsManageSystem" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=GoodsManageSystem - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "GoodsManageSystem.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "GoodsManageSystem.mak" CFG="GoodsManageSystem - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "GoodsManageSystem - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "GoodsManageSystem - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "GoodsManageSystem - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386 /out:"Release/货物管理.exe"

!ELSEIF  "$(CFG)" == "GoodsManageSystem - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "GoodsManageSystem - Win32 Release"
# Name "GoodsManageSystem - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AdoDB.cpp
# End Source File
# Begin Source File

SOURCE=.\DIALOG_BUY.cpp
# End Source File
# Begin Source File

SOURCE=.\DIALOG_CLIENT.cpp
# End Source File
# Begin Source File

SOURCE=.\DIALOG_INPUT_CLIENT.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog_InputBuy.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog_InputSell.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog_SELL.cpp
# End Source File
# Begin Source File

SOURCE=.\GoodsManageSystem.cpp
# End Source File
# Begin Source File

SOURCE=.\GoodsManageSystem.rc
# End Source File
# Begin Source File

SOURCE=.\GoodsManageSystemDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Preview.cpp
# End Source File
# Begin Source File

SOURCE=.\SelTab.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AdoDB.h
# End Source File
# Begin Source File

SOURCE=.\DIALOG_BUY.h
# End Source File
# Begin Source File

SOURCE=.\DIALOG_CLIENT.h
# End Source File
# Begin Source File

SOURCE=.\DIALOG_INPUT_CLIENT.h
# End Source File
# Begin Source File

SOURCE=.\Dialog_InputBuy.h
# End Source File
# Begin Source File

SOURCE=.\Dialog_InputSell.h
# End Source File
# Begin Source File

SOURCE=.\Dialog_SELL.h
# End Source File
# Begin Source File

SOURCE=.\GoodsManageSystem.h
# End Source File
# Begin Source File

SOURCE=.\GoodsManageSystemDlg.h
# End Source File
# Begin Source File

SOURCE=.\Preview.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SelTab.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\buy.ico
# End Source File
# Begin Source File

SOURCE=.\res\client.ico
# End Source File
# Begin Source File

SOURCE=.\res\GoodsManageSystem.ico
# End Source File
# Begin Source File

SOURCE=.\res\GoodsManageSystem.rc2
# End Source File
# Begin Source File

SOURCE=.\res\sell.ico
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
