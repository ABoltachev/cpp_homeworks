#pragma once

#include <iostream>

#include "../array/array.h"
#include "../vector/vector.h"
#include "../set/set.h"

namespace algorithms {
    template<class T, size_t N>
    void sort(cnt::array<T, N> &array) noexcept;

    template<class T, size_t N>
    T max(const cnt::array<T, N> &array);

    template<class T, size_t N>
    T min(const cnt::array<T, N> &array);

    template<class T, size_t N>
    T &find(cnt::array<T, N> &array, const T &el);


    template<class T>
    void sort(cnt::vector<T> &vector) noexcept;

    template<class T>
    T max(cnt::vector<T> &vector);

    template<class T>
    T min(cnt::vector<T> &vector);

    template<class T>
    T& find(cnt::vector<T> &vector, const T &el);


    template<typename T>
    T min(cnt::set<T>& set);

    template<typename T>
    T max(cnt::set<T>& set);
}

#include "algorithms.tpp"
