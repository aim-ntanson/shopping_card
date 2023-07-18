//
// Created by aimsern on 6/24/2023.
//

#include "Order.h"

std::ostream &operator<<(std::ostream &out, Order order) {
    out << "Customer's name: " << (order.getCustomer()).getName();
    out << "(" << order.getId() << ")" << std::endl;
    out << "List order: " << order.toString() << std::endl;
    out << "Order status: " << order.getStatus() << std::endl;
    out << "Time created order: " << order.getCreatedAt() << std::endl;
    return out;
}

void Order::calculateTotalAmount() {
    double total = 0;
    for (OrderItem item : items) {
        total += item.getTotalPrice();
    }
    this->totalAmount = total;
}

void Order::addItem(OrderItem item) {
    //todo
    items.push_back(item);
    calculateTotalAmount();
}

void Order::removeItem(OrderItem item) {
    //todo
    items.remove(item);
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

