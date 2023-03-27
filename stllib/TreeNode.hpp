#pragma once

#include <memory>
#include <utility>

template<typename T>
class TreeNode {
	T value_;
	std::unique_ptr<TreeNode<T>> left_{ nullptr };
	std::unique_ptr<TreeNode<T>> right_{ nullptr };
public:
	TreeNode(T const& value) :value_(value) {}
	TreeNode(TreeNode<T> const& other) :
		value_(other.value_)
	{
		if (other.left_)
			left_ = std::make_unique<TreeNode<T>>(*other.left_);
		if (other.right_)
			right_ = std::make_unique<TreeNode<T>>(*other.right_);
	}
	TreeNode(TreeNode<T>&& other)noexcept :
		value_(std::move(other.value_)),
		left_(std::move(other.left_)),
		right_(std::move(other.right_)) {}
	~TreeNode() {}

	std::unique_ptr<TreeNode<T>> moveLeft()noexcept {
		return std::move(left_);
	}
	std::unique_ptr<TreeNode<T>> moveRight()noexcept {
		return std::move(right_);
	}

	TreeNode<T>& operator=(TreeNode<T> const& other) {
		value_ = other.value_;
		left_ = std::make_unique<TreeNode<T>>(*other.left_);
		right_ = std::make_unique<TreeNode<T>>(*other.right_);
		return *this;
	}
	TreeNode<T>& operator=(TreeNode<T>&& other)noexcept {
		value_ = std::move(other.value_);
		left_ = std::move(other.left_);
		right_ = std::move(other.right_);
		return *this;
	}

	T const& getValue()const noexcept {
		return value_;
	}

	size_t size()const noexcept {
		size_t result = 1;
		if (left_ != nullptr)
			result += left_->size();
		if (right_ != nullptr)
			result += right_->size();
		return result;
	}

	void insert(T const& val) {
		if (val < value_)
			if (left_ == nullptr) {
				left_ = std::make_unique<TreeNode<T>>(val);
			}
			else
				left_->insert(val);
		else if (value_ < val)
			if (right_ == nullptr) {
				right_ = std::make_unique<TreeNode<T>>(val);
			}
			else
				right_->insert(val);
			}
	void emplace(T&& val) {
		if (val < value_)
			if (left_ == nullptr) {
				left_ = std::make_unique<TreeNode<T>>(std::move(val));
			}
			else
				left_->emplace(std::move(val));
		else if (value_< val)
			if (right_ == nullptr) {
				right_ = std::make_unique<TreeNode<T>>(val);
			}
			else
				right_->emplace(std::move(val));
			}

	template<typename U>
	TreeNode<T> const* find(U const& val)const noexcept {
		if (val < value_) {
			if (left_)
				return left_->find(val);
			else
				return nullptr;
		}
		else if (value_ < val) {
			if (right_)
				return right_->find(val);
			else
				return nullptr;
		}
		else 			return this;
	}

	TreeNode<T> const* maxLeftNodePtr()const noexcept {
		if (left_)
			return left_->maxLeftNodePtr();
		else
			return this;
	}
	TreeNode<T> const* maxRightNodePtr()const noexcept {
		if (right_)
			return right_->maxRightNodePtr();
		else
			return this;
	}
};