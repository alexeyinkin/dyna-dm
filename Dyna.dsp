# Microsoft Developer Studio Project File - Name="Dyna" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Dyna - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Dyna.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Dyna.mak" CFG="Dyna - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Dyna - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Dyna - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Dyna - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "NDEBUG"
# ADD RSC /l 0x419 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 winmm.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Dyna - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /w /W0 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /YX /FD /GZ /c
# SUBTRACT CPP /WX
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "_DEBUG"
# ADD RSC /l 0x419 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 winmm.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Dyna - Win32 Release"
# Name "Dyna - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Bitmap.cpp
# End Source File
# Begin Source File

SOURCE=.\Dyna.cpp
# End Source File
# Begin Source File

SOURCE=.\Dyna.rc
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Bitmap.h
# End Source File
# Begin Source File

SOURCE=.\Dyna.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\area_barrel_1.bmp
# End Source File
# Begin Source File

SOURCE=.\area_barrel_2.bmp
# End Source File
# Begin Source File

SOURCE=.\area_barrel_3.bmp
# End Source File
# Begin Source File

SOURCE=.\area_beach_1.bmp
# End Source File
# Begin Source File

SOURCE=.\area_beach_2.bmp
# End Source File
# Begin Source File

SOURCE=.\area_beach_3.bmp
# End Source File
# Begin Source File

SOURCE=.\area_bones_1.bmp
# End Source File
# Begin Source File

SOURCE=.\area_bones_2.bmp
# End Source File
# Begin Source File

SOURCE=.\area_bones_3.bmp
# End Source File
# Begin Source File

SOURCE=.\area_breakfast_1.bmp
# End Source File
# Begin Source File

SOURCE=.\area_breakfast_2.bmp
# End Source File
# Begin Source File

SOURCE=.\area_breakfast_3.bmp
# End Source File
# Begin Source File

SOURCE=.\area_card_1.bmp
# End Source File
# Begin Source File

SOURCE=.\area_card_2.bmp
# End Source File
# Begin Source File

SOURCE=.\area_card_3.bmp
# End Source File
# Begin Source File

SOURCE=.\area_chess_1.bmp
# End Source File
# Begin Source File

SOURCE=.\area_chess_2.bmp
# End Source File
# Begin Source File

SOURCE=.\area_chess_3.bmp
# End Source File
# Begin Source File

SOURCE=.\area_coolgrass_1.bmp
# End Source File
# Begin Source File

SOURCE=.\area_coolgrass_2.bmp
# End Source File
# Begin Source File

SOURCE=.\area_coolgrass_3.bmp
# End Source File
# Begin Source File

SOURCE=.\area_cows_1.bmp
# End Source File
# Begin Source File

SOURCE=.\area_cows_2.bmp
# End Source File
# Begin Source File

SOURCE=.\area_cows_3.bmp
# End Source File
# Begin Source File

SOURCE=.\area_dollars_1.bmp
# End Source File
# Begin Source File

SOURCE=.\area_dollars_2.bmp
# End Source File
# Begin Source File

SOURCE=.\area_dollars_3.bmp
# End Source File
# Begin Source File

SOURCE=.\area_field_1.bmp
# End Source File
# Begin Source File

SOURCE=.\area_field_2.bmp
# End Source File
# Begin Source File

SOURCE=.\area_field_3.bmp
# End Source File
# Begin Source File

SOURCE=.\area_firs_1.bmp
# End Source File
# Begin Source File

SOURCE=.\area_firs_2.bmp
# End Source File
# Begin Source File

SOURCE=.\area_firs_3.bmp
# End Source File
# Begin Source File

SOURCE=.\area_flowers_1.bmp
# End Source File
# Begin Source File

SOURCE=.\area_flowers_2.bmp
# End Source File
# Begin Source File

SOURCE=.\area_flowers_3.bmp
# End Source File
# Begin Source File

SOURCE=.\area_gamebones_1.bmp
# End Source File
# Begin Source File

SOURCE=.\area_gamebones_2.bmp
# End Source File
# Begin Source File

SOURCE=.\area_gamebones_3.bmp
# End Source File
# Begin Source File

SOURCE=.\area_jungle_1.bmp
# End Source File
# Begin Source File

SOURCE=.\area_jungle_2.bmp
# End Source File
# Begin Source File

SOURCE=.\area_jungle_3.bmp
# End Source File
# Begin Source File

SOURCE=.\area_lehasoft_1.bmp
# End Source File
# Begin Source File

SOURCE=.\area_lehasoft_2.bmp
# End Source File
# Begin Source File

SOURCE=.\area_lehasoft_3.bmp
# End Source File
# Begin Source File

SOURCE=.\area_mushrom_1.bmp
# End Source File
# Begin Source File

SOURCE=.\area_mushrom_2.bmp
# End Source File
# Begin Source File

SOURCE=.\area_mushrom_3.bmp
# End Source File
# Begin Source File

SOURCE=.\area_ny_1.bmp
# End Source File
# Begin Source File

SOURCE=.\area_ny_2.bmp
# End Source File
# Begin Source File

SOURCE=.\area_ny_3.bmp
# End Source File
# Begin Source File

SOURCE=.\area_send_1.bmp
# End Source File
# Begin Source File

SOURCE=.\area_send_2.bmp
# End Source File
# Begin Source File

SOURCE=.\area_send_3.bmp
# End Source File
# Begin Source File

SOURCE=.\area_space_1.bmp
# End Source File
# Begin Source File

SOURCE=.\area_space_2.bmp
# End Source File
# Begin Source File

SOURCE=.\area_space_3.bmp
# End Source File
# Begin Source File

SOURCE=.\area_system_1.bmp
# End Source File
# Begin Source File

SOURCE=.\area_system_2.bmp
# End Source File
# Begin Source File

SOURCE=.\area_system_3.bmp
# End Source File
# Begin Source File

SOURCE=.\area_tech_1.bmp
# End Source File
# Begin Source File

SOURCE=.\area_tech_2.bmp
# End Source File
# Begin Source File

SOURCE=.\area_tech_3.bmp
# End Source File
# Begin Source File

SOURCE=.\area_time_1.bmp
# End Source File
# Begin Source File

