/*
* vector и методы для него (самая простая реализация с использованием динамического массива, если размера не хватает, чтобы добавить эелемент в конец, просто расширяется в два раза):
    size (возвращает размер)
    empty (возвращает true если пустой)
    взятие по индексу (operator[])
    push_back (вставка в конец (копирование))
    emplace_back (вставка в конце (перемещение))
    clear (очистка)
    resize (изменение размера, вторым аргументом идет аргумент по умолчанию, которым будут заполняться все места)
    присваивание (копирование и перемещением)
    конструкторы (конструктор без аргументов; первый аргумент размер, второй по умолчанию со значением, которым будут заполняться все места; копирования; перемещения; конструктор с std::inizialized_list)
*/

#include "vector.hpp"

template<typename T>
void Vector<T>::shape(size_t newCapacity){
    T *temp = new T[newCapacity];
    size_t tempSize = vSize;
    if (newCapacity < tempSize)
        tempSize = newCapacity;
    for (int i = 0; i < tempSize; i++)
            temp[i] = vector[i];
        delete [] vector;
        vector = temp;
        vCapacity = newCapacity;
}

template<typename T>
Vector<T>::Vector(size_t size, T value): vector(new T[size]), vSize(size), vCapacity(size)
{
    for (int i = 0; i < vSize; i++){
        vector[i] = value;
    }
}

template<typename T>
Vector<T>::Vector(const Vector<T>& other): vector(new T[size]), vSize(other.vSize), vCapacity(other.vCapacity)
{
    for (int i = 0; i < vSize; i++){
        vector[i] = other.vector[i];
    }
}

template<typename T>
Vector<T>::Vector(Vector<T>&& other): vector(other.vector), vSize(other.vSize), vCapacity(other.vCapacity)
{
    other.vector = nullptr;
    other.vSize = 0;
    other.vCapacity = 0;
}


template<typename T>
Vector<T>::Vector(const std::initializer_list<T>& init_list): vector(new T[size]), vSize(init_list.size()), vCapacity(init_list.size())
{
    int i = 0;
    for (const T &element: init_list) {
        vector[i] = element;
    }
}

template<typename T>
Vector<T>& Vector<T>::operator= (const Vector<T>& other)
{
    if (this != &other) {
        clear();
        vector = new T[other.vCapacity];
        for (int i = 0; i < other._capacity_; i++)
        {
            vector[i] = other.vector[i];
        }
        vSize = other.vSize;
        vCapacity = other.vCapacity;
    }
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator= (Vector<T>&& other)
{
    if (this != &other) {
        vector = other.vector;
        vSize = other.vSize;
        vCapacity = other.vCapacity;

        other.vector = nullptr;
        other.vSize = 0;
        other.vCapacity = 0;
    }
    return *this;
}

template<typename T>
size_t Vector<T>::size()
{
    return vSize;
}

template<typename T>
bool Vector<T>::empty()
{
    return (vSize == 0);
}

template<class T>
void Vector<T>::clear()
{
    delete[] vector;

    vector = new T[vCapacity];
    vSize = 0;
}

template<typename T>
T& Vector<T>::operator[](int index){
    if ((index < 0) or (index >= size())) {
        throw std::out_of_range("Index out of range");
    }
    return vector[index];
}

template<typename T>
void Vector<T>::resize(size_t newSize, T value){

    if (newSize <= 0)
        throw std::logic_error("Vector has incorrect size");

    if (newSize > vCapacity)
        shape(newSize);

    for (size_t i = vSize; i < newSize; i++)
        vector[i] = value;

    vSize = newSize;

}

template<typename T>
void Vector<T>::push_back(const T& element) {

    if (vSize == vCapacity)
        shape(vCapacity*2);

    vector[vSize++] = element;

}

template<typename T>
void Vector<T>::emplace_back(T&& element) {

    if (vSize == vCapacity)
        shape(vCapacity*2);

    vector[vSize++] = std::move(element);

}
