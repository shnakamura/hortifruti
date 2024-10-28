#include "menu.h"

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#include "main.h"
#include "database.h"

#define MAX_PROD_NAME_LENGTH 50
#define MAX_FILENAME_LENGTH 100

void MNU_ShowMenu() {
    int choice;

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
        printf("6. Sair do Programa\n"); 
        printf("Escolha uma opção e pressionde enter: ");

        if (scanf("%d", &choice) != 1){
            printf("Entrada invalida. Por favor, insira um número.\n");
            Sleep(1);

            while (getchar() !='\n');

            system("cls");
        }

        system("cls"); 

        switch (choice) {
            case 1:
                MNU_AddProduct(); 
                break;
            case 2:
                MNU_SellProduct();
                break;
            case 3:
                MNU_ShowStock();
                getch();
                break;
            case 4:
                MNU_ShowSales();
                getch();
                break;
            case 5:
                MNU_DeleteProduct();
                break;
            case 6:
                MAIN_Exit();
                break;
            default:
                printf("Tente novamente, opção escolhida é invalida.\n"); 
                break;
        }

        printf("\n");
        system("cls");
    } while (choice != 6);
}

void MNU_AddProduct() {
    char prod_name[MAX_PROD_NAME_LENGTH];
    float preco; 
    int quantidade;

    printf(" █████╗ ██████╗ ██╗ ██████╗██╗ ██████╗ ███╗   ██╗ █████╗ ██████╗     ██████╗ ██████╗  ██████╗ ██████╗ ██╗   ██╗████████╗ ██████╗ \n");
    printf("██╔══██╗██╔══██╗██║██╔════╝██║██╔═══██╗████╗  ██║██╔══██╗██╔══██╗    ██╔══██╗██╔══██╗██╔═══██╗██╔══██╗██║   ██║╚══██╔══╝██╔═══██╗\n");
    printf("███████║██║  ██║██║██║     ██║██║   ██║██╔██╗ ██║███████║██████╔╝    ██████╔╝██████╔╝██║   ██║██║  ██║██║   ██║   ██║   ██║   ██║\n");
    printf("██╔══██║██║  ██║██║██║     ██║██║   ██║██║╚██╗██║██╔══██║██╔══██╗    ██╔═══╝ ██╔══██╗██║   ██║██║  ██║██║   ██║   ██║   ██║   ██║\n");
    printf("██║  ██║██████╔╝██║╚██████╗██║╚██████╔╝██║ ╚████║██║  ██║██║  ██║    ██║     ██║  ██║╚██████╔╝██████╔╝╚██████╔╝   ██║   ╚██████╔╝\n");
    printf("╚═╝  ╚═╝╚═════╝ ╚═╝ ╚═════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝    ╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚═════╝  ╚═════╝    ╚═╝    ╚═════╝ \n");
    printf("Digite o nome do produto: ");
    scanf("%s", prod_name); 
    printf("Digite o preço do produto: "); 
    scanf("%f", &preco); 
    printf("Digite a quantidade do produto: ");
    scanf("%d", &quantidade); 

    FILE* file = fopen("database.txt", "r");

    if (file == NULL) {
        DB_CreateFile(); 

        file = fopen("database.txt", "r");

        if (file == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return;
        }
    }

    int id = 0; 
    char line[100]; 

    while (fgets(line, sizeof(line), file)) { 
        id++; 
    }

    fclose(file);

    file = fopen("database.txt", "a");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(file, "%d,%s,%.2f,%d\n", id + 1, prod_name, preco, quantidade);
    fclose(file); 

    printf("Produto adicionado com sucesso!\n");
}

