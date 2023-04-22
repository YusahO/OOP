#pragma once

#include <memory>
#include "BinarySearchTree.h"

template <typename T>
class TreeNode;

template <typename T>
class BinarySearchTree;


template <typename T>
using BSTNodeWeakPtr = std::weak_ptr<TreeNode<T>>;

template <typename T>
using BSTNodeSharedPtr = std::shared_ptr<TreeNode<T>>;

template <typename T>
class TreeNode
{
public:
    TreeNode();
    TreeNode(const T &value, const BSTNodeSharedPtr<T> &parent);
    explicit TreeNode(const T &value);

    virtual ~TreeNode() = default;

    T &GetValue() const;
    BSTNodeSharedPtr<T> &GetLeft() const;
    BSTNodeSharedPtr<T> &GetRight() const;

    void SetLeft(const BSTNodeSharedPtr<T> &node);
    void SetLeft(BSTNodeSharedPtr<T> &&node);
    void SetRight(const BSTNodeSharedPtr<T> &node);
    void SetRight(BSTNodeSharedPtr<T> &&node);
    void SetParent(const BSTNodeSharedPtr<T> &node);
    void SetParent(BSTNodeSharedPtr<T> &&node);

protected:
    BSTNodeSharedPtr<T> GetMinimum();
    const BSTNodeSharedPtr<T> GetMinimum() const;
    BSTNodeSharedPtr<T> GetMaximum();
    const BSTNodeSharedPtr<T> GetMaximum() const;

private:
    friend BinarySearchTree<T>;
    T m_value;
    BSTNodeWeakPtr<T> mp_parent;
    BSTNodeSharedPtr<T> mp_left;
    BSTNodeSharedPtr<T> mp_right;
};

#include "TreeNode.hpp"
