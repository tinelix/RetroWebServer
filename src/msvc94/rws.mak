# Microsoft Visual C++ Generated NMAKE File, Format Version 2.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

!IF "$(CFG)" == ""
CFG=Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Win32 Release" && "$(CFG)" != "Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "rws.mak" CFG="Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

################################################################################
# Begin Project
# PROP Target_Last_Scanned "Win32 Debug"
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WinRel"
# PROP BASE Intermediate_Dir "WinRel"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WinRel"
# PROP Intermediate_Dir "WinRel"
OUTDIR=.\WinRel
INTDIR=.\WinRel

ALL : .\build\release\binRetroWebServer.exe .\WinRel\rws.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

# ADD BASE CPP /nologo /W3 /GX /YX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /FR /c
# ADD CPP /nologo /W3 /GX /YX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /FR"build/release/" /Fp"build/release/RetroWebServer.pch" /Fo"build/release/" /c
CPP_PROJ=/nologo /W3 /GX /YX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE"\
 /FR"build/release/" /Fp"build/release/RetroWebServer.pch" /Fo"build/release/"\
 /c 
CPP_OBJS=.\build/release/
# ADD BASE RSC /l 0x419 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"rws.bsc" 
BSC32_SBRS= \
	.\build\release\main.sbr \
	.\build\release\server.sbr \
	.\build\release\clrprntf.sbr \
	.\build\release\client.sbr \
	.\build\release\httpreq.sbr \
	.\build\release\httppage.sbr \
	.\build\release\version.sbr \
	.\build\release\httperrp.sbr

.\WinRel\rws.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /NOLOGO /SUBSYSTEM:console /MACHINE:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib /NOLOGO /SUBSYSTEM:console /MACHINE:I386 /OUT:"build/release/binRetroWebServer.exe"
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib wsock32.lib /NOLOGO /SUBSYSTEM:console /INCREMENTAL:no\
 /PDB:$(OUTDIR)/"rws.pdb" /MACHINE:I386\
 /OUT:"build/release/binRetroWebServer.exe" 
DEF_FILE=
LINK32_OBJS= \
	.\build\release\main.obj \
	.\build\release\server.obj \
	.\build\release\clrprntf.obj \
	.\build\release\client.obj \
	.\build\release\httpreq.obj \
	.\build\release\httppage.obj \
	.\build\release\version.obj \
	.\build\release\httperrp.obj

.\build\release\binRetroWebServer.exe : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WinDebug"
# PROP BASE Intermediate_Dir "WinDebug"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "build/debug/out"
# PROP Intermediate_Dir "build/debug/ind"
OUTDIR=.\build/debug/out
INTDIR=.\build/debug/ind

ALL : .\build\debug\bin\RetroWebServer.exe .\build\debug\RetroWebServer.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

$(INTDIR) : 
    if not exist $(INTDIR)/nul mkdir $(INTDIR)

# ADD BASE CPP /nologo /W3 /GX /Zi /YX /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /FR /c
# ADD CPP /nologo /MT /W3 /GX /Zi /Od /I "src/include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /FR /Fo"build/debug/" /Fd"build/debug/pdb/RetroWebServer.pdb" /c
# SUBTRACT CPP /Yc
CPP_PROJ=/nologo /MT /W3 /GX /Zi /Od /I "src/include" /D "WIN32" /D "_DEBUG" /D\
 "_CONSOLE" /FR$(INTDIR)/ /Fo"build/debug/"\
 /Fd"build/debug/pdb/RetroWebServer.pdb" /c 
CPP_OBJS=.\build/debug/
# ADD BASE RSC /l 0x419 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"build/debug/RetroWebServer.bsc"
BSC32_FLAGS=/nologo /o"build/debug/RetroWebServer.bsc" 
BSC32_SBRS= \
	.\build\debug\ind\main.sbr \
	.\build\debug\ind\server.sbr \
	.\build\debug\ind\clrprntf.sbr \
	.\build\debug\ind\client.sbr \
	.\build\debug\ind\httpreq.sbr \
	.\build\debug\ind\httppage.sbr \
	.\build\debug\ind\version.sbr \
	.\build\debug\ind\httperrp.sbr

