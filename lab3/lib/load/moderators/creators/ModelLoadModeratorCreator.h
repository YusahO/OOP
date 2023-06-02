#pragma once

#include "ModelLoadModerator.h"

class ModelLoadModeratorCreator
{
public:
    std::shared_ptr<ModelLoadModerator> createModerator();

private:
    void createInstance();

    std::shared_ptr<ModelLoadModerator> m_moderator;
};
