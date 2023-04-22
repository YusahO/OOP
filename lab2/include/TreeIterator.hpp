#pragma once

#include "Errors.h"
#include "TreeIterator.h"

template <typename T>
TreeIterator<T>::TreeIterator(const IterSharedPtr<T> &node, const IterSharedPtr<T> &tree)
    : mp_node(node),
      mp_tree(tree)
{
}

template <typename T>
TreeIterator<T>::TreeIterator(const IterSharedPtr<T> &node)
    : mp_node(node)
{
}

template <typename T>
TreeIterator<T>::TreeIterator(const TreeIterator<T> &other)
{
    mp_node = other.mp_node;
}

template <typename T>
TreeIterator<T> &TreeIterator<T>::operator=(const TreeIterator<T> &other)
{
    other.CheckValidity(__LINE__);

    mp_node = other.mp_node;

    return *this;
}

template <typename T>
T &TreeIterator<T>::operator*() const
{
    CheckValidity(__LINE__);
    CheckNull(__LINE__);
    return mp_node.lock()->get();
}

template <typename T>
T *TreeIterator<T>::operator->() const
{
    CheckValidity(__LINE__);
    CheckNull(__LINE__);

    return mp_node.lock()->get();
}

template <typename T>
TreeIterator<T>::operator bool() const
{
    return Valid();
}

template <typename T>
bool TreeIterator<T>::Valid() const
{
    return mp_node.lock() != nullptr && !mp_node.expired();
}

template <typename T>
TreeIterator<T> &TreeIterator<T>::operator++()
{
    CheckValidity(__LINE__);

    IterSharedPtr<T> node = mp_node.lock();
    IterSharedPtr<T> tree = mp_tree.lock();

    if (node)
    {
        node = tree->mp_root;

        if (!node)
            InvalidIteratorError(__LINE__, typeid(*this).name(), __LINE__);

        node->GetMinimum();
    }
    else if (node->mp_right)
    {
        node = node->mp_right;
        node->GetMinimum();
    }
    else
    {
        IterSharedPtr<T> p = node->mp_parent.lock();
        while (p && node == p->mp_right)
        {
            node = p;
            p = p->mp_parent;
        }
        node = p;
    }

    return *this;
}

template <typename T>
TreeIterator<T> TreeIterator<T>::operator++(int)
{
    auto saved = *this;
    operator++();
    return saved;
}

template <typename T>
TreeIterator<T> &TreeIterator<T>::operator--()
{
    CheckValidity(__LINE__);

    IterSharedPtr<T> node = mp_node.lock();
    IterSharedPtr<T> tree = mp_tree.lock();

    if (!node)
    {
        node = tree->mp_root;
        if (!node)
            InvalidIteratorError(__LINE__, typeid(*this).name(), __LINE__);

        node->GetMaximum();
    }
    else if (node->mp_left)
    {
        node = node->mp_left;
        node->GetMaximum();
    }
    else
    {
        IterSharedPtr<T> p = node->mp_parent.lock();
        while (p && node == p->mp_left)
        {
            node = p;
            p = p->mp_paremt.lock();
        }

        node = p;
    }

    return *this;
}

template <typename T>
inline TreeIterator<T> TreeIterator<T>::operator--(int)
{
    auto saved = *this;
    operator--();
    return saved;
}

template <typename T>
bool TreeIterator<T>::operator<=(const TreeIterator<T> &other) const
{
    CheckNull(__LINE__);
    return mp_node <= other.mp_node;
}

template <typename T>
bool TreeIterator<T>::operator<(const TreeIterator<T> &other) const
{
    CheckNull(__LINE__);
    return mp_node < other.mp_node;
}

template <typename T>
bool TreeIterator<T>::operator>=(const TreeIterator<T> &other) const
{
    CheckNull(__LINE__);
    return mp_node >= other.mp_node;
}

template <typename T>
bool TreeIterator<T>::operator>(const TreeIterator<T> &other) const
{
    CheckNull(__LINE__);
    return mp_node > other.mp_node;
}

template <typename T>
bool TreeIterator<T>::operator==(const TreeIterator<T> &other) const
{
    CheckNull(__LINE__);
    return mp_node == other.mp_node;
}

template <typename T>
bool TreeIterator<T>::operator!=(const TreeIterator<T> &other) const
{
    CheckNull(__LINE__);
    return mp_node != other.mp_node;
}

template <typename T>
void TreeIterator<T>::CheckValidity(int line) const
{
    if (!mp_node.expired())
        throw InvalidPointerError(__FILE__, typeid(*this).name(), line);
}

template <typename T>
void TreeIterator<T>::CheckNull(int line) const
{
    if (!mp_node)
        throw InvalidPointerError(__FILE__, typeid(*this).name(), line, "Null pointer error");
}
