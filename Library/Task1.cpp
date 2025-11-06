#include "Task1.h"
#include <iostream>

namespace algebra {

Matrix<int> Task1::executeTask1()
{
    Matrix<int> result = matrix;
    bool found = false;
    int last_index = -1;
    
    for (int i = result.size() - 1; i >= 0; i--)
    {
        if (result[i] % 3 == 0 && result[i] != 0)
        {
            last_index = i;
            found = true;
            break;
        }
    }
    
    if (found)
    {
        result[last_index] = 0;
        std::cout << "Replaced element at position " << last_index + 1 
                  << " (value: " << matrix[last_index] << ") with 0" << std::endl;
    }
    else
    {
        std::cout << "No elements divisible by 3 found" << std::endl;
    }
    
    return result;
}

}