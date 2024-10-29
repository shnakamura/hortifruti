#ifndef PRODUCT_H
#define PRODUCT_H

/**
 * @def MAX_NAME_LENGTH
 * @brief A quantidade máxima de caractéres que o nome de um produto pode ter.
 */
#define PRODUCT_MAX_NAME_LENGTH 50

/**
 * @struct Product
 * @brief Represent um produto em um sistema de gerenciamento.
 * 
 * Essa estrutura contém informações essenciais sobre um produto, incluindo seu nome, identificador numérico,
 * quantidade disponível em estoque e preço em reais.
 */
typedef struct Product {
    /**
     * @var name
     * @brief O nome do produto.
     * 
     * Este campo é utilizado para a exibição do nome do produto no estoque. O valor deve conter no máximo
     * MAX_NAME_LENGTH caracteres.
     */
    char name[PRODUCT_MAX_NAME_LENGTH];

    /**
     * @var id
     * @brief O identificador numérico do produto.
     * 
     * Este campo é utilizado para identificar o produto dentro do sistema. O valor deve ser um número
     * inteiro não negativo.
     */
    int id;

    /**
     * @var amount
     * @brief A quantidade disponível do produto.
     * 
     * Este campo armazena a quantidade do produto em estoque. O valor deve ser um número inteiro não
     * negativo.
     */
    int amount;

    /**
     * @var price
     * @brief O preço do produto em reais.
     * 
     * Este campo é utilizado para a exibição do preço do produto no estoque. O valor deve ser um número
     * inteiro não negativo.
     */
    float price;
} Product;

#endif
