#include "Task2.h"
#include <iostream>

namespace algebra 
{
    void Task2::execute()
    {
        int count_even = 0;
        for (size_t i = 0; i < matrix.size(); i++)
        {
            if (matrix[i] % 2 == 0)
            {
                count_even++;
            }
        }
        
        Matrix<int> result(matrix.size() + count_even);
        
        std::cout << "Enter number K: ";
        int K = 0;
        std::cin >> K;
        
        size_t j = 0;
        for (size_t i = 0; i < matrix.size(); i++)
        {
            result[j] = matrix[i];
            j++;
            
            if (matrix[i] % 2 == 0)
            {
                result[j] = K;
                j++;
            }
        }
        
        std::cout << "Task 2 result: " << result.to_string() << std::endl;
    }
}