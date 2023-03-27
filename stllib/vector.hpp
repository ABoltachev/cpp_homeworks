//* vector и методы для него(самая простая реализация с использованием динамического массива, если размера не хватает, чтобы добавить эелемент в конец, просто расширяется в два раза) :
    //    +size(возвращает размер)
    //    +empty(возвращает true если пустой)
    //    +взятие по индексу(operator[])
    //    +push_back(вставка в конец(копирование))
    //    +emplace_back(вставка в конце(перемещение))
    //    +clear(очистка)
    //    +resize(изменение размера, вторым аргументом идет аргумент по умолчанию, которым будут заполняться все места)
    //    +присваивание(копирование и перемещением)
    //    +конструкторы(конструктор без аргументов; 
    //    первый аргумент размер, второй по умолчанию со значением, которым будут заполняться все места; 
    //    копирования; перемещения; конструктор с std::inizialized_list)
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <stdexcept>

namespace lib {
    template <typename T>
    class Vector
    {
    private:
        T* vect;
        size_t m_size;
        size_t max_size;
    public:
        Vector();
        Vector(size_t size, T value);
        Vector(const Vector<T>& vector);
        Vector(Vector<T>&& vector);
        Vector(std::initializer_list<T> list);

        Vector& operator=(const Vector& vector);
        Vector& operator=(Vector&& vector);

        T& operator[](size_t ind);
        const T& operator[](size_t ind) const;

        void push_back(const T& value);
        void emplace_back(T&& value);

        void clear();
        void resize(size_t size, T value);

        size_t size() const;
        bool empty() const;

        ~Vector();
    };
}

#include "vector.tpp"

#endif 
