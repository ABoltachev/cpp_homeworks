#include "array.h"
template<class T>
Array<T>::Array(int SIZE) 
{
	this->grow = 1;
	this->SIZE = SIZE + grow;
	this->preSIZE = SIZE; 
	this->count = 0; 
	this->arr = new T[this->SIZE]();
}

template<class T>
int Array<T>::size() 
{
	return this->SIZE; 
}

template<class T>
bool Array<T>::empty() 
{
	if (count == 0)
		return false;
	else
		return count; 
}

template<class T>
T & Array<T>::operator[](int index) 
{
	if (index <= count)
		return this->arr[index];
	else
		return this->arr[count];
}

template<class T>
void Array<T>::addElement(T element) 
{
	if (count < this->SIZE)
	{
		this->arr[count] = element;
		count++;
	}
	else
	{
		this->SIZE = this->SIZE + this->grow + 1; 
		T * buf = new T[this->SIZE](); 
		for (size_t i = 0; i < this->SIZE - this->grow; i++)
		{
			buf[i] = arr[i]; 
		}
		delete[] arr;
		arr = new T[this->SIZE]();
		for (size_t i = 0; i < this->SIZE; i++)
		{
			arr[i] = buf[i]; 
		}
		delete[] buf; 
		buf = NULL; 
		arr[count] = element; 
		count++;  
	}
}

template<class T>
Array<T>::~Array() 
{
	delete[] arr; 
	arr = NULL; 
}