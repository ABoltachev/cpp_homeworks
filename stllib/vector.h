#pragma once
#include <iostream>
#include <initializer_list>

namespace container {

    template<typename T>
    class vector {
    public:
        vector(size_t size, const T &element=T());


        vector(const vector<T> &vec);


        vector(vector<T> &&vec) noexcept;


        vector(const std::initializer_list<T>& list);


        vector() = default;


        size_t size() const;

        bool empty() const;

        const T& operator[](int i) const;

        T& operator[](int i);

        void push_back(const T &element);

        void emplace_back(T &&element);

        vector &operator=(const vector<T> &vec);

        vector &operator=(vector<T> &&vec) noexcept;

        void clear();

        ~vector();

        void resize(size_t size, const T &element = T());


    private:
        size_t capacity_ = 0;
        size_t size_ = 0;
        T *vec_ = nullptr;

        void expand_vector(size_t new_capacity);

        void copy_vector(const vector<T> &vec);
    };
}


#include "vector.tpp"
