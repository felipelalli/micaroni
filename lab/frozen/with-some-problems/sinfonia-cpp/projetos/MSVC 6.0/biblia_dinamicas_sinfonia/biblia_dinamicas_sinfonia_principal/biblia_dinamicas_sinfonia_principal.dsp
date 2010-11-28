# Microsoft Developer Studio Project File - Name="biblia_dinamicas_sinfonia_principal" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=biblia_dinamicas_sinfonia_principal - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "biblia_dinamicas_sinfonia_principal.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "biblia_dinamicas_sinfonia_principal.mak" CFG="biblia_dinamicas_sinfonia_principal - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "biblia_dinamicas_sinfonia_principal - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "biblia_dinamicas_sinfonia_principal - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "biblia_dinamicas_sinfonia_principal - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GR /GX /O2 /I "../../../../src/cpp/include" /I "../../../../src/cpp/includeExt" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_REENTRANT" /YX /FD /Zm800 /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x416 /d "NDEBUG"
# ADD RSC /l 0x416 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 biblia.dinamicas.sinfonia.lib stlport_static_r50.lib stlport_static_stld50.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib alleg.lib fmodvc.lib xerces-c_2.lib zlib.lib biblia.old-1.2.lib /nologo /subsystem:windows /incremental:yes /machine:I386 /out:"../../../../deploy/biblia_dinamicas_sinfonia_principal.exe" /libpath:"../../../../lib" /libpath:"../../../../deploy/"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "biblia_dinamicas_sinfonia_principal - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GR /GX /ZI /Od /I "../../../../src/cpp/include" /I "../../../../src/cpp/includeExt" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_REENTRANT" /YX /FD /Zm1000 /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x416 /d "_DEBUG"
# ADD RSC /l 0x416 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 biblia.dinamicas.sinfonia-debug.lib alleg.lib fmodvc.lib stlport_static_d50.lib stlport_static_stld50.lib xerces-c_2D.lib zlib.lib biblia.old-debug-1.2.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /nodefaultlib:"LIBCMTD" /nodefaultlib:"LIBCD" /out:"../../../../deploy/biblia_dinamicas_sinfonia_principal-debug.exe" /pdbtype:sept /libpath:"../../../../lib" /libpath:"../../../../deploy/"

!ENDIF 

# Begin Target

# Name "biblia_dinamicas_sinfonia_principal - Win32 Release"
# Name "biblia_dinamicas_sinfonia_principal - Win32 Debug"
# Begin Group "Fonte (cpp)"

# PROP Default_Filter "*.cpp *.c"
# Begin Source File

SOURCE=..\..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\demonstracao\Demonstracao.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\miniaplicacao\GenesisTeste.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\miniaplicacao\MiniAplicacao.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\cpp\src\Principal.cpp
# End Source File
# End Group
# Begin Group "Cabeçalho (h)"

# PROP Default_Filter "*.h *.hpp"
# Begin Source File

SOURCE=..\..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\demonstracao\Demonstracao.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\miniaplicacao\GenesisTeste.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\miniaplicacao\MiniAplicacao.h
# End Source File
# End Group
# End Target
# End Project
