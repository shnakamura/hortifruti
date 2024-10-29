#include "database.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "user.h"

void DATABASE_CreateFile() {
    FILE* file = fopen(DATABASE_FILE_PATH, "a");

    if (file == NULL) {
        printf("Erro ao criar o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    fclose(file);
}

void DATABASE_WriteUser(char username[USER_MAX_USERNAME_LENGTH], char password[USER_MAX_PASSWORD_LENGTH], bool admin) {
    FILE* file = fopen(DATABASE_FILE_PATH, "rb+");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }
    
    User user;

    strncpy(user.name, username, USER_MAX_USERNAME_LENGTH);
    strncpy(user.password, password, USER_MAX_PASSWORD_LENGTH);

    int id = 0;

    user.id = id;
    user.admin = admin;

    fseek(file, 0, SEEK_END);
    fwrite(&user, sizeof(User), 1, file);
    fclose(file);
}

void DATABASE_RemoveUser(int id) {
    FILE* file = fopen(DATABASE_FILE_PATH, "rb+");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    User user;

    while (fread(&user, sizeof(User), 1, file) != 0) {
        fprint("%d", user.id);
    }

    fclose(file);
}