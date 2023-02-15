#pragma once
#include<iostream>

template<class T>
class Vector {
	T* m_arr;
	size_t m_size;
	size_t m_capacity;
public:
	Vector();
	Vector(size_t size, const T& value = T());
	Vector(const Vector<T>& other);
	Vector(Vector<T>&& other);
	Vector(std::initializer_list<T> init_list);

	size_t size() const;
	bool empty()const;

	void addmemory();
	void push_back(const T& value);
	void emplace_back(T&& value);

	void resize(size_t& size, const T& value=T());
	void clear();

	T& operator[] (size_t index);
	const T& operator[](size_t index) const;

	Vector<T>& operator=(const Vector& other);
	Vector<T>& operator=(Vector&& other);
	~Vector();
};

#include"Vector.tpp"