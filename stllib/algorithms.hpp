/*
На вход каждого алгоритма подается контейнер, который вы реализовали
 * sort (простая сортировка, либо пузырьком, либо вставками)
 * max; min (поиск максимума и минимума соответственно)
 * find (поиск элемента, возвращает ссылку на элемент, либо бросает исключение runtime_error, если не нашло элемент)

Доп задание (доп бал):
    Реализовать функцию range (аналог функции из Python) по аналогии с функцией enumerate с семинара
    Должно быть 2 перегрузки
     * range(int stop)
     * range(int start, int stop, int step=1)
*/

#pragma once

#include "MyArray.hpp"
#include "MyVector.hpp"
#include "MySet.hpp"

namespace UberAlgorithms {
    using namespace UberClasses;

    template<typename T, size_t size>
    void sort(Array<T, size>& cont);

    template<typename T>
    void sort(Vector<T>& cont);

    template<typename T, size_t size>
    T& min(Array<T, size>& cont);

    template<typename T, size_t size>
    T& max(Array<T, size>& cont);

    template<typename T, size_t size>
    T& find(Array<T, size>& cont, const T& elem);

    template<typename T>
    T& min(Vector<T>& cont);

    template<typename T>
    T& max(Vector<T>& cont);

    template<typename T>
    T& find(Vector<T>& cont, const T& elem);

    template<typename T>
    T& min(Set<T>& cont);

    template<typename T>
    T& max(Set<T>& cont);

    template<typename T>
    T& find(Set<T>& cont, const T& elem);
}

#include "algorithms.tpp"