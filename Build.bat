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

:: Set variable
set rootPath=%cd%
set buildToken=%1
set buildTaget=%2

:: Check variable
:: Check build token
if NOT "%buildToken%" == "release" (
    if NOT "%buildToken%" == "debug" (
        call :color c "Error - Parameter one must be release or debug."
        call :exit
    )
)
:: Check build taget
if NOT "%buildTaget%" == "x86" (
    if NOT "%buildTaget%" == "x64" (
        call :color c "Error - Parameter two must be x86 or x64."
    )
)

:: Check directories
if exist %rootPath%\Build (
    rd /s /q %rootPath%\Build
)
if exist %rootPath%\Bin (
    rd /s /q %rootPath%\Bin
)

:: Create directories
md %rootPath%\Build
md %rootPath%\Bin

:: Check cmake support
if exist cmake.exe (
    call :color c "Error - Can't find CMake. Please confirm that you had installed CMake and add the directory into Path environment variable."
    call :exit
)

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

:: Build
cd /D %rootPath%\Build
call vcvarsall.bat %buildTaget%
cmake -G"NMake Makefiles" -DCMAKE_BUILD_TYPE=%buildToken% -DEXECUTABLE_OUTPUT_PATH="%rootPath%\Bin" -DRF_ARCH=%buildTaget% ..\
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