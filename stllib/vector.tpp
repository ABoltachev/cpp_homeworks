#pragma once
#include "vector.hpp"

namespace stl {

    template<typename T>
    void Vector<T>::checkIndex(size_t index) const {
        if (index < 0 || index >= m_size) {
            throw std::out_of_range("Index is out of range");
        }
    }

    template<typename T>
    Vector<T>::Vector() : m_array(new T[0]), m_size(0), m_max_size(1) {
    }

    template<typename T>
    Vector<T>::Vector(const size_t size, const T value) {

        m_size = size;
        m_max_size = size * 2;
        m_array = new T[m_max_size];

        for (int i = 0; i < size; i++) {
            m_array[i] = value;
        }
    }

    template<typename T>
    Vector<T>::Vector(std::initializer_list<T> list) {
        m_size = list.size();
        m_max_size = m_size * 2;

        m_array = new T[m_max_size];

        auto it = list.begin();
        for (int i = 0; i < m_size; i++) {
            m_array[i] = *(it + i);
        }
    }

    template<typename T>
    Vector<T>::Vector(const Vector<T> &vector) {
        delete[] m_array;
        m_size = vector.m_size;
        m_max_size = m_size * 2;

        *m_array = *vector.m_array;
    }

    template<typename T>
    Vector<T>::Vector(Vector<T> &&vector) {
        delete[] m_array;
        m_array = vector.m_array;

        m_size = vector.m_size;
        m_max_size = m_size * 2;

        vector.m_array = nullptr;
    }

    template<typename T>
    Vector<T> &Vector<T>::operator=(const Vector<T> &vector) {
        if (&vector == this) {
            return *this;;
        }

        delete[] m_array;
        m_size = vector.m_size;
        m_max_size = m_size * 2;

        *m_array = *vector.m_array;

        return *this;
    }

    template<typename T>
    Vector<T> &Vector<T>::operator=(Vector<T> &&vector) {
        if (&vector == this) {
            return *this;
        }

        delete[] m_array;
        m_array = vector.m_array;

        m_size = vector.m_size;
        m_max_size = m_size * 2;

        vector.m_array = nullptr;
        return *this;
    }

    template<typename T>
    T &Vector<T>::operator[](size_t index) {
        checkIndex(index);
        return m_array[index];
    }

    template<typename T>
    const T &Vector<T>::operator[](size_t index) const {
        checkIndex(index);
        return m_array[index];
    }

    template<typename T>
    void Vector<T>::push_back(const T &value) {
        if (m_size == m_max_size) {
            m_max_size = m_size * 2;
            T *new_array = new T[m_max_size];
            for (int i = 0; i < m_size; i++) {
                new_array[i] = m_array[i];
            }
            delete[] m_array;
            m_array = new_array;
        }
        m_array[m_size++] = value;
    }

    template<typename T>
    void Vector<T>::emplace_back(T &&value) {
        if (m_size == m_max_size) {
            m_max_size = m_size * 2;
            T *new_array = new T[m_max_size];
            for (int i = 0; i < m_size; i++) {
                new_array[i] = m_array[i];
            }
            delete[] m_array;
            m_array = new_array;
        }
        m_array[m_size++] = value;
    }

    template<typename T>
    size_t Vector<T>::size() const {
        return m_size;
    }

    template<typename T>
    bool Vector<T>::empty() const {
        return m_size == 0;
    }

    template<typename T>
    void Vector<T>::clear() {
        delete[] m_array;
        m_array = new T[m_max_size];
        m_size = 0;
    }

    template<typename T>
    void Vector<T>::resize(const size_t size, const T value) {
        delete[] m_array;

        m_size = size;
        m_max_size = size * 2;
        m_array = new T[m_max_size];

        for (int i = 0; i < size; i++) {
            m_array[i] = value;
        }
    }

}  // namespace stl