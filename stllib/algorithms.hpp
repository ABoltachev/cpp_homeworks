#include <stdexcept>
#include "array.hpp"
#include "vector.hpp"
#include "set.hpp"

//array
template <typename T, std::size_t N>
void sort(Array<T, N>& arr);

template <typename T, std::size_t N>
T max(Array<T, N>& arr);

template <typename T, std::size_t N>
T min(Array<T, N>& arr);

template <typename T, std::size_t N>
T& find(Array<T, N>& arr, const T& val);

//vector
template<typename T>
void sort(Vector<T>& vec);

template<typename T>
T max(Vector<T>& vec);

template<typename T>
T min(Vector<T>& vec);

template<typename T>
T& find(Vector<T>& vec, const T& val);

//set
template<typename T>
T min(Set<T>& arr);

template<typename T>
T max(Set<T>& arr);

template<typename T>
T& find(Set<T>& arr, const T& value);
