#pragma once

template<class T>
cnt::vector<T>::vector() {
    arr = new T[1];
    capacity_size_ = 1;
}

template<class T>
cnt::vector<T>::vector(const size_t size_, const T &value) {
    arr = new T[size_];
    capacity_size_ = size_;
    for (int i = 0; i < size_; ++i) {
        this->push_back(value);
    }
}

template<class T>
cnt::vector<T>::vector(const std::initializer_list<T> &list) {
    current_size_ = list.size();
    arr = new T[current_size_];

    int index = 0;
    for (const auto el: list) {
        arr[index] = el;
        ++index;
    }
    capacity_size_ = current_size_;
}

template<class T>
cnt::vector<T>::vector(const vector<T> &ref_vector) {
    current_size_ = ref_vector.current_size_;
    capacity_size_ = ref_vector.capacity_size_;

    arr = new T[capacity_size_];
    for (int i = 0; i < current_size_; ++i) {
        arr[i] = ref_vector[i];
    }
}

template<class T>
cnt::vector<T>::vector(vector &&init) noexcept : current_size_(init.current_size_), capacity_size_(init.capacity_size_), arr(init.arr) {
    init.arr = nullptr;
    init.current_size_ = 0;
    init.capacity_size_ = 0;
}

template<class T>
cnt::vector<T> &cnt::vector<T>::operator=(const vector<T> &ref_vector) {
    if (this != &ref_vector) {
        delete[] arr;

        current_size_ = ref_vector.current_size_;
        capacity_size_ = ref_vector.capacity_size_;

        arr = new T[current_size_];
        for (int i = 0; i < current_size_; ++i) {
            arr[i] = ref_vector[i];
        }
    }
    return *this;
}

template<class T>
cnt::vector<T> &cnt::vector<T>::operator=(vector<T> &&ref_vector) noexcept {
    if (&ref_vector != this) {
        current_size_ = ref_vector.current_size_;
        capacity_size_ = ref_vector.capacity_size_;
        arr = ref_vector.arr;

        ref_vector.arr = nullptr;
        ref_vector.current_size_ = 0;
        ref_vector.capacity_size_ = 0;
    }
    return *this;
}

template<class T>
cnt::vector<T>::~vector() {
    delete[] arr;
}

template<class T>
size_t cnt::vector<T>::size() const noexcept {
    return current_size_;
}

template<class T>
bool cnt::vector<T>::empty() const noexcept {
    return current_size_ == 0;
}

template<class T>
void cnt::vector<T>::push_back(const T &el) noexcept {
    if (current_size_ == capacity_size_) {
        size_t last_current_size = current_size_;
        resize(capacity_size_ * 2);
        current_size_ = last_current_size;
    }
    arr[current_size_++] = el;
}

template<class T>
void cnt::vector<T>::emplace_back(T &&el) noexcept {
    if (current_size_ == capacity_size_) {
        size_t last_current_size = current_size_;
        resize(capacity_size_ * 2);
        current_size_ = last_current_size;
    }
    arr[current_size_++] = std::move(el);
}

template<class T>
void cnt::vector<T>::clear() noexcept {
    current_size_ = 0;
    delete[] arr;
    arr = new T[capacity_size_];
}

template<class T>
void cnt::vector<T>::resize(const size_t size_, const T &value) noexcept {
    T *arr_new = new T[size_];
    for (int i = 0; i < std::min(current_size_, size_); ++i) {
        arr_new[i] = arr[i];
    }
    delete[] arr;
    if (size_ > capacity_size_) {
        for (int i = current_size_; i < size_; ++i) {
            arr_new[i] = value;
        }
    }
    arr = arr_new;
    current_size_ = size_;
    capacity_size_ = current_size_;
}

template<class T>
T &cnt::vector<T>::operator[](const std::size_t id) {
    if (id >= capacity_size_) {
        throw std::invalid_argument("accessing a memory area that doesn't belong to the vector");
    }
    return arr[id];
}

template<class T>
const T &cnt::vector<T>::operator[](const std::size_t id) const {
    if (id >= capacity_size_) {
        throw std::invalid_argument("accessing a memory area that doesn't belong to the vector");
    }
    return arr[id];
}
