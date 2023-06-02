#pragma once

#include "BaseAdapter.h"
#include "CarcassModel.h"

class CarcassModel;

class ModelAdapter: public BaseAdapter
{
public:
    virtual ~ModelAdapter() = default;

    virtual void setAdaptee(std::shared_ptr<CarcassModel> adaptee)
    {
        m_adaptee = adaptee;
    }

    virtual void request() = 0;
protected:
    std::shared_ptr<CarcassModel> m_adaptee;
};
