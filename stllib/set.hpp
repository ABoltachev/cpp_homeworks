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

#include <initializer_list>
#include <stdexcept>

namespace UberClasses {
    template<typename T>
    class Set {
        struct Node {
            T value;
            Node* right = nullptr;
            Node* left = nullptr;

            Node(const T& new_value): value(new_value), left(nullptr), right(nullptr) {}
            Node(T&& new_value): value(std::move(new_value)), left(nullptr), right(nullptr) {}
            Node(const Node* &new_node);
            ~Node() {
                delete left;
                delete right;
                right = left = nullptr;
            }

        };
        Node* m_root = nullptr;
        size_t m_size = 0;

    public:
        Set() = default;
        Set(const Set<T>& new_set): m_root(new_set.m_root), m_size(new_set.m_size) {}
        Set(Set<T>&& new_set): m_root(new_set.m_root), size(new_set.m_size) {
            new_set.m_root = nullptr;
            new_set.m_size = 0;
        }
        Set(std::initializer_list<T>& list):

        bool empty() { return size == 0; }
        size_t size() { return size; }
        bool find(const T& elem);
        T& top();
        void insert(const T& elem);
        void emplace(T&& elem);
        void clear() {
            m_size = 0;
            delete m_root;
            m_root = nullptr;
        }

        Set& operator= (const Set<T>& another);
        Set& operator= (Set<T>&& another);

        Node* copyTree();
    };
}

#include "set.tpp"