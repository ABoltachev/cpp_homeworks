#include "vector.h"

template<typename T>
bool Vector<T>::empty() {
    return (m_size == 0);
}

template<typename T>
size_t Vector<T>::size() {
    return (m_size);
}

template<typename T>
T &Vector<T>::operator[](std::size_t index) {
    if (index >= m_size) {
        return nullptr;
    } else {
        return vec[index];
    }
}

template<typename T>
void Vector<T>::expand() {
    m_capacity == 0 ? m_capacity = 1 : m_capacity *= 2;
    T *copy = new T[m_capacity];
    for (int i = 0; i < m_size; ++i) {
        copy[i] = vec[i];
    }
    delete[] vec;
    vec = copy;

}

template<typename T>
void Vector<T>::resize(std::size_t size, const T &obj) {
    T *copy = new T[size];
    for (int i = 0; i < size; ++i) {
        if (i < m_size)
            copy[i] = vec[i];
        else
            copy[i] = obj;
    }
    delete[] vec;
    vec = copy;

}

template<typename T>
void Vector<T>::push_back(const T &obj) {
    if (m_capacity == m_size) {
        expand();
    }
    vec[m_size] = obj;
    ++m_size;
}

template<typename T>
void Vector<T>::emplace_back(T &&obj) {
    if (m_capacity == m_size) {
        expand();
    }
    vec[m_size] = obj;
    ++m_size;
}

template<typename T>
void Vector<T>::clear() {
    delete[] vec;
    vec = new T[m_capacity];
    m_size = 0;
}

template<typename T>
Vector<T> &Vector<T>::operator=(Vector<T> &&n_vec) {
    if (vec != n_vec) {
        vec = n_vec.vec;
        m_capacity = n_vec.m_capacity;
        m_size = n_vec.m_size;
        n_vec.clear();
    }
    return *this;
}

template<typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &n_vec) {
    if (vec != n_vec) {
        delete[] vec;
        m_size = 0;
        m_capacity = 0;
        vec = new T[n_vec.m_capacity];
        for (int i = 0; i < n_vec.size; ++i) {
            vec[i] = n_vec.vec[i];
        }
    }
    return *this;
}

template<typename T>
Vector<T>::Vector(Vector<T> &&n_vec) {
    m_size = n_vec.m_size;
    m_capacity = n_vec.m_capacity;
    vec = n_vec.vec;
    n_vec.m_size = 0;
    n_vec.m_capacity = 0;
    n_vec.vec = nullptr;
}

template<typename T>
Vector<T>::Vector(const Vector<T> &n_vec) {
    vec = new T[n_vec.m_capacity];
    m_size = n_vec.size;
    m_capacity = n_vec.m_capacity;
    for (int i = 0; i < n_vec.m_size; ++i) {
        vec[i] == n_vec.vec[i];
    }
}

template<typename T>
Vector<T>::Vector(std::size_t size, const T &obj) {
    vec = new T[size];
    m_capacity = size;
    size = size;
    for (int i = 0; i < size; ++i) {
        vec[i] = obj;
    }
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> list) {
    m_size = list.size();
    m_capacity = list.size();
    vec = new T[list.size()];
    size_t count = 0;
    for (const auto i: list) {
        vec[count++] = i;
    }
}