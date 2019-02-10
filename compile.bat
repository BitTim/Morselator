@echo off
echo Creating icon
windres icon.rc -O coff -o icon.res
echo Icon created!
echo .
echo Compiling main.cpp
g++ main.cpp icon.res -o main.exe
echo Compiled to main.exe!
pause
