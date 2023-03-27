#ifndef ARRAY_TPP
#define ARRAY_TPP

namespace lib {
   template <typename T, size_t arr_size>
    Array<T, arr_size>::Array() : m_size(arr_size) {}

    template <typename T, size_t arr_size>
    Array<T, arr_size>::Array(std::initializer_list<T> list) : Array()
    {
        size_t i = 0;
        for (auto x : list)
        {
            m_array[i++] = x;
        }
    }

    template <typename T, size_t arr_size>
    Array<T, arr_size>& Array<T, arr_size>::operator=(const Array<T, arr_size>& arr)
    {
        for (int i = 0; i < arr.m_size; ++i)
            m_array[i] = arr.m_array[i];

        return *this;
    }

    template <typename T, size_t arr_size>
    T& Array<T, arr_size>::operator[](size_t ind)
    {
        if (ind < 0 || ind >= m_size) {
            throw std::out_of_range("Index is out of range array");
        }
        return m_array[ind];
    }

    template <typename T, size_t arr_size>
    const T& Array<T, arr_size>::operator[](size_t ind) const
    {
        if (ind < 0 || ind >= m_size) {
            throw std::out_of_range("Index is out of range array");
        }
        return m_array[ind];
    }

    template <typename T, size_t arr_size>
    size_t Array<T, arr_size>::size() const
    {
        return m_size;
    }

    template <typename T, size_t arr_size>
    bool Array<T, arr_size>::empty() const
    {
        return m_size == 0;
    }

}  

#endif