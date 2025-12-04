#include "Store.h"
#include <algorithm>
#include "Clothing.h"
#include "Shoes.h"

namespace ChildrenStore {
    Store::Store() {
        addDepartment(std::make_unique<Department>("Clothing"));
        addDepartment(std::make_unique<Department>("Shoes"));
        addDepartment(std::make_unique<Department>("Food"));
        addDepartment(std::make_unique<Department>("Toys"));
        addDepartment(std::make_unique<Department>("Stationery"));
        addDepartment(std::make_unique<Department>("Hygiene"));
    }

    void Store::addDepartment(std::unique_ptr<Department> department) {
        departments.push_back(std::move(department));
    }

    Department* Store::getDepartment(const std::string& name) const {
        for (const auto& dept : departments) {
            if (dept->getName() == name) {
                return dept.get();
            }
        }
        return nullptr;
    }

    std::pair<Product*, Department*> Store::findProductDepartment(const std::string& productName) const {
        for (const auto& department : departments) {
            auto products = department->findProduct(productName);
            if (!products.empty()) {
                return {products[0], department.get()};
            }
        }
        return {nullptr, nullptr};
    }

    std::vector<std::string> Store::getDepartmentProducts(const std::string& departmentName) const {
        auto* dept = getDepartment(departmentName);
        if (dept) {
            return dept->getAllProducts();
        }
        return {};
    }

    double Store::getDepartmentSales(const std::string& departmentName) const {
        auto it = sales.find(departmentName);
        if (it != sales.end()) {
            return it->second;
        }
        return 0.0;
    }

    double Store::calculatePurchase(const std::vector<std::pair<Product*, int>>& items,
                                    bool isRegularCustomer) const {
        double total = 0.0;
        
        for (const auto& item : items) {
            total += item.first->getPrice() * item.second;
        }
        
        double finalTotal = 0.0;
        for (const auto& item : items) {
            double priceWithDiscount = item.first->getDiscountPrice(total, isRegularCustomer);
            finalTotal += priceWithDiscount * item.second;
        }
        
        return finalTotal;
    }

    bool Store::checkClothing(const std::string& productName,
                              const std::string& size,
                              const std::string& color,
                              const std::string& style) const {
        auto result = findProductDepartment(productName);
        if (result.first && result.second && result.second->getName() == "Clothing") {
            auto* clothing = dynamic_cast<Clothing*>(result.first);
            if (clothing) {
                return clothing->hasSizeColorStyle(size, color, style);
            }
        }
        return false;
    }

    bool Store::checkShoes(const std::string& productName,
                           int size,
                           const std::string& color) const {
        auto result = findProductDepartment(productName);
        if (result.first && result.second && result.second->getName() == "Shoes") {
            auto* shoes = dynamic_cast<Shoes*>(result.first);
            if (shoes) {
                return shoes->hasSizeColor(size, color);
            }
        }
        return false;
    }

    void Store::addSale(const std::string& departmentName, double amount) {
        sales[departmentName] += amount;
    }
}