void MNU_SellProduct() {
    printf("██╗   ██╗███████╗███╗   ██╗██████╗ ███████╗██████╗     ██████╗ ██████╗  ██████╗ ██████╗ ██╗   ██╗████████╗ ██████╗ \n");
    printf("██║   ██║██╔════╝████╗  ██║██╔══██╗██╔════╝██╔══██╗    ██╔══██╗██╔══██╗██╔═══██╗██╔══██╗██║   ██║╚══██╔══╝██╔═══██╗\n");
    printf("██║   ██║█████╗  ██╔██╗ ██║██║  ██║█████╗  ██████╔╝    ██████╔╝██████╔╝██║   ██║██║  ██║██║   ██║   ██║   ██║   ██║\n");
    printf("╚██╗ ██╔╝██╔══╝  ██║╚██╗██║██║  ██║██╔══╝  ██╔══██╗    ██╔═══╝ ██╔══██╗██║   ██║██║  ██║██║   ██║   ██║   ██║   ██║\n");
    printf(" ╚████╔╝ ███████╗██║ ╚████║██████╔╝███████╗██║  ██║    ██║     ██║  ██║╚██████╔╝██████╔╝╚██████╔╝   ██║   ╚██████╔╝\n");
    printf("  ╚═══╝  ╚══════╝╚═╝  ╚═══╝╚═════╝ ╚══════╝╚═╝  ╚═╝    ╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚═════╝  ╚═════╝    ╚═╝    ╚═════╝ \n");

    printf("Digite o ID do produto para realizar a venda: ");

    int id;

    scanf("%d", &id);

    printf("Digite a quantidade do produto a ser vendido: ");

    int quantidade;

    scanf("%d", &quantidade);

    FILE* file = fopen("database.txt", "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    FILE* tempFile = fopen("temp.txt", "w");

    if (tempFile == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(file);
        return;
    }

    char line[100];
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        int prod_id;
        char prod_name[MAX_PROD_NAME_LENGTH];
        float preco;
        int estoque_qtd;

        sscanf(line, "%d,%[^,],%f,%d", &prod_id, prod_name, &preco, &estoque_qtd);

        if (prod_id == id) {
            found = 1;
            if (quantidade <= estoque_qtd) {
                int updatedquantidade = estoque_qtd - quantidade;

                fprintf(tempFile, "%d,%s,%.2f,%d\n", prod_id, prod_name, preco, updatedquantidade);
                printf("Produto vendido com sucesso!\n");

                FILE* balanceFile = fopen("balance.txt", "a");

                if (balanceFile == NULL) {
                    printf("Erro ao abrir o arquivo 'balance'.\n");
                    fclose(file);
                    fclose(tempFile);
                    return;
                }

                float valor_total = preco * quantidade;

                fprintf(balanceFile, "%.2f\n", valor_total);
                fclose(balanceFile);
            } else {
                printf("Quantidade insuficiente no estoque.\n");
                fprintf(tempFile, "%d,%s,%.2f,%d\n", prod_id, prod_name, preco, estoque_qtd);
            }
        } else {
            fprintf(tempFile, "%d,%s,%.2f,%d\n", prod_id, prod_name, preco, estoque_qtd);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove("database.txt");
        rename("temp.txt", "database.txt");
    } else {
        printf("Produto não encontrado.\n");
        remove("temp.txt");
    }
}

void MNU_ShowStock() {
    printf("███████╗███████╗████████╗ ██████╗  ██████╗ ██╗   ██╗███████╗ \n");
    printf("██╔════╝██╔════╝╚══██╔══╝██╔═══██╗██╔═══██╗██║   ██║██╔════╝\n");
    printf("█████╗  ███████╗   ██║   ██║   ██║██║   ██║██║   ██║█████╗  \n");
    printf("██╔══╝  ╚════██║   ██║   ██║   ██║██║▄▄ ██║██║   ██║██╔══╝  \n");
    printf("███████╗███████║   ██║   ╚██████╔╝╚██████╔╝╚██████╔╝███████╗\n");
    printf("╚══════╝╚══════╝   ╚═╝    ╚═════╝  ╚══▀▀═╝  ╚═════╝ ╚══════╝\n");

    printf("ID\tNome do Produto\tPreco\tQuantidade\n");

    printf("===============================================\n");

    FILE* file = fopen("database.txt", "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char line[100];

    while (fgets(line, sizeof(line), file)) {
        int prod_id;
        char prod_name[MAX_PROD_NAME_LENGTH];
        float preco;
        int quantidade;

        sscanf(line, "%d,%[^,],%f,%d", &prod_id, prod_name, &preco, &quantidade);
        printf("%d\t%s\t\t%.2f\t%d\n", prod_id, prod_name, preco, quantidade);
    }

    fclose(file); 
}

void MNU_ShowSales() {
    printf("▄▄███▄▄·    ██╗   ██╗███████╗███╗   ██╗██████╗  █████╗ ███████╗    ▄▄███▄▄· \n");
    printf("██╔════╝    ██║   ██║██╔════╝████╗  ██║██╔══██╗██╔══██╗██╔════╝    ██╔════╝\n");
    printf("███████╗    ██║   ██║█████╗  ██╔██╗ ██║██║  ██║███████║███████╗    ███████╗\n");
    printf("╚════██║    ╚██╗ ██╔╝██╔══╝  ██║╚██╗██║██║  ██║██╔══██║╚════██║    ╚════██║\n");
    printf("███████║     ╚████╔╝ ███████╗██║ ╚████║██████╔╝██║  ██║███████║    ███████║\n");
    printf("╚═▀▀▀══╝      ╚═══╝  ╚══════╝╚═╝  ╚═══╝╚═════╝ ╚═╝  ╚═╝╚══════╝    ╚═▀▀▀══╝\n");

    FILE* balanceFile = fopen("balance.txt", "r");

    if (balanceFile == NULL) {
        printf("Erro ao abrir o arquivo 'balance'.\n");
        return;
    }

    float total_vendas = 0.0;
    char line[100];

    while (fgets(line, sizeof(line), balanceFile)) {
        float amount = atof(line);
        total_vendas += amount;
    }

    fclose(balanceFile);

    printf("Total de vendas realizadas em R$: %.2f\n", total_vendas);
}

void MNU_DeleteProduct() {
    printf("██████╗ ███████╗███╗   ███╗ ██████╗ ██╗   ██╗███████╗██████╗     ██████╗ ██████╗  ██████╗ ██████╗ ██╗   ██╗████████╗ ██████╗\n");
    printf("██╔══██╗██╔════╝████╗ ████║██╔═══██╗██║   ██║██╔════╝██╔══██╗    ██╔══██╗██╔══██╗██╔═══██╗██╔══██╗██║   ██║╚══██╔══╝██╔═══██╗\n");
    printf("██████╔╝█████╗  ██╔████╔██║██║   ██║██║   ██║█████╗  ██████╔╝    ██████╔╝██████╔╝██║   ██║██║  ██║██║   ██║   ██║   ██║   ██║\n");
    printf("██╔══██╗██╔══╝  ██║╚██╔╝██║██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗    ██╔═══╝ ██╔══██╗██║   ██║██║  ██║██║   ██║   ██║   ██║   ██║\n");
    printf("██║  ██║███████╗██║ ╚═╝ ██║╚██████╔╝ ╚████╔╝ ███████╗██║  ██║    ██║     ██║  ██║╚██████╔╝██████╔╝╚██████╔╝   ██║   ╚██████╔╝\n");
    printf("╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝ ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝    ╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚═════╝  ╚═════╝    ╚═╝    ╚═════╝ \n");

    int id;

    printf("Informe o ID do produto que deseja remover: ");

    scanf("%d", &id);

    FILE* file = fopen("database.txt", "r+");
    
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    FILE* tempFile = fopen("temp.txt", "w");
    
    if (tempFile == NULL) {
        printf("Erro ao criar um arquivo temporario.\n");
        fclose(file); 
        return;
    }

    char line[100];
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        int prod_id;
        char prod_name[MAX_PROD_NAME_LENGTH];
        float preco;
        int quantidade;

        sscanf(line, "%d,%[^,],%f,%d", &prod_id, prod_name, &preco, &quantidade);

        if (prod_id != id) {
            fprintf(tempFile, "%d,%s,%.2f,%d\n", prod_id, prod_name, preco, quantidade);
        } else {
            found = 1;
        }
    }

    fclose(file); 
    fclose(tempFile);

    if (found) {
        remove("database.txt");
        rename("temp.txt", "database.txt");
        printf("Produto removido com sucesso!\n");
    } else {
        remove("temp.txt");
        printf("Produto não encontrado.\n");
    }
}
