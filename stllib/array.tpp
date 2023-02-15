#pragma once

#include "array.hpp"
#include <exception>

namespace stl {

    template<typename T, size_t array_size>
    bool Array<T, array_size>::empty() {
        return array_size == 0;
    }

    template<typename T, size_t array_size>
    Array<T, array_size> &Array<T, array_size>::operator=(const Array<T, array_size> &other) {
        for (int index = 0; index < _size; index++) {
            arr[index] = other.arr[index];
        }
        return *this;
    }

    template<typename T, size_t array_size>
    T &Array<T, array_size>::operator[](int index) {
        if (index >= _size)
            throw std::out_of_range("List out of range");
        return arr[index];
    }

    template<typename T, size_t array_size>
    Array<T, array_size>::Array(const std::initializer_list<T> &l) {
        for (int i = 0; i < l.size(); ++i) {
            arr[i] = l[i];
        }
    }

    template<typename T, size_t array_size>
    int Array<T, array_size>::size() {
        return _size;
    }

}