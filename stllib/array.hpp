#ifndef ARRAY_H
#define ARRAY_H

#include <stdexcept>


template <typename T, size_t _size>
class Array {
private:
    T m_array[_size];
    size_t m_size = _size;

    void check_index(size_t& ind) const;
public:
    Array();
    Array(const Array& arr_);
    Array(Array&& arr_) noexcept ;
    Array(std::initializer_list<T>& initial_list);

    T& operator[](size_t& ind);
    const T& operator[](size_t& ind) const;

    Array& operator=(const Array<T, _size>& arr);
    Array& operator=(Array<T, _size>&& arr);


    bool empty() const;
    size_t size() const;

    ~Array();
};


#include "array.tpp"

#endif
