#pragma once
#include "Product.h"

namespace ChildrenStore {
    class Clothing : public Product {
    private:
        std::string size;
        std::string color;
        std::string style;

    public:
        Clothing(const std::string& name, double price, int quantity,
                 const std::string& size, const std::string& color,
                 const std::string& style);

        std::string getSize() const;
        std::string getColor() const;
        std::string getStyle() const;

        bool hasSizeColorStyle(const std::string& checkSize,
                               const std::string& checkColor,
                               const std::string& checkStyle) const;

        std::string getDescription() const override;
    };
}