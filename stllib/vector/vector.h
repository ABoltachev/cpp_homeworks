#pragma once

#include <initializer_list>

namespace cnt {
    template<class T>
    class vector {
        T *arr;
        size_t current_size_ = 0;
        size_t capacity_size_;

    public:
        vector();

        explicit vector(size_t size_, const T &value = 0);
        vector(const std::initializer_list<T> &list);
        vector(const vector<T> &ref_vector);
        vector(vector &&init) noexcept;

        vector<T> &operator=(const vector<T> &ref_vector);
        vector<T> &operator=(vector<T> &&ref_vector) noexcept;

        ~vector();

        [[nodiscard]] size_t size() const noexcept;
        [[nodiscard]] bool empty() const noexcept;
        void push_back(const T &el) noexcept;
        void emplace_back(T &&el) noexcept;
        void clear() noexcept;
        void resize(size_t size_, const T &value = 0) noexcept;

        T &operator[](std::size_t id);
        const T &operator[](std::size_t id) const;
    };
}

#include "vector.tpp"
