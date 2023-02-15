#ifndef VECTOR_TPP
#define VECTOR_TPP

namespace VectorMethods {

	template <typename T>
	void Vector<T>::CheckIndex(const size_t& index) const {
		if (index >= size())
			throw std::out_of_range("Error: Index out of range...\n");
	}


	template <typename T>
	Vector<T>::Vector() : vector(new T[0]), v_size(0), max_size(1)
	{
	}

	template <typename T>
	Vector<T>::Vector(const size_t& v_size, const T& value) {
		max_size = 1;
		while (max_size <= v_size)
			max_size *= 2;

		vector = new T[max_size];

		for (size_t i = 0; i < v_size; ++i)
			vector[i] = value;

		this->v_size = v_size;
	}

	template <typename T>
	Vector<T>::Vector(const std::initializer_list<T>& initial_list) {
		max_size = 1;
		while (max_size <= initial_list.size())
			max_size *= 2;

		vector = new T[max_size];

		size_t i = 0;
		for (auto& element : initial_list) {
			vector[i] = element;
			++i;
		}

		this->v_size = initial_list.size();
	}

	template <typename T>
	Vector<T>::Vector(const Vector<T>& another_vector) {
		std::memcpy(vector, another_vector.vector, v_size * sizeof(T));
	}

	template <typename T>
	const Vector<T>& Vector<T>::operator = (const Vector<T>& another_vector) {
		std::memcpy(vector, another_vector.vector, v_size * sizeof(T));
		return *this;
	}

	template <typename T>
	T& Vector<T>::operator [] (const size_t& index) {
		CheckIndex(index);
		return vector[index];
	}

	template <typename T>
	const T& Vector<T>::operator [] (const size_t& index) const {
		CheckIndex(index);
		return vector[index];
	}
	
	template <typename T>
	size_t Vector<T>::size() const {
		return v_size;
	}

	template <typename T>
	bool Vector<T>::empty() const {
		return (size() == 0);
	}

	template <typename T>
	void Vector<T>::resize(const size_t& new_size, const T& value) {
		if (new_size == this->v_size) 
			return;
		else {
			T* dop = new T[new_size];
			for (size_t i = 0; i < new_size; ++i)
				dop[i] = (i < this->v_size ? vector[i] : value);
			delete[] vector;
			vector = dop;
			this->v_size = new_size;

			while ((new_size < max_size / 2) || (max_size < new_size))
				max_size = (new_size < max_size / 2 ? max_size / 2 : (max_size < new_size ? max_size * 2 : max_size));
		}
	}

	template <typename T>
	void Vector<T>::push_back(const T& value) {
		resize(size() + 1);
		vector[size() - 1] = value;
	}

	template <typename T>
	void Vector<T>::emplace_back(T&& value) {
		resize(size() + 1);
		vector[size() - 1] = value;
	}

	template <typename T>
	void Vector<T>::clear() {
		delete[] vector;
		vector = new T;
		max_size = 1;
		v_size = 0;
	}

	template <typename T>
	Vector<T>::~Vector() {
		delete[] vector;
	}
}

#endif