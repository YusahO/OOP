#pragma once

#include "Errors.h"
#include "TreeIterator.h"

template <typename T>
static void print_stack(std::stack<T> st)
{
    std::cout << "stack: ";
    while (!st.empty())
    {
        std::cout << st.top().get() << " ";
        st.pop();
    }
    std::cout << "\n";
}

template <typename T>
TreeIterator<T>::TreeIterator()
    : m_stack()
{
}

template <typename T>
TreeIterator<T>::TreeIterator(const BSTSharedPtr<T> &root)
{
    BSTSharedPtr<T> node = root;
    Leftmost(node);
}

template <typename T>
TreeIterator<T>::TreeIterator(const TreeIterator<T> &other)
    : m_stack(other.m_stack)
{
}

template <typename T>
TreeIterator<T> &TreeIterator<T>::operator=(const TreeIterator<T> &other)
{
    // other.CheckValidity(__LINE__);

    m_stack = other.m_stack;

    return *this;
}

template <typename T>
const T &TreeIterator<T>::operator*() const
{
    // CheckValidity(__LINE__);
    // CheckNull(__LINE__);
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
    BSTSharedPtr<T> &node = m_stack.top();
    return node != nullptr && !node.expired();
}

// template <typename T>
// void TreeIterator<T>::SetNode(const BSTSharedPtr<T> &node)
// {
//     m_stack.top() = node;
// }

template <typename T>
TreeIterator<T> &TreeIterator<T>::operator++()
{
    // if (m_stack.empty())
    // {
    //     throw InvalidIteratorError(__FILE__, typeid(*this).name(), __LINE__, "Incrementing and end() iterator");
    // }

    if (m_stack.top() == nullptr)
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
        while (!m_stack.empty() && m_stack.top()->GetRight() == node)
        {
            node = m_stack.top();
            m_stack.pop();
            if (m_stack.size() == 0)
            {
                Rightmost(node);
                m_stack.push(nullptr);
                return *this;
            }
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
    // if (m_stack.empty())
    // {
    //     return *this;
    // }

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
        while (!m_stack.empty() && m_stack.top()->GetLeft() == node)
        {
            node = m_stack.top();
            m_stack.pop();
            if (m_stack.size() == 0)
            {
                std::cout << node->GetValue() << "\n";
                Leftmost(node);
                return *this;
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

template <typename T>
void TreeIterator<T>::Leftmost(const BSTSharedPtr<T> &node)
{
    BSTSharedPtr<T> n = node;
    while (n)
    {
        m_stack.push(n);
        n = n->GetLeft();
    }
}

template <typename T>
void TreeIterator<T>::Rightmost(const BSTSharedPtr<T> &node)
{
    BSTSharedPtr<T> n = node;
    while (n)
    {
        m_stack.push(n);
        n = n->GetRight();
    }
}
