#include "Product.h"
#include <stdexcept>

namespace ChildrenStore {
    Product::Product(const std::string& name, double price, int quantity, const std::string& department)
        : name(name), price(price), quantity(quantity), department(department) {
        if (price < 0) throw std::invalid_argument("Price cannot be negative");
        if (quantity < 0) throw std::invalid_argument("Quantity cannot be negative");
    }

    std::string Product::getName() const { return name; }
    double Product::getPrice() const { return price; }
    int Product::getQuantity() const { return quantity; }
    std::string Product::getDepartment() const { return department; }

    void Product::setPrice(double newPrice) {
        if (newPrice < 0) throw std::invalid_argument("Price cannot be negative");
        price = newPrice;
    }

    void Product::setQuantity(int newQuantity) {
        if (newQuantity < 0) throw std::invalid_argument("Quantity cannot be negative");
        quantity = newQuantity;
    }

    double Product::getDiscountPrice(double totalPurchase, bool isRegularCustomer) const {
        double discount = 0.0;
        
        if (isRegularCustomer) {
            discount += 0.10;
        }
        
        if (totalPurchase > 5000.0) {
            discount += 0.05;
        }
        
        return price * (1.0 - discount);
    }

    std::string Product::getDescription() const {
        return name + " - " + std::to_string(price) + " (" +
               std::to_string(quantity) + " pcs)";
    }
}