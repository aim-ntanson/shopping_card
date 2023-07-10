//
// Created by aimsern on 7/3/2023.
//

#ifndef SHOPPING_CARD_INMEMORYORDERREPOSITORY_H
#define SHOPPING_CARD_INMEMORYORDERREPOSITORY_H


#include <unordered_map>
#include <vector>
#include "../../domain/repository/OrderRepository.h"

class InMemoryOrderRepository : public OrderRepository {
private:
    std::unordered_map<long, Order*> orders;

public:
    void save(Order order) override;
    Order* getOrderById(long id) override;
    std::list<Order> getAllOrders() override;
};


#endif //SHOPPING_CARD_INMEMORYORDERREPOSITORY_H
