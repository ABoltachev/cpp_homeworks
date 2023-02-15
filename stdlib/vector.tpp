#pragma once

namespace HW_2 {

    template<typename Type>
    Vector<Type>::Vector(size_t size, const Type& value) : m_arr(new Type[size]), m_size(size), m_amount(size) {
        for (size_t i = 0; i < m_size; ++i) {
            m_arr[i] = value;
        }
    }

    template<typename Type>
    Vector<Type>::Vector(const Vector& another) : m_size(another.m_size), m_amount(another.m_amount), m_arr(new Type[m_amount]) {
        for (size_t i = 0; i < m_size; ++i) {
            m_arr[i] = another.m_arr[i];
        }
    }

    template<typename Type>
    Vector<Type>::Vector(Vector&& another) : m_size(another.m_size), m_amount(another.m_amount), m_arr(another.m_arr) {
        another.m_arr = nullptr;
        another.m_size = 0;
        another.m_amount = 0;
    }

    template<typename Type>
    Vector<Type>::Vector(const std::initializer_list<Type> init_list) {
        size_t i = 0;
        for (auto element : init_list) {
            m_arr[i++] = element;
        }
    }

    template<typename Type>
    size_t Vector<Type>::size() const {
        return m_size;
    }

    template<typename Type>
    bool Vector<Type>::empty() const {
        return (m_size == 0);
    }

    template<typename Type>
    void Vector<Type>::push_back(const Type& value) {
        if (m_size == m_amount) {
            resize(m_amount * 2);
        }
        m_arr[m_size++] = value;
    }

    template<typename Type>
    void Vector<Type>::emplace_back(Type&& value) {
        if (m_size == m_amount) {
            resize(m_amount * 2);
        }
        m_arr[m_size++] = std::move(value);
    }

    template<typename Type>
    void Vector<Type>::clear() {
        delete[] m_arr;
        m_arr = new Type[m_amount];
        m_size = 0;
    }

    template<typename Type>
    void Vector<Type>::extend(size_t new_amount) {
        if (m_amount < new_amount) {
            Type* new_arr = new Type[new_amount];
            for (size_t i = 0; i < m_size; i++) {
                new_arr[i] = std::move(m_arr[i]);
            }
            delete[] m_arr;
            m_arr = new_arr;
            m_amount = new_amount;
        }
    }

    template<typename Type>
    void Vector<Type>::resize(size_t size, const Type& value) {
        if (size > m_amount) {
            extend(size);
        }
        for (size_t i = m_size; i < size; i++) {
            m_arr[i] = value;
        }

        m_size = size;
    }

    template<typename Type>
    Type& Vector<Type>::operator[](int i) {
        if (i < 0 || i >= m_size) {
            throw std::out_of_range("Index out of range");
        }
        return m_arr[i];
    }

    template<typename Type>
    const Type& Vector<Type>::operator[](int i) const {
        if (i < 0 || i >= m_size) {
            throw std::out_of_range("Index out of range");
        }
        return m_arr[i];
    }

    template<typename Type>
    Vector<Type>& Vector<Type>::operator=(const Vector& another) {
        if (&another != this) {
            Vector temp(another);
            std::swap(m_size, temp.m_size);
            std::swap(m_amount, temp.m_amount);
            std::swap(m_arr, temp.m_arr);

        }
        return *this;
    }

    template<typename Type>
    Vector<Type>& Vector<Type>::operator=(Vector&& another) {
        if (&another != this) {
            m_amount = another.m_amount;
            m_size = another.m_size;
            m_arr = another.m_arr;

            another.m_arr = nullptr;
            another.m_size = 0;
            another.m_amount = 0;
        }
        return *this;
    }

}