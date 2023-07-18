//
// Created by aimsern on 7/9/2023.
//

#ifndef SHOPPING_CARD_ORDERCONSOLEUI_H
#define SHOPPING_CARD_ORDERCONSOLEUI_H


#include "../domain/service/InventoryService.h"
#include "../application/OrderService.h"
#include "../application/ProductService.h"
#include "../application/impl/OrderServiceImpl.h"

class OrderConsoleUI {
private:
    OrderService    *orderService;
    ProductService  *productService;
    void createOrder();


public:
    OrderConsoleUI();
    void run();
    void viewProducts();
    std::string getCustomerIdFromUser();
    void viewOrdersByCustomer();
};

#endif //SHOPPING_CARD_ORDERCONSOLEUI_H
