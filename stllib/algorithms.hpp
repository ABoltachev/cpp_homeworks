#ifndef ALGO_HPP
#define ALGO_HPP


#include "array.hpp"
#include "vector.hpp"
#include "set.hpp"

typedef std::size_t size_type;

template <class T, std::size_t Size>
void sort(array<T, Size>& Array) {
    if (Array.empty())
        return;
    bool swapp = true;
    while (swapp) {
        swapp = false;
        for (size_type i = 0; i < Array.size() - 1; i++) {
            if (Array[i] > Array[i + 1]) {
                std::swap(Array[i], Array[i + 1]);
                swapp = true;
            }
        }
    }
}

template <class T>
void sort(vector<T>& Vector) {
    if (Vector.empty())
        return;
    bool swapp = true;
    while (swapp) {
        swapp = false;
        for (size_type i = 0; i < Vector.size() - 1; i++) {
            if (Vector[i] > Vector[i + 1]) {
                std::swap(Vector[i], Vector[i + 1]);
                swapp = true;
            }
        }
    }
}

template <class T, std::size_t Size>
T max(array<T, Size>& Array) {
    if (Array.empty())
        throw std::runtime_error("array is empty");
    T maximum = Array[0];
    for (size_type i = 1; i < Array.size(); i++) {
        if (maximum < Array[i])
            maximum = Array[i];
    }
    return maximum;
}

template <class T>
T max(vector<T>& Vector) {
    if (Vector.empty())
        throw std::runtime_error("vector is empty");
    T maximum = Vector[0];
    for (size_type i = 1; i < Vector.size(); i++) {
        if (maximum < Vector[i])
            maximum = Vector[i];
    }
    return maximum;
}

template <typename T>
T max(set<T>& Set) {
    if (Set.empty())
        throw std::runtime_error("set is empty");
    T max_value = Set.top();
    set<T>::Node current = Set.Head->right;
    if (current) {
        max_value = current->value;
        current = current->right;
    }
    return max_value;
}

template <class T, std::size_t Size>
T min(array<T, Size>& Array) {
    if (Array.empty())
        throw std::runtime_error("array is empty");
    T minimum = Array[0];
    for (size_type i = 1; i < Array.size(); i++) {
        if (minimum > Array[i])
            minimum = Array[i];
    }
    return minimum;
}

template <class T>
T min(vector<T>& Vector) {
    if (Vector.empty())
        throw std::runtime_error("vector is empty");
    T minimum = Vector[0];
    for (size_type i = 1; i < Vector.size(); i++) {
        if (minimum > Vector[i])
            minimum = Vector[i];
    }
    return minimum;
}

template <typename T>
T min(set<T>& Set) {
    if (Set.empty())
        throw std::runtime_error("set is empty");
    T min_value = Set.top();
    set<T>::Node* current = Set.Head->left;
    if (current) {
        min_value = current->value;
        current = current->left;
    }
    return min_value;
}

template <class T, std::size_t Size>
T& find(array<T, Size>& Array, T to_find) {
    if (Array.empty())
        throw std::runtime_error("array is empty");
    bool flag = false;
    for (size_type i = 0; i < Array.size(); i++) {
        if (Array[i] == to_find) {
            flag = true;
            return Array[i];
        }
    }
    if (!flag)
        throw std::runtime_error("there is no element to find");
}

template <class T>
T& find(vector<T>& Vector, T to_find) {
    if (Vector.empty())
        throw std::runtime_error("vector is empty");
    bool flag = false;
    for (size_type i = 0; i < Vector.size(); i++) {
        if (Vector[i] == to_find) {
            flag = true;
            return Vector[i];
        }
    }
    if (!flag)
        throw std::runtime_error("there is no element to find");
}

template <class T>
T& find(set<T>& Set, T to_find) {
    if (Set.empty())
        throw std::runtime_error("set is empty");
    set<T>::Node* current = Set.Head;
    while (current) {
        if (current->value == to_find)
            return current->value;
        if (to_find > current->value) {
            current = current->right;
        }
        if (to_find < current->value) {
            current = current->left;
        }
    }
    throw std::runtime_error("there is no element to find");
}

#endif