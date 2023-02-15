#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include"array.hpp"
#include"vector.hpp"

template<typename Data, size_t size>
void sort(Array<Data, size>& arr);

template<typename Data, size_t size>
Data max(Array<Data, size>& arr);

template<typename Data, size_t size>
Data min(Array<Data, size>& arr);

template<typename Data, size_t size>
Data& find(Array<Data, size>& arr, const Data& sym);

template<typename Data>
void sort(Vector<Data>& vec);

template<typename Data>
Data max(Vector<Data>& vec);

template<typename Data>
Data min(Vector<Data>& avec);

template<typename Data>
Data& find(Vector<Data>& vec, const Data& sym);

#include "algorithms.tpp"

#endif
