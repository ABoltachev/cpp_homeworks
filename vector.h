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
#ifndef SHABLON_VECTOR_H
#define SHABLON_VECTOR_H
#include<iostream>

template<typename T>
class Vector {
private:
    T* m_arr;
    size_t m_size;
    size_t m_val;

public:
    Vector();
    Vector(size_t size, const T& value = T());
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;
    Vector(std::initializer_list<T> list);

    T& operator[](size_t& ind);
    const T& operator[](size_t& ind) const;

    Vector& operator=(const Vector<T>& arr);
    Vector& operator=(Vector<T>&& arr) noexcept;

    bool empty();
    size_t size();

    void add(size_t n_val);

    void push_back(const T& elem);
    void emplace_back(T&& elem);

    void resize(size_t& _size_, const T &value=T());
    void clear();
};



#include "vector.tpp"

#endif //SHABLON_VECTOR_H
