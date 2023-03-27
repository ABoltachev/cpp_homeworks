#pragma once
#include<iostream>

template<typename T, size_t Size_>
class Array {
	T m_arr[Size_];
	size_t m_size = Size_;
public:
	Array();
	Array(std::initializer_list<T>& init_list);
	Array(const Array<T, Size_>& other);
	Array<T,Size_>& operator=(const Array<T, Size_>& other);

	size_t size() const;
	bool empty() const;

	T& operator[](size_t& index);
	const T& operator[](size_t& index) const;
	~Array();
};

#include"Array.tpp"
