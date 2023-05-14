#pragma once

#include <cstddef>
#include <memory>

class BaseTree
{
public:
    virtual size_t size() const = 0;
    virtual bool empty() const = 0;
    virtual ~BaseTree() {};
};
