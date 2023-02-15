#pragma once
#include <initializer_list>

template <typename T, std::size_t N>
class Array {
public:
    Array();
    Array(std::initializer_list<T> list);
    Array(const Array<T, N>& other);
    Array<T, N>& operator=(const Array<T, N>& other);
    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;
    std::size_t size() const;
    bool empty() const;

private:
    T data_[N];
};
