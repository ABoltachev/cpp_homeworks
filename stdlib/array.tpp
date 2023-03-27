#pragma once

namespace HW_2 {

    template<typename Type, size_t _size>
    Array<Type, _size>::Array(const std::initializer_list<Type>& init_list) {
        auto it = init_list.begin();
        for (size_t i = 0; i < _size; i++) {
            m_arr[i] = *(it + i);
        }
    }

    template<typename Type, size_t _size>
    size_t Array<Type, _size>::size() const {
        return _size;
    }

    template<typename Type, size_t _size>
    bool Array<Type, _size>::empty() const {
        return (_size == 0);
    }

    template<typename Type, size_t _size>
    Type& Array<Type, _size>::operator[](int i) {
        if (i < 0 || i >= _size) {
            throw std::out_of_range("Index out of range");
        }
        return m_arr[i];
    }

    template<typename Type, size_t _size>
    const Type& Array<Type, _size>::operator[](int i) const {
        if (i < 0 || i >= _size) {
            throw std::out_of_range("Index out of range");
        }
        return m_arr[i];
    }

    template<typename Type, size_t _size>
    Array<Type, _size>& Array<Type, _size>::operator=(const Array& another_array)  {
        for (int i = 0; i < _size; i++) {
            m_arr[i] = another_array[i];
        }
        return *this;
    }

}