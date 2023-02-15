#include <iostream>
#include <initializer_list>

template <typename T>
class Set {
private:
    struct Node {
        T data;
        Node *left;
        Node *right;

        Node(const T &value) : data(value), left(nullptr), right(nullptr) {}
        Node(T &&value) : data(std::move(value)), left(nullptr), right(nullptr) {}
    };

    Node *root;
    std::size_t size_;

public:
    Set();
    Set(const Set &other);
    Set(Set &&other) noexcept;
    Set(std::initializer_list<T> list);

    Set &operator=(const Set &other);
    Set &operator=(Set &&other) noexcept;

    ~Set();

    std::size_t size() const;
    bool empty() const;
    T top() const;
    T min() const;
    bool find(const T &value) const;
    Node* find_node(Node* node, const T& value) const;
    Node* find_n(const T& value) const;
    void insert(const T &value);
    void emplace(T &&value);
    void clear();
    void clearTree(Set::Node *node);
};
