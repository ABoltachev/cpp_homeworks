#ifndef VECTOR_H
#define VECTOR_H

#include <cstdio>
#include <initializer_list>
#include <iostream>

template<typename Type>
class vector{
    typedef Type* iterator;
    typedef const Type* const_iterator;
    std::size_t cur_size{};
    std::size_t reserve_size{};
    Type* body;
public:
    vector() = default;
    explicit vector(std::size_t iniz_size, const Type& val = 0) {
        cur_size = iniz_size;
        reserve_size = 2 * iniz_size + 2;
        body = new Type[reserve_size];
        for(int i = 0; i < cur_size; ++i) body[i] = val;
    }
    vector(std::initializer_list<Type> list) : vector(static_cast<Type>(list.size()))
    {
        cur_size = list.size();
        reserve_size = 2*cur_size + 2;
        int i = 0;
        for(auto x : list) {
            body[i] = x;
            ++i;
        }
    }
    vector(const vector &obj) {
        std::cout << "\nВектор скопирован.\n" << std::endl;
        cur_size = obj.cur_size;
        reserve_size = obj.reserve_size;
        if (cur_size == 0) {body = nullptr; return; }
        body = new Type[reserve_size];
        std::copy(obj.body, obj.body + cur_size, body);
        //std::memcpy(body, obj.body, cur_size * sizeof(int));
    }
    vector(vector&& obj)  noexcept :  cur_size(obj.cur_size),
                                      reserve_size(obj.reserve_size), body(std::move(obj.body)) {
        obj.cur_size = 0;
        obj.reserve_size = 0;
        obj.body = nullptr;
        std::cout << "\nВектор перемещён.\n";
    }

    iterator begin() { return iterator(std::__addressof(body[0])); }
    const_iterator begin() const { return const_iterator(std::__addressof(body[0])); }
    iterator end() { return iterator(std::__addressof(body[cur_size])); }
    const_iterator end() const { return const_iterator(std::__addressof(body[cur_size])); }


    vector &operator=(const vector& obj) {
        if (this == &obj) return *this;
        delete body;
        cur_size = obj.cur_size;
        body = obj.body;
        return *this;
    }
    vector &operator=(vector&& obj)  noexcept {
        if (this == &obj) return *this;
        if (body) delete body;
        cur_size = obj.size();
        body = obj.body;
        obj.cur_size = 0;
        obj.body = nullptr;
        return *this;
    }
    Type& operator[](unsigned index) {
        if (index >= 0 && index < reserve_size) {
            return body[index];
        }
        else throw std::invalid_argument("\n!Индекс вне пределов вектора!\n");
    }
    std::size_t size() const {
        return cur_size;
    }
    std::size_t size_reserve() const {
        return reserve_size;
    }
    std::size_t empty() const {
        return cur_size > 0;
    }

    void resize(std::size_t new_size, const Type& def = 0) {
        if(new_size < reserve_size) {
            cur_size = new_size;
            return;
        }
        else {
            reserve_size = 2*new_size + 2;
            Type* new_body = new Type[reserve_size];
            for(int j = 0; j < cur_size; ++j) new_body[j] = body[j];
            //std::copy(body, body+cur_size, new_body);
            body = new_body;
            for(int i = cur_size; i < reserve_size; ++i) body[i] = def;
            cur_size = new_size;
        }
    }
    void clear(){
        for(int i = 0; i < cur_size; ++i) body[i] = 0;
        delete body;
        cur_size = 0;
        reserve_size = 0;
    }
    void push_back(const Type& new_element){emplace_back(new_element);}
    template<typename ...Args>
    void emplace_back(const Args&... args) {
        if(cur_size == reserve_size) resize(cur_size+1);
        else ++cur_size;
        new (body+cur_size-1) Type(args...);
    }
};



#endif
