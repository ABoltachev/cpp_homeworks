#ifndef ALGORITHM_CPP
#define ALGORITHM_CPP

#include <iostream>

namespace MyStdLib {

    template <typename T, size_t arr_size>
    MyArray<T, arr_size>& sort(MyArray<T, arr_size>& array) {
        if (arr_size > 1) {
            for (size_t i = 1; i < arr_size; ++i) {
                for (size_t j = 0; j < arr_size - i; ++j) {
                    if (array[j] > array[j + 1]) {
                        std::swap(array[j], array[j + 1]);
                    }
                }
            }
        }
        return array;
    }

    template <typename T, size_t arr_size>
    T& min(MyArray<T, arr_size>& array) {
        if (arr_size == 0) {
            throw std::out_of_range("out of range");
        }
        size_t idx_min = 0;
        for (int i = 0; i < arr_size; ++i) {
            if (array[i] < array[idx_min]) {
                idx_min = i;
            }
        }
        return array[idx_min];
    }

    template <typename T, size_t arr_size>
    T& max(MyArray<T, arr_size>& array) {
        if (arr_size == 0) {
            throw std::out_of_range("out of range");
        }
        size_t idx_max = 0;
        for (int i = 0; i < arr_size; ++i) {
            if (array[i] > array[idx_max]) {
                idx_max = i;
            }
        }
        return array[idx_max];
    }

    template <typename T, size_t arr_size>
    T& find(MyArray<T, arr_size>& array, const T& value) {
        for (int i = 0; i < arr_size; ++i) {
            if (array[i] == value) {
                return array[i];
            }
        }
        throw std::runtime_error("there is no such element");
    }

    // ---------------------------------------------------------------

    template <typename T>
    MyVector<T>& sort(MyVector<T>& vector) {
        size_t s_size = vector.size();
        if (s_size > 1) {
            for (size_t i = 1; i < s_size; ++i) {
                for (size_t j = 0; j < s_size - i; ++j) {
                    if (vector[j] > vector[j + 1]) {
                        std::swap(vector[j], vector[j + 1]);
                    }
                }
            }
        }
        return vector;
    }

    template <typename T>
    T& min(MyVector<T>& vector) {
        if (vector.size() == 0) {
            throw std::out_of_range("out of range");
        }
        size_t idx_min = 0;
        for (int i = 0; i < vector.size(); ++i) {
            if (vector[i] < vector[idx_min]) {
                idx_min = i;
            }
        }
        return vector[idx_min];
    }

    template <typename T>
    T& max(MyVector<T>& vector) {
        if (vector.size() == 0) {
            throw std::out_of_range("out of range");
        }
        size_t idx_max = 0;
        for (int i = 0; i < vector.size(); ++i) {
            if (vector[i] > vector[idx_max]) {
                idx_max = i;
            }
        }
        return vector[idx_max];
    }

    template <typename T>
    T& find(MyVector<T>& vector, const T& value) {
        for (int i = 0; i < vector.size(); ++i) {
            if (vector[i] == value) {
                return vector[i];
            }
        }
        throw std::runtime_error("there is no such element");
    }

    // ----------------------------------------------------------------

    template <typename T>
    T& min(MySet<T>& set) {
        return set.bottom();
    }

    template <typename T>
    T& max(MySet<T>& set) {
        return set.top();
    }

    template <typename T>
    T& find(MySet<T>& set, const T& value) {
        return set.elem_find(value);
    }

}

#endif