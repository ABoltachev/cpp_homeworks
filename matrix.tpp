template <typename type>
matrix<type>::matrix() 
{
	data = Array<Array<type>>(1, Array<type>(1));
	n = m = 1;
}

template <typename type>
matrix<type>::matrix(size_t n, size_t m, const type& value) 
{
	this->n = n;
	this->m = m;
	data = Array<Array<type>>(n, Array<type>(m, value));
}

template <typename type>
matrix<type>::matrix(const matrix<type>& _matrix)  : n(_matrix.n), m(_matrix.m)
{
	if (&_matrix == this)
		return;
	n = _matrix.n;
	m = _matrix.m;
	data = Array<Array<type>>(_matrix.n);
	for (size_t i = 0; i < n; ++i)
		data[i] = Array<type>(_matrix[i]);
}

template <typename type>
matrix<type>::matrix(matrix<type>&& _matrix)
{
	n = _matrix.n;
	m = _matrix.m;
	data = _matrix.data;
	_matrix.data.reserve();
	_matrix.n = _matrix.m = 0;
}

template <typename type>
void matrix<type>::eq_sizes(size_t n, size_t m) const 
{
	if (this->n != n || this->m != m)
		throw std::runtime_error("Diff sizes");
}

template <typename type>
void matrix<type>::index_out_of_range(size_t index) const
{
	if (index >= n)
		throw std::out_of_range("Index out of range");
}

template <typename type>
matrix<type> matrix<type>::operator+(const matrix<type>& _matrix) const 
{
	return matrix(*this) += _matrix;
}

template <typename type>
matrix<type>& matrix<type>::operator+=(const matrix<type>& _matrix) 
{
	eq_sizes(_matrix.n, _matrix.m);
	data += _matrix.data;
	return *this;
}

template <typename type>
matrix<type> matrix<type>::operator-(const matrix<type>& _matrix) const 
{
	return matrix(*this) -= _matrix;
}

template <typename type>
matrix<type>& matrix<type>::operator-=(const matrix<type>& _matrix) 
{
	eq_sizes(_matrix.n, _matrix.m);
	data -= _matrix.data;
	return *this;
}

template <typename type>
const bool matrix<type>::operator==(const matrix<type>& _matrix) const 
{
	eq_sizes(_matrix.n, _matrix.m);
	return data == _matrix.data;
}

template <typename type>
const bool matrix<type>::operator!=(const matrix<type>& _matrix) const 
{
	eq_sizes(_matrix.n, _matrix.m);
	return data != _matrix.data;
}

template <typename type>
size_t matrix<type>::size() const 
{
	return n * m;
}

template <typename type>
bool matrix<type>::empty() const 
{
	return !n || !m;
}

template <typename type>
Array<type>& matrix<type>::operator[](size_t index) 
{
	index_out_of_range(index);
	return data[index];
}

template <typename type>
const Array<type>& matrix<type>::operator[](size_t index) const 
{
	index_out_of_range(index);
	return data[index];
}

template <typename type>
std::ostream& operator<<(std::ostream& out, const matrix<type>& _matrix) 
{
	out << _matrix.n << " " << _matrix.m << "\n";
	for (size_t i = 0; i < _matrix.n; ++i)
		out << _matrix[i] << "\n";
	return out;
}

template <typename type>
size_t matrix<type>::rows() const 
{
	return n;
}

template <typename type>
size_t matrix<type>::cols() const
{
	return m;
}