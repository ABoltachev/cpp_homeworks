//
// Created by home on 14.02.23.
//

#ifndef UNTITLED15_ALGORITHMS_HPP
#define UNTITLED15_ALGORITHMS_HPP
#pragma once
#include "set.hpp"
#include "set.tpp"

template<class T,size_t len>
void sort(Array<T, len>& container);
template<class T>
auto min(T container);
template<class data_type>
data_type min(Set<data_type> set);
template<class T>
auto max(T container);
template<class data_type>
data_type max(Set<data_type> set);
template<class data_type, size_t len>
data_type& find (Array<data_type, len> container, data_type elem);
template<class data_type>
data_type& find (Vector <data_type> container, data_type elem);
template<class data_type>
data_type& find(Set<data_type> set, data_type elem);


#include "algorithms.tpp"
#endif //UNTITLED15_ALGORITHMS_HPP
