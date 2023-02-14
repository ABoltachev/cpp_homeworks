#ifndef ARRAY_H
#define ARRAY_H

#include <cstdio>
#include <initializer_list>
#include <atomic>
#include <algorithm>

template<typename Type, std::size_t initializing_size>
struct array {
    typedef Type value_type;
    typedef value_type& reference;
    typedef const value_type &const_reference;
    typedef value_type* iterator;
    typedef const value_type *const_iterator;
    typedef std::size_t size_type;

    value_type array_body[initializing_size ? initializing_size : 1];

    array() = default;
    explicit array(std::initializer_list<Type> list) {
        size_type i = 0;
        for(auto x : list) array_body[i++] = x;
    }
    array(const array<Type,initializing_size>& copied) {
        array_body = new Type[initializing_size];
        std::copy(copied.array_body, copied.array_body+initializing_size, array_body);
    }

    iterator begin() { return iterator(std::__addressof(array_body[0])); }
    const_iterator begin() const { return const_iterator(std::__addressof(array_body[0])); }
    iterator end() { return iterator(std::__addressof(array_body[initializing_size])); }
    const_iterator end() const { return const_iterator(std::__addressof(array_body[initializing_size])); }
    const_iterator cbegin() const { return const_iterator(std::__addressof(array_body[0])); }
    const_iterator cend() const { return const_iterator(std::__addressof(array_body[initializing_size])); }

    constexpr size_type size() const { return initializing_size; }
    constexpr size_type max_size() const { return initializing_size; }
    constexpr bool empty() const { return size() == 0; }

    reference operator[](size_type index) { return array_body[index]; }
    const_reference operator[](size_type index) const { return array_body[index]; }

    array &operator=(const array& obj) {
        if (this == &obj) return *this;
        if(this->size() == obj.size()) {
            std::copy(obj.array_body, obj.array_body+size(), array_body);
        }
        return *this;
    }
};



#endif
