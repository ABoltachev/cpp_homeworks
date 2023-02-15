#pragma once


template <typename T>
container::vector<T>::vector(size_t size, const T& element) {
    expand_vector(size * 2);
    size_ = size;
    for (int i = 0; i < size; i++) {
        vec_[i] = element;
    }
}


template <typename T>
container::vector<T>::vector(const vector<T> &vec) {
    copy_vector(vec);
}


template <typename T>
container::vector<T>::vector(vector <T> &&vec) noexcept {
    vec_ = vec.vec_;
    size_ = vec.size_;
    capacity_ = vec._capacity;
    vec._capacity = 0;
}

template <typename T>
container::vector<T>::vector(const std::initializer_list<T>& list) {
    expand_vector(list.size() * 2);
    size_ = list.size();
    int i = 0;
    for (auto elem: list) {
        vec_[i++] = elem;
    }
}


template <typename T>
size_t container::vector<T>::size() const {
    return size_;
}


template <typename T>
bool container::vector<T>::empty() const {
    return (size_ == 0);
}


template <typename T>
const T& container::vector<T>::operator[](int i) const {
    if (i >= size_) {
        throw std::out_of_range("Vector index out of range");
    }
    return vec_[i];
}


template <typename T>
T& container::vector<T>::operator[](int i) {
    if (i >= size_) {
        throw std::out_of_range("Vector index out of range");
    }
    return vec_[i];
}


template <typename T>
void container::vector<T>::push_back(const T &element) {
    if (size_ == capacity_) {
        expand_vector(capacity_ * 2);
    }
    vec_[size_++] = element;
}


template <typename T>
void container::vector<T>::emplace_back(T&& element) {
    if (size_ == capacity_) {
        expand_vector(capacity_ * 2);
    }
    vec_[size_++] = element;
}


template <typename T>
container::vector<T>& container::vector<T>::operator=(const vector <T> &vec) {
    copy_vector(vec);
    return *this;
}


template <typename T>
container::vector<T>& container::vector<T>::operator=(vector <T> &&vec) noexcept {
    clear();
    vec_ = vec.vec_;
    size_ = vec.size_;
    capacity_ = vec._capacity;
    vec._capacity = 0;
    return *this;
}


template <typename T>
void container::vector<T>::clear() {
    if (capacity_ != 0) {
        delete[] vec_;
    }
}


template <typename T>
container::vector<T>::~vector() {
    clear();
}


template <typename T>
void container::vector<T>::resize(size_t size, const T& element) {
    if (size_ > size) {
        size_ = size;
    }
    else {
        if (size > capacity_) {
            expand_vector(size * 2);
        }
        size_ = size;
    }
    for (int i = 0; i < size_; i++) {
        vec_[i] = element;
    }
}


template <typename T>
void container::vector<T>::expand_vector(size_t new_capacity) {
    T* new_vec = new T[new_capacity];
    for (int i = 0; i < size_; i++) {
        new_vec[i] = vec_[i];
    }
    delete[] vec_;
    vec_ = new_vec;
    capacity_ = new_capacity;
}


template <typename T>
void container::vector<T>::copy_vector(const vector <T> &vec) {
    if (capacity_ < vec.size()) {
        expand_vector(vec.size() * 2);
    }
    size_ = vec.size();
    for (int i = 0; i < size_; i++) {
        vec_[i] = vec[i];
    }
}