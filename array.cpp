#include "array.h"

template<typename T, std::size_t S>
bool Array<T, S>::empty() {
    return (S == 0);
}

template<typename T, std::size_t S>
std::size_t Array<T, S>::size() {
    return S;
}

template<typename T, std::size_t S>
Array<T, S> &Array<T, S>::operator=(const Array<T, S> &arr) {
    for (auto i = 0; i < S; ++i) {
        m_array[i] = arr[i];
    }
    return *this;
}

template<typename T, std::size_t S>
T &Array<T, S>::operator[](std::size_t index) {
    return m_array[index];
}

template<typename T, std::size_t S>
Array<T, S>::Array(std::initializer_list<T> list) {
    int i = 0;
    for (const auto &val: list) {
        m_array[i++] = val;
    }
}