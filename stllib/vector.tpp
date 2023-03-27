#ifndef VECTOR_TPP
#define VECTOR_TPP


template<class Data>
Vector<Data>::Vector()
{
	m_vector = new Data[1];
	m_size = 1;
	m_curr= 0;
}

template<class Data>
Vector<Data>::Vector(size_t size, const Data& sym): m_vector(new Data[size]), m_size(size), m_curr=0{
     for (size_t i = 0; i < m_size; ++i) {
        m_vector[i] = sym;
    } 
}

template<class Data>
Vector<Data>::Vector(const std::initializer_list<Data>& init_list): Vector(init_list.size()) {
	auto it=init_list.begin();
	for (size_t i=0; i<m_size; i++){
		m_vector[i]=*(it+i)	;
        m_curr++;
	}
}

template<class Data>
Vector<Data>::Vector(const Vector<Data>& obj): m_vector(obj.m_vector), m_size(obj.m_size), m_current(obj.m_current){}

template <typename Data>
Vector<Data>::Vector(Vector<Data> &&obj) : m_vector(obj.m_vector), m_size(obj.m_size), m_current(obj.m_current) {
    obj.m_vector = nullptr;
    obj.m_size = 0;
    obj.m_curr=0;
}

template <class Data>
size_t Vector<Data>::size() const {
    return m_size;
}

template <class Data>
bool Vector<Data>:: empty() const {
    return m_vector == nullptr;
}

template <class Data>
void Vector<Data>::check(size_t idx) const {
    if (idx >= m_size) {
        throw std::out_of_range("idx incorrect");
    }
    if (idx <0) {
        throw std::out_of_range("idx incorrect");
    }
}

template <class Data>
Data& Vector<Data>::operator[](size_t idx) {
    check(idx);
    return m_vector[idx];
}

template <class Data>
const Data& Vector<Data>::operator[](size_t idx) const {
    check(idx);
    return m_vector[idx];
}

template<class Data>
void vector<Data>::resize(size_t &new_size, const Data &sym) {
    if (new_size > m_size) {
        Data* new_vector = new Data[new_size];
        for (size_t i = 0; i < m_size; ++i) {
            new_vector[i] = m_vector[i];
        }
        delete[] m_vector;
        m_vector = new_vector;
    }
    for (size_t i = m_size; i < new_size; ++i) {
        m_vector[i] = sym;
    }
    m_size = new_size;
}

template<class Data>
void vector<Data>::push_back(const Data& sym) {
    if (m_size == m_curr) {
        resize(m_size * 2);
    }
    m_vector[m_curr++] = sym;
}

template<class Data>
void vector<Data>::emplace_back(T&& sym) {
    if (m_size == m_curr) {
        resize(m_size * 2);
    }
    m_vector[m_curr++] = sym;
}

template<class Data>
void vector<T>::clear() {
    delete[] m_vector;
    m_vector = new Data[m_size];
    m_curr = 0;
}
template <class Data>
Vector<Data>& Vector<Data>::operator=(Vector<Data> &&obj) {
    if (&obj != this) {
        m_vector = obj.m_vector;
        m_size = obj.m_size;
        m_curr= obj.curr;
    }
    return *this;
}
template <class Data>
Vector<Data>& Vector<Data>::operator=(const Vector<Data> &obj) {
    if (&obj != this) {
        m_vector = obj.m_vector;
        m_size = obj.m_size;
        m_curr= obj.curr;
        obj.m_vector = nullptr;
        obj.m_size = 0;
        obj.curr=0;
    }
    return *this;
}

#endif