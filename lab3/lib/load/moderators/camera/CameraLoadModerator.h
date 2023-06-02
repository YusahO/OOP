#pragma once

#include "BaseLoadModerator.h"
#include "BaseCameraDirector.h"

class CameraLoadModerator : public BaseLoadModerator
{
public:
    explicit CameraLoadModerator(std::shared_ptr<BaseCameraDirector> director);
    ~CameraLoadModerator() = default;

    std::shared_ptr<BaseObject> load(std::string &filename) override;

private:
    std::shared_ptr<BaseCameraBuilder> m_builder;
    std::shared_ptr<BaseCameraDirector> m_director;
};

