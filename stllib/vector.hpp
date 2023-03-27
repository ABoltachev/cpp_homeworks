#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

namespace VectorMethods
{
	template <typename vT>

	class Vector
	{
	private:
		vT* vector;
		size_t v_size;
		size_t max_size;

		void CheckIndex(const size_t& index) const;

	public:
		Vector();
		Vector(const size_t& v_size = 0, const vT& value = vT());
		Vector(const std::initializer_list<vT>& initial_list);
		Vector(const Vector<vT>& another_vector);

		const Vector<vT>& operator = (const Vector<vT>& another_vector);

		vT& operator [] (const size_t& index);
		const vT& operator [] (const size_t& index) const;

		size_t size() const;
		bool empty() const;

		void resize(const size_t& new_size, const vT& value = vT());

		void push_back(const vT& value);
		void emplace_back(vT&& value);

		void clear();
		~Vector();
	};
}

#include "Vector.tpp"

#endif