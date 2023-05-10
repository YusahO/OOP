#pragma once

#include <cstddef>

class BaseTree
{
public:
    virtual size_t size() const = 0;
    virtual ~BaseTree(){};
};
