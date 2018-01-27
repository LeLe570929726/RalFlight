:: ----------------------------------------------------------------------------------------------------
:: Copyright (c) 2016 - 2018 LeLe570929726. All rights reserved.
:: 
:: @Project: RalFlight
:: @License: Licensed under GNU General Public License v3.
:: @Description: A free and open-source flight simulator.
::
:: @Craete: 2017/12/24 by LeLe570929726
:: ----------------------------------------------------------------------------------------------------

:: Close echo
@echo off

:: Create directory
md %cd%\Build\x86
md %cd%\Build\x64

:: Use vcvarsall.bat x86
call vcvarsall.bat x86

:: Config Build32
cd %cd%\Build\x86
cmake -G"NMake Makefiles" -DCMAKE_BUILD_TYPE=Release -DRALFLIGHT_BUILD=ON -DEXECUTABLE_OUTPUT_PATH="%cd%\..\..\Bin\x86" -DLIBRARY_OUTPUT_PATH="%cd%\..\..\Bin\x86" ..\..\

:: Build32
nmake

:: Use vcvarsall.bat x64
call vcvarsall.bat x64

:: Config Build64
cd %cd%\..\x64
cmake -G"NMake Makefiles" -DCMAKE_BUILD_TYPE=Release -DRALFLIGHT_BUILD=ON -DEXECUTABLE_OUTPUT_PATH="%cd%\..\..\Bin\x64" -DLIBRARY_OUTPUT_PATH="%cd%\..\..\Bin\x64" ..\..\

:: Build64
nmake

:: Set status
cmake -G"NMake Makefiles" -DCMAKE_BUILD_TYPE=Release -DRALFLIGHT_BUILD=OFF -DEXECUTABLE_OUTPUT_PATH="%cd%\..\..\Bin\x64" -DLIBRARY_OUTPUT_PATH="%cd%\..\..\Bin\x64" ..\..\