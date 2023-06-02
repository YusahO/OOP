#pragma once

#include "SceneLoadModerator.h"

class SceneLoadModeratorCreator
{
public:
    std::shared_ptr<SceneLoadModerator> createModerator();

private:
    void createInstance();

    std::shared_ptr<SceneLoadModerator> m_moderator;
};


