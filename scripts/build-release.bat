@echo off

if not exist ".\bin" (
    mkdir ".\bin"
)

gcc -I .\include .\src\main.c .\src\database.c .\src\menu.c .\src\splash.c .\src\auth.c -g -Wall -O2
