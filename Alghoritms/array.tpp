#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "array.hpp"

namespace algs
{

template <typename T, size_t _size>
Array<T, _size>::Array(std::initializer_list<T> list)
{
    if (list.size() > _size) {
        throw std::length_error("Initializer list is too long");
    }

    auto it = list.begin();
    for (size_t i = 0; i < list.size(); i++) {
        m_array[i] = *(it + i);
    }
}

template <typename T, size_t _size>
void Array<T, _size>::checkIndex(size_t index) const
{
    if (index < 0 || index >= m_size) {
        throw std::out_of_range("Index is out of range");
    }
}

template <typename T, size_t _size>
T& Array<T, _size>::operator[](size_t index)
{
    checkIndex(index);
    return m_array[index];
}

template <typename T, size_t _size>
const T& Array<T, _size>::operator[](size_t index) const
{
    checkIndex(index);
    return m_array[index];
}

template <typename T, size_t _size>
size_t Array<T, _size>::size() const
{
    return m_size;
}

template <typename T, size_t _size>
bool Array<T, _size>::empty() const
{
    return m_size == 0;
}

}  // namespace algs

#endif