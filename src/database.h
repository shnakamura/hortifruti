#ifndef DATABASE_H
#define DATABASE_H

/**
 * @brief Cria o arquivo de banco de dados para armazenar informações de produtos do sistema de gerenciamento.
 *
 * Gera um arquivo de banco de dados, caso ele ainda não exista, e o prepara para armazenar dados do sistema,
 * sendo informações de produtos como nome, identificador numérico, quantidade disponível em estoque e preço
 * em reais.
 */
void DATABASE_CreateFile();

#endif
