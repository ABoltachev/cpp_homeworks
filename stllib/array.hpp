/*
* array (статический массив) и методы для него:
    size (возвращает размер)
    empty (возвращает true если пустой)
    взятие по индексу (operator[])
    присваивание копированием
    конструкторы (конструктор с std::inizialized_list)
*/
#ifndef ARRAY_HPP

#define ARRAY_HPP

#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <iterator>

template <typename T, size_t N>
class Array;

template <typename T, size_t N>
class Array {
	size_t size_ = N;
	T* const data_ = nullptr;
public:
	Array() : size_(N), data_(new T[N]) {}
	
	Array(std::initializer_list<T> lst) : size_(lst.size()), data_(new T[size_]) {
		// static_assert(size_ <= N, "Too big initalizer list");
		auto x = lst.begin();
		for (size_t i = 0; i < size_; ++i, ++x) {
			data_[i] = *x;
		}
	}

	~Array() {
		delete[] data_;
	}

	void swap(Array& rhs) noexcept {
		std::swap(rhs.data_, data_);
		std::swap(rhs.size_, size_);
	}

	Array(const Array& rhs) : size_(rhs.size_), data_(new T[size_]) {
		// static_assert(size_ == N);
		for (size_t i = 0; i < size_; ++i) {
			data_[i] = rhs.data_[i];
		}
	}

	Array(Array&& rhs) {
		swap(rhs);
	}

	Array& operator=(const Array& rhs) {
		if (rhs != *this) {
			Array(rhs).swap(rhs);
		}
		return *this;
	}

	Array& operator=(Array&& rhs) {
		swap(rhs);
		return *this;
	}

	constexpr size_t size() const noexcept {
		return size_;
	}

	constexpr bool empty() const noexcept {
		return size_ == 0;
	}

	constexpr T const& operator[](size_t i) const {
		return data_[i];
	}

	constexpr T& operator[](size_t i) {
		return data_[i];
	}
};

template <typename T, size_t N>
std::ostream& operator<<(std::ostream& os, const Array<T, N>& rhs) {
	for (size_t i = 0; i < rhs.size(); ++i) {
		os << rhs[i] << " ";
	}
	return os;
}

#endif