SOURCE=.\area_time_2.bmp
# End Source File
# Begin Source File

SOURCE=.\area_time_3.bmp
# End Source File
# Begin Source File

SOURCE=.\area_waves_1.bmp
# End Source File
# Begin Source File

SOURCE=.\area_waves_2.bmp
# End Source File
# Begin Source File

SOURCE=.\area_waves_3.bmp
# End Source File
# Begin Source File

SOURCE=.\area_wc_1.bmp
# End Source File
# Begin Source File

SOURCE=.\area_wc_2.bmp
# End Source File
# Begin Source File

SOURCE=.\area_wc_3.bmp
# End Source File
# Begin Source File

SOURCE=.\arrow_0.bmp
# End Source File
# Begin Source File

SOURCE=.\arrow_0_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\arrow_1.bmp
# End Source File
# Begin Source File

SOURCE=.\arrow_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\arrow_2.bmp
# End Source File
# Begin Source File

SOURCE=.\arrow_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\arrow_3.bmp
# End Source File
# Begin Source File

SOURCE=.\arrow_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\arrow_4.bmp
# End Source File
# Begin Source File

SOURCE=.\arrow_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\arrow_5.bmp
# End Source File
# Begin Source File

SOURCE=.\arrow_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\background_dm.bmp
# End Source File
# Begin Source File

SOURCE=.\background_dm_256.bmp
# End Source File
# Begin Source File

SOURCE=.\background_dm_indicators.bmp
# End Source File
# Begin Source File

SOURCE=.\background_dm_indicators_256.bmp
# End Source File
# Begin Source File

SOURCE=.\background_left.bmp
# End Source File
# Begin Source File

SOURCE=.\ball_0.bmp
# End Source File
# Begin Source File

SOURCE=.\ball_0_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\ball_1.bmp
# End Source File
# Begin Source File

SOURCE=.\ball_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\ball_2.bmp
# End Source File
# Begin Source File

SOURCE=.\ball_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\ball_3.bmp
# End Source File
# Begin Source File

SOURCE=.\ball_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\ball_4.bmp
# End Source File
# Begin Source File

SOURCE=.\ball_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\ball_5.bmp
# End Source File
# Begin Source File

SOURCE=.\ball_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\ball_6.bmp
# End Source File
# Begin Source File

SOURCE=.\ball_6_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\ball_7.bmp
# End Source File
# Begin Source File

SOURCE=.\ball_7_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\ball_8.bmp
# End Source File
# Begin Source File

SOURCE=.\ball_8_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\ball_9.bmp
# End Source File
# Begin Source File

SOURCE=.\ball_9_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\black_wall_1.bmp
# End Source File
# Begin Source File

SOURCE=.\black_wall_2.bmp
# End Source File
# Begin Source File

SOURCE=.\black_wall_3.bmp
# End Source File
# Begin Source File

SOURCE=.\blwall.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp10206.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp10207.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp10208.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp10209.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp10216.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp10217.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp10218.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp10219.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp2010.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp2020.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp2030.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp2510.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp2511.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp2512.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp2520.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp2521.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp2522.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp2710.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp2711.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp2712.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp2720.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp2721.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp2722.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp2810.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp2811.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp2812.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp2820.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp2821.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp2822.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp4102.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp5201.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8106.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8107.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8108.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8109.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8116.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8117.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8118.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8119.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8206.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8207.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8208.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8209.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8216.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8217.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8218.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8219.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8406.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8407.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8408.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8409.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8416.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8417.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8418.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8419.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8506.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8507.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8508.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8509.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8516.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8517.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8518.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8519.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8606.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8607.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8608.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8609.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8616.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8617.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8618.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8619.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8706.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8707.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8708.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8709.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8716.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8717.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8718.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8719.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8800.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8801.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8802.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8803.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8804.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8805.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8806.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8807.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8808.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8809.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8810.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8811.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8812.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8813.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8814.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8815.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8816.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8817.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8818.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8819.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8906.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8907.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8908.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8909.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8916.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8917.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8918.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp8919.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9000.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9001.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9002.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9003.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9004.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9005.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9006.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9007.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9008.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9009.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9016.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9017.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9018.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9019.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9100.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9101.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9102.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9103.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9104.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9105.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9106.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9107.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9108.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9109.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9116.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9117.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9118.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9119.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9206.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9207.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9208.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9209.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9216.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9217.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9218.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9219.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9306.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9307.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9308.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9309.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9316.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9317.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9318.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9319.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9406.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9407.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9408.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9409.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9416.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9417.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9418.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9419.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9506.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9507.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9508.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9509.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9516.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9517.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9518.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9519.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9606.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9607.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9608.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9609.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9616.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9617.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9618.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9619.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9706.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9707.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9708.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9709.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9716.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9717.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9718.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9719.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9806.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9807.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9808.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9809.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9816.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9817.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9818.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp9819.bmp
# End Source File
# Begin Source File

SOURCE=.\bomb.bmp
# End Source File
# Begin Source File

SOURCE=.\bomb_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\bomb_withflame.bmp
# End Source File
# Begin Source File

