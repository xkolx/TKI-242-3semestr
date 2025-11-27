#include "Matrix.h"
#include <sstream>

namespace algebra 
{
    template<typename T>
    Matrix<T>::Matrix() : data(nullptr), size_val(0) {}

    template<typename T>
    Matrix<T>::Matrix(size_t size) : size_val(size)
    {
        data = new T[size];
        for (size_t i = 0; i < size; i++)
        {
            data[i] = 0;
        }
    }

    template<typename T>
    Matrix<T>::Matrix(const Matrix& other) : size_val(other.size_val)
    {
        data = new T[size_val];
        for (size_t i = 0; i < size_val; i++)
        {
            data[i] = other.data[i];
        }
    }

    template<typename T>
    Matrix<T>::~Matrix()
    {
        delete[] data;
    }

    template<typename T>
    T& Matrix<T>::operator[](size_t index)
    {
        return data[index];
    }

    template<typename T>
    const T& Matrix<T>::operator[](size_t index) const
    {
        return data[index];
    }

    template<typename T>
    size_t Matrix<T>::size() const
    {
        return size_val;
    }

    template<typename T>
    std::string Matrix<T>::to_string() const
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

    template<typename T>
    void Matrix<T>::fill(Generator& gen)
    {
        for (size_t i = 0; i < size_val; i++)
        {
            data[i] = gen.generate();
        }
    }

    template class Matrix<int>;
}