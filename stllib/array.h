#include<iostream>


template <typename T, size_t arr_size>
class Array
{
    T arr[arr_size];
    size_t SIZE = arr_size;
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
