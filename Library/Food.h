#pragma once
#include "Product.h"

namespace ChildrenStore {
    class Food : public Product {
    private:
        std::string brand;

    public:
        Food(const std::string& name, const double price, const int quantity,
             const std::string& brand);

        std::string getBrand() const;

        std::string getDescription() const override;
    };
}