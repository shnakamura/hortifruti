#include "database.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "user.h"

int DATABASE_CreateFile() {
    FILE* file = fopen(DATABASE_FILE_PATH, "a");

    if (file == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return EXIT_FAILURE;
    }

    fclose(file);

    return EXIT_SUCCESS;
}

int DATABASE_WriteUser(char username[USER_MAX_USERNAME_LENGTH], char password[USER_MAX_PASSWORD_LENGTH], int admin) {
    FILE* file = fopen(DATABASE_FILE_PATH, "rb+");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return EXIT_FAILURE;
    }

    fseek(file, 0, SEEK_END);

    int count = ftell(file) / sizeof(User);

    for (int i = 0; i < count; i++) {
        User* temp = DATABASE_GetUser(i);

        if (temp->name == username) {
            return EXIT_FAILURE;
        }
    }
    
    User user;

    strncpy(user.name, username, USER_MAX_USERNAME_LENGTH);
    strncpy(user.password, password, USER_MAX_PASSWORD_LENGTH);

    user.admin = admin;
    user.id = ftell(file) / sizeof(User);

    fwrite(&user, sizeof(User), 1, file);
    fclose(file);

    return EXIT_SUCCESS;
}

int DATABASE_RemoveUser(int id) {
    FILE* file = fopen(DATABASE_FILE_PATH, "rb+");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return EXIT_FAILURE;
    }

    FILE* temp = fopen(DATABASE_TEMPORARY_FILE_PATH, "wb");

    if (temp == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(file);
        return EXIT_SUCCESS;
    }

    User user;

    while (fread(&user, sizeof(User), 1, file) == 1) {
        if (user.id != id) {
            fwrite(&user, sizeof(User), 1, temp);
        }
    }

    fclose(file);
    fclose(temp);

    remove(DATABASE_FILE_PATH);
    rename(DATABASE_TEMPORARY_FILE_PATH, DATABASE_FILE_PATH);

    return EXIT_SUCCESS;
}

User* DATABASE_GetUser(int id) {
    FILE* file = fopen(DATABASE_FILE_PATH, "rb+");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    User* user = (User*)malloc(sizeof(User));

    if (user == NULL) {
        printf("Erro ao alocar memória para o usuário.\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fseek(file, sizeof(User) * id, SEEK_SET);

    if (fread(user, sizeof(User), 1, file) != 1) {
        printf("Erro ao ler o usuário do arquivo.\n");
        free(user); 
        fclose(file);
        return NULL;
    }

    fclose(file);
    return user; 
}
