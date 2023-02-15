#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

namespace ArrayMethods {

	template <typename T, size_t T_size>

	class Array
	{
	private:
		T array[T_size];
		size_t arr_size = T_size;

		void CheckIndex(const size_t& index) const;

	public:
		Array();
		Array(const Array<T, T_size>& another_array);
		Array(const std::initializer_list<T>& initial_list);

		const Array& operator = (const Array<T, T_size> & another_array);

		T& operator[](const size_t& index);
		const T& operator[](const size_t& index) const;

		size_t size() const;
		bool empty() const;

		~Array() = default;
	};

}

#include "array.tpp"

#endif