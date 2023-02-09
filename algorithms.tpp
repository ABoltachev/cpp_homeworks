#pragma once

template <typename type>
void algo::swap(type& a, type& b) noexcept
{
	type temp = std::move(a);
	a = std::move(b);
	b = std::move(temp);
}

//	MAX<->MIN operator<

template<typename type>
const type& algo::min(const vector<type>& _vector) 
{
	if (_vector.size() == 0)
		throw std::logic_error("empty algo::vector haven't minimum");
	type _min = _vector[0];
	for (size_t i = 1; i < _vector.size(); ++i)
		if (_vector[i] < _min)
			_min = _vector[i];
	return _min;
}

template<typename type>
const type& algo::max(const vector<type>& _vector) 
{
	if (_vector.size() == 0)
		throw std::logic_error("empty algo::vector haven't maximum");
	type _max = _vector[0];
	for (size_t i = 1; i < _vector.size(); ++i)
		if (_max < _vector[i])
			_max = _vector[i];
	return _max;
}

template<typename type, size_t _size_>
const type& algo::min(const array<type, _size_>& _array) 
{
	if (_size_ == 0)
		throw std::logic_error("empty algo::array haven't minimum");
	type _min = _array[0];
	for (size_t i = 1; i < _size_; ++i)
		if (_array[i] < _min)
			_min = _array[i];
	return _min;
}

template<typename type, size_t _size_>
const type& algo::max(const array<type, _size_>& _array) 
{
	if (_size_ == 0)
		throw std::logic_error("empty algo::array haven't maximum");
	type _max = _array[0];
	for (size_t i = 1; i < _size_; ++i)
		if (_max < _array[i])
			_max = _array[i];
	return _max;
}

//	MAX<->MIN cmp

template<typename type>
const type& algo::min(const vector<type>& _vector, bool (*cmp)(type, type))
{
	if (_vector.size() == 0)
		throw std::logic_error("empty algo::vector haven't minimum");
	type _min = _vector[0];
	for (size_t i = 1; i < _vector.size(); ++i)
		if ((*cmp)(_vector[i], _min))
			_min = _vector[i];
	return _min;
}

template<typename type>
const type& algo::max(const vector<type>& _vector, bool (*cmp)(type, type))
{
	if (_vector.size() == 0)
		throw std::logic_error("empty algo::vector haven't maximum");
	type _max = _vector[0];
	for (size_t i = 1; i < _vector.size(); ++i)
		if ((*cmp)(_max, _vector[i]))
			_max = _vector[i];
	return _max;
}

template<typename type, size_t _size_>
const type& algo::min(const array<type, _size_>& _array, bool (*cmp)(type, type))
{
	if (_size_ == 0)
		throw std::logic_error("empty algo::array haven't minimum");
	type _min = _array[0];
	for (size_t i = 1; i < _size_; ++i)
		if ((*cmp)(_array[i], _min))
			_min = _array[i];
	return _min;
}

template<typename type, size_t _size_>
const type& algo::max(const array<type, _size_>& _array, bool (*cmp)(type, type))
{
	if (_size_ == 0)
		throw std::logic_error("empty algo::array haven't maximum");
	type _max = _array[0];
	for (size_t i = 1; i < _size_; ++i)
		if ((*cmp)(_max, _array[i]))
			_max = _array[i];
	return _max;
}

// FIND

template <typename type>
type& algo::find(vector<type>& _vector, const type& value)
{
	for (size_t i = 0; i < _vector.size(); ++i)
		if (_vector[i] == value)
			return _vector[i];
	throw std::runtime_error("non find algo::vector");
}

template <typename type, size_t _size_>
type& algo::find(array<type, _size_>& _array, const type& value) 
{
	for (size_t i = 0; i < _size_; ++i)
		if (_array[i] == value)
			return _array[i];
	throw std::runtime_error("non find algo::array");
}

// SORTS
// vector operator<

template <typename type>
int algo::sort_checker(vector<type>& _vector, const long long int& i, long long int& j)
{
	if (j == -1)
		j = _vector.size() - 1;
	if (i == j)
		return 1;
	if (i + 1 == j)
	{
		if (_vector[j] < _vector[i])
			algo::swap(_vector[i], _vector[j]);
		return 1;
	}
	return 0;
}

template <typename type>
void algo::bubble_sort(vector<type>& _vector, const size_t& front_index, const size_t& back_index)
{
	long long int i = front_index, j = back_index;
	if (algo::sort_checker(_vector, i, j)) return;
	for (size_t I = i; I <= j; ++I)
		for (size_t J = I + 1; J <= j; ++J)
			if (_vector[J] < _vector[I])
				algo::swap(_vector[I], _vector[J]);
}

template <typename type>
void algo::quick_sort(vector<type>& _vector, const size_t& front_index, const size_t& back_index) 
{
	long long int i = front_index, j = back_index;
	if (algo::sort_checker(_vector, i, j)) return;
	type pivot = _vector[(i + j) / 2];

	while (i <= j)
	{
		while (_vector[i] < pivot)
			++i;
		while (pivot < _vector[j])
			--j;
		if (i <= j)
			algo::swap(_vector[i++], _vector[j--]);
	}
	if (front_index < j)
		algo::quick_sort(_vector, front_index, j);
	if (i < back_index)
		algo::quick_sort(_vector, i, back_index);
}

