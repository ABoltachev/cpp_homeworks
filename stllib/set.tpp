#ifndef SET_TPP
#define SET_TPP

namespace lib {
	template<typename T>
	Set<T>::Set() : m_size(0), head(nullptr) {}

	template<typename T>
	Set<T>::Set(const Set& set)
	{
		head = nullptr;
		m_size = 0;
		for (auto &x : set)
			insert(x);
	}

	template<typename T>
	Set<T>::Set(Set&& set)
	{
		head = set.head;
		m_size = set.m_size;
		set.head = nullptr;
		set.m_size = 0;
	}

	template<typename T>
	Set<T>::Set(std::initializer_list<T> list)
	{
		for (auto &x : list)
			insert(x);
	}

	template<typename T>
	Set<T>& Set<T>::operator=(const Set& set)
	{
		if (&set == this) {
			return *this;
		}
		head = nullptr;
		m_size = 0;
		for (auto& x : set)
			insert(x);
		return *this;
	}

	template<typename T>
	Set<T>& Set<T>::operator=(Set&& set)
	{
		if (&set == this) {
			return *this;
		}
		head = set.head;
		m_size = set.m_size;
		set.head = nullptr;
		set.m_size = 0;
		return *this;
	}

	template<typename T>
	size_t Set<T>::size()
	{
		return m_size;
	}

	template<typename T>
	bool Set<T>::empty()
	{
		return m_size == 0;
	}

	template<typename T>
	T Set<T>::top()
	{
		if (!head) 
			throw std::logic_error("Set hasn't elements");
		
		Node* temp = head;
		while (temp->right) 
		{
			temp = temp->right;
		}
		return temp->value;
	}

	template<typename T>
	T Set<T>::min()
	{
		if (!head) 
			throw std::logic_error("Set hasn't elements");
		
		Node* temp = head;
		while (temp->left) 
		{
			temp = temp->left;
		}
		return temp->value;
	}


	template<typename T>
	bool Set<T>::find(const T& elem)
	{
		if (!head)
			throw std::logic_error("Set hasn't elements");

		Node* temp = head;
		while (temp) 
		{
			if (temp->value == elem)
				return true;
			else if (elem < temp->value)
				temp = temp->left;
			else if (elem > temp->value)
				temp = temp->right;
		}
		return false;
	}

	template<typename T>
	T& Set<T>::find_v(const T& elem)
	{
		Node* temp = head;
		while (temp) 
		{
			if (temp->value == elem)
				return temp->value;
			else if (elem < temp->value)
				temp = temp->left;
			else if (elem > temp->value)
				temp = temp->right;
		}
	}

	template<typename T>
	void Set<T>::insert(const T& elem)
	{
		insert_r(head, elem);
		m_size++;
	}

	template<typename T>
	void Set<T>::insert_r(Node*& head, const T& elem)
	{
		if (!head)
		{
			head = new Node {elem};
			return;
		}

		if (head->value == elem)
			return;
		if (elem < head->value)
			insert_r(head->left, elem);
		if (elem > head->value)
			insert_r(head->right, elem);
	}

	template<typename T>
	void Set<T>::emplace(T&& elem)
	{
		emplace_r(head, elem);
		m_size++;
	}

	template<typename T>
	void Set<T>::emplace_r(Node*& head, T&& elem)
	{
		if (!head)
		{
			head = new Node {std::move(elem)};
			return;
		}

		if (head->value == elem)
			return;
		if (elem < head->value)
			emplace_r(head->left, elem);
		if (elem > head->value)
			emplace_r(head->right, elem);
	}

	template<typename T>
	void Set<T>::clear()
	{
		head = nullptr;
		m_size = 0;
	}
}

#endif