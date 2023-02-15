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

#ifndef ALGLIB
#define ALGLIB

#include "vector.hpp"
#include "array.hpp"
#include "set.hpp"

#include <iostream>

template<typename T, size_t aSize>
void sort(Array<T, aSize>& array);

template<typename T>
void sort(Vector<T>& vector);

template<typename T, size_t aSize>
void max(Array<T, aSize>& array);

template<typename T, class Compare>
void max(Set<T, Compare>& set);

template<typename T>
void max(Vector<T>& vector);

template<typename T, size_t aSize>
void min(Array<T, aSize>& array);

template<typename T, class Compare>
void min(Set<T, Compare>& set);

template<typename T>
void min(Vector<T>& vector);

template<typename T, size_t aSize>
T& find(Array<T, aSize>& array, T element);

// template<typename T, class Compare>
// T& find(Set<T, Compare>& set, T element);

template<typename T>
T& find(Vector<T>& vector, T element);

template<typename T, size_t aSize>
Vector<T>& range(Array<T, aSize>& array, int stop);

template<typename T>
Vector<T>& range(Vector<T>, int stop);

template<typename T, size_t aSize>
Vector<T>& range(Array<T, aSize>& array, int start, int stop, int step = 1);

template<typename T>
Vector<T>& range(Vector<T>, int start, int stop, int step=1);

#include "algorithms.tpp"
#endif
