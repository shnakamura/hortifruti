@echo off

if not exist ".\bin" (
    mkdir ".\bin"
)

gcc -I .\include .\src\main.c .\src\splash.c .\src\login.c .\src\menu.c .\src\database.c -o .\bin\program.exe