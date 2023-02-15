#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

template<class T>
void sort(T* first, T* last){
    if (last - first == 0)
        return;
    int size = last - first + 1;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1 ; j++) {
            if (*(j + first) > *(first + j + 1)) {
                T tmp = *(first + j);
                *(j + first) = *(first + j + 1);
                *(first + j + 1) = tmp;
            }
        }
    }
}

template<class T>
T max(T* first, T* last){
    if (last - first == 0){
        return *first;
    }
    int size = last - first + 1;
    T max = *first;
    for (int i = 0; i < size; i++) {
        if (*(first + i) > max) {
            max = *(first + i);
        }
    }
    return max;
}

template<class T>
T min(T* first, T* last){
    if (last - first == 0){
        return *first;
    }
    int size = last - first + 1;
    T min = *first;
    for (int i = 0; i < size; i++) {
        if (*(first + i) < min) {
            min = *(first + i);
        }
    }
    return min;
}

template<class T>
T& find(T* first, T* last, T elem){
    int size = last - first + 1;
    for (int i = 0; i < size; i++){
        if (*(first + i) == elem)
            return *(first + i);
    }
    throw std::runtime_error("no element");
}
#endif