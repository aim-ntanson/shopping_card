//
// Created by aimsern on 7/4/2023.
//

#ifndef SHOPPING_CARD_INMEMORYPRODUCTREPOSITORY_H
#define SHOPPING_CARD_INMEMORYPRODUCTREPOSITORY_H


#include <list>
#include "../../domain/entity/Product.h"
#include "../../domain/repository/ProductRepository.h"

class InMemoryProductRepository : public ProductRepository{
private:
    std::list<Product> products;

public:
    InMemoryProductRepository() {
        products = std::list<Product>();
    }

    std::list<Product> getAllProducts() override
    {
        return products;
    }

    Product* getProductById(std::string productId) override;
    void saveProduct(Product& product) override;
    void updateProduct(Product& product) override;
    void deleteProduct(Product& product) override;
};


#endif //SHOPPING_CARD_INMEMORYPRODUCTREPOSITORY_H
