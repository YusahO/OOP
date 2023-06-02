#pragma once

#include "CameraLoadModerator.h"
#include "BaseCameraDirector.h"

class CameraLoadModeratorCreator
{
public:
    std::shared_ptr<CameraLoadModerator> createModerator();

private:
    void createInstance();

    std::shared_ptr<CameraLoadModerator> m_moderator;
};

