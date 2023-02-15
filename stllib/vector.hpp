/*
* vector и методы для него (самая простая реализация с использованием динамического массива, если размера не хватает, чтобы добавить эелемент в конец, просто расширяется в два раза):
    size (возвращает размер)
    empty (возвращает true если пустой)
    взятие по индексу (operator[])
    push_back (вставка в конец (копирование))
    emplace_back (вставка в конце (перемещение))
    clear (очистка)
    resize (изменение размера, вторым аргументом идет аргумент по умолчанию, которым будут заполняться все места)
    присваивание (копирование и перемещением)
    конструкторы (конструктор без аргументов; первый аргумент размер, второй по умолчанию со значением, которым будут заполняться все места; копирования; перемещения; конструктор с std::inizialized_list)
*/
#ifndef VECTOR_HPP

#define VECTOR_HPP

#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <iterator>

template <typename T>
class Vector;

template <typename T>
class Vector {
	size_t size_ = 0;
	size_t capacity_ = 0;
	T* data_ = nullptr;
public:
	Vector() : size_(0), capacity_(0), data_(nullptr) {};

	Vector(size_t size, const T& def = T()) : size_(size), capacity_(size_), data_(new T[size_]) {
		for (size_t i = 0; i < size_; ++i) {
			data_[i] = def;
		}
	}

	Vector(std::initializer_list<T> lst) : size_(lst.size()), capacity_(size_), data_(new T[size_]) {
		auto x = lst.begin();
		for (size_t i = 0; i < size_; ++i, ++x) {
			data_[i] = *x;
		}
	}

	~Vector() {
		delete[] data_;
	}

	void swap(Vector& rhs) noexcept {
		std::swap(rhs.size_, size_);
		std::swap(rhs.capacity_, capacity_);
		std::swap(rhs.data_, data_);
	}

	Vector(const Vector& rhs) : size_(rhs.size_), capacity_(rhs.capacity_), data_(new T[size_]) {
		for (size_t i = 0; i < size_; ++i) {
			data_[i] = rhs.data_[i];
		}
	}

	Vector(Vector&& rhs) {
		swap(rhs);
	}

	Vector& operator=(const Vector& rhs) {
		if (rhs != *this) {
			Vector(rhs).swap(rhs);
		}
		return *this;
	}

	Vector& operator=(Vector&& rhs) {
		swap(rhs);
		return *this;
	}

	constexpr size_t size() const noexcept {
		return size_;
	}

	constexpr size_t capacity() const noexcept {
		return capacity_;
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

	void resize(size_t nsize, T const& def = T()) {
		Vector temp(nsize);
		for (size_t i = 0; i < size_ && i < nsize; ++i) {
			temp[i] = data_[i];
		}
		temp.swap(*this);
	}

	void reserve(size_t ncap) {
		Vector temp(ncap);
		size_t n = ncap < size_ ? ncap : size_;
		for (size_t i = 0; i < n; ++i) {
			temp[i] = data_[i];
		}
		temp.size_ = n;
		temp.swap(*this);
	}

	void push_back(const T& x) {
		if (size_ == capacity_) {
			reserve(size_ > 0 ? (size_ * 2) : 1);
		}
		data_[size_++] = x;
	}

	void emplace_back(const T&& x) {
		if (size_ == capacity_) {
			reserve(size_ > 0 ? (size_ * 2) : 1);
		}
		data_[size_++] = std::move(x);
	}
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& rhs) {
	std::cout << "vector {size : " << rhs.size()
		<< ", capacity : " << rhs.capacity() << "}" << std::endl;
	for (size_t i = 0; i < rhs.size(); ++i) {
		os << rhs[i] << " ";
	}
	return os;
}

#endif
