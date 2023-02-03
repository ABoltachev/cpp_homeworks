#pragma once
#include "vector.hpp"
#include "array.hpp"

namespace algo
{
	template <typename type>
	void swap(type& a, type& b) noexcept;

//	MAX<->MIN operator<

	template<typename type>
	const type& min(const vector<type>& _vector);

	template<typename type>
	const type& max(const vector<type>& _vector);

	template<typename type, size_t _size_>
	const type& min(const array<type, _size_>& _array);

	template<typename type, size_t _size_>
	const type& max(const array<type, _size_>& _array);

//	MAX<->MIN cmp

	template<typename type>
	const type& min(const vector<type>& _vector, bool (*cmp)(type, type));

	template<typename type>
	const type& max(const vector<type>& _vector, bool (*cmp)(type, type));

	template<typename type, size_t _size_>
	const type& min(const array<type, _size_>& _array, bool (*cmp)(type, type));

	template<typename type, size_t _size_>
	const type& max(const array<type, _size_>& _array, bool (*cmp)(type, type));

// FIND
	template <typename type>
	type& find(vector<type>& _vector, const type& value);

	template <typename type, size_t _size_>
	type& find(array<type, _size_>& _array, const type& value);

// sorts
	// vector operator< 
	template <typename type>
	int sort_checker(vector<type>& _vector, const long long int& i, long long int& j);

	template <typename type>
	void bubble_sort(vector<type>& _vector, const size_t& front_index = 0, const size_t& back_index = -1);

	template <typename type>
	void quick_sort(vector<type>& _vector, const size_t& front_index = 0, const size_t& back_index = -1);

	template <typename type>
	void sort(vector<type>& _vector, const size_t& front_index = 0, const size_t& back_index = -1);

	// vector cmp

	template <typename type>
	int sort_checker(vector<type>& _vector, bool (*cmp)(type, type), const long long int& i, long long int& j);

	template <typename type>
	void bubble_sort(vector<type>& _vector, bool (*cmp)(type, type), const size_t& front_index = 0, const size_t& back_index = -1);

	template <typename type>
	void quick_sort(vector<type>& _vector, bool (*cmp)(type, type), const size_t& front_index = 0, const size_t& back_index = -1);

	template <typename type>
	void sort(vector<type>& _vector, bool (*cmp)(type, type), const size_t& front_index = 0, const size_t& back_index = -1);

	// array operator<

	template <typename type, size_t _size_>
	int sort_checker(array<type, _size_>& _array, const long long int& i, long long int& j);

	template <typename type, size_t _size_>
	void bubble_sort(array<type, _size_>& _array, const size_t& front_index = 0, const size_t& back_index = -1);

	template <typename type, size_t _size_>
	void quick_sort(array<type, _size_>& _array, const size_t& front_index = 0, const size_t& back_index = -1);

	template <typename type, size_t _size_>
	void sort(array<type, _size_>& _array, const size_t& front_index = 0, const size_t& back_index = -1);

	// array cmp

	template <typename type, size_t _size_>
	int sort_checker(array<type, _size_>& _array, bool (*cmp)(type, type), const long long int& i, long long int& j);

	template <typename type, size_t _size_>
	void bubble_sort(array<type, _size_>& _array, bool (*cmp)(type, type), const size_t& front_index = 0, const size_t& back_index = -1);

	template <typename type, size_t _size_>
	void quick_sort(array<type, _size_>& _array, bool (*cmp)(type, type), const size_t& front_index = 0, const size_t& back_index = -1);

	template <typename type, size_t _size_>
	void sort(array<type, _size_>& _array, bool (*cmp)(type, type), const size_t& front_index = 0, const size_t& back_index = -1);

	
}

#include "algorithms.tpp"