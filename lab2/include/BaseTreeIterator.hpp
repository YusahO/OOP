#pragma once

#include "common.hpp"

class BaseTreeIterator
{
public:
    virtual ~BaseTreeIterator() = 0;
};

BaseTreeIterator::~BaseTreeIterator()
{
}
