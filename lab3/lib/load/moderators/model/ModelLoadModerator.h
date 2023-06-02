#pragma once

#include "BaseLoadModerator.h"
#include "BaseModelDirector.h"
#include "BaseModelBuilder.h"

class ModelLoadModerator : public BaseLoadModerator
{
public:
    ModelLoadModerator() = default;
    explicit ModelLoadModerator(std::shared_ptr<BaseModelDirector> director);

    ~ModelLoadModerator() = default;

    std::shared_ptr<BaseObject> load(std::string &filename) override;

private:
    std::shared_ptr<BaseModelBuilder> m_builder;
    std::shared_ptr<BaseModelDirector> m_director;
};
