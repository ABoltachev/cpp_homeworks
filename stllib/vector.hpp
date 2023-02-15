//* vector � ������ ��� ����(����� ������� ���������� � �������������� ������������� �������, ���� ������� �� �������, ����� �������� �������� � �����, ������ ����������� � ��� ����) :
    //    +size(���������� ������)
    //    +empty(���������� true ���� ������)
    //    +������ �� �������(operator[])
    //    +push_back(������� � �����(�����������))
    //    +emplace_back(������� � �����(�����������))
    //    +clear(�������)
    //    +resize(��������� �������, ������ ���������� ���� �������� �� ���������, ������� ����� ����������� ��� �����)
    //    +������������(����������� � ������������)
    //    +������������(����������� ��� ����������; 
    //    ������ �������� ������, ������ �� ��������� �� ���������, ������� ����� ����������� ��� �����; 
    //    �����������; �����������; ����������� � std::inizialized_list)
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <stdexcept>

namespace lib {
    template <typename T>
    class Vector
    {
    private:
        T* vect;
        size_t m_size;
        size_t max_size;
    public:
        Vector();
        Vector(size_t size, T value);
        Vector(const Vector<T>& vector);
        Vector(Vector<T>&& vector);
        Vector(std::initializer_list<T> list);

        Vector& operator=(const Vector& vector);
        Vector& operator=(Vector&& vector);

        T& operator[](size_t ind);
        const T& operator[](size_t ind) const;

        void push_back(const T& value);
        void emplace_back(T&& value);

        void clear();
        void resize(size_t size, T value);

        size_t size() const;
        bool empty() const;

        ~Vector();
    };
}

#include "vector.tpp"

#endif 
