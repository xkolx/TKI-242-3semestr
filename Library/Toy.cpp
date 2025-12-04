#include "Toy.h"

namespace ChildrenStore {
    Toy::Toy(const std::string& name, double price, int quantity,
             const std::string& ageRange)
        : Product(name, price, quantity, "Toys"),
          ageRange(ageRange) {}

    std::string Toy::getAgeRange() const { return ageRange; }

    std::string Toy::getDescription() const {
        return "Toy: " + name + ", Age: " + ageRange +
               ", Price: " + std::to_string(price);
    }
}