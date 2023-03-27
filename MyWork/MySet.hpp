#ifndef MY_SET_HPP
#define MY_SET_HPP

#include <iostream>

namespace MyStdLib {

    template <typename T>
    struct Node {
        Node<T>* left = nullptr;
        Node<T>* right = nullptr;;
        T val = 0;
    };

    template <typename T>
    class MySet;

    template <typename T>
    std::ostream& operator<<(std::ostream& out, const MySet<T>& other);

    template <typename T>
    class MySet {
    private:
        Node<T>* tree;
        
        size_t m_size;
    
    public:
        MySet(); // OK

        MySet(const MySet<T>& set);

        MySet(MySet<T>&& set);

        MySet(std::initializer_list<T> list); // OK

        size_t size() const;

        bool empty() const;

        T& top();

        T& bottom();

        // Не ставлю const. Так как под капотом вызываю elem_find
        // Можно было бы этого избежать, но пришлось бы копипастить
        // Решил оставить так
        bool bool_find(const T& value); 

        T& elem_find(const T& value);

        void insert(const T& value);

        void emplace(T&& value);

        void clear();

        MySet<T>& operator=(const MySet<T>& set);

        MySet<T>& operator=(MySet<T>&& set);

        friend std::ostream& operator<< <>(std::ostream& out, const MySet<T>& other); // OK


    };

}

#include "MySet.tpp"

#endif 