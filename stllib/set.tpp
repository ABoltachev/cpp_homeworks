#ifndef SET_TPP
#define SET_TPP


template<typename T>
set<T>::Node::Node(const T &value) : value(value), left(nullptr), right(nullptr) {}

template<typename T>
set<T>::Node::Node(T &&value) : value(std::move(value)), left(nullptr), right(nullptr) {}

template<typename T>
set<T>::set() {
    head = nullptr;
    m_size = 0;
}

template<typename T>
set<T>::set(const set<T> &other) : set() {

    for (auto &obj: other) {
        insert(obj);
    }
}

template<typename T>
set<T>::set(set &&other) : set() {

    std::swap(head, other.head);
    std::swap(m_size, other.m_size);

}

template<typename T>
set<T>::set(std::initializer_list<T> &initial_list) :set() {

    for (auto &obj: initial_list) {
        insert(obj);
    }
}

template<typename T>
size_t set<T>::size() const {
    return m_size;
}

template<typename T>
bool set<T>::empty() const {
    return m_size == 0;
}

template<typename T>
const T& set<T>::getMax() const {
    if (head != nullptr) {
        Node* current = head;
        while (current->right != nullptr) {
            current = current->right;
        }
        return current->value;
    }
    throw std::logic_error("Set is empty");
}

template<typename T>
const T& set<T>::getMin() const {
    if (head != nullptr) {
        Node* current = head;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current->value;
    }
    throw std::logic_error("Set is empty");
}

template<typename T>
bool set<T>::find(const T &elem) const {
    Node* current = head;
    while (current) {
        if (elem < current->value) {
            current = current->left;
        }
        else if (elem > current->value) {
            current = current->right;
        }
        else {
            return true;
        }
    }
    return false;
}

template<typename T>
void set<T>::insert(const T &elem) {
    Node* node = new Node(elem);
    if (head == nullptr) {
        head = node;
    }
    else {
        Node* current = head;
        while (true) {
            if (elem == current->value) {
                delete node;
                return;
            }
            else if (elem < current->value) {
                if (current->left == nullptr) {
                    current->left = node;
                    break;
                }
                else {
                    current = current->left;
                }
            }
            else {
                if (current->right == nullptr) {
                    current->right = node;
                    break;
                }
                else {
                    current = current->right;
                }
            }
        }
    }
    m_size++;
}

template<typename T>
void set<T>::emplace(T &&elem) {
    Node* node = new Node(std::move(elem));
    if (head == nullptr) {
        head = node;
    }
    else {
        Node* current = head;
        while (true) {
            if (elem == current->value) {
                delete node;
                return;
            }
            else if (elem < current->value) {
                if (current->left == nullptr) {
                    current->left = node;
                    break;
                }
                else {
                    current = current->left;
                }
            }
            else {
                if (current->right == nullptr) {
                    current->right = node;
                    break;
                }
                else {
                    current = current->right;
                }
            }
        }
    }
    m_size++;
}

template<typename T>
set<T>& set<T>::operator=(const set<T>& arr) {
    if (this != &arr) {
        clear();
        for (auto& val: arr) {
            insert(val);
        }
    }
    return *this;
}

template<typename T>
set<T>& set<T>::operator=(set<T>&& arr) {
    std::swap(head, arr.head);
    std::swap(m_size, arr.m_size);
    return *this;
}

template<typename T>
void set<T>::clear() {
    clearTree(head);
    head = nullptr;
    m_size = 0;
}

template<typename T>
void set<T>::clearTree(set::Node *node) {
    if (node != nullptr) {
        clearTree(node->left);
        clearTree(node->right);
        delete node;
    }
}

template<typename T>
set<T>::~set() {
    clear();
}

#endif
