#pragma once
#include "Product.h"

namespace ChildrenStore {
    class Toy : public Product {
    private:
        std::string ageRange;

    public:
        Toy(const std::string& name, const double price, const int quantity,
            const std::string& ageRange);

        std::string getAgeRange() const;

        std::string getDescription() const override;
    };
}