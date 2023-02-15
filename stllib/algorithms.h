#include "vector.h"
#include "array.h"

namespace stl {
    template<class T, size_t array_size>
    void sort(Array<T, array_size>& container);

    template<class T>
    auto min(T container);

    template<class T>
    auto max(T container);

    template<class data_type, size_t array_size>
    data_type& find(Array<data_type, array_size> container, data_type elem);

    template<class data_type>
    data_type& find(Vector<data_type> container, data_type elem);
}

#include "algorithms.tpp"
