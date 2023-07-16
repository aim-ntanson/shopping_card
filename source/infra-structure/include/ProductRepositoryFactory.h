//
// Created by aimsern on 7/15/2023.
//

#ifndef SHOPPING_CARD_PRODUCTREPOSITORYFACTORY_H
#define SHOPPING_CARD_PRODUCTREPOSITORYFACTORY_H


#include "../../domain/repository/ProductRepository.h"

class ProductRepositoryFactory {
private:
    static ProductRepository   *productRepository;

public:
    ProductRepositoryFactory();
    static ProductRepository* getProductRepository();
};


#endif //SHOPPING_CARD_PRODUCTREPOSITORYFACTORY_H
