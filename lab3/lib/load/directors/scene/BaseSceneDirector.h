#pragma once

#include "SceneBuilder.h"

class BaseSceneDirector
{
public:
    virtual std::shared_ptr<Scene> load(std::shared_ptr<SceneBuilder> builder, std::string &filename) = 0;

protected:
    virtual void loadModels(std::shared_ptr<SceneBuilder> builder, std::string &filename) = 0;
    virtual void loadCameras(std::shared_ptr<SceneBuilder> builder, std::string &filename) = 0;
};

