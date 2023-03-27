#ifndef COLLECTIONS_STATICARRAY_TPP
#define COLLECTIONS_STATICARRAY_TPP

namespace StaticArrayLib {

    template<class T, size_t size>
    [[maybe_unused]] Array<T, size>::Array(const std::initializer_list<T> &init_list)
    : m_size(init_list.size())
    {
        m_arr[init_list.size()];
        auto it = init_list.begin();
        for (size_t i = 0; i < m_size; ++i)
            m_arr[i] = *(it + i);
    }

    template<class T, size_t size>
    [[maybe_unused]] int Array<T, size>::size() const {
        return m_size;
    }

    template<class T, size_t size>
    [[maybe_unused]] bool Array<T, size>::empty() const {
        return m_size == 0;
    }

    template<class T, size_t size>
    T &Array<T, size>::operator[](size_t id) {
        assert(id < m_size);
        return m_arr[id];
    }

    template<class T, size_t size>
    const T &Array<T, size>::operator[](size_t id) const {
        assert(id < m_size);
        return m_arr[id];
    }
}
#endif // COLLECTIONS_STATICARRAY_TPP