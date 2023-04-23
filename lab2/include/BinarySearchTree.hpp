#pragma once

#include "BinarySearchTree.h"
#include "Errors.h"

template<typename T>
BinarySearchTree<T>::BinarySearchTree(std::initializer_list<T> lst)
{
    for (auto &val : lst)
    {
        Insert(val);
    }
}

template <typename T>
TreeIterator<T> BinarySearchTree<T>::Insert(T &&value)
{
    BSTNodeSharedPtr<T> newNode = std::make_shared<TreeNode<T>>(value);
    if (!mp_root)
    {
        mp_root = newNode;
        TreeIterator<T> iter(mp_root, this);
        return iter;
    }

    BSTSharedPtr<T> curr = mp_root;

    while (curr)
    {
        if (curr->m_value < value)
        {
            curr = curr->mp_right;
        }
        else if (curr->m_value > value)
        {
            curr = curr->mp_left;
        }
        else
        {
            throw TreeValueError(__FILE__, typeid(*this).name(), __LINE__);
        }
    }

    BSTSharedPtr<T> parent = curr->mp_parent.lock();
    if (parent->m_value < value)
    {
        parent->mp_right = newNode;
    }
    else
    {
        parent->mp_left = newNode;
    }

    newNode->SetParent(parent);

    TreeIterator<T> iter(newNode, this);
    return iter;
}

template <typename T>
TreeIterator<T> BinarySearchTree<T>::Insert(const T &value)
{
    return Insert(value);
}

template<typename T>
std::ostream &BinarySearchTree<T>::Inorder(const BSTNodeSharedPtr<T> &node, std::ostream &os) const
{
    if (node->mp_left)
    {
        Inorder(node->mp_left, os);
    }

    os << node->mp_value << ", ";

    if (node->mp_right != nullptr)
    {
        Inorder(node->mp_right, os);
    }
    return os;
}
