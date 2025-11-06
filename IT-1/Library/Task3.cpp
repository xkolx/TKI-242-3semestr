#include "Task3.h"

namespace algebra {

Matrix<int> Task3::execute()
{
    Matrix<int> result(matrix.size());
    
    for (size_t i = 0; i < matrix.size(); i++)
    {
        if (i == 0 || i == matrix.size() - 1)
        {
            result[i] = 0;
        }
        else if ((i + 1) % 4 == 0)
        {
            result[i] = 4 * abs(matrix[i]);
        }
        else
        {
            result[i] = -matrix[i] * (i + 1);
        }
    }
    
    return result;
}

}