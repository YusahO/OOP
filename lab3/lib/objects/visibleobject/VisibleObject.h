#pragma once

#include "BaseObject.h"

class VisibleObject : public BaseObject
{
public:
    VisibleObject() = default;
    ~VisibleObject() override = default;

    virtual bool isVisible() const override;
    virtual bool isComposite() const override;
};

