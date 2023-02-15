#ifndef COLLECTIONS_NODE_HPP
#define COLLECTIONS_NODE_HPP

#include <cstdio>

namespace SetLibNode {
    template <class T>
    struct Node {
        T data;
        Node* left;
        Node* right;
        explicit Node(T _data = T{}*0, Node* _left=nullptr, Node* _right=nullptr)
                : data(_data), left(_left), right(_right) {}

    public:
        size_t containsNode(Node* root, const T& _data);
        Node* insert(Node* root, const T& _data);
        ~Node();
    };
}

#include "Node.tpp"
#endif // COLLECTIONS_NODE_HPP