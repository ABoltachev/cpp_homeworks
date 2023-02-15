#pragma once

namespace cnt {
    template<class T>
    class set {
        struct Node {
            T value;
            Node *right;
            Node *left;

            explicit Node(const T &value) : value(value), left(nullptr), right(nullptr) {}
            explicit Node(T &&value) : value(std::move(value)), left(nullptr), right(nullptr) {}
        };

        Node *head;
        size_t size_;

    public:
        set();
        set(const set &set_);
        set(set &&set_) noexcept;
        set(std::initializer_list<T> list);

        set &operator=(const set &set_);
        set &operator=(set &&set_) noexcept;

        ~set();

        [[nodiscard]] bool find(const T &el) const;
        [[nodiscard]] size_t size() const noexcept;
        [[nodiscard]] bool empty() const noexcept;
        [[nodiscard]] T top() const;
        [[nodiscard]] T min() const;
        void emplace(const T &&el);
        void insert(const T &el);
        void clear();
        void clearAdditionally(const Node *node);
    };
}

#include "set.tpp"
