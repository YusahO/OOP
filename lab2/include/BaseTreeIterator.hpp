#pragma once

#include "common.hpp"

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
