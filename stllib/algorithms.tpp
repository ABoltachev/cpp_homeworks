#pragma once
#include "algorithms.hpp"
#include "array.hpp"
#include "vector.hpp"
#include "set.tpp"
#include "set.hpp"
#include <exception>
template<class T, size_t len>
void sort(Array<T, len>& container)
{
    for (int i = 0; i < container.size()-1; i++)
        for (int j = 0; j < container.size()-i-1; j++)
            if (container[j] > container[j+1])
            {
                T temp = container[j];
                container[j] = container[j+1];
                container[j+1] = temp;
            }
}
template<class T>
void sort(Vector<T>& container)
{
    for (int i = 0; i < container.size()-1; i++)
        for (int j = 0; j < container.size()-i-1; j++)
            if (container[j] > container[j+1])
            {
                T temp = container[j];
                container[j] = container[j+1];
                container[j+1] = temp;
            }
}
template<class T>
auto min(T container)
{
    if (container.size() == 0)
        throw std::out_of_range("container is empty");
    auto result = container[0];
    for (int i = 1; i < container.size(); i++)
        if (result > container[i])
            result = container[i];
    return result;
}
template<class data_type>
data_type min(Set<data_type> set)
{
    if (set.size() == 0)
        throw std::out_of_range("container is empty");
    typename Set<data_type>::Node* curr_node = set._head_;
    while(curr_node->left)
    {
        curr_node = curr_node->left;
    }
    return curr_node->data;
}
template <class T>
auto max(T container)
{
    if (container.size() == 0)
        throw std::length_error("container is empty");
    auto result = container[0];
    for (int i = 1; i < container.size(); i++)
        if (result < container[i])
            result = container[i];
    return result;
}
template <class data_type>
data_type max(Set<data_type> set)
{
    return set.top();
}
template<typename data_type, size_t len>
data_type& find (Array<data_type, len> container, data_type elem)
{
    for(int i = 0; i < container.size(); i++)
    {
        if (container[i] == elem)
            return container[i];
    }
    throw std::out_of_range("Not found");
}
template<typename data_type>
data_type& find (Vector <data_type> container, data_type elem)
{
    for(int i = 0; i < container.size(); i++)
    {
        if (container[i] == elem)
            return container[i];
    }
    throw std::out_of_range("Not found");
}
template<class data_type>
data_type& find(Set<data_type> set, data_type elem)
{
    typename Set<data_type>::Node* curr_node = set.find_in_tree(set._head_, elem);
    if (curr_node)
        return curr_node->data;
    throw std::out_of_range("Not found");
}


