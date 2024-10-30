#include <stdlib.h>
#include <windows.h>

#include "database.h"
#include "splash.h"
#include "auth.h"
#include "menu.h"

int main(void) {    
    SetConsoleOutputCP(CP_UTF8);

    SPLASH_ShowSplashScreen();
    AUTH_ShowPanel();

    DATABASE_CreateFile();

    char username[USER_MAX_USERNAME_LENGTH];
    char password[USER_MAX_PASSWORD_LENGTH];

    strncpy(username, "admin", USER_MAX_USERNAME_LENGTH);
    strncpy(password, "admin", USER_MAX_PASSWORD_LENGTH);

    DATABASE_WriteUser(username, password, true);

    MENU_Show();

    return EXIT_SUCCESS;
}