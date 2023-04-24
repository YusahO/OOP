#pragma once

#include "Errors.h"
#include "TreeIterator.h"

template <typename T>
TreeIterator<T>::TreeIterator(const IterSharedPtr<T> &node, const BinarySearchTree<T> &tree)
    : mp_node(node),
      m_tree(tree)
{
}

template <typename T>
TreeIterator<T>::TreeIterator(const TreeIterator<T> &other)
    : mp_node(other.mp_node),
      m_tree(other.m_tree)
{
}

template <typename T>
TreeIterator<T> &TreeIterator<T>::operator=(const TreeIterator<T> &other)
{
    other.CheckValidity(__LINE__);

    mp_node = other.mp_node;
    m_tree = other.m_tree;

    return *this;
}

template <typename T>
const T &TreeIterator<T>::operator*() const
{
    CheckValidity(__LINE__);
    CheckNull(__LINE__);
    return mp_node.lock()->GetValue();
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
void TreeIterator<T>::SetNode(const IterSharedPtr<T> &node)
{
    mp_node = node;
}

template <typename T>
TreeIterator<T> &TreeIterator<T>::operator++()
{
    CheckValidity(__LINE__);

    IterSharedPtr<T> node = mp_node.lock();

    if (!node)
    {
        return *this;
    }

    if (node->GetRight())
    {
        node = node->GetRight();
        while (node->GetLeft())
        {
            node = node->GetLeft();
        }
    }
    else
    {
        IterSharedPtr<T> parent = node->GetParent().lock();
        while (parent != nullptr && node == parent->GetRight())
        {
            node = parent;
            parent = parent->GetParent().lock();
        }
        node = parent;
    }

    mp_node = node;
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
    // CheckValidity(__LINE__);

    IterSharedPtr<T> node = mp_node.lock();
    if (!node)
    {
        node = m_tree.GetRoot();
        while (node->GetRight())
        {
            node = node->GetRight();
        }
    }

    if (node->GetLeft())
    {
        node = node->GetLeft();
        while (node->GetRight())
        {
            node = node->GetRight();
        }
    }
    else
    {
        IterSharedPtr<T> parent = node->GetParent().lock();
        while (parent != nullptr && node == parent->GetLeft())
        {
            node = parent;
            parent = parent->GetParent().lock();
        }
        node = parent;
    }

    mp_node = node;
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
    // CheckNull(__LINE__);
    return mp_node <= other.mp_node;
}

template <typename T>
bool TreeIterator<T>::operator<(const TreeIterator<T> &other) const
{
    // CheckNull(__LINE__);
    return mp_node.lock().get() < other.mp_node.lock().get();
}

template <typename T>
bool TreeIterator<T>::operator>=(const TreeIterator<T> &other) const
{
    // CheckNull(__LINE__);
    return mp_node >= other.mp_node;
}

template <typename T>
bool TreeIterator<T>::operator>(const TreeIterator<T> &other) const
{
    // CheckNull(__LINE__);
    return mp_node > other.mp_node;
}

template <typename T>
bool TreeIterator<T>::operator==(const TreeIterator<T> &other) const
{
    // CheckNull(__LINE__);
    return mp_node == other.mp_node;
}

template <typename T>
bool TreeIterator<T>::operator!=(const TreeIterator<T> &other) const
{
    // CheckNull(__LINE__);
    return mp_node.lock() != other.mp_node.lock();
}

template <typename T>
void TreeIterator<T>::CheckValidity(int line) const
{
    if (mp_node.expired())
        throw InvalidPointerError(__FILE__, typeid(this).name(), line);
}

template <typename T>
void TreeIterator<T>::CheckNull(int line) const
{
    if (!mp_node.lock())
        throw InvalidPointerError(__FILE__, typeid(this).name(), line, "Null pointer error");
}
