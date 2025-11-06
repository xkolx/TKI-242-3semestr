#pragma once
#include <cstddef>
#include <string>
#include <sstream>
#include <iostream>

namespace algebra 
{

template<typename T>
class Matrix
{
private:
    T* data;
    size_t size_val;
public:
    Matrix() : data(nullptr), size_val(0) {}
    
    Matrix(size_t size) : size_val(size)
    {
        data = new T[size];
        for (size_t i = 0; i < size; i++)
        {
            data[i] = 0;
        }
    }
    
    Matrix(const Matrix& other) : size_val(other.size_val)
    {
        data = new T[size_val];
        for (size_t i = 0; i < size_val; i++)
        {
            data[i] = other.data[i];
        }
    }
    
    ~Matrix()
    {
        delete[] data;
    }
    
    T& operator[](size_t index)
    {
        return data[index];
    }
    
    const T& operator[](size_t index) const
    {
        return data[index];
    }
    
    size_t size() const
    {
        return size_val;
    }
    
    std::string to_string() const
    {
        std::stringstream ss;
        ss << "{ ";
        for (size_t i = 0; i < size_val; i++)
        {
            ss << data[i];
            if (i < size_val - 1)
            {
                ss << ", ";
            }
        }
        ss << " }";
        return ss.str();
    }
    
    void manual_fill()
    {
        for (size_t i = 0; i < size_val; i++)
        {
            std::cout << "Enter element " << i + 1 << ": ";
            std::cin >> data[i];
        }
    }

    void random_fill(int min, int max)
    {
        for (size_t i = 0; i < size_val; i++)
        {
            data[i] = min + rand() % (max - min + 1);
        }
    }
};

}