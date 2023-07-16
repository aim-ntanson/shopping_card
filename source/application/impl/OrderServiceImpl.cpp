//
// Created by aimsern on 7/3/2023.
//

#include "OrderServiceImpl.h"

OrderServiceImpl::OrderServiceImpl(InventoryService *inventoryService) {
    this->orderRepository =  OrderRepositoryFactory::getOrderRepository();
    this->productRepository = ProductRepositoryFactory::getProductRepository();
    this->inventoryService = new InventoryService(*inventoryService);
    orderFactory = OrderFactory::getInstance();

}

Order OrderServiceImpl::createOrder(std::string customerId) {
    Order order = orderFactory->createOrder(customerId);
    orderRepository->save(order);
    inventoryService->updateInventory(order);
    return order;
}

void OrderServiceImpl::addItemToOrder(Order order, std::string productId, int quantity) {
    Product *product = productRepository->getProductById(productId);
    OrderItem *orderItem = new OrderItem(product, quantity);
    order.addItem(*orderItem);
    orderRepository->save(order);
    inventoryService->updateInventory(order);

}

