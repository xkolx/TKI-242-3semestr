#include "Food.h"

namespace ChildrenStore {
    Food::Food(const std::string& name, double price, int quantity,
               const std::string& brand)
        : Product(name, price, quantity, "Food"),
          brand(brand) {}

    std::string Food::getBrand() const { return brand; }

    std::string Food::getDescription() const {
        return "Food: " + name + ", Brand: " + brand +
               ", Price: " + std::to_string(price);
    }
}