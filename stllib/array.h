#pragma once

#include <iostream>
#include <initializer_list>

namespace container {
    template<typename T, size_t size_>
    class array {


    private:
        T data_[size_];

    public:
        array(const T &element = T());

        array(const std::initializer_list<T> list);

        size_t size() const;

        bool empty() const;


        const T& operator[](int i) const;


        T& operator[](int i);

        array <T, size_>& operator=(array <T, size_> object);
    };
}

#include "array.tpp"