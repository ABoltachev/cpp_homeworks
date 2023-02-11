#pragma once

#include <stdexcept>

namespace algo
{
	template <typename type, size_t _size_>
	class array
	{
	private:
		type data[_size_];
	public:
		array(const type& default_value = type());
		array(const std::initializer_list<type>& init_list);
		array(const array<type, _size_>& _array);
		size_t size() const;
		bool empty() const;
		const array<type, _size_>& operator=(const array<type, _size_>& _array);
		type& operator[](const size_t& index);
		const type& operator[](const size_t& index) const;

		~array() = default;
	private:
		void check_index(const size_t& index) const;
	};
}

#include "array.tpp"