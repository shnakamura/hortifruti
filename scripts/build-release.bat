@echo off

if not exist ".\bin" (
    mkdir ".\bin"
)

gcc -I .\include -O2 .\src\main.c .\src\database.c .\src\menu.c -o .\bin\program.exe
