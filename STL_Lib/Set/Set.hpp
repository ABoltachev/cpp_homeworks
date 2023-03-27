#ifndef COLLECTIONS_SET_HPP
#define COLLECTIONS_SET_HPP

#include <cstdio>
#include "utils/Node.hpp"
#include <initializer_list>

namespace SetLib {
    template<class T>
    class [[maybe_unused]] Set {
    private:
        size_t m_size {0};
        SetLibNode::Node<T>* m_root {nullptr};

        void delete_bst(SetLibNode::Node<T>*& root);
        SetLibNode::Node<T>* copy_node(const SetLibNode::Node<T>* s_node);

    public:
        // Destructor
        ~Set();

        // Constructors
        Set() = default;
        [[maybe_unused]] Set(const Set<T>& other_set);
        [[maybe_unused]] Set(const std::initializer_list<T>& init_list);
        [[maybe_unused]] Set(Set<T>&& other_set) noexcept;

        // Methods
        [[maybe_unused]] void insert(const T& data);
        [[maybe_unused]] void emplace(T&& data);
        [[maybe_unused]]  [[nodiscard]] size_t size() const;
        [[maybe_unused]] [[nodiscard]] bool empty() const;
        void clear();
        [[maybe_unused]] [[nodiscard]]  T top() const;
        [[maybe_unused]] [[nodiscard]]  T min() const;
        [[maybe_unused]] [[nodiscard]] bool find(const T& data) const;
        [[maybe_unused]] [[nodiscard]] auto get(const T& element) const;

        // Operators
        [[maybe_unused]] Set<T> &operator=(const Set<T>& s_other);
        [[maybe_unused]] Set<T> &operator=(Set&& s_other) noexcept;
    };
}

#include "Set.tpp"
#endif //COLLECTIONS_SET_HPP