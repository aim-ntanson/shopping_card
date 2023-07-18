//
// Created by aimsern on 7/15/2023.
//

#include "../include/ProductRepositoryFactory.h"
#include "../include/InMemoryProductRepository.h"

ProductRepositoryFactory::ProductRepositoryFactory() {
    productRepository = nullptr;

}

ProductRepository *ProductRepositoryFactory::getProductRepository() {
    if (productRepository == nullptr)
        productRepository = new InMemoryProductRepository();

    return productRepository ;
}
