#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <class T, std::size_t Size = 0>
class array {
public:
	using value_type = T;
	using size_type = std::size_t;
	using reference = value_type&;
	using const_reference = const value_type&;
	using pointer = value_type*;
	using const_pointer = const value_type*;

	class iterator {
	public:
		iterator(pointer cptr) : ptr(cptr) {}
		reference operator*() const {
			return *ptr;
		}
		pointer operator->() {
			return ptr;
		}
		iterator& operator++() {
			ptr++;
			return *this;
		}
		iterator& operator+(iterator& other) {
			ptr += other.ptr;
			return *this;
		}
		iterator& operator-(iterator& other) {
			ptr -= other.ptr;
			return *this;
		}
		friend bool operator==(const iterator& a, const iterator& b) {
			return a.ptr == b.ptr;
		};
		friend bool operator!=(const iterator& a, const iterator& b) {
			return a.ptr != b.ptr;
		};
	private:
		pointer ptr;
	};

	iterator begin() {
		return iterator(&data[0]);
	}
	iterator end() {
		return iterator(&data[Size - 1]);
	}

	array() {}

	array(std::initializer_list<value_type> l) {
		if (l.size() <= Size) {
			std::copy(l.begin(), l.end(), std::begin(data));
		}
		else {
			throw std::runtime_error("initializer list and array sizes incompatible");
		}
	}

	array& operator=(const array& other) {
		if (this == &other) {
			return *this;
		}
		if (other.size() > Size) {
			throw std::runtime_error("size of the copied object exceeds size of the current one");
		}
		std::copy(std::begin(other.data), std::end(other.data), std::begin(data));
		return *this;
	}

	~array() = default;

	size_type size() const {
		return Size;
	}
	bool empty() const {
		if (Size == 0) return true;
		else return false;
	}
	value_type& operator[](size_type index) {
		return data[index];
	}

private:
	T data[Size];
};

#endif // ARRAY_HPP