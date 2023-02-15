#pragma once

template <typename T>
container::set<T>::node::node(const T&element) {
    value = element;
}


template <typename T>
void container::set<T>::node::clear_childs() {
    if (left) {
        left->clear_childs();
        delete left;
    }
    if (right) {
        right->clear_childs();
        delete right;
    }
}


template <typename T>
typename container::set<T>::node* container::set<T>::copy_tree(node* copy_root, node* root) {
    if (root == nullptr) {
        root = new node(copy_root->value);
    }
    if (copy_root->left) {
        root->left = new node(copy_root->left->value);
        copy_tree(copy_root->left, root->left);
    }
    if (copy_root->right) {
        root->right = new node(copy_root->right->value);
        copy_tree(copy_root->right, root->right);
    }
    return root;
}


template <typename T>
void container::set<T>::current_print(node* current) const {

    if (current == nullptr) {
        current = root_;
    }
    if (current->left) {
        current_print(current->left);
    }
    if (current->right) {
        current_print(current->right);
    }
    std::cout << current->value << " ";
}


template <typename T>
void container::set<T>::copy_set(const set<T>& object) {
    size_ = object.size();
    root_ = copy_tree(object.root_);
}


template <typename T>
void container::set<T>::insert(const T& element) {
    size_++;
    if (root_ == nullptr) {
        root_ = new node(element);
        return;
    }
    node* temp = root_;
    while (true) {
        if (element > temp->value) {
            if (temp->right) {
                temp = temp->right;
            }
            else {
                temp->right = new node(element);
                break;
            }
        }
        else if (element < temp->value) {
            if (temp->left) {
                temp = temp->left;
            }
            else {
                temp->left= new node(element);
                break;
            }
        }
        else {
            size_--;
            break;
        }
    }
}


template <typename T>
void container::set<T>::emplace(T&& element) noexcept {
    insert(element);
}


template <typename T>
void container::set<T>::print() const {

    current_print();
}


template <typename T>
container::set<T>::set(const set<T> & object) {
    copy_set(object);

}


template <typename T>
container::set<T>::set(set <T> &&object) noexcept{
    size_ = object.size_;
    root_ = object.root_;
    object.root = nullptr;
    object.size_ = 0;
}


template <typename T>
container::set<T>::set(const std::initializer_list<T>& list) {
    size_ = list.size();
    for (auto element: list) {
        insert(element);
    }
}


template <typename T>
size_t container::set<T>::size() const {
    return size_;
}


template <typename T>
bool container::set<T>::empty() const {
    return (size_ == 0);
}


template <typename T>
const T& container::set<T>::top() const {
    node* temp = root_;
    if (size_ == 0) {
        throw "Set is empty";
    }
    while (temp->right) {
        temp = temp->right;
    }
    return temp->value;
}

template <typename T>
const T& container::set<T>::buttom() const {
    node* temp = root_;
    if (size_ == 0) {
        throw "Set is empty";
    }
    while (temp->left) {
        temp = temp->left;
    }
    return temp->value;
}


template <typename T>
void container::set<T>::clear () {
    root_->clear_childs();
    delete root_;
    root_ = nullptr;
    size_ = 0;
}


template <typename T>
container::set<T>& container::set<T>::operator=(const set<T>& object) {
    clear();
    copy_set(object);
    return *this;
}


template <typename T>
container::set<T>& container::set<T>::operator=(set<T>&& object) {
    clear();
    size_ = object.size_;
    root_ = object.root_;
    object.root = nullptr;
    object._size = 0;
    return *this;
}


template <typename T>
bool container::set<T>::find(const T& element) const {
    node* temp = root_;
    while (temp) {
        if (temp->value == element) {
            return true;
        }
        if (temp->value < element) {
            temp = temp->right;
        }
        else {
            temp = temp->left;
        }
    }
    return false;
}


template <typename T>
container::set<T>::~set() {
    clear();
}
