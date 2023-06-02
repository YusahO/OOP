#pragma once 

class BaseBuilder
{
public:
    BaseBuilder() = default;
    ~BaseBuilder() = default;

    virtual void build() = 0;
    virtual bool isBuild() const = 0;
};
