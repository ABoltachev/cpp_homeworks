#pragma once

template <typename type>
algo::set<type>::node_set::node_set()
{
	left = nullptr;
	right = nullptr;
	value = type();
}

template <typename type>
algo::set<type>::node_set::node_set(const node_set& _node_set)
{
	value = _node_set.value;
	if (_node_set.left)
	{
		left = new algo::set<type>::node_set(*_node_set.left);
	}
	else
	{
		left = nullptr;
	}
	if (_node_set.right)
	{
		right = new algo::set<type>::node_set(*_node_set.right);
	}
	else
	{
		right = nullptr;
	}
}

template <typename type>
void algo::set<type>::node_set::clear_childs()
{
	if (left)
	{
		left->clear_childs();
		delete left;
	}
	if (right)
	{
		right->clear_childs();
		delete right;
	}
}

template <typename type>
algo::set<type>::set()
{
	head = nullptr;
	__size__ = 0;
}

template <typename type>
algo::set<type>::set(const set<type>& _set)
{
	if (&_set == this || !_set.head)
	{
		head = nullptr;
		__size__ = 0;
		return;
	}
	head = new algo::set<type>::node_set(*_set.head);
	__size__ = _set.__size__;
}

template <typename type>
algo::set<type>::set(const std::initializer_list<type>& init_list)
{
	head = nullptr;
	__size__ = 0;
	for (const auto& elem : init_list)
	{
		insert(elem);
	}
}

template <typename type>
size_t algo::set<type>::size() const
{
	return __size__;
}

template <typename type>
bool algo::set<type>::empty() const
{
	return __size__ == 0;
}

template <typename type>
const type& algo::set<type>::top() const
{
	check_empty();
	auto iter = head;
	while (iter->right)
		iter = iter->right;
	return iter->value;
}

template <typename type>
void algo::set<type>::check_empty() const
{
	if (!__size__)
		throw std::logic_error("algo::set is clear");
}

template <typename type>
const type& algo::set<type>::bottom() const
{
	check_empty();
	auto iter = head;
	while (iter->left)
		iter = iter->left;
	return iter->value;
}

template <typename type>
bool algo::set<type>::find(const type& value) const
{
	auto iter = head;
	while (iter)
	{
		if (value < iter->value)
			iter = iter->left;
		else if (value == iter->value)
			return true;
		else
			iter = iter->right;
	}
	return false;
}

template <typename type>
void algo::set<type>::insert(const type& value)
{
	if (!__size__)
	{
		head = new algo::set<type>::node_set;
		head->value = value;
	}
	else
	{
		auto iter = head;
		while (true)
		{
			if (value < iter->value)
			{
				if (!iter->left)
				{
					iter->left = new node_set;
					iter->left->value = value;
					break;
				}
				else
					iter = iter->left;
			}
			else if (value == iter->value)
				return;
			else
			{
				if (!iter->right)
				{
					iter->right = new node_set;
					iter->right->value = value;
					break;
				}
				else
					iter = iter->right;
			}
		}
	}
	++__size__;
}

template <typename type>
void algo::set<type>::clear()
{
	if (head)
	{
		head->clear_childs();
		delete head;
		head = nullptr;
		__size__ = 0;
	}
}

template <typename type>
const algo::set<type>& algo::set<type>::operator=(const set<type>& _set)
{
	if (&_set == this || !_set.head)
	{
		head = nullptr;
		__size__ = 0;
		return;
	}
	clear();
	head = new algo::set<type>::node_set(_set.head);
	__size__ = _set.__size__;
}

template <typename type>
algo::set<type>::~set()
{
	clear();
}

template <typename type>
void algo::set<type>::emplace(const type& value) noexcept
{
	if (!__size__)
	{
		head = new algo::set<type>::node_set;
		head->value = std::move(value);
	}
	else
	{
		auto iter = head;
		while (true)
		{
			if (value < iter->value)
			{
				if (!iter->left)
				{
					iter->left = new node_set;
					iter->left->value = std::move(value);
					break;
				}
				else
					iter = iter->left;
			}
			else if (value == iter->value)
				return;
			else
			{
				if (!iter->right)
				{
					iter->right = new node_set;
					iter->right->value = std::move(value);
					break;
				}
				else
					iter = iter->right;
			}
		}
	}
	++__size__;
}