#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <stdexcept>

namespace lib
{

template <typename T, size_t _size>
class Array
{
   private:
    T m_array[_size];
    size_t m_size = _size;

    void checkSize(size_t size) const;
    void checkIndex(size_t index) const;
    void fillArray(const T& data);

   public:
    Array();

    Array(std::initializer_list<T> list);

    Array(const Array& arr);
    Array(Array&& arr);

    Array& operator=(const Array& array);
    Array& operator=(Array&& array);

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    size_t size() const;
    bool empty() const;
};

}  // namespace lib

#include "array.tpp"

#endif