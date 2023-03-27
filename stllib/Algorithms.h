#pragma once
#include"Array.h"
#include"Vector.h"

template<typename T, size_t N>
void sort(Array<T,N>& arr);

template<typename T, size_t N>
 T min(Array<T, N>& arr);

 template<typename T, size_t N>
 T max(Array<T, N>& arr);

template<typename T, size_t N>
T& find(Array<T, N>& arr, const T& value);

/// VECTOR /////////////////////////////
template<typename T>
void sort(Vector<T>& arr);

template<typename T>
T max(Vector<T>& arr);

template<typename T>
T min(Vector<T>& arr);

template<typename T>
T& find(Vector<T>& arr, const T& value);

#include "Algorithms.tpp"