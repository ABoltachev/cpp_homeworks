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

#include <iostream>
#include <stdexcept>

#include "array.hpp"
#include "set.hpp"
#include "vector.hpp"
namespace stl
{

template <typename T, size_t _size>
void sort(Array<T, _size>& array);

template <typename T>
void sort(Vector<T>& vector);

template <typename T, size_t _size>
T& min(const Array<T, _size>& array);

template <typename T, size_t _size>
T& max(const Array<T, _size>& array);

template <typename T>
T& min(const Vector<T>& vector);

template <typename T>
T& max(const Vector<T>& vector);

template <typename T>
T& min(const Set<T>& set);

template <typename T>
T& max(const Set<T>& set);

template <typename T, size_t _size>
T& find(const Array<T, _size>& array, const T& value);

template <typename T>
T& find(const Vector<T>& vector, const T& value);

template <typename T>
T& find(const Set<T>& set, const T& value);
}  // namespace stl

#include "alghoritms.tpp"