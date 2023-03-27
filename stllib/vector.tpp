#ifndef VECTOR_TPP
#define VECTOR_TPP

namespace VectorMethods {

	template <typename vT>
	void Vector<vT>::CheckIndex(const size_t& index) const {
		if (index >= size())
			throw std::out_of_range("Error: Index out of range...\n");
	}


	template <typename vT>
	Vector<vT>::Vector() : vector(new vT[0]), v_size(0), max_size(1)
	{
	}

	template <typename vT>
	Vector<vT>::Vector(const size_t& v_size, const vT& value) {
		max_size = 1;
		while (max_size <= v_size)
			max_size *= 2;

		vector = new vT[max_size];

		for (size_t i = 0; i < v_size; ++i)
			vector[i] = value;

		this->v_size = v_size;
	}

	template <typename vT>
	Vector<vT>::Vector(const std::initializer_list<vT>& initial_list) {
		max_size = 1;
		while (max_size <= initial_list.size())
			max_size *= 2;

		vector = new vT[max_size];

		size_t i = 0;
		for (auto& element : initial_list) {
			vector[i] = element;
			++i;
		}

		this->v_size = initial_list.size();
	}

	template <typename vT>
	Vector<vT>::Vector(const Vector<vT>& another_vector) {
		std::memcpy(vector, another_vector.vector, v_size * sizeof(vT));
	}

	template <typename vT>
	const Vector<vT>& Vector<vT>::operator = (const Vector<vT>& another_vector) {
		std::memcpy(vector, another_vector.vector, v_size * sizeof(vT));
		return *this;
	}

	template <typename vT>
	vT& Vector<vT>::operator [] (const size_t& index) {
		CheckIndex(index);
		return vector[index];
	}

	template <typename vT>
	const vT& Vector<vT>::operator [] (const size_t& index) const {
		CheckIndex(index);
		return vector[index];
	}
	
	template <typename vT>
	size_t Vector<vT>::size() const {
		return v_size;
	}

	template <typename vT>
	bool Vector<vT>::empty() const {
		return (size() == 0);
	}

	template <typename vT>
	void Vector<vT>::resize(const size_t& new_size, const vT& value) {
		if (new_size == this->v_size) 
			return;
		else {
			vT* dop = new vT[new_size];
			for (size_t i = 0; i < new_size; ++i)
				dop[i] = (i < this->v_size ? vector[i] : value);
			delete[] vector;
			vector = dop;
			this->v_size = new_size;

			while ((new_size < max_size / 2) || (max_size < new_size))
				max_size = (new_size < max_size / 2 ? max_size / 2 : (max_size < new_size ? max_size * 2 : max_size));
		}
	}

	template <typename vT>
	void Vector<vT>::push_back(const vT& value) {
		resize(size() + 1);
		vector[size() - 1] = value;
	}

	template <typename vT>
	void Vector<vT>::emplace_back(vT&& value) {
		resize(size() + 1);
		vector[size() - 1] = value;
	}

	template <typename vT>
	void Vector<vT>::clear() {
		delete[] vector;
		vector = new vT;
		max_size = 1;
		v_size = 0;
	}

	template <typename vT>
	Vector<vT>::~Vector() {
		delete[] vector;
	}
}

#endif