/*
* array (статический массив) и методы для него:
    size (возвращает размер)
    empty (возвращает true если пустой)
    взятие по индексу (operator[])
    присваивание копированием
    конструкторы (конструктор с std::inizialized_list)
*/

#include <algorithm>
#include <initializer_list>
#include <stdexcept>

namespace hw
{
    template<typename T, std::size_t Size>
    class array
    {
    private:
        T buffer[Size+1];
    
    public:
        class iterator : public std::iterator<std::random_access_iterator_tag,T>
        {
        private:
            T* ptr;
        public:
            iterator() = delete;
            explicit iterator(T* ptr);
            iterator& operator++();
            iterator operator++(int);
            bool operator==(const iterator& other);
            bool operator!=(const iterator& other);
            T& operator*();

            friend array<T,Size+1>;
        };
        array() = default;
        array(const array<T,Size>&);
        array(std::initializer_list<T> list);

        constexpr std::size_t size() const;
        constexpr bool empty() const;

        void operator=(const array<T,Size>&);
        T& operator[](std::size_t);

        iterator begin();
        iterator end();
    };

    template<typename T, std::size_t Size>
    array<T,Size>::iterator::iterator(T* ptr) : ptr(ptr) {}

    template<typename T, std::size_t Size>
    typename array<T,Size>::iterator& array<T,Size>::iterator::operator++() { ++this->ptr; return *this; }

    template<typename T, std::size_t Size>
    typename array<T,Size>::iterator array<T,Size>::iterator::operator++(int)
    {
        auto temp = *this;
        ++this->ptr;

        return temp;
    }

    template<typename T, std::size_t Size>
    bool array<T,Size>::iterator::operator==(const iterator& other) { return this->ptr == other.ptr; }

    template<typename T, std::size_t Size>
    bool array<T,Size>::iterator::operator!=(const iterator& other) { return this->ptr != other.ptr; }

    template<typename T, std::size_t Size>
    T& array<T,Size>::iterator::operator*() { return *ptr; }

    template<typename T, std::size_t Size>
    array<T,Size>::array(const array<T,Size>& other)
    {
        for(std::size_t i(0); i < Size; ++i)
            this->buffer[i] = other.buffer[i];
    }

    template<typename T, std::size_t Size>
    array<T,Size>::array(std::initializer_list<T> list)
    {
        if(list.size() > Size)
            throw std::invalid_argument("Initializer list size is larger than array size");
        std::size_t i = 0;
        for(const T& el : list)
            this->buffer[i++] = el;
    }

    template<typename T, std::size_t Size>
    constexpr std::size_t array<T,Size>::size() const { return Size; }

    template<typename T, std::size_t Size>
    constexpr bool array<T,Size>::empty() const { return Size != 0; }

    template<typename T, std::size_t Size>
    T& array<T,Size>::operator[](std::size_t i) { return this->buffer[i]; }

    template<typename T, std::size_t Size>
    void array<T,Size>::operator=(const array<T,Size>& other)
    {
        for(std::size_t i(0); i < Size; ++i)
            this->buffer[i] = other.buffer[i];
    }

    template<typename T, std::size_t Size>
    typename array<T,Size>::iterator array<T,Size>::begin()
    {
        return iterator(this->buffer);
    }

    template<typename T, std::size_t Size>
    typename array<T,Size>::iterator array<T,Size>::end()
    {
        return iterator(this->buffer+Size);
    }
}