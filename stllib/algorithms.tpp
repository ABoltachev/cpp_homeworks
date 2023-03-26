#include "algorithms.hpp"

//array
template <typename T, std::size_t N>
void sort(Array<T, N>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T, std::size_t N>
T max(Array<T, N>& arr) {
    T m = arr[0];
    T max_val = m;
    for (size_t i = 1; i < N; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

template <typename T, std::size_t N>
T min(Array<T, N>& arr) {
    T min_val = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }
    return min_val;
}

template <typename T, std::size_t N>
T& find(Array<T, N>& arr, const T& val) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == val) {
            return arr[i];
        }
    }
    throw std::runtime_error("Element not found");
}

//vector
template<typename T>
void sort(Vector<T>& vec) {
    for (int i = 0; i < vec.size() - 1; i++) {
        for (int j = 0; j < vec.size() - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                T temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}

template<typename T>
T max(Vector<T>& vec) {
    T max_val = vec[0];
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] > max_val) {
            max_val = vec[i];
        }
    }
    return max_val;
}

template<typename T>
T min(Vector<T>& vec) {
    T min_val = vec[0];
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] < min_val) {
            min_val = vec[i];
        }
    }
    return min_val;
}

template<typename T>
T& find(Vector<T>& vec, const T& val) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == val) {
            return vec[i];
        }
    }
    throw std::runtime_error("Element not found");
}

//set
template<typename T>
T min(Set<T>& arr) {
    return arr.min();
}

template<typename T>
T max(Set<T>& arr) {
    return arr.top();
}

template<typename T>
T& find(Set<T>& arr, const T& value) {

    auto node_value = arr.find_n(value);
    if (node_value) {
        return node_value->data;
    }
    throw std::runtime_error("Element not found");
}
