#pragma once
#include "Array.hpp"

template <typename type>
class matrix
{
private:
	Array<Array<type>> data;
	size_t n;
	size_t m;
public:
	matrix();
	matrix(size_t n, size_t m, const type& value = type(NULL));
	matrix(const matrix<type>& _matrix);
	matrix(matrix<type>&& _matrix);

	matrix<type> operator+(const matrix<type>& _matrix) const;
	matrix<type>& operator+=(const matrix<type>& _matrix);
	matrix<type> operator-(const matrix<type>& _matrix) const;
	matrix<type>& operator-=(const matrix<type>& _matrix);

	const bool operator==(const matrix<type>& _matrix) const;
	const bool operator!=(const matrix<type>& _matrix) const;

	size_t size() const;
	size_t rows() const;
	size_t cols() const;
	bool empty() const;
	Array<type>& operator[](size_t index);
	const Array<type>& operator[](size_t index) const;

	template <typename type>
	friend std::ostream& operator<<(std::ostream& out, const matrix<type>& _matrix);

	~matrix() = default;
private:
	void eq_sizes(size_t n, size_t m) const;
	void index_out_of_range(size_t index) const;
};

#include "matrix.tpp"