#include "algorithms.hpp"

namespace stl
{

template <typename T, size_t _size>
void sort(Array<T, _size>& array)
{
    if (array.empty())
        return;

    for (int i = 0; i < array.size(); i++) {
        for (int j = i + 1; j < array.size(); j++) {
            if (array[j] < array[i])
                std::swap(array[j], array[i]);
        }
    }
}

template <typename T>
void sort(Vector<T>& vector)
{
    if (vector.empty())
        return;

    for (int i = 0; i < vector.size(); i++) {
        for (int j = i + 1; j < vector.size(); j++) {
            if (vector[j] < vector[i])
                std::swap(vector[j], vector[i]);
        }
    }
}

template <typename T, size_t _size>
T& min(const Array<T, _size>& array)
{
    if (array.empty())
        throw std::range_error("Can't get min from 0 length array");

    size_t min_i = 0;
    for (int i = 1; i < array.size(); i++) {
        if (array[i] < array[min_i]) {
            min_i = i;
        }
    }
    return array[min_i];
}

template <typename T, size_t _size>
T& max(const Array<T, _size>& array)
{
    if (array.empty())
        throw std::range_error("Can't get max from 0 length array");

    size_t max_i = 0;
    for (int i = 1; i < array.size(); i++) {
        if (array[i] > array[max_i]) {
            max_i = i;
        }
    }
    return array[max_i];
}

template <typename T>
T& min(const Vector<T>& vector)
{
    if (vector.empty())
        throw std::range_error("Can't get min from 0 length vector");

    size_t min_i = 0;
    for (int i = 1; i < vector.size(); i++) {
        if (vector[i] < vector[min_i]) {
            min_i = i;
        }
    }
    return vector[min_i];
}

template <typename T>
T& max(const Vector<T>& vector)
{
    if (vector.empty())
        throw std::range_error("Can't get max from 0 length vector");

    size_t max_i = 0;
    for (int i = 1; i < vector.size(); i++) {
        if (vector[i] > vector[max_i]) {
            max_i = i;
        }
    }
    return vector[max_i];
}

template <typename T>
T& min(const Set<T>& set)
{
    return set.min();
}

template <typename T>
T& max(const Set<T>& set)
{
    return set.top();
}

template <typename T, size_t _size>
T& find(const Array<T, _size>& array, const T& value)
{
    for (int i = 0; i < array.size(); i++) {
        if (array[i] == value)
            return array[i];
    }
    throw std::runtime_error("No value found");
}

template <typename T>
T& find(const Vector<T>& vector, const T& value)
{
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i] == value)
            return vector[i];
    }
    throw std::runtime_error("No value found");
}

template <typename T>
T& find(const Set<T>& set, const T& value)
{
    try {
        return set.findValue(value);
    } catch (const std::runtime_error& e) {
        throw e;
    }
}

}  // namespace stl