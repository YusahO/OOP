#pragma once

#include "Errors.hpp"
#include "TreeIterator.hpp"
#include <utility>

namespace MyBST {

template <typename T>
TreeIterator<T>::TreeIterator()
    : m_stack()
{
}

template <typename T>
TreeIterator<T>::TreeIterator(const BSTSharedPtr<T> &root)
{
    Leftmost(root);
}

template <typename T>
TreeIterator<T>::TreeIterator(const BSTSharedPtr<T> &node, const BSTSharedPtr<T> &root)
{
    if (node != nullptr)
    {
        _Search(node, root);
    }
    else
    {
        Rightmost(root);
        m_stack.emplace(node);
    }
}

template <typename T>
TreeIterator<T>::TreeIterator(const TreeIterator<T> &other)
    : m_stack(other.m_stack)
{
}

template<typename T>
TreeIterator<T>::TreeIterator(TreeIterator<T> &&other)
    : m_stack(std::move(m_stack))
{
}

template <typename T>
TreeIterator<T> &TreeIterator<T>::operator=(const TreeIterator<T> &other)
{
    other.CheckValidity(__LINE__);
    m_stack = other.m_stack;
    return *this;
}

template<typename T>
TreeIterator<T> &TreeIterator<T>::operator=(TreeIterator<T> &&other)
{
    other.CheckValidity(__LINE__);
    m_stack = std::move(other.m_stack);
    return *this;
}

template <typename T>
const T &TreeIterator<T>::operator*()
{
    CheckValidity(__LINE__);
    return m_stack.top()->GetValue();
}

template <typename T>
TreeIterator<T>::operator bool() const
{
    return Valid();
}

template <typename T>
bool TreeIterator<T>::Valid() const
{
    return !m_stack.empty();
}

template <typename T>
TreeIterator<T> &TreeIterator<T>::operator++()
{
    CheckValidity(__LINE__);

    if (m_stack.empty() || m_stack.top() == nullptr)
    {
        return *this;
    }

    if (m_stack.top()->GetRight())
    {
        BSTSharedPtr<T> node = m_stack.top()->GetRight();
        Leftmost(node);
    }
    else
    {
        BSTSharedPtr<T> node = m_stack.top();
        m_stack.pop();

        bool stackNotEmpty = !m_stack.empty();
        while (stackNotEmpty && m_stack.top()->GetRight() == node)
        {
            node = m_stack.top();
            m_stack.pop();

            if (m_stack.empty())
                stackNotEmpty = false;
        }

        if (!stackNotEmpty)
        {
            Rightmost(node);
            m_stack.emplace(nullptr);
        }
    }

    return *this;
}

template <typename T>
TreeIterator<T> TreeIterator<T>::operator++(int)
{
    auto saved = *this;
    ++(*this);
    return saved;
}

template <typename T>
TreeIterator<T> &TreeIterator<T>::operator--()
{
    CheckValidity(__LINE__);

    if (m_stack.top() == nullptr)
    {
        m_stack.pop();
        return *this;
    }

    if (m_stack.top()->GetLeft())
    {
        BSTSharedPtr<T> node = m_stack.top()->GetLeft();
        Rightmost(node);
    }
    else
    {
        BSTSharedPtr<T> node = m_stack.top();
        m_stack.pop();

        bool stackNotEmpty = !m_stack.empty();
        while (stackNotEmpty && m_stack.top()->GetLeft() == node)
        {
            node = m_stack.top();
            m_stack.pop();
            if (m_stack.empty())
            {
                Leftmost(node);
            }
        }
    }

    return *this;
}

template <typename T>
TreeIterator<T> TreeIterator<T>::operator--(int)
{
    auto saved = *this;
    --(*this);
    return saved;
}

template <typename T>
bool TreeIterator<T>::operator==(const TreeIterator<T> &other) const
{
    // CheckValidity(__LINE__);
    return m_stack == other.m_stack;
}

template <typename T>
bool TreeIterator<T>::operator!=(const TreeIterator<T> &other) const
{
    // CheckValidity(__LINE__);
    return m_stack != other.m_stack;
}

template <typename T>
void TreeIterator<T>::Recalculate(const BSTSharedPtr<T> &root)
{
    BSTSharedPtr<T> top = m_stack.top();
    Reset();
    
    if (top != nullptr)
    {
        _Search(top, root);
    }
    else
    {
        Rightmost(root);
        m_stack.emplace(top);
    }
}

template <typename T>
void TreeIterator<T>::Reset()
{
    while (!m_stack.empty())
        m_stack.pop();
}

template <typename T>
void TreeIterator<T>::CheckValidity(int line) const
{
    if (!Valid())
        throw InvalidPointerError(__FILE__, typeid(this).name(), line);
}

template <typename T>
void TreeIterator<T>::Leftmost(const BSTSharedPtr<T> &node)
{
    BSTSharedPtr<T> n = node;
    while (n)
    {
        m_stack.emplace(n);
        n = n->GetLeft();
    }
}

template <typename T>
void TreeIterator<T>::Rightmost(const BSTSharedPtr<T> &node)
{
    BSTSharedPtr<T> n = node;
    while (n)
    {
        m_stack.emplace(n);
        n = n->GetRight();
    }
}

template <typename T>
void TreeIterator<T>::_Search(const BSTSharedPtr<T> &node, const BSTSharedPtr<T> &root)
{
    BSTSharedPtr<T> found = root;
    while (found && found->GetValue() != node->GetValue())
    {
        m_stack.emplace(found);
        if (found->GetValue() < node->GetValue())
            found = found->GetRight();
        else
            found = found->GetLeft();
    }
    m_stack.emplace(found);
}

}