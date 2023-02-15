#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <exception>
#include "MyArray.hpp"
#include "MyVector.hpp"
#include "MySet.hpp"

namespace MyStdLib {

    template <typename T, size_t arr_size>
    MyArray<T, arr_size>& sort(MyArray<T, arr_size>& array);

    template <typename T, size_t arr_size>
    T& min(MyArray<T, arr_size>& array);

    template <typename T, size_t arr_size>
    T& max(MyArray<T, arr_size>& array);

    template <typename T, size_t arr_size>
    T& find(MyArray<T, arr_size>& array, const T& value);

    // ---------- MyVector ----------

    template <typename T>
    MyVector<T>& sort(MyVector<T>& vector);

    template <typename T>
    T& min(MyVector<T>& vector);

    template <typename T>
    T& max(MyVector<T>& vector);

    template <typename T>
    T& find(MyVector<T>& vector);

    // ---------- MySet ----------

    template <typename T>
    T& min(MySet<T>& set);

    template <typename T>
    T& max(MySet<T>& set);

    template <typename T>
    T& find(MySet<T>& set);
}

#include "algorithm.tpp"

#endif