/*
* array (статический массив) и методы для него:
    size (возвращает размер)
    empty (возвращает true если пустой)
    взятие по индексу (operator[])
    присваивание копированием
    конструкторы (конструктор с std::inizialized_list)
*/
/*
* array (статический массив) и методы для него:
    size (возвращает размер)
    empty (возвращает true если пустой)
    взятие по индексу (operator[])
    присваивание копированием
    конструкторы (конструктор с std::inizialized_list)
*/
#ifndef SHABLON_ARRAY_H
#define SHABLON_ARRAY_H
#include<iostream>


template <typename T, size_t arr_size>
class Array
{
    T m_arr[arr_size];
    size_t m_size = arr_size;
public:
    Array();
    Array(const Array& arr_);
    size_t size() const;
    bool empty() const;
    T& operator[](size_t& ind);
    const T& operator[](size_t& ind) const;

    Array& operator=(const Array<T, arr_size>& arr);
    Array& operator=(Array<T, arr_size>&& arr);

    ~Array();
};

#include "array.tpp"

#endif //SHABLON_ARRAY_H
