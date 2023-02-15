#ifndef SET_HPP
#define SET_HPP

#include <iostream>

template <typename T>
class set {
public:
	using value_type = T;
	using size_type = std::size_t;

public:
	friend class Node;
	class Node {
	public:
		friend class set<T>;

		Node(value_type node_value) : value(node_value) {}
		Node() = default;
		~Node() = default;

		bool is_leaf() {
			if (left == nullptr && right == nullptr)
				return true;
			else
				return false;
		}

		void set_left(Node* left_node) {
			left = left_node;
		}

		void set_right(Node* right_node) {
			right = right_node;
		}

		value_type value;
		Node* left = nullptr;
		Node* right = nullptr;
	};

public:
	Node* Head = nullptr;

	set() {}

	set(std::initializer_list<value_type> l) {
		for (auto it = l.begin(); it != l.end(); it++) {
			insert(*it);
		}
	}

	void copy(Node* node) {
		if (!node)
			throw std::runtime_error("set to copy is empty");
		insert(node->value);
		if (node->left)
			copy(node->left);
		if (node->right)
			copy(node->right);
	}

	~set() {
		clear(Head);
	}

	set(const set<T>& other) {
		copy(other.Head);
	}

	set(set<T>&& other) : Head(std::move(other.Head)) {}

	size_type size(Node* node) const {
		size_type Size = 0;
		if (node) {
			Size++;
			Size += size(node->left);
			Size += size(node->right);
		}
		return Size;
	}

	size_type size() const {
		return size(Head);
	}

	bool empty() const {
		if (Head != nullptr)
			return false;
		else
			return true;
	}

	value_type top() const {
		if (!Head)
			throw std::runtime_error("set is empty");
		return Head->value;
	}

	bool find(value_type find_element) {
		if (!Head)
			return false;
		if (find_element == Head->value)
			return true;
		else {
			Node* current = Head;
			while (current) {
				if (current->value > find_element)
					current = current->left;
				else if (current->value < find_element)
					current = current->right;
				else
					return true;
			}
			return false;
		}
	}

	void insert(value_type element) {
		if (!Head) {
			Head = new Node(element);
			return;
		}
		Node* current = Head;
		Node* new_Node = new Node(element);
		while (true) {
			if (element > current->value) {
				if (!current->right) {
					current->right = new_Node;
					break;
				}
				current = current->right;
			}
			if (element < current->value) {
				if (!current->left) {
					current->left = new_Node;
					break;
				}
				current = current->left;
			}
		}
	}
	template<class... Args>
	void emplace(Args&&... args) {
		if (!Head) {
			Head = new Node(T(args...));
			return;
		}
		Node* current = Head;
		Node* new_Node = new Node(T(args...));
		while (true) {
			if (new_Node->value > current->value) {
				if (!current->right) {
					current->right = new_Node;
					break;
				}
				current = current->right;
			}
			if (new_Node->value < current->value) {
				if (!current->left) {
					current->left = new_Node;
					break;
				}
				current = current->left;
			}
		}
	}

	void clear(Node* node) {
		if (!node)
			return;
		if (node->left)
			clear(node->left);
		if (node->right)
			clear(node->right);
		delete node;
	}

	void clear() {
		clear(Head);
		Head = nullptr;
	}

	set& operator=(const set& other) {
		if (this == &other) {
			return *this;
		}
		set<T> tmp(other);
		std::swap(Head, tmp.Head);
		return *this;
	}

	set& operator=(set&& other) {
		Head = std::move(other.Head);
		return *this;
	}
};

#endif // SET_HPP