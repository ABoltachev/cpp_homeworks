#ifndef ARRAY_TPP
#define ARRAY_TPP


template<typename T, size_t _size>
Array<T, _size>::Array() : m_size(_size) {
    for (size_t i = 0; i < _size; ++i) m_array[i] = 0;
}

template<typename T, size_t _size>
Array<T, _size>::Array(const Array<T, _size> &arr_) {
    if (&arr_ == this) {
        return;
    }

    m_size = arr_.m_size;

    for (size_t i = 0; i < arr_.m_size; ++i) {
        m_array[i] = arr_.m_array[i];
    }
}

template<typename T, size_t _size>
Array<T, _size>::Array(Array<T, _size> &&arr) noexcept {
    if (&arr != this) {
        m_size = arr.m_size;

        for (size_t i = 0; i < arr.m_size; ++i) {
            m_array[i] = arr.m_array[i];
        }
    }

    return;
}

template <typename T, size_t _size>
Array<T, _size>::Array(std::initializer_list<T> &initial_list) {
    size_t count = 0;

    for (auto& obj: initial_list) {
        m_array[count] = obj;
        ++count;
    }
}

template <typename T, size_t _size>
T& Array<T, _size>::operator[](size_t &ind) {
    check_index(ind);
    return m_array[ind];
}

template <typename T, size_t _size>
const T& Array<T, _size>::operator[](size_t &ind) const {
    check_index(ind);
    return m_array[ind];
}

template <typename T, size_t _size>
Array<T, _size> &Array<T, _size>::operator=(const Array<T, _size> &arr) {
    if (&arr != this) {

        for (int i = 0; i < m_size; ++i) {
            m_array[i] = arr.m_array[i];
        }
    }

    return *this;
}

template <typename T, size_t _size>
Array<T, _size> &Array<T, _size>::operator=(Array<T, _size> &&arr) {
    if (&arr != this) {

        for (int i = 0; i < m_size; ++i) {
            m_array[i] = arr.m_array[i];
        }
    }

    return *this;
}

template <typename T, size_t _size>
bool Array<T, _size>::empty() const {
    return (_size == 0);
}

template <typename T, size_t _size>
size_t Array<T, _size>::size() const {
    return _size;
}

template <typename T, size_t _size>
void Array<T, _size>::check_index(size_t& ind) const {
    if ((ind >= size()) || (ind < 0)) {
        throw std::out_of_range("Index out of range");
    }
}

template <typename T, size_t _size>
Array<T, _size>::~Array() {
    delete[] m_array;
}

#endif