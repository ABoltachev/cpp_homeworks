#pragma once
#include "vector.hpp"
#include <cstdarg>
template<class T>
size_t Vector<T>::size()
{
    return m_size;
}
template<class T>
bool Vector<T>::empty()
{
    return (m_size == 0);
}
template<class T>
T& Vector<T>::operator[](int index)
{
    if (index >= m_size)
        throw std::out_of_range("List out of range");
    return v[index];
}
template<class T>
Vector<T>::Vector()
{
    m_size = 0;
    m_capacity = 0;
    v = nullptr;
}
template<class T>
Vector<T>::Vector(const Vector<T>& other)
{
    v = new T[other.m_capacity];
    for (int i = 0; i < other.m_capacity; i++)
    {
        v[i] = other.v[i];
    }
    m_size = other.m_size;
    m_capacity = other.m_capacity;
}
template<class T>
Vector<T>::Vector(Vector<T>&& other) noexcept
: v(other.v), m_size(other.m_size), m_capacity(other.m_capacity)
{
    other.v = nullptr;
    other.m_size = 0;
}
template<class T>
Vector<T>& Vector<T>::operator= (const Vector<T>& other)
{
    if (&other == this)
        return *this;
    delete[] v;
    v = new T[other.m_capacity];
    for (int i = 0; i < other.m_capacity; i++)
    {
        v[i] = other.v[i];
    }
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    return *this;
}
template<class T>
Vector<T>& Vector<T>::operator= (Vector<T>&& other) noexcept
{
    if (&other == this)
        return *this;
    delete[] v;
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    v = other.v;
    other.v = nullptr;
    other.m_size = 0;
    other.m_capacity = 0;
    return* this;
}
template<class T>
void Vector<T>::grow(size_t new_capacity)
{
        T *new_array = new T[new_capacity];
        for (int i = 0; i < m_size; i++)
            new_array[i] = v[i];
        delete [] v;
        v = new T[new_capacity];
        for (int i = 0; i < 2*m_size; i++)
            v[i] = new_array[i];
        m_capacity = new_capacity;
        delete[] new_array;
}
template<class T>
void Vector<T>::resize(size_t new_size, T default_value) {
    if(new_size > m_capacity) {
        grow(new_size * 2);
    }
        for (int i = m_size; i < new_size; i++)
            v[i] = default_value;
        m_size = new_size;
}
template<class T>
Vector<T>::Vector(size_t size, T default_value)
{
    m_capacity = size*2;
    m_size = size;
    v = new T[m_capacity];
    for (int i = 0; i < m_capacity; i++)
    {
        v[i] = default_value;
    }
}
template<class T>
template<typename...Args>
T Vector<T>::emplace_back(Args&&... args) {
    if (m_size == m_capacity) {
        grow((m_capacity+1)*2);
    }
        return *new(v + m_size++) T(std::forward<Args>(args)...);
}
template<class T>
T Vector<T>::push_back(const T& elem){
    return emplace_back(elem);
}
template<class T>

Vector<T>::Vector(const std::initializer_list<T>& l)
{
    m_size = l.size();
    m_capacity = m_size * 2;
    v = new T[m_capacity];
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
    m_size = 0;
    m_capacity = 0;
}
