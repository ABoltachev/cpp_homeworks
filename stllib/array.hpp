#pragma once

#include <initializer_list>

template<typename T, size_t Size>
class array {
	T items_[Size];
public:
	array() {}
		array(array<T, Size> const& other) {
		for (size_t i = 0; i < Size; ++i)
			items_[i] = other.items_[i];
	}
		array(std::initializer_list<T> list) {
		size_t idx = 0;
		for (auto& i : list) {
			items_[idx] = i;
			++idx;
		}
		for (size_t i = idx; i < Size; ++i)
			items_[i] = 0;
	}
	~array() {}

		array<T, Size>& operator=(array<T, Size> const& other)noexcept {
		for (size_t i = 0; i < Size; ++i)
			items_[i] = other.items_[i];
		return *this;
	}


	size_t size()const noexcept {
		return Size;
	}
	bool empty()const noexcept {
		return Size == 0;
	}
	T& operator[](size_t idx)noexcept {
		return items_[idx];
	}
	const T& operator[](size_t idx)const noexcept {
		return items_[idx];
	}
};