SOURCE=.\Bones.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_barrel_1.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_barrel_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_barrel_2.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_barrel_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_barrel_3.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_barrel_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_beach_1.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_beach_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_beach_2.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_beach_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_beach_3.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_beach_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_bones_1.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_bones_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_bones_2.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_bones_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_bones_3.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_bones_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_breakfast_1.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_breakfast_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_breakfast_2.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_breakfast_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_breakfast_3.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_breakfast_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_cards_1.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_cards_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_cards_2.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_cards_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_cards_3.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_cards_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_chess_1.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_chess_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_chess_2.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_chess_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_chess_3.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_chess_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_coolgrass_1.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_coolgrass_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_coolgrass_2.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_coolgrass_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_coolgrass_3.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_coolgrass_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_cow_1.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_cow_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_cow_2.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_cow_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_cow_3.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_cow_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_dollars_1.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_dollars_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_dollars_2.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_dollars_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_dollars_3.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_dollars_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_field_1.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_field_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_field_2.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_field_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_field_3.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_field_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_firs_1.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_firs_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_firs_2.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_firs_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_firs_3.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_firs_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_flower_1.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_flower_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_flower_2.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_flower_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_flower_3.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_flower_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_gamebones_1.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_gamebones_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_gamebones_2.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_gamebones_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_gamebones_3.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_gamebones_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_jungle_1.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_jungle_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_jungle_2.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_jungle_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_jungle_3.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_jungle_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_lehasoft_1.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_lehasoft_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_lehasoft_2.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_lehasoft_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_lehasoft_3.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_lehasoft_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_mushrom_1.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_mushrom_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_mushrom_2.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_mushrom_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_mushrom_3.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_mushrom_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_ny_1.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_ny_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_ny_2.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_ny_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_ny_3.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_ny_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_send_1.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_send_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_send_2.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_send_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_send_3.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_send_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_space_1.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_space_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_space_2.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_space_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_space_3.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_space_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_system_1.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_system_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_system_2.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_system_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_system_3.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_system_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_tech_1.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_tech_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_tech_2.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_tech_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_tech_3.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_tech_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_time_1.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_time_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_time_2.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_time_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_time_3.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_time_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_waves_1.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_waves_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_waves_2.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_waves_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_waves_3.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_waves_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_wc_1.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_wc_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_wc_2.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_wc_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_wc_3.bmp
# End Source File
# Begin Source File

SOURCE=.\brick_wc_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\broom_0.bmp
# End Source File
# Begin Source File

SOURCE=.\broom_0_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\broom_1.bmp
# End Source File
# Begin Source File

SOURCE=.\broom_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\broom_2.bmp
# End Source File
# Begin Source File

SOURCE=.\broom_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\broom_3.bmp
# End Source File
# Begin Source File

SOURCE=.\broom_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\broom_4.bmp
# End Source File
# Begin Source File

SOURCE=.\broom_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\broom_5.bmp
# End Source File
# Begin Source File

SOURCE=.\broom_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\brwall.bmp
# End Source File
# Begin Source File

SOURCE=.\button_exit_0.bmp
# End Source File
# Begin Source File

SOURCE=.\button_exit_1.bmp
# End Source File
# Begin Source File

SOURCE=.\button_pause_0.bmp
# End Source File
# Begin Source File

SOURCE=.\button_pause_1.bmp
# End Source File
# Begin Source File

SOURCE=.\castle_floor_blue_1.bmp
# End Source File
# Begin Source File

SOURCE=.\castle_floor_blue_2.bmp
# End Source File
# Begin Source File

SOURCE=.\castle_floor_blue_3.bmp
# End Source File
# Begin Source File

SOURCE=.\castle_floor_green_1.bmp
# End Source File
# Begin Source File

SOURCE=.\castle_floor_green_2.bmp
# End Source File
# Begin Source File

SOURCE=.\castle_floor_green_3.bmp
# End Source File
# Begin Source File

SOURCE=.\castle_floor_red_1.bmp
# End Source File
# Begin Source File

SOURCE=.\castle_floor_red_2.bmp
# End Source File
# Begin Source File

SOURCE=.\castle_floor_red_3.bmp
# End Source File
# Begin Source File

SOURCE=.\cfrog_0.bmp
# End Source File
# Begin Source File

SOURCE=.\cfrog_0_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\cfrog_1.bmp
# End Source File
# Begin Source File

SOURCE=.\cfrog_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\cfrog_2.bmp
# End Source File
# Begin Source File

SOURCE=.\cfrog_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\cfrog_3.bmp
# End Source File
# Begin Source File

SOURCE=.\cfrog_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\cfrog_4.bmp
# End Source File
# Begin Source File

SOURCE=.\cfrog_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\cfrog_5.bmp
# End Source File
# Begin Source File

SOURCE=.\cfrog_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\coin_0.bmp
# End Source File
# Begin Source File

SOURCE=.\coin_0_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\coin_1.bmp
# End Source File
# Begin Source File

SOURCE=.\coin_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\coin_2.bmp
# End Source File
# Begin Source File

SOURCE=.\coin_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\coin_3.bmp
# End Source File
# Begin Source File

SOURCE=.\coin_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\coin_4.bmp
# End Source File
# Begin Source File

SOURCE=.\coin_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\coin_5.bmp
# End Source File
# Begin Source File

SOURCE=.\coin_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\coin_6.bmp
# End Source File
# Begin Source File

SOURCE=.\coin_6_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\coin_7.bmp
# End Source File
# Begin Source File

SOURCE=.\coin_7_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\coin_8.bmp
# End Source File
# Begin Source File

SOURCE=.\coin_8_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\coin_9.bmp
# End Source File
# Begin Source File

SOURCE=.\coin_9_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\croc_0.bmp
# End Source File
# Begin Source File

SOURCE=.\croc_0_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\croc_1.bmp
# End Source File
# Begin Source File

SOURCE=.\croc_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\croc_2.bmp
# End Source File
# Begin Source File

SOURCE=.\croc_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\croc_3.bmp
# End Source File
# Begin Source File

SOURCE=.\croc_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\croc_4.bmp
# End Source File
# Begin Source File

SOURCE=.\croc_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\croc_5.bmp
# End Source File
# Begin Source File

SOURCE=.\croc_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_down_0.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_down_0_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_down_1.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_down_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_down_2.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_down_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_down_3.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_down_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_down_4.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_down_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_down_5.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_down_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_left_0.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_left_0_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_left_1.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_left_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_left_2.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_left_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_left_3.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_left_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_left_4.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_left_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_left_5.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_left_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_up_0.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_up_0_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_up_1.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_up_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_up_2.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_up_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_up_3.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_up_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_up_4.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_up_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_up_5.bmp
# End Source File
# Begin Source File

SOURCE=.\deamon_up_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\dm.bmp
# End Source File
# Begin Source File

SOURCE=.\dm_pushed.bmp
# End Source File
# Begin Source File

SOURCE=.\empty.bmp
# End Source File
# Begin Source File

SOURCE=.\empty2.bmp
# End Source File
# Begin Source File

SOURCE=.\empty3.bmp
# End Source File
# Begin Source File

SOURCE=.\Enter.bmp
# End Source File
# Begin Source File

SOURCE=.\exit.bmp
# End Source File
# Begin Source File

SOURCE=.\Exit_0.bmp
# End Source File
# Begin Source File

