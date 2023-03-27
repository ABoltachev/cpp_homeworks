#ifndef MY_VECTOR_CPP
#define MY_VECTOR_CPP


namespace MyStdLib {

    template<typename T>
    void copy_vec(MyVector<T>& a, const MyVector<T>& b) {
        a.clear();
        b.values[0];
        for(size_t i = 0; i < b.size(); ++i) {
            a.push_back(b.values[i]);
        }
    }

    template<typename T>
    void MyVector<T>::push_back(const T& val) {
        if (m_size >= m_capacity) {
            m_capacity = m_capacity * 2 + 1;
            values = static_cast<T*>(realloc(values, sizeof(T) * m_capacity));
        }
        values[m_size++] = val;
    } 

    template<typename T>
    void MyVector<T>::emplace_back(T&& val) {
        if (m_size >= m_capacity) {
            m_capacity = m_capacity * 2 + 1;
            values = static_cast<T*>(realloc(values, sizeof(T) * m_capacity));
        }
        values[m_size++] = val;
    } 

    template<typename T>
    MyVector<T>::MyVector() {
        values = nullptr;
        m_size = 0;
        m_capacity = 0;
    }

    template<typename T>
    MyVector<T>::MyVector(size_t size, const T& init_val) : MyVector<T>() {
        for (size_t i = 0; i < size; ++i) {
            this->push_back(init_val);
        }
    }

    template<typename T>
    MyVector<T>::MyVector(const MyVector& vector) {
        m_size = vector.m_size;
        m_capacity = vector.m_capacity;
        values = new T[m_size];
        copy_vec(*this, vector);
    }

    template<typename T>
    MyVector<T>::MyVector(std::initializer_list<T> list) : MyVector() {
        auto it = list.begin();
        for(int i = 0; it != list.end(); ++i, ++it) {
            this->push_back(*it);
        }
    }

    template<typename T>
    MyVector<T>::MyVector(MyVector&& vector) : m_size(vector.m_size), 
        m_capacity(vector.m_capacity), values(vector.values) {
        vector.m_size = 0;
        vector.m_capacity = 0;
        vector.values = nullptr;    
    }

    template<typename T>
    size_t MyVector<T>::size() const { return m_size; };

    template<typename T>
    bool MyVector<T>::empty() const { return m_size == 0; };

    template<typename T>
    void MyVector<T>::clear() { 
        delete[] values;
        values = nullptr; 
        m_size = 0;
        m_capacity = 0;
    };

    template<typename T>
    void MyVector<T>::resize(size_t size, const T& val) {
        this->clear();
        for (int i = 0; i < size; ++i) {
            this->push_back(val);
        }
    }

    template<typename T>
    T& MyVector<T>::operator[](size_t ind) {
        if (ind >= m_size) {
            throw std::out_of_range("out of range");
        }
        return values[ind];
    }


    template<typename T>
    const T& MyVector<T>::operator[](size_t ind) const {
        if (ind >= m_size) {
            throw std::out_of_range("out of range");
        }
        return values[ind];
    }


    template<typename T>
    MyVector<T>& MyVector<T>::operator=(const MyVector<T>& vector) {
        copy_vec(*this, vector);
        return *this;
    }


    template<typename T>
    MyVector<T>& MyVector<T>::operator=(MyVector<T>&& vector) {
        this->clear();
        values = vector.values;
        m_size = vector.m_size;
        m_capacity = vector.m_capacity;
        vector.m_capacity = 0;
        vector.m_size = 0;
        vector.values = nullptr;
        return *this;
    }


    template <typename T>
    std::ostream& operator<<(std::ostream& out, const MyVector<T>& vector) {
        out << "MyVector { ";
        for (int i = 0; i < vector.m_size; ++i) {
            out << vector.values[i];
            if (i + 1 != vector.m_size) {
                out << ", ";
            }
        }
        out << " };";
        return out;
    }
}

#endif 