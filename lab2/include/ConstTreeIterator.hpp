#pragma once

#include <memory>
#include <stack>
#include <iostream>

#include "BinarySearchTree.hpp"
#include "BaseTreeIterator.hpp"

template <typename T>
class ConstTreeIterator : public BaseTreeIterator<T>
{
public:
    using IteratorCategory = std::bidirectional_iterator_tag;

public:
    ConstTreeIterator();
    explicit ConstTreeIterator(const BSTSharedPtr<T> &root);
    ConstTreeIterator(const BSTSharedPtr<T> &node, const BSTSharedPtr<T> &root);

    ConstTreeIterator(const ConstTreeIterator<T> &other);

    ConstTreeIterator<T> &operator=(const ConstTreeIterator<T> &other);

    const T & operator*() const;

    operator bool() const;
    bool Valid() const;

    ConstTreeIterator<T> &operator++();
    ConstTreeIterator<T> operator++(int);

    ConstTreeIterator<T> &operator--();
    ConstTreeIterator<T> operator--(int);

    bool operator==(const ConstTreeIterator<T> &other) const;
    bool operator!=(const ConstTreeIterator<T> &other) const;

    void Recalculate(const BSTSharedPtr<T> &root);

    template <typename P>
    friend std::ostream &operator<<(std::ostream &os, const ConstTreeIterator<P> &iter);

    void Leftmost(const BSTSharedPtr<T> &node);
    void Rightmost(const BSTSharedPtr<T> &node);
    
protected:
    void Reset();
    void _Search(const BSTSharedPtr<T> &node, const BSTSharedPtr<T> &root);
    void CheckValidity(int) const;

private:
    std::stack<BSTSharedPtr<T>> m_stack;
};

#include "ConstTreeIterator_impl.hpp"

template <typename P>
std::ostream &operator<<(std::ostream &os, const ConstTreeIterator<P> &iter)
{
    std::stack<BSTSharedPtr<P>> st = iter.m_stack;
    os << "[ ";
    while (!st.empty())
    {
        if (st.top().get() == nullptr)
        {
            os << "null ";
        }
        else
        {
            os << st.top().get()->GetValue() << " ";
        }
        st.pop();
    }
    return os << "]";
}
