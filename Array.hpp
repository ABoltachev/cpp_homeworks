#pragma once
#include <iostream>

template <typename type>
class Array
{
private:
	type* data;
	size_t __size__;
public:
	Array();
	Array(size_t __size__, const type& value = type(NULL));
	Array(const Array<type>& _array);
	Array(Array<type>&& _array);

	Array<type> operator+(const Array<type>& _array) const;
	Array<type>& operator+=(const Array<type>& _array);
	Array<type> operator-(const Array<type>& _array) const;
	Array<type>& operator-=(const Array<type>& _array);

	const bool operator==(const Array<type>& _array) const;
	const bool operator!=(const Array<type>& _array) const;

	Array<type>& operator=(const Array<type>& _array);
	Array<type>& operator=(Array<type>&& _array);

	size_t size() const;
	bool empty() const;
	type& operator[](size_t index);
	const type& operator[](size_t index) const;

	template <typename type>
	friend std::ostream& operator<<(std::ostream& out, const Array<type>& _array);

	~Array();

	void reserve();
private:
	void eq_sizes(size_t __size__) const;
	void index_out_of_range(size_t index) const;
};

#include "Array.tpp"