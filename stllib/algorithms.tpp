/*
На вход каждого алгоритма подается контейнер, который вы реализовали
 * sort (простая сортировка, либо пузырьком, либо вставками)
 * max; min (поиск максимума и минимума соответственно)
 * find (поиск элемента, возвращает ссылку на элемент, либо бросает исключение runtime_error, если не нашло элемент)

Доп задание (доп бал):
    Реализовать функцию range (аналог функции из Python) по аналогии с функцией enumerate с семинара
    Должно быть 2 перегрузки
     * range(int stop)
     * range(int start, int stop, int step=1)
*/

#include "algorithms.hpp"

template<typename T, size_t aSize>
void sort(Array<T, aSize>& array){
    int i, j;
    for (i = 0; i < aSize - 1; i++)
        for (j = 0; j < aSize - i - 1; j++)
            if (array[j] > array[j + 1]){
                T temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
}

template<typename T>
void sort(Vector<T>& vector){
    int i, j;
    for (i = 0; i < vector.size() - 1; i++)
        for (j = 0; j < vector.size() - i - 1; j++)
            if (vector[j] > vector[j + 1]){
                T temp = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = temp;
            }
}

template<typename T, size_t aSize>
void max(Array<T, aSize>& array){
    if (array.size() == 0){
        throw std::out_of_range("Empty array");
    }
    T max = array[0];
    for (int i = 0; i < array.size(); i++){
        if (max < array[i]){
            max = array[i];
        }
    }
}

template<typename T, class Compare>
void max(Set<T, Compare>& set){
    return set.top();
}

template<typename T>
void max(Vector<T>& vector){
    if (vector.size() == 0){
        throw std::out_of_range("Empty array");
    }
    T max = vector[0];
    for (int i = 0; i < vector.size(); i++){
        if (max < vector[i]){
            max = vector[i];
        }
    }
}

template<typename T, size_t aSize>
void min(Array<T, aSize>& array){
    if (array.size() == 0){
        throw std::out_of_range("Empty array");
    }
    T min = array[0];
    for (int i = 0; i < array.size(); i++){
        if (min > array[i]){
            min = array[i];
        }
    }
}


template<typename T, class Compare>
void min(Set<T, Compare>& set){
    return set.bottom();
}

template<typename T>
void min(Vector<T>& vector){
    if (vector.size() == 0){
        throw std::out_of_range("Empty array");
    }
    T min = vector[0];
    for (int i = 0; i < vector.size(); i++){
        if (min > vector[i]){
            min = vector[i];
        }
    }
}

template<typename T, size_t aSize>
T& find(Array<T, aSize>& array, T element){

    if (array.size() == 0){
        throw std::out_of_range("Empty array");
    }

    for(int i = 0; i < array.size(); i++)
    {
        if (array[i] == element)
            return array[i];
    }

    throw std::out_of_range("Not found");

}

template<typename T>
T& find(Vector<T>& vector, T element){

    if (vector.size() == 0){
        throw std::out_of_range("Empty array");
    }

    for(int i = 0; i < vector.size(); i++)
    {
        if (vector[i] == element)
            return vector[i];
    }

    throw std::out_of_range("Not found");

}

template<typename T, size_t aSize>
Vector<T>& range(Array<T, aSize>& array, int stop){
    T tVector = new T[stop];
    size_t tSize = stop;
    size_t tCapacity = stop;
    for (int i = 0; i < stop; i++){
        tVector[i] = array.array[i];
    }
    return Vector(tVector, tSize, tCapacity);
}

template<typename T>
Vector<T>& range(Vector<T>& vector, int stop){
    T tVector = new T[stop];
    size_t tSize = stop;
    size_t tCapacity = stop;
    for (int i = 0; i < stop; i++){
        tVector[i] = vector.vector[i];
    }
    return Vector(tVector, tSize, tCapacity);
}

template<typename T, size_t aSize>
Vector<T>& range(Array<T, aSize>& array, int start, int stop, int step){
    T tVector = new T[stop - start];
    size_t tSize = stop - start;
    size_t tCapacity = stop - start;
    for (int i = start; i < stop; i = i + step){
        tVector[i] = array.array[i];
    }
    return Vector(tVector, tSize, tCapacity);
}

template<typename T>
Vector<T>& range(Vector<T> vector, int start, int stop, int step){
    T tVector = new T[stop - start];
    size_t tSize = stop - start;
    size_t tCapacity = stop - start;
    for (int i = 0; i < stop; i = i + step){
        tVector[i] = vector.vector[i];
    }
    return Vector(tVector, tSize, tCapacity);
}