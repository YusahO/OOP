#pragma once

#include <cstddef>
#include <memory>
#include "BaseTreeNode.hpp"

template<typename T>
using BaseTreeNodePtr = std::weak_ptr<BaseTreeNode<T>>;

template<typename T>
class BaseTreeIterator
{
public:
    virtual ~BaseTreeIterator() = 0;

protected:
    BaseTreeNodePtr<T> mp_node = nullptr;
};

template<typename T>
BaseTreeIterator<T>::~BaseTreeIterator()
{
}
