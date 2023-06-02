#pragma once 

#include <BaseAdapter.h>
#include <Composite.h>

class Composite;

class CompositeAdapter: public BaseAdapter
{
public:
    virtual ~CompositeAdapter() = default;

    void setAdaptee(std::shared_ptr<Composite> adaptee) { m_adaptee = adaptee; };

    virtual void request() = 0;
protected:
    std::shared_ptr<Composite>  m_adaptee;
};
