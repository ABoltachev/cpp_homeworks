/*
* array (статический массив) и методы для него:
    size (возвращает размер)
    empty (возвращает true если пустой)
    взятие по индексу (operator[])
    присваивание копированием
    конструкторы (конструктор с std::inizialized_list)
*/
#include "array.hpp"

template<typename T, size_t aSize>
Array<T, aSize>::Array(const std::initializer_list<T> &init_list )
{
    int i = 0;
    
    for(const T element: init_list)
    {
        array[i++] = element;
    }

}

template<typename T, size_t aSize>
Array<T, aSize>& Array<T, aSize>::operator=(const Array<T, aSize> &other_array){

    for (int i = 0; i < arraySize; i++){
        array[i] = other_array[i];
    }
    return *this;
}

template<typename T, size_t aSize>
size_t Array<T, aSize>::size(){

    return aSize;
}

template<typename T, size_t aSize>
bool Array<T, aSize>::empty(){
    return (aSize == 0);
}

template<typename T, size_t aSize>
T& Array<T, aSize>::operator[](int index){
    if ((index < 0) or (index >= size())) {
        throw std::out_of_range("Index out of range");
    }
    return array[index];
}