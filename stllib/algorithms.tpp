#ifndef ALGORITHMS_TPP
#define ALGORITHMS_TPP

            //Array

//Min-Max

template<typename T, size_t _size>
T getMin(Array<T, _size>& arr) {
    if (_size != 0) {
        T min = arr[0];
        for (size_t i = 1; i < _size; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }

        return min;
    }

    throw std::out_of_range("Array is empty");
}

template<typename T, size_t _size>
T getMax(Array<T, _size>& arr) {
    if (_size != 0) {
        T max = arr[0];
        for (size_t i = 1; i < _size; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }

        return max;
    }

    throw std::out_of_range("Array is empty");
}

//Find

template<typename T, size_t _size>
T& find(Array<T, _size>& arr, const T& obj) {
    if (!arr.empty()) {

        for (size_t i = 0; i < _size; ++i) {
            if (arr[i] == obj) return arr[i];
        }

        throw std::runtime_error("Value not found");
    }

    throw std::logic_error("Array is empty");
}

//Sort

template<typename T, size_t _size>
void bubbleSort(Array<T, _size>& arr) {
    if (!arr.empty()) {
        for (size_t i = 0; i < _size - 1; ++i) {
            for (size_t j = 0; j < _size - i - 1; ++j) {

                if (arr[j] > arr[j + 1]) {
                    T temp = arr[j];

                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        return;
    }

    throw std::logic_error("Array is empty");
}


            //Vector

//Min-Max

template<typename T>
T getMin(vector<T>& arr) {
    if (!arr.empty()) {
        T min = arr[0];
        for (size_t i = 1; i < arr.size(); i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }

        return min;
    }

    throw std::out_of_range("Vector is empty");
}

template<typename T>
T getMax(vector<T>& arr) {
    if (!arr.empty()) {
        T max = arr[0];
        for (size_t i = 1; i < arr.size(); i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }

        return max;
    }

    throw std::out_of_range("Vector is empty");
}

//Find

template<typename T>
T& find(vector<T>& arr, const T& obj) {
    if (!arr.empty()) {
        for (std::size_t i = 0; i < arr.size(); i++) {
            if (arr[i] == obj) {
                return arr[i];
            }
        }

        throw std::runtime_error("Value not found");
    }

    throw std::logic_error("Vector is empty");
}

//Sort

template<typename T>
void bubbleSort(vector<T>& arr) {
    if (!arr.empty()) {
        for (size_t i = 0; i < arr.size() - 1; ++i) {
            for (size_t j = 0; j < arr.size() - i - 1; ++j) {

                if (arr[j] > arr[j + 1]) {
                    T temp = arr[j];

                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        return;
    }

    throw std::logic_error("Vector is empty");
}



            //Set


//Min-Max
template<typename T>
T getMax(const set<T>& arr) {
    return arr.top();
}

template<typename T>
T getMin(const set<T>& arr) {
    return arr.getMin();
}

//Find

template<typename T>
T& find(set<T>& arr, const T& elem) {
    auto curr_elem = arr.nFind(elem);
    if (curr_elem) {
        return curr_elem->value;
    }
    throw std::runtime_error("Value not found");
}


#endif
