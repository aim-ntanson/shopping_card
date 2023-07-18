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
#include "../../infra-structure/include/OrderRepositoryFactory.h"
#include "../../infra-structure/include/ProductRepositoryFactory.h"

class OrderServiceImpl : public OrderService {
private:
    OrderRepository *orderRepository;
    ProductRepository *productRepository;
    InventoryService *inventoryService;
    OrderFactory *orderFactory;

public:
    OrderServiceImpl(InventoryService* inventoryService);
    Order createOrder(std::string customerId) override;
    void addItemToOrder(Order order, std::string productId, int quantity) override;
    void removeItemFromOrder(Order order, OrderItem item);
    std::list<Order> getOrdersByCustomer(std::string customerId);

};


#endif //SHOPPING_CARD_ORDERSERVICEIMPL_H
