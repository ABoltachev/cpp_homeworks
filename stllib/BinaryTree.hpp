#pragma once

#include <memory>
#include "TreeNode.h"

template<typename T>
class BinaryTree {
	std::unique_ptr<TreeNode<T>> root_{ nullptr };

public:
	BinaryTree() {}
	BinaryTree(BinaryTree<T> const& other) :root_(std::make_unique<TreeNode<T>>(*other.root_)) {}
	BinaryTree(BinaryTree<T>&& other)noexcept :root_(std::move(other.root_)) {}
	~BinaryTree() {}

	BinaryTree<T>& operator=(BinaryTree<T> const& other) {
		root_ = std::make_unique<TreeNode<T>>(*other.root_);
		return *this;
	}
	BinaryTree<T>& operator=(BinaryTree<T>&& other)noexcept {
		root_ = std::move(other.root_);
		return *this;
	}

	TreeNode<T> const* maxLeftNodePtr()const noexcept {
		if (root_)
			return root_->maxLeftNodePtr();
		else
			return nullptr;
	}
	TreeNode<T> const* maxRightNodePtr()const noexcept {
		if (root_)
			return root_->maxRightNodePtr();
		else
			return nullptr;
	}

	size_t size()const noexcept {
		if (root_ == nullptr)
			return 0;
		else
			return root_->size();
	}
	void insert(T const& val) {
		if (root_ == nullptr) {
			root_ = std::make_unique<TreeNode<T>>(val);
		}
		else
			root_->insert(val);
	}
	void emplace(T&& val) {
		if (root_ == nullptr) {
			root_ = std::make_unique<TreeNode<T>>(std::move(val));
		}
		else
			root_->emplace(std::move(val));
	}
	template<typename U>
	TreeNode<T> const* find(U const& val)const noexcept {
		if (root_ == nullptr)
			return nullptr;
		else
			return root_->find(val);
	}

	void clear()noexcept {
		root_ = nullptr;
	}

	T const& top()const noexcept {
		return *root_->maxRightNodePtr();
	}
};