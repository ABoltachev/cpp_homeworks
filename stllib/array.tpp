#ifndef SHABLON_ARRAY_TPP
#define SHABLON_ARRAY_TPP
#include <exception>
#include "array.h"

template<typename T, size_t arr_size>
Array<T, arr_size>::Array() : SIZE(arr_size) {
    for (size_t i = 0; i < arr_size; ++i)
    {
        arr[i] = 0
    };
}

template<typename T, size_t arr_size>
Array<T, arr_size>::Array(const Array<T, arr_size>& narr) {
    if (&narr == this)
    {return;}
    SIZE = narr.SIZE;

    for (size_t i = 0; i < narr.SIZE; ++i) {
        arr[i] = narr.arr[i];
    }
}

template <typename T, size_t arr_size>
size_t Array<T, arr_size>::size() const
{
    return arr_size;
}

template <typename T, size_t arr_size>
bool Array<T, arr_size>::empty() const {
    return (arr_size == 0);
}

template<typename T, size_t arr_size>
T& Array<T, arr_size>::operator[](size_t& i) {
    if ((i < 0) || (ind >= SIZE))
    {
        cout<<"Out of range.";
    }
    else
    {
        return arr[i];
    }
}

template<typename T, size_t arr_size>
const T& Array<T, arr_size>::operator[](size_t& i) const {
    if (i >= SIZE)
    {
        cout<<"Out of range.";
    }
    else {
        return arr[i];
    };
}

template <typename T, size_t arr_size>
Array<T, arr_size>& Array<T, arr_size>::operator=(const Array<T, arr_size>& narr) {
    if (&arr != this) {
        for (int i = 0; i < SIZE; ++i) {
            arr[i] = arr.narr[i];
        }
    }

    return *this;
}

template <typename T, size_t arr_size>
Array<T, arr_size>& Array<T, arr_size>::operator=(Array<T, arr_size>&& narr) {
    if (&arr != this) {
        for (int i = 0; i < SIZE; ++i) {
            arr[i] = arr.narr[i];
        }
    }

    return *this;
}

template <typename T, size_t arr_size>
Array<T, arr_size>::~Array() {
    delete[] arr;
}
#endif