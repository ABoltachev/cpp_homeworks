/*
* set и методы для него (для реализации использовать простое бинарное дерево, соответственно использовать можно только с данными, которые имеют оператор <):
    size (возвращает размер)
    empty (возвращает true если пустой)
    top (возвращает большее значение)
    find (поиск элемента, true - нашли, false - нет)
    insert (вставка (копирование))
    emplace (вставка (перемещение))
    clear (очистка
    присваивание (копирование и перемещением)
    конструкторы (конструктор без аргументов; копирования; перемещения; конструктор с std::inizialized_list)
*/

#ifndef SETLIB
#define SETLIB

#include <iostream>

template<typename T, class Compare = std::less<T> >
class Set{

    struct Node
    {
        T value;
        Node* left = nullptr;
        Node* right = nullptr;
    };

    size_t sSize = 0;
    Node* head = nullptr;
    typename Set<T>::Node* copy(typename Set<T>::Node* pNode);
    void deleteNode(typename Set<T>::Node* pNode);

    public: 

    Set() = default;
    Set(const Set<T>& other);
    Set(Set<T>&& other);
    Set(const std::initializer_list<T>& init_list);

    Set& operator= (const Set<T>& other);
    Set& operator= (Set<T>&& other);

    size_t size();
    T top();
    bool empty();
    void clear();    
    
    bool find(T element);   
    
    void insert(const T& element);
    void emplace(T&& element);
};

#include "set.tpp"
#endif
