#pragma once

#include <iostream>

/*
    * array (����������� ������) � ������ ��� ����:
        size (���������� ������)
        empty (���������� true ���� ������)
        ������ �� ������� (operator[])
        ������������ ������������
        ������������ (����������� � std::inizializer_list)
*/

namespace HW_2 {

    template<typename Type, size_t _size>
    class Array {
    private:
        Type m_arr[_size];
    public:
        Array() = default;
        Array(const std::initializer_list<Type>& init_list);

        size_t size() const;
        bool empty() const;
        Type& operator[](int i);
        const Type& operator[](int i) const;
        Array& operator=(const Array& another_array);
    };

}

#include "array.tpp"