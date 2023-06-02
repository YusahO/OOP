#pragma once

#include "BaseDirector.h"
#include "ModelBuilder.h"

class BaseModelDirector : public BaseDirector
{
public:
    virtual std::shared_ptr<CarcassModel> load(std::shared_ptr<BaseModelBuilder> builder, std::string &filename) = 0;
};
