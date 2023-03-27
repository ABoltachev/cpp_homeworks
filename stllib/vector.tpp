#ifndef VECTOR_TPP
#define VECTOR_TPP

template<class T>
vector<T>& vector<T>::operator=(const vector& obj){
    if (this == &obj)
        return *this;

    delete[] m_vector;
    m_size = obj.m_size;
    m_capacity = obj.m_capacity;
    m_vector = new T[m_capacity];

    for(int i = 0; i < m_size; ++i){
        m_vector[i] = obj.m_vector[i];
    }
    return *this;
}

template<class T>
vector<T>& vector<T>::operator=(vector&& obj){
    if (this == &obj)
        return *this;

    delete[] m_vector;

    m_size = obj.m_size;
    m_capacity = obj.m_capacity;
    m_vector = obj.m_vector;

    obj.m_size = 0;
    obj.m_capacity = 0;
    obj.m_vector = nullptr;

    return *this;
}

template<class T>
void vector<T>::resize(size_t size){
    if (m_size == size)
        return;
    if (size == 0){
        m_size = 0;
        m_capacity = 0;
        delete[] m_vector;
        m_vector = nullptr;
        return;
    }
    T* tmp = std::move(m_vector);
    m_vector = nullptr;
    m_capacity = size*2;
    m_vector = new T[m_capacity];
    if (m_size < size){
        for(int i = 0; i < m_size;++i){
            m_vector[i] = tmp[i];
        }
        delete[] tmp;
    } 
    else{
        for(int i = 0; i < size;++i){
            m_vector[i] = tmp[i];
        }
        delete[] tmp;
    }
    m_size = size;
}

template<class T>
void vector<T>::resize(size_t size, const T& elem){
    if (m_size == size){
        for(int i = 0; i < size; ++i){
            m_vector[i] = elem;
        }
        return;
    }
    if (size == 0){
        m_size = 0;
        m_capacity = 0;
        delete[] m_vector;
        m_vector = nullptr;
        return;
    }

    delete[] m_vector;

    m_size = size;
    m_capacity = size*2;
    m_vector = new T[m_capacity];
    for(int i = 0; i < size; ++i){
        m_vector[i] = elem;
    }

}

template<class T>
const T& vector<T>::operator[](size_t index) const{
    if (index < 0 || index >= m_size) {
            throw std::out_of_range("Index: " + std::to_string(index) + " out of range");
        }
    return m_vector[index];
}

template<class T>
T& vector<T>::operator[](size_t index){
    if (index < 0 || index >= m_size) {
            throw std::out_of_range("Index: " + std::to_string(index) + " out of range");
        }
    return m_vector[index];
}

template<class T>
void vector<T>::clear(){
    m_size = 0;
    m_capacity = 0;
    delete[] m_vector;
    m_vector = nullptr;
}

template<class T>
void vector<T>::emplace_back(T&& elem){
    if (m_size + 1 <= m_capacity){
        m_vector[m_size] = elem;
        m_size = m_size + 1;
        return;
    }
    T* tmp = std::move(m_vector);
    m_vector = nullptr;
    m_size = m_size + 1;
    m_capacity = m_size*2;
    m_vector = new T[m_capacity];
    for(int i = 0; i < m_size - 1;++i){
        m_vector[i] = tmp[i];
    }
    m_vector[m_size-1] = elem;
    delete[] tmp;
}

template<class T>
void vector<T>::push_back(const T& elem){
    if (m_size + 1 <= m_capacity){
        m_vector[m_size] = elem;
        m_size = m_size + 1;
        return;
    }
    T* tmp = std::move(m_vector);
    m_vector = nullptr;
    m_size = m_size + 1;
    m_capacity = m_size*2;
    m_vector = new T[m_capacity];
    for(int i = 0; i < m_size - 1;++i){
        m_vector[i] = tmp[i];
    }
    m_vector[m_size-1] = elem;
    delete[] tmp;
}

template<class T>
bool vector<T>::empty() const{
    if (m_size == 0)
        return true;
    else
        return false;
};

template<class T>
size_t vector<T>::size() const{
    return m_size;
};

template<class T>
T* vector<T>::begin(){
    return m_vector;
}

template<class T>
T* vector<T>::end(){
    return m_vector + m_size - 1;
}
#endif