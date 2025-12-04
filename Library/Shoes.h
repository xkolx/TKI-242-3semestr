#pragma once
#include "Product.h"

namespace ChildrenStore {
    class Shoes : public Product {
    private:
        int size;
        std::string color;

    public:
        Shoes(const std::string& name, double price, int quantity,
              int size, const std::string& color);

        int getSize() const;
        std::string getColor() const;

        bool hasSizeColor(int checkSize, const std::string& checkColor) const;

        std::string getDescription() const override;
    };
}