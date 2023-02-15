//
// Created by home on 11.02.23.
//

#ifndef UNTITLED15_VECTOR_H
#define UNTITLED15_VECTOR_H
#include<iostream>
template<class T>
class Vector
{
    T* v = nullptr;
    size_t m_size;
    size_t m_capacity;
    void grow(size_t new_capacity);
public:
    size_t size();
    bool empty();
    T& operator[](int index);
    T push_back(const T& elem);
    template<typename... Args>
    T emplace_back(Args&&... args);
    void clear();
    void resize(size_t new_size, T default_value);
    Vector();
    Vector(size_t size, T default_value);
    Vector(const Vector<T>& other);
    Vector(Vector<T>&& other) noexcept;
    Vector& operator= (const Vector<T>& other);
    Vector& operator= (Vector<T>&& other) noexcept;
    Vector(const std::initializer_list<T>& l);

};
#endif //UNTITLED15_VECTOR_H
#include "vector.tpp"