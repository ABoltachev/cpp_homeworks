#pragma once

template<typename T, size_t Size_>
Array<T, Size_>::Array()
	:m_size(Size_)
{
	for (int i = 0; i < Size_; ++i) {
		m_arr[i] = 0;
	}
}

template<typename T, size_t Size_>
Array<T, Size_>::Array(std::initializer_list<T> &init_list)
{
	size_t count = 0;
	for (auto i : init_list) {
		m_arr[count] = i;
		count++;
	}
}

template<typename T, size_t Size_>
Array<T, Size_>::Array(const Array<T, Size_>& other)
{
	for (int i = 0; i < Size_; ++i) {
		m_arr[i] = other.m_arr[i];
	}
}

template<typename T, size_t Size_>
size_t Array<T, Size_>:: size() const {
	return Size_;
}

template<typename T, size_t Size_>
bool Array<T,Size_>:: empty() const {
	return Size_ == 0;
}

template<typename T, size_t Size_>
T& Array<T, Size_>::operator[](size_t& index) { //index > N ????
	if (index < Size_) {
		return m_arr[index];
	}
}

template<typename T, size_t Size_>
const T& Array<T, Size_>::operator[](size_t& index) const
{
	if (index < Size_) {
		return m_arr[index];
	}
}

template<typename T, size_t Size_>
Array<T, Size_> &Array<T,Size_>::operator=(const Array& other) {
	
	for (int i = 0; i < Size_; ++i) {
		m_arr[i] = other.m_arr[i];
	}
	return *this;
}

template<typename T, size_t Size_>
Array<T, Size_>::~Array()
{
	delete[] m_arr;
}
