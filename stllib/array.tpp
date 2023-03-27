#ifndef ARRAY_TPP
#define ARRAY_TPP

namespace ArrayMethods {

	template <typename T, size_t T_size>
	void Array<T, T_size>::CheckIndex(const size_t& index) const {
		if (index < 0 || index >= arr_size)
			throw std::out_of_range("Error: Index out of range...\n");
	}

	template <typename T, size_t T_size>
	Array<T, T_size>::Array() : arr_size(T_size) {
		for (size_t i = 0; i < T_size; ++i) {
			array[i] = 0;
		}
	}

	template <typename T, size_t T_size>
	Array<T, T_size>::Array(const std::initializer_list<T>& initial_list) {
		size_t i = 0;
		for (auto element : initial_list) {
			array[i] = element;
			++i;
		}
	}

	template <typename T, size_t T_size>
	Array<T, T_size>::Array(const Array<T, T_size>& another_array) {
		std::memcpy(array, another_array.array, T_size * sizeof(T));
	}

	template <typename T, size_t T_size>
	const Array<T, T_size>& Array<T, T_size>::operator = (const Array<T, T_size>& another_array) {
		std::memcpy(array, another_array.array, T_size * sizeof(T));
		return *this;
	}

	template <typename T, size_t T_size>
	T& Array<T, T_size>::operator [] (const size_t& index) {
		CheckIndex(index);
		return array[index];
	}

	template <typename T, size_t T_size>
	const T& Array<T, T_size>::operator [] (const size_t& index) const {
		CheckIndex(index);
		return array[index];
	}

	template <typename T, size_t T_size>
	size_t Array<T, T_size>::size() const {
		return T_size;
	}

	template <typename T, size_t T_size>
	bool Array<T, T_size>::empty() const {
		return (size() == 0);
	}
}

#endif