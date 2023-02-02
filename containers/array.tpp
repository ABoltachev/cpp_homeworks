#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "array.hpp"

namespace lib
{
template <typename T, size_t _size>
void Array<T, _size>::checkSize(size_t size) const
{
    if (size > m_size) {
        throw std::length_error("Size of passed array is too long");
    }
}

template <typename T, size_t _size>
Array<T, _size>::Array() : m_size(_size)
{
    for (size_t i = 0; i < _size; i++) {
        m_array[i] = 0;
    }
}

template <typename T, size_t _size>
Array<T, _size>::Array(std::initializer_list<T> list) : Array()
{
    checkSize(list.size());
    auto it = list.begin();
    for (size_t i = 0; i < list.size(); i++) {
        m_array[i] = *(it + i);
    }
}

template <typename T, size_t _size>
Array<T, _size>::Array(const Array<T, _size>& arr)
{
    if (&arr == this) {
        return;
    }

    m_size = arr.m_size;
    for (size_t i = 0; i < arr.m_size; i++) {
        m_array[i] = arr.m_array[i];
    }
}

template <typename T, size_t _size>
Array<T, _size>::Array(Array<T, _size>&& arr)
{
    if (&arr == this) {
        return;
    }

    m_size = arr.m_size;
    for (size_t i = 0; i < arr.m_size; i++) {
        m_array[i] = arr.m_array[i];
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

}  // namespace lib

#endif