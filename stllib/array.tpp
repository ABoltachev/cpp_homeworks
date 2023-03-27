#ifndef ARRAY_TPP
#define ARRAY_TPP

template<class T, size_t param_size>
size_t array<T, param_size>::size() const{
    return m_size;
};

template<class T, size_t param_size>
bool array<T, param_size>::empty() const{
    if (m_size == 0)
        return true;
    else
        return false;
};

template<class T, size_t param_size>
T& array<T, param_size>::operator[](size_t index){
    if (index < 0 || index >= m_size) {
            throw std::out_of_range("Index: " + std::to_string(index) + " out of range");
        }
    return m_array[index];
};

template<class T, size_t param_size>
const T& array<T, param_size>::operator[](size_t index) const{
    if (index < 0 || index >= m_size) {
            throw std::out_of_range("Index: " + std::to_string(index) + " out of range");
        }
    return m_array[index];
};

template<class T, size_t param_size>
array<T, param_size>& array<T, param_size>::operator=(const array& obj){
    if (this == &obj)
        return *this;

    for(int i = 0; i < m_size; ++i){
        this->m_array[i] = obj.m_array[i];
    }

    return *this;
};

template<class T, size_t param_size>
T* array<T, param_size>::begin(){
    return m_array;
}

template<class T, size_t param_size>
T* array<T, param_size>::end(){
    return m_array + m_size - 1;
}

#endif