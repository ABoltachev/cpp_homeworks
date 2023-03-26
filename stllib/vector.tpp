#include "vector.hpp"

// Constructors
template<typename T>
Vector<T>::Vector()
        : data_(nullptr), size_(0), capacity_(0) {
}

template<typename T>
Vector<T>::Vector(size_t size, const T& default_value)
        : data_(new T[size]), size_(size), capacity_(size) {
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = default_value;
    }
}

template<typename T>
Vector<T>::Vector(const Vector<T>& other)
        : data_(new T[other.size_]), size_(other.size_), capacity_(other.size_) {
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

template<typename T>
Vector<T>::Vector(Vector<T>&& other)
        : data_(std::move(other.data_)), size_(other.size_), capacity_(other.capacity_) {
    other.size_ = 0;
    other.capacity_ = 0;
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> il)
        : data_(new T[il.size()]), size_(il.size()), capacity_(il.size()) {
    size_t i = 0;
    for (const T& value : il) {
        data_[i++] = value;
    }
}

// Destructor
template<typename T>
Vector<T>::~Vector() {
}

// Assignment operators
template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if (this != &other) {
        std::unique_ptr<T[]> data(new T[other.size]);
        size_ = other.size_;
        capacity_ = other.capacity_;
        for (size_t i = 0; i < size_; ++i) {
            data[i] = other.data_[i];
        }
        data_ = std::move(data);
    }
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) {
    if (this != &other) {
        data_ = std::move(other.data_);
        size_ = other.size_;
        capacity_ = other.capacity_;
        other.size_ = 0;
        other.capacity_ = 0;
    }
    return *this;
}

// Capacity
template<typename T>
size_t Vector<T>::size() const {
    return size_;
}

template<typename T>
bool Vector<T>::empty() const {
    return size_ == 0;
}

template<typename T>
void Vector<T>::resize(size_t size, const T& default_value) {
    if (size > capacity_) {
        capacity_ = size;
        std::unique_ptr<T[]> data(new T[capacity_]);
        for (size_t i = 0; i < size_; ++i) {
            data[i] = data_[i];
        }
        for (size_t i = size_; i < size; ++i) {
            data[i] = default_value;
        }
        data_ = std::move(data);
    }
    size_ = size;
}

template<typename T>
void Vector<T>::clear() {
    size_ = 0;
}

template<typename T>
T& Vector<T>::operator[](size_t index) {
    return data_[index];
}

template<typename T>
const T& Vector<T>::operator[](size_t index) const {
    return data_[index];
}

// Modifiers
template<typename T>
void Vector<T>::push_back(const T& value) {
    ExpandIfNeeded();
    data_[size_++] = value;
}

template<typename T>
void Vector<T>::emplace_back(T&& value) {
    ExpandIfNeeded();
    data_[size_++] = std::move(value);
}

template<typename T>
void Vector<T>::ExpandIfNeeded() {
    if (size_ == capacity_) {
        if (capacity_ == 0) {
            capacity_ = 1;
        } else {
            capacity_ *= 2;
        }
        std::unique_ptr<T[]> data(new T[capacity_]);
        for (size_t i = 0; i < size_; ++i) {
            data[i] = data_[i];
        }
        data_ = std::move(data);
    }
}
