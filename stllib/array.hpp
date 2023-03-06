/*
* array (статический массив) и методы для него:
    m_size (возвращает размер)
    empty (возвращает true если пустой)
    взятие по индексу (operator[])
    присваивание копированием
    конструкторы (конструктор с std::inizialized_list)
*/

#pragma once

#include <initializer_list>
#include <iostream>

namespace UberClasses {
    template <typename T, size_t m_size>
    class Array {
        T m_data[m_size];
    public:
        Array() = default;
        Array(std::initializer_list<T> &list) {
            if (list.size() > m_size) {
                std::cerr << "Too much elements in list: expected " << m_size << " but got " << list.size() << std::endl;
            }
            for (int i = 0; (i < list.size()) && (i < m_size); ++i)
                m_data[i] = list[i];
        }
        ~Array() = default;

        size_t size() const { return m_size; }
        bool empty() const { return m_size == 0; }

        T& operator[](const int index) {
            if ((index < 0) || (index >= m_size)) {
                std::cerr << "Incorrect index!" << std::endl;
                return m_data[0];
            }
            return m_data[index];
        }

        Array& operator=(const Array<T, m_size> &another) {
            for (int i = 0; i < m_size; ++i)
                m_data[i] = another[i];
            return *this;
        }
    };
}