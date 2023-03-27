#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "array.hpp"
#include "vector.hpp"

namespace ArrayAlgorithms {

	using namespace ArrayMethods;

	template <typename aT, size_t T_size>
	void sort(Array<aT, T_size>& arr);

	template <typename aT, size_t T_size>
	const aT& max(const Array<aT, T_size>& arr);

	template <typename aT, size_t T_size>
	const aT& min(const Array<aT, T_size>& arr);

	template <typename aT, size_t T_size>
	aT& find(Array<aT, T_size>& arr, const aT& value);
}

namespace VectorAlgorithms {

	using namespace VectorMethods;

	template<typename vT>
	void sort(Vector<vT>& vect);

	template<typename vT>
	const vT& max(const Vector<vT>& vect);

	template<typename vT>
	const vT& min(const Vector<vT>& vect);

	template<typename vT>
	vT& find(Vector<vT>& vect, const vT& value);
}

#include "algorithms.tpp"

#endif