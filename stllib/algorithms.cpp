#include "algorithms.hpp"

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
	isEnd();
	return index;
}

const int64_t& algo::range_buffer::range_iterator::operator*() const
{
	isEnd();
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


void algo::range_buffer::range_iterator::isEnd() const
{
	if (index == INT64_MAX)
		throw std::out_of_range("out of range");
}