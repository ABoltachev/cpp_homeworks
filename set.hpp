//
// Created by home on 12.02.23.
//

#ifndef UNTITLED15_SET_HPP
#define UNTITLED15_SET_HPP
#pragma once
#include<iostream>
#include "algorithms.hpp"
template<class T>
class Set
{
    struct Node
    {
        T data;
        Node* left = nullptr;
        Node* right = nullptr;
    };
    size_t _size_ = 0;
    Node* _head_ = nullptr;
    static Node* add_to_tree(Node* head, T elem);
    static Node* clear_tree(Node* head);
    static Node* find_node_to_emplace(Node* head, T elem);
    static Node* copy(Node* head_from);
    static Node* find_in_tree(Node* head, T elem);
public:
    size_t size();
    bool empty();
    bool find(T elem);
    T top();
    void clear();
    T insert(const T& elem);
    template <typename... Args>
    T emplace(Args&&... args);
    Set() = default;
    Set(const Set<T>& other);
    Set(Set<T>&& other) noexcept;
    Set& operator= (const Set<T>& other);
    Set& operator= (Set<T>&& other) noexcept;
    Set(const std::initializer_list<T>& l);
    template<typename data_type>
    friend data_type min(Set<data_type> set);
    template<typename data_type>
    friend data_type max(Set<data_type> set);
    template<typename data_type>
    friend data_type& find(Set<data_type>set,  data_type elem);

};
#include "set.tpp"
#endif //UNTITLED15_SET_HPP
