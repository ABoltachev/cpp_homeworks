#ifndef HW2_VECTOR_H
#define HW2_VECTOR_H

#include <iostream>

template<typename T>
class Vector {
private:
    T *vec = nullptr;
    std::size_t m_size;
    std::size_t m_capacity;
public:
    size_t size();

    bool empty();

    T &operator[](std::size_t index);

    void push_back(const T &obj);

    void emplace_back(T &&obj);

    void clear();

    void resize(std::size_t size, const T &obj = T());

    Vector &operator=(const Vector<T> &n_vec);

    Vector &operator=(Vector<T> &&n_vec);

    Vector(const Vector &n_vec);

    Vector(Vector &&n_vec);

    Vector() = default;

    Vector(std::size_t size, const T &obj);

    Vector(std::initializer_list<T> list);

    void expand();
};

#endif //HW2_VECTOR_H
