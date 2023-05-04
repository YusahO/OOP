#pragma once

#include "BinarySearchTree.h"
#include "Errors.h"

template <Comparable T>
MyBST::BinarySearchTree<T>::BinarySearchTree(std::initializer_list<T> lst)
{
    for (auto val : lst)
    {
        Insert(std::move(val));
    }
}

template <Comparable T>
TreeIterator<T> MyBST::BinarySearchTree<T>::Insert(T &&value)
{
    BSTSharedPtr<T> newNode = std::make_shared<TreeNode<T>>(value);

    if (!mp_root)
    {
        mp_root = newNode;
        return TreeIterator<T>(mp_root);
    }

    BSTSharedPtr<T> curr = mp_root;
    BSTSharedPtr<T> parent = nullptr;

    while (curr)
    {
        parent = curr;
        if (curr->GetValue() < value)
        {
            curr = curr->GetRight();
        }
        else if (curr->GetValue() > value)
        {
            curr = curr->GetLeft();
        }
        else
        {
            throw TreeValueError(__FILE__, typeid(*this).name(), __LINE__);
        }
    }

    if (parent->GetValue() < value)
    {
        parent->GetRight() = newNode;
    }
    else
    {
        parent->GetLeft() = newNode;
    }

    return TreeIterator<T>(newNode);
}

template <Comparable T>
TreeIterator<T> MyBST::BinarySearchTree<T>::Insert(const T &value)
{
    return Insert(std::move(value));
}

template <Comparable T>
TreeIterator<T> MyBST::BinarySearchTree<T>::Find(const T &value)
{
    BSTSharedPtr<T> found = _Find(value);
    return {found, mp_root};
}

template <Comparable T>
BSTSharedPtr<T> MyBST::BinarySearchTree<T>::GetRoot() const
{
    return mp_root;
}

template <Comparable T>
void MyBST::BinarySearchTree<T>::Clean() noexcept
{
    mp_root = nullptr;
}

template <Comparable T>
TreeIterator<T> MyBST::BinarySearchTree<T>::begin()
{
    std::cout << mp_root << "\n";
    return TreeIterator<T>(mp_root);
}

template <Comparable T>
TreeIterator<T> MyBST::BinarySearchTree<T>::end()
{
    TreeIterator<T> iter;
    iter.Rightmost(mp_root);
    return ++iter;
}

template <Comparable T>
template <class Iter>
TreeIterator<T> MyBST::BinarySearchTree<T>::Erase(Iter &pos)
{
    std::pair<BSTSharedPtr<T>, bool> result = _Erase(*pos);
    return {result.first, mp_root};
}

template <Comparable T>
template <class Iter>
TreeIterator<T> MyBST::BinarySearchTree<T>::Erase(Iter &first, Iter &last)
{
    Iter it = first;
    while (it != last)
    {
        std::cout << it << " " << last << "\n";
        std::cout << mp_root->GetValue() << " tree: " << *this << std::endl;
        it = Erase(it);
        last.Recalculate(mp_root);
    }

    return it;
}

template <Comparable T>
bool MyBST::BinarySearchTree<T>::Erase(const T &value)
{
    std::pair<BSTSharedPtr<T>, bool> result = _Erase(value);
    return result.second;
}

template <Comparable T>
std::pair<BSTSharedPtr<T>, bool> MyBST::BinarySearchTree<T>::_Erase(const T &value)
{
    BSTSharedPtr<T> found = mp_root, parent;
    while (found && found->GetValue() != value)
    {
        parent = found;
        if (found->GetValue() < value)
            found = found->GetRight();
        else
            found = found->GetLeft();
    }

    if (!found)
        return {nullptr, false};

    BSTSharedPtr<T> nextAfterDeleted;

    if (found->GetLeft() == nullptr || found->GetRight() == nullptr)
    {
        BSTSharedPtr<T> newCurr;

        if (found->GetLeft() == nullptr)
            newCurr = found->GetRight();
        else
            newCurr = found->GetLeft();

        if (parent == nullptr)
        {
            mp_root = newCurr;
            nextAfterDeleted = nullptr;
        }
        else
        {
            if (found == parent->GetLeft())
                parent->GetLeft() = newCurr;
            else
                parent->GetRight() = newCurr;
            nextAfterDeleted = parent;
        }
    }
    else
    {
        BSTSharedPtr<T> tmp = found->GetRight();
        parent.reset();
        while (tmp->GetLeft())
        {
            parent = tmp;
            tmp = tmp->GetLeft();
        }

        if (parent != nullptr)
            parent->GetLeft() = tmp->GetRight();
        else
            found->GetRight() = tmp->GetRight();

        found->GetValue() = tmp->GetValue();

        nextAfterDeleted = found;
    }

    return {nextAfterDeleted, true};
}

template <Comparable T>
BSTSharedPtr<T> MyBST::BinarySearchTree<T>::_Find(const T &value)
{
    BSTSharedPtr<T> node = mp_root;
    while (node && node->GetValue() != value)
    {
        if (node->GetValue() < value)
        {
            node = node->GetRight();
        }
        else
        {
            node = node->GetLeft();
        }
    }
    return node;
}

template <Comparable T>
std::ostream &MyBST::BinarySearchTree<T>::_Inorder(const BSTSharedPtr<T> &node, std::ostream &os) const
{
    if (node->GetLeft())
    {
        _Inorder(node->GetLeft(), os);
    }

    os << node->GetValue() << " ";

    if (node->GetRight() != nullptr)
    {
        _Inorder(node->GetRight(), os);
    }
    return os;
}
