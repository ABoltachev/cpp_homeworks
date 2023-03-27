#pragma once

#include <initializer_list>

template<typename T>
class vector {
	T* data_;
	size_t capacity_;
	size_t size_;

			void checkCapacity() {
		if (size_ == capacity_) {
			data_ = reinterpret_cast<T*>(realloc(data_, capacity_ * 2 * sizeof(T)));
			if (data_ == nullptr)
				throw std::bad_alloc();
			memset(data_ + size_, 0, size_);
			capacity_ *= 2;
		}
	}
public:
	vector() {
		capacity_ = 16;
		size_ = 0;
		data_ = reinterpret_cast<T*>(malloc(capacity_ * sizeof(T)));
		memset(data_, 0, capacity_ * sizeof(T));
		if (data_ == nullptr)
			throw std::bad_alloc();
	}
	vector(size_t size, T const& value) {
		capacity_ = size * 2;
		size_ = size;
		data_ = reinterpret_cast<T*>(malloc(capacity_ * sizeof(T)));
		memset(data_, 0, capacity_ * sizeof(T));
		if (data_ == nullptr)
			throw std::bad_alloc();
		for (size_t i = 0; i < size_; ++i)
			data_[i] = value;
	}
		vector(vector<T> const& other) {
		capacity_ = other.capacity_;
		size_ = other.size_;
		data_ = reinterpret_cast<T*>(malloc(capacity_ * sizeof(T)));
		memset(data_, 0, capacity_ * sizeof(T));
		if (data_ == nullptr)
			throw std::bad_alloc();
		for (size_t i = 0; i < size_; ++i)
			data_[i] = other.data_[i];
	}
		vector(vector<T>&& other)noexcept {
		capacity_ = other.capacity_;
		other.capacity_ = 0;
		size_ = other.size_;
		other.size_ = 0;
		data_ = other.data_;
		other.data_ = nullptr;
	}
	vector(std::initializer_list<T> list) {
		size_ = list.size();
		capacity_ = size_ * 2;
		data_ = reinterpret_cast<T*>(malloc(capacity_ * sizeof(T)));
		if (data_ == nullptr)
			throw std::bad_alloc();
		size_t idx = 0;
		for (auto& i : list) {
			data_[i] = i;
			++i;
		}
	}
	~vector() {
		free(data_);
	}

		vector<T>& operator=(vector<T> const& other) {
		clear();
		for (size_t i = 0; i < other.size(); ++i)
			push_back(other[i]);
		return *this;
	}
		vector<T>& operator=(vector<T>&& other)noexcept {
		capacity_ = other.capacity_;
		size_ = other.size_;
		free(data_);
		data_ = other.data_;
		other.data_ = nullptr;
		return *this;
	}

	size_t size()const noexcept {
		return size_;
	}
	bool emptty()const noexcept {
		return size_ == 0;
	}
	T& operator[](size_t idx)noexcept {
		return data_[idx];
	}
	T const& operator[](size_t idx)const noexcept {
		return data_[idx];
	}
	void push_back(T const& value) {
		checkCapacity();
		data_[size_] = value;
		++size_;
	}
	void emplace_back(T&& value) {
		checkCapacity();
		data_[size_] = std::move(value);
		++size_;
	}
	void clear() {
		size_ = 0;
	}
	void resize(size_t size, T const& value) {
		if (size < size_) {
			size_ = size;
		}
		else if (size > size_) {
			size_t const count = size - size_;
			for (size_t i = 0; i < count; ++i)
				push_back(value);
		}
	}
};