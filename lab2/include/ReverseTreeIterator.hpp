#pragma once

#include <memory>
#include <stack>
#include <iostream>

#include "BinarySearchTree.hpp"
#include "BaseTreeIterator.hpp"

namespace MyBST {

template <typename T>
class ReverseTreeIterator : public BaseTreeIterator<T>
{
public:
    using IteratorCategory = std::bidirectional_iterator_tag;

public:
    ReverseTreeIterator();
    explicit ReverseTreeIterator(const BSTSharedPtr<T> &root);
    ReverseTreeIterator(const BSTSharedPtr<T> &node, const BSTSharedPtr<T> &root);

    ReverseTreeIterator(const ReverseTreeIterator<T> &other);
    ReverseTreeIterator(ReverseTreeIterator<T> &&other);

    ReverseTreeIterator<T> &operator=(const ReverseTreeIterator<T> &other);
    ReverseTreeIterator<T> &operator=(ReverseTreeIterator<T> &&other);

    const T &operator*() const;

    operator bool() const;
    bool Valid() const;

    ReverseTreeIterator<T> &operator++();
    ReverseTreeIterator<T> operator++(int);

    ReverseTreeIterator<T> &operator--();
    ReverseTreeIterator<T> operator--(int);

    bool operator==(const ReverseTreeIterator<T> &other) const;
    bool operator!=(const ReverseTreeIterator<T> &other) const;

    void Recalculate(const BSTSharedPtr<T> &root);

    template <typename P>
    friend std::ostream &operator<<(std::ostream &os, const ReverseTreeIterator<P> &iter);

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
std::ostream &operator<<(std::ostream &os, const ReverseTreeIterator<P> &iter)
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

#include "ReverseTreeIterator_impl.hpp"
