#include <stdio.h>
#include <locale.h>
#include <windows.h>

#include "main.h"
#include "login.h"
#include "menu.h"
#include "splash.h"

int main(void) {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "Portuguese_Brasil.1252");
    SPL_ShowSplashScreen();
    LOGIN_ShowPanel();
    MNU_ShowMenu();
    return 0;
}

void MAIN_Exit() {
    printf("%s", "Saindo...");
    exit(1);
}