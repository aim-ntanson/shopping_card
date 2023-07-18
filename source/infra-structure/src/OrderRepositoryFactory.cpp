//
// Created by aimsern on 7/10/2023.
//

#include "../include/OrderRepositoryFactory.h"
#include "../include/InMemoryOrderRepository.h"

OrderRepository *OrderRepositoryFactory::getOrderRepository() {
    if (orderRepository == nullptr)
    {
        orderRepository = new InMemoryOrderRepository();
    }
    return orderRepository;
}

