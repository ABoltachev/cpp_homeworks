#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP

#include <iostream>
#include <exception>

namespace MyStdLib {
    
    template <typename T>
    class MyVector;
    
    template <typename T>
    std::ostream& operator<<(std::ostream& out, const MyVector<T>& vector);

    template <typename T>
    void copy_vec(MyVector<T>& a, const MyVector<T>& b);

    template <typename T>
    class MyVector {
    private:
        T* values;

        size_t m_size;
        
        size_t m_capacity;
    public:    
        MyVector();

        MyVector(size_t size, const T& init_val);

        MyVector(const MyVector& vector);

        MyVector(MyVector&& vector);

        MyVector(std::initializer_list<T> list);

        size_t size() const;

        bool empty() const;

        void push_back(const T& val);

        void emplace_back(T&& val);

        void clear();

        void resize(size_t size, const T& val);

        void emplace_back(const T&& val); 

        T& operator[](size_t ind);

        const T& operator[](size_t ind) const;

        MyVector<T>& operator=(const MyVector<T>& vector);

        MyVector<T>& operator=(MyVector<T>&& vector);

        friend void copy_vec <>(MyVector<T>& a, const MyVector<T>& b);

        friend std::ostream& operator<< <>(std::ostream& out, const MyVector<T>& vector);
    };
}

#include "MyVector.tpp"

#endif