SOURCE=.\Exit_1.bmp
# End Source File
# Begin Source File

SOURCE=.\Exit_10.bmp
# End Source File
# Begin Source File

SOURCE=.\Exit_11.bmp
# End Source File
# Begin Source File

SOURCE=.\Exit_12.bmp
# End Source File
# Begin Source File

SOURCE=.\Exit_13.bmp
# End Source File
# Begin Source File

SOURCE=.\Exit_14.bmp
# End Source File
# Begin Source File

SOURCE=.\Exit_15.bmp
# End Source File
# Begin Source File

SOURCE=.\Exit_16.bmp
# End Source File
# Begin Source File

SOURCE=.\Exit_17.bmp
# End Source File
# Begin Source File

SOURCE=.\Exit_18.bmp
# End Source File
# Begin Source File

SOURCE=.\Exit_19.bmp
# End Source File
# Begin Source File

SOURCE=.\Exit_2.bmp
# End Source File
# Begin Source File

SOURCE=.\Exit_20.bmp
# End Source File
# Begin Source File

SOURCE=.\Exit_3.bmp
# End Source File
# Begin Source File

SOURCE=.\Exit_4.bmp
# End Source File
# Begin Source File

SOURCE=.\Exit_5.bmp
# End Source File
# Begin Source File

SOURCE=.\Exit_6.bmp
# End Source File
# Begin Source File

SOURCE=.\Exit_7.bmp
# End Source File
# Begin Source File

SOURCE=.\Exit_8.bmp
# End Source File
# Begin Source File

SOURCE=.\Exit_9.bmp
# End Source File
# Begin Source File

SOURCE=.\exit_pushed.bmp
# End Source File
# Begin Source File

SOURCE=.\Fire.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_0.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_0_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_1.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_2.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_3.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_4.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_5.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_right_1.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_right_10.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_right_10_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_right_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_right_2.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_right_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_right_3.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_right_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_right_4.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_right_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_right_5.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_right_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_right_6.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_right_6_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_right_7.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_right_7_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_right_8.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_right_8_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_right_9.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_right_9_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_strait_1.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_strait_10.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_strait_10_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_strait_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_strait_2.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_strait_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_strait_3.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_strait_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_strait_4.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_strait_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_strait_5.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_strait_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_strait_6.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_strait_6_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_strait_7.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_strait_7_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_strait_8.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_strait_8_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_strait_9.bmp
# End Source File
# Begin Source File

SOURCE=.\fire_strait_9_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\flame_1.bmp
# End Source File
# Begin Source File

SOURCE=.\flame_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\flame_2.bmp
# End Source File
# Begin Source File

SOURCE=.\flame_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\flame_3.bmp
# End Source File
# Begin Source File

SOURCE=.\flame_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\for_frags.bmp
# End Source File
# Begin Source File

SOURCE=.\for_surviving.bmp
# End Source File
# Begin Source File

SOURCE=.\forest_grass2.bmp
# End Source File
# Begin Source File

SOURCE=.\forest_grass_1.bmp
# End Source File
# Begin Source File

SOURCE=.\forest_grass_3.bmp
# End Source File
# Begin Source File

SOURCE=.\frog2_0.bmp
# End Source File
# Begin Source File

SOURCE=.\frog2_0_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\frog2_1.bmp
# End Source File
# Begin Source File

SOURCE=.\frog2_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\frog2_2.bmp
# End Source File
# Begin Source File

SOURCE=.\frog2_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\frog2_3.bmp
# End Source File
# Begin Source File

SOURCE=.\frog2_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\frog2_4.bmp
# End Source File
# Begin Source File

SOURCE=.\frog2_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\frog2_5.bmp
# End Source File
# Begin Source File

SOURCE=.\frog2_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\frog2_6.bmp
# End Source File
# Begin Source File

SOURCE=.\frog2_6_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\frog2_7.bmp
# End Source File
# Begin Source File

SOURCE=.\frog2_7_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\frog2_8.bmp
# End Source File
# Begin Source File

SOURCE=.\frog2_8_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\frog2_9.bmp
# End Source File
# Begin Source File

SOURCE=.\frog2_9_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\frog_0.bmp
# End Source File
# Begin Source File

SOURCE=.\frog_0_mask_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\frog_1.bmp
# End Source File
# Begin Source File

SOURCE=.\frog_1_mask_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\frog_2.bmp
# End Source File
# Begin Source File

SOURCE=.\frog_2_mask_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\frog_3.bmp
# End Source File
# Begin Source File

SOURCE=.\frog_3_mask_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\frog_4.bmp
# End Source File
# Begin Source File

SOURCE=.\frog_4_mask_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\frog_5.bmp
# End Source File
# Begin Source File

SOURCE=.\frog_5_mask_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\FuckBombs.bmp
# End Source File
# Begin Source File

SOURCE=.\grass_1.bmp
# End Source File
# Begin Source File

SOURCE=.\grass_2.bmp
# End Source File
# Begin Source File

SOURCE=.\grass_3.bmp
# End Source File
# Begin Source File

SOURCE=.\hare_red_0.bmp
# End Source File
# Begin Source File

SOURCE=.\hare_red_0_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\hare_red_1.bmp
# End Source File
# Begin Source File

SOURCE=.\hare_red_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\hare_red_2.bmp
# End Source File
# Begin Source File

SOURCE=.\hare_red_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\hare_red_3.bmp
# End Source File
# Begin Source File

SOURCE=.\hare_red_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\hare_red_4.bmp
# End Source File
# Begin Source File

SOURCE=.\hare_red_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\hare_red_5.bmp
# End Source File
# Begin Source File

SOURCE=.\hare_red_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\hare_white_0.bmp
# End Source File
# Begin Source File

SOURCE=.\hare_white_1.bmp
# End Source File
# Begin Source File

SOURCE=.\hare_white_2.bmp
# End Source File
# Begin Source File

SOURCE=.\hare_white_3.bmp
# End Source File
# Begin Source File

SOURCE=.\hare_white_4.bmp
# End Source File
# Begin Source File

SOURCE=.\hare_white_5.bmp
# End Source File
# Begin Source File

SOURCE=.\hare_yellow_0.bmp
# End Source File
# Begin Source File

