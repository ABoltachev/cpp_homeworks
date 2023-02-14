#ifndef SET_H
#define SET_H
#include <bits/stl_tree.h>
#include <initializer_list>
    using namespace std;
    template<typename Key, typename Compare = std::less<Key>>
    class set
    {

    public:

        typedef Key     key_type;
        typedef Key     value_type;
        typedef Compare key_compare;
        typedef Compare value_compare;

    private:

        typedef _Rb_tree<key_type, value_type, _Identity<value_type>,
                key_compare> rb_type;
        rb_type type_tree;
        value_type top_key = NULL;

    public:
        typedef typename rb_type::const_iterator iterator;
        typedef typename rb_type::const_iterator const_iterator;
        typedef typename rb_type::size_type size_type;

        set() : type_tree() { }

        explicit set(const Compare& comp) : type_tree(comp) { }

        template<typename Iterator>
        set(Iterator begin, Iterator last,
            const Compare& comp)
                : type_tree(comp)
        { type_tree._M_insert_unique(begin, last); }

        set(const set& x) : type_tree(x.type_tree) { }


        set(set&& x) : type_tree(std::move(x.type_tree)) { }

        set(initializer_list<value_type> list,
            const Compare& comp = Compare())
                : type_tree(comp)
        {
            for(auto l : list) check_top(*l);
            type_tree._M_insert_unique(list.begin(), list.end());
        }

        set&
        operator=(const set& x)
        {
            type_tree = x.type_tree;
            return *this;
        }

        set& operator=(set&& x)
        {
            this->clear();
            this->swap(x);
            return *this;
        }

        set& operator=(initializer_list<value_type> list)
        {
            this->clear();
            this->insert(list.begin(), list.end());
            return *this;
        }

        key_compare key_comp() const { return type_tree.key_comp(); }
        value_compare value_comp() const { return type_tree.key_comp(); }
        iterator begin() const { return type_tree.begin(); }
        iterator end() const { return type_tree.end(); }
        bool empty() const { return type_tree.empty(); }
        size_type size() const { return type_tree.size(); }


        void
        swap(set& x)
        { type_tree.swap(x.type_tree); }

        std::pair<iterator, bool>
        insert(const value_type& x)
        {
            check_top(x);
            std::pair<typename rb_type::iterator, bool> p =
                    type_tree._M_insert_unique(x);
            return std::pair<iterator, bool>(p.first, p.second);
        }

        std::pair<iterator, bool>
        emplace(value_type&& x)
        {
            check_top(x);
            std::pair<typename rb_type::iterator, bool> p =
                    type_tree._M_insert_unique(std::move(x));
            return std::pair<iterator, bool>(p.first, p.second);
        }

        iterator
        insert(const_iterator position, const value_type& x)
        {
            check_top(x);
            return type_tree._M_insert_unique_(position, x);
        }


        iterator
        insert(const_iterator position, value_type&& x)
        {
            check_top(*x);
            return type_tree._M_insert_unique_(position, std::move(x));
        }

        template<typename Iterator> void
        insert(Iterator begin, Iterator last)
        {

            type_tree._M_insert_unique(begin, last);
        }


        void
        insert(initializer_list<value_type> list)
        {
            for(auto l : list) check_top(l);
            this->insert(list.begin(), list.end());
        }

        void
        clear()
        { type_tree.clear(); }

        void check_top(key_type a) {
            if(a > top_key) top_key = a;
        }

        bool find(const key_type x) {return (type_tree.find(x) != type_tree.end());}

        value_type top() {return top_key;}

    };

    template<typename Key, typename Compare>
    inline bool
    operator==(const set<Key, Compare>& x,
               const set<Key, Compare>& y)
    { return x.type_tree == y.type_tree; }

#endif
