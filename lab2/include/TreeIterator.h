#pragma once

#include <memory>
#include <stack>
#include <iostream>

#include "BinarySearchTree.h"
#include "BaseTreeIterator.h"

template <typename T>
class TreeIterator : public BaseTreeIterator<T>
{
public:
    TreeIterator();
    explicit TreeIterator(const IterSharedPtr<T> &root);

    TreeIterator(const TreeIterator<T> &other);

    TreeIterator<T> &operator=(const TreeIterator<T> &other);

    const T &operator*() const;

    // const T &GetElement(int index) const;

    operator bool() const;
    bool Valid() const;

    // void SetNode(const IterSharedPtr<T> &node);

    TreeIterator<T> &operator++();
    TreeIterator<T> operator++(int);

    TreeIterator<T> &operator--();
    TreeIterator<T> operator--(int);

    bool operator==(const TreeIterator<T> &other) const;
    bool operator!=(const TreeIterator<T> &other) const;

    void Leftmost(const IterSharedPtr<T> &node);
    void Rightmost(const IterSharedPtr<T> &node);

protected:
    // void CheckValidity(int) const;
    // void CheckNull(int) const;

private:
    std::stack<IterSharedPtr<T>> m_stack;
    
};

#include "TreeIterator.hpp"
