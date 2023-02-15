#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

namespace ArrayMethods {

	template <typename aT, size_t T_size>

	class Array
	{
	private:
		aT array[T_size];
		size_t arr_size = T_size;

		void CheckIndex(const size_t& index) const;

	public:
		Array();
		Array(const Array<aT, T_size>& another_array);
		Array(const std::initializer_list<aT>& initial_list);

		const Array& operator = (const Array<aT, T_size> & another_array);

		aT& operator[](const size_t& index);
		const aT& operator[](const size_t& index) const;

		size_t size() const;
		bool empty() const;

		~Array() = default;
	};

}

#include "array.tpp"

#endif