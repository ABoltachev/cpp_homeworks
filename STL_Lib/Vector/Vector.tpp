#ifndef COLLECTIONS_VECTOR_TPP
#define COLLECTIONS_VECTOR_TPP

#include <iostream>

namespace VectorLib {

    template<class T>
    [[maybe_unused]] [[maybe_unused]] Vector<T>::Vector(const std::initializer_list<T> &init_list)
    : m_capacity(init_list.size()), m_size(init_list.size()), m_vec(init_list.size() == 0 ? nullptr : new T[init_list.size()])
    {
        std::size_t i = 0;
        for (const T& elem : init_list)
            m_vec[i++] = elem;
    }

    template<class T>
    Vector<T>::~Vector() {
        delete[] m_vec;
        m_vec = nullptr;
        m_capacity = 0;
        m_size = 0;
    }

    template<class T>
    [[maybe_unused]] Vector<T>::Vector(const Vector<T> &v_other)
    :m_capacity(v_other.m_capacity), m_size(v_other.m_size), m_vec(m_capacity == 0 ? nullptr : new T[v_other.m_capacity])
    {
        size_t i = 0;
        for (const T& elem : v_other)
            m_vec[i++] = elem;
    }

    template<class T>
    [[maybe_unused]] Vector<T>::Vector(Vector &&v_other) noexcept
    : m_capacity(v_other.m_capacity), m_size(v_other.m_size), m_vec(v_other.m_vec)
    {
        v_other.m_data = nullptr;
        v_other.m_size = 0;
        v_other.m_capacity = 0;
    }

    template<class T>
    [[maybe_unused]] Vector<T>::Vector(size_t _size, const T& value)
    : m_capacity(_size), m_size(_size), m_vec((m_capacity == 0) ? nullptr : new T[m_capacity])
    {
        for (std::size_t i = 0; i < _size; i++)
            m_vec[i] = value;
    }

    template<class T>
    [[maybe_unused]] Vector<T>::Vector(size_t _size)
    : m_capacity(_size), m_size(0), m_vec((m_capacity == 0) ? nullptr : new T[m_capacity]) {}


    template<class T>
    [[maybe_unused]] size_t Vector<T>::size() const {
        return m_size;
    }

    template<class T>
    [[maybe_unused]] size_t Vector<T>::capacity() const {
        return m_capacity;
    }

    template<class T>
    [[maybe_unused]] bool Vector<T>::empty() const {
        return m_size == 0;
    }

    template<class T>
    [[maybe_unused]] Vector<T> &Vector<T>::operator=(const Vector<T>& v_other) {
        if (&v_other != this) {
            delete[] m_vec;
            m_vec = nullptr;

            m_capacity = v_other.m_capacity;
            m_size = v_other.m_capacity;
            m_vec = m_capacity == 0 ? nullptr : new T[v_other.m_capacity];

            for (std::size_t i = 0; i < v_other.m_size; i++){
                m_vec[i] = v_other.m_vec[i];
            }
        }
        return *this;
    }

    template<class T>
    T& Vector<T>::operator[](size_t id) {
        assert(id < m_size);
        return m_vec[id];
    }

    template<class T>
    const T &Vector<T>::operator[](size_t id) const {
        assert(id < m_size);
        return m_vec[id];
    }

    template<class T>
    [[maybe_unused]] void Vector<T>::clear() {
        delete[] m_vec;
        m_size = 0;
        m_vec = new T[m_capacity];
    }

    template<class T>
    void Vector<T>::push_back(const T& value) {
        if (m_size == m_capacity)
        {
            m_capacity = m_capacity == 0 ? 1 : 2 * m_capacity;
            T* temp = new T[m_capacity];

            for (size_t i = 0; i < m_size; ++i)
                temp[i] = m_vec[i];

            delete[] m_vec;
            m_vec = temp;
        }
        m_vec[m_size++] = value;
    }

    template<class T>
    [[maybe_unused]] void Vector<T>::emplace_back(T &&value) {
        // push_back(T(std::forward<T>(value)));
        if (m_size == m_capacity)
        {
            m_capacity = m_capacity == 0 ? 1 : 2 * m_capacity;
            T* temp = new T[m_capacity];

            for (size_t i = 0; i < m_size; ++i)
                temp[i] = m_vec[i];

            delete[] m_vec;
            m_vec = temp;
        }
        m_vec[m_size++] = std::forward<T>(value); // or std::move(value);

    }

    template<class T>
    Vector<T> &Vector<T>::operator=(Vector &&v_other)  noexcept {
        if (&v_other != this) {
            delete[] m_vec;
            m_vec = nullptr;

            m_size = v_other.m_size;
            m_capacity = v_other.m_capacity;
            m_vec = v_other.m_vec;

            delete[] v_other.m_vec;
            v_other.m_vec = nullptr;
            v_other.m_capacity = 0;
            v_other.m_size = 0;
        }
        return *this;
    }

    template<class T>
    [[maybe_unused]] void Vector<T>::resize(size_t _size, const T &x){
        if (_size > m_size)
        {
            if (_size > m_capacity)
            {
                m_capacity = _size;
                T* temp = new T[m_capacity];
                for (size_t i = 0; i < m_size; ++i)
                    temp[i] = m_vec[i];

                delete[] m_vec;

                for (size_t i = m_size; i < m_capacity; ++i)
                    temp[i] = x;

                m_vec = temp;
            }
        }
        m_size = _size;
    }
}

#endif // COLLECTIONS_VECTOR_TPP
