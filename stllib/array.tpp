#include "array.hpp"
#include <exception>
template<typename T, size_t len>
bool Array<T, len>::empty() {
    return len == 0;
}
template<typename T, size_t len>
Array<T, len>& Array<T, len>::operator=(const Array<T, len>& other) {
    for (int index = 0; index < _size_; index++)
    {
        arr[index] = other.arr[index];
    }
    return *this;
}
template<typename T, size_t len>
T& Array<T,len>::operator[](int index)
{
    if (index >= _size_)
        throw std::out_of_range("List out of range");
    return arr[index];
}
template<typename T, size_t len>
Array<T, len>::Array(const std::initializer_list<T>& l)
{
    int i = 0;
    for(const auto elem: l)
    {
        arr[i++] = elem;
    }
}
template<typename T, size_t len>
int Array<T, len>::size()
{
    return _size_;
}