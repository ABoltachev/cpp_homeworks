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

#include <algorithm>
#include <initializer_list>
#include <stdexcept>

namespace hw
{
    template<typename T>
    class vector
    {
    private:
        T* buffer{nullptr};
        std::size_t __size{0},capacity{0};
    
    public:
        vector();
        vector(std::size_t size);
        vector(std::size_t size, T init_value);
        vector(const vector<T>&);
        vector(vector<T>&&);
        vector(std::initializer_list<T> list);

        std::size_t size() const;
        bool empty() const;

        void resize(std::size_t new_size);
        void resize(std::size_t new_size, T init_value);
        void clear();
        void push_back(const T& value);
        void emplace_back(T&& value);

        void operator=(const vector<T>&);
        T& operator[](std::size_t);
    };

    template<typename T>
    vector<T>::vector()
    {
        this->capacity = 10;
        this->buffer = new T[this->capacity];

    }

    template<typename T>
    vector<T>::vector(const vector<T>& other)
    {
        this->buffer = new T[other.capacity];
        this->__size = other.size;
        this->capacity = other.capacity;
        for(std::size_t i(0); i < this->size; ++i)
            this->buffer[i] = other.buffer[i];
    }

    template<typename T>
    vector<T>::vector(std::initializer_list<T> list)
    {
        this->capacity = list.size()*2;
        this->__size = list.size();
        this->buffer = new T[this->capacity];
        std::size_t i = 0;
        for(const T& el : list)
            this->buffer[i++] = el;
    }

    template<typename T>
    vector<T>::vector(std::size_t size)
    {
        this->capacity = size*2;
        this->buffer = new T[this->capacity];
        this->size = size;
    }

    template<typename T>
    vector<T>::vector(std::size_t size, T init_value)
    {
        this->capacity = size*2;
        this->buffer = new T[this->capacity];
        this->__size = size;
        for(std::size_t i(0); i < this->__size; ++i)
            this->buffer[i] = init_value;
    }

    template<typename T>
    vector<T>::vector(vector<T>&& other)
    {
        *this = other;
        this->buffer = new T[this->capacity];
        for(std::size_t i(0); i < this->__size; ++i)
            this->buffer[i] = other.buffer[i];
        other.buffer = nullptr;
    }

    template<typename T>
    std::size_t vector<T>::size() const { return this->__size; }

    template<typename T>
    bool vector<T>::empty() const { return this->__size != 0; }

    template<typename T>
    T& vector<T>::operator[](std::size_t i) { return this->buffer[i]; }

    template<typename T>
    void vector<T>::operator=(const vector<T>& other)
    {
        this->buffer = new T[other.capacity];
        this->__size = other.__size;
        this->capacity = other.capacity;
        for(std::size_t i(0); i < this->__size; ++i)
            this->buffer[i] = other.buffer[i];
    }

    template<typename T>
    void vector<T>::resize(std::size_t new_size)
    {
        T* new_buff = new T[new_size];
        for(std::size_t i(0); i < this->__size; ++i)
            new_buff[i] = this->buffer;
        this->buffer = new_buff;
        this->__size = new_size;
        this->capacity = new_size;
    }

    template<typename T>
    void vector<T>::resize(std::size_t new_size, T init_value)
    {
        T* new_buff = new T[new_size];
        for(std::size_t i(0); i < this->__size; ++i)
            new_buff[i] = this->buffer[i];
        for(std::size_t i(this->__size); i < new_size; ++i)
            new_buff[i] = init_value;
        this->buffer = new_buff;
        this->__size = new_size;
        this->capacity = new_size;
    }

    template<typename T>
    void vector<T>::clear()
    {
        this->__size = 0;
    }

    template<typename T>
    void vector<T>::push_back(const T& value)
    {
        if(this->__size >= this->capacity)
        {
            this->capacity *= 2;
            T* new_buff = new T[this->capacity];
            for(std::size_t i(0); i < this->__size; ++i)
                new_buff[i] = this->buffer[i];
            this->buffer = new_buff;
        }
        this->buffer[this->__size] = value;
        ++this->__size;
    }

    template<typename T>
    void vector<T>::emplace_back(T&& value)
    {
        if(this->__size >= this->capacity)
        {
            this->capacity *= 2;
            T* new_buff = new T[this->capacity];
            for(std::size_t i(0); i < this->__size; ++i)
                new_buff[i] = this->buffer[i];
            this->buffer = new_buff;
        }
        this->buffer[this->__size] = value;
        ++this->__size;
    }
}