template <typename type>
void algo::sort(vector<type>& _vector, const size_t& front_index, const size_t& back_index) 
{
	long long int i = front_index, j = back_index;
	if (algo::sort_checker(_vector, i, j)) return;
	if (j - i <= 5)
	{
		bubble_sort(_vector, i, j);
		return;
	}
	type pivot = _vector[(i + j) / 2];

	while (i <= j)
	{
		while (_vector[i] < pivot)
			++i;
		while (pivot < _vector[j])
			--j;
		if (i <= j)
			algo::swap(_vector[i++], _vector[j--]);
	}
	if (front_index < j)
		algo::sort(_vector, front_index, j);
	if (i < back_index)
		algo::sort(_vector, i, back_index);
}

// vector cmp

template <typename type>
int algo::sort_checker(vector<type>& _vector, bool (*cmp)(type, type), const long long int& i, long long int& j)
{
	if (j == -1)
		j = _vector.size() - 1;
	if (i == j)
		return 1;
	if (i + 1 == j)
	{
		if ((*cmp)(_vector[j], _vector[i]))
			algo::swap(_vector[i], _vector[j]);
		return 1;
	}
	return 0;
}

template <typename type>
void algo::bubble_sort(vector<type>& _vector, bool (*cmp)(type, type), const size_t& front_index, const size_t& back_index)
{
	long long int i = front_index, j = back_index;
	if (algo::sort_checker(_vector, cmp, i, j)) return;
	for (size_t I = i; I <= j; ++I)
		for (size_t J = I + 1; J <= j; ++J)
			if ((*cmp)(_vector[J], _vector[I]))
				algo::swap(_vector[I], _vector[J]);
}

template <typename type>
void algo::quick_sort(vector<type>& _vector, bool (*cmp)(type, type), const size_t& front_index, const size_t& back_index)
{
	long long int i = front_index, j = back_index;
	if (algo::sort_checker(_vector, cmp, i, j)) return;
	type pivot = _vector[(i + j) / 2];

	while (i <= j)
	{
		while ((*cmp)(_vector[i], pivot))
			++i;
		while ((*cmp)(pivot, _vector[j]))
			--j;
		if (i <= j)
			algo::swap(_vector[i++], _vector[j--]);
	}
	if (front_index < j)
		algo::quick_sort(_vector, cmp, front_index, j);
	if (i < back_index)
		algo::quick_sort(_vector, cmp, i, back_index);
}

template <typename type>
void algo::sort(vector<type>& _vector, bool (*cmp)(type, type), const size_t& front_index, const size_t& back_index)
{
	long long int i = front_index, j = back_index;
	if (algo::sort_checker(_vector, cmp, i, j)) return;
	if (j - i <= 5)
	{
		bubble_sort(_vector, cmp, i, j);
		return;
	}
	type pivot = _vector[(i + j) / 2];

	while (i <= j)
	{
		while ((*cmp)(_vector[i], pivot))
			++i;
		while ((*cmp)(pivot, _vector[j]))
			--j;
		if (i <= j)
			algo::swap(_vector[i++], _vector[j--]);
	}
	if (front_index < j)
		algo::sort(_vector, cmp, front_index, j);
	if (i < back_index)
		algo::sort(_vector, cmp, i, back_index);
}

// array operator<

template <typename type, size_t _size_>
int algo::sort_checker(array<type, _size_>& _array, const long long int& i, long long int& j) 
{
	if (j == -1)
		j = _size_ - 1;
	if (i == j)
		return 1;
	if (i + 1 == j)
	{
		if (_array[j] < _array[i])
			algo::swap(_array[i], _array[j]);
		return 1;
	}
	return 0;
}

template <typename type, size_t _size_>
void algo::bubble_sort(array<type, _size_>& _array, const size_t& front_index, const size_t& back_index) 
{
	long long int i = front_index, j = back_index;
	if (algo::sort_checker(_array, i, j)) return;
	for (size_t I = i; I <= j; ++I)
		for (size_t J = I + 1; J <= j; ++J)
			if (_array[J] < _array[I])
				algo::swap(_array[I], _array[J]);
}

template <typename type, size_t _size_>
void algo::quick_sort(array<type, _size_>& _array, const size_t& front_index, const size_t& back_index) 
{
	long long int i = front_index, j = back_index;
	if (algo::sort_checker(_array, i, j)) return;
	type pivot = _array[(i + j) / 2];

	while (i <= j)
	{
		while (_array[i] < pivot)
			++i;
		while (pivot < _array[j])
			--j;
		if (i <= j)
			algo::swap(_array[i++], _array[j--]);
	}
	if (front_index < j)
		algo::quick_sort(_array, front_index, j);
	if (i < back_index)
		algo::quick_sort(_array, i, back_index);
}

