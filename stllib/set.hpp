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

#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include <stdexcept>

namespace stl
{

template <typename T>
class Set
{
   private:
    // template <typename V>
    struct Node {
        T data;
        Node* left = nullptr;
        Node* right = nullptr;
    };
    Node* m_root;
    size_t m_size;

    void implCopy(Node*& root, Node* copyNode);

    bool implFind(Node* root, const T& value) const;
    T& implFindValue(Node* root, const T& value) const;

    void implInsert(Node*& root, const T& value);
    void implEmplace(Node*& root, T&& value);

    void implClear(Node*& root);

   public:
    Set();
    Set(std::initializer_list<T> list);
    Set(const Set& set);
    Set(Set&& set);

    Set& operator=(const Set& set);
    Set& operator=(Set&& set);

    size_t size() const;
    bool empty() const;

    T& top() const;
    T& min() const;
    bool find(const T& value) const;
    T& findValue(const T& value) const;

    void insert(const T& value);
    void emplace(T&& value);

    void clear();
};

}  // namespace stl

#include "set.tpp"
#endif