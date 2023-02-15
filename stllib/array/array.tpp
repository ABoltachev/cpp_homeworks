#pragma once

template<class T, size_t N>
cnt::array<T, N>::array(const std::initializer_list<T> &list) {
    size_t listSize = list.size();
    if (N < listSize) {
        throw std::invalid_argument("initializer_list size is larger than array size");
    }
    int index = 0;
    for (const auto el: list) {
        arr[index] = el;
        ++index;
    }
    if (N > list.size()) {
        for (size_t j = listSize; j < N; ++j) {
            arr[j] = 0;
        }
    }
}

template<class T, size_t N>
size_t cnt::array<T, N>::size() const noexcept {
    return N;
}

template<class T, size_t N>
bool cnt::array<T, N>::empty() const noexcept {
    return N == 0;
}

template<class T, size_t N>
cnt::array<T, N> &cnt::array<T, N>::operator=(const array<T, N> &arr_) {
    if (&arr_ != this) {
        for (int i = 0; i < N; ++i) {
            arr[i] = arr_.arr[i];
        }
    }
    return *this;
}

template<class T, size_t N>
T &cnt::array<T, N>::operator[](const std::size_t id) {
    if (id >= N) {
        throw std::invalid_argument("accessing a memory area that doesn't belong to the array");
    }
    return arr[id];
}

template<class T, size_t N>
const T &cnt::array<T, N>::operator[](const std::size_t id) const {
    if (id >= N) {
        throw std::invalid_argument("accessing a memory area that doesn't belong to the array");
    }
    return arr[id];
}
