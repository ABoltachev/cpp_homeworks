
template <typename type>
Array<type>& Array<type>::operator=(const Array<type>& _array) 
{
	if (&_array == this)
		return *this;
	__size__ = _array.__size__;
	data = new type[__size__];
	for (size_t i = 0; i < __size__; ++i)
		data[i] = _array.data[i];
	return *this;
}


template <typename type>
Array<type>& Array<type>::operator=(Array<type>&& _array)
{
	if (&_array == this)
		return *this;
	__size__ = _array.__size__;
	data = new type[__size__];
	for (size_t i = 0; i < __size__; ++i)
		data[i] = _array.data[i];
	return *this;
}

template <typename type>
void Array<type>::index_out_of_range(size_t index) const
{
	if (index >= __size__)
		throw std::out_of_range("index out of range");
}

#pragma once

template <typename type>
Array<type>::Array()
{
	__size__ = 1;
	data = new type;
}

template <typename type>
Array<type>::Array(size_t __size__, const type& value)
{
	this->__size__ = __size__;
	data = new type[__size__];
	std::fill(data, data + __size__, value);
}

template <typename type>
Array<type>::Array(const Array<type>& _array) : __size__(_array.__size__)
{
	if (&_array == this)
		return;
	data = new type[__size__];
	std::copy(_array.data, _array.data + __size__, data);
}

template <typename type>
Array<type>::Array(Array<type>&& _array) : __size__(_array.size()), data(_array.data)
{
	reserve();
}

template <typename type>
void Array<type>::eq_sizes(size_t __size__) const
{
	if (__size__ != this->__size__)
		throw std::runtime_error("Diff sizes");
}

template <typename type>
Array<type> Array<type>::operator+(const Array<type>& _array) const
{
	return Array<type>(*this) += _array;
}

template <typename type>
Array<type>& Array<type>::operator+=(const Array<type>& _array)
{
	eq_sizes(_array.__size__);
	for (size_t i = 0; i < __size__; ++i)
		data[i] += _array.data[i];
	return *this;
}

template <typename type>
Array<type> Array<type>::operator-(const Array<type>& _array) const
{
	return Array<type>(*this) -= _array;
}

template <typename type>
Array<type>& Array<type>::operator-=(const Array<type>& _array)
{
	eq_sizes(_array.__size__);
	for (size_t i = 0; i < __size__; ++i)
		data[i] -= _array.data[i];
	return *this;
}

template <typename type>
const bool Array<type>::operator==(const Array<type>& _array) const
{
	eq_sizes(_array.__size__);
	for (size_t i = 0; i < __size__; ++i)
		if (_array.data[i] != data[i])
			return false;
	return true;
}

template <typename type>
const bool Array<type>::operator!=(const Array<type>& _array) const
{
	return !((*this) == _array);
}

template <typename type>
size_t Array<type>::size() const
{
	return __size__;
}
template <typename type>
bool Array<type>::empty() const
{
	return !__size__;
}

template <typename type>
type& Array<type>::operator[](size_t index)
{
	index_out_of_range(index);
	return data[index];
}

template <typename type>
const type& Array<type>::operator[](size_t index) const
{
	index_out_of_range(index);
	return data[index];
}

template <typename type>
Array<type>::~Array()
{
	delete[] data;
}

template <typename type>
std::ostream& operator<<(std::ostream& out, const Array<type>& _array)
{
	out << "[";
	for (size_t i = 0; i < _array.__size__; ++i)
	{
		out << _array.data[i];
		if (i + 1 != _array.__size__)
			out << ", ";
	}
	out << "]";
	return out;
}

template <typename type>
void Array<type>::reserve() 
{
	data = nullptr;
	__size__ = 0;
}