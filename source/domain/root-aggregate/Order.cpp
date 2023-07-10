//
// Created by aimsern on 6/24/2023.
//

#include "Order.h"
void Order::calculateTotalAmount() {
    double total = 0;
    for (OrderItem item : items) {
        total += item.getTotalPrice();
    }
    this->totalAmount = total;
}

void Order::addItem(OrderItem item) {
    items.push_back(item);
    calculateTotalAmount();
}

void Order::removeItem(OrderItem item) {
    items.remove(item);
//        items.erase(std::remove(items.begin(), items.end(), item), items.end());
    calculateTotalAmount();
}

std::string Order::toString() {
    std::stringstream str;
    str << "customerID:" <<  customer.getId() << "\n";
    for (OrderItem item: items) {
        str << item.getProduct().getName() << ". quantity: " << item.getQuantity() << "\n";
    }
    return str.str();
}
