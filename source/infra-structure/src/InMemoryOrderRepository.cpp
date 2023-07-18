//
// Created by aimsern on 7/3/2023.
//

#include "../include/InMemoryOrderRepository.h"

void InMemoryOrderRepository::save(Order order) {
    orders[order.getId()] = &order;
}

Order* InMemoryOrderRepository::getOrderById(long id) {
    auto it = orders.find(id);
        if (it != orders.end()) {
        return it->second;
    }
    return nullptr;
}

std::list<Order> InMemoryOrderRepository::getAllOrders() {
    std::list<Order> allOrders;
    for (auto& pair : orders) {
        allOrders.push_back(pair.second);
    }
    return allOrders;
}
