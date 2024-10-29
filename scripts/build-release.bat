@echo off

if not exist ".\bin" (
    mkdir ".\bin"
)

gcc -I .\include -O2 .\src\main.c .\src\splash.c .\src\login.c .\src\menu.c .\src\database.c -o .\bin\program.exe