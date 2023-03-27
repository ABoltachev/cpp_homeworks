#pragma once

#include <initializer_list>

namespace cnt {
    template<class T, size_t N>
    class array {
        T arr[N];

    public:
        array() = default;
        array(const std::initializer_list<T> &list);
        ~array() = default;

        [[nodiscard]] size_t size() const noexcept;
        [[nodiscard]] bool empty() const noexcept;

        array<T, N>& operator=(const array<T, N>& arr_);

        T &operator[](std::size_t id);
        const T &operator[](std::size_t id) const;
    };
}

#include "array.tpp"
