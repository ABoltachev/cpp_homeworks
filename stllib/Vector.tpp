#pragma once

template<class T>
Vector<T>::Vector()
{
	m_arr = new T[1];
	m_size = 0;
	m_capacity = 1;
}

template<class T>
Vector<T>::Vector(size_t size, const T& value)
	:m_arr(new T[size]), m_size(size), m_capacity(size)
{
	for (int i = 0; i < m_size; ++i) {
		m_arr[i] = value;
	}
}

template<class T>
Vector<T>::Vector(const Vector<T>& other)
	:m_arr(new T[m_capacity]), m_size(other.m_size),
	m_capacity(other.m_capacity)
{	
	for (int i = 0; i < m_size; ++i) {
		m_arr[i] = other.m_arr[i];
	}
}

template<class T>
Vector<T>::Vector(Vector&& other) 
{
	m_arr = other.m_arr;
	m_size = other.m_size;
	m_capacity = other.m_capacity;
	other.m_arr = nullptr;
	other.m_size = 0;
	other.m_capacity = 0;
}

template<class T>
Vector<T>::Vector(std::initializer_list<T> init_list)
	:m_arr(new T[m_size]), m_size(init_list.size()), m_capacity(m_size)
{
	size_t count = 0;
	for (const auto i : init_list)
	{
		m_arr[count] = i;
		count++;
	}
}

template<class T>
size_t Vector<T>::size() const
{
	return m_size;
}

template<class T>
bool Vector<T>::empty() const
{
	return m_size == 0;
}

template<class T>
void Vector<T>::addmemory()
{
	m_capacity *= 2;
	T* tmp = m_arr;
	m_arr = new T[m_capacity];
	for (size_t i = 0; i < m_size; ++i) {
		m_arr[i] = tmp[i];
	}
	delete[] tmp;
}

template<class T>
void Vector<T>::push_back(const T& value)
{
	if (m_size > m_capacity) {
		addmemory();
	}
	m_arr[m_size++] = value; 
}

template<class T>
void Vector<T>::emplace_back(T&& value)
{
	if (m_size == m_capacity)
		resize(m_capacity * 2);
	m_arr[m_size++] = std::move(value);
}

template<class T>
void Vector<T>::resize(size_t& size, const T& value)
{
	if (size > m_capacity) {
		addmemory();
	}
	for (size_t i = m_size; i < size; ++i) {
		m_arr[i] = value;
	}
	m_size = size;
}

template<class T>
void Vector<T>::clear()
{
	delete[] m_arr;
	m_arr = nullptr;
	m_size = 0;
	m_capacity = 0;
}

template<class T>
T& Vector<T>::operator[](size_t index)
{
	return m_arr[index];
}

template<class T>
const T& Vector<T>::operator[](size_t index) const
{
	return m_arr[index];
}

template<class T>
Vector<T>& Vector<T>::operator= (const Vector& other)
{
	if (&other == this) {
		return *this;
	}
	delete[] m_arr;
	m_arr = new T[other.m_capacity];
	for (int i = 0; i < other.m_capacity; ++i) {
		m_arr[i] = other.m_arr[i];
	}
	m_size = other.m_size;
	m_capacity = other.m_capacity;
	return *this;
}

template<class T>
Vector<T>& Vector<T>::operator=(Vector&& other)
{
	if (this != &other) {
		delete[] m_arr;
		m_arr = other.m_arr;
		m_size = other.m_size;
		m_capacity = other.m_capacity;

		other.m_arr = nullptr;
		other.size = 0;
		other.capacity = 0;
	}
	return this;
}

template<class T>
Vector<T>::~Vector()
{
	delete[] m_arr;
}
