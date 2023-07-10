//
// Created by aimsern on 7/3/2023.
//

#ifndef SHOPPING_CARD_ORDERFACTORY_H
#define SHOPPING_CARD_ORDERFACTORY_H

#include "../root-aggregate/Order.h"
#include <string>

class OrderFactory {
private:
    static std::string generateOrderNumber() {
        // generate a unique order number
        // implementation details omitted for brevity
        return "ORD-123456789";
    }

public:
    static OrderFactory& getInstance() {
        static OrderFactory instance;
        return instance;
    }

    static Order createOrder(const std::string& customerId) {
        std::string orderNumber = generateOrderNumber();
        return Order(orderNumber, customerId);
    }
};


#endif //SHOPPING_CARD_ORDERFACTORY_H
