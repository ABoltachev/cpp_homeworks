#ifndef HW2_C___ALGORITHMS_HPP
#define HW2_C___ALGORITHMS_HPP

#include "vector.hpp"
#include "array.hpp"
#include "set.hpp"


            //Array
//Min-Max
template<typename T, size_t _size>
T getMin(Array<T, _size>& arr);

template<typename T, size_t _size>
T getMax(Array<T, _size>& arr);

//Find

template<typename T, size_t _size>
T& find(Array<T, _size>& arr_, const T& obj);

//Sort

template<typename T, size_t _size>
void bubbleSort(Array<T, _size>& arr);


            //Vector

//Min-Max
template<typename T>
T getMin(vector<T>& arr);

template<typename T>
T getMax(vector<T>& arr);

//Find

template<typename T>
T& find(vector<T>& arr_, const T& obj);

//Sort

template<typename T>
void bubbleSort(vector<T>& arr);


            //Set

//Min-Max

template<typename T>
T getMin(set<T>& arr);

template<typename T>
T getMax(set<T>& arr);

//Find

template<typename T>
T& find(set<T>& arr, const T& elem);



            //Range

class Iterator {
private:
    int64_t m_curr;

public:
    Iterator(int64_t start) : m_curr(start) {}

    int64_t& operator*() {
        return m_curr;
    }

    const int64_t& operator*() const {
        return m_curr;
    }

    bool operator!=(const Iterator &other) {
        return other.m_curr != m_curr;
    }

    Iterator& operator++() {
        ++m_curr;
        return *this;
    }
};

class range {
private:
    int64_t  m_start;
    int64_t  m_end;
    int64_t  m_step;

public:
    range(int64_t end) : m_start(0), m_end(end), m_step(1) {}
    range(int64_t start, int64_t end, int64_t step=1) : m_start(start), m_end(end), m_step(step) {}

    Iterator begin() const { return {m_start}; }
    Iterator end() const  { return {m_end}; }
};


#include "algorithms.tpp"

#endif
