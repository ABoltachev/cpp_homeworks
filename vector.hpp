#pragma once

#include <stdexcept>

namespace algo
{
	template <typename type>
	class vector
	{
	private:
		type* data;
		size_t __size__;
		size_t __capacity__;
	public:
		vector(const size_t& __size__ = 0, const type& default_value = type());
		vector(const std::initializer_list<type>& init_list);
		vector(const vector<type>& _vector);
		size_t size() const;
		bool empty() const;
		const vector<type>& operator=(const vector<type>& _vector);
		type& operator[](const size_t& index);
		const type& operator[](const size_t& index) const;
		void push_back(const type& value);
		void emplace_back(const type& value) noexcept;
		void resize(const size_t& __size__, const type& default_value = type());
		void clear();
		~vector();
	private:
		void check_index(const size_t& index) const;
	};
}

#include "vector.tpp"
