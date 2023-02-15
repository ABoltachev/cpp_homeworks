/*
* array (статический массив) и методы для него:
    size (возвращает размер)
    empty (возвращает true если пустой)
    взятие по индексу (operator[])
    присваивание копированием
    конструкторы (конструктор с std::inizialized_list)
*/

#pragma once

#include <initializer_list>
#include <iostream>

namespace UberClasses {
    template <typename T, size_t size>
    class Array {
        T m_data[size];
    public:
        Array() = default;
        Array(std::initializer_list<T> &list) {
            if (list.size() > size) {
                std::cerr << "Too much elements in list: expected " << size << " but got " << list.size() << std::endl;
            }
            for (int i = 0; (i < list.size()) && (i < size); ++i)
                m_data[i] = list[i];
        }
        ~Array() = default;

        size_t size() const { return size; }
        bool empty() const { return size == 0; }

        T& operator[](const int index) {
            if ((index < 0) || (index >= size)) {
                std::cerr << "Incorrect index!" << std::endl;
                return m_data[0];
            }
            return m_data[index];
        }

        Array& operator=(const Array<T, size> &another) {
            for (int i = 0; i < size; ++i)
                m_data[i] = another[i];
            return *this;
        }
    };
}