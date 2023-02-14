#include "set.hpp"

namespace stl
{

template <typename T>
Set<T>::Set() : m_root(nullptr), m_size(0)
{
}

template <typename T>
Set<T>::Set(std::initializer_list<T> list) : Set()
{
    for (auto it : list) {
        implInsert(m_root, it);
    }
}

template <typename T>
void Set<T>::implCopy(Node<T>*& root, Node<T>* copyNode)
{
    if (copyNode == nullptr)
        return;

    root = new Node<T>{copyNode->data};
    implCopy(root->left, copyNode->left);
    implCopy(root->right, copyNode->right);
}

template <typename T>
Set<T>::Set(const Set<T>& set) : Set()
{
    implCopy(m_root, set.m_root);
    m_size = set.m_size;
}

template <typename T>
Set<T>::Set(Set<T>&& set) : Set()
{
    m_root = set.m_root;
    m_size = set.m_size;
}

template <typename T>
Set<T>& Set<T>::operator=(const Set<T>& set)
{
    if (&set == this) {
        return *this;
    }
    clear();

    implCopy(m_root, set.m_root);
    m_size = set.m_size;

    return *this;
}

template <typename T>
Set<T>& Set<T>::operator=(Set<T>&& set)
{
    if (&set == this) {
        return *this;
    }
    clear();
    m_root = set.m_root;
    m_size = set.m_size;

    set.m_root = nullptr;
    set.m_size = 0;

    return *this;
}

template <typename T>
size_t Set<T>::size() const
{
    return m_size;
}
template <typename T>
bool Set<T>::empty() const
{
    return m_size == 0;
}

template <typename T>
T& Set<T>::implTop(Node<T>* root) const
{
    if (!root->right)
        return root->data;
    return implTop(root->right);
}

template <typename T>
T& Set<T>::top() const
{
    implTop(m_root);
}

template <typename T>
bool Set<T>::implFind(Node<T>* root, const T& value) const
{
    if (!root)
        return false;

    if (root->data == value)
        return true;

    if (value < root->data)
        return implFind(root->left, value);
    else
        return implFind(root->right, value);
}

template <typename T>
bool Set<T>::find(const T& value) const
{
    return implFind(m_root, value);
}

template <typename T>
void Set<T>::implInsert(Node<T>*& root, const T& value)
{
    if (!root) {
        root = new Node<T>{value};
        return;
    }

    if (value == root->data)
        return;

    if (value < root->data) {
        implInsert(root->left, value);
    } else {
        implInsert(root->right, value);
    }
}

template <typename T>
void Set<T>::insert(const T& value)
{
    implInsert(m_root, value);
}

template <typename T>
void Set<T>::implEmplace(Node<T>*& root, T&& value)
{
    if (!root) {
        root = new Node<T>{value};
        return;
    }

    if (value == root->data)
        return;

    if (value < root->data) {
        implEmplace(root->left, value);
    } else {
        implEmplace(root->right, value);
    }
}

template <typename T>
void Set<T>::emplace(T&& value)
{
    implEmplace(m_root, value);
}

template <typename T>
void Set<T>::implClear(Node<T>*& root)
{
    if (root == nullptr) {
        return;
    }

    implClear(root->left);
    implClear(root->right);
    delete root;
    root = nullptr;
}

template <typename T>
void Set<T>::clear()
{
    implClear(m_root);
    m_size = 0;
    m_root = nullptr;
}
// void clear() {}
}  // namespace stl
