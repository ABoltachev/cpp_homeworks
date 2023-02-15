#pragma once

#include "vector.h"
#include "array.h"
#include <iostream>

/*
    На вход каждого алгоритма подается контейнер, который вы реализовали
     * sort (простая сортировка, либо пузырьком, либо вставками)
     * max; min (поиск максимума и минимума соответственно)
     * find (поиск элемента, возвращает ссылку на элемент, либо бросает исключение runtime_error, если не нашло элемент)
    
    Доп задание (доп бал):
    Реализовать функцию range (аналог функции из Python) по аналогии с функцией enumerate с семинара
    Должно быть 2 перегрузки:
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