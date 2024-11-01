#include "menu.h"

#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#include "auth.h"
#include "user.h"
#include "settings.h"
#include "database.h"

void MENU_Show() {
    int choice;

    int exitIndex = s_AuthenticatedUser->admin ? 9 : 6;

    do { 
        printf("███╗   ███╗███████╗███╗   ██╗██╗   ██╗ \n");
        printf("████╗ ████║██╔════╝████╗  ██║██║   ██║ \n");
        printf("██╔████╔██║█████╗  ██╔██╗ ██║██║   ██║ \n");
        printf("██║╚██╔╝██║██╔══╝  ██║╚██╗██║██║   ██║ \n");
        printf("██║ ╚═╝ ██║███████╗██║ ╚████║╚██████╔╝ \n");
        printf("╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝ ╚═════╝  \n");

        printf("1. Adicione um produto\n"); 
        printf("2. Venda de produto \n"); 
        printf("3. Demonstrativo de Estoque \n"); 
        printf("4. Demonstrativo de Vendas \n"); 
        printf("5. Remova um produto\n");

        if (s_AuthenticatedUser && s_AuthenticatedUser->admin == true) {
            printf("6. Adicione um usuário\n"); 
            printf("7. Remova um usuário\n"); 
            printf("8. Listar usuários\n"); 
        }

        printf("%d. Sair do programa\n", exitIndex);

        printf("Escolha uma opção e pressione enter: ");

        if (scanf("%d", &choice) != 1){
            printf("Entrada invalida. Por favor, insira um número.\n");

            while (getchar() !='\n');

            system("cls");
        }

        system("cls"); 

        switch (choice) {
             case 1:
                break;
            case 2:
                break;
            case 3:
                getch();
                break;
            case 4:
                getch();
                break;
            case 5:
                break;
            case 6:
                MENU_AddUser();
                break;
            case 7:
                MENU_RemoveUser();
                getch();
                break;
            case 8:
                MENU_ListUsers();
                getch();
                break;
            default:
                if (choice != exitIndex) {
                    printf("Tente novamente, a opção escolhida é invalida.\n"); 
                }
                break;
        }

        if (choice == exitIndex) {
            printf("Saindo do programa...");
            Sleep(SHUTDOWN_COOLDOWN_IN_MILLISECONDS);
            exit(EXIT_SUCCESS);
        }

        printf("\n");
        system("cls");
    } while (choice != exitIndex);
}

void MENU_AddUser() {
    if (!s_AuthenticatedUser || !s_AuthenticatedUser->admin) {
        return;
    }

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
    if (!s_AuthenticatedUser || !s_AuthenticatedUser->admin) {
        return;
    }

    int id = 0;

    printf("Digite o id do usuário para remover:");
    scanf("%d", &id);

    if (DATABASE_RemoveUser(id) == EXIT_SUCCESS) {
        printf("Usuário removido com sucesso!");
    }
    else {
        printf("Erro ao remover o usuário especificado.");
    }
}

void MENU_ListUsers() {
    if (!s_AuthenticatedUser || !s_AuthenticatedUser->admin) {
        return;
    }

    printf("=============================================================\n");

    FILE* file = fopen(DATABASE_FILE_PATH, "rb"); 

    if (file == NULL) {
        printf("Erro ao abrir a database de usuários.\n");
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
