#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <stdexcept>

namespace algs
{

template <typename T, size_t _size>
class Array
{
   private:
    T m_array[_size];
    size_t m_size = _size;
    void checkIndex(size_t index) const;

   public:
    Array() = default;

    Array(const Array& arr);
    Array(Array&& arr);

    Array(std::initializer_list<T> list);

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    size_t size() const;
    bool empty() const;
};

}  // namespace algs

#include "array.tpp"

#endif