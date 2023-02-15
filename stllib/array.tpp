#ifndef ARRAY_TPP
#define ARRAY_TPP

template<typename Data, size_t size>
Array<Data, size>::Array(const std::initializer_list<Data>& init_list): {
	size_t i = 0;
    for (auto it: init_list) {
        m_arr[i] = it;
        ++i;
    }
}

template <typename Data, size_t size>
size_t Array<Data, size>::size() const {
    return size;
}

template <typename Data size_t size>
bool Array<Data, size>::empty() const {
    return m_arr==nullptr;
}
template <typename Data,size_t size>
void Array<Data, size>::check(size_t idx) const {
    if (idx >= m_size) {
        throw std::out_of_range("idx incorrect");
    }
    if (idx <0) {
        throw std::out_of_range("idx incorrect");
    }
}

template <typename Data, size_t size>
Data& Array<Data, size>::operator[](size_t &idx) {
    check(idx);
    return m_arr[idx];
}

template <typename Data, size_t size>
const Data& Array<Data, size>::operator[](size_t &idx) const {
    check(idx);
    return m_arr[idx];
}

template <typename Data, size_t size>
Array<Data, size> &Array<Data, size>::operator=(Array<Data, size> &&obj) {
    if (&obj != this) {
        for (int i = 0; i < m_size; ++i) {
            m_arr[i] = obj.m_arr[i];
        }
    }
    return *this;
}

template <typename Data, size_t size>
Array<Data, size> &Array<Data, size>::operator=(const Array<Data, size> &obj) {
    if (&obj != this) {
        for (int i = 0; i < m_size; ++i) {
            m_arr[i] = obj.m_arr[i];
        }
    }
    return *this;
}


#endif
