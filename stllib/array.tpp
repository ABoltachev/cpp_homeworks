#include "array.hpp"

template <typename T, std::size_t N>
Array<T, N>::Array() {}

template <typename T, std::size_t N>
Array<T, N>::Array(std::initializer_list<T> list) {
    std::size_t i = 0;
    for (const auto& elem : list) {
        data_[i++] = elem;
    }
}

template <typename T, std::size_t N>
Array<T, N>::Array(const Array<T, N>& other) {
    for (std::size_t i = 0; i < N; i++) {
        data_[i] = other.data_[i];
    }
}

template <typename T, std::size_t N>
Array<T, N>& Array<T, N>::operator=(const Array<T, N>& other) {
    for (std::size_t i = 0; i < N; i++) {
        data_[i] = other.data_[i];
    }
    return *this;
}

template <typename T, std::size_t N>
T& Array<T, N>::operator[](std::size_t index) {
    return data_[index];
}

template <typename T, std::size_t N>
const T& Array<T, N>::operator[](std::size_t index) const {
    return data_[index];
}

template <typename T, std::size_t N>
std::size_t Array<T, N>::size() const {
    return N;
}

template <typename T, std::size_t N>
bool Array<T, N>::empty() const {
    return N == 0;
}

