//
// Created by aimsern on 6/24/2023.
//

#ifndef SHOPPING_CARD_PRODUCTREPOSITORY_H
#define SHOPPING_CARD_PRODUCTREPOSITORY_H


#include <list>
#include "../entity/Product.h"

class ProductRepository {
public:
    virtual std::list<Product> getAllProducts() = 0;
    virtual Product* getProductById(std::string productId) = 0;
    virtual void saveProduct(Product& product) = 0;
    virtual void updateProduct(Product& product) = 0;
    virtual void deleteProduct(Product& product) = 0;
};

#endif //SHOPPING_CARD_PRODUCTREPOSITORY_H
