//        Также несколько алгоритмов :
//*sort(простая сортировка, либо пузырьком, либо вставками)
//* max; min(поиск максимума и минимума соответственно)
//* find(поиск элемента, возвращает ссылку на элемент, либо бросает исключение runtime_error, если не нашло элемент)
#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "array.hpp"
#include "vector.hpp"
#include "set.hpp"

namespace lib
{
	template <typename T, size_t arr_size>
	T max(Array<T, arr_size>& arr);

	template <typename T, size_t arr_size>
	T min(Array<T, arr_size>& arr);

	template <typename T, size_t arr_size>
	void sort(Array<T, arr_size>& arr);

	template <typename T, size_t arr_size>
	T& find(Array<T, arr_size>& arr, const T& elem);


	template<typename T>
	T max(Vector<T>& vector);

	template<typename T>
	T min(Vector<T>& vector);

	template<typename T>
	void sort(Vector<T>& vector);

	template<typename T>
	T& find(Vector<T>& vector, const T& elem);
	

	template<typename T>
	T max(Set<T>& set);

	template<typename T>
	T min(Set<T>& set);

	template<typename T>
	T& find(Set<T>& set, const T& elem);
}

#include "algorithms.tpp"

#endif