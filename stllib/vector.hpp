#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

namespace VectorMethods
{
	template <typename T>

	class Vector
	{
	private:
		T* vector;
		size_t v_size;
		size_t max_size;

		void CheckIndex(const size_t& index) const;

	public:
		Vector();
		Vector(const size_t& v_size = 0, const T& value = T());
		Vector(const std::initializer_list<T>& initial_list);
		Vector(const Vector<T>& another_vector);

		const Vector<T>& operator = (const Vector<T>& another_vector);

		T& operator [] (const size_t& index);
		const T& operator [] (const size_t& index) const;

		size_t size() const;
		bool empty() const;

		void resize(const size_t& new_size, const T& value = T());

		void push_back(const T& value);
		void emplace_back(T&& value);

		void clear();
		~Vector();
	};
}

#include "Vector.tpp"

#endif