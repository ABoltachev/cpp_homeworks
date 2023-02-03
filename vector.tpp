#pragma once

template <typename type>
algo::vector<type>::vector(const size_t& __size__, const type& default_value)
{
	__capacity__ = 1;
	while (__size__ >= __capacity__)
		__capacity__ *= 2;
	this->__size__ = __size__;
	data = new type[__capacity__];
	for (size_t i = 0; i < __size__; ++i)
		data[i] = default_value;
}

template <typename type>
algo::vector<type>::vector(const std::initializer_list<type>& init_list)
{
	__capacity__ = 1;
	while (init_list.size() >= __capacity__)
		__capacity__ *= 2;
	this->__size__ = init_list.size();
	data = new type[__capacity__];
	size_t i = 0;
	for (const auto& elem : init_list)
		data[i++] = elem;
}

template <typename type>
algo::vector<type>::vector(const vector<type>& _vector)
{
	if (this == &_vector)
	{
		__capacity__ = 1;
		__size__ = 0;
		data = new type;
		*data = type();
		return;
	}
	this->__size__ = _vector.__size__;
	this->__capacity__ = _vector.__capacity__;
	data = new type[__capacity__];
	for (size_t i = 0; i < size(); ++i)
		data[i] = _vector[i];
}

template <typename type>
size_t algo::vector<type>::size() const
{
	return __size__;
}

template <typename type>
bool algo::vector<type>::empty() const
{
	return size() == 0;
}

template <typename type>
type& algo::vector<type>::operator[](const size_t& index)
{
	check_index(index);
	return data[index];
}

template <typename type>
const type& algo::vector<type>::operator[](const size_t& index) const
{
	check_index(index);
	return data[index];
}

template <typename type>
const algo::vector<type>& algo::vector<type>::operator=(const vector<type>& _vector)
{
	if (this == &_vector)
	{
		return *this;
	}
	delete[] data;
	this->__size__ = _vector.__size__;
	this->__capacity__ = _vector.__capacity__;
	data = new type[__capacity__];
	for (size_t i = 0; i < size(); ++i)
		data[i] = _vector[i];
	return *this;
}

template <typename type>
void algo::vector<type>::check_index(const size_t& index) const
{
	if (index >= size())
		throw std::out_of_range("index out of range");
}

template <typename type>
void algo::vector<type>::resize(const size_t& __size__, const type& default_value)
{
	if (__size__ == this->__size__)
		return;
	if (__size__ < this->__size__)
	{
		if (__size__ < __capacity__ / 2)
		{
			while (__size__ < __capacity__ / 2)
				__capacity__ /= 2;
			type* temp = new type[__capacity__];
			for (size_t i = 0; i < __size__; ++i)
				temp[i] = data[i];
			this->__size__ = __size__;
			delete[] data;
			data = temp;
		}
		else
			this->__size__ = __size__;
	}
	else 
	{
		if (__size__ >= __capacity__)
		{
			while (__size__ >= __capacity__)
				__capacity__ *= 2;
			type* temp = new type[__capacity__];
			for (size_t i = 0; i < this->__size__; ++i)
				temp[i] = data[i];
			for (size_t i = this->__size__; i < __size__; ++i)
				temp[i] = default_value;
			this->__size__ = __size__;
			delete[] data;
			data = temp;
		}
		else
			this->__size__ = __size__;
	}
}

template <typename type>
void algo::vector<type>::push_back(const type& value)
{
	resize(size() + 1);
	data[size() - 1] = value;
}

template <typename type>
void algo::vector<type>::emplace_back(const type& value) noexcept
{
	resize(size() + 1);
	data[size() - 1] = std::move(value);
}

template <typename type>
void algo::vector<type>::clear()
{
	delete[] data;
	data = new type;
	__capacity__ = 1;
	__size__ = 0;
}

template <typename type>
algo::vector<type>::~vector()
{
	delete[] data;
}