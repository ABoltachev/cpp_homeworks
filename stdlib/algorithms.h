#pragma once

#include "vector.h"
#include "array.h"
#include <iostream>

/*
    �� ���� ������� ��������� �������� ���������, ������� �� �����������
     * sort (������� ����������, ���� ���������, ���� ���������)
     * max; min (����� ��������� � �������� ��������������)
     * find (����� ��������, ���������� ������ �� �������, ���� ������� ���������� runtime_error, ���� �� ����� �������)
    
    ��� ������� (��� ���):
    ����������� ������� range (������ ������� �� Python) �� �������� � �������� enumerate � ��������
    ������ ���� 2 ����������:
     * range(int stop)
     * range(int start, int stop, int step=1)
*/
namespace HW_2 {

    // Array
    template<typename Type, size_t size>
    const Type& max(const Array<Type, size>& object);

    template<typename Type, size_t size>
    const Type& min(const Array<Type, size>& object);

    template<typename Type, size_t size>
    Type& find(const Array<Type, size>& object, const Type& value);

    template<typename Type, size_t size>
    void sort(Array<Type, size>& object, int l = 0, int r = 0);



    template<typename Type>
    const Type& max(const Vector<Type>& object);

    template<typename Type>
    const Type& min(const Vector<Type>& object);

    template<typename Type>
    Type& find(const Vector<Type>& object, const Type& value);

    template<typename Type>
    void sort(Vector<Type>& object, int l = 0, int r = 0);
}

#include "algorithms.tpp"