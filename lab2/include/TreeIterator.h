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
    TreeIterator(const BinarySearchTree<T> &tree);
    TreeIterator(const IterSharedPtr<T> &node, const BinarySearchTree<T> &tree);

    TreeIterator(const TreeIterator<T> &other);

    TreeIterator<T> &operator=(const TreeIterator<T> &other);

    const T &operator*() const;

    // const T &GetElement(int index) const;

    operator bool() const;
    bool Valid() const;

    void SetNode(const IterSharedPtr<T> &node);

    TreeIterator<T> &operator++();
    TreeIterator<T> operator++(int);

    TreeIterator<T> &operator--();
    TreeIterator<T> operator--(int);

    bool operator==(const TreeIterator<T> &other) const;
    bool operator!=(const TreeIterator<T> &other) const;

protected:
    void CheckValidity(int) const;
    void CheckNull(int) const;

private:
    friend BinarySearchTree<T>;

    IterWeakPtr<T> mp_node;
    std::stack<IterWeakPtr<T>> m_stack;
    const BinarySearchTree<T> &m_tree;
};

#include "TreeIterator.hpp"
