#ifndef SHABLON_VECTOR_TPP
#define SHABLON_VECTOR_TPP
#include <iostream>
#include "vector.h"

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
Vector<T>::Vector()
{
    m_size = 0;
    m_val = 0;
    m_arr = nullptr;
}

template<typename T>
Vector<T>::Vector(size_t size, const T &value) : m_size(size), m_val(size), m_arr(new T[size]){
    for (size_t i = 0; i < m_size; ++i) {
        m_arr[i] = value;
    }
}

template<class T>
Vector<T>::Vector(const Vector<T>& other)
{
    m_arr = new T[other.m_val];
    for (int i = 0; i < other.m_val; i++)
    {
        m_arr[i] = other.m_arr[i];
    }
    m_size = other.m_size;
    m_val = other.m_val;
}

template<class T>
Vector<T>::Vector(Vector<T>&& other) noexcept
        : m_arr(other.m_arr), m_size(other.m_size), m_val(other.m_val)
{
    other.m_arr = nullptr;
    other.m_size = 0;
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> list) : m_size(list.size()), m_val(m_size), m_arr(new T[m_size]) {
    size_t i = 0;
    for (const auto &value: list) {
        m_arr[i++] = value;
    }
}

template<class T>
Vector<T>& Vector<T>::operator= (const Vector<T>& other)
{
    if (&other == this)
        return *this;
    delete[] m_arr;
    m_arr = new T[other.m_val];
    for (int i = 0; i < other.m_val; i++)
    {
        m_arr[i] = other.m_arr[i];
    }
    m_size = other.m_size;
    m_val = other.m_val;
    return *this;
}

template<class T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) noexcept
{
    if (&other == this)
        return *this;
    delete[] m_arr;
    m_size = other.m_size;
    m_val = other.m_val;
    m_arr = other.m_arr;
    other.m_arr = nullptr;
    other.m_size = 0;
    other.m_val = 0;
    return* this;
}

template<class T>
T& Vector<T>::operator[](size_t& ind)
{
    if ((ind < 0) || (ind >= m_size))
        throw std::out_of_range("List out of range");
    return m_arr[ind];
}

template<class T>
const T& Vector<T>::operator[](size_t& ind) const
{
    if ((ind < 0) || (ind >= m_size))
        throw std::out_of_range("List out of range");
    return m_arr[ind];
}

template<class T>
void Vector<T>::add(size_t new_val) {
    if (m_val < new_val) {
        T *new_arr = new T[new_val];
        for (size_t i = 0; i < m_size; ++i) {
            new_arr[i] = std::move(m_arr[i]);
        }
        delete[] m_arr;
        m_arr = new_arr;
        m_val = new_val;
    }
}

template<class T>
void Vector<T>::resize(size_t& new_size, const T &val) {
    if(new_size > m_val) {
        add(new_size * 2);
    }
    for (int i = m_size; i < new_size; i++)
        m_arr[i] = val;
    m_size = new_size;
}

template<typename T>
void Vector<T>::clear() {
    delete[] m_arr;

    m_arr = new T[m_val];
    m_size = 0;
}

template<typename T>
void Vector<T>::push_back(const T& elem) {
    if (m_size == m_val) {
        resize(m_val * 2);
    }
    m_arr[m_size++] = elem;
}

template<typename T>
void Vector<T>::emplace_back(T&& elem) {
    if (m_size == m_val) {
        resize(m_val * 2);
    }
    m_arr[m_size++] = std::move(elem);
}

#endif