template <typename type, size_t _size_>
void algo::sort(array<type, _size_>& _array, const size_t& front_index, const size_t& back_index) 
{
	long long int i = front_index, j = back_index;
	if (algo::sort_checker(_array, i, j)) return;
	if (j - i <= 5)
	{
		bubble_sort(_array, i, j);
		return;
	}
	type pivot = _array[(i + j) / 2];

	while (i <= j)
	{
		while (_array[i] < pivot)
			++i;
		while (pivot < _array[j])
			--j;
		if (i <= j)
			algo::swap(_array[i++], _array[j--]);
	}
	if (front_index < j)
		algo::sort(_array, front_index, j);
	if (i < back_index)
		algo::sort(_array, i, back_index);
}

// array cmp

template <typename type, size_t _size_>
int algo::sort_checker(array<type, _size_>& _array, bool (*cmp)(type, type), const long long int& i, long long int& j)
{
	if (j == -1)
		j = _size_ - 1;
	if (i == j)
		return 1;
	if (i + 1 == j)
	{
		if ((*cmp)(_array[j], _array[i]))
			algo::swap(_array[i], _array[j]);
		return 1;
	}
	return 0;
}

template <typename type, size_t _size_>
void algo::bubble_sort(array<type, _size_>& _array, bool (*cmp)(type, type), const size_t& front_index, const size_t& back_index)
{
	long long int i = front_index, j = back_index;
	if (algo::sort_checker(_array, cmp, i, j)) return;
	for (size_t I = i; I <= j; ++I)
		for (size_t J = I + 1; J <= j; ++J)
			if ((*cmp)(_array[J], _array[I]))
				algo::swap(_array[I], _array[J]);
}

template <typename type, size_t _size_>
void algo::quick_sort(array<type, _size_>& _array, bool (*cmp)(type, type), const size_t& front_index, const size_t& back_index)
{
	long long int i = front_index, j = back_index;
	if (algo::sort_checker(_array, cmp, i, j)) return;
	type pivot = _array[(i + j) / 2];

	while (i <= j)
	{
		while ((*cmp)(_array[i], pivot))
			++i;
		while ((*cmp)(pivot, _array[j]))
			--j;
		if (i <= j)
			algo::swap(_array[i++], _array[j--]);
	}
	if (front_index < j)
		algo::quick_sort(_array, cmp, front_index, j);
	if (i < back_index)
		algo::quick_sort(_array, cmp, i, back_index);
}

template <typename type, size_t _size_>
void algo::sort(array<type, _size_>& _array, bool (*cmp)(type, type), const size_t& front_index, const size_t& back_index)
{
	long long int i = front_index, j = back_index;
	if (algo::sort_checker(_array, cmp, i, j)) return;
	if (j - i <= 5)
	{
		bubble_sort(_array, cmp, i, j);
		return;
	}
	type pivot = _array[(i + j) / 2];

	while (i <= j)
	{
		while ((*cmp)(_array[i], pivot))
			++i;
		while ((*cmp)(pivot, _array[j]))
			--j;
		if (i <= j)
			algo::swap(_array[i++], _array[j--]);
	}
	if (front_index < j)
		algo::sort(_array, cmp, front_index, j);
	if (i < back_index)
		algo::sort(_array, cmp, i, back_index);
}

algo::range_buffer algo::range(const int64_t& stop) 
{
	return range_buffer(0, stop, 1);
}

algo::range_buffer algo::range(const int64_t& start, const int64_t& stop, const int64_t& step)
{
	return range_buffer(start, stop, step);
}

algo::range_buffer::range_buffer(const int64_t& start, const int64_t& stop, const int64_t& step) 
	: __start__(start)
	, __stop__(stop)
	, __step__(step) {}


algo::range_buffer::range_iterator::range_iterator(const int64_t& start_index, const algo::range_buffer* _buffer)
	: index(start_index)
	, buffer(_buffer) {}

const algo::range_buffer::range_iterator& algo::range_buffer::range_iterator::operator++() 
{
	index += buffer->__step__;
	if (index >= buffer->__stop__)
		index = INT64_MAX;
	return *this;
}

const algo::range_buffer::range_iterator& algo::range_buffer::range_iterator::operator++(int)
{
	auto object = *this;
	++(*this);
	return object;
}

const bool algo::range_buffer::range_iterator::operator==(const range_iterator& _r_iter) const 
{
	return index == _r_iter.index;
}

const bool algo::range_buffer::range_iterator::operator!=(const range_iterator& _r_iter) const
{
	return index != _r_iter.index;
}

int64_t& algo::range_buffer::range_iterator::operator*() 
{
	return index;
}

const int64_t& algo::range_buffer::range_iterator::operator*() const 
{
	return index;
}

algo::range_buffer::range_iterator algo::range_buffer::begin() const 
{
	return algo::range_buffer::range_iterator(__start__, this);
}

algo::range_buffer::range_iterator algo::range_buffer::end() const 
{
	return algo::range_buffer::range_iterator(INT64_MAX, this);
}