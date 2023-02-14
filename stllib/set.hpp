#ifndef HW2_C___SET_HPP
#define HW2_C___SET_HPP

#include <stdexcept>


template<typename T>
class set {
private:
    struct Node{
        T value;
        Node* right;
        Node* left;

        Node(const T& value);
        Node(T&& value);

    };
    size_t m_size;
    Node* head;

public:
    set();
    set(const set& other);
    set(set&& other);
    set(std::initializer_list<T>& initial_list);

    size_t size() const;
    bool empty() const;

    const T& getMax() const;
    const T& getMin() const;

    bool find(const T& elem) const;

    void insert(const T& elem);
    void emplace(T&& elem);

    set& operator=(const set<T> &arr);
    set& operator=(set<T> &&arr);

    void clear();
    void clearTree(Node* node);

    ~set();

};

#include "set.tpp"

#endif
