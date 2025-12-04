#include "Clothing.h"

namespace ChildrenStore {
    Clothing::Clothing(const std::string& name, const double price, const int quantity,
                       const std::string& size, const std::string& color,
                       const std::string& style)
        : Product(name, price, quantity, "Clothing"),
          size(size), color(color), style(style) {}

    std::string Clothing::getSize() const { return size; }
    std::string Clothing::getColor() const { return color; }
    std::string Clothing::getStyle() const { return style; }

    bool Clothing::hasSizeColorStyle(const std::string& checkSize,
                                     const std::string& checkColor,
                                     const std::string& checkStyle) const {
        if (quantity == 0) return false;
        
        bool sizeOk = checkSize.empty() || size == checkSize;
        bool colorOk = checkColor.empty() || color == checkColor;
        bool styleOk = checkStyle.empty() || style == checkStyle;
        
        return sizeOk && colorOk && styleOk;
    }

    std::string Clothing::getDescription() const {
        return "Clothing: " + name + ", Size: " + size +
               ", Color: " + color + ", Style: " + style +
               ", Price: " + std::to_string(price);
    }
}