#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <stdexcept>


template<typename T>
class vector {
private:
    T* m_arr;
    size_t m_size;
    size_t m_tonnage;

    void check_index(size_t& ind) const;
public:
    vector();
    vector(size_t size, const T& value = T());

    vector(const vector& other);
    vector(vector&& other);

    vector(std::initializer_list<T> list);

    bool empty() const;
    size_t size() const;

    void addMem(size_t n_tonnage);

    void push_back(const T& elem);
    void emplace_back(T&& elem);

    void resize(size_t& _size_, const T &value=T());
    void clear();

    T& operator[](size_t& ind);
    const T& operator[](size_t& ind) const;

    vector& operator=(const vector<T>& arr);
    vector& operator=(vector<T>&& arr);

    ~vector();
};

#include "vector.tpp"

#endif