SOURCE=.\hare_yellow_1.bmp
# End Source File
# Begin Source File

SOURCE=.\hare_yellow_2.bmp
# End Source File
# Begin Source File

SOURCE=.\hare_yellow_3.bmp
# End Source File
# Begin Source File

SOURCE=.\hare_yellow_4.bmp
# End Source File
# Begin Source File

SOURCE=.\hare_yellow_5.bmp
# End Source File
# Begin Source File

SOURCE=.\ice_1.bmp
# End Source File
# Begin Source File

SOURCE=.\ice_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\ice_2.bmp
# End Source File
# Begin Source File

SOURCE=.\ice_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\ice_3.bmp
# End Source File
# Begin Source File

SOURCE=.\ice_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\indicato.bmp
# End Source File
# Begin Source File

SOURCE=.\indicator_bomb.bmp
# End Source File
# Begin Source File

SOURCE=.\indicator_fire.bmp
# End Source File
# Begin Source File

SOURCE=.\indicator_level.bmp
# End Source File
# Begin Source File

SOURCE=.\indicator_time.bmp
# End Source File
# Begin Source File

SOURCE=.\indicator_usd.bmp
# End Source File
# Begin Source File

SOURCE=.\jelly_0.bmp
# End Source File
# Begin Source File

SOURCE=.\jelly_0_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\jelly_1.bmp
# End Source File
# Begin Source File

SOURCE=.\jelly_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\jelly_2.bmp
# End Source File
# Begin Source File

SOURCE=.\jelly_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\jelly_3.bmp
# End Source File
# Begin Source File

SOURCE=.\jelly_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\jelly_4.bmp
# End Source File
# Begin Source File

SOURCE=.\jelly_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\jelly_5.bmp
# End Source File
# Begin Source File

SOURCE=.\jelly_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\Life.bmp
# End Source File
# Begin Source File

SOURCE=.\logo_520x520_8b.bmp
# End Source File
# Begin Source File

SOURCE=.\number_16x24_0.bmp
# End Source File
# Begin Source File

SOURCE=.\number_16x24_0_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\number_16x24_1.bmp
# End Source File
# Begin Source File

SOURCE=.\number_16x24_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\number_16x24_2.bmp
# End Source File
# Begin Source File

SOURCE=.\number_16x24_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\number_16x24_3.bmp
# End Source File
# Begin Source File

SOURCE=.\number_16x24_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\number_16x24_4.bmp
# End Source File
# Begin Source File

SOURCE=.\number_16x24_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\number_16x24_5.bmp
# End Source File
# Begin Source File

SOURCE=.\number_16x24_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\number_16x24_6.bmp
# End Source File
# Begin Source File

SOURCE=.\number_16x24_6_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\number_16x24_7.bmp
# End Source File
# Begin Source File

SOURCE=.\number_16x24_7_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\number_16x24_8.bmp
# End Source File
# Begin Source File

SOURCE=.\number_16x24_8_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\number_16x24_9.bmp
# End Source File
# Begin Source File

SOURCE=.\number_16x24_9_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\number_16x24_minus.bmp
# End Source File
# Begin Source File

SOURCE=.\number_16x24_minus_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\onion_0.bmp
# End Source File
# Begin Source File

SOURCE=.\onion_0_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\onion_1.bmp
# End Source File
# Begin Source File

SOURCE=.\onion_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\onion_2.bmp
# End Source File
# Begin Source File

SOURCE=.\onion_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\onion_3.bmp
# End Source File
# Begin Source File

SOURCE=.\onion_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\onion_4.bmp
# End Source File
# Begin Source File

SOURCE=.\onion_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\onion_5.bmp
# End Source File
# Begin Source File

SOURCE=.\onion_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\orange_0.bmp
# End Source File
# Begin Source File

SOURCE=.\orange_0_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\orange_1.bmp
# End Source File
# Begin Source File

SOURCE=.\orange_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\orange_2.bmp
# End Source File
# Begin Source File

SOURCE=.\orange_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\orange_3.bmp
# End Source File
# Begin Source File

SOURCE=.\orange_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\orange_4.bmp
# End Source File
# Begin Source File

SOURCE=.\orange_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\orange_5.bmp
# End Source File
# Begin Source File

SOURCE=.\orange_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\orange_6.bmp
# End Source File
# Begin Source File

SOURCE=.\orange_6_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\orange_7.bmp
# End Source File
# Begin Source File

SOURCE=.\orange_7_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\orange_8.bmp
# End Source File
# Begin Source File

SOURCE=.\orange_8_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\orange_9.bmp
# End Source File
# Begin Source File

SOURCE=.\orange_9_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\pause.bmp
# End Source File
# Begin Source File

SOURCE=.\peases_1.bmp
# End Source File
# Begin Source File

SOURCE=.\peases_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\peases_2.bmp
# End Source File
# Begin Source File

SOURCE=.\peases_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\peases_3.bmp
# End Source File
# Begin Source File

SOURCE=.\peases_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\peases_4.bmp
# End Source File
# Begin Source File

SOURCE=.\peases_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\peases_5.bmp
# End Source File
# Begin Source File

SOURCE=.\peases_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\peases_6.bmp
# End Source File
# Begin Source File

SOURCE=.\peases_6_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\pig_0.bmp
# End Source File
# Begin Source File

SOURCE=.\pig_0_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\pig_1.bmp
# End Source File
# Begin Source File

SOURCE=.\pig_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\pig_2.bmp
# End Source File
# Begin Source File

SOURCE=.\pig_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\pig_3.bmp
# End Source File
# Begin Source File

SOURCE=.\pig_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\pig_4.bmp
# End Source File
# Begin Source File

SOURCE=.\pig_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\pig_5.bmp
# End Source File
# Begin Source File

SOURCE=.\pig_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\plam_0.bmp
# End Source File
# Begin Source File

SOURCE=.\plam_0_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\plam_1.bmp
# End Source File
# Begin Source File

SOURCE=.\plam_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\plam_2.bmp
# End Source File
# Begin Source File

SOURCE=.\plam_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\plam_3.bmp
# End Source File
# Begin Source File

SOURCE=.\plam_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\plam_4.bmp
# End Source File
# Begin Source File

