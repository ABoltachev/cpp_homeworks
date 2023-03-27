#ifndef COLLECTIONS_STATICARRAY_HPP
#define COLLECTIONS_STATICARRAY_HPP

#include <cstdio>
#include <cstdint>
#include <initializer_list>
#include <iostream>

namespace StaticArrayLib {
    template <class T, size_t _size>
    class [[maybe_unused]] Array {
    private:
        T m_arr[_size];
        size_t m_size = _size;

    public:
        // Constructors
        Array() = default;
        [[maybe_unused]] Array(const std::initializer_list<T>& init_list);
        [[maybe_unused]] Array(const Array& new_arr) = default;

        ~Array() = default;

        // Methods
        [[maybe_unused]] [[nodiscard]] bool empty() const;
        [[maybe_unused]] [[nodiscard]] int size() const;

        // Operators
        T& operator[](size_t id);
        const T& operator[](size_t id) const;
    };
}

#include "StaticArray.tpp"

#endif // COLLECTIONS_STATICARRAY_HPP