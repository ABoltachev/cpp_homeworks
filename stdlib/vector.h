#pragma once

#include <iostream>

/*
    * vector и методы для него (самая простая реализация с использованием динамического массива, если размера не хватает, 
                                чтобы добавить эелемент в конец, просто расширяется в два раза):
        size (возвращает размер)
        empty (возвращает true если пустой)
        взятие по индексу (operator[])
        push_back (вставка в конец (копирование))
        emplace_back (вставка в конце (перемещение))
        clear (очистка)
        resize (изменение размера, вторым аргументом идет аргумент по умолчанию, которым будут заполняться все места)
        присваивание (копирование и перемещением)
        конструкторы (конструктор без аргументов; первый аргумент размер, второй по умолчанию со значением, 
                      которым будут заполняться все места; копирования; перемещения; конструктор с std::inizialized_list)
*/


namespace HW_2 {

    template<typename Type>
    class Vector {
    private:
        Type *m_arr = nullptr;
        size_t m_size;
        size_t m_amount;
    public:
        Vector() = default;
        Vector(size_t size, const Type& value = Type());
        Vector(const Vector& another);
        Vector(Vector&& another);
        Vector(const std::initializer_list<Type> init_list);

        size_t size() const;
        bool empty() const;

        void push_back(const Type& value);
        void emplace_back(Type&& value);
        void clear();
        void extend(size_t new_amount);
        void resize(size_t size, const Type& value = Type());

        Type& operator[](int i);
        const Type& operator[](int i) const;

        Vector& operator=(const Vector& another); // присваивание копированием
        Vector& operator=(Vector&& another); // присваивание перемещением
    };

}

#include "vector.tpp"