SOURCE=.\plam_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\plam_5.bmp
# End Source File
# Begin Source File

SOURCE=.\plam_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\plant_1.bmp
# End Source File
# Begin Source File

SOURCE=.\plant_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\plant_2.bmp
# End Source File
# Begin Source File

SOURCE=.\plant_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\plant_3.bmp
# End Source File
# Begin Source File

SOURCE=.\plant_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\play.bmp
# End Source File
# Begin Source File

SOURCE=.\player2_back_1.bmp
# End Source File
# Begin Source File

SOURCE=.\player2_back_2.bmp
# End Source File
# Begin Source File

SOURCE=.\player2_back_3.bmp
# End Source File
# Begin Source File

SOURCE=.\player2_back_4.bmp
# End Source File
# Begin Source File

SOURCE=.\player2_back_5.bmp
# End Source File
# Begin Source File

SOURCE=.\player2_back_6.bmp
# End Source File
# Begin Source File

SOURCE=.\player2_back_7.bmp
# End Source File
# Begin Source File

SOURCE=.\player2_back_8.bmp
# End Source File
# Begin Source File

SOURCE=.\player2_front_1.bmp
# End Source File
# Begin Source File

SOURCE=.\player2_front_2.bmp
# End Source File
# Begin Source File

SOURCE=.\player2_front_3.bmp
# End Source File
# Begin Source File

SOURCE=.\player2_front_4.bmp
# End Source File
# Begin Source File

SOURCE=.\player2_front_5.bmp
# End Source File
# Begin Source File

SOURCE=.\player2_front_6.bmp
# End Source File
# Begin Source File

SOURCE=.\player2_front_7.bmp
# End Source File
# Begin Source File

SOURCE=.\player2_front_8.bmp
# End Source File
# Begin Source File

SOURCE=.\player2_right_1.bmp
# End Source File
# Begin Source File

SOURCE=.\player2_right_2.bmp
# End Source File
# Begin Source File

SOURCE=.\player2_right_3.bmp
# End Source File
# Begin Source File

SOURCE=.\player2_right_4.bmp
# End Source File
# Begin Source File

SOURCE=.\player2_right_5.bmp
# End Source File
# Begin Source File

SOURCE=.\player2_right_6.bmp
# End Source File
# Begin Source File

SOURCE=.\player2_right_7.bmp
# End Source File
# Begin Source File

SOURCE=.\player2_right_8.bmp
# End Source File
# Begin Source File

SOURCE=.\player3_back_1.bmp
# End Source File
# Begin Source File

SOURCE=.\player3_back_2.bmp
# End Source File
# Begin Source File

SOURCE=.\player3_back_3.bmp
# End Source File
# Begin Source File

SOURCE=.\player3_back_4.bmp
# End Source File
# Begin Source File

SOURCE=.\player3_back_5.bmp
# End Source File
# Begin Source File

SOURCE=.\player3_back_6.bmp
# End Source File
# Begin Source File

SOURCE=.\player3_back_7.bmp
# End Source File
# Begin Source File

SOURCE=.\player3_back_8.bmp
# End Source File
# Begin Source File

SOURCE=.\player3_front_1.bmp
# End Source File
# Begin Source File

SOURCE=.\player3_front_2.bmp
# End Source File
# Begin Source File

SOURCE=.\player3_front_3.bmp
# End Source File
# Begin Source File

SOURCE=.\player3_front_4.bmp
# End Source File
# Begin Source File

SOURCE=.\player3_front_5.bmp
# End Source File
# Begin Source File

SOURCE=.\player3_front_6.bmp
# End Source File
# Begin Source File

SOURCE=.\player3_front_7.bmp
# End Source File
# Begin Source File

SOURCE=.\player3_front_8.bmp
# End Source File
# Begin Source File

SOURCE=.\player3_right_1.bmp
# End Source File
# Begin Source File

SOURCE=.\player3_right_2.bmp
# End Source File
# Begin Source File

SOURCE=.\player3_right_3.bmp
# End Source File
# Begin Source File

SOURCE=.\player3_right_4.bmp
# End Source File
# Begin Source File

SOURCE=.\player3_right_5.bmp
# End Source File
# Begin Source File

SOURCE=.\player3_right_6.bmp
# End Source File
# Begin Source File

SOURCE=.\player3_right_7.bmp
# End Source File
# Begin Source File

SOURCE=.\player3_right_8.bmp
# End Source File
# Begin Source File

SOURCE=.\player4_back_1.bmp
# End Source File
# Begin Source File

SOURCE=.\player4_back_2.bmp
# End Source File
# Begin Source File

SOURCE=.\player4_back_3.bmp
# End Source File
# Begin Source File

SOURCE=.\player4_back_4.bmp
# End Source File
# Begin Source File

SOURCE=.\player4_back_5.bmp
# End Source File
# Begin Source File

SOURCE=.\player4_back_6.bmp
# End Source File
# Begin Source File

SOURCE=.\player4_back_7.bmp
# End Source File
# Begin Source File

SOURCE=.\player4_back_8.bmp
# End Source File
# Begin Source File

SOURCE=.\player4_front_1.bmp
# End Source File
# Begin Source File

SOURCE=.\player4_front_2.bmp
# End Source File
# Begin Source File

SOURCE=.\player4_front_3.bmp
# End Source File
# Begin Source File

SOURCE=.\player4_front_4.bmp
# End Source File
# Begin Source File

SOURCE=.\player4_front_5.bmp
# End Source File
# Begin Source File

SOURCE=.\player4_front_6.bmp
# End Source File
# Begin Source File

SOURCE=.\player4_front_7.bmp
# End Source File
# Begin Source File

SOURCE=.\player4_front_8.bmp
# End Source File
# Begin Source File

SOURCE=.\player4_right_1.bmp
# End Source File
# Begin Source File

SOURCE=.\player4_right_2.bmp
# End Source File
# Begin Source File

SOURCE=.\player4_right_3.bmp
# End Source File
# Begin Source File

SOURCE=.\player4_right_4.bmp
# End Source File
# Begin Source File

SOURCE=.\player4_right_5.bmp
# End Source File
# Begin Source File

