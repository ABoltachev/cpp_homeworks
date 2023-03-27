#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

template <class T>
class vector {
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

	vector() {
		Size = 0; Capacity = 1;
		data = new value_type[Capacity];
	}

	vector(size_type n, value_type el) {
		Size = n; Capacity = n;
		data = new value_type[Size];
		for (int i = 0; i < Size; i++) {
			data[i] = el;
		}
	}

	vector(std::initializer_list<value_type> l) {
		Size = l.size(); Capacity = l.size();
		data = new value_type[Size];
		std::copy(l.begin(), l.end(), data);
	}

	vector(const vector<T>& other) {
		Size = other.Size;
		Capacity = other.Capacity;
		data = new value_type[Capacity];
		std::copy(other.data, other.data + other.Size, data);
	}

	~vector() {
		delete[] data;
	}

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

	void push_back(value_type el) {
		if (Size >= Capacity) {
			Capacity *= 2;
			value_type* to_copy = new value_type[Capacity];
			std::copy(data, data + Size, to_copy);
			delete[] data;
			data = to_copy;
		}
		data[Size] = el;
		Size++;
	}
	template<class... Args>
	void emplace_back(Args&&... args) {
		if (Size >= Capacity) {
			Capacity *= 2;
			value_type* to_copy = new value_type[Capacity];
			std::copy(data, data + Size, to_copy);
			delete[] data;
			data = to_copy;
		}
		data[Size] = T(args...);
		Size++;
	}

	void resize(size_type rSize, value_type el) {
		Capacity = rSize;
		value_type* to_copy = new value_type[Capacity];
		std::copy(data, data + Size, to_copy);
		delete[] data;
		data = to_copy;
		while (Size != rSize) {
			emplace_back(el);
		}
	}

	void clear() {
		Size = 0;
	}

	vector& operator=(const vector& other) {
		if (this == &other) {
			return *this;
		}
		vector<T> tmp(other);
		std::swap(Size, tmp.Size);
		std::swap(Capacity, tmp.Capacity);
		std::swap(data, tmp.data);
		return *this;
	}

	vector& operator=(vector&& other) {
		Size = std::move(other.Size);
		Capacity = std::move(other.Capacity);
		data = std::move(other.data);
		return *this;
	}

private:
	size_type Capacity;
	size_type Size;
	pointer data;
};

#endif // VECTOR_HPP