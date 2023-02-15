#ifndef COLLECTIONS_NODE_TPP
#define COLLECTIONS_NODE_TPP

namespace SetLibNode {
    template<class T>
    size_t Node<T>::containsNode(Node *root, const T &_data) {
        if (root == nullptr)
            return 0;

        size_t x = root->data == _data ? 1 : 0;
        return x | containsNode(root->left, _data) | containsNode(root->right, _data);
    }

    template<class T>
    Node<T> *Node<T>::insert(Node *root, const T &_data) {
        if (root == nullptr) {
            auto *temp_node = new Node<T>;
            temp_node->data = _data;
            temp_node->left = temp_node->right = nullptr;
            return temp_node;
        }

        if (_data < root->data) {
            root->left = insert(root->left, _data);
            return root;
        } else if (_data > root->data) {
            root->right = insert(root->right, _data);
            return root;
        } else
            return root;
    }

    template<class T>
    Node<T>::~Node() {
        delete left;
        left = nullptr;
        delete right;
        right = nullptr;
    }
}

#endif // COLLECTIONS_NODE_TPP