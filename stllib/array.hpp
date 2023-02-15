//
// Created by home on 09.02.23.
//

#ifndef UNTITLED15_ARRAY_HPP
#define UNTITLED15_ARRAY_HPP
#include<iostream>
template<typename T, size_t len>
class Array{
    T arr[len];
    size_t m_size = len;
public:
    int size();
    Array(const std::initializer_list<T>& l);
    bool empty();
    Array& operator=(const Array<T, len>& other);
    T& operator[](int index);
};

#include "../array.tpp"
#endif //UNTITLED15_ARRAY_HPP
