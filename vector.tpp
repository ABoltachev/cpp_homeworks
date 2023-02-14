#pragma once
#include "vector.hpp"
#include <cstdarg>
template<class T>
size_t Vector<T>::size()
{
    return _size_;
}
template<class T>
bool Vector<T>::empty()
{
    return (_size_ == 0);
}
template<class T>
T& Vector<T>::operator[](int index)
{
    if (index >= _size_)
        throw std::out_of_range("List out of range");
    return v[index];
}
template<class T>
Vector<T>::Vector()
{
    _size_ = 0;
    _capacity_ = 0;
    v = nullptr;
}
template<class T>
Vector<T>::Vector(const Vector<T>& other)
{
    v = new T[other._capacity_];
    for (int i = 0; i < other._capacity_; i++)
    {
        v[i] = other.v[i];
    }
    _size_ = other._size_;
    _capacity_ = other._capacity_;
}
template<class T>
Vector<T>::Vector(Vector<T>&& other) noexcept
: v(other.v), _size_(other._size_), _capacity_(other._capacity_)
{
    other.v = nullptr;
    other._size_ = 0;
}
template<class T>
Vector<T>& Vector<T>::operator= (const Vector<T>& other)
{
    if (&other == this)
        return *this;
    delete[] v;
    v = new T[other._capacity_];
    for (int i = 0; i < other._capacity_; i++)
    {
        v[i] = other.v[i];
    }
    _size_ = other._size_;
    _capacity_ = other._capacity_;
    return *this;
}
template<class T>
Vector<T>& Vector<T>::operator= (Vector<T>&& other) noexcept
{
    if (&other == this)
        return *this;
    delete[] v;
    _size_ = other._size_;
    _capacity_ = other._capacity_;
    v = other.v;
    other.v = nullptr;
    other._size_ = 0;
    other._capacity_ = 0;
    return* this;
}
template<class T>
void Vector<T>::grow(size_t new_capacity)
{
        T *new_array = new T[new_capacity];
        for (int i = 0; i < _size_; i++)
            new_array[i] = v[i];
        delete [] v;
        v = new T[new_capacity];
        for (int i = 0; i < 2*_size_; i++)
            v[i] = new_array[i];
        _capacity_ = new_capacity;
        delete[] new_array;
}
template<class T>
void Vector<T>::resize(size_t new_size, T default_value) {
    if(new_size > _capacity_) {
        grow(new_size * 2);
    }
        for (int i = _size_; i < new_size; i++)
            v[i] = default_value;
        _size_ = new_size;
}
template<class T>
Vector<T>::Vector(size_t size, T default_value)
{
    _capacity_ = size*2;
    _size_ = size;
    v = new T[_capacity_];
    for (int i = 0; i < _capacity_; i++)
    {
        v[i] = default_value;
    }
}
template<class T>
template<typename...Args>
T Vector<T>::emplace_back(Args&&... args) {
    if (_size_ == _capacity_) {
        grow((_capacity_+1)*2);
    }
        return *new(v + _size_++) T(std::forward<Args>(args)...);
}
template<class T>
T Vector<T>::push_back(const T& elem){
    return emplace_back(elem);
}
template<class T>

Vector<T>::Vector(const std::initializer_list<T>& l)
{
    _size_ = l.size();
    _capacity_ = _size_ * 2;
    v = new T[_capacity_];
    int i = 0;
    for(const auto elem: l)
    {
        v[i++] = elem;
    }
}
template<class T>
void Vector<T>::clear()
{
    delete[] v;
    v = nullptr;
    _size_ = 0;
    _capacity_ = 0;
}
