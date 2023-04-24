#pragma once

#include "BinarySearchTree.h"
#include "Errors.h"

template <typename T>
BinarySearchTree<T>::BinarySearchTree(std::initializer_list<T> lst)
{
    for (auto val : lst)
    {
        Insert(std::move(val));
    }
}

template <typename T>
TreeIterator<T> BinarySearchTree<T>::Insert(T &&value)
{
    BSTNodeSharedPtr<T> newNode = std::make_shared<TreeNode<T>>(value);
    if (!mp_root)
    {
        mp_root = newNode;
        TreeIterator<T> iter(mp_root, *this);
        return iter;
    }

    BSTSharedPtr<T> curr = mp_root;
    BSTSharedPtr<T> parent = nullptr;

    while (curr)
    {
        parent = curr;
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

    if (parent->m_value < value)
    {
        parent->mp_right = newNode;
    }
    else
    {
        parent->mp_left = newNode;
    }
    newNode->SetParent(parent);

    TreeIterator<T> iter(newNode, *this);
    return iter;
}

template <typename T>
TreeIterator<T> BinarySearchTree<T>::Insert(const T &value)
{
    return Insert(std::move(value));
}

template <typename T>
TreeIterator<T> BinarySearchTree<T>::Find(const T &value)
{
    BSTSharedPtr<T> found = _Find(value);
    return {found, *this};
}

template <typename T>
BSTSharedPtr<T> BinarySearchTree<T>::GetRoot() const
{
    return mp_root;
}

template <typename T>
TreeIterator<T> BinarySearchTree<T>::begin()
{
    auto ptr = _Min(mp_root);
    return {ptr, *this};
}

template <typename T>
TreeIterator<T> BinarySearchTree<T>::end()
{
    TreeIterator<T> iter(_Max(mp_root->mp_right), *this);
    return ++iter;
}

template <typename T>
template <class Iter>
TreeIterator<T> BinarySearchTree<T>::Erase(Iter &pos)
{
    std::pair<BSTSharedPtr<T>, bool> result = _Erase(*pos);
    TreeIterator<T> iter(*this);
    if (result.second)

    return {nextAfterDeleted.first, *this};
}

template <typename T>
template <class Iter>
TreeIterator<T> BinarySearchTree<T>::Erase(Iter &first, Iter &last)
{
    std::pair<BSTSharedPtr<T>, bool> result = { nullptr, true };
    for (Iter it = first; result.second && it != last;)
    {
        result = Erase;
        if (result.second)
            it.SetNode(result.first);
    }
    return {result.first, *this};
}

template <typename T>
bool BinarySearchTree<T>::Erase(const T &value)
{
    std::pair<BSTSharedPtr<T>, bool> result = _Erase(value);
    return result.second;
}

template <typename T>
std::pair<BSTSharedPtr<T>, bool> BinarySearchTree<T>::_Erase(const T &value)
{
    BSTSharedPtr<T> found = _Find(value);

    if (!found)
        return {nullptr, false};

    BSTSharedPtr<T> deleted;
    BSTSharedPtr<T> parent = found->mp_parent.lock();

    if (found->mp_left == nullptr || found->mp_right == nullptr)
    {
        BSTSharedPtr<T> newCurr;

        if (found->mp_left == nullptr)
            newCurr = found->mp_right;
        else
            newCurr = found->mp_left;

        if (parent != nullptr)
        {
            if (found == parent->mp_left)
                parent->mp_left = newCurr;
            else
                parent->mp_right = newCurr;
        }
        deleted = newCurr;
    }
    else
    {
        BSTSharedPtr<T> tmp = _Min(found->mp_right);
        parent = tmp->mp_parent.lock();

        if (parent != nullptr)
            parent->mp_left = tmp->mp_right;
        else
            found->mp_right = tmp->mp_right;

        found->m_value = tmp->m_value;

        deleted = found;
    }

    return {deleted, true};
}

template <typename T>
BSTSharedPtr<T> BinarySearchTree<T>::_Min(const BSTSharedPtr<T> &node)
{
    auto tmp = node;
    while (tmp->mp_left)
    {
        tmp = tmp->mp_left;
    }
    return tmp;
}

template <typename T>
BSTSharedPtr<T> BinarySearchTree<T>::_Max(const BSTSharedPtr<T> &node)
{
    auto tmp = node;
    while (tmp->mp_right)
    {
        tmp = tmp->mp_right;
    }
    return tmp;
}

template <typename T>
BSTSharedPtr<T> BinarySearchTree<T>::_Find(const T &value)
{
    BSTSharedPtr<T> node = mp_root;
    while (node && node->m_value != value)
    {
        if (node->m_value < value)
        {
            node = node->mp_right;
        }
        else
        {
            node = node->mp_left;
        }
    }
    return node;
}

template <typename T>
std::ostream &BinarySearchTree<T>::_Inorder(const BSTNodeSharedPtr<T> &node, std::ostream &os) const
{
    if (node->mp_left)
    {
        _Inorder(node->mp_left, os);
    }

    os << node->m_value << " ";

    if (node->mp_right != nullptr)
    {
        _Inorder(node->mp_right, os);
    }
    return os;
}
