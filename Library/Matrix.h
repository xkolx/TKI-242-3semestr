#pragma once
#include <cstddef>
#include <string>
#include <sstream>
#include <iostream>
#include "Generator.h"

namespace algebra 
{
    template<typename T>
    class Matrix
    {
    private:
        T* data;
        size_t size_val;
    public:
        Matrix();
        Matrix(size_t size);
        Matrix(const Matrix& other);
        ~Matrix();
        
        T& operator[](size_t index);
        const T& operator[](size_t index) const;
        
        size_t size() const;
        std::string to_string() const;
        
        void fill(Generator& gen);
    };
}