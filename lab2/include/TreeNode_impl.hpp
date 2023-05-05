#pragma once

#include "TreeNode.hpp"
// const std::shared_ptr<TreeNode<T>> &parent

#include <memory>

namespace MyBST {

template <typename T>
TreeNode<T>::TreeNode()
    : m_value(0),
      mp_left(0),
      mp_right(0)
{
}

template <typename T>
TreeNode<T>::TreeNode(const T &value)
    : m_value(value),
      mp_left(nullptr),
      mp_right(nullptr)
{
}

template <typename T>
TreeNode<T>::TreeNode(const T &value, const BSTSharedPtr<T> &left, const BSTSharedPtr<T> &right)
    : m_value(value),
      mp_left(left),
      mp_right(right)
{
}

template <typename T>
T &TreeNode<T>::GetValue()
{
    return m_value;
}

template <typename T>
const T &TreeNode<T>::GetValue() const
{
    return m_value;
}

template <typename T>
BSTSharedPtr<T> &TreeNode<T>::GetLeft()
{
    return mp_left;
}

template <typename T>
BSTSharedPtr<T> &TreeNode<T>::GetRight()
{
    return mp_right;
}

template<typename T>
inline void TreeNode<T>::SetValue(T &value)
{
    m_value = value;
}

template<typename T>
inline void TreeNode<T>::SetValue(const T &value)
{
    m_value = value;
}

template <typename T>
void TreeNode<T>::SetLeft(const BSTSharedPtr<T> &node)
{
    mp_left = node;
}

template <typename T>
void TreeNode<T>::SetLeft(BSTSharedPtr<T> &&node)
{
    mp_left = node;
}

template <typename T>
void TreeNode<T>::SetRight(const BSTSharedPtr<T> &node)
{
    mp_right = node;
}

template <typename T>
void TreeNode<T>::SetRight(BSTSharedPtr<T> &&node)
{
    mp_right = node;
}

}