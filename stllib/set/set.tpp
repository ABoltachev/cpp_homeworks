#pragma once

#include "set.h"

template<class T>
cnt::set<T>::set() : head(nullptr), size_(0) {}

template<class T>
cnt::set<T>::set(const set &set_) : head(nullptr), size_(0) {
    for (const auto &value: set_) {
        insert(value);
    }
}

template<class T>
cnt::set<T>::set(cnt::set<T> &&set_) noexcept : head(set_.head), size_(set_.size_) {
    set_.head = nullptr;
    set_.size_ = 0;
}

template<class T>
cnt::set<T>::set(std::initializer_list<T> list) : head(nullptr), size_(0) {
    for (const auto &value: list) {
        insert(value);
    }
}

template<class T>
cnt::set<T> &cnt::set<T>::operator=(const cnt::set<T> &set_) {
    clear();
    for (const auto &value: set_) {
        insert(value);
    }
    return *this;
}

template<class T>
cnt::set<T> &cnt::set<T>::operator=(cnt::set<T> &&set_) noexcept {
    clear();

    head = set_.head;
    size_ = set_.size_;
    set_.head = nullptr;
    set_.size_ = 0;

    return *this;
}

template<class T>
cnt::set<T>::~set() {
    clear();
}

template<class T>
size_t cnt::set<T>::size() const noexcept {
    return size_;
}

template<class T>
bool cnt::set<T>::empty() const noexcept {
    return size_ == 0;
}

template<class T>
T cnt::set<T>::top() const {
    if (!head) {
        throw std::invalid_argument("set is empty");
    }
    Node *node = head;
    while (node->right) {
        node = node->right;
    }
    return node->value;
}

template<class T>
T cnt::set<T>::min() const {
    if (head != nullptr) {
        Node *node = head;
        while (node->left != nullptr) {
            node = node->left;
        }
        return node->value;
    }
    throw std::invalid_argument("set is empty");
}

template<class T>
bool cnt::set<T>::find(const T &el) const {
    Node *node = head;
    while (node) {
        if (el == node->value) {
            return true;
        }
        if (el < node->value) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return false;
}

template<class T>
void cnt::set<T>::insert(const T &el) {
    Node **node = &head;
    while (*node) {
        if (el == (*node)->value) {
            return;
        }
        if (el < (*node)->value) {
            node = &(*node)->left;
        } else {
            node = &(*node)->right;
        }
    }
    *node = new Node(el);
    ++size_;
}

template<class T>
void cnt::set<T>::emplace(const T &&el) {
    Node **node = &head;
    while (*node) {
        if (el == (*node)->value) {
            return;
        }
        if (el < (*node)->value) {
            node = &(*node)->left;
        } else {
            node = &(*node)->right;
        }
    }
    *node = new Node(std::move(el));
    ++size_;
}

template<class T>
void cnt::set<T>::clear() {
    clearAdditionally(head);
    head = nullptr;
    size_ = 0;
}

template<class T>
void cnt::set<T>::clearAdditionally(const set::Node *node) {
    if (node != nullptr) {
        clearAdditionally(node->left);
        clearAdditionally(node->right);
        delete node;
    }
}
