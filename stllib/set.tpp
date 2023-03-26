//
// Created by home on 12.02.23.
//
#pragma once
#include "set.hpp"
template<class T>
typename Set<T>::Node* Set<T>::add_to_tree(Set<T>::Node* head, T elem)
{
    if (!head)
    {
        head = new Set<T>::Node();
        head->data = elem;
        return head;
    }
    if (elem < head->data)
        head->left = add_to_tree(head->left, elem);
    if (elem > head->data)
        head->right = add_to_tree(head->right, elem);
    return head;
}
template<class T>
typename Set<T>::Node* Set<T>::copy(Set<T>::Node* head_from)
{
    Node* head_to = nullptr;
    if(head_from) {
        head_to = add_to_tree(head_to, head_from->data);
        head_to->left = copy(head_from->left);
        head_to->right = copy(head_from->right);
    }
    return head_to;
}
template<class T>
typename Set<T>::Node* Set<T>::clear_tree(Set<T>::Node* head)
{
    if(head) {
        if (head->right)
            head->right = clear_tree(head->right);
        if (head->left)
            head->left = clear_tree(head->left);
        delete head;
    }
    return nullptr;
}
template<class T>
typename Set<T>::Node* Set<T>::find_in_tree(Set<T>::Node* head, T elem)
{
    if (head->data == elem)
        return head;
    if ((head->right)&&(find_in_tree(head->right, elem)))
        return find_in_tree(head->right, elem);
    if ((head->left)&&(find_in_tree(head->left, elem)))
        return find_in_tree(head->left, elem);
    return nullptr;
}
template<class T>
typename Set<T>::Node* Set<T>::find_node_to_emplace(Set<T>::Node* head, T elem)
{
    Set<T>::Node* curr_node = head;
    while (true) {
        if (curr_node->data == elem)
            return head;
        if (curr_node->data < elem)
        {
            if (!curr_node->left)
                return curr_node;
            else {
                curr_node = curr_node->left;
                continue;
            }
        }
        if (curr_node->data > elem)
        {
            if (!curr_node->right)
                return curr_node;
            else
            {
                curr_node = curr_node->right;
                continue;
            }
        }
    }

}
template<class T>
size_t Set<T>::size()
{
    return m_size;
}
template<class T>
bool Set<T>::empty()
{
    return m_size == 0;
}
template<class T>
bool Set<T>::find(T elem)
{
    return (find_in_tree(m_head, elem) != nullptr);
}
template<class T>
T Set<T>::top()
{
    Set<T>::Node* head = m_head;
    while(head->right)
    {
        head = head->right;
    }
    return head->data;
}
template<class T>
T Set<T>::insert(const T& elem)
{
    m_head = add_to_tree(m_head, elem);
    m_size++;
    return elem;
}
template<class T>
Set<T>::Set(const Set<T>& other)
{
    m_head = copy(other.m_head);
    m_size = other.m_size;
}
template<class T>
Set<T>::Set(Set<T>&& other)noexcept: m_head(other.m_head),m_size(other.m_size)
{
    other.m_head = nullptr;
    other.m_size = 0;
}
template<class T>
Set<T>& Set<T>::operator= (const Set<T>& other)
{
    if (&other == this)
        return *this;
    m_head = clear_tree(m_head);
    m_head = copy(other.m_head);
    m_size = other.m_size;
    return *this;
}
template<class T>
Set<T>& Set<T>::operator= (Set<T>&& other) noexcept
{
    if (&other == this)
        return *this;
    m_head = clear_tree(m_head);
    m_size = other.m_size;
    m_head= other.m_head;
    other.m_head = nullptr;
    other.m_size = 0;
    return *this;
}
template<class T>
template<typename...Args>
T Set<T>::emplace(Args&&...args)
{
    Set<T>::Node* curr_node = find_node_to_emplace(m_head,T(std::forward<Args>(args)...));
    if (curr_node->data < T(std::forward<Args>(args)...))
    {
        curr_node->right = new Set<T>::Node();
        curr_node->right->data = T(std::forward<Args>(args)...);
    }
    if (curr_node->data > T(std::forward<Args>(args)...))
    {
        curr_node->left = new Set<T>::Node();
        curr_node->left->data = T(std::forward<Args>(args)...);
    }
    return T(std::forward<Args>(args)...);
}
template<class T>
Set<T>::Set(const std::initializer_list<T>& l)
{
    m_size = l.size();
    int i = 0;
    for(const auto elem: l)
    {
        m_head = add_to_tree(m_head, elem);
    }
}
template<class T>
void Set<T>::clear()
{
    m_head = clear_tree(m_head);
    m_size = 0;
}