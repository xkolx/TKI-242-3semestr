#include <iostream>
#include <vector>
#include <memory>
#include "..\Library\Product.h"
#include "..\Library\Clothing.h"
#include "..\Library\Shoes.h"
#include "..\Library\Food.h"
#include "..\Library\Toy.h"
#include "..\Library\Store.h"

using namespace ChildrenStore;

int main() {
    std::cout << "Children's Store\n\n";

    Store store;

    auto* clothingDept = store.getDepartment("Clothing");
    auto* shoesDept = store.getDepartment("Shoes");
    auto* foodDept = store.getDepartment("Food");
    auto* toysDept = store.getDepartment("Toys");

    clothingDept->addProduct(std::make_unique<Clothing>("Jacket", 2500, 10, "116", "Blue", "Winter"));
    clothingDept->addProduct(std::make_unique<Clothing>("T-Shirt", 800, 25, "104", "White", "Casual"));
    clothingDept->addProduct(std::make_unique<Clothing>("Pants", 1200, 15, "110", "Black", "School"));

    shoesDept->addProduct(std::make_unique<Shoes>("Sneakers", 1800, 20, 28, "Red"));
    shoesDept->addProduct(std::make_unique<Shoes>("Boots", 3200, 8, 26, "Black"));
    shoesDept->addProduct(std::make_unique<Shoes>("Sandals", 1500, 12, 24, "White"));

    foodDept->addProduct(std::make_unique<Food>("Apple Puree", 120, 50, "Frutonyanya"));
    foodDept->addProduct(std::make_unique<Food>("Milk Formula", 850, 30, "Nutrilon"));
    foodDept->addProduct(std::make_unique<Food>("Cookies", 95, 100, "Heinz"));

    toysDept->addProduct(std::make_unique<Toy>("LEGO Set", 2400, 15, "6+"));
    toysDept->addProduct(std::make_unique<Toy>("Teddy Bear", 600, 40, "0+"));
    toysDept->addProduct(std::make_unique<Toy>("Puzzle", 350, 25, "3+"));

    std::vector<std::unique_ptr<Product>> products;
    
    products.push_back(std::make_unique<Clothing>("Dress", 1800, 8, "98", "Pink", "Party"));
    products.push_back(std::make_unique<Shoes>("Shoes", 2100, 6, 25, "Black"));
    products.push_back(std::make_unique<Food>("Juice", 85, 60, "Agusha"));
    products.push_back(std::make_unique<Toy>("Drawing Set", 450, 20, "4+"));

    std::cout << "Different products:\n";
    for (const auto& product : products) {
        std::cout << product->getDescription() << "\n";
    }
    std::cout << "\n";

    std::cout << "Search product 'jacket':\n";
    auto result = store.findProductDepartment("jacket");
    if (result.first && result.second) {
        std::cout << "Product: " << result.first->getName() << "\n";
        std::cout << "Department: " << result.second->getName() << "\n";
    }
    std::cout << "\n";

    std::cout << "Products in 'Clothing' department:\n";
    auto productsList = store.getDepartmentProducts("Clothing");
    for (const auto& product : productsList) {
        std::cout << product << "\n";
    }
    std::cout << "\n";

    store.addSale("Clothing", 15000);
    store.addSale("Shoes", 22000);
    store.addSale("Toys", 8500);
    
    std::cout << "Sales by department:\n";
    std::cout << "Clothing: " << store.getDepartmentSales("Clothing") << "\n";
    std::cout << "Shoes: " << store.getDepartmentSales("Shoes") << "\n";
    std::cout << "Toys: " << store.getDepartmentSales("Toys") << "\n";
    std::cout << "\n";

    std::vector<std::pair<Product*, int>> purchase;
    auto allProducts = clothingDept->findProduct("Jacket");
    if (!allProducts.empty()) {
        purchase.push_back({allProducts[0], 1});
    }
    
    auto shoesProducts = shoesDept->findProduct("Sneakers");
    if (!shoesProducts.empty()) {
        purchase.push_back({shoesProducts[0], 1});
    }
    
    std::cout << "Purchase price:\n";
    std::cout << "Regular customer: " << store.calculatePurchase(purchase, false) << "\n";
    std::cout << "Regular customer with discount: " << store.calculatePurchase(purchase, true) << "\n";
    std::cout << "\n";

    std::cout << "Availability check:\n";
    bool hasClothing = store.checkClothing("Jacket", "116", "Blue", "Winter");
    std::cout << "Jacket size 116 blue: " << (hasClothing ? "Available" : "Not available") << "\n";
    
    bool hasShoes = store.checkShoes("Sneakers", 28, "Red");
    std::cout << "Sneakers size 28 red: " << (hasShoes ? "Available" : "Not available") << "\n";

    return 0;
}