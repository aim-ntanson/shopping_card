//
// Created by aimsern on 7/3/2023.
//

#ifndef SHOPPING_CARD_ORDERSERVICE_H
#define SHOPPING_CARD_ORDERSERVICE_H


#include <string>
#include "../domain/root-aggregate/Order.h"

class OrderService {
public:
    virtual Order createOrder(std::string customerId) = 0;
    virtual void removeItemFromOrder(Order order, OrderItem item) = 0;
    virtual void addItemToOrder(Order order, std::string productId, int quantity) = 0;
    virtual std::list<Order> getOrdersByCustomer(std::string customerId);
};


#endif //SHOPPING_CARD_ORDERSERVICE_H
