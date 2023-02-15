#include <iostream>

template<typename T>
class Vector {
    private:
    T* arr;
    size_t size{};
    size_t capacity{};

    public:
    Vector(){
        arr= new T[1];
        capacity = 1
    }

    size_t size() const {
		return size;
    }

    bool Empty() const {
		return size == 0;
    }

    T &operator[](size_t index)  {
		return arr[index];
    }

    void pushBack(const T& value) {
		if (size >= capacity) addMemory();
    arr[size++] = value;
    }
};