#pragma once

#include <iostream>
#include <initializer_list>

namespace container {
    template<typename T>
    class set {
    private:
        struct node {
            T value;
            node* left = nullptr;
            node* right = nullptr;

            node(const T&element);

            void clear_childs();
        };
        node* root_ = nullptr;
        size_t size_;


        node* copy_tree(node* copy_root, node* root=nullptr);

        void current_print(node* current=nullptr) const;


        void copy_set(const set<T>& object);


    public:
        void insert(const T& element);


        void emplace(T&& element) noexcept;

        void print() const;


        set(const set<T> & object);


        set(set <T> &&object) noexcept;

        set(const std::initializer_list<T>& list);

        set() = default;

        size_t size() const;

        bool empty() const;

        const T& top() const;

        const T& buttom() const;

        void clear ();

        set<T>& operator=(const set<T>& object);

        set<T>& operator=(set<T>&& object);

        bool find(const T& element) const;

        ~set();
    };
}


#include "set.tpp"