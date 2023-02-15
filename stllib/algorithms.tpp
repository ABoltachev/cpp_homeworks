#pragma once

#include <exception>

namespace UberAlgorithms {
    using namespace UberClasses;

    template<typename T>
    void swap(T &a, T &b) {
        T temp { std::move(a) };
        a = std::move(b);
        b = std::move(tmp);
    }

    template<typename T, size_t size>
    void sort(Array <T, size> &cont) {
        for (int i = 0; i < cont.size(); ++i) {
            int min_index = i;
            for (int j = i + 1; j < cont.size(); ++j)
                if (cont[j] < cont[min_index])
                    min_index = j;
            swap(cont[min_index], cont[i]);
        }
    }

    template<typename T>
    void sort(Vector <T> &cont) {
        for (int i = 0; i < cont.size(); ++i) {
            int min_index = i;
            for (int j = i + 1; j < cont.size(); ++j)
                if (cont[j] < cont[min_index])
                    min_index = j;
            swap(cont[min_index], cont[i]);
        }
    }

    template<typename T, size_t size>
    T& min(Array <T, size> &cont) {
        if (cont.empty())
            throw std::length_error("Container is empty!");

        T minimum = cont[0];
        for (int i = 1; i < cont.size(); ++i)
            if (minimum > cont[i])
                minimum = cont[i];
        return minimum;
    }

    template<typename T, size_t size>
    T& max(Array <T, size> &cont) {
        if (cont.empty())
            throw std::length_error("Container is empty!");

        T maximum = cont[0];
        for (int i = 1; i < cont.size(); ++i)
            if (maximum < cont[i])
                maximum = cont[i];
        return maximum;
    }

    template<typename T, size_t size>
    T& find(Array <T, size> &cont, const T &elem) {
        if (cont.empty())
            throw std::length_error("Container is empty!");

        for (int i = 0; i < cont.size(); ++i)
            if (cont[i] == elem)
                return cont[i];

        throw std::out_of_range("Element not found!");
    }

    template<typename T>
    T& min(Vector <T> &cont) {
        if (cont.empty())
            throw std::length_error("Container is empty!");

        T minimum = cont[0];
        for (int i = 1; i < cont.size(); ++i)
            if (minimum > cont[i])
                minimum = cont[i];
        return minimum;
    }

    template<typename T>
    T& max(Vector <T> &cont) {
        if (cont.empty())
            throw std::length_error("Container is empty!");

        T maximum = cont[0];
        for (int i = 1; i < cont.size(); ++i)
            if (maximum < cont[i])
                maximum = cont[i];
        return maximum;
    }

    template<typename T>
    T& find(Vector <T> &cont, const T &elem) {
        if (cont.empty())
            throw std::length_error("Container is empty!");

        for (int i = 0; i < cont.size(); ++i)
            if (cont[i] == elem)
                return cont[i];

        throw std::out_of_range("Element not found!");
    }

    template<typename T>
    T& min(Set <T> &cont) {
        if (!cont)
            throw std::length_error("Container is empty!");
        T* minNode = m_root;
        while (minNode->left)
            minNode = minNode->left;
        return minNode->value;
    }

    template<typename T>
    T& max(Set <T> &cont) {
        if (!cont)
            throw std::length_error("Container is empty!");
        T* maxNode = m_root;
        while (maxNode->right)
            minNode = minNode->right;
        return maxNode->value;
    }

    template<typename T>
    T& find(Set<T> &cont, const T &elem) {
        if (!cont)
            throw std::length_error("Container is empty!");

        Node* tmpPtr = m_root;
        while (tmpPtr) {
            if (tmpPtr->value == elem)
                return tmpPtr->value;

            if (tmpPtr->value < elem)
                tmpPtr = tmpPtr->right;
            else
                tmpPtr = tmpPtr->left;
        }
        throw std::runtime_error("Element not found");
    }
}