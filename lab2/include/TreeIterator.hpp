#pragma once

#include "Errors.h"
#include "TreeIterator.h"

template <typename T>
TreeIterator<T>::TreeIterator(const BinarySearchTree<T> &tree)
    : mp_node(nullptr),
    m_tree(tree)
{
}

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
    // CheckValidity(__LINE__);

    if (m_stack.top() == nullptr)
    {
        return *this;
    }

    BSTSharedPtr<T> node = m_stack.top();
    if (node->GetRight())
    {
        node = node->GetRight();
        m_stack.push(node);
        while (node->GetLeft())
        {
            node = node->GetLeft();
            m_stack.push(node);
        }
    }
    else
    {
        m_stack.pop();
        BSTSharedPtr<T> parent = m_stack.top();
        while (!m_stack.empty() && node == parent->GetRight())
        {
            node = parent;
            m_stack.pop();
            if (!m_stack.empty())
            {
                parent = m_stack.top();
            }
            else
            {
                GetMaximum(parent);
                m_stack.push(nullptr);
            }
        }
        node = parent;
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
    if (m_stack.top() == nullptr)
    {
        m_stack.pop();
    }

    BSTSharedPtr<T> node = m_stack.top();
    if (node->GetLeft())
    {
        node = node->GetLeft();
        m_stack.push(node);
        while (node->GetRight())
        {
            node = node->GetRight();
            m_stack.push(node);
        }
    }
    else
    {
        m_stack.pop();
        BSTSharedPtr<T> parent = m_stack.top();
        while (!m_stack.empty() && node == parent->getLeft())
        {
            node = parent;
            m_stack.pop();
            if (m_stack.empty())
            {
                GetMaximum(parent);
            }
            parent = m_stack.top();
        }
        node = parent;
    }
    return *this;
}

template <typename T>
TreeIterator<T> TreeIterator<T>::operator--(int)
{
    auto saved = *this;
    operator--();
    return saved;
}

template <typename T>
bool TreeIterator<T>::operator==(const TreeIterator<T> &other) const
{
    // CheckValidity(__LINE__);
    return mp_node == other.mp_node;
}

template <typename T>
bool TreeIterator<T>::operator!=(const TreeIterator<T> &other) const
{
    // CheckValidity(__LINE__);
    return mp_node.get() != other.mp_node.get();
}

// template <typename T>
// void TreeIterator<T>::CheckValidity(int line) const
// {
//     if (mp_node.expired())
//         throw InvalidPointerError(__FILE__, typeid(this).name(), line);
// }

// template <typename T>
// void TreeIterator<T>::CheckNull(int line) const
// {
//     if (!mp_node.lock())
//         throw InvalidPointerError(__FILE__, typeid(this).name(), line, "Null pointer error");
// }

template<typename T>
void TreeIterator<T>::GetMinimum(IterSharedPtr<T> &node)
{
    while (node)
    {
        m_stack.push(node);
        node = node->GetLeft();
    }
}

template<typename T>
void TreeIterator<T>::GetMaximum(IterSharedPtr<T> &node)
{
    while (node)
    {
        m_stack.push(node);
        node = node->GetRight();
    }
}
