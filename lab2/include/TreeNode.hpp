#pragma once

#include "TreeNode.h"
// const std::shared_ptr<TreeNode<T>> &parent

#include <memory>

template <typename T>
TreeNode<T>::TreeNode()
    : mp_left(nullptr),
      mp_right(nullptr),
      mp_parent(nullptr)
{
}

template <typename T>
TreeNode<T>::TreeNode(const T &value, const BSTNodeSharedPtr<T> &parent)
    : m_value(value),
      mp_left(nullptr),
      mp_right(nullptr),
      mp_parent(parent)
{
}

template <typename T>
TreeNode<T>::TreeNode(const T &value)
    : m_value(value),
      mp_left(nullptr),
      mp_right(nullptr),
      mp_parent(nullptr)
{
}

template <typename T>
T &TreeNode<T>::GetValue() const
{
    return m_value;
}

template <typename T>
BSTNodeSharedPtr<T> &TreeNode<T>::GetLeft() const
{
    return mp_left;
}

template <typename T>
BSTNodeSharedPtr<T> &TreeNode<T>::GetRight() const
{
    return mp_right;
}

template <typename T>
void TreeNode<T>::SetLeft(const BSTNodeSharedPtr<T> &node)
{
    mp_left = node;
}

template <typename T>
void TreeNode<T>::SetLeft(BSTNodeSharedPtr<T> &&node)
{
    mp_left = node;
}

template <typename T>
void TreeNode<T>::SetRight(const BSTNodeSharedPtr<T> &node)
{
    mp_right = node;
}

template <typename T>
void TreeNode<T>::SetRight(BSTNodeSharedPtr<T> &&node)
{
    mp_right = node;
}

template <typename T>
void TreeNode<T>::SetParent(const BSTNodeSharedPtr<T> &node)
{
    mp_parent = node;
}

template <typename T>
void TreeNode<T>::SetParent(BSTNodeSharedPtr<T> &&node)
{
    mp_parent = node;
}

template <typename T>
BSTNodeSharedPtr<T> TreeNode<T>::GetMinimum()
{
    BSTNodeSharedPtr<T> minNode = std::make_shared<TreeNode<T>>(this);
    while (minNode->mp_left)
        minNode = minNode->mp_left;
    return minNode;
}

template <typename T>
const BSTNodeSharedPtr<T> TreeNode<T>::GetMinimum() const
{
    auto minNode = GetMinimum();
    return const_cast<BSTNodeSharedPtr<T>>(minNode);
}

template <typename T>
BSTNodeSharedPtr<T> TreeNode<T>::GetMaximum()
{
    BSTNodeSharedPtr<T> maxNode = std::make_shared<TreeNode<T>>(this);
    while (maxNode->mp_right)
        maxNode = maxNode->mp_right;
    return maxNode;
}

template <typename T>
const BSTNodeSharedPtr<T> TreeNode<T>::GetMaximum() const
{
    auto maxNode = GetMaximum();
    return const_cast<BSTNodeSharedPtr<T>>(maxNode);
}
