#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template <class T, size_t param_size>
class array{
    private:
    T m_array[param_size];
    const size_t m_size = param_size;
    public:
    array() = default;

    array(const array& obj) = delete;

    array(const std::initializer_list<T> &list){
        int index = 0;
        for (auto it = list.begin(); it != list.end(); ++it){
            m_array[index] = *it;
            index++;
        }
    };

    size_t size() const;

    bool empty() const;

    T& operator[](size_t index);

    const T& operator[](size_t index) const;

    array& operator=(const array& obj);

    T* begin();

    T* end();
};

#include "array.tpp"

#endif