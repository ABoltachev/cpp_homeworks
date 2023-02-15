#pragma once

#include "vector.h"
#include "set.h"
#include "array.h"

#include <iostream>

namespace algo {
    template<typename T>
    const T& max(const container::vector<T> &object);


    template<typename T, size_t size>
    const T& max(const container::array<T, size> &object);


    template<typename T>
    const T& max(const container::set<T> &object);


    template<typename T>
    const T& min(const container::vector<T> &object);


    template<typename T, size_t size>
    const T& min(const container::array<T, size> &object);


    template<typename T>
    const T& min(const container::set<T> &object);


    template<typename T>
    T& find(const container::vector<T> &object, const T &element);


    template<typename T, size_t size>
    T& find(const container::array<T, size> &object, const T &element);


    template<typename T>
    void sort(container::vector<T> &object, int l = 0, int r = 0);


    template<typename T, size_t size>
    void sort(container::array<T, size> &object, int l = 0, int r = 0);
}


#include "algorithm.tpp"