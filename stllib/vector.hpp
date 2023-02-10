#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <stdexcept>

namespace lib
{
template <typename T>
class Vector
{
   private:
    T* m_array;
    size_t m_size;
    size_t m_max_size;

    void checkIndex(size_t index) const;

    void checkSize(size_t size) const;

   public:
    Vector();
    Vector(const size_t size, const T value);
    Vector(std::initializer_list<T> list);

    Vector(const Vector& vector);
    Vector(Vector&& vector);

    Vector& operator=(const Vector& vector);
    Vector& operator=(Vector&& vector);

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    void push_back(const T& value);
    void emplace_back(T&& value);

    size_t size() const;
    bool empty() const;

    void clear();
    void resize(const size_t size, const T value);
};

}  // namespace lib

#include "vector.tpp"

#endif