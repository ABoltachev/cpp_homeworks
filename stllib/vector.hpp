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

#ifndef VECTORLIB
#define VECTORLIB

#include <iostream>

template<typename T>
class Vector{

    T* vector = nullptr;
    size_t vSize = 0;
    size_t vCapacity = 0;
    void shape(size_t newCapacity);

    public: 

    Vector() = default;
    Vector(size_t size, T value);
    Vector(const Vector<T>& other);
    Vector(Vector<T>&& other);
    Vector(const std::initializer_list<T>& init_list);

    Vector& operator= (const Vector<T>& other);
    Vector& operator= (Vector<T>&& other);

    size_t size();
    bool empty();
    void clear();    
    T& operator[](int index);
    void resize(size_t newSize, T value);

    void push_back(const T& element);
    void emplace_back(T&& element);

};

#include "vector.tpp"
#endif
