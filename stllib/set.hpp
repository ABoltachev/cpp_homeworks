#pragma once

#include "BinaryTree.h"
#include <initializer_list>

template<typename T>
class set {
	BinaryTree<T> tree_;
public:
	set() {}
		set(set<T> const& other) :tree_(other.tree_) {}
		set(set<T>&& other) :tree_(std::move(other.tree_)) {}
	set(std::initializer_list<T> list) {
		for (auto& i : list)
			insert(i);
	}
	~set() {}

	set<T>& operator=(set<T> const& other) {
		tree_ = other.tree_;
		return *this;
	}
	set<T>& operator=(set<T>&& other) {
		tree_ = std::move(other.tree_);
		return *this;
	}

	size_t size()const noexcept {
		return tree_.size();
	}
	bool empty()const noexcept {
		return size() == 0;
	}
	const T& top()const noexcept {
		return tree_.maxRightNodePtr()->getValue();
	}
	bool find(T const& value)const noexcept {
		return tree_.find(value) != nullptr;
	}
	void insert(T const& value) {
		tree_.insert(value);
	}
	void emplace(T&& value) {
		tree_.emplace(std::move(value));
	}
	void clear()noexcept {
		tree_.clear();
	}
};