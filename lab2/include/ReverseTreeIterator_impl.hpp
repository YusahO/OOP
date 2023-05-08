#pragma once

#include "Errors.hpp"
#include "ReverseTreeIterator.hpp"
#include <utility>

namespace MyBST {

template <typename T>
ReverseTreeIterator<T>::ReverseTreeIterator()
    : m_stack()
{
}

template <typename T>
ReverseTreeIterator<T>::ReverseTreeIterator(const bst_shared_ptr &root)
{
    leftmost(root);
    m_stack.emplace(nullptr);
}

template <typename T>
ReverseTreeIterator<T>::ReverseTreeIterator(const bst_shared_ptr &node, const bst_shared_ptr &root)
{
    if (node != nullptr)
    {
        search(node, root);
    }
    else
    {
        rightmost(root);
        m_stack.emplace(node);
    }
}

template <typename T>
ReverseTreeIterator<T>::ReverseTreeIterator(const ReverseTreeIterator<T> &other)
    : m_stack(other.m_stack)
{
}

template<typename T>
ReverseTreeIterator<T>::ReverseTreeIterator(ReverseTreeIterator<T> &&other)
    : m_stack(std::move(other.m_stack))
{
}

template <typename T>
ReverseTreeIterator<T> &ReverseTreeIterator<T>::operator=(const ReverseTreeIterator<T> &other)
{
    other.check_validity(__LINE__);
    m_stack = other.m_stack;
    return *this;
}

template<typename T>
ReverseTreeIterator<T> &ReverseTreeIterator<T>::operator=(ReverseTreeIterator<T> &&other)
{
    other.check_validity(__LINE__);
    m_stack = std::move(other.m_stack);
    return *this;
}

template <typename T>
const T &ReverseTreeIterator<T>::operator*() const
{
    check_validity(__LINE__);
    return m_stack.top()->m_value;
}

template <typename T>
ReverseTreeIterator<T>::operator bool() const
{
    return valid();
}

template <typename T>
bool ReverseTreeIterator<T>::valid() const
{
    return !m_stack.empty() && m_stack.top() != nullptr;
}

template <typename T>
ReverseTreeIterator<T> &ReverseTreeIterator<T>::operator--()
{
    check_validity(__LINE__);

    // if (m_stack.empty() || m_stack.top() == nullptr)
    // {
    //     return *this;
    // }

    if (m_stack.top()->mp_right)
    {
        bst_shared_ptr node = m_stack.top()->mp_right;
        leftmost(node);
    }
    else
    {
        bst_shared_ptr node = m_stack.top();
        m_stack.pop();

        bool stackNotEmpty = !m_stack.empty();
        while (stackNotEmpty && m_stack.top()->mp_right == node)
        {
            node = m_stack.top();
            m_stack.pop();

            if (m_stack.empty())
                stackNotEmpty = false;
        }

        if (!stackNotEmpty)
        {
            rightmost(node);
            m_stack.emplace(nullptr);
        }
    }

    return *this;
}

template <typename T>
ReverseTreeIterator<T> ReverseTreeIterator<T>::operator--(int)
{
    auto saved = *this;
    --(*this);
    return saved;
}

template <typename T>
ReverseTreeIterator<T> &ReverseTreeIterator<T>::operator++()
{
    check_validity(__LINE__);

    if (m_stack.top() == nullptr)
    {
        m_stack.pop();
        return *this;
    }

    if (m_stack.top()->mp_left)
    {
        bst_shared_ptr node = m_stack.top()->mp_left;
        rightmost(node);
    }
    else
    {
        bst_shared_ptr node = m_stack.top();
        m_stack.pop();

        bool stackNotEmpty = !m_stack.empty();
        while (stackNotEmpty && m_stack.top()->mp_left == node)
        {
            node = m_stack.top();
            m_stack.pop();

            if (m_stack.empty())
                stackNotEmpty = false;
        }
        if (!stackNotEmpty)
        {
            leftmost(node);
            m_stack.emplace(nullptr);
        }
    }

    return *this;
}

template <typename T>
ReverseTreeIterator<T> ReverseTreeIterator<T>::operator++(int)
{
    auto saved = *this;
    ++(*this);
    return saved;
}

template <typename T>
bool ReverseTreeIterator<T>::operator==(const ReverseTreeIterator<T> &other) const
{
    // check_validity(__LINE__);
    return m_stack == other.m_stack;
}

template <typename T>
bool ReverseTreeIterator<T>::operator!=(const ReverseTreeIterator<T> &other) const
{
    // check_validity(__LINE__);
    return m_stack != other.m_stack;
}

template <typename T>
void ReverseTreeIterator<T>::recalculate(const bst_shared_ptr &root)
{
    bst_shared_ptr top = m_stack.top();
    reset();

    if (top != nullptr)
    {
        search(top, root);
    }
    else
    {
        rightmost(root);
        m_stack.emplace(top);
    }
}

template <typename T>
void ReverseTreeIterator<T>::reset()
{
    while (!m_stack.empty())
        m_stack.pop();
}

template <typename T>
void ReverseTreeIterator<T>::check_validity(int line) const
{
    if (!valid())
        throw TreeOutOfBoundsError(__FILE__, typeid(this).name(), line);
}

template <typename T>
void ReverseTreeIterator<T>::leftmost(const bst_shared_ptr &node)
{
    bst_shared_ptr n = node;
    while (n)
    {
        m_stack.emplace(n);
        n = n->mp_left;
    }
}

template <typename T>
void ReverseTreeIterator<T>::rightmost(const bst_shared_ptr &node)
{
    bst_shared_ptr n = node;
    while (n)
    {
        m_stack.emplace(n);
        n = n->mp_right;
    }
}

template <typename T>
void ReverseTreeIterator<T>::search(const bst_shared_ptr &node, const bst_shared_ptr &root)
{
    bst_shared_ptr found = root;
    while (found && found->m_value != node->m_value)
    {
        m_stack.emplace(found);
        if (found->m_value < node->m_value)
            found = found->mp_right;
        else
            found = found->mp_left;
    }
    m_stack.emplace(found);
}

}
