//
// Created by aimsern on 6/24/2023.
//

#ifndef SHOPPING_CARD_INVENTORYSERVICE_H
#define SHOPPING_CARD_INVENTORYSERVICE_H


#include "../root-aggregate/Order.h"

class InventoryService {
public:
    void updateInventory(Order order) {
        printf("Inventory updated for order: %ld", order.getId());
    }
};


#endif //SHOPPING_CARD_INVENTORYSERVICE_H
