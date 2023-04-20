#pragma once

#include <cstddef>

class BaseIterator
{
public:
    virtual ~BaseIterator() = 0;

protected:
    size_t index;
    size_t size;
};

BaseIterator::~BaseIterator()
{
}