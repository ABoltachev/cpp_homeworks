#ifndef COLLECTIONS_VECTOR_HPP
#define COLLECTIONS_VECTOR_HPP

#include <cstdio>
#include <initializer_list>

namespace VectorLib {

    template <class T>
    class [[maybe_unused]] Vector {
    private:
        size_t m_capacity {0};
        size_t m_size {0};
        T *m_vec {nullptr};

    public:
        // Constructors
        Vector() = default;
        [[maybe_unused]] Vector(const std::initializer_list<T>& init_list);
        [[maybe_unused]] Vector(const Vector<T>& v_other);
        [[maybe_unused]] Vector(size_t _size, const T& value);
        [[maybe_unused]] explicit Vector(size_t _size);
        [[maybe_unused]] Vector(Vector&& v_other) noexcept;

        // Destructor
        ~Vector();

        // Methods
        [[maybe_unused]] [[nodiscard]] bool empty() const;
        [[maybe_unused]] [[nodiscard]] size_t size() const;
        [[maybe_unused]] [[nodiscard]] size_t capacity() const;
        [[maybe_unused]] void clear();
        [[maybe_unused]] void push_back(const T& value);
        [[maybe_unused]] void emplace_back(T&& value);
        [[maybe_unused]] void resize(size_t _size, const T& x = 0);

        // Operators
        [[maybe_unused]] Vector<T> &operator=(const Vector<T>& v_other);
        [[maybe_unused]] Vector<T> &operator=(Vector&& v_other) noexcept;
        T& operator[](size_t id);
        const T& operator[](size_t id) const;
    };
}

#include "Vector.tpp"
#endif // COLLECTIONS_VECTOR_HPP