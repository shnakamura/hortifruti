#include "database.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "product.h"

void DATABASE_CreateFile() {
    FILE* file = fopen(DATABASE_FILE_PATH, "a");

    if (file == NULL) {
        printf("Erro ao criar o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    fclose(file);
}

void DATABASE_WriteProduct(char nome[PRODUCT_MAX_NAME_LENGTH], int id, int amount, float price) {
    FILE* file = fopen(DATABASE_FILE_PATH, "r+");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    Product product;

    strncpy(product.name, nome, PRODUCT_MAX_NAME_LENGTH);

    product.id = id;
    product.amount = amount;
    product.price = price;

    fwrite(&product, sizeof(Product), 1, file);
    fclose(file);
}
