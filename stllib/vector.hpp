/*
* vector и методы для него (самая простая реализация с использованием динамического массива, если размера не хватает, чтобы добавить эелемент в конец, просто расширяется в два раза):
    size (возвращает размер)
    empty (возвращает true если пустой)
    взятие по индексу (operator[])
    push_back (вставка в конец (копирование))
    emplace_back (вставка в конце (перемещение))
    clear (очистка)
    resize (изменение размера, вторым аргументом идет аргумент по умолчанию, которым будут заполняться все места)
    присваивание (копирование и перемещением)
    конструкторы (конструктор без аргументов; первый аргумент размер, второй по умолчанию со значением, которым будут заполняться все места; копирования; перемещения; конструктор с std::inizialized_list)
*/

#pragma once

#include <initializer_list>
#include <stdexcept>

namespace UberClasses {
    template<typename T>
    class Vector {
        size_t m_capacity = 0;
        size_t m_size = 0;
        T *m_data = nullptr;

        void doubleVectorCapacity();
        void unsafe_clear();

    public:
        Vector() = default;
        Vector(std::initializer_list<T> &list);
        Vector(size_t new_size, const T &arg);
        Vector(const Vector& v);
        Vector(Vector &&v);
        ~Vector() = default;

        size_t size() const { return m_size; }
        bool empty() const { return m_size == 0; }

        T& operator[] const (const int index);
        const T& operator[] const (const int index);
        void clear();
        void resize(const int new_size, const T& arg);
        void push_back(const T& arg);
        void emplace_back(T&& arg);
        Vector& operator=(const Vector<T> &another);
        Vector& operator=(Vector<T> &&another);
    };
}

#include "vector.tpp"