.\build\debug\RetroWebServer.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /NOLOGO /SUBSYSTEM:console /DEBUG /MACHINE:I386
# ADD LINK32 wsock32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /NOLOGO /SUBSYSTEM:console /PDB:"build/debug/pdb/RetroWebServer.pdb" /DEBUG /MACHINE:I386 /OUT:"build/debug/bin/RetroWebServer.exe"
# SUBTRACT LINK32 /PDB:none
LINK32_FLAGS=wsock32.lib kernel32.lib user32.lib gdi32.lib winspool.lib\
 comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib\
 odbc32.lib odbccp32.lib /NOLOGO /SUBSYSTEM:console /INCREMENTAL:yes\
 /PDB:"build/debug/pdb/RetroWebServer.pdb" /DEBUG /MACHINE:I386\
 /OUT:"build/debug/bin/RetroWebServer.exe" 
DEF_FILE=
LINK32_OBJS= \
	.\build\debug\main.obj \
	.\build\debug\server.obj \
	.\build\debug\clrprntf.obj \
	.\build\debug\client.obj \
	.\build\debug\httpreq.obj \
	.\build\debug\httppage.obj \
	.\build\debug\version.obj \
	.\build\debug\httperrp.obj

.\build\debug\bin\RetroWebServer.exe : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Group "Source Files"

################################################################################
# Begin Source File

SOURCE=.\src\main.c

!IF  "$(CFG)" == "Win32 Release"

.\build\release\main.obj :  $(SOURCE)  $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Debug"

.\build\debug\main.obj :  $(SOURCE)  $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\src\rws\server.c

!IF  "$(CFG)" == "Win32 Release"

.\build\release\server.obj :  $(SOURCE)  $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Debug"

.\build\debug\server.obj :  $(SOURCE)  $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\src\rws\clrprntf.c

!IF  "$(CFG)" == "Win32 Release"

.\build\release\clrprntf.obj :  $(SOURCE)  $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Debug"

.\build\debug\clrprntf.obj :  $(SOURCE)  $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\src\rws\client.c

!IF  "$(CFG)" == "Win32 Release"

.\build\release\client.obj :  $(SOURCE)  $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Debug"

.\build\debug\client.obj :  $(SOURCE)  $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\src\rws\httpreq.c
DEP_HTTPR=\
	.\src\include\rws\httpreq.h

!IF  "$(CFG)" == "Win32 Release"

.\build\release\httpreq.obj :  $(SOURCE)  $(DEP_HTTPR) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Debug"

.\build\debug\httpreq.obj :  $(SOURCE)  $(DEP_HTTPR) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\src\rws\httppage.c

!IF  "$(CFG)" == "Win32 Release"

.\build\release\httppage.obj :  $(SOURCE)  $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Debug"

.\build\debug\httppage.obj :  $(SOURCE)  $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\src\rws\version.c
DEP_VERSI=\
	.\src\include\rws\version.h

!IF  "$(CFG)" == "Win32 Release"

.\build\release\version.obj :  $(SOURCE)  $(DEP_VERSI) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Debug"

.\build\debug\version.obj :  $(SOURCE)  $(DEP_VERSI) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\src\rws\httperrp.c

!IF  "$(CFG)" == "Win32 Release"

.\build\release\httperrp.obj :  $(SOURCE)  $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Debug"

.\build\debug\httperrp.obj :  $(SOURCE)  $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ENDIF 

# End Source File
# End Group
################################################################################
# Begin Group "Header Files"

################################################################################
# Begin Source File

SOURCE=.\src\include\rws\server.h
# End Source File
################################################################################
# Begin Source File

SOURCE=.\src\include\rws\version.h
# End Source File
################################################################################
# Begin Source File

SOURCE=.\src\include\rws\clrprntf.h
# End Source File
################################################################################
# Begin Source File

SOURCE=.\src\include\rws\client.h
# End Source File
################################################################################
# Begin Source File

SOURCE=.\src\include\rws\httpreq.h
# End Source File
################################################################################
# Begin Source File

SOURCE=.\src\include\rws\httppage.h
# End Source File
################################################################################
# Begin Source File

SOURCE=.\src\include\rws\httperrp.h
# End Source File
# End Group
# End Project
################################################################################
