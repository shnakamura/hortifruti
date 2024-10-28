#ifndef PRODUCT_H
#define PRODUCT_H

typedef struct Product {
    /**
     * O identificador numérico deste produto.
     */
    int id;

    /**
     * A quantidade deste produto.
     */
    int amount;

    /**
     * O preço deste produto.
     */
    float price;
} Product;

#endif