SOURCE=.\player4_right_6.bmp
# End Source File
# Begin Source File

SOURCE=.\player4_right_7.bmp
# End Source File
# Begin Source File

SOURCE=.\player4_right_8.bmp
# End Source File
# Begin Source File

SOURCE=.\player_back_1.bmp
# End Source File
# Begin Source File

SOURCE=.\player_back_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_back_2.bmp
# End Source File
# Begin Source File

SOURCE=.\player_back_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_back_3.bmp
# End Source File
# Begin Source File

SOURCE=.\player_back_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_back_4.bmp
# End Source File
# Begin Source File

SOURCE=.\player_back_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_back_5.bmp
# End Source File
# Begin Source File

SOURCE=.\player_back_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_back_6.bmp
# End Source File
# Begin Source File

SOURCE=.\player_back_6_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_back_7.bmp
# End Source File
# Begin Source File

SOURCE=.\player_back_7_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_back_8.bmp
# End Source File
# Begin Source File

SOURCE=.\player_back_8_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_back_9.bmp
# End Source File
# Begin Source File

SOURCE=.\player_back_9_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_front_1.bmp
# End Source File
# Begin Source File

SOURCE=.\player_front_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_front_2.bmp
# End Source File
# Begin Source File

SOURCE=.\player_front_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_front_3.bmp
# End Source File
# Begin Source File

SOURCE=.\player_front_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_front_4.bmp
# End Source File
# Begin Source File

SOURCE=.\player_front_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_front_5.bmp
# End Source File
# Begin Source File

SOURCE=.\player_front_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_front_6.bmp
# End Source File
# Begin Source File

SOURCE=.\player_front_6_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_front_7.bmp
# End Source File
# Begin Source File

SOURCE=.\player_front_7_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_front_8.bmp
# End Source File
# Begin Source File

SOURCE=.\player_front_8_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_front_9.bmp
# End Source File
# Begin Source File

SOURCE=.\player_front_9_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_head.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_1.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_10.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_10_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_11.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_11_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_12.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_12_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_13.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_13_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_14.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_14_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_15.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_15_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_2.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_3.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_4.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_5.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_6.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_6_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_7.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_7_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_8.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_8_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_9.bmp
# End Source File
# Begin Source File

SOURCE=.\player_quits_9_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_right_1.bmp
# End Source File
# Begin Source File

SOURCE=.\player_right_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_right_2.bmp
# End Source File
# Begin Source File

SOURCE=.\player_right_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_right_3.bmp
# End Source File
# Begin Source File

SOURCE=.\player_right_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_right_4.bmp
# End Source File
# Begin Source File

SOURCE=.\player_right_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_right_5.bmp
# End Source File
# Begin Source File

SOURCE=.\player_right_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_right_6.bmp
# End Source File
# Begin Source File

SOURCE=.\player_right_6_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_right_7.bmp
# End Source File
# Begin Source File

SOURCE=.\player_right_7_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_right_8.bmp
# End Source File
# Begin Source File

SOURCE=.\player_right_8_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\player_right_9.bmp
# End Source File
# Begin Source File

SOURCE=.\player_right_9_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\raspbarry_0.bmp
# End Source File
# Begin Source File

SOURCE=.\raspbarry_0_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\raspbarry_1.bmp
# End Source File
# Begin Source File

SOURCE=.\raspbarry_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\raspbarry_2.bmp
# End Source File
# Begin Source File

SOURCE=.\raspbarry_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\raspbarry_3.bmp
# End Source File
# Begin Source File

SOURCE=.\raspbarry_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\raspbarry_4.bmp
# End Source File
# Begin Source File

SOURCE=.\raspbarry_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\raspbarry_5.bmp
# End Source File
# Begin Source File

SOURCE=.\raspbarry_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\shit_1.bmp
# End Source File
# Begin Source File

SOURCE=.\shit_2.bmp
# End Source File
# Begin Source File

SOURCE=.\shit_3.bmp
# End Source File
# Begin Source File

SOURCE=.\single.bmp
# End Source File
# Begin Source File

SOURCE=.\single_pushed.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_down_blue_0.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_down_blue_1.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_down_blue_2.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_down_blue_3.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_down_blue_4.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_down_blue_5.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_down_red_0.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_down_red_1.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_down_red_2.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_down_red_3.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_down_red_4.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_down_red_5.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_down_yellow_0.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_down_yellow_0_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_down_yellow_1.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_down_yellow_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_down_yellow_2.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_down_yellow_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_down_yellow_3.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_down_yellow_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_down_yellow_4.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_down_yellow_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_down_yellow_5.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_down_yellow_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_right_blue_0.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_right_blue_1.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_right_blue_2.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_right_blue_3.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_right_blue_4.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_right_blue_5.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_right_red_0.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_right_red_1.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_right_red_2.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_right_red_3.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_right_red_4.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_right_red_5.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_right_yellow_0.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_right_yellow_0_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_right_yellow_1.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_right_yellow_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_right_yellow_2.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_right_yellow_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_right_yellow_3.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_right_yellow_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_right_yellow_4.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_right_yellow_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_right_yellow_5.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_body_right_yellow_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_down_blue_0.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_down_blue_1.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_down_blue_2.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_down_blue_3.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_down_blue_4.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_down_blue_5.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_down_red_0.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_down_red_1.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_down_red_2.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_down_red_3.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_down_red_4.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_down_red_5.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_down_yellow_0.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_down_yellow_0_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_down_yellow_1.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_down_yellow_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_down_yellow_2.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_down_yellow_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_down_yellow_3.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_down_yellow_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_down_yellow_4.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_down_yellow_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_down_yellow_5.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_down_yellow_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_right_blue_0.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_right_blue_1.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_right_blue_2.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_right_blue_3.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_right_blue_4.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_right_blue_5.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_right_red_0.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_right_red_1.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_right_red_2.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_right_red_3.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_right_red_4.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_right_red_5.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_right_yellow_0.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_right_yellow_0_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_right_yellow_1.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_right_yellow_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_right_yellow_2.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_right_yellow_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_right_yellow_3.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_right_yellow_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_right_yellow_4.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_right_yellow_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_right_yellow_5.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_head_right_yellow_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_down_blue_0.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_down_blue_1.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_down_blue_2.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_down_blue_3.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_down_blue_4.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_down_blue_5.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_down_red_0.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_down_red_1.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_down_red_2.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_down_red_3.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_down_red_4.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_down_red_5.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_down_yellow_0.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_down_yellow_0_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_down_yellow_1.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_down_yellow_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_down_yellow_2.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_down_yellow_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_down_yellow_3.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_down_yellow_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_down_yellow_4.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_down_yellow_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_down_yellow_5.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_down_yellow_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_right_blue_0.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_right_blue_1.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_right_blue_2.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_right_blue_3.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_right_blue_4.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_right_blue_5.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_right_red_0.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_right_red_1.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_right_red_2.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_right_red_3.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_right_red_4.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_right_red_5.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_right_yellow_0.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_right_yellow_0_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_right_yellow_1.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_right_yellow_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_right_yellow_2.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_right_yellow_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_right_yellow_3.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_right_yellow_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_right_yellow_4.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_right_yellow_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_right_yellow_5.bmp
# End Source File
# Begin Source File

