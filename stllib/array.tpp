#pragma once

template <typename T, size_t size_>
container::array<T, size_>::array(const T &element) {
    for (int i = 0; i < size_; i++) {
        data_[i] = element;
    }
}


template <typename T, size_t size_>
container::array<T, size_>::array(const std::initializer_list<T> list) {
    int i = 0;
    for (auto element: list) {
        data_[i++] = element;
    }
}


template <typename T, size_t size_>
size_t container::array<T, size_>::size() const {
    return size_;
}


template <typename T, size_t size_>
bool container::array<T, size_>::empty() const {
    return (size_ == 0);
}


template <typename T, size_t size_>
const T& container::array<T, size_>::operator[](int i) const {
    if (i >= size_) {
        throw std::out_of_range("Array index out of range");
    }
    return data_[i];
}


template <typename T, size_t size_>
T& container::array<T, size_>::operator[](int i) {
    if (i >= size_) {
        throw std::out_of_range("Array index out of range");
    }
    return data_[i];
}


template <typename T, size_t size_>
container::array<T, size_>& container::array<T, size_>::operator=(array <T, size_> object) {
    for (int i = 0; i < size_; i++) {
        data_[i] = object[i];
    }
    return *this;
}
