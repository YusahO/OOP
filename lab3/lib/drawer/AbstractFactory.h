#pragma once

#include <memory>
#include <BaseAction.h>

class AbstractFactory
{
public:
    virtual std::unique_ptr<BaseDrawer> createDrawer() = 0;
};
