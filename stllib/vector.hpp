#ifndef VECTOR_HPP
#define VECTOR_HPP

template<class T>
class vector{
    private:
        T* m_vector = nullptr;
        size_t m_size = 0;
        size_t m_capacity = 0;
    public:
        vector() = default;
        vector(size_t size): m_size(size){
            m_capacity = size*2;
            m_vector = new T[m_capacity];
        };
        vector(size_t size, const T& elem): m_size(size){
            m_capacity = size*2;
            m_vector = new T[m_capacity];
            for(int i = 0; i < size; ++i){
                m_vector[i] = elem;
            }
        };
        vector(const vector& obj): m_size(obj.m_size), m_capacity(obj.m_capacity){
            m_vector = new T[m_capacity];
            for(int i = 0; i < m_size; ++i){
                m_vector[i] = obj.m_vector[i];
            }
        };
        vector(vector&& obj): m_size(obj.m_size), m_capacity(obj.m_capacity){
            m_vector = obj.m_vector;
            obj.m_vector = nullptr;
            obj.m_size = 0;
            obj.m_capacity = 0;
        };
        vector(const std::initializer_list<T> &list): m_size(list.size()), m_capacity(list.size()*2){
            m_vector = new T[m_capacity];
            int index = 0;
            for (auto it = list.begin(); it != list.end(); ++it){
                m_vector[index] = *it;
                index++;
            }
        };

        vector& operator=(const vector& obj);

        vector& operator=(vector&& obj);

        void resize(size_t size);

        void resize(size_t size, const T& elem);

        void clear();

        void emplace_back(T&& elem);

        void push_back(const T& elem);

        const T& operator[](size_t ind) const;

        T& operator[](size_t ind);

        bool empty() const;

        size_t size() const;

        T* begin();

        T* end();
};

#include "vector.tpp"
#endif