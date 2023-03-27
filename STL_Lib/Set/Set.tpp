#ifndef COLLECTIONS_SET_TPP
#define COLLECTIONS_SET_TPP

namespace SetLib {
    template<class T>
    [[maybe_unused]] Set<T>::Set(const Set<T> &other_set)
    : m_size(other_set.m_size), m_root(other_set.m_root) {}

    template<class T>
    Set<T>::~Set() {
        clear();
    }

    template<class T>
    [[maybe_unused]] Set<TgiSet(const std::initializer_list<T> &init_list)
    : m_size(init_list.size())
    {
        std::size_t i = 0;
        for (const T& elem : init_list)
            if (!m_root->containsNode(m_root, elem))
                m_root = m_root->insert(m_root, elem);
    }

    template<class T>
    [[maybe_unused]] void Set<T>::insert(const T &data) {
        if (!m_root->containsNode(m_root, data)) {
            m_root = m_root->insert(m_root, data);
            m_size++;
        }
    }

    template<class T>
    [[maybe_unused]] size_t Set<T>::size() const {
        return m_size;
    }

    template<class T>
    [[maybe_unused]] bool Set<T>::empty() const {
        return m_size == 0;
    }

    template<class T>
    [[maybe_unused]] void Set<T>::clear() {
        delete_bst(m_root);
        m_size = 0;
    }

    template<class T>
    [[maybe_unused]] T Set<T>::top() const {
        auto temp_root = m_root;
        while (temp_root->right != nullptr)
            temp_root = temp_root->right;

        return (temp_root->data);
    }

    template<class T>
    [[maybe_unused]] bool Set<T>::find(const T &data) const {
        auto temp_root = m_root;
        while (temp_root != nullptr)
        {
            if (temp_root->data == data)
                return true;

            else if (temp_root->data > data)
                temp_root = temp_root->left;
            else
                temp_root = temp_root->right;
        }
        return false;
    }

    template<class T>
    Set<T> &Set<T>::operator=(const Set<T> &s_other) {
        if (&s_other != this) {
            clear();
            m_size = s_other.m_size;
            m_root = copy_node(s_other.m_root);
        }
        return *this;
    }

    template<class T>
    Set<T> &Set<T>::operator=(Set &&s_other) noexcept {
        if (&s_other != this) {
            clear();

            m_size = s_other.m_size;
            m_root = copy_node(s_other);

            s_other.clear();
        }
        return *this;
    }

    template<class T>
    void Set<T>::delete_bst(SetLibNode::Node<T>*& root) {
        if (root == nullptr)
            return;

        delete_bst(root->left);
        delete_bst(root->right);
        delete root;
        root = nullptr;
    }

    template<class T>
    SetLibNode::Node<T> *Set<T>::copy_node(const SetLibNode::Node<T> *node) {
        return node ? new SetLibNode::Node<T>(node->data, copy_node(node->left), copy_node(node->right)) : nullptr;
    }

    template<class T>
    [[maybe_unused]] Set<T>::Set(Set<T> &&other_set) noexcept : m_size(0), m_root(nullptr)
    {
        m_size = other_set.m_size;
        m_root = other_set.m_root;

        other_set.clear();
    }

    template<class T>
    [[maybe_unused]] void Set<T>::emplace(T &&data) {
        auto move_node = new SetLibNode::Node<T>(std::move(data));

        if (m_root == nullptr) {
            m_root = move_node;
            m_size++;
        }
        else { //TODO
        }
    }

    template<class T>
    [[maybe_unused]] T Set<T>::min() const {
        auto temp_root = m_root;
        while (temp_root->left != nullptr)
            temp_root = temp_root->left;

        return (temp_root->data);
    }

    template<class T>
    [[maybe_unused]] auto Set<T>::get(const T &element) const {
        auto temp_root = m_root;
        while (temp_root != nullptr)
        {
            if (temp_root->data == element)
                return temp_root;
            else if (temp_root->data > element)
                temp_root = temp_root->left;
            else
                temp_root = temp_root->right;
        }
        throw std::runtime_error("Element wasn't found");
    }
}
#endif // COLLECTIONS_SET_TPP