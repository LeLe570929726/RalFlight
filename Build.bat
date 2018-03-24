:: ----------------------------------------------------------------------------------------------------
:: Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
:: 
:: @Project: RalFlight
:: @License: Licensed under GNU General Public License v3.
:: @Description: A free and open-source flight simulator.
::
:: @Create: 2018/3/23 by LeLe570929726
:: ----------------------------------------------------------------------------------------------------

:: Close echo
@echo off

:: Set title and color
title RalFlight Build

:: Create directories
md %cd%\Build\x86
md %cd%\Build\x64

:: Set root path
set rootPath=%cd%

:: Import Qt's environment
if exist qtenv2.bat (
    call :color c "Error - Can't find qtenv2.bat. Please confirm that you had installed Qt and add the directory into Path environment variable."
    call :exit
)
call qtenv2.bat

:: Check MSVC's environment
if exist vcvarsall.bat (
    call :color c "Error - Can't find vcvarsall.bat. Please confirm that you had installed Visual Studio and add the directory into Path environment variable."
    call :exit
)

:: Build version of x86
cd /D %rootPath%\Build\x86
call vcvarsall.bat x86
qmake -makefile "CONFIG+=release" %rootPath%\RalFlight.pro
nmake

:: Exit
call :color a "Build successfully."
call :exit

:: Set line color
:color
echo. >%2&findstr /a:%1 . %2*&del %2

:: Exit
:exit
pause
exit