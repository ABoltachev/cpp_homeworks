//*array(статический массив) и методы для него :
    //  +size(возвращает размер)
    //  +empty(возвращает true если пустой)
    //  +взятие по индексу(operator[])
    //  +присваивание копированием
    //  +конструкторы(конструктор с std::inizialized_list)

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

namespace lib {
    template <typename T, size_t arr_size>
    class Array
    {
    private:
        T m_array[arr_size];
        size_t m_size = arr_size;

    public:
        Array();

        Array(std::initializer_list<T> list);

        Array& operator=(const Array& arr);

        T& operator[](size_t ind);
        const T& operator[](size_t ind) const;

        size_t size() const;
        bool empty() const;

        ~Array() = default;
    };

} 

#include "array.tpp"

#endif 
