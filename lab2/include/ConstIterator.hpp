#pragma once

#include "ConstIterator.h"

template<typename T>
ConstIterator<T>::ConstIterator(const ConstIterator<T> &other)
{
    weakPtr = other.weakPtr;
    index = other.index;
    size = other.size;
}

template<typename T>
inline ConstIterator<T>::ConstIterator(const Tree<T> &tree)
{
    index = 0;
    size = vector.getSize();
    weakPtr = vector.values;
}
