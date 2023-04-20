#pragma once

#include <memory>
#include <iostream>

#include "BaseTreeIterator.h"

template <typename T>
class Tree;

template <typename T>
class ConstTreeIterator : public BaseTreeIterator
{
public:
    ConstTreeIterator(const ConstTreeIterator<T> &other);
    ConstTreeIterator(const Tree<T> &tree);

    ConstTreeIterator<T> &operator=(const ConstTreeIterator<T> &other);

    const T &operator*() const;
    const T *operator->() const;

    const T &operator[](int index) const;

    operator bool() const;

    const T &operator+=(int value);
    ConstTreeIterator<T> &operator++();
    ConstTreeIterator<T> operator++(int);
    ConstTreeIterator<T> operator+(int value) const;

    const T &operator-=(int value);
    ConstTreeIterator<T> &operator--();
    ConstTreeIterator<T> operator--(int);
    ConstTreeIterator<T> operator-(int value) const;

    bool operator<=(const ConstTreeIterator<T> &other) const;
    bool operator<(const ConstTreeIterator<T> &other) const;
    bool operator>=(const ConstTreeIterator<T> &other) const;
    bool operator>(const ConstTreeIterator<T> &other) const;
    bool operator==(const ConstTreeIterator<T> &other) const;
    bool operator!=(const ConstTreeIterator<T> &other) const;

protected:
    T *GetCurrentPtr() const;

    void CheckObject(int) const;   
    void CheckValidity(int) const;
};
