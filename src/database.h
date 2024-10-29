#ifndef DATABASE_H
#define DATABASE_H

#define DATABASE_FILE_PATH "produtos.bin"

#include "product.h"

/**
 * @brief Cria o arquivo de banco de dados para armazenar informações de produtos do sistema de gerenciamento.
 *
 * Gera um arquivo de banco de dados, caso ele ainda não exista, e o prepara para armazenar dados do sistema,
 * sendo informações de produtos como nome, identificador numérico, quantidade disponível em estoque e preço
 * em reais.
 */
void DATABASE_CreateFile();

void DATABASE_WriteProduct(char name[PRODUCT_MAX_NAME_LENGTH], int id, int amount, float price);

#endif
