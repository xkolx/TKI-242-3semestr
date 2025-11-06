#pragma once
#include "Matrix.h"
#include <cmath>

namespace algebra {

class Task3
{
private:
    Matrix<int> matrix;
    
public:
    Task3(const Matrix<int>& m) : matrix(m) {}
    
    Matrix<int> execute();
};

}