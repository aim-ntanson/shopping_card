//
// Created by aimsern on 7/3/2023.
//

#ifndef SHOPPING_CARD_ORDERSERVICEIMPL_H
#define SHOPPING_CARD_ORDERSERVICEIMPL_H


#include "../OrderService.h"
#include "../../domain/repository/OrderRepository.h"
#include "../../domain/repository/ProductRepository.h"
#include "../../domain/service/InventoryService.h"
#include "../../domain/factory/OrderFactory.h"

class OrderServiceImpl : public OrderService{
private:
    OrderRepository* orderRepository;
    ProductRepository* productRepository;
    InventoryService* inventoryService;
    OrderFactory* orderFactory;

public:
    OrderServiceImpl(InventoryService* inventoryService) {
        orderRepository = OrderRepositoryFactory
    }


};


#endif //SHOPPING_CARD_ORDERSERVICEIMPL_H
