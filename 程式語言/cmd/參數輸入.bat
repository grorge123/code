@echo off
set /a varr=30+30  
::/a參數可以讓varr做運算
echo %varr%
set /p var=PleaseEnterVar:
::/p可以讓var做輸入
echo %var%
pause