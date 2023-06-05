#pragma once

#include <VisibleObject.h>

class BaseModel: public VisibleObject
{
    virtual bool isVisible() const override;
    virtual bool isComposite() const override;
};
