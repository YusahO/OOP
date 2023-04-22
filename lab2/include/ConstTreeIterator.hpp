#pragma once

#include "ConstTreeIterator.h"
#include "Errors.h"

template <typename T>
ConstTreeIterator<T>::ConstTreeIterator(const IterSharedPtr<T> &node)
    : mp_node(node)
{
}

template <typename T>
ConstTreeIterator<T>::ConstTreeIterator(const ConstTreeIterator<T> &other)
{
    mp_node = other.mp_node;
}

template <typename T>
ConstTreeIterator<T> &ConstTreeIterator<T>::operator=(const ConstTreeIterator<T> &other)
{
    other.CheckValidity(__LINE__);

    mp_node = other.mp_node;

    return *this;
}

template <typename T>
const T &ConstTreeIterator<T>::operator*() const
{
    CheckValidity(__LINE__);
    CheckNull(__LINE__);
    return mp_node.lock()->get();
}

template <typename T>
const T *ConstTreeIterator<T>::operator->() const
{
    CheckValidity(__LINE__);
    CheckNull(__LINE__);

    return mp_node.lock()->get();
}

template <typename T>
ConstTreeIterator<T>::operator bool() const
{
    return Valid();
}

template <typename T>
bool ConstTreeIterator<T>::Valid() const
{
    return mp_node.lock() != nullptr && !mp_node.expired();
}

template <typename T>
ConstTreeIterator<T> &ConstTreeIterator<T>::operator++()
{
    CheckValidity(__LINE__);

    IterSharedPtr<T> node = mp_node.lock();
    IterSharedPtr<T> tree = mp_tree.lock();

    if (node)
    {
        node = tree->mp_root;

        if (!node)
            InvalidIteratorError(__LINE__, typeid(*this).name(), __LINE__);

        node->GetMinimum();
    }
    else if (node->mp_right)
    {
        node = node->mp_right;
        node->GetMinimum();
    }
    else
    {
        IterSharedPtr<T> p = node->mp_parent.lock();
        while (p && node == p->mp_right)
        {
            node = p;
            p = p->mp_parent;
        }
        node = p;
    }

    return *this;
}

template <typename T>
ConstTreeIterator<T> ConstTreeIterator<T>::operator++(int)
{
    auto saved = *this;
    operator++();
    return saved;
}

template <typename T>
ConstTreeIterator<T> &ConstTreeIterator<T>::operator--()
{
    CheckValidity(__LINE__);

    IterSharedPtr<T> node = mp_node.lock();
    IterSharedPtr<T> tree = mp_tree.lock();

    if (!node)
    {
        node = tree->mp_root;
        if (!node)
            InvalidIteratorError(__LINE__, typeid(*this).name(), __LINE__);

        node->GetMaximum();
    }
    else if (node->mp_left)
    {
        node = node->mp_left;
        node->GetMaximum();
    }
    else
    {
        IterSharedPtr<T> p = node->mp_parent.lock();
        while (p && node == p->mp_left)
        {
            node = p;
            p = p->mp_paremt.lock();
        }

        node = p;
    }

    return *this;
}

template <typename T>
inline ConstTreeIterator<T> ConstTreeIterator<T>::operator--(int)
{
    auto saved = *this;
    operator--();
    return saved;
}

template <typename T>
bool ConstTreeIterator<T>::operator<=(const ConstTreeIterator<T> &other) const
{
    CheckNull(__LINE__);
    return mp_node <= other.mp_node;
}

template <typename T>
bool ConstTreeIterator<T>::operator<(const ConstTreeIterator<T> &other) const
{
    CheckNull(__LINE__);
    return mp_node < other.mp_node;
}

template <typename T>
bool ConstTreeIterator<T>::operator>=(const ConstTreeIterator<T> &other) const
{
    CheckNull(__LINE__);
    return mp_node >= other.mp_node;
}

template <typename T>
bool ConstTreeIterator<T>::operator>(const ConstTreeIterator<T> &other) const
{
    CheckNull(__LINE__);
    return mp_node > other.mp_node;
}

template <typename T>
bool ConstTreeIterator<T>::operator==(const ConstTreeIterator<T> &other) const
{
    CheckNull(__LINE__);
    return mp_node == other.mp_node;
}

template <typename T>
bool ConstTreeIterator<T>::operator!=(const ConstTreeIterator<T> &other) const
{
    CheckNull(__LINE__);
    return mp_node != other.mp_node;
}

template <typename T>
void ConstTreeIterator<T>::CheckValidity(int) const
{
    if (!mp_node.expired())
        throw InvalidPointerError(__FILE__, typeid(*this).name(), __LINE__);
}

template <typename T>
void ConstTreeIterator<T>::CheckNull(int) const
{
    if (!mp_node)
        throw InvalidPointerError(__FILE__, typeid(*this).name(), __LINE__, "Null pointer error");
}
