#ifndef ALGORITHMS_TPP
#define ALGORITHMS_TPP

template<typename Data, size_t size>
void sort(Array<Data, size>& arr)
{
	for (int i = 0; i < arr.size() - 1; i++) 
		for (int j = 0; j < arr.size() - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				Data tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
}

template<typename Data, size_t size>
Data max(Array<Data, size>& arr)
{
	Data max_v = arr[0];
	for (int i = 1; i < arr.size(); ++i) {
		if (arr[i] > max_v) {
			max_v = arr[i];
		}
	}
	return max_v;
}

template<typename Data, size_t size>
Data min(Array<Data, size>& arr)
{
	Data min_v = arr[0];
	for (int i = 1; i < arr.size(); ++i) {
		if (arr[i] < min_v) {
			min_v = arr[i];
		}
	}
	return min_v;
}

template<typename Data, size_t size>
Data& find(Array<Data, size>& arr, const Data& sym)
{
	for (int i = 0; i < arr.size(); ++i) {
		if (arr[i] == sym)
			return arr[i];
	}
	throw std::runtime_error("Not");
}

template<typename Data>
void sort(Vector<Data>& vec)
{
	for (int i = 0; i < vec.size() - 1; i++)
		for (int j = 0; j < vec.size() - i - 1; ++j) {
			if (vec[j] >vec[j + 1]) {
				Data tmp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = tmp;
			}
		}

}

template<typename Data>
Data max(Vector<Data>& vec)
{
	Data max_v = vec[0];
	for (int i = 1; i < vec.size(); ++i) {
		if (vec[i] > max_v) {
			max_v = vec[i];
		}
	}
	return max_v;
}

template<typename Data>
Data min(Vector<Data>& vec)
{
	Data min_v = vec[0];
	for (int i = 1; i < vec.size(); ++i) {
		if (vec[i] < min_v) {
			min_v = vec[i];
		}
	}
	return min_v;
}

template<typename Data>
Data& find(Vector<Data>& vec, const Data& sym)
{
	for (int i = 0; i < vec.size(); ++i) {
		if (vec[i] == sym)
			return vec[i];
	}
	throw std::runtime_error("Not");
}

#endif