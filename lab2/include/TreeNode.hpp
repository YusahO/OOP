#pragma once

#include "common.hpp"

namespace MyBST {

template <typename T>
class TreeNode
{
public:
    TreeNode();
    explicit TreeNode(T &&value);
    explicit TreeNode(const T &value);
    TreeNode(const T &value, const BSTSharedPtr<T> &left, const BSTSharedPtr<T> &right);

    virtual ~TreeNode() = default;

    const T &GetValue() const;
    BSTSharedPtr<T> &GetLeft();
    BSTSharedPtr<T> &GetRight();

    void SetValue(T &&value);
    void SetValue(const T &value);
    void SetLeft(const BSTSharedPtr<T> &node);
    void SetLeft(BSTSharedPtr<T> &&node);
    void SetRight(const BSTSharedPtr<T> &node);
    void SetRight(BSTSharedPtr<T> &&node);

private:
    T m_value;
    BSTSharedPtr<T> mp_left;
    BSTSharedPtr<T> mp_right;
};

}

#include "TreeNode_impl.hpp"
