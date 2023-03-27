#pragma once

template<typename T, size_t N>
void sort(Array<T, N>& arr)
{
	for (int i = 0; i < arr.size() - 1; i++) 
		for (int j = 0; j < arr.size() - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				T tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
}

template<typename T, size_t N>
T min(Array<T, N>& arr)
{
	T min_v = arr[0];
	for (int i = 1; i < arr.size(); ++i) {
		if (arr[i] < min_v) {
			min_v = arr[i];
		}
	}
	return min_v;
}

template<typename T, size_t N>
T max(Array<T, N>& arr)
{
	T max_v = arr[0];
	for (int i = 1; i < arr.size(); ++i) {
		if (arr[i] > max_v) {
			max_v = arr[i];
		}
	}
	return max_v;
}

template<typename T, size_t N>
T& find(Array<T, N>& arr, const T& value)
{
	for (int i = 0; i < arr.size(); ++i) {
		if (arr[i] == value)
			return arr[i];
	}
	throw std::runtime_error("Not found");
}

template<typename T>
void sort(Vector<T>& arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
		for (int j = 0; j < arr.size() - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				T tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}

}

template<typename T>
T max(Vector<T>& arr)
{
	T max_v = arr[0];
	for (int i = 1; i < arr.size(); ++i) {
		if (arr[i] > max_v) {
			max_v = arr[i];
		}
	}
	return max_v;
}

template<typename T>
T min(Vector<T>& arr)
{
	T min_v = arr[0];
	for (int i = 1; i < arr.size(); ++i) {
		if (arr[i] < min_v) {
			min_v = arr[i];
		}
	}
	return min_v;
}

template<typename T>
T& find(Vector<T>& arr, const T& value)
{
	for (int i = 0; i < arr.size(); ++i) {
		if (arr[i] == value)
			return arr[i];
	}
	throw std::runtime_error("Not found");
}

