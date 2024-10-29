#include "login.h"

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

int LOGIN_AuthenticateUser(char* username, char* password) {
    if (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0) {
        return 1;
    }

    return 0; 
}

void LOGIN_ShowPanel() {
    char username[USERNAME_MAX_LENGTH];
    char password[PASSWORD_MAX_LENGTH];

    int attempts = 0; 

    printf("██╗      ██████╗  ██████╗ ██╗███╗   ██╗ \n");
    printf("██║     ██╔═══██╗██╔════╝ ██║████╗  ██║ \n");
    printf("██║     ██║   ██║██║  ███╗██║██╔██╗ ██║\n");
    printf("██║     ██║   ██║██║   ██║██║██║╚██╗██║\n");
    printf("███████╗╚██████╔╝╚██████╔╝██║██║ ╚████║\n");
    printf("╚══════╝ ╚═════╝  ╚═════╝ ╚═╝╚═╝  ╚═══╝\n");

    while (attempts < PASSWORD_MAX_ATTEMPTS) {
        printf("Nome de usuário: "); 
        fgets(username, sizeof(username), stdin);

        username[strcspn(username, "\n")] = 0;

        printf("Senha de usuário: ");

        int i = 0;
        char ch;

        while (1) {
            ch = getch(); 

            if (ch == '\r') { 
                password[i] = '\0'; 
                printf("\n");
                break; 
            } else if (ch == 8) {
                if (i > 0) { 
                    i--;
                    printf("\b \b");
                }
            } else if (i < PASSWORD_MAX_LENGTH - 1) {
                password[i] = ch; 
                printf("*"); 
                i++;
            }
        }
        
        if (LOGIN_AuthenticateUser(username, password)) {
            printf("Login realizado com sucesso!\n\n");
            system("cls"); 
            return;
        } else {
            printf("Por favor, tente novamente. Usuário ou senha incorreto.\n");
            attempts++; 
        }
    }

    printf("Número máximo de tentativas de login alcançado. O programa está sendo fechado.\n");
    exit(0);
}
