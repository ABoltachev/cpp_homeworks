#ifndef MY_ARRAY_HPP
#define MY_ARRAY_HPP

#include <iostream>
#include <exception>

namespace MyStdLib {

    template<typename T, size_t arr_size>
    class MyArray;


    template<typename T, size_t arr_size>
    void copy_arr(MyArray<T, arr_size>& a, const MyArray<T, arr_size>& b);

    template<typename T, size_t arr_size>
    std::ostream& operator<<(std::ostream& out, const MyArray<T, arr_size>& arr);

    template<typename T, size_t arr_size>
    class MyArray {
    private:
        T m_arr[arr_size];
        
        size_t m_size = arr_size;
        
    public:
        MyArray() = default;
        
        MyArray(const MyArray<T, arr_size>& arr);
        
        MyArray(const std::initializer_list<T>& values);

        size_t size() const;
        
        bool empty() const;
        
        T& operator[](size_t ind);
        
        void display_temp() const;

        MyArray& operator=(const MyArray& other); // !!!!!!!

        friend void copy_arr <>(MyArray<T, arr_size>& a, const MyArray<T, arr_size>& b);
        
        friend std::ostream& operator<< <>(std::ostream& out, const MyArray<T, arr_size>& arr);
        // const T operator[](int ind) const;
    };

}

#include "MyArray.tpp"

#endif