SOURCE=.\snake_tail_right_yellow_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\snow_1.bmp
# End Source File
# Begin Source File

SOURCE=.\snow_2.bmp
# End Source File
# Begin Source File

SOURCE=.\snow_3.bmp
# End Source File
# Begin Source File

SOURCE=.\Speed.bmp
# End Source File
# Begin Source File

SOURCE=.\spin_0.bmp
# End Source File
# Begin Source File

SOURCE=.\spin_0_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\spin_1.bmp
# End Source File
# Begin Source File

SOURCE=.\spin_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\spin_2.bmp
# End Source File
# Begin Source File

SOURCE=.\spin_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\spin_3.bmp
# End Source File
# Begin Source File

SOURCE=.\spin_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\spin_4.bmp
# End Source File
# Begin Source File

SOURCE=.\spin_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\spin_5.bmp
# End Source File
# Begin Source File

SOURCE=.\spin_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\spin_6.bmp
# End Source File
# Begin Source File

SOURCE=.\spin_6_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\spin_7.bmp
# End Source File
# Begin Source File

SOURCE=.\spin_7_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\spin_8.bmp
# End Source File
# Begin Source File

SOURCE=.\spin_8_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\spin_9.bmp
# End Source File
# Begin Source File

SOURCE=.\spin_9_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\stone_1.bmp
# End Source File
# Begin Source File

SOURCE=.\stone_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\stone_2.bmp
# End Source File
# Begin Source File

SOURCE=.\stone_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\stone_3.bmp
# End Source File
# Begin Source File

SOURCE=.\stone_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\tlwall.bmp
# End Source File
# Begin Source File

SOURCE=.\tree_1.bmp
# End Source File
# Begin Source File

SOURCE=.\tree_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\tree_2.bmp
# End Source File
# Begin Source File

SOURCE=.\tree_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\tree_3.bmp
# End Source File
# Begin Source File

SOURCE=.\tree_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\USD.bmp
# End Source File
# Begin Source File

SOURCE=.\violet_0.bmp
# End Source File
# Begin Source File

SOURCE=.\violet_0_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\violet_1.bmp
# End Source File
# Begin Source File

SOURCE=.\violet_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\violet_2.bmp
# End Source File
# Begin Source File

SOURCE=.\violet_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\violet_3.bmp
# End Source File
# Begin Source File

SOURCE=.\violet_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\violet_4.bmp
# End Source File
# Begin Source File

SOURCE=.\violet_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\violet_5.bmp
# End Source File
# Begin Source File

SOURCE=.\violet_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\vwall.bmp
# End Source File
# Begin Source File

SOURCE=".\wall_border_right-top.bmp"
# End Source File
# Begin Source File

SOURCE=.\wall_border_top.bmp
# End Source File
# Begin Source File

SOURCE=.\wall_brick_red.bmp
# End Source File
# Begin Source File

SOURCE=.\wall_brick_red_2.bmp
# End Source File
# Begin Source File

SOURCE=.\wall_brick_red_3.bmp
# End Source File
# Begin Source File

SOURCE=.\wall_hard.bmp
# End Source File
# Begin Source File

SOURCE=.\water0.bmp
# End Source File
# Begin Source File

SOURCE=.\water1.bmp
# End Source File
# Begin Source File

SOURCE=.\water2.bmp
# End Source File
# Begin Source File

SOURCE=.\water3.bmp
# End Source File
# Begin Source File

SOURCE=.\water4.bmp
# End Source File
# Begin Source File

SOURCE=.\water5.bmp
# End Source File
# Begin Source File

SOURCE=.\water6.bmp
# End Source File
# Begin Source File

SOURCE=.\water7.bmp
# End Source File
# Begin Source File

SOURCE=.\water8.bmp
# End Source File
# Begin Source File

SOURCE=.\water9.bmp
# End Source File
# Begin Source File

SOURCE=.\water_0.bmp
# End Source File
# Begin Source File

SOURCE=.\water_1.bmp
# End Source File
# Begin Source File

SOURCE=.\water_2.bmp
# End Source File
# Begin Source File

SOURCE=.\water_3.bmp
# End Source File
# Begin Source File

SOURCE=.\water_4.bmp
# End Source File
# Begin Source File

SOURCE=.\water_5.bmp
# End Source File
# Begin Source File

SOURCE=.\water_6.bmp
# End Source File
# Begin Source File

SOURCE=.\water_7.bmp
# End Source File
# Begin Source File

SOURCE=.\water_8.bmp
# End Source File
# Begin Source File

SOURCE=.\water_9.bmp
# End Source File
# Begin Source File

SOURCE=.\Wings.bmp
# End Source File
# Begin Source File

SOURCE=.\wood_1.bmp
# End Source File
# Begin Source File

SOURCE=.\wood_2.bmp
# End Source File
# Begin Source File

SOURCE=.\wood_3.bmp
# End Source File
# Begin Source File

SOURCE=.\wood_floor_1.bmp
# End Source File
# Begin Source File

SOURCE=.\wood_floor_2.bmp
# End Source File
# Begin Source File

SOURCE=.\wood_floor_3.bmp
# End Source File
# End Group
# End Target
# End Project
