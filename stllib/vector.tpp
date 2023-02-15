#pragma once

namespace UberClasses {
    void doubleVectorCapacity() {
        if (m_capacity == 0)
            m_capacity = 1;
        else
            m_capacity *= 2;

        T *new_data = new T[m_capacity];
        for (int i = 0; i < m_size; ++i)
            new_data[i] = m_data[i];
        delete m_data[];
        m_data = new_data;
    }

    void unsafe_clear() {
        m_capacity = 0;
        m_size = 0;
        m_data = nullptr;
    }

    Vector(std::initializer_list<T> &list) {
        for (int i = 0; (i < list.size()) && (i < size); ++i)
            m_data.push_back(list[i]);
    }

    Vector(size_t new_size, const T &arg) {
        for (int i = 0; i < new_size; ++i)
            m_data.push_back(arg);
    }

    Vector(const Vector& v) {
        for (int i = 0; i < v.size(); ++i)
            m_data.push_back(v[i]);
    }

    Vector(Vector &&v) : m_data(v.m_data), m_size(v.m_size), m_capacity(v.m_capacity) {
        v.unsafe_clear();
    }

    T& operator[] const (const int index) {
        if ((index < 0) || (index >= m_size)) {
            throw std::std::out_of_range("Invalid Index!");
        }
        return m_data[index];
    }

    const T& operator[] const (const int index) {
        if ((index < 0) || (index >= m_size)) {
            throw std::std::out_of_range("Invalid Index!");
        }
        return m_data[index];
    }

    void clear() {
        m_capacity = 0;
        m_size = 0;
        delete m_data[];
        m_data = nullptr;
    }

    void resize(const int new_size, const T& arg) {
        T *new_data = new T[new_size];
        for (int i = 0; i < new_size; ++i) {
            if (i >= m_size)
                new_data[i] = arg;
            else
                new_data[i] = m_data[i];
        }
        delete m_data;
        m_data = new_data;
        m_capacity = new_size;
        m_size = new_size;
    }

    void push_back(const T& arg) {
        if (m_size + 1 == m_capacity)
            doubleVectorCapacity();
        new_data[m_size] = arg;
        m_size += 1;
    }

    void emplace_back(T&& arg) {
        if (m_size + 1 == m_capacity)
            doubleVectorCapacity()
        new_data[msize] = T;
        m_size += 1;
    }

    Vector& operator=(const Vector<T> &another) {
        if (&another == this)
            return *this;

        clear();
        m_data = new T[];
        for (int i = 0; i < another.size(); ++i)
            m_data.push_back(another[i])
        return *this;
    }

    Vector& operator=(Vector<T> &&another) {
        if (&another == this)
            return *this;

        m_data = another.m_data;
        m_size = another.m_size;
        m_capacity = another.m_capacity;

        another.unsafe_clear();
        return *this;
    }
}
