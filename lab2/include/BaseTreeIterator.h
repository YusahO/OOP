#pragma once

#include "common.h"
#include <cstddef>

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
