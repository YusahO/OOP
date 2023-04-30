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
    explicit TreeNode(const T &value);
    TreeNode(const T &value, const BSTNodeSharedPtr<T> &left, const BSTNodeSharedPtr<T> &right);

    virtual ~TreeNode() = default;

    const T &GetValue() const;
    BSTNodeWeakPtr<T> &GetParent();
    BSTNodeSharedPtr<T> &GetLeft();
    BSTNodeSharedPtr<T> &GetRight();

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
