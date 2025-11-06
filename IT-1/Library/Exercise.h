#pragma once
#include "Matrix.h"
#include "Generator.h"

namespace algebra {

class Exercise
{
protected:
    Matrix<int> matrix;
    Generator* generator;
    
public:
    Exercise(const Matrix<int>& m, Generator* gen);
    virtual ~Exercise();
    
    virtual Matrix<int> executeTask1() { return matrix; }
    virtual Matrix<int> executeTask2() { return matrix; }
    
    Matrix<int> getMatrix() const;
};

}