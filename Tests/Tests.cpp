#include <iostream>
#include <cassert>
#include <sstream>
#include "../Library/Matrix.h"
#include "../Library/ConstantGenerator.h"
#include "../Library/Task1.h"
#include "../Library/Task2.h"
#include "../Library/Task3.h"

namespace algebra {
    size_t findLastMultipleOf3(const Matrix<int>& matrix);
}

class TestRunner {
public:
    void runAllTests() {
        testMatrix();
        testConstantGenerator();
        testTask1();
        testTask2();
        testTask3();
        std::cout << "All tests passed!" << std::endl;
    }

private:
    void testMatrix() {
        std::cout << "Running Matrix tests..." << std::endl;
        
        algebra::Matrix<int> matrix1;
        assert(matrix1.size() == 0);
        
        algebra::Matrix<int> matrix2(3);
        assert(matrix2.size() == 3);
        
        matrix2[0] = 10;
        matrix2[1] = 20;
        matrix2[2] = 30;
        assert(matrix2[0] == 10);
        assert(matrix2[1] == 20);
        assert(matrix2[2] == 30);
        
        std::string str = matrix2.to_string();
        assert(str == "{ 10, 20, 30 }");
        
        std::cout << "Matrix tests passed!" << std::endl;
    }

    void testConstantGenerator() {
        std::cout << "Running ConstantGenerator tests..." << std::endl;
        
        algebra::ConstantGenerator gen2(algebra::RANDOM, 1, 10);
        int value = gen2.generate();
        assert(value >= 1 && value <= 10);
        
        std::cout << "ConstantGenerator tests passed!" << std::endl;
    }

    void testTask1() {
        std::cout << "Running Task1 tests..." << std::endl;
        
        algebra::Matrix<int> matrix(3);
        matrix[0] = 3;
        matrix[1] = 4;
        matrix[2] = 6;
        
        size_t last_index = algebra::findLastMultipleOf3(matrix);
        assert(last_index == 2);
        
        algebra::ConstantGenerator dummyGen(algebra::MANUAL);
        algebra::Task1 task1(matrix, &dummyGen);
        
        std::ostringstream output;
        auto oldCout = std::cout.rdbuf(output.rdbuf());
        task1.execute();
        std::cout.rdbuf(oldCout);
        
        std::string result = output.str();
        assert(result.find("Task 1 result: { 3, 4, 0 }") != std::string::npos);
        
        std::cout << "Task1 tests passed!" << std::endl;
    }

    void testTask2() {
        std::cout << "Running Task2 tests..." << std::endl;
        
        algebra::Matrix<int> matrix(3);
        matrix[0] = 1;
        matrix[1] = 2;
        matrix[2] = 3;
        
        std::istringstream input("99");
        auto oldCin = std::cin.rdbuf(input.rdbuf());
        
        std::ostringstream output;
        auto oldCout = std::cout.rdbuf(output.rdbuf());
        
        algebra::ConstantGenerator dummyGen(algebra::MANUAL);
        algebra::Task2 task2(matrix, &dummyGen);
        task2.execute();
        
        std::cin.rdbuf(oldCin);
        std::cout.rdbuf(oldCout);
        
        std::string result = output.str();
        assert(result.find("Task 2 result: { 1, 2, 99, 3 }") != std::string::npos);
        
        std::cout << "Task2 tests passed!" << std::endl;
    }

    void testTask3() {
        std::cout << "Running Task3 tests..." << std::endl;
        
        algebra::Matrix<int> matrix(3);
        matrix[0] = 2;
        matrix[1] = 3;
        matrix[2] = 4;
        
        std::ostringstream output;
        auto oldCout = std::cout.rdbuf(output.rdbuf());
        
        algebra::ConstantGenerator dummyGen(algebra::MANUAL);
        algebra::Task3 task3(matrix, &dummyGen);
        task3.execute();
        
        std::cout.rdbuf(oldCout);
        
        std::string result = output.str();
        assert(result.find("Task 3 result: { 0, -6, 0 }") != std::string::npos);
        
        std::cout << "Task3 tests passed!" << std::endl;
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