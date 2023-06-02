#pragma once

#include <memory>

#include "BaseObject.h"

class BaseLoadModerator
{
public:
    BaseLoadModerator() = default;
    ~BaseLoadModerator() = default;

    virtual std::shared_ptr<BaseObject> load(std::string &filename) = 0;
};
