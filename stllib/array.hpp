#ifndef ARRAY_HPP
#define ARRAY_HPP

#include<iostream>

namespace stl {
    template<typename T, size_t array_size>
    class Array {
        T arr[array_size];
        size_t _size = array_size;
    public:
        int size();

        Array(const std::initializer_list<T> &l);

        bool empty();

        Array &operator=(const Array<T, array_size> &other);

        T &operator[](int index);
    };
}

#include "array.tpp"

#endif