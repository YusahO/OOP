#pragma once

#include <cstddef>
#include <memory>

#include "TreeNode.h"

template <typename T>
using IterWeakPtr = std::weak_ptr<TreeNode<T>>;

template <typename T>
using IterSharedPtr = std::shared_ptr<TreeNode<T>>;

template <typename T>
class BaseTreeIterator
{
public:
    virtual ~BaseTreeIterator() = 0;
};

template <typename T>
BaseTreeIterator<T>::~BaseTreeIterator()
{
}
