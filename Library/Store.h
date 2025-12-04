#pragma once
#include "Department.h"
#include <vector>
#include <memory>
#include <map>

namespace ChildrenStore {
    class Store {
    private:
        std::vector<std::unique_ptr<Department>> departments;
        std::map<std::string, double> sales;

    public:
        Store();

        void addDepartment(std::unique_ptr<Department> department);
        Department* getDepartment(const std::string& name) const;
        
        std::pair<Product*, Department*> findProductDepartment(const std::string& productName) const;
        std::vector<std::string> getDepartmentProducts(const std::string& departmentName) const;
        double getDepartmentSales(const std::string& departmentName) const;
        double calculatePurchase(const std::vector<std::pair<Product*, int>>& items,
                                 bool isRegularCustomer) const;
        
        bool checkClothing(const std::string& productName,
                           const std::string& size,
                           const std::string& color,
                           const std::string& style) const;
        
        bool checkShoes(const std::string& productName,
                        int size,
                        const std::string& color) const;
        
        void addSale(const std::string& departmentName, double amount);
    };
}