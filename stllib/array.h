#include <iostream>
template<class T>
class Array{
    public:
    Array(int SIZE);
    ~Array();
    void addElement(T element);
    int size();
    bool empty();
    T & operator[](int index); 

    private:
    T * arr;
	int SIZE;
	int preSIZE; 
	int count; 
	int grow; 
};
