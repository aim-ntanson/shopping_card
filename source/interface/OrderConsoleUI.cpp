//
// Created by aimsern on 7/9/2023.
//

#include <iostream>
#include "OrderConsoleUI.h"
#include "ProductServiceImpl.h"

// todo: make constructor
OrderConsoleUI::OrderConsoleUI() {
    this->orderService = new OrderServiceImpl(new InventoryService());
    this->productService = new ProductServiceImpl();

    productService->saveProduct(Product("1", "Tao", 10.0));
    productService->saveProduct(Product("2", "Cam", 20.0));
    productService->saveProduct(Product("3", "Quit", 30.0));
}

void OrderConsoleUI::run() {
    std::string input;
    std::cout << "Welcome to the Order Console!" << std::endl;

    do {
        std::cout << "Please choose an option:" << std::endl;
        std::cout << "1. View products" << std::endl;
        std::cout << "2. Create order" << std::endl;
        std::cout << "3. View order" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::getline(std::cin, input);

        if (input == "1") {
            viewProducts();
        }
        else if (input == "2") {
            createOrder();
        }
        else if (input == "3") {
            viewOrdersByCustomer();
        }
        else if (input == "4") {
            std::cout << "Goodbye!" << std::endl;
        }
        else {
            std::cout << "Invalid input, please try again." << std::endl;
        }

    } while (input != "4");
}

void OrderConsoleUI::viewProducts() {
    std::cout << "Products:" << std::endl;
    for (const auto& product : productService->getAllProducts()) {
        std::cout << product.getId() << ". " << product.getName() << " - $" << product.getPrice() << std::endl;
    }
}

void OrderConsoleUI::createOrder() {
    std::string input;
    std::string customerId = getCustomerIdFromUser();
    Order order = orderService->createOrder(customerId);
    do {
        viewProducts();
        std::cout << "Please enter the ID of the product you want to order, or type 'done' to finish: ";
        std::getline(std::cin, input);

        if (input != "done") {
            try {
                const std::string& productId = input;
                Product *product = productService->getProductById(productId);

                if (nullptr != product) {
                    //todo: convert %.2f%n for product->getPrice()
                    std::cout << "Product: " << product->getName() << " - $" << product->getPrice() << std::endl;
                    std::cout << "Please enter the quantity:" ;
                    int quantity;
                    std::cin >> quantity;
                    std::cin.ignore();

                    orderService->addItemToOrder(order, productId, quantity);
                } else {
                    std::cout << "Invalid product ID, please try again." << std::endl;
                }
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input, please try again." << std::endl;
            }
        }
    } while (input != "done");

    std::cout << "Order details: ";
    for (OrderItem item : order.getItems()) {
        Product product = item.getProduct();
        int quantity = item.getQuantity();
        double totalPrice = item.getTotalPrice();
        std::cout << product.getName() << " - " << quantity << " x " << product.getPrice()
                    << " = " << totalPrice << std::endl;
    }
    std::cout << "Total: " << order.getTotalAmount() << std::endl;
}

std::string OrderConsoleUI::getCustomerIdFromUser() {
    std::string customerId;
    std::cout << "Enter customer ID: " << std::endl;
    std::getline(std::cin, customerId);
    return customerId;
}

void OrderConsoleUI::viewOrdersByCustomer() {
    std::string customerId = getCustomerIdFromUser();
    std::list<Order> orders = orderService->getOrdersByCustomer(customerId);
    if (orders.empty()) {
        std::cout << "No orders found for customer " << customerId << std::endl;
    }
    else {
        std::cout << "Orders for customer " << customerId << ":" << std::endl;
        for (const auto& order : orders) {
            std::cout << order << std::endl;

        }
    }
}
