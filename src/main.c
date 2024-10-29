#include "main.h"

#include <stdio.h>
#include <locale.h>
#include <windows.h>

#include "login.h"
#include "menu.h"
#include "splash.h"

int main(void) {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "Portuguese_Brasil.1252");

    MAIN_Initialize();

    return EXIT_SUCCESS;
}

void MAIN_Initialize() {
    SPLASH_ShowSplashScreen();
    LOGIN_ShowPanel();
    MNU_ShowMenu();
}

void MAIN_Exit() {
    printf("%s", "Saindo do programa...");
    exit(EXIT_SUCCESS);
}
