#pragma once

namespace UberClasses {
    template <typename T>
    void Vector<T>::doubleVectorCapacity() {
        m_capacity *= 2;
        T *new_data = new T[m_capacity];
        for (int i = 0; i < m_size; ++i)
            new_data[i] = m_data[i];
        delete[] m_data;
        m_data = new_data;
    }

    template <typename T>
    void Vector<T>::unsafe_clear() {
        m_capacity = 1;
        m_size = 0;
        m_data = nullptr;
    }

    template <typename T>
    Vector<T>::Vector(std::initializer_list<T> &list) {
        for (int i = 0; (i < list.size()) && (i < m_size); ++i)
            push_back(list[i]);
    }

    template <typename T>
    Vector<T>::Vector(size_t new_size, const T &arg) {
        for (int i = 0; i < new_size; ++i)
            push_back(arg);
    }

    template <typename T>
    Vector<T>::Vector(const Vector& v) {
        for (int i = 0; i < v.size(); ++i)
            push_back(v[i]);
    }

    template <typename T>
    Vector<T>::Vector(Vector &&v) : m_data(v.m_data), m_size(v.m_size), m_capacity(v.m_capacity) {
        v.unsafe_clear();
    }

    template <typename T>
    T& Vector<T>::operator[] (const size_t index) {
        if ((index < 0) || (index >= m_size)) {
            throw std::out_of_range("Invalid Index!");
        }
        return m_data[index];
    }

    template <typename T>
    const T& Vector<T>::operator[] (const size_t index) const {
        if ((index < 0) || (index >= m_size)) {
            throw std::out_of_range("Invalid Index!");
        }
        return m_data[index];
    }

    template <typename T>
    void Vector<T>::clear() {
        m_capacity = 1;
        m_size = 0;
        delete[] m_data;
        m_data = nullptr;
    }

    template <typename T>
    void Vector<T>::resize(const int new_size, const T& arg) {
        T *new_data = new T[new_size];
        for (int i = 0; i < new_size; ++i) {
            if (i >= m_size)
                new_data[i] = arg;
            else
                new_data[i] = m_data[i];
        }
        delete[] m_data;
        m_data = new_data;
        m_capacity = new_size;
        m_size = new_size;
    }

    template <typename T>
    void Vector<T>::push_back(const T& arg) {
        if (m_size + 1 == m_capacity)
            doubleVectorCapacity();
        m_data[m_size] = arg;
        m_size += 1;
    }

    template <typename T>
    void Vector<T>::emplace_back(T&& arg) {
        if (m_size + 1 == m_capacity)
            doubleVectorCapacity();
        m_data[m_size] = arg;
        m_size += 1;
    }

    template <typename T>
    Vector<T>& Vector<T>::operator=(const Vector<T> &another) {
        if (&another == this)
            return *this;

        clear();
        m_data = nullptr;
        for (int i = 0; i < another.size(); ++i)
            push_back(another[i]);
        return *this;
    }

    template <typename T>
    Vector<T>& Vector<T>::operator=(Vector<T> &&another) {
        if (&another == this)
            return *this;

        m_data = another.m_data;
        m_size = another.m_size;
        m_capacity = another.m_capacity;

        another.unsafe_clear();
        return *this;
    }
}
