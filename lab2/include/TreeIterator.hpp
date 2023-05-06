#pragma once

#include <memory>
#include <stack>
#include <iostream>

#include "BinarySearchTree.hpp"
#include "BaseTreeIterator.hpp"

namespace MyBST {

template <typename T>
class TreeIterator : public BaseTreeIterator<T>
{
public:
    using IteratorCategory = std::bidirectional_iterator_tag;

public:
    TreeIterator();
    explicit TreeIterator(const BSTSharedPtr<T> &root);
    TreeIterator(const BSTSharedPtr<T> &node, const BSTSharedPtr<T> &root);

    TreeIterator(const TreeIterator<T> &other);
    TreeIterator(TreeIterator<T> &&other);

    TreeIterator<T> &operator=(const TreeIterator<T> &other);
    TreeIterator<T> &operator=(TreeIterator<T> &&other);

    const T &operator*();

    operator bool() const;
    bool Valid() const;

    TreeIterator<T> &operator++();
    TreeIterator<T> operator++(int);

    TreeIterator<T> &operator--();
    TreeIterator<T> operator--(int);

    bool operator==(const TreeIterator<T> &other) const;
    bool operator!=(const TreeIterator<T> &other) const;

    void Recalculate(const BSTSharedPtr<T> &root);

    template <typename P>
    friend std::ostream &operator<<(std::ostream &os, const TreeIterator<P> &iter);

    void Leftmost(const BSTSharedPtr<T> &node);
    void Rightmost(const BSTSharedPtr<T> &node);

protected:
    void Reset();
    void Search(const BSTSharedPtr<T> &node, const BSTSharedPtr<T> &root);
    void CheckValidity(int) const;

private:
    std::stack<BSTSharedPtr<T>> m_stack;
};

template <typename P>
std::ostream &operator<<(std::ostream &os, const TreeIterator<P> &iter)
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

}

#include "TreeIterator_impl.hpp"
