#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../Library/Matrix.h"
#include "../Library/RandomGenerator.h"
#include "../Library/IStreamGenerator.h"
#include "../Library/Task1.h"
#include "../Library/Task2.h"
#include "../Library/Task3.h"


int main()
{
    srand(time(0));
    
    std::cout << "Enter array size: ";
    size_t size;
    std::cin >> size;
    
    if (size <= 0)
    {
        std::cout << "Size must be greater than 0" << std::endl;
        return 1;
    }
    
    algebra::Matrix<int> array(size);
    
    std::cout << "Choose fill method (0 - manual, 1 - random): ";
    int choice;
    std::cin >> choice;
    
    algebra::Generator* generator = nullptr;
    
    if (choice == 0)
    {
        std::cout << "Enter " << size << " numbers:" << std::endl;
        array.manual_fill();
        generator = new algebra::IStreamGenerator();
    }
    else if (choice == 1)
    {
        std::cout << "Enter min value: ";
        int min;
        std::cin >> min;
        
        std::cout << "Enter max value: ";
        int max;
        std::cin >> max;
        
        if (min > max)
        {
            std::cout << "Invalid range" << std::endl;
            return 1;
        }
        
        array.random_fill(min, max);
        generator = new algebra::RandomGenerator(min, max);
    }
    else
    {
        std::cout << "Invalid choice" << std::endl;
        return 1;
    }
    
    std::cout << "Original array: " << array.to_string() << std::endl;
    

    algebra::Task1 task1(array, generator);
    algebra::Matrix<int> task1_result = task1.executeTask1();
    std::cout << "Task 1 result: " << task1_result.to_string() << std::endl;
    

    algebra::Task2 task2(array, generator);
    algebra::Matrix<int> task2_result = task2.executeTask2();
    std::cout << "Task 2 result: " << task2_result.to_string() << std::endl;
    

    algebra::Task3 task3(array);
    algebra::Matrix<int> task3_result = task3.execute();
    std::cout << "Task 3 result: " << task3_result.to_string() << std::endl;
    

    delete generator;
    
    return 0;
}