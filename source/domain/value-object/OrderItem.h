//
// Created by aimsern on 6/24/2023.
//

#ifndef SHOPPING_CARD_ORDERITEM_H
#define SHOPPING_CARD_ORDERITEM_H


#include "../entity/Product.h"

class OrderItem {
private:
    const Product *product;
    int quantity;

public:
    OrderItem(const Product *product, int quantity) {
        this->product = product;
        this->quantity = quantity;
    }

    bool operator==(const OrderItem& other) const {
        return (this->product)->getId() == (other.product)->getId();
    }

    Product getProduct() {
        return *product;
    }

    int getQuantity() const {
        return quantity;
    }

    void increaseQuantity(int _quantity) {
        quantity += _quantity;
    }

    void decreaseQuantity(int _quantity) {
        quantity -= _quantity;
    }

    double getTotalPrice() {
        return quantity * product->getPrice();
    }

};


#endif //SHOPPING_CARD_ORDERITEM_H
