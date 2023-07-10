//
// Created by aimsern on 6/24/2023.
//

#ifndef SHOPPING_CARD_CUSTOMER_H
#define SHOPPING_CARD_CUSTOMER_H


#include <string>
#include <utility>

class Customer {
private:
    std::string id;
    std::string name;

public:
    Customer(std::string id, std::string name) {
        this->id = std::move(id);
        this->name = std::move(name);
    }

    Customer& operator=(const Customer& other) {
        if (this != &other) {
            this->id = other.id;
            this->name = other.name;
        }
        return *this;
    }

    std::string getId() {
        return id;
    }

    std::string getName() {
        return name;
    }
};


#endif //SHOPPING_CARD_CUSTOMER_H
