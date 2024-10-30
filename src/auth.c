#include "auth.h"

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#include "database.h"

int AUTH_AuthenticateUser(char* username, char* password) {
    FILE* file = fopen(DATABASE_FILE_PATH, "rb+");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);

    int count = ftell(file) / sizeof(User);

    for (int i = 0; i < count; i++) {
        User* temp = DATABASE_GetUser(i);

        if (temp != NULL && strcmp(temp->name, username) == EXIT_SUCCESS && strcmp(temp->password, password) == EXIT_SUCCESS) {
            free(temp); 

            admin = temp->admin;

            return EXIT_SUCCESS;
        }

        free(temp); 
    }

    return EXIT_FAILURE;
}

void AUTH_ShowPanel() {
    char username[USERNAME_MAX_LENGTH];
    char password[PASSWORD_MAX_LENGTH];

    int attempts = 0; 

    printf("██╗      ██████╗  ██████╗ ██╗███╗   ██╗\n");
    printf("██║     ██╔═══██╗██╔════╝ ██║████╗  ██║\n");
    printf("██║     ██║   ██║██║  ███╗██║██╔██╗ ██║\n");
    printf("██║     ██║   ██║██║   ██║██║██║╚██╗██║\n");
    printf("███████╗╚██████╔╝╚██████╔╝██║██║ ╚████║\n");
    printf("╚══════╝ ╚═════╝  ╚═════╝ ╚═╝╚═╝  ╚═══╝\n");

    while (attempts < PASSWORD_MAX_ATTEMPTS) {
        printf("Nome de usuário:"); 
        scanf("%s", username);

        printf("Senha de usuário:"); 
        scanf("%s", password);
        
        if (AUTH_AuthenticateUser(username, password) == EXIT_SUCCESS) {
            printf("Login realizado com sucesso!\n\n");
            system("cls"); 
            return;
        } else {
            attempts++; 

            printf("Usuário ou senha incorretos, tente novamente. %d tentativas restantes.\n", PASSWORD_MAX_ATTEMPTS - attempts);
        }
    }

    printf("Número máximo de tentativas de login alcançado. O programa está sendo fechado.\n");
    Sleep(3000);
    exit(EXIT_FAILURE);
}