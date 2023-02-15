#ifndef SHABLON_ARRAY_TPP
#define SHABLON_ARRAY_TPP
#include <exception>
#include "array.h"

template<typename T, size_t arr_size>
Array<T, arr_size>::Array() : m_size(arr_size) {
    for (size_t i = 0; i < arr_size; ++i) m_arr[i] = 0;
}

template<typename T, size_t arr_size>
Array<T, arr_size>::Array(const Array<T, arr_size> &new_arr) {
    if (&new_arr == this) {
        return;
    }
    m_size = new_arr.m_size;

    for (size_t i = 0; i < new_arr.m_size; ++i) {
        m_arr[i] = new_arr.m_arr[i];
    }
}

template <typename T, size_t arr_size>
size_t Array<T, arr_size>::size() const {
    return arr_size;
}

template <typename T, size_t arr_size>
bool Array<T, arr_size>::empty() const {
    return (arr_size==0);
}

template<typename T, size_t arr_size>
T& Array<T,arr_size>::operator[](size_t& ind) {
    if ((ind < 0) || (ind >= m_size))
        throw std::out_of_range("List out of range");
    return m_arr[ind];
}

template<typename T, size_t arr_size>
const T& Array<T,arr_size>::operator[](size_t& ind) const {
    if (ind >= m_size)
        throw std::out_of_range("List out of range");
    return m_arr[ind];
}

template <typename T, size_t arr_size>
Array<T, arr_size> &Array<T, arr_size>::operator=(const Array<T, arr_size> &arr) {
    if (&arr != this) {
        for (int i = 0; i < m_size; ++i) {
            m_arr[i] = arr.m_arr[i];
        }
    }

    return *this;
}

template <typename T, size_t arr_size>
Array<T, arr_size> &Array<T, arr_size>::operator=(Array<T, arr_size> &&arr) {
    if (&arr != this) {
        for (int i = 0; i < m_size; ++i) {
            m_arr[i] = arr.m_arr[i];
        }
    }

    return *this;
}

template <typename T, size_t arr_size>
Array<T, arr_size>::~Array() {
    delete[] m_arr;
}
#endif