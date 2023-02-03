#pragma once

namespace algo
{
	template <typename type>
	class set 
	{
	private:
		struct node_set
		{
			node_set();
			node_set(const node_set& _node_set);
			node_set* left;
			node_set* right;
			void clear_childs();
			type value;
		};
		node_set* head;
		size_t __size__;
	public:
		set();
		set(const set<type>& _set);
		set(const std::initializer_list<type>& init_list);
		size_t size() const;
		bool empty() const;
		void emplace(const type& value);
		const type& top() const;
		const type& bottom() const;
		bool find(const type& value) const;
		void insert(const type& value);
		void clear();
		const set<type>& operator=(const set<type>& _set);
		~set();
	private:
		void check_empty() const;
	};
}

#include "set.tpp"
