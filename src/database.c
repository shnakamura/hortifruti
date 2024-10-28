#include "database.h"
#include <stdio.h>
#include <stdlib.h>

void DB_CreateFile() {
    FILE* file = fopen("database.txt", "a");

    if (file == NULL) {
        printf("Erro ao criar o arquivo.\n");
        exit(-1);
    }

    fclose(file);
}
