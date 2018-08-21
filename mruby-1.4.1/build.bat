echo off

set DIR=%~dp0
set PATH=%PATH%;%DIR%\..\tools\bin

rem call "%VS140COMNTOOLS%..\..\VC\vcvarsall.bat" x86
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" x86

cd /d %DIR%

echo on

ruby -Eutf-8 ./minirake %1
