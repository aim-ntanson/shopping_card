//
// Created by aimsern on 7/9/2023.
//

#include <iostream>
#include "OrderConsoleUI.h"


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
        } else if (input == "2") {
            createOrder();
        } else if (input == "3") {
            viewOrdersByCustomer();
        } else if (input == "4") {
            std::cout << "Goodbye!" << std::endl;
        } else {
            std::cout << "Invalid input, please try again." << std::endl;
        }

    } while (input != "4");
}

void OrderConsoleUI::viewProducts() {
    std::cout << "Products:" << std::endl;
    for (const auto& product : productService.getAllProducts()) {
        std::cout << product.getId() << ". " << product.getName() << " - $" << product.getPrice() << std::endl;
    }
}

void OrderConsoleUI::createOrder() {
    std::string input;
    std::string customerId = getCustomerIdFromUser();
    Order order = orderService.createOrder(customerId);
}

OrderConsoleUI::OrderConsoleUI() {
    this->orderService = new OrderServiceImpl(new InventoryService());
    this->productService = new ProductServiceImpl();
    productService.saveProduct(Product("1", "Tao", 10.0));
    productService.saveProduct(Product("2", "Cam", 20.0));
    productService.saveProduct(Product("3", "Quit", 30.0));
}

