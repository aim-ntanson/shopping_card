//
// Created by aimsern on 6/24/2023.
//

#ifndef SHOPPING_CARD_ORDERREPOSITORY_H
#define SHOPPING_CARD_ORDERREPOSITORY_H


#include "../root-aggregate/Order.h"

class OrderRepository {
public:
    virtual void save(Order order) = 0;
    virtual Order * getOrderById(long id) = 0;
    virtual std::list<Order> getAllOrders() = 0;
};

#endif //SHOPPING_CARD_ORDERREPOSITORY_H
