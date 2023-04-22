#pragma once

#include "BinarySearchTree.h"
#include "Errors.h"

template <typename T>
std::pair<TreeIterator<T>, bool> BinarySearchTree<T>::Insert(T &&value)
{
    BSTNodeSharedPtr<T> newNode = std::make_shared<TreeNode<T>>(value);
    if (!mp_root)
    {
        mp_root = newNode;
        TreeIterator<T> iter(mp_root, *this);
        return std::make_pair<TreeIterator<T>, bool>(iter, true);
    }

    BSTSharedPtr<T> curr = mp_root;

    while (curr)
    {
        if (curr->mp_value < value)
        {
            curr = curr->mp_right;
        }
        else if (curr->mp_value > value)
        {
            curr = curr->mp_left;
        }
        else
        {
            std::make_pair<TreeIterator<T>, bool>(TreeIterator<T>(curr, *this), false);
        }
    }

    if (curr->mp_parent->m_value < value)
    {
        curr->mp_parent->mp_right = newNode;
    }
    else
    {
        curr->mp_parent->mp_left = newNode;
    }

    newNode->SetParent(curr->mp_parent);

    TreeIterator<T> iter(newNode, *this);
    return std::make_pair<TreeIterator<T>, bool>(iter, true);
}

template <typename T>
std::pair<TreeIterator<T>, bool> BinarySearchTree<T>::Insert(const T &value)
{
    return Insert(value);
}
