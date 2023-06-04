#pragma once

#include "BaseObject.h"

class VisibleObject : public BaseObject
{
public:
    VisibleObject() = default;
    ~VisibleObject() override = default;

    bool isVisible() override { return true; }
};

