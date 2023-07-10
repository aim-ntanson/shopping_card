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
public:
    OrderConsoleUI();
//    Scanner scanner = new Scanner(System.in);

    void run();
    void viewProducts();
    void createOrder();

private:
    ProductService productService;
    OrderService orderService;

};


#endif //SHOPPING_CARD_ORDERCONSOLEUI_H
