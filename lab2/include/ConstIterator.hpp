#pragma once

#include "ConstTreeIterator.h"

template<typename T>
ConstTreeIterator<T>::ConstTreeIterator(const ConstTreeIterator<T> &other)
{
    mp_node = other.mp_node;
}

template<typename T>
ConstTreeIterator<T>::ConstTreeIterator(const Tree<T> &tree)
{
    mp_node = tree.GetRoot();
}

template<typename T>
ConstTreeIterator<T> &ConstTreeIterator<T>::operator=(const ConstTreeIterator<T> &other)
{
    other.CheckObject(__LINE__);

    mp_node = other.mp_node;

    return *this;
}

template<typename T>
const T& ConstTreeIterator<T>::operator*() const
{
}
