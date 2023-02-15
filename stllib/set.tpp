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

#include "set.hpp"

template<typename T, class Compare>
typename Set<T>::Node* Set<T, Compare>::copy(typename Set<T>::Node* pNode){
    Node* result = nullptr;
    if (pNode) {
        result->value = pNode->value;
        result->left = copy(pNode->left);
        result->right = copy(pNode->right);
    }
    return result;
}

template<typename T, class Compare>
Set<T, Compare>::Set(const Set<T>& other)
{
    head = copy(other.head);
    sSize = other.sSize;
}

template<typename T, class Compare>
Set<T, Compare>::Set(Set<T>&& other): head(other.head), sSize(other.sSize)
{
    other.head = nullptr;
    other.sSize = 0;
}


template<typename T, class Compare>
Set<T, Compare>::Set(const std::initializer_list<T>& init_list)
{
    sSize = init_list.size();
    int i = 0;
    for (const T &element: init_list) {
        insert(element);
    }
}

template<typename T, class Compare>
Set<T, Compare>& Set<T, Compare>::operator= (const Set<T>& other)
{
    if (this != &other) {
        clear();
        head = copy(other.head);
        sSize = other.sSize;
    }
    return *this;
}

template<typename T, class Compare>
Set<T, Compare>& Set<T, Compare>::operator=(Set<T>&& other)
{
    std::swap(head, other.head);
    std::swap(sSize, other.sSize);
    other.head = nullptr;
    other.sSize = 0;
}

template<typename T, class Compare>
size_t Set<T,Compare>::size()
{
    return sSize;
}

template<class T, class Compare>
T Set<T, Compare>::top()
{
    Node* check = head;
    while(head->right)
    {
        check = head->right;
    }
    return head->value;
}

template<class T, class Compare>
void Set<T, Compare>::deleteNode(typename Set<T>::Node* pNode)
{
    if (pNode != nullptr) {
        deleteNode(pNode->left);
        deleteNode(pNode->right);
        delete pNode;
    }
}

template<class T, class Compare>
void Set<T, Compare>::clear()
{
    deleteNode(head);
    head = nullptr;
    sSize = 0;
}

template<class T, class Compare>
bool Set<T, Compare>::find(T element)
{
    Node* check = head;
    while (check) {
        if (Compare(element, check->value))
            check = check->left;
        else if (Compare(check->value, element))
            check = check->right;
        else
            return true;
    }
    return false;
}

template<class T, class Compare>
void Set<T, Compare>::insert(const T& element)
{
    if (!(this.find(element))){
        if (head == nullptr){
            head = new Node(element);
            return;
        }
        Node* check = head;
        while (check){
            if (Compare(element, check->value)){
                if (check->left){
                    check = check->left;
                }
                else{
                    check->left = new Node(element);
                }
            }
            else {
                if (check->right){
                    check = check->right;
                }
                else{
                    check->right = new Node(element);
                }
            }
        }
        
    }

    sSize++;
}

template<class T, class Compare>
void Set<T, Compare>::emplace(T&& element)
{
    const T temp = std::move(element);
    this->insert(temp);
}

template<class T, class Compare>
bool Set<T, Compare>::empty()
{
    return (sSize == 0);
}
