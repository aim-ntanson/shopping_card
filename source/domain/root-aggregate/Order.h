//
// Created by aimsern on 6/24/2023.
//

#ifndef SHOPPING_CARD_ORDER_H
#define SHOPPING_CARD_ORDER_H

#include <list>
#include <sstream>
#include <chrono>
#include "../internal-aggregate/Customer.h"
#include "../value-object/OrderItem.h"
#include "../value-object/OrderStatus.h"

class Order {
private:
    long id;
    Customer customer;
    std::list<OrderItem> items;
    double totalAmount;
    time_t createdAt;
    OrderStatus status;
    std::string orderNumber;

public:
    Order(const std::string& orderNumber, const std::string& customerId)
            : orderNumber(orderNumber), customer(Customer(customerId, orderNumber))
    {
        items = std::list<OrderItem>();
        totalAmount = 0;
        status = OrderStatus::NEW;
        createdAt = time(nullptr);
    }

    long getId() {
        return id;
    }

    Customer getCustomer() {
        return customer;
    }

    std::list<OrderItem> getItems() {
        return items;
    }

    double getTotalAmount() {
        return totalAmount;
    }

    time_t getCreatedAt() {
        return createdAt;
    }

    OrderStatus getStatus() {
        return status;
    }

    void setStatus(OrderStatus status) {
        this->status = status;
    }

    void calculateTotalAmount();
    void addItem(OrderItem item);
    void removeItem(OrderItem item);

    void cancel() {
        status = OrderStatus::CANCELLED;
    }

    std::string toString();
};


#endif //SHOPPING_CARD_ORDER_H
