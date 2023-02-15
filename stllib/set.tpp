#include "set.hpp"

template <typename T>
Set<T>::Set() : root(nullptr), size_(0) {}

template <typename T>
Set<T>::Set(const Set &other) : root(nullptr), size_(0) {
    for (const auto &value : other) {
        insert(value);
    }
}

template <typename T>
Set<T>::Set(Set &&other) noexcept : root(other.root), size_(other.size_) {
    other.root = nullptr;
    other.size_ = 0;
}

template <typename T>
Set<T>::Set(std::initializer_list<T> list) : root(nullptr), size_(0) {
    for (const auto &value : list) {
        insert(value);
    }
}

template <typename T>
Set<T> &Set<T>::operator=(const Set &other) {
    clear();
    for (const auto &value : other) {
        insert(value);
    }
    return *this;
}

template <typename T>
Set<T> &Set<T>::operator=(Set &&other) noexcept {
    clear();
    root = other.root;
    size_ = other.size_;
    other.root = nullptr;
    other.size_ = 0;
    return *this;
}

template <typename T>
Set<T>::~Set() {
    clear();
}

template <typename T>
std::size_t Set<T>::size() const {
    return size_;
}

template <typename T>
bool Set<T>::empty() const {
    return !root;
}

template <typename T>
T Set<T>::top() const {
    if (!root) {
        throw std::out_of_range("Set is empty");
    }
    Node *node = root;
    while (node->right) {
        node = node->right;
    }
    return node->data;
}

template <typename T>
T Set<T>::min() const {
    if (root != nullptr) {
        Node *node = root;
        while (node->left != nullptr) {
            node = node->left;
        }
        return node->data;
    }
    throw std::out_of_range("Set is empty");
}

template <typename T>
bool Set<T>::find(const T &value) const {
    Node *node = root;
    while (node) {
        if (value == node->data) {
            return true;
        } else if (value < node->data) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return false;
}

template<typename T>
typename Set<T>::Node *Set<T>::find_node(Node* node, const T& value) const {
    if ((node == nullptr) || (node->data == value)) {
        return node;
    }
    if (value > node->data) {
        return find_node(node->right, value);
    }
    return find_node(node->left, value);
}

template<typename T>
typename Set<T>::Node *Set<T>::find_n(const T &value) const {
    return find_node(root, value);
}

template <typename T>
void Set<T>::insert(const T &value) {
    Node **node = &root;
    while (*node) {
        if (value == (*node)->data) {
            return;
        } else if (value < (*node)->data) {
            node = &(*node)->left;
        } else {
            node = &(*node)->right;
        }
    }
    *node = new Node(value);
    ++size_;
}

template <typename T>
void Set<T>::emplace(T &&value) {
    Node **node = &root;
    while (*node) {
        if (value == (*node)->data) {
            return;
        } else if (value < (*node)->data) {
            node = &(*node)->left;
        } else {
            node = &(*node)->right;
        }
    }
    *node = new Node(std::move(value));
    ++size_;
}

template <typename T>
void Set<T>::clear() {
    clearTree(root);
    root = nullptr;
    size_ = 0;
}

template<typename T>
void Set<T>::clearTree(Set::Node *node) {
    if (node != nullptr) {
        clearTree(node->left);
        clearTree(node->right);
        delete node;
    }
}
