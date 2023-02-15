#include "algorithms.hpp"
#include "array.hpp"
#include "vector.hpp"
#include <exception>

template<class T, size_t array_size>
void sort(stl::Array<T, array_size> &container) {
    for (int i = 1; i < container.size(); i++) {
        for (int j = i; j > 0 && container[j - 1] > container[j]; j--) {
            std::swap(container[j-1],container[j]);
        }
    }
}

template<class T>
void sort(stl::Vector<T> &container) {
    for (int i = 1; i < container.size(); i++) {
        for (int j = i; j > 0 && container[j - 1] > container[j]; j--) {
            std::swap(container[j-1],container[j]);
        }
    }
}

template<class T>
auto min(T container) {
    if (container.size() == 0)
        throw std::out_of_range("empty");
    auto result = container[0];
    for (int i = 1; i < container.size(); i++)
        if (result > container[i])
            result = container[i];
    return result;
}

template<class T>
auto max(T container) {
    if (container.size() == 0)
        throw std::length_error("empty");
    auto result = container[0];
    for (int i = 1; i < container.size(); i++)
        if (result < container[i])
            result = container[i];
    return result;
}

template<typename data_type, size_t array_size>
data_type &find(stl::Array<data_type, array_size> container, data_type elem) {
    for (int i = 0; i < container.size(); i++) {
        if (container[i] == elem)
            return container[i];
    }
    throw std::runtime_error("Not found");
}