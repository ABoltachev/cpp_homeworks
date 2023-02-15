#ifndef ALGORITHMS_TPP
#define ALGORITHMS_TPP

namespace lib
{
	template<typename T, size_t arr_size>
	T max(Array<T, arr_size>& arr)
	{
		if (arr_size == 0)
			throw std::logic_error("Size of array is zero");
		T Max = arr[0];
		for (size_t i = 0; i < arr_size; i++)
		{
			if (arr[i] > Max)
				Max = arr[i];
		}
		return Max;
	}
	template<typename T, size_t arr_size>
	T min(Array<T, arr_size>& arr)
	{
		if (arr_size == 0)
			throw std::logic_error("Size of array is zero");
		T Min = arr[0];
		for (size_t i = 0; i < arr_size; i++)
		{
			if (arr[i] < Min)
				Min = arr[i];
		}
		return Min;
	}
	template<typename T, size_t arr_size>
	void sort(Array<T, arr_size>& arr)
	{
		if (arr_size == 0)
			throw std::logic_error("Size of array is zero");
		for (size_t j = 0; j < arr_size - 1; j++)
		{
			for (size_t i = 0; i < arr_size - j - 1; i++) 
			{
				if (arr[i] > arr[i + 1])
				{
					T temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
				}
			}
		}
	}

	template<typename T, size_t arr_size>
	T& find(Array<T, arr_size>& arr, const T& elem)
	{
		if (arr_size == 0)
			throw std::logic_error("Size of array is zero");
		for (size_t i = 0; i < arr_size; i++)
		{
			if (arr[i] == elem)
				return arr[i];
		}
		throw std::runtime_error("Element isn't found");
	}

	template<typename T>
	T max(Vector<T>& vector)
	{
		if (vector.size() == 0)
			throw std::logic_error("Size of vector is zero");
		T Max = vector[0];
		for (size_t i = 0; i < vector.size(); i++)
		{
			if (vector[i] > Max)
				Max = vector[i];
		}
		return Max;
	}
	template<typename T>
	T min(Vector<T>& vector)
	{
		if (vector.size() == 0)
			throw std::logic_error("Size of vector is zero");
		T Min = vector[0];
		for (size_t i = 0; i < vector.size(); i++)
		{
			if (vector[i] > Min)
				Min = vector[i];
		}
		return Min;
	}
	template<typename T>
	void sort(Vector<T>& vector)
	{
		if (vector.size() == 0)
			throw std::logic_error("Size of vector is zero");
		for (size_t j = 0; j < vector.size() - 1; j++)
		{
			for (size_t i = 0; i < vector.size() - j - 1; i++)
			{
				if (vector[i] > vector[i + 1])
				{
					T temp = vector[i];
					vector[i] = vector[i + 1];
					vector[i + 1] = temp;
				}
			}
		}
	}

	template<typename T>
	T& find(Vector<T>& vector, const T& elem)
	{
		if (vector.size() == 0)
			throw std::logic_error("Size of array is zero");
		for (size_t i = 0; i < vector.size(); i++)
		{
			if (vector[i] == elem)
				return vector[i];
		}
		throw std::runtime_error("Element isn't found");
	}

	template<typename T>
	T max(Set<T>& set)
	{
		return set.top();
	}

	template<typename T>
	T min(Set<T>& set)
	{
		return set.min();
	}

	template<typename T>
	T& find(Set<T>& set, const T& elem)
	{
		if (set.find(elem))
			return set.find_v(elem);
		else
			throw std::runtime_error("Element isn't found");
	}
}

#endif