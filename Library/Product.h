#pragma once
#include <string>

namespace ChildrenStore {
    class Product {
    protected:
        std::string name;
        double price;
        int quantity;
        std::string department;

    public:
        Product(const std::string& name, const double price, const int quantity, const std::string& department);
        virtual ~Product() = default;

        std::string getName() const;
        double getPrice() const;
        int getQuantity() const;
        std::string getDepartment() const;

        void setPrice(const double newPrice);
        void setQuantity(const int newQuantity);

        virtual double getDiscountPrice(double totalPurchase, bool isRegularCustomer) const;
        virtual std::string getDescription() const = 0;
    };
}