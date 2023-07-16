//
// Created by aimsern on 7/10/2023.
//

#ifndef SHOPPING_CARD_ORDERREPOSITORYFACTORY_H
#define SHOPPING_CARD_ORDERREPOSITORYFACTORY_H


#include "../../domain/repository/OrderRepository.h"

class OrderRepositoryFactory {
private:
    static OrderRepository *orderRepository;

public:
    OrderRepositoryFactory() {
        orderRepository = nullptr;
    }
    static OrderRepository*  getOrderRepository();
};


#endif //SHOPPING_CARD_ORDERREPOSITORYFACTORY_H
