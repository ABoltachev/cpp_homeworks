#ifndef MY_SET_CPP
#define MY_SET_CPP

namespace MyStdLib {

    template <typename T>
    MySet<T>::MySet() : tree(nullptr), m_size(0) {};

    template <typename T>
    MySet<T>::MySet(const MySet& set) : MySet() {
        copy_trees(*this, set.tree);
    };

    template <typename T>
    MySet<T>::MySet(MySet&& set) 
        : tree(set.tree),
          m_size(set.m_size) {
        set.m_size = 0;
        set.tree = nullptr;
    };

    template <typename T>
    MySet<T>::MySet(std::initializer_list<T> list) {
        auto it = list.begin();
        auto itEnd = list.end();
        for (; it != itEnd; ++it) {
            this->insert(*it);
        }
    };

    template <typename T>
    size_t MySet<T>::size() const { return this->m_size; };

    template <typename T>
    bool MySet<T>::empty() const { return (0 == this->size()); };

    template <typename T>
    void recursive_cleaning(Node<T>* tree) {
        if (tree) {
            if (tree->left) {
                recursive_cleaning(tree->left);
            } else if (tree->right) {
                recursive_cleaning(tree->left);
            } else {
                delete tree;
            }
        }
    }

    template <typename T>
    void MySet<T>::clear() {    
        recursive_cleaning(this->tree);
        this->tree = nullptr;
        this->m_size = 0;
    };

    template <typename T>
    bool MySet<T>::bool_find(const T& value) {
        try {
            this->elem_find(value);
            return true;
        } catch (const std::exception& ex) {
            return false;
        }
    }

    template <typename T>
    T& MySet<T>::bottom() {
        if (this->empty()) {
            throw std::runtime_error("set is empty");
        }

        Node<T>* temp = this->tree;
        while (temp->left) {
            temp = temp->left;
        }

        return temp->val;
    }

    template <typename T>
    T& MySet<T>::top() {
        if (this->empty()) {
            throw std::runtime_error("set is empty");
        }

        Node<T>* temp = this->tree;
        while (temp->right) {
            temp = temp->right;
        }

        return temp->val;
    }

    template <typename T>
    T& MySet<T>::elem_find(const T& value) {
        if (this->empty()) {
            throw std::runtime_error("there is no such element");
        }

        Node<T>* temp = this->tree;
        while (temp) {
            if (temp->val > value) {
                if (temp->left) {
                    temp = temp->left;
                } else {
                    break;
                }
            } else if (temp->val < value) {
                if (temp->right) {
                    temp = temp->right;
                } else {
                    break;
                }
            } else {
                return temp->val;
            }
        }

        throw std::runtime_error("there is no such element");
    }

    template <typename T>
    void MySet<T>::emplace(T&& value) {
        if (!this->tree) {
            this->tree = new Node<T>;
            this->tree->val = value;
            this->m_size++;
            return;
        } // Нет элементов

        Node<T>* temp = this->tree;
        while(temp) {
            if (temp->left && temp->val > value) {
                temp = temp->left;
            } else if (temp->right && temp->val < value) {
                temp = temp->right;
            } else if (temp->val == value) {
                return;
            } else {
                break;
            }
        } // Ищем элемент

        if (temp->val > value) {
            temp->left = new Node<T>;
            temp->left->val = value;
        } else {
            temp->right = new Node<T>;
            temp->right->val = value;
        } // Вставляем в нужную позицию
        this->m_size++;
    }

    template <typename T>
    void MySet<T>::insert(const T& value) {
        if (!this->tree) {
            this->tree = new Node<T>;
            this->tree->val = value;
            this->m_size++;
            return;
        } // Нет элементов

        Node<T>* temp = this->tree;
        while(temp) {
            if (temp->left && temp->val > value) {
                temp = temp->left;
            } else if (temp->right && temp->val < value) {
                temp = temp->right;
            } else if (temp->val == value) {
                return;
            } else {
                break;
            }
        } // Ищем элемент

        if (temp->val > value) {
            temp->left = new Node<T>;
            temp->left->val = value;
        } else {
            temp->right = new Node<T>;
            temp->right->val = value;
        } // Вставляем в нужную позицию
        this->m_size++;
    }

    template <typename T>
    void copy_trees(MySet<T>& target, const Node<T>* source) {
        if (source) {
            target.insert(source->val);
            copy_trees(target, source->left);
            copy_trees(target, source->right);
        }
    }

    template <typename T> 
    MySet<T>& MySet<T>::operator=(const MySet<T>& set) {
        this->clear();
        copy_trees(*this, set.tree);
        return *this;
    }

    template <typename T>
    MySet<T>& MySet<T>::operator=(MySet<T>&& set) {
        this->clear();
        this->m_size = set.m_size;
        this->tree = set.tree;
        set.m_size = 0;
        set.tree = nullptr;
        return *this;
    }

    template <typename T>
    std::ostream& operator<<(std::ostream& out, const MySet<T>& set) {
        out << "MySet { ";
        bool comma_flag = true;
        display_in(out, set.tree, comma_flag);
        out << " };";
        return out;
    }

    template <typename T>
    void display_in(std::ostream& out, const Node<T>* node, bool& comma_flag) {
        if (node) {
            display_in(out, node->left, comma_flag);
            if (comma_flag) {
                comma_flag = false;
            } else {
                out << ", ";
            }
            out << node->val;
            display_in(out, node->right, comma_flag);
        }
    }

}

#endif