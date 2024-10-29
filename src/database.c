#include "database.h"

#include <stdio.h>
#include <stdlib.h>

void DATABASE_CreateFile() {
    FILE* file = fopen("database.txt", "a");

    if (file == NULL) {
        printf("Erro ao criar o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    fclose(file);
}
