/*
* array (статический массив) и методы для него:
    size (возвращает размер)
    empty (возвращает true если пустой)
    взятие по индексу (operator[])
    присваивание копированием
    конструкторы (конструктор с std::inizialized_list)
*/

#ifndef ARRAYLIB
#define ARRAYLIB

#include <iostream>

template<typename T, size_t aSize>
class Array{
    
    T array[aSize];
    size_t arraySize = aSize;

    public: 

    Array( const std::initializer_list<T> &init_list);
    Array& operator=(const Array<T, aSize> &other_array);
    
    size_t size();
    
    bool empty();
    
    T& operator[](int index);
};

#include "array.tpp"
#endif
