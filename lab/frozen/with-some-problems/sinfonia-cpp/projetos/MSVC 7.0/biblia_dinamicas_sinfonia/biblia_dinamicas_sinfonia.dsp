# Microsoft Developer Studio Project File - Name="biblia_dinamicas_sinfonia" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=biblia_dinamicas_sinfonia - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "biblia_dinamicas_sinfonia.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "biblia_dinamicas_sinfonia.mak" CFG="biblia_dinamicas_sinfonia - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "biblia_dinamicas_sinfonia - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "biblia_dinamicas_sinfonia - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "biblia_dinamicas_sinfonia - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../../../deploy"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GR /GX /O2 /I "../../../src/cpp/include" /I "../../../src/cpp/includeExt" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_REENTRANT" /YX /FD /Zm1000 /c
# ADD BASE RSC /l 0x416 /d "NDEBUG"
# ADD RSC /l 0x416 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"biblia_dinamicas_sinfonia.bsc"
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"../../../deploy/biblia.dinamicas.sinfonia.lib"

!ELSEIF  "$(CFG)" == "biblia_dinamicas_sinfonia - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../../../deploy"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GR /GX /ZI /Od /I "../../../src/cpp/include" /I "../../../src/cpp/includeExt" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_REENTRANT" /YX /FD /Zm1000 /GZ /c
# ADD BASE RSC /l 0x416 /d "_DEBUG"
# ADD RSC /l 0x416 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"biblia_dinamicas_sinfonia-debug.bsc"
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"../../../deploy/biblia.dinamicas.sinfonia-debug.lib"

!ENDIF 

# Begin Target

# Name "biblia_dinamicas_sinfonia - Win32 Release"
# Name "biblia_dinamicas_sinfonia - Win32 Debug"
# Begin Group "Fonte (cpp)"

# PROP Default_Filter "*.cpp, *.c"
# Begin Group ".gde"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\gde\Animacao.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\gde\AreaClicavel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\gde\MouseBiblia.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\gde\RegraDeEstados.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\gde\Som.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\gde\TecladoAllegro.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\gde\Timer.cpp
# End Source File
# End Group
# Begin Group ".sinfonia"

# PROP Default_Filter ""
# Begin Group ".estado"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\Estado.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\EstadoAlvo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\EstadoDependente.cpp
# End Source File
# End Group
# Begin Group ".evento"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\Evento.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\ModificadorDeEstado.cpp
# End Source File
# End Group
# Begin Group ".acessorios"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\Classe.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\Genesis.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\Multifuncional.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\OuvidorDosGeradoresDeEventos.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\Rotulado.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\ScriptDinamica.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\SinfoniaExcecao.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\Universo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\UniversoMultifuncional.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\Valor.cpp
# End Source File
# End Group
# Begin Group ".concretização"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\Concretizador.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\Resultado.cpp
# End Source File
# End Group
# Begin Group ".dinamica"

# PROP Default_Filter ""
# Begin Group ".condicao"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\Condicao.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\CondicaoComposta.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\CondicaoDeComparacao.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\CondicaoImpl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\CondicaoModificadora.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\GeradorDeEventos.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\GeradorDeEventosDependente.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\GeradorDeEventosEspecial.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\MediadorDeEstados.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\Sinfonia.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\Situacao.cpp
# End Source File
# End Group
# End Group
# Begin Group ".util"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\cpp\src\biblia\dinamicas\sinfonia\util\Lock.cpp
# End Source File
# End Group
# End Group
# Begin Group "Cabeçalho (H)"

# PROP Default_Filter "*.h, *.hpp"
# Begin Group "gde"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\gde\Animacao.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\gde\AreaClicavel.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\gde\MouseBiblia.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\gde\RegraDeEstados.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\gde\Som.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\gde\TecladoAllegro.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\gde\Timer.h
# End Source File
# End Group
# Begin Group "sinfonia"

# PROP Default_Filter ""
# Begin Group "estado"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\Estado.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\EstadoAlvo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\EstadoDependente.h
# End Source File
# End Group
# Begin Group "evento"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\Evento.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\ModificadorDeEstado.h
# End Source File
# End Group
# Begin Group "acessorios"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\Classe.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\Genesis.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\Multifuncional.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\OuvidorDosGeradoresDeEventos.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\Rotulado.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\ScriptDinamica.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\SinfoniaExcecao.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\Universo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\UniversoMultifuncional.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\Valor.h
# End Source File
# End Group
# Begin Group "concretização"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\Concretizador.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\Resultado.h
# End Source File
# End Group
# Begin Group "dinamica"

# PROP Default_Filter ""
# Begin Group "condicao"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\Condicao.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\CondicaoComposta.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\CondicaoDeComparacao.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\CondicaoImpl.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\CondicaoModificadora.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\GeradorDeEventos.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\GeradorDeEventosDependente.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\GeradorDeEventosEspecial.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\MediadorDeEstados.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\Sinfonia.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\Situacao.h
# End Source File
# End Group
# End Group
# Begin Group "util"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\cpp\include\biblia\dinamicas\sinfonia\util\Lock.h
# End Source File
# End Group
# End Group
# End Target
# End Project
