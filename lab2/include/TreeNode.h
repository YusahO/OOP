#pragma once

#include "common.h"
#include "BinarySearchTree.h"

template <typename T>
class BinarySearchTree;

template <typename T>
class TreeNode
{
public:
    TreeNode();
    explicit TreeNode(const T &value);
    TreeNode(const T &value, const BSTSharedPtr<T> &left, const BSTSharedPtr<T> &right);

    virtual ~TreeNode() = default;

    const T &GetValue() const;
    BSTSharedPtr<T> &GetLeft();
    BSTSharedPtr<T> &GetRight();

    void SetLeft(const BSTSharedPtr<T> &node);
    void SetLeft(BSTSharedPtr<T> &&node);
    void SetRight(const BSTSharedPtr<T> &node);
    void SetRight(BSTSharedPtr<T> &&node);

private:
    T m_value;
    BSTSharedPtr<T> mp_left;
    BSTSharedPtr<T> mp_right;
};

#include "TreeNode.hpp"
