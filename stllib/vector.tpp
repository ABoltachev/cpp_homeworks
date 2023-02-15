#ifndef VECTOR_TPP
#define VECTOR_TPP

namespace lib {
    template <typename T>
    Vector<T>::Vector() : vect(nullptr), m_size(0), max_size(0) {}

    template <typename T>
    Vector<T>::Vector(size_t size, T value)
    {
        m_size = size;
        max_size = 2 * size;
        vect = new T[m_size];

        for (int i = 0; i < m_size; i++) {
            vect[i] = value;
        }
    }

    template <typename T>
    Vector<T>::Vector(const Vector<T>& vector) : m_size(vector.m_size), max_size(2 * vector.m_size)
    {
        delete[] vect;
        vect = new T[m_size];

        for (int i = 0; i < m_size; ++i)
            vect[i] = vector.vect[i];
    }

    template <typename T>
    Vector<T>::Vector(Vector<T>&& vector)
    {
        delete[] vect;
        m_size = vector.m_size;
        max_size = 2 * m_size;
        vect = vector.vect;
        vector.vect = nullptr;
        vector.m_size = 0;
        vector.max_size = 0;
    }

    template <typename T>
    Vector<T>::Vector(std::initializer_list<T> list) : Vector()
    {
        m_size = list.size();
        max_size = m_size * 2;
        vect = new T[max_size];
        size_t i = 0;
        for (auto x : list)
        {
            vect[i++] = x;
        }
    }

    template <typename T>
    Vector<T>& Vector<T>::operator=(const Vector<T>& vector)
    {
        if (&vector == this)
            return *this;

        delete[] vect;

        m_size = vector.m_size;
        max_size = m_size * 2;
        vect = new T[m_size];

        for (int i = 0; i < m_size; ++i)
            vect[i] = vector.vect[i];

        return *this;
    }

    template <typename T>
    Vector<T>& Vector<T>::operator=(Vector&& vector) 
    {
        if (&vector == this)
            return *this;

        delete[] vect;

        m_size = vector.m_size;
        max_size = m_size * 2;
        vect = vector.vect;

        vector.vect = nullptr;
        vector.m_size = 0;
        vector.max_size = 0;

        return *this;
    }

    template <typename T>
    T& Vector<T>::operator[](size_t ind)
    {
        if (ind < 0 || ind >= m_size) {
            throw std::out_of_range("Index is out of range vector");
        }
        return vect[ind];
    }

    template <typename T>
    const T& Vector<T>::operator[](size_t ind) const
    {
        if (ind < 0 || ind >= m_size) {
            throw std::out_of_range("Index is out of range vector");
        }
        return vect[ind];
    }

    template<typename T>
    void Vector<T>::push_back(const T& value)
    {
        if (m_size == max_size)
        {
            max_size = 2 * m_size;
            T* temp = new T[max_size];
            for (size_t i = 0; i < m_size; i++)
            {
                temp[i] = vect[i];
            }
            delete[] vect;
            vect = temp;
            delete[] temp;
        }
        vect[m_size++] = value;
    }

    template<typename T>
    void Vector<T>::emplace_back(T&& value)
    {
        if (m_size == max_size)
        {
            max_size = 2 * m_size;
            T* temp = new T[max_size];
            for (size_t i = 0; i < m_size; i++)
            {
                temp[i] = vect[i];
            }
            delete[] vect;
            vect = temp;
            delete[] temp;
        }
        vect[m_size++] = value;
    }

    template <typename T>
    void Vector<T>::clear() 
    {
        m_size = 0;
    }

    template <typename T>
    void Vector<T>::resize(size_t size, T value)
    {
        if (size <= 0)
            throw std::logic_error("Vector can't have a negative or zero size");
        delete[] vect;
        
        m_size = size;
        max_size = size * 2;
        vect = new T[max_size];
        
        for (size_t i = 0; i < m_size; i++)
        {
            vect[i] = value;
        }
    }


    template <typename T>
    size_t Vector<T>::size() const
    {
        return m_size;
    }

    template <typename T>
    bool Vector<T>::empty() const
    {
        return m_size == 0;
    }

    template <typename T>
    Vector<T>::~Vector() {
        delete[] vect;
    }
}

#endif