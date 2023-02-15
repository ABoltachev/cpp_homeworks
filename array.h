#ifndef HW2_ARRAY_H
#define HW2_ARRAY_H

#include <initializer_list>

template<typename T, std::size_t S>
class Array {
private:
    T m_array[S];
public:
    Array() = default;

    Array &operator=(const Array<T, S> &arr);

    Array(std::initializer_list<T> list);

    std::size_t size();

    bool empty();

    T &operator[](std::size_t index);

};

#endif
