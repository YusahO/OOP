#pragma once

#include "BaseObject.h"

class InvisibleObject : public BaseObject
{
public:
    InvisibleObject() = default;
    ~InvisibleObject() = default;

    bool isVisible() override;
};
