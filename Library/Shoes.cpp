#include "Shoes.h"

namespace ChildrenStore {
    Shoes::Shoes(const std::string& name, double price, int quantity,
                 int size, const std::string& color)
        : Product(name, price, quantity, "Shoes"),
          size(size), color(color) {}

    int Shoes::getSize() const { return size; }
    std::string Shoes::getColor() const { return color; }

    bool Shoes::hasSizeColor(int checkSize, const std::string& checkColor) const {
        if (quantity == 0) return false;
        
        bool sizeOk = checkSize == 0 || size == checkSize;
        bool colorOk = checkColor.empty() || color == checkColor;
        
        return sizeOk && colorOk;
    }

    std::string Shoes::getDescription() const {
        return "Shoes: " + name + ", Size: " + std::to_string(size) +
               ", Color: " + color + ", Price: " + std::to_string(price);
    }
}