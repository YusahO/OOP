#pragma once

#include <memory>
#include <iostream>

#include "BaseIterator.h"
// #include "ErrorProcessor.h"

template <typename T>
class Tree;

template <typename T>
class ConstIterator : public BaseIterator
{
public:
    ConstIterator(const ConstIterator<T> &);
    ConstIterator(const Tree<T>&);

    const T &operator=(const ConstIterator<T> &iter);

    const T &operator*() const;
    const T *operator->() const;

    const T &operator[](int index) const;

    operator bool() const;

    const T &operator+=(int value);
    ConstIterator<T> &operator++();
    ConstIterator<T> operator++(int);
    ConstIterator<T> operator+(int value) const;

    const T &operator-=(int value);
    ConstIterator<T> &operator--();
    ConstIterator<T> operator--(int);
    ConstIterator<T> operator-(int value) const;

    bool operator<=(const ConstIterator<T> &iterator) const;
    bool operator<(const ConstIterator<T> &iterator) const;
    bool operator>=(const ConstIterator<T> &iterator) const;
    bool operator>(const ConstIterator<T> &iterator) const;
    bool operator==(const ConstIterator<T> &iterator) const;
    bool operator!=(const ConstIterator<T> &iterator) const;

protected:
    T *GetCurrentPtr() const;

    void CheckObject(int) const;   
    void CheckValidity(int) const;

private:
    std::weak_ptr<T[]> weakPtr;
};