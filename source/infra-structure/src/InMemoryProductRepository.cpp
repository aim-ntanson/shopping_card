//
// Created by aimsern on 7/4/2023.
//

#include "../include/InMemoryProductRepository.h"

Product* InMemoryProductRepository::getProductById(std::string productId) {
    for (const Product& product : products) {
        if (product.getId() == productId) {
            return reinterpret_cast<Product *>(&products);
        }
    }
    return nullptr;
}

void InMemoryProductRepository::saveProduct(Product product) {
    products.push_back(product);
}

void InMemoryProductRepository::updateProduct(Product product) {
    for (Product& p : products)
    {
        if (p.getId() == product.getId())
        {
            p = product;
            break;
        }
    }
}

void InMemoryProductRepository::deleteProduct(Product product) {
    products.erase(std::remove(products.begin(), products.end(), product), products.end());
}
