#pragma once

#include <memory>
#include <iostream>

#include "BinarySearchTree.h"
#include "BaseTreeIterator.h"

template <typename T>
class ConstTreeIterator : public BaseTreeIterator<T>
{
public:
    ConstTreeIterator(IterSharedPtr<T> &node, BinarySearchTree<T> &tree);

    ConstTreeIterator(const ConstTreeIterator<T> &other);

    ConstTreeIterator<T> &operator=(const ConstTreeIterator<T> &other);

    const T &operator*() const;
    const T *operator->() const;

    // const T &GetElement(int index) const;

    operator bool() const;
    bool Valid() const;

    ConstTreeIterator<T> &operator++();
    ConstTreeIterator<T> operator++(int);

    ConstTreeIterator<T> &operator--();
    ConstTreeIterator<T> operator--(int);

    bool operator<=(const ConstTreeIterator<T> &other) const;
    bool operator<(const ConstTreeIterator<T> &other) const;
    bool operator>=(const ConstTreeIterator<T> &other) const;
    bool operator>(const ConstTreeIterator<T> &other) const;
    bool operator==(const ConstTreeIterator<T> &other) const;
    bool operator!=(const ConstTreeIterator<T> &other) const;

protected:
    // T *GetCurrentPtr() const;
    void CheckValidity(int) const;
    void CheckNull(int) const;

private:
    friend BinarySearchTree<T>;

    BinarySearchTree<T> &m_tree;
    IterWeakPtr<T> mp_node;
};

#include "ConstTreeIterator.hpp"
