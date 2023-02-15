#ifndef SET_HPP
#define SET_TPP
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
#include <iterator>
#include <utility>
#include <initializer_list>

namespace hw
{

    template<typename T>
    struct less
    {
        bool operator()(const T& a, const T& b) const {
            bool res = a < b;
            return res; }
    };

    template<typename T, typename Comp = std::less<T>>
    class set
    {
    private:
        struct node
        {
            node *left{nullptr},*right{nullptr},*parent{nullptr};
            T value;
            node(const T& value) : value(value) {}
            node(T&& value) : value(value) {}
            ~node()
            {
                if(left)
                    delete left;
                if(right)
                    delete right;
            }
        };
        class iterator : public std::iterator<std::bidirectional_iterator_tag,T,long,const T*,const T&>
        {
        private:
            const node* root;
        public:
            iterator() = delete;
            explicit iterator(const node* root);
            iterator& operator++();
            iterator operator++(int);
            bool operator==(const iterator& other);
            bool operator!=(const iterator& other);
            T operator*() const;

            friend set<T,Comp>;
        };
        node* root{nullptr};
        std::size_t __size{0};

        iterator successor(const node* root) const;
    public:
        set() = default;
        set(std::initializer_list<T> list);
        set(const set<T,Comp>&);
        set(set<T,Comp>&&);

        iterator insert(const T& value);
        iterator emplace(T&& value);
        void clear();

        std::size_t size() const;
        bool empty() const;
        T top() const;
        iterator find(const T& value) const;

        iterator begin() const;
        iterator end() const;
        
    };
    template<typename T, typename Comp>
    set<T,Comp>::iterator::iterator(const set<T,Comp>::node* root) : root(root) {}
    
    template<typename T, typename Comp>
    typename set<T,Comp>::iterator& set<T,Comp>::iterator::operator++()
    {
        if(this->root->right)
        {
            this->root = this->root->right;
            while(this->root->left)
                this->root = this->root->left;
        }
        else if(this->root->parent and this->root == this->root->parent->right)
            this->root = nullptr;
        else if(this->root->parent)
        {
            while(this->root == this->root->parent->right)
            {
                if(not this->root->parent)
                    this->root = nullptr;
                this->root = this->root->parent;
            }
            this->root = this->root->parent;
        }

        
        return *this;
    }

    template<typename T, typename Comp>
    typename set<T,Comp>::iterator set<T,Comp>::iterator::operator++(int)
    {
        auto temp = *this;
        ++(*this);

        return temp;
    }

    template<typename T, typename Comp>
    bool set<T,Comp>::iterator::operator==(const set<T,Comp>::iterator& other) { return this->root == other.root; }

    template<typename T, typename Comp>
    bool set<T,Comp>::iterator::operator!=(const set<T,Comp>::iterator& other) { return this->root != other.root; }

    template<typename T, typename Comp>
    T set<T,Comp>::iterator::operator*() const { return this->root->value; }


    template<typename T, typename Comp>
    set<T,Comp>::set(std::initializer_list<T> list)
    {
        for(const T& el : list)
            this->insert(el);
    }

    template<typename T, typename Comp>
    set<T,Comp>::set(const set<T,Comp>& other)
    {
        this->root = new node;
        *this->root = *other.root;
        this->__size = other.__size;
    }

    template<typename T, typename Comp>
    set<T,Comp>::set(set<T,Comp>&& other)
    {
        *this = other;
        other.root = nullptr;
    }

    template<typename T, typename Comp>
    typename set<T,Comp>::iterator set<T,Comp>::insert(const T& value)
    {
        if(this->empty())
        {
            ++this->__size;
            this->root = new node(value);
            return iterator(this->root);
        }
        ++this->__size;
        node* current;
        node* next = this->root;
        Comp compare;
        while(next)
        {
            current = next;
            next = bool(compare(value,current->value)) ? current->left : current->right;
        }
        bool c = bool(compare(value,current->value));
        if(not compare(value,current->value))
        {
            current->right = new node(value);
            current->right->parent = current;
            return iterator(current->right);
        }
        else
        {
            current->left = new node(value);
            current->left->parent = current;
            return iterator(current->left);
        }
    }

    template<typename T, typename Comp>
    typename set<T,Comp>::iterator set<T,Comp>::emplace(T&& value)
    {
        if(this->empty())
        {
            ++this->__size;
            this->root = new node(value);
            return iterator(this->root);
        }
        ++this->__size;
        node* current;
        node* next = this->root;
        while(next)
        {
            current = next;
            next = Comp()(value,current->value) ? current->left : current->right;
        }
        if(not Comp()(value,current->value))
        {
            current->right = new node(value);
            current->right->parent = current;
            return iterator(current->right);
        }
        else
        {
            current->left = new node(value);
            current->left->parent = current;
            return iterator(current->left);
        }
    }

    template<typename T, typename Comp>
    void set<T,Comp>::clear() { delete this->root; this->__size = 0; }

    template<typename T, typename Comp>
    typename set<T,Comp>::iterator set<T,Comp>::find(const T& value) const
    {
        node* current = this->root;
        node* next = this->root;
        while(Comp()(value,current->value) or Comp()(current->value,value))
        {
            if(not next)
                return iterator(nullptr);
            current = next;
            next = Comp()(value,current->value) ? current->left : current->right;
        }
        return iterator(current);
    }

    template<typename T, typename Comp>
    typename set<T,Comp>::iterator set<T,Comp>::successor(const node* root) const
    {
        const node* current = root;
        while(current->left)
            current = current->left;
        
        return iterator(current);
    }

    template<typename T, typename Comp>
    T set<T,Comp>::top() const
    {
        return this->successor(this->root).root->value;
    }

    template<typename T, typename Comp>
    std::size_t set<T,Comp>::size() const { return this->__size; }

    template<typename T, typename Comp>
    bool set<T,Comp>::empty() const { return not this->__size; }

    template<typename T, typename Comp>
    typename set<T,Comp>::iterator set<T,Comp>::begin() const { return this->empty() ? iterator(nullptr) : this->successor(this->root); }

    template<typename T, typename Comp>
    typename set<T,Comp>::iterator set<T,Comp>::end() const { return iterator(nullptr); }
}

#endif