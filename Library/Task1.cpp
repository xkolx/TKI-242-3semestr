#include "Task1.h"
#include <iostream>

namespace algebra 
{
    size_t findLastMultipleOf3(const Matrix<int>& matrix)
    {
        for (size_t i = matrix.size(); i-- > 0;)
        {
            if (matrix[i] % 3 == 0 && matrix[i] != 0)
            {
                return i;
            }
        }
        return matrix.size();
    }
    
    void Task1::execute()
    {
        Matrix<int> result = matrix;
        size_t last_index = findLastMultipleOf3(matrix);
        
        if (last_index < matrix.size())
        {
            result[last_index] = 0;
            std::cout << "Task 1 result: " << result.to_string() << std::endl;
            std::cout << "Replaced element at position " << last_index + 1 
                      << " (value: " << matrix[last_index] << ") with 0" << std::endl;
        }
        else
        {
            std::cout << "Task 1 result: " << result.to_string() << std::endl;
            std::cout << "No elements divisible by 3 found" << std::endl;
        }
    }
}