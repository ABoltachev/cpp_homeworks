#pragma once

#include <iostream>

/*
    * vector � ������ ��� ���� (����� ������� ���������� � �������������� ������������� �������, ���� ������� �� �������, 
                                ����� �������� �������� � �����, ������ ����������� � ��� ����):
        size (���������� ������)
        empty (���������� true ���� ������)
        ������ �� ������� (operator[])
        push_back (������� � ����� (�����������))
        emplace_back (������� � ����� (�����������))
        clear (�������)
        resize (��������� �������, ������ ���������� ���� �������� �� ���������, ������� ����� ����������� ��� �����)
        ������������ (����������� � ������������)
        ������������ (����������� ��� ����������; ������ �������� ������, ������ �� ��������� �� ���������, 
                      ������� ����� ����������� ��� �����; �����������; �����������; ����������� � std::inizialized_list)
*/


namespace HW_2 {

    template<typename Type>
    class Vector {
    private:
        Type *m_arr = nullptr;
        size_t m_size;
        size_t m_amount;
    public:
        Vector() = default;
        Vector(size_t size, const Type& value = Type());
        Vector(const Vector& another);
        Vector(Vector&& another);
        Vector(const std::initializer_list<Type> init_list);

        size_t size() const;
        bool empty() const;

        void push_back(const Type& value);
        void emplace_back(Type&& value);
        void clear();
        void extend(size_t new_amount);
        void resize(size_t size, const Type& value = Type());

        Type& operator[](int i);
        const Type& operator[](int i) const;

        Vector& operator=(const Vector& another); // ������������ ������������
        Vector& operator=(Vector&& another); // ������������ ������������
    };

}

#include "vector.tpp"
