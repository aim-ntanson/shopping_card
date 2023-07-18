//
// Created by Tan_son_Nguyen on 7/17/2023.
//

#ifndef SHOPPING_CARD_PRODUCTSERVICEIMPL_H
#define SHOPPING_CARD_PRODUCTSERVICEIMPL_H


#include "ProductRepository.h"
#include "ProductRepositoryFactory.h"
#include "ProductService.h"

class ProductServiceImpl : public ProductService {
private:
    ProductRepository *productRepository;

public:
    ProductServiceImpl() {
        this->productRepository = ProductRepositoryFactory::getProductRepository();
    }

    std::list<Product> getAllProducts() override {
        return productRepository->getAllProducts();
    }

    Product* getProductById(std::string id) override {
        return productRepository->getProductById(id);
    }

    void saveProduct(Product product) override {
        productRepository->saveProduct(product);
    }

    void updateProduct(Product product) override {
        productRepository->updateProduct(product);
    }

    void deleteProduct(Product product) override {
        productRepository->deleteProduct(product);
    }
};


#endif //SHOPPING_CARD_PRODUCTSERVICEIMPL_H
