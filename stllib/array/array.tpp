#pragma once

template <typename type, size_t _size_>
algo::array<type, _size_>::array(const type& default_value)
{
	for (size_t i = 0; i < _size_; ++i)
		data[i] = default_value;
}

template <typename type, size_t _size_>
algo::array<type, _size_>::array(const std::initializer_list<type>& init_list)
{
	size_t i = 0;
	for (const auto& elem: init_list) 
	{
		data[i++] = elem;
	}
}

template <typename type, size_t _size_>
algo::array<type, _size_>::array(const array<type, _size_>& _array)
{
	for (size_t i = 0; i < _size_; ++i)
		data[i] = _array[i];
}

template <typename type, size_t _size_>
size_t algo::array<type, _size_>::size() const
{
	return _size_;
}

template <typename type, size_t _size_>
bool algo::array<type, _size_>::empty() const
{
	return size() == 0;
}

template <typename type, size_t _size_>
type& algo::array<type, _size_>::operator[](const size_t& index)
{
	check_index(index);
	return data[index];
}

template <typename type, size_t _size_>
const type& algo::array<type, _size_>::operator[](const size_t& index) const
{
	check_index(index);
	return data[index];
}

template <typename type, size_t _size_>
const algo::array<type, _size_>& algo::array<type, _size_>::operator=(const array<type, _size_>& _array)
{
	for (size_t i = 0; i < _size_; ++i)
		data[i] = _array[i];
	return *this;
}

template <typename type, size_t _size_>
void algo::array<type, _size_>::check_index(const size_t& index) const
{
	if (index >= size())
		throw std::out_of_range("index out of range");
}