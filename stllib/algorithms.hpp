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

	class range_buffer;

	range_buffer range(const int64_t& stop);
	range_buffer range(const int64_t& start, const int64_t& stop, const int64_t& step = 1);

	class range_buffer
	{
	private:
		int64_t __start__;
		int64_t __step__;
		int64_t __stop__;

		range_buffer(const int64_t& start, const int64_t& stop, const int64_t& step);

		class range_iterator
		{
		private:
			int64_t index;
			const algo::range_buffer* buffer;
		public:
			range_iterator(const int64_t& start_index, const algo::range_buffer* _buffer);

			const range_iterator& operator++();
			const range_iterator& operator++(int);

			const bool operator==(const range_iterator& _r_iter) const;
			const bool operator!=(const range_iterator& _r_iter) const;

			int64_t& operator*();
			const int64_t& operator*() const;

			void isEnd() const;
		};
	public:
		range_iterator begin() const;
		range_iterator end() const;

		friend range_buffer range(const int64_t& stop);
		friend range_buffer range(const int64_t& start, const int64_t& stop, const int64_t& step);
		friend class range_iterator;
	};
}

#include "algorithms.tpp"
