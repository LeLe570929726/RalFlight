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

:: Set title
title RalFlight Build

:: Set variable
set rootPath=%cd%
set buildToken=%1
set buildTarget=%2

:: Check variable
:: Check build token
if NOT "%buildToken%" == "release" (
    if NOT "%buildToken%" == "debug" (
        call :color c "Error - Parameter one must be 'release' or 'debug'."
        call :exit
    )
)
:: Check build taget
if NOT "%buildTarget%" == "x86" (
    if NOT "%buildTarget%" == "x64" (
        call :color c "Error - Parameter two must be 'x86' or 'x64'."
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
set cmakeExist=0
cmake --version | find "cmake version" && set cmakeExist=1
if %cmakeExist% equ 0 (
    call :color c "Error - Can't find CMake. Please confirm that you had installed CMake and add the directory into Path environment variable."
    call :exit
)

:: Check MSVC's environment
set vcExist=0
vcvarsall.bat | find "ERROR:vcvarsall.bat" && set vcExist=1
if %vcExist% equ 0 (
    call :color c "Error - Can't find vcvarsall.bat. Please confirm that you had installed Visual Studio and add the directory into Path environment variable."
    call :exit
)

:: Build
cd /D %rootPath%\Build
call vcvarsall.bat %buildTarget%
cmake -G"NMake Makefiles" -DCMAKE_BUILD_TYPE=%buildToken% -DEXECUTABLE_OUTPUT_PATH="%rootPath%\Bin" -DCMAKE_GENERATOR_PLATFORM=%buildTarget% ..\
:: Check makefile
if not exist Makefile (
    call :color c "Error - CMake config failed, please check log of CMake."
    call :exit
)
nmake

:: Exit
call :color a "Build successfully."
call :exit

:: Set line color
:color
echo. >%2&findstr /a:%1 . %2*&del %2

:: Exit
:exit
exit