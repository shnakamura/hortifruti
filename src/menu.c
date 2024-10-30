#include "menu.h"

#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "user.h"
#include "database.h"

void MENU_Show() {
    int choice;

    do { 
        printf("███╗   ███╗███████╗███╗   ██╗██╗   ██╗ \n");
        printf("████╗ ████║██╔════╝████╗  ██║██║   ██║ \n");
        printf("██╔████╔██║█████╗  ██╔██╗ ██║██║   ██║ \n");
        printf("██║╚██╔╝██║██╔══╝  ██║╚██╗██║██║   ██║ \n");
        printf("██║ ╚═╝ ██║███████╗██║ ╚████║╚██████╔╝ \n");
        printf("╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝ ╚═════╝  \n");

        printf("1. Adicione um usuário\n"); 
        printf("2. Remova um usuário\n"); 
        printf("3. Listar usuários\n"); 
        printf("4. Sair do Programa\n");
        printf("Escolha uma opção e pressione enter: ");

        if (scanf("%d", &choice) != 1){
            printf("Entrada invalida. Por favor, insira um número.\n");

            while (getchar() !='\n');

            system("cls");
        }

        system("cls"); 

        switch (choice) {
            case 1:
                MENU_AddUser();
                break;
            case 2:
                MENU_RemoveUser();
                getch();
                break;
            case 3:
                MENU_ListUsers();
                getch();
                break;
            case 4:
                exit(EXIT_SUCCESS);
                break;
            default:
                printf("Tente novamente, a opção escolhida é invalida.\n"); 
                break;
        }

        printf("\n");
        system("cls");
    } while (choice != 4);
}

void MENU_AddUser() {
    char username[USER_MAX_USERNAME_LENGTH];

    printf("Digite o nome do novo usuário:");
    scanf("%s", username);

    char password[USER_MAX_PASSWORD_LENGTH];

    printf("Digite a senha do novo usuário:");
    scanf("%s", password);

    if (DATABASE_WriteUser(username, password, false) == EXIT_SUCCESS) {
        printf("Novo usuário registrado com sucesso!");
    }
    else {
        printf("Erro ao criar novo usuário.");
    }
}

void MENU_RemoveUser() {
    int id = 0;

    printf("Digite o id do usuário para remover:");
    scanf("%d", &id);

    if (DATABASE_RemoveUser(id) == EXIT_SUCCESS) {
        printf("Usuário removido com sucesso!");
    }
    else {
        printf("Erro ao remover usuário.");
    }
}

void MENU_ListUsers() {
    printf("=============================================================\n");

    FILE* file = fopen(DATABASE_FILE_PATH, "rb"); 

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    User user;

    printf("Usuários registrados:\n");
    printf("%-15s %-15s %-15s %-15s\n", "Id", "Nome", "Senha", "Administrador");
    printf("-------------------------------------------------------------\n");

    while (fread(&user, sizeof(User), 1, file) == 1) {
        printf("%-15d %-15s %-15s %-15d\n", user.id, user.name, user.password, user.admin);
    }

    fclose(file);
}
