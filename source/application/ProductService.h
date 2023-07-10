//
// Created by aimsern on 7/3/2023.
//

#ifndef SHOPPING_CARD_PRODUCTSERVICE_H
#define SHOPPING_CARD_PRODUCTSERVICE_H


#include <list>
#include "../domain/entity/Product.h"

class ProductService {
public:
    virtual  std::list<Product> getAllProducts() = 0;
    virtual  Product getProductById(std::string id) = 0;
    virtual  void saveProduct(Product product) = 0;
    virtual  void updateProduct(Product product) = 0;
    virtual  void deleteProduct(Product product) = 0;
};


#endif //SHOPPING_CARD_PRODUCTSERVICE_H
