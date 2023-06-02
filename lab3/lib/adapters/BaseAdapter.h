#pragma once 

class BaseAdapter
{
public:
    virtual ~BaseAdapter() = default;

    virtual void request() = 0;
};
