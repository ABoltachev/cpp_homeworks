#ifndef VECTOR_TPP
#define VECTOR_TPP

#include "vector.hpp"

template<typename T>
vector<T>::vector() : m_arr(new T[0]), m_size(0), m_tonnage(1) {}

template<typename T>
vector<T>::vector(size_t size, const T &value) : m_size(size), m_tonnage(size), m_arr(new T[size]){
    for (size_t i = 0; i < m_size; ++i) {
        m_arr[i] = value;
    }
}

template<typename T>
vector<T>::vector(const vector &other) : m_size(other.m_size), m_tonnage(other.m_tonnage), m_arr(new T[m_tonnage]) {
    for (size_t i = 0; i < m_size; ++i) {
        m_arr[i] = other.m_arr[i];
    }
}

template<typename T>
vector<T>::vector(vector &&other) : m_size(other.m_size), m_tonnage(other.m_tonnage), m_arr(other.m_arr) {
    other.m_arr = nullptr;
    other.m_tonnage = 0;
    other.m_size = 0;
}

template<typename T>
vector<T>::vector(std::initializer_list<T> list) : m_size(list.size()), m_tonnage(m_size), m_arr(new T[m_size]) {
    size_t count = 0;
    for (const auto &value: list) {
        m_arr[count++] = value;
    }
}

template<typename T>
bool vector<T>::empty() const {
    return m_size == 0;
}

template<typename T>
size_t vector<T>::size() const {
    return m_size;
}

template<typename T>
void vector<T>::addMem(size_t n_tonnage) {
    if (m_tonnage < n_tonnage) {
        T* new_arr = new T[n_tonnage];
        for (size_t i = 0; i < m_size; ++i) {
            new_arr[i] = std::move(m_arr[i]);
        }

        delete[] m_arr;
        m_arr = new_arr;
        m_tonnage = n_tonnage;
    }
}

template<typename T>
void vector<T>::push_back(const T& elem) {
    if (m_size == m_tonnage) {
        resize(m_tonnage * 2);
    }
    m_arr[m_size++] = elem;
}

template<typename T>
void vector<T>::emplace_back(T&& elem) {
    if (m_size == m_tonnage) {
        resize(m_tonnage * 2);
    }
    m_arr[m_size++] = std::move(elem);
}

template<typename T>
void vector<T>::resize(size_t &n_size, const T &value) {
    if (n_size <= 0) {
        throw std::logic_error("Vector has incorrect size");
    }
    else if (n_size > m_tonnage) {
        addMem(n_size);
    }

    for (size_t i = m_size; i < n_size; ++i) {
        m_arr[i] = value;
    }

    m_size = n_size;
}

template<typename T>
void vector<T>::clear() {
    delete[] m_arr;

    m_arr = new T[m_tonnage];
    m_size = 0;
}

template<typename T>
T &vector<T>::operator[](size_t &ind) {
    check_index(ind);
    return m_arr[ind];
}

template<typename T>
const T &vector<T>::operator[](size_t &ind) const{
    check_index(ind);
    return m_arr[ind];
}

template<typename T>
vector<T> &vector<T>::operator=(const vector<T> &arr) {
    if (&arr != this) {
        vector temp(arr);

        std::swap(m_size, temp.m_size);
        std::swap(m_tonnage, temp.m_tonnage);
        std::swap(m_arr, temp.m_arr);

    }
    return *this;
}

template<typename T>
vector<T> &vector<T>::operator=(vector<T> &&arr) {
    if (&arr != this) {
        m_tonnage = arr.m_tonnage;
        m_size = arr.m_size;
        m_arr = arr.m_arr;

        arr.m_arr = nullptr;
        arr.m_size = 0;
        arr.m_tonnage = 0;
    }
    return *this;
}

template<typename T>
void vector<T>::check_index(size_t &ind) const {
    if ((ind < 0) || (ind >= m_size)) {
        throw std::out_of_range("Index out of range");
    }
}

template<typename T>
vector<T>::~vector() {
    delete[] m_arr;
}

#endif
