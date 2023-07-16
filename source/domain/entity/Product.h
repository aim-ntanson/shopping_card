//
// Created by aimsern on 6/24/2023.
//

#ifndef SHOPPING_CARD_PRODUCT_H
#define SHOPPING_CARD_PRODUCT_H


#include <string>

class Product {
private:
    std::string id;
    std::string name;
    double price;

public:
    Product(const std::string& id, const std::string& name, double price) {
        this->id = id;
        this->name = name;
        this->price = price;
    }

    Product& operator=(const Product& other) = default;

    std::string getId() const {
        return id;
    }

    std::string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

};


#endif //SHOPPING_CARD_PRODUCT_H
