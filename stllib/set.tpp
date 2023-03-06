#pragma once

#include <stdexcept>

namespace UberClasses {
    template<typename T>
    Node<T>::Node(const Node<T>* &new_node) {
        if (!new_node)
            throw std::logic_error("New Node does not exists");

        value = new_node->value;
        if (new_node->right)
            right = new Node(new_node->right);
        else
            right = nullptr;

        if (new_node->left)
            left = new Node(new_node->left);
        else
            left = nullptr;
    }

    // Set<T>
    template<typename T>
    Set<T>::Set(std::initializer_list<T>& list) {
        for (auto &elem: list)
            insert(elem);
    }

    template<typename T>
    bool Set<T>::find(const T& elem) {
        if (!m_root)
            throw std::out_of_range("Set is empty");

        Node<T>* tmpPtr = m_root;
        while (tmpPtr) {
            if (tmpPtr->value == elem)
                return true;

            if (tmpPtr->value < elem)
                tmpPtr = tmpPtr->right;
            else
                tmpPtr = tmpPtr->left;
        }
        return false;
    }

    template<typename T>
    T& Set<T>::top() {
        if (!m_root)
            throw std::out_of_range("Set is empty");

        Node<T>* tmpPtr = m_root;
        while (tmpPtr->right != nullptr)
            tmpPtr = tmpPtr->right;
        return (*tmpPtr).value;
    }

    template<typename T>
    void Set<T>::insert(const T& elem) {
        if (!m_root) {
            m_root = new Node(elem);
            m_size += 1;
            return;
        }

        Node<T>* tmpPtr = m_root;
        while (tmpPtr->left != tmpPtr->right) {
            if (tmpPtr->value == elem)
                return;
            if (tmpPtr->value < elem) {
                if (tmpPtr->right)
                    tmpPtr = tmpPtr->right;
                else
                    break;
            }
            else if (tmpPtr->value > elem) {
                if (tmpPtr->left)
                    tmpPtr = tmpPtr->left;
                else
                    break;
            }
        }
        if (tmpPtr->value < elem)
            tmpPtr->right = new Node(elem);
        else
            tmpPtr->left = new Node(elem);
        m_size += 1;
    }

    template<typename T>
    void Set<T>::emplace(T&& elem) {
        if (!m_root) {
            m_root = new Node(std::move(elem));
            m_size += 1;
            return;
        }

        Node<T>* tmpPtr = m_root;
        while (tmpPtr->left != tmpPtr->right) {
            if (tmpPtr->value == elem)
                return;
            if (tmpPtr->value < elem) {
                if (tmpPtr->right)
                    tmpPtr = tmpPtr->right;
                else
                    break;
            }
            else if (tmpPtr->value > elem) {
                if (tmpPtr->left)
                    tmpPtr = tmpPtr->left;
                else
                    break;
            }
        }
        if (tmpPtr->value < elem)
            tmpPtr->right = new Node(std::move(elem));
        else
            tmpPtr->left = new Node(std::move(elem));
        m_size += 1;
    }


    template<typename T>
    Set<T>& Set<T>::operator= (const Set<T>& another) {
        m_size = another.size;
        if (this != &another) {
            clear();
            m_root = another.copyTree();
        }
        return *this;
    }

    template<typename T>
    Set<T>& Set<T>::operator= (Set<T>&& another) {
        m_root = another.root;
        m_size = another.size;
        another.root = nullptr;
        another.size = 0;
        return *this;
    }

    template<typename T>
    Node<T>* Set<T>::copyTree() {
        return (m_root) ? new Node(m_root): nullptr;
    }
}
