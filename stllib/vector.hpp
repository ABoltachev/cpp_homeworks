#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <stdexcept>

template<class Data>
class Vector {
private:
	size_t m_curr = 0;
	size_t m_size = 0;
	Data* m_vector = nullptr;

	void check(size_t idx) const;

public:

	Vector();
	Vector(size_t size, const Data& sym=0);
	Vector(const std::initializer_list<Data>& init_list);
	Vector(const Vector<Data>& obj);//копирование
	Vector(Vector<Data>&& obj);//перемещение

	size_t size() const;
	bool empty() const;

	Data& operator[](size_t idx);
	const Data& operator[](size_t idx) const;

	void resize(size_t& new_size, const Data& sym = 0);
	void push_back(const Data& sym);
	void emplace_back(Data&& sym);
	void clear();


	Vector<Data>& operator=(Vector&& obj);
	Vector<Data>& operator=(const Vector& obj);

};
#include "vector.tpp"

#endif
