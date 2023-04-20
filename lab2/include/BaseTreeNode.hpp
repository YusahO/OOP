#pragma once

#include "BaseTreeNode.h"

template<typename T>
BaseTreeNode<T>::BaseTreeNode(const T &value, const BaseTreeChildPtr<T> parent)
    : m_value(value),
      mp_parent(parent)
{
}

template <typename T>
BaseTreeParentPtr<T> BaseTreeNode<T>::GetParent() const
{
    if (auto spt = mp_parent.lock())
        return spt;
    return nullptr;
}

template <typename T>
BaseTreeChildPtr<T> BaseTreeNode<T>::GetLeft() const
{
    return mp_left;
}

template <typename T>
BaseTreeChildPtr<T> BaseTreeNode<T>::GetRight() const
{
    return mp_right;
}
