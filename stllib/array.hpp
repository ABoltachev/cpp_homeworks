#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template<typename Data, size_t size>
class Array {
private:

	Data m_arr[size];
	size_t m_size = size;

	void check(size_t idx) const;

public:

	Array() = default;
	Array(const std::initializer_list<Data>& init_list);

	size_t size() const;
	bool empty() const;

	Data& operator[](size_t idx);
	const Data& operator[](size_t idx) const;

	Array<Data, size>& operator=(Array<Data, size>&& obj);
	Array<Data, size>& operator=(const Array<Data, size>& obj);

};

#include "array.tpp"

#endif
