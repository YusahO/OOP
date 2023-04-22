#pragma once

#include <memory>
#include <iostream>

#include "BinarySearchTree.h"
#include "BaseTreeIterator.h"

template <typename T>
class TreeIterator : public BaseTreeIterator<T>
{
public:
    TreeIterator() = default;
    TreeIterator(const IterSharedPtr<T> &node, const IterSharedPtr<T> &tree);
    explicit TreeIterator(const IterSharedPtr<T> &node);

    TreeIterator(const TreeIterator<T> &other);

    TreeIterator<T> &operator=(const TreeIterator<T> &other);

    T &operator*() const;
    T *operator->() const;

    // const T &GetElement(int index) const;

    operator bool() const;
    bool Valid() const;

    TreeIterator<T> &operator++();
    TreeIterator<T> operator++(int);

    TreeIterator<T> &operator--();
    TreeIterator<T> operator--(int);

    bool operator<=(const TreeIterator<T> &other) const;
    bool operator<(const TreeIterator<T> &other) const;
    bool operator>=(const TreeIterator<T> &other) const;
    bool operator>(const TreeIterator<T> &other) const;
    bool operator==(const TreeIterator<T> &other) const;
    bool operator!=(const TreeIterator<T> &other) const;

protected:
    // T *GetCurrentPtr() const;
    void CheckValidity(int) const;
    void CheckNull(int) const;

private:
    friend BinarySearchTree<T>;

    const IterWeakPtr<T> mp_tree;
    const IterWeakPtr<T> mp_node = nullptr;
};

#include "TreeIterator.hpp"
