echo off

rem ---------------------------- delete object files----------------------------
rem cmd /c "del %1\datetime.o"
rem cmd /c "del %1\xxxxxxxx.o"
rem cmd /c "del %1\yyyyyyyy.o"

rem ---------------------------- touch files -----------------------------------

rem touch file -- does not works
rem cmd /c "copy /b %1\datetime.c+,,"

rem ---------------------------- touch files -----------------------------------

powershell.exe -WindowStyle Hidden (Get-ChildItem -recurse -path %1 datetime.c).LastWriteTime = Get-Date"

echo on
