#include <iostream>
#include <cassert>
#include <sstream>
#include "../Library/Product.h"
#include "../Library/Clothing.h"
#include "../Library/Shoes.h"
#include "../Library/Food.h"
#include "../Library/Toy.h"
#include "../Library/Department.h"
#include "../Library/Store.h"

class TestRunner {
public:
    void runAllTests() {
        testProduct();
        testClothing();
        testShoes();
        testFood();
        testToy();
        testDepartment();
        testStore();
        std::cout << "All tests passed!" << std::endl;
    }

private:
    void testProduct() {
        std::cout << "Running Product tests..." << std::endl;
        
        ChildrenStore::Product product("Test Product", 100.0, 10, "Test Department");
        assert(product.getName() == "Test Product");
        assert(product.getPrice() == 100.0);
        assert(product.getQuantity() == 10);
        assert(product.getDepartment() == "Test Department");
        
        bool exceptionThrown = false;
        try {
            ChildrenStore::Product badProduct("Test", -100.0, 10, "Department");
        } catch (const std::invalid_argument&) {
            exceptionThrown = true;
        }
        assert(exceptionThrown);
        
        double price1 = product.getDiscountPrice(1000.0, false);
        assert(price1 == 100.0);
        
        double price2 = product.getDiscountPrice(1000.0, true);
        assert(price2 == 90.0);
        
        double price3 = product.getDiscountPrice(6000.0, false);
        assert(price3 == 95.0);
        
        double price4 = product.getDiscountPrice(6000.0, true);
        assert(price4 == 85.0);
        
        product.setPrice(200.0);
        assert(product.getPrice() == 200.0);
        
        product.setQuantity(5);
        assert(product.getQuantity() == 5);
        
        std::string desc = product.getDescription();
        assert(desc.find("Test Product") != std::string::npos);
        assert(desc.find("200") != std::string::npos);
        
        std::cout << "Product tests passed!" << std::endl;
    }

    void testClothing() {
        std::cout << "Running Clothing tests..." << std::endl;
        
        ChildrenStore::Clothing clothing("Shirt", 500.0, 20, "104", "White", "Casual");
        assert(clothing.getName() == "Shirt");
        assert(clothing.getPrice() == 500.0);
        assert(clothing.getQuantity() == 20);
        assert(clothing.getDepartment() == "Clothing");
        assert(clothing.getSize() == "104");
        assert(clothing.getColor() == "White");
        assert(clothing.getStyle() == "Casual");
        
        assert(clothing.hasSizeColorStyle("104", "White", "Casual") == true);
        assert(clothing.hasSizeColorStyle("110", "White", "Casual") == false);
        assert(clothing.hasSizeColorStyle("104", "", "") == true);
        assert(clothing.hasSizeColorStyle("", "Black", "") == false);
        assert(clothing.hasSizeColorStyle("104", "White", "Sport") == false);
        
        ChildrenStore::Clothing clothingNoStock("Jacket", 1000.0, 0, "116", "Blue", "Winter");
        assert(clothingNoStock.hasSizeColorStyle("116", "Blue", "Winter") == false);
        
        std::string desc = clothing.getDescription();
        assert(desc.find("Shirt") != std::string::npos);
        assert(desc.find("104") != std::string::npos);
        assert(desc.find("White") != std::string::npos);
        assert(desc.find("Casual") != std::string::npos);
        
        std::cout << "Clothing tests passed!" << std::endl;
    }

    void testShoes() {
        std::cout << "Running Shoes tests..." << std::endl;
        
        ChildrenStore::Shoes shoes("Sneakers", 1800.0, 20, 28, "Red");
        assert(shoes.getName() == "Sneakers");
        assert(shoes.getPrice() == 1800.0);
        assert(shoes.getQuantity() == 20);
        assert(shoes.getDepartment() == "Shoes");
        assert(shoes.getSize() == 28);
        assert(shoes.getColor() == "Red");
        
        assert(shoes.hasSizeColor(28, "Red") == true);
        assert(shoes.hasSizeColor(30, "Red") == false);
        assert(shoes.hasSizeColor(28, "") == true);
        assert(shoes.hasSizeColor(0, "Blue") == false);
        assert(shoes.hasSizeColor(28, "Blue") == false);
        
        ChildrenStore::Shoes shoesNoStock("Boots", 2000.0, 0, 26, "Black");
        assert(shoesNoStock.hasSizeColor(26, "Black") == false);
        
        std::string desc = shoes.getDescription();
        assert(desc.find("Sneakers") != std::string::npos);
        assert(desc.find("28") != std::string::npos);
        assert(desc.find("Red") != std::string::npos);
        
        std::cout << "Shoes tests passed!" << std::endl;
    }

    void testFood() {
        std::cout << "Running Food tests..." << std::endl;
        
        ChildrenStore::Food food("Apple Puree", 120.0, 50, "Frutonyanya");
        assert(food.getName() == "Apple Puree");
        assert(food.getPrice() == 120.0);
        assert(food.getQuantity() == 50);
        assert(food.getDepartment() == "Food");
        assert(food.getBrand() == "Frutonyanya");
        
        std::string desc = food.getDescription();
        assert(desc.find("Apple Puree") != std::string::npos);
        assert(desc.find("Frutonyanya") != std::string::npos);
        assert(desc.find("120") != std::string::npos);
        
        std::cout << "Food tests passed!" << std::endl;
    }

