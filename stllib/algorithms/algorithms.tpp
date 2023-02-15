#pragma once

#include "../set/set.h"
#include "../array/array.h"
#include "../vector/vector.h"

template<class T, size_t N>
void algorithms::sort(cnt::array<T, N> &array) noexcept {
    for (int i = 0; i < array.size() - 1; ++i) {
        for (int j = i + 1; j < array.size(); ++j) {
            if (array[i] > array[j]) {
                std::swap(array[i], array[j]);
            }
        }
    }
}

template<class T, size_t N>
T algorithms::max(const cnt::array<T, N> &array) {
    if (array.empty()) {
        throw std::runtime_error("array is empty");
    }
    T max_ = array[0];
    for (int i = 0; i < array.size(); ++i) {
        if (array[i] > max_) {
            max_ = array[i];
        }
    }
    return max_;
}

template<class T, size_t N>
T algorithms::min(const cnt::array<T, N> &array) {
    if (array.empty()) {
        throw std::runtime_error("array is empty");
    }
    T min_ = array[0];
    for (int i = 0; i < array.size(); ++i) {
        if (array[i] < min_) {
            min_ = array[i];
        }
    }
    return min_;
}

template<class T, size_t N>
T &algorithms::find(cnt::array<T, N> &array, const T &el) {
    if (array.empty()) {
        throw std::runtime_error("array is empty");
    }
    for (int i = 0; i < array.size(); ++i) {
        if (array[i] == el) {
            return array[i];
        }
    }
    throw std::runtime_error("element is not found");
}


template<class T>
void algorithms::sort(cnt::vector<T> &vector) noexcept {
    for (int i = 0; i < vector.size() - 1; ++i) {
        for (int j = i + 1; j < vector.size(); ++j) {
            if (vector[i] > vector[j]) {
                std::swap(vector[i], vector[j]);
            }
        }
    }
}

template<class T>
T algorithms::max(cnt::vector<T> &vector) {
    if (vector.empty()) {
        throw std::runtime_error("vector is empty");
    }
    T max_ = vector[0];
    for (int i = 0; i < vector.size(); ++i) {
        if (vector[i] > max_) {
            max_ = vector[i];
        }
    }
    return max_;
}

template<class T>
T algorithms::min(cnt::vector<T> &vector) {
    if (vector.empty()) {
        throw std::runtime_error("array is empty");
    }
    T min_ = vector[0];
    for (int i = 0; i < vector.size(); ++i) {
        if (vector[i] < min_) {
            min_ = vector[i];
        }
    }
    return min_;
}

template<class T>
T& algorithms::find(cnt::vector<T> &vector, const T &el) {
    if (vector.empty()) {
        throw std::runtime_error("vector is empty");
    }
    for (int i = 0; i < vector.size(); ++i) {
        if (vector[i] == el) {
            return vector[i];
        }
    }
    throw std::runtime_error("element is not found");
}


template<typename T>
T algorithms::min(cnt::set<T>& set) {
    return set.min();
}

template<typename T>
T algorithms::max(cnt::set<T>& set) {
    return set.top();
}