    void testToy() {
        std::cout << "Running Toy tests..." << std::endl;
        
        ChildrenStore::Toy toy("LEGO Set", 2400.0, 15, "6+");
        assert(toy.getName() == "LEGO Set");
        assert(toy.getPrice() == 2400.0);
        assert(toy.getQuantity() == 15);
        assert(toy.getDepartment() == "Toys");
        assert(toy.getAgeRange() == "6+");
        
        std::string desc = toy.getDescription();
        assert(desc.find("LEGO Set") != std::string::npos);
        assert(desc.find("6+") != std::string::npos);
        assert(desc.find("2400") != std::string::npos);
        
        std::cout << "Toy tests passed!" << std::endl;
    }

    void testDepartment() {
        std::cout << "Running Department tests..." << std::endl;
        
        ChildrenStore::Department dept("Test Department");
        assert(dept.getName() == "Test Department");
        assert(dept.getAllProducts().empty());
        assert(dept.getTotalValue() == 0.0);
        
        auto product1 = std::make_unique<ChildrenStore::Product>("Item1", 100.0, 10, "Test Department");
        auto product2 = std::make_unique<ChildrenStore::Product>("Item2", 200.0, 5, "Test Department");
        
        dept.addProduct(std::move(product1));
        dept.addProduct(std::move(product2));
        
        assert(dept.getAllProducts().size() == 2);
        assert(dept.getTotalValue() == 100.0 * 10 + 200.0 * 5);
        
        auto found1 = dept.findProduct("Item1");
        assert(!found1.empty());
        assert(found1[0]->getName() == "Item1");
        
        auto found2 = dept.findProduct("Item");
        assert(found2.size() == 2);
        
        auto notFound = dept.findProduct("Nonexistent");
        assert(notFound.empty());
        
        std::cout << "Department tests passed!" << std::endl;
    }

    void testStore() {
        std::cout << "Running Store tests..." << std::endl;
        
        ChildrenStore::Store store;
        
        auto* dept = store.getDepartment("Clothing");
        assert(dept != nullptr);
        assert(dept->getName() == "Clothing");
        
        auto* notFoundDept = store.getDepartment("Nonexistent");
        assert(notFoundDept == nullptr);
        
        auto clothing = std::make_unique<ChildrenStore::Clothing>("Jacket", 2500.0, 10, "116", "Blue", "Winter");
        dept->addProduct(std::move(clothing));
        
        auto result = store.findProductDepartment("Jacket");
        assert(result.first != nullptr);
        assert(result.second != nullptr);
        assert(result.first->getName() == "Jacket");
        assert(result.second->getName() == "Clothing");
        
        auto notFoundResult = store.findProductDepartment("Nonexistent");
        assert(notFoundResult.first == nullptr);
        assert(notFoundResult.second == nullptr);
        
        auto products = store.getDepartmentProducts("Clothing");
        assert(!products.empty());
        
        auto emptyProducts = store.getDepartmentProducts("Nonexistent");
        assert(emptyProducts.empty());
        
        bool hasClothing = store.checkClothing("Jacket", "116", "Blue", "Winter");
        assert(hasClothing == true);
        
        bool wrongSize = store.checkClothing("Jacket", "130", "Blue", "Winter");
        assert(wrongSize == false);
        
        bool wrongColor = store.checkClothing("Jacket", "116", "Red", "Winter");
        assert(wrongColor == false);
        
        bool wrongStyle = store.checkClothing("Jacket", "116", "Blue", "Summer");
        assert(wrongStyle == false);
        
        bool notClothing = store.checkClothing("Nonexistent", "116", "Blue", "Winter");
        assert(notClothing == false);
        
        auto* shoesDept = store.getDepartment("Shoes");
        auto shoes = std::make_unique<ChildrenStore::Shoes>("Sneakers", 1800.0, 20, 28, "Red");
        shoesDept->addProduct(std::move(shoes));
        
        bool hasShoes = store.checkShoes("Sneakers", 28, "Red");
        assert(hasShoes == true);
        
        bool wrongShoeSize = store.checkShoes("Sneakers", 30, "Red");
        assert(wrongShoeSize == false);
        
        bool wrongShoeColor = store.checkShoes("Sneakers", 28, "Blue");
        assert(wrongShoeColor == false);
        
        store.addSale("Clothing", 15000.0);
        store.addSale("Clothing", 5000.0);
        
        double sales = store.getDepartmentSales("Clothing");
        assert(sales == 20000.0);
        
        double noSales = store.getDepartmentSales("Nonexistent");
        assert(noSales == 0.0);
        
        std::vector<std::pair<ChildrenStore::Product*, int>> purchase;
        auto foundProducts = dept->findProduct("Jacket");
        if (!foundProducts.empty()) {
            purchase.push_back({foundProducts[0], 2});
        }
        
        double regularPrice = store.calculatePurchase(purchase, false);
        assert(regularPrice > 0);
        
        double discountPrice = store.calculatePurchase(purchase, true);
        assert(discountPrice < regularPrice);
        
        std::cout << "Store tests passed!" << std::endl;
    }
};

int main() {
    try {
        TestRunner runner;
        runner.runAllTests();
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
        return 1;
    }
}